#include <mystdlib.h>


#include <meshing.hpp>
#include <csg.hpp>
#include <geometry2d.hpp>
#include <stlgeom.hpp>

#include <visual.hpp>

#include "nginterface.h"
// #include <FlexLexer.h>




namespace netgen
{
  extern AutoPtr<Mesh> mesh;
  extern VisualSceneMesh vsmesh;
  extern Tcl_Interp * tcl_interp;

  extern SplineGeometry2d * geometry2d;
  extern CSGeometry * parsegeom;
  extern CSGeometry * geometry;
  extern STLGeometry * stlgeometry;

  extern VisualSceneSolution vssolution;
  extern CSGeometry * ParseCSG (istream & istr);
}


using namespace netgen;

/*
  extern void * operator new (size_t s);
  extern void * operator new [] (size_t s);
  extern void operator delete (void * p);
  extern void operator delete [] (void * p);
*/

// extern FlexLexer * lexer;



void Ng_LoadGeometry (char * filename)
{
  ifstream infile (filename);

  if (geometry) 
    delete geometry;

  if (strcmp (&filename[strlen(filename)-3], "geo") == 0)
    {
      /*
      geometry = new CSGeometry(filename);
      
      parsegeom = geometry;
      
      lexer = new yyFlexLexer (&infile);
      
      extern int yyparse ();
      yyparse ();
      delete lexer; 
      */

      geometry = netgen::ParseCSG (infile);

      if (!geometry)
	throw NgException ("input file not found");

      geometry -> FindIdenticSurfaces(1e-6);
      Box<3> box (geometry->BoundingBox());

      geometry->CalcTriangleApproximation (box, 0.01, 10);
    }
  else
    {
      geometry = new CSGeometry("");

      if (strcmp (&filename[strlen(filename)-4], "in2d") == 0)
	{

	  if (geometry2d)
	    delete geometry2d;
	  geometry2d = new SplineGeometry2d();
	  geometry2d -> Load (filename);
	}

      else
	{
	  cerr << "Unknown geometry extension!!" << endl;
	}
    }
}                          


void Ng_LoadMesh (char * filename)
{
  mesh.Reset (new Mesh());
  mesh->Load (filename);
}



int Ng_GetDimension ()
{
  return mesh->GetDimension();
}

int Ng_GetNP ()
{
  return mesh->GetNP();
}

int Ng_GetNV ()
{
  return mesh->GetNV();
}

int Ng_GetNE ()
{
  if (mesh->GetDimension() == 3)
    return mesh->GetNE();
  else
    return mesh->GetNSE();
}

int Ng_GetNSE ()
{
  if (mesh->GetDimension() == 3)
    return mesh->GetNSE();
  else
    return mesh->GetNSeg();
}

void Ng_GetPoint (int pi, double * p)
{
  const Point3d & hp = mesh->Point (pi);
  p[0] = hp.X();
  p[1] = hp.Y();
  if (mesh->GetDimension() == 3)
    p[2] = hp.Z();
}


