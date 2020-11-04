/* ***************************************************************** 
    MESQUITE -- The Mesh Quality Improvement Toolkit

    Copyright 2006 Sandia National Laboratories.  Developed at the
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
 
    (2006) kraftche@cae.wisc.edu
   
  ***************************************************************** */


/** \file JSquared.cpp
 *  \brief 
 *  \author Jason Kraftcheck 
 */

#include "Mesquite.hpp"
#include "Mesquite_JSquared.hpp"
#include "Mesquite_MsqMatrix.hpp"
#include "Mesquite_ElementQM.hpp"
#include "Mesquite_MsqError.hpp"
#include "Mesquite_Vector3D.hpp"
#include "Mesquite_PatchData.hpp"
#include "Mesquite_MappingFunction.hpp"
#include "Mesquite_WeightCalculator.hpp"
#include "Mesquite_TargetCalculator.hpp"
#include "Mesquite_TargetMetric2D.hpp"
#include "Mesquite_TargetMetric3D.hpp"
#include "Mesquite_TargetMetricUtil.hpp"

#include <functional>
#include <algorithm>

namespace MESQUITE_NS {

int JSquared::get_negate_flag( ) const { return 1; }

std::string JSquared::get_name() const
  { return std::string("JSquared"); }

void JSquared::get_evaluations( PatchData& pd,
                                std::vector<size_t>& handles,
                                bool free,
                                MsqError& err )
{
  get_sample_pt_evaluations( pd, handles, free, err ); MSQ_CHKERR(err);
}

void JSquared::get_element_evaluations( PatchData& pd,
                                        size_t elem,
                                        std::vector<size_t>& handles,
                                        MsqError& err )
{
  get_elem_sample_points( pd, elem, handles, err ); MSQ_CHKERR(err);
}

bool JSquared::evaluate( PatchData& pd, size_t handle, double& value, MsqError& err )
{
  mIndices.clear();
  return evaluate_with_indices( pd, handle, value, mIndices, err );
}

bool JSquared::evaluate_with_indices( PatchData& pd,
                                      size_t handle,
                                      double& value,
                                      std::vector<size_t>& indices,
                                      MsqError& err )
{
  unsigned s = ElemSampleQM::sample( handle );
  size_t   e = ElemSampleQM::  elem( handle );
  MsqMeshEntity& elem = pd.element_by_index( e );
  EntityTopology type = elem.get_element_type();
  unsigned dim = ElemSampleQM::side_dim_from_sample( s );
  unsigned num = ElemSampleQM::side_num_from_sample( s );
  unsigned edim = TopologyInfo::dimension( type );
  
  const NodeSet bits = pd.non_slave_node_set( e );
  
  bool rval;
  size_t num_vtx = 0;
  if (edim == 3) {
    const MappingFunction3D* func = pd.get_mapping_function3D( type );
    if (!func) {
      MSQ_SETERR(err)( "No mapping function for element type", MsqError::UNSUPPORTED_ELEMENT );
      return false;
    }
    if (!metric3D) {
      MSQ_SETERR(err)("No 3D metric for Jacobian-based metric.\n", MsqError::UNSUPPORTED_ELEMENT );
      return false;
    }

    indices.resize( 27 );
    MsqVector<3> mDerivs;
    MsqMatrix<3,3> A;
    func->jacobian( pd, e, bits, dim, num, arrptr(indices), mDerivs, num_vtx, A, err );
    MSQ_ERRZERO( err );
    indices.resize(num_vtx);
    
    MsqMatrix<3,3> W;
    targetCalc->get_3D_target( pd, e, s, W, err ); MSQ_ERRZERO(err);
    rval = metric3D->evaluate( A, W, value, err ); MSQ_ERRZERO(err);
  }
  else {
    const MappingFunction2D* func = pd.get_mapping_function2D( type );
    if (!func) {
      MSQ_SETERR(err)( "No mapping function for element type", MsqError::UNSUPPORTED_ELEMENT );
      return false;
    }
    if (!metric2D) {
      MSQ_SETERR(err)("No 2D metric for Jacobian-based metric.\n", MsqError::UNSUPPORTED_ELEMENT );
      return false;
    }

    indices.resize( 9 );
    MsqVector<2> mDerivs;
    MsqMatrix<3,2> App;
    func->jacobian( pd, e, bits, dim, num, arrptr(indices), mDerivs, num_vtx, App, err );
    MSQ_ERRZERO( err );
    indices.resize(num_vtx);
    
    MsqMatrix<3,2> Wp;
    targetCalc->get_2D_target( pd, e, s, Wp, err ); MSQ_ERRZERO(err);
    MsqMatrix<3,1> Wp1 = Wp.column(0);
    MsqMatrix<3,1> Wp2 = Wp.column(1);
    MsqMatrix<3,1> nwp = Wp1 * Wp2;
    nwp *= 1.0/length(nwp);
    
    MsqMatrix<3,1> z[2];
    z[0] = Wp1 * (1.0 / length( Wp1 ));
    z[1] = nwp * z[0];
    MsqMatrix<3,2> Z(z);
    MsqMatrix<2,2> W = transpose(Z) * Wp;
    
    MsqMatrix<3,1> npp = App.column(0) * App.column(1);
    npp *= 1.0 / length(npp);
    double dot = npp % nwp;
    MsqMatrix<3,1> nr = (dot >= 0.0) ? nwp : -nwp;
    MsqMatrix<3,1> v = nr * npp;
    double vlen = length(v);
    MsqMatrix<2,2> A;
    if (vlen > DBL_EPSILON) {
      v *= 1.0 / length(v);
      MsqMatrix<3,1> r1[3] = { v, npp, v * npp }, r2[3] = { v, nr, v * nr };
      MsqMatrix<3,3> R1( r1 ), R2( r2 );
      MsqMatrix<3,3> RT = R2 * transpose(R1);
      MsqMatrix<3,2> Ap = RT * App;
      A = transpose(Z) * Ap;
    }
    else {
      A = transpose(Z) * App;
    }
    rval = metric2D->evaluate( A, W, value, err ); MSQ_ERRZERO(err);
  }
  
    // apply target weight to value
  if (weightCalc) {
    double ck = weightCalc->get_weight( pd, e, s, err ); MSQ_ERRZERO(err);
    value *= ck;
  }
  
  return rval;
}




} // namespace Mesquite
