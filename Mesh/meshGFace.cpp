#include "meshGFace.h"
#include "GVertex.h"
#include "2D_Mesh.h"
#include "GEdge.h"
#include "GFace.h"
#include "MVertex.h"
#include "Context.h"
#include "Utils.h"
#include "GPoint.h"
#include "Message.h"
#include "Numeric.h"
#include "BDS.h"

#if defined(HAVE_GSL)
#include <gsl/gsl_vector.h>
#include <gsl/gsl_linalg.h>
#else
#define NRANSI
#include "nrutil.h"
void dsvdcmp(double **a, int m, int n, double w[], double **v);
#endif

/*
  Le concept d'un plan moyen calcule au sens des moidres carres n'est
  pas le bon pour les surfaces non-planes : imagine un quart de cercle
  extrude d'une faible hauteur. Le plan moyen sera dans le plan du
  cercle! En attendant mieux, il y a donc un test de coherence
  supplementaire pour les surfaces non-planes. */



int Orientation (std::vector<MVertex*> &cu)
{
  int N, i, a, b, c;
  double cosa, sina, sum, v[3], w[3], u[3];
  MVertex *ver[3];
  double n[3] = {0,0,1};

  N = cu.size();

  sum = 0.0;
  for(i = 0; i < N; i++) {
    if(i == N - 1) {
      a = N - 1;
      b = 1;
      c = 2;
    }
    else if(i == N - 2) {
      a = N - 2;
      b = N - 1;
      c = 1;
    }
    else {
      a = i;
      b = i + 1;
      c = i + 2;
    }
    ver[0] = cu[a];
    ver[1] = cu[b];
    ver[2] = cu[c];

    u[0] = ver[1]->x() - ver[0]->x();
    u[1] = ver[1]->y() - ver[0]->y();
    u[2] = ver[1]->z() - ver[0]->z();

    v[0] = ver[2]->x() - ver[1]->x();
    v[1] = ver[2]->y() - ver[1]->y();
    v[2] = ver[2]->z() - ver[1]->z();
    norme(u);
    norme(v);
    prodve(u, v, w);
    prosca(w, n, &sina);
    prosca(u, v, &cosa);
    sum += myatan2(sina, cosa);
  }

  if(sum < 0)
    return (1);
  else
    return (0);
}



extern Context_T CTX;

class fromCartesianToParametric
{
  GFace *gf;
public :
  fromCartesianToParametric ( GFace *_gf )  
    : gf(_gf){}
  void operator () (MVertex * v)
  {
    SPoint2 param =  gf->parFromPoint (SPoint3(v->x(),v->y(),v->z()));
    v->x() = param.x();  
    v->y() = param.y();
    v->z() = 0.0;
  }
};

class fromParametricToCartesian
{
  GFace *gf;
public :
  fromParametricToCartesian ( GFace *_gf )  
    : gf(_gf){}
  void operator () (MVertex * v)
  {
    GPoint coords =  gf->point (SPoint2(v->x(),v->y()));
    v->x() = coords.x();  
    v->y() = coords.y();
    v->z() = coords.z();
  } 
};


