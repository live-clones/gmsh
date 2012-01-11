Mesh.RecombinationAlgorithm=1;
Mesh.Algorithm = 8;

unit = 1.0e-02 ;

DefineConstant[ H = {4.5 * unit, Min 1 *unit, Max 8.5 *unit, Step 1*unit, Path "Parameters/Geometry",
                     ShortHelp "Beam Height"} ] ;
DefineConstant[ L = {20 * unit, Min 10 *unit, Max 200 *unit, Step 1*unit, Path "Parameters/Geometry",
                     ShortHelp "Beam Width"} ] ;
DefineConstant[ lc = {2 * unit, Min .1 *unit, Max 10 *unit, Step .1*unit, Path "Parameters/Geometry",
                     ShortHelp "Mesh Size"} ] ;

Point(1) = {0, 0, 0, lc};
Point(2) = {H, 0, 0, lc};
Point(3) = {H, L, 0, lc};
Point(4) = {0, L, 0, lc};
Line(1) = {4, 3};
Line(2) = {3, 2};
Line(3) = {2, 1};
Line(4) = {1, 4};
Line Loop(5) = {2, 3, 4, 1};
Plane Surface(6) = {5};
Physical Surface(7) = {6};
Physical Line(8) = {1};
Physical Line(9) = {3};
Recombine Surface {6};
