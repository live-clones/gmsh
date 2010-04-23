#include <set>
#include "meshGFaceLloyd.h"
#include "DivideAndConquer.h"
#include "GFace.h"
#include "MElement.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "Context.h"
#include "meshGFace.h"
#include "BackgroundMesh.h"


void lloydAlgorithm::operator () ( GFace * gf) {
  std::set<MVertex*> all;

  // get all the points of the face ...

  for (unsigned int i = 0; i < gf->getNumMeshElements(); i++){
    MElement *e = gf->getMeshElement(i);
    for (int j = 0;j<e->getNumVertices(); j++){
      all.insert(e->getVertex(j));
    }
  }

  backgroundMesh::set(gf);
  backgroundMesh::current()->print("bgm.pos",0);

  // Create a triangulator
  DocRecord triangulator (all.size());
  
  Range<double> du = gf->parBounds(0) ;
  Range<double> dv = gf->parBounds(1) ;

  const double LC2D = sqrt ((du.high()-du.low())*(du.high()-du.low()) +
                            (dv.high()-dv.low())*(dv.high()-dv.low()));  

  //printf("Lloyd on face %d %d elements %d nodes LC %g\n", gf->tag(),
  //       gf->getNumMeshElements(), (int)all.size(), LC2D);

  int i = 0;

  for (std::set<MVertex*>::iterator it = all.begin(); it != all.end(); ++it){
    SPoint2 p;
    bool success = reparamMeshVertexOnFace(*it, gf, p);
    if (!success) {
      Msg::Error("Impossible to apply Lloyd to model face %d",gf->tag());
      Msg::Error("A mesh vertex cannot be reparametrized");
      return;
    }
    double XX = CTX::instance()->mesh.randFactor * LC2D * (double)rand() / 
      (double)RAND_MAX;
    double YY = CTX::instance()->mesh.randFactor * LC2D * (double)rand() / 
      (double)RAND_MAX;
    triangulator.x(i) = p.x() + XX;
    triangulator.y(i) = p.y() + YY;
    triangulator.data(i++) = (*it);
  }

  // compute the Voronoi diagram
  triangulator.Voronoi();
  //printf("hullSize = %d\n",triangulator.hullSize());
  triangulator.makePosView("LloydInit.pos");
  
  // now do the Lloyd iterations
  int ITER = 0;
  while (1){
    // store the new coordinates there
    fullMatrix<double> cgs(triangulator.numPoints,2);
    // now iterate on internal vertices
    double ENERGY = 0.0;
    double criteria = 0.0;
    for (int i=0; i<triangulator.numPoints;i++){
      // get the ith vertex
      PointRecord &pt = triangulator.points[i];
      MVertex *v = (MVertex*)pt.data;
      if (v->onWhat() == gf && !triangulator.onHull(i)){
        // get the voronoi corners
        std::vector<SPoint2> pts;
        triangulator.voronoiCell (i,pts); 
        double E, A;
        SPoint2 p(pt.where.h,pt.where.v);
        if (!infiniteNorm){
          centroidOfPolygon (p,pts, cgs(i,0),cgs(i,1),E, A, NULL); //backgroundMesh::current());       
        }
        else {
          centroidOfOrientedBox (pts, 0.0, cgs(i,0),cgs(i,1),E, A);          
        }
        ENERGY += E;
	double d = sqrt((p.x()-cgs(i,0))*(p.x()-cgs(i,0))+
			(p.y()-cgs(i,1))*(p.y()-cgs(i,1)));
	criteria = d/A;
      }// if (v->onWhat() == gf)
      else {
      }
    }// for all points

    for(PointNumero i = 0; i < triangulator.numPoints; i++) {
      MVertex *v = (MVertex*)triangulator.points[i].data;
      if (v->onWhat() == gf && !triangulator.onHull(i)){
        triangulator.points[i].where.h = cgs(i,0);
        triangulator.points[i].where.v = cgs(i,1);
      }
    }

    Msg::Debug("GFace %d Lloyd-iter %d Inertia=%g Convergence=%g ",gf->tag(),ITER++,ENERGY, criteria);
    if (ITER > ITER_MAX)break;

    // compute the Voronoi diagram
    triangulator.Voronoi();

    if (ITER % 10 == 0){
      char name[234];
      sprintf(name,"LloydIter%d.pos",ITER);
      triangulator.makePosView(name);
    }

  }

  // now create the vertices
  std::vector<MVertex*> mesh_vertices;
  for (int i=0; i<triangulator.numPoints;i++){
    // get the ith vertex
    PointRecord &pt = triangulator.points[i];
    MVertex *v = (MVertex*)pt.data;
    if (v->onWhat() == gf && !triangulator.onHull(i)){
      GPoint gp = gf->point (pt.where.h,pt.where.v);
      MFaceVertex *v = new MFaceVertex(gp.x(),gp.y(),gp.z(),gf,gp.u(),gp.v());
      mesh_vertices.push_back(v);
    }
  }

  // destroy the mesh
  deMeshGFace killer;
  killer(gf);
  
  // put all additional vertices in the list of
  // vertices
  gf->_additional_vertices = mesh_vertices;
  // remesh the face with all those vertices in
  Msg::Info("Lloyd remeshing of face %d ", gf->tag());
  meshGFace mesher;
  mesher(gf);
  // assign those vertices to the face internal vertices
  gf->mesh_vertices.insert(gf->mesh_vertices.begin(),
                           gf->_additional_vertices.begin(),  
                           gf->_additional_vertices.end());  
  // clear the list of additional vertices
  gf->_additional_vertices.clear();  
} 
