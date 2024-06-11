SetFactory("OpenCASCADE");

c = 0.067;
globalScale = c/200; // 1/c
order = 1;

l_blade = 0.500000e+00*order*globalScale;
l_inlet = 1.000000e+01*order*globalScale;
l_outlet = 200000e+01*order*globalScale;
l_h0 = 5.00000e-02*order*globalScale;
l_large = 3.00000e+01*order*globalScale;
l_medium = 5*order*globalScale;
l_fine = 2.000000e-01*order*globalScale;
lc = l_large;


//blade
Include "./ls89_blade.geo";
BSpline(1) = {1:404,1};

//lower
Include "./ls89_lower.geo";
Line(2) = {406,407};
Spline(3) = {407:595};
Line(4) = {595,596};

//upper
Include "./ls89_upper.geo";
Line(5) = {597,598};
Spline(6) = {598:786};
Line(7) = {786,787};


//inlet
Line(8) = {406,597};

//exit
Line(9) = {596,787};

//+
Curve Loop(1) = {2, 3, 4, 9, -7, -6, -5, -8};
//+
Curve Loop(2) = {1};
//+
Plane Surface(1) = {1, 2};

Characteristic Length {1} = l_blade;

Characteristic Length {2,3,4,5,6,7} = l_inlet;
Characteristic Length {8,9} = l_outlet;


Recombine Surface {1};

//Boundary layer
Field[1] = BoundaryLayer;
Field[1].EdgesList = {1};
Field[1].Quads     = 1;
Field[1].hfar      = l_large;
Field[1].hwall_n   = 0.60*0.00001;
Field[1].thickness = 3.000000e+00*globalScale;
Field[1].ratio     = 1.3;

//===========================================
// Leading and trailing edge refinement
//===========================================
Field[2]         = Cylinder ;
Field[2].XCenter = 0.0364595;
Field[2].YCenter = -0.0523006;
Field[2].ZCenter = 0.000000e+00;
Field[2].XAxis = 0.000000e+00;
Field[2].YAxis = 0.000000e+00;
Field[2].ZAxis = 1.000000e+00;
Field[2].Radius = 3*globalScale;
Field[2].VIn = 0.98*l_fine;
Field[2].VOut = l_large;

Field[3]         = Cylinder ;
Field[3].XAxis = 0.000000e+00;
Field[3].YAxis = 0.000000e+00;
Field[3].ZAxis = 1.000000e+00;
Field[3].XCenter = 0*globalScale;
Field[3].YCenter = 0*globalScale;
Field[3].ZCenter = 0.000000e+00;
Field[3].Radius = 4*globalScale;
Field[3].VIn = l_medium;
Field[3].VOut = l_large;

Field[4] = Cylinder ;
Field[4].XCenter = 0.03;
Field[4].YCenter = -0.06;
Field[4].ZCenter = 0.000000e+00;
Field[4].XAxis = 0;
Field[4].YAxis = 1;
Field[4].ZAxis = 0;
Field[4].Radius = 0.04;
Field[4].VIn = l_medium;
Field[4].VOut = l_large;


//===========================================
// Merge refinements
//===========================================
Field[5000] = Min;
Field[5000].FieldsList = {2,3,4};
Background Field = 5000;
BoundaryLayer Field = 1;

Extrude {0, 0, 0.0112} {
  Surface{1}; Layers {15}; Recombine;
}

// use 2D del-quad for nicer quads
Mesh.Algorithm = 8;

Mesh 3;
SetOrder 2;

// optimize boundary layer mesh using fast-curving algorithm (requires more
// layers than default to handle very thin elements on high curvature area)
Mesh.HighOrderNumLayers = 12;
OptimizeMesh "HighOrderFastCurving";

Save "ls89.msh";
