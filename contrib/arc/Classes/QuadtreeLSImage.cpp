//
// Description: 
//
//
// Author:  <Boris Sedji>,  12/2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "GModel.h"
#include "QuadtreeLSImage.h"
#include "MElement.h"

QuadtreeLSImage::QuadtreeLSImage(itk::Image< float, 2 >::Pointer image){
  
  itk::Image< float, 2 >::RegionType region;
	// Define a region to get size of the image
  region = image->GetLargestPossibleRegion ();

	
	// Size will be a power of two larger than the image size
	
	_size[0] = 1;
	_size[1] = 1;

  while (_size[0]<region.GetSize(0)){
  	_size[0] = _size[0]*2;
	}
	while (_size[1]<region.GetSize(1)){
  	_size[1] = _size[1]*2;
	}
	
  BoxData *data = new BoxData;

	// The window of the image root
  data->boundingbox[0]=0;
  data->boundingbox[1]=_size[0];
  data->boundingbox[2]=0;
  data->boundingbox[3]=_size[1];

	// initialisation of the quadtree
  _root = new Box(data,NULL,this);
  _root->FillLevelSetValue(image,data);
  _image = image;
	_LeafNumber = 0;

}


void QuadtreeLSImage::Mesh(int maxsize,int minsize){

  // taillemax   //nombre de pixels max dans une direction

	
	if (this->_root->HaveChildren()){
		return;
	}
  if(_root->BoxSize()>maxsize || !_root->IsHomogeneous()){
  _root->Mesh( maxsize, minsize);
  };

}


Box::Box(BoxData* data, Box* parent,QuadtreeLSImage* quadtree){

	_data = data;
  _parent = parent;
  _children[0] = NULL;
  _quadtree = quadtree;

}

bool Box::HaveChildren(){

	if (this->_children[0]==NULL) return false;
	else return true;

}


void Box::FillLevelSetValue(itk::Image< float, 2 >::Pointer image, BoxData *data){

  float pixelValue;
  itk::Image< float, 2 >::IndexType pixelIndex;
  itk::Image< float, 2 >::RegionType region;
  region = image->GetLargestPossibleRegion ();

	// fill with pixel value, and if out of region size, fill with value at largest region size
	for (int i=0;i<2;i++){
  	for (int j=0;j<2;j++){
				
				if (data->boundingbox[i] < region.GetSize(0)) pixelIndex[0] = data->boundingbox[i];
        else pixelIndex[0] = region.GetSize(0)-1;   // x position

  			if (data->boundingbox[2+j] < region.GetSize(1)) pixelIndex[1] = data->boundingbox[2+j];
        else pixelIndex[1] = region.GetSize(1)-1;   // y position

				pixelValue = image->GetPixel( pixelIndex );
        data->LevelSetValue[i][j] = pixelValue;

  	}
  }

}

int Box::BoxSize(){
	
	int SizeX;
  int SizeY;
  int size;

	SizeX = this->_data->boundingbox[1] - this->_data->boundingbox[0];
	SizeY = this->_data->boundingbox[3] - this->_data->boundingbox[2];

  if (SizeX<SizeY) size = SizeX;
	else size = SizeY;

  return size;

}

bool Box::IsHomogeneous(){

  float OneValue =  this->_data->LevelSetValue[0][0];

	for (int i=0;i<2;i++){
  	for (int j=0;j<2;j++){
        OneValue = OneValue*this->_data->LevelSetValue[i][j];
       	if (OneValue<0) {
        	return false; // if sign change => not homogeneous
        };
        OneValue =  this->_data->LevelSetValue[i][j];
  	}
  }
  return true;

}


// Recursive dividing function - eight nodes

void Box::Mesh(int & maxsize, int & minsize){
		

	if(((this->BoxSize()<=maxsize) & (this->IsHomogeneous())) | (this->BoxSize()<=minsize)){  // (max size & homogenous) ou (min size) => dont divide
  	return; // dont divide
  }

	// else we divide...
  this->Divide();

  for (int n = 0;n<4;n++){
   	_children[n]->Mesh(maxsize,minsize);
  }

}

void Box::PrintLevelSetValue(){

	for (int i=0;i<2;i++){
  	for (int j=0;j<2;j++){
				std::cout<<"\n "<< this->_data->LevelSetValue[i][j];
  	}
  }

}



