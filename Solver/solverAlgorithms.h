//
// C++ Interface: solverAlgorithms
//
// Description:
//
//
// Author:  <Eric Bechet>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//


#ifndef _SOLVERALGORITHMS_H_
#define _SOLVERALGORITHMS_H_


#include "dofManager.h"
#include "terms.h"
#include "quadratureRules.h"
#include "MVertex.h"



template<class Iterator,class Assembler> void Assemble(BilinearTermBase &term,FunctionSpaceBase &space,Iterator itbegin,Iterator itend,QuadratureBase &integrator,Assembler &assembler) // symmetric
{
  fullMatrix<typename Assembler::dataMat> localMatrix;
  std::vector<Dof> R;
  for (Iterator it = itbegin;it!=itend; ++it)
  {
    MElement *e = *it;
    R.clear();
    IntPt *GP;
    int npts=integrator.getIntPoints(e,&GP);
    term.get(e,npts,GP,localMatrix);
    space.getKeys(e,R);
    assembler.assemble(R, localMatrix);
  }
}

template<class Assembler> void Assemble(BilinearTermBase &term,FunctionSpaceBase &space,MElement *e,QuadratureBase &integrator,Assembler &assembler) // symmetric
{
  fullMatrix<typename Assembler::dataMat> localMatrix;
  std::vector<Dof> R;
  IntPt *GP;
  int npts=integrator.getIntPoints(e,&GP);
  term.get(e,npts,GP,localMatrix);
  space.getKeys(e,R);
  assembler.assemble(R, localMatrix);
}

template<class Iterator,class Assembler> void Assemble(LinearTermBase &term,FunctionSpaceBase &space,Iterator itbegin,Iterator itend,QuadratureBase &integrator,Assembler &assembler)
{
  fullVector<typename Assembler::dataMat> localVector;
  std::vector<Dof> R;
  for (Iterator it = itbegin;it!=itend; ++it)
  {
    MElement *e = *it;
    R.clear();
    IntPt *GP;
    int npts=integrator.getIntPoints(e,&GP);
    term.get(e,npts,GP,localVector);
    space.getKeys(e,R);
    assembler.assemble(R, localVector);
  }
}

template<class Assembler> void Assemble(LinearTermBase &term,FunctionSpaceBase &space,MElement *e,QuadratureBase &integrator,Assembler &assembler)
{
  fullVector<typename Assembler::dataMat> localVector;
  std::vector<Dof> R;
  IntPt *GP;
  int npts=integrator.getIntPoints(e,&GP);
  term.get(e,npts,GP,localVector);
  space.getKeys(e,R);
  assembler.assemble(R, localVector);
}

template<class Iterator,class dataMat> void Assemble(ScalarTermBase &term,Iterator itbegin,Iterator itend,QuadratureBase &integrator,dataMat & val)
{
  dataMat localval;
  for (Iterator it = itbegin;it!=itend; ++it)
  {
    MElement *e = *it;
    IntPt *GP;
    int npts=integrator.getIntPoints(e,&GP);
    term.get(e,npts,GP,localval);
    val+=localval;
  }
}

template<class Iterator,class dataMat> void Assemble(ScalarTermBase &term,MElement *e,QuadratureBase &integrator,dataMat & val)
{
  dataMat localval;
  IntPt *GP;
  int npts=integrator.getIntPoints(e,&GP);
  term.get(e,npts,GP,localval);
  val+=localval;
}



template<class Assembler> void FixDofs(Assembler &assembler,std::vector<Dof> &dofs,std::vector<typename Assembler::dataVec> &vals)
{
  int nbff=dofs.size();
  for (int i=0;i<nbff;++i)
  {
    assembler.fixDof(dofs[i],vals[i]);
  }
}

class FilterDof
{
 public:
  virtual bool operator()(Dof key)=0;
};

class FilterDofTrivial
{
 public:
  virtual bool operator()(Dof key) {return true;}
};

class FilterDofComponent :public FilterDof
{
  int comp;
 public :
  FilterDofComponent(int comp_):comp(comp_) {}
  virtual bool operator()(Dof key)
  {
    int type=key.getType();
    int icomp,iphys;
    Dof::getTwoIntsFromType(type, icomp, iphys);
    if (icomp==comp) return true;
    return false;
  }
};


template<class Assembler> void FixNodalDofs(FunctionSpaceBase &space,MElement *e,Assembler &assembler,simpleFunction<typename Assembler::dataVec> &fct,FilterDof &filter)
{
  std::vector<MVertex*> tabV;
  int nv=e->getNumVertices();
  std::vector<Dof> R;
  space.getKeys(e,R);
  tabV.reserve(nv);
  for (int i=0;i<nv;++i) tabV.push_back(e->getVertex(i));

  for (std::vector<Dof>::iterator itd=R.begin();itd!=R.end();++itd)
  {
    Dof key=*itd;
    if (filter(key))
    {
      for (int i=0;i<nv;++i)
      {
        if (tabV[i]->getNum()==key.getEntity())
        {
          assembler.fixDof(key, fct(tabV[i]->x(),tabV[i]->y(),tabV[i]->z()));
          break;
        }
      }
    }
  }
}

template<class Iterator,class Assembler> void FixNodalDofs(FunctionSpaceBase &space,Iterator itbegin,Iterator itend,Assembler &assembler,simpleFunction<typename Assembler::dataVec> &fct,FilterDof &filter)
{
  for (Iterator it=itbegin;it!=itend;++it)
  {
    FixNodalDofs(space,*it,assembler,fct,filter);
  }
}

template<class Iterator,class Assembler> void NumberDofs(FunctionSpaceBase &space,Iterator itbegin,Iterator itend,Assembler &assembler)
{
 for (Iterator it=itbegin;it!=itend;++it)
  {
    MElement *e=*it;
    std::vector<Dof> R;
    space.getKeys(e,R);
    int nbdofs=R.size();
    for (int i=0;i<nbdofs;++i) assembler.numberDof(R[i]);

  }
}

//// Mean HangingNodes
//template <class Assembler> void FillHangingNodes(FunctionSpaceBase &space,std::map<int,std::vector <int> > &HangingNodes, Assembler &assembler, int &field, int &dim)
//{
//  std::map<int,std::vector <int> >::iterator ith;
//  ith = HangingNodes.begin();
//  int compt = 1;
//  while (ith!=HangingNodes.end())
//  {
//    float fac;
//    fac = 1.0/(ith->second).size();
//    for (int j=0;j<dim;j++)
//    {
//      DofAffineConstraint<double> constraint;
//      int type = Dof::createTypeWithTwoInts(j, field);
//      Dof hgnd(ith->first,type);
//      for (int i=0;i<(ith->second).size();i++)
//      {
//          Dof key((ith->second)[i],type);
//          std::pair<Dof, double >  linDof(key,fac);
//          constraint.linear.push_back(linDof);
//      }
//      constraint.shift = 0;
//      assembler.setLinearConstraint (hgnd, constraint);
//    }
//    ith++;
//    compt++;
//  }
//}

#endif// _SOLVERALGORITHMS_H_
