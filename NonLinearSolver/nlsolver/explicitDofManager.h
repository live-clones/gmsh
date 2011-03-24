//
// C++ Interface: dof manager for dynamic problems
//
// Description:  derive the dofManager for a dynamic problem (access to velocities and acceleration)
//               and contains a mass matrix
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef EXPLICITDOFMANAGER_H_
#define EXPLICITDOFMANAGER_H_

#include "staticDofManager.h"
#include "explicitHulbertChung.h"
template<class T>
class explicitHCDofManager : public staticDofManager<T>{
 protected:
  // map to have the initial conditions BC for positions, velocities and acceleration
  //std::map<Dof, std::vector<dataVec> > initial; position in dofManager.h not used ??
  std::map<Dof, typename dofManager<T>::dataVec> _initpositions;
  std::map<Dof, typename dofManager<T>::dataVec> _initvelocities;
  std::map<Dof, typename dofManager<T>::dataVec> _initaccelerations;

  // for prescribed velocities and accelerations
  std::map<Dof, typename dofManager<T>::dataVec> _fixedpositions; // needed to compute velocities (position of last time step)
  std::map<Dof, typename dofManager<T>::dataVec> _fixedvelocities;
  std::map<Dof, typename dofManager<T>::dataVec> _fixedaccelerations;
  std::map<Dof, typename dofManager<T>::dataVec> _fixedmass; // needed to compute kinetic energy

  // pointer to an explicit system (allow to avoid multi dynamic_cast)
  explicitHulbertChung<T> *_currentExpl;

 public:
  explicitHCDofManager(linearSystem< typename dofManager<T>::dataMat> *l) : staticDofManager<T>(l){
    _currentExpl = dynamic_cast<explicitHulbertChung<T>*>(l);
  }
  explicitHCDofManager(linearSystem< typename dofManager<T>::dataMat > *l1, linearSystem< typename dofManager<T>::dataMat > *l2){
    _currentExpl = dynamic_cast<explicitHulbertChung<T> >(l1);
  }

  // Function assemble matrix is rewritten to allow to have 2 matrix stiffness and mass
  virtual inline void assemble(std::vector<Dof> &R, const fullMatrix<typename dofManager<T>::dataMat> &m,
                               const typename explicitHulbertChung<T>::whichMatrix wm=explicitHulbertChung<T>::stiff){
    if (!this->_current->isAllocated()) this->_current->allocate(this->unknown.size());
    std::vector<int> NR(R.size());
    for (unsigned int i = 0; i < R.size(); i++)
    {
      std::map<Dof, int>::iterator itR = this->unknown.find(R[i]);
      if (itR != this->unknown.end()) NR[i] = itR->second;
      else NR[i] = -1;
    }
    if(wm == explicitHulbertChung<T>::stiff)
    {
      for (unsigned int i = 0; i < R.size(); i++)
      {
        if (NR[i] != -1)
        {
          for (unsigned int j = 0; j < R.size(); j++)
          {
            if (NR[j] != -1)
            {
              this->_current->addToMatrix(NR[i], NR[j], m(i, j));
            }
            else
            {
              typename std::map<Dof,  typename dofManager<T>::dataVec>::iterator itFixed = this->fixed.find(R[j]);
              if (itFixed == this->fixed.end())
                assembleLinConst(R[i],R[j],m(i,j));
            }
          }
        }
        else
        {
          for (unsigned int j = 0; j < R.size(); j++){
          assembleLinConst(R[i],R[j],m(i,j));
          }
        }
      }
    }
    else{ // mass matrix
      for (unsigned int i = 0; i < R.size(); i++)
        if (NR[i] != -1)
          for (unsigned int j = 0; j < R.size(); j++)
            //if (NR[j] != -1)
              this->_currentExpl->addToMatrix(NR[i], NR[j], m(i, j),explicitHulbertChung<T>::mass);
        else{ // store mass in _fixedmass
          double linemass=0.;
          // if already exist in _fixed mass retrieve value to add sum because diagonal matrix
          typename std::map<Dof,typename dofManager<T>::dataVec>::iterator itm = this->_fixedmass.find(R[i]);
          if(itm != this->_fixedmass.end())
            linemass+=itm->second;
          for(unsigned int j=0; j<R.size(); j++)
            linemass+=m(i,j);
          this->_fixedmass[R[i]] = linemass;
        }
    }
  }

