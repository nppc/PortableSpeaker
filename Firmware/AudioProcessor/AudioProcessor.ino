//#include <Wire.h>
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

// I2C address
#define I2C_ADDR            0b10001000

// I2C function selection
#define INPUT_SELECT        0x00
#define INPUT_GAIN          0x01
#define PREAMP              0x02
#define BASS                0x03
#define TREBLE              0x05
#define VOLUME_RIGHT        0x06
#define VOLUME_LEFT         0x07

#define SPEAKER_MUTE        0b01111111

// I2C autoincrement flag
#define AUTO_INC            0x10

void setup() {
  Serial.begin(115200);
  //Wire.begin(); // join i2c bus (address optional for master)
  I2CInit();
  //Wire.setClock(10000);
}

byte val = 0;

void loop() {
  //while (Serial.available() > 0) {
  //  int subaddr = Serial.parseInt();
  //  int data = Serial.parseInt();

    // look for the newline. That's the end of your sentence:
   // if (Serial.read() == '\n') {

      // print the three numbers in one string as hexadecimal:
//      Serial.print("subaddr: ");Serial.println(subaddr, HEX);
//      Serial.print("data: ");Serial.println(data, HEX);
//      Serial.println();
    I2CStart(I2C_ADDR);
    I2CWriteByte(VOLUME_RIGHT | AUTO_INC);
    I2CWriteByte(0);
    I2CWriteByte(0);
    I2CStop();      //Wire.beginTransmission(I2C_ADDR); // tda7440
      //Wire.write(VOLUME_RIGHT | AUTO_INC);       // subaddress
      //Wire.write(0);             // data
      //Wire.write(0);             // data
      //Wire.endTransmission();
      delay(10);
    I2CStart(I2C_ADDR);
    I2CWriteByte(PREAMP);
    I2CWriteByte(0);
    I2CStop();      
    //Wire.beginTransmission(I2C_ADDR); // tda7440
      //Wire.beginTransmission(I2C_ADDR); // tda7440
      //Wire.write(PREAMP);       // subaddress
      //Wire.write(0);             // data
      //Wire.endTransmission();
      delay(10);
/*
      Wire.beginTransmission(0x88); // tda7440
      Wire.write(byte(subaddr));       // subaddress
      Wire.write(byte(data));             // data
      Wire.endTransmission();
*/
//    }
//  }
  
//  delay(500);
}

