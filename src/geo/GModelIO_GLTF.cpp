// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <limits>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include "GmshConfig.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "Context.h"
#include "OS.h"
#include "GModel.h"
#include "MElement.h"
#include "MFace.h"
#include "MVertex.h"
#include "GModelIO_GLTF.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#include "PViewDataList.h"
#endif

namespace {

  // Minimal glTF writer: each mesh is placed in its own node of a single scene
  class writer {
  public:
    struct primitive {
      int mode; // 0: points, 1: lines, 4: triangles
      // accessor/material indices, or -1 if not used
      int position, color, indices, material;
      primitive(int m, int p)
        : mode(m), position(p), color(-1), indices(-1), material(-1)
      {
      }
    };

  private:
    std::vector<unsigned char> _buffer;
    std::vector<std::string> _bufferViews, _accessors, _materials, _meshes;
    bool _unlit = false;

    int _addBufferView(const void *data, std::size_t size, int target)
    {
      // all the data has 4-byte components, so the alignment is always correct
      const unsigned char *p = static_cast<const unsigned char *>(data);
      std::ostringstream s;
      s << "{ \"buffer\" : 0, \"byteOffset\" : " << _buffer.size()
        << ", \"byteLength\" : " << size << ", \"target\" : " << target
        << " }";
      _buffer.insert(_buffer.end(), p, p + size);
      _bufferViews.push_back(s.str());
      return _bufferViews.size() - 1;
    }
    static std::string _base64(const std::vector<unsigned char> &data)
    {
      static const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                  "abcdefghijklmnopqrstuvwxyz"
                                  "0123456789+/";
      std::string out;
      out.reserve(((data.size() + 2) / 3) * 4);
      for(std::size_t i = 0; i < data.size(); i += 3) {
        unsigned int val = 0;
        int count = 0;
        for(int j = 0; j < 3; j++) {
          val <<= 8;
          if(i + j < data.size()) {
            val |= data[i + j];
            count++;
          }
        }
        for(int j = 0; j < 4; j++) {
          if(j <= count)
            out.push_back(chars[(val >> (18 - 6 * j)) & 0x3F]);
          else
            out.push_back('=');
        }
      }
      return out;
    }
    static std::string _string(const std::string &s)
    {
      std::string out = "\"";
      for(char c : s) {
        if(c == '"' || c == '\\') out.push_back('\\');
        if((unsigned char)c >= 0x20) out.push_back(c);
      }
      return out + "\"";
    }
    static void _array(FILE *fp, const char *name,
                       const std::vector<std::string> &items, bool last = false)
    {
      fprintf(fp, "  \"%s\" : [\n", name);
      for(std::size_t i = 0; i < items.size(); i++)
        fprintf(fp, "    %s%s\n", items[i].c_str(),
                i + 1 < items.size() ? "," : "");
      fprintf(fp, "  ]%s\n", last ? "" : ",");
    }

