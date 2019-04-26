//cutout for wheel

translate([0,0,19])difference(){
    union(){
        //MDF vertical
        translate([0,0,-19])cube([19,300,80+19]);
        translate([-19,0,0])cube([19,61,80]);
        translate([-19*2,0,0])cube([19,61,80]);
        //MDF boden
        translate([-310,0,-19])cube([310,300,19]);
    }
    translate([6,15,-11])wheelcutout();
}

module wheelcutout(){
rotate([-90,90,90]){
    difference(){
        union(){
            cylinder(r=35.5,h=6+3+19,$fn=80);
            translate([0,0,-4]){
                cylinder(r=7,h=6+3+19+8);
                translate([0,-7,0])cube([50,14,6+3+19+8]);
            }
            translate([0,-35.5,0])cube([35.5,35.5,6+3+19]);
        }
    translate([9,-50,-50])cube([50,100,100]);
    translate([-50,16,-10])cube([100,100,50]);
    }
}
}