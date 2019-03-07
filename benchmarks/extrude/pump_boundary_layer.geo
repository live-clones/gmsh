/*Size*/
rInlet = 0.033;
rOutlet = 0.1;
rImpeller = 0.2;
h = 0.001;
/*Blades*/
epBlade1 = 0.013;
epBlade2 = 0.013;
rLE = rInlet+epBlade1;
rTE = rImpeller-epBlade2;
rLECircle = 0.004;
noBlades = 7;
theta = 2*Pi/noBlades;
sweep = Pi/10;
L1x = 0.007;
L1y = 0.09;
L2x = -0.03;
L2y = 0.16;
/*Interface*/
deltaInterface = 0.000001;
rInterface = rImpeller-deltaInterface;
/*Volute*/
delr = 0.02;
n = 1000;
r1 = rImpeller+delr;
r2 = r1+(2*rOutlet);
delta = (Log(r2/r1))/(2*Pi);
/*Mesh Sizes*/
Lc1 = 0.05*1.5;
Lc3 = 0.01*1.5;
Lc2 = 0.005*2;

/*Functions*/
Function Blades
tmp[] = Rotate{{0,0,1}, {0,0,0}, angle} { Duplicata {Line{9:12};} };
Return

Function Spiral
p1 = newp; Point(p1) = {r1*Exp(delta*t)*Cos(t),  -r1*Exp(delta*t)*Sin(t),  0,  Lc3} ;
Return

/*Mesh Algorithms*/
Mesh.Algorithm = 6;
Mesh.Smoothing = 100;
Mesh.OptimizeNetgen = 1;
Mesh.HighOrderOptimize = 0;

/*------------------------Geometry Construction--------------------------------*/
/*Points*/
Point(1) = {0,0,0,Lc1};
/*Inlet*/
Point(2) = {rInlet,0,0,Lc3};
Point(3) = {-rInlet,0,0,Lc3};
Point(4) = {0,rInlet,0,Lc3};
Point(5) = {0,-rInlet,0,Lc3};
/*Impeller*/
Point(6) = {rImpeller,0,0,Lc2};
Point(7) = {-rImpeller,0,0,Lc2};
Point(8) = {0,rImpeller,0,Lc2};
Point(9) = {0,-rImpeller,0,Lc2};
/*Leading Edge Location and Radius*/
Point(10) = {rLE*Cos(Pi/2), rLE*Sin(Pi/2), 0, Lc2};
Point(11) = {rLE*Cos(Pi/2)-rLECircle, rLE*Sin(Pi/2), 0, Lc2};
Point(12) = {rLE*Cos(Pi/2), rLE*Sin(Pi/2)-rLECircle, 0, Lc2};
Point(13) = {rLE*Cos(Pi/2)+rLECircle, rLE*Sin(Pi/2), 0, Lc2};
Angle = Atan(-L1x/(1.2-rLE*Sin(Pi/2)));
Rotate{{0,0,1}, {rLE*Cos(Pi/2), rLE*Sin(Pi/2), 0}, Angle} { Point{11:13}; }
/*Trailing Edge Location*/
Point(14) = {(rTE)*Cos(Pi/2+sweep), rTE*Sin(Pi/2+sweep), 0, Lc2};
/*Control Points Location*/
Point(15) = {L1x-rLECircle,L1y,0,Lc2};
Point(16) = {L1x+rLECircle,L1y,0,Lc2};
Point(17) = {L2x-rLECircle,L2y,0,Lc2};
Point(18) = {L2x+rLECircle,L2y,0,Lc2};
/*Volute Wall*/
For i In {1:n+1}
t = (i-1)*2*Pi/n;
Call Spiral;
EndFor
/*Outlet and Volute Extension*/
p = newp; Point(p) = {r2,-6*rImpeller,0,Lc1};
Point(p+1) = {r1,-6*rImpeller,0,Lc1};
Point(p+6) = {r2,-rImpeller,0,Lc2};
Point(p+7) = {r1,-rImpeller,0,Lc2};
Point(p+8) = {r2,-(rImpeller+deltaInterface),0,Lc3};
Point(p+9) = {r1,-(rImpeller+deltaInterface),0,Lc3};
/*GGI Interface Inlet*/
Point(p+2) = {0,rInterface,0,Lc2};
Point(p+3) = {rInterface,0,0,Lc2};
Point(p+4) = {0,-rInterface,0,Lc2};
Point(p+5) = {-rInterface,0,0,Lc2};

