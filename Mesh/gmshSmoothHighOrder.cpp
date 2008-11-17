#include "gmshSmoothHighOrder.h"

#include "gmshAssembler.h"
#include "gmshLaplace.h"
#include "gmshElasticity.h"
#include "gmshLinearSystemGmm.h"
#include "GFace.h"
#include "GRegion.h"


void getDistordedElements ( const std::vector<MElement*>  & v, 
			    const double & threshold,
			    std::vector<MElement*>  & d,
			    double &minD){
  d.clear();
  minD = 1;
  for (int i=0;i<v.size() ; i++){
    const double disto = v[i]->distoShapeMeasure();
    if ( disto < threshold)
      d.push_back(v[i]);
    minD = std::min(minD,disto);
  }
}

void addOneLayer ( const std::vector<MElement*>  & v, 
		   std::vector<MElement*>  & d ,
		   std::vector<MElement*>  & layer ){
  std::set<MVertex*> all;
  for (int i=0;i<d.size() ; i++){
    MElement *e = d[i];
    int n = e->getNumPrimaryVertices();
    for (int j=0;j<n;j++){
      all.insert(e->getVertex(j));
    }
  }

  layer.clear();

  std::sort(d.begin(), d.end());

  for (int i=0;i<v.size() ; i++){
    MElement *e = v[i];
    bool found = std::binary_search(d.begin(), d.end(), e);
    // element is not yet there
    if (!found){
      int n = e->getNumPrimaryVertices();
      for (int j=0;j<n;j++){
	MVertex *vert = e->getVertex(j);
	if (all.find(vert) != all.end()){
	  layer.push_back(e);
	  j = n;
	}
      }
    }
  }
}


void gmshHighOrderSmoother::smooth ( GFace *gf) {
  std::vector<MElement*> v;

  v.insert(v.begin(), gf->triangles.begin(),gf->triangles.end());
  v.insert(v.begin(), gf->quadrangles.begin(),gf->quadrangles.end());
  Msg::Info("Smoothing high order mesh : model face %d (%d elements)", gf->tag(),
	    v.size());
  smooth(v);
}
void gmshHighOrderSmoother::smooth ( GRegion *gr) {
  std::vector<MElement*> v;
  v.insert(v.begin(), gr->tetrahedra.begin(),gr->tetrahedra.end());
  v.insert(v.begin(), gr->hexahedra.begin(),gr->hexahedra.end());
  v.insert(v.begin(), gr->prisms.begin(),gr->prisms.end());
  Msg::Info("Smoothing high order mesh : model region %d (%d elements)", gr->tag(),
	    v.size());
  smooth(v);
}

void gmshHighOrderSmoother::smooth ( std::vector<MElement*>  & all) {
  

  gmshLinearSystemGmm *lsys = new gmshLinearSystemGmm;
  gmshAssembler myAssembler(lsys);
  gmshElasticityTerm El(0,1.0,.333,getTag());     
  
  std::vector<MElement*> v, layer;

  double minD;

  getDistordedElements ( all, 0.5, v,minD);

  //  printf("%d elements / %d distorted  min Disto = %g\n",all.size(),v.size(), minD);

  if (!v.size())return;

  const int nbLayers = 2;
  for (int i=0;i<nbLayers;i++){
    addOneLayer ( all, v, layer);
    v.insert(v.end(),layer.begin(),layer.end());
  }

  // 3 -> .4
  printf("%d elements after adding %d layers\n",v.size(),nbLayers);

  addOneLayer ( all, v, layer);

  //  printf("%d elements in the next layer\n",layer.size());


  for (int i=0;i<layer.size() ; i++){
    for (int j=0;j<layer[i]->getNumVertices(); j++){
      MVertex *vert = layer[i]->getVertex(j);
      myAssembler.fixVertex ( vert , 0 , getTag() , 0);
      myAssembler.fixVertex ( vert , 1 , getTag() , 0);
      myAssembler.fixVertex ( vert , 2 , getTag() , 0);
    }
  }
  

  std::map<MVertex*,SVector3>::iterator it;
  std::map<MVertex*,SVector3> verticesToMove;

  //  printf("%d vertices \n", _displ.size());

  for (int i=0;i<v.size() ; i++){
    for (int j=0;j<v[i]->getNumVertices(); j++){
      MVertex *vert = v[i]->getVertex(j);
      //      printf("%d %d %d v\n",i,j,v[i]->getNumVertices());
      it = _displ.find(vert);
      if (it != _displ.end()){
	myAssembler.fixVertex ( vert , 0 , getTag() , vert->x()-it->second.x());
	myAssembler.fixVertex ( vert , 1 , getTag() , vert->y()-it->second.y());
	myAssembler.fixVertex ( vert , 2 , getTag() , vert->z()-it->second.z());
	//	printf("%g %g vs %g %g\n", it->second.x(), it->second.y(),vert->x(),vert->y());
	verticesToMove[vert] = it->second;
      }
      // ensure we do not touch any vertex that is on the boundary
      else if (vert->onWhat()->dim() < _dim){
	myAssembler.fixVertex ( vert , 0 , getTag() , 0);
	myAssembler.fixVertex ( vert , 1 , getTag() , 0);
	myAssembler.fixVertex ( vert , 2 , getTag() , 0);
      }
    }
  }
  
  // move back high order nodes to their straight sided 
  // location
  for (it = verticesToMove.begin()  ; it != verticesToMove.end() ; ++it){
    it->first->x() = it->second.x();
    it->first->y() = it->second.y();
    it->first->z() = it->second.z();
  }
  
  // number the other DOFs
  for (int i=0;i<v.size() ; i++){
    for (int j=0;j<v[i]->getNumVertices(); j++){
      MVertex *vert = v[i]->getVertex(j);
      myAssembler.numberVertex ( vert , 0 , getTag() );
      myAssembler.numberVertex ( vert , 1 , getTag() );
      myAssembler.numberVertex ( vert , 2 , getTag() );
      // gather all vertices that are supposed to move
      verticesToMove[vert] = SVector3(0.0,0.0,0.0);
    } 
  }

  //  Msg::Info("%d vertices FIXED %d NUMBERED", myAssembler.sizeOfF()
  //	    , myAssembler.sizeOfR());

  if (myAssembler.sizeOfR()){

    // assembly of the elasticity term on the
    // set of elements
    El.addToMatrix(myAssembler,v); 
    
    // solve the system
    lsys->systemSolve();
  }

  // move the nodes that were involved in the process
  // to their new lcation
  for (it = verticesToMove.begin()  ; it != verticesToMove.end() ; ++it){
    it->first->x() =  it->first->x() + myAssembler.getDofValue (it->first, 0 ,getTag());  
    it->first->y() =  it->first->y() + myAssembler.getDofValue (it->first, 1 ,getTag());  
    it->first->z() =  it->first->z() + myAssembler.getDofValue (it->first, 2 ,getTag());  
    //    printf("%g %g\n", myAssembler.getDofValue (it->first, 0 ,getTag()), myAssembler.getDofValue (it->first, 1 ,getTag()));
  }

  // delete matrices and vectors

  double minD2;
  getDistordedElements ( v, 0.5, layer,minD2);

  printf("Smooting efficiency %g -> %g\n",minD,minD2);


  delete lsys;
  
}



