//
// Description : XFEM elasticity solver implementation
//
//
// Author:  <Eric Bechet>::<Boris Sedji>,  01/2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "VectorXFEMFS.h"
#include "SPoint3.h"

void ScalarLagrangeToXfemFS::f(MVertex *ver, std::vector<ValType> &vals)
{
    if (!(*_TagEnrichedVertex)[ver->getNum()]) vals.push_back(1.0);
    else
    {
        double func = (*_funcEnrichment)(ver->x(),ver->y(),ver->z());
        vals.push_back(1.0);
        vals.push_back(func);
    }
}

void ScalarLagrangeToXfemFS::f(MElement *ele, double u, double v, double w, std::vector<ValType> &vals)
{
    // Enrichment function calcul
    SPoint3 p;
    ele->pnt(u, v, w, p);
    double func;
    func = (*_funcEnrichment)(p.x(), p.y(), p.z());

    // We need parent parameters
    if (ele->getParent()) ele = ele->getParent();

    int ndofs,normaldofs;
    ndofs = ele->getNumVertices();
    normaldofs = ndofs;

    for (int i=0 ;i<ele->getNumVertices();i++)
    {
        if ((*_TagEnrichedVertex)[ele->getVertex(i)->getNum()]) ndofs = ndofs + 1; // enriched dof
    }

    int curpos=vals.size();
    vals.resize(curpos+ndofs);

    // normal shape functions
    ele->getShapeFunctions(u, v, w, &(vals[curpos]));

    int k=0;
    for (int i=0 ;i<ele->getNumVertices();i++)
    {
        if ((*_TagEnrichedVertex)[ele->getVertex(i)->getNum()])
        {
            vals[curpos+normaldofs+k] = vals[curpos+i]*func;  // enriched dof
            k++;
        }
    }

};

void ScalarLagrangeToXfemFS::gradf(MElement *ele, double u, double v, double w,std::vector<GradType> &grads)
{
    // Enrichment function calcul
    SPoint3 p;
    ele->pnt(u, v, w, p);
    double func;
    func = (*_funcEnrichment)(p.x(), p.y(), p.z());

    // We need parent parameters
    if (ele->getParent()) ele = ele->getParent();

    int ndofs,normaldofs;
    ndofs=  ele->getNumVertices();
    normaldofs = ndofs;  // normal dofs

    for (int i=0 ;i< (ele->getNumVertices());i++)
    {
        if ((*_TagEnrichedVertex)[ele->getVertex(i)->getNum()]) ndofs = ndofs + 1; // enriched dof
    }

    int curpos = grads.size();
    grads.reserve(curpos+ndofs);
    double gradsuvw[256][3];
    ele->getGradShapeFunctions(u, v, w, gradsuvw);

    int k = 0;
    for (int i=0 ;i<(ele->getNumVertices());i++)
    {
        if ((*_TagEnrichedVertex)[ele->getVertex(i)->getNum()]) // enriched dof
        {
            gradsuvw[curpos+normaldofs+k][0] = gradsuvw[curpos+i][0]*func;
            gradsuvw[curpos+normaldofs+k][1] = gradsuvw[curpos+i][1]*func;
            gradsuvw[curpos+normaldofs+k][2] = gradsuvw[curpos+i][2]*func;
            k++;
        }
    }

    double jac[3][3];
    double invjac[3][3];
    const double detJ = ele->getJacobian(u, v, w, jac);
    // redondant : on fait cet appel a l'exterieur
    inv3x3(jac, invjac);
    for (int i=0;i<ndofs;++i)
        grads.push_back(GradType(
                            invjac[0][0] * gradsuvw[i][0] + invjac[0][1] * gradsuvw[i][1] + invjac[0][2] * gradsuvw[i][2],
                            invjac[1][0] * gradsuvw[i][0] + invjac[1][1] * gradsuvw[i][1] + invjac[1][2] * gradsuvw[i][2],
                            invjac[2][0] * gradsuvw[i][0] + invjac[2][1] * gradsuvw[i][1] + invjac[2][2] * gradsuvw[i][2]
                        ));


};

int ScalarLagrangeToXfemFS::getNumKeys(MElement *ele)
{
    // We need parent parameters
    if (ele->getParent()) ele = ele->getParent();
    int ndofs;
    ndofs = ele->getNumVertices();
    {
        for (int i=0 ;i<(ele->getNumVertices());i++)
        {
            if ((*_TagEnrichedVertex)[ele->getVertex(i)->getNum()]) ndofs = ndofs + 1;
        }
    }
    return ndofs;
}

int ScalarLagrangeToXfemFS::getNumKeys(MVertex *ver)
{
    if (!(*_TagEnrichedVertex)[ver->getNum()]) return 1 ;
    else return 2; // if enriched vertex, there is two dof at this vertex (one dimension)
}

void ScalarLagrangeToXfemFS::getKeys(MElement *ele, std::vector<Dof> &keys)
{
    if (ele->getParent()) ele = ele->getParent();
    // vector of additionals keys
    std::vector<Dof> SupKeys;
    // vector of all vertex dof keys
    std::vector<Dof> VertexKeys;

    int ndofs,normaldofs;
    ndofs = ele->getNumVertices();

    for (int i=0 ;i<(ele->getNumVertices());i++)
    {
        if ((*_TagEnrichedVertex)[ele->getVertex(i)->getNum()]) ndofs = ndofs + 1;
    }

    keys.reserve(keys.size()+ndofs);

    // the order of dof in one element of three vertex is u1x u2x u3x a1x a2x a3x u1y, etc...
    for (int i=0;i< (ele->getNumVertices()) ;++i)
    {
        getKeys(ele->getVertex(i), VertexKeys);
        if (VertexKeys.size()>1) SupKeys.push_back(VertexKeys[1]);
        keys.push_back(VertexKeys[0]);
        VertexKeys.clear();
    }

    for (int i=0;i< SupKeys.size() ;++i) keys.push_back(SupKeys[i]);

}


void ScalarLagrangeToXfemFS::getKeys(MVertex *ver, std::vector<Dof> &keys)
{
    if ((*_TagEnrichedVertex)[ver->getNum()])
    {
        keys.push_back(Dof(ver->getNum(), _iField));
        keys.push_back(Dof(ver->getNum(), _iField+1)); // we tag the additional dof with number field+1
    }
    else keys.push_back(Dof(ver->getNum(), _iField));
};

