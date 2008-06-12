#ifndef _NGLIB_ADDON_H_
#define _NGLIB_ADDON_H_

void NgAddOn_Init();
Ng_Result NgAddOn_GenerateVolumeMesh(Ng_Mesh *mesh, double maxh);
Ng_Result NgAddOn_OptimizeVolumeMesh(Ng_Mesh *mesh, double maxh);

#endif
