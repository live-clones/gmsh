// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <sstream>
#include <stdlib.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GModelIO_GEO.h"
#include "OS.h"
#include "OpenFile.h"
#include "Numeric.h"
#include "ListUtils.h"
#include "gmshVertex.h"
#include "gmshFace.h"
#include "GFaceCompound.h"
#include "GEdgeCompound.h"
#include "GRegionCompound.h"
#include "gmshEdge.h"
#include "gmshRegion.h"
#include "Field.h"
#include "Context.h"

#if defined(HAVE_PARSER)
#include "Parser.h"
#endif

void GEO_Internals::_allocateAll()
{
  MaxPointNum = MaxLineNum = MaxLineLoopNum = MaxSurfaceNum = 0;
  MaxSurfaceLoopNum = MaxVolumeNum = MaxPhysicalNum = 0;
  Points = Tree_Create(sizeof(Vertex *), compareVertex);
  Curves = Tree_Create(sizeof(Curve *), compareCurve);
  EdgeLoops = Tree_Create(sizeof(EdgeLoop *), compareEdgeLoop);
  Surfaces = Tree_Create(sizeof(Surface *), compareSurface);
  SurfaceLoops = Tree_Create(sizeof(SurfaceLoop *), compareSurfaceLoop);
  Volumes = Tree_Create(sizeof(Volume *), compareVolume);
  LevelSets = Tree_Create(sizeof(LevelSet *), compareLevelSet);
  PhysicalGroups = List_Create(5, 5, sizeof(PhysicalGroup *));
}

void GEO_Internals::_freeAll()
{
  MaxPointNum = MaxLineNum = MaxLineLoopNum = MaxSurfaceNum = 0;
  MaxSurfaceLoopNum = MaxVolumeNum = MaxPhysicalNum = 0;
  Tree_Action(Points, Free_Vertex); Tree_Delete(Points);
  Tree_Action(Curves, Free_Curve); Tree_Delete(Curves);
  Tree_Action(EdgeLoops, Free_EdgeLoop); Tree_Delete(EdgeLoops);
  Tree_Action(Surfaces, Free_Surface); Tree_Delete(Surfaces);
  Tree_Action(SurfaceLoops, Free_SurfaceLoop); Tree_Delete(SurfaceLoops);
  Tree_Action(Volumes, Free_Volume); Tree_Delete(Volumes);
  Tree_Action(LevelSets, Free_LevelSet); Tree_Delete(LevelSets);
  List_Action(PhysicalGroups, Free_PhysicalGroup); List_Delete(PhysicalGroups);
}

void GEO_Internals::resetPhysicalGroups()
{
  List_Action(PhysicalGroups, Free_PhysicalGroup);
  List_Reset(PhysicalGroups);
}

void GEO_Internals::addVertex(int num, double x, double y, double z, double lc)
{
  if(FindPoint(num)){
    Msg::Error("GEO vertex with tag %d already exists", num);
    return;
  }
  Vertex *v = Create_Vertex(num, x, y, z, lc, 1.0);
  Tree_Add(Points, &v);
}

void GEO_Internals::addVertex(int num, double x, double y, gmshSurface *surface,
                              double lc)
{
  if(FindPoint(num)){
    Msg::Error("GEO vertex with tag %d already exists", num);
    return;
  }
  Vertex *v = Create_Vertex(num, x, y, surface, lc);
  Tree_Add(Points, &v);
}

void GEO_Internals::addLine(int num, int startTag, int endTag)
{
  std::vector<int> points;
  points.push_back(startTag);
  points.push_back(endTag);
  addLine(num, points);
}

void GEO_Internals::addLine(int num, std::vector<int> vertexTags)
{
  if(FindCurve(num)){
    Msg::Error("GEO edge with tag %d already exists", num);
    return;
  }
  List_T *temp = List_Create(2, 2, sizeof(int));
  for(unsigned int i = 0; i < vertexTags.size(); i++)
    List_Add(temp, &vertexTags[i]);
  Curve *c = Create_Curve(num, MSH_SEGM_LINE, 1, temp, NULL, -1, -1, 0., 1.);
  Tree_Add(Curves, &c);
  CreateReversedCurve(c);
  List_Delete(temp);
}

void GEO_Internals::addCircleArc(int num, int startTag, int centerTag, int endTag,
                                 double nx, double ny, double nz)
{
  if(FindCurve(num)){
    Msg::Error("GEO edge with tag %d already exists", num);
    return;
  }
  List_T *temp = List_Create(3, 2, sizeof(int));
  List_Add(temp, &startTag);
  List_Add(temp, &centerTag);
  List_Add(temp, &endTag);
  Curve *c = Create_Curve(num, MSH_SEGM_CIRC, 2, temp, NULL, -1, -1, 0., 1.);
  if(nx || ny || nz){
    c->Circle.n[0] = nx;
    c->Circle.n[1] = ny;
    c->Circle.n[2] = nz;
    End_Curve(c);
  }
  Tree_Add(Curves, &c);
  Curve *rc = CreateReversedCurve(c);
  if(nx || ny || nz){
    rc->Circle.n[0] = nx;
    rc->Circle.n[1] = ny;
    rc->Circle.n[2] = nz;
    End_Curve(rc);
  }
  List_Delete(temp);
}

