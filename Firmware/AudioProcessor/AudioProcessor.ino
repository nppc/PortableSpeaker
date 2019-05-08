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



int curVolume = 0;	// in percents 0-100 (0=mute, 1=lowest volume, 100=highest volume)
int curBass = 0;	// from -14 to +14
int curTreble = 0;	// from -14 to +14

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

	initAudio(); // When power on then TDA is starting in muted mode, but lets repeat it (mute volume, but unmute speakers)
	setBass(curBass);
	setTreble(curTreble);

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
	do{delay(5);}while(rotaryEncRead(MAIN_ENCODER)==0)
	showVolume();
	changeVolumeDisplay(curVolume);
}

void loop() {
 
	char encVal = rotaryEncRead(MAIN_ENCODER);
	if(encVal!=0 && encVal!=127){
		curVolume = curVolume + encVal;
		if(curVolume<0){curVolume=0;}
		if(curVolume>100){curVolume=100;}
		changeVolumeDisplay(curVolume);
		setVolume(curVolume);
	}
	delay(1);	// just to prevent encoder reading to often (as rotaryEncRead disables interrupts shortly)
	
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
					Wire.write(byte(47-data));
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




