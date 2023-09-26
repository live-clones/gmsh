#include "visualization.hxx"
#include <limits>

namespace IFF{
  namespace visu{
    void scalarfield(const std::map<Vertex *, double> &solution, const std::string & nameView, int visible){
      std::string modelName;
      gmsh::model::getCurrent(modelName);
      std::vector<size_t> tags;
      std::vector<std::vector<double> > data;
      tags.reserve(solution.size());
      data.reserve(solution.size());
      for(auto &kv: solution){
	tags.push_back(kv.first->getTag());
	std::vector<double> v{kv.second};
	data.push_back(v);
      }
      int tagView = gmsh::view::add(nameView);
      if(solution.size() > 0){
	gmsh::view::addModelData(tagView, 0, modelName, "NodeData", tags, data);
      }
      gmsh::view::option::setNumber(tagView, "Visible", visible);
    }

    void scalarfield(const std::map<Triangle *, double> &solution, const std::string & nameView, int visible){
      std::string modelName;
      gmsh::model::getCurrent(modelName);
      std::vector<size_t> tags;
      std::vector<std::vector<double> > data;
      tags.reserve(solution.size());
      data.reserve(solution.size());
      for(auto &kv: solution){
	tags.push_back(kv.first->getTag());
	std::vector<double> v{kv.second};
	data.push_back(v);
      }
      int tagView = gmsh::view::add(nameView);
      if(solution.size() > 0){
	gmsh::view::addModelData(tagView, 0, modelName, "ElementData", tags, data);
      }
      gmsh::view::option::setNumber(tagView, "Visible", visible);
    }

    void scalarfield(const std::map<Triangle *, std::vector<double>> &solution, const std::string & nameView, int visible){
      std::string modelName;
      gmsh::model::getCurrent(modelName);
      std::vector<size_t> tags;
      std::vector<std::vector<double> > data;
      tags.reserve(solution.size());
      data.reserve(solution.size());
      for(auto &kv: solution){
	tags.push_back(kv.first->getTag());
	data.push_back(kv.second);
      }
      int tagView = gmsh::view::add(nameView);
      if(solution.size() > 0){
	gmsh::view::addModelData(tagView, 0, modelName, "ElementNodeData", tags, data);
      }
      // gmsh::view::option::setNumber(tagView, "IntervalsType", 1);
      // gmsh::view::option::setNumber(tagView, "NbIso", 10.5);
      gmsh::view::option::setNumber(tagView, "Visible", visible);
    }
  
    void scalarfield(const std::map<Vertex *, std::vector<double>> &solutionGiven, const std::string & nameView, int visible){
      std::string modelName;
      gmsh::model::getCurrent(modelName);
      std::vector<size_t> tags;
      std::vector<std::vector<double> > data;
      tags.reserve(solutionGiven.size());
      data.reserve(solutionGiven.size());
      std::map<Vertex *, std::vector<double>> solution;
      if(solutionGiven.begin()->second.size() != 1){
	solution = solutionGiven;
	for(auto &kv: solution){
	  tags.push_back(kv.first->getTag());
	  if(kv.second.size() != 1)
	    kv.second.resize(1);
	  data.push_back(kv.second);
	}
      }
      else{
	for(const auto &kv: solutionGiven){
	  tags.push_back(kv.first->getTag());
	  data.push_back(kv.second);
	}
      }

      int tagView = gmsh::view::add(nameView);
      if(solution.size() > 0){
	gmsh::view::addModelData(tagView, 0, modelName, "NodeData", tags, data);
      }
      gmsh::view::option::setNumber(tagView, "Visible", visible);
    }

    void scalarfieldIsoValues(const std::map<Triangle *, std::vector<double>> &solution, const std::string & nameView, size_t nbIso, int visible){
      std::vector<double> rangeDisplay{std::numeric_limits<double>::max(), -std::numeric_limits<double>::max()};
      for(auto &kv: solution){
	for(double v: kv.second){
	  if(v<rangeDisplay[0])
	    rangeDisplay[0] = v;
	  if(v>rangeDisplay[1])
	    rangeDisplay[1] = v;
	}
      }
      // double delta = (rangeDisplay[1] - rangeDisplay[0])/(nbIso-1);
      double delta = 0.0;
      rangeDisplay[0] += delta/2.0;
      rangeDisplay[1] -= delta/2.0;
      // nbIso -= 1;
      std::string modelName;
      gmsh::model::getCurrent(modelName);
      std::vector<size_t> tags;
      std::vector<std::vector<double> > data;
      tags.reserve(solution.size());
      data.reserve(solution.size());
      for(auto &kv: solution){
	tags.push_back(kv.first->getTag());
	data.push_back(kv.second);
      }
      int tagView = gmsh::view::add(nameView);
      if(solution.size() > 0){
	gmsh::view::addModelData(tagView, 0, modelName, "ElementNodeData", tags, data);
      }
      gmsh::view::option::setNumber(tagView, "IntervalsType", 1);
      gmsh::view::option::setNumber(tagView, "NbIso", nbIso);
      gmsh::view::option::setNumber(tagView, "ColormapNumber", 0);
      // gmsh::view::option::setNumber(tagView, "LineType", 1);
      gmsh::view::option::setNumber(tagView, "LineWidth", 3);
      gmsh::view::option::setNumber(tagView, "Visible", visible);
      gmsh::view::option::setNumber(tagView, "RangeType", 2);
      gmsh::view::option::setNumber(tagView, "Min", rangeDisplay[0]);
      gmsh::view::option::setNumber(tagView, "MinVisible", rangeDisplay[0]);
      gmsh::view::option::setNumber(tagView, "Max", rangeDisplay[1]);
      gmsh::view::option::setNumber(tagView, "MaxVisible", rangeDisplay[1]);
      gmsh::view::option::setNumber(tagView, "CustomMin", rangeDisplay[0]);
      gmsh::view::option::setNumber(tagView, "CustomMax", rangeDisplay[1]);
    }
  
