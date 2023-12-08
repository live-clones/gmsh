SetFactory("OpenCASCADE");

s=news; Rectangle(s)={0,0,0,1,2};
surfaces()=Surface "*";
layer()=Extrude{0,0,0.1}{Surface{surfaces()};Layers{3};Recombine;};
dielectric()+=layer(1);

BoundingBox;
xmin = General.MinX;
xmax = General.MaxX;
ymin = General.MinY;
ymax = General.MaxY;
zmin = General.MinZ;
zmax = General.MaxZ;
air=newv;
d=1;
Box(air)={xmin-d,ymin-d,zmin-d,2*d+xmax-xmin,2*d+ymax-ymin,2*d+zmax-zmin};

BooleanFragments { Volume{air}; Delete; } { Volume{dielectric()}; Delete; }
