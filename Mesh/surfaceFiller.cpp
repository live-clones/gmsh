// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.
//
// Contributor(s):
//   Tristan Carrier Baudoin

#include "GmshConfig.h"
#include "surfaceFiller.h"
#include "Field.h"
#include "GModel.h"
#include "OS.h"
#include <queue>
#include <stack>

/// Here, we aim at producing a set of points that
/// enables to generate a nice quad mesh

#if defined(HAVE_RTREE)
#include "rtree.h"
#endif

#include "MVertex.h"
#include "MElement.h"
//#include "directions3D.h"
#include "BackgroundMesh.h"
#include "intersectCurveSurface.h"

static const double FACTOR = .71;
static const int NUMDIR = 3;
//static const double DIRS [NUMDIR] = {0.0};
static const double DIRS [NUMDIR] = {0.0, M_PI/20.,-M_PI/20.};

/// a rectangle in the tangent plane is transformed
/// into a parallelogram. We define an exclusion zone
/// that is centered around a vertex and that is used
/// in a r-tree structure for generating points with the
/// right spacing in the tangent plane

#if defined(HAVE_RTREE)
struct surfacePointWithExclusionRegion {
  MVertex *_v;
  SPoint2 _center;
  SPoint2 _p[4][NUMDIR];
  SPoint2 _q[4];
  SMetric3 _meshMetric;
  double _distanceSummed;
  /*
         + p3
    p4   |
    +----c-----+ p2
         |
         + p1

*/

  surfacePointWithExclusionRegion (MVertex *v, SPoint2 p[4][NUMDIR], SPoint2 &_mp, SMetric3 & meshMetric, surfacePointWithExclusionRegion *father = 0){
    _v = v;
    _meshMetric = meshMetric;
    _center = _mp;
    for (int i=0;i<4;i++)_q[i] = _center + (p[i][0]+p[(i+1)%4][0]-_center*2)*FACTOR;
    for (int i=0;i<4;i++)for (int j=0;j<NUMDIR;j++)_p[i][j] = p[i][j];

    if (!father){
      fullMatrix<double> V(3,3);
      fullVector<double> S(3);
      meshMetric.eig(V,S);
      double l = std::max(std::max(S(0),S(1)),S(2));
      _distanceSummed = sqrt(1/(l*l));
    }
    else {
      _distanceSummed = father->_distanceSummed + distance (father->_v,_v);
    }
  }
  bool inExclusionZone (const SPoint2 &p){
    double mat[2][2];
    double b[2] , uv[2];
    mat[0][0]= _q[1].x()-_q[0].x();
    mat[0][1]= _q[2].x()-_q[0].x();
    mat[1][0]= _q[1].y()-_q[0].y();
    mat[1][1]= _q[2].y()-_q[0].y();
    b[0] = p.x() - _q[0].x();
    b[1] = p.y() - _q[0].y();
    sys2x2(mat, b, uv);
    //    printf("inversion 1 : %g %g \n",uv[0],uv[1]);
    if (uv[0] >= 0 && uv[1] >= 0 && 1.-uv[0] - uv[1] >= 0)return true;
    mat[0][0]= _q[3].x()-_q[2].x();
    mat[0][1]= _q[0].x()-_q[2].x();
    mat[1][0]= _q[3].y()-_q[2].y();
    mat[1][1]= _q[0].y()-_q[2].y();
    b[0] = p.x() - _q[2].x();
    b[1] = p.y() - _q[2].y();
    sys2x2(mat, b, uv);
    //    printf("inversion 2 : %g %g \n",uv[0],uv[1]);
    if (uv[0] >= 0 && uv[1] >= 0 && 1.-uv[0] - uv[1] >= 0)return true;
    return false;
  }
  void minmax  (double _min[2], double _max[2]) const{
    _min[0] = std::min(std::min(std::min(_q[0].x(),_q[1].x()),_q[2].x()),_q[3].x());
    _min[1] = std::min(std::min(std::min(_q[0].y(),_q[1].y()),_q[2].y()),_q[3].y());
    _max[0] = std::max(std::max(std::max(_q[0].x(),_q[1].x()),_q[2].x()),_q[3].x());
    _max[1] = std::max(std::max(std::max(_q[0].y(),_q[1].y()),_q[2].y()),_q[3].y());
  }
  void print (FILE *f, int i){
    fprintf(f,"SP(%g,%g,%g){%d};\n",_center.x(),_center.y(),0.0,i);
    fprintf(f,"SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d,%d};\n",
	    _q[0].x(),_q[0].y(),0.0,
	    _q[1].x(),_q[1].y(),0.0,
	    _q[2].x(),_q[2].y(),0.0,
	    _q[3].x(),_q[3].y(),0.0,i,i,i,i);

  }
};

