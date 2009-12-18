
#include "itkCurvatureAnisotropicDiffusionImageFilter.h"

#include "itkGradientMagnitudeRecursiveGaussianImageFilter.h"
#include "itkSigmoidImageFilter.h"

#include "itkImage.h"
#include "itkFastMarchingImageFilter.h"

#include "itkBinaryThresholdImageFilter.h"

#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"

#include "itkRescaleIntensityImageFilter.h"


int main( int argc, char *argv[] )
{
  if( argc < 8 )
    {
    std::cerr << "Missing Parameters " << std::endl;
    std::cerr << "Usage: " << argv[0];
    std::cerr << " inputImage  xi xf yi yf zi zf"<< std::endl;
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

  PixelTypeFloat pixelValue;
  ImageTypeFloat::IndexType pixelIndex;

  ImageTypeFloat::RegionType region;
  region = image->GetLargestPossibleRegion ();
  
  std::cout<<"GetImageDimensionX() :" << region.GetSize(0) << "\n" ;
  std::cout<<"GetImageDimensionY() :" << region.GetSize(1) << "\n" ;
  std::cout<<"GetImageDimensionZ() :" << region.GetSize(2) << "\n" ;

	std::cout<<"\nStart loops...\n" ;
  for (int k = atoi(argv[6]);k<atoi(argv[7]);k++){
  	for (int i = atoi(argv[2]);i<atoi(argv[3]);i++){
  		for (int j = atoi(argv[4]);j<atoi(argv[5]);j++){
      	pixelIndex[0] = i;   // x position
  			pixelIndex[1] = j;   // y position
        pixelIndex[2] = k;   // y position
				pixelValue = image->GetPixel( pixelIndex );
      	std::cout<< " " << pixelValue << " " ;
			}
				std::cout<< "\n" ;
		}
    std::cout<< "\n\n\n\n" ;    
  } 
 
  return 0;
}