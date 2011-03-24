//
// C++ Interface: terms
//
// Description: non linear assembly fonctions
//
//
// Author:  <Gauthier BECKER>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef NONLINEARSOLVERALGORITHMS_H_
#define NONLINEARSOLVERALGORITHMS_H_
#include "dofManager.h"
#include "quadratureRules.h"
#include "MVertex.h"
#include "MInterfaceElement.h"
#include "functionSpace.h"
#include "explicitHulbertChung.h"
#include "solverAlgorithms.h"
#include "explicitDofManager.h"

// Assemble linear term. The field of term can be pass (compute matrix by perturbation and avoid a additional getKeys)
// FIX THIS (use classical assemble) when field will be defined properly

template<class Iterator, class Assembler> void Assemble(LinearTermBase<double> *term, FunctionSpaceBase &space,
                                                        Iterator itbegin, Iterator itend,
                                                        QuadratureBase &integrator,
                                                        const unknownField *ufield,Assembler &assembler)
{
  fullVector<typename Assembler::dataMat> localVector(0);
  std::vector<Dof> R;
  nonLinearTermBase<double> *nlterm = dynamic_cast<nonLinearTermBase<double>*>(term);
  if( (nlterm !=NULL) and (nlterm->isData())){
    fullVector<double> disp;
    nlterm->set(&disp);
    for (Iterator it = itbegin; it != itend; ++it){
      MElement *e = *it;
      R.clear();
      IntPt *GP;
      int npts = integrator.getIntPoints(e, &GP);
      space.getKeys(e, R);
      disp.resize(R.size());
      ufield->get(R,disp);
      term->get(e, npts, GP, localVector); //localVector.print();
      assembler.assemble(R, localVector);
    }
  }
  else{
    for (Iterator it = itbegin; it != itend; ++it){
      MElement *e = *it;
      R.clear();
      IntPt *GP;
      int npts = integrator.getIntPoints(e, &GP);
      space.getKeys(e, R);
      term->get(e, npts, GP, localVector); //localVector.print();
      assembler.assemble(R, localVector);
    }

  }
}

// Function Assemble for mass matrix. An other function is needed because Two matrix in the system
template<class Iterator,class Assembler> void AssembleMass(BilinearTermBase *term,FunctionSpaceBase &space,Iterator itbegin,
                                                           Iterator itend,QuadratureBase &integrator,Assembler &assembler) // symmetric
{
  fullMatrix<typename Assembler::dataMat> localMatrix;
  // remove the Dynamic Cast
  explicitHCDofManager<typename Assembler::dataVec>* expAss = dynamic_cast<explicitHCDofManager<typename Assembler::dataVec>*>(&assembler);
  std::vector<Dof> R;
  for (Iterator it = itbegin;it!=itend; ++it)
  {
    MElement *e = *it;
    R.clear();
    IntPt *GP;
    int npts=integrator.getIntPoints(e,&GP);
    term->get(e,npts,GP,localMatrix);
    space.getKeys(e,R);
    expAss->assemble(R, localMatrix,explicitHulbertChung<double>::mass);
  }
}

// Assemble mass for a rigid contact space. Only ddl of GC
template<class Assembler>
void AssembleMass(BilinearTermBase *term, rigidContactSpace *space,Assembler *assembler){
  fullMatrix<typename Assembler::dataMat> localMatrix;
  explicitHCDofManager<typename Assembler::dataVec>* expAss = dynamic_cast<explicitHCDofManager<typename Assembler::dataVec>*>(assembler);
  std::vector<Dof> R;
  space->getKeysOfGravityCenter(R);
  MElement *ele;
  IntPt *GP;
  term->get(ele,0,GP,localMatrix);
  expAss->assemble(R, localMatrix,explicitHulbertChung<double>::mass);
}

