#define TCON0	(0x04<<4)// Register 0 for connect/disconnct pot pins
#define TCON1	(0x0A<<4)// Register 1 for connect/disconnct pot pins
#define POT0	(0x00<<4) //0x00
#define POT1	(0x01<<4) //0x01
#define POT2	(0x06<<4) //0x06
#define POT3	(0x07<<4) //0x07


void digPot_test(){
	Wire.beginTransmission(MCP_I2C_ADDR);
	Wire.write(POT2);
	Wire.write(50);
	Wire.endTransmission();  
	delay(100);
do{
	Wire.beginTransmission(MCP_I2C_ADDR);
	Wire.write(TCON0);
	Wire.write(255); // all pins are connected
	Wire.endTransmission();  
	delay(5000);
	Wire.beginTransmission(MCP_I2C_ADDR);
	Wire.write(TCON0);
	Wire.write(254); // 0B pin is disconnected
	Wire.endTransmission();  
	delay(5000);
}while(1==1);
}