// Plugin(NearToFarField): far field of complex E and H list data on the
// triangles and lines of a square, exp(+iwt) and exp(-iwt) time dependence,
// normalized in dB or raw, on a sphere, a patch and a curve; Matlab output

Merge "data/square.pos"; // views 0-3
Plugin(Remove).Points = 1;
Plugin(Remove).View = 1;
Plugin(Remove).Run; // vector on lines and triangles
Plugin(MathEval).View = 1;
Plugin(MathEval).TimeStep = 0;
Plugin(MathEval).Expression0 = "Cos(Pi*(y-0.5))";
Plugin(MathEval).Expression1 = "0";
Plugin(MathEval).Expression2 = "0";
Plugin(MathEval).Run; // view 4: Re(E)
Plugin(MathEval).Expression0 = "0.3*x";
Plugin(MathEval).Run; // view 5: Im(E)
Plugin(MathEval).Expression0 = "0";
Plugin(MathEval).Expression1 = "Cos(Pi*(y-0.5))/377";
Plugin(MathEval).Run; // view 6: Re(H)
Plugin(MathEval).Expression1 = "0.3*x/377";
Plugin(MathEval).Run; // view 7: Im(H)
View[4].Name = "E"; View[5].Name = "E";
View[6].Name = "H"; View[7].Name = "H";
Combine TimeStepsByViewName; // E and H with 2 steps, now the last 2 views
n = PostProcessing.NbViews;

Plugin(NearToFarField).EView = n - 2;
Plugin(NearToFarField).HView = n - 1;
Plugin(NearToFarField).Wavenumber = 6;
Plugin(NearToFarField).NumPointsPhi = 12;
Plugin(NearToFarField).NumPointsTheta = 6;
Plugin(NearToFarField).Run;
Plugin(NearToFarField).NegativeTime = 1;
Plugin(NearToFarField).Normalize = 0;
Plugin(NearToFarField).dB = 0;
Plugin(NearToFarField).MatlabOutputFile = "monk.m";
Plugin(NearToFarField).Run;
Plugin(NearToFarField).NegativeTime = 0;
Plugin(NearToFarField).RFar = 50;
Plugin(NearToFarField).PhiStart = 0;
Plugin(NearToFarField).PhiEnd = Pi;
Plugin(NearToFarField).ThetaStart = Pi / 4;
Plugin(NearToFarField).ThetaEnd = Pi / 2;
Plugin(NearToFarField).MatlabOutputFile = "";
Plugin(NearToFarField).Run;
Plugin(NearToFarField).NumPointsTheta = 1; // points
Plugin(NearToFarField).Run;
