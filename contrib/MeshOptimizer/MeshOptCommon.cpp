// TODO: Copyright

#include "MeshOptCommon.h"


const double MeshOptResults::BIGVAL = 1.e300;


MeshOptResults::MeshOptResults() :
  success(-1), CPU(0.), minNodeDisp(BIGVAL), maxNodeDisp(-BIGVAL),
  minScaledJac(BIGVAL), maxScaledJac(-BIGVAL), minMetricMin(BIGVAL),
  maxMetricMin(-BIGVAL)
{
}