struct my_wrapper {
  bool _tooclose;
  SPoint2 _p;
  my_wrapper (SPoint2 sp) : _tooclose (false), _p(sp) {}
};

class compareSurfacePointWithExclusionRegionPtr
{
 public:
  inline bool operator () (const surfacePointWithExclusionRegion *a, const surfacePointWithExclusionRegion *b)  const
  {
    if(a->_distanceSummed > b->_distanceSummed) return false;
    if(a->_distanceSummed < b->_distanceSummed) return true;
    return a<b;
  }
};




bool rtree_callback(surfacePointWithExclusionRegion *neighbour,void* point){
  my_wrapper *w = static_cast<my_wrapper*>(point);

  if (neighbour->inExclusionZone(w->_p)){
    w->_tooclose = true;
    return false;
  }

  return true;
}

bool inExclusionZone (SPoint2 &p,
		      RTree<surfacePointWithExclusionRegion*,double,2,double> &rtree,
		      std::vector<surfacePointWithExclusionRegion*> & all ){
  // should assert that the point is inside the domain
  if (!backgroundMesh::current()->inDomain(p.x(),p.y(),0)) return true;

  my_wrapper w (p);
  double _min[2] = {p.x()-1.e-1, p.y()-1.e-1},_max[2] = {p.x()+1.e-1,p.y()+1.e-1};
  rtree.Search(_min,_max,rtree_callback,&w);

  return w._tooclose;

  for (unsigned int i=0;i<all.size();++i){
    if (all[i]->inExclusionZone(p)){
      //      printf("%g %g is in exclusion zone of %g %g\n",p.x(),p.y(),all[i]._center.x(),all[i]._center.y());
      return true;
    }
  }
  return false;
}




// assume a point on the surface, compute the 4 possible neighbors.
//
//              ^ t2
//              |
//              |
//             v2
//              |
//              |
//       v1-----+------v3 -------> t1
//              |
//              |
//             v4
//
// we aim at generating a rectangle with sizes size_1 and size_2 along t1 and t2

