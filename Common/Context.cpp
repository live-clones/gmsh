/* $Id: Context.cpp,v 1.9 2000-12-04 11:28:11 geuzaine Exp $ */

#include "Gmsh.h"
#include "Const.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"

void InitColors(rgbacolors * col, int num){

  if(col->id == num){
    return ;
  }

  col->id = num ;

  switch(num){

  case 0 : /* default drawing colors: black background */
  case 1 : /* alternative drawing colors: white background */
    switch(num){
    case 0 :
      col->bg               = PACK_COLOR(0,   0,   0,   255) ;
      col->fg               = PACK_COLOR(255, 255, 255, 255) ;
      col->text             = PACK_COLOR(255, 255, 255, 255) ;
      col->axes             = PACK_COLOR(255, 255, 0,   255) ;
      col->little_axes      = PACK_COLOR(255, 255, 255, 255) ;
      break;              
    case 1 :              
      col->bg               = PACK_COLOR(255, 255, 255, 255) ;
      col->fg               = PACK_COLOR(0,   0,   0,   255) ;
      col->text             = PACK_COLOR(0,   0,   0,   255) ;
      col->axes             = PACK_COLOR(128, 128, 128, 255) ;
      col->little_axes      = PACK_COLOR(0,   0,   0,   255) ;
      break;
    }
    col->geom.point         = PACK_COLOR(178, 182, 129, 255) ;
    col->geom.line          = PACK_COLOR(0,   0,   255, 255) ;
    col->geom.surface       = PACK_COLOR(128, 128, 128, 255) ;
    col->geom.volume        = PACK_COLOR(128, 128, 128, 255) ;
    col->geom.point_sel     = PACK_COLOR(255, 0,   0,   255) ;
    col->geom.line_sel      = PACK_COLOR(255, 0,   0,   255) ;
    col->geom.surface_sel   = PACK_COLOR(255, 0,   0,   255) ;
    col->geom.volume_sel    = PACK_COLOR(255, 0,   0,   255) ;
    col->geom.point_hlt     = PACK_COLOR(0,   255, 0,   255) ;
    col->geom.line_hlt      = PACK_COLOR(0,   0,   255, 255) ;
    col->geom.surface_hlt   = PACK_COLOR(128, 128, 128, 255) ;
    col->geom.volume_hlt    = PACK_COLOR(128, 128, 128, 255) ;
    col->geom.tangents      = PACK_COLOR(255, 255, 0,   255) ;
    col->geom.normals       = PACK_COLOR(255, 0,   0,   255) ;

    col->mesh.vertex        = PACK_COLOR(0  , 123, 59 , 255) ;
    col->mesh.vertex_supp   = PACK_COLOR(255, 0,   255, 255) ;
    col->mesh.line          = PACK_COLOR(0,   255, 0,   255) ; 
    col->mesh.triangle      = PACK_COLOR(0,   255, 0,   255) ;
    col->mesh.quadrangle    = PACK_COLOR(0,   255, 0,   255) ; 
    col->mesh.tetrahedron   = PACK_COLOR(0,   255, 0,   255) ;
    col->mesh.hexahedron    = PACK_COLOR(128, 255, 0,   255) ;
    col->mesh.prism         = PACK_COLOR(0,   255, 128, 255) ;
    col->mesh.pyramid       = PACK_COLOR(128, 255, 128, 255) ;
    col->mesh.tangents      = PACK_COLOR(128, 128, 128, 255) ;
    col->mesh.normals       = PACK_COLOR(128, 128, 128, 255) ;

    col->mesh.carousel[0]   = PACK_COLOR(0  , 82 , 138, 255) ;
    col->mesh.carousel[1]   = PACK_COLOR(255, 0  , 0  , 255) ;
    col->mesh.carousel[2]   = PACK_COLOR(31 , 110, 171, 255) ;
    col->mesh.carousel[3]   = PACK_COLOR(255, 255, 0  , 255) ; 
    col->mesh.carousel[4]   = PACK_COLOR(255, 0  , 255, 255) ; 
    col->mesh.carousel[4]   = PACK_COLOR(0  , 255, 255, 255) ; 
    col->mesh.carousel[5]   = PACK_COLOR(128, 128, 0  , 255) ; 
    col->mesh.carousel[6]   = PACK_COLOR(128, 0  , 255, 255) ; 
    col->mesh.carousel[7]   = PACK_COLOR(128, 128, 255, 255) ; 
    col->mesh.carousel[8]   = PACK_COLOR(128, 128, 255, 255) ; 
    col->mesh.carousel[9]   = PACK_COLOR(0  , 0  , 255, 255) ; 
    break;
    
  case 2 : /* grayscale */
    col->bg                 = PACK_COLOR(255, 255, 255, 255) ;
    col->fg                 = PACK_COLOR(0,   0,   0,   255) ;
    col->text               = PACK_COLOR(0,   0,   0,   255) ;
    col->axes               = PACK_COLOR(0,   0,   0,   255) ;
    col->little_axes        = PACK_COLOR(0,   0,   0,   255) ;
    
    col->geom.point         = PACK_COLOR(0,   0,   0,   255) ;
    col->geom.line          = PACK_COLOR(0,   0,   0,   255) ;
    col->geom.surface       = PACK_COLOR(0,   0,   0,   255) ; 
    col->geom.volume        = PACK_COLOR(0,   0,   0,   255) ;
    col->geom.point_sel     = PACK_COLOR(0,   0,   0,   255) ;
    col->geom.line_sel      = PACK_COLOR(0,   0,   0,   255) ;
    col->geom.surface_sel   = PACK_COLOR(0,   0,   0,   255) ; 
    col->geom.volume_sel    = PACK_COLOR(0,   0,   0,   255) ;
    col->geom.point_hlt     = PACK_COLOR(0,   0,   0,   255) ;
    col->geom.line_hlt      = PACK_COLOR(0,   0,   0,   255) ;
    col->geom.surface_hlt   = PACK_COLOR(0,   0,   0,   255) ; 
    col->geom.volume_hlt    = PACK_COLOR(0,   0,   0,   255) ;
    col->geom.tangents      = PACK_COLOR(0,   0,   0,   255) ;
    col->geom.normals       = PACK_COLOR(0,   0,   0,   255) ;
    
    col->mesh.vertex        = PACK_COLOR(0,   0,   0,   255) ;
    col->mesh.vertex_supp   = PACK_COLOR(0,   0,   0,   255) ;
    col->mesh.line          = PACK_COLOR(0,   0,   0,   255) ; 
    col->mesh.triangle      = PACK_COLOR(0,   0,   0,   255) ;
    col->mesh.quadrangle    = PACK_COLOR(0,   0,   0,   255) ; 
    col->mesh.tetrahedron   = PACK_COLOR(0,   0,   0,   255) ;
    col->mesh.hexahedron    = PACK_COLOR(0,   0,   0,   255) ;
    col->mesh.prism         = PACK_COLOR(0,   0,   0,   255) ;
    col->mesh.pyramid       = PACK_COLOR(0,   0,   0,   255) ;
    col->mesh.tangents      = PACK_COLOR(0,   0,   0,   255) ;
    col->mesh.normals       = PACK_COLOR(0,   0,   0,   255) ;

    col->mesh.carousel[0]   = PACK_COLOR(255, 255, 255, 255) ;
    col->mesh.carousel[1]   = PACK_COLOR(255, 255, 255, 255) ;
    col->mesh.carousel[2]   = PACK_COLOR(255, 255, 255, 255) ;
    col->mesh.carousel[3]   = PACK_COLOR(255, 255, 255, 255) ;
    col->mesh.carousel[4]   = PACK_COLOR(255, 255, 255, 255) ;
    col->mesh.carousel[4]   = PACK_COLOR(255, 255, 255, 255) ;
    col->mesh.carousel[5]   = PACK_COLOR(255, 255, 255, 255) ;
    col->mesh.carousel[6]   = PACK_COLOR(255, 255, 255, 255) ;
    col->mesh.carousel[7]   = PACK_COLOR(255, 255, 255, 255) ;
    col->mesh.carousel[8]   = PACK_COLOR(255, 255, 255, 255) ;
    col->mesh.carousel[9]   = PACK_COLOR(255, 255, 255, 255) ;

  }

}


