// you need gshhs data file, available on ftp://ftp.soest.hawaii.edu/pwessel/gshhs/gshhs_1.6.zip
Field[1] = Box;
Field[1].VIn = 2000;
Field[1].VOut = 100000;
Field[1].XMax = 6000000;
Field[1].XMin = 3000000;
Field[1].YMin = -2000000;
Field[1].YMax = 1000000;
Field[1].ZMin = 3220000;
Field[1].ZMax = 6000000;
//Field[2] = MathEval;
//Field[2].F= "1.e3";


Plugin(GSHHS).iField=1;
Plugin(GSHHS).InFileName="gshhs_f.b";
Plugin(GSHHS).OutFileName="earth_adapt.geo";
Plugin(GSHHS).Run;
/*
Merge "earth_4km.geo";
Field[3] = Threshold;
Field[3].LcMin = 4e3;
Field[3].LcMax = 500e3;
Field[3].DistMax = 2000e3;
Field[3].DistMin = 0e3;
Field[3].IField = 2;
Field[4]=MathEval;
Field[4].F = "80e3";
Background Field = 3;
*/
