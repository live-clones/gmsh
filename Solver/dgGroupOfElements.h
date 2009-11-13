#ifndef _DG_GROUP_OF_ELEMENTS_
#define _DG_GROUP_OF_ELEMENTS_

#include <vector>
#include "fullMatrix.h"
/*
  A group of element contains N elements
  that are of the same type and of the 
  same order. All element have the same
  number of integration points Np, the same
  number of vertices Nv.

  we DO NOT store N, Ni or Nv (matrices and vectors 
  have the right sizes)
*/
class MElement;
class MFace;
class MEdge;
class polynomialBasis;

class dgElement {
  MElement *_element;
  // solution at points
  const fullMatrix<double> &_solution, &_integration, &_gradients;
public:
  dgElement (MElement *e, const fullMatrix<double> &sol, const fullMatrix<double> &integ)
    : _element(e), _solution(sol), _integration(integ), _gradients(sol)
  {}
  dgElement (MElement *e, const fullMatrix<double> &sol, const fullMatrix<double> &grads, const fullMatrix<double> &integ)
    : _element(e), _solution(sol), _integration(integ), _gradients(grads)
  {}
  const fullMatrix<double> &solution() const { return _solution; }
  const fullMatrix<double> &integration() const { return _integration; }
  MElement *element() const { return _element;}
};


// store topological and geometrical data for 1 group for 1 discretisation
class dgGroupOfElements {
  // N elements in the group
  std::vector<MElement*> _elements;
  // the ONLY function space that is used to 
  // inerpolated the fields (may be different to the 
  // one of the elements)
  const polynomialBasis &_fs;
  // Ni integration points, matrix of size Ni x 4 (u,v,w,weight)
  fullMatrix<double> *_integration;
  // collocation matrix that maps vertices to integration points.
  fullMatrix<double> *_collocation;
  // inverse of the mapping and det mapping (00 01 02 10 11 12 20 21 22 det)
  fullMatrix<double> *_mapping;
  // redistribution of the fluxes to vertices multiplied by
  // the gradient of shape functions (in parametric space)
  // for both diffusive and convective fluxes
  fullMatrix<double> *_redistributionFluxes[3];
  // redistribution for the source term
  fullMatrix<double> *_redistributionSource;
  // inverse mass matrix of all elements
  fullMatrix<double> *_imass;
  // dimension of the parametric space and of the real space
  // may be different if the domain is a surface in 3D (manifold)
  int _dimUVW, _dimXYZ;
  // forbid the copy 
  //  dgGroupOfElements (const dgGroupOfElements &e, int order) {}
  //  dgGroupOfElements & operator = (const dgGroupOfElements &e) {}
public:
  dgGroupOfElements (const std::vector<MElement*> &e, int pOrder);
  virtual ~dgGroupOfElements ();
  inline int getNbElements() const {return _elements.size();}
  inline int getNbNodes() const {return _collocation->size2();}
  inline int getNbIntegrationPoints() const {return _collocation->size1();}
  inline int getDimUVW () const {return _dimUVW;}
  inline int getDimXYZ () const {return _dimXYZ;}
  inline MElement* getElement (int iElement) const {return _elements[iElement];}  
  inline const fullMatrix<double> & getIntegrationPointsMatrix () const {return *_integration;}
  inline const fullMatrix<double> & getCollocationMatrix () const {return *_collocation;}
  inline const fullMatrix<double> & getFluxRedistributionMatrix (int i) const {return *_redistributionFluxes[i];}
  inline const fullMatrix<double> & getSourceRedistributionMatrix () const {return *_redistributionSource;}
  inline double getDetJ (int iElement, int iGaussPoint) const {return (*_mapping)(iElement, 10*iGaussPoint + 9);}
  inline double getInvJ (int iElement, int iGaussPoint, int i, int j) const {return (*_mapping)(iElement, 10*iGaussPoint + i + 3*j);}
  inline fullMatrix<double> getInverseMassMatrix (int iElement) const {return fullMatrix<double>(*_imass,iElement*getNbNodes(),getNbNodes());}
  inline const fullMatrix<double> getMapping (int iElement) const {return fullMatrix<double>(*_mapping, iElement, 1);}
};

