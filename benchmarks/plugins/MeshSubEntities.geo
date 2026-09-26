// Plugin(MeshSubEntities): line elements on all the edges of the physical
// surface 3 of a triangle mesh (with the former names of the options,
// OuputDimension and OuputPhysicalGroup, which stay accepted)
Merge "data/square.msh";
Plugin(MeshSubEntities).InputDimension = 2;
Plugin(MeshSubEntities).InputPhysicalGroup = 3;
Plugin(MeshSubEntities).OuputDimension = 1;
Plugin(MeshSubEntities).OuputPhysicalGroup = 2001;
Plugin(MeshSubEntities).Run;
