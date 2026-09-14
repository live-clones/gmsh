// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by J. Zaleski

#include <iostream>
#include <sstream>

#include "rtree.h"
#include "Context.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GEntity.h"
#include "MElement.h"
#include "MVertex.h"

struct KeyXYZ {
  std::vector<int> index;
  std::vector<int> typekey;
  std::size_t entityKeys;
  double x, y, z;
  std::vector<int> nodes;
};

class KeyXYZRTree {
private:
  RTree<struct KeyXYZ *, double, 3, double> *_rtree;
  double _tol;
  static bool rtree_callback(struct KeyXYZ *v, void *ctx)
  {
    struct KeyXYZ **out = static_cast<KeyXYZ **>(ctx);
    *out = v;
    return false; // we're done searching
  }

public:
  KeyXYZRTree(double tolerance = 1.e-8)
  {
    _rtree = new RTree<struct KeyXYZ *, double, 3, double>();
    _tol = tolerance;
  }
  ~KeyXYZRTree()
  {
    _rtree->RemoveAll();
    delete _rtree;
  }
  void insert(struct KeyXYZ *v)
  {
    struct KeyXYZ *out;
    double _min[3] = {v->x - _tol, v->y - _tol, v->z - _tol};
    double _max[3] = {v->x + _tol, v->y + _tol, v->z + _tol};

    if(!_rtree->Search(_min, _max, rtree_callback, &out)) {
      _rtree->Insert(_min, _max, v);
    }
    else {
      Msg::Debug("Node %d (%.16g, %.16g, %.16g) already exists "
                 "with tolerance %g: node %d (%.16g, %.16g, %.16g)",
                 v->entityKeys, v->x, v->y, v->z, _tol, out->entityKeys, out->x,
                 out->y, out->z);
    }
  }
  struct KeyXYZ *find(struct KeyXYZ *n)
  {
    struct KeyXYZ *out;
    double _min[3] = {n->x - _tol, n->y - _tol, n->z - _tol};
    double _max[3] = {n->x + _tol, n->y + _tol, n->z + _tol};
    if(_rtree->Search(_min, _max, rtree_callback, &out)) { return out; }
    else {
      Msg::Debug("Could not find node corresponding to reference node "
                 "%d (%g, %g, %g)",
                 n->entityKeys, n->x, n->y, n->z);
      return 0;
    }
  }
};

struct NodeXYZ {
  int nodeTag;
  double x, y, z;
};

class NodeXYZRTree {
private:
  RTree<struct NodeXYZ *, double, 3, double> *_rtree;
  double _tol;
  static bool rtree_callback(struct NodeXYZ *v, void *ctx)
  {
    struct NodeXYZ **out = static_cast<NodeXYZ **>(ctx);
    *out = v;
    return false; // we're done searching
  }

public:
  NodeXYZRTree(double tolerance = 1.e-8)
  {
    _rtree = new RTree<struct NodeXYZ *, double, 3, double>();
    _tol = tolerance;
  }
  ~NodeXYZRTree()
  {
    _rtree->RemoveAll();
    delete _rtree;
  }
  void insert(struct NodeXYZ *v)
  {
    struct NodeXYZ *out;
    double _min[3] = {v->x - _tol, v->y - _tol, v->z - _tol};
    double _max[3] = {v->x + _tol, v->y + _tol, v->z + _tol};

    if(!_rtree->Search(_min, _max, rtree_callback, &out)) {
      _rtree->Insert(_min, _max, v);
    }
    else {
      Msg::Debug("Node %d (%.16g, %.16g, %.16g) already exists "
                 "with tolerance %g: node %d (%.16g, %.16g, %.16g)",
                 v->nodeTag, v->x, v->y, v->z, _tol, out->nodeTag, out->x,
                 out->y, out->z);
    }
  }
  struct NodeXYZ *find(struct NodeXYZ *n)
  {
    struct NodeXYZ *out;
    double _min[3] = {n->x - _tol, n->y - _tol, n->z - _tol};
    double _max[3] = {n->x + _tol, n->y + _tol, n->z + _tol};
    if(_rtree->Search(_min, _max, rtree_callback, &out)) { return out; }
    else {
      Msg::Debug("Could not find node corresponding to reference node "
                 "%d (%g, %g, %g)",
                 n->nodeTag, n->x, n->y, n->z);
      return 0;
    }
  }
};

