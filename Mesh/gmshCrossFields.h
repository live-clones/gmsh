// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CROSS_FIELDS_H
#define CROSS_FIELDS_H

#include <string>
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

struct QuadMeshingOptions {
  int cross_field_iter        = 6;
  double simplify_size_factor = 0.9;
  int smoothing_explicit_iter = 100;
};

/* generate a view named 'theta' with 3 values per triangle */
int computeCrossField(GModel * gm, const QuadMeshingOptions& opt);

/* generate a datalist view named 'H' with P1 triangles */
int computeH(GModel * gm, const QuadMeshingOptions& opt);

/* generate a datalist view named 's' with P1 triangles */
int computeQuadSizeMap(GModel * gm, const QuadMeshingOptions& opt);

/* generate two views, named 'U' and 'V', with 3 values per triangle */
int computeUV(GModel * gm, const QuadMeshingOptions& opt);

/* cut the current mesh triangles and classify the triangles */
int computeQuadLayout(GModel * gm, const QuadMeshingOptions& opt);

/* replace the current mesh by an initial quad mesh */
int generateQuadMesh(GModel * gm, const QuadMeshingOptions& opt);

/* simplify the current quad mesh connectivity */
int simplifyQuadMesh(GModel * gm, const QuadMeshingOptions& opt);

/* smooth the current quad mesh geometry */
int smoothQuadMesh(GModel * gm, const QuadMeshingOptions& opt);

/* generate a view "crosses" with crosses scaled by H */
int showScaledCrosses(GModel* gm, const QuadMeshingOptions& opt);

#endif
