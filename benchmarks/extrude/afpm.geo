// arquivo para teste do desenho do motor a fluxo axial usando extrusao.
// Liege. Inicio => 29 de novembro de 2001.

deg2rad = Pi/180;
Geometry.OldNewReg=0;
Geometry.AutoCoherence=0;

r[] = {0,0.020,0.022,0.025,0.040,0.043,0.045,0.060} ;
t[] = {4,6,6,8,6,6,8,6,6,4} ;

s = 1.; //1.5e-03;

For i In {0:7}
  Point(i+1)={r[i],0,0,s};
  If(i)
    num[i-1]=i;
    Line(i)={i,i+1};
  EndIf
EndFor

For i In {0:6}
  For j In {0:9}
    Extrude Line {num[i], {0,0,1}, {0,0,0}, t[j]*deg2rad}{Layers{1};Recombine;};
    num[i] = newreg-(i?3:2);
  EndFor
EndFor

For i In {1:70}
  Extrude Surface {i, {0,0,0.005}}{Layers{1};Recombine;};
  For j In {1:5}
     Extrude Surface {news-1, {0,0,0.005}}{Layers{1};Recombine;};
  EndFor
EndFor

Coherence;
Geometry.OldNewReg=1;
Geometry.AutoCoherence=1;
