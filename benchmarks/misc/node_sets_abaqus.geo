SetFactory("OpenCASCADE");

Box(1) = {0,0,0, 1,1,1};
Physical Volume("my volume") = 1;
Physical Surface("my surface") = {2, 3};
Physical Curve("my curve") = {6, 9};
Mesh 3;

// don't save any groups of elements
Mesh.SaveGroupsOfElements = 0;

// save group of nodes for all physical groups
Mesh.SaveGroupsOfNodes = 1;
Save "node_sets_abaqus_for_each_physical_group.inp";

// save group of nodes only for physical surfaces
Mesh.SaveGroupsOfNodes = -100;
Save "node_sets_abaqus_for_each_physical_surface.inp";

// save group of nodes only for physical surfaces and physical curves
Mesh.SaveGroupsOfNodes = -110;
Save "node_sets_abaqus_for_each_physical_surface_and_curve.inp";

// save group of nodes for all surfaces - warning: this dangerous, as the node
// set could reference nodes not saved in the mesh!
Mesh.SaveGroupsOfNodes = -200;
Save "node_sets_abaqus_for_each_surface.inp";

// last one works even if there are no physical surfaces, allowing to only save
// volume elements - warning: this dangerous, as the node set could reference
// nodes not saved in the mesh!
Delete Physicals;
Physical Volume("my new volume") = 1;
Mesh.SaveGroupsOfNodes = -200;
Save "node_sets_abaqus_for_each_surface_dangerous.inp";

// if the goal is to only save volume elements but also node sets for
// surfaces/curves, instead of saving node sets for all surfaces/curves, one can
// use a negative Mesh.SaveGroupsOfElements value:
Physical Surface("my surface 2") = {4, 5};
Physical Curve("my curve 2") = {4};
Mesh.SaveGroupsOfElements = -1000;
Mesh.SaveGroupsOfNodes = -110;
Save "node_sets_abaqus_for_each_physical_surface_and_curve_but_only_volume_elements.inp";