void computeEdgeLoops (const GFace *gf,
		       std::vector<MVertex*> & all_mvertices,
		       std::vector<int> &indices)
{
  {
    std::list<GEdge*> edges = gf->edges();
    std::list<int> ori   = gf->orientations();
    std::list<GEdge*>::iterator it = edges.begin();
    std::list<int>::iterator ito    = ori.begin();
    
    indices.push_back(0);
    GVertex *start = ((*ito) == 1) ? (*it)->getBeginVertex() : (*it)->getEndVertex();
    GVertex *v_end = ((*ito) != 1) ? (*it)->getBeginVertex() : (*it)->getEndVertex();
    all_mvertices.push_back(start->mesh_vertices[0]);
    if (*ito == 1)
      for (int i=0;i<(*it)->mesh_vertices.size();i++)
	all_mvertices.push_back((*it)->mesh_vertices[i]);
    else
      for (int i=(*it)->mesh_vertices.size()-1;i>=0;i--)
	all_mvertices.push_back((*it)->mesh_vertices[i]);

    GVertex *v_start = start;
    while(1)
      {		
	++it;
	++ito;
	if (v_end == start)
	  {
	    indices.push_back(all_mvertices.size());
	    if (it == edges.end ())break;
	    start = ((*ito) == 1) ? (*it)->getBeginVertex() : (*it)->getEndVertex();
	    v_end = ((*ito) != 1) ? (*it)->getBeginVertex() : (*it)->getEndVertex();
	    v_start = start;
	  }
	else
	  {	
	    if (it == edges.end ())throw;
	    v_start = ((*ito) == 1) ? (*it)->getBeginVertex() : (*it)->getEndVertex();
	    if(v_start != v_end)throw;
	    v_end = ((*ito) != 1) ? (*it)->getBeginVertex() : (*it)->getEndVertex();
	  }
	all_mvertices.push_back(v_start->mesh_vertices[0]);
	if (*ito == 1)
	  for (int i=0;i<(*it)->mesh_vertices.size();i++)
	    all_mvertices.push_back((*it)->mesh_vertices[i]);
	else
	  for (int i=(*it)->mesh_vertices.size()-1;i>=0;i--)
	    all_mvertices.push_back((*it)->mesh_vertices[i]);
      }
  }  

}

