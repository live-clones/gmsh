// Example of compoud surface extrusion from .msh file

Geometry.Surfaces=1;
Mesh.SurfaceFaces=1;
Geometry.AutoCoherence = 1;
Geometry.OldRuledSurface=1;
Mesh.RemeshAlgorithm = 1;
Mesh.Algorithm=6;

Merge "3sidedruled.stl";

CreateTopology;

Compound Surface (news) = {1};

Hide {Surface{1};}

Extrude { Surface{-(news-1)}; Layers{{1},{0.001}}; Recombine; }
