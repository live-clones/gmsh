#ifndef FILE_OCCGEOM
#define FILE_OCCGEOM

/* *************************************************************************/
/* File:   occgeom.hpp                                                     */
/* Author: Robert Gaisbauer                                                */
/* Date:   26. May  03                                                     */
/* *************************************************************************/

#ifdef OCCGEOMETRY

#include <meshing.hpp>

#include "BRep_Tool.hxx"
#include "Geom_Curve.hxx"
#include "Geom2d_Curve.hxx"
#include "Geom_Surface.hxx"
#include "GeomAPI_ProjectPointOnSurf.hxx"
#include "GeomAPI_ProjectPointOnCurve.hxx"
#include "BRepTools.hxx"
#include "TopExp.hxx"
#include "BRepBuilderAPI_MakeVertex.hxx"
#include "BRepBuilderAPI_MakeShell.hxx"
#include "BRepBuilderAPI_MakeSolid.hxx"
#include "BRepOffsetAPI_Sewing.hxx"
#include "BRepLProp_SLProps.hxx"
#include "BRepAdaptor_Surface.hxx"
#include "Poly_Triangulation.hxx"
#include "Poly_Array1OfTriangle.hxx"
#include "TColgp_Array1OfPnt2d.hxx"
#include "Poly_Triangle.hxx"
#include "GProp_GProps.hxx"
#include "BRepGProp.hxx"
#include "Geom_Surface.hxx"
#include "TopExp.hxx"
#include "gp_Pnt.hxx"
#include "TopoDS.hxx"
#include "TopExp_Explorer.hxx"
#include "BRep_Tool.hxx"
#include "Geom_Curve.hxx"
#include "Geom2d_Curve.hxx"
#include "Geom_Surface.hxx"
#include "GeomAPI_ProjectPointOnSurf.hxx"
#include "GeomAPI_ProjectPointOnCurve.hxx"
#include "TopoDS_Wire.hxx"
#include "BRepTools_WireExplorer.hxx"
#include "BRepTools.hxx"
#include "TopTools_IndexedMapOfShape.hxx"
#include "TopExp.hxx"
#include "BRepBuilderAPI_MakeVertex.hxx"
#include "BRepBuilderAPI_MakeShell.hxx"
#include "BRepBuilderAPI_MakeSolid.hxx"
#include "BRepOffsetAPI_Sewing.hxx"
#include "BRepLProp_SLProps.hxx"
#include "BRepAdaptor_Surface.hxx"
#include "Poly_Triangulation.hxx"
#include "Poly_Array1OfTriangle.hxx"
#include "TColgp_Array1OfPnt2d.hxx"
#include "Poly_Triangle.hxx"
#include "GProp_GProps.hxx"
#include "BRepGProp.hxx"
#include "IGESControl_Reader.hxx"
#include "STEPControl_Reader.hxx"
#include "TopoDS_Shape.hxx"
#include "TopoDS_Face.hxx"



namespace netgen
{

#include "occmeshsurf.hpp"


class OCCGeometry
{
public:
  TopoDS_Shape shape;
  TopTools_IndexedMapOfShape fmap, emap, vmap;
  double maxsize;

  bool changed;


  OCCGeometry()
  {
    fmap.Clear();
    emap.Clear();
    vmap.Clear();
  }


  void BuildFMap()
  {
    TopExp_Explorer exp0, exp1, exp2, exp3;
    maxsize = 0;

    /*    
    for (exp3.Init(shape, TopAbs_EDGE); exp3.More(); exp3.Next())
      {
	TopoDS_Edge edge = TopoDS::Edge(exp3.Current());
	(*testout) << edge.Orientation() << endl;
	if (emap.FindIndex(edge) < 1)
	  emap.Add (edge);
      }
    */
   

    for (exp0.Init(shape, TopAbs_SOLID); exp0.More(); exp0.Next())
      for (exp1.Init(exp0.Current(), TopAbs_SHELL); exp1.More(); exp1.Next())
	{
	  TopoDS_Shape shell = exp1.Current().Composed (exp0.Current().Orientation());

	  for (exp2.Init(shell, TopAbs_FACE); exp2.More(); exp2.Next())
	    {
	      fmap.Add (exp2.Current().Composed(shell.Orientation()));
	      
	      for (exp3.Init(exp2.Current(), TopAbs_EDGE); exp3.More(); exp3.Next())
		{
		  TopoDS_Edge edge = TopoDS::Edge(exp3.Current());
		  if (emap.FindIndex(edge) < 1)
		    emap.Add (edge);
		  /*
		  else
		    {
		      cout << edge.Orientation() << " = " << emap(emap.FindIndex(edge)).Orientation() << endl;
		    }
		  */
		}
	      
	      for (exp3.Init(exp2.Current(), TopAbs_VERTEX); exp3.More(); exp3.Next())
		{
		  TopoDS_Vertex vertex = TopoDS::Vertex(exp3.Current());
		  if (vmap.FindIndex(vertex) < 1)
		    {
		      vmap.Add (vertex);
		      
		      gp_Pnt p = BRep_Tool::Pnt(vertex);
		      maxsize = max (maxsize, fabs(p.X()));
		      maxsize = max (maxsize, fabs(p.Y()));
		      maxsize = max (maxsize, fabs(p.Y()));
		    }
		}
	    }
	}
    maxsize *= 2;
  }


  double MaxSize()
  {
    return maxsize;
  }



  void Project (int surfi, Point<3> & p) const
  {
    static int cnt = 0;
    if (cnt++ % 1000 == 0) cout << "Project cnt = " << cnt << endl;

    gp_Pnt pnt(p(0), p(1), p(2));

    GeomAPI_ProjectPointOnSurf proj(pnt, BRep_Tool::Surface(TopoDS::Face(fmap(surfi))));
    pnt = proj.NearestPoint();
    p = Point<3> (pnt.X(), pnt.Y(), pnt.Z());
  }

};


void PrintContents (OCCGeometry * geom);
void HealGeometry (OCCGeometry * geom);
OCCGeometry * LoadOCC_IGES (const char * filename);
OCCGeometry * LoadOCC_STEP (const char * filename);

}

#endif

#endif
