difference () {union() {translate([0,0,0])
    cylinder(h=6, d1=50.45, d2=48.45);

scale([1,1,0.2]) translate([-37,-30,0]) import("./Maple_Leaf_Cutter.stl");
}
 translate([0,0,3]) cylinder(h=4, d1=44.5, d2=45);
}