/*Lines*/
/*Inlet*/
Circle(1) = {2,1,4};
Circle(2) = {4,1,3};
Circle(3) = {3,1,5};
Circle(4) = {5,1,2};
/*Impeller Diameter*/
Circle(5) = {6,1,8};
Circle(6) = {8,1,7};
Circle(7) = {7,1,9};
Circle(8) = {9,1,6};
/*Blades*/
Circle(9) = {11,10,12};
Circle(10) = {12,10,13};
BSpline(11) = {11,11,11,15,17,14,14,14};
BSpline(12) = {14,14,14,18,16,13,13,13};
/*Volute Wall*/
Spline(13) = {25+18:n+1+18};
Line(14) = {n+1+18,p+6};
Line(16) = {p+7,25+18};
/*Outlet*/
Line(21) = {p+6,p+7};
/*Volute Extension*/
Line(15) = {p,p+1};
Line(22) = {p,p+8};
Line(23) = {p+1, p+9};
Line(24) = {p+8,p+9};
/*GGI Interface*/
Circle(17) = {p+2,1,p+3};
Circle(18) = {p+3,1,p+4};
Circle(19) = {p+4,1,p+5};
Circle(20) = {p+5,1,p+2};

/*Inlet*/
Line Loop(1) = {1,2,3,4};
/*Impeller*/
Line Loop(2) = {5,6,7,8};
/*Volute*/
Line Loop(4) = {13,14,21,16};
/*GGI Interface*/
Line Loop(5) = {17,18,19,20};
/*Volute Extension*/
Line Loop(6) = {-23, -15, 22, 24};
/*Blades*/
Line Loop(3) = {9,10,-12,-11};
For t In {1:noBlades}
  angle = theta*(t);
  Call Blades;
  Line Loop(t+6) = {tmp[0],tmp[1],-tmp[2],-tmp[3]};
EndFor

/*Surface*/
Plane Surface(1) = {1,2,3,7:5+noBlades};
Plane Surface(2) = {4,5};
Plane Surface(3) = {6};

//Define Boundary Layer
Field[1] = BoundaryLayer;
/* Field[1].EdgesList = {13,14,16,232,235,233};
Field[1].NodesList = {43,1026,1027,1423,2407,2403};
Field[1].FanNodesList = {43,1423}; */
Field[1].EdgesList = {13,14,16, 9, 10, 12, 11,25:48};
Field[1].NodesList = {25+18:n+1+18,p+6,p+7,14,1045,1070,1095,1120,1145,1170};
Field[1].FanNodesList = {43,14,1045,1070,1095,1120,1145,1170};
Field[1].hwall_n = 0.0005;
Field[1].thickness = 0.005;
Field[1].ratio = 1.2;
Field[1].AnisoMax = 10;
Field[1].Quads = 1;
Field[1].IntersectMetrics = 0;
BoundaryLayer Field = 1;

/*Volume*/
ext[] = Extrude {0,0,h}
{
  Surface{1,2,3}; Layers{1}; Recombine;
};

/*Patch Names*/
Physical Surface("HUB_SHROUD") = {ext[0],ext[1]};
Physical Surface("VOLUTE") = {ext[10+noBlades*4],ext[10+noBlades*4+1]};
Physical Surface("EXTENSION") = {ext[10+noBlades*4+10],ext[10+noBlades*4+11]};
Physical Surface("INLET") = {ext[2]:ext[5]};
Physical Surface("OUTLET_INT") = {ext[10+noBlades*4+4]};
Physical Surface("BLADE_ROT") = {ext[10]:ext[10+noBlades*4-1]};
Physical Surface("GGI_INT") = {ext[10+noBlades*4+6]:ext[10+noBlades*4+9]};
Physical Surface("GGI_EXT") = {ext[6]:ext[9]};
Physical Surface("VOLUTE_WALL") = {ext[10+noBlades*4+2],ext[10+noBlades*4+3],ext[10+noBlades*4+5]};
Physical Surface("EXT_WALL") = {ext[10+noBlades*4+12], ext[10+noBlades*4+14]};
Physical Surface("EXT_OUTLET") = {ext[10+noBlades*4+13]};
Physical Surface("OUTLET_EXT") = {ext[10+noBlades*4+15]};
Physical Volume("internal") = {1,2,3};

/* Printf("%f",ext[10+noBlades*4+15]); */

/*tmp1[] = Translate {0,0,h}
{
  Duplicata { Surface {1}; }
};
tmp2[] =Translate {0,0,h}
{
  Duplicata { Surface {2}; }
};

Surface Loop(1) = {1,tmp1[]};
Surface Loop(2) = {2,tmp2[]};
Volume(1) = {1};*/
