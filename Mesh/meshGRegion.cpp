#include "meshGRegion.h"
#include "GRegion.h"
#include "GFace.h"
#include "BDS.h"
#include "Message.h"
#include <vector>

void getAllBoundingVertices (GRegion *gr, int importVolumeMesh, std::set<MVertex*> &allBoundingVertices )
{
  std::list<GFace*> faces = gr->faces();
  std::list<GFace*>::iterator it = faces.begin();

  if (importVolumeMesh)
    allBoundingVertices.insert ( gr->mesh_vertices.begin() , gr->mesh_vertices.end() );
  
  while (it != faces.end())
    {
      GFace *gf = (*it);      
      for (int i = 0; i< gf->triangles.size(); i++)
	{
	  MTriangle *t = gf->triangles[i];
	  allBoundingVertices.insert (t->getVertex(0));
	  allBoundingVertices.insert (t->getVertex(1));
	  allBoundingVertices.insert (t->getVertex(2));
	}
      ++it;
    }
}


#if defined(HAVE_TETGEN)
#include "tetgen.h"
void buildTetgenStructure (  GRegion *gr, tetgenio &in, std::vector<MVertex*> & numberedV)
{

  std::set<MVertex*> allBoundingVertices;
  getAllBoundingVertices (gr, 0, allBoundingVertices );

  in.mesh_dim = 3;
  in.firstnumber = 1;
  
  in.numberofpoints = allBoundingVertices.size();
  in.pointlist = new REAL[in.numberofpoints * 3];
  in.pointmarkerlist = NULL;

  std::set<MVertex*>::iterator itv =  allBoundingVertices.begin();
  int I=1;
  while (itv != allBoundingVertices.end())
    {
      in.pointlist[(I-1)*3 + 0] = (*itv)->x();
      in.pointlist[(I-1)*3 + 1] = (*itv)->y();
      in.pointlist[(I-1)*3 + 2] = (*itv)->z();
      (*itv)->setNum(I++);
      numberedV.push_back(*itv);
      ++itv;
    }
  
  int nbFace = 0;

  std::list<GFace*> faces = gr->faces();
  std::list<GFace*>::iterator it = faces.begin();
  while (it != faces.end())
    {
      GFace *gf = (*it);
      nbFace += gf->triangles.size();
      ++it;
    }

  Msg(INFO,"%d model faces -- NumFaces = %d",nbFace,faces.size());

  in.numberoffacets = nbFace;
  in.facetlist = new tetgenio::facet[in.numberoffacets];
  in.facetmarkerlist = new int[in.numberoffacets];

  it = faces.begin();
  I= 0;
  while (it != faces.end())
    {
      GFace *gf = (*it);
      for (int i = 0; i< gf->triangles.size(); i++)
	{
	  MTriangle *t = gf->triangles[i];
	  tetgenio::facet *f = &in.facetlist[I];
	  tetgenio::init(f);    
	  f->numberofholes = 0;
	  f->numberofpolygons = 1;
	  tetgenio::polygon *p = f->polygonlist = new tetgenio::polygon[f->numberofpolygons];
	  tetgenio::init(p);    
	  p->numberofvertices = 3;
	  p->vertexlist = new int[p->numberofvertices];
	  p->vertexlist[0] = t->getVertex(0)->getNum();
	  p->vertexlist[1] = t->getVertex(1)->getNum();
	  p->vertexlist[2] = t->getVertex(2)->getNum();
	  //	  Msg(INFO,"Faces %d = %d %d %d",I,p->vertexlist[0] ,p->vertexlist[1] ,p->vertexlist[2] );
	  in.facetmarkerlist[I] = gf->tag();	  
	  ++I;
	}
      ++it;
    }   
}

