/*********************************************************************
 *
 *  Gmsh tutorial 13
 *
 *  Remeshing without an underlying CAD model
 *
 *********************************************************************/

// Let's merge an STL mesh that we would like to remesh.
Merge "t13.stl";

// We first classify ("color") the surfaces by splitting the original surface
// along sharp geometrical features. This will create new discrete surfaces,
// curves and points.
angle = DefineNumber[40, Min 20, Max 120, Step 1,
  Name "Parameters/Angle for surface detection" ];
forceSmallPatches = DefineNumber[0, Choices{0,1},
  Name "Parameters/Create surfaces guaranteed to be parametrizable"];
includeBoundary = 1;
ClassifySurfaces{angle * Pi/180, includeBoundary, forceSmallPatches};

// Create a geometry for all the discrete curves and surfaces in the mesh, by
// computing a parametrization for each one
CreateGeometry;

// Create a volume as usual
Surface Loop(1) = Surface{:};
Volume(1) = {1};

// element size imposed by a size field
Field[1] = MathEval;
Field[1].F = "4";
Background Field = 1;

funny = DefineNumber[0, Choices{0,1},
  Name "Parameters/Apply funny mesh size field?" ];
If(funny)
  Field[1].F = "2*Sin((x+y)/5) + 3";
EndIf
