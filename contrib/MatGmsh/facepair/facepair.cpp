// Face-pairing evidence of a thin-walled solid, from OpenCASCADE alone.
//
//   facepair <part.stp|.igs> <out prefix> <spacing h> <reach R> [all]
//
// Every face is sampled on a grid of its parameter domain, about h apart on
// the surface (nodes outside the trimming are dropped). From every node, a
// ray goes into the material along the inward normal, up to R: the first
// face it meets is the face opposite to the node (normal-projection pairing),
// and the middle of the ray lies on the mid-surface of that pair. Writes
//   <prefix>.json   faces (type, area, loops, curvature), edges between faces
//                   (dihedral, convexity), node and triangle counts
//   <prefix>.nodes  float32 rows: face, x, y, z, nx, ny, nz, area, hit face
//                   (-1: none within R), hit distance, cosine of the normals
//   <prefix>.tris   int32 rows: three node indices (cells of the sampling grid
//                   whose corners are all inside the face)
//   <prefix>.hits   with "all": float32 rows node, face, distance, cosine of
//                   the normals, for every face the ray crosses within R
// Faces and edges are numbered as in TopExp::MapShapes (from 1). These are
// local identifiers, not Gmsh tags. The geometric signatures in the JSON
// allow a consumer to establish and verify that correspondence.

#include <BRepAdaptor_Curve.hxx>
#include <BRepBndLib.hxx>
#include <BRepBuilderAPI_MakeSolid.hxx>
#include <BRepBuilderAPI_Sewing.hxx>
#include <BRepLib.hxx>
#include <BRep_Builder.hxx>
#include <ShapeFix_Solid.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <BRepClass3d_SolidClassifier.hxx>
#include <BRepGProp.hxx>
#include <BRepLProp_SLProps.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <BRepTools.hxx>
#include <BRepTopAdaptor_FClass2d.hxx>
#include <BRep_Tool.hxx>
#include <GProp_GProps.hxx>
#include <GeomAPI_ProjectPointOnSurf.hxx>
#include <Poly_Triangulation.hxx>
#include <IGESControl_Reader.hxx>
#include <STEPControl_Reader.hxx>
#include <Standard_Failure.hxx>
#include <TopExp.hxx>
#include <TopExp_Explorer.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Face.hxx>

#include <algorithm>
#include <array>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace {

using V = std::array<double, 3>;
V sub(const V &a, const V &b) { return {a[0] - b[0], a[1] - b[1], a[2] - b[2]}; }
V add(const V &a, const V &b) { return {a[0] + b[0], a[1] + b[1], a[2] + b[2]}; }
V mul(double s, const V &a) { return {s * a[0], s * a[1], s * a[2]}; }
double dot(const V &a, const V &b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }
V cross(const V &a, const V &b) { return {a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0]}; }
double norm(const V &a) { return std::sqrt(dot(a, a)); }
V unit(const V &a)
{
  const double n = norm(a);
  return n > 1e-300 ? mul(1.0 / n, a) : V{0, 0, 0};
}
V of(const gp_Pnt &p) { return {p.X(), p.Y(), p.Z()}; }
V of(const gp_Vec &p) { return {p.X(), p.Y(), p.Z()}; }

const char *typeName(GeomAbs_SurfaceType t)
{
  switch(t) {
  case GeomAbs_Plane: return "Plane";
  case GeomAbs_Cylinder: return "Cylinder";
  case GeomAbs_Cone: return "Cone";
  case GeomAbs_Sphere: return "Sphere";
  case GeomAbs_Torus: return "Torus";
  case GeomAbs_BezierSurface: return "Bezier";
  case GeomAbs_BSplineSurface: return "BSpline";
  case GeomAbs_SurfaceOfRevolution: return "Revolution";
  case GeomAbs_SurfaceOfExtrusion: return "Extrusion";
  case GeomAbs_OffsetSurface: return "Offset";
  default: return "Other";
  }
}