bool compute4neighbors (GFace *gf,   // the surface
			MVertex *v_center, // the wertex for which we wnt to generate 4 neighbors
			SPoint2 &midpoint,
			bool goNonLinear, // do we compute the position in the real surface which is nonlinear
			SPoint2 newP[4][NUMDIR], // look into other directions
			SMetric3 &metricField, FILE *crossf = 0) // the mesh metric
{

  //Range<double> rangeU = gf->parBounds(0);
  //Range<double> rangeV = gf->parBounds(1);

  // we assume that v is on surface gf

  // get the parameter of the point on the surface
  reparamMeshVertexOnFace(v_center, gf, midpoint);

  double L = backgroundMesh::current()->operator()(midpoint[0],midpoint[1],0.0);
  //  printf("L = %12.5E\n",L);
  metricField = SMetric3(1./(L*L));
  FieldManager *fields = gf->model()->getFields();
  if(fields->getBackgroundField() > 0){
    Field *f = fields->get(fields->getBackgroundField());
     if (!f->isotropic()){
       (*f)(v_center->x(),v_center->y(),v_center->z(), metricField,gf);
     }
     else {
      L = (*f)(v_center->x(),v_center->y(),v_center->z(), gf);
      metricField = SMetric3(1./(L*L));
     }
  }


  // get the unit normal at that point
  Pair<SVector3, SVector3> der = gf->firstDer(SPoint2(midpoint[0],midpoint[1]));
  SVector3 s1 = der.first();
  SVector3 s2 = der.second();
  SVector3 n = crossprod(s1,s2);
  n.normalize();

  double M = dot(s1,s1);
  double N = dot(s2,s2);
  double E = dot(s1,s2);


  // compute the first fundamental form i.e. the metric tensor at the point
  // M_{ij} = s_i \cdot s_j
  double metric[2][2] = {{M,E},{E,N}};

  //  printf("%d %g %g %g\n",gf->tag(),s1.x(),s1.y(),s1.z());

  SVector3 basis_u = s1; basis_u.normalize();
  SVector3 basis_v = crossprod(n,basis_u);

  for (int DIR = 0 ; DIR < NUMDIR ; DIR ++){
    double quadAngle  = backgroundMesh::current()->getAngle (midpoint[0],midpoint[1],0) + DIRS[DIR];

    // normalize vector t1 that is tangent to gf at midpoint
    SVector3 t1 = basis_u * cos (quadAngle) + basis_v * sin (quadAngle) ;
    t1.normalize();

    // compute the second direction t2 and normalize (t1,t2,n) is the tangent frame
    SVector3 t2 = crossprod(n,t1);
    t2.normalize();
    if (DIR == 0 && crossf)fprintf(crossf,"VP(%g,%g,%g) {%g,%g,%g};\n",v_center->x(),v_center->y(),v_center->z(),t1.x(),t1.y(),t1.z());
    if (DIR == 0 && crossf)fprintf(crossf,"VP(%g,%g,%g) {%g,%g,%g};\n",v_center->x(),v_center->y(),v_center->z(),t2.x(),t2.y(),t2.z());
    if (DIR == 0 && crossf)fprintf(crossf,"VP(%g,%g,%g) {%g,%g,%g};\n",v_center->x(),v_center->y(),v_center->z(),-t1.x(),-t1.y(),-t1.z());
    if (DIR == 0 && crossf)fprintf(crossf,"VP(%g,%g,%g) {%g,%g,%g};\n",v_center->x(),v_center->y(),v_center->z(),-t2.x(),-t2.y(),-t2.z());

    double size_1 = sqrt(1. / dot(t1,metricField,t1));
    double size_2 = sqrt(1. / dot(t2,metricField,t2));

    // compute covariant coordinates of t1 and t2
    // t1 = a s1 + b s2 -->
    // t1 . s1 = a M + b E
    // t1 . s2 = a E + b N --> solve the 2 x 2 system
    // and get covariant coordinates a and b
    double rhs1[2] = {dot(t1,s1),dot(t1,s2)}, covar1[2];
    bool singular = false;
    if (!sys2x2(metric,rhs1,covar1)){
      Msg::Info("Argh surface %d %g %g %g -- %g %g %g -- %g %g",gf->tag(),s1.x(),s1.y(),s1.z(),s2.x(),s2.y(),s2.z(),size_1,size_2);
      covar1[1] = 1.0; covar1[0] = 0.0;
      singular = true;
    }
    double rhs2[2] = {dot(t2,s1),dot(t2,s2)}, covar2[2];
    if (!sys2x2(metric,rhs2,covar2)){
      Msg::Info("Argh surface %d %g %g %g -- %g %g %g",gf->tag(),s1.x(),s1.y(),s1.z(),s2.x(),s2.y(),s2.z());
      covar2[0] = 1.0; covar2[1] = 0.0;
      singular = true;
    }

    // transform the sizes with respect to the metric
    // consider a vector v of size 1 in the parameter plane
    // its length is sqrt (v^T M v) --> if I want a real size
    // of size1 in direction v, it should be sqrt(v^T M v) * size1
    double l1 = sqrt(covar1[0]*covar1[0]+covar1[1]*covar1[1]);
    double l2 = sqrt(covar2[0]*covar2[0]+covar2[1]*covar2[1]);

    covar1[0] /= l1;covar1[1] /= l1;
    covar2[0] /= l2;covar2[1] /= l2;

    double size_param_1  = size_1 / sqrt (  M*covar1[0]*covar1[0]+
						  2*E*covar1[1]*covar1[0]+
						  N*covar1[1]*covar1[1]);
    double size_param_2  = size_2 / sqrt (  M*covar2[0]*covar2[0]+
						  2*E*covar2[1]*covar2[0]+
						  N*covar2[1]*covar2[1]);
    if (singular){
      size_param_1 = size_param_2 = std::min (size_param_1,size_param_2);
    }

    //    printf("%12.5E %12.5E\n", size_param_1, size_param_2);


    //    if (v_center->onWhat() != gf && gf->tag() == 3)
    //      printf("M = (%g %g %g) L = %g %g LP = %g %g\n",metricField(0,0),metricField(1,1),metricField(0,1),l1,l2,size_param_1,size_param_2);
    //if (l1 == 0.0 || l2 == 0.0) printf("bouuuuuuuuuuuuh %g %g %g %g --- %g %g %g %g %g %g\n",l1,l2,t1.norm(),t2.norm(),s1.x(),s1.y(),s1.z(),s2.x(),s2.y(),s2.z());

    /*    printf("%12.5E %12.5E %12.5E %12.5E %12.5E %12.5E %12.5E %12.5E %g %g %g %g %g %g %g %g %g %g %g\n",
	   M*covar1[0]*covar1[0]+
	   2*E*covar1[1]*covar1[0]+
	   N*covar1[1]*covar1[1],
	   M*covar2[0]*covar2[0]+
	   2*E*covar2[1]*covar2[0]+
	   N*covar2[1]*covar2[1]
	   ,covar1[0],covar1[1],covar2[0],covar2[1],l1,l2,size_1,size_2,size_param_1,size_param_2,M,N,E,s1.x(),s1.y(),s2.x(),s2.y());*/

    // this is the rectangle in the parameter plane.
    const double EPS = 1.e-7;
    double r1 = EPS*(double)rand() / RAND_MAX;
    double r2 = EPS*(double)rand() / RAND_MAX;
    double r3 = EPS*(double)rand() / RAND_MAX;
    double r4 = EPS*(double)rand() / RAND_MAX;
    double r5 = EPS*(double)rand() / RAND_MAX;
    double r6 = EPS*(double)rand() / RAND_MAX;
    double r7 = EPS* (double)rand() / RAND_MAX;
    double r8 = EPS*(double)rand() / RAND_MAX;
    double newPoint[4][2] = {{midpoint[0] - covar1[0] * size_param_1 +r1,
			      midpoint[1] - covar1[1] * size_param_1 +r2},
			     {midpoint[0] - covar2[0] * size_param_2 +r3,
			      midpoint[1] - covar2[1] * size_param_2 +r4},
			     {midpoint[0] + covar1[0] * size_param_1 +r5,
			      midpoint[1] + covar1[1] * size_param_1 +r6},
			     {midpoint[0] + covar2[0] * size_param_2 +r7,
			      midpoint[1] + covar2[1] * size_param_2 +r8 }};
    // We could stop here. Yet, if the metric varies a lot, we can solve
    // a nonlinear problem in order to find a better approximation in the real
    // surface
    double ERR[4];
    for (int i=0;i<4;i++){                                              //
      //      if (newPoint[i][0] < rangeU.low())newPoint[i][0] = rangeU.low();
      //      if (newPoint[i][0] > rangeU.high())newPoint[i][0] = rangeU.high();
      //      if (newPoint[i][1] < rangeV.low())newPoint[i][1] = rangeV.low();
      //      if (newPoint[i][1] > rangeV.high())newPoint[i][1] = rangeV.high();
      GPoint pp = gf->point(SPoint2(newPoint[i][0], newPoint[i][1]));
      double D = sqrt ((pp.x() - v_center->x())*(pp.x() - v_center->x()) +
		       (pp.y() - v_center->y())*(pp.y() - v_center->y()) +
		       (pp.z() - v_center->z())*(pp.z() - v_center->z()) );
      ERR[i] = 100*fabs(D-L)/(D+L);
      //      printf("L = %12.5E D = %12.5E ERR = %12.5E\n",L,D,100*fabs(D-L)/(D+L));
    }

    if (1 && goNonLinear){//---------------------------------------------------//
      surfaceFunctorGFace ss (gf);                                        //
      SVector3 dirs[4] = {t1*(-1.0),t2*(-1.0),t1*(1.0),t2*(1.0)};                     //
      for (int i=0;i<4;i++){                                              //
	if (ERR[i] > 12){
	  double uvt[3] = {newPoint[i][0],newPoint[i][1],0.0};              //
	  //	  printf("Intersecting with circle N = %g %g %g dir = %g %g %g R = %g p = %g %g %g\n",n.x(),n.y(),n.z(),dirs[i].x(),dirs[i].y(),dirs[i].z(),L,v_center->x(),v_center->y(),v_center->z());
	  curveFunctorCircle cf (dirs[i],n,
				 SVector3(v_center->x(),v_center->y(),v_center->z()),
				 L);
	  if (intersectCurveSurface (cf,ss,uvt,size_param_1*1.e-3)){          //
	    GPoint pp = gf->point(SPoint2(uvt[0],uvt[1]));
	    double D = sqrt ((pp.x() - v_center->x())*(pp.x() - v_center->x()) +
			     (pp.y() - v_center->y())*(pp.y() - v_center->y()) +
			     (pp.z() - v_center->z())*(pp.z() - v_center->z()) );
	    double DP = sqrt ((newPoint[i][0]-uvt[0])*(newPoint[i][0]-uvt[0]) +
			      (newPoint[i][1]-uvt[1])*(newPoint[i][1]-uvt[1]));
	    double newErr = 100*fabs(D-L)/(D+L);
	    //	    if (v_center->onWhat() != gf && gf->tag() == 3){
	    //	      crossField2d::normalizeAngle (uvt[2]);
	    //	      printf("INTERSECT angle = %g DP %g\n",uvt[2],DP);
	    //	    }
	    if (newErr < 1 && DP < .1){
	      //	      printf("%12.5E vs %12.5E : %12.5E  %12.5E vs %12.5E  %12.5E \n",ERR[i],newErr,newPoint[i][0],newPoint[i][1],uvt[0],uvt[1]);
	      newPoint[i][0] = uvt[0];                                        //
	      newPoint[i][1] = uvt[1];                                        //
	    }                                                                 //
	    //	    printf("OK\n");
	  }
	  else{
	    Msg::Debug("Cannot put a new point on Surface %d",gf->tag());
	    //	    printf("NOT OK\n");
	  }
	}
      }                                                                   //
    } /// end non linear -------------------------------------------------//

    // return the four new vertices
    for (int i=0;i<4;i++){
      newP[i][DIR] = SPoint2(newPoint[i][0],newPoint[i][1]);
    }
  }
  return true;
}
#endif

