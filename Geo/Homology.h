// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
// 
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
// 
// Contributed by Matti Pellikka.

#ifndef _HOMOLOGY_H_
#define _HOMOLOGY_H_

#include <sstream>
#include "CellComplex.h"

#if defined(HAVE_KBIPACK)

template <class TTypeA, class TTypeB>
bool convert(const TTypeA& input, TTypeB& output ){
   std::stringstream stream;
   stream << input;
   stream >> output;
   return stream.good();
}


class Homology
{
  private:
   CellComplex* _cellComplex;
   GModel* _model;
   
   bool _combine;
   int _omit;
   
  public:
   
   Homology(GModel* model, std::vector<int> physicalDomain, std::vector<int> physicalSubdomain);
   ~Homology(){ delete _cellComplex; }
   
   bool getCombine() { return _combine; }
   bool setCombine(bool combine) { _combine = combine; }
   
   void findGenerators(std::string fileName);
   void findThickCuts(std::string fileName);
      
   void swapSubdomain() { _cellComplex->swapSubdomain(); }

   int getOmit() {return _omit; }
   void setOmit(int omit) { 
     if(omit > _cellComplex->getDim() || omit < 0) {
       Msg::Error("Invalid number of dimensions to omit. Must be between 0 - %d.", _cellComplex->getDim());
       Msg::Warning("Set to omit 1 dimension.");
       _omit = 1;
     }
     else _omit = omit;
   }
};

#endif

#endif
