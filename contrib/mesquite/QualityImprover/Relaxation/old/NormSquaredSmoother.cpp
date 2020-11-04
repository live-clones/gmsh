/* ***************************************************************** 
   MESQUITE -- The Mesh Quality Improvement Toolkit

   Copyright 2004 Sandia Corporation and Argonne National
   Laboratory.  Under the terms of Contract DE-AC04-94AL85000 
   with Sandia Corporation, the U.S. Government retains certain 
   rights in this software.

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
 
   diachin2@llnl.gov, djmelan@sandia.gov, mbrewer@sandia.gov, 
   pknupp@sandia.gov, tleurent@mcs.anl.gov, tmunson@mcs.anl.gov      
   
   ***************************************************************** */
/*!
  \file   NormSquaredSmoother.cpp
  \brief  

  The NormSquaredSmoother Class is the concrete class
  that performs 1/2 times (the norm of T) squared smoothing
  
  NOTE (IMPORTANT):  This smoother currently only works for tet elements.

  \author Michael Brewer
  \date   2005-05-02
*/

#include "Mesquite_NormSquaredSmoother.hpp"
#include "Mesquite_LPtoPTemplate.hpp"
#include "Mesquite_EdgeLengthQualityMetric.hpp"
#include "Mesquite_MsqFreeVertexIndexIterator.hpp"
#include <vector>
using std::vector;

namespace MESQUITE_NS {

  std::string NormSquaredSmoother::get_name() const
    { return "NormSquaredSmoother"; }

  NormSquaredSmoother::NormSquaredSmoother() 
  {
  }  

  NormSquaredSmoother::~NormSquaredSmoother() 
  {
  }    
  

  void NormSquaredSmoother::initialize(PatchData& /*pd*/, MsqError& /*err*/)
  {
 
  }


  void NormSquaredSmoother::initialize_mesh_iteration(PatchData &/*pd*/,
                                                      MsqError &/*err*/)
  {
      //  cout << "- Executing NormSquaredSmoother::iteration_complete()\n";
  }


/*!
 */
  void NormSquaredSmoother::optimize_vertex_positions(PatchData &pd, 
                                                      MsqError &err)
  {
      //default the laplacian smoother to 3 even for 2-d elements.
      //int dim = get_mesh_set()->space_dim();
      //size_t dim = 3;
  
    MSQ_FUNCTION_TIMER( "NormSquaredSmoother::optimize_vertex_positions" );

  
      // does the Norm squared of T smoothing
    MsqFreeVertexIndexIterator free_iter(pd, err);  MSQ_ERRRTN(err);
    free_iter.reset();
    free_iter.next();
      //m is the free vertex.
    size_t m=free_iter.value();
      //move vertex m
    norm_squared_smooth_mesh(pd, m, err); MSQ_ERRRTN(err);
      //snap vertex m to domain
    pd.snap_vertex_to_domain(m,err);
  
  }
  
  void NormSquaredSmoother::terminate_mesh_iteration(PatchData &/*pd*/,
                                                     MsqError &/*err*/)
  {
      //  cout << "- Executing NormSquaredSmoother::iteration_complete()\n";
  }
  
  void NormSquaredSmoother::cleanup()
  {
      //  cout << "- Executing NormSquaredSmoother::iteration_end()\n";
  }
  
