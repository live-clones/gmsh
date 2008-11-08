#include "gmshSmoothHighOrder.h"

#include "gmshAssembler.h"
#include "gmshLaplace.h"
#include "gmshElasticity.h"
#include "gmshLinearSystemGmm.h"
#include "GFace.h"
#include "GRegion.h"

void gmshHighOrderSmoother::smooth ( GFace *gf) {
  std::vector<MElement*> v;

  v.insert(v.begin(), gf->triangles.begin(),gf->triangles.end());
  v.insert(v.begin(), gf->quadrangles.begin(),gf->quadrangles.end());
  Msg::Info("Smoothing high order mesh face %d (%d elements)", gf->tag(),
	    v.size());
  smooth(v);
}
void gmshHighOrderSmoother::smooth ( GRegion *gr) {
  std::vector<MElement*> v;
  v.insert(v.begin(), gr->tetrahedra.begin(),gr->tetrahedra.end());
  v.insert(v.begin(), gr->hexahedra.begin(),gr->hexahedra.end());
  v.insert(v.begin(), gr->prisms.begin(),gr->prisms.end());
  smooth(v);
}

void gmshHighOrderSmoother::smooth ( std::vector<MElement*>  & v) {
  
  gmshLinearSystemGmm *lsys = new gmshLinearSystemGmm;
  gmshAssembler myAssembler(lsys);
  gmshElasticityTerm El(0,1.0,.333,getTag());     

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

  Msg::Info("%d vertices FIXED %d NUMBERED", myAssembler.sizeOfF()
	    , myAssembler.sizeOfR());

  // assembly of the elasticity term on the
  // set of elements
  El.addToMatrix(myAssembler,v); 
  
  // solve the system
  lsys->systemSolve();

  // move the nodes that were involved in the process
  // to their new lcation
  for (it = verticesToMove.begin()  ; it != verticesToMove.end() ; ++it){
    it->first->x() =  it->first->x() + myAssembler.getDofValue (it->first, 0 ,getTag());  
    it->first->y() =  it->first->y() + myAssembler.getDofValue (it->first, 1 ,getTag());  
    it->first->z() =  it->first->z() + myAssembler.getDofValue (it->first, 2 ,getTag());  
    //    printf("%g %g\n", myAssembler.getDofValue (it->first, 0 ,getTag()), myAssembler.getDofValue (it->first, 1 ,getTag()));
  }

  // delete matrices and vectors
  delete lsys;
  
}