void GEO_Internals::addEllipseArc(int num, int startTag, int centerTag, int majorTag,
                                  int endTag, double nx, double ny, double nz)
{
  if(FindCurve(num)){
    Msg::Error("GEO edge with tag %d already exists", num);
    return;
  }
  List_T *temp = List_Create(3, 2, sizeof(int));
  List_Add(temp, &startTag);
  List_Add(temp, &centerTag);
  List_Add(temp, &majorTag);
  List_Add(temp, &endTag);
  Curve *c = Create_Curve(num, MSH_SEGM_ELLI, 2, temp, NULL, -1, -1, 0., 1.);
  if(nx || ny || nz){
    c->Circle.n[0] = nx;
    c->Circle.n[1] = ny;
    c->Circle.n[2] = nz;
    End_Curve(c);
  }
  Tree_Add(Curves, &c);
  Curve *rc = CreateReversedCurve(c);
  if(nx || ny || nz){
    rc->Circle.n[0] = nx;
    rc->Circle.n[1] = ny;
    rc->Circle.n[2] = nz;
    End_Curve(rc);
  }
  List_Delete(temp);
}

void GEO_Internals::addSpline(int num, std::vector<int> vertexTags)
{
  if(FindCurve(num)){
    Msg::Error("GEO edge with tag %d already exists", num);
    return;
  }
  List_T *temp = List_Create(2, 2, sizeof(int));
  for(unsigned int i = 0; i < vertexTags.size(); i++)
    List_Add(temp, &vertexTags[i]);
  Curve *c = Create_Curve(num, MSH_SEGM_SPLN, 3, temp, NULL, -1, -1, 0., 1.);
  Tree_Add(Curves, &c);
  CreateReversedCurve(c);
  List_Delete(temp);
}

void GEO_Internals::addBSpline(int num, std::vector<int> vertexTags)
{
  if(FindCurve(num)){
    Msg::Error("GEO edge with tag %d already exists", num);
    return;
  }
  List_T *temp = List_Create(2, 2, sizeof(int));
  for(unsigned int i = 0; i < vertexTags.size(); i++)
    List_Add(temp, &vertexTags[i]);
  Curve *c = Create_Curve(num, MSH_SEGM_BSPLN, 2, temp, NULL, -1, -1, 0., 1.);
  Tree_Add(Curves, &c);
  CreateReversedCurve(c);
  List_Delete(temp);
}

void GEO_Internals::addBezier(int num, std::vector<int> vertexTags)
{
  if(FindCurve(num)){
    Msg::Error("GEO edge with tag %d already exists", num);
    return;
  }
  List_T *temp = List_Create(2, 2, sizeof(int));
  for(unsigned int i = 0; i < vertexTags.size(); i++)
    List_Add(temp, &vertexTags[i]);
  Curve *c = Create_Curve(num, MSH_SEGM_BEZIER, 2, temp, NULL, -1, -1, 0., 1.);
  Tree_Add(Curves, &c);
  CreateReversedCurve(c);
  List_Delete(temp);
}

void GEO_Internals::addNurbs(int num, std::vector<int> vertexTags,
                             std::vector<double> knots)
{
  if(FindCurve(num)){
    Msg::Error("GEO edge with tag %d already exists", num);
    return;
  }
  int order = knots.size() - vertexTags.size() - 1;
  List_T *temp = List_Create(2, 2, sizeof(int));
  for(unsigned int i = 0; i < vertexTags.size(); i++)
    List_Add(temp, &vertexTags[i]);
  List_T *knotsList = List_Create(2, 2, sizeof(double));
  for(unsigned int i = 0; i < knots.size(); i++)
    List_Add(knotsList, &knots[i]);
  Curve *c = Create_Curve(num, MSH_SEGM_NURBS, order, temp, knotsList, -1, -1, 0., 1.);
  Tree_Add(Curves, &c);
  CreateReversedCurve(c);
  List_Delete(temp);
}

void GEO_Internals::addCompoundLine(int num, std::vector<int> edgeTags)
{
  if(FindCurve(num)){
    Msg::Error("GEO edge with tag %d already exists", num);
    return;
  }

  Curve *c = Create_Curve(num, MSH_SEGM_COMPOUND, 1, NULL, NULL, -1, -1, 0., 1.);
  c->compound = edgeTags;
  End_Curve(c);
  Tree_Add(Curves, &c);
  CreateReversedCurve(c);
}

void GEO_Internals::addLineLoop(int num, std::vector<int> edgeTags)
{
  if(FindEdgeLoop(num)){
    Msg::Error("GEO line loop with tag %d already exists", num);
    return;
  }
  List_T *temp = List_Create(2, 2, sizeof(int));
  for(unsigned int i = 0; i < edgeTags.size(); i++)
    List_Add(temp, &edgeTags[i]);
  sortEdgesInLoop(num, temp);
  EdgeLoop *l = Create_EdgeLoop(num, temp);
  Tree_Add(EdgeLoops, &l);
  List_Delete(temp);
}

