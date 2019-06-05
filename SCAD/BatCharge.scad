corr=0.2;
$fn=60;
linear_extrude(3)import("C:/src/Tennp/Git/PortableSpeaker/SCAD/Bat.dxf");


translate([-8.2,-9,0])difference(){
    color("gray")hull(){
        translate([0,0,-7])case_base();
        translate([0,0,-1])chg_case_top();
    }
    chg_body(0);
    translate([0,0,-7])cube([15,8.2,2],true);
    translate([0,0,-7])cube([6,7,4],true);

}

linear_extrude(3)import("C:/src/Tennp/Git/PortableSpeaker/SCAD/Charging.dxf");
translate([-8.2,-9,0])chg_body(-0.4);

//allleds();


module chg_body(a){
    hull(){
        translate([0,0,-5])linear_extrude(1)square([6+a,6+a],true);
        translate([0,0,-1])linear_extrude(1)square([11+a,7+a],true);
    }
}

module case_base(){
    color("gray")linear_extrude(2)square(10,true);
}

module chg_case_top(){
    color("gray")linear_extrude(1)square([14,10],true);
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