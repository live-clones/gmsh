// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _MELEMENT_H_
#define _MELEMENT_H_

#include <stdio.h>
#include <algorithm>
#include <string>

#include "GmshMessage.h"
#include "ElementType.h"
#include "MVertex.h"
#include "MEdge.h"
#include "MFace.h"
#include "FuncSpaceData.h"
#include "nodalBasis.h"
#include "polynomialBasis.h"
#include "GaussIntegration.h"

class GModel;
class JacobianBasis;

// A mesh element.
class MElement
{
 private:
  // the id number of the element (this number is unique and is
  // guaranteed never to change once a mesh has been generated)
  int _num;
  // the number of the mesh partition the element belongs to
  short _partition;
  // a visibility flag
  char _visible;
 protected:
  // the tolerance used to determine if a point is inside an element,
  // in parametric coordinates
  static double _isInsideTolerance;
  void _getEdgeRep(MVertex *v0, MVertex *v1,
                   double *x, double *y, double *z, SVector3 *n,
                   int faceIndex=-1);
  void _getFaceRep(MVertex *v0, MVertex *v1, MVertex *v2,
                   double *x, double *y, double *z, SVector3 *n);
 public :
  MElement(int num=0, int part=0);
  virtual ~MElement(){}

  // set/get the tolerance for isInside() test
  static void setTolerance(const double tol);
  static double getTolerance();

  // return the tag of the element
  virtual int getNum() const { return _num; }

  // return the geometrical dimension of the element
  virtual int getDim() const = 0;

  // return the polynomial order the element
  virtual int getPolynomialOrder() const { return 1; }

  // return true if the element can be considered as a serendipity element
  virtual bool getIsAssimilatedSerendipity() const {
    return ElementType::SerendipityFromTag(getTypeForMSH()) > 0;
  }
  // return true if the element has to be considered as a serendipity element
  virtual bool getIsOnlySerendipity() const {
    return ElementType::SerendipityFromTag(getTypeForMSH()) > 1;
  }

  // get/set the partition to which the element belongs
  virtual int getPartition() const { return _partition; }
  virtual void setPartition(int num){ _partition = (short)num; }

  // get/set the visibility flag
  virtual char getVisibility() const;
  virtual void setVisibility(char val){ _visible = val; }

  // get & set the vertices
  virtual int getNumVertices() const = 0;
  virtual const MVertex *getVertex(int num) const= 0;
  virtual MVertex *getVertex(int num) = 0;
  void getVertices(std::vector<MVertex*> &verts)
  {
    int N = getNumVertices();
    verts.resize(N);
    for(int i = 0; i < N; i++) verts[i] = getVertex(i);
  }
  virtual void setVertex(int num, MVertex *v)
  {
    Msg::Error("Vertex set not supported for this element");
  }

  // give an MVertex as input and get its local number
  virtual void getVertexInfo(const MVertex *vertex, int &ithVertex) const
  {
    Msg::Error("Vertex information not available for this element");
  }

  // get the vertex using the I-deas UNV ordering
  virtual MVertex *getVertexUNV(int num){ return getVertex(num); }

  // get the vertex using the VTK ordering
  virtual MVertex *getVertexVTK(int num){ return getVertex(num); }

  // get the vertex using the Tochnog ordering
  virtual MVertex *getVertexTOCHNOG(int num){ return getVertex(num); }

  // get the vertex using the Nastran BDF ordering
  virtual MVertex *getVertexBDF(int num){ return getVertex(num); }

  // get the vertex using DIFF ordering
  virtual MVertex *getVertexDIFF(int num){ return getVertex(num); }

  // get the vertex using INP ordering
  virtual MVertex *getVertexINP(int num){ return getVertex(num); }

  // get the number of vertices associated with edges, faces and
  // volumes (nonzero only for higher order elements, polygons or
  // polyhedra)
  virtual int getNumEdgeVertices() const { return 0; }
  virtual int getNumFaceVertices() const { return 0; }
  virtual int getNumVolumeVertices() const { return 0; }

  // get the number of primary vertices (first-order element)
  int getNumPrimaryVertices() const
  {
    return getNumVertices() - getNumEdgeVertices() - getNumFaceVertices() -
      getNumVolumeVertices();
  }

  // get the edges
  virtual int getNumEdges() const = 0;
  virtual MEdge getEdge(int num) const= 0;

