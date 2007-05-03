#include <string>
#include "GModel.h"
#include "Message.h"
#include "Context.h"
#include "Views.h"
#include "FFace.h"
#include "meshGFace.h" 

#if defined(HAVE_FOURIER_MODEL)

#include "FM_Reader.h"

extern Context_T CTX;

class meshGmsh{
public:
  void operator() (GFace *gf)
  {
    FFace *ff = dynamic_cast<FFace*>(gf);
    if(!ff) {
      Msg(GERROR, "face %d is not Fourier", gf->tag());
      return;
    }
    meshGFace mesh;
    mesh(ff);
  }
};

int GModel::readF(const std::string &fn)
{
  CTX.terminal = 1; 

  FM_Reader reader(fn.c_str());

  for (int i=0;i<reader.GetNumFaces();i++) {
    add(new FFace(this, reader.GetFace(i), i));
  }
  Msg(INFO, "Fourier model created: %d patches", reader.GetNumFaces());

  return 1;
}

#else

int GModel::readF(const std::string &fn)
{
  Msg(GERROR,"Gmsh has to be compiled with Fourier Model support to load %s",
      fn.c_str());
  return 0;
}

#endif
