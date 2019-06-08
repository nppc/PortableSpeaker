corr=0.4;
$fn=40;
print = 0;

prt_bt=3*print;
prt_mic=2*print;

difference(){
union(){
  all_black();
  all_transparent();
  allleds();
}
//translate([25,3,0])cube([50,30,20],true);
}

module all_black(){
  translate([0,0,0])difference(){
      color("gray")union(){
/*
        hull(){ //charging
          translate([-8.2,-9,-7])linear_extrude(2)square([10,9.8],true);
          translate([-8.2,-9,-1])linear_extrude(1)square([14,10],true);
        }

        hull(){ //chg meter
          translate([0,0,-7])linear_extrude(3)square([26,9.8],true);
          translate([0,0,-1])linear_extrude(1)square([24,9.8],true);
        }

        hull(){ // power
          translate([0,15,-7])linear_extrude(2)square([10,9.8],true);
          translate([0,15,-1])linear_extrude(1)r_square(14,14,9);
        }
*/
        hull(){ // MicUp
          translate([0,18.5,-7-prt_mic])linear_extrude(2)square([11,9.8],true);
          translate([0,18.5,1-prt_mic])linear_extrude(1)r_square(18,7.5,5);
        }
        hull(){ // MicDn
          translate([0,-18.5,-7-prt_mic])linear_extrude(2)square([11,9.8],true);
          translate([0,-18.5,1-prt_mic])linear_extrude(1)r_square(18,7.5,5);
        }

        hull(){ // InstUp
          translate([20,13.5,-7])linear_extrude(2)square([10,9.8],true);
          translate([20,13.5,-1])linear_extrude(1)r_square(15,7.5,5);
        }
        hull(){ // InstDn
          translate([20,-13.5,-7])linear_extrude(2)square([10,9.8],true);
          translate([20,-13.5,-1])linear_extrude(1)r_square(15,7.5,5);
        }

        hull(){ // BT
          translate([-20,0,-7-prt_bt])linear_extrude(2)square([9.8,12],true);
          translate([-20,0,2-prt_bt])linear_extrude(1)r_square(13,23,12);
        }
      }
/*
      translate([-8.2,-9,0])chg_body(0);
      chg1_body(corr);
      chg2_body(corr);
      chg3_body(corr);
      chg4_body(corr);
      translate([0,15,0])pwr_body(corr);
*/
      translate([0,18.5,-prt_mic])micUp_body(corr);
      translate([0,-18.5,-prt_mic])micDn_body(corr);
      translate([20,13.5,0])InstUp_body(corr);
      translate([20,-13.5,0])InstDn_body(corr);

      translate([-20,0,-prt_bt])bt_body(corr);
/*
      translate([-8.2,-9,-7])cube([15,8.2,2.1],true); // pcb charging
      translate([0,0,-7])cube([30,8.2,2.1],true); // pcbx4 meter
      translate([0,15,-7])cube([15,8.2,2.1],true); // pcb power
      translate([-8.2,-9,-7])cube([8,7,5.4],true); // cut for led charging
      for(i=[-9:6:9])translate([i,0,-6.1])linear_extrude(2.1)r_square(5+corr,7,1.2+corr); // cut for ledx4 meter
      translate([0,15,-7])cube([8,7,5.4],true); // cut for led power
*/
      translate([0,18.5,-7-prt_mic])cube([10,7,5.4],true); // cut for Mic
      translate([0,-18.5,-7-prt_mic])cube([10,7,5.4],true); // cut for Mic
      translate([0,18.5,-7-prt_mic])cube([15,8.2,2.1],true); // pcb mic
      translate([0,-18.5,-7-prt_mic])cube([15,8.2,2.1],true); // pcb mic

      translate([20,13.5,-7])cube([8.5,7,5.4],true); // cut for Inst
      translate([20,-13.5,-7])cube([8.5,7,5.4],true); // cut for Inst
      translate([20,13.5,-7])cube([15,8.2,2.1],true); // pcb Inst
      translate([20,-13.5,-7])cube([15,8.2,2.1],true); // pcb Inst

      translate([-20,0,-7-prt_bt])cube([7,11,5.4],true); // cut for BT
      translate([-20,0,-7-prt_bt])cube([8.2,15,2.1],true); // pcb BT
  }
}

