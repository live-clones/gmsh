
lc = 1e-1 ;
xx = 0;

// Lines
p = newp;
Point(p) = {xx,  0,  0, 0.3*lc} ;
Point(p+1) = {xx+.5, 0,  0, lc} ;
Point(p+2) = {xx+.5, 1, 0, 0.1*lc} ;
Point(p+3) = {xx, 1, 0, lc} ;
l = newreg;
Line(l) = {p+3,p+2};
Line(l+1) = {p+2,p+1};
Line(l+2) = {p+1,p};
Line(l+3) = {p,p+3};
s = newreg;
Line Loop(s) = {-l,-(l+1),-(l+2),-(l+3)};
Plane Surface(s+1) = {s};

xx += 1;

// B-Splines
p = newp;
Point(p) = {xx,  0,  0, 0.3*lc} ;
Point(p+1) = {xx+.5, 0,  0, lc} ;
Point(p+2) = {xx+.5, 1, 0, 0.1*lc} ;
Point(p+3) = {xx, 1, 0, lc} ;
l = newreg;
BSpline(l) = {p+3,p+3,p+3,p+2,p+1,p+1,p,p,p};
BSpline(l+1) = {p,p,p,p+3,p+3,p+3};
s = newreg;
Line Loop(s) = {-l,-(l+1)};
Plane Surface(s+1) = s;

xx += 1;

// Splines (CatmullRom)
p = newp;
Point(p) = {xx,  0,  0, 0.3*lc} ;
Point(p+1) = {xx+.5, 0,  0, lc} ;
Point(p+2) = {xx+.5, 1, 0, 0.1*lc} ;
Point(p+3) = {xx, 1, 0, lc} ;
l = newreg;
Spline(l) = {p+3,p+2,p+1,p};
Spline(l+1) = {p,p+3};
s = newreg;
Line Loop(s) = {-l,-(l+1)};
Plane Surface(s+1) = s;