void GEO_Internals::addPlaneSurface(int num, std::vector<int> wireTags)
{
  if(FindSurface(num)){
    Msg::Error("GEO face with tag %d already exists", num);
    return;
  }
  if(wireTags.empty()){
    Msg::Error("Plane surface requires at least one line loop");
    return;
  }
  List_T *temp = List_Create(2, 2, sizeof(int));
  for(unsigned int i = 0; i < wireTags.size(); i++)
    List_Add(temp, &wireTags[i]);
  Surface *s = Create_Surface(num, MSH_SURF_PLAN);
  setSurfaceGeneratrices(s, temp);
  List_Delete(temp);
  End_Surface(s);
  Tree_Add(Surfaces, &s);
}

void GEO_Internals::addSurfaceFilling(int num, std::vector<int> wireTags,
                                      int sphereCenterTag)
{
  if(FindSurface(num)){
    Msg::Error("GEO face with tag %d already exists", num);
    return;
  }
  if(wireTags.empty()){
    Msg::Error("Face requires at least one line loop");
    return;
  }
  int ll = (int)std::abs(wireTags[0]);
  EdgeLoop *el = FindEdgeLoop(ll);
  if(!el){
    Msg::Error("Unknown line loop %d", ll);
    return;
  }
  int j = List_Nbr(el->Curves), type = MSH_SURF_PLAN;
  if(j == 4)
    type = MSH_SURF_REGL;
  else if(j == 3)
    type = MSH_SURF_TRIC;
  else
    Msg::Error("Wrong definition of face %d: %d borders instead of 3 or 4",
               num, j);
  List_T *temp = List_Create(2, 2, sizeof(int));
  for(unsigned int i = 0; i < wireTags.size(); i++)
    List_Add(temp, &wireTags[i]);
  Surface *s = Create_Surface(num, type);
  setSurfaceGeneratrices(s, temp);
  List_Delete(temp);
  End_Surface(s);
  if(sphereCenterTag >= 0){
    s->InSphereCenter = FindPoint(sphereCenterTag);
    if(!s->InSphereCenter)
      Msg::Error("Unknown sphere center vertex %d", sphereCenterTag);
  }
  Tree_Add(Surfaces, &s);
}

void GEO_Internals::addCompoundSurface(int num, std::vector<int> faceTags,
                                       std::vector<int> edgeTags[4])
{
  if(FindSurface(num)){
    Msg::Error("GEO face with tag %d already exists", num);
    return;
  }

  Surface *s = Create_Surface(num, MSH_SURF_COMPOUND);
  s->compound = faceTags;
  if(edgeTags){
    for(int i = 0; i < 4; i++)
      s->compoundBoundary[i] = edgeTags[i];
  }
  setSurfaceGeneratrices(s, 0);
  Tree_Add(Surfaces, &s);
}

void GEO_Internals::addSurfaceLoop(int num, std::vector<int> faceTags)
{
  if(FindSurfaceLoop(num)){
    Msg::Error("GEO surface loop with tag %d already exists", num);
    return;
  }

  List_T *temp = List_Create(2, 2, sizeof(int));
  for(unsigned int i = 0; i < faceTags.size(); i++)
    List_Add(temp, &faceTags[i]);
  SurfaceLoop *l = Create_SurfaceLoop(num, temp);
  Tree_Add(SurfaceLoops, &l);
  List_Delete(temp);
}

void GEO_Internals::addVolume(int num, std::vector<int> shellTags)
{
  if(FindVolume(num)){
    Msg::Error("GEO region with tag %d already exists", num);
    return;
  }

  List_T *temp = List_Create(2, 2, sizeof(int));
  for(unsigned int i = 0; i < shellTags.size(); i++)
    List_Add(temp, &shellTags[i]);
  Volume *v = Create_Volume(num, MSH_VOLUME);
  setVolumeSurfaces(v, temp);
  List_Delete(temp);
  Tree_Add(Volumes, &v);
}

void GEO_Internals::addCompoundVolume(int num, std::vector<int> regionTags)
{
  if(FindVolume(num)){
    Msg::Error("GEO region with tag %d already exists", num);
    return;
  }

  Volume *v = Create_Volume(num, MSH_VOLUME_COMPOUND);
  v->compound = regionTags;
  Tree_Add(Volumes, &v);
}

void GEO_Internals::setCompoundMesh(int dim, std::vector<int> tags)
{
  meshCompounds.insert(std::make_pair(dim, tags));
}

