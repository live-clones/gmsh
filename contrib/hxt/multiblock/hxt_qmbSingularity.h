#ifndef HXT_QMBSINGULARITY_H
#define HXT_QMBSINGULARITY_H
#include <cstdint>
#include <vector>
#include <array>

class Singularity
{
public:
  Singularity();
  Singularity(int ID, uint64_t globalEdgID, std::array<double,3> singCoord, std::vector<uint64_t> patch);
  ~Singularity();
  int getID();
  std::array<double,3> getCoord();
  std::array<double,3>* getPCoord();
  std::vector<uint64_t> getPatch();
  std::vector<uint64_t>* getPPatch();
  uint64_t getGlobalEdg();
  int setIsDisabled();
  bool isDisabled();
  int setIsFeatureNode();
  bool getIsFeatureNode();
  int setPatch(std::vector<uint64_t> patchNew);
  std::array<double,3>* getPNormal();
  int setNormal(std::array<double,3> newNormal);

 
  
private:
  int m_ID;
  bool m_isDisabled;
  bool m_isFeatureNode;
  uint64_t m_globalEdgId;
  int m_type; //crossfield sing 1, corner 0
  std::array<double,3> m_coordinates;
  std::vector<uint64_t> m_patch;
  std::array<double,3> m_normal;
};

#endif
