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
#include "MFace.h"
#include "MEdge.h"
class MElement;
class polynomialBasis;
class GEntity;
class GModel;

class binding;
class dgConservationLaw;
class dgDofContainer;


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

class dgGroupOfFaces;


// store topological and geometrical data for 1 group for 1 discretisation
class dgGroupOfElements {
  int _ghostPartition; // -1 : this is not a ghosted group, otherwise the id of the parent partition

  // N elements in the group
  std::vector<MElement*> _elements;
  // inverse map that gives the index of an element in the group
  std::map<MElement*,int> element_to_index;
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
  //
  fullMatrix<double> *_dPsiDx;
  // dimension of the parametric space and of the real space
  // may be different if the domain is a surface in 3D (manifold)
  int _dimUVW, _dimXYZ;
  // polynomial order of the interpolation
  int _order;
  //
  // volume/surface/length of the element (sum_qp w_i detJ_i)
  fullMatrix<double> *_elementVolume;
  // forbid the copy 
  //  dgGroupOfElements (const dgGroupOfElements &e, int order) {}
  //  dgGroupOfElements & operator = (const dgGroupOfElements &e) {}
protected:
  int _multirateExponent;
  bool _multirateInnerBuffer;
  bool _multirateOuterBuffer;
public:

  inline int getMultirateExponent() const {return _multirateExponent;}
  inline int getIsInnerMultirateBuffer() const {return _multirateInnerBuffer;}
  inline int getIsOuterMultirateBuffer() const {return _multirateOuterBuffer;}
  inline int getIsMultirateBuffer()const {return _multirateInnerBuffer || _multirateOuterBuffer;}
  dgGroupOfElements (const std::vector<MElement*> &e, int pOrder,int ghostPartition=-1);
  virtual ~dgGroupOfElements ();
  inline int getNbElements() const {return _elements.size();}
  inline int getNbNodes() const {return _collocation->size2();}
  inline int getNbIntegrationPoints() const {return _collocation->size1();}
  inline int getDimUVW () const {return _dimUVW;}
  inline int getDimXYZ () const {return _dimXYZ;}
  inline MElement* getElement (int iElement) const {return _elements[iElement];}  
  inline const polynomialBasis & getFunctionSpace () const {return _fs;}
  inline const fullMatrix<double> & getIntegrationPointsMatrix () const {return *_integration;}
  inline const fullMatrix<double> & getCollocationMatrix () const {return *_collocation;}
  inline const fullMatrix<double> & getFluxRedistributionMatrix (int i) const {return *_redistributionFluxes[i];}
  inline const fullMatrix<double> & getSourceRedistributionMatrix () const {return *_redistributionSource;}
  inline double getElementVolume (int iElement)const {return (*_elementVolume)(iElement,0);}
  inline double getDetJ (int iElement, int iGaussPoint) const {return (*_mapping)(iElement, 10*iGaussPoint + 9);}
  inline double getInvJ (int iElement, int iGaussPoint, int i, int j) const {return (*_mapping)(iElement, 10*iGaussPoint + i + 3*j);}
  inline fullMatrix<double> & getDPsiDx() const { return *_dPsiDx;}
  inline fullMatrix<double> &getInverseMassMatrix () const {return *_imass;}
  inline const fullMatrix<double> getMapping (int iElement) const {return fullMatrix<double>(*_mapping, iElement, 1);}
  inline int getOrder() const {return _order;}
  inline int getGhostPartition() const {return _ghostPartition;}
  void copyPrivateDataFrom(const dgGroupOfElements *from);
  inline int getIndexOfElement (MElement *e) const {
    std::map<MElement*,int>::const_iterator it = element_to_index.find(e);
    if (it == element_to_index.end())return -1;
    return it->second;
  }
  friend class dgGroupCollection;
};

