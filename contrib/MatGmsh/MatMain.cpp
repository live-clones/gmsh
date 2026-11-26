#include "MatPipeline.h"
#include "gmsh.h"
#include <cmath>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <stdexcept>

// Messages go through the Gmsh logger. An error raised by Gmsh is on the
// terminal before its exception arrives here, and writing an error to the
// logger throws in a session started through the API.
static void reportError(const std::string &message)
{
  try {
    std::string last;
    gmsh::logger::getLastError(last);
    if(last != message) gmsh::logger::write(message, "error");
  }
  catch(...) {
  }
}

int main(int argc, char **argv)
{
  if(argc < 2) {
    std::cerr << "Usage: gmshMat input.step|input.msh --thickness h --output directory\n"
                 "  [--stage filtered|projected|extended] [--project] [--mesh-size s]\n"
                 "  [--source-mesh cached.msh] [--keep-components] [--threads n]\n"
                 "  [--extension-length L] [--extension-layers n]\n"
                 "  [--raw tet|legacy] [--filter collapse|legacy|none]\n"
                 "  [--collapse-threshold 0.21] [--complex]\n"
                 "The defaults are --raw tet --filter collapse; --raw legacy or\n"
                 "--filter legacy alone selects the legacy raw MAT and filter.\n";
    return 1;
  }
  gmsh::initialize();
  int status = 1;
  try {
    matgmsh_native::Options options;
    std::string input = argv[1], cached;
    std::filesystem::path output;
    double meshSize = 0.; int threads = 1; bool complex = false;
    bool rawGiven = false, filterGiven = false, thicknessGiven = false;
    for(int i = 2; i < argc; ++i) {
      const std::string key = argv[i];
      auto value = [&]() { if(++i == argc) throw std::runtime_error("Missing value for " + key); return std::string(argv[i]); };
      if(key == "--thickness") { options.thickness = std::stod(value()); thicknessGiven = true; }
      else if(key == "--output") output = value();
      else if(key == "--project") options.project = true;
      else if(key == "--mesh-size") meshSize = std::stod(value());
      else if(key == "--source-mesh") cached = value();
      else if(key == "--threads") threads = std::stoi(value());
      else if(key == "--keep-components") options.legacyCleanup = false;
      else if(key == "--extension-length") options.extensionLength = std::stod(value());
      else if(key == "--extension-layers") options.extensionLayers = std::stoi(value());
      else if(key == "--collapse-threshold") options.collapseThreshold = std::stod(value());
      else if(key == "--complex") complex = true;
      else if(key == "--raw") {
        const std::string mode = value();
        if(mode == "legacy") options.raw = matgmsh_native::RawMode::Legacy;
        else if(mode == "tet") options.raw = matgmsh_native::RawMode::Tet;
        else throw std::runtime_error("Unknown raw mode " + mode);
        rawGiven = true;
      }
      else if(key == "--filter") {
        const std::string mode = value();
        if(mode == "legacy") options.filter = matgmsh_native::FilterMode::Legacy;
        else if(mode == "collapse") options.filter = matgmsh_native::FilterMode::Collapse;
        else if(mode == "none") options.filter = matgmsh_native::FilterMode::None;
        else throw std::runtime_error("Unknown filter mode " + mode);
        filterGiven = true;
      }
      else if(key == "--stage") {
        const std::string stage = value();
        if(stage == "filtered") options.stopAfter = matgmsh_native::Stage::Filtered;
        else if(stage == "projected") options.stopAfter = matgmsh_native::Stage::Projected;
        else if(stage == "extended") options.stopAfter = matgmsh_native::Stage::Extended;
        else throw std::runtime_error("Unknown stage " + stage);
      }
      else throw std::runtime_error("Unknown argument " + key);
    }
    // The legacy raw MAT and the legacy filter go together: naming one of
    // them is enough.
    if(rawGiven && !filterGiven && options.raw == matgmsh_native::RawMode::Legacy)
      options.filter = matgmsh_native::FilterMode::Legacy;
    if(filterGiven && !rawGiven && options.filter == matgmsh_native::FilterMode::Legacy)
      options.raw = matgmsh_native::RawMode::Legacy;
    if(!thicknessGiven) throw std::runtime_error("--thickness is required");
    if(output.empty()) throw std::runtime_error("--output is required");
    if(std::filesystem::exists(output)) throw std::runtime_error("Output directory already exists; choose a new checkpoint directory");
    if(threads < 1) throw std::runtime_error("--threads must be positive");
    if(!std::isfinite(options.thickness) || options.thickness <= 0.)
      throw std::runtime_error("--thickness must be finite and positive");
    if(!std::isfinite(meshSize) || meshSize < 0.)
      throw std::runtime_error("--mesh-size must be finite and nonnegative");
    if(!std::isfinite(options.extensionLength) || options.extensionLength < 0. ||
       options.extensionLayers < 1)
      throw std::runtime_error("Invalid extension length or number of layers");
    gmsh::option::setNumber("General.NumThreads", threads);
    double initialMeshSizeMin, initialMeshSizeMax;
    gmsh::option::getNumber("Mesh.MeshSizeMin", initialMeshSizeMin);
    gmsh::option::getNumber("Mesh.MeshSizeMax", initialMeshSizeMax);
    gmsh::open(input);
    double inputMeshSizeMin, inputMeshSizeMax;
    gmsh::option::getNumber("Mesh.MeshSizeMin", inputMeshSizeMin);
    gmsh::option::getNumber("Mesh.MeshSizeMax", inputMeshSizeMax);
    const bool inputSetsMeshSize = inputMeshSizeMin != initialMeshSizeMin ||
                                  inputMeshSizeMax != initialMeshSizeMax;
    if(!cached.empty()) gmsh::merge(cached);
    std::vector<int> types;
    std::vector<std::vector<std::size_t>> tags, nodes;
    gmsh::model::mesh::getElements(types, tags, nodes, 2);
    if(types.empty()) {
      const char *policy = "input mesh-size bounds";
      if(meshSize > 0. || !inputSetsMeshSize) {
        const double size = meshSize > 0. ? meshSize : .1 * options.thickness;
        gmsh::option::setNumber("Mesh.MeshSizeMin", size);
        gmsh::option::setNumber("Mesh.MeshSizeMax", size);
        inputMeshSizeMin = inputMeshSizeMax = size;
        policy = meshSize > 0. ? "--mesh-size" : "default h/10";
      }
      gmsh::option::setNumber("Mesh.ElementOrder", 1);
      std::ostringstream sizes;
      sizes << "MAT surface mesh: min=" << inputMeshSizeMin
            << " max=" << inputMeshSizeMax << " (" << policy << ")";
      gmsh::logger::write(sizes.str());
      gmsh::model::mesh::generate(2);
    }
    std::filesystem::create_directories(output);
    // Preserve every face and every coordinate bit for controlled replay,
    // including models with physical groups covering only part of the skin.
    gmsh::option::setNumber("Mesh.SaveAll", 1);
    gmsh::option::setNumber("Mesh.MshFileVersion", 4.1);
    gmsh::option::setNumber("Mesh.Binary", 1);
    gmsh::write((output / "source.msh").string());
    if(complex) options.complexDirectory = (output / "complex").string();
    matgmsh_native::Result result; std::string error;
    if(!matgmsh_native::computeCurrent(options, result, error)) throw std::runtime_error(error);
    for(const auto &item : std::vector<std::pair<std::string,const matgmsh_native::Mesh *>>{
        {"skin",&result.skin},{"raw",&result.raw},{"filtered",&result.filtered},
        {"projected",&result.projected},{"extended",&result.extended}}) {
      if(item.second->triangles.empty()) continue;
      if(!matgmsh_native::writeMesh(*item.second, (output / (item.first + ".msh")).string(), error))
        throw std::runtime_error(error);
    }
    if(!matgmsh_native::writeReport(result, options, (output / "report.json").string(), error))
      throw std::runtime_error(error);
    gmsh::logger::write("MAT checkpoints: " + output.string());
    status = options.stopAfter == matgmsh_native::Stage::Extended && !result.extension.complete ? 2 : 0;
  }
  catch(const std::exception &e) { reportError(e.what()); }
  catch(const std::string &e) { reportError(e); }
  catch(...) { reportError("unknown failure"); }
  gmsh::finalize();
  return status;
}
