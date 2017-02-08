// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <sstream>
#include <stdlib.h>
#include <map>
#include "meshGFace.h"
#include "meshGFaceBDS.h"
#include "meshGFaceDelaunayInsertion.h"
#include "meshGFaceBamg.h"
#include "meshGFaceQuadrilateralize.h"
#include "meshGFaceOptimize.h"
#include "DivideAndConquer.h"
#include "BackgroundMesh.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GEdgeCompound.h"
#include "robustPredicates.h"
#include "discreteFace.h"
#include "GFace.h"
#include "GModel.h"
#include "MVertex.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MElementCut.h"
#include "CenterlineField.h"
#include "meshGFaceElliptic.h"
#include "Context.h"
#include "GPoint.h"
#include "GmshMessage.h"
#include "Numeric.h"
#include "BDS.h"
#include "qualityMeasures.h"
#include "Field.h"
#include "OS.h"
#include "MElementOctree.h"
#include "HighOrder.h"
#include "meshGEdge.h"
#include "meshPartitionOptions.h"
#include "meshPartition.h"
#include "CreateFile.h"
#include "Context.h"
#include "multiscalePartition.h"
#include "meshGFaceLloyd.h"
#include "boundaryLayersData.h"
#include "filterElements.h"

// define this to use the old initial delaunay
#define OLD_CODE_DELAUNAY 1

void copyMesh(GEdge*,GEdge*,int);

static void computeElementShapes(GFace *gf, double &worst, double &avg,
                                 double &best, int &nT, int &greaterThan)
{
  worst = 1.e22;
  avg = 0.0;
  best = 0.0;
  nT = 0;
  greaterThan = 0;
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    double q = qmTriangle::gamma(gf->triangles[i]);
    if(q > .9) greaterThan++;
    avg += q;
    worst = std::min(worst, q);
    best  = std::max(best, q);
    nT++;
  }
  avg /= nT;
}

class quadMeshRemoveHalfOfOneDMesh
{
  GFace *_gf;
public:
  std::map<GEdge*,std::vector<MLine*> > _backup;
  std::map<MEdge, MVertex*,Less_Edge> _middle;
  // remove one point every two and remember middle points
  quadMeshRemoveHalfOfOneDMesh (GFace* gf) : _gf(gf)
  {
    // only do it if a recombination has to be done
    if((CTX::instance()->mesh.recombineAll || gf->meshAttributes.recombine) &&
       CTX::instance()->mesh.algoRecombine == 2){
      // printf("GFace %d removing half of the points in the 1D mesh\n",gf->tag());
      std::list<GEdge*> edges = gf->edges();
      std::list<GEdge*>::iterator ite = edges.begin();
      while(ite != edges.end()){
        if(!(*ite)->isMeshDegenerated()){
          std::vector<MLine*> temp;
          (*ite)->mesh_vertices.clear();
          for(unsigned int i = 0; i< (*ite)->lines.size(); i+=2){
            if (i+1 >= (*ite)->lines.size()){
              Msg::Error("1D mesh cannot be divided by 2");
              break;
            }
            MVertex *v1 = (*ite)->lines[i]->getVertex(0);
            MVertex *v2 = (*ite)->lines[i]->getVertex(1);
            MVertex *v3 = (*ite)->lines[i+1]->getVertex(1);
            v2->x() = 0.5*(v1->x()+v3->x());
            v2->y() = 0.5*(v1->y()+v3->y());
            v2->z() = 0.5*(v1->z()+v3->z());
            temp.push_back(new MLine(v1,v3));
            if (v1->onWhat() == *ite) (*ite)->mesh_vertices.push_back(v1);
            _middle[MEdge(v1,v3)] = v2;
          }
          _backup[*ite] = (*ite)->lines;
          //          printf("line %d goes from %d to %d\n",(*ite)->tag(), (*ite)->lines.size()-1,temp.size()-1);
          (*ite)->lines = temp;
        }
        ++ite;
      }
      CTX::instance()->mesh.lcFactor *=2.0;
    }
  }
  void subdivide ()
  {
    std::vector<MQuadrangle*> qnew;

    std::map<MEdge,MVertex*,Less_Edge> eds;

    for(unsigned int i=0;i<_gf->triangles.size();i++){
      MVertex *v[3];
      SPoint2 m[3];
      for (int j=0;j<3;j++){
        MEdge E = _gf->triangles[i]->getEdge(j);
        SPoint2 p1, p2;
        reparamMeshEdgeOnFace(E.getVertex(0),E.getVertex(1),_gf,p1,p2);
        std::map<MEdge, MVertex *, Less_Edge>::iterator it = _middle.find(E);
        std::map<MEdge, MVertex *, Less_Edge>::iterator it2 = eds.find(E);
        m[j] = p1;
        if (it == _middle.end() && it2 == eds.end()){
          GPoint gp = _gf->point((p1+p2)*0.5);
          double XX = 0.5*(E.getVertex(0)->x()+E.getVertex(1)->x());
          double YY = 0.5*(E.getVertex(0)->y()+E.getVertex(1)->y());
          double ZZ = 0.5*(E.getVertex(0)->z()+E.getVertex(1)->z());
          v[j] = new MFaceVertex (XX,YY,ZZ,_gf,gp.u(),gp.v());
          _gf->mesh_vertices.push_back(v[j]);
          eds[E] = v[j];
        }
        else if (it == _middle.end()){
          v[j] = it2->second;
        }
        else {
          v[j] = it->second;
          v[j]->onWhat()->mesh_vertices.push_back(v[j]);
        }
      }
      GPoint gp    = _gf->point((m[0]+m[1]+m[2])*(1./3.));
      double XX = (v[0]->x()+v[1]->x()+v[2]->x())*(1./3.);
      double YY = (v[0]->y()+v[1]->y()+v[2]->y())*(1./3.);
      double ZZ = (v[0]->z()+v[1]->z()+v[2]->z())*(1./3.);
      MFaceVertex *vmid = new MFaceVertex (XX,YY,ZZ,_gf,gp.u(),gp.v());
      _gf->mesh_vertices.push_back(vmid);
      qnew.push_back(new MQuadrangle(_gf->triangles[i]->getVertex(0),v[0],vmid,v[2]));
      qnew.push_back(new MQuadrangle(_gf->triangles[i]->getVertex(1),v[1],vmid,v[0]));
      qnew.push_back(new MQuadrangle(_gf->triangles[i]->getVertex(2),v[2],vmid,v[1]));
      delete _gf->triangles[i];
    }
    _gf->triangles.clear();
    for(unsigned int i=0;i<_gf->quadrangles.size();i++){
      MVertex *v[4];
      SPoint2 m[4];
      for (int j=0;j<4;j++){
        MEdge E = _gf->quadrangles[i]->getEdge(j);
        SPoint2 p1, p2;
        reparamMeshEdgeOnFace(E.getVertex(0),E.getVertex(1),_gf,p1,p2);
        std::map<MEdge, MVertex *, Less_Edge>::iterator it = _middle.find(E);
        std::map<MEdge, MVertex *, Less_Edge>::iterator it2 = eds.find(E);
        m[j] = p1;
        if (it == _middle.end() && it2 == eds.end()){
          GPoint gp = _gf->point((p1+p2)*0.5);
          double XX = 0.5*(E.getVertex(0)->x()+E.getVertex(1)->x());
          double YY = 0.5*(E.getVertex(0)->y()+E.getVertex(1)->y());
          double ZZ = 0.5*(E.getVertex(0)->z()+E.getVertex(1)->z());
          v[j] = new MFaceVertex (XX,YY,ZZ,_gf,gp.u(),gp.v());
          _gf->mesh_vertices.push_back(v[j]);
          eds[E] = v[j];
        }
        else if (it == _middle.end()){
          v[j] = it2->second;
        }
        else {
          v[j] = it->second;
          v[j]->onWhat()->mesh_vertices.push_back(v[j]);
        }
      }
      GPoint gp    = _gf->point((m[0]+m[1]+m[2]+m[3])*0.25);
      // FIXME : NOT EXACTLY CORRECT, BUT THAT'S THE PLACE WE WANT THE POINT TO RESIDE
      double XX = 0.25*(v[0]->x()+v[1]->x()+v[2]->x()+v[3]->x());
      double YY = 0.25*(v[0]->y()+v[1]->y()+v[2]->y()+v[3]->y());
      double ZZ = 0.25*(v[0]->z()+v[1]->z()+v[2]->z()+v[3]->z());
      MVertex *vmid = new MFaceVertex (XX,YY,ZZ,_gf,gp.u(),gp.v());
      _gf->mesh_vertices.push_back(vmid);
      qnew.push_back(new MQuadrangle(_gf->quadrangles[i]->getVertex(0),v[0],vmid,v[3]));
      qnew.push_back(new MQuadrangle(_gf->quadrangles[i]->getVertex(1),v[1],vmid,v[0]));
      qnew.push_back(new MQuadrangle(_gf->quadrangles[i]->getVertex(2),v[2],vmid,v[1]));
      qnew.push_back(new MQuadrangle(_gf->quadrangles[i]->getVertex(3),v[3],vmid,v[2]));
      delete _gf->quadrangles[i];
    }
    _gf->quadrangles = qnew;
    //    printf("%d triangles %d quads\n",_gf->triangles.size(),_gf->quadrangles.size());
  }
  void finish ()
  {
    if((CTX::instance()->mesh.recombineAll || _gf->meshAttributes.recombine) &&
       CTX::instance()->mesh.algoRecombine == 2){
      // recombine the elements on the half mesh
      CTX::instance()->mesh.lcFactor /=2.0;
      recombineIntoQuads(_gf,true,true,.1,true);
      //      Msg::Info("subdividing");
      subdivide();
      //      _gf->model()->writeMSH("hop2.msh");
      restore();
      recombineIntoQuads(_gf,true,true,1.e-3,false);
      computeElementShapes(_gf,
                           _gf->meshStatistics.worst_element_shape,
                           _gf->meshStatistics.average_element_shape,
                           _gf->meshStatistics.best_element_shape,
                           _gf->meshStatistics.nbTriangle,
                           _gf->meshStatistics.nbGoodQuality);
    }
  }
  void restore ()
  {
    std::list<GEdge*> edges = _gf->edges();
    std::list<GEdge*>::iterator ite = edges.begin();
    while(ite != edges.end()){
      for(unsigned int i = 0; i< (*ite)->lines.size(); i++){
        delete (*ite)->lines[i];
      }
      (*ite)->lines = _backup[*ite];
      ++ite;
    }
  }
};

static void copyMesh(GFace *source, GFace *target)
{
  std::map<MVertex*, MVertex*> vs2vt;

  // add principal vertex pairs

  std::list<GVertex*> s_vtcs = source->vertices();
  std::list<GVertex*> t_vtcs = target->vertices();

  if (s_vtcs.size() != t_vtcs.size()) {
    Msg::Info("Periodicity imposed on topologically incompatible surfaces"
              "(%d vs %d bounding vertices)",s_vtcs.size(),t_vtcs.size());
  }

  std::set<GVertex*> checkVtcs;
  checkVtcs.insert(s_vtcs.begin(),s_vtcs.end());

  for (std::list<GVertex*>::iterator tvIter=t_vtcs.begin();tvIter!=t_vtcs.end();++tvIter) {

    GVertex* gvt = *tvIter;
    std::map<GVertex*,GVertex*>::iterator gvsIter = target->vertexCounterparts.find(gvt);

    if (gvsIter == target->vertexCounterparts.end()) {
      Msg::Info("Error during periodic meshing of surface %d with surface %d:"
                "vertex %d has no periodic counterpart",
                target->tag(),source->tag(),gvt->tag());
    }

    GVertex* gvs = gvsIter->second;
    if (checkVtcs.find(gvs) == checkVtcs.end()) {
      if (gvs) Msg::Info("Error during periodic meshing of surface %d with surface %d:"
                         "vertex %d has periodic counterpart %d outside of source surface",
                         target->tag(),source->tag(),gvt->tag(),gvs->tag());

      else Msg::Info("Error during periodic meshing of surface %d with surface %d:"
                     "vertex %d has no periodic counterpart",
                     target->tag(),source->tag(),gvt->tag());
    }

    MVertex* vs = gvs->mesh_vertices[0];
    MVertex* vt = gvt->mesh_vertices[0];
    vs2vt[vs] = vt;
    target->correspondingVertices[vt] = vs;
  }

  // add corresponding edge nodes assuming edges were correctly meshed already

  std::list<GEdge*> s_edges = source->edges();
  std::list<GEdge*> t_edges = target->edges();

  std::set<GEdge*> checkEdges;
  checkEdges.insert(s_edges.begin(),s_edges.end());

  for (std::list<GEdge*>::iterator te_iter = t_edges.begin();
       te_iter != t_edges.end(); ++te_iter) {

    GEdge* get = *te_iter;

    std::map<GEdge*,std::pair<GEdge*,int> >::iterator gesIter =
      target->edgeCounterparts.find(get);
    if (gesIter == target->edgeCounterparts.end()) {
      Msg::Info("Error during periodic meshing of surface %d with surface %d:"
                "edge %d has no periodic counterpart",
                target->tag(),source->tag(),get->tag());
    }

    GEdge* ges = gesIter->second.first;
    if (checkEdges.find(ges) == checkEdges.end()) {
      Msg::Info("Error during periodic meshing of surface %d with surface %d:"
                "edge %d has periodic counterpart %d outside of get surface",
                target->tag(),source->tag(),get->tag(),ges->tag());
    }

    if (get->mesh_vertices.size() != ges->mesh_vertices.size()) {
      Msg::Info("Error during periodic meshing of surface %d with surface %d:"
                "edge %d has %d vertices, whereas correspondant %d has %d",
                target->tag(),source->tag(),
                get->tag(),get->mesh_vertices.size(),
                ges->tag(),ges->mesh_vertices.size());
    }

    int orientation = gesIter->second.second;
    int is = orientation == 1 ? 0 : get->mesh_vertices.size()-1;

    for (unsigned it=0;it<get->mesh_vertices.size();it++,is+=orientation) {
      MVertex* vs = ges->mesh_vertices[is];
      MVertex* vt = get->mesh_vertices[it];
      vs2vt[vs] = vt;
      target->correspondingVertices[vt] = vs;
    }
  }

  // now transform
  std::vector<double>& tfo = target->affineTransform;

  for(unsigned int i = 0; i < source->mesh_vertices.size(); i++){
    MVertex *vs = source->mesh_vertices[i];
    SPoint2 XXX;

    double ps[4] = {vs->x(), vs->y(), vs->z(), 1.};
    double res[4] = {0., 0., 0., 0.};
    int idx = 0;
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
        res[i] +=  tfo[idx++] * ps[j];

    SPoint3 tp (res[0], res[1], res[2]);
    XXX = target->parFromPoint(tp);

    GPoint gp = target->point(XXX);
    MVertex *vt = new MFaceVertex(gp.x(), gp.y(), gp.z(), target, gp.u(), gp.v());
    target->mesh_vertices.push_back(vt);
    target->correspondingVertices[vt] = vs;
    vs2vt[vs] = vt;
  }

  for (unsigned i = 0; i < source->triangles.size(); i++){
    MVertex *vt[3];
    for (int j = 0; j < 3; j++){
      MVertex *vs = source->triangles[i]->getVertex(j);
      vt[j] = vs2vt[vs];
    }
    if (!vt[0] || !vt[1] ||!vt[2]){
      Msg::Error("Problem in mesh copying procedure %p %p %p %d %d %d",
                 vt[0], vt[1], vt[2], source->triangles[i]->getVertex(0)->onWhat()->dim(),
                 source->triangles[i]->getVertex(1)->onWhat()->dim(),
                 source->triangles[i]->getVertex(2)->onWhat()->dim());
      return;
    }
    target->triangles.push_back(new MTriangle(vt[0], vt[1], vt[2]));
  }

  for (unsigned i = 0; i < source->quadrangles.size(); i++){
    MVertex *v1 = vs2vt[source->quadrangles[i]->getVertex(0)];
    MVertex *v2 = vs2vt[source->quadrangles[i]->getVertex(1)];
    MVertex *v3 = vs2vt[source->quadrangles[i]->getVertex(2)];
    MVertex *v4 = vs2vt[source->quadrangles[i]->getVertex(3)];
    if (!v1 || !v2 || !v3 || !v4){
      Msg::Error("Problem in mesh copying procedure %p %p %p %p %d %d %d %d",
                 v1, v2, v3, v4,
                 source->quadrangles[i]->getVertex(0)->onWhat()->dim(),
                 source->quadrangles[i]->getVertex(1)->onWhat()->dim(),
                 source->quadrangles[i]->getVertex(2)->onWhat()->dim(),
                 source->quadrangles[i]->getVertex(3)->onWhat()->dim());
    }
    target->quadrangles.push_back(new MQuadrangle(v1, v2, v3, v4));
  }
}

