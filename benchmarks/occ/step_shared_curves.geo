// Two surfaces sharing a curve are exported to a STEP file and read back: the
// curve and its two points must still be shared. Surfaces connected by their
// curves are exported as a shell; as separate surfaces each one was read back
// with its own copy of the curve (8 points and 8 curves instead of 6 and 7).

SetFactory("OpenCASCADE");

Point(1) = {0, 0, 0};
Ex[] = Extrude{1, 0, 0}{ Point{1}; };
Ey1[] = Extrude{0, 0.5, 0}{ Line{Ex[1]}; };
Ey2[] = Extrude{0, 0.5, 0}{ Line{Ey1[0]}; };
Coherence;

Save "step_shared_curves_tmp.step";
Delete Model;
Merge "step_shared_curves_tmp.step";

p() = Point{:}; c() = Curve{:}; s() = Surface{:};
If(#p() != 6 || #c() != 7 || #s() != 2)
  Error("%g points, %g curves and %g surfaces read back instead of 6, 7 and 2",
        #p(), #c(), #s());
EndIf
