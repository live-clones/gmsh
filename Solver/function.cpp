#include "function.h"

class functionXYZ : public function{
 private:
  class data : public dataCacheDouble{
   private:
    dataCacheElement &_element;
    dataCacheDouble &_uvw;
   public:
    data(dataCacheMap *m) 
      : dataCache(m), _element(m->getElement(this)), _uvw(m->get("UVW", this))
    {
      _value.resize(_uvw.size1(), 3);
    }
    void eval()
    {
      MElement *ele = _element();
      for(int i = 0; i < _uvw.size1(); i++){
        SPoint3 p;
        ele->pnt(_uvw(i, 0), _uvw(i, 1), _uvw(i, 2), p);
        _value(i, 0) = p.x();
        _value(i, 1) = p.y();
        _value(i, 2) = p.z();
      }
    }
  };
 public:
  dataCache &getDataCache(dataCacheMap *m)
  {
    return new data(m);
  }
};


void registerFunctions()
{
  function::add("XYZ", new functionXYZ);

}
