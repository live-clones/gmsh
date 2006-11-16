  // $Id: GModelIO_OCC.cpp,v 1.7 2006-11-16 18:48:00 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "GModel.h"
#include "Message.h"
#include "OCCIncludes.h"
#include "OCCVertex.h"
#include "OCCEdge.h"
#include "OCCFace.h"
#include "OCCRegion.h"

#if defined(HAVE_OCC)

#include "ShapeAnalysis_ShapeTolerance.hxx"
#include "ShapeAnalysis_ShapeContents.hxx"
#include "ShapeAnalysis_CheckSmallFace.hxx"
#include "ShapeAnalysis_DataMapOfShapeListOfReal.hxx"
#include "BRepAlgoAPI_Fuse.hxx"
#include "BRepCheck_Analyzer.hxx"
#include "BRepLib.hxx"
#include "ShapeBuild_ReShape.hxx"
#include "ShapeFix.hxx"
#include "ShapeFix_FixSmallFace.hxx"

class OCC_Internals
{
  TopoDS_Shape shape;
  TopTools_IndexedMapOfShape fmap, emap, vmap, somap, shmap, wmap;
  double tolerance;
public:
  OCC_Internals ()
  {
    somap.Clear();
    shmap.Clear();
    fmap.Clear();
    wmap.Clear();
    emap.Clear();
    vmap.Clear();
    tolerance = 1.e-5;
  }
  void HealGeometry (bool fixsmalledges = true, bool fixspotstripfaces = true, bool sewfaces = false, bool makesolids = false);
  void loadSTEP(const char *);
  void loadIGES(const char *);
  void loadBREP(const char *);  
  void buildGModel (GModel *gm);
  void buildLists ();
};

