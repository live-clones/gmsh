#include <gmsh/Gmsh.h>
#include <gmsh/GModel.h>
#include <gmsh/MVertex.h>
#include <gmsh/cartesian.h>
#include <gmsh/MTriangle.h>
#include <gmsh/SOrientedBoundingBox.h>
#include <gmsh/Numeric.h>

void insertBoxes ( double x, double y, double z, double EP, cartesianBox<double> &box){
  
  int id1 = box.index_of_element(x-EP,y-EP,z-EP);      
  int id2 = box.index_of_element(x+EP,y+EP,z+EP);      
  int i1,j1,k1;
  box.element_ijk(id1,i1,j1,k1);
  int i2,j2,k2;
  box.element_ijk(id2,i2,j2,k2);
  //  if (y > 0.9)printf("%g %g %g %3d %3d %3d %3d %3d %3d\n",x,y,z,i1,j1,k1,i2,j2,k2);
  for (int i=i1;i<=i2;i++){
    for (int j=j1;j<=j2;j++){
      for (int k=k1;k<=k2;k++){
        int id = box.element_index(i,j,k);
        box.insert(id);   
      }
    }
  }
}

void test(){
  printf("enter z coordinate : ");
  double x,y,z=-1;
  scanf ("%lf",&z);
  printf(" z = %g\n",z);
  std::vector<SPoint3> v;
  std::vector<double> d;

  for (int i=0;i<100;i++){
    for (int j=0;j<100;j++){
      x = -.5+(double) i/50.;
      y = -.5+(double) j/50.;
      v.push_back(SPoint3(4.3,x,y));
    }
  }
  signedDistancesPointsTriangle (d,v,SPoint3(4,0,0),SPoint3(4,1,0),SPoint3(4,0,1));
  
  FILE *f = fopen ("chitte.pos","w");
  fprintf(f,"View \"\"{\n");
  for( int i=0;i<v.size();i++){
    fprintf(f,"SP(%g,%g,%g){%g};\n",v[i].x(),v[i].y(),v[i].z(),d[i]);
  }
  fprintf(f,"};\n");
  fclose(f);
  
}

int main (int argc,char *argv[]){
  
  //  test();
  //  return 1;

  // ne pas oublier les conditions limites 

  GmshInitialize();

  if (argc != 5){
    printf("usage : mainCartesian meshFile thickness NPointsX SAMPLING(smaller than thickness)\n");
    return -1;
  }

  const int FACT=atoi(argv[3]);

  double EP = atof(argv[2]);   

  double SAMPLING;
  if (argc == 5)SAMPLING = atof(argv[4]);
  else SAMPLING = EP/3.0;
  
  GmshMergeFile(argv[1]);
    
  GModel *gm = GModel::current();
  
  printf("mesh read\n");
  
  std::vector<SPoint3> POINTS;
  std::vector<SVector3> NORMALS;

  for (GModel::fiter fit = gm->firstFace(); fit != gm->lastFace(); fit++){
    (*fit)->fillPointCloud(SAMPLING,&POINTS,&NORMALS); 
  }

  // printf("OBB with %d points\n",POINTS.size()); 
  //  SOrientedBoundingBox *obb = SOrientedBoundingBox::buildOBB (POINTS);
  //  printf("OBB done\n"); 

  SBoundingBox3d bb;
  for(int i=0;i<POINTS.size();i++){
    bb += POINTS[i]; 
  }

  bb.scale(1.2,1.2,1.2); 


  SVector3 range = bb.max() - bb.min();   
  int NX =FACT; 
  int NY =FACT*range.y()/range.x(); 
  int NZ =FACT*range.z()/range.x(); 

  printf("%g %g %g -- %g %g %g -- %d %d %d\n",bb.min().x(),bb.min().y(),bb.min().z(),
         bb.max().x(),bb.max().y(),bb.max().z(),NX,NY,NZ);


  cartesianBox<double> box ( bb.min().x(),bb.min().y(),bb.min().z(), 
                             SVector3(range.x(),0,0),
                             SVector3(0,range.y(),0),
                             SVector3(0,0,range.z()),
                             NX,NY,NZ);
  
  box.points() = POINTS;
  box.normals() = NORMALS;
  
  printf("%d points in the cloud \n", box.points().size());

  
  //  FILE *f = fopen ("chitte.pos","w");
  //  fprintf(f,"View \"\"{\n");

  for (int i=0; i< POINTS.size();i++){    
    insertBoxes ( POINTS [i].x(), POINTS [i].y(), POINTS [i].z(), EP, box);
    //    fprintf(f,"SP(%g,%g,%g){%g};\n",POINTS[i].x(),POINTS[i].y(),POINTS[i].z(),0.0);
  }  
  //  fprintf(f,"};\n");
  //  fclose(f);


  printf("insertion done\n");
  box.create_nodes();


  std::map<int,double>::const_iterator it = 
    box.begin();
  std::vector<SPoint3> NODES;
  std::vector<int> indices;;
  std::vector<double> dist,localdist;
  for ( ; it!=box.end();++it){
    NODES.push_back(box.coordinates_of_node(it->first));    
    indices.push_back(it->first);
  }  
  printf("%d nodes in the cartesian mesh\n",NODES.size());
  int III = 0;
  for (GModel::fiter fit = gm->firstFace(); fit != gm->lastFace(); fit++){
    //    printf("model face %d : %d triangles\n",(*fit)->tag(),(*fit)->stl_triangles.size()/3);
    for (int i=0;i<(*fit)->stl_triangles.size(); i+=3){
      int i1 = (*fit)->stl_triangles[i];
      int i2 = (*fit)->stl_triangles[i+1];
      int i3 = (*fit)->stl_triangles[i+2];
      GPoint p1 = (*fit)->point((*fit)->stl_vertices[i1]);
      GPoint p2 = (*fit)->point((*fit)->stl_vertices[i2]);
      GPoint p3 = (*fit)->point((*fit)->stl_vertices[i3]);

      SPoint2 ppp = ((*fit)->stl_vertices[i1]+(*fit)->stl_vertices[i2]+(*fit)->stl_vertices[i3])*.3333333333;
      SVector3 N = (*fit)->normal(ppp);
      SPoint3 P1 (p1.x(),p1.y(),p1.z());
      SPoint3 P2 (p2.x(),p2.y(),p2.z());
      SPoint3 P3 (p3.x(),p3.y(),p3.z());
      SVector3 NN (crossprod(P2-P1,P3-P1));
      
      //      printf("N1 %g %g %g N2 %g %g %g -- %g %g %g -- %g %g %g -- %g %g %g\n",N.x(),N.y(),N.z(),NN.x(),NN.y(),NN.z(),
      //             p1.x(),p1.y(),p1.z(),p2.x(),p2.y(),p2.z(),p3.x(),p3.y(),p3.z());
      if (dot(NN, N) > 0)
        signedDistancesPointsTriangle (localdist,NODES,P1,P2,P3);
      else
        signedDistancesPointsTriangle (localdist,NODES,P2,P1,P3);

      if(1){
        if (dist.empty())dist=localdist;
        else 
          for (int j=0;j<localdist.size();j++)
            dist[j] = (fabs(dist[j]) < fabs(localdist[j])) ? dist[j] : localdist[j];
      }
    }
    III++;
  }
  
  for (int j=0;j<dist.size();j++){
    //    printf("d(%d)=%g\n",indices[j],dist[j]);
    box.setValue(indices[j],dist[j]);
  }
  
  printf("nodes created\n");
  box.writeMSH("yeah.msh");
  printf("mesh written\n");
  GmshFinalize();
}
