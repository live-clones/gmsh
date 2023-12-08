SetFactory("OpenCASCADE");
Rectangle(100) = {-1, 0, 0, 1, 0.5, 0};
Rectangle(101) = {-0, 0, 0, 1, 0.5, 0};
Coherence;

Physical Surface(1000) = 100;
Physical Surface(1001) = 101;

Mesh.PartitionCreateTopology = 1;
Mesh 2;
PartitionMesh 2;
Save "aa.msh4";

// get all the physical surfaces created by the partitioner
phys() = Physical Surface{:};

Printf("// my not so great surface selection...") > "param.pro";
For i In {0: #phys()-1}
  // new elementary entities created by the partitioner
  elem() = Physical Surface{ phys(i) };
  // parents (= orginal elementary entities)
  parents() = Parent Surface{ elem() };
  Printf("elem", elem());
  Printf("parents", parents());
  For j In {0: #parents()-1}
    If(parents(j) == 100)
      Printf("  eps_r[%g] = 1;", phys(i)) >> "param.pro";
    ElseIf(parents(j) == 101)
      Printf("  eps_r[%g] = 4;", phys(i)) >> "param.pro";
    EndIf
  EndFor
EndFor
