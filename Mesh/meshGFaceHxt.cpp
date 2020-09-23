#include "GmshConfig.h"
#include "GModel.h"
#include "meshGRegionHxt.h"
#include "meshGFaceHxt.h"
#include "Context.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "MLine.h"
#include "GFace.h"
#include "GmshMessage.h"
// #include "gmshCrossFields.h"
#include "fastScaledCrossField.h"
#include "meshWinslow2d.h"
#include "geolog.h"

#include "gmsh.h"

#if defined(HAVE_HXT)
extern "C" {
  //#include "hxt_mesh.h"
    #include "hxt_gmsh_point_gen_main.h"
    #include "hxt_point_gen_options.h"
}

static HXTStatus messageCallback(HXTMessage *msg)
{
  if(msg) Msg::Info("%s", msg->string);
  return HXT_STATUS_OK;
}

static inline SVector3 tri_normal(MTriangle* t) {
  SVector3 v10(t->getVertex(1)->x() - t->getVertex(0)->x(),
               t->getVertex(1)->y() - t->getVertex(0)->y(),
               t->getVertex(1)->z() - t->getVertex(0)->z());
  SVector3 v20(t->getVertex(2)->x() - t->getVertex(0)->x(),
               t->getVertex(2)->y() - t->getVertex(0)->y(),
               t->getVertex(2)->z() - t->getVertex(0)->z());
  SVector3 normal_to_triangle = crossprod(v20, v10);
  normal_to_triangle.normalize();
  return normal_to_triangle;
}

inline std::array<double,3> convert(const SVector3& vec) {
  return {vec.data()[0],vec.data()[1],vec.data()[2]};
}

inline std::vector<std::array<double,3> > convert(const std::vector<SVector3>& vecs) {
  std::vector<std::array<double,3> > vecs2(vecs.size());
  for (size_t i = 0; i < vecs2.size(); ++i) vecs2[i] = convert(vecs[i]);
  return vecs2;
}

using vec3 = std::array<double,3>;

