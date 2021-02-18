// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Arthur Bawin

#ifndef AUTOMATIC_MESH_SIZE_FIELD_H
#define AUTOMATIC_MESH_SIZE_FIELD_H

#include "GmshConfig.h"
#include "GModel.h"
#include "GRegion.h"
#include "MTriangle.h"
#include "MLine.h"
#include "Field.h"
#include "Context.h"
#include "STensor3.h"
#include "curvature.h"

#include "rtree.h"

#if defined(HAVE_P4EST)
// P4EST INCLUDES
#include <p4est_to_p8est.h>
#include <p8est_extended.h>
#endif

#if defined(HAVE_HXT)
// HXT INCLUDES
extern "C" {
#include "hxt_tools.h"
#include "hxt_mesh.h"
#include "hxt_bbox.h"
}
#endif

// Information needed to create and compute a forest of octrees
typedef struct ForestOptions {
  int dim;
  double hmax;
  double hmin;
  double hbulk;
  double gradation;
  int nodePerTwoPi;
  int nodePerGap;
  double *bbox;
  double (*sizeFunction)(double, double, double, double);
  std::vector<double> *featureSizeAtVertices;
  RTree<uint64_t, double, 3> *triRTree;
#ifdef HAVE_HXT
  HXTMesh *mesh;
#endif
  double *nodalCurvature;
  double *nodeNormals;
  // std::vector<std::function<double(double)>> *curvFunctions;
  // std::vector<std::function<double(double)>> *xFunctions;
  // std::vector<std::function<double(double)>> *yFunctions;
  FILE *file1;
  FILE *file2;
  FILE *file3;
} ForestOptions;

// The structure containing the size field information (forest)
typedef struct Forest {
#ifdef HAVE_P4EST
  p4est_t *p4est;
#endif
  ForestOptions *forestOptions;
} Forest;

// Data available on each tree cell
typedef struct size_data {
  double size;
#ifdef HAVE_P4EST
  double ds[3]; // Size gradient
#endif
  double h; // Isotropic cell size
  SMetric3 M; // Anisotropic size

  // Données pour l'interpolation des directions de courbure
  bool hasIntersection;
  SVector3 t1, t2, n;

} size_data_t;

// A node to search in the tree
typedef struct size_point {
  double x;
  double y;
  double z;
  double size;
  SMetric3 m;
  bool isFound;
  int parcourus;
} size_point_t;

typedef struct interpolation_data {
  double center[3];
  SVector3 t1;
  SVector3 t2;
  double denom;
} interpolation_data_t;

#if defined(HAVE_HXT) && defined(HAVE_P4EST)
HXTStatus forestOptionsCreate(ForestOptions **forestOptions);
HXTStatus forestOptionsDelete(ForestOptions **forestOptions);

HXTStatus forestCreate(int argc, char **argv, Forest **forest,
                       const char *filename, ForestOptions *forestOptions);
HXTStatus forestDelete(Forest **forest);

HXTStatus forestSave(Forest *forest, const char *forestFile,
                     const char *dataFile);
HXTStatus forestExport(Forest *forest, const char *forestFile);
HXTStatus forestExport2D(Forest *forest, const char *forestFile);
HXTStatus forestLoad(Forest **forest, const char *forestFile,
                     const char *dataFile, ForestOptions *forestOptions);

HXTStatus forestSearchOne(Forest *forest, double x, double y, double z,
                          double *size, int linear);
#endif

class automaticMeshSizeField : public Field {
#if defined(HAVE_HXT) && defined(HAVE_P4EST)
  struct Forest *forest;
  struct ForestOptions *forestOptions;
  HXTStatus updateHXT();
#endif

  std::string _forestFile;
  int _nPointsPerCircle;
  int _nPointsPerGap;
  double _hmin, _hmax;
  double _hbulk;
  double _gradation;
  bool _smoothing, _gaps;

public:
  ~automaticMeshSizeField();
  automaticMeshSizeField(
    std::string fFile = "",
    int minElementsPerTwoPi = CTX::instance()->mesh.lcFromCurvature,
    int nLayersPerGap = CTX::instance()->mesh.nLayersPerGap,
    double gradation = CTX::instance()->mesh.gradation, double hmin = -1.0,
    double hmax = -1.0, double hbulk = -1.0, int smoothing = true,
    int gaps = true)
#if defined(HAVE_HXT) && defined(HAVE_P4EST)
    : forest(nullptr), forestOptions(nullptr)
#endif
  {
    _forestFile = fFile;
    _nPointsPerCircle = minElementsPerTwoPi ? minElementsPerTwoPi : 20;
    _nPointsPerGap = nLayersPerGap ? nLayersPerGap : 0;
    _hmin = hmin;
    _hmax = hmax;
    _hbulk = hbulk;
    _gradation = (int)gradation ? gradation : 1.1;
    _smoothing = smoothing;
    _gaps = gaps;

    options["p4estFileToLoad"] = new FieldOptionString(
      _forestFile, "p4est file containing the size field", &updateNeeded);

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
      _gaps, "Enable computation of local feature size (thin channels)",
      &updateNeeded);

    updateNeeded = true;

    if(fFile != "") update();
  }

  virtual bool isotropic() const { return false; }
  const char *getName() { return "AutomaticMeshSizeField"; }

  std::string getDescription()
  {
    return "Compute a mesh size field that is quite automatic "
           "Takes into account surface curvatures and closeness of objects";
  }

  void update();
  virtual double operator()(double X, double Y, double Z,
                            GEntity *ge = nullptr);
  virtual void operator()(double x, double y, double z, SMetric3 &m,
                          GEntity *ge = nullptr);
};

#endif
