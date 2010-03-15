#ifndef _DG_MESH2MESH_PROJECTION_H_
#define _DG_MESH2MESH_PROJECTION_H_
#include "GmshConfig.h"
#include "dgDofContainer.h"
// #include "function.h"
#include "dgGroupOfElements.h"
// #include "dgConservationLaw.h"
// #include "dgAlgorithm.h"
#include "GModel.h"
#ifdef HAVE_MPI
#include "mpi.h"
#else
#include "string.h"
#endif
// #include <sstream>
#include "MElement.h"
// #include <benchmarks/misc/stipple.pos>

// TODO: better representation of matrices, faster matrix-vector matrix-matrix products
// projecting 3D integration points to 2D plane, instead of assuming z=0
// possibility to use spesific integration rules
class dgMesh2MeshProjection {
public: class dofStoragePattern;
private:
  bool _projectionMatrixIsBuilt, _useDofContainerOctree;
  Octree* _octree;
  int _numInDofs, _numOutDofs, _inMaxDim, _outMaxDim;
  dofStoragePattern* _inDofPattern;
  dofStoragePattern* _outDofPattern;
  linearSystemCSRGmm<double>* _projectionMatrix;
  void _buildProjectionMatrix(dgDofContainer* donor, dgDofContainer* receiver);
  void _multiplyByInverseMassMatrix(dgDofContainer* donor);
  void _applyProjection(dgDofContainer* donor, dgDofContainer* receiver, bool transpose, bool copy);
  bool _checkTranspose(dgDofContainer* donor,dgDofContainer* receiver);
  void _buildReceiverOctree(dgDofContainer* receiver);
  MElement* _getReceiverElementByCoord(SPoint3 point);
public:
  // Contains the number of groups, elements and nodes to check if DOF containers are mutually compatible
  class dofStoragePattern {
    private:
      int _nbGroups, _nbFields, _nbProjDofs;
      std::vector<int> _nbElems, _nbNodes, _groupFirstProjectionDofId;
    public:
      dofStoragePattern(dgDofContainer* dofContainer);
      bool operator == (const dofStoragePattern& other) const;
      // indices needed when accessing the projection matrix
      inline int getProjDofId (int groupId, int elementId, int nodeId) const {
        // this is different from dgDofContainer::getDofId() because nbFields is ignored
        return _groupFirstProjectionDofId[groupId]+elementId*_nbNodes[groupId]+nodeId;
      }
  };
  dgMesh2MeshProjection();
  dgMesh2MeshProjection(dgDofContainer* donor,dgDofContainer* receiver);
  void setIntegrationRule();
  void projectFromTo(dgDofContainer* donor,dgDofContainer* receiver);
  void copyFromTo(dgDofContainer* donor,dgDofContainer* receiver);
  static void registerBindings(binding *b);
};

#endif
