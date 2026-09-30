// Plugin(HomologyPostProcessing): on the homology and cohomology bases of a
// square with two holes, an integer basis change, a basis made dual to the
// cohomology one, and the boundary of a relative 2-chain traced and projected

Point(1) = {0, 0, 0, 0.25}; Point(2) = {2, 0, 0, 0.25};
Point(3) = {2, 1, 0, 0.25}; Point(4) = {0, 1, 0, 0.25};
Line(1) = {1, 2}; Line(2) = {2, 3}; Line(3) = {3, 4}; Line(4) = {4, 1};
Curve Loop(1) = {1, 2, 3, 4};
For i In {0 : 1}
  p = newp;
  Point(p) = {0.4 + i, 0.4, 0, 0.25}; Point(p + 1) = {0.6 + i, 0.4, 0, 0.25};
  Point(p + 2) = {0.6 + i, 0.6, 0, 0.25}; Point(p + 3) = {0.4 + i, 0.6, 0, 0.25};
  l = newl;
  Line(l) = {p, p + 1}; Line(l + 1) = {p + 1, p + 2};
  Line(l + 2) = {p + 2, p + 3}; Line(l + 3) = {p + 3, p};
  Curve Loop(2 + i) = {l : l + 3};
  holes[] += l : l + 3;
EndFor
Plane Surface(1) = {1, 2, 3};
Physical Curve("outer", 1) = {1, 2, 3, 4};
Physical Curve("holes", 2) = {holes[]};
Physical Surface("domain", 3) = {1};
Mesh 2;

Plugin(HomologyComputation).DomainPhysicalGroups = "3";
Plugin(HomologyComputation).ComputeCohomology = 1;
Plugin(HomologyComputation).DimensionOfChainsToSave = "1";
Plugin(HomologyComputation).HomologyPhysicalGroupsBegin = 100; // 100, 101
Plugin(HomologyComputation).CohomologyPhysicalGroupsBegin = 200; // 200, 201
Plugin(HomologyComputation).CreatePostProcessingViews = 0;
Plugin(HomologyComputation).Run;
Plugin(HomologyComputation).SubdomainPhysicalGroups = "1, 2";
Plugin(HomologyComputation).ComputeCohomology = 0;
Plugin(HomologyComputation).DimensionOfChainsToSave = "2";
Plugin(HomologyComputation).HomologyPhysicalGroupsBegin = 300; // 300
Plugin(HomologyComputation).Run;

Plugin(HomologyPostProcessing).TransformationMatrix = "1, 1; 0, 1";
Plugin(HomologyPostProcessing).PhysicalGroupsOfOperatedChains = "100, 101";
Plugin(HomologyPostProcessing).NameForResultChains = "sum";
Plugin(HomologyPostProcessing).Run;
Plugin(HomologyPostProcessing).TransformationMatrix = "1, -1";
Plugin(HomologyPostProcessing).NameForResultChains = "difference";
Plugin(HomologyPostProcessing).Run; // one row: a single chain
Plugin(HomologyPostProcessing).TransformationMatrix = "I";
Plugin(HomologyPostProcessing).PhysicalGroupsOfOperatedChains2 = "200, 201";
Plugin(HomologyPostProcessing).NameForResultChains = "dual";
Plugin(HomologyPostProcessing).Run;
Plugin(HomologyPostProcessing).PhysicalGroupsOfOperatedChains = "300";
Plugin(HomologyPostProcessing).PhysicalGroupsOfOperatedChains2 = "";
Plugin(HomologyPostProcessing).ApplyBoundaryOperatorToResults = 1;
Plugin(HomologyPostProcessing).NameForResultChains = "boundary";
Plugin(HomologyPostProcessing).Run;
Plugin(HomologyPostProcessing).PhysicalGroupsToTraceResults = "2";
Plugin(HomologyPostProcessing).NameForResultChains = "traced";
Plugin(HomologyPostProcessing).Run;
Plugin(HomologyPostProcessing).PhysicalGroupsToTraceResults = "";
Plugin(HomologyPostProcessing).PhysicalGroupsToProjectResults = "2";
Plugin(HomologyPostProcessing).NameForResultChains = "projected";
Plugin(HomologyPostProcessing).Run;
