

Function Square

p1 = newp ; Point (p1) = {   X0,   Y0, Z0, LC } ;
p2 = newp ; Point (p2) = { X0+c,   Y0, Z0, LC } ;
p3 = newp ; Point (p3) = { X0+c, Y0+c, Z0, LC } ;
p4 = newp ; Point (p4) = {   X0, Y0+c, Z0, LC } ;

l1 = newl ; Line (l1) = { p1, p2 } ;
l2 = newl ; Line (l2) = { p2, p3 } ;
l3 = newl ; Line (l3) = { p3, p4 } ;
l4 = newl ; Line (l4) = { p4, p1 } ;

Transfinite Line { l1, l2, l3, l4 } = D ;

ll = newl ; Line Loop (ll) = { l1, l2, l3, l4 } ;
ns = news ; Plane Surface (ns) = { ll } ;
Transfinite Surface { ns } = { p1, p2, p3, p4 } ;
Recombine Surface { ns } ;

LS[iLS] = ns ; iLS += 1 ;

Return


LS[] = { 0 } ; iLS = 0 ;

c  = 1.0 ;
LC = 0.1 ;
D  = 11 ;

X0 = 0 ; Y0 = 0 ; Z0 = 0 ; 

Call Square ;

X0 += c ;
Call Square ;

Coherence ;

Physical Surface (100) = LS[] ;