template<class Assembler> void FixNodalDofs(FunctionSpaceBase *space,MElement *e,Assembler &assembler,simpleFunction<typename Assembler::dataVec> &fct,FilterDof &filter,bool fullDg)
{
  std::vector<MVertex*> tabV;
  int nv=e->getNumVertices();
  std::vector<Dof> R;
  space->getKeys(e,R);
  tabV.reserve(nv);
  for (int i=0;i<nv;++i) tabV.push_back(e->getVertex(i));

  if(!fullDg){
    for (std::vector<Dof>::iterator itd=R.begin();itd!=R.end();++itd)
    {
      Dof key=*itd;
      if (filter(key))
      {
        for (int i=0;i<nv;++i)
        {
          if (tabV[i]->getNum()==key.getEntity())
          {
            //printf("Fix dof number %d comp %d\n",key.getEntity(),key.getType());
            assembler.fixDof(key, fct(tabV[i]->x(),tabV[i]->y(),tabV[i]->z()));
            break;
          }
        }
      }
    }
  }
  else{
    for (std::vector<Dof>::iterator itd=R.begin();itd!=R.end();++itd)
    {
      Dof key=*itd;
      if (filter(key))
      {
        for (int i=0;i<nv;++i)
        {
          assembler.fixDof(key, fct(tabV[i]->x(),tabV[i]->y(),tabV[i]->z()));
          break;
        }
      }
    }
  }
}

template<class Iterator,class Assembler> void FixNodalDofs(FunctionSpaceBase *space,Iterator itbegin,Iterator itend,Assembler &assembler,
                                                           simpleFunction<typename Assembler::dataVec> &fct,FilterDof &filter,bool fullDg)
{
  for (Iterator it=itbegin;it!=itend;++it)
  {
    FixNodalDofs(space,*it,assembler,fct,filter,fullDg);
  }
}

template<class Assembler>
void FixNodalDofs(rigidContactSpace *space,simpleFunction<typename Assembler::dataVec> &fct,FilterDof &filter, Assembler &assembler){
  std::vector<Dof> R;
  space->getKeysOfGravityCenter(R);
  for(int i=0;i<R.size();i++){
    if(filter(R[i]))
      assembler.fixDof(R[i], fct(0.,0.,0.));
  }

}
template<class Assembler> void SetInitialDofs(FunctionSpaceBase *space,MElement *e,Assembler &assembler,
                                            const double &value,const initialCondition::whichCondition whichC,
                                            FilterDof &filter,bool fullDg)
{
  std::vector<MVertex*> tabV;
  int nv=e->getNumVertices();
  std::vector<Dof> R;
//  FunctionSpace<double> *dgspace = dynamic_cast<FunctionSpace<double>*>(space);
  space->getKeys(e,R);
  tabV.reserve(nv);
  explicitHCDofManager<double> *dynass= dynamic_cast<explicitHCDofManager<double>*>(&assembler); // remove this dynamic_cast
  for (int i=0;i<nv;++i) tabV.push_back(e->getVertex(i));

  if(!fullDg){
    for (std::vector<Dof>::iterator itd=R.begin();itd!=R.end();++itd)
    {
      Dof key=*itd;
      if (filter(key))
      {
        for (int i=0;i<nv;++i)
        {
          if (tabV[i]->getNum()==key.getEntity())
          {
            //printf("Fix dof number %d comp %d\n",key.getEntity(),key.getType());
            dynass->setInitialCondition(key,value,whichC);
            break;
          }
        }
      }
    }
  }
  else{
    for (std::vector<Dof>::iterator itd=R.begin();itd!=R.end();++itd)
    {
      Dof key=*itd;
      if (filter(key))
      {
        for (int i=0;i<nv;++i)
        {
          dynass->setInitialCondition(key, value,whichC);
          break;
        }
      }
    }
  }
}

template<class Iterator,class Assembler> void SetInitialDofs(FunctionSpaceBase *space,Iterator itbegin,Iterator itend,
                                                           const double &value,const initialCondition::whichCondition whichC,
                                                            Assembler &assembler, FilterDof &filter,bool fullDg)
{
  for (Iterator it=itbegin;it!=itend;++it)
  {
    SetInitialDofs(space,*it,assembler,value,whichC,filter,fullDg);
  }
}

// Function Numbering Dof for rigid contact (Create Three Dofs for GC of rigid bodies)
template<class Assembler>
void NumberDofs(rigidContactSpace &space, Assembler &assembler){
  // get Dofs of GC
  std::vector<Dof> R;
  space.getKeysOfGravityCenter(R);
  // Put them into DofManager
  int nbdofs=R.size();
  for (int i=0;i<nbdofs;++i)
    assembler.numberDof(R[i]);
}

#endif //NONLINEARSOLVERALGORITHMS_H_

