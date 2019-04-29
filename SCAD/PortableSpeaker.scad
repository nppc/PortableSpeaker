// 2X XH-M544
explode=0;

// V=33L (phase inverter size is 70 mm)
innerHeight=430;
innerWidth=310;
innerDepth=254;
Thick=19;
electronicHeight=48;

$fn=60;
outerDepth=8+Thick+innerDepth+Thick;
outerHeight=Thick+innerHeight+Thick+electronicHeight+Thick;
echo("outerDepth", outerDepth);
echo("outerHeight", outerHeight);

/*
// plates total (310mm): 300+80+80+417+120+80+300+430 + 535+535
// 41.7+30+8+8+6.7+12 = 106.4cm
// 30+43 = 73cm
// 53.5+53.5 = 107cm

1. (310 X 1100): 
  a.	300 X 310 – 1
  b.	430 X 310 – 1 
2. (310 X 1100): (need to cut 1 cm to make it 300 X 1100)
  a.	535 X 300 – 2 
3. (310 X 1100):
  a.	67 X 310 – 1
  b.	80 X 310 – 2
  c.	120 X 310 – 1
  d.	300 X 310 – 1
  e.	417 X 310 – 1
*/

//translate([200,0,innerHeight/2])cube([400,10,19], true);

union()color("Gray"){
//front deck
difference(){
  translate([0,8,0])cube([innerWidth,Thick,innerHeight]);
  // Speakers
  translate([110,7,110])rotate([-90,0,0]){
    cylinder(d=168,h=5);
    cylinder(d=145,h=30);
  }
  translate([innerWidth - 110,7,innerHeight - 110])rotate([-90,0,0]){
    cylinder(d=168,h=5);
    cylinder(d=145,h=30);
  }
  // Tweeters
  translate([50,7,innerHeight/2 + 50])rotate([-90,0,0]){
    cylinder(d=48,h=10,$fn=30);
    cylinder(d=43,h=30,$fn=30);
  }
  translate([innerWidth-50,7,innerHeight/2 - 50])rotate([-90,0,0]){
    cylinder(d=48,h=10,$fn=30);
    cylinder(d=43,h=30,$fn=30);
  }
  //Phaseinverter X2
  translate([50,7,innerHeight - 55])rotate([-90,0,0]){
    cylinder(d=80,h=10,$fn=30);
    cylinder(d=70,h=30,$fn=30);
  }
  translate([innerWidth-50,7,55])rotate([-90,0,0]){
    cylinder(d=80,h=10,$fn=30);
    cylinder(d=70,h=30,$fn=30);
  }

}


//right side
translate([0-explode,0,-Thick])rotate([0,0,90])cube([outerDepth,Thick,outerHeight]);

//left side
//translate([innerWidth+Thick+explode,0,-Thick])rotate([0,0,90])cube([outerDepth,Thick,outerHeight]);

//bottom
translate([0,0,-explode])rotate([-90,0,0])cube([innerWidth,Thick,outerDepth]);

//middle
translate([0,0,innerHeight+Thick+explode])rotate([-90,0,0])cube([innerWidth,Thick,120]);


//top
translate([0,0,Thick+innerHeight+Thick+electronicHeight+explode*2])rotate([-90,0,0]){
  difference(){
    cube([innerWidth,Thick,outerDepth]);
    translate([innerWidth/2,0,40])cube([215,50,81], true);
  }
}


//back
translate([0,outerDepth-Thick+explode,80])cube([innerWidth,Thick,outerHeight-Thick*2-80]);
echo("back",outerHeight-Thick*2-80);

// battery compartment
translate([0,outerDepth-Thick-80+19,explode])cube([innerWidth,Thick,80]);
translate([0,outerDepth-Thick-80+19,80+Thick+explode*2])rotate([-90,0,0])cube([innerWidth,Thick,80-19]);

translate([explode,outerDepth-80+Thick+explode,explode])cube([Thick,80-19,80]);
translate([explode*2+Thick,outerDepth-80+Thick+explode,explode])cube([Thick,80-19,80]);
translate([innerWidth-Thick-explode,outerDepth-80+Thick+explode,explode])cube([Thick,80-19,80]);
translate([innerWidth-(Thick+explode)*2,outerDepth-80+Thick+explode,explode])cube([Thick,80-19,80]);





//right electronic wall
translate([28.5+Thick,0,innerHeight+Thick+explode*1.5])rotate([0,0,90])cube([120,6,electronicHeight]);
//left electronic wall
translate([innerWidth-28.5-Thick+6,0,innerHeight+Thick+explode*1.5])rotate([0,0,90])cube([120,6,electronicHeight]);
//back electronic wall
translate([0,120,innerHeight+electronicHeight+Thick-67+explode*1.5])cube([innerWidth,Thick,67]);

}

