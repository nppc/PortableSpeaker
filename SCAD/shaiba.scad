$fn=50;
shaiba(1.5);
translate([15,0,0])shaiba(1.4);
translate([-15,0,0])shaiba(1.6);
translate([0,15,0])shaiba(1.3);
translate([0,-15,0])shaiba(1.7);


module shaiba(hght){
    linear_extrude(hght)difference(){
        circle(d=12);
        circle(d=7.2);
    }
}