  public:
    // add vertex positions (x0, y0, z0, x1, ...), converted from Gmsh's z-up
    // to glTF's y-up convention; returns the accessor index
    int addPositions(const std::vector<double> &xyz)
    {
      std::vector<float> pos(xyz.size());
      float min[3], max[3];
      for(int i = 0; i < 3; i++) {
        min[i] = std::numeric_limits<float>::max();
        max[i] = std::numeric_limits<float>::lowest();
      }
      for(std::size_t i = 0; i + 2 < xyz.size(); i += 3) {
        float p[3] = {(float)xyz[i], (float)xyz[i + 2], (float)-xyz[i + 1]};
        for(int j = 0; j < 3; j++) {
          pos[i + j] = p[j];
          min[j] = std::min(min[j], p[j]);
          max[j] = std::max(max[j], p[j]);
        }
      }
      int bv = _addBufferView(pos.data(), pos.size() * sizeof(float), 34962);
      // %.9g ensures that min/max exactly match the float values
      char str[512];
      snprintf(str, sizeof(str),
               "{ \"bufferView\" : %d, \"componentType\" : 5126, \"count\" : "
               "%zu, \"type\" : \"VEC3\", \"min\" : [ %.9g, %.9g, %.9g ], "
               "\"max\" : [ %.9g, %.9g, %.9g ] }",
               bv, pos.size() / 3, min[0], min[1], min[2], max[0], max[1],
               max[2]);
      _accessors.push_back(str);
      return _accessors.size() - 1;
    }
    // add vertex colors (packed RGBA, as in CTX); returns the accessor index
    int addColors(const std::vector<unsigned int> &colors)
    {
      std::vector<unsigned char> rgba;
      rgba.reserve(4 * colors.size());
      for(unsigned int c : colors) {
        rgba.push_back(CTX::instance()->unpackRed(c));
        rgba.push_back(CTX::instance()->unpackGreen(c));
        rgba.push_back(CTX::instance()->unpackBlue(c));
        rgba.push_back(CTX::instance()->unpackAlpha(c));
      }
      int bv = _addBufferView(rgba.data(), rgba.size(), 34962);
      char str[256];
      snprintf(str, sizeof(str),
               "{ \"bufferView\" : %d, \"componentType\" : 5121, "
               "\"normalized\" : true, \"count\" : %zu, \"type\" : \"VEC4\" }",
               bv, colors.size());
      _accessors.push_back(str);
      return _accessors.size() - 1;
    }
    // add element indices; returns the accessor index
    int addIndices(const std::vector<unsigned int> &indices)
    {
      int bv = _addBufferView(indices.data(),
                              indices.size() * sizeof(unsigned int), 34963);
      char str[256];
      snprintf(str, sizeof(str),
               "{ \"bufferView\" : %d, \"componentType\" : 5125, \"count\" : "
               "%zu, \"type\" : \"SCALAR\" }",
               bv, indices.size());
      _accessors.push_back(str);
      return _accessors.size() - 1;
    }
    // add a double-sided material with the given base color (packed RGBA); an
    // unlit material ignores the lighting of the viewer (useful when the
    // colors encode values); returns the material index
    int addMaterial(unsigned int color, bool unlit = false)
    {
      char rgba[256];
      snprintf(rgba, sizeof(rgba), "[ %.6g, %.6g, %.6g, %.6g ]",
               CTX::instance()->unpackRed(color) / 255.,
               CTX::instance()->unpackGreen(color) / 255.,
               CTX::instance()->unpackBlue(color) / 255.,
               CTX::instance()->unpackAlpha(color) / 255.);
      std::ostringstream s;
      s << "{ \"pbrMetallicRoughness\" : { \"baseColorFactor\" : " << rgba
        << ", \"metallicFactor\" : 0, \"roughnessFactor\" : 1 }, "
        << "\"doubleSided\" : true";
      if(CTX::instance()->unpackAlpha(color) < 255)
        s << ", \"alphaMode\" : \"BLEND\"";
      if(unlit) {
        s << ", \"extensions\" : { \"KHR_materials_unlit\" : {} }";
        _unlit = true;
      }
      s << " }";
      _materials.push_back(s.str());
      return _materials.size() - 1;
    }
    // add a mesh (and the node that holds it)
    void addMesh(const std::string &name, const std::vector<primitive> &prims)
    {
      std::ostringstream s;
      s << "{ \"name\" : " << _string(name) << ", \"primitives\" : [";
      for(std::size_t i = 0; i < prims.size(); i++) {
        const primitive &p = prims[i];
        s << (i ? "," : "") << "\n        { \"attributes\" : { \"POSITION\" : "
          << p.position;
        if(p.color >= 0) s << ", \"COLOR_0\" : " << p.color;
        s << " }";
        if(p.indices >= 0) s << ", \"indices\" : " << p.indices;
        if(p.material >= 0) s << ", \"material\" : " << p.material;
        s << ", \"mode\" : " << p.mode << " }";
      }
      s << " ] }";
      _meshes.push_back(s.str());
    }
    bool empty() const { return _meshes.empty(); }
    bool write(const std::string &fileName) const
    {
      FILE *fp = Fopen(fileName.c_str(), "w");
      if(!fp) {
        Msg::Error("Unable to open file '%s'", fileName.c_str());
        return false;
      }
      std::vector<std::string> nodes;
      std::ostringstream sceneNodes;
      for(std::size_t i = 0; i < _meshes.size(); i++) {
        nodes.push_back("{ \"mesh\" : " + std::to_string(i) + " }");
        sceneNodes << (i ? ", " : "") << i;
      }
      fprintf(fp, "{\n");
      fprintf(fp, "  \"asset\" : { \"version\" : \"2.0\", \"generator\" : "
                  "\"Gmsh\" },\n");
      if(_unlit)
        fprintf(fp, "  \"extensionsUsed\" : [ \"KHR_materials_unlit\" ],\n");
      fprintf(fp, "  \"scene\" : 0,\n");
      fprintf(fp, "  \"scenes\" : [ { \"nodes\" : [ %s ] } ],\n",
              sceneNodes.str().c_str());
      _array(fp, "nodes", nodes);
      _array(fp, "meshes", _meshes);
      if(_materials.size()) _array(fp, "materials", _materials);
      fprintf(fp, "  \"buffers\" : [ {\n");
      fprintf(fp, "    \"byteLength\" : %zu,\n", _buffer.size());
      fprintf(fp, "    \"uri\" : \"data:application/octet-stream;base64,%s\"\n",
              _base64(_buffer).c_str());
      fprintf(fp, "  } ],\n");
      _array(fp, "bufferViews", _bufferViews);
      _array(fp, "accessors", _accessors, true);
      fprintf(fp, "}\n");
      fclose(fp);
      return true;
    }
  };