void MeanPlane_bis(GFace *gf, const std::vector<MVertex*> &points)
{

  int i, j, min, ndata, na;
  double res[4], ex[3], t1[3], t2[3], svd[3];
  Vertex *v;
  double xm = 0., ym = 0., zm = 0.;

  ndata = points.size();
  na = 3;
  for(i = 0; i < ndata; i++) {
    xm += points[i]->x();
    ym += points[i]->y();
    zm += points[i]->z();
  }
  xm /= (double)ndata;
  ym /= (double)ndata;
  zm /= (double)ndata;

#if defined(HAVE_GSL)
  gsl_matrix *U = gsl_matrix_alloc(ndata, na);
  gsl_matrix *V = gsl_matrix_alloc(na, na);
  gsl_vector *W = gsl_vector_alloc(na);
  gsl_vector *TMPVEC = gsl_vector_alloc(na);
  for(i = 0; i < ndata; i++) {
    gsl_matrix_set(U, i, 0, points[i]->x() - xm);
    gsl_matrix_set(U, i, 1, points[i]->y() - ym);
    gsl_matrix_set(U, i, 2, points[i]->z() - zm);
  }
  gsl_linalg_SV_decomp(U, V, W, TMPVEC);
  svd[0] = gsl_vector_get(W, 0);
  svd[1] = gsl_vector_get(W, 1);
  svd[2] = gsl_vector_get(W, 2);
  if(fabs(svd[0]) < fabs(svd[1]) && fabs(svd[0]) < fabs(svd[2]))
    min = 0;
  else if(fabs(svd[1]) < fabs(svd[0]) && fabs(svd[1]) < fabs(svd[2]))
    min = 1;
  else
    min = 2;
  res[0] = gsl_matrix_get(V, 0, min);
  res[1] = gsl_matrix_get(V, 1, min);
  res[2] = gsl_matrix_get(V, 2, min);
  norme(res);
  gsl_matrix_free(U);
  gsl_matrix_free(V);
  gsl_vector_free(W);
  gsl_vector_free(TMPVEC);
#else
  double **U = dmatrix(1, ndata, 1, na);
  double **V = dmatrix(1, na, 1, na);
  double *W = dvector(1, na);
  for(i = 0; i < ndata; i++) {
    U[i + 1][1] = points[i]->x() - xm;
    U[i + 1][2] = points[i]->y() - ym;
    U[i + 1][3] = points[i]->z() - zm;
  }
  dsvdcmp(U, ndata, na, W, V);
  if(fabs(W[1]) < fabs(W[2]) && fabs(W[1]) < fabs(W[3]))
    min = 1;
  else if(fabs(W[2]) < fabs(W[1]) && fabs(W[2]) < fabs(W[3]))
    min = 2;
  else
    min = 3;
  svd[0] = W[1];
  svd[1] = W[2];
  svd[2] = W[3];
  res[0] = V[1][min];
  res[1] = V[2][min];
  res[2] = V[3][min];
  norme(res);
  free_dmatrix(U, 1, ndata, 1, na);
  free_dmatrix(V, 1, na, 1, na);
  free_dvector(W, 1, na);
#endif

  // check coherence of results for non-plane surfaces
  if(gf->geomType() != GEntity::Plane) {
    double res2[3], c[3], cosc, sinc, angplan;
    double eps = 1.e-3;

    GPoint v1 = gf->point( 0.5, 0.5);
    GPoint v2 = gf->point( 0.5 + eps, 0.5);
    GPoint v3 = gf->point( 0.5, 0.5 + eps);
    t1[0] = v2.x() - v1.x();
    t1[1] = v2.y() - v1.y();
    t1[2] = v2.z() - v1.z();
    t2[0] = v3.x() - v1.x();
    t2[1] = v3.y() - v1.y();
    t2[2] = v3.z() - v1.z();
    norme(t1);
    norme(t2);
    // prodve(t1, t2, res2);
    // Warning: the rest of the code assumes res = t2 x t1, not t1 x t2 (WTF?)
    prodve(t2, t1, res2); 
    norme(res2);
    prodve(res, res2, c);
    prosca(res, res2, &cosc);
    sinc = sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
    angplan = myatan2(sinc, cosc);
    angplan = angle_02pi(angplan) * 180. / Pi;
    if((angplan > 70 && angplan < 110) || (angplan > 260 && angplan < 280)) {
      Msg(INFO, "SVD failed (angle=%g): using rough algo...", angplan);
      res[0] = res2[0];
      res[1] = res2[1];
      res[2] = res2[2];
      goto end;
    }
  }

  ex[0] = ex[1] = ex[2] = 0.0;
  if(res[0] == 0.)
    ex[0] = 1.0;
  else if(res[1] == 0.)
    ex[1] = 1.0;
  else
    ex[2] = 1.0;

  prodve(res, ex, t1);
  norme(t1);
  prodve(t1, res, t2);
  norme(t2);

end:
  res[3] = (xm * res[0] + ym * res[1] + zm * res[2]);

  for(i = 0; i < 3; i++)
    gf->mp.plan[0][i] = t1[i];
  for(i = 0; i < 3; i++)
    gf->mp.plan[1][i] = t2[i];
  for(i = 0; i < 3; i++)
    gf->mp.plan[2][i] = res[i];

  gf->mp.a = res[0];
  gf->mp.b = res[1];
  gf->mp.c = res[2];
  gf->mp.d = res[3];

  gf->mp.x=gf->mp.y=gf->mp.z=0;
  if (fabs(gf->mp.a) >= fabs(gf->mp.b) && fabs(gf->mp.a) >= fabs(gf->mp.c) )
    {
      gf->mp.x = gf->mp.d/gf->mp.a;
    }
  else if (fabs(gf->mp.b) >= fabs(gf->mp.a) && fabs(gf->mp.b) >= fabs(gf->mp.c) )
    {
      gf->mp.y = gf->mp.d/gf->mp.b;
    }
  else
    {
      gf->mp.z = gf->mp.d/gf->mp.c;
    }
  

  Msg(DEBUG1, "Surface: %d", gf->tag());
  Msg(DEBUG2, "SVD    : %g,%g,%g (min=%d)", svd[0], svd[1], svd[2], min);
  Msg(DEBUG2, "Plane  : (%g x + %g y + %g z = %g)", gf->mp.a, gf->mp.b, gf->mp.c, gf->mp.d);
  Msg(DEBUG2, "Normal : (%g , %g , %g )", gf->mp.a, gf->mp.b, gf->mp.c);
  Msg(DEBUG3, "t1     : (%g , %g , %g )", t1[0], t1[1], t1[2]);
  Msg(DEBUG3, "t2     : (%g , %g , %g )", t2[0], t2[1], t2[2]);
  Msg(DEBUG3, "pt     : (%g , %g , %g )", gf->mp.x, gf->mp.y, gf->mp.z);

  //check coherence for plane surfaces
  if(gf->geomType() == GEntity::Plane) {
    std::list<GVertex*> verts = gf->vertices();
    std::list<GVertex*>::const_iterator itv = verts.begin();
    
    for (;itv!=verts.end();itv++)
      {
	const GVertex *v = *itv; 
	double d =
	  gf->mp.a * v->x() + gf->mp.b * v->y() + gf->mp.c * v->z() - gf->mp.d;
	if(fabs(d) > CTX.lc * 1.e-3) {
	  Msg(GERROR1, "Plane surface %d (%gx+%gy+%gz+%g=0) is not plane!",
	      v->tag(), gf->mp.a, gf->mp.b, gf->mp.c, gf->mp.d);
	  Msg(GERROR3, "Control point %d = (%g,%g,%g), val=%g",
	      v->tag(), v->x(), v->y(), v->z(), d);
	  return;
	}
      }
  }
}


