#include <Wire.h>
#include <U8g2lib.h>
#include "AudioProcessor.h"
#include "encoder.h"
#include "display.h"
#include "TDA7440.h"
#include "MCP4461.h"
//#include "i2c.c"

byte curMainScreen = 0;
unsigned long defaultScreenTiming;	// show default screen if encoders are inactive for more that 30 sec

void setup() {
	Wire.begin();
	Serial.begin(115200);
	u8g2.begin();
	u8g2.setFlipMode(0);

	encoderInit();

	digPot_init();

	// Show message MUTED
	u8g2.firstPage();
	do {
		u8g2.setFont(u8g2_font_fub17_tr);
		u8g2.setCursor(20,40);
		u8g2.print(F("MUTED"));
	} while (u8g2.nextPage());

	initAudio(); // When power on then TDA is starting in muted mode, but lets repeat it (mute volume, but unmute speakers)
	setBass(curBass);
	setTreble(curTreble);

	do{delay(5);} while(rotaryEncRead(MAIN_ENCODER)==0);
	curMainScreen=1;	//Volume
	showVolume();
	changeVolumeDisplay(curVolume);
	waitEncoderReleased(MAIN_ENCODER); 
	defaultScreenTiming = millis();
}

void loop() {
	char encVal = rotaryEncRead(MAIN_ENCODER);
	if(encVal!=0){
		defaultScreenTiming = millis();
	}else if(millis()> defaultScreenTiming + 30000 && curMainScreen!=0){
		curMainScreen = 0;
		showDefaultScreen();
	}
	switch (curMainScreen) {
		case 0: //Default screen
			if(encVal!=0 && encVal!=127){
				curMainScreen=1;
				showVolume();
				changeVolumeDisplay(curVolume);
			}else if(encVal==127){
				waitEncoderReleased(MAIN_ENCODER);  // it adds 1ms delay
				curMainScreen=2;
				showBass();
				changeTembreDisplay(curBass);
			}
			break;
		case 1: //Volume
			if(encVal!=0 && encVal!=127){
				curVolume = curVolume + encVal;
				if(curVolume<0){curVolume=0;}
				if(curVolume>48){curVolume=48;}
				changeVolumeDisplay(curVolume);
				setVolume(curVolume);
			}else if(encVal==127){
				waitEncoderReleased(MAIN_ENCODER);  // it adds 1ms delay
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
				waitEncoderReleased(MAIN_ENCODER);  // it adds 1ms delay
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
				setTreble(curTreble);
			}else if(encVal==127){
				waitEncoderReleased(MAIN_ENCODER);  // it adds 1ms delay
				curMainScreen=4;
				showHeadphones();
				changeVolumeDisplay(curHeadphones);
			}		
			break;
		case 4: //Headphones
			if(encVal!=0 && encVal!=127){
				curHeadphones = curHeadphones + encVal;
				if(curHeadphones<0){curHeadphones=0;}
				if(curHeadphones>49){curHeadphones=49;}
				changeVolumeDisplay(curHeadphones);
				delay(2);
				digPot_setdB(0,49-(byte)curHeadphones);
				Serial.println(curHeadphones);
				delay(2);
			}else if(encVal==127){
				waitEncoderReleased(MAIN_ENCODER);  // it adds 1ms delay
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