void GEO_Internals::synchronize(GModel *model)
{
  if(Tree_Nbr(Points)) {
    List_T *points = Tree2List(Points);
    for(int i = 0; i < List_Nbr(points); i++){
      Vertex *p;
      List_Read(points, i, &p);
      GVertex *v = model->getVertexByTag(p->Num);
      if(!v){
        v = new gmshVertex(model, p);
        model->add(v);
      }
      else{
        v->resetMeshAttributes();
      }
      if(!p->Visible) v->setVisibility(0);
    }
    List_Delete(points);
  }
  if(Tree_Nbr(Curves)) {
    List_T *curves = Tree2List(Curves);
    // generate all curves except compounds
    for(int i = 0; i < List_Nbr(curves); i++){
      Curve *c;
      List_Read(curves, i, &c);
      if(c->Num >= 0){
        GEdge *e = model->getEdgeByTag(c->Num);
        if(!e && c->Typ == MSH_SEGM_COMPOUND){
          Msg::Debug("Postpone creation of compound edge %d until all others "
                     "have been created", c->Num);
        }
        else if(!e && c->beg && c->end){
          e = new gmshEdge(model, c,
                           model->getVertexByTag(c->beg->Num),
                           model->getVertexByTag(c->end->Num));
          model->add(e);
        }
        else if(!e){
          e = new gmshEdge(model, c, 0, 0);
          model->add(e);
        }
        else{
          e->resetMeshAttributes();
        }

        if(!c->Visible) e->setVisibility(0);
        if(c->Color.type) e->setColor(c->Color.mesh);
        if(c->degenerated) {
          e->setTooSmall(true);
        }
      }
    }
    // now generate the compound curves
    for(int i = 0; i < List_Nbr(curves); i++){
      Curve *c;
      List_Read(curves, i, &c);
      if(c->Num >= 0){
        GEdge *e = model->getEdgeByTag(c->Num);
        if(!e && c->Typ == MSH_SEGM_COMPOUND){
          std::vector<GEdge*> comp;
          for(unsigned int j = 0; j < c->compound.size(); j++){
            GEdge *ge = model->getEdgeByTag(c->compound[j]);
            if(ge) comp.push_back(ge);
          }
          e = new GEdgeCompound(model, c->Num, comp);
          e->meshAttributes.method = c->Method;
          e->meshAttributes.nbPointsTransfinite = c->nbPointsTransfinite;
          e->meshAttributes.typeTransfinite = c->typeTransfinite;
          e->meshAttributes.coeffTransfinite = c->coeffTransfinite;
          e->meshAttributes.extrude = c->Extrude;
          e->meshAttributes.reverseMesh = c->ReverseMesh;
          model->add(e);
        }
        if(!c->Visible) e->setVisibility(0);
        if(c->Color.type) e->setColor(c->Color.mesh);
        if(c->degenerated) {
          e->setTooSmall(true);
        }
      }
    }
    List_Delete(curves);
  }
  if(Tree_Nbr(Surfaces)) {
    List_T *surfaces = Tree2List(Surfaces);
    for(int i = 0; i < List_Nbr(surfaces); i++){
      Surface *s;
      List_Read(surfaces, i, &s);
      GFace *f = model->getFaceByTag(s->Num);
      if(!f && s->Typ == MSH_SURF_COMPOUND){
        std::list<GFace*> comp;
        for(unsigned int j = 0; j < s->compound.size(); j++){
          GFace *gf = model->getFaceByTag(s->compound[j]);
          if(gf)
            comp.push_back(gf);
        }
        std::list<GEdge*> b[4];
        for(int j = 0; j < 4; j++){
          for(unsigned int k = 0; k < s->compoundBoundary[j].size(); k++){
            GEdge *ge = model->getEdgeByTag(s->compoundBoundary[j][k]);
            if(ge) b[j].push_back(ge);
          }
        }
        int param = CTX::instance()->mesh.remeshParam;
        GFaceCompound::typeOfCompound typ = GFaceCompound::HARMONIC_CIRCLE;
        if (param == 1) typ =  GFaceCompound::CONFORMAL_SPECTRAL;
        if (param == 2) typ =  GFaceCompound::RADIAL_BASIS;
        if (param == 3) typ =  GFaceCompound::HARMONIC_PLANE;
        if (param == 4) typ =  GFaceCompound::CONVEX_CIRCLE;
        if (param == 5) typ =  GFaceCompound::CONVEX_PLANE;
        if (param == 6) typ =  GFaceCompound::HARMONIC_SQUARE;
        if (param == 7) typ =  GFaceCompound::CONFORMAL_FE;
        int algo = CTX::instance()->mesh.remeshAlgo;
        f = new GFaceCompound(model, s->Num, comp, b[0], b[1], b[2], b[3], typ, algo);
        f->meshAttributes.recombine = s->Recombine;
        f->meshAttributes.recombineAngle = s->RecombineAngle;
        f->meshAttributes.method = s->Method;
        f->meshAttributes.extrude = s->Extrude;
        // transfinite import Added by Trevor Strickler.  This helps when
        // experimenting to create compounds from transfinite surfs. Not having
        // it does not break anything Gmsh *officially* does right now, but
        // maybe it was left out by mistake? and could cause problems later?
        f->meshAttributes.transfiniteArrangement = s->Recombine_Dir;
        f->meshAttributes.corners.clear();
        for(int i = 0; i < List_Nbr(s->TrsfPoints); i++){
          Vertex *corn;
          List_Read(s->TrsfPoints, i, &corn);
          GVertex *gv = f->model()->getVertexByTag(corn->Num);
          if(gv)
            f->meshAttributes.corners.push_back(gv);
          else
            Msg::Error("Unknown vertex %d in transfinite attributes", corn->Num);
        }
        model->add(f);
        if(s->EmbeddedCurves){
          for(int i = 0; i < List_Nbr(s->EmbeddedCurves); i++){
            Curve *c;
            List_Read(s->EmbeddedCurves, i, &c);
            GEdge *e = model->getEdgeByTag(abs(c->Num));
            if(e)
              f->addEmbeddedEdge(e);
            else
              Msg::Error("Unknown curve %d", c->Num);
          }
        }
        if(s->EmbeddedPoints){
          for(int i = 0; i < List_Nbr(s->EmbeddedPoints); i++){
            Vertex *v;
            List_Read(s->EmbeddedPoints, i, &v);
            GVertex *gv = model->getVertexByTag(v->Num);
            if(gv)
              f->addEmbeddedVertex(gv);
            else
              Msg::Error("Unknown point %d", v->Num);
          }
        }
      }
      else if(!f){
        f = new gmshFace(model, s);
        model->add(f);
      }
      else{
        if(s->Typ == MSH_SURF_PLAN)
          f->computeMeanPlane(); // recompute in case geom has changed
        f->resetMeshAttributes();
      }
      if(!s->Visible) f->setVisibility(0);
      if(s->Color.type) f->setColor(s->Color.mesh);
    }
    List_Delete(surfaces);
  }
  if(Tree_Nbr(Volumes)) {
    List_T *volumes = Tree2List(Volumes);
    for(int i = 0; i < List_Nbr(volumes); i++){
      Volume *v;
      List_Read(volumes, i, &v);
      GRegion *r = model->getRegionByTag(v->Num);
      if(!r && v->Typ == MSH_VOLUME_COMPOUND){
        std::vector<GRegion*> comp;
        for(unsigned int j = 0; j < v->compound.size(); j++){
          GRegion *gr = model->getRegionByTag(v->compound[j]);
          if(gr) comp.push_back(gr);
        }
        r = new GRegionCompound(model, v->Num, comp);
	model->add(r);
      }
      else if(!r){
        r = new gmshRegion(model, v);
        model->add(r);
      }
      else{
        r->resetMeshAttributes();
      }

      if(v->EmbeddedSurfaces){
	for(int i = 0; i < List_Nbr(v->EmbeddedSurfaces); i++){
	  Surface *s;
	  List_Read(v->EmbeddedSurfaces, i, &s);
	  GFace *gf = model->getFaceByTag(abs(s->Num));
	  if(gf)
	    r->addEmbeddedFace(gf);
	  else
	    Msg::Error("Unknown surface %d", s->Num);
	}
      }
      if(v->EmbeddedCurves){
	for(int i = 0; i < List_Nbr(v->EmbeddedCurves); i++){
	  Curve *c;
	  List_Read(v->EmbeddedCurves, i, &c);
	  GEdge *ge = model->getEdgeByTag(abs(c->Num));
	  if(ge)
	    r->addEmbeddedEdge(ge);
	  else
	    Msg::Error("Unknown curve %d", c->Num);
	}
      }
      if(v->EmbeddedPoints){
        for(int i = 0; i < List_Nbr(v->EmbeddedPoints); i++){
          Vertex *c;
          List_Read(v->EmbeddedPoints, i, &c);
          GVertex *gv = model->getVertexByTag(c->Num);
          if(gv)
            r->addEmbeddedVertex(gv);
          else
            Msg::Error("Unknown point %d", c->Num);
        }
      }
      if(!v->Visible) r->setVisibility(0);
      if(v->Color.type) r->setColor(v->Color.mesh);
    }
    List_Delete(volumes);
  }
  for(int i = 0; i < List_Nbr(PhysicalGroups); i++){
    PhysicalGroup *p;
    List_Read(PhysicalGroups, i, &p);
    for(int j = 0; j < List_Nbr(p->Entities); j++){
      int num;
      List_Read(p->Entities, j, &num);
      GEntity *ge = 0;
      int tag = CTX::instance()->geom.orientedPhysicals ? abs(num) : num;
      switch(p->Typ){
        case MSH_PHYSICAL_POINT:   ge = model->getVertexByTag(tag); break;
        case MSH_PHYSICAL_LINE:    ge = model->getEdgeByTag(tag); break;
        case MSH_PHYSICAL_SURFACE: ge = model->getFaceByTag(tag); break;
        case MSH_PHYSICAL_VOLUME:  ge = model->getRegionByTag(tag); break;
      }
      int pnum = CTX::instance()->geom.orientedPhysicals ?
        (gmsh_sign(num) * p->Num) : p->Num;
      if(ge && std::find(ge->physicals.begin(), ge->physicals.end(), pnum) ==
         ge->physicals.end())
        ge->physicals.push_back(pnum);
    }
  }

  std::map<int, GEO_Internals::MasterEdge>::iterator peIter = periodicEdges.begin();
  for (; peIter != periodicEdges.end(); ++peIter) {
    int iTarget = peIter->first;
    GEO_Internals::MasterEdge& me = peIter->second;
    int iSource = me.tag;
    GEdge* target = model->getEdgeByTag(abs(iTarget));
    GEdge* source = model->getEdgeByTag(abs(iSource));
    if(!target)
      Msg::Error("Unknown target line for periodic connection from %d to %d",
                 iTarget, iSource);
    if(!source)
      Msg::Error("Unknown source line for periodic connection from %d to %d",
                 iTarget, iSource);
    if(target && source){
      if(me.affineTransform.size() == 16)
        target->setMeshMaster(source, me.affineTransform);
      else
        target->setMeshMaster(source, me.tag > 0 ? 1 : -1);
    }
  }

  std::map<int, GEO_Internals::MasterFace>::iterator pfIter = periodicFaces.begin();
  for (; pfIter != periodicFaces.end(); ++pfIter) {
    int iTarget = pfIter->first;
    GEO_Internals::MasterFace& mf = pfIter->second;
    int iSource = mf.tag;
    GFace* target = model->getFaceByTag(iTarget);
    GFace* source = model->getFaceByTag(iSource);
    if(!target)
      Msg::Error("Unknown target surface for periodic connection from %d to %d",
                 iTarget, iSource);
    if(!source)
      Msg::Error("Unknown source surface for periodic connection from %d to %d",
                 iTarget, iSource);
    if(target && source){
      if(mf.affineTransform.size() == 16)
        target->setMeshMaster(source,mf.affineTransform);
      else
        target->setMeshMaster(source,mf.edgeCounterparts);
    }
  }

  for (std::multimap<int, std::vector<int> >::iterator it = meshCompounds.begin();
       it != meshCompounds.end(); ++it){
    int dim = it->first;
    std::vector<int> compound = it->second;
    std::vector<GEntity*> ents;
    for (unsigned int i=0;i<compound.size();i++){
      int tag = compound[i];
      GEntity *ent = NULL;
      switch(dim) {
      case 1: ent = model->getEdgeByTag(tag); break;
      case 2: ent = model->getFaceByTag(tag); break;
      case 3: ent = model->getRegionByTag(tag); break;
      default : Msg::Error("compound mesh with dimension %d",dim);
      }
      if(ent) ents.push_back(ent);
    }
    for (unsigned int i=0;i<ents.size();i++){
      ents[i]->_compound = ents;
    }
  }

  Msg::Debug("Gmsh model (GModel) imported:");
  Msg::Debug("%d Vertices", model->getNumVertices());
  Msg::Debug("%d Edges", model->getNumEdges());
  Msg::Debug("%d Faces", model->getNumFaces());
  Msg::Debug("%d Regions", model->getNumRegions());
}

