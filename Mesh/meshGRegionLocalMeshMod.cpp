#include "meshGRegionLocalMeshMod.h"

static int edges[6][2] =    {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
static int efaces[6][2] =   {{0,2},{0,1},{1,2},{0,3},{2,3},{1,3}};
static int enofaces[6][2] = {{1,3},{2,3},{0,3},{1,2},{0,1},{0,2}};
static int facesXedges[4][3] = {{0,1,3},{1,2,5},{0,2,4},{3,4,5}};
static int faces[4][3] = {{0,1,2},{0,2,3},{0,1,3},{1,2,3}};
static int vFac[4][3] = {{0,1,2},{0,2,3},{0,1,3},{1,2,3}};

// as input, we give a tet and an edge, as return, we get
// all tets that share this edge and all vertices that are
// forming the outer ring of the cavity 
// we return true if the cavity is closed and false if it is open
bool gmshBuildEdgeCavity ( MTet4 *t, 
			   int iLocalEdge, 
			   MVertex **v1,MVertex **v2,
			   std::vector<MTet4*> &cavity,
			   std::vector<MTet4*> &outside,
			   std::vector<MVertex*> &ring ){
  cavity.clear();
  ring.clear();
  outside.clear();

  //  FILE *f = fopen ("pts.pos","w");
  //  fprintf(f,"View \"\"{\n");

  *v1 = t->tet()->getVertex(edges[iLocalEdge][0]);
  *v2 = t->tet()->getVertex(edges[iLocalEdge][1]);

  //  printf("trying to swap %p %p (%p,%p,%p,%p)\n",(*v1),(*v2),t->tet()->getVertex(0),t->tet()->getVertex(1),t->tet()->getVertex(2),t->tet()->getVertex(3));

  MVertex *lastinring = t->tet()->getVertex(edges[5-iLocalEdge][0]);
  
  //  fprintf(f,"SP(%g,%g,%g){%d};\n",(*v1)->x(),(*v1)->y(),(*v1)->z(),-1);
  //  fprintf(f,"SP(%g,%g,%g){%d};\n",(*v2)->x(),(*v2)->y(),(*v2)->z(),-2);

  //  fprintf(f,"SP(%g,%g,%g){%d};\n",lastinring->x(),lastinring->y(),lastinring->z(),ring.size());

  //  printf("the ring starts with %p \n",lastinring);

  ring.push_back(lastinring);
  cavity.push_back(t);

  while (1){
    MVertex *ov1 = t->tet()->getVertex(edges[5-iLocalEdge][0]);
    MVertex *ov2 = t->tet()->getVertex(edges[5-iLocalEdge][1]);
    int K = ov1 == lastinring ? 1 : 0;
    lastinring = ov1 == lastinring ? ov2 : ov1;
    // look in the 2 faces sharing this edge the one that has vertex 
    // ov2 i.e. edges[5-iLocalEdge][1]

    int iFace;
//     int iFaceOK;
//     for (int i=0;i<4;i++)
//       {
// 	MVertex *f1 = t->tet()->getVertex(faces[i][0]);
// 	MVertex *f2 = t->tet()->getVertex(faces[i][1]);
// 	MVertex *f3 = t->tet()->getVertex(faces[i][2]);
// 	if ((f1 == *v1 && f2 == *v2 && f3 == lastinring) ||
// 	    (f1 == *v1 && f3 == *v2 && f2 == lastinring) ||
// 	    (f2 == *v1 && f1 == *v2 && f3 == lastinring) ||
// 	    (f2 == *v1 && f3 == *v2 && f1 == lastinring) ||
// 	    (f3 == *v1 && f2 == *v2 && f1 == lastinring) ||
// 	    (f3 == *v1 && f1 == *v2 && f2 == lastinring) )iFaceOK = i;
//       }

    int iFace1 = efaces[iLocalEdge][0];
    int iFace2 = efaces[iLocalEdge][1];
    if (faces[iFace1][0] == edges[5-iLocalEdge][K] ||
	faces[iFace1][1] == edges[5-iLocalEdge][K] ||
	faces[iFace1][2] == edges[5-iLocalEdge][K] ) iFace = iFace1;
    else if (faces[iFace2][0] == edges[5-iLocalEdge][K] ||
	     faces[iFace2][1] == edges[5-iLocalEdge][K] ||
	     faces[iFace2][2] == edges[5-iLocalEdge][K] ) iFace = iFace2;
    else {printf("error of connexion\n");throw;}
    //    else iFace = iFace2;

    //    printf("iFaceOK %d iFace %d\n",iFaceOK,iFace);

    if (!t->getNeigh(iFace))return false;
    t=t->getNeigh(iFace);
    if (t->isDeleted())throw;
    //    printf("next tet (%p,%p,%p,%p)\n",t->tet()->getVertex(0),t->tet()->getVertex(1),t->tet()->getVertex(2),t->tet()->getVertex(3));
    //    int iNoFace1 = enofaces[iLocalEdge][0];
    //    int iNoFace2 = enofaces[iLocalEdge][1];

    if (t==*(cavity.begin())) break;
    //    fprintf(f,"SP(%g,%g,%g){%d};\n",lastinring->x(),lastinring->y(),lastinring->z(),ring.size());
    ring.push_back(lastinring);    
    //    printf("the ring continues with %p \n",lastinring);

    cavity.push_back(t);
    iLocalEdge = -1;
    for (int i=0;i<6;i++)
      {
	MVertex *a = t->tet()->getVertex(edges[i][0]);
	MVertex *b = t->tet()->getVertex(edges[i][1]);
	if ((a == *v1 && b == *v2) || (a == *v2 && b == *v1)){
	  iLocalEdge = i;
	  break;
	}
      }  
    if (iLocalEdge == -1){
      printf("ERROR : loc = %d\n",iLocalEdge);
      throw;
    }
  }
  //  fprintf(f,"};\n");
  //  fclose(f);
  //  getchar();
  
  for (int i=0;i<cavity.size();i++){
    for (int j=0;j<4;j++){
      MTet4 * neigh = cavity[i]->getNeigh(j);
      if (neigh)
	{
	  bool found = false;
	  for (int k=0;k<outside.size();k++)if(outside[k]==neigh)found=true;
	  if(!found)outside.push_back(neigh);
	}
    }
  }

  return true;
}

typedef struct {
  int nbr_triangles ;           /* number of different triangles       */
  int (*triangles)[3] ;         /* triangles array                     */
  int nbr_trianguls ;           /* number of different triangulations  */
  int nbr_triangles_2 ;         /* number of triangles / triangulation */
  int (*trianguls)[5] ;         /* retriangulations array              */
} SwapPattern ;


void BuildSwapPattern3(SwapPattern *sc)
{
  static int trgl[][3] = { 0,1,2 } ;
  static int trgul[][5] = { 0,-1,-1,-1,-1 } ;

  sc->nbr_triangles = 1 ;
  sc->nbr_triangles_2 = 1 ;
  sc->nbr_trianguls = 1 ;
  sc->triangles = trgl ;
  sc->trianguls = trgul ;
}

void BuildSwapPattern4(SwapPattern *sc)
{
  static int trgl[][3] =
    { 0,1,2, 0,2,3, 0,1,3, 1,2,3 } ;
  static int trgul[][5] = 
    { 0,1,-1,-1,-1, 2,3,-1,-1,-1 } ;

  sc->nbr_triangles = 4 ;
  sc->nbr_triangles_2 = 2 ; 
  sc->nbr_trianguls = 2 ; 
  sc->triangles = trgl ;
  sc->trianguls = trgul ;
}


void BuildSwapPattern5(SwapPattern *sc)
{
  static int trgl[][3] = 
    { 0,1,2, 0,2,3, 0,3,4, 0,1,4, 1,3,4, 1,2,3, 2,3,4, 0,2,4, 0,1,3, 1,2,4 } ;
  static int trgul[][5] =
    { 0,1,2,-1,-1, 3,4,5,-1,-1, 0,6,7,-1,-1, 2,5,8,-1,-1, 3,6,9,-1,-1 } ;

  sc->nbr_triangles = 10 ;
  sc->nbr_triangles_2 = 3 ;
  sc->nbr_trianguls = 5 ;
  sc->triangles = trgl ;
  sc->trianguls = trgul ; 
}

void BuildSwapPattern6(SwapPattern *sc)
{
  static int trgl[][3] = 
    { 0,1,2, 0,2,3, 0,3,4, 0,4,5, 0,2,5, 2,4,5, 2,3,4, 0,3,5,
      3,4,5, 0,2,4, 2,3,5, 1,2,3, 0,1,3, 0,1,5, 1,4,5, 1,3,4,
      0,1,4, 1,3,5, 1,2,4, 1,2,5 } ;
  static int trgul[][5] = 
    { 0,1,2,3,-1, 0,4,5,6,-1, 0,1,7,8,-1, 0,3,6,9,-1, 0,4,8,10,-1,
      2,3,11,12,-1, 11,13,14,15,-1, 7,8,11,12,-1, 3,11,15,16,-1,
      8,11,13,17,-1, 6,13,14,18,-1, 3,6,16,18,-1, 5,6,13,19,-1, 
      8,10,13,19,-1 } ;

  sc->nbr_triangles = 20 ; 
  sc->nbr_triangles_2 = 4 ; 
  sc->nbr_trianguls = 14 ; 
  sc->triangles = trgl ; 
  sc->trianguls = trgul ;
}

void BuildSwapPattern7(SwapPattern *sc)
{
  static int trgl[][3] = 
    { 0,1,2, 0,2,3, 0,3,4, 0,4,5, 0,5,6, 0,3,6, 3,5,6, 3,4,5, 0,4,6,
      4,5,6, 0,3,5, 3,4,6, 0,2,4, 2,3,4, 0,2,6, 2,5,6, 2,4,5, 0,2,5,
      2,4,6, 2,3,5, 2,3,6, 0,1,3, 1,2,3, 0,1,4, 1,3,4, 0,1,6, 1,5,6,
      1,4,5, 0,1,5, 1,4,6, 1,3,5, 1,3,6, 1,2,4, 1,2,5, 1,2,6 };
  static int trgul[][5] = 
    { 0,1,2,3,4, 0,1,5,6,7, 0,1,2,8,9, 0,1,4,7,10, 0,1,5,9,11, 0,3,4,12,13,
      0,13,14,15,16, 0,8,9,12,13, 0,4,13,16,17, 0,9,13,14,18, 0,7,14,15,19,
      0,4,7,17,19, 0,6,7,14,20, 0,9,11,14,20, 2,3,4,21,22, 5,6,7,21,22,
      2,8,9,21,22, 4,7,10,21,22, 5,9,11,21,22, 3,4,22,23,24, 22,24,25,26,27,
      8,9,22,23,24, 4,22,24,27,28, 9,22,24,25,29, 7,22,25,26,30, 4,7,22,28,30,
      6,7,22,25,31, 9,11,22,25,31, 3,4,13,23,32, 13,25,26,27,32, 8,9,13,23,32,
      4,13,27,28,32, 9,13,25,29,32, 13,16,25,26,33, 4,13,16,28,33, 
      13,15,16,25,34, 9,13,18,25,34, 7,19,25,26,33, 4,7,19,28,33,
      7,15,19,25,34, 6,7,20,25,34, 9,11,20,25,34 } ;

  sc->nbr_triangles = 35 ;
  sc->nbr_triangles_2 = 5 ;
  sc->nbr_trianguls = 42 ;
  sc->triangles = trgl ;
  sc->trianguls = trgul ;
}


void gmshEdgeSwap (std::vector<MTet4 *> &newTets,
		   MTet4 *tet, 
		   int iLocalEdge,
		   const gmshQualityMeasure4Tet &cr){
  std::vector<MTet4*> cavity;
  std::vector<MTet4*> outside;
  std::vector<MVertex*> ring;
  MVertex *v1,*v2;
  //  printf("swapping an edge\n");

  bool closed = gmshBuildEdgeCavity ( tet,iLocalEdge,&v1,&v2,cavity,outside,ring);


  if (!closed)return;
  
  double volumeRef = 0.0;
  double tetQualityRef = 1;
  for (int i=0;i<cavity.size();i++){
    double vol;
    tetQualityRef = std::min(qmTet (cavity[i]->tet() ,  cr , &vol) , tetQualityRef);
    //    printf("%p %p -> %p %p %p %p\n",v1,v2,cavity[i]->tet()->getVertex(0),cavity[i]->tet()->getVertex(1),cavity[i]->tet()->getVertex(2),cavity[i]->tet()->getVertex(3));
    volumeRef += fabs(vol);
  }

  // build swap patterns

  SwapPattern sp;
  switch (ring.size()){
  case 3 : BuildSwapPattern3 (&sp); break;
  case 4 : BuildSwapPattern4 (&sp); break;
  case 5 : BuildSwapPattern5 (&sp); break;
  case 6 : BuildSwapPattern6 (&sp); break;
  case 7 : BuildSwapPattern7 (&sp); break;
  default : return;
  }

  //  printf("the cavity contains %d tets the ring is of size %d volume %12.5E qual %12.5E\n",cavity.size(),ring.size(),volumeRef,tetQualityRef);

  // compute qualities of all tets that appear in the patterns 
  double tetQuality1[100],tetQuality2[100];
  double volume1[100],volume2[100];
  for (int i=0;i<sp.nbr_triangles;i++){
    int p1 = sp.triangles[i][0];
    int p2 = sp.triangles[i][1];
    int p3 = sp.triangles[i][2];   
    tetQuality1[i] = qmTet ( ring[p1], ring[p2], ring[p3], v1 , cr , &(volume1[i]));
    tetQuality2[i] = qmTet ( ring[p1], ring[p2], ring[p3], v2 , cr , &(volume2[i]));  
    //    printf("points %d %d %d vol %g %g qual %g %g\n",p1,p2,p3,volume1[i],volume2[i],tetQuality1[i],tetQuality2[i]);
  }



  // look for the best triangulation, i.e. the one
  // that maximize the minimum element quality
  double minQuality[100];
  // for all triangulations
  for (int i=0;i<sp.nbr_trianguls;i++){
    // for all triangles in a triangulation
    minQuality[i] = 1;
    double volume=0;
    for (int j=0;j<sp.nbr_triangles_2;j++){
      int iT = sp.trianguls[i][j];
      minQuality[i] = std::min (minQuality[i],tetQuality1[iT]);
      minQuality[i] = std::min (minQuality[i],tetQuality2[iT]);
      volume += (volume1[iT] + volume2[iT] );
    }
    //    printf("config %3d qual %12.5E volume %12.5E\n",i,minQuality[i],volume);
    if (fabs(volume-volumeRef) > 1.e-12 * (volume+volumeRef))minQuality[i] = 0;
  }

  int iBest;
  double best = 0.0;
  for (int i=0;i<sp.nbr_trianguls;i++){
    if(minQuality[i] > best)
      {
	best = minQuality[i];
	iBest = i;
      }
  }

  // if there exist no swap that enhance the quality
  if (best <= tetQualityRef) return;
  
//   printf("swap is performed\n");

//   return;

  // we have the best configuration, so we swap
  //  printf("outside size = %d\n",outside.size());

  double volumeAssert = 0;
  for (int j=0;j<sp.nbr_triangles_2;j++){
    int iT = sp.trianguls[iBest][j];
    int p1 = sp.triangles[iT][0];
    int p2 = sp.triangles[iT][1];
    int p3 = sp.triangles[iT][2];  
    MVertex *pv1 = ring[p1];
    MVertex *pv2 = ring[p2];
    MVertex *pv3 = ring[p3];
    MTetrahedron *tr1 = new MTetrahedron ( pv1,
					   pv2,
					   pv3,
					   v1);
    MTetrahedron *tr2 = new MTetrahedron ( pv3,
					   pv2,
					   pv1,
					   v2);
    volumeAssert += (fabs(tr1->getVolume()) +fabs(tr2->getVolume()) ); 

    MTet4 *t41 = new MTet4 ( tr1 ); 
    MTet4 *t42 = new MTet4 ( tr2 );
    t41->setOnWhat(cavity[0]->onWhat());
    t42->setOnWhat(cavity[0]->onWhat());
    outside.push_back(t41);
    outside.push_back(t42);
    newTets.push_back(t41);
    newTets.push_back(t42);
  }
  if (fabs(volumeRef-volumeAssert) > 1.e-10 * volumeRef) printf("volumes = %12.5E %12.5E\n",volumeRef,volumeAssert);

  for (int i=0;i<cavity.size();i++){
    cavity[i]->setDeleted(true);
  }

  connectTets ( outside );      

}


void gmshBuildVertexCavity_recur ( MTet4 *t, 
				   MVertex *v, 
				   std::vector<MTet4*> &cavity){
  int iV=-1;
  for (int i=0; i<4; i++){
    if (t->tet()->getVertex(i) == v){
      iV = i;
      break;
    }
  }
  if (iV==-1)throw;
  for (int i=0; i<3; i++){
    MTet4 *neigh = t->getNeigh(vFac[iV][i]);
    if (neigh){
      bool found = false;
      for (int j=0;j<cavity.size();j++){if (cavity[j] == neigh){found = true; break;}}
      if (!found){
	cavity.push_back(neigh);
	gmshBuildVertexCavity_recur ( neigh,v,cavity);
      }
    }
  }
}


void gmshSmoothVertex ( MTet4 *t, 
			int iVertex){
  std::vector<MTet4*> cavity;
  cavity.push_back(t);
  gmshBuildVertexCavity_recur (t,t->tet()->getVertex(iVertex),cavity);
  
  //  printf("cavity o size %d\n",cavity.size());

  double xcg=0,ycg=0,zcg=0;  
  double vTot=0;
  double worst = 1.0;
  for (int i=0 ; i< cavity.size() ; i++){
    double volume;
    double q = qmTet(cavity[i]->tet(),QMTET_2,&volume);
    worst = std::min(worst,q);
    xcg += 0.25*(cavity[i]->tet()->getVertex(0)->x()+cavity[i]->tet()->getVertex(1)->x()+cavity[i]->tet()->getVertex(2)->x()+cavity[i]->tet()->getVertex(3)->x())*volume;
    ycg += 0.25*(cavity[i]->tet()->getVertex(0)->y()+cavity[i]->tet()->getVertex(1)->y()+cavity[i]->tet()->getVertex(2)->y()+cavity[i]->tet()->getVertex(3)->y())*volume;
    zcg += 0.25*(cavity[i]->tet()->getVertex(0)->z()+cavity[i]->tet()->getVertex(1)->z()+cavity[i]->tet()->getVertex(2)->z()+cavity[i]->tet()->getVertex(3)->z())*volume;    
    vTot += volume;
    
  }
  xcg /= (vTot);
  ycg /= (vTot);
  zcg /= (vTot);
  double volumeAfter = 0.0;

  double x = t->tet()->getVertex(iVertex)->x();
  double y = t->tet()->getVertex(iVertex)->y();
  double z = t->tet()->getVertex(iVertex)->z();

  t->tet()->getVertex(iVertex)->x() = xcg;
  t->tet()->getVertex(iVertex)->y() = ycg;
  t->tet()->getVertex(iVertex)->z() = zcg;
  double worstAfter = 1.0;
  for (int i=0 ; i< cavity.size() ; i++){
    double volume;
    double q = qmTet(cavity[i]->tet(),QMTET_2,&volume);
    volumeAfter += volume;
    worstAfter =std::min(worstAfter,q);
  }

  if (fabs(volumeAfter-vTot) > 1.e-10 * vTot || worstAfter < worst){
    t->tet()->getVertex(iVertex)->x() = x;
    t->tet()->getVertex(iVertex)->y() = y;
    t->tet()->getVertex(iVertex)->z() = z;
  }
}


