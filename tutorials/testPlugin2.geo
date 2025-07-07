// Set up OpenCASCADE
//Printf("SetFactory('OpenCASCADE');");
//SetFactory("OpenCASCADE");
General.ShowMessagesOnStartup = 1;


// Base 2D geometry definition (as Macro)
Macro Geo2D
    lc = 1e-2;
    p1 = newp; Point(p1) = {0, 0, 0, lc};
    p2 = newp; Point(p2) = {.1, 0,  0, lc};
    p3 = newp; Point(p3) = {.1, .3, 0, lc};
    p4 = newp; Point(p4) = {0,  .3, 0, lc};
    c1 = newc; Line(c1) = {p1, p2};
    c2 = newc; Line(c2) = {p3, p2};
    c3 = newc; Line(c3) = {p3, p4};
    c4 = newc; Line(c4) = {p4, p1};
    l = newc; Curve Loop(l) = {c4, c1, -c2, c3};
    s = news; Plane Surface(s) = {l};
    Mesh 0; // Hack for having geo in plugin (in model -1)
Return

// Base 3D geometry definition (as Macro)
Macro Geo3D
    //Printf("SetFactory('OpenCASCADE');");
    SetFactory("OpenCASCADE");
    sp = news; Sphere(sp) = {0, 0.1, 0.1, 0.05, -Pi/2, Pi/2, 2*Pi};
    Mesh 0; // Hack for having geo in plugin (in model -1)
Return


// Base 2D geometry definition (as Macro)
Macro Geo2D3D
    Call Geo2D;
    Printf("%d %d", s, l);
    //Delete { Surface{s}; }
    //s = news;
    Transfinite Surface(s);
    Recombine Surface{s};
    Call Geo3D;
Return

// Base 3D geometry definition (as Macro)
Macro ImportMeshWith_StraightTriangle_StraightAndCurvedQuad
    Merge "30P30N_loadMsh.geo";
Return

// Utility to delete all geometry and mesh
Macro DeleteAll
    //Printf("Recursive Delete {Volume {:};");
    Recursive Delete { Volume{:}; }
    Recursive Delete { Surface{:};}
    Recursive Delete { Curve{:}; }
    Recursive Delete { Point{:};}
    Delete Model;
    //Printf("SetFactory('Built-in');");
    SetFactory("Built-in");
Return

Macro DeleteMeshes
    //Printf("Delete Meshes;");
    Delete Meshes;
Return

// Test Case 1: No geometry
Printf("");
Printf("Testing Case: <<<< No geometry >>>>");
//Printf("Call DeleteAll;");
//Call DeleteAll;
Printf("Plugin(AnalyseMeshQuality2).GuidanceLevel = 1;");
Plugin(AnalyseMeshQuality2).GuidanceLevel = 1;
Printf("Plugin(AnalyseMeshQuality2).Run;");
Plugin(AnalyseMeshQuality2).Run;
Printf("Expecting: <<<< No geometry >>>>");

// Test Case 2: No mesh present but geometry exists
Printf(" ");
Printf("Testing Case: <<<< No mesh >>>>");
Printf("Call Geo2D;");
Call Geo2D;
Printf("Plugin(AnalyseMeshQuality2).Run;");
Plugin(AnalyseMeshQuality2).Run;
Printf("Expecting: <<<< No mesh >>>>");

// Test Case 3: Restrict to curved elements
Printf(" ");
Printf("Testing Case: <<<< Restrict to curved elements >>>>");
Printf("Mesh 2;");
Mesh 2;
Printf("Plugin(AnalyseMeshQuality2).RestrictToCurvedElements = 1;");
Plugin(AnalyseMeshQuality2).RestrictToCurvedElements = 1;
Printf("Plugin(AnalyseMeshQuality2).Run;");
Plugin(AnalyseMeshQuality2).Run;
Printf("Expecting: <<<< No curved elements >>>>");

// Test Case 4: Restrict to Quad/Hex
Printf(" ");
Printf("Testing Case: <<<< Restrict to element type Quad/Hex >>>>");
Printf("Plugin(AnalyseMeshQuality2).RestrictToCurvedElements = 0;");
Plugin(AnalyseMeshQuality2).RestrictToCurvedElements = 0;
Printf("Plugin(AnalyseMeshQuality2).RestrictToElementType = 2;");
Plugin(AnalyseMeshQuality2).RestrictToElementType = 2;
Printf("Plugin(AnalyseMeshQuality2).Run;");
Plugin(AnalyseMeshQuality2).Run;
Printf("Expecting: <<<< No element of that type >>>>");

