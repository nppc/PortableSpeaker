$fn=60;
//linear_extrude(height = 80, center = true, convexity = 10)
//import("C:/src/Tennp/Git/PortableSpeaker/DXF/CornerRounder.dxf");

difference(){
translate([0,0,5])linear_extrude(height = 30, center = true, convexity = 10)
import("C:/src/Tennp/Git/PortableSpeaker/DXF/CornerShaver.dxf");
rotate([0,0,-45])translate([-0.8-3.71,-25,0])cube([0.8,50,21]);
    }

