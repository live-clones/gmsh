#include "dofManager.h"

template <>
double DofManager<double, double>::getDofValue(long int entity, int type) const
{
  return 1.2345;
  /*
     if("find in fixed")
       return ...
     else if("find in init")
       return ...
     else if("find in constraint")
       ...
     else
       ...
  */
}

template <>
void DofManager<double, double>::createFixedDof(long int entity, int type, 
                                                const double &value)
{
  fixed[Dof(entity, type)] = value;
}
