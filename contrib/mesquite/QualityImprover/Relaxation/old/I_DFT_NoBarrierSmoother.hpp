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
  \file   I_DFT_NoBarrierSmoother.hpp
  \brief  

  The I_DFT_NoBarrierSmoother Class implements the point relaxation
  method of optimizing I_DFT_NoBarrier.

  \author Michael Brewer
  \date   2005-05-02
*/

#ifndef Mesquite_I_DFT_NoBarrierSmoother_hpp 
#define Mesquite_I_DFT_NoBarrierSmoother_hpp

#include "Mesquite.hpp"
#include "LaplacianCommon.hpp"

#include <vector>

namespace MESQUITE_NS
{

  /*! \class I_DFT_NoBarrierSmoother
    Iteratively moves the center vertex to optimize w.r.t. I_DFT_NoBarrier.
    
    NOTE (IMPORTANT):  This smoother currently only works for tet elements.
   */  
  class I_DFT_NoBarrierSmoother : public LaplacianCommon 
  {
  public:
    I_DFT_NoBarrierSmoother();
    virtual ~I_DFT_NoBarrierSmoother();
    virtual std::string get_name() const;
  protected:
    virtual void initialize(PatchData &pd, MsqError &err);
    virtual void optimize_vertex_positions(PatchData &pd,
                                         MsqError &err);
    virtual void initialize_mesh_iteration(PatchData &pd, MsqError &err);
    virtual void terminate_mesh_iteration(PatchData &pd, MsqError &err);
    virtual void cleanup();

  private:
      //QualityMetric* edgeQM;
    
    bool i_dft_no_barrier_smooth_mesh(PatchData &pd, size_t free_index,
                                      MsqError &err);
    
  };

  
  

  
}

#endif