NG_ELEMENT_TYPE Ng_GetElement (int ei, int * epi, int * np)
{
  if (mesh->GetDimension() == 3)
    {
      int i;
      const Element & el = mesh->VolumeElement (ei);
      for (i = 0; i < el.GetNP(); i++)
	epi[i] = el.PNum(i+1);
      
      if (np)
	*np = el.GetNP();

      if (el.GetType() == PRISM)
	{
	  // degenerated prism, (should be obsolete)
	  const int map1[] = { 3, 2, 5, 6, 1 };
	  const int map2[] = { 1, 3, 6, 4, 2 };
	  const int map3[] = { 2, 1, 4, 5, 3 };
	  
	  const int * map = NULL;
	  int deg1 = 0, deg2 = 0, deg3 = 0;
	  int deg = 0;
	  if (el.PNum(1) == el.PNum(4)) { map = map1; deg1 = 1; }
	  if (el.PNum(2) == el.PNum(5)) { map = map2; deg2 = 1; }
	  if (el.PNum(3) == el.PNum(6)) { map = map3; deg3 = 1; }
	  
	  switch (deg1+deg2+deg3)
	    {
	      {
	      case 1:
		cout << "degenerated prism found, deg = 1" << endl;
		for (i = 0; i < 5; i++)
		  epi[i] = el.PNum (map[i]);
		
		if (np) *np = 5;
		return NG_PYRAMID;
		break;
	      }
	    case 2:
	      {
		cout << "degenerated prism found, deg = 2" << endl;
		if (!deg1) epi[3] = el.PNum(4);
		if (!deg2) epi[3] = el.PNum(5);
		if (!deg3) epi[3] = el.PNum(6);
		
		if (np) *np = 4;
		return NG_TET;
		break;
	      }
	    default:
	      ;
	    }
	  
	}

      return NG_ELEMENT_TYPE (el.GetType());
    }
  else
    {
      int i;
      const Element2d & el = mesh->SurfaceElement (ei);
      for (i = 0; i < el.GetNP(); i++)
	epi[i] = el.PNum(i+1);      

      if (np) *np = el.GetNP();
      return NG_ELEMENT_TYPE (el.GetType());
      /*
      switch (el.GetNP())
	{
	case 3: return NG_TRIG; 
	case 4: return NG_QUAD; 
	case 6: return NG_TRIG6; 
	}
      */
    }

  // should not occur
  return NG_TET;
}


NG_ELEMENT_TYPE Ng_GetElementType (int ei)
{
  if (mesh->GetDimension() == 3)
    {
      return NG_ELEMENT_TYPE (mesh->VolumeElement (ei).GetType());
    }
  else
    {
      int i;
      const Element2d & el = mesh->SurfaceElement (ei);
      switch (el.GetNP())
	{
	case 3: return NG_TRIG; 
	case 4: return NG_QUAD; 
	case 6: return NG_TRIG6; 
	}
    }

  // should not occur
  return NG_TET;
}



int Ng_GetElementIndex (int ei)
{
  if (mesh->GetDimension() == 3)
    return mesh->VolumeElement(ei).GetIndex();
  else
    {
      int ind = mesh->SurfaceElement(ei).GetIndex(); 
      ind = mesh->GetFaceDescriptor(ind).BCProperty();
      return ind;
    }
}

char * Ng_GetElementMaterial (int ei)
{
  static char empty[] = "";
  if (mesh->GetDimension() == 3)
    {
      int ind = mesh->VolumeElement(ei).GetIndex();
      // cout << "ind = " << ind << endl;
      const char * mat = mesh->GetMaterial (ind);
      if (mat)
	return const_cast<char*> (mat);
      else 
	return empty;
    }
  return 0;
}

NG_ELEMENT_TYPE Ng_GetSurfaceElement (int ei, int * epi, int * np)
{
  if (mesh->GetDimension() == 3)
    {
      const Element2d & el = mesh->SurfaceElement (ei);
      for (int i = 0; i < el.GetNP(); i++)
	epi[i] = el[i];
      
      if (np) *np = el.GetNP();
      
      return NG_ELEMENT_TYPE (el.GetType());
    }
  else
    {
      const Segment & seg = mesh->LineSegment (ei);

      if (!seg.pmid)
	{
	  epi[0] = seg.p1;
	  epi[1] = seg.p2;
	  
	  if (np) *np = 2;
	  return NG_SEGM;
	}
      else
	{
	  epi[0] = seg.p1;
	  epi[1] = seg.p2;
	  epi[2] = seg.pmid;

	  if (np) *np = 3;
	  return NG_SEGM3;
	}
    }

  return NG_TRIG;
}

int Ng_GetSurfaceElementIndex (int ei)
{
  if (mesh->GetDimension() == 3)
    return mesh->GetFaceDescriptor(mesh->SurfaceElement(ei).GetIndex()).BCProperty();
  else
    return mesh->LineSegment(ei).si;
}


