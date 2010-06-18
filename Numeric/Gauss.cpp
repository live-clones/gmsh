#include "Gauss.h"
#include "Bindings.h"
static void pts2fullMatrix(int npts, IntPt *pts, fullMatrix<double> &pMatrix, fullMatrix<double> &wMatrix) {
  pMatrix.resize(npts,3);
  wMatrix.resize(npts,1);
  for (int i=0;i<npts;i++) {
    pMatrix(i,0) = pts[i].pt[0];
    pMatrix(i,1) = pts[i].pt[1];
    pMatrix(i,2) = pts[i].pt[2];
    wMatrix(i,0) = pts[i].weight;
  }
}
void gaussIntegration::registerBindings(binding *b)
{
  classBinding *cb = b->addClass<gaussIntegration>("gaussIntegration");
  cb->setDescription("Gauss integration rules (points+weights)");
  methodBinding *mb = cb->addMethod("getTriangle", &gaussIntegration::getTriangle);
  mb->setDescription("get the integration rule that integrate exactly a polynom of given order on a triangle");
  mb->setArgNames("order","points","weights",NULL);
  mb = cb->addMethod("getLine", &gaussIntegration::getLine);
  mb->setDescription("get the integration rule that integrate exactly a polynom of given order on a line");
  mb->setArgNames("order","points","weights",NULL);
  mb = cb->addMethod("getQuad", &gaussIntegration::getQuad);
  mb->setDescription("get the integration rule that integrate exactly a polynom of given order on a quad");
  mb->setArgNames("order","points","weights",NULL);
  mb = cb->addMethod("getTetrahedron", &gaussIntegration::getTetrahedron);
  mb->setDescription("get the integration rule that integrate exactly a polynom of given order on a tetrahedron");
  mb->setArgNames("order","points","weights",NULL);
  mb = cb->addMethod("getHexahedron", &gaussIntegration::getHexahedron);
  mb->setDescription("get the integration rule that integrate exactly a polynom of given order on a hexahedron");
  mb->setArgNames("order","points","weights",NULL);
  mb = cb->addMethod("getPrism", &gaussIntegration::getPrism);
  mb->setDescription("get the integration rule that integrate exactly a polynom of given order on a prism");
  mb->setArgNames("order","points","weights",NULL);
}

void gaussIntegration::getTriangle(int order, fullMatrix<double> &pts, fullMatrix<double> &weights) {
  pts2fullMatrix(getNGQTPts(order),getGQTPts(order),pts,weights);
}
void gaussIntegration::getLine(int order, fullMatrix<double> &pts, fullMatrix<double> &weights) {
  pts2fullMatrix(getNGQLPts(order),getGQLPts(order),pts,weights);
}
void gaussIntegration::getQuad(int order, fullMatrix<double> &pts, fullMatrix<double> &weights) {
  pts2fullMatrix(getNGQQPts(order),getGQQPts(order),pts,weights);
}
void gaussIntegration::getTetrahedron(int order, fullMatrix<double> &pts, fullMatrix<double> &weights) {
  pts2fullMatrix(getNGQTetPts(order),getGQTetPts(order),pts,weights);
}
void gaussIntegration::getHexahedron(int order, fullMatrix<double> &pts, fullMatrix<double> &weights) {
  pts2fullMatrix(getNGQHPts(order),getGQHPts(order),pts,weights);
}
void gaussIntegration::getPrism(int order, fullMatrix<double> &pts, fullMatrix<double> &weights) {
  pts2fullMatrix(getNGQPriPts(order),getGQPriPts(order),pts,weights);
}
