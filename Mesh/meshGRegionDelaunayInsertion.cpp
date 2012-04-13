// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <set>
#include <map>
#include <algorithm>
#include "GmshMessage.h"
#include "robustPredicates.h"
#include "OS.h"
#include "BackgroundMesh.h"
#include "meshGRegion.h"
#include "meshGRegionLocalMeshMod.h"
#include "meshGRegionDelaunayInsertion.h"
#include "GModel.h"
#include "GRegion.h"
#include "MTriangle.h"
#include "Numeric.h"
#include "Context.h"

int MTet4::radiusNorm = 2;
static double LIMIT_ = 1;


static bool isActive(MTet4 *t, double limit_, int &active)
{
  if (t->isDeleted()) return false;
  for (active = 0; active < 4; active++){
    MTet4 *neigh = t->getNeigh(active);
    if (!neigh || (neigh->getRadius() < limit_ && neigh->getRadius() > 0)) {
      return true;
    }
  }
  return false;
}



int MTet4::inCircumSphere(const double *p) const
{
  double pa[3] = {base->getVertex(0)->x(), 
                  base->getVertex(0)->y(), 
                  base->getVertex(0)->z()};
  double pb[3] = {base->getVertex(1)->x(), 
                  base->getVertex(1)->y(),
                  base->getVertex(1)->z()};
  double pc[3] = {base->getVertex(2)->x(),
                  base->getVertex(2)->y(), 
                  base->getVertex(2)->z()};
  double pd[3] = {base->getVertex(3)->x(),
                  base->getVertex(3)->y(),
                  base->getVertex(3)->z()};
  double result = robustPredicates::insphere(pa, pb, pc, pd, (double*)p) * 
    robustPredicates::orient3d(pa, pb, pc, pd);
  return (result > 0) ? 1 : 0;
}

static int faces[4][3] = {{0,1,2}, {0,2,3}, {0,1,3}, {1,2,3}};

struct faceXtet{
  MVertex *v[3];
  MTet4 *t1;
  int i1;
  faceXtet(MTet4 *_t, int iFac) : t1(_t), i1(iFac)
  {
    v[0] = t1->tet()->getVertex(faces[iFac][0]);
    v[1] = t1->tet()->getVertex(faces[iFac][1]);
    v[2] = t1->tet()->getVertex(faces[iFac][2]);
    std::sort(v, v + 3);
  }
  inline bool operator < (const faceXtet & other) const
  {
    if (v[0] < other.v[0]) return true;
    if (v[0] > other.v[0]) return false;
    if (v[1] < other.v[1]) return true;
    if (v[1] > other.v[1]) return false;
    if (v[2] < other.v[2]) return true;
    return false;
  }
};

template <class ITER>
void connectTets(ITER beg, ITER end)
{
  std::set<faceXtet> conn;
  while (beg != end){
    if (!(*beg)->isDeleted()){
      for (int i = 0; i < 4; i++){
        faceXtet fxt(*beg, i);
        std::set<faceXtet>::iterator found = conn.find(fxt);
        if (found == conn.end())
          conn.insert(fxt);
        else if (found->t1 != *beg){
          found->t1->setNeigh(found->i1, *beg);
          (*beg)->setNeigh(i, found->t1);
        }
      }
    }
    ++beg;
  }
}

static void updateActiveFaces(MTet4 *t, double limit_, std::set<MFace,Less_Face> &front)
{
  if (t->isDeleted()) return;
  for (int active = 0; active < 4; active++){
    MTet4 *neigh = t->getNeigh(active);
    if (!neigh || (neigh->getRadius() < limit_ && neigh->getRadius() > 0)) {
      faceXtet fxt (t,active);
      MFace me (fxt.v[0],fxt.v[1],fxt.v[2]);
      front.insert(me);
    }
  }
}

static bool isActive(MTet4 *t, double limit_, int &i, std::set<MFace,Less_Face> *front)
{
  if (t->isDeleted()) return false;
  for (i = 0; i < 4; i++){
    MTet4 *neigh = t->getNeigh(i);
    if (!neigh || (neigh->getRadius() < limit_ && neigh->getRadius() > 0)) {
      faceXtet fxt (t,i);
      MFace me (fxt.v[0],fxt.v[1],fxt.v[2]);
      if(front->find(me) != front->end()){
	return true;
      }
    }
  }
  return false;
}

void connectTets(std::list<MTet4*> &l) { connectTets(l.begin(), l.end()); } 
void connectTets(std::vector<MTet4*> &l) { connectTets(l.begin(), l.end()); }

void recurFindCavity(std::list<faceXtet> & shell, 
                     std::list<MTet4*> & cavity, 
                     MVertex *v , 
                     MTet4 *t)
{
  // Msg::Info("tet %d %d %d %d",t->tet()->getVertex(0)->getNum(),
  //     t->tet()->getVertex(1)->getNum(),
  //     t->tet()->getVertex(2)->getNum(),
  //     t->tet()->getVertex(3)->getNum());

  // invariant : this one has to be inserted in the cavity
  // consider this tet deleted 
  // remove its reference to its neighbors
  t->setDeleted(true);
  // the cavity that has to be removed
  // because it violates delaunay criterion
  cavity.push_back(t);

  for (int i = 0; i < 4; i++){
    MTet4 *neigh = t->getNeigh(i) ;
    if (!neigh)
      shell.push_back(faceXtet(t, i));
    else  if (!neigh->isDeleted()){
      int circ = neigh->inCircumSphere(v);
      if (circ && (neigh->onWhat() == t->onWhat()))
        recurFindCavity(shell, cavity, v, neigh);
      else
        shell.push_back(faceXtet(t, i));
    }
  }
}

