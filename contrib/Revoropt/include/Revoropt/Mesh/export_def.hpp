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
#ifndef _REVOROPT_MESH_EXPORT_DEF_HPP_
#define _REVOROPT_MESH_EXPORT_DEF_HPP_

#include "export_fwd.hpp"

#include <fstream>
#include <sstream>
#include <vector>
#include <map>

namespace Revoropt {

template<typename Mesh>
void export_obj( const Mesh* mesh, const std::string& filename ) {
  //typedefs
  enum { Dim = Mesh::VertexDim } ;
  typedef typename Mesh::Scalar Scalar ;

  //open file
  std::ofstream file ;
  file.open(filename) ;

  //output vertices
  for(unsigned int v = 0; v < mesh->vertices_size(); ++v) {
    file << "v " ;
    const Scalar* vertex = mesh->vertex(v) ;
    for(int d = 0; d < Dim; ++d) {
      file << vertex[d] << " " ;
    }
    file << std::endl ;
  }

  //output faces
  for(unsigned int f = 0; f < mesh->faces_size(); ++f) {
    file << "f " ;
    const unsigned int* face = mesh->face(f) ;
    for(unsigned int v = 0; v < mesh->face_size(f); ++v) {
      file << face[v]+1 << " " ;
    }
    file << std::endl ;
  }

  //close file
  file.close() ;
}

template<typename Mesh>
void export_colored_obj( const Mesh* mesh, 
                         const unsigned int* color_indices,
                         const double* colormap,
                         const std::string& basename 
                       ) {
  //typedefs
  enum { Dim = Mesh::VertexDim } ;
  typedef typename Mesh::Scalar Scalar ;

  //file names
  std::stringstream objfilename ;
  objfilename << basename << ".obj" ;
  std::stringstream mtlfilename ;
  mtlfilename << basename << ".mtl" ;

  //open obj file
  std::ofstream objfile ;
  objfile.open(objfilename.str().c_str()) ;

  //provide material file name
  objfile << "mtllib " << mtlfilename.str() << std::endl ;

  //output vertices
  for(unsigned int v = 0; v < mesh->vertices_size(); ++v) {
    objfile << "v " ;
    const Scalar* vertex = mesh->vertex(v) ;
    for(int d = 0; d < Dim; ++d) {
      objfile << vertex[d] << " " ;
    }
    objfile << std::endl ;
  }

  //sorting faces by color index
  typedef std::map< unsigned int, std::vector<unsigned int> > FaceMap ;
  FaceMap groups ;
 
  for(unsigned int f = 0; f < mesh->faces_size(); ++f) {
    groups[color_indices[f]].push_back(f) ;
  }

  //output faces by groups
  for(FaceMap::iterator it = groups.begin(); it != groups.end(); ++it) {
    objfile << "g " << basename << "_material_" << it->first << std::endl ;
    objfile << "usemtl material_" << it->first << std::endl ;
    std::vector<unsigned int>& f_indices = it->second ;
    for(unsigned int f = 0; f < f_indices.size(); ++f) {
      objfile << "f " ;
      const unsigned int* face = mesh->face(f_indices[f]) ;
      for(unsigned int v = 0; v < mesh->face_size(f_indices[f]); ++v) {
        objfile << face[v]+1 << " " ;
      }
      objfile << std::endl ;
    }
  }

  //close obj file
  objfile.close() ;

  //open mtl file
  std::ofstream mtlfile ;
  mtlfile.open(mtlfilename.str().c_str()) ;

  //output materials
  for(FaceMap::iterator it = groups.begin(); it != groups.end(); ++it) {
    mtlfile << "newmtl material_" << it->first << std::endl ;
    mtlfile << "Ns 100" << std::endl ;
    mtlfile << "Ka 0.000000 0.000000 0.000000" << std::endl ;
    //color
    mtlfile << "Kd " 
            << colormap[3*it->first  ] << " "
            << colormap[3*it->first+1] << " "
            << colormap[3*it->first+2] << std::endl ;
    mtlfile << "Ks 0.000000 0.000000 0.000000" << std::endl ;
    mtlfile << "Ni 1.000000" << std::endl ;
    //mtlfile << "d 1.000000" << std::endl ;
    mtlfile << "illum 1" << std::endl ;
  }
}

} //end of namespace Revoropt

#endif
