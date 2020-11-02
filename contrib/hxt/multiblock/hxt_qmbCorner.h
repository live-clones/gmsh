#ifndef HXT_QMBCORNER_H
#define HXT_QMBCORNER_H
#include <vector>
#include <array>

class Corner
{
 public:
  Corner();
  Corner(int ID,  uint64_t globaVertInd,
	 std::array<double,3> cornerCoord,
	 bool isFictive,
	 std::vector<uint64_t> patch,
	 std::vector<uint64_t> triangles,
	 std::vector<uint64_t> cornerEdges);
  ~Corner();
  int getID();
  uint64_t getGlobalVertex();
  std::array<double,3> getCoord();
  std::array<double,3>* getPCoord();
  std::vector<uint64_t>  getPatch();
  std::vector<uint64_t>* getPPatch();
  bool isFictive();
  int setFictive();
  std::vector<uint64_t> getEdges();
  std::vector<uint64_t> getTriangles();
  int addDirections(std::array<double,3> dir);
  std::vector<std::array<double,3>> getDirections();
  
 private:
  int m_ID;
  uint64_t m_globalVertInd;
  bool m_isFictive;
  std::array<double,3> m_coordinates;
  std::vector<uint64_t> m_patch;
  std::vector<uint64_t> m_tri;
  std::vector<uint64_t> m_edg;
  std::vector<std::array<double,3>> m_directionsBoundary;
  
 
  
};

#endif