void fourthPoint(double *p1, double *p2, double *p3, double *p4)
{
  double c[3];
  circumCenterXYZ(p1, p2, p3, c);
  double vx[3] = {p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]};
  double vy[3] = {p3[0] - p1[0], p3[1] - p1[1], p3[2] - p1[2]};
  double vz[3]; prodve(vx, vy, vz);
  norme(vz);
  double R = sqrt((p1[0] - c[0]) * (p1[0] - c[0]) +
                  (p1[1] - c[1]) * (p1[1] - c[1]) +
                  (p1[2] - c[2]) * (p1[2] - c[2]));
  p4[0] = c[0] + R * vz[0];
  p4[1] = c[1] + R * vz[1];
  p4[2] = c[2] + R * vz[2];
}

static bool noSeam(GFace *gf)
{
  std::list<GEdge*> edges = gf->edges();
  std::list<GEdge*>::iterator it = edges.begin();
  while (it != edges.end()){
    GEdge *ge = *it ;
    bool seam = ge->isSeam(gf);
    if(seam) return false;
    ++it;
  }
  return true;
}

static void remeshUnrecoveredEdges(std::map<MVertex*, BDS_Point*> &recoverMapInv,
                                   std::set<EdgeToRecover> &edgesNotRecovered,
                                   std::list<GFace*> &facesToRemesh)
{
  facesToRemesh.clear();
  deMeshGFace dem;

  std::set<EdgeToRecover>::iterator itr = edgesNotRecovered.begin();
  for(; itr != edgesNotRecovered.end(); ++itr){
    std::list<GFace*> l_faces = itr->ge->faces();
    // un-mesh model faces adjacent to the model edge
    for(std::list<GFace*>::iterator it = l_faces.begin(); it != l_faces.end(); ++it){
      if((*it)->triangles.size() || (*it)->quadrangles.size()){
        facesToRemesh.push_back(*it);
        dem(*it);
      }
    }

    // add a new point in the middle of the intersecting segment
    int p1 = itr->p1;
    int p2 = itr->p2;
    int N = itr->ge->lines.size();
    GVertex *g1 = itr->ge->getBeginVertex();
    GVertex *g2 = itr->ge->getEndVertex();
    Range<double> bb = itr->ge->parBounds(0);

    std::vector<MLine*> newLines;

    for(int i = 0; i < N; i++){
      MVertex *v1 = itr->ge->lines[i]->getVertex(0);
      MVertex *v2 = itr->ge->lines[i]->getVertex(1);
      std::map<MVertex*, BDS_Point*>::iterator itp1 = recoverMapInv.find(v1);
      std::map<MVertex*, BDS_Point*>::iterator itp2 = recoverMapInv.find(v2);
      if(itp1 != recoverMapInv.end() && itp2 != recoverMapInv.end()){
        BDS_Point *pp1 = itp1->second;
        BDS_Point *pp2 = itp2->second;
        if((pp1->iD == p1 && pp2->iD == p2) || (pp1->iD == p2 && pp2->iD == p1)){
          double t1;
          double lc1 = -1;
          if(v1->onWhat() == g1) t1 = bb.low();
          else if(v1->onWhat() == g2) t1 = bb.high();
          else {
            MEdgeVertex *ev1 = (MEdgeVertex*)v1;
            lc1 = ev1->getLc();
            v1->getParameter(0, t1);
          }
          double t2;
          double lc2 = -1;
          if(v2->onWhat() == g1) t2 = bb.low();
          else if(v2->onWhat() == g2) t2 = bb.high();
          else {
            MEdgeVertex *ev2 = (MEdgeVertex*)v2;
            lc2 = ev2->getLc();
            v2->getParameter(0, t2);
          }

          // periodic
          if(v1->onWhat() == g1 && v1->onWhat() == g2)
            t1 = fabs(t2-bb.low()) < fabs(t2-bb.high()) ? bb.low() : bb.high();
          if(v2->onWhat() == g1 && v2->onWhat() == g2)
            t2 = fabs(t1-bb.low()) < fabs(t1-bb.high()) ? bb.low() : bb.high();

          if(lc1 == -1)
            lc1 = BGM_MeshSize(v1->onWhat(), 0, 0, v1->x(), v1->y(), v1->z());
          if(lc2 == -1)
            lc2 = BGM_MeshSize(v2->onWhat(), 0, 0, v2->x(), v2->y(), v2->z());
          // should be better, i.e. equidistant
          double t = 0.5 * (t2 + t1);
          double lc = 0.5 * (lc1 + lc2);
          GPoint V = itr->ge->point(t);
          MEdgeVertex * newv = new MEdgeVertex(V.x(), V.y(), V.z(), itr->ge, t, lc);
          newLines.push_back(new MLine(v1, newv));
          newLines.push_back(new MLine(newv, v2));
          delete itr->ge->lines[i];
        }
        else{
          newLines.push_back(itr->ge->lines[i]);
        }
      }
      else {
        newLines.push_back(itr->ge->lines[i]);
      }
    }

    itr->ge->lines = newLines;
    itr->ge->mesh_vertices.clear();
    N = itr->ge->lines.size();
    for(int i = 1; i < N; i++){
      itr->ge->mesh_vertices.push_back(itr->ge->lines[i]->getVertex(0));
    }
  }
}

static bool algoDelaunay2D(GFace *gf)
{
  // FIXME
  //  if(!noSeam(gf))
  //    return false;

  if(gf->getMeshingAlgo() == ALGO_2D_DELAUNAY ||
     gf->getMeshingAlgo() == ALGO_2D_BAMG ||
     gf->getMeshingAlgo() == ALGO_2D_FRONTAL ||
     gf->getMeshingAlgo() == ALGO_2D_FRONTAL_QUAD ||
     gf->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS ||
     gf->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS_CSTR ||
     gf->getMeshingAlgo() == ALGO_2D_BAMG)
    return true;

  if(gf->getMeshingAlgo() == ALGO_2D_AUTO && gf->geomType() == GEntity::Plane)
    return true;

  return false;
}

static bool recoverEdge(BDS_Mesh *m, GEdge *ge,
                        std::map<MVertex*, BDS_Point*> &recoverMapInv,
                        std::set<EdgeToRecover> *e2r,
                        std::set<EdgeToRecover> *notRecovered, int pass)
{
  BDS_GeomEntity *g = 0;
  if(pass == 2){
    m->add_geom(ge->tag(), 1);
    g = m->get_geom(ge->tag(), 1);
  }

  bool _fatallyFailed;

  for(unsigned int i = 0; i < ge->lines.size(); i++){
    MVertex *vstart = ge->lines[i]->getVertex(0);
    MVertex *vend = ge->lines[i]->getVertex(1);
    std::map<MVertex*, BDS_Point*>::iterator itpstart = recoverMapInv.find(vstart);
    std::map<MVertex*, BDS_Point*>::iterator itpend = recoverMapInv.find(vend);
    if(itpstart != recoverMapInv.end() && itpend != recoverMapInv.end()){
      BDS_Point *pstart = itpstart->second;
      BDS_Point *pend = itpend->second;
      if(pass == 1)
        e2r->insert(EdgeToRecover(pstart->iD, pend->iD, ge));
      else{
        BDS_Edge *e = m->recover_edge(pstart->iD, pend->iD, _fatallyFailed, e2r, notRecovered);
        if(e) e->g = g;
        else {
          if (_fatallyFailed){
            Msg::Error("Unable to recover the edge %d (%d/%d) on GEdge %d (on GFace %d)",
                       ge->lines[i]->getNum(),i+1,ge->lines.size(),ge->tag(),ge->faces().back()->tag());
	    outputScalarField(m->triangles, "wrongmesh.pos", 0);
	    outputScalarField(m->triangles,"wrongparam.pos",1);
	  }
          return !_fatallyFailed;
        }
      }
    }
  }

  if(pass == 2 && ge->getBeginVertex()){
    MVertex *vstart = *(ge->getBeginVertex()->mesh_vertices.begin());
    MVertex *vend = *(ge->getEndVertex()->mesh_vertices.begin());
    std::map<MVertex*, BDS_Point*>::iterator itpstart = recoverMapInv.find(vstart);
    std::map<MVertex*, BDS_Point*>::iterator itpend = recoverMapInv.find(vend);
    if(itpstart != recoverMapInv.end() && itpend != recoverMapInv.end()){
      BDS_Point *pstart = itpstart->second;
      BDS_Point *pend = itpend->second;
      if(!pstart->g){
        m->add_geom(pstart->iD, 0);
        BDS_GeomEntity *g0 = m->get_geom(pstart->iD, 0);
        pstart->g = g0;
      }
      if(!pend->g){
        m->add_geom(pend->iD, 0);
        BDS_GeomEntity *g0 = m->get_geom(pend->iD, 0);
        pend->g = g0;
      }
    }
  }

  return true;
}

void BDS2GMSH(BDS_Mesh *m, GFace *gf,
              std::map<BDS_Point*, MVertex*, PointLessThan> &recoverMap)
{
  {
    std::set<BDS_Point*,PointLessThan>::iterator itp = m->points.begin();
    while (itp != m->points.end()){
      BDS_Point *p = *itp;
      if(recoverMap.find(p) == recoverMap.end()){
        MVertex *v = new MFaceVertex
          (p->X, p->Y, p->Z, gf, m->scalingU * p->u, m->scalingV * p->v);
        recoverMap[p] = v;
        gf->mesh_vertices.push_back(v);
      }
      ++itp;
    }
  }
  {
    std::list<BDS_Face*>::iterator itt = m->triangles.begin();
    while (itt != m->triangles.end()){
      BDS_Face *t = *itt;
      if(!t->deleted){
        BDS_Point *n[4];
        t->getNodes(n);
        MVertex *v1 = recoverMap[n[0]];
        MVertex *v2 = recoverMap[n[1]];
        MVertex *v3 = recoverMap[n[2]];
        if(!n[3]){
          // when a singular point is present, degenerated triangles
          // may be created, for example on a sphere that contains one
          // pole
          if(v1 != v2 && v1 != v3 && v2 != v3)
            gf->triangles.push_back(new MTriangle(v1, v2, v3));
        }
        else{
          MVertex *v4 = recoverMap[n[3]];
          gf->quadrangles.push_back(new MQuadrangle(v1, v2, v3, v4));
        }
      }
      ++itt;
    }
  }
}

static void addOrRemove(MVertex *v1, MVertex *v2, std::set<MEdge,Less_Edge> & bedges, std::set<MEdge,Less_Edge> &removed)
{
  MEdge e(v1,v2);
  if (removed.find(e) != removed.end())return;
  std::set<MEdge,Less_Edge>::iterator it = bedges.find(e);
  if (it == bedges.end())bedges.insert(e);
  else {
    bedges.erase(it);
    removed.insert(e);
  }
}

