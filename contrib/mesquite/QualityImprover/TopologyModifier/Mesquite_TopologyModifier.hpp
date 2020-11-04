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
  \file   TopologyModifier.hpp
  \brief  

  The TopologyModifier Class is the base class for swapping algorythms etc ...

  \author Thomas Leurent
  \date   2002-01-17
*/

#ifndef Mesquite_TopologyModifier_hpp 
#define Mesquite_TopologyModifier_hpp

#include "Mesquite.hpp"
#include "QualityImprover.hpp"

namespace MESQUITE_NS
{
  class MsqError;

  /*   */ 
  class TopologyModifier : public QualityImprover 
  {
  public:
    // virtual destructor ensures use of polymorphism during destruction
    virtual ~TopologyModifier()
      {};
    
    virtual double loop_over_mesh( Mesh* mesh,
                                   MeshDomain* domain,
                                   MsqError &err);

  protected:
    TopologyModifier();

    virtual void iteration_begin() = 0;
    virtual void optimize_connectivity() = 0;
    virtual void iteration_complete() = 0;
    virtual void iteration_end() = 0;

  };
}

#endif