class dgFace {
  int nbGaussPoints;
  MElement *_left, *_right;
  MElement *_face;
  double *_normals;
  const fullMatrix<double> *_solutionRight, *_solutionLeft, *_integration;
public:
  dgFace (MElement *face,MElement *left, MElement *right,
    const fullMatrix<double> &solRight,
    const fullMatrix<double> &solLeft,
    const fullMatrix<double> &integration
    ) : _left(left), _right(right), _face(face),_solutionRight(&solRight),_solutionLeft(&solLeft),_integration(&integration)
  {}
  inline const fullMatrix<double> &solutionRight() const { return *_solutionRight; }
  inline const fullMatrix<double> &solutionLeft() const { return *_solutionLeft; }
  inline const fullMatrix<double> &integration() const { return *_integration; }
  inline MElement *left() const { return _left;}
  inline MElement *right() const { return _right;}
  inline MElement *face() const { return _face;}
};

class dgGroupOfFaces {
  const dgGroupOfElements &_groupLeft,&_groupRight;
  void addFace(const MFace &topoFace, int iElLeft, int iElRight);
  void addEdge(const MEdge &topoEdge, int iElLeft, int iElRight);
  void computeFaceNormals();
  // Two polynomialBases for left and right elements
  // the group has always the same types for left and right
  const polynomialBasis *_fsLeft,*_fsRight, *_fsFace;
  // N elements in the group
  std::vector<int>_left, _right;
  std::vector<MElement *>_faces;
  // Ni integration points, matrix of size Ni x 3 (u,v,weight)
  fullMatrix<double> *_integration;
  // there is a finite number of combinations of orientations, senses
  // and rotations of the faces (typically 24 for tets). Any pair
  // is characterized by a single integer which is the combination
  // this closure is for the interpolation that MAY BE DIFFERENT THAN THE
  // GEOMETRICAL CLOSURE !!!
  std::vector<const std::vector<int> * > _closuresLeft; 
  std::vector<const std::vector<int> * > _closuresRight; 
  // normals at integration points  (N*Ni) x 3
  fullMatrix<double> *_normals;
  // detJac at integration points (N*Ni) x 1
  fullMatrix<double> *_detJac;
  // collocation matrices \psi_i (GP_j) 
  fullMatrix<double> *_collocation;
  //fullMatrix<double> *_collocationLeft, *_collocationRight;
  // redistribution matrices \psi_i (GP_j) * weight_j
  fullMatrix<double> *_redistribution;
  //common part of the 3 constructors
  void init(int pOrder);
public:
  inline MElement* getElementLeft (int i) const {return _groupLeft.getElement(_left[i]);}  
  inline MElement* getElementRight (int i) const {return _groupRight.getElement(_right[i]);}  
  inline MElement* getFace (int iElement) const {return _faces[iElement];}  
  const std::vector<int> * getClosureLeft(int iFace) const{ return _closuresLeft[iFace];}
  const std::vector<int> * getClosureRight(int iFace) const{ return _closuresRight[iFace];}
  dgGroupOfFaces (const dgGroupOfElements &elements,int pOrder);
  virtual ~dgGroupOfFaces ();
  //this part is common with dgGroupOfElements, we should try polymorphism
  inline int getNbElements() const {return _faces.size();}
  inline int getNbNodes() const {return _collocation->size1();}
  inline int getNbIntegrationPoints() const {return _collocation->size1();}
  inline const fullMatrix<double> & getCollocationMatrix () const {return *_collocation;}
  inline const fullMatrix<double> & getIntegrationPointsMatrix () const {return *_integration;}
  inline const fullMatrix<double> & getRedistributionMatrix () const {return *_redistribution;}
  inline double getDetJ (int iElement, int iGaussPoint) const {return (*_detJac)(iElement, iGaussPoint);}
  //keep this outside the Algorithm because this is the only place where data overlap
  void mapToInterface(int nFields, const fullMatrix<double> &vLeft, const fullMatrix<double> &vRight, fullMatrix<double> &v);
  void mapFromInterface(int nFields, const fullMatrix<double> &v, fullMatrix<double> &vLeft, fullMatrix<double> &vRight);
};



#endif