bool insertVertex(MVertex *v, 
                  MTet4 *t,
                  MTet4Factory &myFactory,
                  std::set<MTet4*,compareTet4Ptr> &allTets,
		  std::vector<double> & vSizes,
                  std::vector<double> & vSizesBGM,
		  std::set<MTet4*,compareTet4Ptr> *activeTets = 0 )
{
  std::list<faceXtet> shell;
  std::list<MTet4*> cavity; 
  std::list<MTet4*> new_cavity;

  recurFindCavity(shell, cavity, v, t);  

  // check that volume is conserved
  double newVolume = 0;
  double oldVolume = 0;

  std::list<MTet4*>::iterator ittet = cavity.begin();
  std::list<MTet4*>::iterator ittete = cavity.end();
  while (ittet != ittete){
    oldVolume += fabs((*ittet)->getVolume());
      ++ittet;
    }

  MTet4** newTets = new MTet4*[shell.size()];
  int k = 0;

  std::list<faceXtet>::iterator it = shell.begin();

  bool onePointIsTooClose = false;
  while (it != shell.end()){
    MTetrahedron *tr = new MTetrahedron(it->v[0], it->v[1], it->v[2], v);

    double lc = .25 * (vSizes[tr->getVertex(0)->getIndex()] +
		       vSizes[tr->getVertex(1)->getIndex()] +
		       vSizes[tr->getVertex(2)->getIndex()] +
		       vSizes[tr->getVertex(3)->getIndex()]);
    double lcBGM = .25 * (vSizesBGM[tr->getVertex(0)->getIndex()] +
			  vSizesBGM[tr->getVertex(1)->getIndex()] +
			  vSizesBGM[tr->getVertex(2)->getIndex()] +
			  vSizesBGM[tr->getVertex(3)->getIndex()]);
    double LL = std::min(lc, lcBGM);
    
    MTet4 *t4 = myFactory.Create(tr, vSizes, vSizesBGM); 
    t4->setOnWhat(t->onWhat());

    double d1 = sqrt((it->v[0]->x() - v->x()) * (it->v[0]->x() - v->x()) +
                     (it->v[0]->y() - v->y()) * (it->v[0]->y() - v->y()) +
                     (it->v[0]->z() - v->z()) * (it->v[0]->z() - v->z()));
    double d2 = sqrt((it->v[1]->x() - v->x()) * (it->v[1]->x() - v->x()) +
                     (it->v[1]->y() - v->y()) * (it->v[1]->y() - v->y()) +
                     (it->v[1]->z() - v->z()) * (it->v[1]->z() - v->z()));
    double d3 = sqrt((it->v[2]->x() - v->x()) * (it->v[2]->x() - v->x()) +
                     (it->v[2]->y() - v->y()) * (it->v[2]->y() - v->y()) +
                     (it->v[2]->z() - v->z()) * (it->v[2]->z() - v->z()));

    if (d1 < LL * .25 || d2 < LL * .25 || d3 < LL * .25) onePointIsTooClose = true;
    newTets[k++] = t4;
    // all new tets are pushed front in order to ba able to destroy
    // them if the cavity is not star shaped around the new vertex.
    // here, we better use robust perdicates that implies to orient
    // all faces and ensure that the tets are all oriented the same.
    new_cavity.push_back(t4);
    MTet4 *otherSide = it->t1->getNeigh(it->i1);
    
    if (otherSide)
      new_cavity.push_back(otherSide);
    //      if (!it->t1->isDeleted())throw;
    newVolume += fabs(t4->getVolume());
    ++it;
  }
  // OK, the cavity is star shaped
  if (fabs(oldVolume - newVolume) < 1.e-10 * oldVolume &&
      !onePointIsTooClose){      
    connectTets(new_cavity.begin(), new_cavity.end());      
    allTets.insert(newTets, newTets + shell.size());

    if (activeTets){
      for (std::list<MTet4*>::iterator i = new_cavity.begin(); i != new_cavity.end(); ++i){
        int active_face;
        if(isActive(*i, LIMIT_, active_face) && (*i)->getRadius() > LIMIT_){
          if ((*activeTets).find(*i) == (*activeTets).end())
            (*activeTets).insert(*i);
        }
      }
    }

    delete [] newTets;

    return true;
  }
  else { // The cavity is NOT star shaped
    //    printf("hola %d %g %g %22.15E\n",onePointIsTooClose, oldVolume, newVolume, 100.*fabs(oldVolume - newVolume) / oldVolume);
    for (unsigned int i = 0; i <shell.size(); i++) myFactory.Free(newTets[i]);
    delete [] newTets;      
    ittet = cavity.begin();
    ittete = cavity.end();  
    while(ittet != ittete){
      (*ittet)->setDeleted(false);
      ++ittet;
    }
    return false;
  }
}

static void setLcs(MTetrahedron *t, std::map<MVertex*, double> &vSizes)
{
  for (int i = 0; i < 4; i++){
    for (int j = i + 1; j < 4; j++){
      MVertex *vi = t->getVertex(i);
      MVertex *vj = t->getVertex(j);
      double dx = vi->x()-vj->x();
      double dy = vi->y()-vj->y();
      double dz = vi->z()-vj->z();
      double l = sqrt(dx * dx + dy * dy + dz * dz);
      std::map<MVertex*,double>::iterator iti = vSizes.find(vi);          
      std::map<MVertex*,double>::iterator itj = vSizes.find(vj);          
      if (iti == vSizes.end() || iti->second > l) vSizes[vi] = l;
      if (itj == vSizes.end() || itj->second > l) vSizes[vj] = l;
    }
  }
}

// void recover_volumes( GRegion *gr , std::set<MTet4*,compareTet4Ptr> & allTets )
// {
//   std::set<MTet4*,compareTet4Ptr>::iterator it = allTets.begin();
//   for (; it != allTets.end(); ++it){
//     MTet4 *t = *allTets.begin();
//     if (!t->isDeleted()){
//     }
//   }
// }

// 4th argument will disappear when the reclassification of vertices will be done
bool find_triangle_in_model(GModel *model, MTriangle *tri, GFace **gfound, bool force)
{  
  static compareMTriangleLexicographic cmp;
  
  GModel::fiter fit = model->firstFace() ;
  while (fit != model->lastFace()){
    bool found = std::binary_search((*fit)->triangles.begin(), 
                                    (*fit)->triangles.end(), 
                                    tri, cmp);
    if(found){
      *gfound = *fit;
      return true;
    }
    ++fit;
  }
  return false;
}