// Test Case 5: Restrict to curved Quad/Hex
Printf(" ");
Printf("Testing Case: <<<< Restrict to curved Quad/Hex >>>>");
Printf("Plugin(AnalyseMeshQuality2).RestrictToCurvedElements = 1;");
Plugin(AnalyseMeshQuality2).RestrictToCurvedElements = 1;
//Printf("Plugin(AnalyseMeshQuality2).RestrictToElementType = 2;");
//Plugin(AnalyseMeshQuality2).RestrictToElementType = 2;
Printf("Plugin(AnalyseMeshQuality2).Run;");
Plugin(AnalyseMeshQuality2).Run;
Printf("Expecting: <<<< No curved elements + No element of that type >>>>");

// Test Case 6: Restrict to curved Tri
Printf(" ");
Printf("Testing Case: <<<< Restrict to curved Tri/Tet >>>>");
Printf("Call DeleteAll;");
Call DeleteAll;
Printf("Call ImportMeshWith_StraightTriangle_StraightAndCurvedQuad;");
Call ImportMeshWith_StraightTriangle_StraightAndCurvedQuad;
Printf("Plugin(AnalyseMeshQuality2).RestrictToElementType = 1;");
Plugin(AnalyseMeshQuality2).RestrictToElementType = 1;
Printf("Plugin(AnalyseMeshQuality2).RestrictToCurvedElements = 1;");
Plugin(AnalyseMeshQuality2).RestrictToCurvedElements = 1;
Printf("Plugin(AnalyseMeshQuality2).Run;");
Plugin(AnalyseMeshQuality2).Run;
Printf("Expecting: <<<< No elements combining curved and Tri >>>>");

// Test Case 7: Disabling all metric
Printf(" ");
Printf("Testing Case: <<<< Disabling all metric >>>>");
Printf("Plugin(AnalyseMeshQuality2).EnableDistoQuality = 1;");
Plugin(AnalyseMeshQuality2).EnableDistoQuality = 1;
Printf("Plugin(AnalyseMeshQuality2).RestrictToElementType = 2;");
Plugin(AnalyseMeshQuality2).RestrictToElementType = 2;
Printf("Plugin(AnalyseMeshQuality2).RestrictToCurvedElements = 0;");
Plugin(AnalyseMeshQuality2).RestrictToCurvedElements = 0;
Printf("Plugin(AnalyseMeshQuality2).Run;");
Plugin(AnalyseMeshQuality2).Run;
Printf("Plugin(AnalyseMeshQuality2).EnableDistoQuality = 0;");
Plugin(AnalyseMeshQuality2).EnableDistoQuality = 0;
Printf("Plugin(AnalyseMeshQuality2).EnableAspectQuality = 0;");
Plugin(AnalyseMeshQuality2).EnableAspectQuality = 0;
Printf("Plugin(AnalyseMeshQuality2).RestrictToElementType = 0;");
Plugin(AnalyseMeshQuality2).RestrictToElementType = 0;
Printf("Plugin(AnalyseMeshQuality2).SkipValidity = 1;");
Plugin(AnalyseMeshQuality2).SkipValidity = 1;
Printf("Plugin(AnalyseMeshQuality2).Run;");
Plugin(AnalyseMeshQuality2).Run;
Printf("Expecting: <<<< No metric to analyze >>>>");

// Test Case 8: Omitting computation, asking missing Geofit on flat geo
Printf(" ");
Printf("Testing Case: <<<< Omitting computation, asking missing Geofit on flat geo >>>>");
Printf("Plugin(AnalyseMeshQuality2).EnableGeoFitQuality = 1;");
Plugin(AnalyseMeshQuality2).EnableGeoFitQuality = 1;
Printf("Plugin(AnalyseMeshQuality2).OmitMetricsComputation = 1;");
Plugin(AnalyseMeshQuality2).OmitMetricsComputation = 1;
Printf("Plugin(AnalyseMeshQuality2).Run;");
Plugin(AnalyseMeshQuality2).Run;
Printf("Expecting: <<<< No previously computed data >>>>");
Printf("Expecting: <<<< GeoFit but only flat geo >>>>");

