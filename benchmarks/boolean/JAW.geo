//Mesh.CharacteristicLengthFactor=0.15;


L = 100;
H = 30;
Z = 10;
OCCShape("Box",{0,0,0,L,H,Z},"none");
R = 10;
X = 5;

For I In {0:5}
 OCCShape("Cylinder",{2*I*X,H/2,-3*Z,0,0,1,R,6*Z},"Cut");
EndFor

OCCShape("Sphere",{H-X,H/2,Z/2,R},"Fuse");
OCCShape("Torus",{L,H/2,Z/2,0,0,1,2*R,R/2},"Fuse");


//Compound Surface(100) = {1 ... 26};
