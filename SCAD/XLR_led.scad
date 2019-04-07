main(1.5);
difference(){
    reflector(0.8);
    reflector(0);
}

module reflector(wall){
    hull(){
        translate([0,1,-1.4+wall/2])hull(){
            translate([-6-wall,0,0])cylinder(d=5+wall*2,h=1,$fn=30);
            translate([6+wall,0,0])cylinder(d=5+wall*2,h=1,$fn=30);
        }
        translate([0,1,-3])cube([4.5+wall*10,4.5+wall*2,1.5],true);;
    }
    translate([0,1,-4.5+wall])cube([5.1+wall*10,5.1+wall*2,1.5],true);
}

module main(hght){
    color("lightgreen")translate([-23.4/2,-1,0])linear_extrude(hght)
        scale([0.25,0.25,0.25])import("../DXF/XLR_led.dxf");
}

module led(){
    color("white")cube([5.1,5.1,1.5],true);
}