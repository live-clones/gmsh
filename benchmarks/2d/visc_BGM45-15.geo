lc1 = 4.;
lc2 = 4.;
Point( 1) = {   0.00000,  0.00000, 0.0, lc1};
Point( 2) = {   0.00000, 63.50000, 0.0, lc1};
Point( 3) = {   7.87400, 63.50000, 0.0, lc1};
Point( 4) = {  22.25000, 57.57847, 0.0, lc1};
Point( 5) = {  55.87660, 24.05100, 0.0, lc2};
Point( 6) = {  64.83803, 20.32000, 0.0, lc2};
Point( 7) = {  68.14965, 20.76200, 0.0, lc2};
Point( 8) = { 185.03900, 52.32200, 0.0, lc1};
Point( 9) = { 185.03900,  0.00000, 0.0, lc1};
Point(10) = {  64.83803,  0.00000, 0.0, lc2};
// center of circle arcs
Point(11) = {   7.87400, 43.18000, 0.0, lc1};
Point(12) = {  64.83803, 32.95000, 0.0, lc2};
//
Line(1) = {1, 2};
Line(2) = {2, 3};
Circle(3) = {3, 11, 4};
Line(4) = {4, 5};
Circle(5) = {5, 12, 6};
Circle(6) = {6, 12, 7};
Line(7) = {7, 8};
Line(8) = {8, 9};
Line(9) = {9, 10};
Line(10) = {10, 1};
Line Loop(1) = {1:10};

Plane Surface(1) = {1};

Field[1] = BoundaryLayer;
Field[1].CurvesList = {2:7};
Field[1].PointsList = {2:8};
Field[1].Size = 0.1;
Field[1].SizeFar = 4.;
Field[1].Ratio = 1.2;
Field[1].Thickness = 2.;
Field[1].Quads = 1;

//Field[2] = MinAniso;
//Field[2].FieldsList = {1};
//Background Field = 2;
BoundaryLayer Field = 1;
