/* 
   Gmsh demo file (C) 2000 C. Geuzaine, J.-F. Remacle

   A example of attractors

   All important comments are marked with "README"
*/

Options{
  
  Mesh{
    Algorithm = 2 ; // This is the new 2D anisotropic algorithm
  }

}

lc = .1;

Point(1) = {0.0,0.0,0,lc};
Point(2) = {1,0.0,0,lc};
Point(3) = {1,1,0,lc};
Point(4) = {0,1,0,lc};

Line(1) = {3,2};
Line(2) = {2,1};
Line(3) = {1,4};
Line(4) = {4,3};

Line Loop(5) = {1,2,3,4};
Plane Surface(6) = {5};

Point(5) = {0.1,0.2,0,lc};
Point(11) = {0.5,0.5,-1,lc};
Point(22) = {0.6,0.6,1,lc};

Line(5) = {11,22};

Attractor Line{5} = {1, 0.1, 7};

Attractor Point{5} = {0.1, 0.5, 3};
