// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include "GmshMessage.h"
#include "GModel.h"
#include "GmshDefines.h"
#include "StringUtils.h"
#include "Context.h"
#include "Options.h"

#if defined(HAVE_FLTK)
#include <FL/gl.h>
#include "gl2ps.h"
#include "gl2gif.h"
#include "gl2jpeg.h"
#include "gl2png.h"
#include "gl2ppm.h"
#include "gl2yuv.h"
#endif

extern Context_T CTX;

int GuessFileFormatFromFileName(std::string fileName)
{
  int len;
  char ext[256];
  const char *name = fileName.c_str();
  for(len = strlen(name) - 1; len >= 0; len--) {
    if(name[len] == '.') {
      strcpy(ext, &name[len]);
      break;
    }
  }
  if(len <= 0)
    strcpy(ext, "");
  
  if     (!strcmp(ext, ".geo"))  return FORMAT_GEO;
  else if(!strcmp(ext, ".msh"))  return FORMAT_MSH;
  else if(!strcmp(ext, ".pos"))  return FORMAT_POS;
  else if(!strcmp(ext, ".opt"))  return FORMAT_OPT;
  else if(!strcmp(ext, ".unv"))  return FORMAT_UNV;
  else if(!strcmp(ext, ".vtk"))  return FORMAT_VTK;
  else if(!strcmp(ext, ".stl"))  return FORMAT_STL;
  else if(!strcmp(ext, ".cgns")) return FORMAT_CGNS;
  else if(!strcmp(ext, ".med"))  return FORMAT_MED;
  else if(!strcmp(ext, ".mesh")) return FORMAT_MESH;
  else if(!strcmp(ext, ".bdf"))  return FORMAT_BDF;
  else if(!strcmp(ext, ".diff")) return FORMAT_DIFF;
  else if(!strcmp(ext, ".nas"))  return FORMAT_BDF;
  else if(!strcmp(ext, ".p3d"))  return FORMAT_P3D;
  else if(!strcmp(ext, ".wrl"))  return FORMAT_VRML;
  else if(!strcmp(ext, ".vrml")) return FORMAT_VRML;
  else if(!strcmp(ext, ".gif"))  return FORMAT_GIF;
  else if(!strcmp(ext, ".jpg"))  return FORMAT_JPEG;
  else if(!strcmp(ext, ".jpeg")) return FORMAT_JPEG;
  else if(!strcmp(ext, ".png"))  return FORMAT_PNG;
  else if(!strcmp(ext, ".ps"))   return FORMAT_PS;
  else if(!strcmp(ext, ".eps"))  return FORMAT_EPS;
  else if(!strcmp(ext, ".pdf"))  return FORMAT_PDF;
  else if(!strcmp(ext, ".tex"))  return FORMAT_TEX;
  else if(!strcmp(ext, ".svg"))  return FORMAT_SVG;
  else if(!strcmp(ext, ".ppm"))  return FORMAT_PPM;
  else if(!strcmp(ext, ".yuv"))  return FORMAT_YUV;
  else                           return -1;
}

std::string GetDefaultFileName(int format)
{
  char no_ext[256], ext[256], base[256];
  SplitFileName(GModel::current()->getFileName().c_str(), no_ext, ext, base);
  std::string name(no_ext);
  switch(format){
  case FORMAT_GEO:  name += ".geo_unrolled"; break;
  case FORMAT_MSH:  name += ".msh"; break;
  case FORMAT_POS:  name += ".pos"; break;
  case FORMAT_OPT:  name += ".opt"; break;
  case FORMAT_UNV:  name += ".unv"; break;
  case FORMAT_VTK:  name += ".vtk"; break;
  case FORMAT_STL:  name += ".stl"; break;
  case FORMAT_CGNS: name += ".cgns"; break;
  case FORMAT_MED:  name += ".med"; break;
  case FORMAT_MESH: name += ".mesh"; break;
  case FORMAT_BDF:  name += ".bdf"; break;
  case FORMAT_DIFF: name += ".diff"; break;
  case FORMAT_P3D:  name += ".p3d"; break;
  case FORMAT_VRML: name += ".wrl"; break;
  case FORMAT_GIF:  name += ".gif"; break;
  case FORMAT_JPEG: name += ".jpg"; break;
  case FORMAT_PNG:  name += ".png"; break;
  case FORMAT_PS:   name += ".ps"; break;
  case FORMAT_EPS:  name += ".eps"; break;
  case FORMAT_PDF:  name += ".pdf"; break;
  case FORMAT_TEX:  name += ".tex"; break;
  case FORMAT_SVG:  name += ".svg"; break;
  case FORMAT_PPM:  name += ".ppm"; break;
  case FORMAT_YUV:  name += ".yuv"; break;
  default: break;
  }
  return name;
}

