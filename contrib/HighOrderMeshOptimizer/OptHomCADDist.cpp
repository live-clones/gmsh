// TODO: Header

#include "MLine.h"
#include "MTriangle.h"
#include "GModel.h"
#include "OptHomCADDist.h"


double MFaceGFaceDistance(MTriangle *t, GFace *gf,
                          std::vector<std::vector<SVector3> > *gsfT,
                          std::map<MVertex*,SVector3> *normalsToCAD) {
  const double h = t->maxEdge();
  double jac[3][3];
  double distFace = 0.0;
  //  for (int j=0;j<3;j++){
  for (int j=0;j<t->getNumVertices();j++){
    // get parametric coordinates of jth vertex
    // the last line of the jacobian is the normal
    // to the element @ (u_mesh,v_mesh)

    if (gsfT){
      double detJ = t->getJacobian((*gsfT)[j],jac);
    }
    else{
      const nodalBasis &elbasis = *t->getFunctionSpace();
      double u_mesh = elbasis.points(j,0);
      double v_mesh = elbasis.points(j,1);
      double detJ = t->getJacobian(u_mesh,v_mesh,0,jac);
    }

    SVector3 tg_mesh (jac[2][0],jac[2][1],jac[2][2]);
    tg_mesh.normalize();

    SVector3 tg_cad ;
    if (normalsToCAD)tg_cad = (*normalsToCAD)[t->getVertex(j)];
    else {
      SPoint2 p_cad;
      reparamMeshVertexOnFace(t->getVertex (j), gf, p_cad);
      tg_cad = gf->normal(p_cad);
      tg_cad.normalize();
    }
    SVector3 diff1 = (dot(tg_cad, tg_mesh) > 0) ?
      tg_cad - tg_mesh : tg_cad + tg_mesh;
    //    printf("%g %g %g vs %g %g %g\n",tg_cad.x(),tg_cad.y(),tg_cad.z(),tg_mesh.x(),tg_mesh.y(),tg_mesh.z());
    distFace += diff1.norm();
  }
  return distFace;
}


double MLineGEdgeDistance (MLine *l, GEdge *ge, FILE *f) {
  const nodalBasis &elbasis = *l->getFunctionSpace();
  const double h = .25*0.5*distance (l->getVertex (0), l->getVertex (1) ) / (l->getNumVertices()-1);
  double jac[3][3];
  double distEdge = 0.0;

  //  if(f)printf("%d\n",l->getNumVertices());

  for (int j=0;j<l->getNumVertices();j++){
    double t_mesh = elbasis.points(j,0);
    //    if (f) printf("%g ",t_mesh);
    double detJ = l->getJacobian(t_mesh,0,0,jac);
    SVector3 tg_mesh (jac[0][0],jac[0][1],jac[0][2]);
    tg_mesh.normalize();
    double t_cad;
    reparamMeshVertexOnEdge(l->getVertex (j), ge, t_cad);
    SVector3 tg_cad = ge->firstDer(t_cad);
    tg_cad.normalize();

    SVector3 diff1 = (dot(tg_cad, tg_mesh) > 0) ?
      tg_cad - tg_mesh : tg_cad + tg_mesh;

    if (f){
      fprintf (f,"SP(%g,%g,%g){%g};\n",l->getVertex (j)->x(),
         l->getVertex (j)->y(),l->getVertex (j)->z(),h*diff1.norm());
    }

    //    SVector3 n = crossprod(tg_cad,tg_mesh);
    //    printf("%g %g vs %g %g\n",tg_cad.x(),tg_cad.y(),tg_mesh.x(),tg_mesh.y());
    distEdge += diff1.norm();
  }
  //  if(f)printf("\n");
  return h*distEdge;
}


void distanceFromElementsToGeometry(GModel *gm, int dim, std::map<MElement*,double> &distances){

  std::map<MEdge,double,Less_Edge> dist2Edge;
  for (GModel::eiter it = gm->firstEdge(); it != gm->lastEdge(); ++it){
    if ((*it)->geomType() == GEntity::Line)continue;
    for (unsigned int i=0;i<(*it)->lines.size(); i++){
      double d = MLineGEdgeDistance ( (*it)->lines[i] , *it );
      MEdge e =  (*it)->lines[i]->getEdge(0);
      dist2Edge[e] = d;
    }
  }

  //  printf("DISTANCE TO GEOMETRY : 1D PART %22.15E\n",Obj);

  std::map<MFace,double,Less_Face> dist2Face;
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it){
    if ((*it)->geomType() == GEntity::Plane)continue;
    for (unsigned int i=0;i<(*it)->triangles.size(); i++){
      double d = MFaceGFaceDistance ( (*it)->triangles[i] , *it );
      MFace f =  (*it)->triangles[i]->getFace(0);
      dist2Face[f] = d;
    }
  }

  std::vector<GEntity*> entities;
  gm->getEntities(entities);
  for (int iEnt = 0; iEnt < entities.size(); ++iEnt) {
    GEntity* &entity = entities[iEnt];
    if (entity->dim() != dim) continue;
    for (int iEl = 0; iEl < entity->getNumMeshElements();iEl++) {       // Detect bad elements
      MElement *element = entity->getMeshElement(iEl);
      double d = 0.0;
      for (int iEdge = 0; iEdge < element->getNumEdges(); ++iEdge) {
  MEdge e =  element->getEdge(iEdge);
  std::map<MEdge,double,Less_Edge>::iterator it = dist2Edge.find(e);
  if(it != dist2Edge.end())d+=it->second;
      }
      for (int iFace = 0; iFace < element->getNumFaces(); ++iFace) {
  MFace f =  element->getFace(iFace);
  std::map<MFace,double,Less_Face>::iterator it = dist2Face.find(f);
  if(it != dist2Face.end())d+=it->second;
      }
      distances[element] = d;
    }
  }
}


double distanceToGeometry(GModel *gm)
{

  FILE *f = fopen("toto.pos","w");
  fprintf(f,"View \"\"{\n");

  double Obj = 0.0;

  for (GModel::eiter it = gm->firstEdge(); it != gm->lastEdge(); ++it){
    if ((*it)->geomType() == GEntity::Line)continue;
    for (unsigned int i=0;i<(*it)->lines.size(); i++){
      //Obj += MLineGEdgeDistance ( (*it)->lines[i] , *it,f );
      Obj = std::max(MLineGEdgeDistance ( (*it)->lines[i] , *it, f ),Obj);
    }
  }

    printf("DISTANCE TO GEOMETRY : 1D PART %22.15E\n",Obj);

  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it){
    if ((*it)->geomType() == GEntity::Plane)continue;
    //    printf("FACE %d with %d triangles\n",(*it)->tag(),(*it)->triangles.size());
    for (unsigned int i=0;i<(*it)->triangles.size(); i++){
      //Obj += MFaceGFaceDistance ( (*it)->triangles[i] , *it );
      Obj = std::max(Obj,MFaceGFaceDistance ( (*it)->triangles[i] , *it ));
    }
  }

  printf("DISTANCE TO GEOMETRY : 1D AND 2D PART %22.15E\n",Obj);
  fprintf(f,"};\n");
  fclose(f);
  return Obj;
}


