// Gmsh project created on Tue Jul 10 15:01:07 2012
// HVPS4.geo

// z.B. Widerstand in Vergussbehälter

m1=1; // am Bauteil
m2=1; // Rest Behälter
m3=1; // in der Oberfläche

// Zylinderförmiges Bauteil auf HV-Potential
R1=3;
L1=22;
WidZ=10;

// HV-Behälter mit geerdeten Wänden und offener Oberfläche
BoxX=100;
BoxY=85;
BoxZ=32;

// Oberflächenwiderstand
SurfZ=1; // Dicke der Leitschicht

Point(1) = {0, 0, 0, m1};

Translate {0, -R1, 0} {
  Duplicata { Point{1}; }
}
Extrude {{0, 0, 1}, {0, 0, 0}, Pi/2} {
  Point{2};
}
Extrude {{0, 1, 0}, {0, 0, 0}, -Pi/2} {
  Line{1};
}

Extrude {0, L1, 0} {
  Line{3};
}
Translate {0, -L1, 0} {
  Surface{8, 4};
}
Symmetry {1, 0, 0, 0} {
  Duplicata { Surface{8, 4}; }
}
Symmetry {0, 0, 1, 0} {
  Duplicata { Surface{8, 9, 4, 14}; }
}
Symmetry {0, 1, 0, 0} {
  Duplicata { Surface{9, 14, 8, 4, 30, 26, 21, 16}; }
}

Surface Loop(63) = {40, 45, 53, 62, 57, 49, 36, 31, 9, 14, 30, 21, 16, 26, 4, 8};
Volume(64) = {63};

Geometry.ExactExtrusion=0; // necessary if we transform the extruded surface...

Translate {0, 0, WidZ} { Volume{64}; }
