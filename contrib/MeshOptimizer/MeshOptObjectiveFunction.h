// TODO: Copyright

#ifndef _MESHOPTOBJECTIVEFUNCTION_H_
#define _MESHOPTOBJECTIVEFUNCTION_H_

#include <string>
#include <vector>
#include "ap.h"

class ObjContrib;
class MeshOptResults;
class Patch;


class ObjectiveFunction : protected std::vector<ObjContrib*>    // Contributions to objective function in each pass
{
public:
  ObjectiveFunction() {}
  ObjectiveFunction(const std::vector<ObjContrib*> &model,
                        const std::vector<int> &contribInd);
  void initialize(Patch *mesh);
  std::string contribNames();
  std::string minMaxStr();
  void updateMinMax();
  void updateParameters();
  void updateResults(MeshOptResults &res);
  bool stagnated();
  bool targetReached();
  std::string failMeasures();
  std::string targetsNotReached();
  bool compute(double &obj, alglib::real_1d_array &gradObj);
};


#endif /* _MESHOPTOBJECTIVEFUNCTION_H_ */