  // same color as the one used to draw the mesh (see getColorByEntity())
  unsigned int entityColor(GEntity *e)
  {
    if(e->useColor()) return e->getColor();
    switch(CTX::instance()->mesh.colorCarousel) {
    case 0:
      return (e->dim() == 1) ? CTX::instance()->color.mesh.line :
             (e->dim() == 2) ? CTX::instance()->color.mesh.triangle :
                               CTX::instance()->color.mesh.tetrahedron;
    case 1: return CTX::instance()->color.mesh.carousel[abs(e->tag() % 20)];
    case 2: {
      int np = e->physicals.size();
      int p = np ? e->physicals[np - 1] : 0;
      return CTX::instance()->color.mesh.carousel[abs(p % 20)];
    }
    default: return CTX::instance()->color.fg;
    }
  }

  // add the mesh of an entity as one glTF mesh: lines for curves and triangles
  // for surfaces and for all the element faces of volumes (each face once);
  // quadrangles and polygons are split into triangles, and high-order
  // elements are saved as first order elements
  bool addEntity(writer &w, GModel *m, GEntity *e, double scalingFactor)
  {
    std::map<MVertex *, unsigned int> index;
    std::vector<double> xyz;
    std::vector<unsigned int> indices;
    auto addVertex = [&](MVertex *v) {
      auto it = index.find(v);
      if(it == index.end()) {
        it = index.insert(std::make_pair(v, (unsigned int)index.size())).first;
        xyz.insert(xyz.end(), {scalingFactor * v->x(), scalingFactor * v->y(),
                               scalingFactor * v->z()});
      }
      indices.push_back(it->second);
    };
    auto addFace = [&](const MFace &f) {
      for(std::size_t j = 1; j + 1 < f.getNumVertices(); j++) {
        addVertex(f.getVertex(0));
        addVertex(f.getVertex(j));
        addVertex(f.getVertex(j + 1));
      }
    };

    int dim = e->dim();
    std::set<MFace, MFaceLessThan> done;
    for(std::size_t i = 0; i < e->getNumMeshElements(); i++) {
      MElement *ele = e->getMeshElement(i);
      if(dim == 1 && ele->getNumPrimaryVertices() == 2) {
        addVertex(ele->getVertex(0));
        addVertex(ele->getVertex(1));
      }
      else if(dim == 2 && ele->getNumFaces() == 1) {
        addFace(ele->getFace(0));
      }
      else if(dim == 3) {
        for(int j = 0; j < ele->getNumFaces(); j++) {
          MFace f = ele->getFace(j);
          if(done.insert(f).second) addFace(f);
        }
      }
    }
    if(indices.empty()) return false;

    static const char *names[4] = {"Point ", "Curve ", "Surface ", "Volume "};
    std::string name = m->getElementaryName(dim, e->tag());
    if(name.empty()) name = names[dim] + std::to_string(e->tag());

    writer::primitive p(dim == 1 ? 1 : 4, w.addPositions(xyz));
    p.indices = w.addIndices(indices);
    p.material = w.addMaterial(entityColor(e));
    w.addMesh(name, std::vector<writer::primitive>(1, p));
    return true;
  }

} // namespace

namespace gltf {

