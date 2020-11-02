/* ***************************************************************** 
    MESQUITE -- The Mesh Quality Improvement Toolkit

    Copyright 2005 Lawrence Livermore National Laboratory.  Under 
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


/** \file ArrayIterator.hpp
 *  \brief Provide default implementation of Mesquite::Mesh iterators.
 *  \author Jason Kraftcheck 
 */

#ifndef MSQ_ARRAY_ITERATOR_HPP
#define MSQ_ARRAY_ITERATOR_HPP

#include "Mesquite.hpp"
#include "Mesquite_MeshInterface.hpp"
#include <vector>

namespace MESQUITE_NS {

class MsqError;

/** Default implementation of Mesh::EntityIterator.
  */
class ArrayIterator: public EntityIterator 
{
public:
  virtual ~ArrayIterator();
  virtual void restart();
  virtual Mesh::EntityHandle operator*() const;
  virtual void operator++();
  virtual bool is_at_end();
protected:
  std::vector<Mesh::EntityHandle> mArray;
  std::vector<Mesh::EntityHandle>::iterator mIter;
};

/** Default implementation of Mesh::VertexIterator.
  * Retreives array of all vertices and iterates over resulting array.
  */
class VertexArrayIterator : public ArrayIterator
{
public:
  VertexArrayIterator( Mesh* meshInterface, MsqError& err );
};

/** Default implementation of Mesh::ElementIterator.
  * Retreives array of all vertices and iterates over resulting array.
  */
class ElementArrayIterator : public ArrayIterator
{
public:
  ElementArrayIterator( Mesh* meshInterface, MsqError& err );
};


} // namespace Mesquite

#endif
