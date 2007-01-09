rayon = 0.004 ; 
haut  = 0.012 ;           // hauteur du cylindre
psi   = 40. * Pi / 180 ;  // angle de tressage par rapport a l'axe vertical z du cable
nn    = 24 ;              // nbre de meplats (qui vont dans le meme sens) 
nw    = 5;               // nombre de fils dans un meplat
dw    = 0.0002 ;          // diametre des fils
ampl  = 0.0003 ;          // amplitude du Cosinus
v     = 1 ;               // je le pose arbitrairement
omega = 1 / ( rayon * Tan(Pi/2-psi) ) ; Printf("omega = %g" , omega ) ;
tmax = haut ; 
nbr_pas_tot = 30 ;
dt = tmax / nbr_pas_tot ;
omdeph = nn * omega / 2;  // vitesse angulaire pour dephasage de Pi entre 2 meplats
angm = dw/rayon/Cos(psi) ; 

Geometry.AutoCoherence = 0;

lc1 = 0.0008 ;

For jj In {1:nn} 

   For ii In {0:nbr_pas_tot} 

      t = ii * dt ;
      rf = rayon ; 
      thetaf =  -nw*angm/2 + (jj-1)*2*Pi/nn + omega * t ; 
      zf = v * t ;
      aa = ampl * Cos( Pi/4 + (jj-1)*Pi + omdeph * t );
      xf = (rf+aa) * Cos(thetaf) ; yf = (rf+aa) * Sin(thetaf) ;
      Point((2*jj-1)*1000+ii) = { xf , yf , zf , lc1 } ;
      tab1[ii] = (2*jj-1)*1000+ii ;

      thetaf =  -nw*angm/2 + (jj-1)*2*Pi/nn - omega * t ; 
      aa = ampl * Cos( 3*Pi/4 + (jj-1)*Pi + omdeph * t );
      xf = (rf+aa) * Cos(thetaf) ; yf = (rf+aa) * Sin(thetaf) ;
      Point((2*jj)*1000+ii) = { xf , yf , zf , lc1 } ;
      tab2[ii] = (2*jj)*1000+ii ;

      EndFor
     
      Spline((2*jj-1)*1000+ii) = tab1[];
//    Extrude Line { ((2*jj-1)*1000+ii) , {0,0,1}, {0,0,0}, nw*angm } ;
      For kk In {1:nw-1}
         Rotate { {0,0,1}, {0,0,0}, kk*angm}  { Duplicata { Line{(2*jj-1)*1000+ii} ; } }
         EndFor

      Spline((2*jj)*1000+ii) = tab2[];
//    Extrude Line { ((2*jj)*1000+ii) , {0,0,1}, {0,0,0}, nw*angm } ;
      For kk In {1:nw-1}
         Rotate { {0,0,1}, {0,0,0}, kk*angm}  { Duplicata { Line{(2*jj)*1000+ii} ; } }
         EndFor

   EndFor      

//BoundingBox;

//FIXME: this is buggy -- investigate
Coherence;

b = rayon ; 
L = 2*nn ;    
N = nw ;       
d = dw ;  
ld = 4*Pi*b/L-N*d/Cos(psi) ;// small axis of the diamond shaped aperture (horizontal)
Ld = ld/Tan(psi) ;          // Big axis of the diamond shaped aperture (vertical=z)
P = 4*Pi*b/L/Tan(psi);      // Periode du tressage selon axe z vertical du cable
n = L*L*Tan(psi)/(4*Pi*b) ; // number of apertures per unit length
F = N*d*L/(4*Pi*rayon*Cos(psi)) ; Printf("Fill Factor = %g" , F ) ;
K = 2*F-F*F ;                     Printf("Optical coverage = %g" , K ) ;
