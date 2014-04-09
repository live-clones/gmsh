// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include <stdlib.h>
#include <vector>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "meshGRegion.h"
#include "meshGFace.h"
#include "meshGFaceOptimize.h"
#include "boundaryLayersData.h"
#include "meshGRegionBoundaryRecovery.h"
#include "meshGRegionDelaunayInsertion.h"
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "GEdge.h"
#include "gmshRegion.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MPyramid.h"
#include "MPrism.h"
#include "MHexahedron.h"
#include "BDS.h"
#include "OS.h"
#include "Context.h"
#include "GFaceCompound.h"
#include "meshGRegionMMG3D.h"
#include "simple3D.h"
#include "Levy3D.h"
#include "directions3D.h"
#include "discreteFace.h"
#include "filterElements.h"

#if defined(HAVE_ANN)
#include "ANN/ANN.h"
#endif

// hybrid mesh recovery structure
class splitQuadRecovery {
  std::multimap<GEntity*, std::pair<MVertex*,MFace> >_data;
  bool _empty;
 public :
  splitQuadRecovery() : _empty(true) {}
  bool empty(){ return _empty; }
  void setEmpty(bool val){ _empty = val; }
  void add (const MFace &f, MVertex *v, GEntity*ge)
  {
    _data.insert(std::make_pair(ge, std::make_pair(v,f)));
  }
  int buildPyramids(GModel *gm)
  {
    if(empty()) return 0;
    int NBPY = 0;
    for (GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it){
      std::set<MFace, Less_Face> allFaces;
      for (unsigned int i = 0; i < (*it)->triangles.size(); i++){
        allFaces.insert ((*it)->triangles[i]->getFace(0));
        delete (*it)->triangles[i];
      }
      (*it)->triangles.clear();
      for (std::multimap<GEntity*, std::pair<MVertex*,MFace> >::iterator it2 =
             _data.lower_bound(*it); it2 != _data.upper_bound(*it) ; ++it2){
        MVertex *v = it2->second.first;
        v->onWhat()->mesh_vertices.erase(std::find(v->onWhat()->mesh_vertices.begin(),
                                                   v->onWhat()->mesh_vertices.end(), v));
        const MFace &f = it2->second.second;
        std::set<MFace, Less_Face>::iterator itf0 = allFaces.find(MFace(f.getVertex(0),
                                                                        f.getVertex(1),v));
        std::set<MFace, Less_Face>::iterator itf1 = allFaces.find(MFace(f.getVertex(1),
                                                                        f.getVertex(2),v));
        std::set<MFace, Less_Face>::iterator itf2 = allFaces.find(MFace(f.getVertex(2),
                                                                        f.getVertex(3),v));
        std::set<MFace, Less_Face>::iterator itf3 = allFaces.find(MFace(f.getVertex(3),
                                                                        f.getVertex(0),v));
        if (itf0 != allFaces.end() && itf1 != allFaces.end() &&
            itf2 != allFaces.end() && itf3 != allFaces.end()){
          (*it)->quadrangles.push_back(new MQuadrangle(f.getVertex(0), f.getVertex(1),
                                                       f.getVertex(2), f.getVertex(3)));
	allFaces.erase(*itf0);
	allFaces.erase(*itf1);
	allFaces.erase(*itf2);
	allFaces.erase(*itf3);
	// printf("some pyramids should be created %d regions\n", (*it)->numRegions());
	for (int iReg = 0; iReg < (*it)->numRegions(); iReg++){
	  if (iReg == 1) {
            Msg::Error("Cannot build pyramids on non manifold faces");
            v = new MVertex(v->x(), v->y(), v->z(), (*it)->getRegion(iReg));
          }
	  else
            v->setEntity ((*it)->getRegion(iReg));
	  (*it)->getRegion(iReg)->pyramids.push_back
            (new MPyramid(f.getVertex(0), f.getVertex(1), f.getVertex(2), f.getVertex(3), v));
	  (*it)->getRegion(iReg)->mesh_vertices.push_back(v);
	  NBPY++;
	}
        }
      }
      for (std::set<MFace, Less_Face>::iterator itf = allFaces.begin();
           itf != allFaces.end(); ++itf){
        (*it)->triangles.push_back
          (new MTriangle(itf->getVertex(0), itf->getVertex(1), itf->getVertex(2)));
      }
    }
    return NBPY;
  }
};

void printVoronoi(GRegion *gr,  std::set<SPoint3> &candidates)
{
  std::vector<MTetrahedron*> elements = gr->tetrahedra;
  std::list<GFace*> allFaces = gr->faces();

  //building maps
  std::map<MVertex*, std::set<MTetrahedron*> > node2Tet;
  std::map<MFace, std::vector<MTetrahedron*> , Less_Face> face2Tet;
  for(unsigned int i = 0; i < elements.size(); i++){
    MTetrahedron *ele = elements[i];
    for (int j=0; j<4; j++){
      MVertex *v = ele->getVertex(j);
      std::map<MVertex*, std::set<MTetrahedron*> >::iterator itmap = node2Tet.find(v);
      if (itmap == node2Tet.end()){
  	std::set<MTetrahedron*>  oneTet;
  	oneTet.insert(ele);
  	node2Tet.insert(std::make_pair(v, oneTet));
      }
      else{
  	std::set<MTetrahedron*>  allTets = itmap->second;
  	allTets.insert(allTets.begin(), ele);
  	itmap->second = allTets;
      }
    }
    for (int j = 0; j < 4; j++){
      MFace f = ele->getFace(j);
      std::map<MFace, std::vector<MTetrahedron*>, Less_Face >::iterator itmap =
        face2Tet.find(f);
      if (itmap == face2Tet.end()){
  	std::vector<MTetrahedron*>  oneTet;
  	oneTet.push_back(ele);
  	face2Tet.insert(std::make_pair(f, oneTet));
      }
      else{
  	std::vector<MTetrahedron*>  allTets = itmap->second;
  	allTets.insert(allTets.begin(), ele);
  	itmap->second = allTets;
      }
    }
  }

  //print voronoi poles
  FILE *outfile;
  //smooth_normals *snorm = gr->model()->normals;
  outfile = Fopen("nodes.pos", "w");
  fprintf(outfile, "View \"Voronoi poles\" {\n");
  std::map<MVertex*, std::set<MTetrahedron*> >::iterator itmap = node2Tet.begin();
  for(; itmap != node2Tet.end(); itmap++){
    //MVertex *v = itmap->first;
    std::set<MTetrahedron*>  allTets = itmap->second;
    std::set<MTetrahedron*>::const_iterator it = allTets.begin();
    MTetrahedron *poleTet = *it;
    double maxRadius = poleTet->getCircumRadius();
    for(; it != allTets.end(); it++){
      double radius =  (*it)->getCircumRadius();
      if (radius > maxRadius){
    	maxRadius = radius;
    	poleTet = *it;
      }
    }
    //if (v->onWhat()->dim() == 2 ){
      SPoint3 pc = poleTet->circumcenter();
      //double nx,ny,nz;
      // SVector3 vN = snorm->get(v->x(), v->y(), v->z(), nx,ny,nz);
      // SVector3 pcv(pc.x()-nx, pc.y()-ny,pc.z()-nz);
      // printf("nx=%g ny=%g nz=%g dot=%g \n",  nx,ny,nz, dot(vN, pcv));
      // if ( dot(vN, pcv) > 0.0 )
      double x[3] = {pc.x(), pc.y(), pc.z()};
      double uvw[3];
      poleTet->xyz2uvw(x, uvw);
      //bool inside = poleTet->isInside(uvw[0], uvw[1], uvw[2]);
      //if (inside){
	fprintf(outfile,"SP(%g,%g,%g)  {%g};\n",
		pc.x(), pc.y(), pc.z(), maxRadius);
	candidates.insert(pc);
	//}
    //}
  }
  fprintf(outfile,"};\n");
  fclose(outfile);

  //print scalar lines
  FILE *outfile2;
  outfile2 = Fopen("edges.pos", "w");
  fprintf(outfile2, "View \"Voronoi edges\" {\n");
  std::map<MFace, std::vector<MTetrahedron*> , Less_Face >::iterator itmap2 = face2Tet.begin();
  for(; itmap2 != face2Tet.end(); itmap2++){
    std::vector<MTetrahedron*>  allTets = itmap2->second;
    if (allTets.size() != 2 ) continue;
    SPoint3 pc1 = allTets[0]->circumcenter();
    SPoint3 pc2 = allTets[1]->circumcenter();
    //std::set<SPoint3>::const_iterator it1 = candidates.find(pc1);
    //std::set<SPoint3>::const_iterator it2 = candidates.find(pc2);
    //if( it1 != candidates.end() || it2 != candidates.end())
      fprintf(outfile2,"SL(%g,%g,%g,%g,%g,%g)  {%g,%g};\n",
	      pc1.x(), pc1.y(), pc1.z(), pc2.x(), pc2.y(), pc2.z(),
	      allTets[0]->getCircumRadius(),allTets[1]->getCircumRadius());
   }
  fprintf(outfile2,"};\n");
  fclose(outfile2);

}


