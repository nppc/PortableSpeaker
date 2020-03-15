#define DEBUG

// for encoder readings use bitRead for speed.
// this requires to use AVR original pin numbers
#define BUTTON0_PIN		4 	// PD4
#define BUTTON1_PIN		5	// PD5
#define encoder0PinA	2	// PD2 Interrupt pin (coupled with capacitor to GND)
#define encoder0PinB	6	// PD6
#define encoder1PinA	3	// PD3 Interrupt pin (coupled with capacitor to GND)
#define encoder1PinB	7	// PD7
// this pins are used with Arduino regular functions
#define LED_PIN			8 	// 1 Wire LEDs
#define IN1_SENSE_PIN	9	// MIC/INST 
#define VSENSE_PIN		A7	// Battery charge level

// Datasheet says 0x88 but that is the 8 bit address.
// Wire.h automatically appends the extra (lsb write) bit, 
// so 0x44 if Wire library is used.
//#define TDA_I2C_ADDR            0b10001000  // 0x88 - no Wire library is used
#define TDA_I2C_ADDR            0x44  // for Wire library
#define MCP_I2C_ADDR            0x2C  // for Wire library

// to identify encoder 
#define MAIN_ENCODER  1
#define INPUT_ENCODER 0

#define INPUT_MIC 2
#define INPUT_GUITAR 3
#define INPUT_BT 1
#define INPUT_MIXER 0

U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

byte curMainScreen = 0;
int curVolume = 0;  // in percents 0-100 (0=mute, 1=lowest volume, 100=highest volume)
int8_t curBass;  // from -14 to +14
int8_t curTreble;  // from -14 to +14
int curHeadphones;  // from 0 to 50
byte curInput;
byte encInputChange = 0; // 0 - change Input channel; 1 - change Inout Gain
//byte curGain=14; // default from datasheet (28dB)
byte gainMIC;
byte gainGUITAR;
byte gainBT;
byte gainMIXER;