static void _getElementEdgeNodesCoord(const int elementType,
                                      std::vector<std::size_t> &nodeTags,
                                      std::vector<double> &coord,
                                      std::size_t &numElements, const int tag,
                                      const bool primary)
{
  int dim = ElementType::getDimension(elementType);
  std::map<int, std::vector<GEntity *>> typeEnt;
  _getEntitiesForElementTypes(dim, tag, typeEnt);
  const std::vector<GEntity *> &entities(typeEnt[elementType]);
  int familyType = ElementType::getParentType(elementType);
  numElements = 0;
  int numEdgesPerEle = 0, numNodesPerEdge = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    int n = ge->getNumMeshElementsByType(familyType);
    if(n && !numNodesPerEdge) {
      MElement *e = ge->getMeshElementByType(familyType, 0);
      numEdgesPerEle = e->getNumEdges();
      if(primary) { numNodesPerEdge = 2; }
      else {
        std::vector<MVertex *> v;
        // we could use e->getHighOrderEdge() here if we decide to remove
        // getEdgeVertices
        e->getEdgeVertices(0, v);
        numNodesPerEdge = v.size();
      }
    }
    numElements += n;
  }

  if(!numElements || !numEdgesPerEle || !numNodesPerEdge) return;
  if(numEdgesPerEle * numNodesPerEdge * numElements != nodeTags.size()) {
    nodeTags.resize(numEdgesPerEle * numNodesPerEdge * numElements);
    coord.resize(numEdgesPerEle * numNodesPerEdge * numElements * 3);
  }
  size_t o = 0;
  size_t idx = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    for(std::size_t j = 0; j < ge->getNumMeshElementsByType(familyType); j++) {
      if(o >= 0 && o < numElements) {
        MElement *e = ge->getMeshElementByType(familyType, j);
        for(int k = 0; k < numEdgesPerEle; k++) {
          std::vector<MVertex *> v;
          // we could use e->getHighOrderEdge() here if we decide to remove
          // getEdgeVertices
          e->getEdgeVertices(k, v);
          std::size_t N = primary ? 2 : v.size();
          for(std::size_t l = 0; l < N; l++) {
            nodeTags[idx] = v[l]->getNum();
            coord[3 * idx + 0] = v[l]->x();
            coord[3 * idx + 1] = v[l]->y();
            coord[3 * idx + 2] = v[l]->z();
            idx++;
          }
        }
      }
      o++;
    }
  }
}

