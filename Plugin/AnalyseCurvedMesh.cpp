// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#include "GmshDefines.h"
#include <stdlib.h>
#include "Gmsh.h"
#include "MTriangle.h"
#include "GmshConfig.h"
#include "GModel.h"
#include "polynomialBasis.h"
#include "JacobianBasis.h"
#include "AnalyseCurvedMesh.h"
#include "fullMatrix.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterAnalyseCurvedMeshPlugin()
  {
    return new GMSH_AnalyseCurvedMeshPlugin();
  }
}

std::string GMSH_AnalyseCurvedMeshPlugin::getHelp() const
{
  return "Plugin(AnalyseCurvedMesh) check the jacobian of all elements of the greater dimension. Elements for which we are absolutely certain that they are good (positive jacobian) are ignored. Others are only suppose to be wrong."
    "Plugin(AnalyseCurvedMesh) write in the console which elements are supposed to be wrong. (if labels of analysed type of elements are set visible, only supposed wrong elements will be visible)";
}

static double computeDeterminant(MElement *el, double jac[3][3])
{
  switch (el->getDim()) {
  case 0:
    return 1.0;
  case 1:
    return jac[0][0];
  case 2:
    return jac[0][0] * jac[1][1] - jac[0][1] * jac[1][0];
  case 3:
    return jac[0][0] * jac[1][1] * jac[2][2] + jac[0][2] * jac[1][0] * jac[2][1] +
           jac[0][1] * jac[1][2] * jac[2][0] - jac[0][2] * jac[1][1] * jac[2][0] -
           jac[0][0] * jac[1][2] * jac[2][1] - jac[0][1] * jac[1][0] * jac[2][2];
	default:
		return 1;
  }
}

double getJacobian(double gsf[][3], double jac[3][3], MElement *el)
{
  jac[0][0] = jac[0][1] = jac[0][2] = 0.;
  jac[1][0] = jac[1][1] = jac[1][2] = 0.;
  jac[2][0] = jac[2][1] = jac[2][2] = 0.;

  for (int i = 0; i < el->getNumVertices(); i++) {
    const MVertex *v = el->getVertex(i);
    double *gg = gsf[i];
    for (int j = 0; j < 3; j++) {
      jac[j][0] += v->x() * gg[j];
      jac[j][1] += v->y() * gg[j];
      jac[j][2] += v->z() * gg[j];
    }
  }

  return computeDeterminant(el, jac);
}

PView *GMSH_AnalyseCurvedMeshPlugin::execute(PView *v)
{
	Msg::Info("AnalyseCurvedMeshPlugin : Starting analyse.");
	int numBadEl = 0;
	int numAnalysedEl = 0;

	GModel *m = GModel::current();

	JacobianBases::find(MSH_QUA_8);
	JacobianBases::find(MSH_QUA_9);
	JacobianBases::find(MSH_TET_20);
	JacobianBases::find(MSH_PRI_18);

	switch (m->getDim()) {

		case 3 :
			{
				Msg::Info("Only 3D elements will be analyse.");
				for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); it++) {
					GRegion *r = *it;
					
					unsigned int numType[5] = {0, 0, 0, 0, 0};
					r->getNumMeshElements(numType);

					for(int type = 0; type < 5; type++) { // loop over all types of elements
						MElement *const *el = r->getStartElementType(type);
						
						for(unsigned int i = 0; i < numType[type]; i++) { // loop over all elements of a type
							numAnalysedEl++;
							if (checkJacobian((*(el+i)), 0) <= 0) numBadEl++;
						}
					}
				}
				break;
			}

		case 2 :
			{
				Msg::Info("Only 2D elements will be analyse.");
				Msg::Warning("2D elements must be in a z=cst plane ! If they aren't, results won't be correct.");
				for (GModel::fiter it = m->firstFace(); it != m->lastFace(); it++) {
					GFace *f = *it;
					
					unsigned int numType[3] = {0, 0, 0};
					f->getNumMeshElements(numType);

					for (int type = 0; type < 3; type++) {
						MElement *const *el = f->getStartElementType(type);

						for (unsigned int i = 0; i < numType[type]; i++) {
							numAnalysedEl++;
							if (checkJacobian((*(el+i)), 0) <= 0) numBadEl++;
						}
					}
				}
				break;
			}

		case 1 :
			{
				Msg::Info("Only 1D elements will be analyse.");
				Msg::Warning("1D elements must be on a y=cst & z=cst line ! If they aren't, results won't be correct.");
				for (GModel::eiter it = m->firstEdge(); it != m->lastEdge(); it++) {
					GEdge *e = *it;
					
					unsigned int *numElement = {0};
					e->getNumMeshElements(numElement);

					MElement *const *el = e->getStartElementType(0);

					for (unsigned int i = 0; i < *numElement; i++) {
						numAnalysedEl++;
						if (checkJacobian((*(el+i)), 0) <= 0) numBadEl++;
					}
				}
				break;
			}

		default :
			{
				Msg::Error("I can't analyse any element.");
			}
	}
	
	Msg::Info("%d elements have been analysed.", numAnalysedEl);
	Msg::Info("%d elements may be bad.", numBadEl);
	Msg::Info("AnalyseCurvedMeshPlugin : Job finished.");

  return 0;
}

