//#include "TDA7440.h"

/*
Power on settings:
INPUT SELECTION: IN2
INPUT GAIN: 28dB
VOLUME: MUTE
BASS: 0dB
TREBLE: 2dB
SPEAKER: MUTE
*/

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


void initAudio(){
	// we will mute the volume stage, but unmute the speaker (out stage)
	Wire.beginTransmission(TDA_I2C_ADDR);
	Wire.write(VOLUME);
	Wire.write(VOLUME_MUTE); // direct dB representation (0-40)
	Wire.endTransmission();  
	delay(1);
	Wire.beginTransmission(TDA_I2C_ADDR);
	Wire.write(SPEAKER_RIGHT | AUTO_INC);
	Wire.write(SPEAKER_UNMUTE); // right
	Wire.write(SPEAKER_UNMUTE); // left
	Wire.endTransmission();      
	delay(1);
}

//0 to 48
void setVolume(int dataP){
	// 0 - mute
	byte data = map(dataP,1,48,47,0); // convert 1-48 to 47-0dB
	Wire.beginTransmission(TDA_I2C_ADDR);
	Wire.write(VOLUME);
	if(dataP==0){Wire.write(VOLUME_MUTE);}else{Wire.write(data);}
	Wire.endTransmission(); 
#ifdef DEBUG
  Serial.print("Volume: ");
  Serial.println(dataP);
#endif
	delay(1);
}



// input: -14 to +14 (in 2dB steps eg -14,-12,-10...)
// output: 0 to 15 (see datasheet)
byte convert_dB2byte(int dB){
  byte val;
  if(dB<0){val=(14+dB)/2;}else{val=(14-dB)/2+8;}
  return val;
}


void setInput(byte data){
	Wire.beginTransmission(TDA_I2C_ADDR);
	Wire.write(INPUT_SELECT);
	Wire.write(data);
	Wire.endTransmission();      
#ifdef DEBUG
  Serial.print("Input: ");
  Serial.println(data);
#endif
	delay(1);
}

//-14 to 14
void setBass(int data){
	Wire.beginTransmission(TDA_I2C_ADDR);
	Wire.write(BASS);
	Wire.write(convert_dB2byte(data));
	Wire.endTransmission();      
#ifdef DEBUG
  Serial.print("Bass: ");
  Serial.println(data);
#endif
	delay(1);
}

//-14 to 14
void setTreble(int data){
	Wire.beginTransmission(TDA_I2C_ADDR);
	Wire.write(TREBLE);
	Wire.write(convert_dB2byte(data));
	Wire.endTransmission();      
#ifdef DEBUG
  Serial.print("Treble: ");
  Serial.println(data);
#endif
	delay(1);
}

int getInputGain(byte curInp){
  switch (curInput) {
    case INPUT_MIC:
      return gainMIC;
      break;
    case INPUT_GUITAR:
      return gainGUITAR;
      break;
    case INPUT_BT:
      return gainBT;
      break;
    case INPUT_MIXER:
      return gainMIXER;
      break;
  }  
}
//0 to 15
void setInputGain(byte data, byte curInp){
  Wire.beginTransmission(TDA_I2C_ADDR);
  Wire.write(INPUT_GAIN);
  Wire.write(data);
  Wire.endTransmission();      
#ifdef DEBUG
  Serial.print("Input Gain: ");
  Serial.println(data);
#endif
  delay(1);
  switch (curInp) {
    case INPUT_MIC:
      gainMIC = data;
      break;
    case INPUT_GUITAR:
      gainGUITAR = data;
      break;
    case INPUT_BT:
      gainBT = data;
      break;
    case INPUT_MIXER:
      gainMIXER = data;
      break;
  }  
}
