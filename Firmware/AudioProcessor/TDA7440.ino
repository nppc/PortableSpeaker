/*
Power on settings:
INPUT SELECTION: IN2
INPUT GAIN: 28dB
VOLUME: MUTE
BASS: 0dB
TREBLE: 2dB
SPEAKER: MUTE
*/

void muteAudio(){
	// we will mute the volume stage, but unmute the speaker (out stage)
	Wire.beginTransmission(I2C_ADDR);
	Wire.write(VOLUME);
	Wire.write(VOLUME_MUTE); // direct dB representation (0-40)
	Wire.endTransmission();  
	delay(2);
	Wire.beginTransmission(I2C_ADDR);
	Wire.write(SPEAKER_RIGHT | AUTO_INC);
	Wire.write(SPEAKER_UNMUTE); // right
	Wire.write(SPEAKER_UNMUTE); // left
	Wire.endTransmission();      
	delay(2);
}