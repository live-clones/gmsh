#include "multiscalePartition.h"
#include "GmshConfig.h"
#include "GmshDefines.h"
#include "meshPartition.h"
#include "MElement.h"

static bool zeroGenus (std::vector<MElement *> &elements){

  //TODO
  return true; 

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
  //....
  int nbBounds = 0;
  //....

  int genus = (int)(-poincare + 2 - nbBounds)/2;
  
  if (genus == 0)
    return true;
  else
    return false;

}

static void partitionRegions (std::vector<MElement*> &elements, 
			      std::vector<std::vector<MElement*> > &regions){
  
 for (int i=0;i<elements.size();++i){
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

void multiscalePartition::partition(partitionLevel & level){
#if defined(HAVE_METIS) || defined(HAVE_CHACO)
  PartitionMeshElements(level.elements, options);

  std::vector<std::vector<MElement*> > regions(options.num_partitions);
  partitionRegions(level.elements, regions);
  level.elements.clear();

  for (int i=0;i< regions.size() ; i++){    
  
    partitionLevel *nextLevel = new partitionLevel;
    nextLevel->elements = regions[i];
    nextLevel->recur = level.recur+1;
    nextLevel->region = i;

    levels.push_back(nextLevel);

     if (!zeroGenus(regions[i])){
       Msg::Info("Multiscale partition, level %d region %d not ZERO-GENUS",
		 nextLevel->recur,nextLevel->region);
       partition(*nextLevel);
     }
     else {
       Msg::Info("Multiscale Partition, level %d, region %d is ZERO-GENUS", 
		 nextLevel->recur,nextLevel->region);
     }

}

#endif
}

int multiscalePartition::assembleAllPartitions(){

  int nbParts =  options.num_partitions;;

  return nbParts;

}
