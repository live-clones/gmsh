//                          lx   ly   lz    rmax  levels
//
// plaqueEp.stp             0.2  0.2  0.2   0.3   3
// plaqueEpRotated.stp      0.3  0.3  0.3   0.3   3
// jonction_collee2.stp     6    6    6     10    3
// panneau_raidi_simple.stp 3    3    50    10    1
// plaque_trouee.stp        1    1    1     2     3

#include "Gmsh.h"
#include "GModel.h"
#include "MVertex.h"
#include "cartesian.h"
#include "MTriangle.h"
#include "SOrientedBoundingBox.h"
#include "Numeric.h"
#include "GmshMessage.h"

void insertActiveCells(double x, double y, double z, double rmax,
                       cartesianBox<double> &box)
{
  int id1 = box.getCellContainingPoint(x - rmax, y - rmax, z - rmax);
  int id2 = box.getCellContainingPoint(x + rmax, y + rmax, z + rmax);
  int i1, j1 ,k1;
  box.getCellIJK(id1, i1, j1, k1);
  int i2, j2, k2;
  box.getCellIJK(id2, i2, j2, k2);
  for (int i = i1; i <= i2; i++)
    for (int j = j1; j <= j2; j++)
      for (int k = k1; k <= k2; k++)
        box.insertActiveCell(box.getCellIndex(i, j, k));
}

void computeLevelset(GModel *gm, cartesianBox<double> &box)
{
  std::vector<SPoint3> nodes;
  std::vector<int> indices;
  for (cartesianBox<double>::valIter it = box.nodalValuesBegin(); 
       it != box.nodalValuesEnd(); ++it){
    nodes.push_back(box.getNodeCoordinates(it->first));
    indices.push_back(it->first);
  }
  Msg::Info("  %d nodes in the grid at level %d", (int)nodes.size(), box.getLevel());
  std::vector<double> dist, localdist;
  std::vector<SPoint3> dummy;
  for (GModel::fiter fit = gm->firstFace(); fit != gm->lastFace(); fit++){
    for (int i = 0; i < (*fit)->stl_triangles.size(); i += 3){
      int i1 = (*fit)->stl_triangles[i];
      int i2 = (*fit)->stl_triangles[i + 1];
      int i3 = (*fit)->stl_triangles[i + 2];
      GPoint p1 = (*fit)->point((*fit)->stl_vertices[i1]);
      GPoint p2 = (*fit)->point((*fit)->stl_vertices[i2]);
      GPoint p3 = (*fit)->point((*fit)->stl_vertices[i3]);
      SPoint2 p = ((*fit)->stl_vertices[i1] + (*fit)->stl_vertices[i2] + 
                   (*fit)->stl_vertices[i3]) * 0.33333333;
      SVector3 N = (*fit)->normal(p);
      SPoint3 P1(p1.x(), p1.y(), p1.z());
      SPoint3 P2(p2.x(), p2.y(), p2.z());
      SPoint3 P3(p3.x(), p3.y(), p3.z());
      SVector3 NN(crossprod(P2 - P1, P3 - P1));
      if (dot(NN, N) > 0)
	signedDistancesPointsTriangle(localdist, dummy, nodes, P1, P2, P3);
      else
	signedDistancesPointsTriangle(localdist, dummy, nodes, P2, P1, P3);
      if(dist.empty()) 
        dist = localdist;
      else 
        for (unsigned int j = 0; j < localdist.size(); j++)
          dist[j] = (fabs(dist[j]) < fabs(localdist[j])) ? dist[j] : localdist[j];
    }
  }
  for (unsigned int j = 0; j < dist.size(); j++)
    box.setNodalValue(indices[j], dist[j]);

  if(box.getChildBox()) computeLevelset(gm, *box.getChildBox());
}

void fillPointCloud(GEdge *ge, double sampling, std::vector<SPoint3> &points)
{
  Range<double> t_bounds = ge->parBounds(0);
  double t_min = t_bounds.low();
  double t_max = t_bounds.high();
  double length = ge->length(t_min, t_max, 20);
  int N = length / sampling;
  for(int i = 0; i < N; i++) {
    double t = t_min + (double)i / (double)(N - 1) * (t_max - t_min);
    GPoint p = ge->point(t);
    points.push_back(SPoint3(p.x(), p.y(), p.z()));
  }
}