void computeEdgeParameters ( double x1, double y1, double x2, double y2, GFace *gf , const int numberOfTestPoints, double &coordMiddle, double &edgeLength )
{
  std::vector<GPoint> pts;
  for (int i=0;i<numberOfTestPoints;++i)
    {
      double xi = (double)i/(double)(numberOfTestPoints-1);
      double u = x1 * (1-xi) + x2 * xi;
      double v = y1 * (1-xi) + y2 * xi;
      pts.push_back(gf->point(u,v));      
    } 
  edgeLength = 0;
  for (int i=1;i<numberOfTestPoints;++i)
    {
      GPoint p1 = pts[i-1];
      GPoint p2 = pts[i];
      edgeLength += sqrt ( (p1.x() - p2.x())*(p1.x() - p2.x()) +
			   (p1.y() - p2.y())*(p1.y() - p2.y()) +
			   (p1.z() - p2.z())*(p1.z() - p2.z()) );			   
    }
  double ll = 0;
  for (int i=1;i<numberOfTestPoints;++i)
    {
      double xi = (double)(i-1)/(double)(numberOfTestPoints-1);
      GPoint p1 = pts[i-1];
      GPoint p2 = pts[i];

      double oldll = ll;

      ll += sqrt ( (p1.x() - p2.x())*(p1.x() - p2.x()) +
		   (p1.y() - p2.y())*(p1.y() - p2.y()) +
		   (p1.z() - p2.z())*(p1.z() - p2.z()) );			   

      if (oldll <= 0.5*edgeLength && ll >= 0.5*edgeLength)
	{
	  double xi2 = (0.5*edgeLength - oldll)/(ll-oldll);
	  coordMiddle = xi + xi2/ (double)(numberOfTestPoints-1);
	  return;
	}  
    }  
}

double computeEdgeLinearLength ( BDS_Edge*e, BDS_Point *p1,BDS_Point *p2, std::map<BDS_Point*,BDS_Pos> &realCoordinates)
{
  if (e && e->target_length > 0) return e->target_length;

  const BDS_Pos & x1 = realCoordinates [p1]; 
  const BDS_Pos & x2 = realCoordinates [p2];
  const double l = sqrt ((x1.X-x2.X)*(x1.X-x2.X) +(x1.Y-x2.Y)*(x1.Y-x2.Y) +(x1.Z-x2.Z)*(x1.Z-x2.Z));
  if (e) e->target_length = l;
  return l;
}

bool edgeSwapTest(BDS_Edge *e, GFace *gf, std::map<BDS_Point*,BDS_Pos> &realCoordinates)
{
  BDS_Point *op[2];

  if (e->numfaces() != 2)return false;

  e->oppositeof (op);
  
  double coordMiddle, edgeLength1, edgeLength2;


  edgeLength1 = computeEdgeLinearLength ( e,e->p1,e->p2,realCoordinates);
  edgeLength2 = computeEdgeLinearLength ( 0,op[0],op[1],realCoordinates);
   /*
  computeEdgeParameters ( e->p1->X,
			  e->p1->Y,
			  e->p2->X,
			  e->p2->Y,
			  gf , 2, coordMiddle, edgeLength1 );

  computeEdgeParameters ( op[0]->X,
			  op[0]->Y,
			  op[1]->X,
			  op[1]->Y,
			  gf , 2, coordMiddle, edgeLength2 );
   */
  double el1 = 2*edgeLength1 / ( e->p1->radius_of_curvature +e->p2->radius_of_curvature );
  double el2 = 2*edgeLength2 / ( op[0]->radius_of_curvature + op[1]->radius_of_curvature );

  double q1  = fabs (1-el1);
  double q2  = fabs (1-el2);

  return q2 < 0.5*q1;

}



