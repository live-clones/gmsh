// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Tristan Carrier Baudoin

#include <queue>
#include <stack>
#include "GmshConfig.h"
#include "surfaceFiller.h"
#include "Field.h"
#include "GModel.h"
#include "OS.h"
#include "rtree.h"
#include "MVertex.h"
#include "MElement.h"
#include "MLine.h"
#include "BackgroundMesh.h"
#include "intersectCurveSurface.h"
#include "pointInsertionRTreeTools.h"
#include "discreteFace.h"

// Here, we aim at producing a set of points that enables to generate a nice
// quad mesh

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

int __OK, __KO;

bool compute4neighbors(
  GFace *gf, // the surface
  MVertex *v_center, // the wertex for which we wnt to generate 4 neighbors
  SPoint2 &midpoint,
  SPoint2 newP[8], // look into other directions
  SMetric3 &metricField,// the mesh metric
  Field *f,
  double du,
  double dv,
  double mult)
{
  // we assume that v is on surface gf

  // get the parameter of the point on the surface
  reparamMeshVertexOnFace(v_center, gf, midpoint);

  midpoint = SPoint2(midpoint.x() + du,midpoint.y() + dv);

  SVector3 t1;
  double L;
  double X=v_center->x();
  double Y=v_center->y();
  double Z=v_center->z();
  int iter = 1;
  while (1){
    (*f)(X,Y,Z, t1, gf);
    L = t1.norm()*mult;
    // HOUSTON WE HAVE A PROBLEM
    if (L > 1.e10){
      double DU = ((double)rand()/RAND_MAX)*1.e-3*iter;
      double DV = ((double)rand()/RAND_MAX)*1.e-3*iter;
      GPoint pp = gf->point(DU+midpoint.x(),DV+midpoint.y());
      X = pp.x();
      Y = pp.y();
      Z = pp.z();
      iter++;
    }
    else break;
  }

  metricField = SMetric3(1. / (L * L));

  // get the unit normal at that point
  Pair<SVector3, SVector3> der =
    gf->firstDer(SPoint2(midpoint[0], midpoint[1]));
  SVector3 s1 = der.first();
  SVector3 s2 = der.second();
  SVector3 n = crossprod(s1, s2);
  n.normalize();
  t1 -= n*dot(t1,n);
  t1.normalize();

  double M = dot(s1, s1);
  double N = dot(s2, s2);
  double E = dot(s1, s2);

  // compute the first fundamental form i.e. the metric tensor at the point
  // M_{ij} = s_i \cdot s_j
  double metric[2][2] = {{M, E}, {E, N}};

  // compute the second direction t2 and normalize (t1,t2,n) is the tangent
  // frame
  SVector3 t2 = crossprod(n, t1);
  t2.normalize();

  // compute covariant coordinates of t1 and t2
  // t1 = a s1 + b s2 -->
  // t1 . s1 = a M + b E
  // t1 . s2 = a E + b N --> solve the 2 x 2 system
  // and get covariant coordinates a and b
  double rhs1[2] = {dot(t1, s1)*L, dot(t1, s2)*L}, covar1[2];
  bool singular = false;
  if(!sys2x2(metric, rhs1, covar1)) {
    Msg::Debug("surface filler: SINGULAR AT %g %g",midpoint.x(),midpoint.y());
    return false;
    covar1[1] = 1.0;
    covar1[0] = 0.0;
    singular = true;
  }
  double rhs2[2] = {dot(t2, s1)*L, dot(t2, s2)*L}, covar2[2];
  if(!sys2x2(metric, rhs2, covar2)) {
    Msg::Debug("surface filler: SINGULAR AT %g %g",midpoint.x(),midpoint.y());
    return false;
    covar2[0] = 1.0;
    covar2[1] = 0.0;
    singular = true;
  }

  // compute the corners of the box as well
  double LSQR = L ;
  SVector3 b1 = t1+t2;
  b1.normalize();
  SVector3 b2 = t1-t2;
  b2.normalize();

  double rhs3[2] = {dot(b1, s1)*LSQR, dot(b1, s2)*LSQR}, covar3[2];
  if(!sys2x2(metric, rhs3, covar3)) {
    covar3[1] = 1.e22;
    covar3[0] = 0.0;
    singular = true;
  }
  double rhs4[2] = {dot(b2, s1)*LSQR, dot(b2, s2)*LSQR}, covar4[2];
  if(!sys2x2(metric, rhs4, covar4)) {
    covar4[0] = 1.e22;
    covar4[1] = 0.0;
    singular = true;
  }


  double size_1 = sqrt (covar1[0]*covar1[0]+covar1[1]*covar1[1]);
  double size_2 = sqrt (covar2[0]*covar2[0]+covar2[1]*covar2[1]);


  double newPoint[8][2] = {{midpoint[0] - covar1[0],
			    midpoint[1] - covar1[1]},
			   {midpoint[0] - covar2[0],
			    midpoint[1] - covar2[1]},
			   {midpoint[0] + covar1[0],
			    midpoint[1] + covar1[1]},
			   {midpoint[0] + covar2[0],
			    midpoint[1] + covar2[1]},
			   {midpoint[0] - covar3[0],
			    midpoint[1] - covar3[1]},
			   {midpoint[0] - covar4[0],
			    midpoint[1] - covar4[1]},
			   {midpoint[0] + covar3[0],
			    midpoint[1] + covar3[1]},
			   {midpoint[0] + covar4[0],
			    midpoint[1] + covar4[1]}};

  SVector3 dirs[8]      = {t1 * (-1.0), t2 * (-1.0), t1 * (1.0), t2 * (1.0),
			   b1 * (-1.0), b2 * (-1.0), b1 * (1.0), b2 * (1.0) };
  SVector3 orthodirs[8] = {t2 * (-1.0), t1 * (-1.0), t2 * (1.0), t1 * (1.0),
			   b2 * (-1.0), b1 * (-1.0), b2 * (1.0), b1 * (1.0) };
  double   LS[8]   = {L,L,L,L,LSQR,LSQR,LSQR,LSQR};


  SPoint3 ppx (v_center->x(),v_center->y(),v_center->z());
  surfaceFunctorGFace ss(gf);
  for(int i = 0; i < 4; i++) {
    newP[i] = SPoint2(newPoint[i][0], newPoint[i][1]);
    GPoint pp = gf->point(newP[i]);
    SPoint3 px (pp.x(),pp.y(),pp.z());
    SVector3 test = px - ppx;
    double L2 = test.norm();
    double DIFF_ANG = fabs(dot(orthodirs[i],test)) / L2;
    double DIFF_L   = fabs(L2-LS[i]);
    if (singular || DIFF_L > .01*LS[i] || DIFF_ANG > .1){
      // if (0 && gf->geomType() == GEntity::DiscreteSurface){
      // 	discreteFace *df = dynamic_cast<discreteFace *>(gf);
      // 	double uv[2] = {newPoint[i][0], newPoint[i][1]};
      // 	GPoint qq = df->intersectionWithCircle(dirs[i], n, SVector3(v_center->x(), v_center->y(), v_center->z()),
      // 							 LS[i],uv);
      // 	if (qq.succeeded()){
      // 	  newPoint[i][0]=qq.u();
      // 	  newPoint[i][1]=qq.v();
      // 	}
      // }
      // else {
      curveFunctorCircle cf(dirs[i], n, SVector3(v_center->x(), v_center->y(), v_center->z()), LS[i]);
      double uvt[3] = {newPoint[i][0], newPoint[i][1], 0.0}; //
      if(intersectCurveSurface(cf, ss, uvt, size_1 * 1.e-6)) {
	__KO++;
	pp = gf->point(SPoint2(uvt[0], uvt[1]));
	px = SPoint3 (pp.x(),pp.y(),pp.z());
	test = px - ppx;
	L2 = test.norm();
	double DIFF_ANG2 = fabs(dot(orthodirs[i],test)) / L2;
	double DIFF_L2   = fabs(L2-LS[i]);
	newPoint[i][0]=uvt[0];
	newPoint[i][1]=uvt[1];
	if (DIFF_L2 <= DIFF_L && DIFF_ANG2 <= DIFF_ANG){
	}
	else{
	  Msg::Debug("Difficult to find a point %lu L %g vs %g (ps %12.5E) ",i,L,L2,DIFF_ANG2);
	}
      }
      else{
	SPoint3 p_test (v_center->x() + dirs[i].x() * LS[i],
			v_center->y() + dirs[i].y() * LS[i],
			v_center->z() + dirs[i].z() * LS[i]);
	pp = gf->closestPoint(p_test ,uvt);
	if (pp.succeeded()){
	  newPoint[i][0] = pp.u();
	  newPoint[i][1] = pp.v();
	}
	else
	  Msg::Debug("Face %d Impossible to intersect with a circle of radius %g",gf->tag(),L);
      }
    }
    else {
      __OK++;
    }
  }

  return true;
}

