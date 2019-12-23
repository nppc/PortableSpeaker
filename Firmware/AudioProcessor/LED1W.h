#define NUMPIXELS 10
//#define LED_BAT0 3
//#define LED_BAT1 4
//#define LED_BAT2 5
#define LED_BAT3 6

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void ledInputs_off(void){
  pixels.setPixelColor(0, pixels.Color(0, 0, 0)); //MIC bottom
  pixels.setPixelColor(9, pixels.Color(0, 0, 0)); //MIC top
  pixels.setPixelColor(1, pixels.Color(0, 0, 0)); //GUITAR bottom
  pixels.setPixelColor(8, pixels.Color(0, 0, 0)); //GUITAR top
  pixels.setPixelColor(2, pixels.Color(0, 0, 0)); //BT
}

void showInputLed(byte inp){
  ledInputs_off();
    switch(inp){
      case INPUT_MIC:
        pixels.setPixelColor(0, pixels.Color(0, 100, 0)); //MIC bottom
        pixels.setPixelColor(9, pixels.Color(0, 100, 0)); //MIC top
        break;
      case INPUT_GUITAR:
        pixels.setPixelColor(1, pixels.Color(0, 100, 0)); //GUITAR bottom
        pixels.setPixelColor(8, pixels.Color(0, 100, 0)); //GUITAR top
        break;
      case INPUT_BT:
        pixels.setPixelColor(2, pixels.Color(0, 0, 255)); //BT bottom
        break;
      case INPUT_MIXER:
        pixels.setPixelColor(0, pixels.Color(0, 100, 0)); //MIC bottom
        pixels.setPixelColor(9, pixels.Color(0, 100, 0)); //MIC top
        pixels.setPixelColor(1, pixels.Color(0, 100, 0)); //GUITAR bottom
        pixels.setPixelColor(8, pixels.Color(0, 100, 0)); //GUITAR top
        pixels.setPixelColor(2, pixels.Color(0, 0, 255)); //BT bottom
        break;
    }
  pixels.show(); // This sends the updated pixel color to the hardware.
}

void ledPWR_on(void){
  pixels.setPixelColor(7, pixels.Color(10, 0, 0)); //POWER (broken led, only red is working)
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
    
  for(int i=0;i<4;i++){
    pixels.setPixelColor(LED_BAT3-i, pixels.Color(r[i],g[i],0));
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
    
  for(int i=0;i<4;i++){
    if(g[0]==0 && i==0){
      pixels.setPixelColor(LED_BAT3-i, pixels.Color(val+100,val+100,0)); //yellow
    }else{
      pixels.setPixelColor(LED_BAT3-i, pixels.Color(0,0,g[i]));
    }
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
}