void OCC_Internals :: buildLists ()
{
  TopExp_Explorer exp0, exp1, exp2, exp3, exp4, exp5;
  
  for (exp0.Init(shape, TopAbs_SOLID);
       exp0.More(); exp0.Next())
    {
      TopoDS_Solid solid = TopoDS::Solid (exp0.Current());
      
      if (somap.FindIndex(TopoDS::Solid (exp0.Current())) < 1)
	{
	  somap.Add (TopoDS::Solid (exp0.Current()));
	  
	  for (exp1.Init(exp0.Current(), TopAbs_SHELL);
	       exp1.More(); exp1.Next())
	    {
	      TopoDS_Shell shell = TopoDS::Shell (exp1.Current().Composed (exp0.Current().Orientation()));
	      if (shmap.FindIndex(shell) < 1)
		{
		  shmap.Add (shell);
		  
		  for (exp2.Init(shell, TopAbs_FACE);
		       exp2.More(); exp2.Next())
		    {
		      TopoDS_Face face = TopoDS::Face(exp2.Current().Composed(shell.Orientation()));
		      if (fmap.FindIndex(face) < 1)
			{
			  fmap.Add (face);
			  
			  for (exp3.Init(exp2.Current(), TopAbs_WIRE);
			       exp3.More(); exp3.Next())
			    {
			      TopoDS_Wire wire = TopoDS::Wire (exp3.Current().Composed(face.Orientation()));
			      if (wmap.FindIndex(wire) < 1)
				{
				  wmap.Add (wire);
				  
				  for (exp4.Init(exp3.Current(), TopAbs_EDGE);
				       exp4.More(); exp4.Next())
				    {
				      TopoDS_Edge edge = TopoDS::Edge(exp4.Current().Composed(wire.Orientation()));
				      if (emap.FindIndex(edge) < 1)
					{
					  emap.Add (edge);
					  for (exp5.Init(exp4.Current(), TopAbs_VERTEX);
					       exp5.More(); exp5.Next())
					    {
					      TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
					      if (vmap.FindIndex(vertex) < 1)
						vmap.Add (vertex);
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
  
  // Free Shells
  for (exp1.Init(exp0.Current(), TopAbs_SHELL, TopAbs_SOLID);
       exp1.More(); exp1.Next())
    {
      TopoDS_Shape shell = exp1.Current().Composed (exp0.Current().Orientation());
      if (shmap.FindIndex(shell) < 1)
	{
	  shmap.Add (shell);
	  
	  for (exp2.Init(shell, TopAbs_FACE);
	       exp2.More(); exp2.Next())
	    {
	      TopoDS_Face face = TopoDS::Face(exp2.Current().Composed(shell.Orientation()));
	      if (fmap.FindIndex(face) < 1)
		{
		  fmap.Add (face);
		  
		  for (exp3.Init(exp2.Current(), TopAbs_WIRE);
		       exp3.More(); exp3.Next())
		    {
		      TopoDS_Wire wire = TopoDS::Wire (exp3.Current());
		      if (wmap.FindIndex(wire) < 1)
			{
			  wmap.Add (wire);
			  
			  for (exp4.Init(exp3.Current(), TopAbs_EDGE);
			       exp4.More(); exp4.Next())
			    {
			      TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
			      if (emap.FindIndex(edge) < 1)
				{
				  emap.Add (edge);
				  for (exp5.Init(exp4.Current(), TopAbs_VERTEX);
				       exp5.More(); exp5.Next())
				    {
				      TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
				      if (vmap.FindIndex(vertex) < 1)
					vmap.Add (vertex);
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
  
  
  // Free Faces
  
  for (exp2.Init(shape, TopAbs_FACE, TopAbs_SHELL);
       exp2.More(); exp2.Next())
    {
      TopoDS_Face face = TopoDS::Face(exp2.Current());
      if (fmap.FindIndex(face) < 1)
	{
	  fmap.Add (face);
	  
	  for (exp3.Init(exp2.Current(), TopAbs_WIRE);
	       exp3.More(); exp3.Next())
	    {
	      TopoDS_Wire wire = TopoDS::Wire (exp3.Current());
	      if (wmap.FindIndex(wire) < 1)
		{
		  wmap.Add (wire);
		  
		  for (exp4.Init(exp3.Current(), TopAbs_EDGE);
		       exp4.More(); exp4.Next())
		    {
		      TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
		      if (emap.FindIndex(edge) < 1)
			{
			  emap.Add (edge);
			  for (exp5.Init(exp4.Current(), TopAbs_VERTEX);
			       exp5.More(); exp5.Next())
			    {
			      TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
			      if (vmap.FindIndex(vertex) < 1)
				vmap.Add (vertex);
			    }
			}
		    }
		}
	    }
	}
    }


  // Free Wires
  
  for (exp3.Init(shape, TopAbs_WIRE, TopAbs_FACE);
       exp3.More(); exp3.Next())
    {
      TopoDS_Wire wire = TopoDS::Wire (exp3.Current());
      if (wmap.FindIndex(wire) < 1)
	{
	  wmap.Add (wire);
	  
	  for (exp4.Init(exp3.Current(), TopAbs_EDGE);
	       exp4.More(); exp4.Next())
	    {
	      TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
	      if (emap.FindIndex(edge) < 1)
		{
		  emap.Add (edge);
		  for (exp5.Init(exp4.Current(), TopAbs_VERTEX);
		       exp5.More(); exp5.Next())
		    {
		      TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
		      if (vmap.FindIndex(vertex) < 1)
			vmap.Add (vertex);
		    }
		}
	    }
	}
    }


  // Free Edges
  
  for (exp4.Init(shape, TopAbs_EDGE, TopAbs_WIRE);
       exp4.More(); exp4.Next())
    {
      TopoDS_Edge edge = TopoDS::Edge(exp4.Current());
      if (emap.FindIndex(edge) < 1)
	{
	  emap.Add (edge);
	  for (exp5.Init(exp4.Current(), TopAbs_VERTEX);
	       exp5.More(); exp5.Next())
	    {
	      TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
	      if (vmap.FindIndex(vertex) < 1)
		vmap.Add (vertex);
	    }
	}
    }


  // Free Vertices
  
  for (exp5.Init(shape, TopAbs_VERTEX, TopAbs_EDGE);
       exp5.More(); exp5.Next())
    {
      TopoDS_Vertex vertex = TopoDS::Vertex(exp5.Current());
      if (vmap.FindIndex(vertex) < 1)
	vmap.Add (vertex);
    }    

}


void OCC_Internals ::   HealGeometry (bool fixsmalledges , bool fixspotstripfaces, bool sewfaces, bool makesolids)
{
  int nrc = 0, nrcs = 0,
    nrso = somap.Extent(),
    nrsh = shmap.Extent(),
    nrf = fmap.Extent(),
    nrw = wmap.Extent(),
    nre = emap.Extent(),
    nrv = vmap.Extent();

  TopExp_Explorer e;
  for (e.Init(shape, TopAbs_COMPOUND); e.More(); e.Next()) nrc++;
  for (e.Init(shape, TopAbs_COMPSOLID); e.More(); e.Next()) nrcs++;

  double surfacecont = 0;

  for (int i = 1; i <= fmap.Extent(); i++)
    {
      GProp_GProps system;
      BRepGProp::LinearProperties(fmap(i), system);
      surfacecont += system.Mass();
    }

  cout << "Starting geometry healing procedure (tolerance: " << tolerance << ")" << endl
       << "-----------------------------------" << endl;

  if (fixsmalledges)
    {
      cout << endl << "- fixing small edges" << endl;

      Handle(ShapeFix_Wire) sfw;
      Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
      rebuild->Apply(shape);

      for (int i = 1; i <= fmap.Extent(); i++)
	{
	  TopExp_Explorer exp1;
	  for (exp1.Init (fmap(i), TopAbs_WIRE); exp1.More(); exp1.Next())
	    {
	      TopoDS_Wire oldwire = TopoDS::Wire(exp1.Current());
	      sfw = new ShapeFix_Wire (oldwire, TopoDS::Face(fmap(i)),tolerance);
	      sfw->ModifyTopologyMode() = Standard_True;

	      if (sfw->FixSmall (false, tolerance))
		{
		  cout << "Fixed small edge in wire " << wmap.FindIndex (oldwire) << endl;
		  TopoDS_Wire newwire = sfw->Wire();
		  rebuild->Replace(oldwire, newwire, Standard_False);
		}
	      if ((sfw->StatusSmall(ShapeExtend_FAIL1)) ||
		  (sfw->StatusSmall(ShapeExtend_FAIL2)) ||
		  (sfw->StatusSmall(ShapeExtend_FAIL3)))
		cout << "Failed to fix small edge in wire " << wmap.FindIndex (oldwire) << endl;

	      
	    }
	}

      shape = rebuild->Apply(shape);



      {
      Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
      rebuild->Apply(shape);
      TopExp_Explorer exp1;
      for (exp1.Init (shape, TopAbs_EDGE); exp1.More(); exp1.Next())
	{
	  TopoDS_Edge edge = TopoDS::Edge(exp1.Current());
	  if (vmap.FindIndex(TopExp::FirstVertex (edge)) == 
	      vmap.FindIndex(TopExp::LastVertex (edge)))
	    {
	      GProp_GProps system;
	      BRepGProp::LinearProperties(edge, system);
	      if (system.Mass() < tolerance)
		{
		  cout << "removing degenerated edge " << emap.FindIndex(edge) << endl;
		  rebuild->Remove(edge, false);
		}
	    }
	}
      shape = rebuild->Apply(shape);
      }


      Handle(ShapeFix_Wireframe) sfwf = new ShapeFix_Wireframe;
      sfwf->SetPrecision(tolerance);
      sfwf->Load (shape);

      if (sfwf->FixSmallEdges())
	{
	  cout << endl << "- fixing wire frames" << endl;  
	  if (sfwf->StatusSmallEdges(ShapeExtend_OK)) cout << "no small edges found" << endl;
	  if (sfwf->StatusSmallEdges(ShapeExtend_DONE1)) cout << "some small edges fixed" << endl;
	  if (sfwf->StatusSmallEdges(ShapeExtend_FAIL1)) cout << "failed to fix some small edges" << endl;
	}
  

      if (sfwf->FixWireGaps())
	{
	  cout << endl << "- fixing wire gaps" << endl;
	  if (sfwf->StatusWireGaps(ShapeExtend_OK)) cout << "no gaps found" << endl;
	  if (sfwf->StatusWireGaps(ShapeExtend_DONE1)) cout << "some 2D gaps fixed" << endl;
	  if (sfwf->StatusWireGaps(ShapeExtend_DONE2)) cout << "some 3D gaps fixed" << endl;
	  if (sfwf->StatusWireGaps(ShapeExtend_FAIL1)) cout << "failed to fix some 2D gaps" << endl;
	  if (sfwf->StatusWireGaps(ShapeExtend_FAIL2)) cout << "failed to fix some 3D gaps" << endl;
	}
      

      shape = sfwf->Shape();
    }





  if (fixspotstripfaces)
    {
  
      cout << endl << "- fixing spot and strip faces" << endl;
      Handle(ShapeFix_FixSmallFace) sffsm = new ShapeFix_FixSmallFace();
      sffsm -> Init (shape);
      sffsm -> SetPrecision (tolerance);
      sffsm -> Perform();
      
      shape = sffsm -> FixShape();
    }

  if (sewfaces)
    {
      cout << endl << "- sewing faces" << endl;

      TopExp_Explorer exp0;

      BRepOffsetAPI_Sewing sewedObj(tolerance);

      for (exp0.Init (shape, TopAbs_FACE); exp0.More(); exp0.Next())
	{
	  TopoDS_Face face = TopoDS::Face (exp0.Current());
	  sewedObj.Add (face);
	}
      
      sewedObj.Perform();
  
      if (!sewedObj.SewedShape().IsNull())
	shape = sewedObj.SewedShape();
      else
	cout << " not possible";
    }

  if (makesolids)
    {  
      cout << endl << "- making solids" << endl;
      
      TopExp_Explorer exp0;

      BRepBuilderAPI_MakeSolid ms;
      int count = 0;
      for (exp0.Init(shape, TopAbs_SHELL); exp0.More(); exp0.Next())
	{
	  count++;
	  ms.Add (TopoDS::Shell(exp0.Current()));
	}
      
      if (!count)
	{
	  cout << " not possible (no shells)" << endl;
	}
      else
	{
	  BRepCheck_Analyzer ba(ms);
	  if (ba.IsValid ())
	    {
	      Handle(ShapeFix_Shape) sfs = new ShapeFix_Shape;
	      sfs->Init (ms);
	      sfs->SetPrecision(tolerance);
	      sfs->SetMaxTolerance(tolerance);
	      sfs->Perform();
	      shape = sfs->Shape();
	      
	      for (exp0.Init(shape, TopAbs_SOLID); exp0.More(); exp0.Next())
		{
		  TopoDS_Solid solid = TopoDS::Solid(exp0.Current());
		  TopoDS_Solid newsolid = solid;
		  BRepLib::OrientClosedSolid (newsolid);
		  Handle_ShapeBuild_ReShape rebuild = new ShapeBuild_ReShape;
		  //		  rebuild->Apply(shape);
		  rebuild->Replace(solid, newsolid, Standard_False);
		  TopoDS_Shape newshape = rebuild->Apply(shape, TopAbs_COMPSOLID, 1);
		  //		  TopoDS_Shape newshape = rebuild->Apply(shape);
		  shape = newshape;
		}
	    }
	  else
	    cout << " not possible" << endl;
	}
    }
  buildLists();
}


void OCC_Internals :: loadBREP (const char *fn)
{
  BRep_Builder aBuilder;
  Standard_Boolean result = BRepTools::Read( shape, (char*)fn, aBuilder );
  BRepTools::Clean (shape);
  buildLists();
  //  HealGeometry();
  BRepTools::Clean (shape);
}

void OCC_Internals :: loadSTEP (const char *fn)
{
  STEPControl_Reader reader;
  Standard_Integer stat = reader.ReadFile((char*)fn);
  Standard_Integer nb = reader.NbRootsForTransfer();
  reader.TransferRoots (); 
  shape = reader.OneShape();  
  BRepTools::Clean (shape);
}

void OCC_Internals :: loadIGES (const char *fn)
{
  IGESControl_Reader reader;
  Standard_Integer stat = reader.ReadFile((char*)fn);
  Standard_Integer nb = reader.NbRootsForTransfer();
  reader.TransferRoots (); 
  shape = reader.OneShape();  
  BRepTools::Clean (shape);
}

void OCC_Internals :: buildGModel (GModel *model)
{
  // building geom vertices
  int nvertices = vmap.Extent();
  for (int i = 1; i <= nvertices; i++)
    {
      OCCVertex *v = new OCCVertex (model, i, TopoDS::Vertex(vmap(i)));
      model->add(v);
    }
  // building geom edges
  int nedges = emap.Extent();
  for (int i = 1; i <= nedges; i++)
    {
      TopoDS_Edge edge = TopoDS::Edge(emap(i));
      int i1 = vmap.FindIndex(TopExp::FirstVertex (edge)); 
      int i2 = vmap.FindIndex(TopExp::LastVertex (edge));
      GVertex *v1 = model->vertexByTag ( i1);
      GVertex *v2 = model->vertexByTag ( i2);
      OCCEdge *e = new OCCEdge (model, edge, i, v1, v2);
      model->add(e);
    }
  // building geom faces
  int nfaces = fmap.Extent();
  for (int i = 1; i <= nfaces; i++)
    {
      TopoDS_Face face = TopoDS::Face(fmap(i));
      OCCFace *f = new OCCFace (model, face, i, emap);
      model->add(f);
    }
  // building geom regions
  int nvolumes = somap.Extent();
  for (int i = 1; i <= nvolumes; i++)
    {
      TopoDS_Solid solid = TopoDS::Solid(somap(i));
      OCCRegion *r = new OCCRegion (model, solid, i, fmap);
      model->add(r);
    }

}

int GModel::readOCCSTEP(const std::string &fn)
{
  occ_internals = new OCC_Internals;
  occ_internals->loadSTEP (fn.c_str());
  occ_internals->buildLists ();
  occ_internals->buildGModel (this);
  return 1;
}
int GModel::readOCCIGES(const std::string &fn)
{
  occ_internals = new OCC_Internals;
  occ_internals->loadIGES (fn.c_str());
  occ_internals->buildLists ();
  occ_internals->buildGModel (this);
  return 1;
}
int GModel::readOCCBREP(const std::string &fn)
{
  occ_internals = new OCC_Internals;
  occ_internals->loadBREP (fn.c_str());
  occ_internals->buildLists ();
  //  occ_internals->HealGeometry();
  occ_internals->buildGModel (this);
  return 1;
}
void GModel::deleteOCCInternals()
{
  if(occ_internals)delete occ_internals;
}

#else

int GModel::readOCCSTEP(const std::string &fn)
{
  Msg(GERROR,"Gmsh has to be compiled with OpenCascade support to load %s",
      fn.c_str());
  return 0;
}
int GModel::readOCCIGES(const std::string &fn)
{
  Msg(GERROR,"Gmsh has to be compiled with OpenCascade support to load %s",
      fn.c_str());
  return 0;
}
int GModel::readOCCBREP(const std::string &fn)
{
  Msg(GERROR,"Gmsh has to be compiled with OpenCascade support to load %s",
      fn.c_str());
  return 0;
}
void GModel::deleteOCCInternals()
{
}

#endif
