/*
This is a very simple control sequense
with 2 imbricated loops
*/

i=0;
For t In {0:1:0.1}
  For x In {0:0.5:0.1}
    p = newp;
    Point(p) = {t,x,0,.1};
    aa[i] = p;
    i++;
  EndFor
EndFor

BSpline(1) = {1,1,aa[],p,p};

Spline(2) = {aa[]};

