//
// Description : Filtered and xFem function space definition
//
//
// Author:  <Eric Bechet>::<Boris Sedji>,  02/2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "xFemFunctionSpace.h"


template <class T> void xFemFS<T>::f(MElement *ele, double u, double v, double w,std::vector<ValType> &vals)
{
   // We need parent parameters
    MElement * elep;
    if (ele->getParent()) elep = ele->getParent();
    else elep = ele;

    // Get the spacebase valsd
    std::vector<ValType> valsd;
    xFemFunctionSpace<T>::_spacebase->f(elep,u,v,w,valsd);

    int nbdofs=valsd.size();
    int curpos=vals.size();  // if in composite function space
    vals.reserve(curpos+nbdofs);

    // then enriched dofs so the order is ex:(a2x,a2y,a3x,a3y)
    if (nbdofs>0) // if enriched
    {
        // Enrichment function calcul
        SPoint3 p;
        elep->pnt(u, v, w, p); // parametric to cartesian coordinates
        double func;
        func = (*_funcEnrichment)(p.x(), p.y(), p.z(),elep);
        for (int i=0 ;i<nbdofs;i++)
        {
            vals.push_back(valsd[i]*func);
        }
    }
}

template <class T> void xFemFS<T>::gradf(MElement *ele, double u, double v, double w,std::vector<GradType> &grads)
{

    // We need parent parameters
    MElement * elep;
    if (ele->getParent()) elep = ele->getParent();
    else elep = ele;

    // Get the spacebase gradsd
    std::vector<GradType> gradsd;
    xFemFunctionSpace<T>::_spacebase->gradf(elep,u,v,w,gradsd);


    int nbdofs=gradsd.size();

    // We need spacebase valsd to compute total gradient
    std::vector<ValType> valsd;
    xFemFunctionSpace<T>::_spacebase->f(elep,u,v,w,valsd);

    int curpos=grads.size();  // if in composite function space
    grads.reserve(curpos+nbdofs);

    // then enriched dofs so the order is ex:(a2x,a2y,a3x,a3y)
    if (nbdofs>0) // if enriched
    {
        double df[3];
        SPoint3 p;
        elep->pnt(u, v, w, p);
        _funcEnrichment->gradient (p.x(), p.y(),p.z(),df[0],df[1],df[2],elep);
        ValType gradfuncenrich(df[0],df[1],df[2]);

        // Enrichment function calcul

        double func;
        func = (*_funcEnrichment)(p.x(), p.y(), p.z(),elep);

        for (int i=0 ;i<nbdofs;i++)
        {
          GradType GradFunc;
          tensprod(valsd[i],gradfuncenrich,GradFunc);
          grads.push_back(gradsd[i]*func + GradFunc);
        }
    }
}

template <class T> int xFemFS<T>::getNumKeys(MElement *ele)
{
    MElement * elep;
    if (ele->getParent()) elep = ele->getParent();
    else elep = ele;
    int nbdofs = xFemFunctionSpace<T>::_spacebase->getNumKeys(ele);
    return nbdofs;
}

template <class T> void xFemFS<T>::getKeys(MElement *ele, std::vector<Dof> &keys)
{
    MElement * elep;
    if (ele->getParent()) elep = ele->getParent();
    else elep = ele;

    int normalk=xFemFunctionSpace<T>::_spacebase->getNumKeys(elep);

    std::vector<Dof> bufk;
    bufk.reserve(normalk);
    xFemFunctionSpace<T>::_spacebase->getKeys(elep,bufk);
    int normaldofs=bufk.size();
    int nbdofs = normaldofs;

    int curpos=keys.size();
    keys.reserve(curpos+nbdofs);

    // get keys so the order is ex:(a2x,a2y,a3x,a3y)
    // enriched dof tagged with ( i2 -> i2 + 1 )
    for (int i=0 ;i<nbdofs;i++)
    {
        int i1,i2;
        Dof::getTwoIntsFromType(bufk[i].getType(), i1,i2);
        keys.push_back(Dof(bufk[i].getEntity(),Dof::createTypeWithTwoInts(i1,i2+1)));
    }
}


// Filtered function space
//

template <class T> void FilteredFS<T>::f(MElement *ele, double u, double v, double w,std::vector<ValType> &vals)
{
    // We need parent parameters
    MElement * elep;
    if (ele->getParent()) elep = ele->getParent();
    else elep = ele;

    std::vector<ValType> valsd;

    FilteredFunctionSpace<T,FilterNodeEnriched>::_spacebase->f(elep,u,v,w,valsd);

    int normalk=FilteredFunctionSpace<T,FilterNodeEnriched>::_spacebase->getNumKeys(elep);
    std::vector<Dof> bufk;
    bufk.reserve(normalk);
    FilteredFunctionSpace<T,FilterNodeEnriched>::_spacebase->getKeys(elep,bufk);

    for (int i=0;i<bufk.size();i++)
    {
      if ((*FilteredFunctionSpace<T,FilterNodeEnriched>::_filter)(bufk[i]))
        vals.push_back(valsd[i]);
    }

}


template <class T> void FilteredFS<T>::gradf(MElement *ele, double u, double v, double w,std::vector<GradType> &grads)
{
    // We need parent parameters
    MElement * elep;
    if (ele->getParent()) elep = ele->getParent();
    else elep = ele;

    // Get space base gradsd
    std::vector<GradType> gradsd;
    FilteredFunctionSpace<T,FilterNodeEnriched>::_spacebase->gradf(elep,u,v,w,gradsd);

    // Get numkeys
    int normalk=FilteredFunctionSpace<T,FilterNodeEnriched>::_spacebase->getNumKeys(elep);
    std::vector<Dof> bufk;
    bufk.reserve(normalk);
    FilteredFunctionSpace<T,FilterNodeEnriched>::_spacebase->getKeys(elep,bufk);

    for (int i=0;i<bufk.size();i++)
    {
      if ( (*FilteredFunctionSpace<T,FilterNodeEnriched>::_filter)(bufk[i]))
        grads.push_back(gradsd[i]);
    }

}

template <class T> int FilteredFS<T>::getNumKeys(MElement *ele)
{
    MElement *elep;
    if (ele->getParent()) elep = ele->getParent();
    else elep = ele;

    int nbdofs = 0;

    int normalk=FilteredFunctionSpace<T,FilterNodeEnriched>::_spacebase->getNumKeys(elep);
    std::vector<Dof> bufk;
    bufk.reserve(normalk);
    FilteredFunctionSpace<T,FilterNodeEnriched>::_spacebase->getKeys(elep,bufk);

    for (int i=0;i<bufk.size();i++)
    {
      if ( (*FilteredFunctionSpace<T,FilterNodeEnriched>::_filter)(bufk[i]))
        nbdofs = nbdofs + 1;
    }
    return nbdofs;
}

template <class T> void FilteredFS<T>::getKeys(MElement *ele, std::vector<Dof> &keys)
{
    MElement * elep;
    if (ele->getParent()) elep = ele->getParent();
    else elep = ele;

    int normalk=FilteredFunctionSpace<T,FilterNodeEnriched>::_spacebase->getNumKeys(elep);

    std::vector<Dof> bufk;
    bufk.reserve(normalk);
    FilteredFunctionSpace<T,FilterNodeEnriched>::_spacebase->getKeys(elep,bufk);
    int normaldofs=bufk.size();
    int nbdofs = 0;

    for (int i=0;i<bufk.size();i++)
    {
      if ( (*FilteredFunctionSpace<T,FilterNodeEnriched>::_filter)(bufk[i]))
        keys.push_back(bufk[i]);
    }
}

