nn = 10 ; // nombre de meplats sur un cote
dd = 0.002 ; // distance entre 2 meplats
larg = 0.0016; //largeur du meplat = dd - separation entre meplats
ampl = 0.0001 ; // amplitude dus Sin
nbrp = 10 ; // nombre de subdivisions sur une longueur d'onde
ll = 2*dd ; 
long = nn*ll/2 ;
nbrp_tot = long/ll*nbrp ;
deph = Pi ;

lc1 = ll/nbrp ;

// Point(1)   = { 0. , 0. , 0. , lc1 } ;

For ii In {0:nn-1}

   For tt In {0:nbrp_tot} 

      Point(2*ii*1000+tt) = { tt*ll/nbrp , ii*dd-larg/2 , ampl*Sin(2*Pi*tt/nbrp+ii*deph) , lc1 } ;
      tab1[tt] = 2*ii*1000+tt ;
      Point((2*ii+1)*1000+tt)={dd/2+ii*dd-larg/2,-ll/4+tt*ll/nbrp,ampl*Sin(2*Pi*tt/nbrp-Pi+ii*deph),lc1};
      tab2[tt] = (2*ii+1)*1000+tt ;
      EndFor

   Spline(2*ii*1000+tt) = tab1[];
   Extrude Line {2*ii*1000+tt ,     { 0. , larg , 0. } } ; 
   Spline((2*ii+1)*1000+tt) = tab2[];
   Extrude Line {(2*ii+1)*1000+tt , { larg , 0. , 0. } } ; 
   EndFor

/*
//Translate {0,0.15,0} { Duplicata { Surface{1004} ; } }
Plane Surface (1002) = {1001} ;
Physical Surface (9999) = tab2[] ; 
*/