static void modifyInitialMeshForTakingIntoAccountBoundaryLayers(GFace *gf)
{
  if (!buildAdditionalPoints2D (gf))return;
  BoundaryLayerColumns* _columns = gf->getColumns();

  std::set<MEdge,Less_Edge> bedges;
  std::set<MEdge,Less_Edge> removed;

  std::vector<MQuadrangle*> blQuads;
  std::vector<MTriangle*> blTris;
  std::list<GEdge*> edges = gf->edges();
  std::list<GEdge*> embedded_edges = gf->embeddedEdges();
  edges.insert(edges.begin(), embedded_edges.begin(),embedded_edges.end());
  std::list<GEdge*>::iterator ite = edges.begin();
  FILE *ff2 = Fopen ("tato.pos","w");
  if(ff2) fprintf(ff2,"View \" \"{\n");
  std::set<MVertex*> verts;

  std::vector<MLine*> _lines;

  while(ite != edges.end()){
    for(unsigned int i = 0; i< (*ite)->lines.size(); i++){
      _lines.push_back((*ite)->lines[i]);
      MVertex *v1 = (*ite)->lines[i]->getVertex(0);
      MVertex *v2 = (*ite)->lines[i]->getVertex(1);
      MEdge dv(v1,v2);
      addOrRemove(v1,v2,bedges, removed);
      for (unsigned int SIDE = 0 ; SIDE < _columns->_normals.count(dv); SIDE ++){
        std::vector<MElement*> myCol;
        edgeColumn ec =  _columns->getColumns(v1, v2, SIDE);
        const BoundaryLayerData & c1 = ec._c1;
        const BoundaryLayerData & c2 = ec._c2;
        int N = std::min(c1._column.size(),c2._column.size());
        for (int l=0;l < N ;++l){
          MVertex *v11,*v12,*v21,*v22;
          v21 = c1._column[l];
          v22 = c2._column[l];
          if (l == 0){
            v11 = v1;
            v12 = v2;
          }
          else {
            v11 = c1._column[l-1];
            v12 = c2._column[l-1];
          }
          MQuadrangle *qq = new MQuadrangle(v11,v21,v22,v12);
	  qq->setPartition (l+1);
          myCol.push_back(qq);
          blQuads.push_back(qq);
          if(ff2)
            fprintf(ff2,"SQ (%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d,%d};\n",
                    v11->x(),v11->y(),v11->z(),
                    v12->x(),v12->y(),v12->z(),
                    v22->x(),v22->y(),v22->z(),
                    v21->x(),v21->y(),v21->z(),l+1,l+1,l+1,l+1);
        }
        // int M = std::max(c1._column.size(),c2._column.size());
        for (unsigned int l=0;l<myCol.size();l++)_columns->_toFirst[myCol[l]] = myCol[0];
        _columns->_elemColumns[myCol[0]] = myCol;
      }
   }
    ++ite;
  }

  for (BoundaryLayerColumns::iterf itf = _columns->beginf();
       itf != _columns->endf() ; ++itf){
    MVertex *v = itf->first;
    int nbCol = _columns->getNbColumns(v);

    for (int i=0;i<nbCol-1;i++){
      const BoundaryLayerData & c1 = _columns->getColumn(v,i);
      const BoundaryLayerData & c2 = _columns->getColumn(v,i+1);
      int N = std::min(c1._column.size(),c2._column.size());
      //      printf("%d %d\n",c1._column.size(),c2._column.size());
      std::vector<MElement*> myCol;
      for (int l=0;l < N ;++l){
        MVertex *v11,*v12,*v21,*v22;
        v21 = c1._column[l];
        v22 = c2._column[l];
        if (l == 0){
          v11 = v;
          v12 = v;
          }
        else {
          v11 = c1._column[l-1];
          v12 = c2._column[l-1];
        }
        if (v11 != v12){
          MQuadrangle *qq = new MQuadrangle(v11,v12,v22,v21);
	  qq->setPartition (l+1);
          myCol.push_back(qq);
          blQuads.push_back(qq);
          if(ff2)
            fprintf(ff2,"SQ (%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d,%d};\n",
                    v11->x(),v11->y(),v11->z(),
                    v12->x(),v12->y(),v12->z(),
                    v22->x(),v22->y(),v22->z(),
                    v21->x(),v21->y(),v21->z(),l+1,l+1,l+1,l+1);
        }
        else {
          MTriangle *qq = new MTriangle(v,v22,v21);
	  qq->setPartition (l+1);
          myCol.push_back(qq);
          blTris.push_back(qq);
          if(ff2)
            fprintf(ff2,"ST (%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
                    v->x(),v->y(),v->z(),
                    v22->x(),v22->y(),v22->z(),
                    v21->x(),v21->y(),v21->z(),l+1,l+1,l+1);
        }
      }
      for (unsigned int l=0;l<myCol.size();l++)_columns->_toFirst[myCol[l]] = myCol[0];
      _columns->_elemColumns[myCol[0]] = myCol;
    }
  }

  if(ff2){
    fprintf(ff2,"};\n");
    fclose(ff2);
  }

  filterOverlappingElements (_lines, blTris,blQuads,_columns->_elemColumns,_columns->_toFirst);

  for (unsigned int i = 0; i < blQuads.size();i++){
    addOrRemove(blQuads[i]->getVertex(0),blQuads[i]->getVertex(1),bedges, removed);
    addOrRemove(blQuads[i]->getVertex(1),blQuads[i]->getVertex(2),bedges, removed);
    addOrRemove(blQuads[i]->getVertex(2),blQuads[i]->getVertex(3),bedges, removed);
    addOrRemove(blQuads[i]->getVertex(3),blQuads[i]->getVertex(0),bedges, removed);
    for (int j = 0; j < 4; j++)
      if(blQuads[i]->getVertex(j)->onWhat() == gf)verts.insert(blQuads[i]->getVertex(j));
  }
  for (unsigned int i = 0; i < blTris.size(); i++){
    addOrRemove(blTris[i]->getVertex(0),blTris[i]->getVertex(1),bedges, removed);
    addOrRemove(blTris[i]->getVertex(1),blTris[i]->getVertex(2),bedges, removed);
    addOrRemove(blTris[i]->getVertex(2),blTris[i]->getVertex(0),bedges, removed);
    for (int j = 0; j < 3; j++)
      if(blTris[i]->getVertex(j)->onWhat() == gf)verts.insert(blTris[i]->getVertex(j));
  }

  discreteEdge ne (gf->model(), 444444,0,
                   (*edges.begin())->getEndVertex());
  std::list<GEdge*> hop;
  std::set<MEdge,Less_Edge>::iterator it =  bedges.begin();

  FILE *ff = Fopen ("toto.pos","w");
  if(ff) fprintf(ff,"View \" \"{\n");
  for (; it != bedges.end(); ++it){
    ne.lines.push_back(new MLine (it->getVertex(0),it->getVertex(1)));
    if(ff)
      fprintf(ff,"SL (%g,%g,%g,%g,%g,%g){1,1};\n",
              it->getVertex(0)->x(),it->getVertex(0)->y(),it->getVertex(0)->z(),
              it->getVertex(1)->x(),it->getVertex(1)->y(),it->getVertex(1)->z());
  }
  if(ff){
    fprintf(ff,"};\n");
    fclose(ff);
  }
  hop.push_back(&ne);

  deMeshGFace kil_;
  kil_(gf);
  meshGenerator(gf, 0, 0, true , false, &hop);

  gf->quadrangles = blQuads;
  gf->triangles.insert(gf->triangles.begin(),blTris.begin(),blTris.end());
  gf->mesh_vertices.insert(gf->mesh_vertices.begin(),verts.begin(),verts.end());
}

static bool inside_domain(MElementOctree* octree,double x,double y)
{
  MElement* element;
  element = (MElement*)octree->find(x, y, 0.0, 2, true);
  if(element != NULL) return 1;
  else return 0;
}

static bool translate(GFace* gf,MElementOctree* octree,MVertex* vertex,
                      SPoint2 corr,SVector3& v1,SVector3& v2)
{
  bool ok;
  double k;
  double size;
  double angle;
  double delta_x;
  double delta_y;
  double x,y;
  double x1,y1;
  double x2,y2;
  SPoint2 point;
  GPoint gp1;
  GPoint gp2;

  ok = true;
  k = 0.0001;
  reparamMeshVertexOnFace(vertex,gf,point);
  x = point.x();
  y = point.y();
  size = backgroundMesh::current()->operator()(x,y,0.0)/**get_ratio(gf,corr)*/;
  angle = backgroundMesh::current()->getAngle(x,y,0.0);

  delta_x = k*size*cos(angle);
  delta_y = k*size*sin(angle);

  x1 = x + delta_x;
  y1 = y + delta_y;
  x2 = x + delta_y;
  y2 = y - delta_x;

  if(!inside_domain(octree,x1,y1)){
    x1 = x - delta_x;
    y1 = y - delta_y;
    if(!inside_domain(octree,x1,y1)) ok = false;
  }
  if(!inside_domain(octree,x2,y2)){
    x2 = x - delta_y;
    y2 = y + delta_x;
    if(!inside_domain(octree,x2,y2)) ok = false;
  }

  ok = true; //?

  if(ok){
    gp1 = gf->point(x1,y1);
    gp2 = gf->point(x2,y2);
    v1 = SVector3(gp1.x()-vertex->x(),gp1.y()-vertex->y(),gp1.z()-vertex->z());
    v2 = SVector3(gp2.x()-vertex->x(),gp2.y()-vertex->y(),gp2.z()-vertex->z());
  }
  else{
    v1 = SVector3(1.0,0.0,0.0);
    v2 = SVector3(0.0,1.0,0.0);
  }
  return ok;
}

static bool improved_translate(GFace* gf,MVertex* vertex,SVector3& v1,SVector3& v2)
{
  double x,y;
  double angle;
  SPoint2 point;
  SVector3 s1,s2;
  SVector3 normal;
  SVector3 basis_u,basis_v;
  Pair<SVector3,SVector3> derivatives;

  reparamMeshVertexOnFace(vertex,gf,point);
  x = point.x();
  y = point.y();

  angle = backgroundMesh::current()->getAngle(x,y,0.0);
  derivatives = gf->firstDer(point);

  s1 = derivatives.first();
  s2 = derivatives.second();
  normal = crossprod(s1,s2);

  basis_u = s1;
  basis_u.normalize();
  basis_v = crossprod(normal,basis_u);
  basis_v.normalize();

  v1 = basis_u*cos(angle) + basis_v*sin(angle);
  v2 = crossprod(v1,normal);
  v2.normalize();

  return 1;
}

static void directions_storage(GFace* gf)
{
  bool ok;
  unsigned int i;
  int j;
  MVertex* vertex;
  MElement* element;
  SPoint2 point;
  SVector3 v1;
  SVector3 v2;
  MElementOctree* octree;
  std::set<MVertex*> vertices;
  std::set<MVertex*>::iterator it;

  vertices.clear();

  for(i=0;i<gf->getNumMeshElements();i++){
    element = gf->getMeshElement(i);
    for(j=0;j<element->getNumVertices();j++){
      vertex = element->getVertex(j);
      vertices.insert(vertex);
    }
  }

  backgroundMesh::set(gf);
  octree = backgroundMesh::current()->get_octree();

  gf->storage1.clear();
  gf->storage2.clear();
  gf->storage3.clear();
  gf->storage4.clear();

  for(it=vertices.begin();it!=vertices.end();it++){
    ok = 0;

    if(!gf->getCompound()){
      if(gf->geomType()==GEntity::CompoundSurface){
        ok = translate(gf,octree,*it,SPoint2(0.0,0.0),v1,v2);
      }
      else{
        ok = improved_translate(gf,*it,v1,v2);
      }
    }

    if(ok){
      gf->storage1.push_back(SPoint3((*it)->x(),(*it)->y(),(*it)->z()));
      gf->storage2.push_back(v1);
      gf->storage3.push_back(v2);
      reparamMeshVertexOnFace(*it,gf,point);
      gf->storage4.push_back(backgroundMesh::current()->operator()(point.x(),point.y(),0.0));
    }
  }

  backgroundMesh::unset();
}

