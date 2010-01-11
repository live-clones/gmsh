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
#include "Classes/QuadtreeLSImage.cpp"



int main( int argc, char *argv[] )
{
  if( argc < 4 )
  {
    std::cerr << "Missing Parameters " << std::endl;
    std::cerr << "Usage: " << argv[0];
    std::cerr << " inputLevelSet2dImage MeshSizeMax MeshSizeMin"<< std::endl;
    return 1;
  }

  typedef   float           PixelTypeFloat;
  const     unsigned int    Dimension = 2;
	typedef itk::Image< PixelTypeFloat, Dimension >  ImageTypeFloat;
  typedef itk::ImageFileReader< ImageTypeFloat > ImageReaderTypeFloat;
  ImageReaderTypeFloat::Pointer reader = ImageReaderTypeFloat::New();

	
  reader->SetFileName(argv[1]);    

	ImageTypeFloat::Pointer image = reader->GetOutput();
  image->Update();

  ImageTypeFloat::RegionType region;
  region = image->GetLargestPossibleRegion ();
  
  std::cout<<"\nImage dimensions : " << region.GetSize(0) << " x " << region.GetSize(1);

  QuadtreeLSImage quadtree(image);
  
  int sizemax = atoi(argv[2]);
  int sizemin = atoi(argv[3]);

	// Mesh with conditions on mesh size
  quadtree.Mesh(sizemax,sizemin);

	// Smoothing mesh to avoid too much generation between adjacent elements
	bool statut=false;
  int k = 0;
  std::cout<<"\nLeaf Number : "<< (quadtree.GetLeafNumber())<<"\n";
  while((!statut) & (k < 20)){
    statut = quadtree.Smooth();
    std::cout<<"\nk : "<< k;
		std::cout<<"\nsmoothed : " << (int)statut;
  	std::cout<<"\nLeaf Number : "<< (quadtree.GetLeafNumber())<<"\n";
    k++;
  }
	
	// Create GModel with the octree mesh
  GModel *m = quadtree.CreateGModel();
	
	// Write a .msh file with the mesh 
 	std::string ModelName = "QuadtreeMesh.msh" ;
   m->writeMSH(ModelName,2.1,false,false);
 
	// Write a .msh file with the level set values as postview data
 	PView *pv = quadtree.CreateLSPView(m);
	bool useadapt = true;
 	pv->getData(useadapt)->writeMSH("LSPView.msh", false);
 
  std::cout<<"\n";

  return 0;
}
