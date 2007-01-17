micra = 1e-6;

// Differential pencil probe KDS 70-2
// Producer: Rohmann GmbH, Germany
// Coils with ferrite core and shielding
// 2 coils with 35 turns (wire diameter 0.05 mm ) on 'half D' core (0.5 mm)
// Primary coil with 21 turns (wire diameter 0.1 mm)- global diameter 1.6 mm
// lift-off: 0.92 mm 
// (distance between the end of probe - in contact with sample and first turn)

Rcore = 450 * micra ;
w = 50 * micra ;
turns = 11 ;
turns_in = turns ;
turns_out = turns;
w_in = w ;
w_out_ = w ;
d_coils = 0 ;

hc = 620 * micra ; 
sc = w;

dist = 380 * micra ;

w_air = (230+170+70)*micra/2 ;
w_blindage = (400+290)*micra/2 ;

liftoff = 100 * micra ; 

//-----------------------------------------------------------------------------------
COILOUT = 1000 ;
COILIN1 = 1001 ;
COILIN2 = 1002 ;

SKINCOILIN1 = 1011 ;
SKINCOILIN12 = 1012 ;

SKINCOILIN2 = 1021 ;
SKINCOILIN22 = 1022 ;

SKINCOILOUT = 1100;
SKINCOILOUT2 = 1200;

CUTCOILIN1 = 1111 ; 
CUTCOILIN2 = 1112 ;
CUTCOILOUT = 1113 ;
 
CORE1 = 2000 ;
CORE2 = 2001 ;

CORE1_0 = 2010 ;
CORE2_0 = 2011 ;

CORE1_1 = 2012 ;
CORE2_1 = 2013 ;

SKINCORE1 = 2110 ;
SKINCORE2 = 2111 ;

GAP = 2222 ;

SHIELD = 5000;

