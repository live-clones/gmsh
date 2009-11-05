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
class functionSpace;

class dgElement {
  MElement *_element;
  // solution at points
  const fullMatrix<double> &_solution, &_integration, &_gradients;
public:
  dgElement (MElement *e, const fullMatrix<double> &sol, const fullMatrix<double> &integ)
    : _element(e), _solution(sol), _integration(integ), _gradients(sol)
  {}
  dgElement (MElement *e, const fullMatrix<double> &sol, const fullMatrix<double> &grads, const fullMatrix<double> &integ)
    : _element(e), _solution(sol), _integration(integ), _gradients(grad)
  {}
};

class dgGroupOfElements {
  // N elements in the group
  std::vector<MElement*> _elements;
  // the ONLY function space that is used to 
  // inerpolated the fields (may be different to the 
  // one of the elements)
  const functionSpace &_fs;
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
  // the "finite element" gradient of the solution for this group (not owned)
  fullMatrix<double> *_gradSolution;
  // the solution for this group (not owned)
  fullMatrix<double> *_solution;
  // the residual for this group (not owned)
  fullMatrix<double> *_residual;
  // dimension of the parametric space and of the real space
  // may be different if the domain is a surface in 3D (manifold)
  int _dimUVW, _dimXYZ, _nbFields;
  // forbid the copy 
  //  dgGroupOfElements (const dgGroupOfElements &e, int order) {}
  //  dgGroupOfElements & operator = (const dgGroupOfElements &e) {}
public:
  dgGroupOfElements (const std::vector<MElement*> &e, int pOrder);
  virtual ~dgGroupOfElements ();
  inline int getNbElements() const {return _elements.size();}
  inline int getNbFields() const {return _nbFields;}
  inline int getNbNodes() const {return _collocation.size1();}
  inline int getNbIntegrationPoints() const {return _collocation.size2();}
  inline int getDimUVW () const {return _dimUVW;}
  inline int getDimXYZ () const {return _dimXYZ;}
  inline const MElement* getElement (int iElement) const {return _elements[iElement];}  
  inline const fullMatrix<double> & getIntegrationPointsMatrix () const {return *_integration;}
  inline const fullMatrix<double> & getCollocationMatrix () const {return *_collocation;}
  inline const fullMatrix<double> & getRedistributionMatrix (int i) const {return *_redistribution[i];}
  inline const fullMatrix<double> & getSolution () const {return *_solution;}
  inline const fullMatrix<double> & getGradientOfSolution () const {return *_gradSolution;}
  // get a proxy on the solution for element iElement
  inline fullMatrix<double> & getSolution (int iElement) const {return fullMatrix<double>(*_solution, iElement*_nbFields, _nbFields);}
  inline const fullMatrix<double> & getResidual () const {return *_solution;}
  // get a proxy on the residual for element iElement
  inline fullMatrix<double> & getResidual (int iElement) const {return fullMatrix<double>(*_residual, iElement*_nbFields, _nbFields);}
  inline double getDetJ (int iElement, int iGaussPoint) const {return (*_mapping)(iElement, 10*iGaussPoint + 9);}
  inline double getInvJ (int iElement, int iGaussPoint, int i, int j) const {return (*_mapping)(iElement, 10*iGaussPoint + i + 3*j);}
  inline fullMatrix<double> getMapping (int iElement) const {return fullMatrix<double>(*_mapping, iElement, 1);}
};

/*class dgFace {
  int nbGaussPoints;
  MElement *_left, *_right;
  MElement *_face;
  double *_normals;
  double *_detJ;
  int *_closureLeft,*_closureRight;
public:
  dgFace ();
};
*/
class dgGroupOfFaces {
  void createFaceElements (const std::vector<MFace> &topo_faces);
  void createEdgeElements (const std::vector<MEdge> &topo_faces);
  void computeFaceNormals();
  // Two functionSpaces for left and right elements
  // the group has always the same types for left and right
  const functionSpace *_fsLeft,*_fsRight, *_fsFace;
  // N elements in the group
  std::vector<MElement*> _left, _right, _faces;
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
  void init();
public:
  dgGroupOfFaces (const std::vector<MFace> &faces, 		  
		  const std::vector<MElement*> &l, 
		  const std::vector<MElement*> &r,
		  int pOrder);
  dgGroupOfFaces (const std::vector<MEdge> &edges, 		  
		  const std::vector<MElement*> &l, 
		  const std::vector<MElement*> &r,
		  int pOrder);
  virtual ~dgGroupOfFaces ();
};


#endif
