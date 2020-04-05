// -----------------------------------------------------------------------------
//
//  Gmsh GEO tutorial 20
//
//  STEP import and manipulation
//
// -----------------------------------------------------------------------------

// The OpenCASCADE geometry kernel allows to import STEP files and to
// modify them

SetFactory("OpenCASCADE");

// Load a STEP file (Using `ShapeFromFile' instead of `Merge' allows to directly
// retrieve the tags of the highest dimensional imported entities):
v() = ShapeFromFile("t20_data.step");

// If we had specified
//
// Geometry.OCCTargetUnit = "M";
//
// before merging the STEP file, OpenCASCADE would have converted the units to
// meters (instead of the default, which is millimeters).

// Get the bounding box of the loaded volume:
bbox() = BoundingBox Volume{v()};
xmin = bbox(0);
ymin = bbox(1);
zmin = bbox(2);
xmax = bbox(3);
ymax = bbox(4);
zmax = bbox(5);

// We want to slice the model into N slices, and either keep the volume slices
// or just the surfaces obtained by the cutting:
DefineConstant[
  N = {5, Min 2, Max 100, Step 1, Name "Number of slices"}
  surf = {0, Choices{0, 1}, Name "Keep only surfaces?"}
];
dz = (zmax - zmin) / N;

// Define the cutting planes
For i In {1:N-1}
  Rectangle(1000 + i) = {xmin, ymin, zmin + i * dz,
                         xmax-xmin, ymax-ymin};
EndFor

// Fragment (i.e. intersect) the volume with all the cutting planes:
BooleanFragments{ Volume{v()}; Delete; }{ Surface{1000+1:1000+N-1}; Delete; }

// Now delete all the surfaces that are not on the boundary of a volume, all
// curves that are not on the boundary of a surface, and all the points that are
// not on the boundary of a curve:
Delete { Surface{:}; Curve{:}; Point{:}; }

// Note that to slice the mesh instead the CAD, we could have used the
// "SimplePartition" Plugin:
//
// Plugin("SimplePartition").NumSlicesX = 1;
// Plugin("SimplePartition").NumSlicesY = 1;
// Plugin("SimplePartition").NumSlicesZ = N;
// Plugin("SimplePartition").Run
//
// And for a general mesh partitioning using Metis, we could have used:
//
// PartitionMesh N;

If(surf)
  // If we want to only keep the surfaces, retrieve the surfaces in bounding
  // boxes around the cutting planes...
  eps = 1e-4;
  s() = {};
  For i In {1:N-1}
    s() += Surface In BoundingBox{xmin-eps,ymin-eps,zmin + i * dz - eps,
      xmax+eps,ymax+eps,zmin + i * dz + eps};
  EndFor
  // ...and delete all the other entities:
  dels = Surface{:};
  dels -= s();
  Delete { Volume{:}; Surface{dels()}; Curve{:}; Point{:}; }
EndIf

// Finally, let's specify a global mesh size:
Mesh.CharacteristicLengthMin = 3;
Mesh.CharacteristicLengthMax = 3;