void TransferTetgenMesh(GRegion *gr, tetgenio &in, tetgenio &out, std::vector<MVertex*> & numberedV)
{
  int I = numberedV.size() + 1;
  for (int i = 0; i < out.numberofpoints; i++) 
    {
      MVertex *v = new MVertex (out.pointlist[i * 3 + 0],out.pointlist[i * 3 + 1],out.pointlist[i * 3 + 2]); 
      gr->mesh_vertices.push_back(v);
      numberedV.push_back(v);
    }
 
  for (int i = 0; i < out.numberoftetrahedra; i++) {
    MVertex *v1 = numberedV[out.tetrahedronlist[i * 4 + 0] -1];
    MVertex *v2 = numberedV[out.tetrahedronlist[i * 4 + 1] -1];
    MVertex *v3 = numberedV[out.tetrahedronlist[i * 4 + 2] -1];
    MVertex *v4 = numberedV[out.tetrahedronlist[i * 4 + 3] -1];
    MTetrahedron *t = new  MTetrahedron(v1,v2,v3,v4);
    gr->tetrahedra.push_back(t);
  }

 
}
  

#endif


#if defined(HAVE_NETGEN)
namespace nglib {
#include "nglib.h"
#include "nglib_addon.h"
}
using namespace nglib;

Ng_Mesh * buildNetgenStructure (GRegion *gr, int importVolumeMesh, std::vector<MVertex*> & numberedV)
{
  NgAddOn_Init();
  Ng_Mesh *_ngmesh = Ng_NewMesh();

  std::set<MVertex*> allBoundingVertices;
  getAllBoundingVertices (gr, importVolumeMesh, allBoundingVertices );
  
  std::set<MVertex*>::iterator itv =  allBoundingVertices.begin();
  int I=1;
  while (itv != allBoundingVertices.end())
    {
      double tmp[3];
      tmp[0] = (*itv)->x();
      tmp[1] = (*itv)->y();
      tmp[2] = (*itv)->z();
      (*itv)->setNum(I++);
      numberedV.push_back(*itv);
      Ng_AddPoint(_ngmesh, tmp);
      ++itv;
    }
  
  std::list<GFace*> faces = gr->faces();
  std::list<GFace*>::iterator it = faces.begin();
  while (it != faces.end())
    {
      GFace *gf = (*it);      
      for (int i = 0; i< gf->triangles.size(); i++)
	{
	  MTriangle *t = gf->triangles[i];
	  int tmp[3];
	  tmp[0] = t->getVertex(0)->getNum();
	  tmp[1] = t->getVertex(1)->getNum();
	  tmp[2] = t->getVertex(2)->getNum();	  
	  Ng_AddSurfaceElement(_ngmesh, NG_TRIG, tmp);
	}
      ++it;
    }

  if (importVolumeMesh)
    {
      for (int i = 0; i< gr->tetrahedra.size(); i++)
	{
	  MTetrahedron *t = gr->tetrahedra[i];
	  int tmp[4];
	  tmp[0] = t->getVertex(0)->getNum();
	  tmp[1] = t->getVertex(1)->getNum();
	  tmp[2] = t->getVertex(2)->getNum();	  
	  tmp[3] = t->getVertex(2)->getNum();	  
	  Ng_AddVolumeElement(_ngmesh, NG_TET, tmp);
	}
    }

  return _ngmesh;
}

void TransferVolumeMesh(GRegion *gr, Ng_Mesh * _ngmesh, std::vector<MVertex*> &numberedV)
{
  // Gets total number of vertices of Netgen's mesh
  int nbv = Ng_GetNP(_ngmesh);  
  if(!nbv) return;

  int nbpts = numberedV.size();

  // Create new volume vertices
  for(int i = nbpts; i < nbv; i++) 
    {
      double tmp[3];
      Ng_GetPoint(_ngmesh, i+1, tmp);
      MVertex *v = new MVertex (tmp[0],tmp[1],tmp[2]);
      numberedV.push_back(v);
      gr->mesh_vertices.push_back(v);
    }
  
  // Get total number of simplices of Netgen's mesh
  int nbe = Ng_GetNE(_ngmesh);
  
  // Create new volume simplices
  for(int i = 0; i < nbe; i++) {
    int tmp[4];
    Ng_GetVolumeElement(_ngmesh, i+1, tmp);
    MTetrahedron *t = new MTetrahedron  ( numberedV [tmp[0]-1],
					  numberedV [tmp[1]-1],
					  numberedV [tmp[2]-1],
					  numberedV [tmp[3]-1]);
    gr->tetrahedra.push_back(t);
  }  
}
#endif