// Builds An initial triangular mesh that respects the boundaries of
// the domain, including embedded points and surfaces
bool meshGenerator(GFace *gf, int RECUR_ITER,
                   bool repairSelfIntersecting1dMesh,
                   bool onlyInitialMesh,
                   bool debug,
                   std::list<GEdge*> *replacement_edges)
{
  //onlyInitialMesh=true;
  BDS_GeomEntity CLASS_F(1, 2);
  BDS_GeomEntity CLASS_EXTERIOR(1, 3);
  std::map<BDS_Point*, MVertex*,PointLessThan> recoverMap;
  std::map<MVertex*, BDS_Point*> recoverMapInv;
  std::list<GEdge*> edges = replacement_edges ? *replacement_edges : gf->edges();
  std::list<int> dir = gf->edgeOrientations();
  std::vector<MEdge> medgesToRecover;

  // replace edges by their compounds
  // if necessary split compound and remesh parts
  bool isMeshed = false;
  if(gf->geomType() == GEntity::CompoundSurface  && !onlyInitialMesh){
    isMeshed = checkMeshCompound((GFaceCompound*) gf, edges);
    if (isMeshed) return true;
  }

  // build a set with all points of the boundaries
  std::set<MVertex*, MVertexLessThanNum> all_vertices, boundary;
  std::list<GEdge*>::iterator ite = edges.begin();
  while(ite != edges.end()){
    if((*ite)->isSeam(gf)) return false;
    if(!(*ite)->isMeshDegenerated()){
      for(unsigned int i = 0; i< (*ite)->lines.size(); i++)
        medgesToRecover.push_back(MEdge((*ite)->lines[i]->getVertex(0),
                                       (*ite)->lines[i]->getVertex(1)));
      for(unsigned int i = 0; i< (*ite)->lines.size(); i++){
        MVertex *v1 = (*ite)->lines[i]->getVertex(0);
        MVertex *v2 = (*ite)->lines[i]->getVertex(1);
        all_vertices.insert(v1);
        all_vertices.insert(v2);
        if(boundary.find(v1) == boundary.end())
          boundary.insert(v1);
        else
          boundary.erase(v1);
        if(boundary.find(v2) == boundary.end())
          boundary.insert(v2);
        else
          boundary.erase(v2);
      }
    }
    else
      Msg::Debug("Degenerated mesh on edge %d", (*ite)->tag());
    ++ite;
  }


  if(boundary.size()){
    Msg::Error("The 1D mesh seems not to be forming a closed loop");
    gf->meshStatistics.status = GFace::FAILED;
    return false;
  }

  std::list<GEdge*> emb_edges = gf->embeddedEdges();
  ite = emb_edges.begin();
  while(ite != emb_edges.end()){
    for(unsigned int i = 0; i< (*ite)->lines.size(); i++)
      medgesToRecover.push_back(MEdge((*ite)->lines[i]->getVertex(0),
                                     (*ite)->lines[i]->getVertex(1)));
    if(!(*ite)->isMeshDegenerated()){
      all_vertices.insert((*ite)->mesh_vertices.begin(),
                          (*ite)->mesh_vertices.end() );
      all_vertices.insert((*ite)->getBeginVertex()->mesh_vertices.begin(),
                          (*ite)->getBeginVertex()->mesh_vertices.end());
      all_vertices.insert((*ite)->getEndVertex()->mesh_vertices.begin(),
                          (*ite)->getEndVertex()->mesh_vertices.end());
    }
    ++ite;
  }

  // add embedded vertices
  std::list<GVertex*> emb_vertx = gf->embeddedVertices();
  std::list<GVertex*>::iterator itvx = emb_vertx.begin();
  while(itvx != emb_vertx.end()){
    all_vertices.insert((*itvx)->mesh_vertices.begin(),
                        (*itvx)->mesh_vertices.end());
    ++itvx;
  }

  // add additional vertices
  all_vertices.insert(gf->additionalVertices.begin(),
                      gf->additionalVertices.end());


  if(all_vertices.size() < 3){
    Msg::Warning("Mesh Generation of Model Face %d Skipped: "
                 "Only %d mesh vertices on the contours",
                 gf->tag(), all_vertices.size());
    gf->meshStatistics.status = GFace::DONE;
    return true;
  }
  if(all_vertices.size() == 3){
    MVertex *vv[3];
    int i = 0;
    for(std::set<MVertex*, MVertexLessThanNum>::iterator it = all_vertices.begin();
        it != all_vertices.end(); it++){
      vv[i++] = *it;
    }
    gf->triangles.push_back(new MTriangle(vv[0], vv[1], vv[2]));
    gf->meshStatistics.status = GFace::DONE;
    return true;
  }

  // Buid a BDS_Mesh structure that is convenient for doing the actual
  // meshing procedure
  BDS_Mesh *m = new BDS_Mesh;
  m->scalingU = 1;
  m->scalingV = 1;

  std::vector<BDS_Point*> points(all_vertices.size());
  SBoundingBox3d bbox;
  int count = 0;
  for(std::set<MVertex*, MVertexLessThanNum>::iterator it = all_vertices.begin();
      it != all_vertices.end(); it++){
    MVertex *here = *it;
    GEntity *ge = here->onWhat();
    SPoint2 param;
    reparamMeshVertexOnFace(here, gf, param);
    BDS_Point *pp = m->add_point(count, param[0], param[1], gf);
    m->add_geom(ge->tag(), ge->dim());
    BDS_GeomEntity *g = m->get_geom(ge->tag(), ge->dim());
    pp->g = g;
    recoverMap[pp] = here;
    recoverMapInv[here] = pp;
    points[count] = pp;
    bbox += SPoint3(param[0], param[1], 0);
    count++;
  }

  bbox.makeCube();

  // use a divide & conquer type algorithm to create a triangulation.
  // We add to the triangulation a box with 4 points that encloses the
  // domain.
#ifdef OLD_CODE_DELAUNAY
  {
    // compute the bounding box in parametric space
    SVector3 dd(bbox.max(), bbox.min());
    double LC2D = norm(dd);
    DocRecord doc(points.size() + 4);
    for(unsigned int i = 0; i < points.size(); i++){
      double XX = CTX::instance()->mesh.randFactor * LC2D * (double)rand() /
        (double)RAND_MAX;
      double YY = CTX::instance()->mesh.randFactor * LC2D * (double)rand() /
        (double)RAND_MAX;
      //      printf("%22.15E %22.15E \n",XX,YY);
      doc.points[i].where.h = points[i]->u + XX;
      doc.points[i].where.v = points[i]->v + YY;
      doc.points[i].data = points[i];
      doc.points[i].adjacent = NULL;

    }

    // increase the size of the bounding box
    bbox *= 2.5;

    // add 4 points than encloses the domain (use negative number to
    // distinguish those fake vertices)
    double bb[4][2] = {{bbox.min().x(), bbox.min().y()},
                       {bbox.min().x(), bbox.max().y()},
                       {bbox.max().x(), bbox.min().y()},
                       {bbox.max().x(), bbox.max().y()}};
    for(int ip = 0; ip < 4; ip++){
      BDS_Point *pp = m->add_point(-ip - 1, bb[ip][0], bb[ip][1], gf);
      m->add_geom(gf->tag(), 2);
      BDS_GeomEntity *g = m->get_geom(gf->tag(), 2);
      pp->g = g;
      doc.points[points.size() + ip].where.h = bb[ip][0];
      doc.points[points.size() + ip].where.v = bb[ip][1];
      doc.points[points.size() + ip].adjacent = 0;
      doc.points[points.size() + ip].data = pp;
    }



    // Use "fast" inhouse recursive algo to generate the triangulation.
    // At this stage the triangulation is not what we need
    //   -) It does not necessary recover the boundaries
      //   -) It contains triangles outside the domain (the first edge
      //      loop is the outer one)
    Msg::Debug("Meshing of the convex hull (%d points)", points.size());
    try{
      doc.MakeMeshWithPoints();
    }
    catch(const char *err){
      Msg::Error("%s", err);
    }
    Msg::Debug("Meshing of the convex hull (%d points) done", points.size());


    for(int i = 0; i < doc.numTriangles; i++) {
      int a = doc.triangles[i].a;
      int b = doc.triangles[i].b;
      int c = doc.triangles[i].c;
      int n = doc.numPoints;
      if(a < 0 || a >= n || b < 0 || b >= n || c < 0 || c >= n){
        Msg::Warning("Skipping bad triangle %d", i);
        continue;
      }
      BDS_Point *p1 = (BDS_Point*)doc.points[doc.triangles[i].a].data;
      BDS_Point *p2 = (BDS_Point*)doc.points[doc.triangles[i].b].data;
      BDS_Point *p3 = (BDS_Point*)doc.points[doc.triangles[i].c].data;
      m->add_triangle(p1->iD, p2->iD, p3->iD);
    }
  }
#else
  {
    std::vector<MVertex*> v;
    std::vector<MTriangle*> result;
    v.insert(v.end(), all_vertices.begin(), all_vertices.end());

    std::map<MVertex*,SPoint3> pos;
    for(unsigned int i = 0; i < v.size(); i++) {
      MVertex *v0 = v[i];
      BDS_Point *p0  = recoverMapInv[v0];
      pos[v0] = SPoint3(v0->x(),v0->y(),v0->z());
      v0->setXYZ(p0->u,p0->v,0.0);
    }
    delaunayMeshIn2D(v, result, 0);
    //    delaunayMeshIn2D(v, result, 0, & medgesToRecover);

    for(unsigned int i = 0; i < v.size()-4; i++) {
      MVertex *v0 = v[i];
      SPoint3 pp = pos[v0];
      v0->setXYZ(pp.x(),pp.y(),pp.z());
    }

    // add the four corners
    for(int ip = 0; ip < 4; ip++){
      MVertex *vv = v[v.size()-ip-1];
      BDS_Point *pp = m->add_point(-ip - 1, vv->x(),vv->y(), gf);
      m->add_geom(gf->tag(), 2);
      recoverMapInv[vv] = pp;
      BDS_GeomEntity *g = m->get_geom(gf->tag(), 2);
      pp->g = g;
    }
    // add the triangles
    for(unsigned int i = 0; i < result.size(); i++) {
      MVertex *v0 = result[i]->getVertex(0);
      MVertex *v1 = result[i]->getVertex(1);
      MVertex *v2 = result[i]->getVertex(2);
      BDS_Point *p0  = recoverMapInv[v0];
      BDS_Point *p1  = recoverMapInv[v1];
      BDS_Point *p2  = recoverMapInv[v2];
      m->add_triangle(p0->iD, p1->iD, p2->iD);
    }
  }
#endif

  if(debug && RECUR_ITER == 0){
    char name[245];
    sprintf(name, "surface%d-initial-real.pos", gf->tag());
    outputScalarField(m->triangles, name, 0);
    sprintf(name, "surface%d-initial-param.pos", gf->tag());
    outputScalarField(m->triangles, name, 1);
  }

  // Recover the boundary edges and compute characteristic lenghts
  // using mesh edge spacing. If two of these edges intersect, then
  // the 1D mesh have to be densified
  Msg::Debug("Recovering %d model Edges", edges.size());
  std::set<EdgeToRecover> edgesToRecover;
  std::set<EdgeToRecover> edgesNotRecovered;
  ite = edges.begin();
  while(ite != edges.end()){
    if(!(*ite)->isMeshDegenerated())
      recoverEdge(m, *ite, recoverMapInv, &edgesToRecover, &edgesNotRecovered, 1);
    ++ite;
  }
  ite = emb_edges.begin();
  while(ite != emb_edges.end()){
    if(!(*ite)->isMeshDegenerated())
      recoverEdge(m, *ite, recoverMapInv, &edgesToRecover, &edgesNotRecovered, 1);
    ++ite;
  }


  // effectively recover the medge
  ite = edges.begin();
  while(ite != edges.end()){
    if(!(*ite)->isMeshDegenerated()){
      if (!recoverEdge(m, *ite, recoverMapInv, &edgesToRecover, &edgesNotRecovered, 2)){
        delete m;
        gf->meshStatistics.status = GFace::FAILED;
        return false;
      }
    }
    ++ite;
  }

  Msg::Debug("Recovering %d mesh Edges (%d not recovered)", edgesToRecover.size(),
             edgesNotRecovered.size());

  if(edgesNotRecovered.size()){
    std::ostringstream sstream;
    for(std::set<EdgeToRecover>::iterator itr = edgesNotRecovered.begin();
        itr != edgesNotRecovered.end(); ++itr)
      sstream << " " << itr->ge->tag();
    Msg::Warning(":-( There are %d intersections in the 1D mesh (curves%s)",
                 edgesNotRecovered.size(), sstream.str().c_str());
    if (repairSelfIntersecting1dMesh)
      Msg::Warning("8-| Gmsh splits those edges and tries again");

    if(debug){
      char name[245];
      sprintf(name, "surface%d-not_yet_recovered-real-%d.msh", gf->tag(),
              RECUR_ITER);
      gf->model()->writeMSH(name);
    }

    std::list<GFace *> facesToRemesh;
    if(repairSelfIntersecting1dMesh)
      remeshUnrecoveredEdges(recoverMapInv, edgesNotRecovered, facesToRemesh);
    else{
      std::set<EdgeToRecover>::iterator itr = edgesNotRecovered.begin();
      //int *_error = new int[3 * edgesNotRecovered.size()];
      int I = 0;
      for(; itr != edgesNotRecovered.end(); ++itr){
        int p1 = itr->p1;
        int p2 = itr->p2;
        int tag = itr->ge->tag();
        Msg::Error("Edge not recovered: %d %d %d", p1, p2, tag);
        //_error[3 * I + 0] = p1;
        //_error[3 * I + 1] = p2;
        //_error[3 * I + 2] = tag;
        I++;
      }
      //throw _error;
    }

    // delete the mesh
    delete m;
    if(RECUR_ITER < 10 && facesToRemesh.size() == 0)
      return meshGenerator
        (gf, RECUR_ITER + 1, repairSelfIntersecting1dMesh, onlyInitialMesh,
         debug, replacement_edges);
    return false;
  }

  if(RECUR_ITER > 0)
    Msg::Warning(":-) Gmsh was able to recover all edges after %d iterations",
                 RECUR_ITER);

  Msg::Debug("Boundary Edges recovered for surface %d", gf->tag());

  // look for a triangle that has a negative node and recursively
  // tag all exterior triangles
  {
    std::list<BDS_Face*>::iterator itt = m->triangles.begin();
    while (itt != m->triangles.end()){
      (*itt)->g = 0;
      ++itt;
    }
    itt = m->triangles.begin();
    while (itt != m->triangles.end()){
      BDS_Face *t = *itt;
      BDS_Point *n[4];
      t->getNodes(n);
      if (n[0]->iD < 0 || n[1]->iD < 0 ||
          n[2]->iD < 0 ) {
        recur_tag(t, &CLASS_EXTERIOR);
        break;
      }
      ++itt;
    }
  }

  // now find an edge that has belongs to one of the exterior
  // triangles
  {
    std::list<BDS_Edge*>::iterator ite = m->edges.begin();
    while (ite != m->edges.end()){
      BDS_Edge *e = *ite;
      if(e->g  && e->numfaces() == 2){
        if(e->faces(0)->g == &CLASS_EXTERIOR){
          recur_tag(e->faces(1), &CLASS_F);
          break;
        }
        else if(e->faces(1)->g == &CLASS_EXTERIOR){
          recur_tag(e->faces(0), &CLASS_F);
          break;
        }
      }
      ++ite;
    }
    std::list<BDS_Face*>::iterator itt = m->triangles.begin();
    while (itt != m->triangles.end()){
      if ((*itt)->g == &CLASS_EXTERIOR) (*itt)->g = 0;
      ++itt;
    }
  }

  {
    std::list<BDS_Edge*>::iterator ite = m->edges.begin();
    while (ite != m->edges.end()){
      BDS_Edge *e = *ite;
      if(e->g  && e->numfaces() == 2){
        BDS_Point *oface[2];
        e->oppositeof(oface);
        if(oface[0]->iD < 0){
          recur_tag(e->faces(1), &CLASS_F);
          break;
        }
        else if(oface[1]->iD < 0){
          recur_tag(e->faces(0), &CLASS_F);
          break;
        }
      }
      ++ite;
    }
  }

  ite = emb_edges.begin();
  while(ite != emb_edges.end()){
    if(!(*ite)->isMeshDegenerated())
      recoverEdge(m, *ite, recoverMapInv, &edgesToRecover, &edgesNotRecovered, 2);
    ++ite;
  }

  // compute characteristic lengths at vertices
  if (!onlyInitialMesh){
      Msg::Debug("Computing mesh size field at mesh vertices %d",
                 edgesToRecover.size());
      std::set<BDS_Point*, PointLessThan>::iterator it = m->points.begin();
      for(; it != m->points.end();++it){
        //      for(int i = 0; i < doc.numPoints; i++){
        //        BDS_Point *pp = (BDS_Point*)doc.points[i].data;
        BDS_Point *pp = *it;
        std::map<BDS_Point*, MVertex*,PointLessThan>::iterator itv = recoverMap.find(pp);
        if(itv != recoverMap.end()){
          MVertex *here = itv->second;
          GEntity *ge = here->onWhat();
          if(ge->dim() == 0){
            pp->lcBGM() = BGM_MeshSize(ge, 0, 0, here->x(), here->y(), here->z());
          }
          else if(ge->dim() == 1){
            double u;
            here->getParameter(0, u);
            pp->lcBGM() = BGM_MeshSize(ge, u, 0, here->x(), here->y(), here->z());
          }
          else
            pp->lcBGM() = MAX_LC;
          pp->lc() = pp->lcBGM();
        }
      }
  }

  // delete useless stuff
  std::list<BDS_Face*>::iterator itt = m->triangles.begin();
  while (itt != m->triangles.end()){
    BDS_Face *t = *itt;
    if(!t->g) m->del_face(t);
    ++itt;
  }
  m->cleanup();

  {
    std::list<BDS_Edge*>::iterator ite = m->edges.begin();
    while (ite != m->edges.end()){
      BDS_Edge *e = *ite;
      if(e->numfaces() == 0)
        m->del_edge(e);
      else{
        if(!e->g)
          e->g = &CLASS_F;
        if(!e->p1->g || e->p1->g->classif_degree > e->g->classif_degree)
          e->p1->g = e->g;
        if(!e->p2->g || e->p2->g->classif_degree > e->g->classif_degree)
          e->p2->g = e->g;
      }
      ++ite;
    }
  }
  m->cleanup();
  m->del_point(m->find_point(-1));
  m->del_point(m->find_point(-2));
  m->del_point(m->find_point(-3));
  m->del_point(m->find_point(-4));

  if(debug){
    char name[245];
    sprintf(name, "surface%d-recovered-real.pos", gf->tag());
    outputScalarField(m->triangles, name, 0);
    sprintf(name, "surface%d-recovered-param.pos", gf->tag());
    outputScalarField(m->triangles, name, 1);
  }

  if(1){
    std::list<BDS_Face*>::iterator itt = m->triangles.begin();
    while (itt != m->triangles.end()){
      BDS_Face *t = *itt;
      if(!t->deleted){
        BDS_Point *n[4];
        t->getNodes(n);
        MVertex *v1 = recoverMap[n[0]];
        MVertex *v2 = recoverMap[n[1]];
        MVertex *v3 = recoverMap[n[2]];
        if(!n[3]){
          if(v1 != v2 && v1 != v3 && v2 != v3)
            gf->triangles.push_back(new MTriangle(v1, v2, v3));
        }
        else{
          MVertex *v4 = recoverMap[n[3]];
          gf->quadrangles.push_back(new MQuadrangle(v1, v2, v3, v4));
        }
      }
      ++itt;
    }
  }

  {
    int nb_swap;
    Msg::Debug("Delaunizing the initial mesh");
    delaunayizeBDS(gf, *m, nb_swap);
  }
  //gf->triangles.clear();
  //gf->quadrangles.clear();

  // only delete the mesh data stored in the base GFace class (calling
  // gf->deleteMesh() would also destroy e.g. the data in a compound face, which
  // we should not do)
  gf->GFace::deleteMesh();

  Msg::Debug("Starting to add internal points");
  // start mesh generation
  if(!algoDelaunay2D(gf) && !onlyInitialMesh){
    // if(CTX::instance()->mesh.recombineAll || gf->meshAttributes.recombine || 1) {
    //   backgroundMesh::unset();
    //   buildBackGroundMesh (gf);
    // }
    refineMeshBDS(gf, *m, CTX::instance()->mesh.refineSteps, true,
                  &recoverMapInv);
    optimizeMeshBDS(gf, *m, 2);
    refineMeshBDS(gf, *m, CTX::instance()->mesh.refineSteps, false,
                &recoverMapInv);
    optimizeMeshBDS(gf, *m, 2);
    // if(CTX::instance()->mesh.recombineAll || gf->meshAttributes.recombine || 1) {
    //   backgroundMesh::unset();
    // }
  }

  /*
  computeMeshSizeFieldAccuracy(gf, *m, gf->meshStatistics.efficiency_index,
                               gf->meshStatistics.longest_edge_length,
                               gf->meshStatistics.smallest_edge_length,
                               gf->meshStatistics.nbEdge,
                               gf->meshStatistics.nbGoodLength);
  */
  //printf("=== Efficiency index is tau=%g\n", gf->meshStatistics.efficiency_index);

  gf->meshStatistics.status = GFace::DONE;

  // fill the small gmsh structures
  BDS2GMSH(m, gf, recoverMap);

  bool infty = false;
  if (gf->getMeshingAlgo() == ALGO_2D_FRONTAL_QUAD ||
      gf->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS ||
      gf->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS_CSTR)
    infty = true;
  if (!onlyInitialMesh) {
    if (infty)
      buildBackGroundMesh (gf);
    // BOUNDARY LAYER
    modifyInitialMeshForTakingIntoAccountBoundaryLayers(gf);
  }

  // the delaunay algo is based directly on internal gmsh structures
  // BDS mesh is passed in order not to recompute local coordinates of
  // vertices
  if(algoDelaunay2D(gf) && !onlyInitialMesh){
    if(gf->getMeshingAlgo() == ALGO_2D_FRONTAL){
      bowyerWatsonFrontal(gf);
    }
    else if(gf->getMeshingAlgo() == ALGO_2D_FRONTAL_QUAD){
      bowyerWatsonFrontalLayers(gf,true);
    }
    else if(gf->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS){
      bowyerWatsonParallelograms(gf);
    }
    else if(gf->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS_CSTR){
      bowyerWatsonParallelogramsConstrained(gf,gf->constr_vertices);
    }
    else if(gf->getMeshingAlgo() == ALGO_2D_DELAUNAY ||
            gf->getMeshingAlgo() == ALGO_2D_AUTO){
      bowyerWatson(gf);
    }
    else {
      bowyerWatson(gf,15000);
      meshGFaceBamg(gf);
    }
    if (!infty || !(CTX::instance()->mesh.recombineAll || gf->meshAttributes.recombine))
      laplaceSmoothing(gf, CTX::instance()->mesh.nbSmoothing, infty);
  }

  if(debug){
    char name[256];
    sprintf(name, "real%d.pos", gf->tag());
    outputScalarField(m->triangles, name, 0, gf);
    sprintf(name, "param%d.pos", gf->tag());
    outputScalarField(m->triangles, name,1);
  }

  delete m;

  if((CTX::instance()->mesh.recombineAll || gf->meshAttributes.recombine) &&
     !CTX::instance()->mesh.optimizeLloyd && !onlyInitialMesh && CTX::instance()->mesh.algoRecombine != 2)
    recombineIntoQuads(gf);

  computeElementShapes(gf, gf->meshStatistics.worst_element_shape,
                       gf->meshStatistics.average_element_shape,
                       gf->meshStatistics.best_element_shape,
                       gf->meshStatistics.nbTriangle,
                       gf->meshStatistics.nbGoodQuality);

  gf->mesh_vertices.insert(gf->mesh_vertices.end(),
                              gf->additionalVertices.begin(),
                              gf->additionalVertices.end());
  gf->additionalVertices.clear();

  if(CTX::instance()->mesh.algo3d==ALGO_3D_RTREE){
    directions_storage(gf);
  }

  return true;
}

