// Gmsh project created on Wed Jul 03 17:27:59 2013

Point(1) = {1, 0, 0, 1.0};

//Layers in radial direction
rlayers = 3;

//Layers in angular direction
philayers = 12;

// Make radial Line from Start Point length=1
Extrude {1, 0, 0} {
  Point{1}; Layers{rlayers};
}

// 4 quarter-Circles extruded from first line


Extrude {{0, 0, 1}, {0, 0, 0}, Pi/2} {
  Line{1}; Layers{philayers/4}; Recombine;
}
Extrude {{0, 0, 1}, {0, 0, 0}, Pi/2} {
  Line{2}; Layers{philayers/4}; Recombine;
}
Extrude {{0, 0, 1}, {0, 0, 0}, Pi/2} {
  Line{6}; Layers{philayers/4}; Recombine;
}
Extrude {{0, 0, 1}, {0, 0, 0}, Pi/2} {
  Line{10}; Layers{philayers/4}; Recombine;
}

Physical Surface(1) = {1,2,3,4};