void getBoundingInfoAndSplitQuads(GRegion *gr,
                                  std::map<MFace,GEntity*,Less_Face> &allBoundingFaces,
                                  std::set<MVertex*> &allBoundingVertices,
                                  splitQuadRecovery &sqr)
{
  std::map<MFace, GEntity*, Less_Face> allBoundingFaces_temp;

  // Get all the faces that are on the boundary
  std::list<GFace*> faces = gr->faces();
  std::list<GFace*>::iterator it = faces.begin();
  while (it != faces.end()){
    GFace *gf = (*it);
    for(unsigned int i = 0; i < gf->getNumMeshElements(); i++){
      allBoundingFaces_temp[gf->getMeshElement(i)->getFace(0)] = gf;
    }
    ++it;
  }

  // if some elements pre-exist in the mesh, then use the internal faces of
  // those

  for (unsigned int i=0;i<gr->getNumMeshElements();i++){
    MElement *e = gr->getMeshElement(i);
    for (int j = 0; j < e->getNumFaces(); j++){
      std::map<MFace, GEntity*, Less_Face>::iterator it = allBoundingFaces_temp.find(e->getFace(j));
      if (it == allBoundingFaces_temp.end()) allBoundingFaces_temp[e->getFace(j)] = gr;
      else allBoundingFaces_temp.erase(it);
    }
  }

  std::map<MFace, GEntity*, Less_Face>::iterator itx = allBoundingFaces_temp.begin();
  for (; itx != allBoundingFaces_temp.end();++itx){
    const MFace &f = itx->first;
    // split the quad face into 4 triangular faces
    if (f.getNumVertices() == 4){
      sqr.setEmpty(false);
      MVertex *v0 = f.getVertex(0);
      MVertex *v1 = f.getVertex(1);
      MVertex *v2 = f.getVertex(2);
      MVertex *v3 = f.getVertex(3);
      MVertex *newv = new MVertex ((v0->x() + v1->x() + v2->x() + v3->x())*0.25,
				   (v0->y() + v1->y() + v2->y() + v3->y())*0.25,
				   (v0->z() + v1->z() + v2->z() + v3->z())*0.25,itx->second);
      sqr.add(f,newv,itx->second);
      allBoundingFaces[MFace(v0,v1,newv)] = itx->second;
      allBoundingFaces[MFace(v1,v2,newv)] = itx->second;
      allBoundingFaces[MFace(v2,v3,newv)] = itx->second;
      allBoundingFaces[MFace(v3,v0,newv)] = itx->second;
      itx->second->mesh_vertices.push_back(newv);
      allBoundingVertices.insert(v0);
      allBoundingVertices.insert(v1);
      allBoundingVertices.insert(v2);
      allBoundingVertices.insert(v3);
      allBoundingVertices.insert(newv);
    }
    else{
      allBoundingFaces[f] = itx->second;
      allBoundingVertices.insert(f.getVertex(0));
      allBoundingVertices.insert(f.getVertex(1));
      allBoundingVertices.insert(f.getVertex(2));
    }
  }
}

#if defined(HAVE_TETGEN)

#include "tetgen.h"

void buildTetgenStructure(GRegion *gr, tetgenio &in, std::vector<MVertex*> &numberedV,
                          splitQuadRecovery &sqr)
{
  std::set<MVertex*> allBoundingVertices;
  std::map<MFace,GEntity*,Less_Face> allBoundingFaces;
  getBoundingInfoAndSplitQuads(gr, allBoundingFaces, allBoundingVertices, sqr);

  in.mesh_dim = 3;
  in.firstnumber = 1;
  in.numberofpoints = allBoundingVertices.size() + Filler::get_nbr_new_vertices() +
    LpSmoother::get_nbr_interior_vertices();
  in.pointlist = new REAL[in.numberofpoints * 3];
  in.pointmarkerlist = NULL;

  std::set<MVertex*>::iterator itv = allBoundingVertices.begin();
  int I = 1;
  while(itv != allBoundingVertices.end()){
    in.pointlist[(I - 1) * 3 + 0] = (*itv)->x();
    in.pointlist[(I - 1) * 3 + 1] = (*itv)->y();
    in.pointlist[(I - 1) * 3 + 2] = (*itv)->z();
    (*itv)->setIndex(I++);
    numberedV.push_back(*itv);
    ++itv;
  }

  for(int i=0;i<Filler::get_nbr_new_vertices();i++){
    MVertex* v;
    v = Filler::get_new_vertex(i);
    in.pointlist[(I - 1) * 3 + 0] = v->x();
    in.pointlist[(I - 1) * 3 + 1] = v->y();
    in.pointlist[(I - 1) * 3 + 2] = v->z();
    I++;
  }

  for(int i=0;i<LpSmoother::get_nbr_interior_vertices();i++){
    MVertex* v;
    v = LpSmoother::get_interior_vertex(i);
    in.pointlist[(I - 1) * 3 + 0] = v->x();
    in.pointlist[(I - 1) * 3 + 1] = v->y();
    in.pointlist[(I - 1) * 3 + 2] = v->z();
    I++;
  }

  in.numberoffacets = allBoundingFaces.size();
  in.facetlist = new tetgenio::facet[in.numberoffacets];
  in.facetmarkerlist = new int[in.numberoffacets];

  I = 0;
  std::map<MFace,GEntity*,Less_Face>::iterator it = allBoundingFaces.begin();
  for (; it != allBoundingFaces.end();++it){
    const MFace &fac = it->first;
    tetgenio::facet *f = &in.facetlist[I];
    tetgenio::init(f);
    f->numberofholes = 0;
    f->numberofpolygons = 1;
    f->polygonlist = new tetgenio::polygon[f->numberofpolygons];
    tetgenio::polygon *p = &f->polygonlist[0];
    tetgenio::init(p);
    p->numberofvertices = 3;
    p->vertexlist = new int[p->numberofvertices];
    p->vertexlist[0] = fac.getVertex(0)->getIndex();
    p->vertexlist[1] = fac.getVertex(1)->getIndex();
    p->vertexlist[2] = fac.getVertex(2)->getIndex();
    in.facetmarkerlist[I] = (it->second->dim() == 3) ? -it->second->tag() : it->second->tag();
    ++I;
  }
}

void TransferTetgenMesh(GRegion *gr, tetgenio &in, tetgenio &out,
                        std::vector<MVertex*> &numberedV)
{
  // improvement has to be done here : tetgen splits some of the existing edges
  // of the mesh. If those edges are classified on some model faces, new points
  // SHOULD be classified on the model face and get the right set of parametric
  // coordinates.

  const int initialSize = (int)numberedV.size();

  for(int i = numberedV.size(); i < out.numberofpoints; i++){
    MVertex *v = new MVertex(out.pointlist[i * 3 + 0],
                             out.pointlist[i * 3 + 1],
                             out.pointlist[i * 3 + 2], gr);
    gr->mesh_vertices.push_back(v);
    numberedV.push_back(v);
  }

  Msg::Info("%d points %d edges and %d faces in the initial mesh",
            out.numberofpoints, out.numberofedges, out.numberoftrifaces);

  // Tetgen modifies both surface & edge mesh, so we need to re-create
  // everything

  gr->model()->destroyMeshCaches();
  std::list<GFace*> faces = gr->faces();
  for(std::list<GFace*>::iterator it = faces.begin(); it != faces.end(); it++){
    GFace *gf = (*it);
    for(unsigned int i = 0; i < gf->triangles.size(); i++)
      delete gf->triangles[i];
    for(unsigned int i = 0; i < gf->quadrangles.size(); i++)
      delete gf->quadrangles[i];
    gf->triangles.clear();
    gf->quadrangles.clear();
    gf->deleteVertexArrays();
  }

  // TODO: re-create 1D mesh
  /*for(int i = 0; i < out.numberofedges; i++){
  MVertex *v[2];
  v[0] = numberedV[out.edgelist[i * 2 + 0] - 1];
  v[1] = numberedV[out.edgelist[i * 2 + 1] - 1];
  //implement here the 1D mesh ...
  }*/

  bool needParam = (CTX::instance()->mesh.order > 1 &&
                    CTX::instance()->mesh.secondOrderExperimental);
  // re-create the triangular meshes FIXME: this can lead to hanging nodes for
  // non manifold geometries (single surface connected to volume)
  for(int i = 0; i < out.numberoftrifaces; i++){
    //    printf("%d %d %d\n",i,out.numberoftrifaces,needParam);

    if (out.trifacemarkerlist[i] > 0) {
      MVertex *v[3];
      v[0] = numberedV[out.trifacelist[i * 3 + 0] - 1];
      v[1] = numberedV[out.trifacelist[i * 3 + 1] - 1];
      v[2] = numberedV[out.trifacelist[i * 3 + 2] - 1];
      // do not recover prismatic faces !!!
      GFace *gf = gr->model()->getFaceByTag(out.trifacemarkerlist[i]);

      double guess[2] = {0, 0};
      if (needParam) {
	int Count = 0;
	for(int j = 0; j < 3; j++){
	  if(!v[j]->onWhat()){
	    Msg::Error("Uncategorized vertex %d", v[j]->getNum());
	  }
	  else if(v[j]->onWhat()->dim() == 2){
	    double uu,vv;
	    v[j]->getParameter(0, uu);
	    v[j]->getParameter(1, vv);
	    guess[0] += uu;
	    guess[1] += vv;
	    Count++;
	  }
	  else if(v[j]->onWhat()->dim() == 1){
	    GEdge *ge = (GEdge*)v[j]->onWhat();
	    double UU;
	    v[j]->getParameter(0, UU);
	    SPoint2 param;
	    param = ge->reparamOnFace(gf, UU, 1);
	    guess[0] += param.x();
	    guess[1] += param.y();
	    Count++;
	  }
	  else if(v[j]->onWhat()->dim() == 0){
	    SPoint2 param;
	    GVertex *gv = (GVertex*)v[j]->onWhat();
	    param = gv->reparamOnFace(gf,1);
	    guess[0] += param.x();
	    guess[1] += param.y();
	    Count++;
	  }
	}
	if(Count != 0){
	  guess[0] /= Count;
	  guess[1] /= Count;
	}
      }

      for(int j = 0; j < 3; j++){
	if (out.trifacelist[i * 3 + j] - 1 >= initialSize){
	  printf("aaaaaaaaaaaaaaargh\n");
	  //	if(v[j]->onWhat()->dim() == 3){
	  v[j]->onWhat()->mesh_vertices.erase
	    (std::find(v[j]->onWhat()->mesh_vertices.begin(),
		       v[j]->onWhat()->mesh_vertices.end(),
		       v[j]));
	  MVertex *v1b;
	  if(needParam){
	    // parametric coordinates should be set for the vertex !  (this is
	    // not 100 % safe yet, so we reserve that operation for high order
	    // meshes)
	    GPoint gp = gf->closestPoint(SPoint3(v[j]->x(), v[j]->y(), v[j]->z()), guess);
	    if(gp.g()){
	      v1b = new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, gp.u(), gp.v());
	    }
	    else{
	      v1b = new MVertex(v[j]->x(), v[j]->y(), v[j]->z(), gf);
	      Msg::Warning("The point was not projected back to the surface (%g %g %g)",
			   v[j]->x(), v[j]->y(), v[j]->z());
	    }
	  }
	  else{
	    v1b = new MVertex(v[j]->x(), v[j]->y(), v[j]->z(), gf);
	  }

	  gf->mesh_vertices.push_back(v1b);
	  numberedV[out.trifacelist[i * 3 + j] - 1] = v1b;
	  delete v[j];
	  v[j] = v1b;
	}
      }
      //      printf("new triangle %d %d %d\n",v[0]->onWhat()->dim(), v[1]->onWhat()->dim(), v[2]->onWhat()->dim());
      MTriangle *t = new MTriangle(v[0], v[1], v[2]);
      gf->triangles.push_back(t);
    }// do not do anything with prismatic faces
  }


  for(int i = 0; i < out.numberoftetrahedra; i++){
    MVertex *v1 = numberedV[out.tetrahedronlist[i * 4 + 0] - 1];
    MVertex *v2 = numberedV[out.tetrahedronlist[i * 4 + 1] - 1];
    MVertex *v3 = numberedV[out.tetrahedronlist[i * 4 + 2] - 1];
    MVertex *v4 = numberedV[out.tetrahedronlist[i * 4 + 3] - 1];
    MTetrahedron *t = new  MTetrahedron(v1, v2, v3, v4);
    gr->tetrahedra.push_back(t);
  }
}