// this function buils a list of vertices (BDS) that are consecutive
// in one given edge loop. We take care of periodic surfaces. In the
// case of periodicty, some curves are present 2 times in the wire
// (seams). Those must be meshed separately

static inline double dist2(const SPoint2 &p1, const SPoint2 &p2)
{
  const double dx = p1.x() - p2.x();
  const double dy = p1.y() - p2.y();
  return dx * dx + dy * dy;
}

/*
static void printMesh1d(int iEdge, int seam, std::vector<SPoint2> &m)
{
  printf("Mesh1D for edge %d seam %d\n", iEdge, seam);
  for(unsigned int i = 0; i < m.size(); i++){
    printf("%12.5E %12.5E\n", m[i].x(), m[i].y());
  }
}
*/

static bool buildConsecutiveListOfVertices(GFace *gf, GEdgeLoop &gel,
                                           std::vector<BDS_Point*> &result,
                                           SBoundingBox3d &bbox, BDS_Mesh *m,
                                           std::map<BDS_Point*, MVertex*,PointLessThan> &recoverMap,
                                           int &count, int countTot, double tol,
                                           bool seam_the_first = false)
{
  // for each edge, we build a list of points that are the mapping of
  // the edge points on the face for seams, we build the list for
  // every side for closed loops, we build it on both senses

  std::map<GEntity*, std::vector<SPoint2> > meshes;
  std::map<GEntity*, std::vector<SPoint2> > meshes_seam;

  const int MYDEBUG = false;

  std::map<BDS_Point*, MVertex*,PointLessThan> recoverMapLocal;

  result.clear();
  count = 0;

  GEdgeLoop::iter it = gel.begin();

  if(MYDEBUG)
    printf("face %d with %d edges case %d\n", gf->tag(),
           (int)gf->edges().size(), seam_the_first);

  while (it != gel.end()){
    GEdgeSigned ges = *it ;
    std::vector<SPoint2> mesh1d;
    std::vector<SPoint2> mesh1d_seam;

    bool seam = ges.ge->isSeam(gf);

    //if (seam) printf("face %d has seam %d\n", gf->tag(), ges.ge->tag());

    Range<double> range = ges.ge->parBounds(0);

    MVertex *here = ges.ge->getBeginVertex()->mesh_vertices[0];
    mesh1d.push_back(ges.ge->reparamOnFace(gf, range.low(), 1));
    if(seam) mesh1d_seam.push_back(ges.ge->reparamOnFace(gf, range.low(), -1));
    for(unsigned int i = 0; i < ges.ge->mesh_vertices.size(); i++){
      double u;
      here = ges.ge->mesh_vertices[i];
      here->getParameter(0, u);
      mesh1d.push_back(ges.ge->reparamOnFace(gf, u, 1));
      if(seam) mesh1d_seam.push_back(ges.ge->reparamOnFace(gf, u, -1));
    }
    here = ges.ge->getEndVertex()->mesh_vertices[0];
    mesh1d.push_back(ges.ge->reparamOnFace(gf, range.high(), 1));
    if(seam) mesh1d_seam.push_back(ges.ge->reparamOnFace(gf, range.high(), -1));
    meshes.insert(std::pair<GEntity*,std::vector<SPoint2> >(ges.ge, mesh1d));
    if(seam) meshes_seam.insert(std::pair<GEntity*,std::vector<SPoint2> >
                                (ges.ge, mesh1d_seam));
    // printMesh1d(ges.ge->tag(), seam, mesh1d);
    // if(seam) printMesh1d (ges.ge->tag(), seam, mesh1d_seam);
    it++;
  }

  std::list<GEdgeSigned> unordered;
  unordered.insert(unordered.begin(), gel.begin(), gel.end());

  GEdgeSigned found(0, 0);
  SPoint2 last_coord(0, 0);
  int counter = 0;

  while (unordered.size()){
    if(MYDEBUG)
      printf("unordered.size() = %d\n", (int)unordered.size());
    std::list<GEdgeSigned>::iterator it = unordered.begin();
    std::vector<SPoint2>  coords;

    while (it != unordered.end()){
      std::vector<SPoint2> mesh1d;
      std::vector<SPoint2> mesh1d_seam;
      std::vector<SPoint2> mesh1d_reversed;
      std::vector<SPoint2> mesh1d_seam_reversed;
      GEdge *ge = (*it).ge;
      bool seam = ge->isSeam(gf);
      mesh1d = meshes[ge];
      if(seam){ mesh1d_seam = meshes_seam[ge]; }
      mesh1d_reversed.insert(mesh1d_reversed.begin(), mesh1d.rbegin(), mesh1d.rend());
      if(seam) mesh1d_seam_reversed.insert(mesh1d_seam_reversed.begin(),
                                           mesh1d_seam.rbegin(),mesh1d_seam.rend());
      if(!counter){
        counter++;
        if(seam && seam_the_first){
          coords = ((*it)._sign == 1) ? mesh1d_seam : mesh1d_seam_reversed;
          found = (*it);
          Msg::Info("This test case would have failed in previous Gmsh versions ;-)");
        }
        else{
          coords = ((*it)._sign == 1) ? mesh1d : mesh1d_reversed;
          found = (*it);
        }
        if(MYDEBUG)
          printf("Starting with edge = %d seam %d\n", (*it).ge->tag(), seam);
        unordered.erase(it);
        break;
      }
      else{
        if(MYDEBUG)
          printf("Followed by edge = %d\n", (*it).ge->tag());
        SPoint2 first_coord = mesh1d[0];
        double d = -1, d_reversed = -1, d_seam = -1, d_seam_reversed = -1;
        d = dist2(last_coord, first_coord);
        if(MYDEBUG)
          printf("%g %g dist = %12.5E\n", first_coord.x(), first_coord.y(), d);
        if(d < tol){
          coords.clear();
          coords = mesh1d;
          found = GEdgeSigned(1,ge);
          unordered.erase(it);
          goto Finalize;
        }
        SPoint2 first_coord_reversed = mesh1d_reversed[0];
        d_reversed = dist2(last_coord, first_coord_reversed);
        if(MYDEBUG)
          printf("%g %g dist_reversed = %12.5E\n",
                 first_coord_reversed.x(), first_coord_reversed.y(), d_reversed);
        if(d_reversed < tol){
          coords.clear();
          coords = mesh1d_reversed;
          found = (GEdgeSigned(-1,ge));
          unordered.erase(it);
          goto Finalize;
        }
        if(seam){
          SPoint2 first_coord_seam = mesh1d_seam[0];
          SPoint2 first_coord_seam_reversed = mesh1d_seam_reversed[0];
          d_seam = dist2(last_coord,first_coord_seam);
          if(MYDEBUG) printf("dist_seam = %12.5E\n", d_seam);
          if(d_seam < tol){
            coords.clear();
            coords = mesh1d_seam;
            found = (GEdgeSigned(1,ge));
            unordered.erase(it);
            goto Finalize;
          }
          d_seam_reversed = dist2(last_coord, first_coord_seam_reversed);
          if(MYDEBUG) printf("dist_seam_reversed = %12.5E\n", d_seam_reversed);
          if(d_seam_reversed < tol){
            coords.clear();
            coords = mesh1d_seam_reversed;
            found = GEdgeSigned(-1, ge);
            unordered.erase(it);
            break;
            goto Finalize;
          }
        }
      }
      ++it;
    }
  Finalize:
    if(MYDEBUG) printf("Finalize, found %d points\n", (int)coords.size());
    if(coords.size() == 0){
      // It has not worked : either tolerance is wrong or the first seam edge
      // has to be taken with the other parametric coordinates (because it is
      // only present once in the closure of the domain).
      for(std::map<BDS_Point*, MVertex*,PointLessThan>::iterator it = recoverMapLocal.begin();
          it != recoverMapLocal.end(); ++it){
        m->del_point(it->first);
      }
      return false;
    }

    std::vector<MVertex*> edgeLoop;
    if(found._sign == 1){
      edgeLoop.push_back(found.ge->getBeginVertex()->mesh_vertices[0]);
      for(unsigned int i = 0; i <found.ge->mesh_vertices.size(); i++)
        edgeLoop.push_back(found.ge->mesh_vertices[i]);
    }
    else{
      edgeLoop.push_back(found.ge->getEndVertex()->mesh_vertices[0]);
      for(int i = found.ge->mesh_vertices.size() - 1; i >= 0; i--)
        edgeLoop.push_back(found.ge->mesh_vertices[i]);
    }

    if(MYDEBUG)
      printf("edge %d size %d size %d\n",
             found.ge->tag(), (int)edgeLoop.size(), (int)coords.size());

    std::vector<BDS_Point*> edgeLoop_BDS;
    for(unsigned int i = 0; i < edgeLoop.size(); i++){
      MVertex *here = edgeLoop[i];
      GEntity *ge = here->onWhat();

      BDS_Point *pp = 0;
      if(ge->dim() == 0){
        // Point might already be part of other loop
        for (std::map<BDS_Point*, MVertex*, PointLessThan>::iterator it = recoverMap.begin();
             it != recoverMap.end(); ++it){
          if (it->second == here){
            pp = it->first;
            break;
          }
        }
      }
      if(pp == 0){
        double U, V;
        SPoint2 param = coords[i];
        U = param.x() / m->scalingU;
        V = param.y() / m->scalingV;
        pp = m->add_point(count + countTot, U, V, gf);
        if (ge->dim() == 0){
          pp->lcBGM() = BGM_MeshSize(ge, 0, 0, here->x(), here->y(), here->z());
        }
        else if (ge->dim() == 1){
          double u;
          here->getParameter(0, u);
          pp->lcBGM() = BGM_MeshSize(ge, u, 0, here->x(), here->y(), here->z());
        }
        else
          pp->lcBGM() = MAX_LC;

        pp->lc() = pp->lcBGM();
        m->add_geom(ge->tag(), ge->dim());
        BDS_GeomEntity *g = m->get_geom(ge->tag(), ge->dim());
        pp->g = g;
        if (MYDEBUG)
          printf("point %3d (%8.5f %8.5f : %8.5f %8.5f) (%2d,%2d)\n",
                 count, pp->u, pp->v, param.x(), param.y(), pp->g->classif_tag,
                 pp->g->classif_degree);
        bbox += SPoint3(U, V, 0);
      }
      edgeLoop_BDS.push_back(pp);
      recoverMapLocal[pp] = here;
      count++;
    }
    last_coord = coords[coords.size() - 1];
    if(MYDEBUG) printf("last coord %g %g\n", last_coord.x(), last_coord.y());
    result.insert(result.end(), edgeLoop_BDS.begin(), edgeLoop_BDS.end());
  }

  // It has worked, so we add all the points to the recover map
  recoverMap.insert(recoverMapLocal.begin(), recoverMapLocal.end());

  return true;
}

