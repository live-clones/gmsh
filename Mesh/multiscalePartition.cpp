#include "multiscalePartition.h"
#include "GmshConfig.h"
#include "GmshDefines.h"
#include "meshPartition.h"
#include "MEdge.h"
#include "MElement.h"
#include "multiscaleLaplace.h"
#include "Context.h"

static void recur_connect(MVertex *v,
                          std::multimap<MVertex*,MEdge> &v2e,
                          std::set<MEdge,Less_Edge> &group,
                          std::set<MVertex*> &touched)
{
  if (touched.find(v) != touched.end())return;

  touched.insert(v);
  for (std::multimap <MVertex*,MEdge>::iterator it = v2e.lower_bound(v); 
       it != v2e.upper_bound(v) ; ++it){
    group.insert(it->second);
    for (int i=0;i<it->second.getNumVertices();++i){
      recur_connect (it->second.getVertex(i),v2e,group,touched);
    }
  }

}

static int connected_bounds (std::vector<MEdge> &edges,  std::vector<std::vector<MEdge> > &boundaries)
{
  std::multimap<MVertex*,MEdge> v2e;
  for (unsigned i = 0; i < edges.size(); ++i){
    for (int j=0;j<edges[i].getNumVertices();j++){
      v2e.insert(std::make_pair(edges[i].getVertex(j),edges[i]));
    }
  }
  while (!v2e.empty()){
    std::set<MEdge, Less_Edge> group;
    std::set<MVertex*> touched;
    recur_connect (v2e.begin()->first,v2e,group,touched);
    std::vector<MEdge> temp;
    temp.insert(temp.begin(), group.begin(), group.end());
    boundaries.push_back(temp);
    for (std::set<MVertex*>::iterator it = touched.begin() ; it != touched.end();++it)
      v2e.erase(*it);
  }

  return boundaries.size();
}


static int getGenus (std::vector<MElement *> &elements,  
		     std::vector<std::vector<MEdge> > &boundaries)
{

  //We suppose MElements are simply connected
 
  std::set<MEdge, Less_Edge> es;
  std::set<MVertex*> vs;
  int N = 0;
  for(unsigned int i = 0; i < elements.size(); i++){
    N++;
    MElement *e = elements[i];
    for(int j = 0; j < e->getNumVertices(); j++){
      vs.insert(e->getVertex(j));
    }
    for(int j = 0; j < e->getNumEdges(); j++){
      es.insert(e->getEdge(j));
    }
  }
  
  int poincare = vs.size() - es.size() + N; 

  //compute connected boundaries 
  int nbBounds = 0;
  std::vector<MEdge> bEdges;  
  for(unsigned int i = 0; i < elements.size(); i++){
    for(int j = 0; j < elements[i]->getNumEdges(); j++){
      MEdge me =  elements[i]->getEdge(j);
      if(std::find(bEdges.begin(), bEdges.end(), me) == bEdges.end())
	 bEdges.push_back(me);
      else
	 bEdges.erase(std::find(bEdges.begin(), bEdges.end(),me));
    }    
  }    
  nbBounds = connected_bounds(bEdges, boundaries);
  int genus = (int)(-poincare + 2 - nbBounds)/2;

  //printf("************** partition has %d boundaries and genus =%d \n", nbBounds, genus);
  
  return genus;

}

static int getAspectRatio(std::vector<MElement *> &elements, 
                          std::vector<std::vector<MEdge> > &boundaries)
{ 
  std::set<MVertex*> vs;
  for(unsigned int i = 0; i < elements.size(); i++){
    MElement *e = elements[i];
    for(int j = 0; j < e->getNumVertices(); j++){
      vs.insert(e->getVertex(j));
    }
  }
  SBoundingBox3d bb;
  SOrientedBoundingBox obbox ;
  std::vector<SPoint3> vertices;
  for (std::set<MVertex* >::iterator it = vs.begin(); it != vs.end(); it++){
    SPoint3 pt((*it)->x(),(*it)->y(), (*it)->z());
    vertices.push_back(pt);
    bb += pt;
  }
  
  //obbox =  SOrientedBoundingBox::buildOBB(vertices);
  //double H = obbox.getMaxSize(); 
  double H = norm(SVector3(bb.max(), bb.min()));
  
  double D = H;
  for (unsigned int i = 0; i < boundaries.size(); i++){
    std::set<MVertex*> vb;
    std::vector<MEdge> iBound = boundaries[i];
    for (unsigned int j = 0; j < iBound.size(); j++){
      MEdge e = iBound[j];
      vb.insert(e.getVertex(0));
      vb.insert(e.getVertex(1));
    }
    std::vector<SPoint3> vBounds;
    for (std::set<MVertex* >::iterator it = vb.begin(); it != vb.end(); it++){
      SPoint3 pt((*it)->x(),(*it)->y(), (*it)->z());
      vBounds.push_back(pt);
    }
    SOrientedBoundingBox obboxD = SOrientedBoundingBox::buildOBB(vBounds);
    D = std::min(D, obboxD.getMaxSize());
  }
  int AR = (int)ceil(H/D);
  
  return AR;
}

static void getGenusAndRatio(std::vector<MElement *> &elements, int & genus, int &AR)
{
  std::vector<std::vector<MEdge> > boundaries;
  genus = getGenus(elements, boundaries);  
  AR = getAspectRatio(elements, boundaries);
}

