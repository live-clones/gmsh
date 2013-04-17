Mesh.Algorithm = 7; //(1=MeshAdapt, 2=Automatic, 5=Delaunay, 6=Frontal, 7=bamg, 8=delquad, 9=packing)
Mesh.Algorithm3D = 7; //(1=tetgen, 4=netgen, 7=mmg3D, 9=Rtree)

//Mesh.RecombineAll=1;
//Mesh.Recombine3DAll=1;
//Mesh.Smoothing=0;
//Mesh.SmoothCrossField=0;

Mesh.LcIntegrationPrecision = 1.e-3;

Merge "cylemi.stl";

//Mesh.Bunin = 100;

Field[1] = Centerline;
Field[1].FileName = "centerlinesCYL.vtk";
Field[1].nbPoints = 16;

Field[1].closeVolume =1;
Field[1].reMesh =1;

Field[1].run;

Background Field = 1;