static bool meshGeneratorElliptic(GFace *gf, bool debug = true)
{
#if defined(HAVE_ANN)
  Centerline *center = 0;
  FieldManager *fields = GModel::current()->getFields();
  if (fields->getBackgroundField() > 0 ){
    Field *myField = fields->get(fields->getBackgroundField());
    center = dynamic_cast<Centerline*> (myField);
  }

  bool recombine =  (CTX::instance()->mesh.recombineAll) ;
  int nbBoundaries = gf->edges().size();

  if (center && recombine && nbBoundaries == 2) {
    printf("--> regular periodic grid generator (elliptic smooth) \n");
    //bool success  = createRegularTwoCircleGrid(center, gf);
    bool success  = createRegularTwoCircleGridPeriodic(center, gf);
    return success;
  }
  else return false;

#else
  return false;
#endif
}

static bool meshGeneratorPeriodic(GFace *gf, bool debug = true)
{
  std::map<BDS_Point*, MVertex*, PointLessThan> recoverMap;

  Range<double> rangeU = gf->parBounds(0);
  Range<double> rangeV = gf->parBounds(1);

  double du = rangeU.high() - rangeU.low();
  double dv = rangeV.high() - rangeV.low();

  const double LC2D = sqrt(du * du + dv * dv);

  // Buid a BDS_Mesh structure that is convenient for doing the actual
  // meshing procedure
  BDS_Mesh *m = new BDS_Mesh;
  m->scalingU = 1;
  m->scalingV = 1;

  std::vector<std::vector<BDS_Point*> > edgeLoops_BDS;
  SBoundingBox3d bbox;
  int nbPointsTotal = 0;
  {
    for(std::list<GEdgeLoop>::iterator it = gf->edgeLoops.begin();
        it != gf->edgeLoops.end(); it++){
      std::vector<BDS_Point* > edgeLoop_BDS;
      int nbPointsLocal;
      const double fact[4] = {1.e-12, 1.e-7, 1.e-5, 1.e-3};
      bool ok = false;
      for(int i = 0; i < 4; i++){
        if(buildConsecutiveListOfVertices(gf, *it, edgeLoop_BDS, bbox, m,
                                          recoverMap, nbPointsLocal,
                                          nbPointsTotal, fact[i] * LC2D)){
          ok = true;
          break;
        }
        if(buildConsecutiveListOfVertices(gf, *it, edgeLoop_BDS, bbox, m,
                                          recoverMap, nbPointsLocal,
                                          nbPointsTotal, fact[i] * LC2D, true)){
          ok = true;
          break;
        }
      }
      if(!ok){
        gf->meshStatistics.status = GFace::FAILED;
        Msg::Error("The 1D mesh seems not to be forming a closed loop");
        delete m;
        return false;
      }
      nbPointsTotal += nbPointsLocal;
      edgeLoops_BDS.push_back(edgeLoop_BDS);
    }
  }

  if(nbPointsTotal < 3){
    Msg::Warning("Mesh Generation of Model Face %d Skipped: "
                 "Only %d Mesh Vertices on The Contours",
                 gf->tag(), nbPointsTotal);
    gf->meshStatistics.status = GFace::DONE;
    delete m;
    return true;
  }
  if(nbPointsTotal == 3){
    MVertex *vv[3];
    int i = 0;
    for(std::map<BDS_Point*, MVertex*, PointLessThan>::iterator it = recoverMap.begin();
        it != recoverMap.end(); it++){
      vv[i++] = it->second;
    }
    gf->triangles.push_back(new MTriangle(vv[0], vv[1], vv[2]));
    gf->meshStatistics.status = GFace::DONE;
    delete m;
    return true;
  }


  // Use a divide & conquer type algorithm to create a triangulation.
  // We add to the triangulation a box with 4 points that encloses the
  // domain.
#if 1 //OLD_CODE_DELAUNAY
  {
    DocRecord doc(nbPointsTotal + 4);
    int count = 0;
    for(unsigned int i = 0; i < edgeLoops_BDS.size(); i++){
      std::vector<BDS_Point*> &edgeLoop_BDS = edgeLoops_BDS[i];
      for(unsigned int j = 0; j < edgeLoop_BDS.size(); j++){
        BDS_Point *pp = edgeLoop_BDS[j];
        double XX = CTX::instance()->mesh.randFactor * LC2D * (double)rand() /
          (double)RAND_MAX;
        double YY = CTX::instance()->mesh.randFactor * LC2D * (double)rand() /
          (double)RAND_MAX;
        doc.points[count].where.h = pp->u + XX;
        doc.points[count].where.v = pp->v + YY;
        doc.points[count].adjacent = NULL;
        doc.points[count].data = pp;
        count++;
      }
    }

    // Increase the size of the bounding box, add 4 points that enclose
    // the domain, use negative number to distinguish those fake
    // vertices

    // FIX A BUG HERE IF THE SIZE OF THE BOX IS ZERO
    bbox.makeCube();

    bbox *= 3.5;
    MVertex *bb[4];
    bb[0] = new MVertex(bbox.min().x(), bbox.min().y(), 0, 0, -1);
    bb[1] = new MVertex(bbox.min().x(), bbox.max().y(), 0, 0, -2);
    bb[2] = new MVertex(bbox.max().x(), bbox.min().y(), 0, 0, -3);
    bb[3] = new MVertex(bbox.max().x(), bbox.max().y(), 0, 0, -4);
    for(int ip = 0; ip < 4; ip++){
      BDS_Point *pp = m->add_point(-ip - 1, bb[ip]->x(), bb[ip]->y(), gf);
      m->add_geom(gf->tag(), 2);
      BDS_GeomEntity *g = m->get_geom(gf->tag(), 2);
      pp->g = g;
      doc.points[nbPointsTotal+ip].where.h = bb[ip]->x();
      doc.points[nbPointsTotal+ip].where.v = bb[ip]->y();
      doc.points[nbPointsTotal+ip].adjacent = 0;
      doc.points[nbPointsTotal+ip].data = pp;
    }
    for(int ip = 0; ip < 4; ip++) delete bb[ip];

    // Use "fast" inhouse recursive algo to generate the triangulation
    // At this stage the triangulation is not what we need
    //   -) It does not necessary recover the boundaries
    //   -) It contains triangles outside the domain (the first edge
    //      loop is the outer one)
    Msg::Debug("Meshing of the convex hull (%d points)", nbPointsTotal);

    try{
      doc.MakeMeshWithPoints();
    }
    catch(const char *err){
      Msg::Error("%s", err);
    }

    for(int i = 0; i < doc.numTriangles; i++){
      int a = doc.triangles[i].a;
      int b = doc.triangles[i].b;
      int c = doc.triangles[i].c;
      int n = doc.numPoints;
      if(a < 0 || a >= n || b < 0 || b >= n || c < 0 || c >= n){
        Msg::Warning("Skipping bad triangle %d", i);
        continue;
      }
      BDS_Point *p1 = (BDS_Point*)doc.points[doc.triangles[i].a].data;
      BDS_Point *p2 = (BDS_Point*)doc.points[doc.triangles[i].b].data;
      BDS_Point *p3 = (BDS_Point*)doc.points[doc.triangles[i].c].data;
      m->add_triangle(p1->iD, p2->iD, p3->iD);
    }
  }
#else
  {
    /// FIXME FOR PERIODIC : SOME MVERTices SHOULD BE DUPLICATED ...
    /// Still to be done...
    std::vector<MVertex*> v;
    std::map<MVertex*, BDS_Point*> recoverMapInv;
    for(unsigned int i = 0; i < edgeLoops_BDS.size(); i++){
      std::vector<BDS_Point*> &edgeLoop_BDS = edgeLoops_BDS[i];
      for(unsigned int j = 0; j < edgeLoop_BDS.size(); j++){
        BDS_Point *pp = edgeLoop_BDS[j];
        v.push_back(recoverMap[pp]);
        recoverMapInv[recoverMap[pp]] = pp;
      }
    }

    //    printf("coucou2 %d verices\n",v.size());
    std::map<MVertex*,SPoint3> pos;
    for(unsigned int i = 0; i < v.size(); i++) {
      MVertex *v0 = v[i];
      BDS_Point *p0  = recoverMapInv[v0];
      pos[v0] = SPoint3(v0->x(),v0->y(),v0->z());
      v0->setXYZ(p0->u,p0->v,0.0);
    }
    std::vector<MTriangle*> result;
    delaunayMeshIn2D(v, result, 0);
    //    delaunayMeshIn2D(v, result, 0, & medgesToRecover);

    for(unsigned int i = 0; i < v.size()-4; i++) {
      MVertex *v0 = v[i];
      SPoint3 pp = pos[v0];
      v0->setXYZ(pp.x(),pp.y(),pp.z());
    }

    // add the four corners
    for(int ip = 0; ip < 4; ip++){
      MVertex *vv = v[v.size()-ip-1];
      BDS_Point *pp = m->add_point(-ip - 1, vv->x(),vv->y(), gf);
      m->add_geom(gf->tag(), 2);
      recoverMapInv[vv] = pp;
      BDS_GeomEntity *g = m->get_geom(gf->tag(), 2);
      pp->g = g;
    }
    // add the triangles
    for(unsigned int i = 0; i < result.size(); i++) {
      MVertex *v0 = result[i]->getVertex(0);
      MVertex *v1 = result[i]->getVertex(1);
      MVertex *v2 = result[i]->getVertex(2);
      BDS_Point *p0  = recoverMapInv[v0];
      BDS_Point *p1  = recoverMapInv[v1];
      BDS_Point *p2  = recoverMapInv[v2];
      m->add_triangle(p0->iD, p1->iD, p2->iD);
    }
  }
#endif

  // Recover the boundary edges and compute characteristic lenghts
  // using mesh edge spacing
  BDS_GeomEntity CLASS_F(1, 2);
  BDS_GeomEntity CLASS_E(1, 1);
  BDS_GeomEntity CLASS_EXTERIOR(3, 2);

  if(debug){
    char name[245];
    sprintf(name, "surface%d-initial-real.pos", gf->tag());
    outputScalarField(m->triangles, name, 0);
    sprintf(name, "surface%d-initial-param.pos", gf->tag());
    outputScalarField(m->triangles, name, 1);
  }

  bool _fatallyFailed;

  for(unsigned int i = 0; i < edgeLoops_BDS.size(); i++){
    std::vector<BDS_Point*> &edgeLoop_BDS = edgeLoops_BDS[i];
    for(unsigned int j = 0; j < edgeLoop_BDS.size(); j++){
      BDS_Edge * e = m->recover_edge
        (edgeLoop_BDS[j]->iD, edgeLoop_BDS[(j + 1) % edgeLoop_BDS.size()]->iD, _fatallyFailed);
      if(!e){
        Msg::Error("Impossible to recover the edge %d %d", edgeLoop_BDS[j]->iD,
                   edgeLoop_BDS[(j + 1) % edgeLoop_BDS.size()]->iD);
        gf->meshStatistics.status = GFace::FAILED;
        delete m;
        return false;
      }
      else e->g = &CLASS_E;
    }
  }

  // look for a triangle that has a negative node and recursively
  // tag all exterior triangles
  {
    std::list<BDS_Face*>::iterator itt = m->triangles.begin();
    while (itt != m->triangles.end()){
      (*itt)->g = 0;
      ++itt;
    }
    itt = m->triangles.begin();
    while (itt != m->triangles.end()){
      BDS_Face *t = *itt;
      BDS_Point *n[4];
      t->getNodes(n);
      if (n[0]->iD < 0 || n[1]->iD < 0 ||
          n[2]->iD < 0 ) {
        recur_tag(t, &CLASS_EXTERIOR);
        break;
      }
      ++itt;
    }
  }

  // now find an edge that has belongs to one of the exterior
  // triangles
  {
    std::list<BDS_Edge*>::iterator ite = m->edges.begin();
    while (ite != m->edges.end()){
      BDS_Edge *e = *ite;
      if(e->g  && e->numfaces() == 2){
        if(e->faces(0)->g == &CLASS_EXTERIOR){
          recur_tag(e->faces(1), &CLASS_F);
          break;
        }
        else if(e->faces(1)->g == &CLASS_EXTERIOR){
          recur_tag(e->faces(0), &CLASS_F);
          break;
        }
      }
      ++ite;
    }
    std::list<BDS_Face*>::iterator itt = m->triangles.begin();
    while (itt != m->triangles.end()){
      if ((*itt)->g == &CLASS_EXTERIOR) (*itt)->g = 0;
      ++itt;
    }
  }

  // delete useless stuff
  {
    std::list<BDS_Face*>::iterator itt = m->triangles.begin();
    while (itt != m->triangles.end()){
      BDS_Face *t = *itt;
      if(!t->g){
        m->del_face (t);
      }
      ++itt;
    }
  }

  m->cleanup();

  {
    std::list<BDS_Edge*>::iterator ite = m->edges.begin();
    while (ite != m->edges.end()){
      BDS_Edge *e = *ite;
      if(e->numfaces() == 0)
        m->del_edge(e);
      else{
        if(!e->g)
          e->g = &CLASS_F;
        if(!e->p1->g || e->p1->g->classif_degree > e->g->classif_degree)
          e->p1->g = e->g;
        if(!e->p2->g || e->p2->g->classif_degree > e->g->classif_degree)
          e->p2->g = e->g;
      }
      ++ite;
    }
  }
  m->cleanup();
  m->del_point(m->find_point(-1));
  m->del_point(m->find_point(-2));
  m->del_point(m->find_point(-3));
  m->del_point(m->find_point(-4));

  if(debug){
    char name[245];
    sprintf(name, "surface%d-recovered-real.pos", gf->tag());
    outputScalarField(m->triangles, name, 0);
    sprintf(name, "surface%d-recovered-param.pos", gf->tag());
    outputScalarField(m->triangles, name, 1);
  }


  // start mesh generation for periodic face
  if(!algoDelaunay2D(gf)){
    // need for a BGM for cross field
    //    if(CTX::instance()->mesh.recombineAll || gf->meshAttributes.recombine || 1) {
    //      printf("coucou here !!!\n");
    //      backgroundMesh::unset();
    //      buildBackGroundMesh (gf);
    //    }
    refineMeshBDS(gf, *m, CTX::instance()->mesh.refineSteps, true);
    optimizeMeshBDS(gf, *m, 2);
    refineMeshBDS(gf, *m, -CTX::instance()->mesh.refineSteps, false);
    optimizeMeshBDS(gf, *m, 2, &recoverMap);
    // compute mesh statistics
    /*
    computeMeshSizeFieldAccuracy(gf, *m, gf->meshStatistics.efficiency_index,
                                 gf->meshStatistics.longest_edge_length,
                                 gf->meshStatistics.smallest_edge_length,
                                 gf->meshStatistics.nbEdge,
                                 gf->meshStatistics.nbGoodLength);*/
    gf->meshStatistics.status = GFace::DONE;

    //    if(CTX::instance()->mesh.recombineAll || gf->meshAttributes.recombine || 1) {
    //            backgroundMesh::unset();
    //    }
  }

  // This is a structure that we need only for periodic cases
  // We will duplicate the vertices (MVertex) that are on seams

  std::map<MVertex*, MVertex*> equivalence;
  std::map<MVertex*, SPoint2> parametricCoordinates;
  if(algoDelaunay2D(gf)){
    std::map<MVertex*, BDS_Point*> invertMap;
    std::map<BDS_Point*, MVertex*, PointLessThan>::iterator it = recoverMap.begin();
    while(it != recoverMap.end()){
      // we have twice vertex MVertex with 2 different coordinates
      MVertex *mv1 = it->second;
      BDS_Point *bds = it->first;
      std::map<MVertex*, BDS_Point*>::iterator invIt = invertMap.find(mv1);
      if (invIt != invertMap.end()){
        // create a new "fake" vertex that will be destroyed afterwards
        MVertex *mv2 = 0;
        if (mv1->onWhat()->dim() == 1) {
          double t;
          mv1->getParameter(0,t);
          mv2 = new MEdgeVertex(mv1->x(),mv1->y(),mv1->z(),mv1->onWhat(), t,
                                ((MEdgeVertex*)mv1)->getLc());
        }
        else if (mv1->onWhat()->dim() == 0) {
          mv2 = new MVertex (mv1->x(),mv1->y(),mv1->z(),mv1->onWhat());
        }
        else
          Msg::Error("Could not reconstruct seam");
        if(mv2){
          it->second = mv2;
          equivalence[mv2] = mv1;
          parametricCoordinates[mv2] = SPoint2(bds->u,bds->v);
          invertMap[mv2] = bds;
        }
      }
      else {
        parametricCoordinates[mv1] = SPoint2(bds->u,bds->v);
        invertMap[mv1] = bds;
      }
      ++it;
    }
    // recoverMap.insert(new_relations.begin(), new_relations.end());
  }
  Msg::Info("%d points that are duplicated for Delaunay meshing", equivalence.size());

  // fill the small gmsh structures
  {
    std::set<BDS_Point*, PointLessThan>::iterator itp = m->points.begin();
    while (itp != m->points.end()){
      BDS_Point *p = *itp;
      if(recoverMap.find(p) == recoverMap.end()){
        MVertex *v = new MFaceVertex
          (p->X, p->Y, p->Z, gf, m->scalingU * p->u, m->scalingV * p->v);
        recoverMap[p] = v;
        gf->mesh_vertices.push_back(v);
      }
      ++itp;
    }
  }

  std::map<MTriangle*, BDS_Face*> invert_map;
  {
    std::list<BDS_Face*>::iterator itt = m->triangles.begin();
    while (itt != m->triangles.end()){
      BDS_Face *t = *itt;
      if(!t->deleted){
        BDS_Point *n[4];
        t->getNodes(n);
        MVertex *v1 = recoverMap[n[0]];
        MVertex *v2 = recoverMap[n[1]];
        MVertex *v3 = recoverMap[n[2]];
        if(!n[3]){
          // when a singular point is present, degenerated triangles
          // may be created, for example on a sphere that contains one
          // pole
          if(v1 != v2 && v1 != v3 && v2 != v3){
            // we are in the periodic case. if we aim at
            // using delaunay mesh generation in thoses cases,
            // we should double some of the vertices
            gf->triangles.push_back(new MTriangle(v1, v2, v3));
          }
        }
        else{
          MVertex *v4 = recoverMap[n[3]];
          gf->quadrangles.push_back(new MQuadrangle(v1, v2, v3, v4));
        }
      }
      ++itt;
    }
  }

  if(debug){
    char name[245];
    sprintf(name, "surface%d-final-real.pos", gf->tag());
    outputScalarField(m->triangles, name, 0, gf);
    sprintf(name, "surface%d-final-param.pos", gf->tag());
    outputScalarField(m->triangles, name, 1);
  }

  bool infty = false;
  if (gf->getMeshingAlgo() == ALGO_2D_FRONTAL_QUAD ||
      gf->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS ||
      gf->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS_CSTR)
    infty = true;
  if (infty)
    buildBackGroundMesh (gf, &equivalence, &parametricCoordinates);
  // BOUNDARY LAYER
  modifyInitialMeshForTakingIntoAccountBoundaryLayers(gf);


  if(algoDelaunay2D(gf)){
    if(gf->getMeshingAlgo() == ALGO_2D_FRONTAL)
      bowyerWatsonFrontal(gf, &equivalence, &parametricCoordinates);
    else if(gf->getMeshingAlgo() == ALGO_2D_FRONTAL_QUAD)
      bowyerWatsonFrontalLayers(gf,true, &equivalence, &parametricCoordinates);
    else if(gf->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS)
      bowyerWatsonParallelograms(gf,&equivalence, &parametricCoordinates);
    else if(gf->getMeshingAlgo() == ALGO_2D_PACK_PRLGRMS_CSTR)
      bowyerWatsonParallelogramsConstrained(gf,gf->constr_vertices,&equivalence, &parametricCoordinates);
    else if(gf->getMeshingAlgo() == ALGO_2D_DELAUNAY ||
            gf->getMeshingAlgo() == ALGO_2D_AUTO)
      bowyerWatson(gf,1000000000, &equivalence, &parametricCoordinates);
    else
      meshGFaceBamg(gf);
    if (!infty || !(CTX::instance()->mesh.recombineAll || gf->meshAttributes.recombine))
      laplaceSmoothing(gf, CTX::instance()->mesh.nbSmoothing, infty);
  }

  // delete the mesh
  delete m;

  if((CTX::instance()->mesh.recombineAll || gf->meshAttributes.recombine) &&
     !CTX::instance()->mesh.optimizeLloyd && CTX::instance()->mesh.algoRecombine != 2)
    recombineIntoQuads(gf,true,false);

  computeElementShapes(gf, gf->meshStatistics.worst_element_shape,
                       gf->meshStatistics.average_element_shape,
                       gf->meshStatistics.best_element_shape,
                       gf->meshStatistics.nbTriangle,
                       gf->meshStatistics.nbGoodQuality);
  gf->meshStatistics.status = GFace::DONE;
  return true;
}