class dgGroupOfFaces {
  // normals always point outside left to right
  // only used if this is a group of boundary faces
  std::string _boundaryTag;
  const dgGroupOfElements &_groupLeft,&_groupRight;
  void addFace(const MFace &topoFace, int iElLeft, int iElRight);
  void addEdge(const MEdge &topoEdge, int iElLeft, int iElRight);
  void addVertex(MVertex *topoVertex, int iElLeft, int iElRight);
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
  std::vector<std::vector<int> > _closuresLeft; 
  std::vector<std::vector<int> > _closuresRight; 
  std::vector<int> _closuresIdLeft; 
  std::vector<int> _closuresIdRight; 
  // face integration point in the coordinate of the left and right element (one fullMatrix per closure)
  std::vector<fullMatrix<double> > _integrationPointsLeft;
  std::vector<fullMatrix<double> > _integrationPointsRight;
  // XYZ gradient of the shape functions of both elements on the integrations points of the face
  // (iQP*3+iXYZ , iFace*NPsi+iPsi)
  fullMatrix<double> *_dPsiLeftDxOnQP;
  fullMatrix<double> *_dPsiRightDxOnQP;
  // normals at integration points  (N*Ni) x 3
  fullMatrix<double> *_normals;
  // detJac at integration points (N*Ni) x 1
  fullMatrix<double> *_detJac;
  // collocation matrices \psi_i (GP_j) 
  fullMatrix<double> *_collocation;
  //fullMatrix<double> *_collocationLeft, *_collocationRight;
  // redistribution matrices \psi_i (GP_j) * weight_j
  fullMatrix<double> *_redistribution;
  // surface/length/1 of the interface element (sum_qp w_i detJ_i)
  fullMatrix<double> *_interfaceSurface;
  //common part of the 3 constructors
  void init(int pOrder);
public:
  inline const dgGroupOfElements &getGroupLeft()const {return _groupLeft; }
  inline const dgGroupOfElements &getGroupRight()const {return _groupRight; }
  inline int getElementLeftId (int i) const {return _left[i];};
  inline int getElementRightId (int i) const {return _right[i];};
  inline MElement* getElementLeft (int i) const {return _groupLeft.getElement(_left[i]);}  
  inline MElement* getElementRight (int i) const {return _groupRight.getElement(_right[i]);}  
  inline double getElementVolumeLeft(int iFace) const {return _groupLeft.getElementVolume(_left[iFace]);}
  inline double getElementVolumeRight(int iFace) const {return _groupRight.getElementVolume(_right[iFace]);}
  inline MElement* getFace (int iElement) const {return _faces[iElement];}  
  inline const std::vector<int> &getClosureLeft(int iFace) const{ return _closuresLeft[_closuresIdLeft[iFace]]; }
  inline const std::vector<int> &getClosureRight(int iFace) const{ return _closuresRight[_closuresIdRight[iFace]];}
  inline fullMatrix<double> &getIntegrationOnElementLeft(int iFace) { return _integrationPointsLeft[_closuresIdLeft[iFace]];}
  inline fullMatrix<double> &getIntegrationOnElementRight(int iFace) { return _integrationPointsRight[_closuresIdRight[iFace]];}
  
