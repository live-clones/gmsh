#include <iostream>
#include <mpi.h>

#include "parmetis.h"
#include "Gmsh.h"
#include "GModel.h"
#include "MElement.h"

#include "main_mpi.h"
#include "graph.h"
#include "topology.h"
#include "topology_mpi.h"
#include "io.h"

using namespace PAR;

int main_mpi(int nbproc, int myrank, std::string path, int nparts)
{
    GModel *m = new GModel();
    if(myrank == 0) std::cout << "Reading msh file... " << std::flush;
    m->readMSH(path.c_str());
    if(myrank == 0) std::cout << "Done!" << std::endl;
    
    
    const int numElements = m->getNumMeshElements();
    const int numVertices = m->getNumMeshVertices();
    
    if(nparts > 1)
    {
        int *elmdist = new int[nbproc+1];
        elmdist[0] = 0;
        for(unsigned int i = 1; i < nbproc; i++)
        {
            elmdist[i] = i*numElements/nbproc;
        }
        elmdist[nbproc] = numElements;
        
        /*for(unsigned int i = 0; i < nbproc+1; i++)
        {
            if(myrank == 0) std::cout << elmdist[i] << std::endl;
        }*/
        
        
        int* eptr = new int[(elmdist[myrank+1]-elmdist[myrank])+1];
        int* eind = NULL;
        int *metisToGmshIndex = new int[elmdist[myrank+1]-elmdist[myrank]];
        
        if(myrank == 0) std::cout << "Creating Metis structure... " << std::flush;
        const int pos = GModelToGraph(m, eptr, &eind, metisToGmshIndex, elmdist);
        if(myrank == 0) std::cout << "Done!" << std::endl;
        
        
        if(myrank == 0) std::cout << "Mesh partitioning... " << std::flush;
        idx_t numflag = 0;
        idx_t ncommon = m->getDim();
        idx_t *xadj = NULL;
        idx_t *adjncy = NULL;
        MPI_Comm comm = MPI_COMM_WORLD;
        
        int error = ParMETIS_V3_Mesh2Dual((idx_t*)elmdist, (idx_t*)eptr, (idx_t*)eind, &numflag, &ncommon, &xadj, &adjncy, &comm);
        switch(error)
        {
            case METIS_OK:
                break;
            case METIS_ERROR:
                std::cout << "[rank " << myrank << "] Metis error!" << std::endl;
                MPI_Finalize();
                return 0;
                break;
        }
        
        idx_t objval;
        idx_t wgtflag = 0;
        idx_t ncon = 1;
        real_t *tpwgts = new real_t[nparts];
        for(unsigned int i = 0; i < nparts; i++)
        {
            tpwgts[i] = 1./nparts;
        }
        real_t ubvec[1];
        ubvec[0] = 1.05;
        idx_t options[3];
        options[0] = 0;
        idx_t* part = new idx_t[elmdist[myrank+1]-elmdist[myrank]];
        error = ParMETIS_V3_PartKway((idx_t*)elmdist, xadj, adjncy, NULL, NULL, &wgtflag, &numflag, &ncon, (idx_t*)&nparts, tpwgts, ubvec, options, &objval, part, &comm);
        
        /*for(unsigned int i = 0; i < elmdist[myrank+1]-elmdist[myrank]; i++)
        {
            std::cout << "[rank " << myrank << "] " << part[i] << std::endl;
        }*/
        
        switch(error)
        {
            case METIS_OK:
                if(myrank == 0) std::cout << "Done!" << std::endl;
                break;
            case METIS_ERROR:
                std::cout << "[rank " << myrank << "] Metis error!" << std::endl;
                MPI_Finalize();
                return 0;
                break;
        }
        
        MPI_Barrier(MPI_COMM_WORLD);
        for(unsigned int i = 0; i < nbproc; i++)
        {
            if(i == myrank)
            {
                for(unsigned int j = 0; j < elmdist[myrank+1]-elmdist[myrank]; j++)
                {
                    m->getMeshElementByTag(metisToGmshIndex[j])->setPartition(part[j]);
                    
                    for(unsigned int k = 0; k < nbproc; k++)
                    {
                        if(k != myrank)
                        {
                            //element tag
                            MPI_Send(&metisToGmshIndex[j], 1, MPI_INT, k, 1, MPI_COMM_WORLD);
                            //partition
                            MPI_Send(&part[j], 1, MPI_INT, k, 2, MPI_COMM_WORLD);
                        }
                    }
                }
            }
            else
            {
                for(unsigned int j = 0; j < elmdist[i+1]-elmdist[i]; j++)
                {
                    int tag = 0, numPart = 0;
                    MPI_Status status;
                    //element tag
                    MPI_Recv(&tag, 1, MPI_INT, i, 1, MPI_COMM_WORLD, &status);
                    //partition
                    MPI_Recv(&numPart, 1, MPI_INT, i, 2, MPI_COMM_WORLD, &status);
                    
                    m->getMeshElementByTag(tag)->setPartition(numPart);
                }
            }
        }
        
        delete[] eptr;
        delete[] eind;
        delete[] metisToGmshIndex;
        delete[] xadj;
        delete[] adjncy;
        delete[] tpwgts;
        delete[] part;
        delete[] elmdist;
    }
    
    std::vector<int> myPart;
    for(unsigned int i = 0; i < nparts; i++)
    {
        if((i+1)%nbproc == myrank)
        {
            myPart.push_back(i);
        }
    }
    
    if(myPart.size() != 0)
    {
        if(myrank == 0) std::cout << "Creating new GModel... " << std::flush;
        GModel* global = new GModel();
        std::vector<GModel*> models = createNewModels(m, global, nparts, myPart);
        if(myrank == 0) std::cout << "Done!" << std::endl;
            
        if(myrank == 0) std::cout << "Assign mesh vertices to models... " << std::flush;
        for (unsigned int i = 0; i < myPart.size(); i++)
        {
            SEQ::assignMeshVerticesToModel(models[i]);
        }
        if(myrank == 0) SEQ::assignMeshVerticesToModel(global);
        if(myrank == 0) std::cout << "Done!" << std::endl;
            
        if(myrank == 0) std::cout << "Creating new elements... " << std::endl;
        SEQ::createPartitionBoundaries(global, models);
        if(myrank == 0) std::cout << "Done!" << std::endl;
        
        if(myrank == 0) std::cout << "Writing partition meshes... " << std::flush;
        SEQ::writeModels(models);
        if(myrank == 0) std::cout << "Done!" << std::endl;
        
        if(myrank == 0) std::cout << "Writing global mesh... " << std::flush;
        if(myrank == 0) global->writeMSH("global.msh", 3.0);
        if(myrank == 0) std::cout << "Done!" << std::endl;
        
        if(myrank == 0) std::cout << "Writing .pro file... " << std::flush;
        if(myrank == 0) SEQ::writeProFile(global, nparts);
        if(myrank == 0) std::cout << "Done!" << std::endl;
        
        SEQ::freeModels(models, global);
    }
    else
    {
        std::cout << "[rank " << myrank << "] Unused rank because nparts is smaller than nbproc!" << std::endl;
    }
    
    delete m;
    return 0;
}
