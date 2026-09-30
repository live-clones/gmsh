// Plugin(HomologyComputation): homology and cohomology bases of a square with
// a hole and of the solid it extrudes to, absolute and relative to boundaries,
// reduction options, views or physical groups only, a saved file

Point(1) = {0, 0, 0, 0.3}; Point(2) = {1, 0, 0, 0.3};
Point(3) = {1, 1, 0, 0.3}; Point(4) = {0, 1, 0, 0.3};
Point(5) = {0.4, 0.4, 0, 0.3}; Point(6) = {0.6, 0.4, 0, 0.3};
Point(7) = {0.6, 0.6, 0, 0.3}; Point(8) = {0.4, 0.6, 0, 0.3};
Line(1) = {1, 2}; Line(2) = {2, 3}; Line(3) = {3, 4}; Line(4) = {4, 1};
Line(5) = {5, 6}; Line(6) = {6, 7}; Line(7) = {7, 8}; Line(8) = {8, 5};
Curve Loop(1) = {1, 2, 3, 4};
Curve Loop(2) = {5, 6, 7, 8};
Plane Surface(1) = {1, 2};
Physical Curve("outer", 1) = {1, 2, 3, 4};
Physical Curve("hole", 2) = {5, 6, 7, 8};
Physical Surface("domain", 3) = {1};
Mesh 2;

Plugin(HomologyComputation).DomainPhysicalGroups = "3";
Plugin(HomologyComputation).ComputeCohomology = 1;
Plugin(HomologyComputation).DimensionOfChainsToSave = "1";
Plugin(HomologyComputation).Run; // H1 and H^1: one generator each
Plugin(HomologyComputation).SubdomainPhysicalGroups = "1, 2";
Plugin(HomologyComputation).HomologyPhysicalGroupsBegin = 100;
Plugin(HomologyComputation).CohomologyPhysicalGroupsBegin = 200;
Plugin(HomologyComputation).DimensionOfChainsToSave = "0, 1, 2";
Plugin(HomologyComputation).Filename = "relative.msh";
Plugin(HomologyComputation).Run; // relative to the boundary

NewModel; // the same square extruded: a solid with a tunnel
Point(1) = {0, 0, 0, 0.4}; Point(2) = {1, 0, 0, 0.4};
Point(3) = {1, 1, 0, 0.4}; Point(4) = {0, 1, 0, 0.4};
Point(5) = {0.4, 0.4, 0, 0.4}; Point(6) = {0.6, 0.4, 0, 0.4};
Point(7) = {0.6, 0.6, 0, 0.4}; Point(8) = {0.4, 0.6, 0, 0.4};
Line(1) = {1, 2}; Line(2) = {2, 3}; Line(3) = {3, 4}; Line(4) = {4, 1};
Line(5) = {5, 6}; Line(6) = {6, 7}; Line(7) = {7, 8}; Line(8) = {8, 5};
Curve Loop(1) = {1, 2, 3, 4};
Curve Loop(2) = {5, 6, 7, 8};
Plane Surface(1) = {1, 2};
e[] = Extrude {0, 0, 0.5} { Surface{1}; };
Physical Surface("ends", 1) = {1, e[0]};
Physical Volume("solid", 3) = {e[1]};
Mesh 3;

Plugin(HomologyComputation).DomainPhysicalGroups = "3";
Plugin(HomologyComputation).SubdomainPhysicalGroups = "";
Plugin(HomologyComputation).HomologyPhysicalGroupsBegin = -1;
Plugin(HomologyComputation).CohomologyPhysicalGroupsBegin = -1;
Plugin(HomologyComputation).DimensionOfChainsToSave = "1, 2";
Plugin(HomologyComputation).Filename = "";
Plugin(HomologyComputation).Run;
Plugin(HomologyComputation).SubdomainPhysicalGroups = "1";
Plugin(HomologyComputation).ReductionImmunePhysicalGroups = "1";
Plugin(HomologyComputation).ReductionCombine = 1;
Plugin(HomologyComputation).PostProcessSimplify = 0;
Plugin(HomologyComputation).ReductionHeuristic = 0;
Plugin(HomologyComputation).Run;
Plugin(HomologyComputation).CreatePostProcessingViews = 0;
Plugin(HomologyComputation).ReductionOmit = 0;
Plugin(HomologyComputation).Run; // physical groups only
