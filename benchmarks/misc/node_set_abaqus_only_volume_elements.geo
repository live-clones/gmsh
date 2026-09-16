SetFactory("OpenCASCADE");
Box(1) = {0,0,0,1,1,1};
Box(2) = {1,0,0,1,1,1};
Coherence;
Physical Surface(10) = CombinedBoundary{ Volume{1,2}; };
Mesh.SaveGroupsOfNodes = 1; // save group of nodes for physicals
Mesh.SaveAll = 1; // a priori save all elements (not only those on physicals)...
Mesh.SaveGroupsOfElements = -1000; // ...but don't save any surface, line or point elements
Mesh 3;
Save "test.inp";