static void partitionRegions(std::vector<MElement*> &elements, 
                             std::vector<std::vector<MElement*> > &regions)
{
 for (unsigned int i = 0; i < elements.size(); ++i){
   MElement *e = elements[i];
   int part = e->getPartition();
   regions[part-1].push_back(e);
 }
}

static void printLevel(std::vector<MElement *> &elements, int recur, int region)
{
  char fn[256];
  sprintf(fn, "part_%d_%d.msh", recur, region);
  double version = 2.0;

  std::set<MVertex*> vs;
  for (int i=0;i<elements.size();i++){
    for (int j=0;j<elements[i]->getNumVertices();j++){
      vs.insert(elements[i]->getVertex(j));
    }
  }

  bool binary = false;
  FILE *fp = fopen (fn, "w");
  fprintf(fp, "$MeshFormat\n");  
  fprintf(fp, "%g %d %d\n", version, binary ? 1 : 0, (int)sizeof(double));
  fprintf(fp, "$EndMeshFormat\n");  

  fprintf(fp,"$Nodes\n%d\n", (int)vs.size());
  std::set<MVertex*> :: iterator it = vs.begin();
  int index = 1;
  for (; it != vs.end() ; ++it){
    (*it)->setIndex(index++);
    fprintf(fp,"%d %g %g %g\n",(*it)->getIndex(),
	    (*it)->x(),(*it)->y(),(*it)->z());
  }
  fprintf(fp,"$EndNodes\n",elements.size());
  
  fprintf(fp,"$Elements\n%d\n", (int)elements.size());
  for (int i=0;i<elements.size();i++){
    elements[i]->writeMSH(fp,version);
  }
  fprintf(fp,"$EndElements\n%d\n", (int)elements.size());
  
  fclose(fp);
}

multiscalePartition::multiscalePartition(std::vector<MElement *> &elements, int nbParts, typeOfPartition method)
{
  options = CTX::instance()->partitionOptions;
  options.num_partitions = nbParts;
  options.partitioner = 1; //1 CHACO, 2 METIS
  if (options.partitioner == 1){
    options.global_method = 2;// 1 Multilevel-KL, 2 Spectral
    options.mesh_dims[0] = nbParts;
  }
  
  partitionLevel *level = new partitionLevel;
  level->elements.insert(level->elements.begin(),elements.begin(),elements.end());
  level->recur = 0;
  level->region = 0;

  levels.push_back(level);

  partition(*level, nbParts, method);

  totalParts = assembleAllPartitions();
}

void multiscalePartition::setNumberOfPartitions(int &nbParts)
{
  options.num_partitions = nbParts;
   if (options.partitioner == 1){
     options.mesh_dims[0] = nbParts;
   }
}

void multiscalePartition::partition(partitionLevel & level, int nbParts, typeOfPartition method)
{
#if defined(HAVE_METIS) || defined(HAVE_CHACO)

  if (method == LAPLACIAN){
    multiscaleLaplace multiLaplace(level.elements, level.recur);
  }
  else if (method == MULTILEVEL){
    setNumberOfPartitions(nbParts);
    PartitionMeshElements(level.elements, options);
  }
  
  std::vector<std::vector<MElement*> > regions(nbParts);
  partitionRegions(level.elements, regions);
  level.elements.clear();

  for (unsigned i=0;i< regions.size() ; i++){    
  
    partitionLevel *nextLevel = new partitionLevel;
    nextLevel->elements = regions[i];
    nextLevel->recur = level.recur+1;
    nextLevel->region = i;

    levels.push_back(nextLevel);
    int genus, AR;
    getGenusAndRatio(regions[i], genus, AR);

    if (genus < 0) {
      Msg::Error("Genus partition is negative G=%d!", genus);
      exit(1);
    }
  
    //printLevel (nextLevel->elements, nextLevel->recur,nextLevel->region);  

    if (genus != 0 ){
      int nbParts = 2; //std::max(genus+2,2);
      Msg::Info("Multiscale part: level %d region %d  is %d-GENUS (AR=%d) ---> MULTILEVEL partition %d parts",
		nextLevel->recur,nextLevel->region, genus, AR, nbParts);  
      partition(*nextLevel, nbParts, MULTILEVEL);
    }
     else if (genus == 0  &&  AR > 3 ){
       int nbParts = 2;
       Msg::Info("Multiscale part: level %d region %d  is ZERO-GENUS (AR=%d) ---> LAPLACIAN partition %d parts",
 		nextLevel->recur,nextLevel->region, AR, nbParts);  
       partition(*nextLevel, nbParts, LAPLACIAN);
     }
    else {
    Msg::Info("Multiscale part: level %d, region %d is ZERO-GENUS (AR=%d)", 
		 nextLevel->recur,nextLevel->region, AR);
    }
    
  }
  
#endif
}

int multiscalePartition::assembleAllPartitions()
{
  int nbParts =  1;   

  for (unsigned i = 0; i< levels.size(); i++){
    partitionLevel *iLevel = levels[i];
    if(iLevel->elements.size() > 0){
      for (unsigned j = 0; j < iLevel->elements.size(); j++){
	MElement *e = iLevel->elements[j];
	int part = e->getPartition();
	e->setPartition(nbParts);
      }
      nbParts++;
    }
  }
  
  return nbParts - 1;
}
