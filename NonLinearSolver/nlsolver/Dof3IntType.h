//
// Description: Derivate class of Dof used for FullDg formulation where the type includes 3 informations (field,local vertex number, dof)
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef DGC0DOF_H_
#define DGC0DOF_H_
#include "dofManager.h"
// Two functions are added to dof to define type with three int
// Use by high level so impossible to let this in the projects ?
class Dof3IntType : public Dof{
  public :
    Dof3IntType(long int ent, int type) : Dof(ent,type){}
    ~Dof3IntType(){}
    inline static int createTypeWithThreeInts(int comp,int field, int num=0){return 100000*field+100*num+comp;}
    inline static void getThreeIntsFromType(int t, int &comp, int &field, int &num){
      field = t/100000;
      int i1=t%100000;
      num = i1/100;
      comp= i1%100;
    }
    // This function is used for Cg/Dg case (Allow to call the same function for the Two formulations)
    inline static void getThreeIntsFromType(int t, int &comp, int &field){
      field = t/100000;
      comp =t%100000;
    }
};
#endif // Dof3IntType
