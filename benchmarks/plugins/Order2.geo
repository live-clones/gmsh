// Second order list data (6-node triangles, 9-node quadrangles, 10-node
// tetrahedra, 27-node hexahedra): the plugins that write list data or use the
// element classes read their corners (they overflowed arrays of 8 nodes)

Merge "data/order2.pos"; // views 0: scalar, 1: vector, 3 steps

Plugin(Gradient).View = 0; Plugin(Gradient).Run;
Plugin(Curl).View = 1; Plugin(Curl).Run;
Plugin(Divergence).View = 1; Plugin(Divergence).Run;
Plugin(Integrate).View = 0; Plugin(Integrate).Run;
Plugin(Integrate).View = 1; Plugin(Integrate).Dimension = 2; Plugin(Integrate).Run;
Plugin(MathEval).View = 0; Plugin(MathEval).Expression0 = "v0^2"; Plugin(MathEval).Run;
Plugin(ExtractElements).View = 0; Plugin(ExtractElements).MinVal = 1;
Plugin(ExtractElements).MaxVal = 2; Plugin(ExtractElements).Run;
Plugin(HarmonicToTime).View = 1; Plugin(HarmonicToTime).RealPart = 0;
Plugin(HarmonicToTime).ImaginaryPart = 1; Plugin(HarmonicToTime).Run;
Plugin(CutPlane).View = 0; Plugin(CutPlane).A = 1; Plugin(CutPlane).D = -0.4;
Plugin(CutPlane).Run;
Plugin(CutPlane).View = 1; Plugin(CutPlane).ExtractVolume = 1; Plugin(CutPlane).Run;
Plugin(Isosurface).View = 0; Plugin(Isosurface).Value = 1.5; Plugin(Isosurface).Run;
Plugin(CutSphere).View = 1; Plugin(CutSphere).R = 0.6; Plugin(CutSphere).Run;
Plugin(Warp).View = 0; Plugin(Warp).OtherView = 1; Plugin(Warp).Run;