    void vectorfield(const std::map<Vertex *, std::vector<double>> &solutionGiven, const std::string & nameView, int visible){
      std::string modelName;
      gmsh::model::getCurrent(modelName);
      std::vector<size_t> tags;
      std::vector<std::vector<double> > data;
      tags.reserve(solutionGiven.size());
      data.reserve(solutionGiven.size());
      std::map<Vertex *, std::vector<double>> solution;
      if(solutionGiven.begin()->second.size() == 2){
	solution = solutionGiven;
	for(auto &kv: solution)
	  kv.second.push_back(0.0);
	for(auto &kv: solution){
	  tags.push_back(kv.first->getTag());
	  data.push_back(kv.second);
	}
      }
      else{
	for(const auto &kv: solutionGiven){
	  tags.push_back(kv.first->getTag());
	  data.push_back(kv.second);
	}
      }

      int tagView = gmsh::view::add(nameView);
      if(solutionGiven.size() > 0){
	gmsh::view::addModelData(tagView, 0, modelName, "NodeData", tags, data);
      }
      gmsh::view::option::setNumber(tagView, "Visible", visible);
    }

    void vectorfield(const std::map<Triangle *, std::vector<double>> &solutionGiven, const std::string & nameView, int visible){
      std::string modelName;
      gmsh::model::getCurrent(modelName);
      std::vector<size_t> tags;
      std::vector<std::vector<double> > data;
      tags.reserve(solutionGiven.size());
      data.reserve(solutionGiven.size());
      std::map<Triangle *, std::vector<double>> solution;
      if(solutionGiven.begin()->second.size() == 2){
	solution = solutionGiven;
	for(auto &kv: solution)
	  kv.second.push_back(0.0);
	for(auto &kv: solution){
	  tags.push_back(kv.first->getTag());
	  data.push_back(kv.second);
	}
      }
      else{
	for(const auto &kv: solutionGiven){
	  tags.push_back(kv.first->getTag());
	  data.push_back(kv.second);
	}
      }

      int tagView = gmsh::view::add(nameView);
      if(solutionGiven.size() > 0){
	gmsh::view::addModelData(tagView, 0, modelName, "ElementNodeData", tags, data, 0.0, 3);
      }
      gmsh::view::option::setNumber(tagView, "GlyphLocation", 2);
      gmsh::view::option::setNumber(tagView, "Visible", visible);
    }
  
    void crossfield(const std::map<Vertex *, std::vector<std::vector<double>>> &mapVertDir, const std::string & nameView, int visible){
      std::string modelName;
      gmsh::model::getCurrent(modelName);
      std::vector<size_t> tags;
      std::vector<std::vector<std::vector<double>>> data;
      tags.reserve(mapVertDir.size());
      data.resize(4);
      for(size_t k=0; k<4; k++)
	data[k].reserve(mapVertDir.size());
      for(auto &kv: mapVertDir){
	tags.push_back(kv.first->getTag());
	for(size_t k=0; k<4; k++){
	  std::vector<double> vectVal(kv.second[k%2]);
	  if(k==2 || k==3)
	    for(size_t l=0; l<vectVal.size(); l++)
	      vectVal[l] *= -1.0;
	  data[k].push_back(vectVal);
	}
      }
      for(size_t k=0; k<4; k++){
	int tagView = gmsh::view::add(nameView + " " + std::to_string(k));
	if(mapVertDir.size() > 0){
	  gmsh::view::addModelData(tagView, 0, modelName, "NodeData", tags, data[k]);
	}
	gmsh::view::option::setNumber(tagView, "GlyphLocation", 2);
	gmsh::view::option::setNumber(tagView, "Visible", visible);
      }
    }

    void edges(const std::vector<Edge*> &edges, const std::string & nameView, int visible){
      std::string dataType = "SL";
      int numElem = edges.size();
      std::vector<double> data;
      data.reserve(5*edges.size());
      for(Edge *e : edges){
	for(size_t j=0; j<3; j++){
	  for(size_t l=0; l<2; l++){
	    data.push_back(e->getVertex(l)->getCoord()[j]);
	  }
	}
	for(size_t l=0; l<2; l++)
	  data.push_back(1.0);
      }

      int tagView = gmsh::view::add(nameView);
      if(edges.size() > 0){
	gmsh::view::addListData(tagView, dataType, numElem, data);
      }
      gmsh::view::option::setNumber(tagView, "LineType", 1);
      gmsh::view::option::setNumber(tagView, "LineWidth", 3);
      gmsh::view::option::setNumber(tagView, "ColormapNumber", 0);
      gmsh::view::option::setNumber(tagView, "Visible", visible);
    }
  }
}
