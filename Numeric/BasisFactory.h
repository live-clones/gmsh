// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef BASISFACTORY_H
#define BASISFACTORY_H

#include "JacobianBasis.h"
#include "FuncSpaceData.h"
class nodalBasis;
class MetricBasis;
class GradientBasis;
class bezierBasis;
class CondNumBasis;

class BasisFactory
{
 private:
  static std::map<int, nodalBasis*> fs;
  static std::map<int, MetricBasis*> ms;
  static std::map<int, CondNumBasis*> cs;
  static std::map<FuncSpaceData, JacobianBasis*> js;
  static std::map<FuncSpaceData, bezierBasis*> bs;
  static std::map<FuncSpaceData, GradientBasis*> gs;

 public:
  // Caution: the returned pointer can be NULL

  // Nodal
  static const nodalBasis* getNodalBasis(int tag);

  // Jacobian
  // Warning: bases returned by BasisFactory::getJacobianBasis(int tag) are the
  // only safe bases for using Bezier on the jacobian determinant!
  static const JacobianBasis* getJacobianBasis(FuncSpaceData);
  static const JacobianBasis* getJacobianBasis(int tag, int order) {
    const int type = ElementType::ParentTypeFromTag(tag);
    if (type != TYPE_PYR)
      return getJacobianBasis(FuncSpaceData(true, tag, order));
    else
      return getJacobianBasis(FuncSpaceData(true, tag, false, order+1, order));
  }
  static const JacobianBasis* getJacobianBasis(int tag) {
    const int order = JacobianBasis::jacobianOrder(tag);
    const int type = ElementType::ParentTypeFromTag(tag);
    if (type != TYPE_PYR)
      return getJacobianBasis(FuncSpaceData(true, tag, order));
    else
      return getJacobianBasis(FuncSpaceData(true, tag, false, order+2, order));
  }

  // Metric
  static const MetricBasis* getMetricBasis(int tag);

  // Condition number
  static const CondNumBasis* getCondNumBasis(int tag, int cnOrder = -1);

  // Gradients
  static const GradientBasis* getGradientBasis(FuncSpaceData);
  static const GradientBasis* getGradientBasis(int tag, int order) {
    return getGradientBasis(FuncSpaceData(true, tag, order));
  }

  // Bezier
  static const bezierBasis* getBezierBasis(FuncSpaceData);
  static const bezierBasis* getBezierBasis(int parentTag, int order) {
    int primaryTag = ElementType::getTag(parentTag, 1);
    return getBezierBasis(FuncSpaceData(true, primaryTag, order));
  }
  static const bezierBasis* getBezierBasis(int tag) {
    return getBezierBasis(FuncSpaceData(tag));
  }

  static void clearAll();
};

#endif