void deMeshGRegion :: operator() (GRegion *gr) 
{
  for (unsigned int i=0;i<gr->mesh_vertices.size();i++) delete gr->mesh_vertices[i];
  gr->mesh_vertices.clear();
  for (unsigned int i=0;i<gr->tetrahedra.size();i++) delete gr->tetrahedra[i];
  gr->tetrahedra.clear();
  for (unsigned int i=0;i<gr->hexahedra.size();i++) delete gr->hexahedra[i];
  gr->hexahedra.clear();
  for (unsigned int i=0;i<gr->prisms.size();i++) delete gr->prisms[i];
  gr->prisms.clear();
  for (unsigned int i=0;i<gr->pyramids.size();i++) delete gr->pyramids[i];
  gr->pyramids.clear();
}

int intersect_line_triangle ( double X[3],
			      double Y[3],
			      double Z[3] , 
			      double P[3], 
			      double N[3] )
{
  double mat[3][3], det;
  double b[3], res[3];
  const double eps_prec = 1.e-5;

  mat[0][0] = X[1] - X[0];
  mat[0][1] = X[2] - X[0];
  mat[0][2] = N[0];

  mat[1][0] = Y[1] - Y[0];
  mat[1][1] = Y[2] - Y[0];
  mat[1][2] = N[1];

  mat[2][0] = Z[1] - Z[0];
  mat[2][1] = Z[2] - Z[0];
  mat[2][2] = N[2];

  b[0] = P[0] - X[0];
  b[1] = P[1] - Y[0];
  b[2] = P[2] - Z[0];

  if(!sys3x3_with_tol(mat, b, res, &det))       
    return 0;

  //  Msg(INFO,"going there %g %g %g",res[0],res[1],res[2]);

  if(res[0] >=  eps_prec && res[0] <=  1.0 - eps_prec && 
     res[1] >=  eps_prec && res[1] <=  1.0 - eps_prec && 
     1-res[0]-res[1] >=  eps_prec && 1-res[0]-res[1] <=  1.0 - eps_prec )
    {
      // the line clearly intersects the triangle
      return (res[2] > 0) ? 1 : 0;
    }
  else if (res[0] <  -eps_prec || res[0] >   1.0 + eps_prec || 
	   res[1] <  -eps_prec || res[1] >   1.0 + eps_prec || 
	   1-res[0]-res[1] <  -eps_prec || 1-res[0]-res[1] >  1.0 + eps_prec )
    {
      // the line clearly does NOT intersect the triangle
      return 0;
    }
  else
    {
      // the intersection is not robust, try another triangle
      return -10000;
    }

}


