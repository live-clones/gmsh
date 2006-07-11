#include "meshGEdge.h"
#include "GEdge.h"
#include "Gmsh.h"
#include "Utils.h"
#include "Mesh.h"
#include "Context.h"
#include "Message.h"

static GEdge * _myGEdge;
static double  _myGEdgeLength, t_begin,t_end,lc_begin,lc_end;
static Range<double> _myGEdgeBounds;
// boooooooh !!!!!!
extern Mesh *THEM;
extern Context_T CTX;

double F_Lc_bis(double t)
{
  const double fact = (t-t_begin)/(t_end-t_begin);
  const double lc_here = lc_begin + fact * (lc_end-lc_begin);
  SVector3 der   =  _myGEdge -> firstDer(t) ;
  const double d = norm(der);

  if(THEM->BackgroundMeshType == ONFILE) {
    GPoint point =  _myGEdge -> point(t) ;      
    const double Lc = BGMXYZ(point.x(), point.y(), point.z());
    if(CTX.mesh.constrained_bgmesh)
      return std::max(d / Lc, d / lc_here);
    else
      return d / Lc;
  }
  else
    return d/lc_here;
}

double F_Transfini_bis(double t)
{
  double val,r;
  int i;

  SVector3 der = _myGEdge -> firstDer(t) ;
  double d = norm(der);

  double coef = _myGEdge->meshGEdgeAttributes.coeffTransfinite;
  int    type = _myGEdge->meshGEdgeAttributes.typeTransfinite;
  int    nbpt = _myGEdge->meshGEdgeAttributes.nbPointsTransfinite;

  if(coef <= 0.0 || coef == 1.0) {
    // coef < 0 should never happen
    val = d * coef / _myGEdgeLength;
  }
  else {
    switch (abs(type)) {

    case 1:    // Geometric progression ar^i; Sum of n terms = THEC->l = a (r^n-1)/(r-1)
      {
	if(sign(type) >= 0)
	  r = coef;
	else
	  r = 1. / coef;
	double a = _myGEdgeLength * (r - 1.) / (pow(r, nbpt - 1.) - 1.);
	int i = (int)(log(t * _myGEdgeLength / a * (r - 1.) + 1.) / log(r));
	val = d / (a * pow(r, (double)i));
      }
      break;
	
    case 2:    // Bump
      {
	if(coef > 1.0) {
	  a = -4. * sqrt(coef - 1.) *
	    atan2(1., sqrt(coef - 1.)) /
	    ((double)nbpt *  _myGEdgeLength);
	}
	else {
	  a = 2. * sqrt(1. - coef) *
	    log(fabs((1. + 1. / sqrt(1. - coef))
		     / (1. - 1. / sqrt(1. - coef))))
	    / ((double)nbpt * _myGEdgeLength);
	}
	double b = -a * _myGEdgeLength * _myGEdgeLength / (4. * (coef - 1.));
	val = d / (-a * DSQR(t * _myGEdgeLength - (_myGEdgeLength) * 0.5) + b);
      }
      break;
      
    default:
      Msg(WARNING, "Unknown case in Transfinite Line mesh");
      val = 1.;
    }
  }
  return val;
}

double F_One_bis(double t)
{
  SVector3 der = _myGEdge -> firstDer(t) ;
  return norm(der);
}


void deMeshGEdge :: operator() (GEdge *ge) 
{
  for (int i=0;i<ge->mesh_vertices.size();i++) delete ge->mesh_vertices[i];
  ge->mesh_vertices.clear();
}

void meshGEdge :: operator() (GEdge *ge) 
{  

  deMeshGEdge dem;
  dem(ge);

  // Send a messsage to the GMSH environment
  Msg(STATUS3, "Meshing curve %d", ge->tag());

  // Create a list of integration points
  List_T *Points = List_Create(10, 10, sizeof(IntPoint));

  // For avoiding the global variable :
  // We have to change the Integration function in order
  // to pass an extra argument... 
  _myGEdge = ge;
    
  // first compute the length of the curve by integrating one
  _myGEdgeBounds = ge->parBounds(0) ;
  _myGEdgeLength = Integration(_myGEdgeBounds.low(), _myGEdgeBounds.high(), F_One_bis, Points, 1.e-4);
  List_Reset(Points);


  lc_begin  =  _myGEdge->getBeginVertex()->prescribedMeshSizeAtVertex();
  lc_end    =  _myGEdge->getEndVertex()->prescribedMeshSizeAtVertex();
    
  t_begin = _myGEdgeBounds.low();
  t_end   = _myGEdgeBounds.high();

  // Integrate ∫ detJ/lc du 
  double a;
  int N;
  if(ge->meshGEdgeAttributes.Method == TRANSFINI) 
    {
      a = Integration(_myGEdgeBounds.low(), _myGEdgeBounds.high(), F_Transfini_bis, Points, 1.e-7);
      N = ge->meshGEdgeAttributes.nbPointsTransfinite;
    }
  else
    {
      a = Integration(_myGEdgeBounds.low(), _myGEdgeBounds.high(), F_Lc_bis, Points, 1.e-4);
      N = std::max (ge->minimumEdgeSegments()+1, (int)(a + 1.));      
    }
  const double b = a / (double)(N - 1);

  int count = 1, NUMP = 1;
  IntPoint P1,P2;

  // do not consider the first and the last vertex 
  // those are not classified on this mesh edge
  ge->mesh_vertices.resize(N-2);

  while(NUMP < N - 1) {
    List_Read(Points, count - 1, &P1);
    List_Read(Points, count, &P2);
    const double d = (double)NUMP *b;
    
    if((fabs(P2.p) >= fabs(d)) && (fabs(P1.p) < fabs(d))) {
      double dt = P2.t - P1.t;
      double dp = P2.p - P1.p;
      double t = P1.t + dt / dp * (d - P1.p);      
      GPoint V = ge -> point(t) ;      
      MEdgeVertex *ev = new MEdgeVertex ( V.x(), V.y(), V.z(), ge, t );     
      ge->mesh_vertices [NUMP-1] = ev;
      NUMP++;
    }
    else {
      count++;
    }
  }
  List_Delete(Points);
}  