// Test Case 9: Validity only on Curved geo
Printf(" ");
Printf("Testing Case: <<<< Asking for validity on curved geo >>>>");
Printf("Call DeleteAll;");
Call DeleteAll;
Printf("Call Geo3D;");
Call Geo3D;
Printf("Mesh 2;");
Mesh 2;
Printf("Plugin(AnalyseMeshQuality2).EnableGeoFitQuality = 0;");
Plugin(AnalyseMeshQuality2).EnableGeoFitQuality = 0;
Printf("Plugin(AnalyseMeshQuality2).OmitMetricsComputation = 0;");
Plugin(AnalyseMeshQuality2).OmitMetricsComputation = 0;
Printf("Plugin(AnalyseMeshQuality2).SkipValidity = 0;");
Plugin(AnalyseMeshQuality2).SkipValidity = 0;
Printf("Plugin(AnalyseMeshQuality2).Run;");
Plugin(AnalyseMeshQuality2).Run;
Printf("Expecting: <<<< Validity but only curved geo >>>>");

// Test Case 10: GeoFit with no curved selected element
Printf(" ");
Printf("Testing Case: <<<< Asking for GeoFit with no curved selected element >>>>");
Printf("Call DeleteAll;");
Call DeleteAll;
Printf("Call Geo2D3D;");
Call Geo2D3D;
Printf("Mesh 2;");
Mesh 2;
Printf("Plugin(AnalyseMeshQuality2).EnableGeoFitQuality = 1;");
Plugin(AnalyseMeshQuality2).EnableGeoFitQuality = 1;
Printf("Plugin(AnalyseMeshQuality2).RestrictToElementType = 2;");
Plugin(AnalyseMeshQuality2).RestrictToElementType = 2;
Printf("Plugin(AnalyseMeshQuality2).SkipValidity = 1;");
Plugin(AnalyseMeshQuality2).SkipValidity = 1;
Printf("Plugin(AnalyseMeshQuality2).Run;");
Plugin(AnalyseMeshQuality2).Run;
Printf("Expecting: <<<< GeoFit but only flat selected elements >>>>");

// Test Case 11: Save plot
Printf(" ");
Printf("Testing Case: <<<< Save plot >>>>");
Printf("Plugin(AnalyseMeshQuality2).RestrictToElementType = 0;");
Plugin(AnalyseMeshQuality2).RestrictToElementType = 0;
Printf("Plugin(AnalyseMeshQuality2).CreatePlotView = 1;");
Plugin(AnalyseMeshQuality2).CreatePlotView = 1;
Printf("Plugin(AnalyseMeshQuality2).Run;");
Plugin(AnalyseMeshQuality2).Run;
Printf("Save 'TEST.pos';");
Save "TEST.pos";
Printf("Save 'TEST.png';");
Save "TEST.png";
Printf("Expecting: <<<< A plot, saved as TEST.png and TEST.pos >>>>");

// Test Case 12: Save plot
Printf(" ");
Printf("Testing Case: <<<< A normal run >>>>");
Printf("Plugin(AnalyseMeshQuality2).EnableDistoQuality = 1;");
Plugin(AnalyseMeshQuality2).EnableDistoQuality = 1;
Printf("Plugin(AnalyseMeshQuality2).EnableGeoFitQuality = 0;");
Plugin(AnalyseMeshQuality2).EnableGeoFitQuality = 0;
Printf("Plugin(AnalyseMeshQuality2).CreatePlotView = 0;");
Plugin(AnalyseMeshQuality2).CreatePlotView = 0;
Printf("Plugin(AnalyseMeshQuality2).GuidanceLevel = 0;");
Plugin(AnalyseMeshQuality2).GuidanceLevel = 0;
Printf("Plugin(AnalyseMeshQuality2).SmartRecomputation = 1;");
Plugin(AnalyseMeshQuality2).SmartRecomputation = 1;
Printf("Plugin(AnalyseMeshQuality2).SkipValidity = 0;");
Plugin(AnalyseMeshQuality2).SkipValidity = 0;
Printf("Plugin(AnalyseMeshQuality2).Run;");
Plugin(AnalyseMeshQuality2).Run;
Printf("Plugin(AnalyseMeshQuality2).SmartRecomputation = 1;");
Plugin(AnalyseMeshQuality2).SmartRecomputation = 1;
Printf("Plugin(AnalyseMeshQuality2).EnableRatioJacDetAsAMetric = 1;");
Plugin(AnalyseMeshQuality2).EnableRatioJacDetAsAMetric = 1;
Printf("Plugin(AnalyseMeshQuality2).Run;");
Plugin(AnalyseMeshQuality2).Run;
Printf("Expecting: <<<< Validity computed for 84 elements >>>>");

// End of testing
Printf(" ");
Printf(">>>> All cases completed. Abort. >>>>");
Abort;