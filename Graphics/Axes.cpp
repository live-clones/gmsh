// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshUI.h"
#include "Draw.h"
#include "Context.h"
#include "gl2ps.h"
#include "GModel.h"

extern Context_T CTX;

void Draw_Axes()
{
  bool geometryExists = false;
  for(unsigned int i = 0; i < GModel::list.size(); i++){
    if(!GModel::list[i]->empty()){
      geometryExists = true;
      break;
    }
  }
    
  if(geometryExists && (CTX.draw_bbox || !CTX.mesh.draw)) {
    glColor4ubv((GLubyte *) & CTX.color.fg);
    glLineWidth(CTX.line_width);
    gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);
    Draw_Box(CTX.min[0], CTX.min[1], CTX.min[2], 
             CTX.max[0], CTX.max[1], CTX.max[2]);
    glColor3d(1.,0.,0.);
    for(int j = 0; j < 6; j++)
      if(CTX.geom.clip & (1 << j) || CTX.mesh.clip & (1 << j))
        Draw_PlaneInBoundingBox(CTX.min[0], CTX.min[1], CTX.min[2],
                                CTX.max[0], CTX.max[1], CTX.max[2],
                                CTX.clip_plane[j][0], CTX.clip_plane[j][1], 
                                CTX.clip_plane[j][2], CTX.clip_plane[j][3]);
  }

  if(CTX.axes){
    glColor4ubv((GLubyte *) & CTX.color.axes);
    glLineWidth(CTX.line_width);
    gl2psLineWidth(CTX.line_width * CTX.print.eps_line_width_factor);
    if(!CTX.axes_auto_position){
      Draw_Axes(CTX.axes, CTX.axes_tics, CTX.axes_format, CTX.axes_label, 
                CTX.axes_position, CTX.axes_mikado);
    }
    else if(geometryExists){
      double bb[6] = {CTX.min[0], CTX.max[0], CTX.min[1], 
                      CTX.max[1], CTX.min[2], CTX.max[2]};
      Draw_Axes(CTX.axes, CTX.axes_tics, CTX.axes_format, CTX.axes_label, 
                bb, CTX.axes_mikado);
    }
  }

  if(CTX.draw_rotation_center){
    glColor4ubv((GLubyte *) & CTX.color.fg);
    if(CTX.rotation_center_cg)
      Draw_Sphere(CTX.point_size, CTX.cg[0], CTX.cg[1], CTX.cg[2], CTX.geom.light);
    else
      Draw_Sphere(CTX.point_size, CTX.rotation_center[0], CTX.rotation_center[1], 
                  CTX.rotation_center[2], CTX.geom.light);
  }

}
