//
// Description: 
//
//
// Author:  <Boris Sedji>,  12/2009
//
// Copyright: See COPYING file that comes with this distribution
//
//


#ifndef _QUADTREELSIMAGE_H_
#define _QUADTREELSIMAGE_H_

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "PView.h"
#include "PViewData.h"


//data defining a box

class BoxData{
 	public:
		int boundingbox[4]; // x1, x2, y1, y2
		float LevelSetValue[2][2]; // LevelSetValue[x][y][z]
};

class QuadtreeLSImage;
class Box;

// Quadtree class to decompose a float valued 3d image

class QuadtreeLSImage
{
 	 
	private :

		// Quadtree's root
		Box* _root;
  	// Quadtree's image
    itk::Image< float, 2 >::Pointer _image;
		// Window size
		int _size[2];
		// Mesh list of nodes
    std::vector< std::vector <int> > _ListNodes;
		// Mesh list of elements
		std::vector< std::vector <int> > _ListElements;
		// Mesh list of levelsetvalue
    std::vector< float > _ListLSValue;
 		// Number of box leafs
    int _LeafNumber;
		// Count octree's leafs
		void SetLeafNumber();
		void FillMeshInfo();

	public :

    QuadtreeLSImage(itk::Image< float, 2 >::Pointer image);
    //~QuadtreeLSImage();
		void Erase();
    Box* GetRoot(){return _root;}
		// Refine with related mesh conditions (see implementation)
    void Mesh(int  maxsize, int  minsize);
    itk::Image< float, 2 >::Pointer GetImage(){return _image;}
    int GetLeafNumber(){this->SetLeafNumber();return _LeafNumber;}
    // Refine if too much generations between adjacent leafs 
		bool Smooth();
		//std::vector< std::vector <int> > *GetListElements();
		// Create GModel
		GModel* CreateGModel();
    // Create PView representation of the level set
		PView* CreateLSPView(GModel* m);
    int* GetSize(){return _size;}

};


class Box{
      private :

				// children pointers
      	Box* _children[4];
        Box* _parent;
        BoxData* _data;
        QuadtreeLSImage* _quadtree;
				int _ElementNodes[4]; // utilisé seulement par balayage

			public :

        Box(BoxData* data,Box* parent,QuadtreeLSImage* octree);
        BoxData* GetData(){return _data;}
        // Does it have children
        bool HaveChildren();
				// Fill level set value in data with image values        
        void FillLevelSetValue(itk::Image< float, 2 >::Pointer image, BoxData *data);
	      // The smallest length of the box
        int BoxSize();
				// Is the box crossed by the iso zero levelset
				bool IsHomogeneous();
				// Recursive function to refine until condition is reached (see implementation)
        void Mesh(int & maxsize, int & minsize);
				// Divide by eight the box leaf
				void Divide();
        void PrintLevelSetValue();
        Box* GetParent(){return _parent;};
        Box* GetChild(int n){return _children[n];};
				// Recursive function to count the leafs from the root
        void CountLeafNumber(int &LeafNumber);
				// Recursive function to smoothed the octree (see QuadtreeLSImage::Smooth)
  			bool Smooth();
				// Give all the leafs containing this node
        void GetLeafsWith(std::vector<Box*> &Leafs, int x, int y);
				// Recursive function to create the list of the mesh nodes, elements and levelset values
				void FillMeshInfo(std::vector<std::vector<int> > &ListNodes, std::vector< std::vector<int> > &ListElements, std::vector< float > &ListLSValue);
				// Recursive function to create the list of mesh elements in relation with the list of nodes
				void SetElementNode(int pos,int iti){_ElementNodes[pos]=iti;}
				void FillElementsNode(std::vector< std::vector<int> > &ListElements);
  	};

#endif