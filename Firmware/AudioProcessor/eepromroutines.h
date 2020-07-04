#include <EEPROM.h>

#define EEPROM_BASS_ADDR        3
#define EEPROM_TREBLE_ADDR      4
#define EEPROM_HEADPHONES_ADDR  5

#define EEPROM_CUR_INPUT_ADDR   6
#define EEPROM_MIC_GAIN_ADDR    7
#define EEPROM_GUITAR_GAIN_ADDR 8
#define EEPROM_BT_GAIN_ADDR     9
#define EEPROM_MIXER_GAIN_ADDR  10
#define EEPROM_MIXERMIC_ADDR    11
#define EEPROM_MIXERMUSIC_ADDR  12

void setDefaultEEPROM(void){
  EEPROM.update(EEPROM_CUR_INPUT_ADDR, INPUT_MIC);
  EEPROM.update(EEPROM_MIC_GAIN_ADDR, 14); // default from datasheet (28dB)
  EEPROM.update(EEPROM_GUITAR_GAIN_ADDR, 14); // default from datasheet (28dB)
  EEPROM.update(EEPROM_BT_GAIN_ADDR, 14); // default from datasheet (28dB)
  EEPROM.update(EEPROM_MIXER_GAIN_ADDR, 14); // default from datasheet (28dB)
  EEPROM.update(EEPROM_BASS_ADDR, 0); // 
  EEPROM.update(EEPROM_TREBLE_ADDR, 0); // 
  EEPROM.update(EEPROM_HEADPHONES_ADDR, 20); //
  EEPROM.update(EEPROM_MIXERMIC_ADDR, 25); 
  EEPROM.update(EEPROM_MIXERMUSIC_ADDR, 25); 
#ifdef DEBUG
  Serial.println(F("EEPROM initialized."));
#endif
}

void restoreDataEEPROM(void){
  // Reset to defaults if needed
  char tmp = EEPROM.read(EEPROM_CUR_INPUT_ADDR);
  if(tmp==0xFF){setDefaultEEPROM();}

  // restore data
  curInput = EEPROM.read(EEPROM_CUR_INPUT_ADDR);
  gainMIC = EEPROM.read(EEPROM_MIC_GAIN_ADDR);
  gainGUITAR = EEPROM.read(EEPROM_GUITAR_GAIN_ADDR);
  gainBT = EEPROM.read(EEPROM_BT_GAIN_ADDR);
  gainMIXER = EEPROM.read(EEPROM_MIXER_GAIN_ADDR);
  curBass = (int8_t)EEPROM.read(EEPROM_BASS_ADDR);
  curTreble = (int8_t)EEPROM.read(EEPROM_TREBLE_ADDR);
  curHeadphones = EEPROM.read(EEPROM_HEADPHONES_ADDR);
  gainMIXMIC = EEPROM.read(EEPROM_MIXERMIC_ADDR);
  gainMIXMUSIC = EEPROM.read(EEPROM_MIXERMUSIC_ADDR);
#ifdef DEBUG
  Serial.println(F("EEPROM data restored."));
#endif
}

void saveCurDataEEPROM(void){
  EEPROM.update(EEPROM_CUR_INPUT_ADDR, curInput);
  EEPROM.update(EEPROM_MIC_GAIN_ADDR, gainMIC);
  EEPROM.update(EEPROM_GUITAR_GAIN_ADDR, gainGUITAR);
  EEPROM.update(EEPROM_BT_GAIN_ADDR, gainBT);
  EEPROM.update(EEPROM_MIXER_GAIN_ADDR, gainMIXER);
  EEPROM.update(EEPROM_BASS_ADDR, curBass);
  EEPROM.update(EEPROM_TREBLE_ADDR, curTreble);
  EEPROM.update(EEPROM_HEADPHONES_ADDR, curHeadphones);
  EEPROM.update(EEPROM_MIXERMIC_ADDR, gainMIXMIC); 
  EEPROM.update(EEPROM_MIXERMUSIC_ADDR, gainMIXMUSIC); 
#ifdef DEBUG
  Serial.println(F("EEPROM data saved."));
#endif
}
