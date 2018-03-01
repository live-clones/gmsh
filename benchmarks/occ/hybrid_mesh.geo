SetFactory("OpenCASCADE");
mm = 1e-3;
DefineConstant[
  r1 = {1*mm, Min 0.2*mm, Max 5*mm, Step 0.2*mm,
    Name "Parameters/Coil/0Wire radius"}
  r2 = {5*mm, Min 2*r1, Max 40*mm, Step 0.5*mm,
    Name "Parameters/Coil/1Radius"}
  l1 = {15*mm, Min 1*mm, Max 100*mm, Step 0.5*mm,
    Name "Parameters/Coil/2Base length"}
  xm = {-5*mm, Min -10*mm, Max 10*mm, Step 0.5*mm,
    Name "Parameters/Mold/0Position X"}
  ym = {-1.5*mm, Min -10*mm, Max 10*mm, Step 0.5*mm,
    Name "Parameters/Mold/0Position Y"}
  zm = {-2*mm, Min -10*mm, Max 10*mm, Step 0.5*mm,
    Name "Parameters/Mold/0Position Z"}
  dxm = {20*mm, Min 1*mm, Max 50*mm, Step 0.5*mm,
    Name "Parameters/Mold/1Width"}
  dym = {3*mm, Min 1*mm, Max 50*mm, Step 0.5*mm,
    Name "Parameters/Mold/2Thickness"}
  dzm = {20*mm, Min 1*mm, Max 50*mm, Step 0.5*mm,
    Name "Parameters/Mold/3Depth"}
  lc1 = {1*mm, Min 0.1*mm, Max 10*mm, Step 0.1*mm,
    Name "Parameters/Mesh/Mesh size near"}
  lc2 = {10*mm, Min 0.1*mm, Max 10*mm, Step 0.1*mm,
    Name "Parameters/Mesh/Mesh size far"}
  layersInd = {10, Min 5, Max 30, Step 1,
    Name "Parameters/Mesh/Extrusion layers in wire"}
  layersMold = {10, Min 5, Max 30, Step 1,
    Name "Parameters/Mesh/Extrusion layers in mold"}
];

// draw axes to visualize the size of the parts in the model
General.Axes = 3;
General.AxesAutoPosition = 0;
General.AxesMinX = xm; General.AxesMaxX = xm+dxm;
General.AxesMinY = ym; General.AxesMaxY = 0;
General.AxesMinZ = 0; General.AxesMaxZ = 0;

// don't warn about mixing structured/unstructured
General.ExpertMode = 1;

// thickness of the air layer around the objects in the model
dair = 10*mm;

// inductor
Disk(1) = {0, 0, 0, r1};
Extrude {0, 0, -l1} { Surface{1};
  //Layers{layersInd};
}
Extrude {{0, 1, 0}, {r2, 0, -l1}, -Pi} { Surface{3};
  Layers{layersInd};
}
Extrude {0, 0, l1} { Surface{5};
  Layers{layersInd};
}

// mold
Rectangle(8) = {xm, ym, zm, dxm, -dzm};
Rotate{{1,0,0},{xm,ym,zm}, Pi/2 }{ Surface{8}; }
Extrude{0, -dym, 0}{ Surface{8}; Layers{layersMold}; }

// compute the model bounding box and create the air box
BoundingBox;
lx = 2*dair + General.MaxX - General.MinX;
ly = 2*dair + General.MaxY - General.MinY;
lz = 2*dair + General.MaxZ - General.MinZ;
Box(5) = {General.MinX - dair, General.MinY - dair, 0, lx, ly, -lz};

Characteristic Length { PointsOf{ Volume{1:4}; } } = lc1;
Characteristic Length { PointsOf{ Volume{5}; } } = lc2;

// intersect everything to make the final mesh conformal
BooleanFragments{ Volume{1:5}; Delete; }{}
