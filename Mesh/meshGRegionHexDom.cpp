#include <nanoflann.hpp>
#include "meshGRegionHexDom.h"
#include "GmshConfig.h"
#include "Context.h"
#include "MVertex.h"
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MTriangle.h"
#include "MLine.h"
#include "MPoint.h"
#include "GmshMessage.h"
#include "Field.h"
#include "meshQuadQuasiStructured.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "PViewDataList.h"
#include "PViewDataGModel.h"
#include "PViewOptions.h"
#endif

#if defined(HAVE_HXT)
#include "hxt_tet_combination_api.h"

static void getAllSurfaces(std::vector<GRegion *> &regions,
			   std::vector<GFace *> &allSurfaces){
  
  std::set<GFace *, GEntityPtrLessThan> allSurfacesSet;
  for(std::size_t i = 0; i < regions.size(); i++) {
    std::vector<GFace *> const &f = regions[i]->faces();
    std::vector<GFace *> const &f_e = regions[i]->embeddedFaces();
    allSurfacesSet.insert(f.begin(), f.end());
    allSurfacesSet.insert(f_e.begin(), f_e.end());
  }
  allSurfaces.insert(allSurfaces.begin(), allSurfacesSet.begin(),
                     allSurfacesSet.end());  
}

static void getAllCurves(std::vector<GRegion *> &regions,
			 std::vector<GFace *> &surfaces,
			 std::vector<GEdge *> &allCurves)
{

  std::set<GEdge *, GEntityPtrLessThan> allCurvesSet;

  for(std::size_t i = 0; i < surfaces.size(); i++) {
    std::vector<GEdge *> const &f = surfaces[i]->edges();
    std::vector<GEdge *> const &f_e = surfaces[i]->embeddedEdges();
    allCurvesSet.insert(f.begin(), f.end());
    allCurvesSet.insert(f_e.begin(), f_e.end());
  }
  for(std::size_t i = 0; i < regions.size(); i++) {
    std::vector<GEdge *> const &r_e = regions[i]->embeddedEdges();
    allCurvesSet.insert(r_e.begin(), r_e.end());
  }
  allCurves.insert(allCurves.begin(), allCurvesSet.begin(), allCurvesSet.end());
}


static void getAllMeshEntities(std::vector<GRegion *> &regions,
			       std::vector<MVertex*> &vertices,
			       std::vector<double> &coord,
			       std::vector<unsigned int> &tets,
			       std::vector<unsigned int> &triangles,
			       std::vector<uint16_t> & tets_colors,
			       std::vector<uint16_t> & triangles_colors){
  std::set<MVertex *> all;
  std::vector<GFace *> surfaces;
  std::vector<GEdge *> curves;
  std::vector<GVertex *> points;
  
  getAllSurfaces(regions, surfaces);
  getAllCurves(regions, surfaces, curves);
  
  for(GRegion *gr : regions) {
    for(GVertex *gv : gr->embeddedVertices()) {
      points.push_back(gv);
      for(size_t i = 0; i < gv->points.size(); i++) {
        MVertex *v = gv->points[i]->getVertex(0);
        all.insert(v);
      }
    }
  }

  for(size_t j = 0; j < curves.size(); j++) {
    GEdge *ge = curves[j];
    for(size_t i = 0; i < ge->lines.size(); i++) {
      all.insert(ge->lines[i]->getVertex(0));
      all.insert(ge->lines[i]->getVertex(1));
    }
  }

  for(size_t j = 0; j < surfaces.size(); j++) {
    GFace *gf = surfaces[j];
    for(size_t i = 0; i < gf->triangles.size(); i++) {
      all.insert(gf->triangles[i]->getVertex(0));
      all.insert(gf->triangles[i]->getVertex(1));
      all.insert(gf->triangles[i]->getVertex(2));
    }
  }
  for(GRegion *gr : regions) {
    for(size_t i = 0; i < gr->tetrahedra.size(); i++) {
      all.insert(gr->tetrahedra[i]->getVertex(0));
      all.insert(gr->tetrahedra[i]->getVertex(1));
      all.insert(gr->tetrahedra[i]->getVertex(2));
      all.insert(gr->tetrahedra[i]->getVertex(3));
    }
  }
  
  coord.resize(all.size()*3);
  size_t counter = 0;
  for(MVertex *v : all) {
    coord[3*counter+0] = v->x();
    coord[3*counter+1] = v->y();
    coord[3*counter+2] = v->z();
    v->setIndex(counter++);
    vertices.push_back(v);
  }
  all.clear();
  
  for(size_t j = 0; j < surfaces.size(); j++) {
    GFace *gf = surfaces[j];
    for(size_t i = 0; i < gf->triangles.size(); i++) {
      triangles_colors.push_back(gf->tag());
      triangles.push_back(gf->triangles[i]->getVertex(0)->getIndex());
      triangles.push_back(gf->triangles[i]->getVertex(1)->getIndex());
      triangles.push_back(gf->triangles[i]->getVertex(2)->getIndex());
    }
  }
  for(GRegion *gr : regions) {
    for(size_t i = 0; i < gr->tetrahedra.size(); i++) {
      tets_colors.push_back(gr->tag());
      tets.push_back(gr->tetrahedra[i]->getVertex(0)->getIndex());
      tets.push_back(gr->tetrahedra[i]->getVertex(1)->getIndex());
      tets.push_back(gr->tetrahedra[i]->getVertex(2)->getIndex());
      tets.push_back(gr->tetrahedra[i]->getVertex(3)->getIndex());
    }
  }    
}

