//#include "i2c.c"
#include <Wire.h>
#include <U8g2lib.h>
#include "encoder.ino"


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

U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

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
//#define I2C_ADDR            0b10001000  // 0x88 - no Wire library is used
#define I2C_ADDR            0x44  // for Wire library

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

void setup() {
	//I2CInit();
	Serial.begin(115200);
	u8g2.begin();
	u8g2.setFlipMode(0);

	encoderInit();

	// Show message MUTED
	u8g2.firstPage();
	do {
		u8g2.setFont(u8g2_font_fub17_tr);
		u8g2.drawStr(10,40,"MUTED");
	} while (u8g2.nextPage());

	// When power on then TDA is starting in muted mode, but lets repeat it (mute volume, but unmute speakers)
	muteAudio();

/*
	// smooth volume up to 50%
	for(byte i=0;i<20;i++){
		I2CStart(I2C_ADDR);
		I2CWriteByte(VOLUME);
		I2CWriteByte(40-i); // direct dB representation (0-40)
		I2CStop();      
		delay(100);
	}
*/

}

void loop() {
 
	char encVal = rotaryEncRead(MAIN_ENCODER);
	while (Serial.available() > 0) {
		int subaddr = Serial.parseInt();
		int data = Serial.parseInt();

		// look for the newline. That's the end of sentence:
		if (Serial.read() == '\n') {
			Wire.beginTransmission(I2C_ADDR);
			switch (subaddr) {
				case INPUT_SELECT: 
					Serial.print("INPUT: "); Serial.println(data);
					Wire.write(INPUT_SELECT);
					Wire.write(byte(4-data));
					break;
				case INPUT_GAIN: 
					Serial.print("INPUT GAIN (dB): "); Serial.println(data);
					Wire.write(INPUT_GAIN);
					Wire.write(byte(data/2));
					break;
				case VOLUME: 
					Serial.print("VOLUME (dB): "); Serial.println(data);
					Wire.write(VOLUME);
					Wire.write(byte(40-data));
					break;
				case BASS: 
					Serial.print("BASS (dB): "); Serial.println(data);
					Wire.write(BASS);
					Wire.write(convert_dB2byte(data));
					break;
				case TREBLE: 
					Serial.print("TREBLE (dB): "); Serial.println(data);
					Wire.write(TREBLE);
					Wire.write(convert_dB2byte(data));
					break;
				default: // mute/unmute speakers
					byte dat = (data==0 ? SPEAKER_MUTE : SPEAKER_UNMUTE);
					Wire.write(SPEAKER_RIGHT | AUTO_INC);
					Wire.write(dat); // right
					Wire.write(dat); // left
			}
			Wire.endTransmission();      
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



