//
// contact base term
//
// Description: contact term
//
//
// Author:  <Gauthier BECKER>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
#include "contactTerms.h"
#include "unknownField.h"
template<> void rigidContactLinearTermBase<double>::get(MElement *ele, int npts, IntPt *GP,fullVector<double> &m) const
{
  nbdofs = _spc->getNumKeys(ele);
  nbdofsGC = _spc->getNumKeysOfGravityCenter();
  m.resize(nbdofs);
  m.setAll(0.);
  nbvertex = ele->getNumVertices();
  nbcomp = (nbdofs-nbdofsGC)/nbvertex;
  nbcomptimenbvertex = nbvertex*nbcomp;
  // get displacement of vertices (To know the current node positions)
  disp.clear(); R.clear();
  _spc->getKeys(ele,R);

  _ufield->get(R,disp);

  verdisp[3] = disp[nbcomptimenbvertex]; verdisp[4] = disp[nbcomptimenbvertex+1]; verdisp[5] = disp[nbcomptimenbvertex+2];
  for(int i=0;i<nbvertex;i++){
    for(int j=0;j<6;j++) mvalue[j] =0.;
    ver = ele->getVertex(i);
    verdisp[0] = disp[i]; verdisp[1] = disp[i+nbvertex]; verdisp[2] = disp[i+2*nbvertex];
    this->get(ver,verdisp,mvalue);
    // look if there is contact force
    int jj=0;
    while(jj<6){
      if(mvalue[jj] != 0.){
//        Msg::Info("Contact detected on elem %d vertex %d",ele->getNum(),ele->getVertex(i)->getNum());
        _allcontactNode->insert(ele,i,_lastNormalContact);
        for(int j=0;j<nbcomp;j++){
          m(i+j*nbvertex) += mvalue[j];
          m(nbcomptimenbvertex+j) += mvalue[j+3]; // count two times
        }
        break;
      }
      jj++;
    }
  }
 // if(m.norm() != 0.)
//    m.print("contact");
}