void Ng_GetNormalVector (int sei, int locpi, double * nv)
{
  nv[0] = 0; 
  nv[1] = 0;
  nv[2] = 1;
  
  if (mesh->GetDimension() == 3)
    {
      Vec<3> n;
      Point<3> p;
      p = mesh->Point (mesh->SurfaceElement(sei).PNum(locpi));

      int surfi = mesh->GetFaceDescriptor(mesh->SurfaceElement(sei).GetIndex()).SurfNr();
      if (geometry)
	{
	  geometry->GetSurface (surfi) -> GetNormalVector(p, n);
	  nv[0] = n(0);
	  nv[1] = n(1);
	  nv[2] = n(2);
	}
    }
}


int Ng_FindElementOfPoint (double * p, double * lami)
{
  if (mesh->GetDimension() == 3)
    {
      Point3d p3d(p[0], p[1], p[2]);
      int ind = 
	mesh->GetElementOfPoint(p3d, lami);
      return ind;
    }
  else
    {
      double lam3[3];
      Point3d p2d(p[0], p[1], 0);
      int ind = 
	mesh->GetElementOfPoint(p2d, lam3);
      lami[0] = lam3[0];
      lami[1] = lam3[1];
      return ind;
    }
}



void Ng_GetElementTransformation (int ei, const double * xi, 
				  double * x, double * dxdxi)
{
  if (mesh->GetDimension() == 2)
    {
      Point<2> xl(xi[0], xi[1]);
      Point<3> xg;
      Mat<3,2> dx;

      mesh->GetCurvedElements().CalcSurfaceTransformation (xl, ei-1, xg, dx);

      // still 1-based arrays
      if (x)
	{
	  for (int i = 0; i < 2; i++)
	    x[i] = xg(i);
	}
	  
      if (dxdxi)
	{
	  for (int i=0; i<2; i++)
	    {
	      dxdxi[2*i] = dx(i,0);
	      dxdxi[2*i+1] = dx(i,1);
	    }
	}
    }
  else
    {
      Point<3> xl(xi[0], xi[1], xi[2]);
  //    (*testout) << "elnr = " << ei << ", eltrans, xl = " << xl << endl;
      Point<3> xg;
      Mat<3,3> dx;

      mesh->GetCurvedElements().CalcElementTransformation (xl, ei-1, xg, dx);

      // still 1-based arrays
      if (x)
	{
	  for (int i = 0; i < 3; i++)
	    x[i] = xg(i);
	}

      if (dxdxi)
	{
	  for (int i=0; i<3; i++)
	    {
	      dxdxi[3*i] = dx(i,0);
	      dxdxi[3*i+1] = dx(i,1);
              dxdxi[3*i+2] = dx(i,2);
	    }
	}
    }
}


void Ng_GetSurfaceElementTransformation (int sei, const double * xi, 
					 double * x, double * dxdxi)
{
  if (mesh->GetDimension() == 2)
    {
      Point<3> xg;
      Vec<3> dx;

      // still 1-based arrays
      mesh->GetCurvedElements().CalcSegmentTransformation (xi[0], sei-1, xg, dx);

      if (x)
        for (int i = 0; i < 2; i++)
	  x[i] = xg(i);
	  
      if (dxdxi)
        for (int i=0; i<2; i++)
	  dxdxi[i] = dx(i);

    }
  else
    {
      Point<2> xl(xi[0], xi[1]);
      Point<3> xg;
      Mat<3,2> dx;
      
      // still 1-based arrays
      mesh->GetCurvedElements().CalcSurfaceTransformation (xl, sei-1, xg, dx);
      
      for (int i=0; i<3; i++)
	{
	  if (x)
	    x[i] = xg(i);
	  if (dxdxi)
	    {
	      dxdxi[2*i] = dx(i,0);
	      dxdxi[2*i+1] = dx(i,1);
	    }
	}
    }
}




void Ng_SetRefinementFlag (int ei, int flag)
{
  if (mesh->GetDimension() == 3)
    mesh->VolumeElement(ei).SetRefinementFlag (flag != 0);
  else
    mesh->SurfaceElement(ei).SetRefinementFlag (flag != 0);
}