void NewMeshGenerator ( GFace *gf,
			const std::vector<MVertex*> &points,
			const std::vector<int> &indices)
{
  BDS_Mesh m;
  std::map<MVertex*,int> numPoints;
  std::map<BDS_Point*,BDS_Pos> realCoordinates;
  int NUMP = 0;

  // fill the initial BDS Structure

  int nbEdgeLoops = indices.size()-1;
  for(int i = 0; i < nbEdgeLoops; i++) {
    int nbPtsOnEdgeLoop = indices[i+1] -indices[i];
    for(int j = indices[i]; j < indices[i+1]; j++) {
      MVertex *here     = points[j];
      MVertex *previous = (j == indices[i])?points[indices[i+1]-1] : points[j-1]; 
      MVertex *next     = (j == indices[i+1]-1)?points[indices[i]] : points[j+1];

      double coordMiddle, edgeLength1, edgeLength2;
      computeEdgeParameters ( here->x(),here->y(), previous->x(),previous->y() , gf , 2, coordMiddle, edgeLength1 );
      computeEdgeParameters ( here->x(),here->y(), next->x(), next->y(), gf, 2, coordMiddle, edgeLength2 );
      double lc = 0.5 * (edgeLength1+edgeLength2);
      BDS_Point *bds_p = m.add_point ( NUMP, here->x(), here->y(), here->z());
      GPoint gp = gf->point (here->x(), here->y());
      realCoordinates[bds_p] = BDS_Pos(gp.x(),gp.y(),gp.z());
      numPoints[here]=NUMP++;
      bds_p->radius_of_curvature = lc;
    }
  }
  // will not work correctly if points are present initially inside
  // the domain.
  for (int i=0;i<gf->mesh_vertices.size();++i)
    {
      MVertex *p = gf->mesh_vertices[i];
      m.add_point ( NUMP, p->x(), p->y(), p->z());
      numPoints[p]=NUMP++;
    }
  for (int i=0;i<gf->triangles.size();i+=3)
    {
      MVertex *p0 = gf->triangles[i];
      MVertex *p1 = gf->triangles[i+1];
      MVertex *p2 = gf->triangles[i+2];
      m.add_triangle ( numPoints[p0], numPoints[p1], numPoints[p2] );
    }

  // add points to the surface ...
  const double  errGeomTresh  = 0.02;
  int IT =0;
  while (1)
    {
      std::list<BDS_Edge *> temp (m.edges);
      std::list<BDS_Edge*>::iterator it = temp.begin();
      int NB_MODIF = 0;
      while (it != temp.end())
	{
	  const int numberOfTestPoints = 8;
	  double coordMiddle=0.5, trueLength,linearLength;
	  /*	  computeEdgeParameters ( (*it)->p1->X,
				  (*it)->p1->Y,
				  (*it)->p2->X,
				  (*it)->p2->Y,
				  gf , numberOfTestPoints, coordMiddle, trueLength );*/
	  linearLength = computeEdgeLinearLength ( (*it),(*it)->p1,
						   (*it)->p2,realCoordinates);
	  

	  double l_wanted = 0.5*((*it)->p1->radius_of_curvature + (*it)->p2->radius_of_curvature);

	  //double errGeom = fabs(trueLength - linearLength)/linearLength;
	  double errGeom = 0;
	  
	  //	  Msg(INFO,"le = %g lex = %g err %g",linearLength,trueLength,errGeom);
	  //	  if ((*it)->numfaces() == 2 && (  > 1000 || edgeLength > 1.4 * l_wanted))
	  if ((*it)->numfaces() == 2 && (linearLength > 1.4 * l_wanted || errGeom > errGeomTresh *1.4))
	    {
	      BDS_Point *ppp = m.split_edge ( *it, coordMiddle );
	      ppp->radius_of_curvature = l_wanted;
	      GPoint gp = gf->point (ppp->X,ppp->Y);
	      realCoordinates[ppp] = BDS_Pos(gp.x(),gp.y(),gp.z());	      
	      if(linearLength > 2.4 * l_wanted) NB_MODIF++;	      
	    } 
	  ++it;
	}


      temp = m.edges;
      it = temp.begin();
      while (it != temp.end())
	{
	  const int numberOfTestPoints = 8;
	  double coordMiddle=0.5, trueLength,linearLength;
	  /*	  computeEdgeParameters ( (*it)->p1->X,
				  (*it)->p1->Y,
				  (*it)->p2->X,
				  (*it)->p2->Y,
				  gf ,numberOfTestPoints, coordMiddle, trueLength );*/
	  linearLength = computeEdgeLinearLength ( (*it),(*it)->p1,
						   (*it)->p2,realCoordinates);
	  double l_wanted = 0.5*((*it)->p1->radius_of_curvature + (*it)->p2->radius_of_curvature);
	  double errGeom = 0;
	  //	  Msg(INFO,"colll le = %g lex = %g err %g",linearLength,trueLength,errGeom);


	  if ((*it)->numfaces() == 2 && linearLength < 0.7 * l_wanted && errGeom < errGeomTresh * 0.7)
	    {
	      if ( (*it)->p1->iD >= points.size() )
		m.collapse_edge ( *it, (*it)->p1, 0);
	      else if ( (*it)->p2->iD >= points.size() )
		m.collapse_edge ( *it, (*it)->p2, 0);
	      if(linearLength < 0.35 * l_wanted) NB_MODIF++;	      
	    }
	  ++it;

	}
      temp = m.edges;
      it = temp.begin();
      while (it != temp.end())
	{
	  if (!(*it)->deleted && edgeSwapTest(*it,gf,realCoordinates))
	    m.swap_edge ( *it , BDS_SwapEdgeTestPlanar()); 
	  ++it;
	}

      std::set<BDS_Point*,PointLessThan> PTS (m.points);
      std::set<BDS_Point*,PointLessThan>::iterator itp = PTS.begin();
      while (itp != PTS.end())
	{
	  m.smooth_point(*itp);
	  GPoint gp = gf->point ((*itp)->X,(*itp)->Y);
	  realCoordinates[(*itp)] = BDS_Pos(gp.x(),gp.y(),gp.z());
	  std::list < BDS_Triangle * >t;
	  (*itp)->getTriangles(t);
	  if ((t.size()==3 && (*itp)->edges.size() == 3)||
	      (t.size()==4 && (*itp)->edges.size() == 4))
	      m.collapse_edge ( *(*itp)->edges.begin(), (*itp), 0);
	  ++itp;
	}
      Msg(INFO,"surf %d NB_MODIF = %d EDGES=%d",gf->tag(),NB_MODIF,m.edges.size());
      if (IT++ > 25 || (double)(NB_MODIF) < .003*(double)m.edges.size())break;
    }
  
  for (int i=0;i<gf->mesh_vertices.size();++i)
    {
      MVertex *p = gf->mesh_vertices[i];
      delete p;
    }
  gf->mesh_vertices.clear();

  std::map<int,MVertex*> verts_;
  {
    std::set<BDS_Point*,PointLessThan>::iterator it = m.points.begin();
    while (it != m.points.end())
      {
	if ( (*it)->iD >= points.size() )
	  {
	    MFaceVertex *v = new MFaceVertex ( (*it)->X,(*it)->Y, 0.0, gf, 0,0);           
	    gf->mesh_vertices.push_back(v);
	    verts_[(*it)->iD]  = v; 
	  }
	++it;
      }
  }
  {
    gf->triangles.clear();
    std::list<BDS_Triangle*>::iterator it = m.triangles.begin();
    while (it != m.triangles.end())
      {
	if (!(*it)->deleted)
	  {
	    BDS_Point *n[3];
	    (*it)->getNodes (n);
	    for (int i=0;i<3;i++)
	      {
		if (n[i]->iD >= points.size())
		  {
		    gf->triangles.push_back(verts_[n[i]->iD]);
		  }
		else
		  {
		    gf->triangles.push_back(points[n[i]->iD]);
		  }
	      }
	  }
	++it;
      }
  }
}