/*
translate([110,7,110])speaker();
translate([innerWidth - 110,7,innerHeight - 110])speaker();
translate([50,7,innerHeight/2 + 50])Tweeter();
translate([innerWidth-50,7,innerHeight/2 - 50])Tweeter();
*/

translate([innerWidth/2,outerDepth/2,outerHeight-Thick+explode*3])AdamHall3427StrapHandle();
translate([innerWidth/2,outerDepth+3+explode*2,outerHeight-395])AdamHall3471Handle();

translate([innerWidth/2,43,outerHeight-Thick-35])rotate([40,0,0])electronicPanel();

translate([200,115,0])rotate([0,0,90])power27V();

  for(i=[0:19:110])translate([i+60,250,0])liion();
  for(i=[0:19:110])translate([i+60,269,0])liion();
  for(i=[0:19:110])translate([i+60,288,0])liion();


translate([-Thick+10,outerDepth,-19+48/2-18])wheel();
translate([Thick+innerWidth-10,outerDepth,-19+48/2-18])wheel();

module speaker(){
  rotate([-90,0,0])color([0.2,0.2,0.2])union(){
    cylinder(d=168,h=5);
    cylinder(d1=145,d2=100,h=50);
    translate([0,0,50])cylinder(d=120,h=30);
  }
}

module Tweeter(){
  rotate([-90,0,0])color([0.2,0.2,0.2])union(){
    cylinder(d=48,h=5,$fn=30);
    cylinder(d1=43,d2=20,h=20,$fn=20);
  }
}

module AdamHall3427StrapHandle(){
  //https://www.thomann.de/intl/adam_hall_3427_strap_handle_black.htm
  size=280;
  color("Black")union(){
    translate([-size/2,-34/2,0])cube([50,34,10]);
    translate([size/2-50,-34/2,0])cube([50,34,10]);
    translate([0,0,6])cube([180,25,6],true);
  }
}

module AdamHall3471Handle(){
  //https://www.thomann.de/intl/adam_hall_3471.htm
  color("Black")difference(){
    union(){
      cube([218,6,60],true);
      translate([0,0,395-60])cube([218,6,60],true);
      translate([70,10,(395+80)/2-30])cube([20,20,395+80],true);
      translate([-70,10,(395+80)/2-30])cube([20,20,395+80],true);
      translate([0,10,395+80-20])cube([160,20,20],true);
    }
    translate([185/2,0,0])rotate([90,0,0])cylinder(d=6, h=20,center=true,$fn=10);
    translate([-185/2,0,0])rotate([90,0,0])cylinder(d=6, h=20,center=true,$fn=10);
    translate([185/2,0,333])rotate([90,0,0])cylinder(d=6, h=20,center=true,$fn=10);
    translate([-185/2,0,333])rotate([90,0,0])cylinder(d=6, h=20,center=true,$fn=10);
  }
}

module electronicPanel(){
  pWidth=200;
  pHeight=90;
  color([0.1,0.1,0.1])hull(){
    translate([-pWidth/2+6/2,-pHeight/2+6/2,0])cylinder(d=6,h=4,$fn=10);
    translate([pWidth/2-6/2,-pHeight/2+6/2,0])cylinder(d=6,h=4,$fn=10);
    translate([-pWidth/2+6/2,pHeight/2-6/2,0])cylinder(d=6,h=4,$fn=10);
    translate([pWidth/2-6/2,pHeight/2-6/2,0])cylinder(d=6,h=4,$fn=10);
  }
  translate([20,-20,6])knob28x12();
  translate([-75,-25,6])knob17x14();
  translate([-75,10,6])neutrikNCJ9FIS();
  
