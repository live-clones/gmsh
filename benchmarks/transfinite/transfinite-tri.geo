SetFactory("OpenCASCADE");

L=1;
H=2;
d=0.15;

Point(1)={L*0.75,H,0};
Point(2)={0,0,0};
Point(3)={L,0,0};

Line(1)={1,2};
Line(2)={2,3};
Line(3)={3,1};

n=9;
Transfinite Curve{1,2,3}=n;

Curve Loop(1)={1,2,3};
Plane Surface(1)={1};


Translate{L+d,0,0}{Duplicata{Surface{1};}}
Translate{L+d,0,0}{Duplicata{Surface{2};}}
Translate{L+d,0,0}{Duplicata{Surface{3};}}

Transfinite Curve{4,5,6}=n;
Transfinite Curve{7,8,9}=n;
Transfinite Curve{10,11,12}=n;

Transfinite Surface{1};

Transfinite Surface{2} Right;
Recombine Surface{2};

Transfinite Surface{3} Left;
Recombine Surface{3};

Transfinite Surface{4} Alternate;
Recombine Surface{4};

Mesh.TransfiniteTri=1;
Mesh.Smoothing = 0;
