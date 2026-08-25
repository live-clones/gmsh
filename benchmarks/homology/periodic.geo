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
Plugin(HomologyComputation).PeriodicIdentification = 1;
Plugin(HomologyComputation).Run;

Save "periodic_cohomology.msh";