int removeBadChildCells(cartesianBox<double> *parent)
{
  cartesianBox<double> *child = parent->getChildBox();
  if(!child) return 0;
  int I = parent->getNxi();
  int J = parent->getNeta();
  int K = parent->getNzeta();
  for(int i = 0; i < I; i++)
    for(int j = 0; j < J; j++)
      for(int k = 0; k < K; k++){
        // remove children if they do not entirely fill parent, or if
        // there is no parent on the boundary
        int idx[8] = {child->getCellIndex(2 * i, 2 * j, 2 * k),
                      child->getCellIndex(2 * i, 2 * j, 2 * k + 1),
                      child->getCellIndex(2 * i, 2 * j + 1, 2 * k),
                      child->getCellIndex(2 * i, 2 * j + 1, 2 * k + 1),
                      child->getCellIndex(2 * i + 1, 2 * j, 2 * k),
                      child->getCellIndex(2 * i + 1, 2 * j, 2 * k + 1),
                      child->getCellIndex(2 * i + 1, 2 * j + 1, 2 * k),
                      child->getCellIndex(2 * i + 1, 2 * j + 1, 2 * k + 1)};
        bool exist[8], atLeastOne = false, butNotAll = false;
        for(int ii = 0; ii < 8; ii++){
          exist[ii] = child->activeCellExists(idx[ii]);
          if(exist[ii]) atLeastOne = true;
          if(!exist[ii]) butNotAll = true;
        }
        if(atLeastOne && 
           (butNotAll ||
            (i != 0 && !parent->activeCellExists(parent->getCellIndex(i - 1, j, k))) ||
            (i != I - 1 && !parent->activeCellExists(parent->getCellIndex(i + 1, j, k))) ||
            (j != 0 && !parent->activeCellExists(parent->getCellIndex(i, j - 1, k))) ||
            (j != J - 1 && !parent->activeCellExists(parent->getCellIndex(i, j + 1, k))) ||
            (k != 0 && !parent->activeCellExists(parent->getCellIndex(i, j, k - 1))) ||
            (k != K - 1 && !parent->activeCellExists(parent->getCellIndex(i, j, k + 1)))))
            for(int ii = 0; ii < 8; ii++) child->eraseActiveCell(idx[ii]);
      }
  return removeBadChildCells(child);
}

void removeParentCellsWithChildren(cartesianBox<double> *box)
{
  if(!box->getChildBox()) return;
  for(int i = 0; i < box->getNxi(); i++)
    for(int j = 0; j < box->getNeta(); j++)
      for(int k = 0; k < box->getNzeta(); k++){
        if(box->activeCellExists(box->getCellIndex(i, j, k))){
          cartesianBox<double> *parent = box, *child;
          int ii = i, jj = j, kk = k;
          while((child = parent->getChildBox())){
            ii *= 2; jj *= 2; kk *= 2;
            if(child->activeCellExists(child->getCellIndex(ii, jj, kk))){
              box->eraseActiveCell(box->getCellIndex(i, j, k));
              break;
            }
            parent = child;
          }
        }
      }
  removeParentCellsWithChildren(box->getChildBox());
}

void removeOutsideCells(cartesianBox<double> *box)
{
  if(!box) return;
  int nbErased = 0;
  for(cartesianBox<double>::cellIter it = box->activeCellsBegin(); 
      it != box->activeCellsEnd();){
    std::vector<double> vals;
    box->getNodalValuesForCell(*it, vals);
    double lsmax = *std::max_element(vals.begin(), vals.end());
    double lsmin = *std::min_element(vals.begin(), vals.end());
    double change_sign = lsmax * lsmin;
    double epsilon = 1.e-10;
    if(change_sign > 0 && lsmax < -epsilon) { 
      box->eraseActiveCell(*(it++));
      nbErased++;
    }
    else ++it;
  }
  Msg::Info("  number of cells erased after filtering: %d", nbErased);
  removeOutsideCells(box->getChildBox());
}

