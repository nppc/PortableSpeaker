
void drawNumRight(int vol){
  if(vol<10){u8g2.print("  ");}else if(vol<100){u8g2.print(" ");}
  u8g2.print(vol);
}


//**************** Headphones routines *******************/

// show header and clear the remaining of the screen
void showHeadphones(){
	u8g2.firstPage();
	do {
		u8g2.setFont(u8g2_font_fub17_tr);
		u8g2.setCursor(0,17);
		u8g2.print(F("Headphone"));
	} while (u8g2.nextPage());
}


//**************** Volume routines *******************/

// show header and clear the remaining of the screen
void showVolume(){
	u8g2.firstPage();
	do {
		u8g2.setFont(u8g2_font_fub17_tr);
		u8g2.setCursor(0,17);
		u8g2.print(F("Volume"));
	} while (u8g2.nextPage());
}

void volumeBar(byte vol){
  // input 0-48 (0 - mute)
  const byte wdth = 80; // width of Volume Bar
  const byte hght = 15; // height of Volume Bar
  const byte x = 0; // height of Volume Bar
  const byte y = 30; // height of Volume Bar
  byte gval = map(vol, 0, 48, 0, wdth-2);
  u8g2.drawFrame(x,y,wdth,hght);
  u8g2.drawBox(x+1,y+1,gval,hght-2);
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.setCursor(wdth+4, y+hght-2);
  drawNumRight(vol);
  u8g2.print(F("dB"));
}

void gainBar(byte gain){
  // input 0-15 (0 - 30dB)
  const byte wdth = 80; // width of Volume Bar
  const byte hght = 15; // height of Volume Bar
  const byte x = 0; // height of Volume Bar
  const byte y = 30; // height of Volume Bar
  byte gval = map(gain, 0, 15, 0, wdth-2);
  u8g2.drawFrame(x,y,wdth,hght);
  u8g2.drawBox(x+1,y+1,gval,hght-2);
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.setCursor(wdth+4, y+hght-2);
  drawNumRight(gain*2);
  u8g2.print(F("dB"));
}

// show only volume control. Assume that header already displayed
void changeVolumeDisplay(byte vol) {
	//we updating only part of the screen
	u8g2.firstPage();
	u8g2.setBufferCurrTileRow(3);
	for(byte b=0;b<3;b++){
		volumeBar(vol);
		u8g2.nextPage();
	}	
}

//**************** Tembre routines (bass and treble) *******************/

void tembreBar(int tembre){
  // input -14-14
  const byte wdth = 80; // width of Volume Bar
  const byte hght = 15; // height of Volume Bar
  const byte x = 0; // height of Volume Bar
  const byte y = 30; // height of Volume Bar
  byte gval = map(tembre, -14, 14, -(wdth-2)/2,(wdth-2)/2);
  u8g2.drawFrame(x,y,wdth,hght);
  if(tembre>0){u8g2.drawBox(x+wdth/2,y+1,gval+1,hght-2);}
  if(tembre==0){u8g2.drawBox(x+wdth/2-1,y+1,3,hght-2);}
  if(tembre<0){u8g2.drawBox(x+wdth/2+gval,y+1,-gval,hght-2);}
  u8g2.drawLine(x+wdth/2,y-2,x+wdth/2,y+hght+2);
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.setCursor(wdth+(tembre>=0 ? 2 : -5), y+hght-2);
  drawNumRight(tembre);
  u8g2.print(F("dB"));
}

// show header and clear the remaining of the screen
void showBass(){
	u8g2.firstPage();
	do {
		u8g2.setFont(u8g2_font_fub17_tr);
		u8g2.setCursor(0,17);
		u8g2.print(F("Bass"));
	} while (u8g2.nextPage());
}

void showTreble(){
	u8g2.firstPage();
	do {
		u8g2.setFont(u8g2_font_fub17_tr);
		u8g2.setCursor(0,17);
		u8g2.print(F("Treble"));
	} while (u8g2.nextPage());
}

// show only Tembre control. Assume that header already displayed
void changeTembreDisplay(int tembre) {
	//we updating only part of the screen
	u8g2.firstPage();
	u8g2.setBufferCurrTileRow(3);
	for(byte b=0;b<3;b++){
		tembreBar(tembre);
		u8g2.nextPage();
	}	
}

// combine on one screen volume, bass and treble
void showDefaultScreen(){
	u8g2.firstPage();
	do {
		u8g2.setFont(u8g2_font_helvB12_tr);
		u8g2.setCursor(0,17);
		u8g2.print(F("VOL: "));
		u8g2.print(curVolume);
		u8g2.setCursor(0,40);
		u8g2.print(F("BAS: "));
		u8g2.print(curBass);
		u8g2.setCursor(0,63);
		u8g2.print(F("TRE: "));
		u8g2.print(curTreble);
	} while (u8g2.nextPage());
}

// show input

void showInputHeader(void){
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_fub17_tr);
    u8g2.setCursor(0,17);
    u8g2.print(F("INPUT:"));
  } while (u8g2.nextPage());
}
void showInput(byte inp){
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_fub17_tr);
    u8g2.setCursor(0,17);
    u8g2.print(F("INPUT:"));
    switch(inp){
      case INPUT_MIC:
        u8g2.setCursor(35,50);
        u8g2.print(F("MIC"));
        break;
      case INPUT_GUITAR:
        u8g2.setCursor(20,50);
        u8g2.print(F("MUSIC"));
        break;
      case INPUT_BT:
        u8g2.setCursor(50,50);
        u8g2.print(F("BT"));
        break;
      case INPUT_MIXER:
        u8g2.setCursor(20,50);
        u8g2.print(F("MIXER"));
        break;
    }
  } while (u8g2.nextPage());
}

void showMixerHeader(byte inp){
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_fub17_tr);
    u8g2.setCursor(0,17);
    switch(inp){
      case 1:
        u8g2.print(F("MIX: ALL"));
        break;
      case 2:
        u8g2.print(F("MIX: MIC"));
        break;
      case 3:
        u8g2.print(F("MIX:MUSIC"));
        break;
    }
  } while (u8g2.nextPage());
}

/*
void showMixerInput(byte inp){
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_fub17_tr);
    u8g2.setCursor(0,17);
    u8g2.print(F("INPUT:"));
    switch(inp){
      case 0:
        u8g2.setCursor(15,50);
        u8g2.print(F("MIXER"));
        break;
      case 1:
        u8g2.setCursor(10,50);
        u8g2.print(F("MIX: ALL"));
        break;
      case 2:
        u8g2.setCursor(10,50);
        u8g2.print(F("MIX: MIC"));
        break;
      case 3:
        u8g2.setCursor(0,50);
        u8g2.print(F("MIX:MUSIC"));
        break;
    }
  } while (u8g2.nextPage());
}
*/

// show only volume control. Assume that header already displayed
void changeGainDisplay(byte gain) {
  //we updating only part of the screen
  u8g2.firstPage();
  u8g2.setBufferCurrTileRow(3);
  for(byte b=0;b<3;b++){
    gainBar(gain);
    u8g2.nextPage();
  } 
}