static void _getFullPeriodicKeys(
  GEntity *ge, const int elementType, const std::string &fsName, int &order,
  int &numComponents, const int tag, int &tagMaster, const int dim,
  std::vector<int> &typeKeys, std::vector<int> &typeKeysMaster,
  std::vector<std::size_t> &entityKeys,
  std::vector<std::size_t> &entityKeysMaster, std::vector<double> &coord,
  std::vector<double> &coordMaster, std::vector<int> &orientationSign,
  const bool returnCoord)
{
  std::string functionSpaceType = fsName + std::to_string(order);
  std::vector<std::size_t> entityKeysMaster_temp;
  std::vector<double> coordMaster_temp;

  gmsh::model::mesh::getKeys(elementType, functionSpaceType, typeKeys,
                             entityKeys, coord, tag, returnCoord);

  typeKeysMaster = typeKeys;
  entityKeysMaster = entityKeys;
  coordMaster = coord;
  orientationSign = std::vector<int>(typeKeys.size(), 1);

  int nthreads = CTX::instance()->numThreads;
  if(!nthreads) nthreads = Msg::GetMaxThreads();

  if(fsName == "IsoParametric" || fsName == "Lagrange") {
#pragma omp parallel for num_threads(nthreads)
    for(std::size_t i = 0; i < entityKeys.size(); i++) {
      MVertex *v = GModel::current()->getMeshVertexByTag(entityKeys[i]);
      if(!v) { Msg::Warning("Unknown node %d", entityKeys[i]); }
      else {
        auto mv = ge->correspondingVertices.find(v);
        if(mv != ge->correspondingVertices.end()) {
          entityKeysMaster[i] = mv->second->getNum();
          if(returnCoord) {
            coord[3 * i] = mv->second->x();
            coord[3 * i + 1] = mv->second->y();
            coord[3 * i + 2] = mv->second->z();
          }
        }
        else {
          auto mv2 = ge->correspondingHighOrderVertices.find(v);
          if(mv2 != ge->correspondingHighOrderVertices.end()) {
            entityKeysMaster[i] = mv2->second->getNum();
            if(returnCoord) {
              coord[3 * i] = mv2->second->x();
              coord[3 * i + 1] = mv2->second->y();
              coord[3 * i + 2] = mv2->second->z();
            }
          }
        }
      }
    }
  }
  else if(dim == 1 && (fsName == "HcurlLegendre" || fsName == "H1Legendre")) {
    std::vector<double> affineTransform = ge->affineTransform;
    std::vector<std::size_t> nodeTagsMasterEdges, nodeTagsEdges;
    std::size_t numElements = 0;
    std::vector<double> coordNodeMaster, coordNode;

    _getElementEdgeNodesCoord(elementType, nodeTagsMasterEdges, coordNodeMaster,
                              numElements, tagMaster, true);
    _getElementEdgeNodesCoord(elementType, nodeTagsEdges, coordNode,
                              numElements, tag, true);
    int nbrKeysPerElement = entityKeys.size() / numElements;

    double tol = 1.e-8;
    NodeXYZRTree NodeTree(tol);
    for(std::size_t i = 0; i < nodeTagsMasterEdges.size(); i++) {
      struct NodeXYZ *Node = new NodeXYZ();

      Node->nodeTag = nodeTagsMasterEdges[i];
      Node->x = coordNodeMaster[3 * i + 0] * affineTransform[0] +
                coordNodeMaster[3 * i + 1] * affineTransform[1] +
                coordNodeMaster[3 * i + 2] * affineTransform[2] +
                affineTransform[3];
      Node->y = coordNodeMaster[3 * i + 0] * affineTransform[4] +
                coordNodeMaster[3 * i + 1] * affineTransform[5] +
                coordNodeMaster[3 * i + 2] * affineTransform[6] +
                affineTransform[7];
      Node->z = coordNodeMaster[3 * i + 0] * affineTransform[8] +
                coordNodeMaster[3 * i + 1] * affineTransform[9] +
                coordNodeMaster[3 * i + 2] * affineTransform[10] +
                affineTransform[11];

      struct NodeXYZ *foundNode = NodeTree.find(Node);
      if(!foundNode) NodeTree.insert(Node);
    }

    gmsh::model::mesh::getKeys(elementType, functionSpaceType, typeKeysMaster,
                               entityKeysMaster_temp, coordMaster_temp,
                               tagMaster, returnCoord);
    coordMaster = coordMaster_temp;

    KeyXYZRTree keyTree(tol);
    int diffKey = 0;

    struct KeyXYZ *Key = new KeyXYZ();
    for(unsigned i = 0; i < entityKeysMaster_temp.size(); i++) {
      if(diffKey == 0) {
        Key = new KeyXYZ();
        Key->x = coordMaster[3 * i + 0] * affineTransform[0] +
                 coordMaster[3 * i + 1] * affineTransform[1] +
                 coordMaster[3 * i + 2] * affineTransform[2] +
                 affineTransform[3];
        Key->y = coordMaster[3 * i + 0] * affineTransform[4] +
                 coordMaster[3 * i + 1] * affineTransform[5] +
                 coordMaster[3 * i + 2] * affineTransform[6] +
                 affineTransform[7];
        Key->z = coordMaster[3 * i + 0] * affineTransform[8] +
                 coordMaster[3 * i + 1] * affineTransform[9] +
                 coordMaster[3 * i + 2] * affineTransform[10] +
                 affineTransform[11];

        Key->typekey = {typeKeysMaster[i]};
        Key->index = {static_cast<int>(i)};
        Key->entityKeys = entityKeysMaster_temp[i];
      }
      else {
        Key->typekey.push_back(typeKeysMaster[i]);
        Key->index.push_back(static_cast<int>(i));
      }

      keyTree.insert(Key);

      diffKey++;
      if(diffKey > order) {
        keyTree.insert(Key);
        diffKey = 0;
      }
    }

    // Find the match between the keys with the transformed coordMaster and
    // coord (dependent).
    int el = 0;
    diffKey = 0;
    struct KeyXYZ *foundKey;
    for(unsigned j = 0; j < entityKeys.size(); j++) {
      if((el + 1) * nbrKeysPerElement <= j) el++;

      struct KeyXYZ *Key = new KeyXYZ();
      Key->x = coord[3 * j + 0];
      Key->y = coord[3 * j + 1];
      Key->z = coord[3 * j + 2];

      if(diffKey == 0) foundKey = keyTree.find(Key);

      if(foundKey) {
        entityKeysMaster[j] = foundKey->entityKeys;
        typeKeysMaster[j] = foundKey->typekey[diffKey];

        coordMaster[j * 3 + 0] =
          coordMaster_temp[foundKey->index[diffKey] * 3 + 0];
        coordMaster[j * 3 + 1] =
          coordMaster_temp[foundKey->index[diffKey] * 3 + 1];
        coordMaster[j * 3 + 2] =
          coordMaster_temp[foundKey->index[diffKey] * 3 + 2];

        struct NodeXYZ *node = new NodeXYZ();
        node->nodeTag = nodeTagsEdges[2 * el];

        node->x = coordNode[3 * el * 2 + 0];
        node->y = coordNode[3 * el * 2 + 1];
        node->z = coordNode[3 * el * 2 + 2];

        struct NodeXYZ *foundNode = NodeTree.find(node);
        if(!foundNode)
          Msg::Warning("Could not find node corresponding to reference node "
                       "%d (%g, %g, %g)",
                       node->nodeTag, node->x, node->y, node->z);
        int node1 = foundNode->nodeTag;

        node = new NodeXYZ();
        node->x = coordNode[3 * el * 2 + 3];
        node->y = coordNode[3 * el * 2 + 4];
        node->z = coordNode[3 * el * 2 + 5];

        foundNode = NodeTree.find(node);
        if(!foundNode)
          Msg::Warning("Could not find node corresponding to reference node "
                       "%d (%g, %g, %g)",
                       node->nodeTag, node->x, node->y, node->z);
        int node2 = foundNode->nodeTag;

        // CLaude code
        bool flip =
          (nodeTagsEdges[2 * el] > nodeTagsEdges[2 * el + 1] &&
           node1 < node2) ||
          (nodeTagsEdges[2 * el] < nodeTagsEdges[2 * el + 1] && node1 > node2);
        if(flip) {
          int localIndex = static_cast<int>(
            j - el * nbrKeysPerElement); // 0 = se, 1 = se2, ...
          int degree = localIndex + 1; // p = 1, 2, ...
          orientationSign[j] = (degree % 2 == 0) ? 1 : -1;
        }
        // End of Claude code
        // orientation is between two nodes so size of orientation is half the
        // size of keys. (keys are only end node of edge)
      }
      else
        Msg::Warning("Could not find key corresponding to reference key "
                     "%d (%g, %g, %g)",
                     Key->entityKeys, Key->x, Key->y, Key->z);
      diffKey++;
      if(diffKey > order) diffKey = 0;
    }
  }

  else {
    Msg::Error("Periodic key generation currently only available for "
               "\"IsoParametric\", \"Lagrange\" and \"1D HcurlLegendre\" "
               "function spaces");
  }
}
