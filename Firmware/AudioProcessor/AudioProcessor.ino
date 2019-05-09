#include <Wire.h>
#include <U8g2lib.h>
#include "AudioProcessor.h"
#include "encoder.h"
#include "display.h"
#include "TDA7440.h"
//#include "i2c.c"

int curVolume = 0;	// in percents 0-100 (0=mute, 1=lowest volume, 100=highest volume)
int curBass = 0;	// from -14 to +14
int curTreble = 0;	// from -14 to +14
byte curMainScreen = 0;

void setup() {
	//I2CInit();
  Wire.begin();
	Serial.begin(115200);
	u8g2.begin();
	u8g2.setFlipMode(0);

	encoderInit();

	// Show message MUTED
	u8g2.firstPage();
	do {
		u8g2.setFont(u8g2_font_fub17_tr);
		u8g2.drawStr(20,40,"MUTED");
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
	do{delay(5);} while(rotaryEncRead(MAIN_ENCODER)==0);
	curMainScreen=1;	//Volume
	showVolume();
	changeVolumeDisplay(curVolume);
}

void loop() {
 
	char encVal = rotaryEncRead(MAIN_ENCODER);
	switch (curMainScreen) {
		case 1: //Volume
			if(encVal!=0 && encVal!=127){
				curVolume = curVolume + encVal;
				if(curVolume<0){curVolume=0;}
				if(curVolume>48){curVolume=48;}
				changeVolumeDisplay(curVolume);
				setVolume(curVolume);
			}else if(encVal==127){
				curMainScreen=2;
				showBass();
				changeTembreDisplay(curBass);
			}
			break;
		case 2: //Bass
			if(encVal!=0 && encVal!=127){
				curBass = curBass + encVal;
				if(curBass<-14){curBass=-14;}
				if(curBass>14){curBass=14;}
				changeTembreDisplay(curBass);
				setBass(curBass);
			}else if(encVal==127){
				curMainScreen=3;
				showTreble();
				changeTembreDisplay(curTreble);
			}		
			break;
		case 3: //Treble
			if(encVal!=0 && encVal!=127){
				curTreble = curTreble + encVal;
				if(curTreble<-14){curTreble=-14;}
				if(curTreble>14){curTreble=14;}
				changeTembreDisplay(curTreble);
				setBass(curTreble);
			}else if(encVal==127){
				curMainScreen=1;
				showVolume();
				changeVolumeDisplay(curVolume);
			}		
			break;
	}
	delay(1);	// just to prevent encoder reading to often (as rotaryEncRead disables interrupts shortly)
	
	while (Serial.available() > 0) {
		int subaddr = Serial.parseInt();
		int data = Serial.parseInt();

		// look for the newline. That's the end of sentence:
		if (Serial.read() == '\n') {
			/*Wire.beginTransmission(I2C_ADDR);
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
			Serial.println();*/
		}
	}
}




