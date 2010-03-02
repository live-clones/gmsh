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

class Box2DData{
 	public:
		int boundingbox[4]; // x1, x2, y1, y2
		float LevelSetValue[2][2]; // LevelSetValue[x][y][z]
};

class QuadtreeLSImage;
class Box2D;

// Quadtree class to decompose a float valued 3d image

class QuadtreeLSImage
{

	private :

		// Quadtree's root
		Box2D* _root;
  	// Quadtree's image
    itk::Image< float, 2 >::Pointer _image;
		// Region size
		int _ImageSize[2];
		// Mesh list of nodes
    std::vector< std::vector <int> > _ListNodes;
		// Mesh list of elements
		std::vector< std::vector <int> > _ListElements;
		// Mesh list of levelsetvalue
    std::vector< float > _ListLSValue;
    // List of HangingNodes
    std::map< int ,std::vector<int> > _HangingNodes;
 		// Number of box leafs
    int _LeafNumber;
		// Count octree's leafs
		void SetLeafNumber();
		void FillMeshInfo(int & pas);
		void FillHangingNodes();

	public :

    QuadtreeLSImage(itk::Image< float, 2 >::Pointer image);
    //~QuadtreeLSImage();
		void Erase();
    Box2D* GetRoot(){return _root;}
		// Refine with related mesh conditions (see implementation)
    void Mesh(int  maxsize, int  minsize);
    itk::Image< float, 2 >::Pointer GetImage(){return _image;}
    int GetLeafNumber(){this->SetLeafNumber();return _LeafNumber;}
    // Refine if too much generations between adjacent leafs
		bool Smooth();
		//std::vector< std::vector <int> > *GetListElements();
		// Create GModel
		GModel* CreateGModel(bool simplex, double facx, double facy,double facz,int & sizemax,int & sizemin);
    // Create PView representation of the level set
		PView* CreateLSPView(GModel* m);
    int* GetSize(){return _ImageSize;}

    std::vector< float >* getListLSValue(){return &_ListLSValue;}
    std::map< int ,std::vector<int> >* getListHangingNodes(){return &_HangingNodes;}

};


class Box2D{
      private :

				// children pointers
      	Box2D* _children[4];
        Box2D* _parent;
        Box2DData* _data;
        QuadtreeLSImage* _quadtree;
				int _ElementNodes[4]; // utilisé seulement par balayage

			public :

        Box2D(Box2DData* data,Box2D* parent,QuadtreeLSImage* octree);
        Box2DData* GetData(){return _data;}
        // Does it have children
        bool HaveChildren();
				// Fill level set value in data with image values
        void FillLevelSetValue(itk::Image< float, 2 >::Pointer image, Box2DData *data);
	      // The smallest length of the box
        int BoxSize();
				// Is the box crossed by the iso zero levelset
				bool IsHomogeneous();
				// Recursive function to refine until condition is reached (see implementation)
        void Mesh(int & maxsize, int & minsize);
				// Divide by eight the box leaf
				void Divide();
        void PrintLevelSetValue();
        Box2D* GetParent(){return _parent;};
        Box2D* GetChild(int n){return _children[n];};
				// Recursive function to count the leafs from the root
        void CountLeafNumber(int &LeafNumber);
				// Recursive function to smoothed the octree (see QuadtreeLSImage::Smooth)
  			bool Smooth();
				// Give all the leafs containing this node
        void GetLeafsWith(std::vector<Box2D*> &Leafs, int x, int y);
				// Recursive function to create the list of the mesh nodes, elements and levelset values
				void FillMeshInfo(std::vector< std::vector<int> > &ListNodes, std::vector< std::vector<int> > &ListElements, std::vector<float> &ListLSValue,int &pas);
				// Recursive function to create the list of mesh elements in relation with the list of nodes
				void SetElementNode(int pos,int iti){_ElementNodes[pos]=iti;}
				void FillElementsNode(std::vector< std::vector<int> > &ListElements);
				void FillHangingNodes(std::vector< std::vector<int> > &ListNodes, std::vector< std::vector<int> > &ListElements,std::map< int ,std::vector<int> > &HangingNodes);
  	};

#endif
