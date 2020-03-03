#ifndef AUTOMATIC_MESH_SIZE_FIELD_H
#define AUTOMATIC_MESH_SIZE_FIELD_H

#include "GmshConfig.h"
#include "GModel.h"
#include "GRegion.h"
#include "MTriangle.h"
#include "MLine.h"
#include "Field.h"

#ifdef HAVE_HXT
#include "hxt_octree.h"
#endif

class automaticMeshSizeField : public Field {

#if defined(HAVE_HXT) && defined(HAVE_P4EST)
  struct HXTForest *forest;
  struct HXTForestOptions *forestOptions;
  HXTStatus updateHXT();
#endif

  std::string _forestFile;
  int _nPointsPerCircle;
  int _nPointsPerGap;
  double _hmin, _hmax;
  double _hbulk;
  double _gradientMax;
  int _nRefine;
  bool _smoothing, _gaps,_tetMesh;

 public:
  ~automaticMeshSizeField();
  automaticMeshSizeField() : 
#if defined(HAVE_HXT) && defined(HAVE_P4EST)
  forest(NULL), forestOptions(NULL)
#endif
  {
    _forestFile = "";
    _nPointsPerCircle = 30;
    _nPointsPerGap = 4;
    _hmin  = -1.0;// update needed
    _hmax  = -1.0;// update needed    
    _hbulk = -1.0; // update needed
    _gradientMax = 1.1;
    _nRefine = 20;
    _smoothing = true;
    _gaps = true;
    _tetMesh = false;

    options["FileToLoad"] = new FieldOptionString(_forestFile,
                 "p4est file containing the size field",&update_needed);    

    options["nPointsPerCircle"] = new FieldOptionInt(_nPointsPerCircle,
						     "Number of points per circle (adapt to curvature of surfaces)",&update_needed);

    options["nPointsPerGap"] = new FieldOptionInt(_nPointsPerGap,
						  "Number of points in thin layers",&update_needed);

    options["hMin"] = new FieldOptionDouble(_hmin,
               "Minimum size", &update_needed);

    options["hMax"] = new FieldOptionDouble(_hmax,
               "Maximum size", &update_needed);
    
    options["hBulk"] = new FieldOptionDouble(_hbulk,
					     "Size everywhere no size is prescribed", &update_needed);

    options["gradientMax"] = new FieldOptionDouble(_gradientMax,
						   "Maximum gradient of the size field",&update_needed);
  
    options["NRefine"] = new FieldOptionInt(_nRefine,
					    "Initial refinement level for the octree",&update_needed);

    options["Smoothing"] = new FieldOptionBool(_smoothing,
              "Lissage ?",&update_needed);

    options["Gaps"] = new FieldOptionBool(_gaps,
              "Tenir compte des gaps ?",&update_needed);

    // options["TetMesh"] = new FieldOptionBool(_tetMesh,
    //           "Generate 3D mesh ? (choose if surface mesh has already been recomputed)",&update_needed);

    update_needed = true;
    // update();
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