  // give an MEdge as input and get its local number and sign
  virtual void getEdgeInfo(const MEdge & edge, int &ithEdge, int &sign) const
  {
    Msg::Error("Edge information not available for this element");
  }

  // get an edge representation for drawing
  virtual int getNumEdgesRep(bool curved) = 0;
  virtual void getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n) = 0;

  // get the faces
  virtual int getNumFaces() = 0;
  virtual MFace getFace(int num) = 0;

  // give an MFace as input and get its local number, sign and rotation
  virtual void getFaceInfo(const MFace & face, int &ithFace, int &sign,
                           int &rot) const
  {
    Msg::Error("Face information not available for this element");
  }

  // get a face representation for drawing
  virtual int getNumFacesRep(bool curved) = 0;
  virtual void getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n) = 0;

  // get all the vertices on a edge or a face
  virtual void getEdgeVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(0);
  }
  virtual void getFaceVertices(const int num, std::vector<MVertex*> &v) const
  {
    v.resize(0);
  }

  // get and set parent and children for hierarchial grids
  virtual MElement *getParent() const { return NULL; }
  virtual void setParent(MElement *p, bool owner = false) {}
  virtual void updateParent(GModel *gm) {} // used only for reading msh files
  virtual int getNumChildren() const { return 0; }
  virtual MElement *getChild(int i) const { return NULL; }
  virtual bool ownsParent() const { return false; }

  // get base element in case of MSubElement
  virtual const MElement *getBaseElement() const { return this; }
  virtual MElement *getBaseElement() { return this; }

  // get and set domain for borders
  virtual MElement *getDomain(int i) const { return NULL; }
  virtual void setDomain (MElement *e, int i) { }

  // get the type of the element
  virtual int getType() const = 0;

  // get the max/min edge length
  virtual double maxEdge();
  virtual double minEdge();

  // max. distance between curved and straight element among all high-order nodes
  double maxDistToStraight() const;

  // get the quality measures
  double skewness();
  virtual double rhoShapeMeasure();
  virtual double gammaShapeMeasure(){ return 0.; }
  virtual double etaShapeMeasure(){ return 0.; }
  double distoShapeMeasure()
  {
    double jmin, jmax;
    scaledJacRange(jmin, jmax);
    return jmin;
  }
  double minSICNShapeMeasure()
  {
    double sICNMin, sICNMax;
    signedInvCondNumRange(sICNMin, sICNMax);
    return sICNMin;
  }
  double minIsotropyMeasure(bool knownValid = false, bool reversedOk = false);
  double minScaledJacobian(bool knownValid = false, bool reversedOk = false);
  double specialQuality();
  double specialQuality2();
  virtual double angleShapeMeasure() { return 1.0; }
  virtual void scaledJacRange(double &jmin, double &jmax, GEntity *ge = 0) const;
  virtual void idealJacRange(double &jmin, double &jmax, GEntity *ge = 0);
  virtual void signedInvCondNumRange(double &iCNMin, double &iCNMax, GEntity *ge = 0);

  // get the radius of the inscribed circle/sphere if it exists,
  // otherwise get the minimum radius of all the circles/spheres
  // tangent to the most boundaries of the element.
  virtual double getInnerRadius(){ return 0.; }

  // get the radius of the circumscribed circle/sphere if it exists,
  // otherwise get the maximum radius of all the circles/spheres
  // tangent to the most boundaries of the element.
  virtual double getOuterRadius(){ return 0.; }

  // compute the barycenter
  virtual SPoint3 barycenter(bool primary = false) const;
  virtual SPoint3 barycenterUVW() const;
  // compute the barycenter in infinity norm
  virtual SPoint3 barycenter_infty() const;

  // reverse the orientation of the element
  virtual void reverse(){}

  // get volume of element
  virtual double getVolume();

  // return sign of volume (+1 or -1) for 3D elements (or 0 if element
  // has zero volume)
  virtual int getVolumeSign();

  // compute and change the orientation of 3D elements to get positive
  // volume (return false if element has zero volume)
  virtual bool setVolumePositive();

  // compute the extrema of the Jacobian determinant
  // return  1 if the element is valid,
  //         0 if the element is invalid,
  //        -1 if the element is reversed
  int getValidity();

  // return an information string for the element
  virtual std::string getInfoString();

  // get the function space for the element
  virtual const nodalBasis* getFunctionSpace(int order=-1, bool serendip=false) const;

  // get the function space for the jacobian of the element
  virtual const JacobianBasis* getJacobianFuncSpace(int order=-1) const;

  // return parametric coordinates (u,v,w) of a vertex
  virtual void getNode(int num, double &u, double &v, double &w) const;

  // return the interpolating nodal shape functions evaluated at point
  // (u,v,w) in parametric coordinates (if order == -1, use the
  // polynomial order of the element)
  virtual void getShapeFunctions(double u, double v, double w, double s[],
                                 int order=-1) const;

  // return the gradient of the nodal shape functions evaluated at
  // point (u,v,w) in parametric coordinates (if order == -1, use the
  // polynomial order of the element)
  virtual void getGradShapeFunctions(double u, double v, double w, double s[][3],
                                     int order=-1) const;
  virtual void getHessShapeFunctions(double u, double v, double w, double s[][3][3],
                                     int order=-1) const;
  virtual void getThirdDerivativeShapeFunctions(double u, double v, double w,
                                                double s[][3][3][3], int order=-1) const;
  // return the Jacobian of the element evaluated at point (u,v,w) in
  // parametric coordinates
  virtual double getJacobian(const fullMatrix<double> &gsf, double jac[3][3]) const;
  // To be compatible with _vgrads of functionSpace without having to put under
  // fullMatrix form
  virtual double getJacobian(const std::vector<SVector3> &gsf, double jac[3][3])const ;
  virtual double getJacobian(double u, double v, double w, double jac[3][3]) const;
  inline double getJacobian(double u, double v, double w, fullMatrix<double> &j) const{
    double JAC[3][3];
    const double detJ = getJacobian (u,v,w,JAC);
    for (int i=0;i<3;i++){
      j(i,0) = JAC[i][0];
      j(i,1) = JAC[i][1];
      j(i,2) = JAC[i][2];
    }
    return detJ;
  }
  virtual double getPrimaryJacobian(double u, double v, double w, double jac[3][3]) const;
  double getJacobianDeterminant(double u, double v, double w) const
  {
    double jac[3][3]; return getJacobian(u, v, w, jac);
  }
  void getSignedJacobian(fullVector<double> &jacobian, int o = -1) const;
  void getNodesCoord(fullMatrix<double> &nodesXYZ) const;
  virtual int getNumShapeFunctions() const { return getNumVertices(); }
  virtual int getNumPrimaryShapeFunctions() const { return getNumPrimaryVertices(); }
  virtual const MVertex *getShapeFunctionNode(int i) const { return getVertex(i); }
  virtual MVertex *getShapeFunctionNode(int i) { return getVertex(i); }

  // return the eigenvalues of the metric evaluated at point (u,v,w) in
  // parametric coordinates
  virtual double getEigenvaluesMetric(double u, double v, double w, double values[3]) const;

  // get the point in cartesian coordinates corresponding to the point
  // (u,v,w) in parametric coordinates
  virtual void pnt(double u, double v, double w, SPoint3 &p) const;
  // To be compatible with functionSpace without changing form
  virtual void pnt(const std::vector<double> &sf,SPoint3 &p) const;
  virtual void primaryPnt(double u, double v, double w, SPoint3 &p);

  // invert the parametrisation
  virtual void xyz2uvw(double xyz[3], double uvw[3]) const;

  // move point between parent and element parametric spaces
  virtual void movePointFromParentSpaceToElementSpace(double &u, double &v,
                                                      double &w) const;
  virtual void movePointFromElementSpaceToParentSpace(double &u, double &v,
                                                      double &w) const;

  // test if a point, given in parametric coordinates, belongs to the
  // element
  virtual bool isInside(double u, double v, double w) const = 0;

  // interpolate the given nodal data (resp. its gradient, curl and
  // divergence) at point (u,v,w) in parametric coordinates
  double interpolate(double val[], double u, double v, double w, int stride=1,
                     int order=-1);
  void interpolateGrad(double val[], double u, double v, double w, double f[],
                       int stride=1, double invjac[3][3]=0, int order=-1);
  void interpolateCurl(double val[], double u, double v, double w, double f[],
                       int stride=3, int order=-1);
  double interpolateDiv(double val[], double u, double v, double w, int stride=3,
                        int order=-1);

  // integration routines
  virtual void getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
  {
    Msg::Error("No integration points defined for this type of element: %d",
               this->getType());
  }
  double integrate(double val[], int pOrder, int stride=1, int order=-1);
  // val[] must contain interpolation data for face/edge vertices of given edge/face
  double integrateCirc(double val[], int edge, int pOrder, int order=-1);
  double integrateFlux(double val[], int face, int pOrder, int order=-1);

  // IO routines
  virtual void writeMSH(FILE *fp, bool binary=false, int elementary=1,
                        std::vector<short> *ghosts=0);
  virtual void writeMSH2(FILE *fp, double version=1.0, bool binary=false,
                         int num=0, int elementary=1, int physical=1,
                         int parentNum=0, int dom1Num = 0, int dom2Num = 0,
                         std::vector<short> *ghosts=0);
  virtual void writePOS(FILE *fp, bool printElementary, bool printElementNumber,
                        bool printSICN, bool printGamma, bool printRho,
                        bool printDisto,double scalingFactor=1.0, int elementary=1);
  virtual void writeSTL(FILE *fp, bool binary=false, double scalingFactor=1.0);
  virtual void writeVRML(FILE *fp);
  virtual void writePLY2(FILE *fp);
  virtual void writeUNV(FILE *fp, int num=0, int elementary=1, int physical=1);
  virtual void writeVTK(FILE *fp, bool binary=false, bool bigEndian=false);
  virtual void writeTOCHNOG(FILE *fp, int num);
  virtual void writeMESH(FILE *fp, int elementTagType=1, int elementary=1,
                         int physical=0);
  virtual void writeIR3(FILE *fp, int elementTagType, int num, int elementary,
                        int physical);
  virtual void writeBDF(FILE *fp, int format=0, int elementTagType=1,
                        int elementary=1, int physical=0);
  virtual void writeDIFF(FILE *fp, int num, bool binary=false,
                         int physical_property=1);
  virtual void writeINP(FILE *fp, int num);
  virtual void writeSU2(FILE *fp, int num);

  // info for specific IO formats (returning 0 means that the element
  // is not implemented in that format)
  virtual int getTypeForMSH() const { return 0; }
  virtual int getTypeForUNV() const { return 0; }
  virtual int getTypeForVTK() const { return 0; }
  virtual const char *getStringForTOCHNOG() const { return 0; }
  virtual const char *getStringForPOS() const { return 0; }
  virtual const char *getStringForBDF() const { return 0; }
  virtual const char *getStringForDIFF() const { return 0; }
  virtual const char *getStringForINP() const { return 0; }

  // return the number of vertices, as well as the element name if
  // 'name' != 0
  static int getInfoMSH(const int typeMSH, const char **const name=0);
  virtual int getNumVerticesForMSH() { return getNumVertices(); }
  virtual void getVerticesIdForMSH(std::vector<int> &verts);

  // copy element and parent if any, vertexMap contains the new vertices
  virtual MElement *copy(std::map<int, MVertex*> &vertexMap,
                         std::map<MElement*, MElement*> &newParents,
                         std::map<MElement*, MElement*> &newDomains);
};