void CreateOutputFile(const char *filename, int format)
{
  std::string name;
  if(!filename || !strlen(filename))
    name = GetDefaultFileName(format);
  else
    name = filename;

  char no_ext[256], ext[256], base[256];
  SplitFileName(name.c_str(), no_ext, ext, base);

  int oldformat = CTX.print.format;
  CTX.print.format = format;
  CTX.printing = 1;

#if defined(HAVE_FLTK)
  int vp[4];
  GetCurrentOpenglWindowViewport(vp);
  GLint viewport[4];
  for(int i = 0; i < 4; i++) viewport[i] = vp[i];
  GLint width = viewport[2] - viewport[0];
  GLint height = viewport[3] - viewport[1];
#endif

  bool printEndMessage = true;
  if(format != FORMAT_AUTO) 
    Msg::StatusBar(2, true, "Writing '%s'", name.c_str());

  switch (format) {

  case FORMAT_AUTO:
    CreateOutputFile(name.c_str(), GuessFileFormatFromFileName(name));
    printEndMessage = false;
    break;
    
  case FORMAT_OPT:
    Print_Options(0, GMSH_FULLRC, 1, 1, name.c_str());
    break;

  case FORMAT_MSH:
    GModel::current()->writeMSH(name, CTX.mesh.msh_file_version, CTX.mesh.binary, 
                                CTX.mesh.save_all, CTX.mesh.save_parametric,
                                CTX.mesh.scaling_factor);
    break;

  case FORMAT_STL:
    GModel::current()->writeSTL(name, CTX.mesh.binary,
                                CTX.mesh.save_all, CTX.mesh.scaling_factor);
    break;

  case FORMAT_VRML:
    GModel::current()->writeVRML(name, CTX.mesh.save_all, CTX.mesh.scaling_factor);
    break;

  case FORMAT_UNV:
    GModel::current()->writeUNV(name, CTX.mesh.save_all, CTX.mesh.save_groups_of_nodes,
                                CTX.mesh.scaling_factor);
    break;

  case FORMAT_VTK:
    GModel::current()->writeVTK(name, CTX.mesh.binary, CTX.mesh.save_all,
                                CTX.mesh.scaling_factor, CTX.big_endian);
    break;

  case FORMAT_MESH:
    GModel::current()->writeMESH(name, CTX.mesh.save_all, CTX.mesh.scaling_factor);
    break;

  case FORMAT_BDF:
    GModel::current()->writeBDF(name, CTX.mesh.bdf_field_format, 
				CTX.mesh.save_all, CTX.mesh.scaling_factor);
    break;

  case FORMAT_DIFF:
    GModel::current()->writeDIFF(name, CTX.mesh.binary, CTX.mesh.save_all,
                                 CTX.mesh.scaling_factor);
    break;

  case FORMAT_P3D:
    GModel::current()->writeP3D(name, CTX.mesh.save_all, CTX.mesh.scaling_factor);
    break;

  case FORMAT_CGNS:
    GModel::current()->writeCGNS(name, CTX.mesh.zone_definition,
                                 CTX.mesh.cgns_options,
                                 CTX.mesh.scaling_factor);
    break;

  case FORMAT_MED:
    GModel::current()->writeMED(name, CTX.mesh.save_all, CTX.mesh.scaling_factor);
    break;

  case FORMAT_POS:
    GModel::current()->writePOS(name, CTX.print.pos_elementary, CTX.print.pos_element, 
                                CTX.print.pos_gamma, CTX.print.pos_eta, CTX.print.pos_rho, 
				CTX.print.pos_disto, CTX.mesh.save_all, 
                                CTX.mesh.scaling_factor);
    break;

  case FORMAT_GEO:
    GModel::current()->writeGEO(name, CTX.print.geo_labels);
    break;

#if defined(HAVE_FLTK)
  case FORMAT_PPM:
  case FORMAT_YUV:
  case FORMAT_GIF:  
  case FORMAT_JPEG:
  case FORMAT_PNG:
    {
      FILE *fp;
      if(!(fp = fopen(name.c_str(), "wb"))) {
        Msg::Error("Unable to open file '%s'", name.c_str());
        break;
      }

      PixelBuffer buffer(width, height, GL_RGB, GL_UNSIGNED_BYTE);

      int old_bg_gradient = CTX.bg_gradient;
      if(format == FORMAT_GIF && CTX.print.gif_transparent)
        CTX.bg_gradient = 0;
      buffer.Fill(CTX.batch);
      CTX.bg_gradient = old_bg_gradient;

      if(format == FORMAT_PPM){
        create_ppm(fp, &buffer);
      }
      else if(format == FORMAT_YUV){
        create_yuv(fp, &buffer);
      }
      else if(format == FORMAT_GIF){
        create_gif(fp, &buffer,
                   CTX.print.gif_dither,
                   CTX.print.gif_sort,
                   CTX.print.gif_interlace,
                   CTX.print.gif_transparent,
                   CTX.UNPACK_RED(CTX.color.bg),
                   CTX.UNPACK_GREEN(CTX.color.bg), 
                   CTX.UNPACK_BLUE(CTX.color.bg));
      }
      else if(format == FORMAT_JPEG){
        create_jpeg(fp, &buffer, CTX.print.jpeg_quality, CTX.print.jpeg_smoothing);
      }
      else{
        create_png(fp, &buffer, 100);
      }
      fclose(fp);
    }
    break;

  case FORMAT_PS:
  case FORMAT_EPS:
  case FORMAT_PDF:
  case FORMAT_SVG:
    {
      FILE *fp;
      if(!(fp = fopen(name.c_str(), "wb"))) {
        Msg::Error("Unable to open file '%s'", name.c_str());
        break;
      }
      
      int psformat;
      switch(format){
      case FORMAT_PDF:
        psformat = GL2PS_PDF;
        break;
      case FORMAT_PS:
        psformat = GL2PS_PS;
        break;
      case FORMAT_SVG:
        psformat = GL2PS_SVG;
        break;
      default:
        psformat = GL2PS_EPS;
        break;
      }

      int old_bg_gradient = CTX.bg_gradient;
      if(!CTX.print.eps_background) CTX.bg_gradient = 0;
      
      PixelBuffer buffer(width, height, GL_RGB, GL_FLOAT);
      
      if(CTX.print.eps_quality == 0)
        buffer.Fill(CTX.batch);
      
      int pssort = 
        (CTX.print.eps_quality == 3) ? GL2PS_NO_SORT :
        (CTX.print.eps_quality == 2) ? GL2PS_BSP_SORT : 
        GL2PS_SIMPLE_SORT;
      int psoptions =
        GL2PS_SIMPLE_LINE_OFFSET | GL2PS_SILENT |
        (CTX.print.eps_occlusion_culling ? GL2PS_OCCLUSION_CULL : 0) |
        (CTX.print.eps_best_root ? GL2PS_BEST_ROOT : 0) |
        (CTX.print.eps_background ? GL2PS_DRAW_BACKGROUND : 0) |
        (CTX.print.eps_compress ? GL2PS_COMPRESS : 0) |
        (CTX.print.eps_ps3shading ? 0 : GL2PS_NO_PS3_SHADING);

      GLint buffsize = 0;
      int res = GL2PS_OVERFLOW;
      while(res == GL2PS_OVERFLOW) {
        buffsize += 2048 * 2048;
        gl2psBeginPage(base, "Gmsh", viewport, 
                       psformat, pssort, psoptions, GL_RGBA, 0, NULL, 
                       15, 20, 10, buffsize, fp, base);
        if(CTX.print.eps_quality == 0){
          double modelview[16], projection[16];
          glGetDoublev(GL_PROJECTION_MATRIX, projection);
          glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
          glMatrixMode(GL_PROJECTION);
          glLoadIdentity();
          glOrtho((double)viewport[0], (double)viewport[2],
                  (double)viewport[1], (double)viewport[3], -1., 1.);
          glMatrixMode(GL_MODELVIEW);
          glLoadIdentity();
          glRasterPos2d(0, 0);
          gl2psDrawPixels(width, height, 0, 0, GL_RGB, GL_FLOAT, buffer.GetPixels());
          glMatrixMode(GL_PROJECTION);
          glLoadMatrixd(projection);
          glMatrixMode(GL_MODELVIEW);
          glLoadMatrixd(modelview);
        }
        else{
          buffer.Fill(CTX.batch);
        }
        res = gl2psEndPage();
      }

      CTX.bg_gradient = old_bg_gradient;
      fclose(fp);
    }
    break;

  case FORMAT_TEX:
    {
      FILE *fp;
      if(!(fp = fopen(name.c_str(), "w"))) {
        Msg::Error("Unable to open file '%s'", name.c_str());
        break;
      }
      GLint buffsize = 0;
      int res = GL2PS_OVERFLOW;
      while(res == GL2PS_OVERFLOW) {
        buffsize += 2048 * 2048;
        gl2psBeginPage(base, "Gmsh", viewport,
                       GL2PS_TEX, GL2PS_NO_SORT, GL2PS_NONE, GL_RGBA, 0, NULL, 
                       0, 0, 0, buffsize, fp, base);
        PixelBuffer buffer(width, height, GL_RGB, GL_UNSIGNED_BYTE);
        int oldtext = CTX.print.text;
        CTX.print.text = 1;
        buffer.Fill(CTX.batch);
        CTX.print.text = oldtext;
        res = gl2psEndPage();
      }
      fclose(fp);
    }
    break;
#endif

  default:
    Msg::Error("Unknown output file format");
    printEndMessage = false;
    break;
  }

  if(printEndMessage) Msg::StatusBar(2, true, "Wrote '%s'", name.c_str());

  CTX.print.format = oldformat;
  CTX.printing = 0;

#if defined(HAVE_FLTK)
  Draw();
#endif
}