bool GMSH_AnalyseCurvedMeshPlugin::isJacPositive(MElement *el)
{
	const polynomialBasis *fs = el->getFunctionSpace(-1);
	if (!fs) {
		Msg::Error("Function space not implemented for type of element %d", el->getNum());
		return false;
	}
	const JacobianBasis *jfs = el->getJacobianFuncSpace(-1);
	if (!jfs) {
		Msg::Error("Jacobian function space not implemented for type of element %d", el->getNum());
		return false;
	}
	int numSamplingPt = jfs->points.size1();
	int dim = jfs->points.size2();
	bool isPositive = true;
	fullVector<double> jacobian(numSamplingPt);

	for (int i = 0; i < numSamplingPt; i++) {
		double gsf[256][3];
		switch (dim) {
			case 1:
				fs->df(jfs->points(i,0),0,0, gsf);
				break;
			case 2:
				fs->df(jfs->points(i,0),jfs->points(i,1),0, gsf);
				break;
			case 3:
				fs->df(jfs->points(i,0),jfs->points(i,1),jfs->points(i,2), gsf);
				break;
			default:
				Msg::Error("Can't get the gradient for %dD elements.", dim);
				return false;
		}
		double jac[3][3];
		jacobian(i) = getJacobian(gsf, jac, el);
	}

	fullVector<double> jacBez(jacobian.size());

	jfs->matrixLag2Bez.mult(jacobian, jacBez);

	for (int i = 0; i < jacBez.size(); i++) {
		if (jacBez(i) < 0.) isPositive = false;
	}

	//Msg::Info("%d", el->getNum());
	//if (el->getNum() == 582 || el->getNum() == 584) {
	//	for (int i = 0; i < jfs->points.size1(); i++) {
	//		Msg::Info("jacBez[%d] = %lf, jacobian[%d] = %lf", i, jacBez(i), i, jacobian(i));
	//	}
	//}

	return isPositive;
}

int GMSH_AnalyseCurvedMeshPlugin::checkJacobian(MElement *el, int depth)
{
	int tag = method1(el, depth);
	if (tag < 0) {
		Msg::Info("Bad element : %d", el->getNum());
	}
	else if (tag > 0) {
		el->setVisibility(0);
	}
	else {
		Msg::Info("Element %d may be bad.", el->getNum());
	}
	return tag;
}

int GMSH_AnalyseCurvedMeshPlugin::method1(MElement *el, int depth)
{
	const polynomialBasis *fs = el->getFunctionSpace(-1);
	if (!fs) {
		Msg::Error("Function space not implemented for type of element %d", el->getNum());
		return 0;
	}
	const JacobianBasis *jfs = el->getJacobianFuncSpace(-1);
	if (!jfs) {
		Msg::Error("Jacobian function space not implemented for type of element %d", el->getNum());
		return 0;
	}
	int numSamplingPt = jfs->points.size1(), dim = jfs->points.size2();
	fullVector<double> jacobian(numSamplingPt);

	for (int i = 0; i < numSamplingPt; i++) {
		double gsf[256][3];
		switch (dim) {
			case 1:
				fs->df(jfs->points(i,0),0,0, gsf);
				break;
			case 2:
				fs->df(jfs->points(i,0),jfs->points(i,1),0, gsf);
				break;
			case 3:
				fs->df(jfs->points(i,0),jfs->points(i,1),jfs->points(i,2), gsf);
				break;
			default:
				Msg::Error("Can't get the gradient for %dD elements.", dim);
				return false;
		}
		double jac[3][3];
		jacobian(i) = getJacobian(gsf, jac, el);
	}

	for (int i = 0; i < jacobian.size(); i++) {
		if (jacobian(i) < 0.) return -1;
	}

	fullVector<double> jacBez(jacobian.size());
	jfs->matrixLag2Bez.mult(jacobian, jacBez);

	bool allPtPositive = true;
	for (int i = 0; i < jacBez.size(); i++) {
		if (jacBez(i) < 0.) allPtPositive = false;
	}
	if (allPtPositive) return 1;

	if (depth <= 0) {
		return 0;
	}
	//else{return division(el, depth-1);}

	return 0;
}