#endif

static void addOrRemove(const MFace &f,
			MElement *e,
			std::map<MFace,MElement*,Less_Face> & bfaces)
{
  std::map<MFace,MElement*,Less_Face>::iterator it = bfaces.find(f);
  if (it == bfaces.end())bfaces.insert(std::make_pair(f,e));
  else bfaces.erase(it);
}


/*
  here, we have a list of elements that actually do not form a mesh
  --> a set boundary layer elements (prism, hexes, pyramids (and soon tets)
  --> a set of tetrahedra that respect the external boundary of the BL mesh,
  yet possiblty containing elements that are on the other side of the boundary
  and therefore overlapping those elements. We have to extract the good ones !



*/

bool AssociateElementsToModelRegionWithBoundaryLayers (GRegion *gr,
						       std::vector<MTetrahedron*> &tets,
						       std::vector<MHexahedron*> &hexes,
						       std::vector<MPrism*> &prisms,
						       std::vector<MPyramid*> &pyramids)
{
  std::set<MElement*> all;
  all.insert(hexes.begin(),hexes.end());
  all.insert(prisms.begin(),prisms.end());
  all.insert(pyramids.begin(),pyramids.end());
  // start with one BL element !
  MElement *FIRST = all.size() ? *(all.begin()) : 0;
  if (!FIRST) return true;
  all.insert(tets.begin(),tets.end());

  //  printf("coucou1 %d eleemnts\n",all.size());
  fs_cont search;
  buildFaceSearchStructure(gr->model(), search);

  // create the graph face 2 elements for the region
  std::map<MFace,std::pair<MElement*,MElement*> ,Less_Face> myGraph;

  for (std::set<MElement*>::iterator it = all.begin(); it != all.end(); ++it){
    MElement *t = *it;
    const int nbf = t->getNumFaces();
    for (int j=0;j<nbf;j++){
      MFace f = t->getFace(j);
      std::map<MFace,std::pair<MElement*,MElement*>,Less_Face>::iterator itf = myGraph.find(f);
      if (itf == myGraph.end())myGraph.insert (std::make_pair (f, std::make_pair (t,(MElement*)0)));
      else {
	// what to do ??????
	// two tets and one prism --> the prism should be
	// geometrically on the other side of the
	if (itf->second.second) {
	  MElement *prism=0, *t1=0, *t2=0;
	  if (itf->second.second->getType () == TYPE_PRI || itf->second.second->getType () == TYPE_PYR) {
	    prism = itf->second.second;
	    t1 =  itf->second.first;
	    t2 = t;
	  }
	  else if (itf->second.first->getType () == TYPE_PRI || itf->second.first->getType () == TYPE_PYR) {
	    prism = itf->second.first;
	    t1 =  itf->second.second;
	    t2 = t;
	  }
	  else if (t->getType () == TYPE_PRI || t->getType () == TYPE_PYR) {
	    prism = t;
	    t1 =  itf->second.second;
	    t2 = itf->second.first;
	  }
	  else {
	    printf("types %d %d %d\n",t->getType () ,itf->second.first->getType (),itf->second.second->getType () );
	  }
	  if (!t1 || !t2 || !prism){
	    gr->model()->writeMSH("ooops.msh");
	    Msg::Error ("Wrong BL configuration");
	    return false;
	  }
	  SVector3 n = f.normal();
	  SPoint3 c = f.barycenter();
	  MVertex *v_prism = 0, *v_t1 = 0, *v_t2 = 0;
	  for (int i=0;i<4;i++){
	    if (t1->getVertex(i) != f.getVertex(0) &&
		t1->getVertex(i) != f.getVertex(1) &&
		t1->getVertex(i) != f.getVertex(2))v_t1 = t1->getVertex(i);
	    if (t2->getVertex(i) != f.getVertex(0) &&
		t2->getVertex(i) != f.getVertex(1) &&
		t2->getVertex(i) != f.getVertex(2))v_t2 = t2->getVertex(i);
	  }
	  for (int i=0;i<prism->getNumVertices();i++){
	    if (prism->getVertex(i) != f.getVertex(0) &&
		prism->getVertex(i) != f.getVertex(1) &&
		prism->getVertex(i) != f.getVertex(2)) v_prism = prism->getVertex(i);
	  }
	  SVector3 vf1 (v_t1->x() - c.x(),v_t1->y() - c.y(),v_t1->z() - c.z());
	  SVector3 vf2 (v_t2->x() - c.x(),v_t2->y() - c.y(),v_t2->z() - c.z());
	  SVector3 vfp (v_prism->x() - c.x(),v_prism->y() - c.y(),v_prism->z() - c.z());
	  //	  printf("%12.5E %12.5E%12.5E\n",dot(vf1,n),dot(vf2,n),dot(vfp,n));
	  if (dot (vf1,n) * dot (vfp,n) > 0){itf->second.first = prism;itf->second.second=t2; /*delete t1;*/}
	  else if (dot (vf2,n) * dot (vfp,n) > 0){itf->second.first = prism;itf->second.second=t1; /*delete t2;*/}
	  //	  else if (dot (vf2,vfp) > 0){itf->second.first = prism;itf->second.second=t2;}
	  else Msg::Fatal("Impossible Geom Config");
	}
	else itf->second.second = t;
      }
    }
  }

  std::stack<MElement*> myStack;
  std::set<MElement*> connected;
  std::set<GFace*> faces_bound;
  myStack.push(FIRST);
  while (!myStack.empty()){
    FIRST = myStack.top();
    myStack.pop();
    connected.insert(FIRST);
    for (int i=0;i<FIRST->getNumFaces();i++){
      MFace f = FIRST->getFace(i);
      GFace* gfound = findInFaceSearchStructure (f.getVertex(0),
						 f.getVertex(1),
						 f.getVertex(2),
						 search);
      if (!gfound){
	std::map<MFace,std::pair<MElement*,MElement*>,Less_Face>::iterator
	  itf = myGraph.find(f);
	MElement *t_neigh = itf->second.first == FIRST ?
	  itf->second.second :  itf->second.first;
	if (connected.find(t_neigh) == connected.end())myStack.push(t_neigh);
      }
      else {
	//	if (faces_bound.find(gfound) == faces_bound.end())printf("face %d\n",gfound->tag());
	faces_bound.insert(gfound);
      }
    }
  }
  //  printf ("found a set of %d elements that are connected with %d bounding faces\n",connected.size(),faces_bound.size());
  GRegion *myGRegion = getRegionFromBoundingFaces(gr->model(), faces_bound);
  //  printf("REGION %d %d\n",myGRegion->tag(),gr->tag());
  if (myGRegion == gr){
    //    printf("one region %d is found : %d elements\n",myGRegion->tag(),connected.size());
    myGRegion->tetrahedra.clear();
    for (std::set<MElement*>::iterator it = connected.begin(); it != connected.end(); ++it){
      MElement *t = *it;
      std::set<MVertex*> _mesh_vertices;
      for (int i=0;i<t->getNumVertices();i++){
	MVertex *_v = t->getVertex(i);
	if (_v->onWhat() == gr){
	  _mesh_vertices.insert(_v);
	}
      }
      //      myGRegion->mesh_vertices.insert(myGRegion->mesh_vertices.end(),_mesh_vertices.begin(),_mesh_vertices.end());

      if (t->getType() == TYPE_TET)
	myGRegion->tetrahedra.push_back((MTetrahedron*)t);
      else if (t->getType() == TYPE_HEX)
	myGRegion->hexahedra.push_back((MHexahedron*)t);
      else if (t->getType() == TYPE_PRI)
	myGRegion->prisms.push_back((MPrism*)t);
      else if (t->getType() == TYPE_PYR)
	myGRegion->pyramids.push_back((MPyramid*)t);
    }
  }
  else {
    return false;
  }
  return true;
}