  bool NormSquaredSmoother::norm_squared_smooth_mesh(
    PatchData &pd, size_t free_index, MsqError &err)
  {
      //get vertex and element arrays
    MsqVertex* verts=pd.get_vertex_array(err);MSQ_ERRFALSE(err);
    MsqMeshEntity* elems=pd.get_element_array(err);MSQ_ERRFALSE(err);
    size_t num_elements = pd.num_elements();
      //matrix to store a map for the given corner
      // (element/vertex combination) that maps the
      //vertex to 0 and the other vertices to 1,2,3
    int local_matrix_map[MSQ_MAX_NUM_VERT_PER_ENT];
    size_t local_matrix_map_length=MSQ_MAX_NUM_VERT_PER_ENT;
    size_t local_matrix_map_used=0;
    Vector3D new_position;
      //will be used as the denominator
    double scale_value = 0.0;
    size_t i, j, k;
      //Z and Z^(t)
    Matrix3D z_mat_transpose;
    Matrix3D z_mat;
      //array of Y's... one for each vertex in this corner.
    Matrix3D y_mat[4];
      //c_(j,k) for the vertices
    double c_scalars[4];
    vector<size_t> elems_verts;
      //loop over the two or three dimensions
    for(i=0;i<num_elements;++i) {
        //actually get the map for this corner...
      local_matrix_map_used = elems[i].get_local_matrix_map_about_vertex(
        pd, &verts[free_index],local_matrix_map_length, local_matrix_map,err);
      MSQ_ERRFALSE(err);
        //get a vector of the vertex indices for this element
      elems[i].get_vertex_indices(elems_verts);
        //get the W array for this elements
      int elem_idx = pd.get_element_index(&elems[i]);
      const TargetMatrix* W = pd.targetMatrices.get_element_corner_tags(
        &pd, elem_idx, err );MSQ_ERRFALSE(err);
        //initial c_scalars to 0.0 and calculate Y for each vertex in the
        // this corner.
      for(j=0;j<local_matrix_map_used;++j){
        c_scalars[j]=0.0;
        if(local_matrix_map[j] < 0){
          MSQ_SETERR(err)("Invalid index returned from MsqMeshEntity.\n",
                          MsqError::INVALID_STATE);
          return false;
        }
          //tmp_mat=W[local_matrix_map[j]];
        inv(z_mat,W[local_matrix_map[j]]);
          //inv(z_mat, I);
        z_mat_transpose=transpose(z_mat);
        matmult( y_mat[j], z_mat, z_mat_transpose);
          //std::cout<<"\n j "<<j<<"\n";
          //std::cout<<"\n"<<y_mat[j]<<"\n";
      }
        //0 case (c_scalars[0])
      for(j=0;j<3;++j){
        for(k=0;k<3;++k){
          c_scalars[0] += ((y_mat[0])[j][k]);
        }
        c_scalars[0] += ((y_mat[j+1])[j][j]);
      }
        //1, 2, and if need 3
      for(j=0;j<3;++j){
        for(k=0;k<3;++k){
          c_scalars[j+1] -= (((y_mat[0])[j][k]) + ((y_mat[j+1])[k][j]));
        }
        c_scalars[j+1] += ((y_mat[((j+2)%3)+1])[((j+1)%3)][((j+2)%3)]);
        c_scalars[j+1] += ((y_mat[((j+1)%3)+1])[((j+2)%3)][((j+1)%3)]);
      }
        // accumulate this corner's contribution to the numerator
        // and the denominator...
      for(j=1;j<local_matrix_map_used;++j){
          //std::cout<<"c_k ("<<j<<") ="<<c_scalars[j]<<"\n";
          //std::cout<<"x_k ("<<j<<") ="<<verts[elems_verts[ (size_t) local_matrix_map[j]]]<<"\n";
      
        new_position+=verts[elems_verts[ (size_t) local_matrix_map[j]]]
          *c_scalars[j];
      }
//     std::cout<<"c_k (0) ="<<c_scalars[0]<<"\n";
      scale_value+=c_scalars[0];
    
    }
    if(scale_value==0.0){
      MSQ_SETERR(err)("Invalid accummulation          .\n",
                      MsqError::INVALID_STATE);
      return false;
    }
      //divide the new position by the denominator and get the
      // negative sign into the equation.
    new_position/=(-1.0*scale_value);
      //debug
      //MSQ_DBGOUT(1) << "Original position "<<verts[free_index]<<"\n";
      //MSQ_DBGOUT(1) << "New position "<<new_position<<"\n";
      //actually set the new position
    verts[free_index].set(new_position);
  
    return true;
  }

} // namespace Mesquite
