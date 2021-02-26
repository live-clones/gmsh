#ifndef HEXTREME_GINZBURG_H
#define HEXTREME_GINZBURG_H

#include "hxt_mesh.h"

typedef struct HXTGinzburgStruct HXTGinzburg;

// if epsilon == 0, epsilon^2 = sqrt(nbturns)*triangle_area
HXTStatus hxtGinzburgCreate(HXTMesh *mesh, double epsilon, int nbTurn, int useWeakBoundary,  int useCurvatures, const char *petscOpt, HXTGinzburg **ginzburg);
HXTStatus hxtGinzburgDelete(HXTGinzburg **ginzburg);
HXTStatus hxtGinzburgComputeDirections(HXTGinzburg *ginzburg, int maxIter);
HXTStatus hxtGinzburgComputeEnergy(HXTGinzburg *ginzburg, double *energy);
HXTStatus hxtGinzburgWriteEnergy(HXTGinzburg *ginzburg, const char *filename);
HXTStatus hxtGinzburgWriteDirections(HXTGinzburg *ginzburg, const char *filename);
HXTStatus hxtGinzburgWriteCurvatureCrossField(HXTGinzburg *ginzburg, const char *filename);
HXTStatus hxtGinzburgWriteTxt(HXTGinzburg *ginzburg, const char *filename);
HXTStatus hxtGinzburgWriteVectorTrianglePos(HXTGinzburg *ginzburg, const char *fileName);
HXTStatus hxtGinzburgWriteVectorCurvatureTrianglePos(HXTGinzburg *dir, const char *fileName);

HXTStatus hxtWriteField(HXTGinzburg *dir, char *fileName);
  
int hxtGinzburgSingularityCreation(HXTGinzburg *ginzburg);

HXTStatus hxtGinzburgSetSolutionTorus(HXTGinzburg *gz, double R1, double R2);

HXTStatus hxtGinzburgGetDirections(HXTGinzburg *ginzburg, double **crossfield);
#endif
