// Plugin(SpanningTree): a tree spanning the nodes of the physical surface 1
// then of the physical volume 3 of a tetrahedral mesh, in physical group 100
Merge "data/cube.msh";
Plugin(SpanningTree).PhysicalSurfaces = "1";
Plugin(SpanningTree).PhysicalVolumes = "3";
Plugin(SpanningTree).OutputPhysical = 100;
Plugin(SpanningTree).Run;