void Ng_SetSurfaceRefinementFlag (int ei, int flag)
{
  if (mesh->GetDimension() == 3)
    mesh->SurfaceElement(ei).SetRefinementFlag (flag != 0);
}


void Ng_Refine (NG_REFINEMENT_TYPE reftype)
{
  BisectionOptions biopt;
  biopt.usemarkedelements = 1;
  biopt.refine_hp = 0;
  if (reftype == NG_REFINE_P || reftype == NG_REFINE_HP)
    biopt.refine_hp = 1;

  if (geometry && mesh->GetDimension() == 3)
    {
      RefinementSurfaces ref (*geometry);
      ref.Bisect (*mesh, biopt);
    }
  else if (stlgeometry)
    {
      RefinementSTLGeometry ref (*stlgeometry);
      ref.Bisect (*mesh, biopt);
    }
  else if (geometry2d)
    {
      Refinement2d ref (*geometry2d);
      ref.Bisect (*mesh, biopt);
    }
  else
    {
      cout << "No geometry available" << endl;
      Refinement ref;
      ref.Bisect (*mesh, biopt);
    }

  mesh -> UpdateTopology();
}

void Ng_SecondOrder ()
{
  if (stlgeometry)
    {
      RefinementSTLGeometry ref (*stlgeometry);
      ref.MakeSecondOrder (*mesh);
    }

  else if (geometry2d)
    {
      Refinement2d ref (*geometry2d);
      ref.MakeSecondOrder (*mesh);
    }

  else if (geometry && mesh->GetDimension() == 3)

    {
      RefinementSurfaces ref (*geometry);
      ref.MakeSecondOrder (*mesh);
    }
  else
    {
      cout << "no geom" << endl;
      Refinement ref;
      ref.MakeSecondOrder (*mesh);
    }

  mesh -> UpdateTopology();
}

void Ng_HPRefinement (int levels)
{
  HPRefinement (*mesh, levels);
}


void Ng_HighOrder (int order)
{
  Refinement * ref;

  if (stlgeometry)
    ref = new RefinementSTLGeometry (*stlgeometry);
  else if (geometry2d)
    ref = new Refinement2d (*geometry2d);
  else
    ref = new RefinementSurfaces (*geometry);

  // cout << "parameter 1: " << argv[1] << " (conversion to int = " << atoi(argv[1]) << ")" << endl;

  mesh -> GetCurvedElements().BuildCurvedElements (ref, order);

  delete ref;
}












int Ng_ME_GetNVertices (NG_ELEMENT_TYPE et)
{
  switch (et)
    {
    case NG_SEGM:
    case NG_SEGM3:
      return 2;

    case NG_TRIG:
    case NG_TRIG6:
      return 3;

    case NG_QUAD:
      return 4;

    case NG_TET:
    case NG_TET10:
      return 4;

    case NG_PYRAMID:
      return 5;

    case NG_PRISM:
    case NG_PRISM12:
      return 6;

    case NG_HEX:
      return 8;

    default:
      cerr << "Ng_ME_GetNVertices, illegal element type " << et << endl;
    }
  return 0;
}

int Ng_ME_GetNEdges (NG_ELEMENT_TYPE et)
{
  switch (et)
    {
    case NG_SEGM:
    case NG_SEGM3:
      return 1;

    case NG_TRIG:
    case NG_TRIG6:
      return 3;

    case NG_QUAD:
      return 4;

    case NG_TET:
    case NG_TET10:
      return 6;

    case NG_PYRAMID:
      return 8;

    case NG_PRISM:
    case NG_PRISM12:
      return 9;

    case NG_HEX:
      return 12;

    default:
      cerr << "Ng_ME_GetNEdges, illegal element type " << et << endl;
    }
  return 0;
}


