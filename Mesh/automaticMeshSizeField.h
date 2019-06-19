#ifndef _AUTOMATIC_MESH_SIZE_FIELD_H_
#define _AUTOMATIC_MESH_SIZE_FIELD_H_

#include "GmshConfig.h"

#ifdef HAVE_HXT
#include "hxt_octree.h"
#endif

#include "Field.h"

class automaticMeshSizeField : public Field {
  
#ifdef HAVE_HXT
  struct HXTForest *forest;
  struct HXTForestOptions *forestOptions;
  HXTStatus updateHXT();
#endif
  
  int _nPointsPerCircle;
  int _nPointsPerGap;
  double _hmin, _hmax;
  double _hbulk;
  double _gradientMax;
  int _nRefine;
  char fileName[256];
  
 public:
  ~automaticMeshSizeField();
  automaticMeshSizeField() : forest(NULL), forestOptions(NULL){
    _nPointsPerCircle = 20;
    _nPointsPerGap = 1;
    _hmin = 1.e-8;// update needed
    _hmax = 1.e+8;// update needed    
    _hbulk = 0.1; // update needed
    _gradientMax =1.4;
    _nRefine = 5;
    
    options["nPointsPerCircle"] = new FieldOptionInt(_nPointsPerCircle,
						     "Number of points per circle (adapt to curvature of surfaces)",&update_needed);
    
    options["nPointsPerGap"] = new FieldOptionInt(_nPointsPerGap,
						  "Number of points in thin layers",&update_needed);
    
    options["hBulk"] = new FieldOptionDouble(_hbulk,
					     "Size everywhere no size is prescribed", &update_needed);
    
    options["gradientMax"] = new FieldOptionDouble(_gradientMax,
						   "Maximum gradient of the size field",&update_needed);
    
    options["NRefine"] = new FieldOptionInt(_nRefine,
					    "Initial refinement level for the octree",&update_needed);

    update_needed = true;
    update();
  }

  const char *getName() { return "AutomaticMeshSizeField"; }
  
  std::string getDescription(){
    return "Compute a mesh size field that is quite automatic "
      "Takes into account surface curvatures and closeness of objects";
  }
  
  void update();
  virtual double operator()(double X, double Y, double Z, GEntity *ge = 0);
};


#endif
