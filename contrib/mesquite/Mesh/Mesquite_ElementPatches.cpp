/* ***************************************************************** 
    MESQUITE -- The Mesh Quality Improvement Toolkit

    Copyright 2006 Lawrence Livermore National Laboratory.  Under 
    the terms of Contract B545069 with the University of Wisconsin -- 
    Madison, Lawrence Livermore National Laboratory retains certain
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

    (2006) kraftche@cae.wisc.edu    

  ***************************************************************** */

#ifndef MSQ_ELEMENT_PATCHES_CPP
#define MSQ_ELEMENT_PATCHES_CPP

#include "Mesquite_ElementPatches.hpp"
#include "Mesquite_MeshInterface.hpp"
#include "Mesquite_MsqError.hpp"

namespace MESQUITE_NS {

ElementPatches::~ElementPatches() {}

void ElementPatches::get_patch_handles( 
                             std::vector<PatchHandle>& patch_handles_out,
                             MsqError& err )
{
  get_mesh()->get_all_elements( patch_handles_out, err ); MSQ_CHKERR(err);
}

void ElementPatches::get_patch( PatchHandle patch_handle,
                     std::vector<Mesh::ElementHandle>& elem_handles_out,
                     std::vector<Mesh::VertexHandle>& free_vertices_out,
                     MsqError& )
{
  elem_handles_out.clear();
  free_vertices_out.clear();
  elem_handles_out.push_back( patch_handle );
}

} // namespace Mesquite

#endif