int Ng_ME_GetNFaces (NG_ELEMENT_TYPE et)
{
  switch (et)
    {
    case NG_SEGM:
    case NG_SEGM3:
      return 0;

    case NG_TRIG:
    case NG_TRIG6:
      return 1;

    case NG_QUAD:
    case NG_QUAD6:
      return 1;

    case NG_TET:
    case NG_TET10:
      return 4;

    case NG_PYRAMID:
      return 5;

    case NG_PRISM:
    case NG_PRISM12:
      return 5;

    case NG_HEX:
      return 6;

    default:
      cerr << "Ng_ME_GetNVertices, illegal element type " << et << endl;
    }
  return 0;
}


const NG_POINT * Ng_ME_GetVertices (NG_ELEMENT_TYPE et)
{
  static double segm_points [][3] = 
    { { 1, 0, 0 },
      { 0, 0, 0 } };

  static double trig_points [][3] = 
    { { 1, 0, 0 },
      { 0, 1, 0 },
      { 0, 0, 0 } };

  static double quad_points [][3] = 
    { { 0, 0, 0 },
      { 1, 0, 0 },
      { 1, 1, 0 },
      { 0, 1, 0 } };

  static double tet_points [][3] = 
    { { 1, 0, 0 },
      { 0, 1, 0 },
      { 0, 0, 1 },
      { 0, 0, 0 } };

  static double pyramid_points [][3] =
    {
      { 0, 0, 0 },
      { 1, 0, 0 },
      { 1, 1, 0 },
      { 0, 1, 0 },
      { 0, 0, 1-1e-7 },
    };    
  
  static double prism_points[][3] = 
    {
      { 1, 0, 0 },
      { 0, 1, 0 },
      { 0, 0, 0 },
      { 1, 0, 1 },
      { 0, 1, 1 },
      { 0, 0, 1 }
    };

  switch (et)
    {
    case NG_SEGM:
    case NG_SEGM3:
      return segm_points;

    case NG_TRIG:
    case NG_TRIG6:
      return trig_points;

    case NG_QUAD:
    case NG_QUAD6:
      return quad_points;

    case NG_TET:
    case NG_TET10:
      return tet_points;

    case NG_PYRAMID:
      return pyramid_points;

    case NG_PRISM:
    case NG_PRISM12:
      return prism_points;

    case NG_HEX:
    default:
      cerr << "Ng_ME_GetVertices, illegal element type " << et << endl;
    }
  return 0;
}



const NG_EDGE * Ng_ME_GetEdges (NG_ELEMENT_TYPE et)
{
  static int segm_edges[1][2] =
    { { 1, 2 }};

  static int trig_edges[3][2] =
    { { 3, 1 },
      { 3, 2 },
      { 1, 2 }};

  static int quad_edges[4][2] =
    { { 1, 2 },
      { 4, 3 },
      { 1, 4 },
      { 2, 3 }};


  static int tet_edges[6][2] =
    { { 4, 1 },
      { 4, 2 },
      { 4, 3 }, 
      { 1, 2 },
      { 1, 3 },
      { 2, 3 }};

  static int prism_edges[9][2] =
    { { 3, 1 },
      { 1, 2 },
      { 3, 2 },
      { 6, 4 },
      { 4, 5 },
      { 6, 5 },
      { 3, 6 },
      { 1, 4 },
      { 2, 5 }};

  static int pyramid_edges[8][2] =
    { { 1, 2 },
      { 2, 3 },
      { 1, 4 },
      { 4, 3 },
      { 1, 5 },
      { 2, 5 },
      { 3, 5 },
      { 4, 5 }};



  switch (et)
    {
    case NG_SEGM:
    case NG_SEGM3:
      return segm_edges;

    case NG_TRIG:
    case NG_TRIG6:
      return trig_edges;

    case NG_QUAD:
    case NG_QUAD6:
      return quad_edges;

    case NG_TET:
    case NG_TET10:
      return tet_edges;

    case NG_PYRAMID:
      return pyramid_edges;

    case NG_PRISM:
    case NG_PRISM12:
      return prism_edges;

    case NG_HEX:
    default:
      cerr << "Ng_ME_GetEdges, illegal element type " << et << endl;
    }
  return 0;  
}