// at crossfield singularities, directions are undefined
// we draw a circle around
// static void createSingularPatches (GFace *gf, std::map<MVertex *, int> &s, Field *f, std::vector<MVertex*> &toInsert){

//   FILE *_f = fopen("patches.pos","w");
//   fprintf(_f,"View \"\"{\n");
//   for (std::map<MVertex *, int>::iterator it = s.begin();it != s.end() ; ++it){
//     SPoint2 midpoint;
//     SPoint2 newP[8];
//     SMetric3 metricField;
//     compute4neighbors(gf, it->first, midpoint, newP, metricField, f, 0, 0, it->second == 5 ? .25 : 1);
//     //the 8 points (I know, it's strange ...)
//     //                 2
//     //             7       6
//     //          1             3
//     //             4       5
//     //                 0

//     // get the unit normal at that point
//     Pair<SVector3, SVector3> der =
//       gf->firstDer(SPoint2(midpoint[0], midpoint[1]));
//     SVector3 s1 = der.first();
//     SVector3 s2 = der.second();
//     SVector3 n = crossprod(s1, s2);
//     n.normalize();

//     int loop [8] = {0,4,1,7,2,6,3,5};
//     SVector3 t0[8],t1[8];
//     GPoint p0[8];
//     std::vector<double> dots;
//     std::vector<SPoint3> pts;
//     for (int i=0;i<8;i++){
//       p0[i] = gf->point(newP[loop[i]]);
//       (*f)(p0[i].x(), p0[i].y(),p0[i].z(),t0[i], gf);
//       t0[i] -= n*dot(t0[i],n);
//       t0[i].normalize();
//       t1[i] = crossprod(n, t0[i]);
//       t1[i].normalize();
//     }
//     int nSamples = 30;
//     SPoint3 p(it->first->x(),it->first->y(),it->first->z());
//     for (int i=0;i<8;i++){
//       SVector3 t0i = t0[i];
//       SVector3 t1i = t1[i];
//       SVector3 t0n = t0[(i+1)%8];
//       SVector3 t1n = t1[(i+1)%8];
//       if (fabs(dot(t0i,t0n)) < fabs(dot(t0i,t1n))){
// 	SVector3 temp_ = t0n;
// 	t0n = t1n;
// 	t1n = temp_;
//       }
//       if (dot(t0i,t0n) < 0)t0n = t0n * (-1.0);
//       if (dot(t1i,t1n) < 0)t1n = t1n * (-1.0);

