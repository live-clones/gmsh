#ifndef _PARAMCOORD_H_
#define _PARAMCOORD_H_



class ParamCoord
{

public:

  virtual void exportParamCoord(MVertex *v, const SPoint3 &uvw) {};
  virtual int nCoord(MVertex* vert) = 0;                                                 // Number of parametric coordinates for vertex
  virtual SPoint3 getUvw(MVertex* vert) = 0;                                             // Get parametric coordinates of vertex
  virtual SPoint3 uvw2Xyz(MVertex* vert, const SPoint3 &uvw) = 0;                        // Calculate physical coordinates from parametric coordinates of vertex
  virtual void gXyz2gUvw(MVertex* vert, const SPoint3 &uvw, const SPoint3 &gXyz, SPoint3 &gUvw) = 0; // Calculate derivatives w.r.t parametric coordinates
  virtual void gXyz2gUvw(MVertex* vert, const SPoint3 &uvw, const std::vector<SPoint3> &gXyz, std::vector<SPoint3> &gUvw) = 0; // Calculate derivatives w.r.t parametric coordinates
  virtual ~ParamCoord() {}

};



class ParamCoordPhys3D : public ParamCoord
{

public:

  int nCoord(MVertex* vert) { return 3; }
  virtual SPoint3 getUvw(MVertex* vert) { return vert->point(); }
  virtual SPoint3 uvw2Xyz(MVertex* vert, const SPoint3 &uvw) { return uvw; }
  virtual void gXyz2gUvw(MVertex* vert, const SPoint3 &uvw, const SPoint3 &gXyz, SPoint3 &gUvw) { gUvw = gXyz; }
  virtual void gXyz2gUvw(MVertex* vert, const SPoint3 &uvw, const std::vector<SPoint3> &gXyz, std::vector<SPoint3> &gUvw)
  {
    std::vector<SPoint3>::iterator itUvw=gUvw.begin();
    for (std::vector<SPoint3>::const_iterator itXyz=gXyz.begin(); itXyz != gXyz.end(); itXyz++) {
      *itUvw = *itXyz;
      itUvw++;
    }
  }

};



class ParamCoordPhys2D : public ParamCoord
{

public:

  int nCoord(MVertex* vert) { return 2; }
  virtual SPoint3 getUvw(MVertex* vert) { return vert->point(); }
  virtual SPoint3 uvw2Xyz(MVertex* vert, const SPoint3 &uvw) { return uvw; }
  virtual void gXyz2gUvw(MVertex* vert, const SPoint3 &uvw, const SPoint3 &gXyz, SPoint3 &gUvw) { gUvw = gXyz; }
  virtual void gXyz2gUvw(MVertex* vert, const SPoint3 &uvw, const std::vector<SPoint3> &gXyz, std::vector<SPoint3> &gUvw)
  {
    std::vector<SPoint3>::iterator itUvw=gUvw.begin();
    for (std::vector<SPoint3>::const_iterator itXyz=gXyz.begin(); itXyz != gXyz.end(); itXyz++) {
      *itUvw = *itXyz;
      itUvw++;
    }
  }

};



class ParamCoordSurf : public ParamCoord
{

public:

  ParamCoordSurf(GEntity *ge);
  int nCoord(MVertex* vert) { return 2; }
  virtual SPoint3 getUvw(MVertex* vert);
  virtual SPoint3 uvw2Xyz(MVertex* vert, const SPoint3 &uvw);
  virtual void gXyz2gUvw(MVertex* vert, const SPoint3 &uvw, const SPoint3 &gXyz, SPoint3 &gUvw);
  virtual void gXyz2gUvw(MVertex* vert, const SPoint3 &uvw, const std::vector<SPoint3> &gXyz, std::vector<SPoint3> &gUvw);

private:

  GFace *_gf;

};



class ParamCoordParent : public ParamCoord
{

public:

  int nCoord(MVertex* vert) { return vert->onWhat()->dim(); }
  virtual void exportParamCoord(MVertex *v, const SPoint3 &uvw);
  virtual SPoint3 getUvw(MVertex* vert);
  virtual SPoint3 uvw2Xyz(MVertex* vert, const SPoint3 &uvw);
  virtual void gXyz2gUvw(MVertex* vert, const SPoint3 &uvw, const SPoint3 &gXyz, SPoint3 &gUvw);
  virtual void gXyz2gUvw(MVertex* vert, const SPoint3 &uvw, const std::vector<SPoint3> &gXyz, std::vector<SPoint3> &gUvw);

};



#endif
