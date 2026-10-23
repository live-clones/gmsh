// The lateral surface of a cylinder is periodic: it has a seam, a curve that it
// uses twice, with opposite signs. Both uses are written to the MSH file, and
// must be read back, in ASCII and in binary.

SetFactory("OpenCASCADE");
Cylinder(1) = {0, 0, 0, 0, 0, 1, 0.5};
Mesh 2;
c[] = Boundary{ Surface{1}; };
num = #c[];
For binary In {0:1}
  Mesh.Binary = binary;
  Save "seam_out.msh";
  Delete Model;
  Merge "seam_out.msh";
  c[] = Boundary{ Surface{1}; };
  If(#c[] != num)
    Error("Read back %g boundary curves (binary: %g), expected %g", #c[], binary, num);
  EndIf
EndFor
