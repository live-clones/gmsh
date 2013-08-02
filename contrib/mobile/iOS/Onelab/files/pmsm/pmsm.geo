Include "pmsm_data.geo";

Mesh.Algorithm = 1;
Geometry.CopyMeshingMethod = 1;

Mesh.CharacteristicLengthFactor = 1.5 ;


// Mesh characteristic lengths
s = 0.4 ;
pR1=(rR2-rR1)/6.*s;
pR2=(rR2-rR1)/6.*s;

pS1=(rS7-rS1)/7.*s;
pS2=(rS7-rS1)/12.*s;
pS3=(rS6-rS3)/10.*s;

NbrDivMB = 2*Ceil[2*Pi*rRext/8/pR1]; //1/8 Moving band

//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------

cen = newp ; Point(cen)={0,0,0,pR1};
nicepos_rotor[] = {};
nicepos_stator[] = {};

Include "pmsm_rotor.geo";
Include "pmsm_stator.geo";


// For nice visualisation...
Mesh.Light = 0 ;
//Mesh.SurfaceFaces = 1; Mesh.SurfaceEdges=0;

Hide { Point{ Point '*' }; }
Hide { Line{ Line '*' }; }
Show { Line{ nicepos_rotor[], nicepos_stator[] }; }

Physical Line(NICEPOS) = { nicepos_rotor[], nicepos_stator[] };

//For post-processing...
View[0].Light = 0;
View[0].NbIso = 25; // Number of intervals
View[0].IntervalsType = 1;

DefineConstant[ Flag_AddInfo = {0, Choices{0,1},
                               Label "Add info about phases and axis",
                               Path "Input/1"} ];

For i In {PostProcessing.NbViews-1 : 0 : -1}
  If(StrFind(View[i].Attributes, "tmp"))
    Delete View[i];
  EndIf
EndFor

If(Flag_AddInfo)
  rr = 1.25 * rS3 ;
  For k In {0:NbrPoles-1}
    xa[] += rr*Cos(1*Pi/24+k*Pi/4) ; ya[] += rr*Sin(1*Pi/24+k*Pi/4) ;
    xb[] += rr*Cos(3*Pi/24+k*Pi/4) ; yb[] += rr*Sin(3*Pi/24+k*Pi/4) ;
    xc[] += rr*Cos(5*Pi/24+k*Pi/4) ; yc[] += rr*Sin(5*Pi/24+k*Pi/4) ;
  EndFor

  // Adding some axes
  rr0 = 0.3 * rS7 ;
  rr1 = 1.3 * rS7 ;
  th_d = InitialRotorAngle ;
  th_q = th_d + 22.5 * deg2rad ;

  th_a = 30 * deg2rad ;
  th_b = (30 + 120/4) * deg2rad ;
  th_c = (30 + 240/4) * deg2rad ;

  ff = 0.9;

  xd[0] = rr0*Cos(th_d) ;    yd[0] = rr0*Sin(th_d) ;
  xd[1] = ff*rr1*Cos(th_d) ; yd[1] = ff*rr1*Sin(th_d) ;
  xq[0] = rr0*Cos(th_q) ;    yq[0] = rr0*Sin(th_q) ;
  xq[1] = ff*rr1*Cos(th_q) ; yq[1] = ff*rr1*Sin(th_q) ;

  xaa[0] = rr0*Cos(th_a) ; yaa[0] = rr0*Sin(th_a) ;
  xaa[1] = rr1*Cos(th_a) ; yaa[1] = rr1*Sin(th_a) ;
  xbb[0] = rr0*Cos(th_b) ; ybb[0] = rr0*Sin(th_b) ;
  xbb[1] = rr1*Cos(th_b) ; ybb[1] = rr1*Sin(th_b) ;
  xcc[0] = rr0*Cos(th_c) ; ycc[0] = rr0*Sin(th_c) ;
  xcc[1] = rr1*Cos(th_c) ; ycc[1] = rr1*Sin(th_c) ;


  Include "info_view.geo";

EndIf




