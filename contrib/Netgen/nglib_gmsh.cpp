// Interface to the Netgen meshing kernel for Gmsh. This file replaces the
// original nglib/nglib.cpp file from the Netgen distribution.

#include <string>
#include "GmshMessage.h"
#include <meshing.hpp>
#include "geom2d/csg2d.hpp" // for intersect() below

namespace netgen {
  extern void (*ng_print_dest_callback)(const char *);

  // only used by 2D boundary layers (in basegeom.cpp), which Gmsh never
  // calls: this avoids compiling the 2D CSG and spline geometry
  IntersectionType intersect(const Point<2> P1, const Point<2> P2,
                             const Point<2> Q1, const Point<2> Q2,
                             double &alpha, double &beta)
  { throw NgException("2D boundary layers are not available in Gmsh"); }
} // namespace netgen

namespace nglib {
#include "nglib_gmsh.h"
}

using namespace netgen;

namespace nglib {

  static void printDest(const char *s)
  {
    std::string str(s);
    while(!str.empty() &&
          (str.back() == '\n' || str.back() == '\r' || str.back() == ' '))
      str.pop_back();
    std::size_t first = str.find_first_not_of(' ');
    if(first == std::string::npos) return;
    str = str.substr(first);
    if(str.size() == 1) return; // progress dots
    if(!str.compare(0, 6, "ERROR:"))
      Msg::Error("Netgen: %s", str.substr(7).c_str());
    else if(!str.compare(0, 8, "WARNING:"))
      Msg::Warning("Netgen: %s", str.substr(9).c_str());
    else
      Msg::Debug("Netgen: %s", str.c_str());
  }

  void Ng_Init()
  {
    ng_print_dest_callback = printDest;
    printmessage_importance = (Msg::GetVerbosity() > 5) ? 3 : 0;
  }

  void Ng_Exit() {}

  Ng_Mesh *Ng_NewMesh()
  {
    Mesh *mesh = new Mesh;
    mesh->AddFaceDescriptor(FaceDescriptor(1, 1, 0, 1));
    return (Ng_Mesh *)(void *)mesh;
  }

  void Ng_DeleteMesh(Ng_Mesh *mesh)
  {
    if(!mesh) return;
    ((Mesh *)mesh)->DeleteMesh();
    delete(Mesh *)mesh;
  }

  void Ng_AddPoint(Ng_Mesh *mesh, double *x)
  { ((Mesh *)mesh)->AddPoint(Point<3>(x[0], x[1], x[2])); }

  void Ng_AddSurfaceElement(Ng_Mesh *mesh, int *pi)
  {
    Element2d el(3);
    el.SetIndex(FaceRegionIndex::FromNr1(1));
    for(int i = 0; i < 3; i++) el[i] = PointIndex::FromNr1(pi[i]);
    ((Mesh *)mesh)->AddSurfaceElement(el);
  }

  void Ng_AddVolumeElement(Ng_Mesh *mesh, int *pi)
  {
    Element el(4);
    el.SetIndex(VolumeRegionIndex::FromNr1(1));
    for(int i = 0; i < 4; i++) el[i] = PointIndex::FromNr1(pi[i]);
    ((Mesh *)mesh)->AddVolumeElement(el);
  }

  int Ng_GetNP(Ng_Mesh *mesh) { return ((Mesh *)mesh)->GetNP(); }

  int Ng_GetNE(Ng_Mesh *mesh) { return ((Mesh *)mesh)->GetNE(); }

  void Ng_GetPoint(Ng_Mesh *mesh, int num, double *x)
  {
    const Point<3> &p = ((Mesh *)mesh)->Point(PointIndex::FromNr1(num));
    x[0] = p(0);
    x[1] = p(1);
    x[2] = p(2);
  }

  void Ng_GetVolumeElement(Ng_Mesh *mesh, int num, int *pi)
  {
    auto el = ((Mesh *)mesh)->VolumeElement(ElementIndex::FromNr1(num));
    for(int i = 0; i < 4; i++) pi[i] = el.PNum(i + 1).Nr1();
  }

  static Ng_Result run(Ng_Mesh *mesh, double maxh, bool generate)
  {
    Mesh *m = (Mesh *)mesh;
    MeshingParameters mp;
    mp.uselocalh = true;
    mp.maxh = maxh;
    mp.parallel_meshing = false;
    try {
      m->CalcLocalH(mp.grading);
      if(generate) {
        if(MeshVolume(mp, *m) != MESHING3_OK) {
          Msg::Error("Netgen could not mesh the volume");
          return NG_VOLUME_FAILURE;
        }
      }
      else {
        RemoveIllegalElements(*m);
        OptimizeVolume(mp, *m);
      }
    } catch(std::exception &e) {
      Msg::Error("Netgen: %s", e.what());
      return NG_VOLUME_FAILURE;
    }
    return NG_OK;
  }

  Ng_Result Ng_GenerateVolumeMesh(Ng_Mesh *mesh, double maxh)
  {
    return run(mesh, maxh, true);
  }

  Ng_Result Ng_OptimizeVolumeMesh(Ng_Mesh *mesh, double maxh)
  {
    return run(mesh, maxh, false);
  }

} // namespace nglib
