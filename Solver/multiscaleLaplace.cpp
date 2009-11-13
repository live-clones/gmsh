#include "multiscaleLaplace.h"
#include "GmshConfig.h"
#include "GmshDefines.h"
#include "Numeric.h"
#include "OS.h"
#include "SBoundingBox3d.h"
#include "SPoint3.h"
#include "dofManager.h"
#include "laplaceTerm.h"
#include "linearSystemCSR.h"
#include "linearSystemFull.h"

// starting form a list of elements, returns
// lists of lists that are all simply connected
static void recur_connect (MVertex *v,
			   std::multimap<MVertex*,MElement*> &v2e,
			   std::set<MElement*> &group,
			   std::set<MVertex*> &touched){
  if (touched.find(v) != touched.end())return;
  touched.insert(v);
  for (std::multimap <MVertex*,MElement*>::iterator it = v2e.lower_bound(v);
	 it != v2e.upper_bound(v) ; ++it){
    group.insert(it->second);
    for (int i=0;i<it->second->getNumVertices();++i){
      recur_connect (it->second->getVertex(i),v2e,group,touched);
    }
  }
}
static void connectedRegions (std::vector<MElement*> &elements,
			      std::vector<std::vector<MElement*> > &regions)
{
  // build vertex 2 elements
  std::multimap<MVertex*,MElement*> v2e;
  for (int i=0;i<elements.size();++i){
    for (int j=0;j<elements[i]->getNumVertices();j++){
      v2e.insert(std::make_pair(elements[i]->getVertex(j),elements[i]));
    }
  }
  while (!v2e.empty()){
    std::set<MElement*> group;
    std::set<MVertex*> touched;
    recur_connect (v2e.begin()->first,v2e,group,touched);
    std::vector<MElement*> temp;
    temp.insert(temp.begin(), group.begin(), group.end());
    regions.push_back(temp);
    for ( std::set<MVertex*>::iterator it = touched.begin() ; it != touched.end();++it)
      v2e.erase(*it);
  }
}


static void printLevel ( const char* fn,
			 std::vector<MElement *> &elements,
			 std::map<MVertex*,SPoint2> &coordinates,
			 double version, bool param){

  bool binary = false;
  FILE *fp = fopen (fn, "w");
  fprintf(fp, "$MeshFormat\n");  
  fprintf(fp, "%g %d %d\n", version, binary ? 1 : 0, (int)sizeof(double));
  fprintf(fp, "$EndMeshFormat\n");  

  fprintf(fp,"$Nodes\n%d\n",coordinates.size());
  std::map<MVertex*,SPoint2> :: iterator it = coordinates.begin();
  int index = 1;
  for (; it != coordinates.end() ; ++it){
    it->first->setIndex(index++);
    if (param) fprintf(fp,"%d %g %g 0\n",it->first->getIndex(),it->second[0],it->second[1]);
    else fprintf(fp,"%d %g %g %g\n",it->first->getIndex(),
		 it->first->x(),it->first->y(),it->first->z());
  }
  fprintf(fp,"$EndNodes\n",elements.size());
  
  fprintf(fp,"$Elements\n%d\n",elements.size());
  for (int i=0;i<elements.size();i++){
    elements[i]->writeMSH(fp);
  }
  fprintf(fp,"$EndElements\n%d\n",elements.size());
  
  fclose(fp);
}


multiscaleLaplace::multiscaleLaplace (std::vector<MElement *> &elements,
				      std::vector<MVertex*> &boundaryNodes,
				      std::vector<double> &linearAbscissa) {

#if defined(HAVE_TAUCS)
  _lsys = new linearSystemCSRTaucs<double>;
#elif defined(HAVE_GMM)
  linearSystemGmm<double> *_lsysb = new linearSystemGmm<double>;
  _lsysb->setGmres(1);
  _lsys = _lsysb;
#else
  _lsys = new linearSystemFull<double>;
#endif
  
  multiscaleLaplaceLevel *level = new multiscaleLaplaceLevel;
  level->elements.insert(level->elements.begin(),elements.begin(),elements.end());
  for(unsigned int i = 0; i < boundaryNodes.size(); i++){
    MVertex *v = boundaryNodes[i];
    const double theta = 2 * M_PI * linearAbscissa[i];
    level->coordinates[v] = SPoint2(cos(theta),sin(theta));
  }
  levels.push_back(level);
  level->recur = 0;
  level->region = 0;
  parametrize(*level);
}