gmshSurface *GEO_Internals::newGeometrySphere(int num, int centerTag, int pointTag)
{
  Vertex *v1 = FindPoint(centerTag);
  if(!v1){
    Msg::Error("Unknown sphere center vertex %d", centerTag);
    return 0;
  }
  Vertex *v2 = FindPoint(pointTag);
  if(!v2){
    Msg::Error("Unknown sphere vertex %d", pointTag);
    return 0;
  }
  return gmshSphere::NewSphere
    (num, v1->Pos.X, v1->Pos.Y, v1->Pos.Z,
     sqrt((v2->Pos.X - v1->Pos.X) * (v2->Pos.X - v1->Pos.X) +
          (v2->Pos.Y - v1->Pos.Y) * (v2->Pos.Y - v1->Pos.Y) +
          (v2->Pos.Z - v1->Pos.Z) * (v2->Pos.Z - v1->Pos.Z)));
}

gmshSurface *GEO_Internals::newGeometryPolarSphere(int num, int centerTag, int pointTag)
{
  Vertex *v1 = FindPoint(centerTag);
  if(!v1){
    Msg::Error("Unknown polar sphere center vertex %d", centerTag);
    return 0;
  }
  Vertex *v2 = FindPoint(pointTag);
  if(!v2){
    Msg::Error("Unknown polar sphere vertex %d", pointTag);
    return 0;
  }
  return gmshPolarSphere::NewPolarSphere
    (num, v1->Pos.X, v1->Pos.Y, v1->Pos.Z,
     sqrt((v2->Pos.X - v1->Pos.X) * (v2->Pos.X - v1->Pos.X) +
          (v2->Pos.Y - v1->Pos.Y) * (v2->Pos.Y - v1->Pos.Y) +
          (v2->Pos.Z - v1->Pos.Z) * (v2->Pos.Z - v1->Pos.Z)));
}