void OldMeshGenerator ( GFace *gf,
			std::vector<MVertex*> &points,
			std::vector<int> &indices, int initialOnly)
{


  // put the loops on the right sense, cause this stupid cannot
  // handle non oriented loops
  int nbEdgeLoops = indices.size()-1;

  for(int i = 0; i < nbEdgeLoops; i++) {
    int nbPtsOnEdgeLoop = indices[i+1] -indices[i];
    std::vector<MVertex*> loop;
    for(int j = indices[i]; j < indices[i+1]; j++)loop.push_back(points[j]);
    //    Msg(INFO, " %d %d %d %d",i,indices[i],indices[i+1],Orientation(loop));
    int k = 0;
    int ori = Orientation(loop);
    if (i == 0 && !ori)
      for(int j = indices[i]; j < indices[i+1]; j++)points[j] = loop [nbPtsOnEdgeLoop-k++-1];
    else if (i != 0 && ori)
      for(int j = indices[i]; j < indices[i+1]; j++)points[j] = loop [nbPtsOnEdgeLoop-k++-1];
  }

  extern PointRecord *gPointArray;


  // FIX THAT !!
  double LC2D = 1;
  if (gf->geomType () == GEntity::Plane)
    {
      SBoundingBox3d bb = gf->bounds();
      SPoint3 _min = bb.min();
      SPoint3 _max = bb.max();
      
      SVector3 diam (_min,_max);
      LC2D = norm(diam);
    }

  //  Msg(INFO, "LC = %g",LC2D);

  maillage M;
  ContourRecord *cp, **liste;
  liste = (ContourPeek *) malloc(nbEdgeLoops * sizeof(ContourPeek));
  for(int i = 0; i < nbEdgeLoops; i++) {
    cp = (ContourRecord *) malloc(sizeof(ContourRecord));
    int nbPtsOnEdgeLoop = indices[i+1] -indices[i];
    cp->oriented_points =
      (PointRecord *) malloc(nbPtsOnEdgeLoop * sizeof(PointRecord));
    cp->perturbations = (MPoint *) malloc( nbPtsOnEdgeLoop * sizeof(MPoint));
    cp->numerocontour = i;
    int k=0;
    //    Msg(INFO, " %d %d %d ",i,indices[i],indices[i+1]);
    for(int j = indices[i]; j < indices[i+1]; j++) {
      MVertex *here     = points[j];
      cp->oriented_points[k].where.h = here->x();
      cp->oriented_points[k].where.v = here->y();
      cp->perturbations[k].h = CTX.mesh.rand_factor * LC2D *
        (double)rand() / (double)RAND_MAX;
      cp->perturbations[k].v = CTX.mesh.rand_factor * LC2D *
        (double)rand() / (double)RAND_MAX;      
      cp->oriented_points[k].numcontour = i;

      MVertex *previous = (j == indices[i])?points[indices[i+1]-1] : points[j-1]; 
      MVertex *next     = (j == indices[i+1]-1)?points[indices[i]] : points[j+1];

      double lc = 0.5 * ( sqrt ( (here->x() - previous->x())*(here->x() - previous->x()) +
				 (here->y() - previous->y())*(here->y() - previous->y()) ) +
			  sqrt ( (here->x() - next->x())*(here->x() - next->x()) +
				 (here->y() - next->y())*(here->y() - next->y()) ) );		   
      
      //            Msg(INFO, " %g %g %g ",here->x(),here->y(),lc);
      cp->oriented_points[k].quality = lc;
      cp->oriented_points[k].permu = j;
      cp->oriented_points[k].initial = j;
      k++;
    }
    cp->numpoints = nbPtsOnEdgeLoop;
    liste[i] = cp;
  }

  int N;
  int res_mesh_domain = mesh_domain(liste, nbEdgeLoops, &M, &N,initialOnly);

  //  Msg(INFO, "result is %d",res_mesh_domain);
    
  MVertex ** verts_ = new MVertex* [M.numpoints];
  for(int i = 0; i < M.numpoints; i++) {
    //    Msg(INFO, "gpa[%d] = %g %g",i,gPointArray[i].where.h,gPointArray[i].where.v);
    if(gPointArray[i].initial < 0) {
   
      verts_[i]  = new MFaceVertex ( gPointArray[i].where.h,
				     gPointArray[i].where.v, 0.0, gf, 
				     0,0);           
      gf->mesh_vertices.push_back(verts_[i]);
    }
    else
      {
	verts_[i]  = points[gPointArray[i].initial];
      }
  }  
  
  for(int i = 0; i < M.numtriangles; i++) 
    {
      int a = M.listdel[i]->t.a;
      int b = M.listdel[i]->t.b;
      int c = M.listdel[i]->t.c;
      //      Msg(INFO, "tri[%d] = %d %d %d",i,a,b,c);
      gf->triangles.push_back(verts_[a]);
      gf->triangles.push_back(verts_[b]);
      gf->triangles.push_back(verts_[c]);
    }
  
  delete [] verts_;
  if(res_mesh_domain >= 0)
    free(M.listdel);
  free(gPointArray);
  
  for(int i = 0; i < nbEdgeLoops; i++) {
    free(liste[i]->perturbations);
    free(liste[i]->oriented_points);
    free(liste[i]);
  }
  free(liste);
}