// fills a surface with points in order to build a nice
// quad mesh ------------
void packingOfParallelograms(GFace* gf,  std::vector<MVertex*> &packed, std::vector<SMetric3> &metrics){
  #if defined(HAVE_RTREE)

  const bool goNonLinear = true;

  //  FILE *f = Fopen ("parallelograms.pos","w");

  // get all the boundary vertices
  std::set<MVertex*> bnd_vertices;
  for(unsigned int i=0;i<gf->getNumMeshElements();i++){
    MElement* element = gf->getMeshElement(i);
    for(int j=0;j<element->getNumVertices();j++){
      MVertex *vertex = element->getVertex(j);
      if (vertex->onWhat()->dim() < 2)bnd_vertices.insert(vertex);
    }
  }

  // put boundary vertices in a fifo queue
  // std::queue<surfacePointWithExclusionRegion*> fifo;
  std::set<surfacePointWithExclusionRegion*,  compareSurfacePointWithExclusionRegionPtr> fifo;
  std::vector<surfacePointWithExclusionRegion*> vertices;
  // put the RTREE
  RTree<surfacePointWithExclusionRegion*,double,2,double> rtree;
  SMetric3 metricField(1.0);
  SPoint2 newp[4][NUMDIR];
  std::set<MVertex*>::iterator it =  bnd_vertices.begin() ;

  char NAME[345]; sprintf(NAME,"crossReal%d.pos",gf->tag());
  FILE *crossf = Fopen (NAME,"w");
  if (crossf)fprintf(crossf,"View \"\"{\n");
  for (; it !=  bnd_vertices.end() ; ++it){
    SPoint2 midpoint;
    compute4neighbors (gf, *it, midpoint, goNonLinear, newp, metricField,crossf);
    surfacePointWithExclusionRegion *sp =
      new surfacePointWithExclusionRegion (*it, newp, midpoint,metricField);
    //    fifo.push(sp);
    fifo.insert(sp);
    vertices.push_back(sp);
    double _min[2],_max[2];
    sp->minmax(_min,_max);
    //    printf("%g %g .. %g %g\n",_min[0],_min[1],_max[0],_max[1]);
    rtree.Insert(_min,_max,sp);
    //    sp->print(f);
  }

  //  printf("initially : %d vertices in the domain\n",vertices.size());


  while(!fifo.empty()){
    //surfacePointWithExclusionRegion & parent = fifo.top();
    //    surfacePointWithExclusionRegion * parent = fifo.front();
    surfacePointWithExclusionRegion * parent = *fifo.begin();
    //    fifo.pop();
    fifo.erase(fifo.begin());
    for (int dir=0;dir<NUMDIR;dir++){
      //      printf("dir = %d\n",dir);
      int countOK = 0;
      for (int i=0;i<4;i++){
	//	printf("i = %d %12.5E %12.5E \n",i,parent._p[i][dir].x(),parent._p[i][dir].y());

	//	if (!w._tooclose){
	if (!inExclusionZone (parent->_p[i][dir], rtree, vertices) ){
	  countOK++;
	  GPoint gp = gf->point(parent->_p[i][dir]);
	  MFaceVertex *v = new MFaceVertex(gp.x(),gp.y(),gp.z(),gf,gp.u(),gp.v());
	  //	  	printf(" %g %g %g %g\n",parent._center.x(),parent._center.y(),gp.u(),gp.v());
	  SPoint2 midpoint;
	  compute4neighbors (gf, v, midpoint, goNonLinear, newp, metricField,crossf);
	  surfacePointWithExclusionRegion *sp =
	    new surfacePointWithExclusionRegion (v, newp, midpoint, metricField, parent);
	  //	  fifo.push(sp);
	  fifo.insert(sp);
	  vertices.push_back(sp);
	  double _min[2],_max[2];
	  sp->minmax(_min,_max);
	  rtree.Insert(_min,_max,sp);
	}
      }
      if (countOK)break;
    }
    //    printf("%d\n",vertices.size());
  }
  if (crossf){
    fprintf(crossf,"};\n");
    fclose (crossf);
  }
  //  printf("done\n");

  // add the vertices as additional vertices in the
  // surface mesh
  char ccc[256]; sprintf(ccc,"points%d.pos",gf->tag());
  FILE *f = Fopen(ccc,"w");
  fprintf(f,"View \"\"{\n");
  for (unsigned int i=0;i<vertices.size();i++){
    //    if(vertices[i]->_v->onWhat() != gf)
      vertices[i]->print(f,i);
    if(vertices[i]->_v->onWhat() == gf) {
      packed.push_back(vertices[i]->_v);
      metrics.push_back(vertices[i]->_meshMetric);
      SPoint2 midpoint;
      reparamMeshVertexOnFace(vertices[i]->_v, gf, midpoint);
      //      fprintf(f,"TP(%22.15E,%22.15E,%g){%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E};\n",vertices[i]->_v->x(),vertices[i]->_v->y(),vertices[i]->_v->z(),
      //	      vertices[i]->_meshMetric(0,0),vertices[i]->_meshMetric(0,1),vertices[i]->_meshMetric(0,2),
      //	      vertices[i]->_meshMetric(1,0),vertices[i]->_meshMetric(1,1),vertices[i]->_meshMetric(1,2),
      //	      vertices[i]->_meshMetric(2,0),vertices[i]->_meshMetric(2,1),vertices[i]->_meshMetric(2,2));
	    //fprintf(f,"SP(%22.15E,%22.15E,%g){1};\n",midpoint.x(),midpoint.y(),0.0);
    }
    delete  vertices[i];
  }
  fprintf(f,"};");
  fclose(f);
  //  printf("packed.size = %d\n",packed.size());
  //  delete rtree;
  #endif
}