GModel *QuadtreeLSImage::CreateGModel(){
  
	this->FillMeshInfo();
  
  std::map<int, MVertex*> vertexMap;
  std::vector<MVertex*> vertexVector;

  std::vector<int> numElement;
	std::vector<std::vector<int> > vertexIndices;
	std::vector<int> elementType	;
	std::vector<int> physical;
	std::vector<int> elementary;
	std::vector<int> partition;

	int numVertices;
  numVertices = _ListNodes.size();
  int minVertex = numVertices+1;
  int maxVertex = -1;
  std::vector<std::vector<int> >::iterator it;
	it = _ListNodes.begin();
	int i = 1;
	while(it!=_ListNodes.end()){
    int num;        
    float xyz[3];
    xyz[0] = ((*it)[0])*1;
    xyz[1] = ((*it)[1])*1.2;
		xyz[2] = 0;
		num = i;
		MVertex* newVertex = new MVertex(xyz[0], xyz[1], xyz[2], 0, num);
		vertexMap[num] = newVertex;
		it++;
		i++;
 	}
	minVertex = 1;
  maxVertex = numVertices;
	i = 1;
	it = _ListElements.begin();
	while(it!=_ListElements.end()) {
		int num, type, phys = 0, ele = 0, part = 0, numVertices;
    num = i;
    type = 3; // MSH_QUA_4
    ele = 26;
    phys = 0;
    part = 0;
    numVertices = MElement::getInfoMSH(type);
    std::vector <int> indices;
    for(int j = 0; j < numVertices; j++){
      indices.push_back((*it)[j]);
		}
    numElement.push_back(i);
    vertexIndices.push_back(indices);
    elementType.push_back(type);
    physical.push_back(phys);
    elementary.push_back(ele);
    partition.push_back(part);		
    indices.clear();
		it++;
    i++;
  }
 
	GModel *gmod = GModel::createGModel(vertexMap,numElement,vertexIndices,elementType,physical,elementary,partition);
	
	return gmod;
       
}

PView *QuadtreeLSImage::CreateLSPView(GModel* m){

	std::map<int, std::vector<double> > data;
	std::vector<float>::iterator itf;
	itf = _ListLSValue.begin();
  int i = 1;
  
  while (itf!=_ListLSValue.end()){
  	std::vector<double> d;
    d.push_back((*itf)) ;
		data[i] = d;
		d.clear();
 		itf++;
  	i++;
	}
	std::string postTypeName = "LevelSet Value" ;
	PView *pv = new PView (postTypeName, "NodeData", m, data, 0.0);

	return pv; 

}

void QuadtreeLSImage::FillMeshInfo(){

  if (!_ListNodes.empty()){
		return;
	}

	_root->FillMeshInfo(_ListNodes,_ListElements,_ListLSValue);

}



// fonction par balayage de région


void Box::FillMeshInfo(std::vector< std::vector<int> > &ListNodes, std::vector< std::vector<int> > &ListElements, std::vector<float> &ListLSValue){

	int pas = 1;
	
  int* size = _quadtree->GetSize();

	int xpas = size[0]/size[1]*pas;  
  int ypas = size[1]/size[1]*pas;  // à modifier si sizeY n'est pas le plus petit


	std::cout<<"\nxyzpas :"<< xpas << " " << ypas ;
	
	std::vector<std::vector<int> >::iterator it;

  it = ListNodes.begin();
  int iti=0;	


	for(int y = 0;y<=size[1];y+=ypas)
	for(int x = 0;x<=size[0]; x+=xpas)
	{    
			std::vector<Box*> Leafs;
      Leafs.clear();
			GetLeafsWith(Leafs, x,  y);
			std::map<int,std::vector< int > > ElementsNodes;			
			std::vector<int> NodesIn;

			bool added = false;
			for(unsigned int l=0;l<Leafs.size();l++){           
				if (!added){
					std::vector<int> XYZ;
          XYZ.push_back(x);
          XYZ.push_back(y);
          XYZ.push_back(0);
					for (int i = 0 ; i<2;i++ )
       			for (int j = 0 ; j<2;j++ )
       				
								if (x == Leafs[l]->GetData()->boundingbox[i] & y == Leafs[l]->GetData()->boundingbox[j+2] ){
									ListLSValue.push_back(Leafs[l]->GetData()->LevelSetValue[i][j]);
									ListNodes.push_back(XYZ);
									added = true;
									iti++;
								}
							
				}else break;			
			}
			if (added){
				for(unsigned int l=0;l<Leafs.size();l++){           					
					for (int i = 0 ; i<2;i++ )
       				for (int j = 0 ; j<2;j++ ){
                int pos ;
								pos = i*2+j*1;
								if (x == Leafs[l]->GetData()->boundingbox[i] & y == Leafs[l]->GetData()->boundingbox[j+2]){
									Leafs[l]->SetElementNode(pos,iti);
								}
							}		
				}
 			}
		}
	std::cout<<"\nNumber Nodes : "<< ListNodes.size();
	_quadtree->GetRoot()->FillElementsNode(ListElements);
        
}

