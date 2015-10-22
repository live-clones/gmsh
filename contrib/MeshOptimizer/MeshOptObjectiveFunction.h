// TODO: Copyright

#ifndef _MESHOPTOBJECTIVEFUNCTION_H_
#define _MESHOPTOBJECTIVEFUNCTION_H_

#include <string>
#include <vector>
#include "ap.h"

class ObjContrib;
class Patch;


class ObjectiveFunction : public std::vector<ObjContrib*>    // Contributions to objective function in each pass
{
public:
  void initialize(Patch *mesh);
  std::string contribNames();
  std::string minMaxStr();
  std::vector< std::pair<double,double> > minMax();
  std::vector<std::string> names();
  void updateMinMax();
  void updateParameters();
  void updateResults();
  bool stagnated();
  bool targetReached();
  std::string failMeasures();
  std::string targetsNotReached();
  bool compute(double &obj, alglib::real_1d_array &gradObj);
};


#endif /* _MESHOPTOBJECTIVEFUNCTION_H_ */
