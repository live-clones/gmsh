// TODO: Copyright

#include "MeshOptObjContrib.h"
#include <algorithm>

const double ObjContrib::BIGVAL = 1.e300;


ObjContrib::ObjContrib(std::string mesName, std::string name) :
 _parent(this), _min(BIGVAL), _max(-BIGVAL), _measureName(mesName), _name(name)
{
}


void ObjContrib::updateResults()
{
  _parent->_min = std::min(_parent->_min, _min);
  _parent->_max = std::max(_parent->_max, _max);
}