int computeCrossFieldAndScalingForHxt(
    GModel* gm,
    size_t targetNumberOfQuads,
    const std::vector<MVertex*>& vertices,
    std::map<size_t, std::array<double,7> >& vertexDirections) 
{
  Msg::Debug("compute cross field and scaling for Hxt ...");

#ifdef HAVE_QUADMESHINGTOOLS
  std::vector<GFace*> faces;
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    faces.push_back(*it);
  }

  int nbDiffusionLevels = 7;
  double thresholdNormConvergence = 1.e-2;
  int nbBoundaryExtensionLayer = 1;

  /* Compute cross field */
  std::map<std::array<size_t,2>,double> edgeTheta;
  for (GFace* gf: faces) {
    Msg::Debug("- compute cross field for face %i ...",gf->tag());
    int status = computeCrossFieldWithHeatEquation({gf}, edgeTheta, nbDiffusionLevels, thresholdNormConvergence,
        nbBoundaryExtensionLayer);
    if (status != 0) {
      Msg::Error("failed to compute cross field for face %i",gf->tag());
    }
  }

  /* Compute sizemap from cross field */
  std::vector<size_t> nodeTags;
  std::vector<double> scaling;
  int status = computeCrossFieldScaling(faces, edgeTheta, targetNumberOfQuads, nodeTags, scaling);
  if (status != 0) {
    Msg::Error("failed to compute cross field scaling");
    return -1;
  }

  /* Extract values at triangle corners */
  std::map<size_t, std::array<double,9> > triangleDirections;
  int st2 = extractPerTriangleScaledCrossFieldDirections(faces, edgeTheta, nodeTags, scaling, triangleDirections);
  if (st2 != 0) {
    Msg::Error("failed to extract per triangle scaled directions");
    return -1;
  }

  std::vector<MTriangle*> t2ptr(triangleDirections.size(),NULL);
  for (GFace* gf: faces) {
    for (MTriangle* t: gf->triangles) {
      size_t tNum = t->getNum();
      if (tNum >= t2ptr.size()) t2ptr.resize(tNum+1,NULL);
      t2ptr[tNum] = t;
    }
  }

  std::set<size_t> isBoundary;
  for(GModel::eiter it = gm->firstEdge(); it != gm->lastEdge(); ++it) {
    GEdge *ge = *it;
    for (size_t i=0; i<ge->lines.size(); i++){
      MLine *l = ge->lines[i];

      size_t n0 = l->getVertex(0)->getNum();
      size_t n1 = l->getVertex(1)->getNum();


      isBoundary.insert(n0);
      isBoundary.insert(n1);



      MVertex *v0 = l->getVertex(0);
      MVertex *v1 = l->getVertex(1);
      GeoLog::add(convert(v0->point()),1,"boundary");
      GeoLog::add(convert(v1->point()),1,"boundary");



    }
  }

 

  std::array<double,7> zero7 = {0.,0.,0.,0.,0.,0.,0.};
  std::vector<std::array<double,7> > vertexNumDirections(vertices.size(),zero7);
  for (const auto& kv: triangleDirections) {
    MTriangle* t = t2ptr[kv.first];
    if (t == NULL) continue;
    SVector3 N = tri_normal(t);
    for (size_t lv = 0; lv < 3; ++lv) {
      size_t num = t->getVertex(lv)->getNum();
      if (num >= vertexNumDirections.size()) vertexNumDirections.resize(num+1,zero7);
      std::array<double,7>& vDirs = vertexNumDirections[num];
      SVector3 dir1(vDirs[0],vDirs[1],vDirs[2]);
      SVector3 dir2(vDirs[3],vDirs[4],vDirs[5]);
      double d1best = -DBL_MAX;
      double d2best = -DBL_MAX;
      SVector3 d1bestV;
      SVector3 d2bestV;

      SVector3 dir(kv.second[3*lv+0],kv.second[3*lv+1],kv.second[3*lv+2]);
      SVector3 dir_orth = crossprod(dir,N);
      dir.normalize();
      dir_orth.normalize();

      std::set<size_t>::iterator it = isBoundary.find(num);
      if (it != isBoundary.end() && dir1.normSq()==0 && dir2.normSq() == 0.){

        for (size_t d = 0; d < 3; ++d) {
          vDirs[d] = dir[d];
          vDirs[3+d] = dir_orth[d];
        }

        SVector3 pt = t->getVertex(lv)->point();
        GeoLog::add(convert(pt), convert(&vDirs[0]),"dir_a1");
        GeoLog::add(convert(pt), convert(&vDirs[3]),"dir_a2");
      }

      if (it != isBoundary.end()) continue;

      
      {
        SVector3 pt = t->getVertex(lv)->point();
        GeoLog::add(convert(pt), convert(dir),"dir");
        GeoLog::add(convert(pt), convert(dir_orth),"dir_orth");
      }
      if (dir1.normSq() == 0. && dir2.normSq() == 0.) {
        d1bestV = dir;
        d2bestV = dir_orth;
      } 
      else {
        SVector3 candidates[4] = {dir,-1.*dir,dir_orth,-1.*dir_orth};
        for (size_t k = 0; k < 4; ++k) {
          double dp1 = dot(dir1,candidates[k]);
          double dp2 = dot(dir2,candidates[k]);
          if (dp1 > d1best) {
            d1best = dp1;
            d1bestV = candidates[k];
          }
          if (dp2 > d2best) {
            d2best = dp2;
            d2bestV = candidates[k];
          }
        }
      }
      for (size_t d = 0; d < 3; ++d) {
        vDirs[d] += d1bestV[d];
        vDirs[3+d] += d2bestV[d];
      }
    }
  }

  for (MVertex* v: vertices) {
    const std::array<double,7>& vDirs = vertexNumDirections[v->getNum()];
    SVector3 dir1(vDirs[0],vDirs[1],vDirs[2]);
    SVector3 dir2(vDirs[3],vDirs[4],vDirs[5]);
    dir1.normalize();
    dir2.normalize();
    vertexDirections[v->getNum()] = {dir1[0],dir1[1],dir1[2], dir2[0],dir2[1],dir2[2], 0.};
  }
  for (size_t i = 0; i < nodeTags.size(); ++i) {
    vertexDirections[nodeTags[i]][6] = scaling[i];
  }

