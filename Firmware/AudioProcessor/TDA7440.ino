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


void initAudio(){
	// we will mute the volume stage, but unmute the speaker (out stage)
	Wire.beginTransmission(I2C_ADDR);
	Wire.write(VOLUME);
	Wire.write(VOLUME_MUTE); // direct dB representation (0-40)
	Wire.endTransmission();  
	delay(1);
	Wire.beginTransmission(I2C_ADDR);
	Wire.write(SPEAKER_RIGHT | AUTO_INC);
	Wire.write(SPEAKER_UNMUTE); // right
	Wire.write(SPEAKER_UNMUTE); // left
	Wire.endTransmission();      
	delay(1);
}

//0 to 100
setVolume(int dataP){
	// 0 - mute
	byte data = map(dataP,1,100,47,0); // convert 1-100% to 47-0dB
	Wire.beginTransmission(I2C_ADDR);
	Wire.write(VOLUME);
	if(dataP==0){Wire.write(VOLUME_MUTE);}else{Wire.write(data);}
	Wire.endTransmission(); 
	delay(1);
}

//-14 to 14
setBass(int data){
	Wire.beginTransmission(I2C_ADDR);
	Wire.write(BASS);
	Wire.write(convert_dB2byte(data));
	Wire.endTransmission();      
	delay(1);
}

//-14 to 14
setTreble(int data){
	Wire.beginTransmission(I2C_ADDR);
	Wire.write(TREBLE);
	Wire.write(convert_dB2byte(data));
	Wire.endTransmission();      
	delay(1);
}


// input: -14 to +14 (in 2dB steps eg -14,-12,-10...)
// output: 0 to 15 (see datasheet)
byte convert_dB2byte(int dB){
	byte val;
	if(dB<0){val=(14+dB)/2;}else{val=(14-dB)/2+8;}
	return val;
}