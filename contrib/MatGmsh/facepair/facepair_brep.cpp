// Mid-surface faces of the wall groups of a thin part, as a BRep.
//
//   facepair_brep <part.stp> <plan> <out.brep>
//
// Each line of the plan is "face offset": the face (numbered as in
// TopExp::MapShapes, from 1) is offset along its outward normal by `offset`
// (negative: into the material, by half the gap to the opposite side of its
// wall). The offset face keeps the trimming of the original face, so its
// edges lie exactly above the CAD edges. The faces are written as one
// compound. <out.brep>.json maps each plan row to the exported face IDs.
// Exit status: 0 complete, 3 partial, 1 failed (including an empty plan).

#include <BRepOffsetAPI_MakeOffsetShape.hxx>
#include <BRepCheck_Analyzer.hxx>
#include <BRepTools.hxx>
#include <BRep_Builder.hxx>
#include <STEPControl_Reader.hxx>
#include <Standard_Failure.hxx>
#include <TopExp.hxx>
#include <TopExp_Explorer.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Compound.hxx>

#include <cstdio>
#include <cmath>
#include <fstream>
#include <filesystem>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

namespace {
std::string quoted(const std::string &s)
{
  std::ostringstream out;
  out << '"';
  for(unsigned char c : s) {
    if(c == '"' || c == '\\') out << '\\' << char(c);
    else if(c < 32) out << "\\u" << std::hex << std::setw(4) << std::setfill('0') << int(c) << std::dec;
    else out << char(c);
  }
  return out.str() + '"';
}
struct FaceResult {
  int line = 0, input = -1;
  double offset = 0;
  std::string error;
  std::vector<TopoDS_Shape> shapes;
};
} // namespace

int main(int argc, char **argv)
{
  if(argc < 4) {
    std::fprintf(stderr, "usage: facepair_brep <part.stp> <plan> <out.brep>\n");
    return 1;
  }
  for(int input : {1, 2}) {
    std::error_code error;
    if(std::filesystem::equivalent(argv[input], argv[3], error) && !error) {
      std::fprintf(stderr, "output must differ from input CAD and plan\n");
      return 1;
    }
  }
  std::remove(argv[3]); // A failed rerun must not leave an old BRep as its output.
  std::vector<FaceResult> results;
  const auto writeReport = [&](const std::string &status, const std::string &error,
                               const TopTools_IndexedMapOfShape &exported) {
    std::ofstream json(std::string(argv[3]) + ".json");
    json << "{\"schema_version\":1,\"status\":" << quoted(status)
         << ",\"input\":" << quoted(argv[1]) << ",\"plan\":" << quoted(argv[2])
         << ",\"error\":" << quoted(error) << ",\"output_faces\":" << exported.Extent()
         << ",\"faces\":[";
    bool first = true;
    for(const auto &r : results) {
      if(!first) json << ',';
      first = false;
      json << "{\"line\":" << r.line << ",\"input_face\":" << r.input
           << ",\"offset\":";
      if(std::isfinite(r.offset)) json << std::setprecision(17) << r.offset;
      else json << "null";
      json << ",\"status\":" << quoted(r.error.empty() ? "complete" : "failed")
           << ",\"error\":" << quoted(r.error) << ",\"output_faces\":[";
      bool firstFace = true;
      for(const auto &s : r.shapes) {
        const int id = exported.FindIndex(s);
        if(!id) continue;
        if(!firstFace) json << ',';
        firstFace = false;
        json << id;
      }
      json << "]}";
    }
    json << "],\"failed_faces\":[";
    first = true;
    for(const auto &r : results) if(!r.error.empty()) {
      if(!first) json << ',';
      first = false;
      json << r.input;
    }
    json << "]}\n";
    json.flush();
    return bool(json);
  };
  TopTools_IndexedMapOfShape noFaces;
  try {
    STEPControl_Reader reader;
    if(reader.ReadFile(argv[1]) != IFSelect_RetDone) {
      std::fprintf(stderr, "cannot read %s\n", argv[1]);
      writeReport("failed", "cannot read input STEP", noFaces);
      return 1;
    }
    reader.TransferRoots();
    const TopoDS_Shape shape = reader.OneShape();
    TopTools_IndexedMapOfShape faces;
    TopExp::MapShapes(shape, TopAbs_FACE, faces);

    BRep_Builder builder;
    TopoDS_Compound compound;
    builder.MakeCompound(compound);
    std::ifstream plan(argv[2]);
    if(!plan) {
      writeReport("failed", "cannot read plan", noFaces);
      return 1;
    }
    int made = 0, failed = 0, lineNumber = 0;
    std::string line;
    while(std::getline(plan, line)) {
      ++lineNumber;
      if(line.find_first_not_of(" \t\r") == std::string::npos) continue;
      FaceResult result;
      result.line = lineNumber;
      std::istringstream row(line);
      std::string extra;
      if(!(row >> result.input >> result.offset) || (row >> extra) || !std::isfinite(result.offset))
        result.error = "invalid plan row: expected finite face offset";
      else if(result.input < 1 || result.input > faces.Extent()) result.error = "invalid input face ID";
      if(!result.error.empty()) {
        ++failed;
        results.push_back(std::move(result));
        continue;
      }
      try {
        BRepOffsetAPI_MakeOffsetShape maker;
        maker.PerformBySimple(faces(result.input), result.offset);
        if(!maker.IsDone()) throw Standard_Failure("offset not done");
        for(TopExp_Explorer f(maker.Shape(), TopAbs_FACE); f.More(); f.Next()) {
          if(!BRepCheck_Analyzer(f.Current()).IsValid()) throw Standard_Failure("invalid offset face");
          result.shapes.push_back(f.Current());
        }
        if(result.shapes.empty()) throw Standard_Failure("no face");
        for(const auto &f : result.shapes) builder.Add(compound, f);
        ++made;
      }
      catch(const Standard_Failure &e) {
        result.error = e.GetMessageString() ? e.GetMessageString() : "OpenCASCADE failure";
        result.shapes.clear();
        std::fprintf(stderr, "face %d: offset %g failed (%s)\n", result.input, result.offset, result.error.c_str());
        ++failed;
      }
      results.push_back(std::move(result));
    }
    const bool written = made > 0 && BRepTools::Write(compound, argv[3]);
    TopTools_IndexedMapOfShape exported;
    if(written) TopExp::MapShapes(compound, TopAbs_FACE, exported);
    const std::string error = !made ? "no offset face produced" : !written ? "cannot write output BRep" : "";
    const std::string status = !error.empty() ? "failed" : failed ? "partial" : "complete";
    if(!writeReport(status, error, exported)) {
      std::fprintf(stderr, "cannot write status report\n");
      return 1;
    }
    std::printf("mid faces %d failed %d\n", made, failed);
    return status == "complete" ? 0 : status == "partial" ? 3 : 1;
  }
  catch(const Standard_Failure &e) {
    writeReport("failed", e.GetMessageString() ? e.GetMessageString() : "OpenCASCADE failure", noFaces);
    return 1;
  }
  catch(const std::exception &e) {
    writeReport("failed", e.what(), noFaces);
    return 1;
  }
}