#else
  Msg::Error("Computation of scaled cross field requires the QuadMeshingTools module");
  return -1;
#endif

  return 0;
}

int meshGFaceHxt(GModel *gm)
{
  Msg::Debug("mesh CAD faces with Hxt ...");

  HXT_CHECK(hxtSetMessageCallback(messageCallback));

  gm->createTopologyFromMesh();

  HXTMesh *mesh;
  HXT_CHECK(hxtMeshCreate(&mesh));

  std::map<MVertex *, uint32_t> v2c;
  std::vector<MVertex *> c2v;
  HXT_CHECK(Gmsh2Hxt(gm, mesh, v2c, c2v));

  size_t targetNumberOfQuads = 10000;

  printf("Target quad numbers = \n");
  size_t temp = 0;
  scanf("%d",&temp);
  targetNumberOfQuads = temp;

  

  std::map<size_t, std::array<double,7> > vertexDirections;
  int st = computeCrossFieldAndScalingForHxt(gm, targetNumberOfQuads, c2v, vertexDirections);
  if (st != 0) {
    Msg::Error("failed to compute cross field and scaling for hxt");
    return -1;
  }

  std::vector<double> data(7*c2v.size(),0.);
  {
    std::vector<MVertex*> v2ptr(c2v.size(),NULL);
    for (MVertex* v: c2v) {
      size_t num = v->getNum();
      if (num >= v2ptr.size()) v2ptr.resize(num+1,NULL);
      v2ptr[num] = v;
    }
    for (MVertex* v: c2v) {
      uint32_t c = v2c[v];
      for (size_t k = 0; k < 7; ++k) {
        data[7*c+k] = vertexDirections[v->getNum()][k];
      }
    }
  }
  for (MVertex* v: c2v) {
    SVector3 d1(
        vertexDirections[v->getNum()][0],
        vertexDirections[v->getNum()][1],
        vertexDirections[v->getNum()][2]);
    SVector3 d2(
        vertexDirections[v->getNum()][3],
        vertexDirections[v->getNum()][4],
        vertexDirections[v->getNum()][5]);
    GeoLog::add(convert(v->point()),convert(d1),"d1");
    GeoLog::add(convert(v->point()),convert(d2),"d2");
    GeoLog::add(convert(v->point()),vertexDirections[v->getNum()][6],"sizemap");
  }

  //gmsh::initialize();
  //GeoLog::flush();
  //gmsh::fltk::run();
  //return 0;


  // std::map<int, std::vector<double> > dataH;
  // std::map<int, std::vector<double> > dataDir;
  // std::map<int, std::vector<double> > dataDirOrtho;
  // computeCrossFieldAndH(gm,dataH,dataDir,dataDirOrtho);


  // /// put the cross field and conformal factor into a big vector
  // double *data = (double*)malloc(c2v.size()*sizeof(double)*7);
  // for (size_t i = 0; i< c2v.size()*7 ; i++)data [i] = 0.0;
  // 
  // std::map<int, std::vector<double> > :: iterator it = dataDir.begin();
  // for ( ; it != dataDir.end() ; ++it){
  //   MElement *e = gm->getMeshElementByTag (it->first);
  //   std::vector<double> &dir      = it->second;
  //   std::vector<double> &dirOrtho = dataDirOrtho[it->first];
  //   SVector3 t1 (dir[0],dir[1],dir[2]);
  //   SVector3 t2 (dirOrtho[0],dirOrtho[1],dirOrtho[2]);
  //   SVector3 n = crossprod(t1,t2);
  //   
  //   for (size_t i=0;i< e->getNumVertices();i++){
  //     MVertex *v = e->getVertex (i);
  //     if (v2c.find(v)  == v2c.end())Msg::Error ("FILE %s LINE %d Cannot find vertex %lu",__FILE__,__LINE__,v->getNum()); 
  //     if (v2c[v] >= v2c.size())Msg::Error ("FILE %s LINE %d Bad numbering v2c[%lu] = %lu",__FILE__,__LINE__,v->getNum(),v2c[v]); 
  //     double *nn = data+7*v2c[v];
  //     nn[0] += n[0];
  //     nn[1] += n[1];
  //     nn[2] += n[2];
  //     SVector3 t (nn[3],nn[4],nn[5]);
  //     if (t.norm () < 1.e-12){
	// nn[3] = t1.x();
	// nn[4] = t1.y();
	// nn[5] = t1.z();
  //     }
  //     else {
	// double x0 = dot (t,t1);
	// double x1 = dot (t,-t1);
	// double x2 = dot (t,t2);
	// double x3 = dot (t,-t2);
	// if (x0 > x1 && x0 > x2 && x0 > x3){
	//   nn[3]+= t1.x();nn[4]+= t1.y();nn[5]+= t1.z();
	// }
	// else if (x1 > x0 && x1 > x2 && x1 > x3){
	//   nn[3]-= t1.x();nn[4]-= t1.y();nn[5]-= t1.z();
	// }
	// else if (x2 > x0 && x2 > x1 && x2 > x3){
	//   nn[3]+= t2.x();nn[4]+= t2.y();nn[5]+= t2.z();
	// }
	// else{
	//   nn[3]-= t2.x();nn[4]-= t2.y();nn[5]-= t2.z();
	// }	  
  //     }
  //   }    
  // }
  // 
  // for (size_t i = 0; i< c2v.size() ; i++){
  //   double *n = data+ 7*i;
  //   
  //   SVector3 t (n[0],n[1],n[2]); t.normalize();
  //   n[0] = t.x();n[1] = t.y();n[2] = t.z();
  //   t = SVector3(n[3],n[4],n[5]); t.normalize();
  //   n[3] = t.x();n[4] = t.y();n[5] = t.z();
  //   
  //   if (dataH.find(c2v[i]->getNum()) != dataH.end()){    
  //     n[6] = dataH[c2v[i]->getNum()][0];
  //   }
  //   else {
  //     Msg::Warning ("Vertex %lu has no value for H",c2v[i]->getNum());
  //   }
  // }
  
  ///// HERE WE NEED THE CODE TO THE REMESHING STUFF
   
  HXTMesh *fmesh;
  HXT_CHECK(hxtMeshCreate(&fmesh));

  // TODO 
  HXTPointGenOptions opt = { .verbosity = 0,
                             .generateLines = 1,
                             .generateSurfaces = 1,
                             .generateVolumes = 0,
                             .remeshSurfaces = 1,
                             .quadSurfaces = 1,
                             .walkMethod2D = 1,
                             .walkMethod3D = 0,
                             .dirType = 0,
                             .uniformSize = 1.0,
                             .areaThreshold = 10e-9,
                             .tolerance = 10e-9,
                             .numTris = 0};


  HXT_CHECK(hxtGmshPointGenMain(mesh,&opt,data.data(),fmesh));
  v2c.clear();
  c2v.clear();
  //  HXT_CHECK(Hxt2Gmsh(gm, fmesh, v2c, c2v));

  GModel *gm2 = new GModel(gm->getName());
  
  gm2->readMSH("finalmesh.msh");	  	  

  printf("WINSLOW START\n");
  meshWinslow2d (gm2);
  printf("WINSLOW ENDS\n");
  gm2->writeMSH("finalmesh_smoothed.msh", 4.0, false, true);	  	  
  HXT_CHECK(hxtMeshDelete(&fmesh));
 
 
  ///// END OF HERE WE NEED THE CODE TO THE REMESHING STUFF

  HXT_CHECK(hxtMeshDelete(&mesh));
  
  //  meshWinslow2d (gm);
  
  return 0;
}


#else

int meshGFaceHxt(GModel *gm)
{
  Msg::Error("Gmsh should be compiled with Hxt to enable this option");
  return -1;
}

#endif
