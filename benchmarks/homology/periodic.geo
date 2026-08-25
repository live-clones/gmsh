// Gmsh
// Run with: gmsh periodic.geo -

Merge "periodic.msh";

// cohomology of the physical group with ID 1000
Plugin(HomologyComputation).DomainPhysicalGroups = "1000";
Plugin(HomologyComputation).SubdomainPhysicalGroups = "";
Plugin(HomologyComputation).ReductionImmunePhysicalGroups = "";
Plugin(HomologyComputation).DimensionOfChainsToSave = "1";
Plugin(HomologyComputation).Filename = "";
Plugin(HomologyComputation).ComputeHomology = 0;
Plugin(HomologyComputation).ComputeCohomology = 1;
Plugin(HomologyComputation).CreatePostProcessingViews = 1;
// glue the periodic boundaries of the domain: only the periodic links going
// from the "Top" surface to the "Bottom" surface are used, so that any other
// periodicity the mesh may carry is ignored
Plugin(HomologyComputation).PeriodicIdentification = 1;
Plugin(HomologyComputation).PeriodicSlavePhysicalGroups = "3000";
Plugin(HomologyComputation).PeriodicMasterPhysicalGroups = "3001";
Plugin(HomologyComputation).Run;

Save "periodic_cohomology.msh";