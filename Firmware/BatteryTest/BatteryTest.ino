// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      4

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  
  for(float i=0;i<101;i++){
    BatCharge(i);
    delay(200); // Delay for a period of time (in milliseconds).
  }

  for(float i=100;i>0;i--){
    BatDischarge(i);
    delay(200); // Delay for a period of time (in milliseconds).
  }

  for(int b=0;b<NUMPIXELS;b++){
    pixels.setPixelColor(b, pixels.Color(0,0,0));
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
  delay(1000);
}

void BatDischarge(float per){
byte r[4], g[4];
byte b=0;
byte val=80;
if(per>(100.0-12.5)){
    r[0]=0;g[0]=val+30;
    r[1]=0;g[1]=val;
    r[2]=0;g[2]=val;
    r[3]=0;g[3]=val;
  }else if(per>100.0-25.0){
    r[0]=0;g[0]=val+30;
    r[1]=0;g[1]=val;
    r[2]=0;g[2]=val;
    r[3]=val;g[3]=val;    
  }else if(per>100.0-37.5){
    r[0]=0;g[0]=val+30;
    r[1]=0;g[1]=val;
    r[2]=val;g[2]=val;
    r[3]=val;g[3]=val;    
  }else if(per>100.0-50.0){
    r[0]=0;g[0]=val+30;
    r[1]=val;g[1]=val;
    r[2]=val;g[2]=val;
    r[3]=val;g[3]=val;    
  }else if(per>100.0-62.5){
    r[0]=val+30;g[0]=val+30;
    r[1]=val;g[1]=val;
    r[2]=val;g[2]=val;
    r[3]=val;g[3]=0;    
  }else if(per>100.0-75.0){
    r[0]=val+30;g[0]=val+30;
    r[1]=val;g[1]=val;
    r[2]=val;g[2]=0;
    r[3]=0;g[3]=0;    
  }else if(per>100.0-87.5){
    r[0]=val+30;g[0]=val+30;
    r[1]=val;g[1]=0;
    r[2]=0;g[2]=0;
    r[3]=0;g[3]=0;    
  }else{
    r[0]=val+30;g[0]=0;
    r[1]=0;g[1]=0;
    r[2]=0;g[2]=0;
    r[3]=0;g[3]=0;    
  }
    
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(r[i],g[i],0));
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
}

void BatCharge(float per){
byte g[4];
byte b=0;
byte val=80;
if(per>=100.0){
    g[0]=val+100;
    g[1]=val;
    g[2]=val;
    g[3]=val;
  }else if(per>100.0-25.0){
    g[0]=val+100;
    g[1]=val;
    g[2]=val;
    g[3]=0;
  }else if(per>100.0-50.0){
    g[0]=val+100;
    g[1]=val;
    g[2]=0;
    g[3]=0;
  }else if(per>100.0-75.0){
    g[0]=val+100;
    g[1]=0;
    g[2]=0;
    g[3]=0;
  }else{
    g[0]=0;
    g[1]=0;
    g[2]=0;
    g[3]=0;
  }
    
  for(int i=0;i<NUMPIXELS;i++){
    if(g[0]==0 && i==0){
      pixels.setPixelColor(i, pixels.Color(val+100,val+100,0)); //yellow
    }else{
      pixels.setPixelColor(i, pixels.Color(0,0,g[i]));
    }
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
}