// GModel interface

void GModel::_createGEOInternals()
{
  _geo_internals = new GEO_Internals;
}

void GModel::_deleteGEOInternals()
{
  if(_geo_internals) delete _geo_internals;
  _geo_internals = 0;
}

int GModel::importGEOInternals()
{
  if(!_geo_internals) return 0;
  _geo_internals->synchronize(this);
  return 1;
}

int GModel::readGEO(const std::string &name)
{
  ParseFile(name, true);
  int imported = GModel::current()->importGEOInternals();

  // FIXME: temp
  GModel::current()->importOCCInternals();
  return imported;
}

int GModel::exportDiscreteGEOInternals()
{
  int maxv = 1; // FIXME: temporary - see TODO below

  if(_geo_internals){
    maxv = _geo_internals->MaxVolumeNum;
    delete _geo_internals;
  }
  _geo_internals = new GEO_Internals;

  for(viter it = firstVertex(); it != lastVertex(); it++){
    Vertex *v = Create_Vertex((*it)->tag(), (*it)->x(), (*it)->y(), (*it)->z(),
        (*it)->prescribedMeshSizeAtVertex(), 1.0);
    Tree_Add(_geo_internals->Points, &v);
  }

  for(eiter it = firstEdge(); it != lastEdge(); it++){
    if((*it)->geomType() == GEntity::DiscreteCurve){
      Curve *c = Create_Curve((*it)->tag(), MSH_SEGM_DISCRETE, 1,
          NULL, NULL, -1, -1, 0., 1.);
      List_T *points = Tree2List(_geo_internals->Points);
      GVertex *gvb = (*it)->getBeginVertex();
      GVertex *gve = (*it)->getEndVertex();
      int nb = 2 ;
      c->Control_Points = List_Create(nb, 1, sizeof(Vertex *));
      for(int i = 0; i < List_Nbr(points); i++) {
        Vertex *v;
        List_Read(points, i, &v);
        if (v->Num == gvb->tag()) {
          List_Add(c->Control_Points, &v);
          c->beg = v;
        }
        if (v->Num == gve->tag()) {
          List_Add(c->Control_Points, &v);
          c->end = v;
        }
      }
      End_Curve(c);
      Tree_Add(_geo_internals->Curves, &c);
      CreateReversedCurve(c);
      List_Delete(points);
    }
  }

  for(fiter it = firstFace(); it != lastFace(); it++){
    if((*it)->geomType() == GEntity::DiscreteSurface){
      Surface *s = Create_Surface((*it)->tag(), MSH_SURF_DISCRETE);
      std::list<GEdge*> edges = (*it)->edges();
      s->Generatrices = List_Create(edges.size(), 1, sizeof(Curve *));
      List_T *curves = Tree2List(_geo_internals->Curves);
      Curve *c;
      for(std::list<GEdge*>::iterator ite = edges.begin(); ite != edges.end(); ite++){
        for(int i = 0; i < List_Nbr(curves); i++) {
          List_Read(curves, i, &c);
          if (c->Num == (*ite)->tag()) {
            List_Add(s->Generatrices, &c);
          }
        }
      }
      Tree_Add(_geo_internals->Surfaces, &s);
      List_Delete(curves);
    }
  }

  // TODO: create Volumes from discreteRegions ; meanwhile, keep track of
  // maximum volume num so that we don't break later operations:
  _geo_internals->MaxVolumeNum = maxv;

  Msg::Debug("Geo internal model has:");
  Msg::Debug("%d Vertices", Tree_Nbr(_geo_internals->Points));
  Msg::Debug("%d Edges", Tree_Nbr(_geo_internals->Curves));
  Msg::Debug("%d Faces", Tree_Nbr(_geo_internals->Surfaces));

  return 1;
}

