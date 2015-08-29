// @licstart revoropt
// This file is part of Revoropt, a library for the computation and 
// optimization of restricted Voronoi diagrams.
//
// Copyright (C) 2013 Vincent Nivoliers <vincent.nivoliers@univ-lyon1.fr>
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
// @licend revoropt
#ifndef _REVOROPT_MESH_IMPORT_DEF_HPP_
#define _REVOROPT_MESH_IMPORT_DEF_HPP_

#include "import_fwd.hpp"

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

namespace Revoropt {

//loading obj meshes
template< typename MeshBuilder >
void import_obj(const std::string& filename, MeshBuilder* builder) {
  //vertex dimension
  enum { Dim = MeshBuilder::VertexDim } ;

  //open the file
  std::ifstream file(filename) ;
  if(!file.is_open()) {
    std::cerr << "Mesh file could not be opened" << std::endl ;
    return ;
  }

  //array used to store face indices for each face
  std::vector<unsigned int> face_indices ;

  //read the vertices and faces
  unsigned int fcount = 0 ;
  std::string line ;
  while(file.good()) {
    //get a new line
    std::getline(file,line) ;

    //get the line type
    std::stringstream line_stream(line) ;
    std::string elemtype ;
    std::getline(line_stream,elemtype,' ') ;
    if(elemtype == "v") {
      //line contains a vertex
      //append the coordinates to the vertex array
      double coord[Dim] ;
      for(int i=0; i<Dim; ++i) {
        line_stream >> coord[i] ;
      }
      builder->push_vertex(coord) ;
    } else if (elemtype == "f") {
      //line contains a face
      ++fcount ;
      //append the vertex indices to the array
      face_indices.resize(0) ;
      while(true) {
        std::string indices ;
        std::getline(line_stream,indices,' ') ;
        std::stringstream indices_stream(indices) ;
        std::string vertex_index ;
        std::getline(indices_stream,vertex_index,'/') ;
        std::stringstream vertex_index_stream(vertex_index) ;
        unsigned int index ;
        vertex_index_stream >> index ;
        if(line_stream.fail()) break ;
        face_indices.push_back(index-1) ;
      }
      builder->push_face(face_indices.data(), face_indices.size()) ;
    }
  }

  //close the file
  file.close() ;
}

} //end of namespace Revoropt

#endif