const NG_FACE * Ng_ME_GetFaces (NG_ELEMENT_TYPE et)
{
  static int tet_faces[4][4] =
    { { 4, 2, 3, 0 },
      { 4, 1, 3, 0 },
      { 4, 1, 2, 0 },
      { 1, 2, 3, 0 } };
  
  static int prism_faces[5][4] =
    {
      { 1, 2, 3, 0 },
      { 4, 5, 6, 0 },
      { 3, 1, 4, 6 },
      { 1, 2, 5, 4 },
      { 2, 3, 6, 5 } 
    };
  
  static int pyramid_faces[5][4] =
    {
      { 1, 2, 5, 0 },
      { 2, 3, 5, 0 },
      { 3, 4, 5, 0 },
      { 4, 1, 5, 0 },
      { 1, 2, 3, 4 } 
    };
  
  static int trig_faces[1][4] = 
    {
      { 1, 2, 3, 0 },
    };

  switch (et)
    {
    case NG_TET:
    case NG_TET10:
      return tet_faces;

    case NG_PRISM:
    case NG_PRISM12:
      return prism_faces;

    case NG_PYRAMID:
      return pyramid_faces;


    case NG_SEGM:
    case NG_SEGM3:

    case NG_TRIG:
    case NG_TRIG6:
      return trig_faces;
    case NG_QUAD:


    case NG_HEX:

    default:
      cerr << "Ng_ME_GetFaces, illegal element type " << et << endl;
    }
  return 0;
}


int Ng_GetNEdges()
{
  return mesh->GetTopology().GetNEdges();
}
int Ng_GetNFaces()
{
  return mesh->GetTopology().GetNFaces();
}



int Ng_GetElement_Edges (int elnr, int * edges, int * orient)
{
  const MeshTopology & topology = mesh->GetTopology();
  if (mesh->GetDimension() == 3)
    return topology.GetElementEdges (elnr, edges, orient);
  else
    return topology.GetSurfaceElementEdges (elnr, edges, orient);
}

int Ng_GetElement_Faces (int elnr, int * faces, int * orient)
{
  const MeshTopology & topology = mesh->GetTopology();
  if (mesh->GetDimension() == 3)
    return topology.GetElementFaces (elnr, faces, orient);
  else
    {
      faces[0] = elnr;
      if (orient) orient[0] = 0;
      return 1;
    }
}

int Ng_GetSurfaceElement_Edges (int elnr, int * edges, int * orient)
{
  const MeshTopology & topology = mesh->GetTopology();
  if (mesh->GetDimension() == 3)
    return topology.GetSurfaceElementEdges (elnr, edges, orient);
  else
    {
      if (orient)
	topology.GetSegmentEdge(elnr, edges[0], orient[0]);
      else
	edges[0] = topology.GetSegmentEdge(elnr);
    }
  return 1;
  /*
    int i, ned;
    const MeshTopology & topology = mesh->GetTopology();
    ARRAY<int> ia;
    topology.GetSurfaceElementEdges (elnr, ia);
    ned = ia.Size();
    for (i = 1; i <= ned; i++)
    edges[i-1] = ia.Get(i);

    if (orient)
    {
    topology.GetSurfaceElementEdgeOrientations (elnr, ia);
    for (i = 1; i <= ned; i++)
    orient[i-1] = ia.Get(i);
    }
    return ned;
  */
}

int Ng_GetSurfaceElement_Face (int selnr, int * orient)
{
  if (mesh->GetDimension() == 3)
    {
      const MeshTopology & topology = mesh->GetTopology();
      if (orient)
	*orient = topology.GetSurfaceElementFaceOrientation (selnr);
      return topology.GetSurfaceElementFace (selnr);
    }
  return -1;
}

