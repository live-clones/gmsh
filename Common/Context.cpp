/* $Id: Context.cpp,v 1.4 2000-11-23 16:51:28 geuzaine Exp $ */

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

  ctx->viewport[0]    = 0 ;
  ctx->viewport[1]    = 0 ;
  ctx->viewport[2]    = 1 ;
  ctx->viewport[3]    = 1 ;
  ctx->render_mode    = GMSH_RENDER ;
  ctx->pixel_equiv_x  = 0. ;
  ctx->pixel_equiv_y  = 0. ; 

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
  ctx->threads           = 0 ; // bugge avec Open3D sur DEC ...
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
  ctx->mesh.limit_gamma       = 0.0 ;
  ctx->mesh.limit_eta         = 0.0 ;
  ctx->mesh.limit_rho         = 0.0 ;
  ctx->mesh.dual              = 0 ;
  ctx->mesh.interactive       = 0 ;

  ctx->post.draw                   = 1 ;
  ctx->post.scales                 = 1 ;
  ctx->post.link                   = 0 ;
  ctx->post.font                   = "Courier" ;
  ctx->post.fontsize               = 12 ;
  ctx->post.initial_visibility     = 1 ;
  ctx->post.initial_intervals      = DRAW_POST_ISO ;
  ctx->post.initial_nbiso          = 15 ;
  ctx->post.anim_delay             = 0 ;

  ctx->print.type    = PRINT_GL2PS_SIMPLE ;
  ctx->print.format  = FORMAT_EPS ;

  ctx->color.id = -1;
  InitColors(&ctx->color, 0) ;

}

