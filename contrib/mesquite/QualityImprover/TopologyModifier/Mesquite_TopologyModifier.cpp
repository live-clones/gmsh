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
  \file   TopologyModifier.cpp
  \brief  

  The VertexMover Class is the base class for swapping algorythms etc... 

  \author Thomas Leurent
  \date   2002-01-17
*/


#include "Mesquite_TopologyModifier.hpp"


using namespace Mesquite;

double TopologyModifier::loop_over_mesh( Mesh* /*mesh*/,
                                         MeshDomain* /*domain*/,
                                         MsqError &/*err*/)
{
  // TODO: for all vertices
//  cout << "o Executing TopologyModifier::loop_over_mesh()\n"
//       << "  Here we will be looping over elements\n";
  this->iteration_begin();
  this->optimize_connectivity();
  this->iteration_complete();
  this->iteration_end();

  return 0.;
}
