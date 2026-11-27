// MatGmsh - shell meshes in the PERMAS input format, with thickness groups
//
// The .dat of an industrial pipeline (write_mesh_dat of thicknesses.py): the
// nodes ($COOR), the triangles (TRIA3) and quadrangles (QUAD4) in element
// sets of equal thickness, and the thickness of each set ($GEODAT SHELL).
// The layout is that of the PERMAS files of the pipeline: an element number
// before the nodes of each element, $END STRUCTURE, $END SYSTEM, $EXIT
// COMPONENT and $FIN, the columns of the manual meshes.

#ifndef MAT_PERMAS_H
#define MAT_PERMAS_H

#include <cstddef>
#include <functional>
#include <string>
#include <vector>
#include "gmsh.h"

class GModel;
class MElement;

namespace matgmsh_native {

struct PermasOptions {
  // the thickness of an element is rounded up to a multiple of the step: the
  // set "thick_<t>" holds the elements of thickness in ]t - step, t], and t
  // is its thickness
  double step = .1;
  std::string component = "AUTO_MESH";
  // if not empty, an $ELPROP line per set gives it this material (defined
  // in another file)
  std::string material;
  double scalingFactor = 1.;
  // all the elements, or those of the physical groups if there are some
  bool saveAll = false;
  // the thickness of the elements without one
  double defaultThickness = 1.;
};

struct PermasReport {
  std::size_t nodes = 0, triangles = 0, quadrangles = 0, sets = 0;
  // the elements without thickness (given the default one), and the
  // elements of order 2 or more (written with their corner nodes)
  std::size_t withoutThickness = 0, higherOrder = 0;
  double minThickness = 0., maxThickness = 0.;
};

// thickness(e, t): the thickness t of element e, false if it has none
using ElementThickness = std::function<bool(MElement *, double &)>;

// Writes the triangles and quadrangles of the surfaces of the model
GMSH_API bool writePermas(GModel *model, const std::string &fileName,
                          const ElementThickness &thickness,
                          const PermasOptions &options, PermasReport &report,
                          std::string &error);

// The thickness of an element as the mean of the thickness at its corners,
// given at the nodes of these numbers (MVertex::getNum())
GMSH_API ElementThickness nodalThickness(const std::vector<std::size_t> &nodes,
                                         const std::vector<double> &values);

// The thickness given by a scalar view of node or element data on the model
// (its first step): the first whose name holds "thickness" (in any case),
// or else the first one; null if there is none. name: the name of the view
GMSH_API ElementThickness viewThickness(GModel *model, std::string &name);

// The .dat of File > Export and gmsh::write: the thickness of viewThickness(),
// the step Mesh.PermasThicknessStep, Mesh.SaveAll and Mesh.ScalingFactor
GMSH_API int writePermasFile(GModel *model, const std::string &fileName);

// A PERMAS input file (its first keyword, after the comments, opens a
// component, a structure or a system)
GMSH_API bool isPermasFile(const std::string &fileName);

// Reads the nodes and the TRIA3 and QUAD4 elements: a discrete surface and a
// physical surface named after each element set, and a view of element data
// "PERMAS thickness" if $GEODAT SHELL gives the thickness of the sets
GMSH_API int readPermasFile(GModel *model, const std::string &fileName);

} // namespace matgmsh_native

#endif