class writeFieldOptionGEO {
 private :
  FILE *geo;
  Field *field;
 public :
  writeFieldOptionGEO(FILE *fp, Field *_field)
  {
    geo = fp ? fp : stdout;
    field = _field;
  }
  void operator() (std::pair<std::string, FieldOption *> it)
  {
    std::string v;
    it.second->getTextRepresentation(v);
    fprintf(geo, "Field[%i].%s = %s;\n", field->id, it.first.c_str(), v.c_str());
  }
};

class writeFieldGEO {
  private :
    FILE *geo;
  public :
    writeFieldGEO(FILE *fp) { geo = fp ? fp : stdout; }
    void operator() (std::pair<const int, Field *> it)
    {
      fprintf(geo, "Field[%i] = %s;\n", it.first, it.second->getName());
      std::for_each(it.second->options.begin(), it.second->options.end(),
          writeFieldOptionGEO(geo, it.second));
    }
};

class writePhysicalGroupGEO {
  private :
    FILE *geo;
    int dim;
    bool printLabels;
    std::map<int, std::string> &oldLabels;
    std::map<std::pair<int, int>, std::string> &newLabels;
  public :
    writePhysicalGroupGEO(FILE *fp, int i, bool labels,
        std::map<int, std::string> &o,
        std::map<std::pair<int, int>, std::string> &n)
      : dim(i), printLabels(labels), oldLabels(o), newLabels(n)
    {
      geo = fp ? fp : stdout;
    }
    void operator () (std::pair<const int, std::vector<GEntity *> > &g)
    {
      std::string oldName, newName;
      if(printLabels){
        if(newLabels.count(std::pair<int, int>(dim, g.first))) {
          newName = newLabels[std::pair<int, int>(dim, g.first)];
        }
        else if(oldLabels.count(g.first)) {
          oldName = oldLabels[g.first];
          fprintf(geo, "%s = %d;\n", oldName.c_str(), g.first);
        }
      }

      switch (dim) {
        case 0: fprintf(geo, "Physical Point"); break;
        case 1: fprintf(geo, "Physical Line"); break;
        case 2: fprintf(geo, "Physical Surface"); break;
        case 3: fprintf(geo, "Physical Volume"); break;
      }

      if(oldName.size())
        fprintf(geo, "(%s) = {", oldName.c_str());
      else if(newName.size())
        fprintf(geo, "(\"%s\") = {", newName.c_str());
      else
        fprintf(geo, "(%d) = {", g.first);
      for(unsigned int i = 0; i < g.second.size(); i++) {
        if(i) fprintf(geo, ", ");
        fprintf(geo, "%d", g.second[i]->tag());
      }
      fprintf(geo, "};\n");
    }
};