GRegion *getRegionFromBoundingFaces(GModel *model,
                                    std::set<GFace *> &faces_bound)
{
  GModel::riter git = model->firstRegion();
  //  for (std::set<GFace *>::iterator it = faces_bound.begin();
  //       it != faces_bound.end(); ++it){
  //    printf(" %d",(*it)->tag());
  //  }
  //  printf("\n");
  while (git != model->lastRegion()){
    std::list <GFace *> _faces = (*git)->faces();
    //    printf("region %d %d faces\n",(*git)->tag(),_faces.size());
    //    for (std::list<GFace *>::iterator it = _faces.begin(); it != _faces.end(); ++it){
    //      printf(" %d",(*it)->tag());      
    //    }
    //  printf("\n");
	   
    if(_faces.size() == faces_bound.size()){
      bool ok = true;
      for (std::list<GFace *>::iterator it = _faces.begin(); it != _faces.end(); ++it){
        if(faces_bound.find (*it) == faces_bound.end()) ok = false;
      }
      if (ok) return *git;
    }    
    ++git;
  }
  return 0;
}
 
void recur_classify(MTet4 *t, std::list<MTet4*> &theRegion,                   
                    std::set<GFace*> &faces_bound, GRegion *bidon,
                    GModel *model, const fs_cont &search)
{
  if (!t) Msg::Error("a tet is not connected by a boundary face");
  if (t->onWhat()) return; // should never return here...
  theRegion.push_back(t);
  t->setOnWhat(bidon);
  
  bool FF[4] = {0,0,0,0};

  for (int i = 0; i < 4; i++){
    //      if (!t->getNeigh(i) || !t->getNeigh(i)->onWhat())
    {
      GFace* gfound = findInFaceSearchStructure (t->tet()->getVertex(faces[i][0]),
                                                 t->tet()->getVertex(faces[i][1]),
                                                 t->tet()->getVertex(faces[i][2]),
                                                 search);
      if (gfound){
        FF[i] = true;
        if (faces_bound.find(gfound) == faces_bound.end())
          faces_bound.insert(gfound);
      }
      
//        MTriangle tri (t->tet()->getVertex (faces[i][0]),
//                       t->tet()->getVertex (faces[i][1]),
//                       t->tet()->getVertex (faces[i][2]));
//        GFace *gfound;
//        if (FF[i] = find_triangle_in_model(model, &tri, &gfound, false)){
//          if (faces_bound.find(gfound) == faces_bound.end())
//            faces_bound.insert(gfound);         
//        }
    }
  }
  for (int i = 0; i < 4; i++){
    if (!FF[i])
      recur_classify(t->getNeigh(i), theRegion, faces_bound, bidon, model, search );
  }
}

void adaptMeshGRegion::operator () (GRegion *gr)
{
  const qualityMeasure4Tet qm = QMTET_2;

  typedef std::list<MTet4 *> CONTAINER ;
  CONTAINER allTets;
  for(unsigned int i = 0; i < gr->tetrahedra.size(); i++){
    allTets.push_back(new MTet4(gr->tetrahedra[i], qm));
  }
  gr->tetrahedra.clear();
  
  connectTets(allTets.begin(),allTets.end());

  double t1 = Cpu();
  std::vector<MTet4*> illegals;
  const int nbRanges = 10;
  int quality_ranges[nbRanges];
  {
    double totalVolumeb = 0.0;
    double worst = 1.0;
    double avg = 0;
    int count=0;
    for (int i = 0; i < nbRanges; i++) quality_ranges[i] = 0;
    for (CONTAINER::iterator it = allTets.begin();it!=allTets.end(); ++it){
      if (!(*it)->isDeleted()){
        double vol = fabs((*it)->tet()->getVolume());
        double qual = (*it)->getQuality();
        worst = std::min(qual, worst);
        avg += qual;
        count++;
        totalVolumeb += vol;
        for (int i = 0; i < nbRanges; i++){
          double low  = (double)i / nbRanges;
          double high = (double)(i + 1) / nbRanges;
          if (qual >= low && qual < high) quality_ranges[i]++;
        }                     
      }
    }
    Msg::Info("Adaptation : START with %12.5E QBAD %12.5E QAVG %12.5E",
              totalVolumeb, worst, avg / count);
    for (int i = 0; i < nbRanges; i++){
      double low  = (double)i / nbRanges;
      double high = (double)(i + 1) / nbRanges;
      Msg::Info("Opti : %3.2f < QUAL < %3.2f : %9d elements ",
                low, high, quality_ranges[i]);
    }                 
  }    
    
  double qMin = 0.5;
  double sliverLimit = 0.2;

  int nbESwap = 0, nbFSwap = 0, nbReloc = 0, nbCollapse = 0;
    
  while (1){
    std::vector<MTet4*> newTets;    
    for (CONTAINER::iterator it = allTets.begin(); it!=allTets.end(); ++it){
      if (!(*it)->isDeleted()){
        for (int i = 0; i < 4; i++){
          for (int j = 0; j < 4; j++){
            if (collapseVertex(newTets, *it, i, j, QMTET_2)){
              nbCollapse++; i = j = 10;
            }
          }
        }
      }
    }
    
    printf("nbCollapses = %d\n", nbCollapse);

    for (CONTAINER::iterator it = allTets.begin(); it!=allTets.end(); ++it){
      if (!(*it)->isDeleted()){
        double qq = (*it)->getQuality();
        if (qq < qMin){
          for (int i = 0; i < 4; i++){
            if (faceSwap(newTets, *it, i, qm)){
              nbFSwap++;
              break;
            }
          }
        }
      }
    }
 
    illegals.clear();
    for (int i = 0; i < nbRanges; i++) quality_ranges[i] = 0;

    for (CONTAINER::iterator it = allTets.begin(); it != allTets.end(); ++it){
      if (!(*it)->isDeleted()){
        double qq = (*it)->getQuality();
        if (qq < qMin)
          for (int i = 0; i < 6; i++){
            if (edgeSwap(newTets, *it, i, qm)) {
              nbESwap++;
              break; 
            }
          }
          if (!(*it)->isDeleted()){
            if (qq < sliverLimit) illegals.push_back(*it);
            for (int i = 0; i < nbRanges; i++){
              double low  = (double)i / nbRanges;
              double high = (double)(i + 1)/ nbRanges;
              if (qq >= low && qq < high) quality_ranges[i]++;
            }                 
          }
      }
    }
    
    if (!newTets.size()) break;
    
    // add all the new tets in the container
    for(unsigned int i = 0; i < newTets.size(); i++){
      if(!newTets[i]->isDeleted()){
        allTets.push_back(newTets[i]);
      }
      else{
        delete newTets[i]->tet();
        delete newTets[i];
      }
    }  

    // relocate vertices
    for (CONTAINER::iterator it = allTets.begin(); it != allTets.end(); ++it){
      if (!(*it)->isDeleted()){
        double qq = (*it)->getQuality();
        if (qq < qMin)
          for (int i = 0; i < 4; i++){
            if (smoothVertex(*it, i, qm)) nbReloc++;
          }
      }
    }
    
    double totalVolumeb = 0.0;
    double worst = 1.0;
    double avg = 0;
    int count = 0;
    for (CONTAINER::iterator it = allTets.begin(); it != allTets.end(); ++it){
      if (!(*it)->isDeleted()){
        double vol = fabs((*it)->tet()->getVolume());
        double qual = (*it)->getQuality();
        worst = std::min(qual, worst);
        avg += qual;
        count++;
        totalVolumeb += vol;
      }
    }
    double t2 = Cpu();
    Msg::Info("Opti : (%d,%d,%d) = %12.5E QBAD %12.5E QAVG %12.5E (%8.3f sec)",
              nbESwap, nbFSwap, nbReloc, totalVolumeb, worst, avg / count, t2 - t1);
    break;
  }
  
  int nbSlivers = 0;
  for(unsigned int i = 0; i < illegals.size(); i++)
    if(!(illegals[i]->isDeleted())) nbSlivers++;
  
  if (nbSlivers){
    Msg::Info("Opti : %d illegal tets are still in the mesh, trying to remove them",
              nbSlivers);
  }
  else{
    Msg::Info("Opti : no illegal tets in the mesh ;-)", nbSlivers);
  }

  for (int i = 0; i < nbRanges ;i++){
    double low  = (double)i / nbRanges;
    double high = (double)(i + 1) / nbRanges;
    Msg::Info("Opti : %3.2f < QUAL < %3.2f : %9d elements",
              low, high, quality_ranges[i]);
  }                   
  
  for (CONTAINER::iterator it = allTets.begin(); it != allTets.end(); ++it){
    if (!(*it)->isDeleted()){
      gr->tetrahedra.push_back((*it)->tet());
      delete *it;
    }
    else{
      delete (*it)->tet();
      delete *it;       
    }
  }
}

