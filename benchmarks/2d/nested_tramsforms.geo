a = 0.004;
b = 0.002;
lc = 0.001;
Point(1) = { 0, 0, 0, lc };
Point(100) = { a, 0, 0, lc };
Point(101) = { 0, b, 0, lc };
Point(102) = {-a, 0, 0, lc };
Point(103) = { 0,-b, 0, lc };

Ellipse(100) = { 100, 1, 100, 101 };
Ellipse(101) = { 101, 1, 102, 102 };
Ellipse(102) = { 102, 1, 102, 103 };
Ellipse(103) = { 103, 1, 100, 100 };

Line Loop(4) = { 100, 101, 102, 103 };
Plane Surface(4) = { 4 };

to_rad = 3.141592654/180;

/* this does not work. The problem is due to the automatic removal of
   duplicate entities that is performed by default after each
   transformation. 

   The ellipse center for the duplicate curve is the same as for the
   original one. After the rotation the automatic duplicate removal
   leaves only one. The translation moves it, which completely borks
   the first ellipse! */
/*
Translate { -0.01, 0.01, 0 } { 
  Rotate { {0, 0, 1}, {0, 0, 0}, 120*to_rad } { 
    Duplicata { Surface {4}; } 
  }
}
*/

// this is fixes it, but is a bit ugly:

Geometry.AutoCoherence = 0;
Translate { -0.01, 0.01, 0 } { 
  Rotate { {0, 0, 1}, {0, 0, 0}, 120*to_rad } { 
    Duplicata { Surface {4}; } 
  }
}
Coherence;
Geometry.AutoCoherence = 1;
