// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
// 
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
// 
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

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

   std::vector<int> _domain;
   std::vector<int> _subdomain;
   
  public:
   
   Homology(GModel* model, std::vector<int> physicalDomain, std::vector<int> physicalSubdomain);
   ~Homology(){ delete _cellComplex; }
   
   // Find the generators/duals of homology spaces, or just compute the ranks of homology spaces
   void findGenerators(std::string fileName);
   void findDualGenerators(std::string fileName);
   void computeBettiNumbers();
   
   
   //void swapSubdomain() { _cellComplex->swapSubdomain(); }
   
   // Restore the cell complex to its original state before cell reductions
   void restoreHomology() { _cellComplex->restoreComplex(); }
   
   // Create a string describing the generator
   std::string getDomainString() {
     std::string domainString = "({";
     for(unsigned int i = 0; i < _domain.size(); i++){
       std::string temp = "";
       convert(_domain.at(i),temp);
       domainString += temp;
       if (_domain.size()-1 > i){ 
         domainString += ", ";
       }
     }
     domainString += "}";
     
     if(!_subdomain.empty()){
       domainString += ", {";
       
       for(unsigned int i = 0; i < _subdomain.size(); i++){
         std::string temp = "";
         convert(_subdomain.at(i),temp);
         domainString += temp;
         if (_subdomain.size()-1 > i){
           domainString += ", ";
         }
       } 
       domainString += "}";
       
     }
   domainString += ") ";
   return domainString;
   }
   
   int writeHeaderMSH(const std::string &name){  
       FILE *fp = fopen(name.c_str(), "w");
       if(!fp){
         Msg::Error("Unable to open file '%s'", name.c_str());
             printf("Unable to open file.");
             return 0;
       }
     fprintf(fp, "$MeshFormat\n2.1 0 8\n$EndMeshFormat\n");
     fclose(fp);
     return 1;
   }
};

#endif

#endif
