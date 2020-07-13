#ifndef AUTOMATIC_MESH_SIZE_FIELD_H
#define AUTOMATIC_MESH_SIZE_FIELD_H

#include "GmshConfig.h"
#include "GModel.h"
#include "GRegion.h"
#include "MTriangle.h"
#include "MLine.h"
#include "Field.h"
#include "Context.h"

#include "rtree.h"

#if defined(HAVE_HXT) && defined(HAVE_P4EST)
// P4EST INCLUDES
#ifdef HAVE_P4EST
#include <p4est_to_p8est.h>
#include <p8est_extended.h>
#endif

// HXT INCLUDES
extern "C" {
  #include "hxt_tools.h"
  #include "hxt_mesh.h"
  #include "hxt_bbox.h"
}
#endif

// Information needed to create and compute a forest of octrees
typedef struct ForestOptions{
  int           dim;
  double        hmax;
  double        hmin;
  double        hbulk;
  double        gradation;
  int           nodePerTwoPi;
  int           nodePerGap;
  double       *bbox;
  double      (*sizeFunction)(double, double, double, double);
  RTree<uint64_t,double,3>  *triRTree;
  HXTMesh                   *mesh;
  double                    *nodalCurvature;
  double                    *nodeNormals;
  std::vector<std::function<double(double)>> *curvFunctions;
  std::vector<std::function<double(double)>> *xFunctions;
  std::vector<std::function<double(double)>> *yFunctions;
} ForestOptions;

// The structure containing the size field information (forest)
typedef struct Forest{
#ifdef HAVE_P4EST
  p4est_t *p4est;
#endif 
  ForestOptions *forestOptions;
} Forest;

// Data available on each tree cell
typedef struct size_data{
  double size;
#ifdef HAVE_P4EST
  double ds[3]; // Size gradient
#endif
  double h;     // Isotropic cell size
} size_data_t;

// A node to search in the tree
typedef struct size_point{
  double x;
  double y;
  double z;
  double size;
  bool isFound;
} size_point_t;

HXTStatus forestOptionsCreate(ForestOptions **forestOptions);
HXTStatus forestOptionsDelete(ForestOptions **forestOptions);

HXTStatus forestCreate(int argc, char **argv, Forest **forest, const char* filename, ForestOptions *forestOptions);
HXTStatus forestDelete(Forest **forest);

HXTStatus forestSave(Forest *forest, const char* forestFile, const char *dataFile);
HXTStatus forestExport(Forest *forest, const char *forestFile);
HXTStatus forestExport2D(Forest *forest, const char *forestFile);
HXTStatus forestLoad(Forest **forest, const char* forestFile, const char *dataFile, ForestOptions *forestOptions);

HXTStatus forestSearchOne(Forest *forest, double x, double y, double z, double *size, int linear);

class automaticMeshSizeField : public Field {

#if defined(HAVE_HXT) && defined(HAVE_P4EST)
  // struct HXTForest *forest;
  // struct HXTForestOptions *forestOptions;
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
  automaticMeshSizeField(std::string fFile = "",
                         int minElementsPerTwoPi = CTX::instance()->mesh.minElementsPerTwoPi,
                         int nLayersPerGap       = CTX::instance()->mesh.nLayersPerGap,
                         double gradation        = CTX::instance()->mesh.gradation,
                         double hmin = -1.0,
                         double hmax = -1.0,
                         double hbulk = -1.0,
                         int smoothing = true,
                         int gaps = true)  
#if defined(HAVE_HXT) && defined(HAVE_P4EST)
  :  forest(NULL), forestOptions(NULL)
#endif
  {
    _forestFile       = fFile;
    _nPointsPerCircle = minElementsPerTwoPi ? minElementsPerTwoPi : 20;
    _nPointsPerGap    = nLayersPerGap ? nLayersPerGap : 0;
    _hmin             = hmin;
    _hmax             = hmax;   
    _hbulk            = hbulk;
    _gradation        = (int) gradation ? gradation : 1.1;
    _smoothing        = smoothing;
    _gaps             = gaps;

    options["p4estFileToLoad"] = new FieldOptionString(_forestFile,
                 "p4est file containing the size field",&update_needed);    

    options["nPointsPerCircle"] = new FieldOptionInt(_nPointsPerCircle,
						     "Number of points per circle (adapt to curvature of surfaces)",&update_needed);

    options["nPointsPerGap"] = new FieldOptionInt(_nPointsPerGap,
						  "Number of layers of elements in thin layers",&update_needed);

    options["hMin"] = new FieldOptionDouble(_hmin,
               "Minimum size", &update_needed);

    options["hMax"] = new FieldOptionDouble(_hmax,
               "Maximum size", &update_needed);
    
    options["hBulk"] = new FieldOptionDouble(_hbulk,
					     "Default size where it is not prescribed", &update_needed);

    options["gradation"] = new FieldOptionDouble(_gradation,
						   "Maximum growth ratio for the edges lengths",&update_needed);

    options["smoothing"] = new FieldOptionBool(_smoothing,
              "Enable size smoothing (should always be true)",&update_needed);

    options["features"] = new FieldOptionBool(_gaps,
              "Enable computation of local feature size (thin channels)",&update_needed);

    update_needed = true;

    if (fFile != "") update();
  }

  const char *getName() { return "AutomaticMeshSizeField"; }

  std::string getDescription()
  {
    return "Compute a mesh size field that is quite automatic "
           "Takes into account surface curvatures and closeness of objects";
  }

  void update();
  virtual double operator()(double X, double Y, double Z, GEntity *ge = 0);
};

#endif
