
Include "Rotor.geo" ;
Include "Stator.geo" ;

MB = 9999;
If (MB)
  dH=newreg; 
  Line Loop(dH) = {OuterMB_[]};
  Line Loop(dH+1) = {InnerMB_[]};
  Plane Surface(dH) = {dH,dH+1};
  Physical Surface(MB) = {dH};
  Color Black {Surface{dH};}
EndIf




Mesh.CharacteristicLengthFactor = 1.2;

Mesh.Smoothing = 5;
//Mesh.Algorithm = 2;
Mesh.ElementOrder = 2;

Coherence;

dP=newp-1;
Point(dP+1)  = {0.0258, 0.0045, 0, p*2};  //stator
//Point(dP+2)  = {0.0248, 0.0043, 0, p*2};  
Point(dP+2)  = {0.0242, 0.007, 0, p*2};  








