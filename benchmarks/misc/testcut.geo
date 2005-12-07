
View "Test 1" {
SH(0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1){ 0, 1, 1, 0, 0, 1, 1, 0};
};
View "Test 2" {
SH(1, 0, 0, 2, 0, 0, 2, 1, 0, 1, 1, 0, 1, 0, 1, 2, 0, 1, 2, 1, 1, 1, 1, 1){ 1, 0, 0, 1, 1, 0, 0, 1};
};

General.Trackball = 0;

General.RotationX = 10;
General.RotationY = -45;
General.RotationZ = 0;

Combine Views;

/*
View "Test 3" {
SH(0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1){ 0, 1, 1, 0, 0, 1, 1, 0};
SH(1, 0, 0, 2, 0, 0, 2, 1, 0, 1, 1, 0, 1, 0, 1, 2, 0, 1, 2, 1, 1, 1, 1, 1){ 1, 0, 0, 1, 1, 0, 0, 1};
};
*/

Plugin(CutGrid).X0 = 0;
Plugin(CutGrid).Y0 = 0.5;
Plugin(CutGrid).Z0 = 0.5;
Plugin(CutGrid).X1 = 2;
Plugin(CutGrid).Y1 = 0.5;
Plugin(CutGrid).Z1 = 0.5;
Plugin(CutGrid).nPointsU = 51;
Plugin(CutGrid).nPointsV = 1;
Plugin(CutGrid).ConnectPoints = 0;
Plugin(CutGrid).iView = -1;

Plugin(CutGrid).Run;

View[1].Axes = 1;
View[1].Type = 2;
View[1].IntervalsType = 2;
View[1].AxesLabelX = "U";
View[1].AxesLabelY = "x";
