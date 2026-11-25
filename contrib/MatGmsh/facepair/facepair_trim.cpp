// Mid-surface of a thin part from its face plan, extended and trimmed into
// one connected BRep, as a CAD system builds mid-surfaces from face pairs.
//
//   facepair_trim <part.stp> <plan> <out.brep> [reach]
//
// Each line of the plan is "face offset" (see facepair_brep.cpp). Every
// face of the plan is first enlarged on its own surface by `reach` gaps
// (default 4; the gap of a face is twice its offset) and then offset: an
// untrimmed mid face that runs past the junctions and past the material.
// One general fuse splits all these faces by each other and by the faces of
// the part. A piece is kept when it lies inside the material and covers some
// of the original (unenlarged) mid face: the enlargement then stops at the
// first other mid face it meets (a junction or a corner, where the pieces
// share their edge) or at the skin of the part (a free edge, prolonged up to
// the material), and the flaps past a junction are dropped. The kept pieces
// are written as one compound whose junction edges are shared.

#include <BOPAlgo_Builder.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <BRepAlgoAPI_Splitter.hxx>
#include <GeomAPI_ProjectPointOnSurf.hxx>
#include <GeomLProp_SLProps.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepClass3d_SolidClassifier.hxx>
#include <BRepClass_FaceClassifier.hxx>
#include <gp_Pnt2d.hxx>
#include <BRepExtrema_DistShapeShape.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <BRepOffsetAPI_MakeOffsetShape.hxx>
#include <BRepTools.hxx>
#include <BRep_Builder.hxx>
#include <BRep_Tool.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepGProp.hxx>
#include <GProp_GProps.hxx>
#include <Bnd_Box.hxx>
#include <BRepBndLib.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <GeomLib.hxx>
#include <Geom_BSplineSurface.hxx>
#include <Geom_BoundedSurface.hxx>
#include <Geom_OffsetSurface.hxx>
#include <BRepBuilderAPI_NurbsConvert.hxx>
#include <Geom_RectangularTrimmedSurface.hxx>
#include <Geom_Surface.hxx>
#include <Poly_Triangulation.hxx>
#include <STEPControl_Reader.hxx>
#include <Standard_Failure.hxx>
#include <TopExp.hxx>
#include <TopExp_Explorer.hxx>
#include <TopLoc_Location.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Pnt.hxx>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <memory>
#include <string>
#include <vector>

