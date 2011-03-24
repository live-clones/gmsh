//
// C++ Interface: energetic field
//
// Description: Class derived from element field to manage energetic balance
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef ENERGETICFIELD_H_
#define ENERGETICFIELD_H_

#include "elementField.h"
#include "nonLinearMechSolver.h"
class energeticField : public elementField{
 protected:
  linearSystem<double> *_lsys;
  IPField *_ipf;
  unknownField *_ufield;
  dofManager<double> *_pAssembler;
  const std::string _fname; // file to store total energy in function of time
  std::vector<partDomain*> &_domvec;
  std::vector<fextPrescribedDisp> &_allaef;
  std::map<Dof,double> _fextn;
  std::map<Dof,double> _dispn;
  std::map<Dof,double> _fextnp1;
  std::map<Dof,double> _dispnp1;

  double _wext;

 public:
  energeticField(linearSystem<double> *lsys, IPField *ipf,
                 unknownField *ufield, dofManager<double> *pAssembler,
                 std::vector<partDomain*> &domvec,
                 std::vector<fextPrescribedDisp> &allaef) : elementField("energy.msh",100000000,1,elementField::ElementData,true),
                                              _lsys(lsys), _ipf(ipf), _ufield(ufield), _pAssembler(pAssembler),
                                              _fname("energy.csv"), _domvec(domvec), _allaef(allaef), _wext(0.){
    // initialize file to store energy
    FILE *fp = fopen(_fname.c_str(),"w");
    fprintf(fp,"Time;Kinetic;Deformation;Wext;Total\n");
    fprintf(fp,"0.;0.;0.;0;0.\n"); // false if initial deformation FIX IT HOW ??
    fclose(fp);
    long int nelem=0;
    for(std::vector<partDomain*>::iterator itdom=_domvec.begin(); itdom!=_domvec.end();++itdom){
      partDomain *dom = *itdom;
      nelem+=dom->g->size();
      for(partDomain::neuContainer::iterator itn=dom->neuBegin(); itn!=dom->neuEnd();++itn){
        nonLinearNeumannBC *neu = *itn;
        FunctionSpaceBase *neuspace = neu->_space;
        std::vector<Dof> R;
        for(groupOfElements::elementContainer::const_iterator it = neu->g->begin(); it!=neu->g->end(); ++it){
          MElement *e = *it;
          R.clear();
          neuspace->getKeys(e,R);
          int ndofs = neuspace->getNumKeys(e);
          for(int i=0;i<ndofs;i++){
            _fextn.insert(std::pair<Dof,double>(R[i],0.));
            _dispn.insert(std::pair<Dof,double>(R[i],0.));
            _fextnp1.insert(std::pair<Dof,double>(R[i],0.));
            _dispnp1.insert(std::pair<Dof,double>(R[i],0.));
          }
        }
      }
    }
    this->setTotElem(nelem);
    // Wext for prescribed displacement
    for(int i=0; i<_allaef.size(); i++){
      _fextn.insert(std::pair<Dof,double>(_allaef[i].D,0.));
      _dispn.insert(std::pair<Dof,double>(_allaef[i].D,0.));
      _fextnp1.insert(std::pair<Dof,double>(_allaef[i].D,0.));
      _dispnp1.insert(std::pair<Dof,double>(_allaef[i].D,0.));
    }
  }
  ~energeticField(){}

  // functions to compute the different parts of energy
  double kineticEnergy() const; // More efficient than a loop on element thanks to vector operation via PETSC
  double kineticEnergy(MElement *ele, const partDomain *dom) const;
  double deformationEnergy(MElement *ele, const partDomain *dom) const;
  double deformationEnergy() const;
  double externalWork();

  void get(partDomain *dom,MElement *ele,std::vector<double> &ener, const int cc = -1);
  void archive(const double time);
};
#endif // ENERGETICFIELD_H_

