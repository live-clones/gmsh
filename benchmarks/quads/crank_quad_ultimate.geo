// Crankshaft: PACK -> Blossom -> OptimizeQuadsFast surface mesh.
// Run: gmsh crank_quad_ultimate.geo -2 -nt 2 -o crank_quad_ultimate.msh
// Change the target edge length with -setnumber h 6 (STEP model units).
// Small CAD features can leave residual triangles after the final repair.
// Inspect the final validity and size/shape audits separately.

// Use the OpenCASCADE geometry kernel to import the STEP model.
SetFactory("OpenCASCADE");
// Import the shared crankshaft geometry and store its volume tags in v().
v() = ShapeFromFile("../step/SampleCrankshaft4A.stp");

// Target edge length in model units; UI range: 1 to 12, increment: 1.
DefineConstant[
  h = {4, Min 1, Max 12, Step 1, Name "Parameters/Target edge length"}
];

// Select PACK (9): place surface points in 3D using a guiding cross field.
Mesh.Algorithm = 9;
// Set the lower mesh-size bound; equal lower/upper bounds give uniform sizing.
Mesh.MeshSizeMin = h;
// Set the upper mesh-size bound; PACK reads this sizing through its guiding field.
Mesh.MeshSizeMax = h;
// Build the guiding-field size map from the background triangulation (3).
Mesh.PackSizemapMethod = 3;
// Disable global quad patterns on simple CAD faces; set to 1 to enable them.
Mesh.PackPatterns = 0;
// Disable automatic fallback to MeshAdapt if the 2D meshing algorithm fails.
Mesh.AlgorithmSwitchOnFailure = 0;
// Fix the seed used by the mesh generator's pseudo-random number generator.
Mesh.RandomSeed = 1;

// Recombine triangles into quadrangles on every surface.
Mesh.RecombineAll = 1;
// Use Blossom matching (1) to choose triangle pairs for recombination.
Mesh.RecombinationAlgorithm = 1;
// Impose no positive recombination quality threshold; validity checks remain.
Mesh.RecombineMinimumQuality = 0;
// Run OptimizeQuadsFast/V2 (1); alternatives: legacy cleanup (0), disabled (2).
Mesh.PackCleanupMethod = 1;
// Use Smart Laplacian smoothing followed by one 3D Winslow sweep per batch.
Mesh.OptimizeQuadsSmartLaplacian = 2;
// Allow up to three Smart Laplacian sweeps initially and after topology changes.
Mesh.Smoothing = 3;
// Consider splitting quads when their CAD distance exceeds 0.2 times local h;
// accept the alternative diagonal only within tolerance and twice closer.
Mesh.OptimizeQuadsFinalSplitCadDistanceRatio = 0.2;

// Save all mesh elements, including those outside physical groups.
Mesh.SaveAll = 1;
// Save node coordinates in the CAD curves' and surfaces' parameter spaces.
Mesh.SaveParametric = 1;
