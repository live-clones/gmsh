#ifndef HXT_COMBINE_TET_MESH_
#define HXT_COMBINE_TET_MESH_

#include <functional>
#include <unordered_set>
#include <cassert>
#include <vector>
#include <fstream>

#include "basic_types.h"
#include "cell_types.h"
#include "combine_quality.h"

#include "hxt_message.h"
#include "hxt_mesh.h"

/**
* \file tet_mesh.h Declaration of classes interfacing tet mesh structures
* \author Jeanne Pellerin
*/

namespace HXTCombine {

  /**
  * \addtogroup Combine
  * @{
  */
  
  /**
  *  Structure holding all arrays storing a mesh
  *
  *  Internal to Combine module.
  *  Kept to not depend a 100% on HXTMesh which is not a stable structure yet.
  */
  class MeshStore {
  public:
    /** To be compatible with HXTMesh there are 4 double per vertex */
    std::vector<double> vertices;

    std::vector<VertexIndex> triangleCorners;
    std::vector<VertexIndex> quadCorners;
    std::vector<VertexIndex> tetCorners;
    std::vector<VertexIndex> hexCorners;

    std::vector<ColorIndex> triangleColors;
    std::vector<ColorIndex> quadColors;
    std::vector<ColorIndex> hexColors;
    std::vector<ColorIndex> tetColors;

    std::vector<AdjacentTetIndex> tetAdjacent;  // 4 values per tet,  4*adjacent tet + facet index
    AdjacentTetIndex NO_ADJACENT_ID = NO_ID;
  };

  void computeTetAdjacencies(MeshStore& store);

  void buildhxtVertexFromCoordinates(const std::vector<double>& points, std::vector<double>& hxtvertices);

  /**
  * Loads a tet mesh file stored in .mesh format 
  */
  void readFileMESH(const std::string& filename, MeshStore& mesh, bool read_triangles = true);

  /**
  *  Common accessor to mesh storage.
  *
  *  The class neither own or can modifiy the arrays it points to.
  */
  class TetMeshWrapper {
  public:
    const AdjacentTetIndex NO_ADJACENT = NO_ID;

  public:
    TetMeshWrapper(const MeshStore* store) :
      NO_ADJACENT(store->NO_ADJACENT_ID),
      nbVertices_(store->vertices.size()/4),
      nbTets_(store->tetCorners.size()/4),
      nbTriangles_(store->triangleCorners.size()/3),
      points_(store->vertices.data()),
      tetCorners_(store->tetCorners.data()),
      adjacentTets_(store->tetAdjacent.data()),
      tetColors_(store->tetColors.empty() ? nullptr : store->tetColors.data()),
      triangleCorners_(store->triangleCorners.empty() ? nullptr : store->triangleCorners.data()),
      triangleColors_(store->triangleColors.empty() ? nullptr : store->triangleColors.data())
    {}

    TetMeshWrapper(const HXTMesh* hxtmesh) :
      NO_ADJACENT(HXT_NO_ADJACENT),
      nbVertices_(hxtmesh->vertices.num),
      nbTets_(hxtmesh->tetrahedra.num),
      nbTriangles_(hxtmesh->triangles.num),
      points_(hxtmesh->vertices.coord),
      tetCorners_(hxtmesh->tetrahedra.node),
      adjacentTets_(hxtmesh->tetrahedra.neigh),
      tetColors_(hxtmesh->tetrahedra.color),
      triangleCorners_(hxtmesh->triangles.node),
      triangleColors_(hxtmesh->triangles.color)
    {}

    virtual ~TetMeshWrapper() {};

    TetMeshWrapper() = delete;
    TetMeshWrapper(const TetMeshWrapper& rhs) = delete;
    TetMeshWrapper& operator=(const TetMeshWrapper& rhs) = delete;

    unsigned int nbTets() const { return nbTets_; }
    unsigned int nbVertices() const { return nbVertices_; }
    unsigned int nbTriangles() const { return nbTriangles_; }

    VertexIndex vertex(TetIndex t, TetVertexIndex lv) const { return tetCorners_[4*t+lv]; }

    vec3 point(VertexIndex v) const {
      return vec3(points_[4*v], points_[4*v+1], points_[4*v+2]);
    }

    bool haveTetsColors() const { return tetColors_!= nullptr; }
    ColorIndex tetColor(TetIndex t) const { return haveTetsColors() ? tetColors_[t] : 0; }

    bool hasTriangles() const { return triangleCorners_!=nullptr; }
    bool hasColoredTriangles() const { return triangleColors_ != nullptr; }
    VertexIndex triangleVertex(TriangleIndex t, TriangleVertexIndex lv) const {
      return triangleCorners_[3*t+lv];
    }
    ColorIndex triangleColor(TriangleIndex t) const { return triangleColors_[t]; }

