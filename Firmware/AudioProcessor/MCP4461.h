#define TCON0	(0x04<<4)// Register 0 for connect/disconnct pot(0,1) pins
#define		TCON0_R1HW	7
#define		TCON0_R1A	6
#define		TCON0_R1W	5
#define		TCON0_R1B	4
#define		TCON0_R0HW	3
#define		TCON0_R0A	2
#define		TCON0_R0W	1
#define		TCON0_R0B	0

#define TCON1	(0x0A<<4)// Register 1 for connect/disconnct pot(2,3) pins
#define		TCON1_R3HW	7
#define		TCON1_R3A	6
#define		TCON1_R3W	5
#define		TCON1_R3B	4
#define		TCON1_R2HW	3
#define		TCON1_R2A	2
#define		TCON1_R2W	1
#define		TCON1_R2B	0

#define POT0	(0x00<<4) //0x00
#define POT1	(0x01<<4) //0x01
#define POT2	(0x06<<4) //0x06
#define POT3	(0x07<<4) //0x07

#define POTINCCMD	(0b01<<2)
#define POTDECCMD	(0b10<<2)
#define POTREADCMD	(0b11<<2)

// 0dB = 256
const prog_uint8_t dBlogTable[] PROGMEM = {
	228,	//-1dB
	203,	//-2dB
	181,	//-3dB
	162,	//-4dB
	144,	//-5dB
	128,	//-6dB
	114,	//-7dB
	102,	//-8dB
	91,	//-9dB
	81,	//-10dB
	72,	//-11dB
	64,	//-12dB
	57,	//-13dB
	51,	//-14dB
	46,	//-15dB
	41,	//-16dB
	36,	//-17dB
	32,	//-18dB
	29,	//-19dB
	26,	//-20dB
	23,	//-21dB
	20,	//-22dB
	18,	//-23dB
	16,	//-24dB
	14,	//-25dB
	13,	//-26dB
	11,	//-27dB
	10,	//-28dB
	9,	//-29dB
	8,	//-30dB
	7,	//-31dB
	6,	//-32dB
	6,	//-33dB
	5,	//-34dB
	5,	//-35dB
	4,	//-36dB
	4,	//-37dB
	4,	//-38dB
	3,	//-39dB
	3,	//-40dB
	3,	//-41dB
	2,	//-42dB
	2,	//-43dB
	2,	//-44dB
	2,	//-45dB
	2,	//-46dB
	2,	//-47dB
	1,	//-48dB
	0,	// MUTE
	
};

void digPot_init(){
	uint8_t tcon0val = digPot_readCommand(TCON0);	// get current value
	// make sure, POT0 is fully connected
	tcon0val != (1<<TCON0_R0A)+(1<<TCON0_R0W)+(1<<TCON0_R0B);
	Wire.beginTransmission(MCP_I2C_ADDR);
	Wire.write(TCON0);
	Wire.write(tcon0val); // all pins are connected
	Wire.endTransmission();  
}

// Set command directly
// val = 0 - 256
// pot = 0 - 3
void digPot_sendCommand(uint8_t pot, uint16_t val){
	// find command for selected potentsiometer
	uint8_t command;
	command = pot;
	// if value is 256 then add a 9th bit to the command's 0 bit
	if(val==256){command++;val=0;}
	Wire.beginTransmission(MCP_I2C_ADDR);
	Wire.write(command);
	Wire.write((uint8_t)val);	// send the rest 8 bits
	Wire.endTransmission();
}

uint16_t digPot_readCommand(uint8_t cmd){
	uint16_t val = 0;
	uint8_t command;
	command = cmd;
	cmd |= POTREADCMD; 
	//send command byte
	Wire.beginTransmission(MCP_I2C_ADDR);
	Wire.write(command);
	Wire.endTransmission(false); //do not release bus
	Wire.requestFrom(MCP_I2C_ADDR,2); // we are waiting for 2 bytes
	//read the register
	uint8_t i = 0;
	while(Wire.available()){ 
		val |= Wire.read();
		if (i==0) val = val<<8;
		i++;
	}
	return val;
}

//set resistance according to dB value
// 0 - 49 (49=MUTE?)
void digPot_setdB(uint8_t pot, uint8_t dBval){
	// find command for selected potentsiometer
	uint8_t val;
	uint8_t command;
	switch (pot) {
		case 0:
			command = POT0;
			break;
		case 1:
			command = POT1;
			break;
		case 2:
			command = POT2;
			break;
		case 3:
			command = POT3;
	}
	// get a wiper position from dB
	if(dBval==0){val=256;}else{val =  pgm_read_byte_near(dBlogTable + dBval);}
	digPot_sendCommand(command, val);
}



//change resistance according to dB value (smoothly)
// 0 - 49 (49=MUTE?)
void digPot_changedB(uint8_t pot, uint8_t dBval){
	// find command for selected potentsiometer
	uint8_t val;
	uint8_t command;
	switch (pot) {
		case 0:
			command = POT0;
			break;
		case 1:
			command = POT1;
			break;
		case 2:
			command = POT2;
			break;
		case 3:
			command = POT3;
	}
	// first - read a current position of wiper
	uint16_t wCurPos = digPot_getR(pot);
	uint16_t wNewPos = 0;

	// get a wiper position from dB
	if(dBval==0){
		wNewPos=256; // this value is missing from the lookup table in sake of table size
	}else{
		wNewPos =  pgm_read_byte_near(dBlogTable + dBval); 
	}
	// Smoothly change the wiper position to the desired one with continuous write (inc/dec).
	// 1. Decide we should inc or dec and how much...
	uint16_t cmdCntr;
	if(wCurPos<wNewPos){
		command |= POTINCCMD; //inc
		cmdCntr = wNewPos-wCurPos;
	}else{
		command |= POTDECCMD; //dec
		cmdCntr = wCurPos-wNewPos;
	}
	// only change the wiper if there is a need
	if(cmdCntr!=0){
		Wire.beginTransmission(MCP_I2C_ADDR);
		for(uint16_t i = 0;i<cmdCntr;i++){Wire.write(command);} // we supply only commands (see datasheet)
		Wire.endTransmission();
	}
}


//return the value for a specific wiper
uint16_t digPot_getR(uint8_t pot){
	uint16_t val = 0;
	uint8_t command;
	switch (pot) {
		case 0:
			command = POT0;
			break;
		case 1:
			command = POT1;
			break;
		case 2:
			command = POT2;
			break;
		case 3:
			command = POT3;
	}
	val = digPot_readCommand(command);
	return val;
}