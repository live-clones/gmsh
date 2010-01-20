a = .4;
b = 2;
radius = 0.5;
radiusBoundaryLayer = 0.7;
Point(1) = {0, 0, 0, a};

nlayers=2;
np=3;
np2=2;


For n In {0:nlayers}
  r= radius + (radiusBoundaryLayer-radius)*n/nlayers;
  Point(n*10+2) = {r,0,0,a};
  Point(n*10+3) = {0,-r,0,a};
  Point(n*10+4) = {-r,0,0,a};
  Point(n*10+5) = {0,r,0,a};

  Circle(n*10+2) = {n*10+2,1,n*10+3};
  Circle(n*10+3) = {n*10+3,1,n*10+4};
  Circle(n*10+4) = {n*10+4,1,n*10+5};
  Circle(n*10+5) = {n*10+5,1,n*10+2};

  Transfinite Line (n*10+2) = np;
  Transfinite Line (n*10+3) = np;
  Transfinite Line (n*10+4) = np;
  Transfinite Line (n*10+5) = np;

  If (n>0)
    Line (n*10+7) = {(n-1)*10+2, n*10+2};
    Line (n*10+8) = {(n-1)*10+3, n*10+3};
    Line (n*10+9) = {(n-1)*10+4, n*10+4};
    Line (n*10+10) = {(n-1)*10+5, n*10+5};

    Transfinite Line (n*10+7) = np2;
    Transfinite Line (n*10+8) = np2;
    Transfinite Line (n*10+9) = np2;
    Transfinite Line (n*10+10) = np2;

    Line Loop (n*10+2) = {n*10+2, -n*10-8, -(n-1)*10-2, n*10+7};
    Plane Surface(n*10+2) = {n*10+2};
    Transfinite Surface (n*10+2) = {n*10+2, n*10+3, (n-1)*10+3, (n-1)*10+2};
    Line Loop (n*10+3) = {n*10+3, -n*10-9, -(n-1)*10-3, n*10+8};
    Plane Surface(n*10+3) = {n*10+3};
    Transfinite Surface (n*10+3) = {n*10+3, n*10+4, (n-1)*10+4, (n-1)*10+3};
    Line Loop (n*10+4) = {n*10+4, -n*10-10, -(n-1)*10-4, n*10+9};
    Plane Surface(n*10+4) = {n*10+4};
    Transfinite Surface (n*10+4) = {n*10+4, n*10+5, (n-1)*10+5, (n-1)*10+4};
    Line Loop (n*10+5) = {n*10+5, -n*10-7, -(n-1)*10-5, n*10+10};
    Plane Surface(n*10+5) = {n*10+5};
    Transfinite Surface (n*10+5) = {n*10+5, n*10+2, (n-1)*10+2, (n-1)*10+5};

    Recombine Surface {n*10+2, n*10+3, n*10+4,n*10+5};
  EndIf
EndFor

Point(6) = {-5, -5, 0, b};
Point(7) = {-5, 5, 0, b};
Point(8) = {15, 5, 0, b};
Point(9) = {15, -5, 0, b};

Line(10001) = {7, 8};
Line(10002) = {8, 9};
Line(10003) = {9, 6};
Line(10004) = {6, 7};

Line Loop(1)={10001,10002,10003,10004};
Line Loop(2)={-nlayers*10-5,-nlayers*10-4,-nlayers*10-3,-nlayers*10-2};
Plane Surface(1)={1,2};
Mesh.CharacteristicLengthExtendFromBoundary=1;

Physical Line("Box") = {10004, 10001, 10002, 10003};
Physical Line("Cylinder") = {2,3,4,5};

Physical Surface("BoundaryLayer") = {2:10000};
Physical Surface("Air") = {1};