//template <class CONTAINER, class DATA> 
void optimizeMesh(GRegion *gr, const qualityMeasure4Tet &qm)
{
  typedef std::list<MTet4 *> CONTAINER ;
  CONTAINER allTets;
  for(unsigned int i = 0; i < gr->tetrahedra.size(); i++){
    MTet4 * t = new MTet4(gr->tetrahedra[i], qm);
    t->setOnWhat(gr);
    allTets.push_back(t);
  }
  gr->tetrahedra.clear();
  
  connectTets(allTets.begin(), allTets.end());

  double t1 = Cpu();
  std::vector<MTet4*> illegals;
  const int nbRanges = 10;
  int quality_ranges [nbRanges];
  {
    double totalVolumeb = 0.0;
    double worst = 1.0;
    double avg = 0;
    int count = 0;
    for (int i = 0; i < nbRanges; i++) quality_ranges[i] = 0;
    for (CONTAINER::iterator it = allTets.begin(); it != allTets.end(); ++it){
      if (!(*it)->isDeleted()){
        double vol = fabs((*it)->tet()->getVolume());
        double qual = (*it)->getQuality();
        worst = std::min(qual, worst);
        avg += qual;
        count++;
        totalVolumeb += vol;
        for (int i = 0; i < nbRanges; i++){
          double low  = (double)i / nbRanges;
          double high = (double)(i + 1) / nbRanges;
          if (qual >= low && qual < high) quality_ranges[i]++;
        }                     
      }
    }
    Msg::Info("Opti : START with %12.5E QBAD %12.5E QAVG %12.5E",
              totalVolumeb, worst, avg / count);
    for (int i = 0; i < nbRanges; i++){
      double low  = (double)i / nbRanges;
      double high = (double)(i + 1) / nbRanges;
      Msg::Info("Opti : %3.2f < QUAL < %3.2f : %9d elements",
                low, high, quality_ranges[i]);
    }                 
  }    
  
  double qMin = 0.5;
  double sliverLimit = 0.1;

  int nbESwap = 0, nbFSwap = 0, nbReloc = 0;
    
  while (1){
    std::vector<MTet4*> newTets;    
    for (CONTAINER::iterator it = allTets.begin(); it != allTets.end(); ++it){
      if (!(*it)->isDeleted()){
        double qq = (*it)->getQuality();
        if (qq < qMin){
          for (int i = 0; i < 4; i++){
            if (faceSwap(newTets, *it, i, qm)){
              nbFSwap++;
              break;
            }
          }
        }
      }
    }
    
    illegals.clear();
    for (int i = 0; i < nbRanges; i++) quality_ranges[i] = 0;

    for (CONTAINER::iterator it = allTets.begin(); it != allTets.end(); ++it){
      if (!(*it)->isDeleted()){
        double qq = (*it)->getQuality();
        if (qq < qMin)
          for (int i = 0; i < 6; i++){
            if (edgeSwap(newTets, *it, i, qm)) {
              nbESwap++;
              break;
            }
          }
        if (!(*it)->isDeleted()){
          if (qq < sliverLimit) illegals.push_back(*it);
          for (int i = 0; i < nbRanges; i++){
            double low  = (double)i / nbRanges;
            double high = (double)(i + 1) / nbRanges;
            if (qq >= low && qq < high) quality_ranges[i]++;
          }                   
        }
      }
    }
    
    if (0 && !newTets.size()){
      int nbSlivers = 0;
      int nbSliversWeCanDoSomething = 0;
      for(unsigned int i = 0; i < illegals.size(); i++)
        if(!(illegals[i]->isDeleted())){
          if(sliverRemoval(newTets, illegals[i], qm))
            nbSliversWeCanDoSomething++;
          nbSlivers++;
        }
      Msg::Info("Opti : %d Sliver Removals", nbSliversWeCanDoSomething);
    }
    
    if (!newTets.size()){
      break;
    }
    
    // add all the new tets in the container
    for(unsigned int i = 0; i < newTets.size(); i++){
      if(!newTets[i]->isDeleted()){
        allTets.push_back(newTets[i]);
      }
      else{
        delete newTets[i]->tet();
        delete newTets[i];
      }
    }  

    // relocate vertices
    for (CONTAINER::iterator it = allTets.begin();it!=allTets.end();++it){
      if (!(*it)->isDeleted()){
        double qq = (*it)->getQuality();
        if (qq < qMin)
          for (int i = 0; i < 4; i++){
            if (smoothVertex(*it, i, qm)) nbReloc++;
          }
      }
    }

    double totalVolumeb = 0.0;
    double worst = 1.0;
    double avg = 0;
    int count = 0;
    for (CONTAINER::iterator it = allTets.begin(); it != allTets.end(); ++it){
      if (!(*it)->isDeleted()){
        double vol = fabs((*it)->tet()->getVolume());
        double qual = (*it)->getQuality();
        worst = std::min(qual, worst);
        avg += qual;
        count++;
        totalVolumeb += vol;
      }
    }
    double t2 = Cpu();
    Msg::Info("Opti : (%d,%d,%d) = %12.5E QBAD %12.5E QAVG %12.5E (%8.3f sec)",
              nbESwap, nbFSwap, nbReloc, totalVolumeb, worst, avg / count, t2 - t1);
  }
  
  if (illegals.size()){
    Msg::Info("Opti : %d illegal tets are still in the mesh", illegals.size());
  }
  else{
    Msg::Info("Opti : no illegal tets in the mesh ;-)");
  }

  for (int i = 0; i < nbRanges; i++){
    double low  = (double)i / nbRanges;
    double high = (double)(i + 1) / nbRanges;
    Msg::Info("Opti : %3.2f < QUAL < %3.2f : %9d elements",
              low, high, quality_ranges[i]);
  }                   

  for (CONTAINER::iterator it = allTets.begin(); it != allTets.end(); ++it){
    if (!(*it)->isDeleted()){
      gr->tetrahedra.push_back((*it)->tet());
      delete *it;
    }
    else{
      delete (*it)->tet();
      delete *it;       
    }
  }
}