void deMeshGFace::operator() (GFace *gf)
{
  if(gf->geomType() == GEntity::DiscreteSurface && !CTX::instance()->meshDiscrete)
    return;
  gf->deleteMesh();
  gf->meshStatistics.status = GFace::PENDING;
  gf->meshStatistics.nbTriangle = gf->meshStatistics.nbEdge = 0;
  gf->correspondingVertices.clear();
}

// for debugging, change value from -1 to -100;
int debugSurface = -1; //-100;

void meshGFace::operator() (GFace *gf, bool print)
{
  gf->model()->setCurrentMeshEntity(gf);

  if(debugSurface >= 0 && gf->tag() != debugSurface){
    gf->meshStatistics.status = GFace::DONE;
    return;
  }

  //  if(gf->geomType() == GEntity::DiscreteFace) return;
  if(gf->geomType() == GEntity::ProjectionFace) return;
  if(gf->meshAttributes.method == MESH_NONE) return;
  if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) return;

  // destroy the mesh if it exists
  deMeshGFace dem;
  dem(gf);

  // FIXME: if transfinite surface, impossible to use ALGO_3D_RTREE
  // because meshGenerator never called
  if(MeshTransfiniteSurface(gf)) return;
  if(MeshExtrudedSurface(gf)) return;
  if(gf->meshMaster() != gf){
    GFace *gff = dynamic_cast<GFace*> (gf->meshMaster());
    if(gff){
      if (gff->meshStatistics.status != GFace::DONE){
        gf->meshStatistics.status = GFace::PENDING;
        return;
      }
      Msg::Info("Meshing face %d (%s) as a copy of %d", gf->tag(),
                gf->getTypeString().c_str(), gf->meshMaster()->tag());
      copyMesh(gff, gf);
      gf->meshStatistics.status = GFace::DONE;
      return;
    }
    else
      Msg::Warning("Unknown mesh master face %d", gf->meshMaster()->tag());
  }

  const char *algo = "Unknown";

  switch(gf->getMeshingAlgo()){
  case ALGO_2D_MESHADAPT : algo = "MeshAdapt"; break;
  case ALGO_2D_FRONTAL : algo = "Frontal"; break;
  case ALGO_2D_FRONTAL_QUAD : algo = "Frontal Quad"; break;
  case ALGO_2D_DELAUNAY : algo = "Delaunay"; break;
  case ALGO_2D_MESHADAPT_OLD : algo = "MeshAdapt (old)"; break;
  case ALGO_2D_BAMG : algo = "Bamg"; break;
  case ALGO_2D_PACK_PRLGRMS : algo = "Square Packing"; break;
  case ALGO_2D_AUTO :
    algo = (gf->geomType() == GEntity::Plane) ? "Delaunay" : "MeshAdapt";
    break;
  }

  if (!algoDelaunay2D(gf)){
    algo = "MeshAdapt";
  }

  if (print)
    Msg::Info("Meshing surface %d (%s, %s)", gf->tag(), gf->getTypeString().c_str(), algo);

  // compute loops on the fly (indices indicate start and end points
  // of a loop; loops are not yet oriented)
  Msg::Debug("Computing edge loops");

  Msg::Debug("Generating the mesh");

  if(meshGeneratorElliptic(gf)){
    gf->meshStatistics.status = GFace::DONE;
    return;
  }

  quadMeshRemoveHalfOfOneDMesh halfmesh (gf);

  if ((gf->getNativeType() != GEntity::AcisModel ||
       (!gf->periodic(0) && !gf->periodic(1))) &&
      (noSeam(gf) || gf->getNativeType() == GEntity::GmshModel ||
       gf->edgeLoops.empty())){
    meshGenerator(gf, 0, repairSelfIntersecting1dMesh, onlyInitialMesh,
                  debugSurface >= 0 || debugSurface == -100);
  }
  else {
    if(!meshGeneratorPeriodic
       (gf, debugSurface >= 0 || debugSurface == -100))
      Msg::Error("Impossible to mesh periodic face %d", gf->tag());
  }

  Msg::Debug("Type %d %d triangles generated, %d internal vertices",
             gf->geomType(), gf->triangles.size(), gf->mesh_vertices.size());

  halfmesh.finish();
}

bool checkMeshCompound(GFaceCompound *gf, std::list<GEdge*> &edges)
{
  bool isMeshed = false;
#if defined(HAVE_SOLVER)
  bool correctTopo = gf->checkTopology();
  if (!correctTopo && gf->allowPartition()){
    partitionAndRemesh((GFaceCompound*) gf);
    isMeshed = true;
    return isMeshed;
  }

  bool correctParam = gf->parametrize();

  if (!correctParam &&  gf->allowPartition()){
   partitionAndRemesh((GFaceCompound*) gf);
   isMeshed = true;
   return isMeshed;
  }

  //Replace edges by their compounds
  std::set<GEdge*> mySet;
  std::list<GEdge*>::iterator it = edges.begin();
  while(it != edges.end()){
    if((*it)->getCompound()){
      mySet.insert((*it)->getCompound());
    }
    else{
      mySet.insert(*it);
    }
    ++it;
  }
  edges.clear();
  edges.insert(edges.begin(), mySet.begin(), mySet.end());
#endif
  return isMeshed;
}

