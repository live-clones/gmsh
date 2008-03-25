// you need gshhs data file, available on ftp://ftp.soest.hawaii.edu/pwessel/gshhs/gshhs_1.6.zip
Field[1] = MathEval;
Field[1].F= "100.e3";
/*
Plugin(GSHHS).iField=1;
Plugin(GSHHS).InFileName="gshhs_f.b";
Plugin(GSHHS).OutFileName="earth_100km.geo";
Plugin(GSHHS).Run;
*/
Merge "earth_100km.geo";
Field[3] = Threshold;
Field[3].LcMin = 10e3;
Field[3].LcMax = 500e3;
Field[3].DistMax = 2000e3;
Field[3].DistMin = 0e3;
Field[3].IField = 2;
Field[4]=MathEval;
Field[4].F = "80e3";
Background Field = 3;

