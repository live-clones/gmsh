#ifndef HXT_QMBSEPARATRICE_H
#define HXT_QMBSEPARATRICE_H
#include <vector>
#include <array>

class Separatrice
{
 public:
  Separatrice(int ID,std::vector<std::array<double,3>> nodesCoord, std::vector<uint64_t> triangles, std::vector<uint64_t> edges, std::vector<double> enteringAngles);
  ~Separatrice();
  int getID();
  std::vector<std::array<double,3>> getCoord();
  std::vector<std::array<double,3>>* getPCoord();
  int Disable();
  std::vector<uint64_t> getTriangles();
  std::vector<uint64_t>* getPTriangles();
  std::vector<uint64_t> getEdges();
  std::vector<double> getAngles();
  int addTriangle(uint64_t triNum);
  int addEdge(uint64_t edgNum);
  int addAngle(double angle);
  int addPoint(std::array<double,3> point);
  int addIntersectingSepID(int ID);
  std::vector<int>* getPIntersection();
  int setIsBoundarySep();
  bool isBoundary();
  bool isSaved();
  bool getIsRemovable();
  void setIsRemovable(bool value);
  void addToIgnoredPatch(std::vector<uint64_t> *patch);
  bool isInIgnoredPatch(uint64_t triNum);
  int getLoopType();
  int setLoopType(int type);
  int setLinkAngle(double angle);
  double getLinkAngle();
  uint64_t getSizeIgnoredPatch();
  
 private:
  int m_ID;
  std::vector<std::array<double,3>> m_nodesCoord;
  std::vector<uint64_t> m_triangles;
  std::vector<uint64_t> m_edges;
  std::vector<double> m_enteringAngles;
  bool m_isSaved;
  bool m_isRemovable;
  std::vector<int> m_intersection;
  std::vector<uint64_t> m_ignoredPatch;
  bool m_isBoundary;
  int m_loopType; //0 not loop, 1 a loop, 2 loop with start+end at singularity
  double m_linkAngle;
 
  
};

#endif