// Triangles of the part in a uniform grid; first hit of a segment.
struct Caster {
  std::vector<std::array<V, 3>> tri;
  std::vector<V> normal;
  std::vector<int> face;
  double h = 1;
  std::unordered_map<std::int64_t, std::vector<int>> cells;
  std::vector<unsigned> stamp;
  unsigned visit = 0;
  static std::int64_t key(long i, long j, long k)
  {
    return (static_cast<std::int64_t>(i) & 0x1fffff) | ((static_cast<std::int64_t>(j) & 0x1fffff) << 21) |
           ((static_cast<std::int64_t>(k) & 0x1fffff) << 42);
  }
  long cell(double x) const { return static_cast<long>(std::floor(x / h)); }
  void build(double size)
  {
    h = size;
    stamp.assign(tri.size(), 0);
    for(std::size_t t = 0; t < tri.size(); ++t) {
      V lo = tri[t][0], hi = tri[t][0];
      for(const V &p : tri[t])
        for(int c = 0; c < 3; ++c) {
          lo[c] = std::min(lo[c], p[c]);
          hi[c] = std::max(hi[c], p[c]);
        }
      for(long i = cell(lo[0]); i <= cell(hi[0]); ++i)
        for(long j = cell(lo[1]); j <= cell(hi[1]); ++j)
          for(long k = cell(lo[2]); k <= cell(hi[2]); ++k) cells[key(i, j, k)].push_back(static_cast<int>(t));
    }
  }
  // Nearest hit along o + s d, 0 < s <= length, ignoring hits of `self`
  // closer than skip.
  bool cast(const V &o, const V &d, double length, int self, double skip, double &s, int &which)
  {
    ++visit;
    const V e = add(o, mul(length, d));
    s = length;
    which = -1;
    for(long i = cell(std::min(o[0], e[0])); i <= cell(std::max(o[0], e[0])); ++i)
      for(long j = cell(std::min(o[1], e[1])); j <= cell(std::max(o[1], e[1])); ++j)
        for(long k = cell(std::min(o[2], e[2])); k <= cell(std::max(o[2], e[2])); ++k) {
          const auto it = cells.find(key(i, j, k));
          if(it == cells.end()) continue;
          for(int t : it->second) {
            if(stamp[t] == visit) continue;
            stamp[t] = visit;
            const V &v0 = tri[t][0];
            const V e1 = sub(tri[t][1], v0), e2 = sub(tri[t][2], v0);
            const V p = cross(d, e2);
            const double det = dot(e1, p);
            if(std::abs(det) < 1e-14) continue;
            const double inv = 1.0 / det;
            const V tv = sub(o, v0);
            const double u = dot(tv, p) * inv;
            if(u < -1e-9 || u > 1 + 1e-9) continue;
            const V q = cross(tv, e1);
            const double v = dot(d, q) * inv;
            if(v < -1e-9 || u + v > 1 + 1e-9) continue;
            const double r = dot(e2, q) * inv;
            if(r <= 1e-9 || r > s) continue;
            if(face[t] == self && r < skip) continue;
            s = r;
            which = t;
          }
        }
    return which >= 0;
  }
  // Every face crossed along o + s d, 0 < s <= length: the nearest hit of
  // each (ignoring hits of `self` closer than skip), as (face, s, triangle).
  void castAll(const V &o, const V &d, double length, int self, double skip,
               std::unordered_map<int, std::pair<double, int>> &hits)
  {
    hits.clear();
    ++visit;
    const V e = add(o, mul(length, d));
    for(long i = cell(std::min(o[0], e[0])); i <= cell(std::max(o[0], e[0])); ++i)
      for(long j = cell(std::min(o[1], e[1])); j <= cell(std::max(o[1], e[1])); ++j)
        for(long k = cell(std::min(o[2], e[2])); k <= cell(std::max(o[2], e[2])); ++k) {
          const auto it = cells.find(key(i, j, k));
          if(it == cells.end()) continue;
          for(int t : it->second) {
            if(stamp[t] == visit) continue;
            stamp[t] = visit;
            const V &v0 = tri[t][0];
            const V e1 = sub(tri[t][1], v0), e2 = sub(tri[t][2], v0);
            const V p = cross(d, e2);
            const double det = dot(e1, p);
            if(std::abs(det) < 1e-14) continue;
            const double inv = 1.0 / det;
            const V tv = sub(o, v0);
            const double u = dot(tv, p) * inv;
            if(u < -1e-9 || u > 1 + 1e-9) continue;
            const V q = cross(tv, e1);
            const double v = dot(d, q) * inv;
            if(v < -1e-9 || u + v > 1 + 1e-9) continue;
            const double r = dot(e2, q) * inv;
            if(r <= 1e-9 || r > length) continue;
            if(face[t] == self && r < skip) continue;
            auto found = hits.find(face[t]);
            if(found == hits.end() || r < found->second.first) hits[face[t]] = {r, t};
          }
        }
  }
};

