// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Boris Sedji
//

#ifndef _FUNCGRADDISC_H_
#define _FUNCGRADDISC_H_

#include "gmshLevelset.h"
#include "MVertex.h"
#include "GModel.h"

template <class scalar> class simpleFunction;


class FuncGradDisc :  public  simpleFunctionOnElement<double> {
 private :
  gLevelset *_ls;
  GModel * _pModel;

 public :
  FuncGradDisc(gLevelset *ls, GModel *pModel){
    _ls = ls;
    _pModel = pModel;
  }

  double operator () (double x, double y, double z) const {

    // --- F2 --- //
    MElement *e = getElement();
    SPoint3 p(x, y, z);

    if (e->getParent()) e = e->getParent();
    double xyz[3] = {x, y, z};
    double uvw[3];
    e->xyz2uvw(xyz, uvw);
    double val[30];
    e->getShapeFunctions(uvw[0], uvw[1], uvw[2], val);
    double f = 0;
    for (int i = 0; i < e->getNumShapeFunctions(); i++){
      MVertex *v = e->getShapeFunctionNode(i);
      //std::cout<<"val[i] :" << val[i] << "\n";
      //std::cout<<"ls(i) :" << (*_ls)(v->x(),v->y(),v->z()) << "\n";
      f = f + std::abs((*_ls)(v->x(), v->y(), v->z())) * val[i];
    }
    f = f - std::abs((*_ls)(x, y, z));

    //std::cout<<"val f :" << f << "\n";
    return f;

    // --- F1 --- //


//        SPoint3 p(x,y,z);
//        if (e->getParent()) e = e->getParent();
//        double xyz[3] = {x,y,z};
//        double uvw[3];
//        e->xyz2uvw(xyz,uvw);
//        double val[30];
//        e->getShapeFunctions(uvw[0], uvw[1], uvw[2], val);
//        double f = 0;
//        for (int i = 0; i < e->getNumShapeFunctions(); i++)
//        {
//           MVertex *v = e-<getShapeFunctionNode(i);
//           f = f + (*_ls)(v->x(), v->y(), v->z()) * val[i];
//        }
//        f = std::abs(f);
//        return f;

  }



  void gradient (double x, double y, double z,
                 double &dfdx, double &dfdy, double &dfdz) const {

    // ---- F2 ---- //
    MElement *e=getElement();
    SPoint3 p(x, y, z);
    if (e->getParent()) e = e->getParent();
    double xyz[3] = {x, y, z};
    double uvw[3];
    e->xyz2uvw(xyz, uvw);
    double gradsuvw[256][3];
    e->getGradShapeFunctions(uvw[0], uvw[1], uvw[2], gradsuvw);

    double jac[3][3];
    double invjac[3][3];
    double dNdx;
    double dNdy;
    double dNdz;
    const double detJ = e->getJacobian(uvw[0], uvw[1], uvw[2], jac);
    inv3x3(jac, invjac);

    dfdx = 0;
    dfdy = 0;
    dfdz = 0;

    if ((*_ls)(x, y, z) > 0) {
      for (int i = 0; i < e->getNumShapeFunctions(); i++) {
        dNdx = invjac[0][0] * gradsuvw[i][0] + invjac[0][1] * gradsuvw[i][1] + invjac[0][2] * gradsuvw[i][2];
        dNdy = invjac[1][0] * gradsuvw[i][0] + invjac[1][1] * gradsuvw[i][1] + invjac[1][2] * gradsuvw[i][2];
        dNdz = invjac[2][0] * gradsuvw[i][0] + invjac[2][1] * gradsuvw[i][1] + invjac[2][2] * gradsuvw[i][2];

        MVertex *v = e->getShapeFunctionNode(i);
        dfdx = dfdx + std::abs((*_ls)(v->x(), v->y(), v->z())) * dNdx ;
        dfdx = dfdx - (*_ls)(v->x(), v->y(), v->z()) * dNdx;
        dfdy = dfdy + std::abs((*_ls)(v->x(), v->y(), v->z())) * dNdy ;
        dfdy = dfdy - (*_ls)(v->x(), v->y(), v->z()) * dNdy;
        dfdz = dfdz + std::abs((*_ls)(v->x(), v->y(), v->z())) * dNdz ;
        dfdz = dfdz - (*_ls)(v->x(), v->y(), v->z()) * dNdz;
      }
    }
    else{
      for (int i = 0; i < e->getNumShapeFunctions(); i++) {
        dNdx = invjac[0][0] * gradsuvw[i][0] + invjac[0][1] * gradsuvw[i][1] + invjac[0][2] * gradsuvw[i][2];
        dNdy = invjac[1][0] * gradsuvw[i][0] + invjac[1][1] * gradsuvw[i][1] + invjac[1][2] * gradsuvw[i][2];
        dNdz = invjac[2][0] * gradsuvw[i][0] + invjac[2][1] * gradsuvw[i][1] + invjac[2][2] * gradsuvw[i][2];

        MVertex *v = e->getShapeFunctionNode(i);
        dfdx = dfdx + std::abs((*_ls)(v->x(), v->y(), v->z())) * dNdx ;
        dfdx = dfdx + (*_ls)(v->x(), v->y(), v->z()) * dNdx;
        dfdy = dfdy + std::abs((*_ls)(v->x(), v->y(), v->z())) * dNdy ;
        dfdy = dfdy + (*_ls)(v->x(), v->y(), v->z()) * dNdy;
        dfdz = dfdz + std::abs((*_ls)(v->x(), v->y(), v->z())) * dNdz ;
        dfdz = dfdz + (*_ls)(v->x(), v->y(), v->z()) * dNdz;
      }
    }
  }


