
// proj. problem with angle=pi/2

angle=Pi/2;

mpi     = 0.0254;

dia1    = 3.50 * mpi;
rad1    = dia1 / 2.0;

dia2    = 75.00 * mpi;
rad2    = dia2 / 2.0;

thick   = 1.0 * mpi;
length1 = 1.5 * dia1;

x0      = 0.0;
y0      = 0.0;
z0      = 0.0;

y1  = y0 - 0.50 * length1 ;
yr1 = y1 - 0.25 * length1 ;

y2  = y1 + length1;
yr2 = y2 + 0.25 * length1;

lcart1  = 0.05 * rad1;
// lcart2  = 0.100 * rad2;
// lcart2  = 0.050 * rad2;
lcart2  = 0.025 * rad2;

Printf ( " %f %f ", lcart1, lcart2 );

p01 = newp; Point(p01) = { x0 + rad1,  yr1,   z0, lcart1};
p02 = newp; Point(p02) = { x0 + rad2,  yr1,   z0, lcart2};
p03 = newp; Point(p03) = { x0 + rad2,  yr2,   z0, lcart2};
p04 = newp; Point(p04) = { x0 + rad1,  yr2,   z0, lcart1};

l01  = newreg; Line (l01) = { p01, p02 };
l02  = newreg; Line (l02) = { p02, p03 };
l03  = newreg; Line (l03) = { p03, p04 };
l04  = newreg; Line (l04) = { p01, p04 };

a1 = newreg; s1 = newreg; Line Loop ( a1 ) = { l01, l02, l03, -l04 } ;  Plane Surface ( s1 ) = { a1 };
s11[] = Extrude Surface { s1, { 0, 1, 0 }, { 0.0, 0.0, 0.0 }, -angle  }; ;
