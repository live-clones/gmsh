#ifdef OCCGEOMETRY

#include <mystdlib.h>
#include <occgeom.hpp>  


namespace netgen
{

void PrintContents (OCCGeometry * geom)
{
  TopExp_Explorer exp0;
  int cnt;

  (*testout) << "OCC CONTENTS" << endl
	     << "============" << endl;

  for (cnt = 0, exp0.Init(geom->shape, TopAbs_COMPOUND); exp0.More(); exp0.Next()) cnt++;
  (*testout) << "COMPOUND : " << cnt << endl;

  for (cnt = 0, exp0.Init(geom->shape, TopAbs_COMPSOLID); exp0.More(); exp0.Next()) cnt++;
  (*testout) << "COMPSOLID: " << cnt << endl;

  for (cnt = 0, exp0.Init(geom->shape, TopAbs_SOLID); exp0.More(); exp0.Next()) cnt++;
  (*testout) << "SOLID    : " << cnt << endl;

  for (cnt = 0, exp0.Init(geom->shape, TopAbs_SHELL); exp0.More(); exp0.Next()) cnt++;
  (*testout) << "SHELL    : " << cnt << endl;

  for (cnt = 0, exp0.Init(geom->shape, TopAbs_FACE); exp0.More(); exp0.Next()) cnt++;
  (*testout) << "FACE     : " << cnt << endl;

  for (cnt = 0, exp0.Init(geom->shape, TopAbs_WIRE); exp0.More(); exp0.Next()) cnt++;
  (*testout) << "WIRE     : " << cnt << endl;

  for (cnt = 0, exp0.Init(geom->shape, TopAbs_EDGE); exp0.More(); exp0.Next()) cnt++;
  (*testout) << "EDGE     : " << cnt << endl;

  for (cnt = 0, exp0.Init(geom->shape, TopAbs_VERTEX); exp0.More(); exp0.Next()) cnt++;
  (*testout) << "VERTEX   : " << cnt << endl;
}


void HealGeometry (OCCGeometry * geom)
{
  TopExp_Explorer exp0;
  int cnt;


  for (cnt = 0, exp0.Init(geom->shape, TopAbs_SOLID); exp0.More(); exp0.Next()) cnt++;
  if (cnt == 0)
    {
      cout << "OCC: Geometry file invalid! No solids. Generating one common solid" << endl;

      BRepOffsetAPI_Sewing sewedObj;
      for (exp0.Init(geom->shape, TopAbs_FACE); exp0.More(); exp0.Next())
	sewedObj.Add (TopoDS::Face(exp0.Current()));
      sewedObj.Perform();

      BRepBuilderAPI_MakeSolid ms;
      for (exp0.Init(sewedObj.SewedShape(), TopAbs_SHELL); exp0.More(); exp0.Next())
	ms.Add (TopoDS::Shell(exp0.Current()));

      geom->shape = ms;
    }
}


OCCGeometry * LoadOCC_IGES (const char * filename)
{
  OCCGeometry * occgeo;
  occgeo = new OCCGeometry;
  
  IGESControl_Reader reader;
  Standard_Integer stat = reader.LoadFile((char*)filename);
  reader.TransferRoots (Standard_False); // Tranlate IGES -> OCC
  occgeo->shape = reader.OneShape();
  occgeo->changed = 1;
  PrintContents (occgeo);
  HealGeometry (occgeo);
  occgeo->BuildFMap();
  return occgeo;
}

OCCGeometry * LoadOCC_STEP (const char * filename)
{
  OCCGeometry * occgeo;
  occgeo = new OCCGeometry;
  
  STEPControl_Reader reader;
  Standard_Integer stat = reader.ReadFile((char*)filename);
  Standard_Integer nb = reader.NbRootsForTransfer();
  reader.TransferRoots (); // Tranlate STEP -> OCC
  occgeo->shape = reader.OneShape();
  occgeo->changed = 1;
  PrintContents (occgeo);
  HealGeometry (occgeo);
  occgeo->BuildFMap();
  return occgeo;
}


}


#endif