struct PointCloud
{
  std::vector<SPoint3>  pts;
  std::vector<SVector3>  t1;
  std::vector<SVector3>  t2;  
  std::vector<double>     l;  
}; 

template <typename Derived>
struct PointCloudAdaptor
{  
  const Derived &obj;
  PointCloudAdaptor(const Derived &obj_) : obj(obj_) { }
  inline const Derived& derived() const { return obj; }
  inline size_t kdtree_get_point_count() const { return derived().pts.size(); }
  inline double kdtree_distance(const double *p1, const size_t idx_p2,size_t /*size*/) const
  {
    const double d0=p1[0]-derived().pts[idx_p2].x();
    const double d1=p1[1]-derived().pts[idx_p2].y();
    const double d2=p1[2]-derived().pts[idx_p2].z();
    return d0*d0+d1*d1+d2*d2;
  }
  inline double kdtree_get_pt(const size_t idx, int dim) const
  {
    if (dim==0) return derived().pts[idx].x();
    else if (dim==1) return derived().pts[idx].y();
    else return derived().pts[idx].z();
  }
  template <class BBOX>
  bool kdtree_get_bbox(BBOX& /*bb*/) const { return false; }
}; 


typedef PointCloudAdaptor<PointCloud> PC2KD;
typedef nanoflann::KDTreeSingleIndexAdaptor<
  nanoflann::L2_Simple_Adaptor<double, PC2KD > ,
  PC2KD, 3 > my_kd_tree_t;


