//
// Description : From function space to node enriched composant function space
//
//
// Author:  <Eric Bechet>::<Boris Sedji>,  01/2010
//
// Copyright: See COPYING file that comes with this distribution
//
//


#include "NodeEnrichedFS.h"


template <class T> void NodeEnrichedFS<T>::f(MElement *ele, double u, double v, double w, std::vector<ValType> &vals)
{
    // We need parent parameters
    MElement * elep;
    if (ele->getParent()) elep = ele->getParent();
    else elep = ele;

    std::vector<ValType> valsd;
    _SupportFS->f(elep,u,v,w,valsd);
    int normaldofs=valsd.size();

    // nbdofs element calcul
    int nbdofs = normaldofs;
    std::vector<int> EnrichedVertex;
    for (int i=0 ;i<elep->getNumVertices();i++)
    {
        std::set<int>::iterator it;
        it = _TagEnrichedVertex->find(elep->getVertex(i)->getNum());
        if (it!=_TagEnrichedVertex->end())
        {
            EnrichedVertex.push_back(i);
            nbdofs = nbdofs + 1*_EnrichComp->size(); // enriched dof
        }
    }

    int curpos=vals.size();
    vals.reserve(curpos+nbdofs);

    // first normal dofs
    for (int i=0;i<normaldofs;i++) vals.push_back(valsd[i]);

    // then enriched dofs so the order is ex:(u1x,u2x,u3x,u1y,u2y,u3y,a2x,a2y,a3x,a3y)
    if (nbdofs>normaldofs) // if enriched
    {
        // Enrichment function calcul
        SPoint3 p;
        elep->pnt(u, v, w, p);
        double func;
        func = (*_funcEnrichment)(p.x(), p.y(), p.z());

        for (int i=0 ;i<EnrichedVertex.size();i++)
        {
            for (int j=0;j<_EnrichComp->size();j++) vals.push_back(valsd[EnrichedVertex[i]+(_EnrichComp->at(j))*elep->getNumVertices()]*func);
        }
    }


}

template <class T> void NodeEnrichedFS<T>::gradf(MElement *ele, double u, double v, double w,std::vector<GradType> &grads)
{
    // We need parent parameters
    MElement * elep;
    if (ele->getParent()) elep = ele->getParent();
    else elep = ele;

    std::vector<GradType> gradsd;
    _SupportFS->gradf(elep,u,v,w,gradsd);

    int normaldofs=gradsd.size();
    int nbdofs = normaldofs;

    GradType val;

    std::vector<int> EnrichedVertex;

    for (int i=0 ;i<elep->getNumVertices();i++)
    {
        std::set<int>::iterator it;
        it = _TagEnrichedVertex->find(elep->getVertex(i)->getNum());
        if (it!=_TagEnrichedVertex->end())
        {
            EnrichedVertex.push_back(i);
            nbdofs = nbdofs + 1*_EnrichComp->size(); // enriched dof
        }
    }


    int curpos=grads.size();
    grads.reserve(curpos+nbdofs);

    // first normal dofs
    for (int i=0;i<normaldofs;i++) grads.push_back(gradsd[i]);

    // then enriched dofs so the order is ex:(u1x,u2x,u3x,u1y,u2y,u3y,a2x,a2y,a3x,a3y)
    if (nbdofs>normaldofs) // if enriched
    {
        // Enrichment function calcul
        SPoint3 p;
        elep->pnt(u, v, w, p);
        double func;
        func = (*_funcEnrichment)(p.x(), p.y(), p.z());

        for (int i=0 ;i<EnrichedVertex.size();i++)
        {
            for (int j=0;j<_EnrichComp->size();j++){
                grads.push_back(gradsd[EnrichedVertex[i]+(_EnrichComp->at(j))*elep->getNumVertices()]*func);
            }
        }
    }
}


template <class T> int NodeEnrichedFS<T>::getNumKeys(MElement *ele)
{
    MElement * elep;
    if (ele->getParent()) elep = ele->getParent();
    else elep = ele;

    int normaldofs = _SupportFS->getNumKeys(ele);
    int nbdofs = normaldofs;

    for (int i=0 ;i<elep->getNumVertices();i++)
    {
        std::set<int>::iterator it;
        it = _TagEnrichedVertex->find(elep->getVertex(i)->getNum());
        if (it!=_TagEnrichedVertex->end())
        {
            nbdofs = nbdofs + 1*_EnrichComp->size(); // enriched dof
        }
    }
    return nbdofs;
}

template <class T> void NodeEnrichedFS<T>::getKeys(MElement *ele, std::vector<Dof> &keys)
{
    MElement * elep;
    if (ele->getParent()) elep = ele->getParent();
    else elep = ele;

    int normalk=_SupportFS->getNumKeys(elep);

    std::vector<Dof> bufk;
    bufk.reserve(normalk);
    _SupportFS->getKeys(elep,bufk);
    int normaldofs=bufk.size();
    int nbdofs = normaldofs;

    int curpos=keys.size();

    std::vector<int> EnrichedVertex;

    for (int i=0 ;i<elep->getNumVertices();i++)
    {
        std::set<int>::iterator it;
        it = _TagEnrichedVertex->find(elep->getVertex(i)->getNum());
        if (it!=_TagEnrichedVertex->end())
        {
            EnrichedVertex.push_back(i);
            nbdofs = nbdofs + 1*_EnrichComp->size(); // enriched dof
        }
    }

    keys.reserve(curpos+nbdofs);

    // get keys so the order is ex:(u1x,u2x,u3x,u1y,u2y,u3y,a2x,a2y,a3x,a3y)

    for (int i=0;i<bufk.size();i++) keys.push_back(bufk[i]);

    for (int i=0 ;i<EnrichedVertex.size();i++)
    {
        for (int j=0;j<_EnrichComp->size();j++)
        {
            int i1,i2;
            Dof::getTwoIntsFromType(bufk[EnrichedVertex[i]+_EnrichComp->at(j)*elep->getNumVertices()].getType(), i1,i2);
            keys.push_back(Dof(bufk[EnrichedVertex[i]+_EnrichComp->at(j)*elep->getNumVertices()].getEntity(),Dof::createTypeWithTwoInts(_EnrichComp->at(j),i1+1)));
        }
    }
}
