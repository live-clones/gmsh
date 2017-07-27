#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>

#include "Gmsh.h"
#include "GModel.h"
#include "MElement.h"

#ifdef PARALLEL
    #include <mpi.h>
    #include "main_mpi.h"
#else
    #include "metis.h"
#endif

#include "graph.h"
#include "topology.h"
#include "io.h"

using namespace SEQ;

int main(int argc, char **argv)
{
#ifdef PARALLEL
    int nbproc, myrank;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    MPI_Comm_size(MPI_COMM_WORLD, &nbproc);
    
    clock_t t1, t2;
    if(myrank == 0)
    {
        std::cout << "#############################################################################" << std::endl;
        std::cout << "#                                                                           #" << std::endl;
        std::cout << "#                         #   #  #####   ####  #   #                        #" << std::endl;
        std::cout << "#                         ## ##  #      #      #   #                        #" << std::endl;
        std::cout << "#                         # # #  ####   #####  #####                        #" << std::endl;
        std::cout << "#                         #   #  #          #  #   #                        #" << std::endl;
        std::cout << "#                         #   #  #####  ####   #   #                        #" << std::endl;
        std::cout << "#                                                                           #" << std::endl;
        std::cout << "#                                                                           #" << std::endl;
        std::cout << "#  ####    ###   #####  #####  ###  #####  ###   ###   #   #  #####  #####  #" << std::endl;
        std::cout << "#  #   #  #   #  #   #    #     #     #     #   #   #  ##  #  #      #   #  #" << std::endl;
        std::cout << "#  ####   #####  #####    #     #     #     #   #   #  # # #  ####   #####  #" << std::endl;
        std::cout << "#  #      #   #  # ##     #     #     #     #   #   #  # # #  #      # ##   #" << std::endl;
        std::cout << "#  #      #   #  #   #    #    ###    #    ###   ###   #  ##  #####  #   #  #" << std::endl;
        std::cout << "#                                                                           #" << std::endl;
        std::cout << "####################################################### Parallel version ####" << std::endl << std::endl;
        
        if(argc < 2)
        {
            std::cout << "Arguments missing! Syntaxe :" << std::endl;
            std::cout << argv[0] << " \"mesh.msh\" \"nbrPartitions\"" << std::endl;
            MPI_Finalize();
            return 0;
        }
        
        if(atoi(argv[2]) < 1)
        {
            std::cout << "The number of partition must be greater than zero!" << std::endl;
            MPI_Finalize();
            return 0;
        }
        t1 = clock();
    }
    
    MPI_Barrier(MPI_COMM_WORLD);
    GmshInitialize(argc, argv);
    main_mpi(nbproc, myrank, argv[1], atoi(argv[2]));
    MPI_Barrier(MPI_COMM_WORLD);
    GmshFinalize();
    
    if(myrank == 0)
    {
        t2 = clock();
        float temps = (float)(t2-t1)/CLOCKS_PER_SEC;
        
        std::cout << "-> Partition done in " << temps << "seconds" << std::endl;
        
        std::ofstream time("time.txt", std::ofstream::app);
        time << temps << std::endl;
        time.close();
    }
    MPI_Finalize();
#else
    std::cout << "#############################################################################" << std::endl;
    std::cout << "#                                                                           #" << std::endl;
    std::cout << "#                         #   #  #####   ####  #   #                        #" << std::endl;
    std::cout << "#                         ## ##  #      #      #   #                        #" << std::endl;
    std::cout << "#                         # # #  ####   #####  #####                        #" << std::endl;
    std::cout << "#                         #   #  #          #  #   #                        #" << std::endl;
    std::cout << "#                         #   #  #####  ####   #   #                        #" << std::endl;
    std::cout << "#                                                                           #" << std::endl;
    std::cout << "#                                                                           #" << std::endl;
    std::cout << "#  ####    ###   #####  #####  ###  #####  ###   ###   #   #  #####  #####  #" << std::endl;
    std::cout << "#  #   #  #   #  #   #    #     #     #     #   #   #  ##  #  #      #   #  #" << std::endl;
    std::cout << "#  ####   #####  #####    #     #     #     #   #   #  # # #  ####   #####  #" << std::endl;
    std::cout << "#  #      #   #  # ##     #     #     #     #   #   #  # # #  #      # ##   #" << std::endl;
    std::cout << "#  #      #   #  #   #    #    ###    #    ###   ###   #  ##  #####  #   #  #" << std::endl;
    std::cout << "#                                                                           #" << std::endl;
    std::cout << "#############################################################################" << std::endl << std::endl;
    
    if(argc < 2)
    {
        std::cout << "Arguments missing! Syntaxe :" << std::endl;
        std::cout << argv[0] << " \"mesh.msh\" \"nbrPartitions\"" << std::endl;
        return 0;
    }
    
    if(atoi(argv[2]) < 1)
    {
        std::cout << "The number of partition must be greater than zero!" << std::endl;
        return 0;
    }
    
    float temps;
    clock_t t1, t2;
    t1 = clock();
    
    GmshInitialize(argc, argv);
    GModel *m = new GModel();
    std::cout << "Reading msh file... " << std::flush;
    m->readMSH(argv[1]);
    std::cout << "Done!" << std::endl;

    const int numElements = m->getNumMeshElements();
    const int numVertices = m->getNumMeshVertices();
    
    idx_t nparts = atoi(argv[2]);
    
    if(nparts > 1)
    {
        idx_t *epart = new idx_t[numElements];
        idx_t *npart = new idx_t[numVertices];
        int* eptr = new int[numElements+1];
        int* eind = NULL;
        int *metisToGmshIndex = new int[numElements];
        
        std::cout << "Creating Metis structure... " << std::flush;
        GModelToGraph(m, eptr, &eind, metisToGmshIndex);
        std::cout << "Done!" << std::endl;
        
        std::cout << "Mesh partitioning... " << std::flush;
        idx_t objval;
        idx_t ncommon = m->getDim();
        idx_t options[METIS_NOPTIONS];
        METIS_SetDefaultOptions(options);
    
        const int error = METIS_PartMeshDual((idx_t*)&numElements, (idx_t*)&numVertices, (idx_t*)eptr, (idx_t*)eind, NULL, NULL, &ncommon, &nparts, NULL, options, &objval, epart, npart);
    
        switch(error)
        {
            case METIS_OK:
                std::cout << "Done!" << std::endl;
                break;
            case METIS_ERROR_INPUT:
                std::cout << "Metis error (input)!" << std::endl;
                return 0;
                break;
            case METIS_ERROR_MEMORY:
                std::cout << "Metis error (memory)!" << std::endl;
                return 0;
                break;
            case METIS_ERROR:
                std::cout << "Metis error!" << std::endl;
                return 0;
                break;
            default:
                std::cout << "Error!" << std::endl;
                return 0;
                break;
        }

        for(unsigned int i = 0; i < numElements; i++)
        {
            m->getMeshElementByTag(metisToGmshIndex[i])->setPartition(epart[i]);
        }
        
        delete[] eptr;
        delete[] eind;
        delete[] epart;
        delete[] npart;
        delete[] metisToGmshIndex;
    }
    
    std::cout << "Creating new GModel... " << std::flush;
    GModel* global = new GModel();
    std::vector<GModel*> models = createNewModels(m, global, nparts);
    std::cout << "Done!" << std::endl;
    
    std::cout << "Assign mesh vertices to models... " << std::flush;
    for (unsigned int i = 0; i < nparts; i++)
    {
        assignMeshVerticesToModel(models[i]);
    }
    assignMeshVerticesToModel(global);
    std::cout << "Done!" << std::endl;
    
    std::cout << "Creating new elements... " << std::endl;
    createPartitionBoundaries(global, models);
    std::cout << "Done!" << std::endl;
    
    std::cout << "Writing partition meshes... " << std::flush;
    writeModels(models);
    std::cout << "Done!" << std::endl;
    
    std::cout << "Writing global mesh... " << std::flush;
    global->writeMSH("global.msh", 3.0);
    std::cout << "Done!" << std::endl;
    
    std::cout << "Writing .pro file... " << std::flush;
    writeProFile(global, nparts);
    std::cout << "Done!" << std::endl;
    
    freeModels(models, global);

    delete m;
    GmshFinalize();
    
    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    
    std::cout << "-> Partition done in " << temps << "seconds" << std::endl;
    
    std::ofstream time("time.txt", std::ofstream::app);
    time << temps << std::endl;
    time.close();
#endif
    
    return 0;
}