int main(int argc,char *argv[])
{
  if(argc < 6){
    printf("Usage: %s file lx ly lz rmax [levels=1]\n", argv[0]);
    printf("where\n");
    printf("  'file' contains a CAD model\n");
    printf("  'lx', 'ly' and 'lz' are the sizes of the elements along the"
           " x-, y- and z-axis at the coarsest level\n");
    printf("  'rmax' is the radius of the largest sphere that can be inscribed"
           " in the structure\n");
    printf("  'levels' sets the number of levels in the grid\n");
    return -1;
  }

  GmshInitialize();
  GmshSetOption("General", "Terminal", 1.);
  GmshMergeFile(argv[1]);
  double lx = atof(argv[2]), ly = atof(argv[3]), lz = atof(argv[4]);
  double rmax = atof(argv[5]);
  int levels = (argc > 6) ? atof(argv[6]) : 1;

  // minimum distance between points in the cloud at the coarsest
  // level
  double sampling = std::min(rmax, std::min(lx, std::min(ly, lz)));

  // radius of the "tube" created around parts to refine at the
  // coarsest level
  double rtube = std::max(lx, std::max(ly, lz)) * 2.;

  GModel *gm = GModel::current();
  
  std::vector<SPoint3> points;
  Msg::Info("Filling coarse point cloud on surfaces");
  for (GModel::fiter fit = gm->firstFace(); fit != gm->lastFace(); fit++)
    (*fit)->fillPointCloud(sampling, &points);
  Msg::Info("  %d points in the surface cloud", (int)points.size());

  std::vector<SPoint3> refinePoints;
  if(levels > 1){
    double s = sampling / pow(2., levels - 1);
    Msg::Info("Filling refined point cloud on curves and curved surfaces");
    for (GModel::eiter eit = gm->firstEdge(); eit != gm->lastEdge(); eit++)
      fillPointCloud(*eit, s, refinePoints);
    // FIXME: refine this by computing e.g. "mean" curvature
    for (GModel::fiter fit = gm->firstFace(); fit != gm->lastFace(); fit++)
      if((*fit)->geomType() != GEntity::Plane)
        (*fit)->fillPointCloud(2 * s, &refinePoints);
    Msg::Info("  %d points in the refined cloud", (int)refinePoints.size());
  }

  SBoundingBox3d bb;
  for(unsigned int i = 0; i < points.size(); i++) bb += points[i]; 
  for(unsigned int i = 0; i < refinePoints.size(); i++) bb += refinePoints[i]; 
  bb.scale(1.21, 1.21, 1.21);
  SVector3 range = bb.max() - bb.min();   
  int NX = range.x() / lx; 
  int NY = range.y() / ly; 
  int NZ = range.z() / lz; 
  if(NX < 2) NX = 2;
  if(NY < 2) NY = 2;
  if(NZ < 2) NZ = 2;

  Msg::Info("  bounding box min: %g %g %g -- max: %g %g %g",
            bb.min().x(), bb.min().y(), bb.min().z(),
            bb.max().x(), bb.max().y(), bb.max().z());
  Msg::Info("  Nx=%d Ny=%d Nz=%d", NX, NY, NZ);
  
  cartesianBox<double> box(bb.min().x(), bb.min().y(), bb.min().z(), 
                           SVector3(range.x(), 0, 0),
                           SVector3(0, range.y(), 0),
                           SVector3(0, 0, range.z()),
                           NX, NY, NZ, levels);

  Msg::Info("Inserting active cells in the cartesian grid");
  Msg::Info("  level %d", box.getLevel());
  for (unsigned int i = 0; i < points.size(); i++)
    insertActiveCells(points[i].x(), points[i].y(), points[i].z(), rmax, box);

  cartesianBox<double> *parent = &box, *child;
  while((child = parent->getChildBox())){
    Msg::Info("  level %d", child->getLevel());
    for(unsigned int i = 0; i < refinePoints.size(); i++)
      insertActiveCells(refinePoints[i].x(), refinePoints[i].y(), refinePoints[i].z(), 
                        rtube / pow(2., (levels - child->getLevel())), *child);
    parent = child;
  }

  // remove child cells that do not entirely fill parent cell or for
  // which there is no parent neighbor; then remove parent cells that
  // have children
  Msg::Info("Removing cells to match X-FEM mesh topology constraints");
  removeBadChildCells(&box);
  removeParentCellsWithChildren(&box);

  // we generate duplicate nodes at this point so we can easily access
  // cell values at each level; we will clean up by renumbering after
  // filtering
  Msg::Info("Initializing nodal values in the cartesian grid");
  box.createNodalValues();

  Msg::Info("Computing levelset on the cartesian grid");  
  computeLevelset(gm, box);

  Msg::Info("Removing cells outside the structure");
  removeOutsideCells(&box);

  Msg::Info("Renumbering mesh vertices across levels");
  box.renumberNodes();
  
  bool decomposeInSimplex = false;
  box.writeMSH("yeah.msh", decomposeInSimplex);

  Msg::Info("Done!");
  GmshFinalize();
}
