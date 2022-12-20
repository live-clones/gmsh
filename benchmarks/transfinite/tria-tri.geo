SetFactory("OpenCASCADE");

L=1;
H=1.75;

Point(1)={0,0,0};
Point(2)={L,0,0};
Point(3)={L/2,H,0};

t=1;
Point(4)={L/2,t,0};

x1=L;y1=0;x2=L/2;y2=H;
x0=(x1+x2)/2;
y0=(y1+y2)/2;
dx=x1-x2;
dy=y1-y2;
t=1;
x=x0+t*dy;
y=y0-t*dx;
Point(5)={x,y,0};

x2=0;y2=0;x1=L/2;y1=H;
x0=(x1+x2)/2;
y0=(y1+y2)/2;
dx=x1-x2;
dy=y1-y2;
t=0.6;
x=x0+t*dy;
y=y0-t*dx;
Point(6)={x,y,0};

Circle(1)={1,4,2};
Circle(2)={2,5,3};
Circle(3)={3,6,1};

Delete{Point{4,5,6};}


dL=0.3+L;
Point(4)={dL,0,0};
Point(5)={dL+L,0,0};
Point(6)={dL+2*L/3,H,0};

t=0.5;
Point(7)={dL+L/2,-t,0};

x1=dL+L;y1=0;x2=dL+2*L/3;y2=H;
x0=(x1+x2)/2;
y0=(y1+y2)/2;
dx=x1-x2;
dy=y1-y2;
t=-3;
x=x0+t*dy;
y=y0-t*dx;
Point(8)={x,y,0};

x2=dL;y2=0;x1=dL+2*L/3;y1=H;
x0=(x1+x2)/2;
y0=(y1+y2)/2;
dx=x1-x2;
dy=y1-y2;
t=-5;
x=x0+t*dy;
y=y0-t*dx;
Point(9)={x,y,0};

Circle(4)={4,7,5};
Circle(5)={5,8,6};
Circle(6)={6,9,4};

Delete{Point{7,8,9};}


n=11;
Transfinite Curve{1,2,3}=n+2;
Transfinite Curve{4,5,6}=n;

Curve Loop(1) = {1,2,3};
Plane Surface(1) = {1};

Curve Loop(2) = {4,5,6};
Plane Surface(2) = {2};


Mesh.TransfiniteTri=1;
Transfinite Surface{:};
Mesh.Smoothing = 0;

