// The lateral surface of a cylinder is periodic: it has a seam, a curve that it
// uses twice, with opposite signs. Both uses are written to the MSH file, and
// must be read back, in ASCII and in binary.

SetFactory("OpenCASCADE");
Cylinder(1) = {0, 0, 0, 0, 0, 1, 0.5};
Mesh 2;
c[] = OrientedBoundary{ Surface{1}; };
num = #c[];
files[] = Str("seam_out.msh", "seam_binary_out.msh");
// Write both formats from the original model, before either is read back.
For binary In {0:1}
  Mesh.Binary = binary;
  Save Str(files[binary]);
EndFor
For binary In {0:1}
  Delete Model;
  Merge Str(files[binary]);
  read[] = OrientedBoundary{ Surface{1}; };
  If(#read[] != num)
    Error("Read back %g boundary curves (binary: %g), expected %g", #read[], binary, num);
  Else
    For i In {0:num-1}
      expected = 0;
      actual = 0;
      For j In {0:num-1}
        expected += (c[j] == c[i]);
        actual += (read[j] == c[i]);
      EndFor
      If(actual != expected)
        Error("Read back %g uses of signed curve %g (binary: %g), expected %g", actual, c[i], binary, expected);
      EndIf
    EndFor
  EndIf
EndFor