static double tetcircumcenter(double a[3], double b[3], double c[3], double d[3], 
			      double circumcenter[3], double *xi, double *eta, double *zeta){
  double xba, yba, zba, xca, yca, zca, xda, yda, zda;
  double balength, calength, dalength;
  double xcrosscd, ycrosscd, zcrosscd;
  double xcrossdb, ycrossdb, zcrossdb;
  double xcrossbc, ycrossbc, zcrossbc;
  double denominator;
  double xcirca, ycirca, zcirca;
  
  /* Use coordinates relative to point `a' of the tetrahedron. */
  xba = b[0] - a[0];
  yba = b[1] - a[1];
  zba = b[2] - a[2];
  xca = c[0] - a[0];
  yca = c[1] - a[1];
  zca = c[2] - a[2];
  xda = d[0] - a[0];
  yda = d[1] - a[1];
  zda = d[2] - a[2];
  /* Squares of lengths of the edges incident to `a'. */
  balength = xba * xba + yba * yba + zba * zba;
  calength = xca * xca + yca * yca + zca * zca;
  dalength = xda * xda + yda * yda + zda * zda;
  /* Cross products of these edges. */
  xcrosscd = yca * zda - yda * zca;
  ycrosscd = zca * xda - zda * xca;
  zcrosscd = xca * yda - xda * yca;
  xcrossdb = yda * zba - yba * zda;
  ycrossdb = zda * xba - zba * xda;
  zcrossdb = xda * yba - xba * yda;
  xcrossbc = yba * zca - yca * zba;
  ycrossbc = zba * xca - zca * xba;
  zcrossbc = xba * yca - xca * yba;
  
  /* Calculate the denominator of the formulae. */
  /* Use orient3d() from http://www.cs.cmu.edu/~quake/robust.html     */
  /*   to ensure a correctly signed (and reasonably accurate) result, */
  /*   avoiding any possibility of division by zero.                  */
  const double xxx =  robustPredicates::orient3d(b, c, d, a);
  denominator = 0.5 / xxx;
  
  /* Calculate offset (from `a') of circumcenter. */
  xcirca = (balength * xcrosscd + calength * xcrossdb + dalength * xcrossbc) *
    denominator;
  ycirca = (balength * ycrosscd + calength * ycrossdb + dalength * ycrossbc) *
    denominator;
  zcirca = (balength * zcrosscd + calength * zcrossdb + dalength * zcrossbc) *
    denominator;
  circumcenter[0] =  xcirca + a[0];
  circumcenter[1] =  ycirca + a[1];
  circumcenter[2] =  zcirca + a[2];
 
  /*  
 printf(" %g %g %g %g\n",
	 sqrt((a[0]-xcirca)*(a[0]-xcirca)+(a[1]-ycirca)*(a[1]-ycirca)+(a[2]-zcirca)*(a[2]-zcirca)),
	 sqrt((b[0]-xcirca)*(b[0]-xcirca)+(b[1]-ycirca)*(b[1]-ycirca)+(b[2]-zcirca)*(b[2]-zcirca)),
	 sqrt((c[0]-xcirca)*(c[0]-xcirca)+(c[1]-ycirca)*(c[1]-ycirca)+(c[2]-zcirca)*(c[2]-zcirca)),
	 sqrt((d[0]-xcirca)*(d[0]-xcirca)+(d[1]-ycirca)*(d[1]-ycirca)+(d[2]-zcirca)*(d[2]-zcirca)) );
  */
 
  if (xi != (double *) NULL) {
    /* To interpolate a linear function at the circumcenter, define a    */
    /*   coordinate system with a xi-axis directed from `a' to `b',      */
    /*   an eta-axis directed from `a' to `c', and a zeta-axis directed  */
    /*   from `a' to `d'.  The values for xi, eta, and zeta are computed */
     /*   by Cramer's Rule for solving systems of linear equations.       */
    *xi = (xcirca * xcrosscd + ycirca * ycrosscd + zcirca * zcrosscd) *
      (2.0 * denominator);
    *eta = (xcirca * xcrossdb + ycirca * ycrossdb + zcirca * zcrossdb) *
      (2.0 * denominator);
    *zeta = (xcirca * xcrossbc + ycirca * ycrossbc + zcirca * zcrossbc) *
      (2.0 * denominator);
  }
  return xxx;
}


