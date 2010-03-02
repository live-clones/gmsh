//
// Description :
//
//
// Author:  <Boris Sedji>,  01/2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include <string.h>
#include "GmshConfig.h"
#include "elasticitySolver.h"
#include "linearSystemCSR.h"
#include "linearSystemPETSc.h"
#include "linearSystemGMM.h"
#include "Numeric.h"
#include "GModel.h"
#include "functionSpace.h"
#include "terms.h"
#include "solverAlgorithms.h"
#include "quadratureRules.h"
#include "solverField.h"
#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "MPoint.h"
#endif

#include "ImageSolver.h"
#include "DILevelset.h"
#include "NodeEnrichedFS.cpp"
#include "gLevelSetMesh.h"

#include "groupOfElements.h"
#include "FuncGradDisc.h"

#include "xFemFunctionSpace.cpp"


ImageSolver::~ImageSolver()
{
    //delete _funcEnrichment;
}


void ImageSolver::setMesh(GModel *m, int dim, std::vector< float > &ListLSValue, std::map< int ,std::vector<int> > & ListHangingNodes)
{
    _dim = dim;
    int tag  = 1;
    _tag = tag;
    //if (_ls) delete _ls;
    std::vector<float>::iterator itl;
    itl = ListLSValue.begin();
    int k = 1;
    while (itl!=ListLSValue.end()){
        _LevelSetValue[k] = ListLSValue[k-1] ;
        k++;
        itl++;
    }
    gLevelSetMesh *ls = new gLevelSetMesh(&_LevelSetValue,m,tag);
    GModel *pcut = m->buildCutGModel(ls);
    pModel = pcut;
    std::string ModelName = "Tree_cutLS.msh" ;
    pcut->writeMSH(ModelName,2.1,false,false);
    GModel::setCurrent(pModel);
    _ls = new gLevelSetMesh(&_LevelSetValue,m,tag);
    //ListHangingNodes.clear();
    _ListHangingNodes = & ListHangingNodes;
    //delete p;
    delete ls;
}


void ImageSolver::readInputFile(const std::string &fn)
{
    FILE *f = fopen(fn.c_str(), "r");
    char what[256];
    while (!feof(f)){
        if (fscanf(f, "%s", what) != 1) return;
        if (!strcmp(what, "ElasticDomain")){
            GModel::setCurrent(pModel);
            elasticField field;
            int physical;
            if (fscanf(f, "%d %lf %lf", &physical, &field._E, &field._nu) != 3) return;
            field._tag = _tag;
            field.g = new groupOfElements (_dim, physical);
            elasticFields.push_back(field);
        }
        else if (!strcmp(what, "Void")){
            //      elasticField field;
            //      create enrichment ...
            //      create the group ...
            //      assign a tag
            //      elasticFields.push_back(field);
        }
        else if (!strcmp(what, "NodeDisplacement")){
            double val;
            int node, comp;
            if (fscanf(f, "%d %d %lf", &node, &comp, &val) != 3) return;
            dirichletBC diri;
            diri.g = new groupOfElements (0, node);
            diri._f= simpleFunction<double>(val);
            diri._comp=comp;
            diri._tag=node;
            diri.onWhat=BoundaryCondition::ON_VERTEX;
            allDirichlet.push_back(diri);
        }
        else if (!strcmp(what, "EdgeDisplacement")){
            GModel::setCurrent(pModel);
            double val;
            int edge, comp;
            if (fscanf(f, "%d %d %lf", &edge, &comp, &val) != 3) return;
            dirichletBC diri;
            diri.g = new groupOfElements (1, edge);
            diri._f= simpleFunction<double>(val);
            diri._comp=comp;
            diri._tag=edge;
            diri.onWhat=BoundaryCondition::ON_EDGE;
            allDirichlet.push_back(diri);
        }
        else if (!strcmp(what, "FaceDisplacement")){
            double val;
            int face, comp;
            if (fscanf(f, "%d %d %lf", &face, &comp, &val) != 3) return;
            dirichletBC diri;
            diri.g = new groupOfElements (2, face);
            diri._f= simpleFunction<double>(val);
            diri._comp=comp;
            diri._tag=face;
            diri.onWhat=BoundaryCondition::ON_FACE;
            allDirichlet.push_back(diri);
        }
        else if (!strcmp(what, "NodeForce")){
            double val1, val2, val3;
            int node;
            if (fscanf(f, "%d %lf %lf %lf", &node, &val1, &val2, &val3) != 4) return;
            neumannBC neu;
            neu.g = new groupOfElements (0, node);
            neu._f= simpleFunction<SVector3>(SVector3(val1, val2, val3));
            neu._tag=node;
            neu.onWhat=BoundaryCondition::ON_VERTEX;
            allNeumann.push_back(neu);
        }
        else if (!strcmp(what, "EdgeForce")){
            GModel::setCurrent(pModel);
            double val1, val2, val3;
            int edge;
            if (fscanf(f, "%d %lf %lf %lf", &edge, &val1, &val2, &val3) != 4) return;
            neumannBC neu;
            neu.g = new groupOfElements (1, edge);
            neu._f= simpleFunction<SVector3>(SVector3(val1, val2, val3));
            neu._tag=edge;
            neu.onWhat=BoundaryCondition::ON_EDGE;
            allNeumann.push_back(neu);
        }
        else if (!strcmp(what, "FaceForce")){
            double val1, val2, val3;
            int face;
            if (fscanf(f, "%d %lf %lf %lf", &face, &val1, &val2, &val3) != 4) return;
            neumannBC neu;
            neu.g = new groupOfElements (2, face);
            neu._f= simpleFunction<SVector3>(SVector3(val1, val2, val3));
            neu._tag=face;
            neu.onWhat=BoundaryCondition::ON_FACE;
            allNeumann.push_back(neu);
        }
        else if (!strcmp(what, "VolumeForce")){
            double val1, val2, val3;
            int volume;
            if (fscanf(f, "%d %lf %lf %lf", &volume, &val1, &val2, &val3) != 4) return;
            neumannBC neu;
            neu.g = new groupOfElements (3, volume);
            neu._f= simpleFunction<SVector3>(SVector3(val1, val2, val3));
            neu._tag=volume;
            neu.onWhat=BoundaryCondition::ON_VOLUME;
            allNeumann.push_back(neu);
        }
        else {
            Msg::Error("Invalid input : %s", what);
//      return;
        }
    }
    fclose(f);
}