void meshNormalsPointOutOfTheRegion (GRegion *gr) 
{
  std::list<GFace*> faces = gr->faces();
  std::list<GFace*>::iterator it = faces.begin();
  while (it != faces.end())
    {
      GFace *gf = (*it);      
      int nb_intersect = 0;
      for (int i = 0; i< gf->triangles.size(); i++)
	{
	  MTriangle *t = gf->triangles[i];
	  double X[3] = {t->getVertex(0)->x(),t->getVertex(1)->x(),t->getVertex(2)->x()};
	  double Y[3] = {t->getVertex(0)->y(),t->getVertex(1)->y(),t->getVertex(2)->y()};
	  double Z[3] = {t->getVertex(0)->z(),t->getVertex(1)->z(),t->getVertex(2)->z()};
	  double P[3] = {(X[0]+X[1]+X[2])/3.,(Y[0]+Y[1]+Y[2])/3.,(Z[0]+Z[1]+Z[2])/3.};
	  double v1[3] = {X[0]-X[1],Y[0]-Y[1],Z[0]-Z[1]};
	  double v2[3] = {X[2]-X[1],Y[2]-Y[1],Z[2]-Z[1]};
	  double N[3] ;
	  prodve ( v1, v2 , N );
	  norme (v1);
	  norme (v2);
	  norme(N);
	  N[0]+= 0.05*v1[0]-0.05*v2[0];
	  N[1]+= 0.03*v1[1]-0.15*v2[1];
	  N[2]+= 0.05*v1[2]-0.05*v2[2];
	  norme(N);
	  std::list<GFace*>::iterator it_b = faces.begin();
	  while (it_b != faces.end())
	    {
	      GFace *gf_b = (*it_b);
	      for (int i_b = 0; i_b< gf_b->triangles.size(); i_b++)
		{
		  MTriangle *t_b = gf_b->triangles[i_b];
		  if (t_b != t)
		    {
		      double X_b[3] = {t_b->getVertex(0)->x(),t_b->getVertex(1)->x(),t_b->getVertex(2)->x()};
		      double Y_b[3] = {t_b->getVertex(0)->y(),t_b->getVertex(1)->y(),t_b->getVertex(2)->y()};
		      double Z_b[3] = {t_b->getVertex(0)->z(),t_b->getVertex(1)->z(),t_b->getVertex(2)->z()};
		      int inters = intersect_line_triangle ( X_b,Y_b,Z_b,P,N );
		      nb_intersect += inters;
		    }
		}
	      ++it_b;
	    }
	  Msg (INFO,"Region %d Face %d, %d intersect",gr->tag(),gf->tag(),nb_intersect);
	  if (nb_intersect >= 0) break; // negative value means intersetcion is not "robust"
	}


      if (nb_intersect % 2 == 1) // odd nb of intersections: the normal points inside the region 
	{
	  for (int i = 0; i< gf->triangles.size(); i++)
	    {
	      gf->triangles[i]->revert();
	    }
	}
      ++it;
    }
}



void meshGRegion :: operator() (GRegion *gr) 
{  
  if(gr->geomType() == GEntity::DiscreteVolume) return;

  // destroy the mesh if it exists
  deMeshGRegion dem;
  dem(gr);

  // Send a messsage to the GMSH environment
  Msg(STATUS2, "Meshing volume %d", gr->tag());

  // orient the triangles of with respect to this region
  meshNormalsPointOutOfTheRegion (gr); 
  
  if(CTX.mesh.algo3d == DELAUNAY_TETGEN)
    {
#if !defined(HAVE_TETGEN)
    Msg(GERROR, "Tetgen is not compiled in this version of Gmsh");
#else
    tetgenio in, out;
    std::vector<MVertex*> numberedV;
    char opts[128];
    buildTetgenStructure (  gr, in, numberedV);
    sprintf(opts, "pq1.4Ya%f%c", (float)CTX.mesh.quality, 
	    (CTX.verbosity < 3)? 'Q': (CTX.verbosity > 6)? 'V': '\0');
    Msg(STATUS2, "Meshing with volume constraint %f", (float)CTX.mesh.quality);
    tetrahedralize(opts, &in, &out);
    TransferTetgenMesh(gr, in, out, numberedV);
#endif
    }

  if(CTX.mesh.algo3d == FRONTAL_NETGEN)
    {
#if !defined(HAVE_NETGEN)
    Msg(GERROR, "Netgen is not compiled in this version of Gmsh");
#else
    std::vector<MVertex*> numberedV;
    Ng_Mesh * _ngmesh = buildNetgenStructure (gr, 0, numberedV);
    Ng_Meshing_Parameters mp;
    mp.maxh = 1;
    mp.fineness = 1;
    mp.secondorder = 0;
    NgAddOn_GenerateVolumeMesh(_ngmesh, &mp); // does not optimize
    TransferVolumeMesh(gr, _ngmesh, numberedV);
    Ng_DeleteMesh(_ngmesh);
    Ng_Exit();
#endif
    }
}