  // Function to fix dof (fix velocities and acceleration Too. Must be modified to prescribed a velocities or an acceleration)
  inline void fixDof(Dof key, const typename dofManager<T>::dataVec &value){
     if(this->unknown.find(key) != this->unknown.end())
      return;
    this->fixed[key] = value;
    this->_fixedvelocities[key]=0.;
    this->_fixedaccelerations[key]=0.;
    this->RHSfixed[key]=0.;
  }

  // function with get operation (WARNING All getDofValue are not redifined)
  virtual inline void getDofValue(std::vector<Dof> &keys,std::vector<typename dofManager<T>::dataVec> &Vals,
                                    const typename initialCondition::whichCondition wv= initialCondition::position)
  {
    int ndofs=keys.size();
    size_t originalSize = Vals.size();
    Vals.resize(originalSize+ndofs);
    for (int i=0;i<ndofs;++i) getDofValue(keys[i], Vals[originalSize+i],wv);
  }

  virtual inline void getDofValue(Dof key,  typename dofManager<T>::dataVec &val,
                                  initialCondition::whichCondition wv= initialCondition::position) const
  {
   switch(wv){
    case initialCondition::position:
     {
       typename std::map<Dof, typename dofManager<T>::dataVec>::const_iterator it = this->fixed.find(key);
       if (it != this->fixed.end()) {
         val =  it->second;
         return ;
       }
     }
     {
       std::map<Dof, int>::const_iterator it = this->unknown.find(key);
       if (it != this->unknown.end()) {
         _currentExpl->getFromSolution(it->second, val,wv);
         return;
       }
     }
     {
       typename std::map<Dof, DofAffineConstraint< typename dofManager<T>::dataVec > >::const_iterator it = this->constraints.find(key);
       if (it != this->constraints.end())
       {
          typename dofManager<T>::dataVec tmp(val);
          val = it->second.shift;
          for (unsigned i=0;i<(it->second).linear.size();i++)
          {
             std::map<Dof, int>::const_iterator itu = this->unknown.find(((it->second).linear[i]).first);
             getDofValue(((it->second).linear[i]).first, tmp);
             dofTraits<T>::gemm(val,((it->second).linear[i]).second, tmp, 1, 1);
          }
          return ;
       }
     }
     break;
     case initialCondition::velocity:
     {
       typename std::map<Dof, typename dofManager<T>::dataVec>::const_iterator it = this->_fixedvelocities.find(key);
       if (it != this->_fixedvelocities.end()) {
         val =  it->second;
         return ;
       }
     }
     {
       std::map<Dof, int>::const_iterator it = this->unknown.find(key);
       if (it != this->unknown.end()) {
         _currentExpl->getFromSolution(it->second, val,wv);
         return;
       }
     }
     break;
     case initialCondition::acceleration:
     {
       typename std::map<Dof, typename dofManager<T>::dataVec>::const_iterator it = this->_fixedaccelerations.find(key);
       if (it != this->_fixedaccelerations.end()) {
         val =  it->second;
         return ;
       }
     }
     {
       std::map<Dof, int>::const_iterator it = this->unknown.find(key);
       if (it != this->unknown.end()) {
         _currentExpl->getFromSolution(it->second, val,wv);
         return;
       }
     }
     break;
    }
  }

  // specific functions tfor initial conditions
  // I don't use the initial vector because initial conditions are given directly
  // to the solver
  virtual inline void setInitialCondition(const Dof &R, const typename dofManager<T>::dataVec &value,
                                          const typename initialCondition::whichCondition wc){

    if (!this->_current->isAllocated()) this->_current->allocate(this->unknown.size());
    // find the dof in map if not find -1
    int NR=-1;
    std::map<Dof, int>::iterator itR = this->unknown.find(R);
    if (itR != this->unknown.end()){
      NR = itR->second;
      _currentExpl->setInitialCondition(NR, value,wc);
    }
    else{ // insert the initial conditions
      typename std::map<Dof, typename dofManager<T>::dataVec>::iterator it;
      if(wc == initialCondition::position){
        this->_initpositions[R] = value;
        // Find if the two others exist. If not set to zero
        it = this->_initvelocities.find(R);
        if (it == this->_initvelocities.end()) _initvelocities[R] = 0.;
        it = this->_initaccelerations.find(R);
        if (it == this->_initaccelerations.end()) _initaccelerations[R] = 0.;
        // set initial position in fixedpos or 0
         _fixedpositions[R] = value;
    }
      else if(wc == initialCondition::velocity){
        _initvelocities[R] = value;
        // Find if the two others exist. If not set to zero
        it = this->_initpositions.find(R);
        if (it == this->_initpositions.end()) this->_initpositions[R] = 0.;
        it = this->_initaccelerations.find(R);
        if (it == this->_initaccelerations.end()) _initaccelerations[R] = 0.;
         _fixedpositions[R] = 0.;
      }
      else if(wc == initialCondition::acceleration){
        _initaccelerations[R] = value;
        // Find if the two others exist. If not set to zero
        it = this->_initpositions.find(R);
        if (it == this->_initpositions.end()) this->_initpositions[R] = 0.;
        it = this->_initvelocities.find(R);
        if (it == this->_initvelocities.end()) _initvelocities[R] = 0.;
        _fixedpositions[R] = 0.;
      }
    }
  }