//       GPoint pi = p0[i];
//       GPoint pn = p0[(i+1)%8];
//       fprintf(_f,"SP(%g,%g,%g){%d};\n",
// 	      pi.x(),pi.y(),pi.z(),i);
//       for (int j=0;j<nSamples;j++){
// 	double xi = (double)j/(nSamples);
// 	SPoint3 pij (pi.x()*(1-xi)+pn.x()*xi,pi.y()*(1-xi)+pn.y()*xi,pi.z()*(1-xi)+pn.z()*xi);
// 	SVector3 vij = p-pij;
// 	pts.push_back (pij);
// 	vij.normalize();
// 	SVector3 v0 = t0i*(1-xi) + t0n*xi;
// 	SVector3 v1 = t1i*(1-xi) + t1n*xi;
// 	v0.normalize();
// 	v1.normalize();
// 	double dot0 = fabs(dot(v0,vij));
// 	double dot1 = fabs(dot(v1,vij));
// 	dots.push_back(std::max(dot0,dot1));
// 	fprintf(_f,"VP(%g,%g,%g){%g,%g,%g};\n",
// 		pij.x(),pij.y(),pij.z(),
// 		dot0*v0.x(),dot0*v0.y(),dot0*v0.z());
// 	fprintf(_f,"VP(%g,%g,%g){%g,%g,%g};\n",
// 		pij.x(),pij.y(),pij.z(),
// 		dot1*v1.x(),dot1*v1.y(),dot1*v1.z());
//       }
//     }

