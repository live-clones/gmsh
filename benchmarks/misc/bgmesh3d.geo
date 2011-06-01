// cube geometry
lc = 1;
Point(1) = {0.0,0.0,0.0,lc};
Point(2) = {1,0.0,0.0,lc};
Point(3) = {1,1,0.0,lc};
Point(4) = {0,1,0.0,lc};
Line(1) = {4,3};
Line(2) = {3,2};
Line(3) = {2,1};
Line(4) = {1,4};
Line Loop(5) = {2,3,4,1};
Plane Surface(6) = {5};
Extrude {0,0.0,1} { Surface{6}; }

// background mesh built by hand

eps=1.e-6;
h=0.1+eps;
For x In {0:1-eps:h}
For y In {0:1-eps:h}
For z In {0:1-eps:h}
View "bgm" {
  SH(x,y,z, x+h,y,z, x+h,y+h,z, x,y+h,z,  x,y,z+h, x+h,y,z+h, x+h,y+h,z+h, x,y+h,z+h)
    {1,1,1,1,1,1,1,1};
};
EndFor
EndFor
EndFor
Combine Views;

Plugin(ModifyComponent).Expression = "0.2 * ((x-0.95)^2 + (y-0.5)^2 + (z-0.5)^2) + 0.01";
Plugin(ModifyComponent).Run;

Background Mesh View[0];