namespace {

// The face on its own surface, enlarged by `length` on every side (a plane
// or a cylinder through its parameters, a B-spline by extension), with the
// orientation of the face; the original face when the surface cannot be
// enlarged.
TopoDS_Face enlarged(const TopoDS_Face &face, double length)
{
  Handle(Geom_Surface) surface = BRep_Tool::Surface(face);
  if(auto trimmed = Handle(Geom_RectangularTrimmedSurface)::DownCast(surface))
    surface = trimmed->BasisSurface();
  double u0, u1, v0, v1;
  BRepTools::UVBounds(face, u0, u1, v0, v1);
  const GeomAdaptor_Surface adaptor(surface);
  double du = length, dv = length;
  switch(adaptor.GetType()) {
  case GeomAbs_Plane: break;
  case GeomAbs_Cylinder: du = length / adaptor.Cylinder().Radius(); break;
  case GeomAbs_Cone: {
    const double r = std::max(adaptor.Cone().RefRadius(), length);
    du = length / r;
    break;
  }
  case GeomAbs_BSplineSurface: {
    Handle(Geom_BoundedSurface) bounded = Handle(Geom_BSplineSurface)::DownCast(surface->Copy());
    for(bool inU : {true, false})
      for(bool after : {true, false}) GeomLib::ExtendSurfByLength(bounded, length, 1, inU, after);
    bounded->Bounds(u0, u1, v0, v1);
    TopoDS_Face out = BRepBuilderAPI_MakeFace(bounded, u0, u1, v0, v1, 1e-7);
    out.Orientation(face.Orientation());
    return out;
  }
  default: return face;
  }
  if(adaptor.IsUPeriodic()) {
    const double period = adaptor.UPeriod();
    if(u1 - u0 + 2 * du >= period) du = std::max(0.0, 0.5 * (period - (u1 - u0)) - 1e-6);
  }
  TopoDS_Face out = BRepBuilderAPI_MakeFace(surface, u0 - du, u1 + du, v0 - dv, v1 + dv, 1e-7);
  out.Orientation(face.Orientation());
  return out;
}

TopoDS_Shape offset(const TopoDS_Face &face, double distance)
{
  BRepOffsetAPI_MakeOffsetShape maker;
  maker.PerformBySimple(face, distance);
  if(!maker.IsDone()) throw Standard_Failure("offset not done");
  return maker.Shape();
}

// Points inside a face: the points of its surface at the centroids (in the
// parameters) of its triangles, at most `count`, spread over the list, and
// the points of a grid of its parameters that fall inside it.
std::vector<gp_Pnt> samples(const TopoDS_Face &face, double deflection, std::size_t count)
{
  std::vector<gp_Pnt> out;
  // On the surface, not on the chords of the triangles.
  const Handle(Geom_Surface) surface = BRep_Tool::Surface(face);
  // A grid of the parameters, for the large faces meshed by few triangles,
  // and for those BRepMesh fails on (a large plate with many inner loops):
  // finer while it finds no point inside.
  {
    double u0, u1, v0, v1;
    BRepTools::UVBounds(face, u0, u1, v0, v1);
    BRepClass_FaceClassifier classifier;
    for(int grid : {10, 40}) {
      for(int i = 0; i < grid; ++i)
        for(int j = 0; j < grid; ++j) {
          const gp_Pnt2d uv(u0 + (i + 0.5) * (u1 - u0) / grid, v0 + (j + 0.5) * (v1 - v0) / grid);
          classifier.Perform(face, uv, 1e-9);
          if(classifier.State() == TopAbs_IN) out.push_back(surface->Value(uv.X(), uv.Y()));
        }
      if(!out.empty()) break;
    }
  }
  try {
    BRepMesh_IncrementalMesh(face, deflection, false, 0.5);
  }
  catch(const Standard_Failure &) {
    return out;
  }
  TopLoc_Location location;
  const Handle(Poly_Triangulation) mesh = BRep_Tool::Triangulation(face, location);
  if(mesh.IsNull() || mesh->NbTriangles() == 0) return out;
  const int n = mesh->NbTriangles();
  const int step = std::max(1, n / static_cast<int>(count));
  for(int i = 1; i <= n; i += step) {
    int a, b, c;
    mesh->Triangle(i).Get(a, b, c);
    if(mesh->HasUVNodes()) {
      const gp_XY uv = (mesh->UVNode(a).XY() + mesh->UVNode(b).XY() + mesh->UVNode(c).XY()) / 3.0;
      out.push_back(surface->Value(uv.X(), uv.Y()));
      continue;
    }
    const gp_XYZ p = (mesh->Node(a).XYZ() + mesh->Node(b).XYZ() + mesh->Node(c).XYZ()) / 3.0;
    out.push_back(gp_Pnt(p).Transformed(location.Transformation()));
  }
  return out;
}

// Whether a point lies on a face: on its surface, within `tolerance`, and
// inside its boundary in the parameters.
bool onFace(const TopoDS_Face &face, const gp_Pnt &p, double tolerance)
{
  double u0, u1, v0, v1;
  BRepTools::UVBounds(face, u0, u1, v0, v1);
  GeomAPI_ProjectPointOnSurf projection(p, BRep_Tool::Surface(face), u0, u1, v0, v1);
  if(!projection.IsDone() || projection.NbPoints() == 0 || projection.LowerDistance() > tolerance) return false;
  double u, v;
  projection.LowerDistanceParameters(u, v);
  BRepClass_FaceClassifier classifier(face, gp_Pnt2d(u, v), 1e-7);
  return classifier.State() == TopAbs_IN;
}

} // namespace