//     int nbMax = 0;
//     for (size_t i=0;i<pts.size();i++){
//       double V0 = dots[i];
//       double V1 = dots[(i+1)%pts.size()];
//       double V2 = dots[(i+2)%pts.size()];
//       if (V1 > V0 && V1 > V2){
// 	double uvt[2] = {0,0};
// 	GPoint pp = gf->closestPoint(pts[i] ,uvt);
// 	MFaceVertex *vv = new MFaceVertex (pp.x(),pp.y(),pp.z(),gf,pp.u(),pp.v());
// 	toInsert.push_back(vv);
// 	nbMax++;
//       }
//     }
//     if (nbMax == it-> second)printf("singularity %lu has a good set of %d sampling points\n",it->first->getNum(),nbMax);
//     else {
//       toInsert.resize(toInsert.size() - nbMax);
//       printf("singularity %lu has a bad set of %d vs %d sampling points\n",it->first->getNum(),nbMax,it->second);
//     }
//   }

//   fprintf(_f,"};\n");
//   fclose(_f);

// }



static bool outBounds(SPoint2 p, double minu, double maxu, double minv, double maxv){
  if (p.x() > maxu || p.x() <  minu || p.y() > maxv || p.y() <  minv){
    //    printf("OUT BOUND %g %g\n",p.x(),p.y());
    return true;

  }
  return false;
}

static bool close2sing(std::vector<MVertex*> &s, GFace *gf, SPoint2 p, Field *f){

  if (s.empty())return false;
  GPoint gp = gf->point(p);
  SVector3 t1;
  (*f)(gp.x(), gp.y(), gp.z(), t1, gf);
  double L = t1.norm();

  for (size_t i=0;i<s.size();i++){
    MVertex *v = s[i];
    double d = sqrt ((v->x()-gp.x())*(v->x()-gp.x())+
		     (v->y()-gp.y())*(v->y()-gp.y())+
		     (v->z()-gp.z())*(v->z()-gp.z()));
    if (d < FACTOR*L)return true;
  }
  return false;
}


