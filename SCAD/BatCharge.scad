corr=0.4;
$fn=40;

difference(){
union(){
  all_black();
  all_transparent();
  allleds();
}
//translate([21,0,0])cube([50,20,20],true);
}

module all_black(){
  translate([0,0,0])difference(){
      color("gray")union(){
        hull(){
          translate([-8.2,-9,-7])linear_extrude(2)square([10,9.8],true);
          translate([-8.2,-9,-1])chg_case_top();
        }
        hull(){
          translate([0,0,-7])linear_extrude(3)square([26,9.8],true);
          translate([0,0,-1])linear_extrude(1)square([24,9.8],true);
        }
      }
      translate([-8.2,-9,0])chg_body(0);
      chg1_body(corr);
      chg2_body(corr);
      chg3_body(corr);
      chg4_body(corr);
      translate([-8.2,-9,-7])cube([15,8.2,2.1],true); // pcb
      translate([0,0,-7])cube([30,8.2,2.1],true); // pcbx4
      translate([-8.2,-9,-7])cube([8,7,5.4],true); // cut for led
      for(i=[-9:6:9])translate([i,0,-6.1])linear_extrude(2.1)r_square(5+corr,7,1.2+corr); // cut for ledx4

  }
}

module all_transparent(){
  translate([-8.2,-9,0])chg_body(-corr);
  chg1_body(0);
  chg2_body(0);
  chg3_body(0);
  chg4_body(0);
  linear_extrude(3)import("C:/src/Tennp/Git/PortableSpeaker/SCAD/Bat.dxf");
  linear_extrude(3)import("C:/src/Tennp/Git/PortableSpeaker/SCAD/Charging.dxf");
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


module chg_case_top(){
    linear_extrude(1)square([14,10],true);
}

module allleds(){
    for(i=[-9:6:9])translate([i,0,-6])led();
    color("green")translate([0,0,-1.6/2-6])cube([33,8,1.6],true);
    color("green")translate([-8.2,-9,-1.6/2-6])cube([15,8,1.6],true);


    translate([-8.2,-9,-6])led();
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