void partitionAndRemesh(GFaceCompound *gf)
{
#if defined(HAVE_SOLVER) && (defined(HAVE_CHACO) || defined(HAVE_METIS))

  // Partition the mesh and createTopology for new faces
  double tbegin = Cpu();
  std::list<GFace*> cFaces = gf->getCompounds();
  std::vector<MElement *> elements;
  for (std::list<GFace*>::iterator it = cFaces.begin(); it != cFaces.end(); it++)
    for(unsigned int j = 0; j < (*it)->getNumMeshElements(); j++)
      elements.push_back((*it)->getMeshElement(j));

  typeOfPartition method;
  if(gf->nbSplit > 0) method = MULTILEVEL;
  else method = LAPLACIAN;

  int allowType = gf->allowPartition();
  multiscalePartition *msp = new multiscalePartition(elements, abs(gf->nbSplit),
                                                     method, allowType);

  int NF = msp->getNumberOfParts();
  int numv = gf->model()->getMaxElementaryNumber(0) + 1;
  int nume = gf->model()->getMaxElementaryNumber(1) + 1;
  int numf = gf->model()->getMaxElementaryNumber(2) + 1;
  std::vector<discreteFace*> pFaces;
  createPartitionFaces(gf->model(), elements, NF, pFaces);

  gf->model()->createTopologyFromFaces(pFaces);

  double tmult = Cpu();
  Msg::Info("Multiscale Partition SUCCESSFULLY PERFORMED : %d parts (%g s)",
            NF, tmult - tbegin);
  gf->model()->writeMSH("multiscalePARTS.msh", 2.2, false, true);

  // Remesh new faces (Compound Lines and Compound Surfaces)
  Msg::Info("*** Starting parametrize compounds:");
  double t0 = Cpu();

  //Parametrize Compound Lines
  int NE = gf->model()->getMaxElementaryNumber(1) - nume + 1;
  for (int i=0; i < NE; i++){
    std::vector<GEdge*>e_compound;
    GEdge *pe = gf->model()->getEdgeByTag(nume+i);//partition edge
    e_compound.push_back(pe);
    int num_gec = nume + NE + i ;
    Msg::Info("Parametrize Compound Line (%d) = %d discrete edge",
              num_gec, pe->tag());
    GEdgeCompound *gec = new GEdgeCompound(gf->model(), num_gec, e_compound);
    gf->model()->add(gec);
  }

  // Parametrize Compound surfaces
  std::set<MVertex*> allNod;
  std::list<GEdge*> U0;
  for (int i=0; i < NF; i++){
    std::list<GFace*> f_compound;
    GFace *pf =  gf->model()->getFaceByTag(numf+i);//partition face
    int num_gfc = numf + NF + i ;
    f_compound.push_back(pf);
    Msg::Info("Parametrize Compound Surface (%d) = %d discrete face",
              num_gfc, pf->tag());

    GFaceCompound *gfc = new GFaceCompound(gf->model(), num_gfc, f_compound, U0,
                                           gf->getTypeOfCompound());

    gfc->meshAttributes.recombine = gf->meshAttributes.recombine;
    gf->model()->add(gfc);

    gfc->parametrize();
  }

  double t1 = Cpu();
  Msg::Info("*** Parametrize compounds done (%g s)", t1-t0);
  Msg::Info("*** Starting meshing 1D edges ...:");
  for (int i = 0; i < NE; i++){
    GEdge *gec = gf->model()->getEdgeByTag(nume + NE + i);
    meshGEdge mge;
    mge(gec);
  }
  double t2 = Cpu();
  Msg::Info("*** Meshing 1D edges done (%gs)", t2-t1);

  Msg::Info("*** Starting Mesh of surface %d ...", gf->tag());

  for (int i=0; i < NF; i++){
    GFace *gfc =  gf->model()->getFaceByTag(numf + NF + i );
    meshGFace mgf;
    mgf(gfc);

    for(unsigned int j = 0; j < gfc->triangles.size(); ++j){
      MTriangle *t = gfc->triangles[j];
      std::vector<MVertex *> v(3);
      for(int k = 0; k < 3; k++){
        v[k] = t->getVertex(k);
        allNod.insert(v[k]);
      }
      gf->triangles.push_back(new MTriangle(v[0], v[1], v[2]));
    }
    for(unsigned int j = 0; j < gfc->quadrangles.size(); ++j){
      MQuadrangle *q = gfc->quadrangles[j];
      std::vector<MVertex *> v(4);
      for(int k = 0; k < 4; k++){
        v[k] = q->getVertex(k);
        allNod.insert(v[k]);
      }
      gf->quadrangles.push_back(new MQuadrangle(v[0], v[1], v[2], v[3]));
    }

    //update mesh statistics
    gf->meshStatistics.efficiency_index += gfc->meshStatistics.efficiency_index;
    gf->meshStatistics.longest_edge_length = std::max(gf->meshStatistics.longest_edge_length,
                                                     gfc->meshStatistics.longest_edge_length);
    gf->meshStatistics.smallest_edge_length= std::min(gf->meshStatistics.smallest_edge_length,
                                                      gfc->meshStatistics.smallest_edge_length);
    gf->meshStatistics.nbGoodLength  += gfc->meshStatistics.nbGoodLength;
    gf->meshStatistics.nbGoodQuality += gfc->meshStatistics.nbGoodQuality;
    gf->meshStatistics.nbEdge += gfc->meshStatistics.nbEdge;

  }

  // Removing discrete Vertices - Edges - Faces
  int NV = gf->model()->getMaxElementaryNumber(0) - numv + 1;
  for (int i=0; i < NV; i++){
    GVertex *pv = gf->model()->getVertexByTag(numv+i);
    gf->model()->remove(pv);
  }
  for (int i=0; i < NE; i++){
    GEdge *gec = gf->model()->getEdgeByTag(nume+NE+i);
    GEdge *pe = gf->model()->getEdgeByTag(nume+i);
    gf->model()->remove(pe);
    gf->model()->remove(gec);
  }
  for (int i=0; i < NF; i++){
    GFace *gfc = gf->model()->getFaceByTag(numf+NF+i);
    GFace *pf  = gf->model()->getFaceByTag(numf+i);
    gf->model()->remove(pf);
    gf->model()->remove(gfc);
  }

  // Put new mesh in a new discreteFace
  for(std::set<MVertex*>::iterator it = allNod.begin(); it != allNod.end(); ++it){
    gf->mesh_vertices.push_back(*it);
  }

  // FIXME: This horrible hack is necessary to remove vertices that might belong
  // to a GVertex.  The true fix is rewrite this part of the code: it's far too
  // complex and error prone.
  for(GModel::viter it = gf->model()->firstVertex(); it != gf->model()->lastVertex(); it++){
    std::vector<MVertex*>::iterator itve = std::find
      (gf->mesh_vertices.begin(), gf->mesh_vertices.end(), (*it)->mesh_vertices[0]);
    if(itve != gf->mesh_vertices.end())
      gf->mesh_vertices.erase(itve);
  }

  // Remove mesh_vertices that belong to l_edges
  std::list<GEdge*> l_edges = gf->edges();
  for(std::list<GEdge*>::iterator it = l_edges.begin(); it != l_edges.end(); it++){
    std::vector<MVertex*> edge_vertices = (*it)->mesh_vertices;
    std::vector<MVertex*>::const_iterator itv = edge_vertices.begin();
    for(; itv != edge_vertices.end(); itv++){
      std::vector<MVertex*>::iterator itve = std::find
        (gf->mesh_vertices.begin(), gf->mesh_vertices.end(), *itv);
      if (itve != gf->mesh_vertices.end()) gf->mesh_vertices.erase(itve);
    }
    MVertex *vB = (*it)->getBeginVertex()->mesh_vertices[0];
    std::vector<MVertex*>::iterator itvB = std::find
      (gf->mesh_vertices.begin(), gf->mesh_vertices.end(), vB);
    if (itvB != gf->mesh_vertices.end()) gf->mesh_vertices.erase(itvB);
    MVertex *vE = (*it)->getEndVertex()->mesh_vertices[0];
    std::vector<MVertex*>::iterator itvE = std::find
      (gf->mesh_vertices.begin(), gf->mesh_vertices.end(), vE);
    if (itvE != gf->mesh_vertices.end()) gf->mesh_vertices.erase(itvE);

    //if l_edge is a compond
    if((*it)->getCompound()){
      GEdgeCompound *gec = (*it)->getCompound();
      std::vector<MVertex*> edge_vertices = gec->mesh_vertices;
      std::vector<MVertex*>::const_iterator itv = edge_vertices.begin();
      for(; itv != edge_vertices.end(); itv++){
        std::vector<MVertex*>::iterator itve = std::find
          (gf->mesh_vertices.begin(), gf->mesh_vertices.end(), *itv);
        if (itve != gf->mesh_vertices.end()) gf->mesh_vertices.erase(itve);
      }
      MVertex *vB = (*it)->getBeginVertex()->mesh_vertices[0];
      std::vector<MVertex*>::iterator itvB = std::find
        (gf->mesh_vertices.begin(), gf->mesh_vertices.end(), vB);
      if (itvB != gf->mesh_vertices.end()) gf->mesh_vertices.erase(itvB);
      MVertex *vE = (*it)->getEndVertex()->mesh_vertices[0];
      std::vector<MVertex*>::iterator itvE = std::find
        (gf->mesh_vertices.begin(), gf->mesh_vertices.end(), vE);
      if (itvE != gf->mesh_vertices.end()) gf->mesh_vertices.erase(itvE);
    }
  }

  double t3 = Cpu();
  Msg::Info("*** Mesh of surface %d done by assembly %d remeshed faces (%g s)",
            gf->tag(), NF, t3-t2);
  Msg::Info("-----------------------------------------------------------");

  gf->coherenceNormals();
  gf->meshStatistics.status = GFace::DONE;
#endif
}

static bool getGFaceNormalFromVert(GFace *gf, MElement *el, SVector3 &nf)
{
  bool found = false;
  for (int iElV = 0; iElV < el->getNumVertices(); iElV++) {
    MVertex *v = el->getVertex(iElV);
    SPoint2 param;
    if(v->onWhat() == gf && v->getParameter(0, param[0]) &&
       v->getParameter(1, param[1])) {
      nf = gf->normal(param);
      found = true;
      break;
    }
  }
  return found;
}

static bool getGFaceNormalFromBary(GFace *gf, MElement *el, SVector3 &nf)
{
  SPoint2 param(0., 0.);
  bool ok = true;
  for (int j = 0; j < el->getNumVertices(); j++) {
    SPoint2 p;
    // FIXME: use inexact reparam because some vertices might not be
    // exactly on the surface after the 3D Delaunay
    ok = reparamMeshVertexOnFace(el->getVertex(j), gf, p, false);
    if (!ok) break;
    param += p;
  }
  if (ok) {
    param *= 1. / el->getNumVertices();
    nf = gf->normal(param);
  }
  return ok;
}

static void getGFaceOrientation(GFace *gf, BoundaryLayerColumns *blc,
                                bool existBL, bool fromVert,
                                int &orientNonBL, int &orientBL)
{
  for (unsigned int iEl = 0; iEl < gf->getNumMeshElements(); iEl++) {
    MElement *e = gf->getMeshElement(iEl);
    const bool isBLEl = existBL &&
                        (blc->_toFirst.find(e) != blc->_toFirst.end());
    SVector3 nf;
    // Check only if orientation of BL/non-BL el. not already known
    if ((!isBLEl && orientNonBL == 0) || (isBLEl && orientBL == 0)) {
      const bool found = fromVert ? getGFaceNormalFromVert(gf, e, nf) :
        getGFaceNormalFromBary(gf, e, nf);
      if (found) {
        SVector3 ne = e->getFace(0).normal();
        const int orient = (dot(ne, nf) > 0.) ? 1 : -1;
        if (isBLEl) orientBL = orient;
        else orientNonBL = orient;
      }
    }
    // Stop when orientation found for non-BL and BL el.
    if ((orientNonBL != 0) && (orientBL != 0)) break;
  }
}

void orientMeshGFace::operator()(GFace *gf)
{
  if(!gf->getNumMeshElements()) return;
  if(gf->geomType() == GEntity::ProjectionFace) return;

  gf->model()->setCurrentMeshEntity(gf);

  if(gf->geomType() == GEntity::DiscreteSurface ||
     gf->geomType() == GEntity::BoundaryLayerSurface ||
     gf->geomType() == GEntity::CompoundSurface){
    // don't do anything
  }
  else {
    // In old versions we checked the orientation by comparing the orientation
    // of a line element on the boundary w.r.t. its connected surface
    // element. This is probably better than what follows, but
    // * it failed when the 3D Delaunay changes the 1D mesh (since we don't
    //    recover it yet)
    // * it failed with OpenCASCADE geometries, where surface orientions do not
    //   seem to be consistent with the orientation of the bounding edges

    // Now: orient surface elements w.r.t. normal to geometric model.
    // Assumes that originally, orientation is consistent among boundary layer
    // (BL) elements, and orientation is consistent among non-BL elements, but
    // BL and non-BL elements can be oriented differently

    // Determine whether there is a boundary layer (BL)
    BoundaryLayerColumns *blc = gf->getColumns();
    const bool existBL = !blc->_toFirst.empty();

    // Get orientation of BL and non-BL elements.
    // First, try to get normal to GFace from vertices.
    // If it fails, try to get normal to GFace from element barycenter
    int orientNonBL = 0, orientBL = existBL ? 0 : 1;
    getGFaceOrientation(gf, blc, existBL, true, orientNonBL, orientBL);
    if ((orientNonBL == 0) || (orientBL == 0))
      getGFaceOrientation(gf, blc, existBL, false, orientNonBL, orientBL);

    // Exit if could not determine orientation of both non-BL el. and BL el.
    if ((orientNonBL == 0) && (orientBL == 0)) {
      Msg::Warning("Could not orient mesh in face %d", gf->tag());
      return;
    }

    // Reverse BL and non-BL elements if needed
    if (existBL) { // If there is a BL, test BL/non-BL elements
      if ((orientNonBL == -1) || (orientBL == -1))
        for (unsigned int iEl = 0; iEl < gf->getNumMeshElements(); iEl++) {
          MElement *e = gf->getMeshElement(iEl);
          // If el. outside of BL...
          if (blc->_toFirst.find(e) == blc->_toFirst.end()) {
            // ... reverse if needed
            if (orientNonBL == -1) e->reverse();
          }
          else // If el. in BL
            // ... reverse if needed
            if (orientBL == -1) e->reverse();
        }
    }
    else // If no BL, reverse all elements if needed
      if (orientNonBL == -1)
        for (unsigned int iEl = 0; iEl < gf->getNumMeshElements(); iEl++)
          gf->getMeshElement(iEl)->reverse();
  }

  // Apply user-specified mesh orientation constraints
  if(gf->meshAttributes.reverseMesh)
    for(unsigned int k = 0; k < gf->getNumMeshElements(); k++)
      gf->getMeshElement(k)->reverse();
}
