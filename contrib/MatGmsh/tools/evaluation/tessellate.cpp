// Display tessellation of a BREP shape with OpenCASCADE's BRepMesh (no Gmsh
// meshing): for every face, its surface type and its triangles.
//
// usage: tessellate <in.brep> <linear deflection> <out.txt>
// out.txt: one block per face, "face <type> <triangle count>" then one line of
// nine coordinates per triangle, oriented with the face.
#include <BRepAdaptor_Surface.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <BRepTools.hxx>
#include <BRep_Builder.hxx>
#include <BRep_Tool.hxx>
#include <Poly_Triangulation.hxx>
#include <TopExp_Explorer.hxx>
#include <TopLoc_Location.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Face.hxx>

#include <cstdlib>
#include <fstream>
#include <iostream>

static const char *typeName(GeomAbs_SurfaceType type)
{
  switch(type) {
  case GeomAbs_Plane: return "Plane";
  case GeomAbs_Cylinder: return "Cylinder";
  case GeomAbs_Cone: return "Cone";
  case GeomAbs_Sphere: return "Sphere";
  case GeomAbs_Torus: return "Torus";
  case GeomAbs_BezierSurface: return "BezierSurface";
  case GeomAbs_BSplineSurface: return "BSpline surface";
  case GeomAbs_SurfaceOfRevolution: return "SurfaceOfRevolution";
  case GeomAbs_SurfaceOfExtrusion: return "SurfaceOfExtrusion";
  case GeomAbs_OffsetSurface: return "Unknown";
  default: return "Other";
  }
}

int main(int argc, char **argv)
{
  if(argc != 4) {
    std::cerr << "usage: tessellate <in.brep> <linear deflection> <out.txt>\n";
    return 2;
  }
  TopoDS_Shape shape;
  BRep_Builder builder;
  if(!BRepTools::Read(shape, argv[1], builder)) {
    std::cerr << "cannot read " << argv[1] << '\n';
    return 1;
  }
  BRepMesh_IncrementalMesh mesh(shape, std::atof(argv[2]), false, 0.3, true);
  std::ofstream out(argv[3]);
  out.precision(9);
  for(TopExp_Explorer it(shape, TopAbs_FACE); it.More(); it.Next()) {
    const TopoDS_Face face = TopoDS::Face(it.Current());
    TopLoc_Location location;
    const Handle(Poly_Triangulation) tri = BRep_Tool::Triangulation(face, location);
    if(tri.IsNull()) continue;
    const bool reversed = face.Orientation() == TopAbs_REVERSED;
    out << "face " << typeName(BRepAdaptor_Surface(face).GetType()) << '\t'
        << tri->NbTriangles() << '\n';
    for(int t = 1; t <= tri->NbTriangles(); ++t) {
      int n[3];
      tri->Triangle(t).Get(n[0], n[1], n[2]);
      if(reversed) std::swap(n[1], n[2]);
      for(int k = 0; k < 3; ++k) {
        const gp_Pnt p = tri->Node(n[k]).Transformed(location.Transformation());
        out << p.X() << ' ' << p.Y() << ' ' << p.Z() << (k == 2 ? '\n' : ' ');
      }
    }
  }
  return 0;
}