static bool skipRegion(GRegion *gr)
{
  if(gr->physicals.size()) return false;
  return true;
}

static bool skipFace(GFace *gf)
{
  if(gf->physicals.size()) return false;
  std::list<GRegion*> regions(gf->regions());
  for(std::list<GRegion*>::iterator itr = regions.begin(); itr != regions.end(); itr++){
    if(!skipRegion(*itr)) return false;
  }
  return true;
}

static bool skipEdge(GEdge *ge)
{
  if(ge->physicals.size()) return false;
  std::list<GFace*> faces(ge->faces());
  for(std::list<GFace*>::iterator itf = faces.begin(); itf != faces.end(); itf++){
    if(!skipFace(*itf)) return false;
  }
  return true;
}

static bool skipVertex(GVertex *gv)
{
  if(gv->physicals.size()) return false;
  std::list<GEdge*> edges(gv->edges());
  for(std::list<GEdge*>::iterator ite = edges.begin(); ite != edges.end(); ite++){
    if(!skipEdge(*ite)) return false;
  }
  return true;
}

int GModel::writeGEO(const std::string &name, bool printLabels, bool onlyPhysicals)
{
  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp){
    Msg::Error("Could not open file '%s'", name.c_str());
    return 0;
  }

  std::map<double, std::string> meshSizeParameters;
  int cpt = 0;
  for(viter it = firstVertex(); it != lastVertex(); it++){
    double val = (*it)->prescribedMeshSizeAtVertex();
    if(meshSizeParameters.find(val) == meshSizeParameters.end()){
      std::ostringstream paramName;
      paramName << "cl__" << ++cpt;
      fprintf(fp, "%s = %.16g;\n", paramName.str().c_str(), val);
      meshSizeParameters.insert(std::make_pair(val, paramName.str()));
    }
  }

  for(viter it = firstVertex(); it != lastVertex(); it++){
    double val = (*it)->prescribedMeshSizeAtVertex();
    if(!onlyPhysicals || !skipVertex(*it))
      (*it)->writeGEO(fp, meshSizeParameters[val]);
  }
  for(eiter it = firstEdge(); it != lastEdge(); it++){
    if(!onlyPhysicals || !skipEdge(*it))
      (*it)->writeGEO(fp);
  }
  for(fiter it = firstFace(); it != lastFace(); it++){
    if(!onlyPhysicals || !skipFace(*it))
      (*it)->writeGEO(fp);
  }
  for(riter it = firstRegion(); it != lastRegion(); it++){
    if(!onlyPhysicals || !skipRegion(*it))
      (*it)->writeGEO(fp);
  }

  std::map<int, std::string> labels;
#if defined(HAVE_PARSER)
  // get "old-style" labels from parser
  for(std::map<std::string, gmsh_yysymbol>::iterator it = gmsh_yysymbols.begin();
      it != gmsh_yysymbols.end(); ++it)
    for(unsigned int i = 0; i < it->second.value.size(); i++)
      labels[(int)it->second.value[i]] = it->first;
#endif

  std::map<int, std::vector<GEntity*> > groups[4];
  getPhysicalGroups(groups);
  for(int i = 0; i < 4; i++)
    std::for_each(groups[i].begin(), groups[i].end(),
        writePhysicalGroupGEO(fp, i, printLabels, labels, physicalNames));

  std::for_each(getFields()->begin(), getFields()->end(), writeFieldGEO(fp));
  if(getFields()->getBackgroundField() > 0)
    fprintf(fp, "Background Field = %i;\n", getFields()->getBackgroundField());

  fclose(fp);
  return 1;
}
