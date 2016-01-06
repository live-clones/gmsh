// Copyright (C) 2013 ULg-UCL
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.
//
// Please report all bugs and problems to the public mailing list
// <gmsh@onelab.info>.
//
// Contributors: Thomas Toulorge, Jonathan Lambrechts

#ifndef _PARAMCOORD_H_
#define _PARAMCOORD_H_

class ParamCoord
{
public:
  // Set param. coord. of MVertex if applicable
  virtual void exportParamCoord(const SPoint3 &uvw) {}
  // Get parametric coordinates of vertex
  virtual SPoint3 getUvw(MVertex* v) = 0;
  // Calculate physical coordinates from parametric coordinates of vertex
  virtual SPoint3 uvw2Xyz(const SPoint3 &uvw) = 0;
  // Calculate derivatives w.r.t parametric coordinates
  virtual void gXyz2gUvw(const SPoint3 &uvw, const SPoint3 &gXyz, SPoint3 &gUvw) = 0;
  // Calculate derivatives w.r.t parametric coordinates
  virtual void gXyz2gUvw(const SPoint3 &uvw,
                         const std::vector<SPoint3> &gXyz, std::vector<SPoint3> &gUvw) = 0;
  virtual ~ParamCoord() {}
};

class ParamCoordPhys3D : public ParamCoord
{
public:
  SPoint3 getUvw(MVertex* v) { return v->point(); }
  SPoint3 uvw2Xyz(const SPoint3 &uvw) { return uvw; }
  void gXyz2gUvw(const SPoint3 &uvw, const SPoint3 &gXyz,
                         SPoint3 &gUvw){ gUvw = gXyz; }
  void gXyz2gUvw(const SPoint3 &uvw, const std::vector<SPoint3> &gXyz, std::vector<SPoint3> &gUvw)
  {
    std::vector<SPoint3>::iterator itUvw=gUvw.begin();
    for (std::vector<SPoint3>::const_iterator itXyz=gXyz.begin(); itXyz != gXyz.end();
         itXyz++) {
      *itUvw = *itXyz;
      itUvw++;
    }
  }
};

class ParamCoordParent : public ParamCoord
{
public:
  ParamCoordParent(MVertex* v) : _vert(v) {}
  void exportParamCoord(const SPoint3 &uvw) {
    for (int d = 0; d < _vert->onWhat()->dim(); ++d) _vert->setParameter(d, uvw[d]);
  }
  SPoint3 getUvw(MVertex* v);
  SPoint3 uvw2Xyz(const SPoint3 &uvw);
  void gXyz2gUvw(const SPoint3 &uvw, const SPoint3 &gXyz, SPoint3 &gUvw);
  void gXyz2gUvw(const SPoint3 &uvw, const std::vector<SPoint3> &gXyz, std::vector<SPoint3> &gUvw);
protected:
  MVertex *_vert;
};

class ParamCoordLocalLine : public ParamCoord
{
public:
  ParamCoordLocalLine(MVertex* v);
  SPoint3 getUvw(MVertex* v) { return SPoint3(0.,0.,0.); }
  SPoint3 uvw2Xyz(const SPoint3 &uvw) {
    return SPoint3(x0+uvw[0]*dir[0],y0+uvw[0]*dir[1],z0+uvw[0]*dir[2]);
  }
  void gXyz2gUvw(const SPoint3 &uvw, const SPoint3 &gXyz, SPoint3 &gUvw) {
    gUvw[0] = gXyz.x()*dir[0] + gXyz.y()*dir[1] + gXyz.z()*dir[2];
  }
  void gXyz2gUvw(const SPoint3 &uvw, const std::vector<SPoint3> &gXyz, std::vector<SPoint3> &gUvw) {
    std::vector<SPoint3>::iterator itUvw = gUvw.begin();
    for (std::vector<SPoint3>::const_iterator itXyz=gXyz.begin();
         itXyz != gXyz.end(); itXyz++) {
      (*itUvw)[0] = itXyz->x()*dir[0] + itXyz->y()*dir[1] + itXyz->z()*dir[2];
      itUvw++;
    }
  }
protected:
  double x0, y0, z0;
  SVector3 dir;
};

class ParamCoordLocalSurf : public ParamCoord
{
public:
  ParamCoordLocalSurf(MVertex* v);
  SPoint3 getUvw(MVertex* v) { return SPoint3(0.,0.,0.); }
  SPoint3 uvw2Xyz(const SPoint3 &uvw) {
    return SPoint3(x0+uvw[0]*dir0[0]+uvw[1]*dir1[0],
                   y0+uvw[0]*dir0[1]+uvw[1]*dir1[1],
                   z0+uvw[0]*dir0[2]+uvw[1]*dir1[2]);
  }
  void gXyz2gUvw(const SPoint3 &uvw, const SPoint3 &gXyz, SPoint3 &gUvw) {
    gUvw[0] = gXyz.x()*dir0[0] + gXyz.y()*dir0[1] + gXyz.z()*dir0[2];
    gUvw[1] = gXyz.x()*dir1[0] + gXyz.y()*dir1[1] + gXyz.z()*dir1[2];
  }
  void gXyz2gUvw(const SPoint3 &uvw, const std::vector<SPoint3> &gXyz, std::vector<SPoint3> &gUvw) {
    std::vector<SPoint3>::iterator itUvw = gUvw.begin();
    for (std::vector<SPoint3>::const_iterator itXyz=gXyz.begin();
         itXyz != gXyz.end(); itXyz++) {
      (*itUvw)[0] = itXyz->x()*dir0[0] + itXyz->y()*dir0[1] + itXyz->z()*dir0[2];
      (*itUvw)[1] = itXyz->x()*dir1[0] + itXyz->y()*dir1[1] + itXyz->z()*dir1[2];
      itUvw++;
    }
  }
protected:
  double x0, y0, z0;
  SVector3 dir0, dir1;
};

#endif
