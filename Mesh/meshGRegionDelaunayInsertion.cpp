// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <set>
#include <map>
#include <algorithm>
#include "GmshMessage.h"
#include "GmshPredicates.h"
#include "OS.h"
#include "BackgroundMesh.h"
#include "meshGRegion.h"
#include "meshGRegionLocalMeshMod.h"
#include "meshGRegionDelaunayInsertion.h"
#include "GModel.h"
#include "GRegion.h"
#include "MTriangle.h"
#include "Numeric.h"

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
  double result = 
    gmsh::insphere(pa, pb, pc, pd, (double*)p) * gmsh::orient3d(pa, pb, pc, pd);
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
                  std::vector<double> & vSizesBGM)
{
  std::list<faceXtet> shell;
  std::list<MTet4*> cavity; 
  std::list<MTet4*> new_cavity;

  recurFindCavity(shell, cavity, v, t);  

  // Msg::Info("%d %d",cavity.size(),NC);
  // if (NC != cavity.size())throw;

  // check that volume is conserved
  double newVolume = 0;
  double oldVolume = 0;

  //  char name2[245];
  //  FILE *ff2 = fopen (name2,"w");
  //  fprintf(ff2,"View\"test\"{\n");

  std::list<MTet4*>::iterator ittet = cavity.begin();
  std::list<MTet4*>::iterator ittete = cavity.end();
  while (ittet != ittete){
    oldVolume += fabs((*ittet)->getVolume());
//       fprintf(ff2,"SS(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g) {0,0,0,0};\n",
//            (*ittet)->tet()->getVertex(0)->x(),
//            (*ittet)->tet()->getVertex(0)->y(),
//            (*ittet)->tet()->getVertex(0)->z(),
//            (*ittet)->tet()->getVertex(1)->x(),
//            (*ittet)->tet()->getVertex(1)->y(),
//            (*ittet)->tet()->getVertex(1)->z(),
//            (*ittet)->tet()->getVertex(2)->x(),
//            (*ittet)->tet()->getVertex(2)->y(),
//            (*ittet)->tet()->getVertex(2)->z(),
//            (*ittet)->tet()->getVertex(3)->x(),
//            (*ittet)->tet()->getVertex(3)->y(),
//            (*ittet)->tet()->getVertex(3)->z());
//       if(!(*ittet)->inCircumSphere ( v ))throw;
      ++ittet;
    }
//   fprintf(ff2,"};\n");
//   fclose(ff2);
//  Msg::Info("cavity of size %d volume %g",cavity.size(),oldVolume);
  // create new tetrahedron using faces that are
  // on the border of the cavity
  // add those to a list
  // add also tets that are on the other side of the face
  // in order to perform the connexions afterwards

//   char name[245];
//   sprintf(name,"test%d.pos",III);

//   FILE *ff = fopen(name,"w");
//   fprintf(ff,"View\"test\"{\n");

  MTet4** newTets = new MTet4*[shell.size()];;
  int k = 0;

  std::list<faceXtet>::iterator it = shell.begin();

  while (it != shell.end()){
    MTetrahedron *tr = new MTetrahedron(it->v[0], it->v[1], it->v[2], v);
    //      Msg::Info("shell %d %d %d",it->v[0]->getNum(),it->v[1]->getNum(),it->v[2]->getNum());
//            fprintf(ff,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g) {0,0,0};\n",
//                 it->v[0]->x(),
//                 it->v[0]->y(),
//                 it->v[0]->z(),
//                 it->v[1]->x(),
//                 it->v[1]->y(),
//                 it->v[1]->z(),
//                 it->v[2]->x(),
//                 it->v[2]->y(),
//                 it->v[2]->z());
      
    MTet4 *t4 = myFactory.Create(tr, vSizes, vSizesBGM); 
      t4->setOnWhat(t->onWhat());
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
//   fprintf(ff,"};\n");
//   fclose (ff);
//  Msg::Info("new cavity of vol %g (%d boundaries)",newVolume,shell.size());
  // OK, the cavity is star shaped
  if (fabs(oldVolume - newVolume) < 1.e-10 * oldVolume){      
    connectTets(new_cavity.begin(), new_cavity.end());      
    allTets.insert(newTets, newTets + shell.size());
    
//     ittet = cavity.begin();
//     ittete = cavity.end();
//     while ( ittet != ittete ){
//       myFactory.Free (*ittet);
//       ++ittet;
//     }
    delete [] newTets;
    return true;
  }
  else { // The cavity is NOT star shaped
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
  while (git != model->lastRegion()){
    std::list <GFace *> _faces = (*git)->faces();
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
  const gmshQualityMeasure4Tet qm = QMTET_2;

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
            if (gmshCollapseVertex(newTets, *it, i, j, QMTET_2)){
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
            if (gmshFaceSwap(newTets, *it, i, qm)){
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
            if (gmshEdgeSwap(newTets, *it, i, qm)) {
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
            if (gmshSmoothVertex(*it, i, qm)) nbReloc++;
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
void gmshOptimizeMesh(GRegion *gr, const gmshQualityMeasure4Tet &qm)
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
            if (gmshFaceSwap(newTets, *it, i, qm)){
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
            if (gmshEdgeSwap(newTets, *it, i, qm)) {
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
          if(gmshSliverRemoval(newTets, illegals[i], qm))
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
            if (gmshSmoothVertex(*it, i, qm)) nbReloc++;
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
      worst->circumcenter(center);
      double uvw[3];
      worst->tet()->xyz2uvw(center, uvw);
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
        myFactory.changeTetRadius(allTets.begin(), 0.);
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
