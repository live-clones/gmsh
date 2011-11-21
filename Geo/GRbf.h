#ifndef _RBF_H
#define _RBF_H

#include <math.h>
#include <vector>
#include "fullMatrix.h"
#include "SPoint3.h"
#include "SVector3.h"
#include "MVertex.h"
#include "Context.h"
#if defined(HAVE_ANN)
class ANNkd_tree;
#endif


class Sphere{
 public:
  int index;
  SPoint3 center;
  double radius;
};

class GRbf {

  std::map<MVertex*, int> _mapV;
  std::map<MVertex*, int> _mapAllV;
  std::map<int, std::vector<int> > nodesInSphere;

  fullMatrix<double> matA, matAInv;
  fullMatrix<double> matA_nn, matAInv_nn;

  int nbNodes; //initial nodes
  bool isLocal;
  int nn;
  int num_neighbours;

  int _inUV;
  double delta; //offset level set
  double deltaUV; //offset level set
  double radius;
  double sBox;

  SVector3 lastDXDU, lastDXDV;
  double lastX, lastY, lastZ, lastU, lastV;

  int variableShapeParam; 
  int radialFunctionIndex; // Index for the radial function used (0 - GA,1 - MQ, ... )

  std::set<MVertex *> myNodes; //Used mesh vertices for light rbf
  fullMatrix<double> centers; // Data centers (without duplicates)
  fullMatrix<double> allCenters; // Data centers
  fullMatrix<double> normals; // Data normals(without Duplicates)
  fullMatrix<double> surfInterp;//level set
  fullMatrix<double> extendedX;//X values extend in and out
  fullMatrix<double> UV;//solution harmonic map laplu=0 and laplV=0

#if defined (HAVE_ANN)
  ANNkd_tree *XYZkdtree; 
  ANNkd_tree *UVkdtree; 
#endif

 public:

  GRbf (double sizeBox, int variableEps, int rbfFun, 
	std::map<MVertex*, SVector3> normals, 
	std::set<MVertex *> allNodes, std::vector<MVertex*> bcNodes, bool isLocal = false);
  ~GRbf();

  //build octree
  void buildOctree(double radius);
  void buildXYZkdtree();

  // Sets up the surface generation problem as suggested by Beatson et al. Introduction of 2 extra points per node. The
  // function values at the nodes on the surface are set to 0 while the function values inside are set to -1 and outside to 1.
  void setup_level_set(const fullMatrix<double> &cntrs,
		       const fullMatrix<double> &normals,
		       fullMatrix<double> &level_set_nodes, 
		       fullMatrix<double> &level_set_funvals);
	
  // Evaluates the (p)th derivative of the radial function w.r.t. r^2 (not w.r.t. r)
  // This is to avoid the introduction of removable singularities at r=0.
  double evalRadialFnDer (int p, double dx, double dy, double dz, double ep);
	
	
  // Generates the RBF collocation matrix for data in d-dimensions, associated with the
  //(p)th derivative of the radial function w.r.t. the (q)th variable
  fullMatrix<double> generateRbfMat(int p,
				    const fullMatrix<double> &nodes1,
				    const fullMatrix<double> &nodes2);
  
  // Computes the interpolation(p==0) or the derivative (p!=0) operator(mxn) (n:number of centers, m: number of evaluation nodes)
  void RbfOp(int p, // (p)th derivatives
	     const fullMatrix<double> &cntrs,
	     const fullMatrix<double> &nodes, 
	     fullMatrix<double> &D);

  // Computes the interpolant(p==0) or the derivative (p!=0) of the function values entered and evaluates it at the new nodes
  void evalRbfDer(int p, // (p)th derivatives
		  const fullMatrix<double> &cntrs,
		  const fullMatrix<double> &nodes,
		  const fullMatrix<double> &fValues, 
		  fullMatrix<double> &fApprox);

  // Finds surface differentiation matrix using the LOCAL projection method
  void RbfLapSurface_local_projection(const fullMatrix<double> &cntrs,
				      const fullMatrix<double> &normals,
				      fullMatrix<double> &Oper);

  // Finds global surface differentiation matrix using the projection method
  void RbfLapSurface_global_projection(const fullMatrix<double> &cntrs,
				       const fullMatrix<double> &normals,
				       fullMatrix<double> &Oper);

  // Finds surface differentiation matrix (method CPML LOCAL)
  void RbfLapSurface_local_CPM(bool isLow,
			       const fullMatrix<double> &cntrs,
			       const fullMatrix<double> &normals,
			       fullMatrix<double> &Oper);
  
  // Finds global surface differentiation matrix (method CPML)
  void RbfLapSurface_global_CPM_low(const fullMatrix<double> &cntrs,
				    const fullMatrix<double> &normals,
				    fullMatrix<double> &D);
  
  // Finds global surface differentiation matrix (method CPMH)
  void RbfLapSurface_global_CPM_high(const fullMatrix<double> &cntrs,
				     const fullMatrix<double> &normals,
				     fullMatrix<double> &D);

  // Second method that Finds global surface differentiation matrix (method CPMH)
  void RbfLapSurface_global_CPM_high_2(const fullMatrix<double> &cntrs,
				     const fullMatrix<double> &normals,
				     fullMatrix<double> &D);
  
  // Calculates the curvature of a surface at centers

  void curvatureRBF(const fullMatrix<double> &cntrs,
		    fullMatrix<double> &curvature);

  void computeCurvature(const fullMatrix<double> &cntrs, 
			std::map<MVertex*, double>&rbf_curv);

  void computeLocalCurvature(const fullMatrix<double> &cntrs, 
		       std::map<MVertex*, double>&rbf_curv);

  //Finds the U,V,S (in the 0-level set) that are the 'num_neighbours' closest to u_eval and v_eval.
  //Thus in total, we're working with '3*num_neighbours' nodes
  //Say that the vector 'index' gives us the indices of the closest points
 bool UVStoXYZ(const double u_eval, const double v_eval,
	       double &XX, double &YY, double &ZZ,
	       SVector3 &dXdu, SVector3& dxdv, int num_neighbours=15);

 void solveHarmonicMap(fullMatrix<double> Oper, std::vector<MVertex*> ordered, 
		       std::vector<double> coords, std::map<MVertex*, SPoint3> &rbf_param);

 inline const fullMatrix<double> getUV() {return UV;};
 inline const fullMatrix<double> getXYZ() {return centers;};
 inline const fullMatrix<double> getN() {return normals;};

};

#endif
