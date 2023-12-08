//-----------------------------
// Boundary Layer Example
//-----------------------------

SetFactory("OpenCASCADE");

// Parameters
radc = 1e-3;
rada = 10e-3;

//Initial Mesh Control Parameters
mshc = 1e-4;
msha = 5e-4;

Disk(1) = {-2*radc, 0, 0, radc};
Disk(2) = {2*radc, 0, 0, radc};

Disk(3) = {0, 0, 0, rada};

Characteristic Length { PointsOf{ Surface{1,2}; } } = mshc;
Characteristic Length { PointsOf{ Surface{3}; } } = msha;

Coherence;

//Setup Boundary Layer Mesh-------------------------------------------------------------------------
Field[1] = BoundaryLayer;
Field[1].EdgesList = { Boundary{Surface{1,2}; } };
Field[1].hfar = radc/10;         // Element size far from the wall
Field[1].hwall_n = radc/100;     // Mesh Size Normal to the The Wall
Field[1].thickness = radc/4;     // Maximum thickness of the boundary layer
Field[1].ratio = 1.2;            // Size Ratio Between Two Successive Layers
Field[1].ExcludedFaceList = {3}; // Don't create BL in this surface
Field[1].Quads = 1;              // Make quads
BoundaryLayer Field = 1;
