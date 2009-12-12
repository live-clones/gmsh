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



#include "terms.h"



template<class Iterator,class Assembler> void Assemble(BilinearTermBase &term,FunctionSpaceBase &space1,Iterator itbegin,Iterator itend,Assembler &assembler) // symmetric
{
    fullMatrix<double> localMatrix;
    std::vector<Dof> R;
    for (Iterator it = itbegin;it!=itend; ++it)
    {
      MElement *e = *it;
      R.clear();
      int integrationOrder = 3 * (e->getPolynomialOrder() - 1) ; // todo: to be given from outside
      int npts=0;
      IntPt *GP;
      e->getIntegrationPoints(integrationOrder, &npts, &GP);
      term.get(e,npts,GP,localMatrix);
      space1.getKeys(e,R);
      assembler.assemble(R, localMatrix);
    }
}

template<class Assembler> void Assemble(BilinearTermBase &term,FunctionSpaceBase &space1,MElement *e,Assembler &assembler) // symmetric
{
    fullMatrix<double> localMatrix;
    std::vector<Dof> R;
    int integrationOrder = 3 * (e->getPolynomialOrder() - 1) ; // todo: to be given from outside
    int npts=0;
    IntPt *GP;
    e->getIntegrationPoints(integrationOrder, &npts, &GP);
    term.get(e,npts,GP,localMatrix);
    space1.getKeys(e,R);
    assembler.assemble(R, localMatrix);
}

template<class Iterator,class Assembler> void Assemble(LinearTermBase &term,FunctionSpaceBase &space1,Iterator itbegin,Iterator itend,Assembler &assembler)
{
    fullVector<double> localVector;
    std::vector<Dof> R;
    for (Iterator it = itbegin;it!=itend; ++it)
    {
      MElement *e = *it;
      R.clear();
      int integrationOrder = 2* (e->getPolynomialOrder()) ; // todo: to be given from outside
      int npts=0;
      IntPt *GP;
      e->getIntegrationPoints(integrationOrder, &npts, &GP);
      term.get(e,npts,GP,localVector);
      space1.getKeys(e,R);
      assembler.assemble(R, localVector);
    }
}

template<class Assembler> void Assemble(LinearTermBase &term,FunctionSpaceBase &space1,MElement *e,Assembler &assembler)
{
    fullVector<double> localVector;
    std::vector<Dof> R;
    int integrationOrder = 2* (e->getPolynomialOrder()) ; // todo: to be given from outside
    int npts=0;
    IntPt *GP;
    e->getIntegrationPoints(integrationOrder, &npts, &GP);
    term.get(e,npts,GP,localVector);
    space1.getKeys(e,R);
    assembler.assemble(R, localVector);
}

#endif// _SOLVERALGORITHMS_H_