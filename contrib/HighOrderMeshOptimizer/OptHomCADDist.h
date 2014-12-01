// TODO: Header

#ifndef OPTHOMCADDIST_H_
#define OPTHOMCADDIST_H_


class GModel;
class MElement;
class MLine;
class MTriangle;
class GEdge;
class GFace;

double MFaceGFaceDistance(MTriangle *t, GFace *gf,
                          std::vector<std::vector<SVector3> > *gsfT=0,
                          std::map<MVertex*,SVector3> *normalsToCAD=0);
double MLineGEdgeDistance (MLine *l, GEdge *ge, FILE *f = 0);

void distanceFromElementsToGeometry(GModel *gm, int dim, std::map<MElement*, double> &distances);
double distanceToGeometry(GModel *gm);


#endif /* OPTHOMCADDIST_H_ */