static void findPhysicalGroupsForSingularities(GFace *gf,
                                               std::map<MVertex *, int> &temp)
{

  std::set<GVertex *, GEntityPtrLessThan> emb = gf->embeddedVertices();
  if (emb.empty())return;

  std::map<int, std::vector<GEntity *> > groups[4];
  gf->model()->getPhysicalGroups(groups);
  for(std::map<int, std::vector<GEntity *> >::iterator it = groups[0].begin();
      it != groups[0].end(); ++it) {
    std::string name = gf->model()->getPhysicalName(0, it->first);
    if(name == "SINGULARITY_OF_INDEX_THREE") {
      for(size_t j = 0; j < it->second.size(); j++) {
	if (emb.find((GVertex*)it->second[j]) != emb.end()){
	  if(!it->second[j]->mesh_vertices.empty())
	    temp[it->second[j]->mesh_vertices[0]] = 3;
	}
      }
    }
    else if(name == "SINGULARITY_OF_INDEX_FIVE") {
      for(size_t j = 0; j < it->second.size(); j++) {
	if (emb.find((GVertex*)it->second[j]) != emb.end()){
	  if(!it->second[j]->mesh_vertices.empty())
	    temp[it->second[j]->mesh_vertices[0]] = 5;
	}
      }
    }
    else if(name == "SINGULARITY_OF_INDEX_SIX") {
      for(size_t j = 0; j < it->second.size(); j++) {
	if (emb.find((GVertex*)it->second[j]) != emb.end()){
	  if(!it->second[j]->mesh_vertices.empty())
	    temp[it->second[j]->mesh_vertices[0]] = 6;
	}
      }
    }
  }
}


