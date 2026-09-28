// Plugin(GaussPoints): Gauss points of triangles, of the lines of physical
// curve 1, of tetrahedra, and of hexahedra (physical volume 3);
// order 0 only: `Order' is a parser keyword, so it cannot be set here
Merge "data/square.msh";
Plugin(GaussPoints).Run;
Plugin(GaussPoints).Dimension = 1;
Plugin(GaussPoints).PhysicalGroup = 1;
Plugin(GaussPoints).Run;

NewModel;
Merge "data/cube.msh";
Plugin(GaussPoints).Dimension = 3;
Plugin(GaussPoints).PhysicalGroup = 0;
Plugin(GaussPoints).Run;

NewModel;
Merge "data/hexes.msh";
Plugin(GaussPoints).PhysicalGroup = 3;
Plugin(GaussPoints).Run;

// a higher order, with the new name of the option (Order is a keyword of the
// parser)
Plugin(GaussPoints).IntegrationOrder = 2;
Plugin(GaussPoints).Run;
