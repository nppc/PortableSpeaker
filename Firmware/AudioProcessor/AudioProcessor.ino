#include "i2c.c"

// for encoder readings use bitRead for speed.
// this requires to use AVR original pin numbers
#define BUTTON0_PIN		4 	// PD4
#define BUTTON1_PIN		5	// PD5
#define encoder0PinA	2	// PD2 Interrupt pin (coupled with capacitor to GND)
#define encoder0PinB	6	// PD6
#define encoder1PinA	3	// PD3 Interrupt pin (coupled with capacitor to GND)
#define encoder1PinB	7	// PD7
// this pins are used with Arduino regular functions
#define LED_PIN			8 	// 1 Wire LEDs
#define IN1_SENSE_PIN	9	// MIC/INST 
#define VSENSE_PIN		A7	// Battery charge level

// to identify encoder 
#define MAIN_ENCODER	0
#define INPUT_ENCODER	1


/***********
 * SubAddress:
 * 0 - input select
 * 1 - input gain
 * 2 - volume
 * 3 - bass
 * 4 - not used
 * 5 - treble
 * 6 - Speaker R
 * 7 - Speaker L
 */

// Datasheet says 0x88 but that is the 8 bit address.
// Wire.h automatically appends the extra (lsb write) bit, 
// so 0x44 if Wire library is used.
#define I2C_ADDR            0b10001000  // 0x88 - no Wire library is used

// TDA7440 subaddress (function)
#define INPUT_SELECT		0x00 // 4 inputs
#define INPUT_GAIN			0x01 // 2dB steps [0-15]=[0-30] (0dB to +30dB)
#define VOLUME				0x02 // 1dB steps [0-40]=[0-40] (0dB to -40dB) or MUTE
#define BASS				0x03
#define TREBLE				0x05
#define SPEAKER_RIGHT		0x06 // for Balance - not using as we input mono (only for muting).
#define SPEAKER_LEFT		0x07 // for Balance - not using as we input mono (only for muting).

// TDA7440 function values
#define VOLUME_MUTE			0b01111111

#define SPEAKER_MUTE		0b01111111
#define SPEAKER_UNMUTE		0b00000000

// TDA7440 autoincrement flag
#define AUTO_INC			0x10

// Encoders variables
volatile char encoder0Pos = 0;
volatile byte encoder0Change = 0;
unsigned long encoder0millis = 0;

volatile char encoder1Pos = 0;
volatile byte encoder1Change = 0;
unsigned long encoder1millis = 0;


void setup() {
	I2CInit();
	Serial.begin(115200);
/*
	bitClear(DDRD, encoder0PinA);
	bitSet(PORTD, encoder0PinA);
	bitClear(DDRD, encoder1PinA);
	bitSet(PORTD, encoder1PinA);
	bitClear(DDRD, encoder0PinB);
	bitSet(PORTD, encoder0PinB);
	bitClear(DDRD, encoder1PinB);
	bitSet(PORTD, encoder1PinB);
	bitClear(DDRD, BUTTON0_PIN);
	bitSet(PORTD, BUTTON0_PIN);
	bitClear(DDRD, BUTTON1_PIN);
	bitSet(PORTD, BUTTON1_PIN);
*/
	pinMode(encoder0PinA, INPUT_PULLUP); 
	pinMode(encoder0PinB, INPUT_PULLUP); 
	pinMode(encoder1PinA, INPUT_PULLUP); 
	pinMode(encoder1PinB, INPUT_PULLUP); 
	pinMode(BUTTON0_PIN, INPUT_PULLUP);
	pinMode(BUTTON1_PIN, INPUT_PULLUP);

	attachInterrupt(0, doEncoder0, FALLING);  // encoder pin on interrupt 0 - pin 2
	attachInterrupt(1, doEncoder1, FALLING);  // encoder pin on interrupt 1 - pin 3

	
	I2CStart(I2C_ADDR);
	I2CWriteByte(VOLUME);
	I2CWriteByte(VOLUME_MUTE); // direct dB representation (0-40)
	I2CStop();  
	delay(2);
	I2CStart(I2C_ADDR);
	I2CWriteByte(SPEAKER_RIGHT | AUTO_INC);
	I2CWriteByte(SPEAKER_UNMUTE); // right
	I2CWriteByte(SPEAKER_UNMUTE); // left
	I2CStop();      
	delay(2);

	// smooth volume up to 50%
	for(byte i=0;i<20;i++){
		I2CStart(I2C_ADDR);
		I2CWriteByte(VOLUME);
		I2CWriteByte(40-i); // direct dB representation (0-40)
		I2CStop();      
		delay(100);
	}
}

