// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CROSS_FIELDS_H
#define CROSS_FIELDS_H

#include <string>
#include <float.h>
#include <map>
#include <vector>
class GModel;

int computeCrossField    (GModel *, std::vector<int> &tags);
int computeCrossFieldAndH(GModel *gm,
			  std::map<int, std::vector<double> > &dataH,
			  std::map<int, std::vector<double> > &dataDir,
			  std::map<int, std::vector<double> > &dataDirOrtho);



/********************************************************/
/* Attempt at an API callable step-by-step from the GUI */
/********************************************************/

/* Options used by the various QuadMeshingTools algorithms */
struct QuadMeshingOptions {
  bool cross_field_use_prescribed_if_available = true;
  int cross_field_iter        = 6;
  int cross_field_bc_expansion = 0;
  size_t sizemap_nb_quads = 1000;
  double simplify_size_factor = 0.9;
  int smoothing_explicit_iter = 100;
  std::string model_cut = "cut";
  std::string model_quad_init = "quad_init";
  std::string model_quad = "quad";
};

/* Values filled by the API calls, useful for GUI feedback */
struct QuadMeshingState {
  /* initial model, geometry and triangulation */
  std::string model_initial = "";

  /* cross field */
  int theta_tag = -1;

  /* scaling factor H */
  int H_tag = -1;
  double H_min = DBL_MAX;
  double H_max = -DBL_MAX;

  /* size map */
  int s_tag = -1;
  double s_min = DBL_MAX;
  double s_max = -DBL_MAX;
  size_t s_nb_quad_estimate = 0;

  /* UV-parametrisation */
  int U_tag = -1;
  int V_tag = -1;
  void* data_uv_cuts = NULL;

  /* cut model, triangulation */
  std::string model_cut = "";
  void* data_boundary_projector = NULL;

  /* quad mesh model, initial quantization */
  std::string model_quad_init = "";

  /* quad mesh model, final output */
  std::string model_quad = "";

  /* destructor required to delete the (void*) data */
  ~QuadMeshingState();
};

/* generate a view named 'theta' with 3 values per triangle and a datalist view 'H' with P1 triangles */
int computeCrossField(GModel * gm, const QuadMeshingOptions& opt, QuadMeshingState& state);

// deprecated, integrated into computeCrossField
// /* generate a datalist view named 'H' with P1 triangles */
// int computeH(GModel * gm, const QuadMeshingOptions& opt, QuadMeshingState& state);

/* generate a datalist view named 's' with P1 triangles */
int computeQuadSizeMap(GModel * gm, const QuadMeshingOptions& opt, QuadMeshingState& state);

/* generate two views, named 'U' and 'V', with 3 values per triangle */
int computeUV(GModel * gm, const QuadMeshingOptions& opt, QuadMeshingState& state);

/* generata a new model with cut triangles and classified triangles */
int computeQuadLayout(GModel * gm, const QuadMeshingOptions& opt, QuadMeshingState& state);

/* replace the current mesh by an initial quad mesh */
int generateQuadMesh(GModel * gm, const QuadMeshingOptions& opt, QuadMeshingState& state);

/* simplify the current quad mesh connectivity */
int simplifyQuadMesh(GModel * gm, const QuadMeshingOptions& opt, QuadMeshingState& state);

/* smooth the current quad mesh geometry */
int smoothQuadMesh(GModel * gm, const QuadMeshingOptions& opt, QuadMeshingState& state);

/* generate a view "crosses" with crosses scaled by H */
int showScaledCrosses(GModel* gm, const QuadMeshingOptions& opt, QuadMeshingState& state);

#endif
