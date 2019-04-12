#include "i2c.c"
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

// TDA7440 address
#define I2C_ADDR            0b10001000

// TDA7440 subaddress (function)
#define INPUT_SELECT		0x00 // 4 inputs
#define INPUT_GAIN			0x01 // 2dB steps [0-15]=[0-30] (0dB to +30dB)
#define VOLUME				0x02 // 1dB steps [0-40]=[0-40] (0dB to -40dB) or MUTE
#define BASS				0x03
#define TREBLE				0x05
#define SPEAKER_RIGHT		0x06 // for Balance - not using as we input mono (only for muting).
#define SPEAKER_LEFT		0x07 // for Balance - not using as we input mono (only for muting).

// TDA7440 function values
#define INPUT_1				0x03
#define INPUT_2				0x02
#define INPUT_3				0x01
#define INPUT_4				0x00

#define VOLUME_MUTE			0b01111111


#define SPEAKER_MUTE		0b01111111
#define SPEAKER_UNMUTE		0b00000000

// TDA7440 autoincrement flag
#define AUTO_INC			0x10

void setup() {
	Serial.begin(115200);
	I2CInit();
	delay(2);
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
		I2CWriteByte(i); // direct dB representation (0-40)
		I2CStop();      
		delay(100);
	}
}

void loop() {
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
					I2CWriteByte(byte(data));
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
					I2CWriteByte(byte(data));
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
					I2CStart(I2C_ADDR);
					I2CWriteByte(SPEAKER_RIGHT | AUTO_INC);
					I2CWriteByte((data==0 ? SPEAKER_MUTE : SPEAKER_UNMUTE)); // right
					I2CWriteByte((data==0 ? SPEAKER_MUTE : SPEAKER_UNMUTE)); // left
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