        // ---- F1 ------ //

//
//        SPoint3 p(x,y,z);
//        if (e->getParent()) e = e->getParent();
//        double xyz[3] = {x,y,z};
//        double uvw[3];
//        e->xyz2uvw(xyz,uvw);
//        double gradsuvw[256][3];
//        e->getGradShapeFunctions(uvw[0],uvw[1],uvw[2],gradsuvw);
//
//        double jac[3][3];
//        double invjac[3][3];
//        double dNdx;
//        double dNdy;
//        double dNdz;
//        const double detJ = e->getJacobian(uvw[0], uvw[1], uvw[2], jac);
//        inv3x3(jac, invjac);
//
//        dfdx = 0;
//        dfdy = 0;
//        dfdz = 0;
//
//        if ((*_ls)(x,y,z)>0)
//        {
//          for (int i = 0; i < e->getNumShapeFunctions(); i++)
//          {
//            dNdx = invjac[0][0] * gradsuvw[i][0] + invjac[0][1] * gradsuvw[i][1] + invjac[0][2] * gradsuvw[i][2];
//            dNdy = invjac[1][0] * gradsuvw[i][0] + invjac[1][1] * gradsuvw[i][1] + invjac[1][2] * gradsuvw[i][2];
//            dNdz = invjac[2][0] * gradsuvw[i][0] + invjac[2][1] * gradsuvw[i][1] + invjac[2][2] * gradsuvw[i][2];
//
//            MVertex *v = e->getShapeFunctionNode(i);
//            dfdx = dfdx + (*_ls)(v->x(), v->y(), v->z()) * dNdx;
//            dfdy = dfdy + (*_ls)(v->x(), v->y(), v->z()) * dNdy;
//            dfdz = dfdz + (*_ls)(v->x(), v->y(), v->z()) * dNdz;
//          }
//        }else
//        {
//          for (int i = 0; i < e->getNumShapeFunctions(); i++)
//          {
//            dNdx = invjac[0][0] * gradsuvw[i][0] + invjac[0][1] * gradsuvw[i][1] + invjac[0][2] * gradsuvw[i][2];
//            dNdy = invjac[1][0] * gradsuvw[i][0] + invjac[1][1] * gradsuvw[i][1] + invjac[1][2] * gradsuvw[i][2];
//            dNdz = invjac[2][0] * gradsuvw[i][0] + invjac[2][1] * gradsuvw[i][1] + invjac[2][2] * gradsuvw[i][2];
//
//            MVertex *v = e->getShapeFunctionNode(i);
//            dfdx = dfdx - (*_ls)(v->x(), v->y(), v->z()) * dNdx;
//            dfdy = dfdy - (*_ls)(v->x(), v->y(), v->z()) * dNdy;
//            dfdz = dfdz - (*_ls)(v->x(), v->y(), v->z()) * dNdz;
//          }
//        }
//   }

};

#endif
