// TODO: Copyright

#ifndef _MESHQUALITYOBJCONTRIBINVCOND_H_
#define _MESHQUALITYOBJCONTRIBINVCOND_H_

#include "MeshOptPatch.h"
#include "MeshOptObjContrib.h"


template<class FuncType>
class ObjContribInvCondNum : public ObjContrib, public FuncType
{
public:
  ObjContribInvCondNum(double weight);
  virtual ~ObjContribInvCondNum() {}
  virtual ObjContrib *copy() const;
  virtual void initialize(Patch *mesh);
  virtual bool fail() { return false; }
  virtual bool addContrib(double &Obj, alglib::real_1d_array &gradObj);
  virtual void updateParameters() { FuncType::updateParameters(_min, _max); }
  virtual bool targetReached() { return FuncType::targetReached(_min, _max); }
  virtual bool stagnated() { return FuncType::stagnated(_min, _max); }
  virtual void updateMinMax();

protected:
  Patch *_mesh;
  double _weight;
};


template<class FuncType>
ObjContribInvCondNum<FuncType>::ObjContribInvCondNum(double weight) :
  ObjContrib("InvCondNum", FuncType::getNamePrefix()+"InvCondNum"),
  _mesh(0), _weight(weight)
{
}


template<class FuncType>
ObjContrib *ObjContribInvCondNum<FuncType>::copy() const
{
  return new ObjContribInvCondNum<FuncType>(*this);
}


template<class FuncType>
void ObjContribInvCondNum<FuncType>::initialize(Patch *mesh)
{
  _mesh = mesh;
  _mesh->initInvCondNum();
  updateMinMax();
  FuncType::initialize(_min, _max);
}


template<class FuncType>
bool ObjContribInvCondNum<FuncType>::addContrib(double &Obj, alglib::real_1d_array &gradObj)
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for (int iEl = 0; iEl < _mesh->nEl(); iEl++) {
    std::vector<double> invCond(_mesh->nICNEl(iEl));                                  // Min. of Metric
    std::vector<double> gInvCond(_mesh->nICNEl(iEl)*_mesh->nPCEl(iEl));               // Dummy gradients of metric min.
    _mesh->invCondNumAndGradients(iEl, invCond, gInvCond);
    for (int l = 0; l < _mesh->nICNEl(iEl); l++) {                                    // Add contribution for each Bezier coeff.
      Obj += _weight * FuncType::compute(invCond[l]);
      const double dfact = _weight * FuncType::computeDiff(invCond[l]);
      for (int iPC = 0; iPC < _mesh->nPCEl(iEl); iPC++)
        gradObj[_mesh->indPCEl(iEl,iPC)] += dfact *  gInvCond[_mesh->indGICN(iEl, l, iPC)];
      _min = std::min(_min, invCond[l]);
      _max = std::max(_max, invCond[l]);
    }
  }

  return true;
}


template<class FuncType>
void ObjContribInvCondNum<FuncType>::updateMinMax()
{
  _min = BIGVAL;
  _max = -BIGVAL;

  for (int iEl = 0; iEl < _mesh->nEl(); iEl++) {
    std::vector<double> invCond(_mesh->nICNEl(iEl));                            // Min. of Metric
    std::vector<double> dumGInvCond(_mesh->nICNEl(iEl)*_mesh->nPCEl(iEl));      // Dummy gradients of metric min.
    _mesh->invCondNumAndGradients(iEl, invCond, dumGInvCond);
    for (int l = 0; l < _mesh->nICNEl(iEl); l++) {                              // Add contribution for each Bezier coeff.
      _min = std::min(_min, invCond[l]);
      _max = std::max(_max, invCond[l]);
    }
  }
}


#endif /* _MESHQUALITYOBJCONTRIBINVCOND_H_ */
