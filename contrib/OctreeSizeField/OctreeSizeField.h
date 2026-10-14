// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Successor of src/mesh/automaticMeshSizeField.{h,cpp} (originally
// contributed by Arthur Bawin), reimplemented on top of the hand-written
// SizeOctree (contrib/OctreeSizeField/SizeOctree.h) instead of p4est -- see
// that file's header comment for the rationale. Implements the algorithm of
// Bawin, Henrotte, Remacle, "Automatic feature-preserving size field for
// three-dimensional mesh generation", IJNME 2021. Isotropic and 3D only (the
// anisotropic path and the unfinished 2D path from the original
// implementation are out of scope, see the design notes next to the
// implementation).
//
// The class is intentionally still named "AutomaticMeshSizeField" through
// getName(), so that existing .geo scripts using
// `Field[1] = AutomaticMeshSizeField;` keep working unchanged.

#ifndef OCTREE_SIZE_FIELD_H
#define OCTREE_SIZE_FIELD_H

#include "GmshConfig.h"
#include "Field.h"
#include "Context.h"

#if defined(HAVE_HXT)
extern "C" {
#include "hxt_tools.h"
}
#include "SizeOctree.h"
#endif

class OctreeSizeField : public Field {
#if defined(HAVE_HXT)
  SizeOctree *_octree;
  HXTStatus updateHXT();
#endif

  int _nPointsPerCircle;
  int _nPointsPerGap;
  double _hmin, _hmax;
  double _hbulk;
  double _gradation;
  bool _smoothing, _features, _exportPos;

public:
  OctreeSizeField(
    int minElementsPerTwoPi = CTX::instance()->mesh.lcFromCurvature,
    int nLayersPerGap = CTX::instance()->mesh.nLayersPerGap,
    double gradation = CTX::instance()->mesh.gradation, double hmin = -1.0,
    double hmax = -1.0, double hbulk = -1.0, bool smoothing = true,
    bool features = true, bool exportPos = false)
#if defined(HAVE_HXT)
    : _octree(nullptr)
#endif
  {
    _nPointsPerCircle = minElementsPerTwoPi ? minElementsPerTwoPi : 20;
    _nPointsPerGap = nLayersPerGap ? nLayersPerGap : 0;
    _hmin = hmin;
    _hmax = hmax;
    _hbulk = hbulk;
    _gradation = (int)gradation ? gradation : 1.1;
    _smoothing = smoothing;
    _features = features;
    _exportPos = exportPos;

    options["nPointsPerCircle"] = new FieldOptionInt(
      _nPointsPerCircle,
      "Number of points per circle (adapt to curvature of surfaces)",
      &updateNeeded);

    options["nPointsPerGap"] = new FieldOptionInt(
      _nPointsPerGap, "Number of layers of elements in thin layers",
      &updateNeeded);

    options["hMin"] =
      new FieldOptionDouble(_hmin, "Minimum size", &updateNeeded);

    options["hMax"] =
      new FieldOptionDouble(_hmax, "Maximum size", &updateNeeded);

    options["hBulk"] = new FieldOptionDouble(
      _hbulk, "Default size where it is not prescribed", &updateNeeded);

    options["gradation"] = new FieldOptionDouble(
      _gradation, "Maximum growth ratio for the edges lengths", &updateNeeded);

    options["smoothing"] = new FieldOptionBool(
      _smoothing, "Enable size smoothing (should always be true)",
      &updateNeeded);

    options["features"] = new FieldOptionBool(
      _features, "Enable computation of local feature size (thin channels)",
      &updateNeeded);

    options["exportPos"] = new FieldOptionBool(
      _exportPos,
      "Export the octree size field to a .pos file for debugging, "
      "named after the model",
      &updateNeeded);

    updateNeeded = true;
  }

  ~OctreeSizeField();

  virtual bool isotropic() const { return true; }
  const char *getName() { return "AutomaticMeshSizeField"; }

  std::string getDescription()
  {
    return "Compute a mesh size field that is quite automatic "
           "Takes into account surface curvatures and closeness of objects";
  }

  void update();
  virtual double operator()(double X, double Y, double Z,
                            GEntity *ge = nullptr);
};

#endif
