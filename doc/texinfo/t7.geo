@format
@code{
/********************************************************************* 
 *
 *  Gmsh tutorial 7
 * 
 *  Anisotropic meshes, Attractors
 *
 *********************************************************************/

// The anisotropic 2D mesh generator can be selected with:

Mesh.Algorithm = 2 ;

// One can force a 4 step Laplacian smoothing of the mesh with:

Mesh.Smoothing = 4 ;

lc = .1;

Point(1) = @{0.0,0.0,0,lc@};
Point(2) = @{1.2,-0.2,0,lc@};
Point(3) = @{1,1,0,lc@};
Point(4) = @{0,1,0,lc@};

Line(1) = @{3,2@};
Line(2) = @{2,1@};
Line(3) = @{1,4@};
Line(4) = @{4,3@};

Line Loop(5) = @{1,2,3,4@};
Plane Surface(6) = @{5@};

Point(5) = @{0.1,0.2,0,lc@};
Point(11) = @{0.5,0.5,-1,lc@};
Point(12) = @{0.5,0.5,0,lc@};
Point(22) = @{0.6,0.6,1,lc@};

Line(5) = @{11,22@};

Spline(7) = @{4,5,12,2@};

// Anisotropic attractors can be defined on points and lines:

Attractor Line@{5@} = @{.1, 0.01, 17@};

Attractor Line@{1,2@} = @{0.1, 0.005, 3@};
Attractor Line@{7@} = @{0.1, 0.05, 3@};

}
@end format