static void compute3DScaledCrossesFast (std::vector<GRegion *> &regions){

  FieldManager *fields = regions[0]->model()->getFields();
  Field *cross_field = NULL;
  if(fields->getBackgroundField() > 0) {
    cross_field = fields->get(fields->getBackgroundField());
    if(cross_field->numComponents() != 3) {// we have a true scaled cross fields !!
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
  std::vector<GFace *> surfaces;  
  getAllSurfaces(regions, surfaces);

  PointCloud P;
  for (auto gf : surfaces){
    std::vector<SPoint3> points;
    std::vector<SPoint2> uvpoints;
    std::vector<SVector3> normals;
    SBoundingBox3d bb = gf->bounds();
    SVector3 dd = bb.max() - bb.min();
    double maxDist = dd.norm() / 20 ;
    gf->fillPointCloud(maxDist, &points, &uvpoints, &normals);
    for (size_t i=0;i<points.size();i++){
      SVector3 t1,t2;
      (*cross_field)(points[i].x(),points[i].y(),points[i].z(), t1, gf);
      t2 = crossprod(normals[i],t1);
      P.pts.push_back(points[i]);
      double L = t1.norm();
      t1.normalize();
      t2.normalize();
      P.t1.push_back(t1);
      P.t2.push_back(t2);
      P.l.push_back(L);
    }    
  }

  const PC2KD  pc2kd(P); // The adaptor
  my_kd_tree_t   *index;
  index = new my_kd_tree_t(3 , pc2kd, nanoflann::KDTreeSingleIndexAdaptorParams(10) );
  index->buildIndex();
  
  std::map<MVertex*,size_t> indices;
  std::vector<double> datalist;

  for(GRegion *gr : regions) {
    for(auto t : gr->tetrahedra) {
      for (int i=0;i<4;i++)
	datalist.push_back(t->getVertex(i)->x());
      for (int i=0;i<4;i++)
	datalist.push_back(t->getVertex(i)->y());
      for (int i=0;i<4;i++)
	datalist.push_back(t->getVertex(i)->z());
      
      for (int i=0;i<4;i++){
	std::map<MVertex*,size_t>::iterator it = indices.find(t->getVertex(i));
	size_t ret_index;
	if (it == indices.end()){
	  double query_pt[3] = {t->getVertex(i)->x(),t->getVertex(i)->y(),t->getVertex(i)->z()};
	  const size_t num_results = 1;
	  double out_dist_sqr;
	  nanoflann::KNNResultSet<double> resultSet(num_results);
	  resultSet.init(&ret_index, &out_dist_sqr );
	  index->findNeighbors(resultSet, &query_pt[0], nanoflann::SearchParams(10));
	  indices[t->getVertex(i)] = ret_index;
	}
	else ret_index = it->second;
	SVector3 d1 = P.t1[ret_index];
	SVector3 d2 = P.t2[ret_index];
	SVector3 d3 = crossprod(d1,d2);
	datalist.push_back(d1.x());
	datalist.push_back(d2.x());
	datalist.push_back(d3.x());
	datalist.push_back(d1.y());
	datalist.push_back(d2.y());
	datalist.push_back(d3.y());
	datalist.push_back(d1.z());
	datalist.push_back(d2.z());
	datalist.push_back(d3.z());
      }
    }
  }

#if defined(HAVE_POST)
  PView *view = new PView();
  view->getData()->setName("cross_field_3D");
  PViewDataList *d = new PViewDataList();
  d->setName("cross_field_3D");
  d->setFileName("cross_field_3D.pos");
  view->setData(d);
  size_t numElements = datalist.size() / (12 + 36);
  int idxtypeSS = 14; /* Post type: SS */
  d->importList(idxtypeSS, numElements, datalist, false);
  d->writePOS("cross_field_3D.pos");
#endif

}

void compute3DScaledCrossesFast (){

  bool overwriteGModelMesh = false; 
  bool overwriteField = false;
  bool deleteGModelMeshAfter = false;
  BuildBackgroundMeshAndGuidingField(GModel::current(), overwriteGModelMesh,
				     deleteGModelMeshAfter, overwriteField);
  
  std::vector<GRegion*> r ;
  for(GModel::riter it = GModel::current()->firstRegion() ; it != GModel::current()->lastRegion() ; ++it)
    r.push_back(*it);
  compute3DScaledCrossesFast (r);
}


int meshGRegionHexDom (std::vector<GRegion *> &regions, double minQuality, int doPrisms, int doPyramids){
  std::vector<double> coord;
  std::vector<MVertex*> vertices;
  std::vector<unsigned int> triangles;
  std::vector<unsigned int> tets;
  std::vector<uint16_t> tets_colors;
  std::vector<uint16_t> triangles_colors;

  if (regions.size() != 1){
    Msg::Warning ("meshGRegionHexDom can only work with one region at once");
    return -1;
  }
  
  getAllMeshEntities(regions, vertices, coord, tets, triangles,tets_colors,triangles_colors);
  
  std::vector<unsigned int> tets_out, hexes_out, prisms_out,  pyramids_out;
  std::vector<uint16_t> hexes_colors_out, prisms_colors_out, pyramids_colors_out, tets_colors_out;  
  hxt_tet_combination (coord, tets, triangles,  tets_colors, triangles_colors, minQuality,doPrisms,doPyramids,	
		       tets_out, hexes_out, prisms_out, pyramids_out, tets_colors_out,
		       hexes_colors_out, prisms_colors_out, pyramids_colors_out);    

  for (auto t : regions[0]->tetrahedra)delete t;
  regions[0]->tetrahedra.clear();

  for (size_t i=0;i<tets_out.size();i+=4)
    regions[0]->tetrahedra.push_back(new MTetrahedron(vertices[tets_out[4*i+0]],vertices[tets_out[4*i+1]],
						     vertices[tets_out[4*i+2]],vertices[tets_out[4*i+3]]));
  for (size_t i=0;i<hexes_out.size();i+=8)
    regions[0]->hexahedra.push_back(new MHexahedron(vertices[hexes_out[4*i+0]],vertices[hexes_out[4*i+1]],
						    vertices[hexes_out[4*i+2]],vertices[hexes_out[4*i+3]],
						    vertices[hexes_out[4*i+4]],vertices[hexes_out[4*i+5]],
						    vertices[hexes_out[4*i+6]],vertices[hexes_out[4*i+7]]));
  for (size_t i=0;i<prisms_out.size();i+=6)
    regions[0]->prisms.push_back(new MPrism(vertices[prisms_out[4*i+0]],vertices[prisms_out[4*i+1]],
					    vertices[prisms_out[4*i+2]],vertices[prisms_out[4*i+3]],
					    vertices[prisms_out[4*i+4]],vertices[prisms_out[4*i+5]]));
  for (size_t i=0;i<pyramids_out.size();i+=5)
    regions[0]->pyramids.push_back(new MPyramid(vertices[pyramids_out[4*i+0]],vertices[pyramids_out[4*i+1]],
						vertices[pyramids_out[4*i+2]],vertices[pyramids_out[4*i+3]],
						vertices[pyramids_out[4*i+4]]));
  
  return 0;
}

#endif