void deMeshGFace :: operator() (GFace *gf) 
{
  for (int i=0;i<gf->mesh_vertices.size();i++) delete gf->mesh_vertices[i];
  gf->mesh_vertices.clear();
}


void meshGFace :: operator() (GFace *gf) 
{  


  // destroy the mesh if it exists
  deMeshGFace dem;
  dem(gf);

  // Only apply this technique to unknown surfaces or planar surfaces
  // when it is unknown, try your best ...

  std::vector<MVertex*> points;
  std::vector<int> indices;
  // compute loops on the fly
  // indices indicate start and end points of a loop
  // loops are not yet oriented
  computeEdgeLoops(gf,points,indices);

  //compute the mean plane, this is sometimes useful 
  MeanPlane_bis(gf,points);

  Msg(DEBUG1, "Face %d type %d with %d edge loops and %d points", gf->tag(),gf->geomType(),indices.size()-1,points.size());
  fromCartesianToParametric c2p ( gf );
  std::for_each (points.begin(),points.end(),c2p);    
  Msg(DEBUG1, "points were put in parametric coords ...");


  if (gf->geomType() == GEntity::Plane )
    {
      OldMeshGenerator ( gf,
			 points,
			 indices,0);
    }
  else
    {
      OldMeshGenerator ( gf,
			 points,
			 indices,1);
      NewMeshGenerator ( gf, points, indices );
    }

  Msg(DEBUG1, "type %d %d triangles generated, %d internal vertices", gf->geomType(),gf->triangles.size()/3,gf->mesh_vertices.size());

  if(0){
    char name[256];
    sprintf(name,"view%d-N.pos",gf->tag());
    FILE *fff = fopen (name,"w");
    fprintf(fff,"View \" \" {\n");
    
    std::vector<MVertex*> &triangles = gf->triangles;
    for (int i=0;i<gf->triangles.size();i+=3)
      {
	fprintf(fff,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){1,1,1};\n",
		triangles[i]->x(),triangles[i]->y(),triangles[i]->z(),
		triangles[i+1]->x(),triangles[i+1]->y(),triangles[i+1]->z(),
		triangles[i+2]->x(),triangles[i+2]->y(),triangles[i+2]->z());
      }
    
    fprintf(fff,"};\n");
    fclose(fff);
  }

  fromParametricToCartesian p2c ( gf );
  std::for_each (points.begin(),points.end(),p2c);    
  std::for_each (gf->mesh_vertices.begin(),gf->mesh_vertices.end(),p2c);    

  if(1){
    char name[256];
    sprintf(name,"view%d.pos",gf->tag());
    FILE *fff = fopen (name,"w");
    fprintf(fff,"View \" \" {\n");
    
    std::vector<MVertex*> &triangles = gf->triangles;
    for (int i=0;i<gf->triangles.size();i+=3)
      {
	fprintf(fff,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){1,1,1};\n",
		triangles[i]->x(),triangles[i]->y(),triangles[i]->z(),
		triangles[i+1]->x(),triangles[i+1]->y(),triangles[i+1]->z(),
		triangles[i+2]->x(),triangles[i+2]->y(),triangles[i+2]->z());
      }
    
    fprintf(fff,"};\n");
    fclose(fff);
  }
  
}  
