lambda = 0.1 ;
larg = 0.05 ;
long = 0.5 ;
nbr_pas = 12 ; 
nbr_pas_tot = long/lambda*nbr_pas ;
ampl = 0.01 ;
lc1 = 0.005 ;
For tt In {0:nbr_pas_tot} 
  Point(1000+tt) = { tt*lambda/nbr_pas , 0. , ampl*Sin(2*Pi*tt/nbr_pas) , lc1 } ;
  tab_pt_1[tt] = 1000 + tt ;
  EndFor 
Spline(1000) = tab_pt_1[];
Extrude Line {1000 , { 0., larg , 0. } } ; 
Translate {0,0.15,0} { Duplicata { Surface{1004} ; } }
