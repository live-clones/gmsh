#include <vector>
#include <cmath>
#include <iostream>
#include "tools.hxx"

namespace tools{
  void normalize(std::vector<double> &v){
    double norm = 0.0;
    for(size_t k=0; k<v.size(); k++)
      norm += v[k]*v[k];
    norm = sqrt(norm);
    if(norm > 1e-12){
      for(size_t k=0; k<v.size(); k++)
	v[k] /= norm;
    }
  }

  void scale(std::vector<double> &v, double scaling){
    for(size_t k=0; k<v.size(); k++)
      v[k] *= scaling;
  }
  
  std::vector<double> getNormalizedVector(const std::vector<double> &v){
    std::vector<double> vCopy = v;
    normalize(vCopy);
    return vCopy;
  }

  std::vector<double> crossprod(const std::vector<double> &v0, const std::vector<double> &v1){
    std::vector<double> res{0.0, 0.0, 0.0};
    if(v0.size() == 3 && v1.size() == 3){
      res[0] = v0[1]*v1[2] - v0[2]*v1[1];
      res[1] = v0[2]*v1[0] - v0[0]*v1[2];
      res[2] = v0[0]*v1[1] - v0[1]*v1[0];
    }
    else{
      std::cout << "TOOLS: Wrong use of crossprod" << std::endl;
      exit(0);
    }
    return res;
  }

  double dotprod(const std::vector<double> &v0, const std::vector<double> &v1){
    double val = 0.0;
    for(size_t k=0; k<v0.size(); k++)
      val += v1[k]*v0[k];
    return val;
  }

  double norm(const std::vector<double> &v){
    double norm = 0.0;
    for(size_t k=0; k<v.size(); k++)
      norm += v[k]*v[k];
    norm = sqrt(norm);
    return norm;
  }

  double norm(const double *v, const size_t &size){
    double norm = 0.0;
    for(size_t k=0; k<size; k++)
      norm += v[k]*v[k];
    norm = sqrt(norm);
    return norm;
  }

  double distance(const std::vector<double> &v0, const std::vector<double> &v1){
    std::vector<double> diff;
    diff.resize(v0.size(), 0.0);
    for(size_t k=0; k<v0.size(); k++)
      diff[k] = v1[k] - v0[k];
    return norm(diff);
  }
}