void insertVerticesInRegion (GRegion *gr) 
{
  //printf("sizeof MTet4 = %d sizeof MTetrahedron %d sizeof(MVertex) %d\n",
  //       sizeof(MTet4), sizeof(MTetrahedron), sizeof(MVertex));


  std::vector<double> vSizes;
  std::vector<double> vSizesBGM;
  MTet4Factory myFactory(1600000);
  std::set<MTet4*, compareTet4Ptr> &allTets = myFactory.getAllTets();
  int NUM = 0;

  { // leave this in a block so the map gets deallocated directly
    std::map<MVertex*, double> vSizesMap;
    for(unsigned int i = 0; i < gr->tetrahedra.size(); i++)
      setLcs(gr->tetrahedra[i], vSizesMap);
    for(std::map<MVertex*, double>::iterator it = vSizesMap.begin(); 
        it != vSizesMap.end(); ++it){
      it->first->setIndex(NUM++);
      vSizes.push_back(it->second);
      vSizesBGM.push_back(it->second);
    }
  }
  
  for(unsigned int i = 0; i < gr->tetrahedra.size(); i++)
    allTets.insert(myFactory.Create(gr->tetrahedra[i], vSizes,vSizesBGM));

  gr->tetrahedra.clear();
  connectTets(allTets.begin(), allTets.end());

  // classify the tets on the right region
  // Msg::Info("reclassifying %d tets", allTets.size());

  fs_cont search;
  buildFaceSearchStructure(gr->model(), search);

  for(MTet4Factory::iterator it = allTets.begin(); it != allTets.end(); ++it){
    if(!(*it)->onWhat()){
      std::list<MTet4*> theRegion;
      std::set<GFace *> faces_bound;
      GRegion *bidon = (GRegion*)123;
      double _t1 = Cpu();
      Msg::Debug("start with a non classified tet");      
      recur_classify(*it, theRegion, faces_bound, bidon, gr->model(), search);
      double _t2 = Cpu();
      Msg::Debug("found %d tets with %d faces (%g sec for the classification)",
                 theRegion.size(), faces_bound.size(), _t2 - _t1);
      GRegion *myGRegion = getRegionFromBoundingFaces(gr->model(), faces_bound);
       Msg::Info("a region is found %p",myGRegion);
      if(myGRegion) // a geometrical region associated to the list of faces has been found
        for(std::list<MTet4*>::iterator it2 = theRegion.begin(); 
            it2 != theRegion.end(); ++it2) (*it2)->setOnWhat(myGRegion);
      else // the tets are in the void 
        for(std::list<MTet4*>::iterator it2 = theRegion.begin();
            it2 != theRegion.end(); ++it2)(*it2)->setDeleted(true);
    }
  }
  search.clear();
  
  for(MTet4Factory::iterator it = allTets.begin(); it!=allTets.end(); ++it){
    (*it)->setNeigh(0, 0);
    (*it)->setNeigh(1, 0);
    (*it)->setNeigh(2, 0);
    (*it)->setNeigh(3, 0);
  }
  connectTets(allTets.begin(), allTets.end());
  Msg::Debug("All %d tets were connected", allTets.size());

  // here the classification should be done

  int ITER = 0;

  while(1){
    if(allTets.empty()){
      Msg::Error("No tetrahedra in region %d %d", gr->tag(), allTets.size());
      break;
    }
      
    MTet4 *worst = *allTets.begin();

    if(worst->isDeleted()){
      myFactory.Free(worst);
      allTets.erase(allTets.begin());
    }
    else{
      if(ITER++ %5000 == 0)
        Msg::Info("%d points created -- Worst tet radius is %g",
                  vSizes.size(), worst->getRadius());
      if(worst->getRadius() < 1) break;
      double center[3];
      double uvw[3];
      MTetrahedron *base = worst->tet();
      double pa[3] = {base->getVertex(0)->x(), 
		      base->getVertex(0)->y(), 
		      base->getVertex(0)->z()};
      double pb[3] = {base->getVertex(1)->x(), 
		      base->getVertex(1)->y(),
		      base->getVertex(1)->z()};
      double pc[3] = {base->getVertex(2)->x(),
		      base->getVertex(2)->y(), 
		      base->getVertex(2)->z()};
      double pd[3] = {base->getVertex(3)->x(),
		      base->getVertex(3)->y(),
		      base->getVertex(3)->z()};
      
      //      double UU,VV,WW;
      tetcircumcenter(pa,pb,pc,pd, center,&uvw[0],&uvw[1],&uvw[2] );
      //      worst->tet()->xyz2uvw(center, uvw);
      //      printf("%12.5E %12.5E %12.5E -- %12.5E %12.5E %12.5E \n",
      //	     UU,VV,WW,uvw[0],uvw[1],uvw[2]);
      /*
      if (!worst->tet()->isInside(uvw[0], uvw[1], uvw[2]) && 
	  worst->getRadius() > 20){
	uvw[0] = uvw[1] = uvw[2] = 0.25;
	center[0] = 0.25*(pa[0]+pb[0]+pc[0]+pd[0]);
	center[1] = 0.25*(pa[1]+pb[1]+pc[1]+pd[1]);
	center[2] = 0.25*(pa[2]+pb[2]+pc[2]+pd[2]);
      }
      */

      if(worst->tet()->isInside(uvw[0], uvw[1], uvw[2])){	
        MVertex *v = new MVertex(center[0], center[1], center[2], worst->onWhat());
        v->setIndex(NUM++);
        double lc1 = 
          (1 - uvw[0] - uvw[1] - uvw[2]) * vSizes[worst->tet()->getVertex(0)->getIndex()] +
          uvw[0] * vSizes[worst->tet()->getVertex(1)->getIndex()] +
          uvw[1] * vSizes[worst->tet()->getVertex(2)->getIndex()] +
          uvw[2] * vSizes[worst->tet()->getVertex(3)->getIndex()];
        double lc = BGM_MeshSize(gr, 0, 0, center[0], center[1], center[2]);
        // double lc = std::min(lc1, BGM_MeshSize(gr, 0, 0, center[0], center[1], center[2]));
        vSizes.push_back(lc1);
        vSizesBGM.push_back(lc);
        // compute mesh spacing there
        if(!insertVertex(v, worst, myFactory, allTets, vSizes,vSizesBGM)){
          myFactory.changeTetRadius(allTets.begin(), 0.);
          delete v;
        }
        else
          v->onWhat()->mesh_vertices.push_back(v);
      }
      else{
	//	printf("point outside %12.5E %12.5E %12.5E %12.5E %12.5E\n",VV,uvw[0], uvw[1], uvw[2],1-uvw[0]-uvw[1]-uvw[2]);
        myFactory.changeTetRadius(allTets.begin(), 0.0);
      }
    }

    // Normally, a tet mesh contains about 6 times more tets than
    // vertices. This allows to clean up the set of tets when lots of
    // deleted ones are present in the mesh
    if(allTets.size() > 7 * vSizes.size()){
      int n1 = allTets.size();
      std::set<MTet4*,compareTet4Ptr>::iterator itd = allTets.begin();
      while(itd != allTets.end()){
        if((*itd)->isDeleted()){
          myFactory.Free((*itd));
          allTets.erase(itd++);
        }
        else
          itd++;
      }
      Msg::Info("cleaning up the memory %d -> %d", n1, allTets.size());
    }
  }

    // relocate vertices
  int nbReloc = 0;
  for (int SM=0;SM<CTX::instance()->mesh.nbSmoothing;SM++){
    for(MTet4Factory::iterator it = allTets.begin(); it != allTets.end(); ++it){
      if (!(*it)->isDeleted()){
	double qq = (*it)->getQuality();
	if (qq < .4)
	  for (int i = 0; i < 4; i++){
	    if (smoothVertex(*it, i, QMTET_2)) nbReloc++;
	  }
      }
    }
  }

  
  while(1){
    if(allTets.begin() == allTets.end()) break;
    MTet4 *worst = *allTets.begin();
    if(!worst->isDeleted()){
      worst->onWhat()->tetrahedra.push_back(worst->tet());
      worst->tet() = 0;
    }
    myFactory.Free(worst);
    allTets.erase(allTets.begin());      
  }
}

