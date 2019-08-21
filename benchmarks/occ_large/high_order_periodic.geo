// Nanophotonics benchmark from Alexis Gobe and Stephane Lanteri

///////////////////////////////
/////// C2N STRUCTURE 6 ///////
///////////////////////////////

SetFactory("OpenCASCADE");

///////////////////////////////////////////////////////////////////////////
Macro SetPBCs

// Find bottom and top surfaces using a bounding box search:
e = 1e-6;
masterX() = Surface In BoundingBox{        -e,         -e,         -e,         +e, latSizeY+e, currentHeight+e};
slaveX()  = Surface In BoundingBox{latSizeX-e,         -e,         -e, latSizeX+e, latSizeY+e, currentHeight+e};
masterY() = Surface In BoundingBox{        -e,         -e,         -e, latSizeX+e,         +e, currentHeight+e};
slaveY()  = Surface In BoundingBox{        -e, latSizeY-e,         -e, latSizeX+e, latSizeY+e, currentHeight+e};

// Set a translation mesh periodicity constraint:
Periodic Surface{slaveX()} = {masterX()} Translate{latSizeX,        0,        0};
Periodic Surface{slaveY()} = {masterY()} Translate{       0, latSizeX,        0};
Return
//////

Macro Layer
//Input: currentHeight, latSizeX, latSizeY, hLayer

// Add volume
nLayer = newv;

// Set initial altitude if necessary
If (nLayer == 1)
   currentHeight = 0.0;
EndIf

// Create layer
Block(nLayer) = {0, 0, currentHeight, latSizeX, latSizeY, hLayer};

// Increment height
currentHeight += hLayer;

// Assemble with domain
If (nLayer == 1)
   domain() = nLayer;
Else
   domain() = BooleanFragments{ Volume{domain()}; Delete; } { Volume{nLayer}; Delete; };
EndIf

Return
//////

Macro Plot

// Adjust height
currentHeight -= hLayer;

// Cone
nPlot1 = newv;
Cone(nPlot1) = {xCones, yCones, currentHeight, 0, 0, hCones, rCones, coneSpike, 2*Pi};
s() = Unique(Abs(Boundary{ Volume{nPlot1}; }));
l() = Unique(Abs(Boundary{ Surface{s()}; }));
p() = Unique(Abs(Boundary{ Line{l()}; }));
Characteristic Length{p()} = h1;
cones()  += BooleanIntersection{ Volume{nPlot1}; Delete; }{ Volume{domain()}; };

domain()  = BooleanFragments{ Volume{domain()}; Delete; } { Volume{cones()}; Delete; };

// Adjust height
currentHeight += hLayer;

Return
//////

Macro PlotBot

// Cone
nPlot1 = newv;
Cone(nPlot1) = {xCones, yCones, currentHeight+hCones, 0, 0, hCones, rCones, coneSpike, 2*Pi};
cones() = nPlot1;
s() = Unique(Abs(Boundary{ Volume{nPlot1}; }));
l() = Unique(Abs(Boundary{ Surface{s()}; }));
p() = Unique(Abs(Boundary{ Line{l()}; }));
Characteristic Length{p()} = h1;
s = shiftDiag/475.0;
Affine{ 1,0,s,0, 0,1,s,0, 0,0,1,0 }{ Volume{nPlot1};}
Affine{ 1,0,0,0, 0,1,0,0, 0,0,1,  -hCones }{ Volume{nPlot1};}

domain()  = BooleanFragments{ Volume{domain()}; Delete; } { Volume{cones()}; Delete; };

Return
/////////////////////////////////////////////////////////////////////////

///// PARAMETERS /////

h1 = 20.0;

///// SIZES /////
latSize     = 1000.0;
latSizeX    = latSize;
latSizeY    = latSize;
hLayerMid   = 1736.0;
hLayerTF    = 400.0;
hLayerPML   = 400.0;
hConesTop   = 710.0;
rConesTop   = 250.0;
hConesBot   = 330.0;
rConesBot   = 475.0;
hAir        = 200.0;
hTopPml     = 200.0;
shiftDiag   = 0.0;    // Shift du sommet du cone du bas(0 to 450)
coneSpike   = 20.0;   // largeur de l'aiguille au sommet du cone

///// PLOTS LAYER /////
hLayer = hConesBot;
physicalVolLayerIndex = 2;
Call Layer;
hCones = -hConesBot;
rCones = rConesBot;
xCones = latSize/2.0;
yCones = latSize/2.0;
Call PlotBot;
Physical Volume(physicalVolLayerIndex) = {domain(#domain()-1)};

///// PLOTS LAYER /////
hLayer = hLayerMid;
physicalVolLayerIndex = 1;
Call Layer;
Physical Volume(physicalVolLayerIndex) = {domain(#domain()-1)};

///// PLOTS LAYER /////
hLayer = hConesTop+200;
physicalVolLayerIndex = 3;
physicalVolPlotIndex  = 1;
Call Layer;
hCones = hConesTop;
rCones = rConesTop;
For i In {0:1}
    xCones = rCones+(2*rCones)*i;
    For j In {0:1}
        yCones = rCones+(2*rCones)*j;
        Call Plot;
    EndFor
EndFor
Physical Volume(physicalVolPlotIndex) += {cones()};
Physical Volume(physicalVolLayerIndex) = {domain(#domain()-1)};

///// PLOTS LAYER /////
hLayer = hLayerTF;
physicalVolLayerIndex = 1003;
Call Layer;
Physical Volume(physicalVolLayerIndex) = {domain(#domain()-1)};

///// PLOTS LAYER /////
hLayer = hLayerPML;
physicalVolLayerIndex += 1003;
Call Layer;
Physical Volume(physicalVolLayerIndex) = {domain(#domain()-1)};

Call SetPBCs;

Mesh.CharacteristicLengthMin = 100;
Mesh.CharacteristicLengthMax = 200;
Mesh.HighOrderOptimize = 2; // elastic + optim
Mesh.HighOrderPeriodic = 1;
Mesh.OptimizeNetgen = 1;
Mesh.ElementOrder = 2;
Mesh.HighOrderThresholdMin = 0.5;
Mesh.HighOrderThresholdMax = 2.0;
//Mesh.ScalingFactor = 1.0e-9;
