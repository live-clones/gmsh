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
#include "ChainComplex.h"

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
   
   // base cell complex and the model of the homology computation
   CellComplex* _cellComplex;
   GModel* _model;

   // domain and the relative subdomain of the homology computation
   std::vector<int> _domain;
   std::vector<int> _subdomain;

   // generator chains
   std::vector<Chain*> _generators[4];
   
  public:
   
   Homology(GModel* model, std::vector<int> physicalDomain, std::vector<int> physicalSubdomain);
   ~Homology(){ 
     delete _cellComplex; 
     for(int i = 0; i < 4; i++) {
       for(int j = 0; j < _generators[i].size(); j++){
         Chain* chain = _generators[i].at(j);
         //_model->deletePhysicalGroup(chain->getDim(), chain->getNum());
         delete chain;
       }
     }
   }
   
   // Find the generators/duals of homology spaces, or just compute the ranks of homology spaces
   void findGenerators(std::string fileName);
   void findDualGenerators(std::string fileName);
   void computeBettiNumbers();
   
   
   //void swapSubdomain() { _cellComplex->swapSubdomain(); }
   
   // Restore the cell complex to its original state before cell reductions
   void restoreHomology() { 
     _cellComplex->restoreComplex();
     for(int i = 0; i < 4; i++) _generators[i].clear();
   }
   
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
   
   // create PViews of the generators
   void createPViews(){
     for(int i = 0; i < 4; i++){
       for(int j = 0; j < _generators[i].size(); j++){
         Chain* chain = _generators[i].at(j);
         chain->createPView();
       }
     }
   }
   
   // write the generators to a file
   bool writeGeneratorsMSH(std::string fileName, bool binary=false){
     if(!_model->writeMSH(fileName, 2.0, binary)) return false;
     /*
     for(int i = 0; i < 4; i++){
       for(int j = 0; j < _generators[i].size(); j++){
         Chain* chain = _generators[i].at(j);
         if(!chain->writeChainMSH(fileName)) return false;
       }
     }*/
     Msg::Info("Wrote homology computation results to %s.", fileName.c_str());
     printf("Wrote homology computation results to %s. \n", fileName.c_str());
     
     return true;
   }
   
};

#endif

#endif