  // Function to update the fixed dof value
  // must be rewritten to take into account a fixed velocity
  virtual void updateFixedDof(const double timeStep){
    // loop
    for(typename std::map<Dof, typename dofManager<T>::dataVec>::iterator it=this->fixed.begin(); it!=this->fixed.end(); ++it){
      // watch for an initial position
      typename std::map<Dof, typename dofManager<T>::dataVec>::iterator itpos = _initpositions.find(it->first);
      double initpos=0.;
      typename dofManager<T>::dataVec lastpos=_fixedpositions[it->first];
      typename dofManager<T>::dataVec lastvelo = _fixedvelocities[it->first];
      if(itpos != _initpositions.end() ) initpos = itpos->second;
      it->second = it->second + initpos;
      _fixedpositions[it->first] = it->second;
      _fixedvelocities.find(it->first)->second = (it->second - lastpos)/timeStep;
      // update acceleration with plexus manual theory
      //_fixedaccelerations.find(it->first)->second = (it->second/timeStep - _fixedvelocities.find(it->first)->second)/timeStep;
      _fixedaccelerations.find(it->first)->second = 0.; //(_fixedvelocities.find(it->first)->second -lastvelo)/timeStep;
    }
  }
  virtual void getVertexMass(std::vector<Dof> &R, std::vector<typename dofManager<T>::dataVec> &vmass){
    if(this->_current->isAllocated()){
      std::map<Dof, int>::const_iterator it;
      double mass;
      for(int i=0;i<R.size(); i++){
        it = this->unknown.find(R[i]);
        if(it != this->unknown.end()){
          _currentExpl->getFromMatrix(it->second,it->second,mass);
          vmass.push_back(mass);
        }
        else{  // find mass in _fixedmass
          typename std::map<Dof,typename dofManager<T>::dataVec>::iterator itm = this->_fixedmass.find(R[i]);
          if(itm != _fixedmass.end()) vmass.push_back(itm->second);
          else vmass.push_back(0.);
        }
      }
    }
    else{
      for(int i=0;i<R.size(); i++) vmass.push_back(0.);
    }
  }

  // Function to get global kinetic energy. Used vector PETSC function so it's more quick
  double getKineticEnergy() const{
    double ener = _currentExpl->getKineticEnergy(); // energy of free dofs
    // add energy of fixed dof
    for(typename std::map<Dof,typename dofManager<T>::dataVec>::const_iterator it = _fixedmass.begin(); it!=_fixedmass.end(); ++it){
      double mv = it->second;
      double v = 0.;
      typename std::map<Dof,typename dofManager<T>::dataVec>::const_iterator itv = _fixedvelocities.find(it->first);
      if(itv != _fixedvelocities.end()) v = itv->second;
      ener += 0.5*mv*v*v;
    }
    return ener;
  }

  // Print Right Hand Side (Use for debug)
  void printRightHandSide() const{
    Msg::Info("Right Hand Side");
    for(std::map<Dof,int>::const_iterator it=this->unknown.begin(); it!=this->unknown.end(); ++it){
      double force;
      _currentExpl->getFromRightHandSide(it->second,force);
      Msg::Info("Dof Ent: %d Dof Type %d value %e",it->first.getEntity(),it->first.getType(),force);
    }
  }
};
#endif // EXPLICITDOFMANAGER_H_

