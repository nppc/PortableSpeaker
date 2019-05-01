for(i=[-9:6:9])translate([i,0,0])led();
color("green")translate([0,0,-1.5/2-1.6/2])cube([33,8,1.6],true);


module led(){
    color("white")cube([5.1,5.1,1.5],true);
}