module all_transparent(){
  //translate([-8.2,-9,0])chg_body(-corr);
  chg1_body(0);
  chg2_body(0);
  chg3_body(0);
  chg4_body(0);
  //translate([0,15,0])pwr_body(0);
  translate([0,18.5,0])micUp_body(0);
  translate([0,-18.5,0])micDn_body(0);
  translate([20,13.5,0])InstUp_body(0);
  translate([20,-13.5,0])InstDn_body(0);
  translate([-20,0,0])bt_body(0);
  linear_extrude(3)inset(0.15)import("C:/src/Tennp/Git/PortableSpeaker/SCAD/Bat.dxf");
  translate([0,0,2])linear_extrude(3)inset(0.15)import("C:/src/Tennp/Git/PortableSpeaker/SCAD/Mic.dxf");
  translate([20,0,0])linear_extrude(3)inset(0.15)import("C:/src/Tennp/Git/PortableSpeaker/SCAD/Instrument.dxf");
  translate([-20,0,3])linear_extrude(3)inset(0.15)import("C:/src/Tennp/Git/PortableSpeaker/SCAD/Bt.dxf");
  //linear_extrude(3)inset(0.15)import("C:/src/Tennp/Git/PortableSpeaker/SCAD/Charging.dxf");
  //translate([0,15,0])linear_extrude(3)inset(0.15)import("C:/src/Tennp/Git/PortableSpeaker/SCAD/Power.dxf");
}

module chg1_body(a){
  hull(){
    translate([7,0,-0.1])linear_extrude(0.1)r_square(4+a,6+a,1.2+a);
    translate([9,0,-4.3])linear_extrude(0.2)r_square(5+a,6+a,1.2+a);
  }
}

module chg2_body(a){
  hull(){
    translate([2,0,-0.1])linear_extrude(0.1)r_square(3+a,6+a,1.2+a);
    translate([3,0,-4.3])linear_extrude(0.2)r_square(5+a,6+a,1.2+a);
  }
}

module chg3_body(a){
  hull(){
    translate([-2,0,-0.1])linear_extrude(0.1)r_square(3+a,6+a,1.2+a);
    translate([-3,0,-4.3])linear_extrude(0.2)r_square(5+a,6+a,1.2+a);
  }
}

module chg4_body(a){
  hull(){
    translate([-7,0,-0.1])linear_extrude(0.1)r_square(4+a,6+a,1.2+a);
    translate([-9,0,-4.3])linear_extrude(0.2)r_square(5+a,6+a,1.2+a);
  }
}


module chg_body(a){
    hull(){
        translate([0,0,-4.3])linear_extrude(1)square([8+a,6+a],true);
        translate([0,0,-1])linear_extrude(1)square([11+a,7+a],true);
    }
}

module pwr_body(a){
  hull(){
    translate([0,0,-1])linear_extrude(1)r_square(10+a,11+a,9+a);
    translate([0,0,-4.3])linear_extrude(0.2)r_square(7+a,6+a,4+a);
  }
}

module micUp_body(a){
  hull(){
    translate([0,0,1])linear_extrude(1)r_square(15.5+a,5+a,3+a);
    translate([0,0,-4.3])linear_extrude(0.2)r_square(9+a,5+a,4+a);
  }
}

module micDn_body(a){
  hull(){
    translate([0,0,1])linear_extrude(1)r_square(15.5+a,5+a,3+a);
    translate([0,0,-4.3])linear_extrude(0.2)r_square(9+a,5+a,4+a);
  }
}

module InstUp_body(a){
  hull(){
    translate([0,0,-1])linear_extrude(1)r_square(12+a,5+a,3+a);
    translate([0,0,-4.3])linear_extrude(0.2)r_square(8+a,5+a,4+a);
  }
}

module InstDn_body(a){
  hull(){
    translate([0,0,-1])linear_extrude(1)r_square(12+a,5+a,3+a);
    translate([0,0,-4.3])linear_extrude(0.2)r_square(8+a,5+a,4+a);
  }
}

module bt_body(a){
  hull(){
    translate([0,0,2])linear_extrude(1)r_square(10+a,20+a,10+a);
    translate([0,0,-4.3])linear_extrude(0.2)r_square(6+a,10+a,4+a);
  }
}

module allleds(){
    for(i=[-9:6:9])translate([i,0,-6])led();
    color("green")translate([0,0,-1.6/2-6])cube([33,8,1.6],true);

    //color("green")translate([-8.2,-9,-1.6/2-6])cube([15,8,1.6],true);
    //translate([-8.2,-9,-6])led();
    //color("green")translate([0,15,-1.6/2-6])cube([15,8,1.6],true);
    //translate([0,15,-6])led();
    //mic
    color("green")translate([0,18.5,-1.6/2-6])cube([15,8,1.6],true);
    translate([0,18.5,-6])led();
    color("green")translate([0,-18.5,-1.6/2-6])cube([15,8,1.6],true);
    translate([0,-18.5,-6])led();
}

module led(){
    color("white")linear_extrude(1.5)square(5.2,true);
}

module r_square(x,y,d){
  x1=(x-d)/2;
  y1=(y-d)/2;
  hull(){
    translate([x1,y1,0])circle(d=d);
    translate([-x1,y1,0])circle(d=d);
    translate([x1,-y1,0])circle(d=d);
    translate([-x1,-y1,0])circle(d=d);
  }
}


module inset(val){
    difference(){
        square(200,true);
        minkowski(){
            difference(){
                square(300,true);
                children();
            }
            circle(val);
        }
    }
}