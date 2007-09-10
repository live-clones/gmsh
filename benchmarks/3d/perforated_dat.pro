TRANS = 1 ;
SQUARES = 0 ;
u = 1e-3 ;

// Geometry of induction heater archetype
nbrHoles = 8 ;

dhole =  20 * u ;
rh = dhole/2;

h_ps = 2*nbrHoles*dhole+dhole ;

// Workpiece: Al disk at (0,0)
r = 191 * u ; 
h = 10 * u ;

mu0 = 4.e-7 * Pi ;
sigmaW = 3.7e7 ;

// Excitation Coil at (202,0)
w_ec = 1.5 * u ;//cross section width
h_ec = 16 * u ; //cross section height

x_ec = 201.2 * u ; //inner radius

//Passive shield at (300.3, 0)
w_ps = 0.65 * u;//*40 ;
//h_ps = 190 * u ;

x_ps = 300  * u;//inner radius

//Target area (500,0) (1500,800)

rta = 0.50 ; 
wta = 1. ;
hta = .8 ;

rfar = (rta+wta);
rfar2 = rfar + 0.2*rfar;

rfar  = ((x_ps > h_ps/2) ?  1.6 * x_ps : .7*h_ps) ;
rfar2 = ((x_ps > h_ps/2) ?  1.9 * x_ps : .9*h_ps) ;



//PHYSICAL REGIONS

WORKPIECE     = 1000 ;
SKINWORKPIECE = 1001 ;
Z0WORKPIECE   = 1002 ;
PHI0WORKPIECE = 1003 ;
PHI1WORKPIECE = 1004 ;

PASSIVESHIELD =     2000 ;
SKINPASSIVESHIELD = 2001 ;
SKINPASSIVESHIELD2= 2002 ;
Z0PASSIVESHIELD   = 2003;
PHI0PASSIVESHIELD = 2004 ;
PHI1PASSIVESHIELD = 2005 ;

LINPHI0SHELLINT   = 2006 ;
LINPHI1SHELLINT   = 2007 ;
LINZ0SHELLINT     = 2008 ;

CUTPASSIVESHIELD = 2222 ;
SKINPASSIVESHIELDINT = 2223 ;
SKINPASSIVESHIELDEXT = 2224 ;

//Coils
EC  = 3000 ; 
SKINEC = 3333 ; 
SKINEC2 = 3334 ; 
CUTEC = 3335 ;
Z0EC = 3336;
PHI0EC = 3337;
PHI1EC = 3338;

AIR    = 5000 ; 
SURAIR = 5010 ;
Z0AIR0 = 5001 ;
Z0AIR1 = 5002 ;
Z0AIR2 = 5003 ;
PHI0AIR = 5004;
PHI1AIR = 5005;

AIRINF     = 6000 ;
SURAIRINF  = 6010 ;
Z0AIRINF   = 6001 ; 
PHI0AIRINF = 6002 ;
PHI1AIRINF = 6003 ;

