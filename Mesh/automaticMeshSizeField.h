#ifndef AUTOMATIC_MESH_SIZE_FIELD_H
#define AUTOMATIC_MESH_SIZE_FIELD_H

#include "Field.h"

class automaticMeshSizeField : public Field {
  int _nPointsPerCircle;
  int _nPointsPerGap;
  double _hmin, _hmax;
  double _hbulk;
  double _gradientMax;

public:
  automaticMeshSizeField()
  {
    _nPointsPerCircle = 15;
    _nPointsPerGap = 5;
    _hmin = 1.e-8; // update needed
    _hmax = 1.e+8; // update needed
    _hbulk = 0.1; // update needed
    _gradientMax = 1.4;

    options["nPointsPerCircle"] = new FieldOptionInt(
      _nPointsPerCircle,
      "Number of points per circle (adapt to curvature of surfaces)");

    options["nPointsPerGap"] =
      new FieldOptionInt(_nPointsPerGap, "Number of points in thin layers");

    options["hBulk"] = new FieldOptionDouble(
      _hbulk, "Size everywhere no size is prescribed", &update_needed);

    options["gradientMax"] =
      new FieldOptionDouble(_gradientMax, "Maximun gradient of the size field");
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