std::string escape(const std::string &s)
{
  std::string out;
  for(char c : s) out += (c == '"' || c == '\\') ? std::string("\\") + c : std::string(1, c);
  return out;
}

} // namespace

int main(int argc, char **argv)
{
  if(argc < 5) {
    std::fprintf(stderr, "usage: facepair <part.stp> <out prefix> <spacing> <reach>\n");
    return 1;
  }
  const std::string input = argv[1], prefix = argv[2];
  const double h = std::atof(argv[3]), reach = std::atof(argv[4]);
  // With "all": <prefix>.hits, every face each ray crosses (not only the
  // first), for criteria that project a face onto another regardless of
  // the faces between them (MidSurfer's overlap).
  const bool allHits = argc > 5 && std::string(argv[5]) == "all";
  std::vector<float> hitRows;
  std::unordered_map<int, std::pair<double, int>> crossed;

  // STEP or IGES, by extension.
  std::string lower = input;
  for(char &c : lower) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
  const bool iges = lower.size() > 4 && (lower.substr(lower.size() - 4) == ".igs" ||
                                         lower.substr(lower.size() - 5) == ".iges");
  TopoDS_Shape shape;
  if(iges) {
    IGESControl_Reader reader;
    if(reader.ReadFile(input.c_str()) != IFSelect_RetDone) {
      std::fprintf(stderr, "cannot read %s\n", input.c_str());
      return 1;
    }
    reader.TransferRoots();
    shape = reader.OneShape();
    // IGES gives loose faces: sew them into shells, and the closed shells
    // into oriented solids, so that faces share edges and point outwards.
    Bnd_Box box;
    BRepBndLib::Add(shape, box);
    const double diagonal = std::sqrt(box.SquareExtent());
    BRepBuilderAPI_Sewing sewing(1e-5 * diagonal);
    sewing.Add(shape);
    sewing.Perform();
    TopoDS_Shape sewn = sewing.SewedShape();
    BRep_Builder builder;
    TopoDS_Compound solids;
    builder.MakeCompound(solids);
    int closed = 0;
    for(TopExp_Explorer e(sewn, TopAbs_SHELL); e.More(); e.Next()) {
      const TopoDS_Shell &shell = TopoDS::Shell(e.Current());
      if(!BRep_Tool::IsClosed(shell)) {
        builder.Add(solids, shell);
        continue;
      }
      ShapeFix_Solid fix;
      fix.Init(BRepBuilderAPI_MakeSolid(shell).Solid());
      fix.Perform();
      TopoDS_Solid solid = TopoDS::Solid(fix.Solid());
      BRepLib::OrientClosedSolid(solid);
      builder.Add(solids, solid);
      ++closed;
    }
    shape = solids;
    std::fprintf(stderr, "IGES sewn: %d closed shells\n", closed);
  }
  else {
    STEPControl_Reader reader;
    if(reader.ReadFile(input.c_str()) != IFSelect_RetDone) {
      std::fprintf(stderr, "cannot read %s\n", input.c_str());
      return 1;
    }
    reader.TransferRoots();
    shape = reader.OneShape();
  }
  TopTools_IndexedMapOfShape faces, edges;
  TopExp::MapShapes(shape, TopAbs_FACE, faces);
  TopExp::MapShapes(shape, TopAbs_EDGE, edges);
  TopTools_IndexedDataMapOfShapeListOfShape edgeFaces;
  TopExp::MapShapesAndAncestors(shape, TopAbs_EDGE, TopAbs_FACE, edgeFaces);

  // The part's surface mesh, for the rays (fine: hits within h / 50).
  BRepMesh_IncrementalMesh mesher(shape, h / 50.0, false, 0.1, false);
  Caster caster;
  for(int f = 1; f <= faces.Extent(); ++f) {
    const TopoDS_Face &face = TopoDS::Face(faces(f));
    TopLoc_Location loc;
    const Handle(Poly_Triangulation) poly = BRep_Tool::Triangulation(face, loc);
    if(poly.IsNull()) continue;
    const bool reversed = face.Orientation() == TopAbs_REVERSED;
    for(int t = 1; t <= poly->NbTriangles(); ++t) {
      int a, b, c;
      poly->Triangle(t).Get(a, b, c);
      if(reversed) std::swap(b, c);
      std::array<V, 3> p = {of(poly->Node(a).Transformed(loc.Transformation())),
                            of(poly->Node(b).Transformed(loc.Transformation())),
                            of(poly->Node(c).Transformed(loc.Transformation()))};
      caster.tri.push_back(p);
      caster.normal.push_back(unit(cross(sub(p[1], p[0]), sub(p[2], p[0]))));
      caster.face.push_back(f);
    }
  }
  caster.build(std::max(h, reach / 4.0));

  // Sampling grids, rays, triangles.
  std::vector<float> nodes;
  std::vector<std::int32_t> tris;
  std::string facesJson;
  std::size_t nodeCount = 0;
  for(int f = 1; f <= faces.Extent(); ++f) {
    const TopoDS_Face &face = TopoDS::Face(faces(f));
    const bool reversed = face.Orientation() == TopAbs_REVERSED;
    BRepAdaptor_Surface surface(face);
    double u0, u1, v0, v1;
    BRepTools::UVBounds(face, u0, u1, v0, v1);
    // Grid steps from the largest metric over a coarse grid.
    double su = 0, sv = 0;
    for(int i = 0; i <= 6; ++i)
      for(int j = 0; j <= 6; ++j) {
        gp_Pnt p;
        gp_Vec du, dv;
        surface.D1(u0 + (u1 - u0) * i / 6.0, v0 + (v1 - v0) * j / 6.0, p, du, dv);
        su = std::max(su, du.Magnitude());
        sv = std::max(sv, dv.Magnitude());
      }
    int nu = std::clamp(static_cast<int>(std::ceil((u1 - u0) * su / h)), 1, 4000);
    int nv = std::clamp(static_cast<int>(std::ceil((v1 - v0) * sv / h)), 1, 4000);
    while(static_cast<double>(nu) * nv > 4e6) {
      nu = std::max(1, nu / 2);
      nv = std::max(1, nv / 2);
    }
    BRepTopAdaptor_FClass2d inside(face, 1e-7);
    std::vector<long> index((nu + 1) * (nv + 1), -1);
    std::vector<V> point((nu + 1) * (nv + 1)), normal((nu + 1) * (nv + 1));
    std::vector<double> metric((nu + 1) * (nv + 1), 0.0);
    std::vector<bool> interior((nu + 1) * (nv + 1), false);
    long positive = 0, negative = 0, sampled = 0;
    double meanCurvature = 0;
    const double du = (u1 - u0) / nu, dv = (v1 - v0) / nv;
    for(int i = 0; i <= nu; ++i)
      for(int j = 0; j <= nv; ++j) {
        const double u = u0 + i * du, v = v0 + j * dv;
        const TopAbs_State state = inside.Perform(gp_Pnt2d(u, v));
        if(state != TopAbs_IN && state != TopAbs_ON) continue;
        const int k = i * (nv + 1) + j;
        try {
          BRepLProp_SLProps props(surface, u, v, 2, 1e-9);
          if(!props.IsNormalDefined()) continue;
          V n = of(gp_Vec(props.Normal().XYZ()));
          if(reversed) n = mul(-1.0, n);
          point[k] = of(props.Value());
          normal[k] = n;
          metric[k] = props.D1U().Crossed(props.D1V()).Magnitude();
          index[k] = static_cast<long>(nodeCount++);
          interior[k] = state == TopAbs_IN;
          // Curvature is undefined at singular points (poles, apexes).
          try {
            if(props.IsCurvatureDefined()) {
              const double K = props.GaussianCurvature();
              if(K > 1e-6) ++positive;
              else if(K < -1e-6) ++negative;
              meanCurvature += std::abs(props.MeanCurvature());
              ++sampled;
            }
          }
          catch(const Standard_Failure &) {
          }
        }
        catch(const Standard_Failure &) {
          continue;
        }
      }
    // Node areas from the full cells around them; triangles of those cells.
    std::vector<double> area((nu + 1) * (nv + 1), 0.0);
    for(int i = 0; i < nu; ++i)
      for(int j = 0; j < nv; ++j) {
        const int a = i * (nv + 1) + j, b = (i + 1) * (nv + 1) + j, c = (i + 1) * (nv + 1) + j + 1,
                  d = i * (nv + 1) + j + 1;
        if(index[a] < 0 || index[b] < 0 || index[c] < 0 || index[d] < 0) continue;
        const double cellArea = 0.25 * (metric[a] + metric[b] + metric[c] + metric[d]) * du * dv;
        for(int k : {a, b, c, d}) area[k] += 0.25 * cellArea;
        if(reversed) {
          tris.insert(tris.end(), {static_cast<std::int32_t>(index[a]), static_cast<std::int32_t>(index[c]),
                                   static_cast<std::int32_t>(index[b])});
          tris.insert(tris.end(), {static_cast<std::int32_t>(index[a]), static_cast<std::int32_t>(index[d]),
                                   static_cast<std::int32_t>(index[c])});
        }
        else {
          tris.insert(tris.end(), {static_cast<std::int32_t>(index[a]), static_cast<std::int32_t>(index[b]),
                                   static_cast<std::int32_t>(index[c])});
          tris.insert(tris.end(), {static_cast<std::int32_t>(index[a]), static_cast<std::int32_t>(index[c]),
                                   static_cast<std::int32_t>(index[d])});
        }
      }
    for(int k = 0; k < (nu + 1) * (nv + 1); ++k) {
      if(index[k] < 0) continue;
      const V &p = point[k], &n = normal[k];
      double s;
      int which;
      const V inward = mul(-1.0, n);
      const bool hit = caster.cast(add(p, mul(1e-6 * h, inward)), inward, reach, f, 0.25 * h, s, which);
      if(allHits) {
        caster.castAll(add(p, mul(1e-6 * h, inward)), inward, reach, f, 0.25 * h, crossed);
        for(const auto &[hf, st] : crossed)
          hitRows.insert(hitRows.end(), {static_cast<float>(index[k]), static_cast<float>(hf),
                                         static_cast<float>(st.first),
                                         static_cast<float>(dot(n, caster.normal[st.second]))});
      }
      const int hitFace = hit ? caster.face[which] : -1;
      const double c = hit ? dot(n, caster.normal[which]) : 0.0;
      nodes.insert(nodes.end(), {static_cast<float>(f), static_cast<float>(p[0]), static_cast<float>(p[1]),
                                 static_cast<float>(p[2]), static_cast<float>(n[0]), static_cast<float>(n[1]),
                                 static_cast<float>(n[2]), static_cast<float>(area[k]),
                                 static_cast<float>(hitFace), static_cast<float>(hit ? s : 0.0),
                                 static_cast<float>(c)});
    }
    GProp_GProps mass;
    BRepGProp::SurfaceProperties(face, mass);
    int wires = 0, faceEdges = 0;
    for(TopExp_Explorer w(face, TopAbs_WIRE); w.More(); w.Next()) ++wires;
    for(TopExp_Explorer e(face, TopAbs_EDGE); e.More(); e.Next()) ++faceEdges;
    char buffer[512];
    std::snprintf(buffer, sizeof(buffer),
                  "%s{\"id\":%d,\"type\":\"%s\",\"area\":%.9g,\"loops\":%d,\"edges\":%d,"
                  "\"k_pos\":%.6g,\"k_neg\":%.6g,\"mean_curvature\":%.6g,\"samples\":%ld",
                  f > 1 ? ",\n  " : "  ", f, typeName(surface.GetType()), mass.Mass(), wires, faceEdges,
                  sampled ? double(positive) / sampled : 0.0, sampled ? double(negative) / sampled : 0.0,
                  sampled ? meanCurvature / sampled : 0.0, sampled);
    facesJson += buffer;
    // Double precision signatures use actual points of the trimmed face.
    // Do not use the float32 ray rows to match small or translated CAD faces.
    std::vector<std::size_t> samples;
    for(int axis = 0; axis < 3; ++axis)
      for(int sign : {-1, 1}) {
        std::size_t best = point.size();
        for(std::size_t k = 0; k < point.size(); ++k) {
          if(index[k] < 0 || !interior[k]) continue;
          if(best == point.size() || sign * point[k][axis] > sign * point[best][axis]) best = k;
        }
        if(best != point.size() && std::find(samples.begin(), samples.end(), best) == samples.end())
          samples.push_back(best);
      }
    std::vector<V> signaturePoints;
    for(const auto k : samples) signaturePoints.push_back(point[k]);
    if(signaturePoints.empty()) {
      // Small faces can have a one-cell grid whose nodes are all ON the
      // boundary. Seek strictly interior points independently of that grid.
      for(int i = 1; i < 8 && signaturePoints.size() < 6; ++i)
        for(int j = 1; j < 8 && signaturePoints.size() < 6; ++j) {
          const double u = u0 + (u1 - u0) * i / 8.0, v = v0 + (v1 - v0) * j / 8.0;
          if(inside.Perform(gp_Pnt2d(u, v)) == TopAbs_IN)
            signaturePoints.push_back(of(surface.Value(u, v)));
        }
    }
    std::ostringstream signature;
    const gp_Pnt centre = mass.CentreOfMass();
    signature << std::setprecision(17) << ",\"signature\":{\"area\":" << mass.Mass()
              << ",\"centroid\":[" << centre.X() << ',' << centre.Y() << ',' << centre.Z()
              << "],\"interior_points\":[";
    for(std::size_t j = 0; j < signaturePoints.size(); ++j) {
      const auto &p = signaturePoints[j];
      if(j) signature << ',';
      signature << '[' << p[0] << ',' << p[1] << ',' << p[2] << ']';
    }
    signature << "]}}";
    facesJson += signature.str();
  }

  // Edges between two faces: dihedral angle (cosine of the outward normals)
  // and convexity (the bisector of the outward normals points out of the
  // solid at a convex edge, into it at a concave one).
  BRepClass3d_SolidClassifier classifier(shape);
  std::string edgesJson;
  int edgeCount = 0;
  for(int e = 1; e <= edgeFaces.Extent(); ++e) {
    const TopTools_ListOfShape &around = edgeFaces(e);
    std::vector<int> ids;
    for(const TopoDS_Shape &s : around) {
      const int id = faces.FindIndex(s);
      if(id > 0 && std::find(ids.begin(), ids.end(), id) == ids.end()) ids.push_back(id);
    }
    if(ids.size() != 2) continue;
    const TopoDS_Edge &edge = TopoDS::Edge(edgeFaces.FindKey(e));
    if(BRep_Tool::Degenerated(edge)) continue;
    BRepAdaptor_Curve curve(edge);
    const double t = 0.5 * (curve.FirstParameter() + curve.LastParameter());
    const gp_Pnt m = curve.Value(t);
    V n[2];
    bool ok = true;
    for(int k = 0; k < 2; ++k) {
      const TopoDS_Face &face = TopoDS::Face(faces(ids[k]));
      double u, v;
      try {
        GeomAPI_ProjectPointOnSurf projection(m, BRep_Tool::Surface(face));
        if(projection.NbPoints() == 0) {
          ok = false;
          break;
        }
        projection.LowerDistanceParameters(u, v);
      }
      catch(const Standard_Failure &) {
        ok = false;
        break;
      }
      BRepAdaptor_Surface surface(face);
      try {
        BRepLProp_SLProps props(surface, u, v, 1, 1e-9);
        if(!props.IsNormalDefined()) {
          ok = false;
          break;
        }
        n[k] = of(gp_Vec(props.Normal().XYZ()));
      }
      catch(const Standard_Failure &) {
        ok = false;
        break;
      }
      if(face.Orientation() == TopAbs_REVERSED) n[k] = mul(-1.0, n[k]);
    }
    if(!ok) continue;
    const double c = dot(n[0], n[1]);
    int convex = 0;  // 1 convex, -1 concave, 0 smooth
    if(c < 0.995) {
      const V bisector = unit(add(n[0], n[1]));
      if(norm(bisector) > 0.5) {
        classifier.Perform(gp_Pnt(m.X() + 0.05 * h * bisector[0], m.Y() + 0.05 * h * bisector[1],
                                  m.Z() + 0.05 * h * bisector[2]), 1e-7);
        convex = classifier.State() == TopAbs_IN ? -1 : 1;
      }
    }
    GProp_GProps mass;
    BRepGProp::LinearProperties(edge, mass);
    char buffer[256];
    std::snprintf(buffer, sizeof(buffer), "%s[%d,%d,%.9g,%.6g,%d]", edgeCount ? ",\n  " : "  ", ids[0],
                  ids[1], mass.Mass(), c, convex);
    edgesJson += buffer;
    ++edgeCount;
  }

  Bnd_Box box;
  for(const auto &t : caster.tri)
    for(const V &p : t) box.Add(gp_Pnt(p[0], p[1], p[2]));
  double x0, y0, z0, x1, y1, z1;
  box.Get(x0, y0, z0, x1, y1, z1);
  std::ofstream(prefix + ".nodes", std::ios::binary)
      .write(reinterpret_cast<const char *>(nodes.data()), static_cast<std::streamsize>(nodes.size() * sizeof(float)));
  if(allHits)
    std::ofstream(prefix + ".hits", std::ios::binary)
        .write(reinterpret_cast<const char *>(hitRows.data()),
               static_cast<std::streamsize>(hitRows.size() * sizeof(float)));
  std::ofstream(prefix + ".tris", std::ios::binary)
      .write(reinterpret_cast<const char *>(tris.data()), static_cast<std::streamsize>(tris.size() * sizeof(std::int32_t)));
  std::ofstream json(prefix + ".json");
  json << "{\"input\":\"" << escape(input) << "\",\"spacing\":" << h << ",\"reach\":" << reach
       << ",\"diagonal\":" << std::sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0) + (z1 - z0) * (z1 - z0))
       << ",\"node_columns\":11,\"nodes\":" << nodeCount << ",\"triangles\":" << tris.size() / 3
       << ",\n\"faces\":[\n" << facesJson << "],\n\"edges\":[\n" << edgesJson << "]}\n";
  std::printf("faces %d edges %d nodes %zu triangles %zu\n", faces.Extent(), edgeCount, nodeCount, tris.size() / 3);
  return 0;
}
