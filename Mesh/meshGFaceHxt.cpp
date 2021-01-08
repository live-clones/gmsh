#include "GmshConfig.h"
#include "GModel.h"
#include "meshGRegionHxt.h"
#include "meshGFaceHxt.h"
#include "Context.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "MLine.h"
#include "MEdge.h"
#include "MEdgeHash.h"
#include "GFace.h"
#include "GmshMessage.h"
// #include "gmshCrossFields.h"
#include "fastScaledCrossField.h"
#include "meshWinslow2d.h"
#include "Field.h"
#include "meshGFaceOptimize.h"
#include "meshQuadQuasiStructured.h"
#include "qmt_utils.hpp"


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

int Gmsh2Hxt(GFace *gf, HXTMesh *m,
		   std::map<MVertex *, uint32_t> &v2c,
       std::vector<MVertex *> &c2v) 
{
  c2v.clear();
  v2c.clear();

  c2v.reserve(2*gf->mesh_vertices.size());
  uint32_t vcount = 0;
  std::vector<uint32_t> nodes;
  std::vector<std::array<uint32_t,2> > lines;
  std::vector<std::array<uint32_t,3> > triangles;
  std::vector<std::array<uint32_t,4> > quads;
  std::vector<uint16_t> nodes_color;
  std::vector<uint16_t> lines_color;
  std::vector<uint16_t> triangles_color;
  std::vector<uint16_t> quads_color;

  /* Loop over CAD nodes */
  for (GVertex* gv: gf->vertices())  {
    if (gv->mesh_vertices.size() != 1) continue;
    MVertex* v = gv->mesh_vertices[0];
    auto it = v2c.find(v);
    size_t nv = 0;
    if (it == v2c.end()) {
      v2c[v] = vcount;
      nv = vcount;
      c2v.push_back(v);
      vcount += 1;
    } else {
      nv = it->second;
    }
    nodes.push_back(nv);
    nodes_color.push_back((uint16_t)gv->tag());
  }

  /* Loop over CAD curves */
  std::vector<GEdge*> edges = gf->edges();
  std::sort(edges.begin(),edges.end());
  edges.erase(std::unique(edges.begin(),edges.end()),edges.end());

  //for (GEdge* ge: gf->edges()) {
  for (GEdge* ge: edges){
    for (MLine* l: ge->lines) {
      std::array<uint32_t,2> line;
      for (size_t lv = 0; lv < 2; ++lv) {
        MVertex* v = l->getVertex(lv);
        auto it = v2c.find(v);
        if (it == v2c.end()) {
          v2c[v] = vcount;
          line[lv] = vcount;
          c2v.push_back(v);
          vcount += 1;
        } else {
          line[lv] = it->second;
        }
      }
      lines.push_back(line);
      lines_color.push_back((uint16_t)ge->tag());
    }
  }

  /* Loop over elements */
  triangles.reserve(gf->triangles.size());
  triangles_color.reserve(gf->triangles.size());
  for (MTriangle* f: gf->triangles) {
    std::array<uint32_t,3> tri;
    for (size_t lv = 0; lv < 3; ++lv) {
      MVertex* v = f->getVertex(lv);
      auto it = v2c.find(v);
      if (it == v2c.end()) {
        v2c[v] = vcount;
        tri[lv] = vcount;
        c2v.push_back(v);
        vcount += 1;
      } else {
        tri[lv] = it->second;
      }
    }
    triangles.push_back(tri);
    triangles_color.push_back((uint16_t)gf->tag());
  }
  quads.reserve(gf->quadrangles.size());
  quads_color.reserve(gf->quadrangles.size());
  for (MQuadrangle* f: gf->quadrangles) {
    std::array<uint32_t,4> quad;
    for (size_t lv = 0; lv < 4; ++lv) {
      MVertex* v = f->getVertex(lv);
      auto it = v2c.find(v);
      if (it == v2c.end()) {
        v2c[v] = vcount;
        quad[lv] = vcount;
        c2v.push_back(v);
        vcount += 1;
      } else {
        quad[lv] = it->second;
      }
    }
    quads.push_back(quad);
    quads_color.push_back((uint16_t)gf->tag());
  }
  

  /* Fill HXTMesh */
  /* - vertices */
  m->vertices.num = m->vertices.size = c2v.size();
  HXT_CHECK(
      hxtAlignedMalloc(&m->vertices.coord, 4 * m->vertices.num * sizeof(double)));
  for (size_t i = 0; i < c2v.size(); ++i) {
    MVertex* v = c2v[i];
    m->vertices.coord[4 * i + 0] = v->x();
    m->vertices.coord[4 * i + 1] = v->y();
    m->vertices.coord[4 * i + 2] = v->z();
    m->vertices.coord[4 * i + 3] = 0;
  }

  /* - points */
  m->points.num = m->points.size = nodes.size();
  HXT_CHECK(hxtAlignedMalloc(&m->points.node, (m->points.num) * sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&m->points.color, (m->points.num) * sizeof(uint16_t)));
  for(size_t i = 0; i < nodes.size(); i++) {
    m->points.node[i] = nodes[i];
    m->points.color[i] = nodes_color[i];
  }

  /* - lines */
  m->lines.num = m->lines.size = lines.size();
  HXT_CHECK(hxtAlignedMalloc(&m->lines.node, (m->lines.num) * 2 * sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&m->lines.color, (m->lines.num) * sizeof(uint16_t)));
  for(size_t i = 0; i < lines.size(); i++) {
    m->lines.node[2 * i + 0] = lines[i][0];
    m->lines.node[2 * i + 1] = lines[i][1];
    m->lines.color[i] = lines_color[i];
  }

  /* - triangles */
  m->triangles.num = m->triangles.size = triangles.size();
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.node, (m->triangles.num) * 3 * sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.color, (m->triangles.num) * sizeof(uint16_t)));
  for(size_t i = 0; i < triangles.size(); i++) {
    m->triangles.node[3 * i + 0] = triangles[i][0];
    m->triangles.node[3 * i + 1] = triangles[i][1];
    m->triangles.node[3 * i + 2] = triangles[i][2];
    m->triangles.color[i] = triangles_color[i];
  }

  /* - quads */
  m->quads.num = m->quads.size = quads.size();
  HXT_CHECK(hxtAlignedMalloc(&m->quads.node, (m->quads.num) * 4 * sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&m->quads.color, (m->quads.num) * sizeof(uint16_t)));
  for(size_t i = 0; i < quads.size(); i++) {
    m->quads.node[4 * i + 0] = quads[i][0];
    m->quads.node[4 * i + 1] = quads[i][1];
    m->quads.node[4 * i + 2] = quads[i][2];
    m->quads.node[4 * i + 3] = quads[i][3];
    m->quads.color[i] = quads_color[i];
  }

  return 0;
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
    std::vector<GFace*>& faces,
    size_t targetNumberOfQuads,
    const std::vector<MVertex*>& vertices,
    std::map<size_t, std::array<double,7> >& vertexDirections) 
{
  Msg::Debug("compute cross field and scaling for Hxt ...");

#ifdef HAVE_QUADMESHINGTOOLS

  int nbDiffusionLevels = 7;
  double thresholdNormConvergence = 1.e-2;
  int nbBoundaryExtensionLayer = 1;

  /* Compute cross field */
  std::unordered_map<MEdge,double,MEdgeHash,MEdgeEqual> edgeTheta;
  for (GFace* gf: faces) {
    Msg::Debug("- compute cross field for face %i ...",gf->tag());
    int status = computeCrossFieldWithHeatEquation({gf}, edgeTheta, nbDiffusionLevels, thresholdNormConvergence,
        nbBoundaryExtensionLayer);
    if (status != 0) {
      Msg::Error("failed to compute cross field for face %i",gf->tag());
    }
  }

  /* Compute conformal scaling (H) from cross field */
  std::unordered_map<MVertex*,double> scaling;
  std::vector<MTriangle*> triangles;
  getFacesTriangles(faces, triangles);
  int status = computeCrossFieldConformalScaling(triangles, edgeTheta, scaling);
  if (status != 0) {
    Msg::Error("failed to compute cross field scaling");
    return -1;
  }

  /* Compute sizemap (changing scaling) */
  Msg::Info("Compute quad mesh size map from conformal factor and %li target quads ...", 
      targetNumberOfQuads);
  std::vector<std::vector<GFace*> > components;
  getConnectedSurfaceComponents(faces, components);
  std::vector<size_t> componentNumberOfQuads;
  distributeQuadsBasedOnArea(targetNumberOfQuads, components, componentNumberOfQuads);
  for (size_t i = 0; i < components.size(); ++i) {
    std::vector<MTriangle*> componentTriangles;
    getFacesTriangles(components[i],componentTriangles);
    int status2 = computeQuadSizeMapFromCrossFieldConformalFactor(componentTriangles, componentNumberOfQuads[i], scaling);
    if (status2 != 0) {
      Msg::Error("Failed to compute quad mesh size map");
      return -1;
    }
  }

  /* Adapt size map to CAD */
  double smallestMultiplier = 0.05;
  double gradientMax = 1.15;
  bool oka = QSQ::adaptSizeMapToSmallFeatures(faces, scaling, smallestMultiplier, gradientMax);
  if (!oka) {
    Msg::Error("failed to adapt size map to smallest features");
  }

  /* Extract values at triangle corners */
  std::unordered_map<MTriangle*, std::array<double,9> > triangleDirections;
  int st2 = extractPerTriangleScaledCrossFieldDirections(triangles, edgeTheta, scaling, triangleDirections);
  if (st2 != 0) {
    Msg::Error("failed to extract per triangle scaled directions");
    return -1;
  }


  std::set<size_t> isBoundary;
  for (GFace* gf: faces) for (GEdge* ge: gf->edges()) {
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
    MTriangle* t = kv.first;
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
    vertexDirections[v->getNum()][6] = scaling[v];
  }

#else
  Msg::Error("Computation of scaled cross field requires the QuadMeshingTools module");
  return -1;
#endif

  return 0;
}