class MElementFactory{
 public:
  MElement *create(int type, std::vector< MVertex* > &v, int num=0, int part=0,
                   bool owner=false, int parent=0, MElement *parent_ptr=NULL, MElement *d1 = 0, MElement *d2 = 0);
  MElement *create(int num, int type, const std::vector<int> &data, GModel *model);
};

// Traits of various elements based on the dimension.  These generally define
// the faces of 2-D elements as MEdge and 3-D elements as MFace.

template <unsigned DIM> struct DimTr;
template <> struct DimTr<2>
{
  typedef MEdge FaceT;
  static int getNumFace(MElement *const element)
  {
    return element->getNumEdges();
  }
  static MEdge getFace(MElement *const element, const int iFace)
  {
    return element->getEdge(iFace);
  }
  static void getAllFaceVertices(MElement *const element, const int iFace,
                                 std::vector<MVertex*> &v)
  {
    element->getEdgeVertices(iFace, v);
  }
};

template <> struct DimTr<3>
{
  typedef MFace FaceT;
  static int getNumFace(MElement *const element)
  {
    return element->getNumFaces();
  }
  static MFace getFace(MElement *const element, const int iFace)
  {
    return element->getFace(iFace);
  }
  static void getAllFaceVertices(MElement *const element, const int iFace,
                                 std::vector<MVertex*> &v)
  {
    element->getFaceVertices(iFace, v);
  }
};

struct Less_ElementPtr : public std::binary_function<MElement *, MElement *, bool> {
  bool operator()(const MElement *e1, const MElement *e2) const
  {
    return e1->getNum()<e2->getNum();
  }
};

#endif
