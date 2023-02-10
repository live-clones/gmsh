SetFactory("OpenCASCADE");

General.Trackball = 1;
Geometry.OCCUnionUnify=0;

Sphere(1)={0,0,0,1,0,Pi/2,Pi/2};

Rotate{{0,0,1},{0,0,0},Pi/2}{Duplicata{Volume{1};}}
BooleanUnion{Volume{1};Delete;}{Volume{2};Delete;}

Rotate{{0,0,1},{0,0,0},Pi}{Duplicata{Volume{1};}}
BooleanUnion{Volume{1};Delete;}{Volume{2};Delete;}

Rotate{{1,0,0},{0,0,0},Pi}{Duplicata{Volume{1};}}
BooleanUnion{Volume{1};Delete;}{Volume{2};Delete;}


Dilate{{0,0,0},{1,0.8,0.5}}{Volume{1};}

Translate{2.4,0,0}{Duplicata{Volume{1};}}


n=16;
Transfinite Curve{:}=n;

Mesh.TransfiniteTri=1;
Mesh.Smoothing = 20;

Transfinite Surface{1}={1,2,3}; 
Transfinite Surface{2}={1,4,2}; 
Transfinite Surface{3}={5,3,2}; 
Transfinite Surface{4}={1,3,6}; 
Transfinite Surface{5}={1,6,4}; 
Transfinite Surface{6}={5,2,4}; 
Transfinite Surface{7}={5,6,3}; 
Transfinite Surface{8}={5,4,6}; 

Transfinite Surface{9}={7,8,9}; 
Transfinite Surface{10}={7,8,10};
Transfinite Surface{11}={11,8,9}; 
Transfinite Surface{12}={7,12,9}; 
Transfinite Surface{13}={7,10,12}; 
Transfinite Surface{14}={11,10,8}; 
Transfinite Surface{15}={11,9,12}; 
Transfinite Surface{16}={11,12,10}; 

Recombine Surface{1:8};

Hide{Curve{:};Point{:};}