void multiscaleLaplace::parametrize (multiscaleLaplaceLevel & level){
  simpleFunction<double> ONE(1.0);
  std::set<MVertex*> allNodes;
  for(unsigned int i = 0; i < level.elements.size(); ++i){
    MElement *e = level.elements[i];
    for(unsigned int j = 0; j<e->getNumVertices(); ++j){
      allNodes.insert(e->getVertex(j));
    }
  }  
  std::map<MVertex*,SPoint2> solution;
  // PARAMETRIZE ---------------------------------
  for (int step =0 ; step<2 ; step++){
    dofManager<double> myAssembler(_lsys);
    for(std::map<MVertex*,SPoint2>::iterator it = level.coordinates.begin();
	it != level.coordinates.end(); ++it){
      MVertex *v = it->first;
      myAssembler.fixVertex(v, 0, 1, it->second[step]);
    }
    // do the numbering
    for(std::set<MVertex *>::iterator itv = allNodes.begin(); itv !=allNodes.end() ; ++itv){
      MVertex *v = *itv;
      myAssembler.numberVertex(v, 0, 1);
    }
    // assemble
    laplaceTerm laplace(0, 1, &ONE);
    for(unsigned int i = 0; i < level.elements.size(); ++i){
      MElement *e = level.elements[i];
      SElement se(e);
      laplace.addToMatrix(myAssembler, &se);
    }
    // solve
    if (myAssembler.sizeOfR() != 0) _lsys->systemSolve();
    // get the values 
    int count = 0;
    for(std::set<MVertex *>::iterator itv = allNodes.begin(); itv !=allNodes.end() ; ++itv){
      MVertex *v = *itv;
      double value = myAssembler.getDofValue(v, 0, 1);      
      if (step == 0)solution[v] = SPoint2(value,0);
      else solution[v] = SPoint2(solution[v][0],value);
    }    
    _lsys->clear();
  }

  // compute the bbox of the parametric space
  SBoundingBox3d bbox;
  for(std::set<MVertex *>::iterator itv = allNodes.begin(); itv !=allNodes.end() ; ++itv){
    MVertex *v = *itv;
    SPoint2 p = solution[v];
    bbox += SPoint3(p.x(),p.y(),0.0);
  }
  double global_size = bbox.max().distance(bbox.min());
  // check elements that are too small
  std::vector<MElement*> tooSmall, goodSize;
  std::set<MVertex*> goodSizev;
  for(unsigned int i = 0; i < level.elements.size(); ++i){
    MElement *e = level.elements[i];
    std::vector<SPoint2> localCoord;
    SBoundingBox3d local;
    for(unsigned int j = 0; j<e->getNumVertices(); ++j){
      SPoint2 p = solution[e->getVertex(j)];
      local += SPoint3(p.x(),p.y(),0.0);
    }    
    double local_size = local.max().distance(local.min());    
    if (local_size < 1.e-6 * global_size){
      tooSmall.push_back(e);
    }
    else{
      goodSize.push_back(e);
      for(unsigned int j = 0; j<e->getNumVertices(); ++j){
	goodSizev.insert(e->getVertex(j));
	level.coordinates[e->getVertex(j)] = solution[e->getVertex(j)];
      }    
    }
  }
  // only keep the right elements and nodes
  level.elements = goodSize;

  //END PARAMETRIZE ---------------------------------
  // DEBUG
  char name[245];
  sprintf(name,"multiscale_level%d_region%d_param.msh",level.recur, level.region);
  printLevel (name,level.elements,level.coordinates,1.0,true);
  sprintf(name,"multiscale_level%d_region%d_real.msh",level.recur, level.region);
  printLevel (name,level.elements,level.coordinates,1.0,false);
  // END DEBUG

  std::vector<std::vector<MElement*> > regions;
  connectedRegions (tooSmall,regions);

  Msg::Info("%d connected regions\n",regions.size());
  
  for (int i=0;i< regions.size() ; i++){    
    // check nodes that appear both on too small and good size
    // and set it to the next level
    // maybe more than one level should be created here
    std::set<MVertex*> tooSmallv;
    for (int k=0; k<regions[i].size() ; k++){
      MElement *e = regions[i][k];
      for(unsigned int j = 0; j<e->getNumVertices(); ++j){
	tooSmallv.insert(e->getVertex(j));
      }    
    }
    
    multiscaleLaplaceLevel *nextLevel = new multiscaleLaplaceLevel;
    nextLevel->elements = regions[i];
    nextLevel->recur = level.recur+1;
    nextLevel->region = i;
    SBoundingBox3d smallB;
    for(std::set<MVertex *>::iterator itv = tooSmallv.begin(); itv !=tooSmallv.end() ; ++itv){
      SPoint2 p = solution[*itv];
      nextLevel->center += p;
      smallB += SPoint3(p.x(),p.y(),0.0);
    }
    nextLevel->center *= (1./(double)tooSmallv.size());
    nextLevel->scale = smallB.max().distance(smallB.min());
    
    for(std::set<MVertex *>::iterator itv = tooSmallv.begin(); itv !=tooSmallv.end() ; ++itv){
      MVertex *v = *itv;
      if (goodSizev.find(v) != goodSizev.end()){
	nextLevel->coordinates[v] =  (solution[v]-nextLevel->center)*(1./nextLevel->scale);
      }
    }
    // recursively continue if tooSmall is not empty
    if (!tooSmall.empty()){
      Msg::Info("Multiscale Laplace, level %d region %d, %d too small",level.recur,level.region,tooSmall.size());
      levels.push_back(nextLevel);
      parametrize (*nextLevel);
    }
    else {
      Msg::Info("Multiscale Laplace, level %d DONE",level.recur);
      delete nextLevel;
    }
  }
}