void InitContext(Context_T *ctx){

  ctx->interactive  = 0 ;
  ctx->verbosity    = 2 ;
  ctx->expose       = 0 ;

  ctx->r[0]  = 0.0 ;
  ctx->r[1]  = 0.0 ;
  ctx->r[2]  = 0.0 ;
  ctx->t[0]  = 0.0 ;
  ctx->t[1]  = 0.0 ;
  ctx->t[2]  = 0.0 ;
  ctx->s[0]  = 1.0 ;
  ctx->s[1]  = 1.0 ;
  ctx->s[2]  = 1.0 ;

  ctx->min[0]     = 0.0 ;
  ctx->min[1]     = 0.0 ;
  ctx->min[2]     = 0.0 ;
  ctx->max[0]     = 0.0 ;
  ctx->max[1]     = 0.0 ;
  ctx->max[2]     = 0.0 ;
  ctx->range[0]   = 0.0 ;
  ctx->range[1]   = 0.0 ;
  ctx->range[2]   = 0.0 ;

  ctx->viewport[0]     = 0 ;
  ctx->viewport[1]     = 0 ;
  ctx->viewport[2]     = 1 ;
  ctx->viewport[3]     = 1 ;
  ctx->vxmin           = 0. ;
  ctx->vymin           = 0. ;
  ctx->vxmax           = 0. ;
  ctx->vymax           = 0. ;
  ctx->render_mode     = GMSH_RENDER ;
  ctx->pixel_equiv_x   = 0. ;
  ctx->pixel_equiv_y   = 0. ; 
  ctx->clip[0]         = 0;
  ctx->clip[1]         = 0;
  ctx->clip[2]         = 0;
  ctx->clip[3]         = 0;
  ctx->clip[4]         = 0;
  ctx->clip[5]         = 0;

  ctx->font_string          = "-*-helvetica-medium-r-*-*-*-*-*-*-*-*-*-*";
  ctx->colorbar_font_string = "fixed";

  ctx->light0[0]         = 0.5 ;
  ctx->light0[1]         = 0.3 ;
  ctx->light0[2]         = 1.0 ;
  ctx->light0[3]         = 0.0 ;
  ctx->shine             = 0.4 ;
  ctx->alpha             = 0 ; /* disable alpha blending by default */
  ctx->flash             = 0 ;
  ctx->same_visual       = 0 ;

  ctx->db                = 1 ;
  ctx->overlay           = 1 ;
  ctx->stream            = TO_SCREEN ;
  ctx->axes              = 1 ;
  ctx->little_axes       = 1 ;
  ctx->ortho             = 1 ;
  ctx->fast              = 1 ;
  ctx->display_lists     = 0 ; 
  ctx->command_win       = 0 ;
  ctx->threads           = 1 ; // effective on Unix only with -D_USETHREADS
  ctx->threads_lock      = 0 ;

  ctx->geom.vis_type     = 0 ;
  ctx->geom.points       = 1 ;
  ctx->geom.lines        = 1 ;
  ctx->geom.surfaces     = 0 ;
  ctx->geom.volumes      = 0 ;
  ctx->geom.points_num   = 0 ;
  ctx->geom.lines_num    = 0 ;
  ctx->geom.surfaces_num = 0 ;
  ctx->geom.volumes_num  = 0 ;
  ctx->geom.level        = ELEMENTARY ;
  ctx->geom.normals      = 0.0 ;
  ctx->geom.tangents     = 0.0 ;
  ctx->geom.highlight    = 1 ;
  ctx->geom.hidden       = 0 ;
  ctx->geom.shade        = 0 ;

  ctx->mesh.vis_type          = 0 ;
  ctx->mesh.draw              = 1 ;  
  ctx->mesh.points            = 1 ;
  ctx->mesh.lines             = 1 ;
  ctx->mesh.surfaces          = 1 ;
  ctx->mesh.volumes           = 1 ;
  ctx->mesh.points_num        = 0 ;
  ctx->mesh.lines_num         = 0 ;
  ctx->mesh.surfaces_num      = 0 ;
  ctx->mesh.volumes_num       = 0 ;
  ctx->mesh.normals           = 0.0 ;
  ctx->mesh.tangents          = 0.0 ;  
  ctx->mesh.explode           = 1.0 ;
  ctx->mesh.hidden            = 0 ;  
  ctx->mesh.shade             = 0 ;  
  ctx->mesh.format            = FORMAT_MSH ;
  ctx->mesh.nb_smoothing      = 0 ;
  ctx->mesh.algo              = DELAUNAY_OLDALGO ;
  ctx->mesh.point_insertion   = CENTER_CIRCCIRC;
  ctx->mesh.speed_max         = 0 ;
  ctx->mesh.degree            = 1 ;
  ctx->mesh.scaling_factor    = 1.0 ;
  ctx->mesh.lc_factor         = 1.0 ;
  ctx->mesh.rand_factor       = 1.e-5 ;
  ctx->mesh.limit_gamma       = 0.0 ;
  ctx->mesh.limit_eta         = 0.0 ;
  ctx->mesh.limit_rho         = 0.0 ;
  ctx->mesh.dual              = 0 ;
  ctx->mesh.interactive       = 0 ;

  ctx->post.draw                   = 1 ;
  ctx->post.scales                 = 1 ;
  ctx->post.link                   = 0 ;
  ctx->post.initial_visibility     = 1 ;
  ctx->post.initial_intervals      = DRAW_POST_ISO ;
  ctx->post.initial_nbiso          = 15 ;
  ctx->post.anim_delay             = 0 ;

  ctx->print.type      = PRINT_GL2PS_SIMPLE ;
  ctx->print.format    = FORMAT_EPS ;
  ctx->print.font      = "Courier" ;
  ctx->print.fontsize  = 12 ;

  ctx->color.id = -1;
  InitColors(&ctx->color, 0) ;

}

