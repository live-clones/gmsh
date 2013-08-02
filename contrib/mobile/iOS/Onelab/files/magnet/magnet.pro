/*
   To solve the problem
   with scalar potential, type 'getdp test -solve MagSta_phi -pos phi'
   with vector potential, type 'getdp test -solve MagSta_a -pos a'
*/

Include "magnet_data.pro";

Group {
  // AIR, AIR_INF, etc. are variables defined in core.txt, and correspond to the
  // tags of physical regions in the mesh
  Air     = Region[ AIR ];
  AirInf  = Region[ AIR_INF ];
  Core    = Region[ CORE ];
  AirGap  = Region[ AIR_GAP ];
  Magnet  = Region[ MAGNET ];

  // These are the generic group names that are used in "Magnetostatics.pro"
  Domain_S = Region[ {} ] ;
  Domain_Inf = Region[ AirInf ] ;
  Domain_M   = Region[ Magnet ] ;
  Domain_Mag = Region[ {Air, Core, AirGap} ] ;
  Dirichlet_a_0   = Region[ LINE_INF ] ;
  Dirichlet_phi_0 = Region[ {LINE_X, LINE_INF} ] ;
}

Function {
  mu0 = 4.e-7 * Pi ;

  // DefineConstant is used to define a default value for murCore; this value
  // can be changed interactively by the ONELAB server
  DefineConstant[ murCore = {200., Min 1, Max 1000, Step 10,
                             Label "Core relative permeability",
                             Path "Parameters/Materials"} ];

  nu [ Region[{Air, AirInf, AirGap, Magnet}] ] = 1. / mu0 ;
  nu [ Core ]  = 1. / (murCore * mu0) ;

  mu [ Region[{Air, AirInf, AirGap, Magnet}] ] = mu0 ;
  mu [ Core ]  = murCore * mu0;

  DefineConstant[ Hc = {920000, Label "Magnet coercive field (A/m)",
                        Path "Parameters/Materials"} ];
  hc [ Magnet ] = Vector[0., Hc, 0.] ;
}

Include "Magnetostatics.pro"

eps = 1.e-5 ;

PostOperation {
  { Name phi ; NameOfPostProcessing MagSta_phi;
    Operation {
      Print[ phi, OnElementsOf Domain, File "phi.pos" ] ;
      Print[ b, OnElementsOf Domain, File "b_phi.pos" ] ;
      Print[ b, OnLine {{-0.07,eps,0}{0.09,eps,0}} {500}, File "b_phi.txt", Format Table ] ;
      Printf [ "murCore: %f", murCore ] ;
    }
  }
  { Name a ; NameOfPostProcessing MagSta_a;
    Operation {
      Print[ a, OnElementsOf Domain, File "a.pos"] ;
      Print[ b, OnElementsOf Domain, File "b_a.pos" ] ;
      Print[ h, OnElementsOf Domain, File "h_a.pos" ] ;
      Print[ b, OnLine {{-0.07,eps,0}{0.09,eps,0}} {500}, File "b_a.txt" , Format Table ] ;
      Printf [ "murCore: %f", murCore ] ;
    }
  }
}