  inline fullMatrix<double> &getNormals () const {return *_normals;}
  dgGroupOfFaces (const dgGroupOfElements &elements,int pOrder);
  dgGroupOfFaces (const dgGroupOfElements &a, const dgGroupOfElements &b,int pOrder);
  dgGroupOfFaces (const dgGroupOfElements &elGroup, std::string boundaryTag, int pOrder,std::set<MVertex*> &boundaryVertices);
  dgGroupOfFaces (const dgGroupOfElements &elGroup, std::string boundaryTag, int pOrder,std::set<MEdge,Less_Edge> &boundaryEdges);
  dgGroupOfFaces (const dgGroupOfElements &elGroup, std::string boundaryTag, int pOrder,std::set<MFace,Less_Face> &boundaryFaces);
  virtual ~dgGroupOfFaces ();
  inline bool isBoundary() const {return !_boundaryTag.empty();}
  inline const std::string getBoundaryTag() const {return _boundaryTag;}
  inline fullMatrix<double> & getDPsiLeftDxMatrix() const { return *_dPsiLeftDxOnQP;}
  inline fullMatrix<double> & getDPsiRightDxMatrix() const { return *_dPsiRightDxOnQP;}
  //this part is common with dgGroupOfElements, we should try polymorphism
  inline int getNbElements() const {return _faces.size();}
  inline int getNbNodes() const {return _collocation->size2();}
  inline int getNbIntegrationPoints() const {return _collocation->size1();}
  inline const fullMatrix<double> & getCollocationMatrix () const {return *_collocation;}
  inline const fullMatrix<double> & getIntegrationPointsMatrix () const {return *_integration;}
  inline const fullMatrix<double> & getRedistributionMatrix () const {return *_redistribution;}
  inline double getDetJ (int iElement, int iGaussPoint) const {return (*_detJac)(iGaussPoint,iElement);}
  inline double getInterfaceSurface (int iFace)const {return (*_interfaceSurface)(iFace,0);}
  //keep this outside the Algorithm because this is the only place where data overlap
  void mapToInterface(int nFields, const fullMatrix<double> &vLeft, const fullMatrix<double> &vRight, fullMatrix<double> &v);
  void mapFromInterface(int nFields, const fullMatrix<double> &v, fullMatrix<double> &vLeft, fullMatrix<double> &vRight);
  void mapLeftFromInterface(int nFields, const fullMatrix<double> &v, fullMatrix<double> &vLeft);
  void mapRightFromInterface(int nFields, const fullMatrix<double> &v, fullMatrix<double> &vRight);
  const polynomialBasis * getPolynomialBasis() const {return _fsFace;}
};

class dgGroupCollection {
  GModel *_model;
  std::vector<dgGroupOfElements*> _elementGroups; //volume
  std::vector<dgGroupOfFaces*> _faceGroups; //interface
  std::vector<dgGroupOfFaces*> _boundaryGroups; //boundary
  std::vector<dgGroupOfElements*> _ghostGroups; //ghost volume

  //{group,id} of the elements to send to each partition for a scatter operation
  std::vector< std::vector<std::pair<int,int> > >_elementsToSend;
  bool _groupsOfElementsBuilt;
  bool _groupsOfInterfacesBuilt;

  // Multirate stuff
  int _dtMaxExponent;

  public:
  inline int getDtMaxExponent() const {return _dtMaxExponent;}
  inline GModel* getModel() {return _model;}
  inline int getNbElementGroups() const {return _elementGroups.size();}
  inline int getNbFaceGroups() const {return _faceGroups.size();}
  inline int getNbBoundaryGroups() const {return _boundaryGroups.size();}
  inline int getNbGhostGroups() const {return _ghostGroups.size();}
  inline dgGroupOfElements *getElementGroup(int i) const {return _elementGroups[i];}
  inline dgGroupOfFaces *getFaceGroup(int i) const {return _faceGroups[i];}
  inline dgGroupOfFaces *getBoundaryGroup(int i) const {return _boundaryGroups[i];}
  inline dgGroupOfElements *getGhostGroup(int i) const {return _ghostGroups[i];}

  inline int getNbImageElementsOnPartition(int partId) const {return _elementsToSend[partId].size();}
  inline int getImageElementGroup(int partId, int i) const {return _elementsToSend[partId][i].first;}
  inline int getImageElementPositionInGroup(int partId, int i) const {return _elementsToSend[partId][i].second;}

  void buildGroupsOfElements (GModel *model,int dimension, int order);
  void buildGroupsOfInterfaces ();

  void splitGroupsForMultirate(double refDt,dgConservationLaw *claw, dgDofContainer *solution);

  void find (MElement *elementToFind, int &iGroup, int &ithElementOfGroup);

  dgGroupCollection(GModel *model, int dimension, int order);
  dgGroupCollection();
  static void registerBindings(binding *b);
  ~dgGroupCollection();
};
#endif
