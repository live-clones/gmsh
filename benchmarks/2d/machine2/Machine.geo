
Include "Rotor1.geo" ;
Include "Stator1.geo" ;

MB = 9999;
If (MB)
  dH=newreg; 
  Line Loop(dH) = {OuterMB_[]};
  Line Loop(dH+1) = {InnerMB_[]};
  Plane Surface(dH) = {dH,dH+1};
  Physical Surface(MB) = {dH};
EndIf

Mesh.CharacteristicLengthFactor = 0.3*1.*0.5*2*0.6;
Mesh.Smoothing = 5;
Mesh.Algorithm = 1;

Coherence;
