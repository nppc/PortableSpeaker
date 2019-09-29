// Electronics holder in Portable Speaker
$fn=50;

translate([68,0,-3])rotate([0,-90,90])hang();

difference(){
    union(){
        translate([0,0,-3])linear_extrude(1){
            difference(){
                hull(){
                    translate([54-3,35-3])circle(d=7);
                    translate([3,57])circle(d=7);
                    translate([20,57])circle(d=7);
                    translate([54-3,-47])circle(d=7);
                    translate([3,-47])circle(d=7);
                }
                translate([12,7])square([30,20]);
                translate([12,-40])square([30,20]);
            }
        }
        translate([4,-6,-2])cube([42,5,2]);
        translate([54,19,-3])cube([20,8,2]);
    }
    translate([4.85,-5.15,-3.1])cube([40.3,3.3,4]);
    translate([54,23,2.3])rotate([0,90,0])cylinder(d=10,h=23);
}

translate([54-3,35-3,-3])shaiba();
translate([3,35-3,-3])shaiba();
translate([54-3,3,-3])shaiba();
translate([3,3,-3])shaiba();


translate([52,-50,0])rotate([0,0,90]){
    translate([2.5,51-2.5,-3])shaiba();
    translate([41-2.75,2.75,-3])shaiba();
}

translate([42,-50,-3])cube([10,10,3]);
translate([1,-19,-3])cube([10,10,3]);




module hang(){
    difference(){
        fillet(r=3,steps=8) {
            cube([40,3,17]);
            translate([0,-3,6])cube([6,4,13]);
            translate([0,0,17])cube([40,12,2]);
        }
        translate([3,-7,2])cylinder(d=10,h=21);
    }
}


module shaiba(){
    linear_extrude(3)difference(){
        circle(d=6);
        circle(d=2);
    }
}

//---------------------------------------------------
/*
color("Green")union(){
    translate([54/2-37/2,0,16])DigPots();
    AudioProcessor();
    translate([52,-50,0])rotate([0,0,90])Arduino();
    translate([0,40,0])MicPreamp();
}
*/

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
    translate([55,23,2.3])rotate([0,90,0])cylinder(d=10,h=21);
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

module fillet(r=1.0,steps=3,include=true) {
  if(include) for (k=[0:$children-1]) {
	children(k);
  }
  for (i=[0:$children-2] ) {
    for(j=[i+1:$children-1] ) {
	fillet_two(r=r,steps=steps) {
	  children(i);
	  children(j);
	  intersection() {
		children(i);
		children(j);
	  }
	}
    }
  }
}

module fillet_two(r=1.0,steps=3) {
  for(step=[1:steps]) {
	hull() {
	  render() intersection() {
		children(0);
		offset_3d(r=r*step/steps) children(2);
	  }
	  render() intersection() {
		children(1);
		offset_3d(r=r*(steps-step+1)/steps) children(2);
	  }
	}
  }
}

module offset_3d(r=1.0) {
  for(k=[0:$children-1]) minkowski() {
	children(k);
	sphere(r=r,$fn=8);
  }
}