static int getWedge(BoundaryLayerColumns* _columns, MVertex *v1, MVertex *v2,
                    int indicesVert1 [], int indicesVert2 [])
{
  int N1 = _columns->getNbColumns(v1) ;
  int N2 = _columns->getNbColumns(v2) ;
  int fanSize = 4;
  int NW1 = 0;
  int NW2 = 0;
  for (int i=0;i<N1;i++){
    const BoundaryLayerData & c1 = _columns->getColumn(v1,i);
    if (c1._joint.size())NW1++;
  }
  for (int i=0;i<N2;i++){
    const BoundaryLayerData & c2 = _columns->getColumn(v2,i);
    if (c2._joint.size())NW2++;
  }

  std::map<int,int> one2two;
  for (int i=0;i<NW1;i++){
    const BoundaryLayerData & c1 = _columns->getColumn(v1,i);
    for (int j=0;j<NW2;j++){
      const BoundaryLayerData & c2 = _columns->getColumn(v2,j);
      for (unsigned int k=0;k<c2._joint.size();k++){
	if (std::find(c1._joint.begin(),c1._joint.end(),c2._joint[k]) !=
	    c1._joint.end()) {
	  one2two[i] = j;
	}
      }
    }
  }

  //  printf("%d %d %d %d \n",N1,N2,NW1,NW2);
  //  for (std::map<int,int>::iterator it = one2two.begin(); it != one2two.end(); it++){
  //    printf("one2two[%d] = %d\n",it->first,it->second);
  //  }
  if (one2two.size() != 2)return 0;

  int vert1Start,vert1End;
  int vert2Start,vert2End;
  std::map<int,int>::iterator it = one2two.begin();
  vert1Start = it->first;
  vert2Start = it->second;
  ++it;
  vert1End   = it->first;
  vert2End   = it->second;


  int INDEX1 = 0, count = 0;
  for (int i=0;i<NW1;i++){
    for (int j=i+1;j<NW1;j++){
      if ((vert1Start == i && vert1End == j) ||
	  (vert1Start == j && vert1End == i))
	{
	  INDEX1 = count;
	}
      count++;
    }
  }
  int INDEX2 = 0;
  count = 0;
  for (int i=0;i<NW2;i++){
    for (int j=i+1;j<NW2;j++){
      if ((vert2Start == i && vert2End == j) ||
	  (vert2Start == j && vert2End == i))
	{
	  INDEX2 = count;
	}
      count++;
    }
  }

  int indexVert1Start = NW1 + fanSize * ( 0 + INDEX1);
  int indexVert1End   = NW1 + fanSize * ( 1 + INDEX1);

  int indexVert2Start = NW2 + fanSize * ( 0 + INDEX2);
  int indexVert2End   = NW2 + fanSize * ( 1 + INDEX2);

  indicesVert1[0]         = vert1Start;
  int k=1;
  for (int i=indexVert1Start;i< indexVert1End;++i)indicesVert1[k++] = i;
  indicesVert1[fanSize+1] = vert1End;

  indicesVert2[0]         = vert2Start;
  k = 1;
  if (indexVert2End > indexVert2Start){
    for (int i=indexVert2Start;i< indexVert2End;++i)indicesVert2[k++] = i;
  }
  else {
    for (int i=indexVert2Start-1;i<= indexVert2End;--i)indicesVert2[k++] = i;
  }
  indicesVert2[fanSize+1] = vert2End;


  //  printf("%d %d %d %d %d %d %d %d\n",vert1Start,vert1End,vert2Start,vert2End,indexVert1Start,indexVert1End,indexVert2Start,indexVert2End);
  //  return 0;

  return fanSize  + 2;
}

