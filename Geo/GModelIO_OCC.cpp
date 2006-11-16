  // $Id: GModelIO_OCC.cpp,v 1.5 2006-11-16 01:56:52 geuzaine Exp $
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

#if defined(HAVE_OCC)
#include "OCCIncludes.h"
#include "OCCVertex.h"
#include "OCCEdge.h"
#include "OCCFace.h"
#include "OCCRegion.h"

class OCC_Internals
{
  TopoDS_Shape shape;
  TopTools_IndexedMapOfShape fmap, emap, vmap, somap, shmap, wmap;
public:
  OCC_Internals ()
  {
    somap.Clear();
    shmap.Clear();
    fmap.Clear();
    wmap.Clear();
    emap.Clear();
    vmap.Clear();
  }
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

void OCC_Internals :: loadBREP (const char *fn)
{
  BRep_Builder aBuilder;
  Standard_Boolean result = BRepTools::Read( shape, (char*)fn, aBuilder );
}

void OCC_Internals :: loadSTEP (const char *fn)
{
  STEPControl_Reader reader;
  Standard_Integer stat = reader.ReadFile((char*)fn);
  Standard_Integer nb = reader.NbRootsForTransfer();
  reader.TransferRoots (); 
  shape = reader.OneShape();  
}

void OCC_Internals :: loadIGES (const char *fn)
{
  IGESControl_Reader reader;
  Standard_Integer stat = reader.ReadFile((char*)fn);
  Standard_Integer nb = reader.NbRootsForTransfer();
  reader.TransferRoots (); 
  shape = reader.OneShape();  
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
