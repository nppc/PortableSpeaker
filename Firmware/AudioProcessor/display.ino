//**************** Volume routines *******************/

// show header and clear the remaining of the screen
showVolume(){
	u8g2.firstPage();
	do {
		u8g2.setFont(u8g2_font_fub17_tr);
		u8g2.drawStr(0,17,F("Volume"));
	} while (u8g2.nextPage());
}

// show only volume control. Assume that header already displayed
changeVolumeDisplay(byte vol) {
	//we updating only part of the screen
	u8g2.firstPage();
	u8g2.setBufferCurrTileRow(3);
	for(byte b=0;b<3;b++){
		volumeBar(vol);
		u8g2.nextPage();
	}	
}

void volumeBar(byte vol){
  // input 0-100%
  const byte wdth = 80; // width of Volume Bar
  const byte hght = 15; // height of Volume Bar
  const byte x = 0; // height of Volume Bar
  const byte y = 30; // height of Volume Bar
  byte gval = map(vol, 0, 100, 0, wdth-2);
  u8g2.drawFrame(x,y,wdth,hght);
  u8g2.drawBox(x+1,y+1,gval,hght-2);
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.setCursor(wdth+7, y+hght-2);
  drawNumRight(vol);
  u8g2.print("%");
}


//**************** Tembre routines (bass and treble) *******************/

// show header and clear the remaining of the screen
showBass(){
	u8g2.firstPage();
	do {
		u8g2.setFont(u8g2_font_fub17_tr);
		u8g2.drawStr(0,17,F("Bass"));
	} while (u8g2.nextPage());
}

showTreble(){
	u8g2.firstPage();
	do {
		u8g2.setFont(u8g2_font_fub17_tr);
		u8g2.drawStr(0,17,F("Treble"));
	} while (u8g2.nextPage());
}

// show only Tembre control. Assume that header already displayed
changeTembreDisplay(int tembre) {
	//we updating only part of the screen
	u8g2.firstPage();
	u8g2.setBufferCurrTileRow(3);
	for(byte b=0;b<3;b++){
		tembreBar(tembre);
		u8g2.nextPage();
	}	
}


void tembreBar(int tembre){
  // input -14-14
  const byte wdth = 80; // width of Volume Bar
  const byte hght = 15; // height of Volume Bar
  const byte x = 0; // height of Volume Bar
  const byte y = 30; // height of Volume Bar
  byte gval = map(tembre, -14, 14, -(wdth-2)/2,(wdth-2)/2);
  u8g2.drawFrame(x,y,wdth,hght);
  if(tembre>0){u8g2.drawBox(x+wdth/2,y+1,gval,hght-2);}
  if(tembre==0){u8g2.drawBox(x+wdth/2-1,y+1,3,hght-2);}
  if(tembre<0){u8g2.drawBox(x+wdth/2+gval,y+1,-gval,hght-2);}
  u8g2.drawLine(x+wdth/2,y-2,x+wdth/2,y+hght+2);
  u8g2.setFont(u8g2_font_helvB12_tr);
  u8g2.setCursor(wdth+(tembre>=0 ? 2 : -5), y+hght-2);
  drawNumRight(tembre);
  u8g2.print("dB");
}


void drawNumRight(int vol){
  if(vol<10){u8g2.print("  ");}else if(vol<100){u8g2.print(" ");}
  u8g2.print(vol);
}