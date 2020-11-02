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
#ifndef MESQUITE_PARAMETER_SET_HPP
#define MESQUITE_PARAMETER_SET_HPP


#include <cstddef>

#include "Mesquite.hpp"
#include "Mesquite_MsqError.hpp"

namespace MESQUITE_NS
{
  
  class ParameterSet
  {
  public:
    ParameterSet();
    ~ParameterSet();
    
    void add_int_parameter(const char* name,
                           int initial_value, MsqError &err);
    void set_int_parameter(const char* name,
                           int value, MsqError &err);
    void get_int_parameter(const char* name,
                           int* value, MsqError &err);
    
    void remove_parameter(const char* name, MsqError &err);
    
  private:
    
    struct ParameterRecord
    {
      enum ParameterType
      {
        MSQ_INT,
        MSQ_DBL,
        MSQ_PTR,
        MSQ_STRING,
        MSQ_BOOL
      };

      union ParameterValue
      {
        int intVal;
        double dblVal;
        void* ptrVal;
        char* strVal;
        bool boolVal;
      };

      char* name;
      ParameterType type;
      ParameterValue value;
    };
    
    ParameterRecord* mParameterArray;
    std::size_t mNumParameters;
    
      // returns the 0-based index of where the parameter
      // with the given name can be found in mParameterArray,
      // or mNumParameters if it can't be found.
    std::size_t get_parameter_index(const char* name, MsqError &err);
    
    void generic_add_parameter(const char* name, MsqError &err);
  };

}

#endif