void ImageSolver::solve(){

    //GModel::setCurrent(pModel);

#if defined(HAVE_TAUCS)
    linearSystemCSRTaucs<double> *lsys = new linearSystemCSRTaucs<double>;
#elif defined(HAVE_PETSC)
    linearSystemPETSc<double> *lsys = new linearSystemPETSc<double>;
#else
    linearSystemGmm<double> *lsys = new linearSystemGmm<double>;
    lsys->setNoisy(2);
#endif
    if (pAssembler) delete pAssembler;
    pAssembler = new dofManager<double>(lsys);

    // determine all enriched nodes and save in map member _TagEnrichedVertex

    for (int i = 0; i < elasticFields.size(); ++i){
        std::set<MElement*>::const_iterator it = elasticFields[i].g->begin();
        for ( ; it != elasticFields[i].g->end(); ++it)
        {
            MElement *e = *it;
            if (e->getParent()) // if element got parents
            {
                for (int k = 0; k < e->getParent()->getNumVertices(); ++k)
                {  // for all vertices in the element parent
                    _TagEnrichedVertex.insert(e->getParent()->getVertex(k)->getNum());
                }
            }
        }
    }

    _TagEnrichedVertex.clear();
    _EnrichComp.insert(0);
    _EnrichComp.insert(1);
    _EnrichComp.insert(2);

    _funcEnrichment = new FuncGradDisc(_ls,pModel);


    // space function definition //
    // Lagrange space with normal dofs
    FunctionSpace<SVector3> *LagrangeSpace;
    if (_dim==3) LagrangeSpace=new VectorLagrangeFunctionSpace(_tag);
    if (_dim==2) LagrangeSpace=new VectorLagrangeFunctionSpace(_tag,VectorLagrangeFunctionSpace::VECTOR_X,VectorLagrangeFunctionSpace::VECTOR_Y);

    // Filtered space
    FilterNodeEnriched *filter = new FilterNodeEnriched(&_TagEnrichedVertex , &_EnrichComp);
    FilteredFS<SVector3> *LagrangeFiltered = new FilteredFS<SVector3>(LagrangeSpace,filter);

    // xfem filtered space
    xFemFS<SVector3> *xFemLagrange = new xFemFS<SVector3>(LagrangeFiltered,_funcEnrichment);

    // Composite space : xfem + Lagrange
    if (LagSpace) delete LagSpace;

    LagSpace = new CompositeFunctionSpace<SVector3>(*LagrangeSpace, *xFemLagrange);

    std::cout <<  "Dirichlet BC"<< std::endl;
    for (unsigned int i = 0; i < allDirichlet.size(); i++)
    {
        FilterDofComponent filter(allDirichlet[i]._comp);
        FixNodalDofs(*LagSpace,allDirichlet[i].g->begin(),allDirichlet[i].g->end(),*pAssembler,allDirichlet[i]._f,filter);
    }

    // fill mean hanging nodes

    std::map<int,std::vector <int> >::iterator ith;
    ith = _ListHangingNodes->begin();
    int compt = 1;
    while (ith!=_ListHangingNodes->end())
    {
        float fac;
        fac = 1.0/(ith->second).size();  // mean hanging nodes
        for (int j=0;j<_dim;j++)
        {
            DofAffineConstraint<double> constraint;
            int type = Dof::createTypeWithTwoInts(j, _tag);
            Dof hgnd(ith->first,type);
            for (int i=0;i<(ith->second).size();i++)
            {
                Dof key((ith->second)[i],type);
                std::pair<Dof, double >  linDof(key,fac);
                constraint.linear.push_back(linDof);
            }
            constraint.shift = 0;
            pAssembler->setLinearConstraint (hgnd, constraint);
        }
        ith++;
        compt++;
    }

//  std::map<int , std::vector < int > >::iterator ith;
//  ith = _ListHangingNodes->begin();
//  std::cout <<  "HangingNodes :"<< std::endl;
//  while (ith!=_ListHangingNodes->end())
//  {
//
//    std::cout<< ith->first << " " << (ith->second)[0] << " " << (ith->second)[1]  <<"\n";
//    MVertex *v1;
//    MVertex *v2;
//    MVertex *v3;
//    v1 = pModel->getMeshVertexByTag(ith->first);
//    v2 = pModel->getMeshVertexByTag((ith->second)[0]);
//    v3 = pModel->getMeshVertexByTag((ith->second)[1]);
//    std::cout<<"xyz : "<<v1->x()<<" "<< v1->y() <<" "<< v1->z() << " :: " <<v2->x()<<" "<< v2->y() <<" "<< v2->z() << " :: " <<v3->x()<<" "<< v3->y() <<" "<< v3->z() << " \n ";
//    ith++;
//  }


//  we number the dofs : when a dof is numbered, it cannot be numbered
//  again with another number.


    for (unsigned int i = 0; i < elasticFields.size(); ++i)
    {
        NumberDofs(*LagSpace, elasticFields[i].g->begin(), elasticFields[i].g->end(),*pAssembler);
    }

    // Now we start the assembly process
    // First build the force vector

    GaussQuadrature Integ_Boundary(GaussQuadrature::Val);
    std::cout <<  "Neumann BC"<< std::endl;
    for (unsigned int i = 0; i < allNeumann.size(); i++)
    {
        LoadTerm<SVector3> Lterm(*LagSpace,allNeumann[i]._f);
        Assemble(Lterm,*LagSpace,allNeumann[i].g->begin(),allNeumann[i].g->end(),Integ_Boundary,*pAssembler);
    }

// bulk material law

    GaussQuadrature Integ_Bulk(GaussQuadrature::GradGrad);
    for (unsigned int i = 0; i < elasticFields.size(); i++)
    {
        IsotropicElasticTerm Eterm(*LagSpace,elasticFields[i]._E,elasticFields[i]._nu);
//    LaplaceTerm<SVector3,SVector3> Eterm(*LagSpace);
        Assemble(Eterm,*LagSpace,elasticFields[i].g->begin(),elasticFields[i].g->end(),Integ_Bulk,*pAssembler);
    }

    printf("-- done assembling!\n");
    std::cout<<"Dof Number : " << pAssembler->sizeOfR() <<"\n";
    lsys->systemSolve();
    printf("-- done solving!\n");
    double energ=0;
    for (unsigned int i = 0; i < elasticFields.size(); i++)
    {
        SolverField<SVector3> Field(pAssembler, LagSpace);
        IsotropicElasticTerm Eterm(Field,elasticFields[i]._E,elasticFields[i]._nu);
        BilinearTermToScalarTerm<SVector3,SVector3> Elastic_Energy_Term(Eterm);
        Assemble(Elastic_Energy_Term,elasticFields[i].g->begin(),elasticFields[i].g->end(),Integ_Bulk,energ);
    }
    printf("elastic energy=%f\n",energ);

}



