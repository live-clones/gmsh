#include "SElement.h"

simpleFunction<double> * SElement::_enrichement_s = 0,* SElement::_enrichement_t = 0;

void SElement::gradNodalFunctions ( double u, double v, double w, double invjac[3][3],double Grads[][3],
				    simpleFunction<double> *_enrichement)
{
  double grads[256][3];
  _e->getGradShapeFunctions(u, v, w, grads);

  int nbNodes = getNumNodalShapeFunctions();
  for (int j = 0; j < nbNodes; j++){
    Grads[j][0] = invjac[0][0] * grads[j][0] + invjac[0][1] * grads[j][1] + 
      invjac[0][2] * grads[j][2];
    Grads[j][1] = invjac[1][0] * grads[j][0] + invjac[1][1] * grads[j][1] + 
      invjac[1][2] * grads[j][2];
    Grads[j][2] = invjac[2][0] * grads[j][0] + invjac[2][1] * grads[j][1] + 
      invjac[2][2] * grads[j][2];
  }
  
  if (_enrichement){
    const int N = getNumNodalShapeFunctions();
    SPoint3 p;
    double sf[256];
    _e->getShapeFunctions(u, v, w, sf);
    // FIXME : re-use sf for computing coordinates
    _e->pnt(u,v,w,p);
    double E = (*_enrichement_s)(p.x(),p.y(),p.z());
    double dEdx,dEdy,dEdz;
    _enrichement_s->gradient(p.x(),p.y(),p.z(),dEdx,dEdy,dEdz);
    for (int i=0;i<N;i++){
      Grads[i][0] = Grads[i][0] * E + dEdx * sf[i];
      Grads[i][1] = Grads[i][1] * E + dEdy * sf[i];
      Grads[i][2] = Grads[i][2] * E + dEdz * sf[i];
    }
  }
}

void SElement::nodalFunctions ( double u, double v, double w, double s[],
				simpleFunction<double> *_enrichement)
{
  _e->getShapeFunctions(u, v, w, s);
  if (_enrichement){
    const int N =  getNumNodalShapeFunctions();
    SPoint3 p;
    // FIXME : re-use s for computing coordinates
    _e->pnt(u,v,w,p);
    double E = (*_enrichement_s)(p.x(),p.y(),p.z());
    for (int i=0;i<N;i++){
      s[i] *= E;
    }
  }
}


void SElement::gradNodalShapeFunctions ( double u, double v, double w, double invjac[3][3],
					 double grads[][3])
{
  gradNodalFunctions (u,v,w,invjac,grads,_enrichement_s); 
}

void SElement::gradNodalTestFunctions ( double u, double v, double w, double invjac[3][3],
					double grads[][3])
{
  gradNodalFunctions (u,v,w,invjac,grads,_enrichement_t); 
}

void SElement::nodalShapeFunctions ( double u, double v, double w, double s[])
{
  nodalFunctions (u,v,w,s,_enrichement_s); 
}

void SElement::nodalTestFunctions ( double u, double v, double w, double s[])
{
  nodalFunctions (u,v,w,s,_enrichement_t); 
}

int SElement::getNumNodalShapeFunctions ( ) const {
  if (_e->getParent())return _e->getParent()->getNumVertices();
  return _e->getNumVertices();
}

int SElement::getNumNodalTestFunctions ( ) const {
  if (_e->getParent())return _e->getParent()->getNumVertices();
  return _e->getNumVertices();
}