void Box::FillElementsNode(std::vector< std::vector<int> > &ListElements){

	// if it s a leaf then fill list node if node dont exist in list
	if (!this->HaveChildren()) {
    std::vector<int> ElementNodes;
		int temp;
		temp = _ElementNodes[3];
    _ElementNodes[3] = _ElementNodes[2];
		_ElementNodes[2] = temp;
		for (int i = 0 ; i < 4 ; i++) ElementNodes.push_back(_ElementNodes[i]);
		ListElements.push_back(ElementNodes);
		std::cout<<"\n Nodes :";
    for (int i = 0 ; i < 4 ; i++)
    std::cout<<" " << ElementNodes[i]; 
		return;
	}

  for (int n = 0 ; n < 4 ; n++){
 	 this->_children[n]->FillElementsNode(ListElements);	
  }

}




/*
void Box::FillMeshInfo(std::vector< std::vector<int> > &ListNodes, std::vector< std::vector<int> > &ListElements, std::vector<float> &ListLSValue){

	// if it s a leaf then fill list node if node dont exist in list
	if (!this->HaveChildren()) {
		std::vector<int> NodesIn;
		NodesIn.clear();
		int temp;
    for (int i = 0 ; i<2;i++ ){
      for (int k = 0 ; k<2;k++ )
      	for (int j = 0 ; j<2;j++ ){
          std::vector<int> XYZ;
          float LSValue;
          XYZ.push_back(this->GetData()->boundingbox[i]);
          XYZ.push_back(this->GetData()->boundingbox[2+j]);
 					XYZ.push_back(this->GetData()->boundingbox[4+k]);
					LSValue = this->GetData()->LevelSetValue[i][j][k];
					std::vector<std::vector<int> >::iterator it;
   	 			it = ListNodes.begin();
          bool add = true;
					int l;
					l = 1;
    			while (it!=ListNodes.end()){ // attention segmentation & pas opti
						if (((*it)[0] == XYZ[0]) & ((*it)[1] == XYZ[1]) & ((*it)[2] == XYZ[2])){
							add = false;
							NodesIn.push_back(l);
 							break;
						}
          	it++;
            l++;
    			}
					if (add) {
						ListNodes.push_back(XYZ);
						ListLSValue.push_back(LSValue);
						NodesIn.push_back(l);
					}
					XYZ.clear();
    		}
  		}
		temp = NodesIn[3];
    NodesIn[3] = NodesIn[2];
		NodesIn[2] = temp;
		temp = NodesIn[7];
    NodesIn[7] = NodesIn[6];
		NodesIn[6] = temp;
		ListElements.push_back(NodesIn);
		return;
	}

  for (int n = 0 ; n < 8 ; n++){
 	 this->_children[n]->FillMeshInfo(ListNodes,ListElements,ListLSValue);	
  }

}*/

/*
std::vector< std::vector <int> > *QuadtreeLSImage::GetListElements(){

  if (!_ListElements.empty()){
		return &_ListElements;
	}

	_root->GetLeafElements(_ListElements);

  return &_ListElements;

}*/


/*
void Box::GetLeafElements(std::vector< std::vector<int> > &ListElements){

// 	if (!this->HaveChildren()) {
//     std::vector<std::vector<int> >::iterator it;
//     std::vector<std::vector<int> > *ListNodes;
//    	ListNodes = this->_quadtree->GetListNodes(); 
// 		it = ListNodes->begin();
// 		std::vector<int> NodesIn;
//     int l = 1;
//     while (it!=ListNodes->end())	{
//     	for (int i = 0 ; i<2;i++ ){
//       	for (int j = 0 ; j<2;j++ ){
//       		for (int k = 0 ; k<2;k++ ){
// 						if ((_data->boundingbox[i] == (*it)[0]) & (_data->boundingbox[2+j] == (*it)[1]) & (_data->boundingbox[4+k] == (*it)[2]))
// 							NodesIn.push_back(l);
//     			}
//   			}
// 			}
//       it++;
//       l++;
// 		}
// 		ListElements.push_back(NodesIn);
// 		return;
// 	}
// 
//   for (int n = 0 ; n < 8 ; n++){
//  	 this->_children[n]->GetLeafElements(ListElements);	
//   }

}
*/




void QuadtreeLSImage::SetLeafNumber(){
    _LeafNumber = 0;
		_root->CountLeafNumber(_LeafNumber);  
}

void Box::CountLeafNumber(int &LeafNumber){

	if (this->GetChild(0)==NULL) {
  	LeafNumber = LeafNumber + 1;
    return;
	}

  for (int n = 0 ; n < 4 ; n++){
 	 this->_children[n]->CountLeafNumber(LeafNumber);	
  }

}

// Divide function

