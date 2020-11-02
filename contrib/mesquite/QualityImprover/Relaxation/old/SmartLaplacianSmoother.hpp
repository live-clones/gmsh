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
  \file   SmartLaplacianSmoother.hpp
  \brief  

  The SmartLaplacianSmoother Class implements the SmartLaplacian smoothing
  for a patch with one free vertex. 

  \author Michael Brewer
  \author Thomas Leurent
  \date   2002-01-17
*/

#ifndef Mesquite_SmartLaplacianSmoother_hpp 
#define Mesquite_SmartLaplacianSmoother_hpp

#include "Mesquite.hpp"
#include "LaplacianCommon.hpp"

namespace MESQUITE_NS
{
  class MsqError;
  class PatchData;
  class ObjectiveFunction;
  class QualityMetric;

  /*! \class SmartLaplacianSmoother
    Moves free center vertex to the average of the neighboring vertices if
    that move does not decrease the given objective function value.
   */  
  class SmartLaplacianSmoother : public LaplacianCommon 
  {
  public:
    MESQUITE_EXPORT SmartLaplacianSmoother(ObjectiveFunction *obj_func, 
                                           MsqError &err);
    MESQUITE_EXPORT ~SmartLaplacianSmoother();
    virtual std::string get_name() const;
  protected:
    virtual void initialize(PatchData &pd, MsqError &err);
    virtual void optimize_vertex_positions(PatchData &pd,
                                         MsqError &err);
    virtual void initialize_mesh_iteration(PatchData &pd, MsqError &err);
    virtual void terminate_mesh_iteration(PatchData &pd, MsqError &err);
    virtual void cleanup();

  private:
    QualityMetric* edgeQM;

    ObjectiveFunction* defaultObjFunc;

  };

  

  
}

#endif
