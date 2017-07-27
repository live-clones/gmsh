#include <map>
#include <unordered_map>
#include <vector>
#include <fstream>

#include "GModel.h"
#include "GEntity.h"

#include "partitionFace.h"
#include "partitionEdge.h"
#include "partitionVertex.h"

#include "io.h"

void SEQ::writeModels(std::vector<GModel*> &models)
{
    for(unsigned int i = 0; i < models.size(); i++)
    {
        std::string str = "mesh_";
        str += std::to_string(i);
        str += ".msh";
        
        models[i]->writeMSH(str.c_str());//, 3.0);
    }
}

void SEQ::writeProFile(GModel* m, const int npart)
{
    std::ofstream file("partition.pro", std::ofstream::trunc);
    
    //-----------Group-----------
    file << "Group{" << std::endl;
    
    //Omega
    std::unordered_map<int, std::vector<int> > listOfOmega;//map between tag of omega and the physical's numbers that corresponds
    for(GModel::piter it = m->firstPhysicalName(); it != m->lastPhysicalName(); ++it)
    {
        std::string name = it->second;
        
        if(name[0] == '_' && name[1] == 'o')
        {
            std::vector<int> num = getNumFromString(name);
            
            std::vector<int> vec = listOfOmega[num[0]];
            vec.push_back(it->first.second);
            listOfOmega[num[0]] = vec;
        }
    }
    //Omega_i
    for(std::unordered_map<int, std::vector<int> >::iterator it = listOfOmega.begin(); it != listOfOmega.end(); ++it)
    {
        std::vector<int> vec = it->second;
        file << "\tOmega_" << it->first << " = Region[{";
        
        for(unsigned int i = 0; i < vec.size(); i++)
        {
            if(i != 0)
            {
                file << ", ";
            }
            file << vec[i];
        }
        file << "}];" << std::endl;
    }
    file << std::endl;
    
    //Sigma
    if(npart == 1)
    {
        file << "\tSigma_0_0 = Region[{}];" << std::endl;
        file << "\tBndSigma_0_0 =  Region[{}];" << std::endl;
        file << "\tSigma_0 =  Region[{}];" << std::endl;
        file << "\tBndGammaInf_0_0 = Region[{}];" << std::endl;
        file << "\tBndGammaD_0_0 = Region[{}];" << std::endl;
        file << "\tBndGammaInf_0 = Region[{}];" << std::endl;
        file << "\tBndGammaD_0 = Region[{}];" << std::endl;
        file << "\tD_0() = {0};" << std::endl;
    }
    std::unordered_map<int, std::vector<int> > listOfSigma;//map between tag of sigma and the physical's numbers that corresponds
    std::unordered_map<int, std::vector<int> > listOfBndSigma;//map between tag of sigma's boundary and the physical's numbers that corresponds
    for(GModel::piter it = m->firstPhysicalName(); it != m->lastPhysicalName(); ++it)
    {
        std::string name = it->second;
        
        if(name[0] == '_' && name[1] == 's')
        {
            std::vector<int> num = getNumFromString(name);
            
            if(num.size() < 3)
            {
                for(unsigned int i = 0; i < num.size(); i++)
                {
                    std::vector<int> vec = listOfSigma[num[i]];
                    vec.push_back(it->first.second);
                    listOfSigma[num[i]] = vec;
                }
            }
            else
            {
                for(unsigned int i = 0; i < num.size(); i++)
                {
                    std::vector<int> vec = listOfBndSigma[num[i]];
                    vec.push_back(it->first.second);
                    listOfBndSigma[num[i]] = vec;
                }
            }
        }
    }
    file << std::endl;
    //Sigma_i_j and BndSigma_i_j
    std::unordered_map<int, std::vector<int> > listOfNeighbour;//map between tag of omega and tag of neighbours
    for(std::unordered_map<int, std::vector<int> >::iterator it = listOfSigma.begin(); it != listOfSigma.end(); ++it)
    {
        for(std::unordered_map<int, std::vector<int> >::iterator it2 = it; it2 != listOfSigma.end(); ++it2)
        {
            if(it != it2)
            {
                std::vector<int> vec1 = it->second;
                std::vector<int> vec2 = it2->second;
                std::vector<int>* vecCommun =  new std::vector<int>;
            
                if(communPhysicals(vec1, vec2, vecCommun))
                {
                    listOfNeighbour[it->first].push_back(it2->first);
                    listOfNeighbour[it2->first].push_back(it->first);
                    
                    file << "\tSigma_" << it->first << "_" << it2->first << " = Region[{";
                    for(unsigned int i = 0; i < vecCommun->size(); i++)
                    {
                        if(i != 0)
                        {
                            file << ", ";
                        }
                        file << (*vecCommun)[i];
                    }
                    file << "}];" << std::endl;
                    
                    file << "\tSigma_" << it2->first << "_" << it->first << " = Region[{";
                    for(unsigned int i = 0; i < vecCommun->size(); i++)
                    {
                        if(i != 0)
                        {
                            file << ", ";
                        }
                        file << (*vecCommun)[i];
                    }
                    file << "}];" << std::endl;
                    
                    if(listOfBndSigma.count(it->first) > 0)
                    {
                        std::vector<int> vec1 = listOfBndSigma[it->first];
                        std::vector<int> vec2 = listOfBndSigma[it2->first];
                        std::vector<int>* vecCommun =  new std::vector<int>;
                        
                        if(communPhysicals(vec1, vec2, vecCommun))
                        {
                            file << "\tBndSigma_" << it->first << "_" << it2->first << " = Region[{";
                            for(unsigned int i = 0; i < vecCommun->size(); i++)
                            {
                                if(i != 0)
                                {
                                    file << ", ";
                                }
                                file << (*vecCommun)[i];
                            }
                            file << "}];" << std::endl;
                            
                            file << "\tBndSigma_" << it2->first << "_" << it->first << " = Region[{";
                            for(unsigned int i = 0; i < vecCommun->size(); i++)
                            {
                                if(i != 0)
                                {
                                    file << ", ";
                                }
                                file << (*vecCommun)[i];
                            }
                            file << "}];" << std::endl;
                        }
                        else
                        {
                            file << "\tBndSigma_" << it->first << "_" << it2->first << " = Region[{}];" << std::endl;
                            file << "\tBndSigma_" << it2->first << "_" << it->first << " = Region[{}];" << std::endl;
                        }
                    }
                    else
                    {
                        file << "\tBndSigma_" << it->first << "_" << it2->first << " = Region[{}];" << std::endl;
                        file << "\tBndSigma_" << it2->first << "_" << it->first << " = Region[{}];" << std::endl;
                    }
                    
                    file << "\tBndGammaInf_" << it->first << "_" << it2->first << " = Region[{}];" << std::endl;
                    file << "\tBndGammaInf_" << it2->first << "_" << it->first << " = Region[{}];" << std::endl;
                    
                    file << "\tBndGammaD_" << it->first << "_" << it2->first << " = Region[{}];" << std::endl;
                    file << "\tBndGammaD_" << it2->first << "_" << it->first << " = Region[{}];" << std::endl;
                    
                    file << "\tBndGammaInf_" << it->first << " = Region[{}];" << std::endl;
                    file << "\tBndGammaInf_" << it2->first << " = Region[{}];" << std::endl;
                    
                    file << "\tBndGammaD_" << it->first << " = Region[{}];" << std::endl;
                    file << "\tBndGammaD_" << it2->first << " = Region[{}];" << std::endl;
                }
                delete vecCommun;
            }
        }
    }
    file << std::endl;
    //Sigma_i
    for(std::unordered_map<int, std::vector<int> >::iterator it = listOfSigma.begin(); it != listOfSigma.end(); ++it)
    {
        std::vector<int> vec = it->second;
        file << "\tSigma_" << it->first << " = Region[{";
        
        for(unsigned int i = 0; i < vec.size(); i++)
        {
            if(i != 0)
            {
                file << ", ";
            }
            file << vec[i];
        }
        file << "}];" << std::endl;
    }
    file << std::endl;
    //BndSigma_i
    for(std::unordered_map<int, std::vector<int> >::iterator it = listOfBndSigma.begin(); it != listOfBndSigma.end(); ++it)
    {
        std::vector<int> vec = it->second;
        file << "\tBndSigma_" << it->first << " = Region[{";
        
        for(unsigned int i = 0; i < vec.size(); i++)
        {
            if(i != 0)
            {
                file << ", ";
            }
            file << vec[i];
        }
        file << "}];" << std::endl;
    }
    file << std::endl << std::endl;
    
    //D
    file << "\tD() = {";
    for(unsigned int i = 0; i < listOfOmega.size(); i++)
    {
        if(i != 0)
        {
            file << ", ";
        }
        file << i;
    }
    file << "};" << std::endl;
    file << "\tN_DOM = #D();" << std::endl;
    
    //D_i
    for(std::unordered_map<int, std::vector<int> >::iterator it = listOfNeighbour.begin(); it != listOfNeighbour.end(); ++it)
    {
        file << "\tD_" << it->first << " = {";
        for(unsigned int i = 0; i < it->second.size(); i++)
        {
            if(i != 0)
            {
                file << ", ";
            }
            file << it->second[i];
        }
        file << "};" << std::endl;
    }
    
    
    file << "}" << std::endl << std::endl << std::endl;
    //**********************************************
    
    
    //-----------Function-----------
    file << "Function {" << std::endl;
    file << "\tmyD = {} ; // the domains that I'm in charge of" << std::endl;
    for(unsigned int i = 0; i < listOfOmega.size(); i++)
    {
        file << "\tmyD_" << i << " = {};" << std::endl;
    }
    file << "\tListOfFields = {};" << std::endl;
    file << "\tListOfConnectedFields = {};" << std::endl << std::endl;
    
    
    file << "\tFor idom In {0:N_DOM-1}" << std::endl;
    
    file << "\t\tIf (idom % MPI_Size == MPI_Rank)" << std::endl;
    
    file << "\t\t\tmyD() += D(idom);" << std::endl;
    file << "\t\t\tmyD~{idom} += D~{idom}();" << std::endl;
    
    file << "\t\tEndIf" << std::endl;
    file << "\tEndFor" << std::endl;
    
    file << "\tFor ii In {0:#myD()-1}" << std::endl;
    
    file << "\t\ti = myD(ii);" << std::endl;
    
    file << "\t\tIf(#myD~{i}() == 2)" << std::endl;
    file << "\t\t\tPrintf(\"We can do sweeping!\");" << std::endl;
    file << "\t\tEndIf" << std::endl;

    file << "\t\tFor jj In {0:#myD~{i}()-1}" << std::endl;
    file << "\t\t\tj = myD~{i}(jj);" << std::endl << std::endl;
    
    file << "\t\t\ttag_g~{i}~{j} = i * 1000 + j;" << std::endl;
    file << "\t\t\ttag_g~{j}~{i} = j * 1000 + i;" << std::endl << std::endl;
    
    file << "\t\t\tListOfFields() += tag_g~{i}~{j};" << std::endl;
    file << "\t\t\tListOfConnectedFields() += 1;" << std::endl;
    file << "\t\t\tListOfConnectedFields() += tag_g~{j}~{i};" << std::endl;
    
    file << "\t\t\tIf(ANALYSIS == 0)" << std::endl;
    file << "\t\t\t\tg_in~{i}~{j}[ Sigma~{i}~{j} ] = ComplexScalarField[XYZ[]]{ tag_g~{j}~{i} };" << std::endl;
    file << "\t\t\tEndIf" << std::endl;
    file << "\t\t\tIf(ANALYSIS == 1)" << std::endl;
    file << "\t\t\t\tg_in~{i}~{j}[ Sigma~{i}~{j} ] = ComplexVectorField[XYZ[]]{ tag_g~{j}~{i} };" << std::endl;
    file << "\t\t\tEndIf" << std::endl;
    
    file << "\t\tEndFor" << std::endl;

    file << "\tEndFor" << std::endl;
    
    file << "}" << std::endl;
    
    file.close();
}

std::vector<int> SEQ::getNumFromString(std::string name)
{
    std::vector<int> num;
    std::string currentNum;
    
    for(unsigned int i = 0; i < name.size(); i++)
    {
        if(name[i] == '0' || name[i] == '1' || name[i] == '2'|| name[i] == '3'|| name[i] == '4'|| name[i] == '5'|| name[i] == '6'|| name[i] == '7'|| name[i] == '8'|| name[i] == '9')
        {
            currentNum += name[i];
        }
        
        if(name[i] == ',' || name[i] == '}')
        {
            num.push_back(stoi(currentNum));
            currentNum.clear();
        }
    }
    
    return num;
}

bool SEQ::communPhysicals(const std::vector<int> vec1, const std::vector<int> vec2, std::vector<int>* vecCommun)
{
    for(unsigned int i = 0; i < vec1.size(); i++)
    {
        for(unsigned int j = 0; j < vec2.size(); j++)
        {
            if(vec1[i] == vec2[j])
            {
                vecCommun->push_back(vec1[i]);
            }
        }
    }
    
    if(vecCommun->size() > 0)
    {
        return true;
    }
    return false;
}



