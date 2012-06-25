Mesh.Algorithm = 7; //(1=MeshAdapt, 2=Automatic, 5=Delaunay, 6=Frontal, 7=bamg, 8=delquad)
Mesh.Algorithm3D = 7; //(1=tetgen, 4=netgen, 7=mmg3D

Mesh.LcIntegrationPrecision = 1.e-2;

Merge "cylemi.stl";

Mesh.RecombineAll = 1;
//Mesh.Bunin = 200;

Field[1] = Centerline;
Field[1].FileName = "centerlinesCYL.vtk";
Field[1].nbPoints = 25;

Field[1].closeVolume =1;
Field[1].reMesh =1;

Field[1].run;

Background Field = 1;


