// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <set>
#include <map>
#include <algorithm>
#include "GmshMessage.h"
#include "robustPredicates.h"
#include "OS.h"
#include "meshGRegion.h"
#include "meshGRegionLocalMeshMod.h"
#include "meshGRegionDelaunayInsertion.h"
#include "GModel.h"
#include "GRegion.h"
#include "MTriangle.h"
#include "Numeric.h"
#include "Context.h"
#include "delaunay3d.h"
#include "MEdge.h"
#include "MLine.h"

int MTet4::radiusNorm = 2;

static void createAllEmbeddedEdges (GRegion *gr, std::set<MEdge, Less_Edge> &allEmbeddedEdges)
{
  std::list<GEdge*> e = gr->embeddedEdges();
  //  printf("=================> %d embedded GEdges\n",e.size());
  for (std::list<GEdge*>::iterator it = e.begin() ; it != e.end(); ++it){
    for (unsigned int i = 0; i < (*it)->lines.size(); i++){
      allEmbeddedEdges.insert (MEdge((*it)->lines[i]->getVertex(0),(*it)->lines[i]->getVertex(1)));
    }
  }
}

static void createAllEmbeddedFaces (GRegion *gr, std::set<MFace, Less_Face> &allEmbeddedFaces)
{
  std::list<GFace*> f = gr->embeddedFaces();
  for (std::list<GFace*>::iterator it = f.begin() ; it != f.end(); ++it){
    for (unsigned int i = 0; i < (*it)->triangles.size(); i++){
      allEmbeddedFaces.insert ((*it)->triangles[i]->getFace(0));
    }
  }
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


static int faces[4][3] = {{0,1,2}, {0,2,3}, {0,3,1}, {1,3,2}};

struct faceXtet{
  MVertex *v[3],*unsorted[3];
  MTet4 *t1;
  int i1;
  faceXtet(MTet4 *_t=0, int iFac=0) : t1(_t), i1(iFac)
  {
    MVertex *v0 = t1->tet()->getVertex(faces[iFac][0]);
    MVertex *v1 = t1->tet()->getVertex(faces[iFac][1]);
    MVertex *v2 = t1->tet()->getVertex(faces[iFac][2]);

    unsorted[0] = v[0] = v0;
    unsorted[1] = v[1] = v1;
    unsorted[2] = v[2] = v2;
    MVertexLessThanNum lll;
    std::sort(v, v + 3, lll);
  }

  inline MVertex * getVertex (int i) const { return unsorted[i];}

 inline bool operator < (const faceXtet & other) const
  {
    if (v[0]->getNum() < other.v[0]->getNum()) return true;
    if (v[0]->getNum() > other.v[0]->getNum()) return false;
    if (v[1]->getNum() < other.v[1]->getNum()) return true;
    if (v[1]->getNum() > other.v[1]->getNum()) return false;
    if (v[2]->getNum() < other.v[2]->getNum()) return true;
    return false;
  }
  inline bool operator == (const faceXtet & other) const
  {
    return (v[0]->getNum() == other.v[0]->getNum() &&
	    v[1]->getNum() == other.v[1]->getNum() &&
	    v[2]->getNum() == other.v[2]->getNum() );
  }
  bool visible (MVertex *v){
    MVertex* v0 = t1->tet()->getVertex(faces[i1][0]);
    MVertex* v1 = t1->tet()->getVertex(faces[i1][1]);
    MVertex* v2 = t1->tet()->getVertex(faces[i1][2]);
    double a[3] = {v0->x(),v0->y(),v0->z()};
    double b[3] = {v1->x(),v1->y(),v1->z()};
    double c[3] = {v2->x(),v2->y(),v2->z()};
    double d[3] = {v->x(),v->y(),v->z()};
    double o = robustPredicates :: orient3d(a,b,c,d);
    return o < 0;
  }
};

void connectTets_vector2(std::vector<MTet4*> &t, std::vector<faceXtet> &conn)
{
  conn.clear();
  //  unsigned int k = 0;
  for (unsigned int i=0;i<t.size();i++){
    if (!t[i]->isDeleted()){
      for (int j = 0; j < 4; j++){
	conn.push_back(faceXtet(t[i], j));
      }
    }
  }
  if (!conn.size())return;
  std::sort(conn.begin(), conn.end());

  for (unsigned int i=0;i<conn.size()-1;i++){
    faceXtet &f1  = conn[i];
    faceXtet &f2  = conn[i+1];
    if (f1 == f2 && f1.t1 != f2.t1){
      f1.t1->setNeigh(f1.i1, f2.t1);
      f2.t1->setNeigh(f2.i1, f1.t1);
      ++i;
    }
  }
}


template <class ITER>
void connectTets(ITER beg, ITER end, std::set<MFace, Less_Face> *allEmbeddedFaces = 0)
{
  std::set<faceXtet> conn;
  while (beg != end){
    if (!(*beg)->isDeleted()){
      for (int i = 0; i < 4; i++){
        faceXtet fxt(*beg, i);
	// if a face is embedded, do not connect tets on both sides !
	if (!allEmbeddedFaces ||
	    allEmbeddedFaces->find (MFace(fxt.v[0],fxt.v[1],fxt.v[2])) ==
	    allEmbeddedFaces->end()){
	  std::set<faceXtet>::iterator found = conn.find(fxt);
	  if (found == conn.end())
	    conn.insert(fxt);
	  else if (found->t1 != *beg){
	    found->t1->setNeigh(found->i1, *beg);
	    (*beg)->setNeigh(i, found->t1);
	  }
	}
      }
    }
    ++beg;
  }
}


void connectTets(std::list<MTet4*> &l) { connectTets(l.begin(), l.end()); }
void connectTets(std::vector<MTet4*> &l) { connectTets(l.begin(), l.end()); }

// Ensure the star-shapeness of the delaunay cavity
// We use the visibility criterion : the vertex should be visible
// by all the facets of the cavity

static void removeFromCavity (std::list<faceXtet> & shell,
			      std::list<MTet4*> & cavity,
			      faceXtet &toRemove)
{
  toRemove.t1->setDeleted(false);
  cavity.erase(std::remove_if(cavity.begin(),cavity.end(),
			      std::bind2nd(std::equal_to<MTet4*>(), toRemove.t1)));
  for (int i=0;i<4;i++){
    faceXtet fxt2(toRemove.t1,i);
    std::list<faceXtet>::iterator it = std::find(shell.begin(),shell.end(),fxt2);
    if (it == shell.end()){
      MTet4 *opposite = toRemove.t1->getNeigh(toRemove.i1);
      if (opposite){
	for (int j=0;j<4;j++){
	  faceXtet fxt3(opposite,j);
	  if (fxt3 == fxt2){
	    shell.push_back(fxt3);
	  }
	}
      }
    }
    else shell.erase(it);
  }
}

static void extendCavity (std::list<faceXtet> & shell,
			  std::list<MTet4*> & cavity,
			  faceXtet &toExtend)
{
  MTet4 *t = toExtend.t1;
  MTet4 *opposite = t->getNeigh(toExtend.i1);
  for (int i=0;i<4;i++){
    faceXtet fxt(opposite,i);
    std::list<faceXtet>::iterator it = std::find(shell.begin(),shell.end(),fxt);
    if (it == shell.end()) shell.push_back(fxt);
    else shell.erase(it);
  }
  cavity.push_back(opposite);
  opposite->setDeleted(true);
}

// if all faces of the tet that are not in the shell see v, then it is ok
// either to add or to remove t from the shell
static bool verifyShell (MVertex *v, MTet4*t, std::list<faceXtet> & shell){
  if (!t)return false;
  return 1;
  int NBAD_BEFORE=0,NBAD_AFTER=0;
  for (int i=0;i<4 ; i++){
    faceXtet fxt(t,i);
    bool starShaped = fxt.visible(v);
    if (!starShaped){
      std::list<faceXtet>::iterator its = std::find(shell.begin(),shell.end(),fxt);
      if (its == shell.end())NBAD_AFTER ++;
      else NBAD_BEFORE++;
    }
  }
  return 1;
  return (NBAD_AFTER < NBAD_BEFORE);
}

int makeCavityStarShaped (std::list<faceXtet> & shell,
			   std::list<MTet4*> & cavity,
			   MVertex *v ){
  std::list<faceXtet> wrong;
  for (std::list<faceXtet>::iterator it = shell.begin(); it != shell.end() ;++it) {
    faceXtet &fxt = *it;
    bool starShaped = fxt.visible(v);
    if (!starShaped){
      wrong.push_back(fxt);
    }
  }
  if (wrong.empty()) return 0;
  //  printf ("cavity %p (shell size %d cavity size %d)is not star shaped (%d faces not visible), correcting it\n",
  //  	  v,shell.size(),cavity.size(),wrong.size());
  //  bool doneNothing = true;
  while (!wrong.empty()){
    faceXtet &fxt = *(wrong.begin());
    std::list<faceXtet>::iterator its = std::find(shell.begin(),shell.end(),fxt);
    if (its != shell.end()){
      if (fxt.t1->getNeigh(fxt.i1) && fxt.t1->getNeigh(fxt.i1)->onWhat() == fxt.t1->onWhat() && verifyShell(v,fxt.t1->getNeigh(fxt.i1),shell)){
	extendCavity (shell,cavity,fxt);
      }
      else if (verifyShell(v,fxt.t1,shell)){
	return -1;
      	removeFromCavity (shell,cavity,fxt);
      }
      else {
	return -1;
      }
    }
    wrong.erase(wrong.begin());
  }
  //  printf("after : shell size %d cavity size %d\n",shell.size(),cavity.size());
  return 1;
}

void findCavity(std::list<faceXtet> & shell,
                std::list<MTet4*> & cavity,
                MVertex *v,
                MTet4 *t)
{
  t->setDeleted(true);
  cavity.push_back(t);
  for (std::list<MTet4*>::iterator it = --cavity.end(); it != cavity.end(); ++it) {
    for (int i = 0; i < 4; i++) {
      MTet4 *neigh = (*it)->getNeigh(i);
      faceXtet fxt(*it, i);
      if (!neigh)
        shell.push_back(fxt);
      else if (!neigh->isDeleted()) {
        int circ = neigh->inCircumSphere(v);
        if (circ && (neigh->onWhat() == (*it)->onWhat())) {
          neigh->setDeleted(true);
          cavity.push_back(neigh);
        }
        else {
          shell.push_back(fxt);
        }
      }
    }
  }
}

void printTets (const char *fn, std::list<MTet4*> &cavity, bool force = false )
{
  FILE *f = Fopen (fn,"w");
  if(f){
    fprintf(f,"View \"\"{\n");
    std::list<MTet4*>::iterator ittet = cavity.begin();
    std::list<MTet4*>::iterator ittete = cavity.end();
    while (ittet != ittete){
      MTet4 *tet = *ittet;
      if (force || !tet->isDeleted()){
        MTetrahedron *t = tet->tet();
        t->writePOS (f, false,false,false,true,false,false);
      }
      ittet++;
    }
    fprintf(f,"};\n");
    fclose(f);
  }
}


bool insertVertexB(std::list<faceXtet> &shell,
		   std::list<MTet4*> &cavity,
		   MVertex *v,
		   double lc1,
		   double lc2,
		   std::vector<double> &vSizes,
		   std::vector<double> &vSizesBGM,
		   MTet4 *t,
		   MTet4Factory &myFactory,
		   std::set<MTet4*,compareTet4Ptr> &allTets)
{
  std::vector<faceXtet> conn;
  std::vector<MTet4*> new_cavity;


  MTet4** newTets = new MTet4*[shell.size()];
  int k = 0;

  std::list<faceXtet>::iterator it = shell.begin();

  bool onePointIsTooClose = false;
  while (it != shell.end()){
    MTetrahedron *tr = new MTetrahedron(it->getVertex(0), it->getVertex(1), it->getVertex(2), v);
    MTet4 *t4 = myFactory.Create(tr, vSizes, vSizesBGM, lc1, lc2);
    t4->setOnWhat(t->onWhat());

    double d1 = distance (it->v[0],v);
    double d2 = distance (it->v[1],v);
    double d3 = distance (it->v[2],v);
    
    double lc = Extend2dMeshIn3dVolumes() ? std::min(lc1, lc2) : lc2;
    if (d1 < lc * .05 || d2 < lc * .05 || d3 < lc * .05) {
      //      printf("coucou %g %g %g %g\n",lc,d1,d2,d3);
      onePointIsTooClose = true;
    }

    newTets[k++] = t4;
    // all new tets are pushed front in order to ba able to destroy
    // them if the cavity is not star shaped around the new vertex.
    // here, we better use robust perdicates that implies to orient
    // all faces and ensure that the tets are all oriented the same.
    new_cavity.push_back(t4);
    MTet4 *otherSide = it->t1->getNeigh(it->i1);

    if (otherSide)
      new_cavity.push_back(otherSide);
    ++it;
  }
  if (!onePointIsTooClose){
    connectTets_vector2(new_cavity,conn);
    allTets.insert(newTets, newTets + shell.size());
    delete [] newTets;
    return true;
  }
  else /* one point is too close */ {
    for (unsigned int i = 0; i <shell.size(); i++) myFactory.Free(newTets[i]);
    delete [] newTets;
    std::list<MTet4*>::iterator ittet = cavity.begin();
    std::list<MTet4*>::iterator ittete = cavity.end();
    while(ittet != ittete){
      (*ittet)->setDeleted(false);
      ++ittet;
    }
    return false;
  }
}

static void setLcs(MTriangle *t, std::map<MVertex*, double, MVertexLessThanNum> &vSizes,
                   std::set<MVertex*,MVertexLessThanNum> &bndVertices)
{

  for(int i = 0; i < 3; i++){
    bndVertices.insert(t->getVertex(i));
    MEdge e = t->getEdge(i);
    MVertex *vi = e.getVertex(0);
    MVertex *vj = e.getVertex(1);
    double dx = vi->x()-vj->x();
    double dy = vi->y()-vj->y();
    double dz = vi->z()-vj->z();
    double l = sqrt(dx * dx + dy * dy + dz * dz);
    std::map<MVertex*,double, MVertexLessThanNum>::iterator iti = vSizes.find(vi);
    std::map<MVertex*,double, MVertexLessThanNum>::iterator itj = vSizes.find(vj);
    // use largest edge length
    if (iti == vSizes.end() || iti->second < l) vSizes[vi] = l;
    if (itj == vSizes.end() || itj->second < l) vSizes[vj] = l;
  }

  /*
  double l = 0;
  for(int i = 0; i < 3; i++){
    MEdge e = t->getEdge(i);
    MVertex *vi = e.getVertex(0);
    MVertex *vj = e.getVertex(1);
    double dx = vi->x()-vj->x();
    double dy = vi->y()-vj->y();
    double dz = vi->z()-vj->z();
    l += sqrt(dx * dx + dy * dy + dz * dz);
  }
  l /= 3;
  for(int i = 0; i < 3; i++){
    bndVertices.insert(t->getVertex(i));
    MEdge e = t->getEdge(i);
    MVertex *vi = e.getVertex(0);
    MVertex *vj = e.getVertex(1);
    std::map<MVertex*,double>::iterator iti = vSizes.find(vi);
    std::map<MVertex*,double>::iterator itj = vSizes.find(vj);
    // use largest edge length
    if (iti == vSizes.end() || iti->second > l) vSizes[vi] = l;
    if (itj == vSizes.end() || itj->second > l) vSizes[vj] = l;
  }
  */
}

static void setLcs(MTetrahedron *t, std::map<MVertex*, double,MVertexLessThanNum> &vSizes,
                   std::set<MVertex*,MVertexLessThanNum> &bndVertices)
{
  for (int i = 0; i < 4; i++){
    for (int j = i + 1; j < 4; j++){
      MVertex *vi = t->getVertex(i);
      MVertex *vj = t->getVertex(j);
      double dx = vi->x()-vj->x();
      double dy = vi->y()-vj->y();
      double dz = vi->z()-vj->z();
      double l = sqrt(dx * dx + dy * dy + dz * dz);
      std::map<MVertex*,double,MVertexLessThanNum>::iterator iti = vSizes.find(vi);
      std::map<MVertex*,double,MVertexLessThanNum>::iterator itj = vSizes.find(vj);
      std::set<MVertex*,MVertexLessThanNum>::iterator itvi = bndVertices.find(vi);
      std::set<MVertex*,MVertexLessThanNum>::iterator itvj = bndVertices.find(vj);
      // smallest tet edge
      if (itvi == bndVertices.end() &&
          (iti == vSizes.end() || iti->second > l)) vSizes[vi] = l;
      if (itvj == bndVertices.end() &&
          (itj == vSizes.end() || itj->second > l)) vSizes[vj] = l;
    }
  }
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


void non_recursive_classify(MTet4 *t, std::list<MTet4*> &theRegion,
			    std::set<GFace*> &faces_bound, GRegion *bidon,
			    GModel *model, const fs_cont &search)
{

  std::stack<MTet4*> _stackounette;
  _stackounette.push(t);

  bool touchesOutsideBox = false;

  while(!_stackounette.empty()){
    t = _stackounette.top();
    _stackounette.pop();
    if (!t) {
      Msg::Error("a tet is not connected by a boundary face");
      touchesOutsideBox = true;
    }
    else if (!t->onWhat()) {
      theRegion.push_back(t);
      t->setOnWhat(bidon);
      bool FF[4] = {0,0,0,0};
      for (int i = 0; i < 4; i++){
	GFace* gfound = findInFaceSearchStructure (t->tet()->getVertex(faces[i][0]),
						   t->tet()->getVertex(faces[i][1]),
						   t->tet()->getVertex(faces[i][2]),
						   search);
	if (gfound){
	  FF[i] = true;
	  if (faces_bound.find(gfound) == faces_bound.end())
	    faces_bound.insert(gfound);
	}
      }
      for (int i = 0; i < 4; i++){
	if (!FF[i])
	  _stackounette.push(t->getNeigh(i));
      }
    }
  }
  if (touchesOutsideBox)faces_bound.clear();
}



void adaptMeshGRegion::operator () (GRegion *gr)
{
  const qmTetrahedron::Measures qm = qmTetrahedron::QMTET_GAMMA;

  typedef std::list<MTet4 *> CONTAINER ;
  CONTAINER allTets;
  for(unsigned int i = 0; i < gr->tetrahedra.size(); i++){
    allTets.push_back(new MTet4(gr->tetrahedra[i], qm));
  }
  gr->tetrahedra.clear();

  std::set<MFace, Less_Face> allEmbeddedFaces;
  createAllEmbeddedFaces (gr, allEmbeddedFaces);
  std::set<MEdge, Less_Edge> allEmbeddedEdges;
  createAllEmbeddedEdges (gr, allEmbeddedEdges);
  connectTets(allTets.begin(),allTets.end(),&allEmbeddedFaces);

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
            if (collapseVertex(newTets, *it, i, j, qmTetrahedron::QMTET_GAMMA)){
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
	    MEdge ed = (*it)->tet()->getEdge(i);
	    if (allEmbeddedEdges.find(ed) == allEmbeddedEdges.end()){
	      if (edgeSwap(newTets, *it, i, qm)) {
		nbESwap++;
		break;
	      }
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

void optimizeMesh(GRegion *gr, const qmTetrahedron::Measures &qm)
{
  // well, this should not be true !!!
  // if (gr->hexahedra.size() ||
  //      gr->prisms.size() ||
  //      gr->pyramids.size())return;
  if (!gr->tetrahedra.size())return;


  typedef std::list<MTet4 *> CONTAINER ;
  CONTAINER allTets;
  for(unsigned int i = 0; i < gr->tetrahedra.size(); i++){
    MTet4 * t = new MTet4(gr->tetrahedra[i], qm);
    t->setOnWhat(gr);
    allTets.push_back(t);
  }
  gr->tetrahedra.clear();

  std::set<MFace, Less_Face> allEmbeddedFaces;
  createAllEmbeddedFaces (gr, allEmbeddedFaces);
  connectTets(allTets.begin(),allTets.end(),&allEmbeddedFaces);
  std::set<MEdge, Less_Edge> allEmbeddedEdges;
  createAllEmbeddedEdges (gr, allEmbeddedEdges);

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
    //    printf("coucou\n");
    std::vector<MTet4*> newTets;
    for (CONTAINER::iterator it = allTets.begin(); it != allTets.end(); ++it){
      if (!(*it)->isDeleted()){
        double qq = (*it)->getQuality();
        if (qq < qMin){
          for (int i = 0; i < 4; i++){
            if (0 && faceSwap(newTets, *it, i, qm)){
              nbFSwap++;
              break;
            }
          }
        }
      }
    }
    //    printf("coucou\n");

    illegals.clear();
    for (int i = 0; i < nbRanges; i++) quality_ranges[i] = 0;

    //   printf("coucou\n");
    for (CONTAINER::iterator it = allTets.begin(); it != allTets.end(); ++it){
      if (!(*it)->isDeleted()){
        double qq = (*it)->getQuality();
        if (qq < qMin){
          for (int i = 0; i < 6; i++){
	    MEdge ed = (*it)->tet()->getEdge(i);
	    if (allEmbeddedEdges.find(ed) == allEmbeddedEdges.end()){
	      if (edgeSwap(newTets, *it, i, qm)) {
		nbESwap++;
		break;
	      }
	    }
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
    //    printf("coucou\n");

    if (!newTets.size()){
      break;
    }

    //    printf("coucou\n");
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
    //    printf("coucou\n");

    // relocate vertices
    if (!gr->hexahedra.size() &&
        !gr->prisms.size() &&
        !gr->pyramids.size()){
      for (CONTAINER::iterator it = allTets.begin();it!=allTets.end();++it){
	if (!(*it)->isDeleted()){
	  double qq = (*it)->getQuality();
	  if (qq < qMin)
	    for (int i = 0; i < 4; i++){
	      if (smoothVertex(*it, i, qm)) nbReloc++;
	    }
	}
      }
    }

    //    printf("coucou\n");
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
    //    printf("coucou\n");
    double t2 = Cpu();
    Msg::Info("Opti : (%d,%d,%d) = %12.5E QBAD %12.5E QAVG %12.5E (%8.3f sec)",
              nbESwap, nbFSwap, nbReloc, totalVolumeb, worst, avg / count, t2 - t1);
  }

  if (illegals.size()){
    Msg::Info("Opti : %d ill-shaped tets are still in the mesh", illegals.size());
  }
  else{
    Msg::Info("Opti : no ill-shaped tets in the mesh ;-)");
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


double tetcircumcenter(double a[3], double b[3], double c[3], double d[3],
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

static void memoryCleanup(MTet4Factory &myFactory, std::set<MTet4*, compareTet4Ptr> &allTets){
  //  int n1 = allTets.size();
  std::set<MTet4*,compareTet4Ptr>::iterator itd = allTets.begin();
  while(itd != allTets.end()){
    if((*itd)->isDeleted()){
      myFactory.Free((*itd));
      allTets.erase(itd++);
    }
    else
      itd++;
  }
  //  Msg::Info("cleaning up the memory %d -> %d", n1, allTets.size());
}

int isCavityCompatibleWithEmbeddedEdges(std::list<MTet4*> &cavity,
					std::list<faceXtet> &shell,
					std::set<MEdge, Less_Edge> &allEmbeddedEdges){

  //  printf("coucou\n");
  std::set<MEdge,Less_Edge> ed;
  for (std::list<faceXtet>::iterator it = shell.begin(); it != shell.end();it++){
    ed.insert(MEdge(it->v[0],it->v[1]));
    ed.insert(MEdge(it->v[1],it->v[2]));
    ed.insert(MEdge(it->v[2],it->v[0]));
  }

  for (std::list<MTet4*>::iterator itc = cavity.begin(); itc != cavity.end(); ++itc){
    for (int j=0;j<6;j++){
      MEdge e = (*itc)->tet()->getEdge(j);
      if (ed.find(e) == ed.end() && allEmbeddedEdges.find(e) != allEmbeddedEdges.end()){
	return 0;
      }
    }
  }
  return 1;
}

void insertVerticesInRegion (GRegion *gr, int maxVert, bool _classify)
{

  //printf("sizeof MTet4 = %d sizeof MTetrahedron %d sizeof(MVertex) %d\n",
  //       sizeof(MTet4), sizeof(MTetrahedron), sizeof(MVertex));


  std::vector<double> vSizes;
  std::vector<double> vSizesBGM;
  MTet4Factory myFactory(1600000);
  std::set<MTet4*, compareTet4Ptr> &allTets = myFactory.getAllTets();
  int NUM = 0;

	//	printTets ("before.pos", cavity, true);
  std::set<MEdge, Less_Edge> allEmbeddedEdges;
  createAllEmbeddedEdges (gr, allEmbeddedEdges);

  { // leave this in a block so the map gets deallocated directly
    std::map<MVertex*, double,MVertexLessThanNum> vSizesMap;
    std::set<MVertex*,MVertexLessThanNum> bndVertices;

    std::set<MEdge, Less_Edge>::iterator it = allEmbeddedEdges.begin();
    while (it != allEmbeddedEdges.end()){
      MVertex *vi = it->getVertex(0);
      MVertex *vj = it->getVertex(1);
      double dx = vi->x()-vj->x();
      double dy = vi->y()-vj->y();
      double dz = vi->z()-vj->z();
      double l = sqrt(dx * dx + dy * dy + dz * dz);
      std::map<MVertex*,double,MVertexLessThanNum>::iterator iti = vSizesMap.find(vi);
      std::map<MVertex*,double,MVertexLessThanNum>::iterator itj = vSizesMap.find(vj);
      // smallest tet edge
      if (iti == vSizesMap.end() || iti->second > l) vSizesMap[vi] = l;
      if (itj == vSizesMap.end() || itj->second > l) vSizesMap[vj] = l;
      ++it;
    }

    for(GModel::fiter it = gr->model()->firstFace(); it != gr->model()->lastFace(); ++it){
      GFace *gf = *it;
      for(unsigned int i = 0; i < gf->triangles.size(); i++){
        setLcs(gf->triangles[i], vSizesMap, bndVertices);
      }
    }
    for(unsigned int i = 0; i < gr->tetrahedra.size(); i++)
      setLcs(gr->tetrahedra[i], vSizesMap, bndVertices);
    for(std::map<MVertex*, double, MVertexLessThanNum>::iterator it = vSizesMap.begin();
        it != vSizesMap.end(); ++it){
      it->first->setIndex(NUM++);
      vSizes.push_back(it->second);
      vSizesBGM.push_back(it->second);
    }
  }

  for(unsigned int i = 0; i < gr->tetrahedra.size(); i++){
    gr->tetrahedra[i]->setVolumePositive();
    allTets.insert(myFactory.Create(gr->tetrahedra[i], vSizes,vSizesBGM));
  }

  gr->tetrahedra.clear();
  connectTets(allTets.begin(), allTets.end());

  // classify the tets on the right region
  // Msg::Info("reclassifying %d tets", allTets.size());


  if (_classify) {
    fs_cont search;
    buildFaceSearchStructure(gr->model(), search);
    for(MTet4Factory::iterator it = allTets.begin(); it != allTets.end(); ++it){
      if(!(*it)->onWhat()){
	std::list<MTet4*> theRegion;
	std::set<GFace *> faces_bound;
	GRegion *bidon = (GRegion*)123;
	double _t1 = Cpu();
	Msg::Debug("start with a non classified tet");
	non_recursive_classify(*it, theRegion, faces_bound, bidon, gr->model(), search);
	double _t2 = Cpu();
	Msg::Debug("found %d tets with %d faces (%g sec for the classification)",
		   theRegion.size(), faces_bound.size(), _t2 - _t1);
	GRegion *myGRegion = getRegionFromBoundingFaces(gr->model(), faces_bound);
	if(myGRegion){ // a geometrical region associated to the list of faces has been found
	  Msg::Info("Found region %d", myGRegion->tag());
	  for(std::list<MTet4*>::iterator it2 = theRegion.begin();
	      it2 != theRegion.end(); ++it2) (*it2)->setOnWhat(myGRegion);
	}
	else {
	  // the tets are in the void
	  Msg::Info("Found void region");
	  for(std::list<MTet4*>::iterator it2 = theRegion.begin();
	      it2 != theRegion.end(); ++it2)(*it2)->setDeleted(true);

	}
      }
    }
    search.clear();
  }
  else {
    // FIXME ... too simple
    for(MTet4Factory::iterator it = allTets.begin(); it != allTets.end(); ++it)
      (*it)->setOnWhat(gr);
  }

  for(MTet4Factory::iterator it = allTets.begin(); it!=allTets.end(); ++it){
    (*it)->setNeigh(0, 0);
    (*it)->setNeigh(1, 0);
    (*it)->setNeigh(2, 0);
    (*it)->setNeigh(3, 0);
  }
  // store all embedded faces
  std::set<MFace, Less_Face> allEmbeddedFaces;
  createAllEmbeddedFaces (gr, allEmbeddedFaces);
  connectTets(allTets.begin(), allTets.end(),&allEmbeddedFaces);
  Msg::Debug("All %d tets were connected", allTets.size());

  //  printf("===========================>   %d embedded edges \n",allEmbeddedEdges.size());

  // here the classification should be done

  int ITER = 0, REALCOUNT = 0;
  int NB_CORRECTION_OF_CAVITY = 0;
  int COUNT_MISS_1 = 0;
  int COUNT_MISS_2 = 0;

  double t1 = Cpu();
  // MAIN LOOP IN DELAUNAY INSERTION STARTS HERE

  while(1){
    if (COUNT_MISS_2 > 100000)break;
    if (ITER >= maxVert)break;
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
      if(ITER++ % 5000 == 0)
        Msg::Info("%d points created - Worst tet radius is %g (PTS removed %d %d)",
                 REALCOUNT, worst->getRadius(), COUNT_MISS_1,COUNT_MISS_2);
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

      tetcircumcenter(pa,pb,pc,pd, center, NULL, NULL, NULL);
      
      
      //// A TEST !!!
      std::list<faceXtet> shell;
      std::list<MTet4*> cavity;
      MVertex vv (center[0], center[1], center[2], worst->onWhat());
      findCavity(shell, cavity, &vv, worst);

      bool FOUND = false;
      for (std::list<MTet4*>::iterator itc = cavity.begin(); itc != cavity.end(); ++itc){
	MTetrahedron *toto = (*itc)->tet();
	//	(*itc)->setDeleted(false);
	toto->xyz2uvw(center,uvw);
	if (toto->isInside(uvw[0], uvw[1], uvw[2])){
	  worst = (*itc);
	  FOUND = true;
	  break;
	}
      }
      /// END TETS

      if (FOUND && !allEmbeddedEdges.empty()){
        FOUND = isCavityCompatibleWithEmbeddedEdges(cavity, shell, allEmbeddedEdges);
      }

      bool correctedCavityIncompatibleWithEmbeddedEdge = false;

      if(FOUND){
        MVertex *v = new MVertex(center[0], center[1], center[2], worst->onWhat());
        v->setIndex(NUM++);

	//	printTets ("before.pos", cavity, true);
	bool starShaped = true;
	bool correctCavity = false;
	while (1){
	  int k = makeCavityStarShaped (shell, cavity, v);
	  if (k == -1){starShaped = false ; break;}
	  else if (k == 0) break;
	  else if (k == 1) correctCavity = true;
	}
	if (correctCavity && starShaped) {
	  NB_CORRECTION_OF_CAVITY ++;
	  if(!isCavityCompatibleWithEmbeddedEdges(cavity, shell, allEmbeddedEdges)){
	    correctedCavityIncompatibleWithEmbeddedEdge = true;
	  }
	}
	double lc1 =
	  (1 - uvw[0] - uvw[1] - uvw[2]) * vSizes[worst->tet()->getVertex(0)->getIndex()] +
	  uvw[0] * vSizes[worst->tet()->getVertex(1)->getIndex()] +
	  uvw[1] * vSizes[worst->tet()->getVertex(2)->getIndex()] +
	  uvw[2] * vSizes[worst->tet()->getVertex(3)->getIndex()];
	double lc2 = BGM_MeshSize(gr, 0, 0, center[0], center[1], center[2]);

	
	if(correctedCavityIncompatibleWithEmbeddedEdge || !starShaped || !insertVertexB(shell,cavity,v, lc1, lc2, vSizes, vSizesBGM, worst, myFactory, allTets)){
	  COUNT_MISS_1++;
	  myFactory.changeTetRadius(allTets.begin(), 0.);
	  for (std::list<MTet4*>::iterator itc = cavity.begin(); itc != cavity.end(); ++itc)
	    (*itc)->setDeleted(false);
	  delete v;
	  NUM--;
	}
	else{
	  vSizes.push_back(lc1);
	  vSizesBGM.push_back(lc2);
	  REALCOUNT++;
	  v->onWhat()->mesh_vertices.push_back(v);
	}
      }

      else{
        myFactory.changeTetRadius(allTets.begin(), 0.0);
	COUNT_MISS_2++;
	for (std::list<MTet4*>::iterator itc = cavity.begin(); itc != cavity.end(); ++itc)  (*itc)->setDeleted(false);
      }
    }

    // Normally, a tet mesh contains about 6 times more tets than
    // vertices. This allows to clean up the set of tets when lots of
    // deleted ones are present in the mesh
    if(allTets.size() > 7 * vSizes.size() && ITER > 1000){
      memoryCleanup(myFactory, allTets);
    }
  }

  memoryCleanup(myFactory, allTets);
  double t2 = Cpu();
  double dt = (t2-t1);
  int COUNT_MISS = COUNT_MISS_1+COUNT_MISS_2;
  Msg::Info("3D point insertion terminated (%d points created):",
            (int)vSizes.size());
  Msg::Info(" - %d Delaunay cavities modified for star shapeness",
            NB_CORRECTION_OF_CAVITY);
  Msg::Info(" - %d points could not be inserted",
            COUNT_MISS);
  Msg::Info(" - %d tetrahedra created in %g sec. (%d tets/sec.)",
            allTets.size(), dt, (int)(allTets.size() / dt));

  // relocate vertices
  int nbReloc = 0;
  for (int SM=0;SM<CTX::instance()->mesh.nbSmoothing;SM++){
    for(MTet4Factory::iterator it = allTets.begin(); it != allTets.end(); ++it){
      if (!(*it)->isDeleted()){
	double qq = (*it)->getQuality();
	if (qq < .4)
	  for (int i = 0; i < 4; i++){
	    if (smoothVertex(*it, i, qmTetrahedron::QMTET_GAMMA)) nbReloc++;
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


///// do a 3D delaunay mesh assuming a set of vertices

void delaunayMeshIn3D(std::vector<MVertex*> &v, std::vector<MTetrahedron*> &result, bool removeBox) {
  double t1 = Cpu();
  delaunayTriangulation (1, 1, v, result);
  double t2 = Cpu();
  Msg::Info("Tetrahedrization of %d points in %g seconds",v.size(),t2-t1);
}