static bool modifyInitialMeshForTakingIntoAccountBoundaryLayers(GRegion *gr)
{
  if (getBLField(gr->model())) insertVerticesInRegion(gr,-1);
  if (!buildAdditionalPoints3D (gr)) return false;
  BoundaryLayerColumns* _columns = gr->getColumns();
  std::map<MFace,MElement*,Less_Face> bfaces;

  std::vector<MPrism*> blPrisms;
  std::vector<MHexahedron*> blHexes;
  std::vector<MPyramid*> blPyrs;
  std::list<GFace*> faces = gr->faces();

  std::list<GFace*> embedded_faces = gr->embeddedFaces();
  faces.insert(faces.begin(), embedded_faces.begin(),embedded_faces.end());
  std::set<MVertex*> verts;

  std::list<GFace*>::iterator itf = faces.begin();
  while(itf != faces.end()){
    for(unsigned int i = 0; i< (*itf)->triangles.size(); i++){
      MVertex *v1 = (*itf)->triangles[i]->getVertex(0);
      MVertex *v2 = (*itf)->triangles[i]->getVertex(1);
      MVertex *v3 = (*itf)->triangles[i]->getVertex(2);
      MFace dv(v1,v2,v3);
      addOrRemove (dv,0,bfaces);
      for (unsigned int SIDE = 0 ; SIDE < _columns->_normals3D.count(dv); SIDE ++){
	faceColumn fc =  _columns->getColumns(*itf,v1, v2, v3, SIDE);
	const BoundaryLayerData & c1 = fc._c1;
	const BoundaryLayerData & c2 = fc._c2;
	const BoundaryLayerData & c3 = fc._c3;
	int N = std::min(c1._column.size(),std::min(c2._column.size(),c3._column.size()));
	//	printf("%d Layers\n",N);
	std::vector<MElement*> myCol;
	for (int l=0;l < N ;++l){
	  MVertex *v11,*v12,*v13,*v21,*v22,*v23;
	  v21 = c1._column[l];
	  v22 = c2._column[l];
	  v23 = c3._column[l];
	  if (l == 0){
	    v11 = v1;
	    v12 = v2;
	    v13 = v3;
	  }
	  else {
	    v11 = c1._column[l-1];
	    v12 = c2._column[l-1];
	    v13 = c3._column[l-1];
	  }
	  //	  printf("coucoucouc %p %p %p %p %p %p\n",v11,v12,v13,v21,v22,v23);
	  MPrism *prism = new MPrism(v11,v12,v13,v21,v22,v23);
	  // store the layer the element belongs
	  prism->setPartition(l+1);
	  blPrisms.push_back(prism);
	  myCol.push_back(prism);
	}
	if (!myCol.empty()){
	  for (unsigned int l=0;l<myCol.size();l++)_columns->_toFirst[myCol[l]] = myCol[0];
	  _columns->_elemColumns[myCol[0]] = myCol;
	}
      }
    }
    ++itf;
  }

  std::set<MEdge,Less_Edge> edges;
  {
    std::list<GEdge*> gedges = gr->edges();
    for (std::list<GEdge*>::iterator it = gedges.begin(); it != gedges.end() ; ++it){
      for (unsigned int i=0;i<(*it)->lines.size();++i){
	edges.insert(MEdge((*it)->lines[i]->getVertex(0),(*it)->lines[i]->getVertex(1)));
      }
    }
  }

  // now treat the Wedges
  // we have to know the two target GFaces that are concerned with a GEdge
  std::set<MEdge>::iterator ite =  edges.begin();
  while(ite != edges.end()){
    MEdge e = *ite;
    MVertex *v1 = e.getVertex(0);
    MVertex *v2 = e.getVertex(1);
    if (v1 != v2){
      int indices1[256];
      int indices2[256];
      int NbW = getWedge (_columns, v1, v2, indices1,indices2);
      for (int i=0;i<NbW-1;i++){
	int i11 = indices1[i];
	int i12 = indices1[i+1];
	int i21 = indices2[i];
	int i22 = indices2[i+1];
	BoundaryLayerData c11 = _columns->getColumn(v1,i11);
	BoundaryLayerData c12 = _columns->getColumn(v1,i12);
	BoundaryLayerData c21 = _columns->getColumn(v2,i21);
	BoundaryLayerData c22 = _columns->getColumn(v2,i22);
	int N = std::min(c11._column.size(),
			 std::min(c12._column.size(),
				  std::min(c21._column.size(), c22._column.size())));
	std::vector<MElement*> myCol;
	for (int l=0;l < N ;++l){
	  MVertex *v11,*v12,*v13,*v14;
	  MVertex *v21,*v22,*v23,*v24;
	  v21 = c11._column[l];
	  v22 = c12._column[l];
	  v23 = c22._column[l];
	  v24 = c21._column[l];
	  if (l == 0){
	    v11 = v12 = v1;
	    v13 = v14 = v2;
	  }
	  else {
	    v11 = c11._column[l-1];
	    v12 = c12._column[l-1];
	    v13 = c22._column[l-1];
	    v14 = c21._column[l-1];
	  }

	  if (l == 0){
	    MPrism *prism = new MPrism(v12,v21,v22,v13,v24,v23);
	    // store the layer the element belongs
	    prism->setPartition(l+1);
	    myCol.push_back(prism);

	    blPrisms.push_back(prism);
	  }
	  else {
	    MHexahedron *hex = new MHexahedron(v11,v12,v13,v14,v21,v22,v23,v24);
	    // store the layer the element belongs
	    myCol.push_back(hex);
	    hex->setPartition(l+1);
	    blHexes.push_back(hex);
	  }
	}
	if (!myCol.empty()){
	  for (unsigned int l=0;l<myCol.size();l++)_columns->_toFirst[myCol[l]] = myCol[0];
	  _columns->_elemColumns[myCol[0]] = myCol;
	}
      }
    }
    ++ite;
  }

  //  filterOverlappingElements (blPrisms,blHexes,_columns->_elemColumns,_columns->_toFirst);
  {
    FILE *ff2 = fopen ("tato3D.pos","w");
    fprintf(ff2,"View \" \"{\n");
    for (unsigned int i = 0; i < blPrisms.size();i++){
      blPrisms[i]->writePOS(ff2,1,0,0,0,0,0);
    }
    for (unsigned int i = 0; i < blHexes.size();i++){
      blHexes[i]->writePOS(ff2,1,0,0,0,0,0);
    }
    fprintf(ff2,"};\n");
    fclose(ff2);
  }

  for (unsigned int i = 0; i < blPrisms.size();i++){
    for (unsigned int j=0;j<5;j++)
      addOrRemove(blPrisms[i]->getFace(j),blPrisms[i],bfaces);
    for (int j = 0; j < 6; j++)
      if(blPrisms[i]->getVertex(j)->onWhat() == gr)verts.insert(blPrisms[i]->getVertex(j));
  }
  for (unsigned int i = 0; i < blHexes.size();i++){
    for (unsigned int j=0;j<6;j++)
      addOrRemove(blHexes[i]->getFace(j),blHexes[i],bfaces);
    for (int j = 0; j < 8; j++)
      if(blHexes[i]->getVertex(j)->onWhat() == gr)verts.insert(blHexes[i]->getVertex(j));
  }

  discreteFace *nf = new discreteFace(gr->model(), 444444);
  gr->model()->add (nf);
  std::list<GFace*> hop;
  std::map<MFace,MElement*,Less_Face>::iterator it =  bfaces.begin();

  FILE *ff = fopen ("toto3D.pos","w");
  fprintf(ff,"View \" \"{\n");
  for (; it != bfaces.end(); ++it){
    if (it->first.getNumVertices() == 3){
      nf->triangles.push_back(new MTriangle (it->first.getVertex(0),it->first.getVertex(1),it->first.getVertex(2)));
      fprintf(ff,"ST (%g,%g,%g,%g,%g,%g,%g,%g,%g){1,1,1};\n",
	      it->first.getVertex(0)->x(),it->first.getVertex(0)->y(),it->first.getVertex(0)->z(),
	      it->first.getVertex(1)->x(),it->first.getVertex(1)->y(),it->first.getVertex(1)->z(),
	      it->first.getVertex(2)->x(),it->first.getVertex(2)->y(),it->first.getVertex(2)->z());
    }
    else {

      // we have a quad face --> create a pyramid

      MElement *e = it->second;

      // compute the center of the face;
      SPoint3 center (0.25*(it->first.getVertex(0)->x()+it->first.getVertex(1)->x()+it->first.getVertex(2)->x()+it->first.getVertex(3)->x()),
		      0.25*(it->first.getVertex(0)->y()+it->first.getVertex(1)->y()+it->first.getVertex(2)->y()+it->first.getVertex(3)->y()),
		      0.25*(it->first.getVertex(0)->z()+it->first.getVertex(1)->z()+it->first.getVertex(2)->z()+it->first.getVertex(3)->z()));
      // compute the center of the opposite face;
      SPoint3 opposite (0,0,0);
      int counter=0;
      for (int i=0;i<e->getNumVertices();i++){
	MVertex *vv = e->getVertex(i);
	bool found = false;
	for (int j=0;j<4;j++){
	  MVertex *ww = it->first.getVertex(j);
	  if (ww == vv)found = true;
	}
	if (!found){
	  counter ++;
	  opposite += SPoint3(vv->x(),vv->y(),vv->z());
	}
      }
      //      printf("counter = %d\n",counter);
      opposite /= (double)counter;

      SVector3 dir = center - opposite;
      MTriangle temp (it->first.getVertex(0),it->first.getVertex(1),it->first.getVertex(2));
      double D = temp.minEdge();
      dir.normalize();
      const double eps = D*1.e-2;
      MVertex *newv = new MVertex (center.x() + eps * dir.x(),center.y() + eps * dir.y(), center.z() + eps * dir.z(), gr);

      MPyramid *pyr = new MPyramid (it->first.getVertex(0),it->first.getVertex(1),it->first.getVertex(2),it->first.getVertex(3),newv);
      verts.insert(newv);
      blPyrs.push_back(pyr);

      nf->triangles.push_back(new MTriangle (it->first.getVertex(0),it->first.getVertex(1),newv));
      nf->triangles.push_back(new MTriangle (it->first.getVertex(1),it->first.getVertex(2),newv));
      nf->triangles.push_back(new MTriangle (it->first.getVertex(2),it->first.getVertex(3),newv));
      nf->triangles.push_back(new MTriangle (it->first.getVertex(3),it->first.getVertex(0),newv));

      fprintf(ff,"ST (%g,%g,%g,%g,%g,%g,%g,%g,%g){2,2,2};\n",
	      it->first.getVertex(0)->x(),it->first.getVertex(0)->y(),it->first.getVertex(0)->z(),
	      it->first.getVertex(1)->x(),it->first.getVertex(1)->y(),it->first.getVertex(1)->z(),
	      newv->x(),newv->y(),newv->z());

      fprintf(ff,"ST (%g,%g,%g,%g,%g,%g,%g,%g,%g){2,2,2};\n",
	      it->first.getVertex(1)->x(),it->first.getVertex(1)->y(),it->first.getVertex(1)->z(),
	      it->first.getVertex(2)->x(),it->first.getVertex(2)->y(),it->first.getVertex(2)->z(),
	      newv->x(),newv->y(),newv->z());

      fprintf(ff,"ST (%g,%g,%g,%g,%g,%g,%g,%g,%g){2,2,2};\n",
	      it->first.getVertex(2)->x(),it->first.getVertex(2)->y(),it->first.getVertex(2)->z(),
	      it->first.getVertex(3)->x(),it->first.getVertex(3)->y(),it->first.getVertex(3)->z(),
	      newv->x(),newv->y(),newv->z());
      fprintf(ff,"ST (%g,%g,%g,%g,%g,%g,%g,%g,%g){2,2,2};\n",
	      it->first.getVertex(3)->x(),it->first.getVertex(3)->y(),it->first.getVertex(3)->z(),
	      it->first.getVertex(0)->x(),it->first.getVertex(0)->y(),it->first.getVertex(0)->z(),
	      newv->x(),newv->y(),newv->z());

      fprintf(ff,"SQ (%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){3,3,3,3};\n",
	      it->first.getVertex(0)->x(),it->first.getVertex(0)->y(),it->first.getVertex(0)->z(),
	      it->first.getVertex(1)->x(),it->first.getVertex(1)->y(),it->first.getVertex(1)->z(),
	      it->first.getVertex(2)->x(),it->first.getVertex(2)->y(),it->first.getVertex(2)->z(),
	      it->first.getVertex(3)->x(),it->first.getVertex(3)->y(),it->first.getVertex(3)->z());
    }
  }
  fprintf(ff,"};\n");
  fclose(ff);

  printf("discrete face with %d %d elems\n", (int)nf->triangles.size(),
         (int)nf->quadrangles.size());
  hop.push_back(nf);

  for(unsigned int i = 0; i < gr->tetrahedra.size(); i++) delete gr->tetrahedra[i];
  gr->tetrahedra.clear();

  gr->set(hop);
  CreateAnEmptyVolumeMesh(gr);
  printf("%d tets\n", (int)gr->tetrahedra.size());
  deMeshGFace _kill;
  _kill (nf);
  gr->model()->remove(nf);
  delete nf;

  gr->set(faces);
  gr->mesh_vertices.insert(gr->mesh_vertices.begin(),verts.begin(),verts.end());

  gr->model()->writeMSH("BL_start.msh");

  AssociateElementsToModelRegionWithBoundaryLayers(gr, gr->tetrahedra, blHexes,
                                                   blPrisms, blPyrs);

  gr->model()->writeMSH("BL_start2.msh");

  return true;
}

