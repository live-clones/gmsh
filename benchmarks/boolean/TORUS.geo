Mesh.CharacteristicLengthFactor=0.1;

X = 12;
For I In {0:1}
 OCCShape("Torus",{2*I*X,0,0,0,0,1,10,4},"Fuse");
 OCCShape("Torus",{2*I*X,24,0,0,0,1,10,4},"Fuse");
 OCCShape("Torus",{2*I*X,48,0,0,0,1,10,4},"Fuse");
EndFor


//Compound Surface(100) = {1,2,3,4,5,6,7,8,9};


