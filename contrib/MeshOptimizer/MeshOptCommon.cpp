// TODO: Copyright

#include "MeshOptCommon.h"


MeshOptResults::MeshOptResults() :
  success(-1), CPU(0.), minNodeDisp(BIGVAL), maxNodeDisp(-BIGVAL),
  minScaledJac(BIGVAL), maxScaledJac(-BIGVAL), minMetricMin(BIGVAL),
  maxMetricMin(-BIGVAL)
{
}