void loop() {
	char encVal = rotaryEncRead(MAIN_ENCODER);
	while (Serial.available() > 0) {
		int subaddr = Serial.parseInt();
		int data = Serial.parseInt();

		// look for the newline. That's the end of sentence:
		if (Serial.read() == '\n') {
			switch (subaddr) {
				case INPUT_SELECT: 
					Serial.print("INPUT: "); Serial.println(data);
					I2CStart(I2C_ADDR);
					I2CWriteByte(INPUT_SELECT);
					I2CWriteByte(byte(4-data));
					I2CStop();      
					break;
				case INPUT_GAIN: 
					Serial.print("INPUT GAIN (dB): "); Serial.println(data);
					I2CStart(I2C_ADDR);
					I2CWriteByte(INPUT_GAIN);
					I2CWriteByte(byte(data/2));
					I2CStop();      
					break;
				case VOLUME: 
					Serial.print("VOLUME (dB): "); Serial.println(data);
					I2CStart(I2C_ADDR);
					I2CWriteByte(VOLUME);
					I2CWriteByte(byte(40-data));
					I2CStop();      
					break;
				case BASS: 
					Serial.print("BASS (dB): "); Serial.println(data);
					I2CStart(I2C_ADDR);
					I2CWriteByte(BASS);
					I2CWriteByte(convert_dB2byte(data));
					I2CStop();      
					break;
				case TREBLE: 
					Serial.print("TREBLE (dB): "); Serial.println(data);
					I2CStart(I2C_ADDR);
					I2CWriteByte(TREBLE);
					I2CWriteByte(convert_dB2byte(data));
					I2CStop();      
					break;
				default: // mute/unmute speakers
					byte dat = (data==0 ? SPEAKER_MUTE : SPEAKER_UNMUTE);
					I2CStart(I2C_ADDR);
					I2CWriteByte(SPEAKER_RIGHT | AUTO_INC);
					I2CWriteByte(dat); // right
					I2CWriteByte(dat); // left
					I2CStop();      
			}
			Serial.println();
		}
	}
}

// input: -14 to +14 (in 2dB steps eg -14,-12,-10...)
// output: 0 to 15 (see datasheet)
byte convert_dB2byte(int dB){
	byte val;
	if(dB<0){val=(14+dB)/2;}else{val=(14-dB)/2+8;}
	return val;
}

char rotaryEncRead(byte rotaryNr) {
  noInterrupts();
  char tmp = (rotaryNr==MAIN_ENCODER) ? encoder0Pos : encoder1Pos;
  if(rotaryNr==MAIN_ENCODER){encoder0Pos=0;}else{encoder1Pos=0;}  // reset encoders
  interrupts();
  if(!bitRead(PIND,(rotaryNr==MAIN_ENCODER) ? BUTTON0_PIN : BUTTON1_PIN)){tmp=127;}
  return tmp;
}

void doEncoder0() {
    // If interrupts come faster than 5ms, assume it's a bounce and ignore
    if (millis() - encoder0millis > 5) {
        if (!bitRead(PIND,encoder0PinB))
            encoder0Pos++;
        else
            encoder0Pos--;
        }
    encoder0millis = millis();
  // here is code to process encoder change...
  encoder0Change = 1;
}

void doEncoder1() {
    // If interrupts come faster than 5ms, assume it's a bounce and ignore
    if (millis() - encoder1millis > 5) {
        if (!bitRead(PIND,encoder1PinB))
            encoder1Pos++;
        else
            encoder1Pos--;
        }
    encoder1millis = millis();
  // here is code to process encoder change...
  encoder1Change = 1;
}