  translate([-45,20,16])RCA();
  translate([-45,0,16])RCA();
  
  translate([20,20,3])oled1_3();
  
  translate([-20,10,-5.9])color("lightblue"){
    bluetoothSign();
    mirror([0,1,0])bluetoothSign();
  }
  
  translate([70,0,3])powerSwitch();
}

module knob28x12(){ //https://www.aliexpress.com/item/D-Axis-Volume-Knob-Potentiometer-Knob-Encoder-knob-28-x-12MM/32812148438.html
  color("lightGray")cylinder(d=28, h=12,$fn=20);
}

module knob17x14(){ //https://www.aliexpress.com/item/17x10mm-Aluminum-Alloy-Potentiometer-Knob-Pack-of-2/32922183298.html
  color("Gray")cylinder(d=17, h=10,$fn=15);
}

module neutrikNCJ9FIS(){
  color("black")rotate([180,0,0])union(){
  difference(){
    cylinder(d=23.5,h=7,$fn=15);
    cylinder(d=7,h=20,$fn=10, center=true);
  }
  translate([0,0,7])cylinder(d=37,h=30,$fn=15);
}
  color("lightgreen")translate([-23.4/2,-39.48/2,-3])linear_extrude(1)scale([0.25,0.25,0.25])import("../DXF/XLR_leds.dxf");
}

module RCA(){
  color("Gold")rotate([180,0,0])union(){
    difference(){
      cylinder(d=9,h=10,$fn=15);
      cylinder(d=3,h=40, $fn=8,center=true);
    }
    translate([0,0,10])cylinder(d=15,h=20,$fn=15);
  }
}

module oled1_3(){ //https://www.aliexpress.com/item/1PCS-1-3-OLED-module-bule-color-128X64-1-3-inch-OLED-LCD-LED-Display-Module/32814239906.html
  color("Darkblue")cube([36,34,1], true);
  color("blue")translate([0,0,1])cube([32,18,1],true);
}

module power27V(){
//https://www.aliexpress.com/item/DC12V-13-8V-15V-18V-24V-27V-30V-32V-36V-48V-100W-120W-180W-200W-300W/32948831075.html
  color("LightGray")cube([100,160,50]);
}

module liion(){
  color("lightblue")cylinder(d=18.5,h=65, $fn=10);
}

module bluetoothSign(){
  btSize=7.5; //mm
  btdiam=1.2; //mm
  hull(){
    translate([-btSize/2,btSize/2,0])cylinder(d=btdiam,h=10,$fn=10);
    translate([btSize/2,-btSize/2,0])cylinder(d=btdiam,h=10,$fn=10);
  }
  hull(){
    translate([btSize/2,-btSize/2,0])cylinder(d=btdiam,h=10,$fn=10);
    translate([0,-btSize,0])cylinder(d=btdiam,h=10,$fn=10);
  }
  hull(){
    translate([0,-btSize,0])cylinder(d=btdiam,h=10,$fn=10);
    translate([0,-btSize/2,0])cylinder(d=btdiam,h=10,$fn=10);
  }
}

module powerSwitch(){
  //https://www.aliexpress.com/item/Latching-Rocker-Switch-Power-Switch-I-O-4-Pins-With-Light-16A-250VAC-20A-125VAC-KCD4/32829575455.html
  color("Black")cube([25,32,10],true);
}


module wheel(){
  //wheels is Adam Hall 3783
  color("lightgray")rotate([0,90,0])cylinder(d=58, h=15, center=true, $fn=30);
}


// rear power socket
//https://www.aliexpress.com/item/15A-250V-3pin-AC-power-socket-with-Power-Rocker-Switch-Fused/32812877104.html