int readScaledCrossFieldFromBackgroundField(
    std::vector<GFace*>& faces,
    const std::vector<MVertex*>& vertices,
    std::map<size_t, std::array<double,7> >& vertexDirections) {

  Field* cross_field = NULL;
  if (faces.size() == 0) return -1;
  FieldManager *fields = faces[0]->model()->getFields();
  if(fields->getBackgroundField() > 0) {        
    cross_field = fields->get(fields->getBackgroundField());
    if(cross_field->numComponents() != 3) {// we hae a true scaled cross fields !!
      Msg::Error("The background field has the wrong number of components (expect 3)");
      return -1;
    }
  } else {
    Msg::Error("No background field");
    return -1;
  }

  if (cross_field->updateNeeded) {
    cross_field->update(); /* build octree ? */
  }

  std::array<double,7> zero7 = {0.,0.,0.,0.,0.,0.,0.};
  for (MVertex* v: vertices) {
    vertexDirections[v->getNum()] = zero7;
  }

  std::set<size_t> isBoundary;
  for (GFace* gf: faces) for (GEdge* ge: gf->edges()) {
    for (size_t i=0; i<ge->lines.size(); i++){
      MLine *l = ge->lines[i];
      size_t n0 = l->getVertex(0)->getNum();
      size_t n1 = l->getVertex(1)->getNum();
      isBoundary.insert(n0);
      isBoundary.insert(n1);
    }
  }

  for (GFace* gf: faces) {
    for (MTriangle* t: gf->triangles) {
      SVector3 N = tri_normal(t);
      for (size_t lv = 0; lv < 3; ++lv) {
        MVertex* v = t->getVertex(lv);
        size_t num = v->getNum();

        std::array<double,7>& vDirs = vertexDirections[num];
        SVector3 dir1(vDirs[0],vDirs[1],vDirs[2]);
        SVector3 dir2(vDirs[3],vDirs[4],vDirs[5]);
        double d1best = -DBL_MAX;
        double d2best = -DBL_MAX;
        SVector3 d1bestV;
        SVector3 d2bestV;


        SVector3 dir;
        (*cross_field)(v->x(), v->y(), v->z(), dir);
        SVector3 dir_orth = crossprod(dir,N);
        vDirs[6] = dir.norm();

        dir.normalize();
        dir_orth.normalize();

        std::set<size_t>::iterator it = isBoundary.find(num);
        if (it != isBoundary.end() && dir1.normSq()==0 && dir2.normSq() == 0.){
          for (size_t d = 0; d < 3; ++d) {
            vDirs[d] = dir[d];
            vDirs[3+d] = dir_orth[d];
          }
        }
        if (it != isBoundary.end()) continue;
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
  }

  return 0;
}


int getCrossFieldAndScaling(
    GModel* gm,
    Field *cross_field,
    const std::vector<MVertex*>& vertices,
    std::map<size_t, std::array<double,7> >& vertexDirections) 
{
  Msg::Debug("get cross field and scaling ...");

  std::vector<GFace*> faces;
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    faces.push_back(*it);
  }

  for (GFace* gf: faces) {
    v2t_cont adj;
    buildVertexToElement(gf->triangles, adj);

    std::map<MVertex*, double, MVertexPtrLessThan> sizes;
    v2t_cont::iterator it = adj.begin();
    while(it != adj.end()) {
      MVertex *v = it->first;
      SVector3 t1;
      (*cross_field)(v->x(), v->y(), v->z(), t1, gf);
      sizes[v] = t1.norm();
      ++it;
    }
  }
 




  std::array<double,7> zero7 = {0.,0.,0.,0.,0.,0.,0.};
  std::vector<std::array<double,7> > vertexNumDirections(vertices.size(),zero7);
 
  for (GFace* gf: faces) {
    for (MTriangle* t: gf->triangles) {
      if (t == NULL) continue;
      SVector3 N = tri_normal(t);
      for (size_t lv = 0; lv < 3; ++lv) {
/*        size_t num = t->getVertex(lv)->getNum();*/
        //if (num >= vertexNumDirections.size()) vertexNumDirections.resize(num+1,zero7);

        MVertex *v = t->getVertex(lv);

        std::cout << v->getNum() << std::endl;

        std::cout << v->x() << std::endl;

        SVector3 t1;

        std::cout << v->onWhat() << std::endl;


        int test = (*cross_field).numComponents(); 
        std::cout << test << std::endl;
        (*cross_field)(v->x(),v->y(),v->z(),t1,gf);
        std::cout << "ok"<<std::endl;
        //std::cout << t1.norm() << std::endl;
      }
 
    }
  }


  return 0;
}

int meshGFaceHxt(GModel *gm)
{
  Msg::Debug("mesh CAD faces with Hxt ...");
  gm->createTopologyFromMesh();

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

  std::vector<GFace*> faces;
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    faces.push_back(*it);
  }

  std::map<size_t, std::array<double,7> > vertexDirections;
  int st = computeCrossFieldAndScalingForHxt(faces, targetNumberOfQuads, c2v, vertexDirections);
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
                             .walkMethod2D = 0,
                             .walkMethod3D = 0,
                             .dirType = 0,
                             .uniformSize = 1.0,
                             .areaThreshold = 10e-9,
                             .tolerance = 10e-9,
                             .numTris = 0};


  if (Msg::GetVerbosity() == 99) opt.verbosity = 2;

  HXT_CHECK(hxtGmshPointGenMain(mesh,&opt,data.data(),fmesh));


  v2c.clear();
  c2v.clear();
  //  HXT_CHECK(Hxt2Gmsh(gm, fmesh, v2c, c2v));
  
  // NOT USED ANYMORE
  if(0){

    GModel *gm2 = new GModel(gm->getName());
    
    gm2->readMSH("finalmesh.msh");	  	  
    
    printf("WINSLOW START\n");
    meshWinslow2d (gm2);
    printf("WINSLOW ENDS\n");
    gm2->writeMSH("finalmesh_smoothed.msh", 4.0, false, true);	  	  
  }

  HXT_CHECK(hxtMeshDelete(&fmesh));
 
 
  ///// END OF HERE WE NEED THE CODE TO THE REMESHING STUFF

  HXT_CHECK(hxtMeshDelete(&mesh));
  
  //  meshWinslow2d (gm);
  
  return 0;
}

