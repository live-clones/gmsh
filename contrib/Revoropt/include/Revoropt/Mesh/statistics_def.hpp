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
#ifndef _REVOROPT_MESH_STATISTICS_DEF_HPP_
#define _REVOROPT_MESH_STATISTICS_DEF_HPP_

#include <vector>
#include <iostream>
#include <Eigen/Dense>

namespace Revoropt {

/* Angles */

template<typename Mesh>
void face_angles( const Mesh* mesh, typename Mesh::Scalar* angles ) {
  //the angles array needs to have size mesh->face_vertices_size()
  //scalar type
  typedef typename Mesh::Scalar Scalar ;
  //vector type
  typedef Eigen::Matrix<Scalar,Mesh::VertexDim,1> Vector ;
  //iterate on faces
  for(unsigned int f = 0; f < mesh->faces_size(); ++f) {
    //face size
    const unsigned int fsize = mesh->face_size(f) ;
    //vertices
    const unsigned int* fverts = mesh->face(f) ;
    //iterate on face vertices
    for(unsigned int v = 0; v < fsize; ++v) {
      const unsigned int previndex = fverts[(v+fsize-1)%fsize] ;
      const unsigned int currindex = fverts[ v               ] ;
      const unsigned int nextindex = fverts[(v      +1)%fsize] ;
      Eigen::Map<const Vector> vprev(mesh->vertex(previndex)) ;
      Eigen::Map<const Vector> vcurr(mesh->vertex(currindex)) ;
      Eigen::Map<const Vector> vnext(mesh->vertex(nextindex)) ;
      //normal weight for this vertex
      const Vector e1 = (vprev-vcurr) ;
      const Scalar e1_len = e1.norm() ;
      const Vector e2 = (vcurr-vnext) ;
      const Scalar e2_len = e2.norm() ;
      if(e1_len*e2_len != 0) {
        Scalar angle_cos = -e1.dot(e2)/(e1_len*e2_len) ;
        angle_cos = std::min(angle_cos,1.) ;
        angle_cos = std::max(angle_cos,-1.) ;
        const Scalar angle = acos(angle_cos) ;
        angles[mesh->face_offset(f)+v] = angle ;
      } else {
        angles[mesh->face_offset(f)+v] = 0 ;
      }
    }
  }
}

template<typename Mesh>
void triangle_quality( const Mesh* mesh, typename Mesh::Scalar* qualities ) {
  //the qualities array needs to have size mesh->faces_size()
  //scalar type
  typedef typename Mesh::Scalar Scalar ;
  //compute angles
  std::vector<Scalar> angles(mesh->face_vertices_size()) ;
  face_angles(mesh, angles.data()) ;
  //compute qualities
  for(unsigned int f = 0; f < mesh->faces_size(); ++f) {
    //face angles
    const Scalar* fangles = angles.data() + mesh->face_offset(f) ;
    //quality
    qualities[f] = 4*sin(fangles[0])*sin(fangles[1])*sin(fangles[2]) ;
    qualities[f] /= sin(fangles[0])+sin(fangles[1])+sin(fangles[2]) ;
  }
}

/* Edge lengths */
//inner edges are twice accounted for

template<typename Mesh>
void edge_lengths( const Mesh* mesh, typename Mesh::Scalar* lengths ) {
  //the lengths array needs to have size mesh->face_vertices_size()
  //scalar type
  typedef typename Mesh::Scalar Scalar ;
  //vector type
  typedef Eigen::Matrix<Scalar,Mesh::VertexDim,1> Vector ;
  //iterate on faces
  for(unsigned int f = 0; f < mesh->faces_size(); ++f) {
    //face size
    const unsigned int fsize = mesh->face_size(f) ;
    //vertices
    const unsigned int* fverts = mesh->face(f) ;
    //iterate on face vertices
    for(unsigned int v = 0; v < fsize; ++v) {
      const unsigned int currindex = fverts[ v         ] ;
      const unsigned int nextindex = fverts[(v+1)%fsize] ;
      Eigen::Map<const Vector> vcurr(mesh->vertex(currindex)) ;
      Eigen::Map<const Vector> vnext(mesh->vertex(nextindex)) ;
      //normal weight for this vertex
      const Vector e2 = (vcurr-vnext) ;
      lengths[mesh->face_offset(f)+v] = e2.norm() ;
    }
  }
}

/* Histogram */

template<typename Scalar>
void histogram( const Scalar* data, unsigned int size,
                Scalar min, Scalar max, unsigned int bins,
                unsigned int* output
              ) {
  //output must havs size bins
  const Scalar extent = max - min ;
  //reset the output
  std::fill(output, output+bins, 0) ;
  //fill the bins
  for(unsigned int i = 0; i < size; ++i) {
    const unsigned int bin = (unsigned int) ((data[i]-min)/extent*bins) ;
    ++output[bin] ;
  }
}

template<typename Scalar>
void histogram( const Scalar* data, unsigned int size,
                Scalar min, Scalar max, unsigned int bins,
                const char* filename
              ) {
  std::vector<Scalar> histogram(bins,0) ;
  const Scalar extent = max - min ;
  //fill the bins
  for(unsigned int i = 0; i < size; ++i) {
    const unsigned int bin = (unsigned int) ((data[i]-min)/extent*bins) ;
    ++histogram[bin] ;
  }
  //write the result
  std::ofstream file ;
  file.open(filename) ;
  for(unsigned int i = 0; i < bins; ++i) {
    file << min + i/((double)bins)*extent << " " << histogram[i] << std::endl ;
  }
  file.close() ;
}

} //end of namespace Revoropt

#endif