void _relocateVertex(MVertex *ver,
		     const std::vector<MElement*> &lt)
{
  if(ver->onWhat()->dim() != 3) return;
  double x = 0, y=0, z=0;
  int N = 0;
  bool isPyramid = false;
  for(unsigned int i = 0; i < lt.size(); i++){
    double XCG=0,YCG=0,ZCG=0;
    for (int j=0;j<lt[i]->getNumVertices();j++){
      XCG += lt[i]->getVertex(j)->x();
      YCG += lt[i]->getVertex(j)->y();
      ZCG += lt[i]->getVertex(j)->z();
    }
    x += XCG;
    y += YCG;
    z += ZCG;
    if (lt[i]->getNumVertices() == 5) isPyramid = true;
    N += lt[i]->getNumVertices();
  }
  if (isPyramid){
    ver->x() = x / N;
    ver->y() = y / N;
    ver->z() = z / N;
  }
}

#if defined(HAVE_TETGEN)
bool CreateAnEmptyVolumeMesh(GRegion *gr)
{
  printf("creating an empty volume mesh\n");
  splitQuadRecovery sqr;
  tetgenio in, out;
  std::vector<MVertex*> numberedV;
  char opts[128];
  buildTetgenStructure(gr, in, numberedV, sqr);
  printf("tetgen structure created\n");
  sprintf(opts, "-Ype%c",
	  (Msg::GetVerbosity() < 3) ? 'Q':
	  (Msg::GetVerbosity() > 6) ? 'V': '\0');
  try{
    tetrahedralize(opts, &in, &out);
  }
  catch (int error){
    Msg::Error("Self intersecting surface mesh");
    return false;
  }
  printf("creating an empty volume mesh done\n");
  TransferTetgenMesh(gr, in, out, numberedV);
  return true;
}

#else

bool CreateAnEmptyVolumeMesh(GRegion *gr)
{
  Msg::Error("You should compile with TETGEN in order to create an empty volume mesh");
  return false;
}

#endif

void MeshDelaunayVolumeTetgen(std::vector<GRegion*> &regions)
{
  if(regions.empty()) return;

#if !defined(HAVE_TETGEN)
  Msg::Error("Tetgen is not compiled in this version of Gmsh");
#else

  for(unsigned int i = 0; i < regions.size(); i++)
    Msg::Info("Meshing volume %d (Delaunay)", regions[i]->tag());

  // put all the faces in the same model
  GRegion *gr = regions[0];
  std::list<GFace*> faces = gr->faces();

  std::set<GFace*> allFacesSet;
  for(unsigned int i = 0; i < regions.size(); i++){
    std::list<GFace*> f = regions[i]->faces();
    allFacesSet.insert(f.begin(), f.end());
    f = regions[i]->embeddedFaces();
    allFacesSet.insert(f.begin(), f.end());
  }
  std::list<GFace*> allFaces;
  for(std::set<GFace*>::iterator it = allFacesSet.begin(); it != allFacesSet.end(); it++){
    allFaces.push_back(*it);
  }
  gr->set(allFaces);

  // mesh with tetgen, possibly changing the mesh on boundaries (leave
  // this in block, so in/out are destroyed before we refine the mesh)
  splitQuadRecovery sqr;
  {
    tetgenio in, out;
    std::vector<MVertex*> numberedV;
    char opts[128];
    buildTetgenStructure(gr, in, numberedV, sqr);
    if(CTX::instance()->mesh.algo3d == ALGO_3D_FRONTAL_DEL ||
       CTX::instance()->mesh.algo3d == ALGO_3D_FRONTAL_HEX ||
       CTX::instance()->mesh.algo3d == ALGO_3D_MMG3D ||
       CTX::instance()->mesh.algo2d == ALGO_2D_FRONTAL_QUAD ||
       CTX::instance()->mesh.algo2d == ALGO_2D_BAMG){
      sprintf(opts, "Ype%c",  (Msg::GetVerbosity() < 3) ? 'Q':
	      (Msg::GetVerbosity() > 6) ? 'V': '\0');
      // removed -q because mesh sizes at new vertices are wrong
      // sprintf(opts, "-q1.5pY%c",  (Msg::GetVerbosity() < 3) ? 'Q':
      // 	 (Msg::GetVerbosity() > 6) ? 'V': '\0');
    }
    else if (CTX::instance()->mesh.algo3d == ALGO_3D_RTREE){
       sprintf(opts, "S0Ype%c",  (Msg::GetVerbosity() < 3) ? 'Q':
	       (Msg::GetVerbosity() > 6) ? 'V': '\0');
    }
    else {
      sprintf(opts, "Ype%c",
              (Msg::GetVerbosity() < 3) ? 'Q':
              (Msg::GetVerbosity() > 6) ? 'V': '\0');
      // removed -q because mesh sizes at new vertices are wrong
      // sprintf(opts, "-q3.5Ype%c", (Msg::GetVerbosity() < 3) ? 'Q':
      //        (Msg::GetVerbosity() > 6) ? 'V': '\0');*/
    }
    try{
      tetrahedralize(opts, &in, &out);
    }
    catch (int error){
      Msg::Error("Self intersecting surface mesh, computing intersections "
                 "(this could take a while)");
      sprintf(opts, "dV");
      try{
        tetrahedralize(opts, &in, &out);
        Msg::Info("%d intersecting faces have been saved into 'intersect.pos'",
                  out.numberoftrifaces);
        FILE *fp = Fopen("intersect.pos", "w");
        if(fp){
          fprintf(fp, "View \"intersections\" {\n");
          for(int i = 0; i < out.numberoftrifaces; i++){
            MVertex *v1 = numberedV[out.trifacelist[i * 3 + 0] - 1];
            MVertex *v2 = numberedV[out.trifacelist[i * 3 + 1] - 1];
            MVertex *v3 = numberedV[out.trifacelist[i * 3 + 2] - 1];
            int surf = out.trifacemarkerlist[i];
            fprintf(fp, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
                    v1->x(), v1->y(), v1->z(), v2->x(), v2->y(), v2->z(),
                    v3->x(), v3->y(), v3->z(), surf, surf, surf);
          }
          fprintf(fp, "};\n");
          fclose(fp);
        }
        else
          Msg::Error("Could not open file 'intersect.pos'");
      }
      catch (int error2){
        Msg::Error("Surface mesh is wrong, cannot do the 3D mesh");
      }
      gr->set(faces);
      return;
    }
    TransferTetgenMesh(gr, in, out, numberedV);
  }


   // sort triangles in all model faces in order to be able to search in vectors
  std::list<GFace*>::iterator itf =  allFaces.begin();
  while(itf != allFaces.end()){
    compareMTriangleLexicographic cmp;
    std::sort((*itf)->triangles.begin(), (*itf)->triangles.end(), cmp);
    ++itf;
  }

  // restore the initial set of faces
  gr->set(faces);

  bool _BL = modifyInitialMeshForTakingIntoAccountBoundaryLayers(gr);

  // now do insertion of points
  if(CTX::instance()->mesh.algo3d == ALGO_3D_FRONTAL_DEL)
    bowyerWatsonFrontalLayers(gr, false);
  else if(CTX::instance()->mesh.algo3d == ALGO_3D_FRONTAL_HEX)
    bowyerWatsonFrontalLayers(gr, true);
  else if(CTX::instance()->mesh.algo3d == ALGO_3D_MMG3D){
    refineMeshMMG(gr);
  }
  else
    if(!Filler::get_nbr_new_vertices() && !LpSmoother::get_nbr_interior_vertices()){
      insertVerticesInRegion(gr,2000000000,!_BL);
    }

  //emi test frame field
  // int NumSmooth = 10;//CTX::instance()->mesh.smoothCrossField
  // std::cout << "NumSmooth = " << NumSmooth << std::endl;
  // if(NumSmooth && (gr->dim() == 3)){
  //   double scale = gr->bounds().diag()*1e-2;
  //   Frame_field::initRegion(gr,NumSmooth);
  //   Frame_field::saveCrossField("cross0.pos",scale);
  //   //Frame_field::smoothRegion(gr,NumSmooth);
  //   //Frame_field::saveCrossField("cross1.pos",scale);
  //   GFace *gf = GModel::current()->getFaceByTag(2);
  //   Frame_field::continuousCrossField(gr,gf);
  //   Frame_field::saveCrossField("cross2.pos",scale);
  // }
  // Frame_field::init_region(gr);
  // Frame_field::clear();
  // exit(1);
  //fin test emi

 if (sqr.buildPyramids (gr->model())){
   // relocate vertices if pyramids
   for(unsigned int k = 0; k < regions.size(); k++){
     v2t_cont adj;
     buildVertexToElement(regions[k]->tetrahedra, adj);
     buildVertexToElement(regions[k]->pyramids, adj);
     v2t_cont::iterator it = adj.begin();
     while (it != adj.end()){
       _relocateVertex( it->first, it->second);
       ++it;
     }
   }
 }
#endif
}

// uncomment this to test the new code
#define NEW_CODE

