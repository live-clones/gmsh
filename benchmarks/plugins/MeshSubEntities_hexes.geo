// Plugin(MeshSubEntities): point elements on the nodes of the physical volume
// 3 of a hexahedral mesh, then of its physical surface 1 into a second group
Merge "data/hexes.msh";
Plugin(MeshSubEntities).InputDimension = 3;
Plugin(MeshSubEntities).InputPhysicalGroup = 3;
Plugin(MeshSubEntities).OuputDimension = 0;
Plugin(MeshSubEntities).Run;
Plugin(MeshSubEntities).InputDimension = 2;
Plugin(MeshSubEntities).InputPhysicalGroup = 1;
Plugin(MeshSubEntities).OuputPhysicalGroup = 2001;
Plugin(MeshSubEntities).Run;
