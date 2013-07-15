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
// <gmsh@geuz.org>.
//
// Contributors: Thomas Toulorge, Jonathan Lambrechts

#ifndef _PARAMCOORD_H_
#define _PARAMCOORD_H_

class ParamCoord
{
public:
  virtual void exportParamCoord(MVertex *v, const SPoint3 &uvw) {};
  // Number of parametric coordinates for vertex
  virtual int nCoord(MVertex* vert) = 0;
  // Get parametric coordinates of vertex
  virtual SPoint3 getUvw(MVertex* vert) = 0;
  // Calculate physical coordinates from parametric coordinates of vertex
  virtual SPoint3 uvw2Xyz(MVertex* vert, const SPoint3 &uvw) = 0;
  // Calculate derivatives w.r.t parametric coordinates
  virtual void gXyz2gUvw(MVertex* vert, const SPoint3 &uvw,
                         const SPoint3 &gXyz, SPoint3 &gUvw) = 0;
  // Calculate derivatives w.r.t parametric coordinates
  virtual void gXyz2gUvw(MVertex* vert, const SPoint3 &uvw,
                         const std::vector<SPoint3> &gXyz, std::vector<SPoint3> &gUvw) = 0;
  virtual ~ParamCoord() {}
};

class ParamCoordPhys3D : public ParamCoord
{
public:
  int nCoord(MVertex* vert) { return 3; }
  virtual SPoint3 getUvw(MVertex* vert) { return vert->point(); }
  virtual SPoint3 uvw2Xyz(MVertex* vert, const SPoint3 &uvw) { return uvw; }
  virtual void gXyz2gUvw(MVertex* vert, const SPoint3 &uvw, const SPoint3 &gXyz,
                         SPoint3 &gUvw){ gUvw = gXyz; }
  virtual void gXyz2gUvw(MVertex* vert, const SPoint3 &uvw,
                         const std::vector<SPoint3> &gXyz, std::vector<SPoint3> &gUvw)
  {
    std::vector<SPoint3>::iterator itUvw=gUvw.begin();
    for (std::vector<SPoint3>::const_iterator itXyz=gXyz.begin(); itXyz != gXyz.end();
         itXyz++) {
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
  virtual void gXyz2gUvw(MVertex* vert, const SPoint3 &uvw, const SPoint3 &gXyz,
                         SPoint3 &gUvw) { gUvw = gXyz; }
  virtual void gXyz2gUvw(MVertex* vert, const SPoint3 &uvw,
                         const std::vector<SPoint3> &gXyz, std::vector<SPoint3> &gUvw)
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
  int nCoord(MVertex* vert) { return vert->onWhat()->dim(); }
  virtual void exportParamCoord(MVertex *v, const SPoint3 &uvw);
  virtual SPoint3 getUvw(MVertex* vert);
  virtual SPoint3 uvw2Xyz(MVertex* vert, const SPoint3 &uvw);
  virtual void gXyz2gUvw(MVertex* vert, const SPoint3 &uvw, const SPoint3 &gXyz,
                         SPoint3 &gUvw);
  virtual void gXyz2gUvw(MVertex* vert, const SPoint3 &uvw,
                         const std::vector<SPoint3> &gXyz, std::vector<SPoint3> &gUvw);
};

#endif