int meshGFaceHxt(GFace *gf) {
  Msg::Debug("- Face %li: generate quad mesh with hxt ...", gf->tag());
  HXT_CHECK(hxtSetMessageCallback(messageCallback));

  HXTMesh *mesh;
  HXT_CHECK(hxtMeshCreate(&mesh));

  std::map<MVertex *, uint32_t> v2c;
  std::vector<MVertex *> c2v;
  int status = Gmsh2Hxt(gf, mesh, v2c, c2v);
  if (status != 0) {
    Msg::Error("failed to convert face %i to HXTMesh", gf->tag());
    return status;
  }


  //TODO delete
  {
    printf("\n");
    printf("COLOR = %d \n", mesh->triangles.color[0]);
    printf("\n");

    char buffer[32];
    snprintf(buffer,sizeof(char)*32,"convert_%i.msh",(int)mesh->triangles.color[0]);
    hxtMeshWriteGmsh(mesh, buffer);
  }  
  hxtMeshWriteGmsh(mesh, "convert.msh");

  size_t targetNumberOfQuads = gf->triangles.size()/2;
  Msg::Debug("-- target number of quads: %li", targetNumberOfQuads);

  constexpr bool RECOMPUTE_CROSS_FIELD = false;
  std::map<size_t, std::array<double,7> > vertexDirections;
  if (RECOMPUTE_CROSS_FIELD) {
    std::vector<GFace*> faces = {gf};
    int st = computeCrossFieldAndScalingForHxt(faces, targetNumberOfQuads, c2v, vertexDirections);
    if (st != 0) {
      Msg::Error("failed to compute cross field and scaling for hxt");
      return -1;
    }
  } else {
    std::vector<GFace*> faces = {gf};
    int st = readScaledCrossFieldFromBackgroundField(faces, c2v, vertexDirections);
    if (st != 0) {
      Msg::Error("failed to read cross field and scaling from background field");
      return -1;
    }
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

      
      SVector3 dir1(vertexDirections[v->getNum()][0], 
                    vertexDirections[v->getNum()][1], 
                    vertexDirections[v->getNum()][2]);
      SVector3 dir2(vertexDirections[v->getNum()][3], 
                    vertexDirections[v->getNum()][4], 
                    vertexDirections[v->getNum()][5]);
      dir1.normalize();
      dir2.normalize();
      for (size_t k=0; k<3; k++){
        vertexDirections[v->getNum()][k] = dir1[k];
        vertexDirections[v->getNum()][k+3] = dir2[k];
      }
 

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



  ///// HERE WE NEED THE CODE TO THE REMESHING STUFF
   
  HXTMesh *fmesh;
  HXT_CHECK(hxtMeshCreate(&fmesh));

  // TODO 
  HXTPointGenOptions opt = { .verbosity = 0,
                             .generateLines = 0,
                             .generateSurfaces = 1,
                             .generateVolumes = 0,
                             .remeshSurfaces = 1,
                             .quadSurfaces = 1,
                             .walkMethod2D = 0,
                             .walkMethod3D = 0,
                             .dirType = 0,
                             .uniformSize = 1.0,
                             .areaThreshold = 10e-9,
                             .tolerance = 10e-9,
                             .numTris = 0};


  if (Msg::GetVerbosity() == 99) opt.verbosity = 2;

  HXTStatus stgp = hxtGmshPointGenMain(mesh,&opt,data.data(),fmesh);
  if (stgp != HXT_STATUS_OK) {
    Msg::Error("hxtGmshPointGenMain: wrong output status");
    gf->meshStatistics.status = GFace::PENDING;
    HXT_CHECK(hxtMeshDelete(&fmesh));
    HXT_CHECK(hxtMeshDelete(&mesh));
    return -1;
  }


  if (fmesh->quads.size > 0) {
    Msg::Debug("- Face %i: %li quads in output of meshGFaceHxt", gf->tag(), fmesh->quads.size);
    for (MTriangle* f: gf->triangles) { delete f; }
    for (MQuadrangle* f: gf->quadrangles) { delete f; }
    for (MVertex* v: gf->mesh_vertices) { 
      uint32_t c = v2c[v];
      if (c < c2v.size()) c2v[c] = NULL;
      delete v; 
    }
    gf->triangles.clear();
    gf->quadrangles.clear();
    gf->mesh_vertices.clear();

    std::unordered_map<uint32_t,MVertex*> outOld2New;
    for (size_t f = 0; f < fmesh->quads.size; ++f) {
      MQuadrangle* q = new MQuadrangle(NULL,NULL,NULL,NULL);
      for (size_t lv = 0; lv < 4; ++lv) {
        uint32_t v = fmesh->quads.node[4*f+lv];
        if (v < c2v.size() && c2v[v] != NULL && dynamic_cast<GFace*>(c2v[v]->onWhat()) == NULL) { /* existing vertex on boundary */
          q->setVertex(lv,c2v[v]);
        } else {
          auto it = outOld2New.find(v);
          if (it != outOld2New.end()) {
            q->setVertex(lv,it->second);
          } else {
            MVertex *vNew = new MFaceVertex(
                fmesh->vertices.coord[4*v+0],
                fmesh->vertices.coord[4*v+1],
                fmesh->vertices.coord[4*v+2],
                gf,0.,0.);
            gf->addMeshVertex(vNew);
            q->setVertex(lv,vNew);
            outOld2New[v] = vNew;
          }
        }
      }
      gf->quadrangles.push_back(q);
    }
    gf->meshStatistics.status = GFace::DONE;
  } else {
    Msg::Error("- Face %i: no quads in output of meshGFaceHxt", gf->tag());
  }

  HXT_CHECK(hxtMeshDelete(&fmesh));
  HXT_CHECK(hxtMeshDelete(&mesh));
  
  return 0;

}


#else

int Hxt2Gmsh(GFace *gf, HXTMesh *m,
		   std::map<MVertex *, uint32_t> &v2c,
       std::vector<MVertex *> &c2v) 
{
  Msg::Error("Gmsh should be compiled with Hxt to enable this option");
  return -1;
}

int meshGFaceHxt(GModel *gm)
{
  Msg::Error("Gmsh should be compiled with Hxt to enable this option");
  return -1;
}

int meshGFaceHxt(GFace *gf) {
  Msg::Error("Gmsh should be compiled with Hxt to enable this option");
  return -1;

}

#endif
