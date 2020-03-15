#include <Adafruit_NeoPixel.h>


#include <Wire.h>
#include <U8g2lib.h>
#include "AudioProcessor.h"
#include "encoder.h"
#include "display.h"
#include "TDA7440.h"
#include "MCP4461.h"
#include "LED1W.h"
#include "eepromroutines.h"
//#include "i2c.c"

unsigned long defaultScreenTiming;	// show default screen if encoders are inactive for more that 30 sec

void setup() {
  pixels.begin();
  pixels.clear();
  ledPWR_on();

  Wire.begin();
#ifdef DEBUG
  Serial.begin(115200);
#endif
  u8g2.begin();
  u8g2.setFlipMode(0);

  encoderInit();

  restoreDataEEPROM(); // restore values for Input and gain

  digPot_init();

  // Show message MUTED
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_fub17_tr);
    u8g2.setCursor(20, 40);
    u8g2.print(F("MUTED"));
  } while (u8g2.nextPage());

  initAudio(); // When power on then TDA is starting in muted mode, but lets repeat it (mute volume, but unmute speakers)
  setBass(curBass);
  setTreble(curTreble);

  showInputLed(curInput);
  setInput(curInput);
  setInputGain(getInputGain(curInput), curInput);

  BatCharge(100); // Percents chagred

  do {
    delay(5);
    char tmpM = rotaryEncRead(MAIN_ENCODER);
    char tmpI = rotaryEncRead(INPUT_ENCODER);
    if(tmpM !=0 || tmpI!=0){
      if(tmpM==127){waitEncoderReleased(MAIN_ENCODER);}
      if(tmpI==127){waitEncoderReleased(INPUT_ENCODER);}
      encoder1Pos = tmpM;
      encoder0Pos = tmpI;      
      break;
    }
  } while (1);
  //showVolume();
  //changeVolumeDisplay(curVolume);
  defaultScreenTiming = millis();


}

void loop() {
  char encValMain = rotaryEncRead(MAIN_ENCODER);
  char encValInp = rotaryEncRead(INPUT_ENCODER);
  if (encValMain != 0 || encValInp != 0 ) {
    defaultScreenTiming = millis();
  } else if (millis() > defaultScreenTiming + 30000 && curMainScreen != 0) {
    curMainScreen = 0;
    showDefaultScreen();
    encInputChange = 0; // also change back to select input...
    saveCurDataEEPROM();  // save current data to EEPROM
  }
  switch (curMainScreen) {
    case 0: //Default screen
      if (encValMain != 0 && encValMain != 127) {
        curMainScreen = 1;
        showVolume();
        changeVolumeDisplay(curVolume);
      } else if (encValMain == 127) {
        waitEncoderReleased(MAIN_ENCODER);  // it adds 1ms delay
        curMainScreen = 2;
        showBass();
        changeTembreDisplay(curBass);
      }
      break;
    case 1: //Volume
      if (encValMain != 0 && encValMain != 127) {
        curVolume = curVolume + encValMain;
        if (curVolume < 0) {
          curVolume = 0;
        }
        if (curVolume > 48) {
          curVolume = 48;
        }
        changeVolumeDisplay(curVolume);
        setVolume(curVolume);
      } else if (encValMain == 127) {
        waitEncoderReleased(MAIN_ENCODER);  // it adds 1ms delay
        curMainScreen = 2;
        showBass();
        changeTembreDisplay(curBass);
      }
      break;
    case 2: //Bass
      if (encValMain != 0 && encValMain != 127) {
        curBass = curBass + encValMain;
        if (curBass < -14) {
          curBass = -14;
        }
        if (curBass > 14) {
          curBass = 14;
        }
        changeTembreDisplay(curBass);
        setBass(curBass);
      } else if (encValMain == 127) {
        waitEncoderReleased(MAIN_ENCODER);  // it adds 1ms delay
        curMainScreen = 3;
        showTreble();
        changeTembreDisplay(curTreble);
      }
      break;
    case 3: //Treble
      if (encValMain != 0 && encValMain != 127) {
        curTreble = curTreble + encValMain;
        if (curTreble < -14) {
          curTreble = -14;
        }
        if (curTreble > 14) {
          curTreble = 14;
        }
        changeTembreDisplay(curTreble);
        setTreble(curTreble);
      } else if (encValMain == 127) {
        waitEncoderReleased(MAIN_ENCODER);  // it adds 1ms delay
        curMainScreen = 4;
        showHeadphones();
        changeVolumeDisplay(curHeadphones);
      }
      break;
    case 4: //Headphones
      if (encValMain != 0 && encValMain != 127) {
        curHeadphones = curHeadphones + encValMain;
        if (curHeadphones < 0) {
          curHeadphones = 0;
        }
        if (curHeadphones > 50) {
          curHeadphones = 50;
        }
        changeVolumeDisplay(curHeadphones);
        delay(2);
        digPot_setdB(0, (byte)curHeadphones);
#ifdef DEBUG
        Serial.print("Headphones: ");
        Serial.println(curHeadphones);
#endif
        delay(2);
      } else if (encValMain == 127) {
        waitEncoderReleased(MAIN_ENCODER);  // it adds 1ms delay
        curMainScreen = 1;
        showVolume();
        changeVolumeDisplay(curVolume);
      }
      break;
    case 9: //Input
      if (encValMain != 0) {
        // swith from input to volume regulation if main rotated
        curMainScreen = 1;
        showVolume();
        changeVolumeDisplay(curVolume);
      }
      break;
  }
  // Check input encoder
  if (encValInp != 0 && encValInp != 127) {
    // change to next input
    if (encInputChange == 0) {
      curMainScreen = 9; // Screen for selecting/adjusting inputs
      switch (curInput) {
        case INPUT_MIC:
          curInput = (encValInp > 0 ? INPUT_GUITAR : INPUT_MIXER);
          break;
        case INPUT_GUITAR:
          curInput = (encValInp > 0 ? INPUT_BT : INPUT_MIC);
          break;
        case INPUT_BT:
          curInput = (encValInp > 0 ? INPUT_MIXER : INPUT_GUITAR);
          break;
        case INPUT_MIXER:
          curInput = (encValInp > 0 ? INPUT_MIC : INPUT_BT);
          break;
      }
      // set input
      showInput(curInput);
      showInputLed(curInput);
      setInput(curInput);
      setInputGain(getInputGain(curInput), curInput);
      curMainScreen = 9; // something else to refresh screen later
    } else {
      // change Input Gain
      if (curMainScreen != 9) {
        curMainScreen = 9;
        showInputHeader();
      }
      int gain = (int)getInputGain(curInput) + encValInp;
      if (gain < 0) {
        gain = 0;
      }
      if (gain > 15) {
        gain = 15;
      }
      //curGain = gain;
      setInputGain(gain, curInput);
      changeGainDisplay(gain);
    }
  } else if (encValInp == 127) {
    curMainScreen = 9;
    waitEncoderReleased(INPUT_ENCODER);  // it adds 1ms delay
    if (encInputChange == 0) {
      encInputChange = 1;
      showInputHeader();
      changeGainDisplay(getInputGain(curInput));
    } else {
      encInputChange = 0;
      showInput(curInput);
    }
  }
  delay(1);	// just to prevent encoder reading to often (as rotaryEncRead disables interrupts shortly)

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
  */

}
