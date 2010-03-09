//
// C++ Interface: terms
//
// Description: Insertion of Interface Elements in GModel
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//


#ifndef GMODELDG_H_
#define GMODELDG_H_
#include "GModel.h"
#include "MInterfaceElement.h"
#include "DgC0PlateSolver.h" // remove if elasticfields is not pass to generateInterfaceElementsOnBoundary
#include "groupOfElements.h" // remove if elasticfields is not pass to generateInterfaceElementsOnBoundary
class GModelWithInterface : public GModel{

  protected :
    // Add Interface element to the GModel I keep the MInterfaceElement because there is no need of a GInterfaceElement
    // I use vector because I don't know how to use set
    std::vector<std::pair<int,MInterfaceElement> > interfaces; // TODO make a pair to take into account more than 1 elasticfield
    std::vector<std::pair<int,MInterfaceElement> > boundinter; // A different vector is used for boundary element of the interface

    // Store interface elements when I understand this operation
    // void _storeInterfaceElements(std::vector<std::map<int,MInterfaceElement> > & ie );

  public :
    // build function
    GModelWithInterface() : GModel(){};

    // return interface
    std::vector<MInterfaceElement*> getInterface(const int num_field){
      std::vector<MInterfaceElement*> vie;
      for(int i=0;i<interfaces.size();i++)
        if(interfaces[i].first == num_field) vie.push_back(&interfaces[i].second);
      return vie;
    }

    // Function reading the input .msh file
    int readMSH(const std::string &name);

    // Function to generate interface element on boundary
    void generateInterfaceElementsOnBoundary(const int &num_phys, std::vector<DGelasticField> elasticFields);

    // Return the boundary interfaceElement linked to an elasticField
    std::vector<MInterfaceElement*> getBoundInterface(const int num_field){
      std::vector<MInterfaceElement*> vie;
      for(int i=0;i<boundinter.size();i++)
        if(boundinter[i].first == num_field) vie.push_back(&boundinter[i].second);
      return vie;
    }
};


#endif // GMODELDG_H_