    TetIndex adjacentTet(TetIndex t, TetFacetIndex lf) const {
      // I know I am casting I will have problems when there are too many tets !!!
      return adjacentTets_[4*t+lf]/4;
    }
    TetFacetIndex adjacentFacetInAdjacentTet(TetIndex t, TetFacetIndex lf) const { return adjacentTets_[4*t+lf]%4; }
    bool isOnBoundary(TetIndex t, TetFacetIndex lf) const { return adjacentTets_[4*t+lf] == NO_ADJACENT; }

    bool isVolumePositive(VertexIndex v0, VertexIndex v1, VertexIndex v2, VertexIndex v3) const 
    {
      return orient3d(point(v0), point(v1), point(v2), point(v3)) > 0;
    }

    quadindex tet(TetIndex t) const {
      VertexIndex v0 = vertex(t, 0);
      VertexIndex v1 = vertex(t, 1);
      VertexIndex v2 = vertex(t, 2);
      VertexIndex v3 = vertex(t, 3);
      return quadindex(v0, v1, v2, v3);
    }
    trindex tetFacet(TetIndex t, TetFacetIndex lf) const {
      VertexIndex v0 = vertex(t, Tet::facetVertex[lf][0]);
      VertexIndex v1 = vertex(t, Tet::facetVertex[lf][1]);
      VertexIndex v2 = vertex(t, Tet::facetVertex[lf][2]);
      return trindex(v0, v1, v2);
    }
    bindex tetEdge(TetIndex t, TetEdgeIndex le) const {
      VertexIndex v0 = vertex(t, Tet::edgeVertex[le][0]);
      VertexIndex v1 = vertex(t, Tet::edgeVertex[le][1]);
      return bindex(v0, v1);
    }
    trindex triangleFacet(TriangleIndex t) const {
      VertexIndex v0 = triangleVertex(t, 0);
      VertexIndex v1 = triangleVertex(t, 1);
      VertexIndex v2 = triangleVertex(t, 2);
      return trindex(v0, v1, v2);
    }

    void debugPrint() const {
      std::cout << "nb vertices " << nbVertices_ << std::endl;
      std::cout << "nb tets " << nbTets_ << std::endl;
      std::cout << "nb triangles " << nbTriangles_ << std::endl;

      std::cout << "Adjacencies "<< std::endl;
      for (unsigned int i = 0; i < nbTets_; ++i) {
        std::cout << i << " "
          << adjacentTet(i, 0) << " "
          << adjacentTet(i, 1) << " "
          << adjacentTet(i, 2) << " "
          << adjacentTet(i, 3) << std::endl;
      }
    }

  private:
    const unsigned int nbVertices_;
    const unsigned int nbTets_;
    const unsigned int nbTriangles_;

    const double* points_;                   // 4 * nbVertices_ -- 4th value is for alignement
    const VertexIndex* tetCorners_;          // 4 * nbTets_
    const AdjacentTetIndex* adjacentTets_;   // 4 * nbTets_
    const ColorIndex* tetColors_;            // empty or nbTets_

    const VertexIndex* triangleCorners_;     // empty or 3 * nbTriangles_
    const ColorIndex* triangleColors_;       // empty or 1 * nbTriangles_
  };


  class TetMeshForCombining : public TetMeshWrapper {
  public:
    TetMeshForCombining(const MeshStore* store) :
      TetMeshWrapper(store)
    {
      initConnectivityTables();
    }
    TetMeshForCombining(const HXTMesh* hxtmesh) :
      TetMeshWrapper(hxtmesh)
    {
      initConnectivityTables();
    }

    TetMeshForCombining() = delete;
    TetMeshForCombining(const TetMeshForCombining& rhs) = delete;
    TetMeshForCombining& operator=(const TetMeshForCombining & rhs) = delete;

    inline ColorIndex tetAdjacentTriangleColor(TetIndex t, TetFacetIndex f) const {
      TriangleIndex tri = adjacentTriangles_[4*t+f];
      return tri != NO_ID ? triangleColor(tri) : NO_COLOR;
    }

    /**
    * Returns the sorted list DECREASING VALUES
    * of vertices connected to \param v through an edge
    */
    inline const vector<VertexIndex>& verticesAroundVertex(VertexIndex v) const {
      return vertexToVertices_[v];
    }

    /**
    * Returns all tets incident to a vertex
    */
    inline vector<TetIndex> tetsAroundVertex(VertexIndex v) const {
      vector<TetIndex> result;
      TetCornerIndex c = vertexToTetCorner_[v];
      while (c!= NO_ID) {
        TetIndex t = c/4;
        result.push_back(t);
        c = nextTetCornerAroundVertex_[c];
      }
      return result;
    }

