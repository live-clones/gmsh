// TODO: Header

#ifndef OPTHOMCADDIST_H_
#define OPTHOMCADDIST_H_


class GradientBasis;
class GModel;
class MElement;
class MLine;
class MTriangle;
class GEdge;
class GFace;

double MFaceGFaceDistanceOld(MTriangle *t, GFace *gf,
                            std::vector<std::vector<SVector3> > *gsfT=0,
                            std::map<MVertex*,SVector3> *normalsToCAD=0);
double MLineGEdgeDistanceOld(MLine *l, GEdge *ge, FILE *f = 0);

double distToCAD1D(const GradientBasis *gb, const fullMatrix<double> &nodesXYZ,
                   const std::vector<SVector3> &tanCAD, double edLength);
double distToCAD2D(const GradientBasis *gb, const fullMatrix<double> &nodesXYZ,
                   const std::vector<SVector3> &normCAD);
double MLineGEdgeDistance (MLine *l, GEdge *ge);
double MFaceGFaceDistance(MElement *el, GFace *gf);

//void distanceFromElementsToGeometry(GModel *gm, int dim, std::map<MElement*, double> &distances);
//double distanceToGeometry(GModel *gm);


#endif /* OPTHOMCADDIST_H_ */