MVertex * optimalPointFrontal (GRegion *gr, 
			       MTet4 *worst,
			       int active_face,
			       std::vector<double> &vSizes,
			       std::vector<double> &vSizesBGM){
  double centerTet[3], centerFace[3];
  MTetrahedron *base = worst->tet();
  faceXtet fxt ( worst, active_face );
  double pa[3] = {fxt.v[0]->x(),fxt.v[0]->y(),fxt.v[0]->z()};
  double pb[3] = {fxt.v[1]->x(),fxt.v[1]->y(),fxt.v[1]->z()};
  double pc[3] = {fxt.v[2]->x(),fxt.v[2]->y(),fxt.v[2]->z()};
  circumCenterXYZ(pa, pb, pc, centerFace);
  worst->circumcenter(centerTet);
  
  SVector3 dir (centerTet[0] - centerFace[0],
		centerTet[1] - centerFace[1],
		centerTet[2] - centerFace[2]);

  const double q = dir.norm();
  dir.normalize();

  SVector3 rDir (pa[0] - centerFace[0],
		 pa[1] - centerFace[1],
		 pa[2] - centerFace[2]);
  
  const double p = 0.5 * rDir.norm();

  const double rhoM1 = 0.33333 * (vSizes[fxt.v[0]->getIndex()] + 
				  vSizes[fxt.v[1]->getIndex()] + 
				  vSizes[fxt.v[2]->getIndex()] );
  const double rhoM2 = 0.33333 * (vSizesBGM[fxt.v[0]->getIndex()] + 
				  vSizesBGM[fxt.v[1]->getIndex()] + 
				  vSizesBGM[fxt.v[2]->getIndex()] );

  const double rhoM  = std::min(rhoM1, rhoM2);
  
  const double HEIGHT = 1/sqrt(3.);

  const double rhoM_hat = std::min(std::max(rhoM, p), (p * p + q * q) / (2 * q));
  const double d = (rhoM_hat + sqrt (rhoM_hat * rhoM_hat - p * p)) * HEIGHT;

  //  const double a = 2*p *3 /sqrt(3);
  const double a = .025;
  const double tt = a*sqrt(6.)/3;

  MVertex *vert = new MVertex(centerFace[0] + tt * dir[0],
			      centerFace[1] + tt * dir[1],
			      centerFace[2] + tt * dir[2],
			      gr);
  return vert;
}