  bool writeMesh(GModel *m, const std::string &fileName, bool saveAll,
                 double scalingFactor)
  {
    if(m->noPhysicalGroups()) saveAll = true;

    std::vector<GEntity *> entities;
    m->getEntities(entities);
    writer w;
    for(int dim : {2, 3, 1})
      for(GEntity *e : entities)
        if(e->dim() == dim && (saveAll || e->physicals.size()))
          addEntity(w, m, e, scalingFactor);

    if(w.empty()) {
      Msg::Error("No mesh elements to save in glTF format");
      return false;
    }
    return w.write(fileName);
  }

#if defined(HAVE_POST)
  bool writeView(PView *v, const std::string &fileName)
  {
    PViewOptions *opt = v->getOptions();
    PViewData *data = v->getData();

    int step = opt->timeStep;
    if(!data->hasTimeStep(step)) step = data->getFirstNonEmptyTimeStep();

    // same value range as the one used for drawing
    double vmin, vmax;
    if(opt->externalViewIndex >= 0) {
      vmin = opt->externalMin;
      vmax = opt->externalMax;
    }
    else if(opt->rangeType == PViewOptions::Custom) {
      vmin = opt->customMin;
      vmax = opt->customMax;
    }
    else if(opt->rangeType == PViewOptions::PerTimeStep) {
      vmin = data->getMin(step);
      vmax = data->getMax(step);
    }
    else {
      vmin = data->getMin();
      vmax = data->getMax();
    }
    int numColors = (opt->intervalsType == PViewOptions::Discrete ||
                     opt->intervalsType == PViewOptions::Numeric) ?
                      opt->nbIso :
                      -1;

    // glTF only has linear primitives: with PostProcessing.SaveAdapted, save
    // the step refined, as for the other formats (the refined data holds this
    // step only); otherwise high-order elements are saved as first order
    // elements
    bool adapted = false;
    if(v->savesAdapted()) {
      std::vector<PViewDataList *> steps = v->getAdaptedSteps();
      if(step < (int)steps.size() && steps[step]) {
        data = steps[step];
        step = 0;
      }
      adapted = true;
    }

    // vertices (and their colors) of the points, lines and triangles; vertices
    // are not shared, so no indices are needed
    std::vector<double> xyz[3];
    std::vector<unsigned int> colors[3];
    std::size_t numSkippedType = 0, numSkippedComp = 0, numHighOrder = 0;
    for(int ent = 0; ent < data->getNumEntities(step); ent++) {
      if(data->skipEntity(step, ent)) continue;
      for(int ele = 0; ele < data->getNumElements(step, ent); ele++) {
        if(data->skipElement(step, ent, ele, true)) continue;
        int type = data->getType(step, ent, ele);
        if(opt->skipElement(type)) continue;
        int numVertices;
        switch(type) {
        case TYPE_PNT: numVertices = 1; break;
        case TYPE_LIN: numVertices = 2; break;
        case TYPE_TRI: numVertices = 3; break;
        default: numSkippedType++; continue;
        }
        if(data->getNumComponents(step, ent, ele) != 1) {
          numSkippedComp++;
          continue;
        }
        // only keep the corner vertices of high-order elements
        if(data->getNumNodes(step, ent, ele) > numVertices) numHighOrder++;
        double x[3], y[3], z[3], val[3];
        bool outOfRange = false;
        for(int i = 0; i < numVertices; i++) {
          data->getNode(step, ent, ele, i, x[i], y[i], z[i]);
          data->getValue(step, ent, ele, i, val[i]);
          if(val[i] < vmin || val[i] > vmax) outOfRange = true;
        }
        if(outOfRange && !opt->saturateValues) continue;
        for(int i = 0; i < numVertices; i++) {
          xyz[numVertices - 1].insert(xyz[numVertices - 1].end(),
                                      {x[i], y[i], z[i]});
          colors[numVertices - 1].push_back(
            opt->getColor(val[i], vmin, vmax, false, numColors));
        }
      }
    }

    if(adapted) PView::doneSaving();

    if(numHighOrder)
      Msg::Info("Exported %zu high-order elements as first order elements in "
                "glTF export",
                numHighOrder);
    if(numSkippedType)
      Msg::Warning("Skipped %zu elements in glTF export (only points, lines "
                   "and triangles are supported)",
                   numSkippedType);
    if(numSkippedComp)
      Msg::Warning("Skipped %zu non-scalar elements in glTF export",
                   numSkippedComp);

    if(xyz[0].empty() && xyz[1].empty() && xyz[2].empty()) {
      Msg::Error("No scalar points, lines or triangles to save in glTF format");
      return false;
    }

    writer w;
    // the colors encode the values: don't let the viewer shade them
    int material =
      w.addMaterial(CTX::instance()->packColor(255, 255, 255, 255), true);
    std::vector<writer::primitive> prims;
    const int modes[3] = {0, 1, 4};
    for(int i = 2; i >= 0; i--) {
      if(xyz[i].empty()) continue;
      writer::primitive p(modes[i], w.addPositions(xyz[i]));
      p.color = w.addColors(colors[i]);
      p.material = material;
      prims.push_back(p);
    }
    w.addMesh(v->getData()->getName(), prims);
    return w.write(fileName);
  }
#endif

} // namespace gltf
