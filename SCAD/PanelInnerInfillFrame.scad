$fn=20;
hght=1.5;
difference(){
linear_extrude(hght)import("C:/src/Tennp/Git/PortableSpeaker/DXF/PanelInnerFrameinfill.dxf");

translate([80,0,1.5])cube([7,200,2],true);
translate([-85,0,1.5])cube([7,200,2],true);
translate([-35,0,1.5])cube([7,200,2],true);
difference(){
    translate([20,0,1.5])cube([7,200,2],true);
    translate([20,0,0])cube([10,30,10],true);
}
}