#define UNPACK_RGB(thecol) \
   UNPACK_RED(thecol), UNPACK_GREEN(thecol), UNPACK_BLUE(thecol)

void PrintContext(Context_T *ctx, FILE *file){
  int i;

  fprintf(file, "Options {\n");

  fprintf(file, "  General {\n");
  fprintf(file, "    Interactive = %d;\n", ctx->verbosity);
  fprintf(file, "    Rotation = {%g, %g, %g};\n", ctx->r[0], ctx->r[1], ctx->r[2]);
  fprintf(file, "    Translation = {%g, %g, %g};\n", ctx->t[0], ctx->t[1], ctx->t[2]);
  fprintf(file, "    Scale = {%g, %g, %g};\n", ctx->s[0], ctx->s[1], ctx->s[2]);
  for(i = 0 ; i < 6 ; i++)
    if(ctx->clip[i])
      fprintf(file, "    Clip Plane (%d) = {%g, %g, %g, %g};\n", 
	      ctx->clip[i], ctx->s[0], ctx->s[1], ctx->s[2], ctx->s[3]);
  fprintf(file, "    Proportional Font = \"%s\";\n", ctx->font_string);
  fprintf(file, "    Fixed Font = \"%s\"\n", ctx->colorbar_font_string);
  fprintf(file, "    Light (0) = {%g, %g, %g, %g};\n", 
	  ctx->light0[0],ctx->light0[1],ctx->light0[2],ctx->light0[3]);
  fprintf(file, "    Shine = %g;\n", ctx->shine);
  fprintf(file, "    Alpha = %d;\n", ctx->alpha);
  fprintf(file, "    Axes = %d;\n", ctx->axes);
  fprintf(file, "    Little Axes = %d;\n", ctx->little_axes);
  fprintf(file, "    Ortho = %d;\n", ctx->ortho);
  fprintf(file, "    Fast = %d;\n", ctx->fast);
  fprintf(file, "    Display Lists = %d;\n", ctx->display_lists);
  fprintf(file, "    Colors {\n");
  fprintf(file, "      Background = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.bg));
  fprintf(file, "      Foreground = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.fg));
  fprintf(file, "      Text = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.text));
  fprintf(file, "      Axes = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.axes));
  fprintf(file, "      Little Axes = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.little_axes));
  fprintf(file, "    }\n");
  fprintf(file, "  }\n");

  fprintf(file, "  Geometry {\n");
  fprintf(file, "    Points = %d;\n", ctx->geom.points);
  fprintf(file, "    Lines = %d;\n", ctx->geom.lines);
  fprintf(file, "    Surfaces = %d;\n", ctx->geom.surfaces);
  fprintf(file, "    Volumes = %d;\n", ctx->geom.volumes);
  fprintf(file, "    Points Numbers = %d;\n", ctx->geom.points_num);
  fprintf(file, "    Lines Numbers = %d;\n", ctx->geom.lines_num);
  fprintf(file, "    Surfaces Numbers = %d;\n", ctx->geom.surfaces_num);
  fprintf(file, "    Volumes Numbers = %d;\n", ctx->geom.volumes_num);
  fprintf(file, "    Normals = %g;\n", ctx->geom.normals);
  fprintf(file, "    Tangents = %g;\n", ctx->geom.tangents);
  fprintf(file, "    Highlight = %d;\n", ctx->geom.highlight);
  fprintf(file, "    Hidden = %d;\n", ctx->geom.hidden);
  fprintf(file, "    Shade = %d;\n", ctx->geom.shade);
  fprintf(file, "    Colors {\n");
  fprintf(file, "      Points = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.geom.point));
  fprintf(file, "      Lines = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.geom.line));
  fprintf(file, "      Surfaces = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.geom.surface));
  fprintf(file, "      Volumes = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.geom.volume));
  fprintf(file, "      PointsSelect = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.geom.point_sel));
  fprintf(file, "      LinesSelect = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.geom.line_sel));
  fprintf(file, "      SurfacesSelect = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.geom.surface_sel));
  fprintf(file, "      VolumesSelect = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.geom.volume_sel));
  fprintf(file, "      PointsHighlight = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.geom.point_hlt));
  fprintf(file, "      LinesHighlight = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.geom.line_hlt));
  fprintf(file, "      SurfacesHighlight = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.geom.surface_hlt));
  fprintf(file, "      VolumesHighlight = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.geom.volume_hlt));
  fprintf(file, "      Tangents = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.geom.tangents));
  fprintf(file, "      Normals = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.geom.normals));
  fprintf(file, "    }\n");
  fprintf(file, "  }\n");

  fprintf(file, "  Mesh {\n");
  fprintf(file, "    Points = %d;\n", ctx->mesh.points);
  fprintf(file, "    Lines = %d;\n", ctx->mesh.lines);
  fprintf(file, "    Surfaces = %d;\n", ctx->mesh.surfaces);
  fprintf(file, "    Volumes = %d;\n", ctx->mesh.volumes);
  fprintf(file, "    Points Numbers = %d;\n", ctx->mesh.points_num);
  fprintf(file, "    Lines Numbers = %d;\n", ctx->mesh.lines_num);
  fprintf(file, "    Surfaces Numbers = %d;\n", ctx->mesh.surfaces_num);
  fprintf(file, "    Volumes Numbers = %d;\n", ctx->mesh.volumes_num);
  fprintf(file, "    Normals = %g;\n", ctx->mesh.normals);
  fprintf(file, "    Tangents = %g;\n", ctx->mesh.tangents);
  fprintf(file, "    Explode = %g;\n", ctx->mesh.explode);
  fprintf(file, "    Hidden = %d;\n", ctx->mesh.hidden);
  fprintf(file, "    Shade = %d;\n", ctx->mesh.shade);
  fprintf(file, "    Format = %d;\n", ctx->mesh.format);
  fprintf(file, "    Smoothing = %d;\n", ctx->mesh.nb_smoothing);
  fprintf(file, "    Algorithm = %d;\n", ctx->mesh.algo);
  fprintf(file, "    Degree = %d;\n", ctx->mesh.degree);
  fprintf(file, "    ScalingFactor = %g;\n", ctx->mesh.scaling_factor);
  fprintf(file, "    Characteristic Length Factor = %g;\n", ctx->mesh.lc_factor);
  fprintf(file, "    Random Factor = %g;\n", ctx->mesh.rand_factor);
  fprintf(file, "    Gamma Limit = %g;\n", ctx->mesh.limit_gamma);
  fprintf(file, "    Eta Limit = %g;\n", ctx->mesh.limit_eta);
  fprintf(file, "    Rho Limit = %g;\n", ctx->mesh.limit_rho);
  fprintf(file, "    Dual = %d;\n", ctx->mesh.dual);
  fprintf(file, "    interactive = %d;\n", ctx->mesh.interactive);
  fprintf(file, "    Colors {\n");
  fprintf(file, "      Vertex = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.vertex));
  fprintf(file, "      VertexSupp = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.vertex_supp));
  fprintf(file, "      Line = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.line));
  fprintf(file, "      Triangle = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.triangle));
  fprintf(file, "      Quadrangle = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.quadrangle));
  fprintf(file, "      Tetrahedron = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.tetrahedron));
  fprintf(file, "      Hexahedron = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.hexahedron));
  fprintf(file, "      Prism = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.prism));
  fprintf(file, "      Pyramid = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.pyramid));
  fprintf(file, "      One = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.carousel[0]));
  fprintf(file, "      Two = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.carousel[1]));
  fprintf(file, "      Three = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.carousel[2]));
  fprintf(file, "      Four = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.carousel[3]));
  fprintf(file, "      Five = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.carousel[4]));
  fprintf(file, "      Six = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.carousel[5]));
  fprintf(file, "      Seven = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.carousel[6]));
  fprintf(file, "      Eight = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.carousel[7]));
  fprintf(file, "      Nine = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.carousel[8]));
  fprintf(file, "      Ten = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.carousel[9]));
  fprintf(file, "      Tangents = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.tangents));
  fprintf(file, "      Normals = {%d,%d,%d};\n", UNPACK_RGB(ctx->color.mesh.normals));
  fprintf(file, "    }\n");
  fprintf(file, "  }\n");

  fprintf(file, "  Post {\n");
  fprintf(file, "    Scales = %d;\n", ctx->post.scales);
  fprintf(file, "    Link = %d;\n", ctx->post.link);
  fprintf(file, "    Visibility = %d;\n", ctx->post.initial_visibility);
  fprintf(file, "    Intervals = %d;\n", ctx->post.initial_intervals);
  fprintf(file, "    NbIso = %d;\n", ctx->post.initial_nbiso);
  fprintf(file, "    Animation Delay= %ld;\n", ctx->post.anim_delay);
  fprintf(file, "  }\n");


  fprintf(file, "  Print {\n");
  fprintf(file, "    Font = \"%s\";\n", ctx->print.font);
  fprintf(file, "    Font Size = \"%s\";\n", ctx->print.font);
  fprintf(file, "    Type = %d;\n", ctx->print.type);
  fprintf(file, "    Format = %d;\n", ctx->print.format);
  fprintf(file, "  }\n");

  fprintf(file, "}\n");

}
