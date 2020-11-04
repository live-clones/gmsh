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
  \file   SmartLaplacianSmoother.cpp
  \brief  

  The SmartLaplacianSmoother Class is the concrete class
  that performs Smart Laplacian Smoothing

  \author Michael Brewer
  \author Thomas Leurent
  \date   2002-01-17
*/

#include "Mesquite_SmartLaplacianSmoother.hpp"
#include "Mesquite_LaplacianSmoother.hpp"
#include "Mesquite_MsqDebug.hpp"
#include "Mesquite_LInfTemplate.hpp"
#include "Mesquite_IdealWeightInverseMeanRatio.hpp"

#include <vector>
using std::vector;

namespace MESQUITE_NS {

std::string SmartLaplacianSmoother::get_name() const
  { return "SmartLaplacianSmoother"; }

SmartLaplacianSmoother::SmartLaplacianSmoother(ObjectiveFunction* obj_func,
                                               MsqError &err) 
  : LaplacianCommon( obj_func ? obj_func : 
                    (defaultObjFunc = new LInfTemplate(
                     (edgeQM = new IdealWeightInverseMeanRatio(err))))) 
{
  if (obj_func) {
    edgeQM = 0;
    defaultObjFunc = 0;
  }
}  

SmartLaplacianSmoother::~SmartLaplacianSmoother() 
{
  delete edgeQM;
  delete defaultObjFunc;
}    
  
void SmartLaplacianSmoother::initialize(PatchData& /*pd*/, MsqError& /*err*/)
{
 
}

void SmartLaplacianSmoother::initialize_mesh_iteration(PatchData &/*pd*/,
                                                  MsqError &/*err*/)
{
  //  cout << "- Executing SmartLaplacianSmoother::iteration_complete()\n";
}

/*! \todo Michael:  optimize_vertex_position is probably not implemented
  in an optimal way.  We used to use all of the vertices in
  the patch as 'adjacent' vertices.  Now we call get_adjacent_vertex_indices.
  We could use a VERTICES_ON_VERTEX type of patch or a global patch?
*/
void SmartLaplacianSmoother::optimize_vertex_positions(PatchData &pd, 
                                                MsqError &err)
{
    //default the laplacian smoother to 3 even for 2-d elements.
    //int dim = get_mesh_set()->space_dim();
  size_t dim = 3;
  MsqVertex* verts=pd.get_vertex_array(err);  MSQ_ERRRTN(err);
    //the objective function evaluator
  OFEvaluator& obj_func = get_objective_function_evaluator();
    //variables for the function values.
  double orig_val=0;
  double mod_val=0;
    //compute the original function value and check validity
  bool valid_flag = obj_func.evaluate(pd,orig_val,err);  MSQ_ERRRTN(err);
  // does the Laplacian smoothing
  MsqFreeVertexIndexIterator free_iter(pd, err);  MSQ_ERRRTN(err);
  free_iter.reset();
  free_iter.next();
    //m is the free vertex.
  size_t m=free_iter.value();
  vector<size_t> vert_indices;
  vert_indices.reserve(25);
    //get vertices adjacent to vertex m
  pd.get_adjacent_vertex_indices(m,vert_indices,err);  MSQ_ERRRTN(err);
    //move vertex m
    //save the original position of the free vertex
  Vector3D orig_position(verts[m]);
    //smooth the patch
  centroid_smooth_mesh(pd, vert_indices.size(), vert_indices,
                       m, dim, err); MSQ_ERRRTN(err);
    //snap vertex m to domain
  pd.snap_vertex_to_domain(m,err);  MSQ_ERRRTN(err);
    //if the original function val was invalid, then we allow the move
    //But, if it wasn valid, we need to decide.
  if(valid_flag){
      //compute the new value
    valid_flag = obj_func.evaluate(pd,mod_val,err);  MSQ_ERRRTN(err);
      //if the new value is worse the original OR if the new value is not
      //valid (we already know the original value was valid by above) then
      //we don't allow the move.
    if(!valid_flag || mod_val>orig_val){
        //move the vert back to where it was.
      verts[m]=orig_position;
        //PRINT_INFO("\norig = %f, new = %f, new valid = %d",orig_val,mod_val,valid_flag);
    }
    
  }
  
}
  
void SmartLaplacianSmoother::terminate_mesh_iteration(PatchData &/*pd*/,
                                                 MsqError &/*err*/)
{
  //  cout << "- Executing SmartLaplacianSmoother::iteration_complete()\n";
}
  
void SmartLaplacianSmoother::cleanup()
{
  //  cout << "- Executing SmartLaplacianSmoother::iteration_end()\n";
}
  

}