void Box::Divide(){

// box divide in 4 boxes with limits xl = (xmin + xmax)/2 ; yl = (ymin + ymax)/2 

		int n;
	
		// Box 1 :  < xl ; < yl 

		n = 0;   
		BoxData* data1 = new BoxData;    

  	data1->boundingbox[0]=this->_data->boundingbox[0];
  	data1->boundingbox[1]=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2;
  	data1->boundingbox[2]=this->_data->boundingbox[2];
  	data1->boundingbox[3]=(this->_data->boundingbox[3]+this->_data->boundingbox[2])/2;
  	

  	this->_children[n] = new Box(data1,this,this->_quadtree);
  	this->_children[n]->FillLevelSetValue(_children[n]->_quadtree->GetImage(),_children[n]->GetData());

	 	// Box 2 :  > xl ; < yl 
 		
		n = 1;   
		BoxData* data2 = new BoxData;  

  	data2->boundingbox[0]=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2;
  	data2->boundingbox[1]=this->_data->boundingbox[1];
  	data2->boundingbox[2]=this->_data->boundingbox[2];
  	data2->boundingbox[3]=(this->_data->boundingbox[3]+this->_data->boundingbox[2])/2;
  	

  	this->_children[n] = new Box(data2,this,this->_quadtree);
  	this->_children[n]->FillLevelSetValue(_children[n]->_quadtree->GetImage(),_children[n]->GetData());

		// Box 3 :  < xl ; > yl 
 		
		n = 2;
		BoxData* data3 = new BoxData;    
 
  	data3->boundingbox[0]=this->_data->boundingbox[0];
  	data3->boundingbox[1]=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2;
  	data3->boundingbox[2]=(this->_data->boundingbox[3]+this->_data->boundingbox[2])/2;
  	data3->boundingbox[3]=this->_data->boundingbox[3];
  	

  	this->_children[n] = new Box(data3,this,this->_quadtree);
  	this->_children[n]->FillLevelSetValue(_children[n]->_quadtree->GetImage(),_children[n]->GetData());

		// Box 4 :  > xl ; > yl  
 		
		n = 3;   
		BoxData* data4 = new BoxData; 
 
  	data4->boundingbox[0]=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2;
  	data4->boundingbox[1]=this->_data->boundingbox[1];
  	data4->boundingbox[2]=(this->_data->boundingbox[3]+this->_data->boundingbox[2])/2;
  	data4->boundingbox[3]=this->_data->boundingbox[3];
  	

  	this->_children[n] = new Box(data4,this,this->_quadtree);
  	this->_children[n]->FillLevelSetValue(_children[n]->_quadtree->GetImage(),_children[n]->GetData());

  
}

bool QuadtreeLSImage::Smooth(){

	return _root->Smooth();

}


bool Box::Smooth(){

	
	if (!this->HaveChildren()) {
    bool smoothed = true;
    BoxData*data = this->GetData();
 		std::vector<Box*> Leafs;
		for (int i = 0 ; i<2;i++ ){
      for (int j = 0 ; j<2;j++ ){
					Leafs.clear();
					_quadtree->GetRoot()->GetLeafsWith(Leafs,data->boundingbox[i],data->boundingbox[2+j]);
					if (Leafs.size()!=4){
 						int min = Leafs[0]->BoxSize();
						for(unsigned int l=0;l<Leafs.size();l++){           
							if(min>Leafs[l]->BoxSize()) min = Leafs[l]->BoxSize();
						}				
						for(unsigned int l=0;l<Leafs.size();l++){           
							if(min<=(Leafs[l]->BoxSize())/4){ 
								Leafs[l]->Divide();
						  	smoothed = false;
							}
						}
					}
  		}
	  }
		return smoothed;
	}

	bool smoothed = true;
  for (int n = 0 ; n < 4 ; n++){
 	  if(!this->_children[n]->Smooth()) smoothed = false;	
  }
	return smoothed;
}

// Quadtree research, box specialisation from root

void Box::GetLeafsWith(std::vector<Box*> &Leafs, int x, int y){

		if (!this->HaveChildren()){
        Box* parent = this;
        BoxData* data;
        while(parent->GetParent()!=NULL){
          data = parent->GetParent()->GetData();
 					parent=parent->GetParent();
        }
 			Leafs.push_back(this);											
 			return;	
		}
 		

		if ((x<=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2) & (y <= (this->_data->boundingbox[3]+this->_data->boundingbox[2])/2) ){
  		_children[0]->GetLeafsWith(Leafs,x,y);
    }
		
		if ((x>=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2) & (y <= (this->_data->boundingbox[3]+this->_data->boundingbox[2])/2) ){
  		_children[1]->GetLeafsWith(Leafs,x,y);
    }

		if ((x<=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2) & (y >= (this->_data->boundingbox[3]+this->_data->boundingbox[2])/2) ){
  		_children[2]->GetLeafsWith(Leafs,x,y);
    }
		
		if ((x>=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2) & (y >= (this->_data->boundingbox[3]+this->_data->boundingbox[2])/2)){
  		_children[3]->GetLeafsWith(Leafs,x,y);
    }

 		
}
