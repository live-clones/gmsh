#include <mystdlib.h>
#include <csg.hpp>
#include <geometry2d.hpp>
#include "meshing.hpp"

namespace netgen
{

  // static ARRAY<Point<2> > points2;
  //  static ARRAY<int> lp1, lp2;


  extern void Optimize2d (Mesh & mesh, MeshingParameters & mp);




  void MeshFromSpline2D (SplineGeometry2d & geometry,
			 Mesh *& mesh, 
			 MeshingParameters & mp)
  {
    int i, j, domnr;
    double elto0, minx, miny, maxx, maxy;

    PointIndex pi;
    SegmentIndex si;
    SurfaceElementIndex sei;

    double h = mp.maxh;

    Box<2> bbox;
    geometry.GetBoundingBox (bbox);

    if (bbox.Diam() < h) 
      {
	h = bbox.Diam();
	mp.maxh = h;
      }

    mesh = new Mesh;
    mesh->SetDimension (2);
    PrintMessage (1, "Generate Mesh from spline geometry");

    geometry.PartitionBoundary (h, *mesh);

    int maxdomnr = 0;
    for (si = 0; si < mesh->GetNSeg(); si++)
      {
	if ( (*mesh)[si].domin > maxdomnr) maxdomnr = (*mesh)[si].domin;
	if ( (*mesh)[si].domout > maxdomnr) maxdomnr = (*mesh)[si].domout;
      }
  

    mesh->ClearFaceDescriptors();
    for (i = 1; i <= maxdomnr; i++)
      mesh->AddFaceDescriptor (FaceDescriptor (i, 0, 0, i));

    Point3d pmin(bbox.PMin()(0), bbox.PMin()(1), -bbox.Diam());
    Point3d pmax(bbox.PMax()(0), bbox.PMax()(1), bbox.Diam());

    mesh->SetLocalH (pmin, pmax, mparam.grading);
    mesh->SetGlobalH (h);
  
    mesh->CalcLocalH();

    int bnp = mesh->GetNP(); // boundary points

    for (domnr = 1; domnr <= maxdomnr; domnr++)
      {
	PrintMessage (3, "Meshing domain ", domnr, " / ", maxdomnr);

	int oldnf = mesh->GetNSE();

	Meshing2 meshing (Box3d (pmin, pmax));

	for (pi = PointIndex::BASE; 
	     pi < bnp+PointIndex::BASE; pi++)
	  meshing.AddPoint ( (*mesh)[pi], pi);
      

	PointGeomInfo gi;
	gi.trignum = 1;
	for (si = 0; si < mesh->GetNSeg(); si++)
	  {
	    if ( (*mesh)[si].domin == domnr)
	      meshing.AddBoundaryElement ( (*mesh)[si].p1 + 1 - PointIndex::BASE, 
					   (*mesh)[si].p2 + 1 - PointIndex::BASE, gi, gi);
	    if ( (*mesh)[si].domout == domnr)
	      meshing.AddBoundaryElement ( (*mesh)[si].p2 + 1 - PointIndex::BASE, 
					   (*mesh)[si].p1 + 1 - PointIndex::BASE, gi, gi);
	  }


	mparam.checkoverlap = 0;
	meshing.GenerateMesh (*mesh, h, domnr);

	for (sei = oldnf; sei < mesh->GetNSE(); sei++)
	  (*mesh)[sei].SetIndex (domnr);
      }


    int hsteps = mp.optsteps2d;

    mp.optimize2d = "smcm"; 
    mp.optsteps2d = hsteps/2;
    Optimize2d (*mesh, mp);

    mp.optimize2d = "Smcm"; 
    mp.optsteps2d = (hsteps+1)/2;
    Optimize2d (*mesh, mp);

    mp.optsteps2d = hsteps;



    mesh->Compress();
    mesh -> SetNextMajorTimeStamp();
  }


}