void packingOfParallelograms(GFace *gf, std::vector<MVertex *> &packed,
                             std::vector<SMetric3> &metrics)
{

  //  printf("ALGO %d %d\n", CTX::instance()->mesh.algo2d,
  //	 CTX::instance()->mesh.algo2d == ALGO_2D_QUAD_QUASI_STRUCT);

  FILE *f = NULL;
  FILE *f2 = NULL;
  if(Msg::GetVerbosity() == 99) {
    char ccc[256];
    sprintf(ccc, "points%d.pos", gf->tag());
    f = Fopen(ccc, "w");
    sprintf(ccc, "e_points%d.pos", gf->tag());
    f2 = Fopen(ccc, "w");
    if(f) fprintf(f, "View \"\"{\n");
    if(f2) fprintf(f2, "View \"\"{\n");
  }

  FieldManager *fields = gf->model()->getFields();
  Field *cross_field = NULL;
  SVector3 t1;
  double L;
  if(fields->getBackgroundField() > 0) {
    cross_field = fields->get(fields->getBackgroundField());
    if(cross_field->numComponents() != 3) {// we hae a true scaled cross fields !!
      Msg::Error ("Packing of Parallelograms require a scaled cross field");
      Msg::Error ("Do first gmsh yourmeshname.msh -crossfield to create yourmeshname_scaled_crossfield.pos");
      Msg::Error ("Then do yourmeshname.geo -bgm yourmeshname_scaled_crossfield.pos");
      return;
    }
  }
  else {
    Msg::Error ("Packing of Parallelograms require a scaled cross field");
    Msg::Error ("Do first gmsh yourmeshname.msh -crossfield to create yourmeshname_scaled_crossfield.pos");
    Msg::Error ("Then do yourmeshname.geo -bgm yourmeshname_scaled_crossfield.pos");
    return;
  }


  const bool goNonLinear = true;

  // get all the boundary vertices
  std::set<MVertex *, MVertexPtrLessThan> bnd_vertices;
  for(unsigned int i = 0; i < gf->getNumMeshElements(); i++) {
    MElement *element = gf->getMeshElement(i);
    for(std::size_t j = 0; j < element->getNumVertices(); j++) {
      MVertex *vertex = element->getVertex(j);
      if(vertex->onWhat()->dim() < 2) bnd_vertices.insert(vertex);
    }
  }

  // Renormalize size map taking into account quantization...
  double globalMult = 1.0;

  // put boundary vertices in a fifo queue
  std::queue<surfacePointWithExclusionRegion *> fifo;
  std::vector<surfacePointWithExclusionRegion *> vertices;
  // put the RTREE
  RTree<surfacePointWithExclusionRegion *, double, 2, double> rtree;
  SMetric3 metricField(1.0);
  SPoint2 newp[8];
  std::set<MVertex *, MVertexPtrLessThan>::iterator it = bnd_vertices.begin();

  double maxu = -1.e22,minu = 1.e22;
  double maxv = -1.e22,minv = 1.e22;

  std::vector<MVertex*> singularities;
  for(; it != bnd_vertices.end(); ++it) {

    int NP = 0;
    SPoint2 midpoint;
    double du[4] = {0,0,0,0}, dv[4]= {0,0,0,0};

    //    printf("cop %d\n",(*it)->getNum());
    
    for (int i=0;i<2;i++){
      if (gf->periodic(i)){
	reparamMeshVertexOnFace(*it, gf, midpoint);
	Range<double> bnds = gf->parBounds(i);
	//	if (1 || midpoint[i] == bnds.low()){
	if (i == 0)
	  du[NP] =  bnds.high() -  bnds.low();
	else
	  dv[NP] =  bnds.high() -  bnds.low();
	NP++;
	//	}
	//	else if (midpoint[i] == bnds.high()){
	if (i == 0)
	  du[NP] =  -(bnds.high() -  bnds.low());
	else
	  dv[NP] =  -(bnds.high() -  bnds.low());
	NP++;
	//	}
      }
    }

    if (NP == 0)NP=1;
    
    for (int i=0;i<NP;i++){
      bool singular = !compute4neighbors(gf, *it, midpoint, newp, metricField, cross_field, du[i],dv[i],globalMult );
      //      printf("there %d %g %g\n",singular,du[i],dv[i]);
      if (!singular){
	surfacePointWithExclusionRegion *sp =
	  new surfacePointWithExclusionRegion(*it, newp, midpoint, metricField);
	minu = std::min(midpoint.x(),minu);
	maxu = std::max(midpoint.x(),maxu);
	minv = std::min(midpoint.y(),minv);
	maxv = std::max(midpoint.y(),maxv);
	vertices.push_back(sp);
	fifo.push(sp);
	double _min[2], _max[2];
	sp->minmax(_min, _max);
	rtree.Insert(_min, _max, sp);
      }
      else{
	singularities.push_back(*it);
	break;
      }
    }
  }

  __OK = 0;
  __KO = 0;

  while(!fifo.empty()) {
    //    printf("%d vertices in the domain\n",vertices.size());
    //    if (vertices.size() > 5000)break;
    surfacePointWithExclusionRegion *parent = fifo.front();
    fifo.pop();
    for(int i = 0; i < 4; i++) {
      if(!close2sing (singularities,gf,parent->_p[i],cross_field)
	 && !inExclusionZone(parent->_v, parent->_p[i], rtree) &&
	 !outBounds(parent->_p[i],minu,maxu,minv,maxv)
	 && (gf->getNativeType() == GEntity::GmshModel || gf->containsParam(parent->_p[i])))
	{
	  GPoint gp = gf->point(parent->_p[i]);
	  MFaceVertex *v =
	    new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, gp.u(), gp.v());
	  SPoint2 midpoint;
	  compute4neighbors(gf, v, midpoint, newp, metricField, cross_field,0, 0, globalMult);
	  surfacePointWithExclusionRegion *sp =
	    new surfacePointWithExclusionRegion(v, newp, midpoint, metricField, parent);
	  fifo.push(sp);
	  vertices.push_back(sp);
	  double _min[2], _max[2];
	  sp->minmax(_min, _max);
	  rtree.Insert(_min, _max, sp);
	}
      else{
	//	printf("%d %d\n", inExclusionZone(parent->_v, parent->_p[i], rtree), outBounds(parent->_p[i],minu,maxu,minv,maxv));
	if(Msg::GetVerbosity() == 99) {
	  GPoint gp = gf->point(parent->_p[i]);
	  MFaceVertex *v =
	    new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, gp.u(), gp.v());
	  SPoint2 midpoint;
	  compute4neighbors(gf, v, midpoint, newp, metricField, cross_field, 0, 0 , globalMult);
	  surfacePointWithExclusionRegion *sp =
	    new surfacePointWithExclusionRegion(v, newp, midpoint, metricField,parent);
	  //	  if (!gf->containsParam(parent->_p[i]))
	  sp->print(f2, i);
	}
      }
    }
  }

  //  printf("%d %d\n",__OK,__KO);
  //  getchar();
  // add the vertices as additional vertices in the surface mesh
  for(unsigned int i = 0; i < vertices.size(); i++) {
    if (f)vertices[i]->print(f, i);
    if(vertices[i]->_v->onWhat() == gf) {
      packed.push_back(vertices[i]->_v);
      metrics.push_back(vertices[i]->_meshMetric);
      SPoint2 midpoint;
      reparamMeshVertexOnFace(vertices[i]->_v, gf, midpoint);
    }
    delete vertices[i];
  }
  if (f){
    fprintf(f2, "};");
    fclose(f2);
    fprintf(f, "};");
    fclose(f);
  }
}

