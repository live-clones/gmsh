rayon = 0.008 ; 
haut  = 0.024 ;           // hauteur du cylindre
psi   = 40. * Pi / 180 ;  // angle de tressage par rapport a l'axe vertical z du cable
nn    = 24 ;              // nbre de meplats (qui vont dans le meme sens) 
nw    = 6 ;               // nombre de fils dans un meplat
dw    = 0.0002 ;          // diametre des fils
ampl  = 0.0004 ;          // amplitude du Cosinus
v     = 1 ;               // je le pose arbitrairement
omega = 1 / ( rayon * Tan(Pi/2-psi) ) ; Printf("omega = %g" , omega ) ;
tmax = haut ; 
nbr_pas_tot = 50 ;
dt = tmax / nbr_pas_tot ;
omdeph = nn * omega / 2;  // vitesse angulaire pour dephasage de Pi entre 2 meplats
angm = dw/rayon/Cos(psi) ; 

Geometry.AutoCoherence = 0;

lc1 = 0.0011 ;

For jj In {1:nn} 

   For ii In {0:nbr_pas_tot} 

      t = ii * dt ;
      rf = rayon ; 
      thetaf =  -nw*angm/2 + (jj-1)*2*Pi/nn + omega * t ; 
      zf = v * t ;
      aa = ampl * Cos( Pi/4 + (jj-1)*Pi + omdeph * t );
      xf = (rf+aa) * Cos(thetaf) ; yf = (rf+aa) * Sin(thetaf) ;
      num = (2*jj-1)*10000+ii;
      Point(num) = { xf , yf , zf , lc1 } ;
      tab1[ii] = num ;

      thetaf =  -nw*angm/2 + (jj-1)*2*Pi/nn - omega * t ; 
      aa = ampl * Cos( 3*Pi/4 + (jj-1)*Pi + omdeph * t );
      xf = (rf+aa) * Cos(thetaf) ; yf = (rf+aa) * Sin(thetaf) ;
      num = (2*jj)*10000+ii;
      Point(num) = { xf , yf , zf , lc1 } ;
      tab2[ii] = num;

   EndFor

   num = (2*jj-1)*10000+ii;
   Spline(num) = tab1[];
   Extrude Line { num , {0,0,1}, {0,0,0}, nw*angm }{Layers{5,num,1};Recombine;} ;

   num = (2*jj)*10000+ii;
   Spline(num) = tab2[];
   Extrude Line { num , {0,0,1}, {0,0,0}, nw*angm }{Layers{5,num,1};Recombine;} ;

EndFor      

Coherence;
