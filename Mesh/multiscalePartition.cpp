#include "multiscalePartition.h"
#include "GmshConfig.h"
#include "GmshDefines.h"
#include "meshPartition.h"
#include "MEdge.h"
#include "MElement.h"

static void recur_connect (MVertex *v,
			   std::multimap<MVertex*,MEdge> &v2e,
			   std::set<MEdge,Less_Edge> &group,
			   std::set<MVertex*> &touched){

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
  for (unsigned i=0;i<edges.size();++i){
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
    for ( std::set<MVertex*>::iterator it = touched.begin() ; it != touched.end();++it)
      v2e.erase(*it);
  }

  return boundaries.size();
}


static int getGenus (std::vector<MElement *> &elements,  
		     std::vector<std::vector<MEdge> > &boundaries){ 

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

static int getAspectRatio (std::vector<MElement *> &elements, 
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
    bb +=pt;
  }
   
//  obb =  SOrientedBoundingBox::buildOBB(vertices);
//  double H = obbox.getMaxSize(); 
 double H = norm(SVector3(bb.max(), bb.min()));
 
 double D = 0.0;
  if (boundaries.size() == 0){
    D=1.;
  }
  else{
    for (unsigned i=0; i< boundaries.size(); i++){
      std::set<MVertex*> vb;
      std::vector<MEdge> iBound = boundaries[i];
      for (unsigned j=0; j< iBound.size(); j++){
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
      D = std::max(D, obboxD.getMaxSize());
    }
  }
  int eta = (int)ceil(H/D);

  return eta;

}
static void getGenusAndRatio(std::vector<MElement *> &elements, int & genus, int &eta){

  std::vector<std::vector<MEdge> > boundaries;
  genus = getGenus(elements, boundaries);  
  eta = getAspectRatio(elements, boundaries);

  return;

}
static void partitionRegions (std::vector<MElement*> &elements, 
			      std::vector<std::vector<MElement*> > &regions){
  
 for (unsigned i=0;i<elements.size();++i){
   MElement *e = elements[i];
   int part = e->getPartition();
   regions[part-1].push_back(e);
 }
  
 return;

}


multiscalePartition::multiscalePartition (std::vector<MElement *> &elements, 
					  meshPartitionOptions &_options){
  
  options = _options;

  partitionLevel *level = new partitionLevel;
  level->elements.insert(level->elements.begin(),elements.begin(),elements.end());
  level->recur = 0;
  level->region = 0;

  levels.push_back(level);

  partition(*level);

  totalParts = assembleAllPartitions();

}
void multiscalePartition:: setNumberOfPartitions(int &nbParts)
{
  options.num_partitions = nbParts;
   if ( options.partitioner == 1){
     options.mesh_dims[0] = nbParts;
   }
}

void multiscalePartition::partition(partitionLevel & level){
#if defined(HAVE_METIS) || defined(HAVE_CHACO)
  PartitionMeshElements(level.elements, options);

  std::vector<std::vector<MElement*> > regions(options.num_partitions);
  partitionRegions(level.elements, regions);
  level.elements.clear();

  for (unsigned i=0;i< regions.size() ; i++){    
  
    partitionLevel *nextLevel = new partitionLevel;
    nextLevel->elements = regions[i];
    nextLevel->recur = level.recur+1;
    nextLevel->region = i;

    levels.push_back(nextLevel);
    int genus, eta;
    getGenusAndRatio(regions[i], genus, eta);
    if (genus < 0) {
      Msg::Error("Genus partition is negative G=%d!", genus);
      exit(1);
    }
    if (genus != 0 || eta > 4 ){
      int nbParts = std::max(genus+2, (int)eta/4);
      setNumberOfPartitions(nbParts);
      Msg::Info("Multiscale partition, level %d region %d  is %d-GENUS (ETA=%d) ---> partition %d parts",
		nextLevel->recur,nextLevel->region, genus, eta, nbParts);
      
      partition(*nextLevel);
    }
    else {
      Msg::Info("Multiscale Partition, level %d, region %d is ZERO-GENUS (ETA=%d)", 
		nextLevel->recur,nextLevel->region, eta);
    }
     
}

#endif
}

int multiscalePartition::assembleAllPartitions(){

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

  Msg::Info("-----------------------------------------------------------");
  Msg::Info("Multiscale Partition SUCCESSFULLY PERFORMED : %d parts", nbParts-1);
  Msg::Info("-----------------------------------------------------------");
 

  return nbParts-1;

 

}
