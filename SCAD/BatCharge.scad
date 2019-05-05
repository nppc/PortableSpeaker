$fn=60;
import("C:/src/Tennp/Git/PortableSpeaker/DXF/IndicatorBatCharge.dxf");

for(i=[-9:6:9])translate([i+4,0,-4])led();
color("green")translate([4,0,-1.5/2-1.6/2-4])cube([33,8,1.6],true);


translate([-4,-9.4,-4])led();

module led(){
    color("white")cube([5.2,5.2,1.5],true);
}