void MeshDelaunayVolume(std::vector<GRegion*> &regions)
{
  if(regions.empty()) return;

#if !defined(NEW_CODE) && defined(HAVE_TETGEN)
  MeshDelaunayVolumeTetgen(regions);
  return;
#endif

  for(unsigned int i = 0; i < regions.size(); i++)
    Msg::Info("Meshing volume %d (Delaunay)", regions[i]->tag());

  // put all the faces in the same model
  GRegion *gr = regions[0];
  std::list<GFace*> faces = gr->faces();

  std::set<GFace*> allFacesSet;
  for(unsigned int i = 0; i < regions.size(); i++){
    std::list<GFace*> f = regions[i]->faces();
    allFacesSet.insert(f.begin(), f.end());
    f = regions[i]->embeddedFaces();
    allFacesSet.insert(f.begin(), f.end());
  }
  std::list<GFace*> allFaces;
  for(std::set<GFace*>::iterator it = allFacesSet.begin();
      it != allFacesSet.end(); it++){
    allFaces.push_back(*it);
  }
  gr->set(allFaces);

  try{
    meshGRegionBoundaryRecovery *init = new meshGRegionBoundaryRecovery();
    init->reconstructmesh(gr);
    delete init;
  }
  catch(int err){
    Msg::Error("Could not recover boundary: error %d", err);
  }

  // sort triangles in all model faces in order to be able to search in vectors
  std::list<GFace*>::iterator itf =  allFaces.begin();
  while(itf != allFaces.end()){
    compareMTriangleLexicographic cmp;
    std::sort((*itf)->triangles.begin(), (*itf)->triangles.end(), cmp);
    ++itf;
  }

  // restore the initial set of faces
  gr->set(faces);

  bool _BL = modifyInitialMeshForTakingIntoAccountBoundaryLayers(gr);

  // now do insertion of points
  if(CTX::instance()->mesh.algo3d == ALGO_3D_FRONTAL_DEL)
    bowyerWatsonFrontalLayers(gr, false);
  else if(CTX::instance()->mesh.algo3d == ALGO_3D_FRONTAL_HEX)
    bowyerWatsonFrontalLayers(gr, true);
  else if(CTX::instance()->mesh.algo3d == ALGO_3D_MMG3D){
    refineMeshMMG(gr);
  }
  else if(!Filler::get_nbr_new_vertices() && !LpSmoother::get_nbr_interior_vertices()){
    insertVerticesInRegion(gr,2000000000,!_BL);
  }

}

#if defined(HAVE_NETGEN)

namespace nglib {
#include "nglib_gmsh.h"
}
using namespace nglib;

static void getAllBoundingVertices(GRegion *gr, std::set<MVertex*> &allBoundingVertices)
{
  std::list<GFace*> faces = gr->faces();
  std::list<GFace*>::iterator it = faces.begin();

  while (it != faces.end()){
    GFace *gf = (*it);
    for(unsigned int i = 0; i < gf->triangles.size(); i++){
      MTriangle *t = gf->triangles[i];
      for(int k = 0; k < 3; k++)
        if(allBoundingVertices.find(t->getVertex(k)) ==  allBoundingVertices.end())
          allBoundingVertices.insert(t->getVertex(k));
    }
    ++it;
  }
}

Ng_Mesh *buildNetgenStructure(GRegion *gr, bool importVolumeMesh,
                              std::vector<MVertex*> &numberedV)
{
  Ng_Init();
  Ng_Mesh *ngmesh = Ng_NewMesh();

  std::set<MVertex*> allBoundingVertices;
  getAllBoundingVertices(gr, allBoundingVertices);

  std::set<MVertex*>::iterator itv = allBoundingVertices.begin();
  int I = 1;
  while(itv != allBoundingVertices.end()){
    double tmp[3];
    tmp[0] = (*itv)->x();
    tmp[1] = (*itv)->y();
    tmp[2] = (*itv)->z();
    (*itv)->setIndex(I++);
    numberedV.push_back(*itv);
    Ng_AddPoint(ngmesh, tmp);
    ++itv;
  }

  if(importVolumeMesh){
    for(unsigned int i = 0; i < gr->mesh_vertices.size(); i++){
      double tmp[3];
      tmp[0] = gr->mesh_vertices[i]->x();
      tmp[1] = gr->mesh_vertices[i]->y();
      tmp[2] = gr->mesh_vertices[i]->z();
      gr->mesh_vertices[i]->setIndex(I++);
      Ng_AddPoint(ngmesh, tmp);
    }
  }
  std::list<GFace*> faces = gr->faces();
  std::list<GFace*>::iterator it = faces.begin();
  while(it != faces.end()){
    GFace *gf = (*it);
    for(unsigned int i = 0; i< gf->triangles.size(); i++){
      MTriangle *t = gf->triangles[i];
      int tmp[3];
      tmp[0] = t->getVertex(0)->getIndex();
      tmp[1] = t->getVertex(1)->getIndex();
      tmp[2] = t->getVertex(2)->getIndex();
      Ng_AddSurfaceElement(ngmesh, NG_TRIG, tmp);
    }
    ++it;
  }

  if(importVolumeMesh){
    for(unsigned int i = 0; i< gr->tetrahedra.size(); i++){
      MTetrahedron *t = gr->tetrahedra[i];
      // netgen expects tet with negative volume
      if(t->getVolumeSign() > 0) t->reverse();
      int tmp[4];
      tmp[0] = t->getVertex(0)->getIndex();
      tmp[1] = t->getVertex(1)->getIndex();
      tmp[2] = t->getVertex(2)->getIndex();
      tmp[3] = t->getVertex(3)->getIndex();
      Ng_AddVolumeElement(ngmesh, NG_TET, tmp);
    }
  }

  return ngmesh;
}

void TransferVolumeMesh(GRegion *gr, Ng_Mesh *ngmesh,
                        std::vector<MVertex*> &numberedV)
{
  // Gets total number of vertices of Netgen's mesh
  int nbv = Ng_GetNP(ngmesh);
  if(!nbv) return;

  int nbpts = numberedV.size();

  // Create new volume vertices
  for(int i = nbpts; i < nbv; i++){
    double tmp[3];
    Ng_GetPoint(ngmesh, i + 1, tmp);
    MVertex *v = new MVertex (tmp[0], tmp[1], tmp[2], gr);
    numberedV.push_back(v);
    gr->mesh_vertices.push_back(v);
  }

  // Get total number of simplices of Netgen's mesh
  int nbe = Ng_GetNE(ngmesh);

  // Create new volume simplices
  for(int i = 0; i < nbe; i++){
    int tmp[4];
    Ng_GetVolumeElement(ngmesh, i + 1, tmp);
    MTetrahedron *t = new MTetrahedron(numberedV[tmp[0] - 1],
                                       numberedV[tmp[1] - 1],
                                       numberedV[tmp[2] - 1],
                                       numberedV[tmp[3] - 1]);
    gr->tetrahedra.push_back(t);
  }
}

#endif

void deMeshGRegion::operator() (GRegion *gr)
{
  if(gr->geomType() == GEntity::DiscreteVolume) return;
  gr->deleteMesh();
}

int intersect_line_triangle(double X[3], double Y[3], double Z[3] ,
                            double P[3], double N[3], double eps_prec)
{
  double mat[3][3], det;
  double b[3], res[3];

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

  if(res[0] >= eps_prec && res[0] <= 1.0 - eps_prec &&
     res[1] >= eps_prec && res[1] <= 1.0 - eps_prec &&
     1 - res[0] - res[1] >= eps_prec && 1 - res[0] - res[1] <= 1.0 - eps_prec){
    // the line clearly intersects the triangle
    return (res[2] > 0) ? 1 : 0;
  }
  else if(res[0] < -eps_prec || res[0] > 1.0 + eps_prec ||
          res[1] < -eps_prec || res[1] > 1.0 + eps_prec ||
          1 - res[0] - res[1] < -eps_prec || 1 - res[0] - res[1] > 1.0 + eps_prec){
    // the line clearly does NOT intersect the triangle
    return 0;
  }
  else{
    // the intersection is not robust, try another triangle
    return -10000;
  }
}

void setRand(double r[6])
{
  for(int i = 0; i < 6; i++)
    r[i] = 0.0001 * ((double)rand() / (double)RAND_MAX);
}