void bowyerWatsonFrontalLayers(GRegion *gr, bool hex)
{

  std::vector<double> vSizes;
  std::vector<double> vSizesBGM;
  MTet4Factory myFactory(1600000);
  std::set<MTet4*, compareTet4Ptr> &allTets = myFactory.getAllTets();
  std::set<MTet4*, compareTet4Ptr> activeTets;
  int NUM = 0;

  if (!backgroundMesh::current()) {
    // TODO !!!
  }

  if (hex){
    LIMIT_ = sqrt(2.) * .99;
    MTet4::radiusNorm =-1;
  }

  { // leave this in a block so the map gets deallocated directly
    std::map<MVertex*, double> vSizesMap;
    for(unsigned int i = 0; i < gr->tetrahedra.size(); i++)
      setLcs(gr->tetrahedra[i], vSizesMap);
    for(std::map<MVertex*, double>::iterator it = vSizesMap.begin(); 
        it != vSizesMap.end(); ++it){
      it->first->setIndex(NUM++);
      vSizes.push_back(it->second);
      vSizesBGM.push_back(it->second);
    }
  }
  
  for(unsigned int i = 0; i < gr->tetrahedra.size(); i++)
    allTets.insert(myFactory.Create(gr->tetrahedra[i], vSizes,vSizesBGM));

  gr->tetrahedra.clear();
  connectTets(allTets.begin(), allTets.end());

  fs_cont search;
  buildFaceSearchStructure(gr->model(), search);
  
  for(MTet4Factory::iterator it = allTets.begin(); it != allTets.end(); ++it){
    if(!(*it)->onWhat()){
      std::list<MTet4*> theRegion;
      std::set<GFace *> faces_bound;
      GRegion *bidon = (GRegion*)123;
      double _t1 = Cpu();
      Msg::Debug("start with a non classified tet");      
      recur_classify(*it, theRegion, faces_bound, bidon, gr->model(), search);
      double _t2 = Cpu();
      Msg::Debug("found %d tets with %d faces (%g sec for the classification)",
                 theRegion.size(), faces_bound.size(), _t2 - _t1);
      GRegion *myGRegion = getRegionFromBoundingFaces(gr->model(), faces_bound);
      // Msg::Info("a region is found %p",myGRegion);
      if(myGRegion) // a geometrical region associated to the list of faces has been found
        for(std::list<MTet4*>::iterator it2 = theRegion.begin(); 
            it2 != theRegion.end(); ++it2) (*it2)->setOnWhat(myGRegion);
      else // the tets are in the void 
        for(std::list<MTet4*>::iterator it2 = theRegion.begin();
            it2 != theRegion.end(); ++it2)(*it2)->setDeleted(true);
    }
  }
  search.clear();

  for(MTet4Factory::iterator it = allTets.begin(); it!=allTets.end(); ++it){
    (*it)->setNeigh(0, 0);
    (*it)->setNeigh(1, 0);
    (*it)->setNeigh(2, 0);
    (*it)->setNeigh(3, 0);
  }
  connectTets(allTets.begin(), allTets.end());

  int ITER = 0, active_face;

  std::set<MFace,Less_Face> _front;
  for(MTet4Factory::iterator it = allTets.begin(); it!=allTets.end(); ++it){
    if(isActive(*it,LIMIT_,active_face) && (*it)->getRadius() > LIMIT_){
      activeTets.insert(*it);
      updateActiveFaces(*it, LIMIT_, _front);
    }
    else if ((*it)->getRadius() < LIMIT_)break;
  }

  // insert points
  int ITERATION = 1;
  while (1){
    if (ITERATION == 8)break;
    ITERATION ++;

    std::set<MTet4*, compareTet4Ptr> activeTetsNotInFront;

    while (1){
      
      if (!activeTets.size())break;

      //      printf("%d active tets %d tets\n",activeTets.size(),allTets.size());

      std::set<MTet4*,compareTet4Ptr>::iterator WORST_ITER = activeTets.begin();      
      MTet4 *worst = (*WORST_ITER);
      if(worst->isDeleted()){
	activeTets.erase(WORST_ITER);
	//	myFactory.Free(worst);
      }
      else {
	activeTets.erase(WORST_ITER);
	if (isActive(worst, LIMIT_, active_face,&_front)  && 
	    worst->getRadius() > LIMIT_){
	  //	  printf("worst = %12.5E\n",worst->getRadius());
	
	  if(ITER++ % 5000 == 0)
	    Msg::Info("%d points created -- Worst tet radius is %g",
		      vSizes.size(), worst->getRadius());
	
	  MVertex *v = optimalPointFrontal (gr,worst,active_face,vSizes,vSizesBGM);
	  v->setIndex(NUM++);
	  vSizes.push_back(.025);
	  vSizesBGM.push_back(.025);

	  if(!worst->inCircumSphere(v) ||
	     !insertVertex(v, worst, myFactory, allTets, vSizes,vSizesBGM,&activeTets)){	    
	    myFactory.changeTetRadius(allTets.begin(), 0.);
	    if(v) delete v;
	  }
	  else{
	    //	    printf("yeah ! one new vertex \n");
	    v->onWhat()->mesh_vertices.push_back(v);	  
	    //	    if (ITER == 100)break;
	  }
	}
	else if (worst->getRadius() > LIMIT_){
	  activeTetsNotInFront.insert(worst);
	}
      }
    }
    _front.clear();
    MTet4Factory::iterator it = activeTetsNotInFront.begin();
    for ( ; it!=activeTetsNotInFront.end();++it){
      if((*it)->getRadius() > LIMIT_ && isActive(*it,LIMIT_,active_face)){
	activeTets.insert(*it);
	updateActiveFaces(*it, LIMIT_, _front);
      }
    }
    if (!activeTets.size())break;
  }


  int nbReloc = 0;
  for (int SM=0;SM<CTX::instance()->mesh.nbSmoothing;SM++){
    for(MTet4Factory::iterator it = allTets.begin(); it != allTets.end(); ++it){
      if (!(*it)->isDeleted()){
	double qq = (*it)->getQuality();
	if (qq < .4)
	  for (int i = 0; i < 4; i++){
	    if (smoothVertex(*it, i, QMTET_2)) nbReloc++;
	  }
      }
    }
  }


  while(1){
    if(allTets.begin() == allTets.end()) break;
    MTet4 *worst = *allTets.begin();
    if(!worst->isDeleted()){
      worst->onWhat()->tetrahedra.push_back(worst->tet());
      worst->tet() = 0;
    }
    myFactory.Free(worst);
    allTets.erase(allTets.begin());      
  }
  MTet4::radiusNorm = 2;
  LIMIT_ = 1;
} 
