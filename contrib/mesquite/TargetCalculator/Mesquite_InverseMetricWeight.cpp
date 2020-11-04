/* ***************************************************************** 
    MESQUITE -- The Mesh Quality Improvement Toolkit

    Copyright 2007 Sandia National Laboratories.  Developed at the
    University of Wisconsin--Madison under SNL contract number
    624796.  The U.S. Government and the University of Wisconsin
    retain certain rights to this software.

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License 
    (lgpl.txt) along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA

    (2007) kraftche@cae.wisc.edu    

  ***************************************************************** */


/** \file InverseMetricWeight.cpp
 *  \brief 
 *  \author Jason Kraftcheck 
 */

#include "Mesquite.hpp"
#include "Mesquite_InverseMetricWeight.hpp"
#include "Mesquite_ElemSampleQM.hpp"
#include "Mesquite_MsqError.hpp"

namespace MESQUITE_NS {

InverseMetricWeight::~InverseMetricWeight() {}


double InverseMetricWeight::get_weight( PatchData& pd, 
                                 size_t element,
                                 Sample sample,
                                 MsqError& err )
{
  size_t h = ElemSampleQM::handle( sample, element );
  double value;
  bool flag = mMetric->evaluate( pd, h, value, err );
  MSQ_ERRZERO(err);
  if (!flag) {
    MSQ_SETERR(err)("Invalid metric value canot be used as target weight", MsqError::INVALID_STATE);
    return 0.0;
  }
  
  return 1.0/value;
}

} // namespace Mesquite