void meshNormalsPointOutOfTheRegion(GRegion *gr)
{
  std::list<GFace*> faces = gr->faces();
  std::list<GFace*>::iterator it = faces.begin();

  //for (std::list<GFace*>::iterator itb = faces.begin(); itb != faces.end(); itb ++)
  //  printf("face=%d size =%d\n", (*itb)->tag(), faces.size());

  double rrr[6];
  setRand(rrr);

  while(it != faces.end()){
    GFace *gf = (*it);
    int nb_intersect = 0;
    for(unsigned int i = 0; i < gf->triangles.size(); i++){
      MTriangle *t = gf->triangles[i];
      double X[3] = {t->getVertex(0)->x(), t->getVertex(1)->x(), t->getVertex(2)->x()};
      double Y[3] = {t->getVertex(0)->y(), t->getVertex(1)->y(), t->getVertex(2)->y()};
      double Z[3] = {t->getVertex(0)->z(), t->getVertex(1)->z(), t->getVertex(2)->z()};
      double P[3] = {(X[0] + X[1] + X[2]) / 3.,
                     (Y[0] + Y[1] + Y[2]) / 3.,
                     (Z[0] + Z[1] + Z[2]) / 3.};
      double v1[3] = {X[0] - X[1], Y[0] - Y[1], Z[0] - Z[1]};
      double v2[3] = {X[2] - X[1], Y[2] - Y[1], Z[2] - Z[1]};
      double N[3];
      prodve(v1, v2, N);
      norme(v1);
      norme(v2);
      norme(N);
      N[0] += rrr[0] * v1[0] + rrr[1] * v2[0];
      N[1] += rrr[2] * v1[1] + rrr[3] * v2[1];
      N[2] += rrr[4] * v1[2] + rrr[5] * v2[2];
      norme(N);
      std::list<GFace*>::iterator it_b = faces.begin();
      while(it_b != faces.end()){
        GFace *gf_b = (*it_b);
        for(unsigned int i_b = 0; i_b < gf_b->triangles.size(); i_b++){
          MTriangle *t_b = gf_b->triangles[i_b];
          if(t_b != t){
            double X_b[3] = {t_b->getVertex(0)->x(), t_b->getVertex(1)->x(),
                             t_b->getVertex(2)->x()};
            double Y_b[3] = {t_b->getVertex(0)->y(), t_b->getVertex(1)->y(),
                             t_b->getVertex(2)->y()};
            double Z_b[3] = {t_b->getVertex(0)->z(), t_b->getVertex(1)->z(),
                             t_b->getVertex(2)->z()};
            int inters = intersect_line_triangle(X_b, Y_b, Z_b, P, N, 1.e-9);
            nb_intersect += inters;
          }
        }
        ++it_b;
      }
      Msg::Info("Region %d Face %d, %d intersect", gr->tag(), gf->tag(), nb_intersect);
      if(nb_intersect >= 0) break; // negative value means intersection is not "robust"
    }

    if(nb_intersect < 0){
      setRand(rrr);
    }
    else{
      if(nb_intersect % 2 == 1){
        // odd nb of intersections: the normal points inside the region
        for(unsigned int i = 0; i < gf->triangles.size(); i++){
          gf->triangles[i]->reverse();
        }
      }
      ++it;
    }
  }

  // FILE *fp = Fopen("debug.pos", "w");
  // fprintf(fp, "View \"debug\" {\n");
  // for(std::list<GFace*>::iterator it = faces.begin(); it != faces.end(); it++)
  //   for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
  //     (*it)->triangles[i]->writePOS(fp, 1., (*it)->tag());
  // fprintf(fp, "};\n");
  // fclose(fp);
}

void meshGRegion::operator() (GRegion *gr)
{

  gr->model()->setCurrentMeshEntity(gr);

  if(gr->geomType() == GEntity::DiscreteVolume) return;
  if(gr->meshAttributes.method == MESH_NONE) return;
  if(CTX::instance()->mesh.meshOnlyVisible && !gr->getVisibility()) return;

  ExtrudeParams *ep = gr->meshAttributes.extrude;
  if(ep && ep->mesh.ExtrudeMesh) return;

  // destroy the mesh if it exists
  deMeshGRegion dem;
  dem(gr);

  if(MeshTransfiniteVolume(gr)) return;

  std::list<GFace*> faces = gr->faces();

  // sanity check for frontal algo
  if(CTX::instance()->mesh.algo3d == ALGO_3D_FRONTAL){
    for(std::list<GFace*>::iterator it = faces.begin(); it != faces.end(); it++){
      if((*it)->quadrangles.size()){
	Msg::Error("Cannot use frontal 3D algorithm with quadrangles on boundary");
	return;
      }
    }
  }

  // replace discreteFaces by their compounds
  {
    std::set<GFace*> mySet;
    std::list<GFace*>::iterator it = faces.begin();
    while(it != faces.end()){
      if((*it)->getCompound())
        mySet.insert((*it)->getCompound());
      else
        mySet.insert(*it);
      ++it;
    }
    faces.clear();
    faces.insert(faces.begin(), mySet.begin(), mySet.end());
    gr->set(faces);
  }

  if(CTX::instance()->mesh.algo3d != ALGO_3D_FRONTAL){
    delaunay.push_back(gr);
  }
  else if(CTX::instance()->mesh.algo3d == ALGO_3D_FRONTAL){
#if !defined(HAVE_NETGEN)
    Msg::Error("Netgen is not compiled in this version of Gmsh");
#else
    Msg::Info("Meshing volume %d (Frontal)", gr->tag());
    // orient the triangles of with respect to this region
    meshNormalsPointOutOfTheRegion(gr);
    std::vector<MVertex*> numberedV;
    Ng_Mesh *ngmesh = buildNetgenStructure(gr, false, numberedV);
    Ng_GenerateVolumeMesh(ngmesh, CTX::instance()->mesh.lcMax);
    TransferVolumeMesh(gr, ngmesh, numberedV);
    Ng_DeleteMesh(ngmesh);
    Ng_Exit();
#endif
  }

}

void optimizeMeshGRegionNetgen::operator() (GRegion *gr)
{
  gr->model()->setCurrentMeshEntity(gr);

  if(gr->geomType() == GEntity::DiscreteVolume) return;

  // don't optimize transfinite or extruded meshes
  if(gr->meshAttributes.method == MESH_TRANSFINITE) return;
  ExtrudeParams *ep = gr->meshAttributes.extrude;
  if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY) return;

#if !defined(HAVE_NETGEN)
  Msg::Error("Netgen is not compiled in this version of Gmsh");
#else
  Msg::Info("Optimizing volume %d", gr->tag());
  // import mesh into netgen, including volume tets
  std::vector<MVertex*> numberedV;
  Ng_Mesh *ngmesh = buildNetgenStructure(gr, true, numberedV);
  // delete volume vertices and tets
  deMeshGRegion dem;
  dem(gr);
  // optimize mesh
  Ng_OptimizeVolumeMesh(ngmesh, CTX::instance()->mesh.lcMax);
  TransferVolumeMesh(gr, ngmesh, numberedV);
  Ng_DeleteMesh(ngmesh);
  Ng_Exit();
#endif
}

void optimizeMeshGRegionGmsh::operator() (GRegion *gr)
{
  gr->model()->setCurrentMeshEntity(gr);

  if(gr->geomType() == GEntity::DiscreteVolume) return;

  // don't optimize extruded meshes
  if(gr->meshAttributes.method == MESH_TRANSFINITE) return;
  ExtrudeParams *ep = gr->meshAttributes.extrude;
  if(ep && ep->mesh.ExtrudeMesh && ep->geo.Mode == EXTRUDED_ENTITY) return;

  Msg::Info("Optimizing volume %d", gr->tag());
  optimizeMesh(gr, QMTET_2);
}

bool buildFaceSearchStructure(GModel *model, fs_cont &search)
{
  search.clear();

  std::set<GFace*> faces_to_consider;
  GModel::riter rit = model->firstRegion();
  while(rit != model->lastRegion()){
    std::list <GFace *> _faces = (*rit)->faces();
    faces_to_consider.insert( _faces.begin(),_faces.end());
    rit++;
  }

  std::set<GFace*>::iterator fit = faces_to_consider.begin();
  while(fit != faces_to_consider.end()){
    for(unsigned int i = 0; i < (*fit)->triangles.size(); i++){
      MVertex *p1 = (*fit)->triangles[i]->getVertex(0);
      MVertex *p2 = (*fit)->triangles[i]->getVertex(1);
      MVertex *p3 = (*fit)->triangles[i]->getVertex(2);
      MVertex *p = std::min(p1, std::min(p2, p3));
      search.insert(std::pair<MVertex*, std::pair<MTriangle*, GFace*> >
                    (p, std::pair<MTriangle*, GFace*>((*fit)->triangles[i], *fit)));
    }
    ++fit;
  }
  return true;
}

bool buildEdgeSearchStructure(GModel *model, es_cont &search)
{
  search.clear();

  GModel::eiter eit = model->firstEdge();
  while(eit != model->lastEdge()){
    for(unsigned int i = 0; i < (*eit)->lines.size(); i++){
      MVertex *p1 = (*eit)->lines[i]->getVertex(0);
      MVertex *p2 = (*eit)->lines[i]->getVertex(1);
      MVertex *p = std::min(p1, p2);
      search.insert(std::pair<MVertex*, std::pair<MLine*, GEdge*> >
                    (p, std::pair<MLine*, GEdge*>((*eit)->lines[i], *eit)));
    }
    ++eit;
  }
  return true;
}

GFace *findInFaceSearchStructure(MVertex *p1, MVertex *p2, MVertex *p3,
                                 const fs_cont &search)
{
  MVertex *p = std::min(p1, std::min(p2, p3));

  for(fs_cont::const_iterator it = search.lower_bound(p);
      it != search.upper_bound(p);
      ++it){
    MTriangle *t = it->second.first;
    GFace *gf= it->second.second;
    if((t->getVertex(0) == p1 || t->getVertex(0) == p2 || t->getVertex(0) == p3) &&
       (t->getVertex(1) == p1 || t->getVertex(1) == p2 || t->getVertex(1) == p3) &&
       (t->getVertex(2) == p1 || t->getVertex(2) == p2 || t->getVertex(2) == p3))
      return gf;
  }
  return 0;
}

GEdge *findInEdgeSearchStructure(MVertex *p1, MVertex *p2, const es_cont &search)
{
  MVertex *p = std::min(p1, p2);

  for(es_cont::const_iterator it = search.lower_bound(p);
      it != search.upper_bound(p);
      ++it){
    MLine *l = it->second.first;
    GEdge *ge = it->second.second;
    if((l->getVertex(0) == p1 || l->getVertex(0) == p2) &&
       (l->getVertex(1) == p1 || l->getVertex(1) == p2))
      return ge;
  }
  return 0;
}
