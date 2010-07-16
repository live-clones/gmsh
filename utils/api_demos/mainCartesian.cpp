#include "Gmsh.h"
#include "GModel.h"
#include "MVertex.h"
#include "cartesian.h"
#include "MTriangle.h"
#include "SOrientedBoundingBox.h"
#include "Numeric.h"

void insertBoxes(double x, double y, double z, double thickness, cartesianBox<double> &box)
{
  int id1 = box.index_of_element(x - thickness, y - thickness, z - thickness);
  int id2 = box.index_of_element(x + thickness, y + thickness, z + thickness);
  int i1, j1 ,k1;
  box.element_ijk(id1, i1, j1, k1);
  int i2, j2, k2;
  box.element_ijk(id2, i2, j2, k2);
  for (int i = i1; i <= i2; i++){
    for (int j = j1; j <= j2; j++){
      for (int k = k1; k <= k2; k++){
        int id = box.element_index(i, j, k);
        box.insert(id);
      }
    }
  }
}

int main (int argc,char *argv[])
{
  if(argc < 4){
    printf("Usage: %s file thickness npointsx [sampling] [filter]\n", argv[0]);
    printf("where\n");
    printf("  'file' contains a CAD model or a mesh\n");
    printf("  'thickness' sets the thickness of the layer of elements created around the surfaces\n");
    printf("  'npointsx' sets the number of mesh points along the x-axis\n");
    printf("  'sampling' sets the maximum distance between 2 sampling points on the surfaces\n");
    printf("  'filter' selects if only cells inside the body are saved in the mesh\n");
    return -1;
  }

  GmshInitialize();
  GmshMergeFile(argv[1]);
  double thickness = atof(argv[2]);
  int npointsx = atoi(argv[3]);
  double sampling = (argc > 4) ? atof(argv[4]) : thickness / 3.;
  int filter = (argc > 5) ? atoi(argv[5]) : 0;

  GModel *gm = GModel::current();
  
  std::vector<SPoint3> points;
  std::vector<SVector3> normals;

  for (GModel::fiter fit = gm->firstFace(); fit != gm->lastFace(); fit++)
    (*fit)->fillPointCloud(sampling, &points, &normals); 
  printf("%d points in the cloud\n", (int)points.size());

  // printf("OBB with %d points\n", points.size()); 
  // SOrientedBoundingBox *obb = SOrientedBoundingBox::buildOBB(points);
  // printf("OBB done\n"); 

  SBoundingBox3d bb;
  for(unsigned int i = 0; i < points.size(); i++) bb += points[i]; 
  bb.scale(1.2, 1.2, 1.2);
  SVector3 range = bb.max() - bb.min();   
  int NX = npointsx; 
  int NY = NX * range.y() / range.x(); 
  int NZ = NX * range.z() / range.x(); 

  printf("bb Min= %g %g %g -- bb Max= %g %g %g --NX %d NY %d NZ %d\n",
         bb.min().x(), bb.min().y(), bb.min().z(),
         bb.max().x(), bb.max().y(), bb.max().z(), NX, NY, NZ);

  cartesianBox<double> box(bb.min().x(), bb.min().y(), bb.min().z(), 
                           SVector3(range.x(), 0, 0),
                           SVector3(0, range.y(), 0),
                           SVector3(0, 0, range.z()),
                           NX, NY, NZ);

  for (unsigned int i = 0; i < points.size();i++)
    insertBoxes(points[i].x(), points[i].y(), points[i].z(), thickness, box);

  printf("insertion done\n");
  box.create_nodes();

  std::map<int,double>::const_iterator it = box.begin();
  std::vector<SPoint3> NODES;
  std::vector<SPoint3> CNODES;
  std::vector<int> indices;
  std::vector<double> dist, localdist;
  for ( ; it != box.end(); ++it){
    NODES.push_back(box.coordinates_of_node(it->first));
    indices.push_back(it->first);
  }  
  printf("%d nodes in the cartesian mesh\n", (int)NODES.size());

  for (GModel::fiter fit = gm->firstFace(); fit != gm->lastFace(); fit++){
    for (int i = 0; i < (*fit)->stl_triangles.size(); i += 3){
      int i1 = (*fit)->stl_triangles[i];
      int i2 = (*fit)->stl_triangles[i + 1];
      int i3 = (*fit)->stl_triangles[i + 2];
      GPoint p1 = (*fit)->point((*fit)->stl_vertices[i1]);
      GPoint p2 = (*fit)->point((*fit)->stl_vertices[i2]);
      GPoint p3 = (*fit)->point((*fit)->stl_vertices[i3]);
      SPoint2 ppp = ((*fit)->stl_vertices[i1] + (*fit)->stl_vertices[i2] + (*fit)->stl_vertices[i3]) * 0.33333333;
      SVector3 N = (*fit)->normal(ppp);
      SPoint3 P1(p1.x(), p1.y(), p1.z());
      SPoint3 P2(p2.x(), p2.y(), p2.z());
      SPoint3 P3(p3.x(), p3.y(), p3.z());
      SVector3 NN(crossprod(P2 - P1, P3 - P1));
      if (dot(NN, N) > 0)
	signedDistancesPointsTriangle(localdist, CNODES, NODES, P1, P2, P3);
      else
	signedDistancesPointsTriangle(localdist, CNODES, NODES, P2, P1, P3);
      if(dist.empty()) 
        dist = localdist;
      else 
        for (unsigned int j = 0; j < localdist.size(); j++)
          dist[j] = (fabs(dist[j]) < fabs(localdist[j])) ? dist[j] : localdist[j];
    }
  }
  for (unsigned int j = 0; j < dist.size(); j++)
    box.setValue(indices[j], dist[j]);

  if(filter){
    int nbErased = 0;
    //Coup de menage avant d'exporter le maillage
    for(cartesianBox<double>::boxIter it = box.activeBoxBegin(); it != box.activeBoxEnd();){
      std::vector<double> ls_vals;
      box.getNodalValues(*it, ls_vals);
      double lsmax = *std::max_element(ls_vals.begin(), ls_vals.end());
      double lsmin = *std::min_element(ls_vals.begin(), ls_vals.end());
      double change_sign = lsmax * lsmin ;
      double epsilon = 1.e-10;
      if(change_sign > 0 && lsmax < -epsilon) { 
        box.erase(*(it++));
        nbErased++;
      }
      else ++it;
    }
    std::cout << "Number of erased cells after filtering : " << nbErased << std::endl;
  }
  
  printf("nodes created\n");
  box.writeMSH("yeah.msh", true);

  box.writeMSH("youhou.msh", true, false);
  box.writeNodalValues("youhou.pos");
  printf("mesh written\n");
  GmshFinalize();
}
