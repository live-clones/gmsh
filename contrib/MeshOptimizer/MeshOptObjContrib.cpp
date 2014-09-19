// TODO: Copyright

#include "MeshOptObjContrib.h"


const double ObjContrib::BIGVAL = 1.e300;


ObjContrib::ObjContrib(std::string mesName, std::string name) :
 _min(0.), _max(0.), _measureName(mesName), _name(name)
{
}