    /**
    * This has to be as fast as possible.
    * When identifying candidate hexahedra in the mesh, this is the critical test.
    */
    inline bool hasFacet(const trindex& triangle) const {
      const auto &v = facets_[triangle.indices[0]];
      const auto s = std::make_pair(triangle.indices[1], triangle.indices[2]);
      const auto it = std::lower_bound(v.begin(), v.end(), s);
      return it != v.end() && *it==s;
    }

    inline const vector<VertexIndex>& verticesAroundVertices(VertexIndex v0) const {
      return verticesAroundVertex(v0);
    }

    inline vector<VertexIndex> verticesAroundVertices(VertexIndex v0, VertexIndex v1) const
    {
      const vector<VertexIndex>& first = verticesAroundVertices(v0);
      const vector<VertexIndex>& second = verticesAroundVertices(v1);
      vector<VertexIndex> result;
      result.reserve(first.size());
      std::set_intersection(first.begin(), first.end(), second.begin(), second.end(),
        std::back_inserter(result), std::greater<VertexIndex>());
      return result;
    }
    inline vector<VertexIndex> verticesAroundVertices( 
      VertexIndex v0, VertexIndex v1, VertexIndex v2) const 
    {
      const vector<VertexIndex> first = verticesAroundVertices(v0, v1);
      const vector<VertexIndex>& second = verticesAroundVertices(v2);
      vector<VertexIndex> result;
      result.reserve(first.size());
      std::set_intersection(first.begin(), first.end(), second.begin(), second.end(),
        std::back_inserter(result), std::greater<VertexIndex>());
      return result;
    }

    inline bool isTriangulatedQuad(VertexIndex v0, VertexIndex v1, VertexIndex v2, VertexIndex v3) const {
      return (hasFacet(trindex(v0, v1, v2)) && hasFacet(trindex(v0, v2, v3)))
        || (hasFacet(trindex(v1, v2, v3)) && hasFacet(trindex(v1, v3, v0)));
    }
    inline bool isTriangleFacet(VertexIndex v0, VertexIndex v1, VertexIndex v2) const {
      return hasFacet(trindex(v0, v1, v2));
    }

    double quadCornerQuality(VertexIndex v0, VertexIndex v1, VertexIndex v2) const {
      return quadCornerApproximateQuality(point(v0), point(v1), point(v2)); // What is the error ?
    }
    double hexCornerQuality(VertexIndex v0, VertexIndex v1, VertexIndex v2, VertexIndex v3) const {
      return cellCornerQuality<Hex>(point(v0), point(v1), point(v2), point(v3));
    }
    double prismCornerQuality(VertexIndex v0, VertexIndex v1, VertexIndex v2, VertexIndex v3) const {
      return cellCornerQuality<Prism>(point(v0),point(v1), point(v2), point(v3));
    }
    bool triangleCornerQuality(VertexIndex v0, VertexIndex v1, VertexIndex v2) const {
      return evaluateTriangle(point(v0), point(v1), point(v2));
    }

  private:
    void initConnectivityTables();

    void chainTetCornersAroundVertices();
    void fillVertexToVertices();
    void fillFacets();
    void connectTetsToTriangles();

  private:
    /** Which triangle is adjacent to each tet */
    vector<TriangleIndex> adjacentTriangles_; // empty or 4 per tet

                                              // Chain of tet corners around vertices
    vector<TetCornerIndex> nextTetCornerAroundVertex_;
    vector<TetCornerIndex> vertexToTetCorner_;

    /**
    * Neighboring vertices for each vertex are sorted by DECREASING value
    */
    vector<vector<VertexIndex>>vertexToVertices_;

    /**
    * All the facets of the mesh
    * Why are we not using anymore the hash table of trindex ? I cannot remember ... JP
    */
    std::vector<std::vector<std::pair<VertexIndex, VertexIndex>>> facets_;
  };


  /** Convenient function to save the vertices of a TetMeshForCombining. */
  template<class T>
  inline void saveVerticesMESH(const T& mesh, std::ofstream& out)
  {
    out << "Vertices" << std::endl;
    out << mesh.nbVertices() << std::endl;
    for (unsigned int i = 0; i < mesh.nbVertices(); ++i) {
      out << mesh.point(i) << " 0 " << std::endl;
    }
    out << std::endl;
  }

  template<class T>
  inline void saveVerticesMSH(const T& mesh, std::ofstream& out)
  {
    out << "$Nodes" << std::endl;
    out << mesh.nbVertices() << std::endl;
    for (unsigned int i = 0; i < mesh.nbVertices(); ++i) {
      out << i+1 << " " << mesh.point(i) << std::endl;
    }
    out << "$EndNodes"<< std::endl;
  }

  /**
  * @}
  */

}

#endif