int main(int argc, char **argv)
{
  if(argc < 4) {
    std::fprintf(stderr, "usage: facepair_trim <part.stp> <plan> <out.brep> [reach]\n");
    return 1;
  }
  const double reach = argc > 4 ? std::atof(argv[4]) : 4.0;
  auto clock = std::chrono::steady_clock::now();
  const auto lap = [&](const char *stage) {
    const auto now = std::chrono::steady_clock::now();
    if(std::getenv("FACEPAIR_TRIM_DEBUG"))
      std::fprintf(stderr, "%s: %.1f s\n", stage, std::chrono::duration<double>(now - clock).count());
    clock = now;
  };
  STEPControl_Reader reader;
  if(reader.ReadFile(argv[1]) != IFSelect_RetDone) {
    std::fprintf(stderr, "cannot read %s\n", argv[1]);
    return 1;
  }
  reader.TransferRoots();
  const TopoDS_Shape part = reader.OneShape();
  TopTools_IndexedMapOfShape faces;
  TopExp::MapShapes(part, TopAbs_FACE, faces);
  std::vector<TopoDS_Solid> solids;
  for(TopExp_Explorer s(part, TopAbs_SOLID); s.More(); s.Next()) solids.push_back(TopoDS::Solid(s.Current()));

  // The mid faces, original and enlarged.
  struct Mid {
    int face;
    double gap;
    TopoDS_Face original, enlarged;
    std::vector<TopoDS_Face> parts; // the enlarged face split by its barriers
  };
  std::vector<Mid> mids;
  double smallest = 1e300;
  {
    std::ifstream plan(argv[2]);
    int face;
    double distance;
    while(plan >> face >> distance) {
      if(face < 1 || face > faces.Extent()) continue;
      const TopoDS_Face cad = TopoDS::Face(faces(face));
      const double gap = 2 * std::abs(distance);
      try {
        Mid mid{face, gap, {}, {}, {}};
        for(TopExp_Explorer f(offset(cad, distance), TopAbs_FACE); f.More(); f.Next())
          mid.original = TopoDS::Face(f.Current());
        mid.enlarged = mid.original;
        try {
          for(TopExp_Explorer f(offset(enlarged(cad, reach * gap), distance), TopAbs_FACE); f.More(); f.Next())
            mid.enlarged = TopoDS::Face(f.Current());
          // An offset of a B-spline is a Geom_OffsetSurface, which the
          // intersections handle poorly: as a B-spline.
          if(BRep_Tool::Surface(mid.enlarged)->IsKind(STANDARD_TYPE(Geom_OffsetSurface))) {
            BRepBuilderAPI_NurbsConvert nurbs(mid.enlarged, Standard_True);
            for(TopExp_Explorer f(nurbs.Shape(), TopAbs_FACE); f.More(); f.Next())
              mid.enlarged = TopoDS::Face(f.Current());
          }
        }
        catch(const Standard_Failure &e) {
          std::fprintf(stderr, "face %d: not enlarged (%s)\n", face, e.GetMessageString());
        }
        if(mid.original.IsNull()) throw Standard_Failure("no face");
        smallest = std::min(smallest, gap);
        mids.push_back(mid);
      }
      catch(const Standard_Failure &e) {
        std::fprintf(stderr, "face %d: offset %g failed (%s)\n", face, distance, e.GetMessageString());
      }
    }
  }
  if(mids.empty()) {
    std::fprintf(stderr, "no mid face\n");
    return 1;
  }

  lap("offsets");
  // Barriers: a mid face is enlarged towards the junctions only. Across a
  // free edge, the face of the part beyond the edge (the end face, which
  // spans the thickness: its far side touches the other skin) enlarged on
  // its own surface splits the enlarged mid face, so that the enlargement
  // past the end of the wall, which may run inside the material of another
  // wall (the foot of a rib along a plate), is a piece of its own.
  TopTools_IndexedDataMapOfShapeListOfShape facesOfEdge;
  TopExp::MapShapesAndAncestors(part, TopAbs_EDGE, TopAbs_FACE, facesOfEdge);
  int barriers = 0;
  for(Mid &mid : mids) {
    const TopoDS_Face cad = TopoDS::Face(faces(mid.face));
    const Handle(Geom_Surface) surface = BRep_Tool::Surface(cad);
    TopTools_ListOfShape tools;
    TopTools_IndexedMapOfShape seen;
    for(TopExp_Explorer e(cad, TopAbs_EDGE); e.More(); e.Next()) {
      const TopoDS_Edge edge = TopoDS::Edge(e.Current());
      if(BRep_Tool::Degenerated(edge) || !facesOfEdge.Contains(edge)) continue;
      const BRepAdaptor_Curve curve(edge);
      const gp_Pnt m = curve.Value(0.5 * (curve.FirstParameter() + curve.LastParameter()));
      // OCC may throw on some surfaces (offsets of fillets): the edge is
      // then no barrier.
      try {
        GeomAPI_ProjectPointOnSurf projection(m, surface);
        if(!projection.IsDone() || projection.NbPoints() == 0) continue;
        double u, v;
        projection.LowerDistanceParameters(u, v);
        GeomLProp_SLProps props(surface, u, v, 1, 1e-9);
        if(!props.IsNormalDefined()) continue;
        gp_Dir n = props.Normal();
        if(cad.Orientation() == TopAbs_REVERSED) n.Reverse();
        const gp_Pnt across = m.Translated(-mid.gap * gp_Vec(n));
        for(const TopoDS_Shape &other : facesOfEdge.FindFromKey(edge)) {
          if(other.IsSame(cad) || seen.Contains(other)) continue;
          BRepExtrema_DistShapeShape distance(BRepBuilderAPI_MakeVertex(across).Vertex(), other);
          if(!distance.IsDone() || distance.Value() > 0.25 * mid.gap) continue;
          seen.Add(other);
          tools.Append(enlarged(TopoDS::Face(other), reach * mid.gap));
        }
      }
      catch(const Standard_Failure &) {
      }
    }
    if(tools.IsEmpty()) {
      mid.parts.push_back(mid.enlarged);
      continue;
    }
    barriers += tools.Extent();
    BRepAlgoAPI_Splitter splitter;
    TopTools_ListOfShape arguments;
    arguments.Append(mid.enlarged);
    splitter.SetArguments(arguments);
    splitter.SetTools(tools);
    splitter.SetFuzzyValue(1e-4 * smallest);
    splitter.Build();
    if(!splitter.IsDone()) {
      mid.parts.push_back(mid.enlarged);
      continue;
    }
    for(TopExp_Explorer f(splitter.Shape(), TopAbs_FACE); f.More(); f.Next())
      mid.parts.push_back(TopoDS::Face(f.Current()));
  }

  lap("barriers");
  // One general fuse of the enlarged mid faces and of the faces of the part.
  BOPAlgo_Builder fuse;
  for(const Mid &mid : mids)
    for(const TopoDS_Face &face : mid.parts) fuse.AddArgument(face);
  for(int i = 1; i <= faces.Extent(); ++i) fuse.AddArgument(faces(i));
  fuse.SetFuzzyValue(1e-4 * smallest);
  fuse.SetRunParallel(true);
  fuse.Perform();
  if(fuse.HasErrors()) {
    std::fprintf(stderr, "general fuse failed\n");
    return 1;
  }

  lap("general fuse");
  // The pieces to keep.
  const double deflection = 0.25 * smallest;
  // One classifier per solid, built once (building it is the costly part).
  std::vector<std::unique_ptr<BRepClass3d_SolidClassifier>> classifiers;
  for(const TopoDS_Solid &solid : solids) classifiers.push_back(std::make_unique<BRepClass3d_SolidClassifier>(solid));
  const auto inside = [&](const gp_Pnt &p) {
    for(auto &classifier : classifiers) {
      classifier->Perform(p, 1e-6);
      if(classifier->State() == TopAbs_IN) return true;
    }
    return false;
  };
  BRep_Builder builder;
  TopoDS_Compound out, droppedOutside, droppedFlaps, unsampledPieces;
  builder.MakeCompound(out);
  builder.MakeCompound(droppedOutside);
  builder.MakeCompound(droppedFlaps);
  builder.MakeCompound(unsampledPieces);
  const char *debug = std::getenv("FACEPAIR_TRIM_DEBUG");
  const auto area = [](const TopoDS_Shape &shape) {
    GProp_GProps props;
    BRepGProp::SurfaceProperties(shape, props);
    return props.Mass();
  };
  TopTools_IndexedMapOfShape kept;
  int pieces = 0, outside = 0, flaps = 0, unsampled = 0;
  for(const Mid &mid : mids) {
    double keptArea = 0;
    int keptPieces = 0;
    const std::vector<gp_Pnt> originalPoints = samples(mid.original, deflection, 32);
    TopTools_ListOfShape split;
    for(const TopoDS_Face &face : mid.parts) {
      const TopTools_ListOfShape &modified = fuse.Modified(face);
      if(modified.IsEmpty()) split.Append(face);
      for(const TopoDS_Shape &shape : modified) split.Append(shape);
    }
    for(const TopoDS_Shape &shape : split) {
      ++pieces;
      const TopoDS_Face piece = TopoDS::Face(shape);
      if(kept.Contains(piece)) continue;
      try {
        const std::vector<gp_Pnt> points = samples(piece, deflection, 24);
        if(points.empty()) {
          ++unsampled;
          builder.Add(unsampledPieces, piece);
          continue;
        }
        // The piece is wholly in or out (the faces of the part split it): a
        // vote of a few of its points.
        int in = 0, voters = 0;
        const std::size_t stride = std::max<std::size_t>(1, points.size() / 7);
        for(std::size_t k = 0; k < points.size(); k += stride, ++voters) in += inside(points[k]);
        if(2 * in <= voters) {
          ++outside;
          builder.Add(droppedOutside, piece);
          continue;
        }
        // The piece and the original face overlap: a point of the one lies on
        // the other (both ways, for a small piece or a small original face).
        const bool covers = std::any_of(originalPoints.begin(), originalPoints.end(),
                                        [&](const gp_Pnt &p) { return onFace(piece, p, 1e-3 * mid.gap); }) ||
                            std::any_of(points.begin(), points.end(),
                                        [&](const gp_Pnt &p) { return onFace(mid.original, p, 1e-3 * mid.gap); });
        if(!covers) {
          ++flaps;
          builder.Add(droppedFlaps, piece);
          continue;
        }
        kept.Add(piece);
        builder.Add(out, piece);
        keptArea += area(piece);
        ++keptPieces;
      }
      catch(const Standard_Failure &e) {
        // A piece OCC cannot sample or classify: counted with the unsampled.
        ++unsampled;
        builder.Add(unsampledPieces, piece);
      }
    }
    if(debug) {
      double far = 0;
      int in = 0, n = 0;
      for(const gp_Pnt &p : samples(mid.original, deflection, 12)) {
        BRepExtrema_DistShapeShape d(BRepBuilderAPI_MakeVertex(p).Vertex(), mid.enlarged);
        if(d.IsDone()) far = std::max(far, d.Value());
        in += inside(p);
        ++n;
      }
      const Handle(Geom_Surface) s = BRep_Tool::Surface(TopoDS::Face(faces(mid.face)));
      std::printf("face %d %s gap %.3g: original %.4g (inside %d/%d, off the enlarged face %.3g), kept %.4g in %d "
                  "pieces of %d\n", mid.face, s->DynamicType()->Name(), mid.gap, area(mid.original), in, n, far,
                  keptArea, keptPieces, split.Extent());
    }
  }
  if(debug) {
    BRepTools::Write(droppedOutside, (std::string(debug) + "_outside.brep").c_str());
    BRepTools::Write(droppedFlaps, (std::string(debug) + "_flaps.brep").c_str());
    BRepTools::Write(unsampledPieces, (std::string(debug) + "_unsampled.brep").c_str());
  }
  lap("selection");
  BRepTools::Write(out, argv[3]);
  std::printf("mid faces %zu, barriers %d, pieces %d: kept %d, outside %d, past a junction or a free edge %d, not sampled %d\n",
              mids.size(), barriers, pieces, kept.Extent(), outside, flaps, unsampled);
  return 0;
}
