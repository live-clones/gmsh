Mesh.Algorithm = 6; // test frontal algorithm

// Einheiten
mm = 1.e-3;
deg = Pi/180.;

// Charakteristische Länge
lc = 2*mm;			// allgemein
lc_delta = lc/5;		// Luftspalt


// -----------
// STATORDATEN
// -----------

da = 250.*mm;			// Aussendurchmesser
di = 126.*mm;			// Bohrungsdurchmesser
n = 10;				// Anzahl der Nuten
hNut = 65.*mm;			// Nuthöhe
bNut_u = 6.*mm;			// Nutbreite unten
bNut_o = 10.*mm;		// Nutbreite oben
bNutoeffnung = 2.*mm;		// Breite der Nutöffnung
hNutoeffnung = 4.*mm;		// Höhe der Nutöffnung
hPolfuss = 5.*mm;		// 

// Luftspalt
delta = 1.*mm;

// Mittelpunkt
x0 = 0;
y0 = 0;
z0 = 0;

// Punkte berechnen

// Umriss des Stators
ursprung = newp;  Point(ursprung) = {x0, y0, z0, lc};
Point(2) = {x0, y0 + da, z0, lc};
Point(3) = {x0 + da, y0, z0, lc};
Point(4) = {x0, y0 + di, z0, lc_delta};
Point(5) = {x0 + di, y0, z0, lc_delta};

Function Nut
  // eine Nut

  x1 = x0 + bNutoeffnung / 2;
  y1 = y0 + Sqrt(di^2-x1^2);
  
  x2 = x1;
  y2 = y1 + hNutoeffnung;
  
  x3 = bNut_u;
  y3 = y2 + hPolfuss;
  
  x4 = bNut_o;
  y4 = y3 + hNut;

  p1 = newp;  Point(p1) = {x1, y1, z0, lc_delta};
  p2 = newp;  Point(p2) = {-x1, y1, z0, lc_delta};
  p3 = newp;  Point(p3) = {x2, y2, z0, lc_delta};
  p4 = newp;  Point(p4) = {-x2, y2, z0, lc_delta};
  p5 = newp;  Point(p5) = {x3, y3, z0, lc};
  p6 = newp;  Point(p6) = {-x3, y3, z0, lc};
  p7 = newp;  Point(p7) = {x4, y4, z0, lc};
  p8 = newp;  Point(p8) = {-x4, y4, z0, lc};
  
  first[i] = p2;
  last[i] = p1;

  Rotate { {0, 0, 1}, {x0, y0, z0}, winkel} {Point{p1}; Point{p2}; Point{p3}; Point{p4}; Point{p5}; Point{p6}; Point{p7}; Point{p8};}
  
  l1[i] = newc;  Line(l1[i]) = {p1, p3};
  l2[i] = newc;  Line(l2[i]) = {p3, p5};
  l3[i] = newc;  Line(l3[i]) = {p5, p7};
  l4[i] = newc;  Line(l4[i]) = {p7, p8};
  l5[i] = newc;  Line(l5[i]) = {p8, p6};
  l6[i] = newc;  Line(l6[i]) = {p6, p4};
  l7[i] = newc;  Line(l7[i]) = {p4, p2};
  l8[i] = newc;  Line(l8[i]) = {p4, p3};

  theloops[i] = newreg;
  Line Loop(theloops[i]) = {l2[i], l3[i], l4[i], l5[i], l6[i], l8[i]};

  dienut = newreg;
  Plane Surface(dienut) = theloops[i];
  
Return

// Nuten erzeugen

winkel = 0;
i = 0;
last[0] = 4;

For i In {1:n}
  winkel = -(90 * (i-0.5)/(n)) * deg;
  Call Nut;
  l[i] = newreg;  Circle(l[i]) = {last[i-1], ursprung, first[i]};
EndFor
l[n+1] = newreg;  Circle(l[n+1]) = {last[n], ursprung, 5};

// Statorumrisse erzeugen
links = newc;  Line(links) = {2, 4};
rechts = newc;  Line(rechts) = {5, 3};
aussen = newc;  Circle(aussen) = {2, ursprung, 3};

ll = newll; 
Line Loop(ll) = { l1[{1:n}], l2[{1:n}], l3[{1:n}], l4[{1:n}], l5[{1:n}], l6[{1:n}], 
                  l7[{1:n}], -l[{1:n+1}], -links, -rechts, aussen};
Plane Surface(news) = ll;
Recombine Surface {10, 21, 32, 43, 54, 65, 76, 87, 98, 109, 116};