int Ng_GetFace_Vertices (int fnr, int * vert)
{
  const MeshTopology & topology = mesh->GetTopology();
  ArrayMem<int,4> ia;
  topology.GetFaceVertices (fnr, ia);
  for (int i = 0; i < ia.Size(); i++)
    vert[i] = ia[i];
  //  cout << "face verts = " << ia << endl;
  return ia.Size();
}


int Ng_GetFace_Edges (int fnr, int * edge)
{
  const MeshTopology & topology = mesh->GetTopology();
  ArrayMem<int,4> ia;
  topology.GetFaceEdges (fnr, ia);
  for (int i = 0; i < ia.Size(); i++)
    edge[i] = ia[i];
  return ia.Size();
}

void Ng_GetEdge_Vertices (int ednr, int * vert)
{
  const MeshTopology & topology = mesh->GetTopology();
  topology.GetEdgeVertices (ednr, vert[0], vert[1]);
}


int Ng_GetElementOrder (int enr)
{
  if (mesh->GetDimension() == 3)
    return mesh->VolumeElement(enr).GetOrder();
  else
    return mesh->SurfaceElement(enr).GetOrder();
}



int Ng_GetNLevels ()
{
  return mesh->mglevels;
}


void Ng_GetParentNodes (int ni, int * parents)
{
  if (ni <= mesh->mlbetweennodes.Size())
    {
      parents[0] = mesh->mlbetweennodes.Get(ni).I1();
      parents[1] = mesh->mlbetweennodes.Get(ni).I2();
    }
  else
    parents[0] = parents[1] = 0;
}


int Ng_GetParentElement (int ei)
{
  if (mesh->GetDimension() == 3)
    {
      if (ei <= mesh->mlparentelement.Size())
	return mesh->mlparentelement.Get(ei);
    }
  else
    {
      if (ei <= mesh->mlparentsurfaceelement.Size())
	return mesh->mlparentsurfaceelement.Get(ei);
    }
  return 0;
}


int Ng_GetParentSElement (int ei)
{
  if (mesh->GetDimension() == 3)
    {
      if (ei <= mesh->mlparentsurfaceelement.Size())
	return mesh->mlparentsurfaceelement.Get(ei);
    }
  else
    {
      return 0;
    }
  return 0;
}





int Ng_GetClusterRepVertex (int pi)
{
  return mesh->GetClusters().GetVertexRepresentant(pi);
}

int Ng_GetClusterRepEdge (int pi)
{
  return mesh->GetClusters().GetEdgeRepresentant(pi);
}

int Ng_GetClusterRepFace (int pi)
{
  return mesh->GetClusters().GetFaceRepresentant(pi);
}

int Ng_GetClusterRepElement (int pi)
{
  return mesh->GetClusters().GetElementRepresentant(pi);
}






void Ng_InitSolutionData (Ng_SolutionData * soldata)
{
  soldata -> name = NULL;
  soldata -> data = NULL;
  soldata -> components = 1;
  soldata -> dist = 1;
  soldata -> order = 1;
  soldata -> iscomplex = 0;
  soldata -> draw_surface = 1;
  soldata -> draw_volume = 1;
  soldata -> soltype = NG_SOLUTION_NODAL;
  soldata -> solclass = 0;
}

void Ng_SetSolutionData (Ng_SolutionData * soldata)
{
  //   vssolution.ClearSolutionData ();
  VisualSceneSolution::SolData * vss = new VisualSceneSolution::SolData;

  //  cout << "Add solution " << soldata->name << ", type = " << soldata->soltype << endl;

  vss->name = new char[strlen (soldata->name)+1];
  strcpy (vss->name, soldata->name);

  vss->data = soldata->data;
  vss->components = soldata->components;
  vss->dist = soldata->dist;
  vss->order = soldata->order;
  vss->iscomplex = bool(soldata->iscomplex);
  vss->draw_surface = soldata->draw_surface;
  vss->draw_volume = soldata->draw_volume;
  vss->soltype = VisualSceneSolution::SolType (soldata->soltype);
  vss->solclass = soldata->solclass;
  vssolution.AddSolutionData (vss);
}


