// Electronics holder in Portable Speaker

$fn=30;
union(){
    translate([54/2-37/2,0,16])DigPots();
    AudioProcessor();
    translate([52,-50,0])rotate([0,0,90])Arduino();
    translate([0,40,0])MicPreamp();
}

module DigPots(){
    cube([37,21,1.6]);
    translate([10,15,-5])rotate([0,90,0])cylinder(d=10,h=21);
}

module MicPreamp(){
    cube([23,19,1.6]);
}

module AudioProcessor(){
    linear_extrude(1.6)
    difference(){
        square([54,35]);
        translate([3,3])circle(d=3);
        translate([54-3,35-3])circle(d=3);
        translate([3,35-3])circle(d=3);
        translate([54-3,3])circle(d=3);
    }
    translate([55,23,2])rotate([0,90,0])cylinder(d=10,h=21);
}

module Arduino(){
    linear_extrude(1.6)
    difference(){
        square([41,51]);
        translate([2.5,51-2.5])circle(d=3);
        translate([41-2.75,2.75])circle(d=3);
    }
    translate([41.2/2-3,1,1.6])cube([6,8,2]);
    translate([38,44,2])cylinder(d=10,h=21);
}