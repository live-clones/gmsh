//
// Description : Import Float Level Set Image in Gmsh QuadTree Mesh
//
//
// Author:  <Boris Sedji>,  12/2009
//
// Copyright: See COPYING file that comes with this distribution
//
//




#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include <stdio.h>
#include "GModel.h"



#include "GModel.h"
#include "Gmsh.h"
#include "elasticitySolver.h"
#include "PView.h"
#include "PViewData.h"

#include "groupOfElements.h"
#include <iterator>


#include "Classes/ImageSolver.cpp"

#include "Classes/QuadtreeLSImage.cpp"
#include "Classes/OctreeLSImage.cpp"



int main( int argc, char *argv[] )
{
  if( argc < 5 )
  {
    std::cerr << "Missing Parameters " << std::endl;
    std::cerr << "Usage: " << argv[0];
    std::cerr << " inputLevelSetImage MeshSizeMax MeshSizeMin input.dat"<< std::endl;
    return 1;
  }

  bool simplex = 1;
	double facx = 1;
	double facy = 1;
	double facz = 1;

  GmshInitialize(argc, argv);

  typedef   float           PixelTypeFloat;
  const     unsigned int    Dimension = 3;
	typedef itk::Image< PixelTypeFloat, Dimension >  ImageTypeFloat;
  typedef itk::ImageFileReader< ImageTypeFloat > ImageReaderTypeFloat;
  ImageReaderTypeFloat::Pointer reader = ImageReaderTypeFloat::New();

  typedef itk::Image< PixelTypeFloat, 2 >  ImageTypeFloat2D;


  reader->SetFileName(argv[1]);

	ImageTypeFloat::Pointer image3D = reader->GetOutput();
  image3D->Update();

  ImageTypeFloat::RegionType region;
  region = image3D->GetLargestPossibleRegion ();
  std::cout<<"\nImage dimensions : " << region.GetSize(0) << " x " << region.GetSize(1) << " x " << region.GetSize(2)<<"\n";


  if (region.GetSize(2)==1)
  {
      typedef itk::ImageFileReader< ImageTypeFloat2D > ImageReaderTypeFloat2D;
      ImageReaderTypeFloat2D::Pointer reader2D = ImageReaderTypeFloat2D::New();
      ImageTypeFloat2D::Pointer image2D = reader2D->GetOutput();
      image2D->Update();
      QuadtreeLSImage tree(image2D);


  int sizemax = atoi(argv[2]);
  int sizemin = atoi(argv[3]);

	// Mesh with conditions on mesh size
  tree.Mesh(sizemax,sizemin);

	// Smoothing mesh to avoid too much generation between adjacent elements
	bool statut=false;
  int k = 0;
  std::cout<<"\nLeaf Number : "<< (tree.GetLeafNumber())<<"\n";
  while((!statut) & (k < 20)){
    statut = tree.Smooth();
    std::cout<<"\nk : "<< k;
		std::cout<<"\nsmoothed : " << (int)statut;
  	std::cout<<"\nLeaf Number : "<< (tree.GetLeafNumber())<<"\n";
    k++;
  }

	// Create GModel with the octree mesh
  GModel *m = tree.CreateGModel(simplex,facx,facy,facz,sizemax, sizemin);

	// Write a .msh file with the mesh
 	std::string ModelName = "TreeMesh.msh" ;
  m->writeMSH(ModelName,2.1,false,false);

	// Write a .msh file with the level set values as postview data
 	PView *pv = tree.CreateLSPView(m);
	bool useadapt = true;
 	pv->getData(useadapt)->writeMSH("LSPView.msh", false);


  ImageSolver mySolver(1000);

  std::vector< float >* ListLSValue = tree.getListLSValue();
  std::map< int ,std::vector<int> > * ListHangingNodes = tree.getListHangingNodes();
  mySolver.setMesh(m,2,*ListLSValue,*ListHangingNodes);

  int ok;
  std::cout<<"Verifier les conditions limites \n";
  //std::cin>>ok;

  mySolver.readInputFile(argv[4]);

   //solve the problem
  mySolver.solve() ;

    pv = mySolver.buildDisplacementView("displacement");
    pv->getData()->writeMSH("disp.msh", false);
    delete pv;
    pv = mySolver.buildElasticEnergyView("elastic energy");
    pv->getData()->writeMSH("energ.msh", false);
    delete pv;
  }
  if (region.GetSize(2)>1)
  {

  OctreeLSImage tree(image3D);


  int sizemax = atoi(argv[2]);
  int sizemin = atoi(argv[3]);

	// Mesh with conditions on mesh size
  tree.Mesh(sizemax,sizemin);

	// Smoothing mesh to avoid too much generation between adjacent elements
	bool statut=false;
  int k = 0;
  std::cout<<"\nLeaf Number : "<< (tree.GetLeafNumber())<<"\n";
  while((!statut) & (k < 20)){
    statut = tree.Smooth();
    std::cout<<"\nk : "<< k;
		std::cout<<"\nsmoothed : " << (int)statut;
  	std::cout<<"\nLeaf Number : "<< (tree.GetLeafNumber())<<"\n";
    k++;
  }

	// Create GModel with the octree mesh
  GModel *m = tree.CreateGModel(simplex,facx,facy,facz,sizemax, sizemin);

	// Write a .msh file with the mesh
 	std::string ModelName = "TreeMesh.msh" ;
  m->writeMSH(ModelName,2.1,false,false);

  PView *pv;
	// Write a .msh file with the level set values as postview data
 	//pv = tree.CreateLSPView(m);
//	bool useadapt = true;
// 	pv->getData(useadapt)->writeMSH("LSPView.msh", false);



  ImageSolver mySolver(1000);

  std::vector< float >* ListLSValue = tree.getListLSValue();
  std::map< int ,std::vector<int> > * ListHangingNodes = tree.getListHangingNodes();
  mySolver.setMesh(m,3,*ListLSValue,*ListHangingNodes);

  int ok;
  std::cout<<"Verifier les conditions limites \n";
  //std::cin>>ok;

  mySolver.readInputFile(argv[4]);

  // solve the problem
  mySolver.solve() ;
//
    pv = mySolver.buildDisplacementView("displacement");
    pv->getData()->writeMSH("disp.msh", false);
    delete pv;
//    pv = mySolver.buildElasticEnergyView("elastic energy");
//    pv->getData()->writeMSH("energ.msh", false);
//    delete pv;

  }
    // stop gmsh
    GmshFinalize();

  std::cout<<"\n";

  return 0;
}
