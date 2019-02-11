// This file was originally written by Nico Schloemer,
// Citation: http://onelab.info/pipermail/gmsh/2012/007576.html

//set options
Geometry.Surfaces=1;
Mesh.SurfaceFaces=1;
Mesh.RecombinationAlgorithm = 0;
Mesh.Algorithm=6; // mesh algorithm
Mesh.Algorithm3D=4; // mesh algorithm
Geometry.AutoCoherence = 1;
Geometry.OldRuledSurface=1;

Function MyTorus
  // Given a zshift and two radii irad and orad, and a zshift, this
  // creates a torus parallel to the x-y-plane.
  // The points:
  tp1 = newp;
  Point(tp1) = {0,orad,zshift,lcar};
  tp2 = newp;
  Point(tp2) = {0,irad+orad,zshift,lcar};
  tp3 = newp;
  Point(tp3) = {0,orad,zshift+irad,lcar};
  tp4 = newp;
  Point(tp4) = {0,orad,zshift-irad,lcar};
  tp5 = newp;
  Point(tp5) = {0,-irad+orad,zshift,lcar};
  // One cirle:
  tc1 = newreg;
  Circle(tc1) = {tp2,tp1,tp3};
  tc2 = newreg;
  Circle(tc2) = {tp3,tp1,tp5};
  tc3 = newreg;
  Circle(tc3) = {tp5,tp1,tp4};
  tc4 = newreg;
  Circle(tc4) = {tp4,tp1,tp2};
  // The extrusion to the torus:
  tll1 = newreg;
  Line Loop(tll1) = {tc1,tc2,tc3,tc4};
  ts1 = newreg;
  Plane Surface(ts1) = {tll1};
  // Gmsh cannot rotate beyond PI, so split the extrusion up in three parts.
  ts2[] = Extrude {{0,0,1}, {0,0,0}, 2*Pi/3}{Surface{ts1};};
  ts3[] = Extrude {{0,0,1}, {0,0,0}, 2*Pi/3}{Surface{ts2[0]};};
  ts4[] = Extrude {{0,0,1}, {0,0,0}, 2*Pi/3}{Surface{ts3[0]};};

  // Delete the unneeded entities.
  Delete {
    Volume{1};
    Volume{2};
    Volume{3};
    Surface{ts1};
    Surface{ts2[0]};
    Surface{ts3[0]};
  }

  // Define outer surface.
  // We then store the surface loops identification numbers in a list
  // for later reference (we will need these to define the final
  // volume).
  theloops[t] = newreg;
  Surface Loop(theloops[t]) = {ts2[2], ts2[3], ts2[4], ts2[5],
                               ts3[2], ts3[3], ts3[4], ts3[5],
                               ts4[2], ts4[3], ts4[4], ts4[5]};
//                                   71, ts4[3], ts4[4], ts4[5]};

  thetorus = newreg;
  Volume(thetorus) = {theloops[t]};

  Physical Volume(Sprintf("coil %g", t)) = thetorus;
Return

// Actual creation starts here.
t = 1;
lcar = 0.05;
orad = 0.5;
irad = 0.15;
zshift = 0.04;
Call MyTorus;