/* OLD STUFF

   double uvt[3] = {newPoint[0], newPoint[1], 0.0};
  curveFunctorCircle cc(n2, n1, middle, d);
  surfaceFunctorGFace ss(gf);

  if(intersectCurveSurface(cc, ss, uvt, d * 1.e-8)) {
    // if(gf->containsParam(SPoint2(uvt[0], uvt[1]))) {
      newPoint[0] = uvt[0];
      newPoint[1] = uvt[1];
      return true;
    // }
  }


  surfaceFunctorGFace ss(gf); //
  SVector3 dirs[4] = {t1 * (-1.0), t2 * (-1.0), t1 * (1.0), t2 * (1.0)}; //
  for(int i = 0; i < 4; i++) { //
    double uvt[3] = {newPoint[i][0], newPoint[i][1], 0.0}; //

    curveFunctorCircle cf(
			  dirs[i], n, SVector3(v_center->x(), v_center->y(), v_center->z()),
			  L);
    if(intersectCurveSurface(cf, ss, uvt, size_1 * 1.e-2)) { //
      GPoint pp = gf->point(SPoint2(uvt[0], uvt[1]));
      double D =
	sqrt((pp.x() - v_center->x()) * (pp.x() - v_center->x()) +
	     (pp.y() - v_center->y()) * (pp.y() - v_center->y()) +
	     (pp.z() - v_center->z()) * (pp.z() - v_center->z()));
      double DP =
	sqrt((newPoint[i][0] - uvt[0]) * (newPoint[i][0] - uvt[0]) +
	     (newPoint[i][1] - uvt[1]) * (newPoint[i][1] - uvt[1]));
      double newErr = 100 * fabs(D - L) / (D + L);
      if(newErr < 1 && DP < .1) {
	newPoint[i][0] = uvt[0];
	newPoint[i][1] = uvt[1];
      }
      else {
	SPoint3 test (v_center->x() + dirs[i].x() * L,
		      v_center->y() + dirs[i].y() * L,
		      v_center->z() + dirs[i].z() * L);


	GPoint pp = gf->closestPoint(test,uvt);
	if (pp.succeeded()){
	  newPoint[i][0] = pp.u();
	  newPoint[i][1] = pp.v();
	}
	else return false;
      }
    }
    else {
      SPoint3 test (v_center->x() + dirs[i].x() * L,
		    v_center->y() + dirs[i].y() * L,
		    v_center->z() + dirs[i].z() * L);


      GPoint pp = gf->closestPoint(test,uvt);
      if (pp.succeeded()){
	newPoint[i][0] = pp.u();
	newPoint[i][1] = pp.v();
      }
      else return false;
    }
  }


  // return the four new vertices
  for(int i = 0; i < 4; i++) {
    newP[i] = SPoint2(newPoint[i][0], newPoint[i][1]);
  }
  return true;

 */
