#ifndef _MGEOM_SEARCH_H
#define _MGEOM_SEARCH_H
#include <vector>
#include <algorithm>
#define MIN(x,y) ((x<y)?(x):(y))
#define MAX(x,y) ((x>y)?(x):(y))
#define TOL 1.e-06

namespace AOMD {

  template <class T>
  class Brick
  {
  public:
    std::vector<T*> Objects;
    Brick(){}
    T* operator [] (int i)
    {
      if(i < 0 || i >= Objects.size())throw i;
      T *obj = Objects[i];
      return obj;
    }
    int size(){return Objects.size();}
  };

  template <class T, class GetBox, class InteriorCheck>
  class mGeomSearch
  {
    Brick<T> *theTable;
    int Nx,Ny,Nz;
    double Xmin,Xmax,Ymin,Ymax,Zmin,Zmax;
    int getBrickId (double X, double Y, double Z)
    {
      int Ix = (int)((double)Nx * (X-Xmin) / (Xmax-Xmin)); 
      int Iy = (int)((double)Ny * (Y-Ymin) / (Ymax-Ymin)); 
      int Iz = (int)((double)Nz * (Z-Zmin) / (Zmax-Zmin)); 
      Ix = MIN(Ix,Nx-1);
      Iy = MIN(Iy,Ny-1);
      Iz = MIN(Iz,Nz-1);
      if(Ix<0)Ix=0;
      if(Iy<0)Iy=0;
      if(Iz<0)Iz=0;
      int index = Ix + Iy * Nx + Iz * Nx * Ny;
      return index;
    }
    Brick<T> * getBrick (int index)
    {
      if(index <0 || index >= Nx*Ny*Nz)throw index;
      Brick<T> *b = &(theTable[index]);
      return b;
    }
    GetBox getBox;
    InteriorCheck interiorCheck;
  public:
    mGeomSearch (double x1,
		 double x2,
		 double y1, 
		 double y2, 
		 double z1, 
		 double z2,
		 GetBox g,
		 InteriorCheck i,
		 int nx = 10, 
		 int ny = 10, 
		 int nz = 10) :	Nx(nx), Ny(ny), Nz(nz),getBox(g),interiorCheck(i)
    {
      Xmin = x1-TOL; Xmax  = x2+TOL;
      Ymin = y1-TOL; Ymax  = y2+TOL;
      Zmin = z1-TOL; Zmax  = z2+TOL;
      
      theTable = new Brick<T> [Nx*Ny*Nz];
    }
  
    ~mGeomSearch ()
    {
      delete [] theTable;
    };
    Brick<T> *getBrick(double X, double Y, double Z)
    {
      return (getBrick(getBrickId(X,Y,Z)));
    }
    T * find (double X[3] , double U[3]);
    bool AddObject ( T *);
    bool RemoveObject ( T *);
  };

  template <class T,class GetBox, class InteriorCheck> 
  T *  mGeomSearch<T,GetBox,InteriorCheck> :: find ( double X[3] ,
						     double U[3] )
  {
    Brick<T> *b = getBrick (X[0],X[1],X[2]);
    if(!b) return 0;

    for(int i=0;i<b->size();i++)
      {
	T * obj = (*b)[i];	
	if(interiorCheck(obj,X,U))return obj;
      }
    return 0;
  }

  template <class T,class GetBox, class InteriorCheck> 
  bool mGeomSearch<T,GetBox, InteriorCheck> :: AddObject ( T * obj )
  {
    int     Ix1,Ix2,Iy1,Iy2,Iz1,Iz2;
    int     i,j,k,index;
    Brick<T>   *pBrick;
  
    /*Template Objects must overload getBox function*/
    double min[3];
    double max[3];
    getBox(obj,min,max);
  
    Ix1 = (int)( (double)Nx * (min[0] - Xmin) /( Xmax - Xmin )); 
    Ix2 = (int)( (double)Nx * (max[0] - Xmin) /( Xmax - Xmin )); 
    Iy1 = (int)( (double)Ny * (min[1] - Ymin) /( Ymax - Ymin ));  
    Iy2 = (int)( (double)Ny * (max[1] - Ymin) /( Ymax - Ymin ));  
    Iz1 = (int)( (double)Nz * (min[2] - Zmin) /( Zmax - Zmin ));  
    Iz2 = (int)( (double)Nz * (max[2] - Zmin) /( Zmax - Zmin )); 
  
  
    Ix1 = MAX(Ix1,0);
    Ix2 = MIN(Ix2,Nx-1);
    Iy1 = MAX(Iy1,0);
    Iy2 = MIN(Iy2,Ny-1);
    Iz1 = MAX(Iz1,0);
    Iz2 = MIN(Iz2,Nz-1);
 
    for(i=Ix1;i<=Ix2;i++){
      for(j=Iy1;j<=Iy2;j++){
	for(k=Iz1;k<=Iz2;k++){
	  index = i + j * Nx + k * Nx * Ny;
	  pBrick = getBrick(index);
	  pBrick->Objects.push_back(obj);
	}
      }
    }
    return true;
  }

  template <class T,class GetBox, class InteriorCheck> 
  bool mGeomSearch<T,GetBox, InteriorCheck> :: RemoveObject ( T * obj )
  {
    int     Ix1,Ix2,Iy1,Iy2,Iz1,Iz2;
    int     i,j,k,index;
    Brick<T>   *pBrick;
    
    /*Template Objects must overload getBox function*/
    double min[3];
    double max[3];
    getBox(obj,min,max);
    
    Ix1 = (int)( (double)Nx * (min[0] - Xmin) /( Xmax - Xmin )); 
    Ix2 = (int)( (double)Nx * (max[0] - Xmin) /( Xmax - Xmin )); 
    Iy1 = (int)( (double)Ny * (min[1] - Ymin) /( Ymax - Ymin ));  
    Iy2 = (int)( (double)Ny * (max[1] - Ymin) /( Ymax - Ymin ));  
    Iz1 = (int)( (double)Nz * (min[2] - Zmin) /( Zmax - Zmin ));  
    Iz2 = (int)( (double)Nz * (max[2] - Zmin) /( Zmax - Zmin )); 
  
  
    Ix1 = MAX(Ix1,0);
    Ix2 = MIN(Ix2,Nx-1);
    Iy1 = MAX(Iy1,0);
    Iy2 = MIN(Iy2,Ny-1);
    Iz1 = MAX(Iz1,0);
    Iz2 = MIN(Iz2,Nz-1);
 
    for(i=Ix1;i<=Ix2;i++){
      for(j=Iy1;j<=Iy2;j++){
	for(k=Iz1;k<=Iz2;k++){
	  index = i + j * Nx + k * Nx * Ny;
	  pBrick = getBrick(index);
	  pBrick->Objects.erase ( std::remove (pBrick->Objects.begin(),pBrick->Objects.end(),obj) , 
				  pBrick->Objects.end () );
	}
      }
    }
    return true;
  }

} // end of namespace

#undef TOL
#endif
