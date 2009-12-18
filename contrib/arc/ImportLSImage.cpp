//
// Description: 
//
//
// Author:  <Boris Sedji>,  12/2009
//
// Copyright: See COPYING file that comes with this distribution
//
//


#ifndef _ITK_H_

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#define _ITK_H_

#endif

#include "Octree.h"
#include <stdio.h>
#include "Gmsh.h"
#include "GModel.h"
#include "MElement.h"
#include "gmshLevelset.h"
#include "OctreeLSImage/OctreeLSImage.cpp"



int main( int argc, char *argv[] )
{
  if( argc < 4 )
  {
    std::cerr << "Missing Parameters " << std::endl;
    std::cerr << "Usage: " << argv[0];
    std::cerr << " inputLevelSetImage MeshSizeMax MeshSizeMin"<< std::endl;
    return 1;
  }

  typedef   float           PixelTypeFloat;
  const     unsigned int    Dimension = 3;
  typedef itk::Image< PixelTypeFloat, Dimension >  ImageTypeFloat;
  typedef itk::ImageFileReader< ImageTypeFloat > ImageReaderTypeFloat;
  ImageReaderTypeFloat::Pointer reader = ImageReaderTypeFloat::New();

  reader->SetFileName(argv[1]);    

	ImageTypeFloat::Pointer image = reader->GetOutput();
  image->Update();

  ImageTypeFloat::RegionType region;
  region = image->GetLargestPossibleRegion ();
  
  std::cout<<"\nImage dimensions : " << region.GetSize(0) << " x " << region.GetSize(1) << " x " << region.GetSize(2);

  OctreeLSImage octree(image);
  
  int sizemax = atoi(argv[2]);
  int sizemin = atoi(argv[3]);

	// Mesh with conditions on mesh size
  octree.Mesh(sizemax,sizemin);

	// Smoothing mesh to avoid too much generation between adjacent elements
	bool statut=false;
  int k = 0;
  std::cout<<"\nLeaf Number : "<< (octree.GetLeafNumber())<<"\n";
  while((!statut) & (k < 20)){
    statut = octree.Smooth();
    std::cout<<"\nk : "<< k;
		std::cout<<"\nsmoothed : " << (int)statut;
  	std::cout<<"\nLeaf Number : "<< (octree.GetLeafNumber())<<"\n";
    k++;
  }
	
	// Create GModel with the octree mesh
  GModel *m = octree.CreateGModel();
	
	// Write a .msh file with the mesh 
 	std::string ModelName = "OctreeMesh.msh" ;
   m->writeMSH(ModelName,2.1,false,false);
 
	// Write a .msh file with the level set values as postview data
 	PView *pv = octree.CreateLSPView(m);
	bool useadapt = true;
 	pv->getData(useadapt)->writeMSH("LSPView.msh", false);
 
  std::cout<<"\n";

  return 0;
}