PView* ImageSolver::buildDisplacementView (const std::string &postFileName)
{

    std::set<MVertex*> v;
    for (unsigned int i = 0; i < elasticFields.size(); ++i)
    {
        for (groupOfElements::elementContainer::const_iterator it = elasticFields[i].g->begin(); it != elasticFields[i].g->end(); ++it)
        {
            MElement *e=*it;
            if (e->getParent()) e=e->getParent();
            for (int j = 0; j < e->getNumVertices(); ++j) v.insert(e->getVertex(j));
        }
    }
    std::map<int, std::vector<double> > data;
    SolverField<SVector3> Field(pAssembler, LagSpace);
    for ( std::set<MVertex*>::iterator it = v.begin(); it != v.end(); ++it)
    {
        SVector3 val;
        MPoint p(*it);
        Field.f(&p,0,0,0,val);
        std::vector<double> vec(3);
        vec[0]=val(0);
        vec[1]=val(1);
        vec[2]=val(2);
//    std::cout<<"ver num : " << (*it)->getNum() <<"\n" ;
//    std::cout<<"( "<<vec[0]<<" "<<vec[1]<<" "<<vec[2]<<" )\n";
        data[(*it)->getNum()]=vec;
    }
    PView *pv = new PView (postFileName, "NodeData", pModel, data, 0.0);
    return pv;

}
