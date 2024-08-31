// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Alexandre Chemin

#include <gmsh.h>
#include <Visualization.hxx>

// gmsh::view::add
//     GMSH_API int add(const std::string & name,
//                      const int tag = -1);

//     // gmsh::view::addListData
//     //
//     // Add list-based post-processing data to the view with tag `tag'. List-based
//     // datasets are independent from any model and any mesh. `dataType' identifies
//     // the data by concatenating the field type ("S" for scalar, "V" for vector,
//     // "T" for tensor) and the element type ("P" for point, "L" for line, "T" for
//     // triangle, "S" for tetrahedron, "I" for prism, "H" for hexaHedron, "Y" for
//     // pyramid). For example `dataType' should be "ST" for a scalar field on
//     // triangles. `numEle' gives the number of elements in the data. `data'
//     // contains the data for the `numEle' elements, concatenated, with node
//     // coordinates followed by values per node, repeated for each step: [e1x1, ...,
//     // e1xn, e1y1, ..., e1yn, e1z1, ..., e1zn, e1v1..., e1vN, e2x1, ...].
//     GMSH_API void addListData(const int tag,
//                               const std::string & dataType,
//                               const int numEle,
//                               const std::vector<double> & data);

namespace IFF{
  namespace visu{
    int framefield(const std::map<Element *, std::vector<std::vector<double>>> &mapElemDir, const std::string & nameView, int visible){
      if(!gmsh::isInitialized())
        gmsh::initialize();
      int tagView = gmsh::view::add(nameView);
      int nBranches = (mapElemDir.begin()->second)[0].size()/3;
      std::cout << "Nbranches: " << nBranches << std::endl;
      int numEl = mapElemDir.size()*3*nBranches;
      std::vector<double> data;
      data.reserve(numEl*6);
      for(auto &kv: mapElemDir){
        Element *e = kv.first;
        for(int k=0; k<e->getNumEdges(); k++){
          Edge *edg = e->getEdge(k);
          std::vector<double> nodeCoord = edg->getBarycenter();
          for(int l=0; l<nBranches; l++){
            for(int j=0; j<3; j++)
              data.push_back(nodeCoord[j]);
            for(int j=0; j<3; j++)
              data.push_back(kv.second[k][3*l+j]);
          }
        }
      }
      gmsh::view::addListData(tagView, "VP", numEl, data);
      gmsh::view::option::setNumber(tagView, "Visible", visible);
      return tagView;
    }
    
    int vectorField(const std::map<Element *, std::vector<double>> &mapElemVect, const std::string & nameView, int visible){
      if(!gmsh::isInitialized())
        gmsh::initialize();
      std::string modelName;
      gmsh::model::getCurrent(modelName);
      std::vector<size_t> tags;
      std::vector<std::vector<double>> data;
      tags.reserve(mapElemVect.size());
      data.reserve(mapElemVect.size());
      for(const auto &kv: mapElemVect){
        tags.push_back(kv.first->getGmshTag());
        data.push_back(kv.second);
      }
      int tagView = gmsh::view::add(nameView);
      if(mapElemVect.size()>0){
        gmsh::view::addModelData(tagView, 0, modelName, "ElementData", tags, data, 0.0, 3);
      }
      // gmsh::view::option::setNumber(tagView, "GlyphLocation", 2);
      gmsh::view::option::setNumber(tagView, "Visible", visible);
      return tagView;
    }
    
    int scalarField(const std::map<Vertex*, double> &mapVertScalar, const std::string & nameView, int visible){
      if(!gmsh::isInitialized())
        gmsh::initialize();
      std::string modelName;
      gmsh::model::getCurrent(modelName);
      int numEl = mapVertScalar.size();
      std::vector<double> data;
      data.reserve(mapVertScalar.size()*4);
      for(const auto &kv: mapVertScalar){
        std::vector<double> nodeCoord = kv.first->getCoord();
        for(int j=0; j<nodeCoord.size(); j++)
          data.push_back(nodeCoord[j]);
        data.push_back(kv.second);
      }
      int tagView = gmsh::view::add(nameView);
      if(mapVertScalar.size()>0){
        gmsh::view::addListData(tagView, "SP", numEl, data);
        // gmsh::view::addModelData(tagView, 0, modelName, "NodeData", tags, data, 0.0, 1);
      }

      gmsh::view::option::setNumber(tagView, "PointType", 1);
      gmsh::view::option::setNumber(tagView, "PointSize", 8);

      // gmsh::view::option::setNumber(tagView, "GlyphLocation", 2);
      gmsh::view::option::setNumber(tagView, "Visible", visible);
      return tagView;
    }
    int scalarField(const std::map<Edge*, double> &mapEdgScalar, const std::string & nameView, int visible){
      if(!gmsh::isInitialized())
        gmsh::initialize();
      std::string modelName;
      gmsh::model::getCurrent(modelName);
      int numEl = mapEdgScalar.size();
      std::vector<double> data;
      data.reserve(mapEdgScalar.size()*4);
      for(const auto &kv: mapEdgScalar){
        std::vector<double> nodeCoord = kv.first->getBarycenter();
        for(int j=0; j<nodeCoord.size(); j++)
          data.push_back(nodeCoord[j]);
        data.push_back(kv.second);
      }
      int tagView = gmsh::view::add(nameView);
      if(mapEdgScalar.size()>0){
        gmsh::view::addListData(tagView, "SP", numEl, data);
        // gmsh::view::addModelData(tagView, 0, modelName, "NodeData", tags, data, 0.0, 1);
      }
      
      // gmsh::view::option::setNumber(tagView, "GlyphLocation", 2);
      gmsh::view::option::setNumber(tagView, "PointType", 1);
      gmsh::view::option::setNumber(tagView, "PointSize", 8);
      gmsh::view::option::setNumber(tagView, "Visible", visible);
      return tagView;
    }
    int scalarField(const std::map<Element*, double> &mapElemScalar, const std::string & nameView, int visible){
      if(!gmsh::isInitialized())
        gmsh::initialize();
      std::string modelName;
      gmsh::model::getCurrent(modelName);
      std::vector<size_t> tags;
      std::vector<std::vector<double>> data;
      tags.reserve(mapElemScalar.size());
      data.reserve(mapElemScalar.size());
      for(const auto &kv: mapElemScalar){
        tags.push_back(kv.first->getGmshTag());
        std::vector<double> elemData(1);
        elemData[0] = kv.second;
        data.push_back(elemData);
      }
      int tagView = gmsh::view::add(nameView);
      if(mapElemScalar.size()>0){
        gmsh::view::addModelData(tagView, 0, modelName, "ElementData", tags, data, 0.0, 1);
      }
      // gmsh::view::option::setNumber(tagView, "GlyphLocation", 2);
      gmsh::view::option::setNumber(tagView, "Visible", visible);
      gmsh::view::option::setNumber(tagView, "ShowElement", 1);
      return tagView;
    }
  }
}
