//
// Description :
//
//
// Author:  <Boris Sedji>,  01/2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "GModel.h"
#include "Gmsh.h"
#include "elasticitySolver.h"
#include "PView.h"
#include "PViewData.h"
#include "highlevel.h"
#include "groupOfElements.h"
#include <iterator>


#include "Classes/OctreeSolver.cpp"



int main (int argc, char* argv[])
{


//
    if (argc < 2)
    {
        printf("usage : elasticity input_file_name.msh \n");
        return -1;
    }

    // globals are still present in Gmsh
    GmshInitialize(argc, argv);

    OctreeSolver mySolver(1000);

    mySolver.readInputFile(argv[1]);

    // solve the problem
    mySolver.solve();
//
    PView *pv = mySolver.buildDisplacementView("displacement");
    pv->getData()->writeMSH("disp.msh", false);
    delete pv;
    pv = mySolver.buildElasticEnergyView("elastic energy");
    pv->getData()->writeMSH("energ.msh", false);
    delete pv;

    // stop gmsh
    GmshFinalize();

//
//
//  // what is the input file ?
//
//  if (argc != 2){
//    printf("Input file missing...\n");
//    return -1;
//  }
//
//  // globals are still present in Gmsh
//
//  GmshInitialize(argc, argv);
//
//  // declare a GModel
//
//  GModel *m = new GModel();
//
//  // read from input file
//
//  m->readMSH(argv[1]);
//
//  // number of elements
//
//  int nbr_Elements;
//  nbr_Elements = m->getNumMeshElements();
//  std::cout<< "\nLe nombre d'éléments du modèle non coupé est " << nbr_Elements;
//
//  // level set plane definition
//
//  double a(0.), b(1.), c(0.), d(-300);   // normal vector and distance
//  int n(1);  // tag
//
//  gLevelset *ls = new gLevelsetPlane(a, b, c, d, n); // reference argument
//
//  // cut model
//
//  GModel *mm1 = m->buildCutGModel(ls);
//
//  // save cut model in a file by the name of uncut + "_cut"
//
//  std::string ModelName = argv[1] ;
//  ModelName.erase(ModelName.find(".",0),4);
//  ModelName.insert(ModelName.length(),"_cut.msh");
//  mm1->writeMSH(ModelName,2.1,false,false);
//
//
//  delete m;
//
//  // stop gmsh
//
//  GmshFinalize();

//




}