void Ng_Redraw ()
{
  vssolution.UpdateSolutionTimeStamp();
  Render();
}


void Ng_SetVisualizationParameter (const char * name, const char * value)
{
  char buf[100];
  sprintf (buf, "visoptions.%s", name);
  cout << "name = " << name << ", value = " << value << endl;
  cout << "set tcl-variable " << buf << " to " << value << endl;
  Tcl_SetVar (tcl_interp, buf, const_cast<char*> (value), 0);
  Tcl_Eval (tcl_interp, "Ng_Vis_Set parameters;");
}




int firsttime = 1;
int animcnt = 0;
void PlayAnimFile(const char* name, int speed, int maxcnt)
{
  //extern Mesh * mesh;

  /*
  if (mesh.Ptr()) mesh->DeleteMesh();
  if (!mesh.Ptr()) mesh = new Mesh();
  */
  mesh.Reset (new Mesh());

  int ne, np, i, ti;

  char str[80];
  char str2[80];

  //int tend = 5000;
  //  for (ti = 1; ti <= tend; ti++)
  //{
  int rti = (animcnt%(maxcnt-1)) + 1;
  animcnt+=speed;
  
  sprintf(str2,"%05i.sol",rti);
  strcpy(str,"mbssol/");
  strcat(str,name);
  strcat(str,str2);

  cout << "read file '" << str << "'" << endl;
  
  ifstream infile(str);
  infile >> ne;
  for (i = 1; i <= ne; i++)
    {
      int j;
      Element2d tri(3);
      tri.SetIndex(1); //faceind
      
      for (j = 1; j <= 3; j++)
	infile >> tri.PNum(j);

      infile >> np;
      for (i = 1; i <= np; i++)
	{
	  Point3d p;
	  infile >> p.X() >> p.Y() >> p.Z();
	  if (firsttime)
	    mesh->AddPoint (p);
	  else
	    mesh->Point(i)=p;
	}

      //firsttime = 0;
      Ng_Redraw();
   }
}

		
int Ng_GetNPeriodicVertices ()
{
  ARRAY<INDEX_2> apairs;
  mesh->GetIdentifications().GetPairs (0, apairs);
  return apairs.Size();
}


// pairs should be an integer array of 2*npairs
void Ng_GetPeriodicVertices (int * pairs)
{
  ARRAY<INDEX_2> apairs;
  mesh->GetIdentifications().GetPairs (0, apairs);
  for (int i = 0; i < apairs.Size(); i++)
    {
      pairs[2*i] = apairs[i].I1();
      pairs[2*i+1] = apairs[i].I2();
    }
      
	/*<<<<<< nginterface.cpp
      infile >> np;
      for (i = 1; i <= np; i++)
	{
	  Point3d p;
	  infile >> p.X() >> p.Y() >> p.Z();
	  if (firsttime)
	    mesh->AddPoint (p);
	  else
	    mesh->Point(i)=p;
	}

      //firsttime = 0;
      Ng_Redraw();
      //}
}

		
int Ng_GetNPeriodicVertices ()
{
  ARRAY<INDEX_2> apairs;
  mesh->GetIdentifications().GetPairs (0, apairs);
  return apairs.Size();
}


// pairs should be an integer array of 2*npairs
void Ng_GetPeriodicVertices (int * pairs)
{
  ARRAY<INDEX_2> apairs;
  mesh->GetIdentifications().GetPairs (0, apairs);
  for (int i = 0; i < apairs.Size(); i++)
    {
      pairs[2*i] = apairs[i].I1();
      pairs[2*i+1] = apairs[i].I2();
    }
=======
      if (firsttime)
	mesh->AddSurfaceElement (tri);
    }
  
  infile >> np;
  for (i = 1; i <= np; i++)
    {
      Point3d p;
      infile >> p.X() >> p.Y() >> p.Z();
      if (firsttime)
	mesh->AddPoint (p);
      else
	mesh->Point(i)=p;
    }
  
  //firsttime = 0;
  Ng_Redraw();
>>>>>>> 1.9 
*/
}


