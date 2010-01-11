//
// Description : XFEM elasticity solver main
//
//
// Author:  <Eric Bechet>::<Boris Sedji>,  01/2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "Gmsh.h"
#include "elasticitySolver.h"
#include "PView.h"
#include "PViewData.h"
#include "highlevel.h"
#include "groupOfElements.h"
#include <iterator>

#include "Classes/XFEMelasticitySolver.cpp"



int main (int argc, char* argv[])
{

    if (argc < 2)
    {
        printf("usage : elasticity input_file_name yeahhh \n");
        return -1;
    }

    GmshInitialize(argc, argv);
    // globals are still present in Gmsh

    // instanciate a solver
    XFEMelasticitySolver mySolver (1000);

    // read some input file
    mySolver.readInputFile(argv[1]);

    // solve the problem
    mySolver.solve();

    PView *pv = mySolver.buildDisplacementView("displacement");
    pv->getData()->writeMSH("disp.msh", false);
    delete pv;
    pv = mySolver.buildElasticEnergyView("elastic energy");
    pv->getData()->writeMSH("energ.msh", false);
    delete pv;

    // stop gmsh
    GmshFinalize();

}

