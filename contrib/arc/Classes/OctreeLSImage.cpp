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
#include "OctreeLSImage.h"
#include "MElement.h"

OctreeLSImage::OctreeLSImage(itk::Image< float, 3 >::Pointer image){

    itk::Image< float, 3 >::RegionType region;
    // Define a region to get size of the image
    region = image->GetLargestPossibleRegion ();
    // Size will be a power of two larger than the image size
    int size[3];
    size[0] = 1;
    size[1] = 1;
    size[2] = 1;

    _ImageSize[0] = region.GetSize(0);
    _ImageSize[1] = region.GetSize(1);
    _ImageSize[2] = region.GetSize(2);

    while (size[0]<_ImageSize[0]){
        size[0] = size[0]*2;
    }
    while (size[1]<_ImageSize[1]){
        size[1] = size[1]*2;
    }
    while (size[2]<_ImageSize[2]){
        size[2] = size[2]*2;
    }

    BoxData *data = new BoxData;

    if (size[0]>= size[1] & size[0]>=size[2] )
    {
        // The window of the image root
        data->boundingbox[0]=0;
        data->boundingbox[1]=size[0];
        data->boundingbox[2]=0;
        data->boundingbox[3]=size[0];
        data->boundingbox[4]=0;
        data->boundingbox[5]=size[0];
    }
    if (size[1]>= size[0] & size[1]>=size[2] )
    {
        // The window of the image root
        data->boundingbox[0]=0;
        data->boundingbox[1]=size[1];
        data->boundingbox[2]=0;
        data->boundingbox[3]=size[1];
        data->boundingbox[4]=0;
        data->boundingbox[5]=size[1];
    }

    if (size[2]>= size[1] & size[2]>=size[0] )
    {
        // The window of the image root
        data->boundingbox[0]=0;
        data->boundingbox[1]=size[2];
        data->boundingbox[2]=0;
        data->boundingbox[3]=size[2];
        data->boundingbox[4]=0;
        data->boundingbox[5]=size[2];
    }

    // initialisation of the octree
    _root = new Box(data,NULL,this);
    _root->FillLevelSetValue(image,data);
    _image = image;
    _LeafNumber = 0;

    std::cout<<"size root :"<<_root->BoxSize()<<"\n";

}


void OctreeLSImage::Mesh(int maxsize,int minsize){


    if (this->_root->HaveChildren()){
        return;
    }
    if (_root->BoxSize()>maxsize || !_root->IsHomogeneous()){
        _root->Mesh( maxsize, minsize);
    };
//
//  if(_root->BoxSize()>=maxsize){
//  _root->Mesh( maxsize, minsize);
//  };

}


Box::Box(BoxData* data, Box* parent,OctreeLSImage* octree){

    _data = data;
    _parent = parent;
    _children[0] = NULL;
    _octree = octree;

}

bool Box::HaveChildren(){

    if (this->_children[0]==NULL) return false;
    else return true;

}


void Box::FillLevelSetValue(itk::Image< float, 3 >::Pointer image, BoxData *data){

    float pixelValue;
    itk::Image< float, 3 >::IndexType pixelIndex;
    itk::Image< float, 3 >::RegionType region;
    region = image->GetLargestPossibleRegion ();

    // fill with pixel value, and if out of region size, fill with value at largest region size
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            for (int k=0;k<2;k++){

                if (data->boundingbox[i] < region.GetSize(0)) pixelIndex[0] = data->boundingbox[i];
                else pixelIndex[0] = region.GetSize(0)-1;   // x position

                if (data->boundingbox[2+j] < region.GetSize(1)) pixelIndex[1] = data->boundingbox[2+j];
                else pixelIndex[1] = region.GetSize(1)-1;   // y position

                if (data->boundingbox[4+k] < region.GetSize(2)) pixelIndex[2] = data->boundingbox[4+k];
                else pixelIndex[2] = region.GetSize(2)-1; // z position

                pixelValue = image->GetPixel( pixelIndex );
                data->LevelSetValue[i][j][k] = pixelValue;

            }
        }
    }

}

int Box::BoxSize(){

    int SizeX;
    int SizeY;
    int SizeZ;
    int size;

    SizeX = this->_data->boundingbox[1] - this->_data->boundingbox[0];
    SizeY = this->_data->boundingbox[3] - this->_data->boundingbox[2];
    SizeZ = this->_data->boundingbox[5] - this->_data->boundingbox[4];

    if (SizeX<SizeY) size = SizeX;
    else size = SizeY;

    if (SizeZ<size) size = SizeZ;

    return size;

}

bool Box::IsHomogeneous(){

    float OneValue =  this->_data->LevelSetValue[0][0][0];

    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            for (int k=0;k<2;k++){
                OneValue = OneValue*this->_data->LevelSetValue[i][j][k];
                if (OneValue<0) {
                    return false; // if sign change => not homogeneous
                };
                OneValue =  this->_data->LevelSetValue[i][j][k];
            }
        }
    }
    return true;

}


// Recursive dividing function - eight nodes

void Box::Mesh(int & maxsize, int & minsize){

    if (((this->BoxSize()<=maxsize) & (this->IsHomogeneous())) | (this->BoxSize()<=minsize)){ // (max size & homogenous) ou (min size) => dont divide
        return; // dont divide
    }

//  std::cout<<"databoundingbox : "<< this->_data->boundingbox[1] <<"\n";
//  if(((this->BoxSize()<=maxsize) & !(this->_data->boundingbox[0] == 0 & this->_data->boundingbox[3] == 1024 & this->_data->boundingbox[4] == 0)) | (this->BoxSize()<=minsize)){  // (max size & homogenous) ou (min size) => dont divide
//  	return; // dont divide
//  }

    // else we divide...
    this->Divide();

    for (int n = 0;n<8;n++){
        _children[n]->Mesh(maxsize,minsize);
    }

}

void Box::PrintLevelSetValue()
{

    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            for (int k=0;k<2;k++){
                std::cout<<"\n "<< this->_data->LevelSetValue[i][j][k];
            }
        }
    }

}



GModel *OctreeLSImage::CreateGModel(bool simplex, double facx, double facy, double facz,int & sizemax,int & sizemin){

    this->FillMeshInfo(sizemin);
    this->FillHangingNodes();

    std::cout<<"HangingNodes size :"<< _HangingNodes.size()<<"\n";

    itk::Image< float, 3 >::RegionType region;
    // Define a region to get size of the image
    region = _image->GetLargestPossibleRegion ();


    std::map<int, MVertex*> vertexMap;
    std::map<int,int> vertexNum;
    std::vector<MVertex*> vertexVector;

    std::vector<int> numElement;
    std::vector<std::vector<int> > vertexIndices;
    std::vector<int> elementType	;
    std::vector<int> physical;
    std::vector<int> elementary;
    std::vector<int> partition;
    std::vector<double> d;
    std::map<int, std::vector<double> > data;
    data.clear();

    double eps = 1e-6;

    int numVertices;

    std::vector<std::vector<int> >::iterator ite;

    int i = 1;
    int k = 1;

    int a;

    int xlimit = _ImageSize[0] - _ImageSize[0]%sizemax; // lost of image pixels...
    int ylimit = _ImageSize[1] - _ImageSize[1]%sizemax;
    int zlimit = _ImageSize[2] - _ImageSize[2]%sizemax;

    std::cout<<"\nxlimit :"<< xlimit<<"\n";
    std::cout<<"ylimit :"<< ylimit<<"\n";
    std::cout<<"zlimit :"<< zlimit<<"\n";
    std::cout<<"Listnodes size :"<<_ListNodes.size()<<"\n";

    i = 1;
    ite = _ListElements.begin();
    if (!simplex)  // first try, to be improved
    {
        while (ite!=_ListElements.end()) {
            int num, type, phys = 0, ele = 0, part = 0, numVertices;
            num = i;
            type = 5;
            ele = 7;
            phys = 7;
            part = 0;
            numVertices = MElement::getInfoMSH(type);
            std::vector <int> indices;
            for (int j = 0; j < numVertices; j++){
                indices.push_back((*ite)[j]);
            }
            numElement.push_back(i);
            vertexIndices.push_back(indices);
            elementType.push_back(type);
            physical.push_back(phys);
            elementary.push_back(ele);
            partition.push_back(part);
            indices.clear();
            ite++;
            i++;
        }
    }
    else  // if simplex
    {
        while (ite!=_ListElements.end()) {

            bool inImage;
            inImage = true;
            for (int j = 0;j<8;j++){
                if ( _ListNodes[(*ite)[j]-1][0] > xlimit | _ListNodes[(*ite)[j]-1][1] > ylimit | _ListNodes[(*ite)[j]-1][2] > zlimit ){
                    inImage = false;
                }
            }
            if (inImage)
            {
                k++;
                for (int j = 0;j<8;j++)
                {
                    if (vertexMap.find((*ite)[j]) == vertexMap.end()) // if not in
                    {
                        float xyz[3];
                        d.clear();
                        xyz[0] = (_ListNodes[(*ite)[j]-1][0])*facx;
                        xyz[1] = (_ListNodes[(*ite)[j]-1][1])*facy;
                        xyz[2] = (_ListNodes[(*ite)[j]-1][2])*facz;
                        MVertex* newVertex = new MVertex(xyz[0], xyz[1], xyz[2], 0, (*ite)[j]);
                        vertexMap[(*ite)[j]] = newVertex;
                        d.push_back(_ListLSValue[(*ite)[j]-1]);
                        data[(*ite)[j]]=d;
                        d.clear();
                    }
                }

                int num, type, phys = 0, ele = 0, part = 0, numVertices;
                num = i;
                type = 4;
                ele = 7;
                phys = 7;
                part = 0;
                numVertices = 4;  //
                std::vector <int> indices;
                std::vector <int> front_1_indices;
                std::vector <int> front_2_indices;
                std::vector <int> front_3_indices;
                std::vector <int> front_4_indices;
                std::vector <int> front_5_indices;
                std::vector <int> front_6_indices;

                // --- Domain element tetraedre 1 ---
                indices.clear();
                indices.push_back((*ite)[0]);
                indices.push_back((*ite)[1]);
                indices.push_back((*ite)[3]);
                indices.push_back((*ite)[7]);
                type = 4;
                ele = 7;
                phys = 7;
                part = 0;
                numElement.push_back(i);
                vertexIndices.push_back(indices);
                elementType.push_back(type);
                physical.push_back(phys);
                elementary.push_back(ele);
                partition.push_back(part);
                i++;


                // --- frontier element---
                front_1_indices.clear();
                front_2_indices.clear();
                front_3_indices.clear();
                front_4_indices.clear();
                front_5_indices.clear();
                front_6_indices.clear();
                for (int j =0;j<4;j++)
                {
                    if (vertexMap[indices[j]]->x() < eps*facx)
                    {
                        front_1_indices.push_back(indices[j]);
                    }
                    if (vertexMap[indices[j]]->y() < eps*facy)
                    {
                        front_2_indices.push_back(indices[j]);
                    }
                }
                if (front_2_indices.size() == 3)
                {
                    type = 2; // MSH_TRI
                    ele = 2;
                    phys = 2;
                    part = 0;
                    numVertices = 3;
                    numElement.push_back(i);
                    vertexIndices.push_back(front_2_indices);
                    elementType.push_back(type);
                    physical.push_back(phys);
                    elementary.push_back(ele);
                    partition.push_back(part);
                    i++;
                }
                if (front_1_indices.size() == 3)
                {
                    type = 2; // MSH_TRI
                    ele = 1;
                    phys = 1;
                    part = 0;
                    numVertices = 3;
                    numElement.push_back(i);
                    vertexIndices.push_back(front_1_indices);
                    elementType.push_back(type);
                    physical.push_back(phys);
                    elementary.push_back(ele);
                    partition.push_back(part);
                    i++;
                }

                // --- Domain element tetraedre 2 ---
                indices.clear();
                indices.push_back((*ite)[1]);
                indices.push_back((*ite)[2]);
                indices.push_back((*ite)[3]);
                indices.push_back((*ite)[7]);
                type = 4;
                ele = 7;
                phys = 7;
                part = 0;
                numElement.push_back(i);
                vertexIndices.push_back(indices);
                elementType.push_back(type);
                physical.push_back(phys);
                elementary.push_back(ele);
                partition.push_back(part);
                i++;

                // --- frontier element tetraedre 2---
                front_1_indices.clear();
                front_2_indices.clear();
                front_3_indices.clear();
                front_4_indices.clear();
                front_5_indices.clear();
                front_6_indices.clear();
                for (int j =0;j<4;j++)
                {
                    if (vertexMap[indices[j]]->x() < eps*facx)
                    {
                        front_1_indices.push_back(indices[j]);
                    }
                    if (vertexMap[indices[j]]->z() > (zlimit-eps)*facz)
                    {
                        front_6_indices.push_back(indices[j]);
                    }
                }

                if (front_1_indices.size() == 3)
                {
                    type = 2; // MSH_TRI
                    ele = 1;
                    phys = 1;
                    part = 0;
                    numVertices = 3;
                    numElement.push_back(i);
                    vertexIndices.push_back(front_1_indices);
                    elementType.push_back(type);
                    physical.push_back(phys);
                    elementary.push_back(ele);
                    partition.push_back(part);
                    i++;
                }
                if (front_6_indices.size() == 3)
                {
                    type = 2; // MSH_TRI
                    ele = 6;
                    phys = 6;
                    part = 0;
                    numVertices = 3;
                    numElement.push_back(i);
                    vertexIndices.push_back(front_6_indices);
                    elementType.push_back(type);
                    physical.push_back(phys);
                    elementary.push_back(ele);
                    partition.push_back(part);
                    i++;
                }


                // --- Domain element tetraedre 3 ---
                indices.clear();
                indices.push_back((*ite)[1]);
                indices.push_back((*ite)[6]);
                indices.push_back((*ite)[2]);
                indices.push_back((*ite)[7]);
                type = 4;
                ele = 7;
                phys = 7;
                part = 0;
                numElement.push_back(i);
                vertexIndices.push_back(indices);
                elementType.push_back(type);
                physical.push_back(phys);
                elementary.push_back(ele);
                partition.push_back(part);
                i++;


                // --- frontier element tetraedre 3---
                front_1_indices.clear();
                front_2_indices.clear();
                front_3_indices.clear();
                front_4_indices.clear();
                front_5_indices.clear();
                front_6_indices.clear();
                for (int j =0;j<4;j++)
                {
                    if (vertexMap[indices[j]]->y() > (ylimit-eps)*facy)
                    {
                        front_5_indices.push_back(indices[j]);
                    }
                    if (vertexMap[indices[j]]->z() > (zlimit-eps)*facz)
                    {
                        front_6_indices.push_back(indices[j]);
                    }
                }

                if (front_5_indices.size() == 3)
                {
                    type = 2; // MSH_TRI
                    ele = 5;
                    phys = 5;
                    part = 0;
                    numVertices = 3;
                    numElement.push_back(i);
                    vertexIndices.push_back(front_5_indices);
                    elementType.push_back(type);
                    physical.push_back(phys);
                    elementary.push_back(ele);
                    partition.push_back(part);
                    i++;
                }

                if (front_6_indices.size() == 3)
                {
                    type = 2; // MSH_TRI
                    ele = 6;
                    phys = 6;
                    part = 0;
                    numVertices = 3;
                    numElement.push_back(i);
                    vertexIndices.push_back(front_6_indices);
                    elementType.push_back(type);
                    physical.push_back(phys);
                    elementary.push_back(ele);
                    partition.push_back(part);
                    i++;
                }


                // --- Domain element tetraedre 4 ---
                indices.clear();
                indices.push_back((*ite)[1]);
                indices.push_back((*ite)[5]);
                indices.push_back((*ite)[6]);
                indices.push_back((*ite)[7]);
                type = 4;
                type = 4;
                ele = 7;
                phys = 7;
                part = 0;
                numElement.push_back(i);
                vertexIndices.push_back(indices);
                elementType.push_back(type);
                physical.push_back(phys);
                elementary.push_back(ele);
                partition.push_back(part);
                i++;

                // --- frontier element tetraedre 4---
                front_1_indices.clear();
                front_2_indices.clear();
                front_3_indices.clear();
                front_4_indices.clear();
                front_5_indices.clear();
                front_6_indices.clear();
                for (int j =0;j<4;j++)
                {
                    if (vertexMap[indices[j]]->x() > (xlimit-eps)*facx)
                    {
                        front_4_indices.push_back(indices[j]);
                    }
                    if (vertexMap[indices[j]]->y() > (ylimit-eps)*facy)
                    {
                        front_5_indices.push_back(indices[j]);
                    }
                }
                if (front_4_indices.size() == 3)
                {
                    type = 2; // MSH_TRI
                    ele = 4;
                    phys = 4;
                    part = 0;
                    numVertices = 3;
                    numElement.push_back(i);
                    vertexIndices.push_back(front_4_indices);
                    elementType.push_back(type);
                    physical.push_back(phys);
                    elementary.push_back(ele);
                    partition.push_back(part);
                    i++;
                }
                if (front_5_indices.size() == 3)
                {
                    type = 2; // MSH_TRI
                    ele = 5;
                    phys = 5;
                    part = 0;
                    numVertices = 3;
                    numElement.push_back(i);
                    vertexIndices.push_back(front_5_indices);
                    elementType.push_back(type);
                    physical.push_back(phys);
                    elementary.push_back(ele);
                    partition.push_back(part);
                    i++;
                }

                // --- Domain element tetraedre 5 ---
                indices.clear();
                indices.push_back((*ite)[1]);
                indices.push_back((*ite)[5]);
                indices.push_back((*ite)[7]);
                indices.push_back((*ite)[4]);
                type = 4;
                ele = 7;
                phys = 7;
                part = 0;
                numElement.push_back(i);
                vertexIndices.push_back(indices);
                elementType.push_back(type);
                physical.push_back(phys);
                elementary.push_back(ele);
                partition.push_back(part);
                i++;

                // --- frontier element tetraedre 5---
                front_1_indices.clear();
                front_2_indices.clear();
                front_3_indices.clear();
                front_4_indices.clear();
                front_5_indices.clear();
                front_6_indices.clear();
                for (int j =0;j<4;j++)
                {
                    if (vertexMap[indices[j]]->z() < eps*facz)
                    {
                        front_3_indices.push_back(indices[j]);
                    }
                    if (vertexMap[indices[j]]->x() > (xlimit-eps)*facx)
                    {
                        front_4_indices.push_back(indices[j]);
                    }
                }

                if (front_3_indices.size() == 3)
                {
                    type = 2; // MSH_TRI
                    ele = 3;
                    phys = 3;
                    part = 0;
                    numVertices = 3;
                    numElement.push_back(i);
                    vertexIndices.push_back(front_3_indices);
                    elementType.push_back(type);
                    physical.push_back(phys);
                    elementary.push_back(ele);
                    partition.push_back(part);
                    i++;
                }

                if (front_4_indices.size() == 3)
                {
                    type = 2; // MSH_TRI
                    ele = 4;
                    phys = 4;
                    part = 0;
                    numVertices = 3;
                    numElement.push_back(i);
                    vertexIndices.push_back(front_4_indices);
                    elementType.push_back(type);
                    physical.push_back(phys);
                    elementary.push_back(ele);
                    partition.push_back(part);
                    i++;
                }

                // --- Domain element tetraedre 6 ---
                indices.clear();
                indices.push_back((*ite)[1]);
                indices.push_back((*ite)[4]);
                indices.push_back((*ite)[7]);
                indices.push_back((*ite)[0]);
                type = 4;
                type = 4;
                ele = 7;
                phys = 7;
                part = 0;
                numElement.push_back(i);
                vertexIndices.push_back(indices);
                elementType.push_back(type);
                physical.push_back(phys);
                elementary.push_back(ele);
                partition.push_back(part);
                i++;


                // --- frontier element tetraedre 6---
                front_1_indices.clear();
                front_2_indices.clear();
                front_3_indices.clear();
                front_4_indices.clear();
                front_5_indices.clear();
                front_6_indices.clear();
                for (int j =0;j<4;j++)
                {
                    if (vertexMap[indices[j]]->y() < eps*facy)
                    {
                        front_2_indices.push_back(indices[j]);
                    }
                    if (vertexMap[indices[j]]->z() < eps*facz)
                    {
                        front_3_indices.push_back(indices[j]);
                    }
                }
                if (front_2_indices.size() == 3)
                {
                    type = 2; // MSH_TRI
                    ele = 2;
                    phys = 2;
                    part = 0;
                    numVertices = 3;
                    numElement.push_back(i);
                    vertexIndices.push_back(front_2_indices);
                    elementType.push_back(type);
                    physical.push_back(phys);
                    elementary.push_back(ele);
                    partition.push_back(part);
                    i++;
                }

                if (front_3_indices.size() == 3)
                {
                    type = 2; // MSH_TRI
                    ele = 3;
                    phys = 3;
                    part = 0;
                    numVertices = 3;
                    numElement.push_back(i);
                    vertexIndices.push_back(front_3_indices);
                    elementType.push_back(type);
                    physical.push_back(phys);
                    elementary.push_back(ele);
                    partition.push_back(part);
                    i++;
                }

            }
            ite++;  // next octree leaf
        }
    }

    std::cout<<"numElement size :"<<numElement.size()<<"\n";
    std::cout<<"vertexIndices size :"<<vertexIndices.size()<<"\n";

    std::cout<<"data size :"<<data.size()<<"\n";
    std::cout<<"vertexMap size :"<<vertexMap.size()<<"\n";
    GModel *gmod = GModel::createGModel(vertexMap,numElement,vertexIndices,elementType,physical,elementary,partition);
    // Write a .msh file with the level set values as postview data
    std::string postTypeName = "LevelSet Value" ;
    PView *pv = new PView (postTypeName, "NodeData", gmod, data);
    //PView *pv = octree.CreateLSPView(m);
    bool useadapt = true;
    pv->getData(useadapt)->writeMSH("LSPView.msh", false);

    std::cout<<"getNumScalars :"<< pv->getData(useadapt)->getNumScalars()<<"\n";

//
// 	std::string LevelSetFileName = "LevelSetValue.msh" ;
// 	FILE *f = fopen(LevelSetFileName.c_str(), "w");
//  char name[256] = "LSValues";
//  int num;
//  float val;
//  int numnodes;
//  fprintf(f, "%s\n", name);
//  fprintf(f, "%d\n", data.size());
//  i = 1;
//  while(data.find(i)!=data.end()){
//    fprintf(f,"%d %f\n",i,data[i][0]);
//    i++;
//  }
//  fclose(f);

    return gmod;

}

PView *OctreeLSImage::CreateLSPView(GModel* m){

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


void OctreeLSImage::FillHangingNodes(){

    _root->FillHangingNodes(_ListNodes,_ListElements,_HangingNodes);

}


void Box::FillHangingNodes(std::vector< std::vector<int> > &ListNodes, std::vector< std::vector<int> > &ListElements,std::map< int ,std::vector<int> > &HangingNodes){

    std::vector<std::vector<int> >::iterator it;

    it = ListNodes.begin();
    int k=0;
    while (it!=ListNodes.end())
    {
        std::vector<Box*> Leafs;
        std::vector<int> MasterNodes;
        Leafs.clear();
        MasterNodes.clear();
        GetLeafsWith(Leafs, (*it)[0],  (*it)[1],(*it)[2]);
        if (Leafs.size()==5)
        {
            Box *MaxLeaf;
            MaxLeaf = Leafs[0];
            int Face[4];
            for (int i=1;i<5;i++)
            {
                if (MaxLeaf->BoxSize() < Leafs[i]->BoxSize())
                    MaxLeaf = Leafs[i];
            }
            int j;
            j = 0;
            for (int i = 0 ; i<8;i++)
            {
                if (ListNodes[MaxLeaf->_ElementNodes[i]-1][0] == (*it)[0] | ListNodes[MaxLeaf->_ElementNodes[i]-1][1]== (*it)[1] | ListNodes[MaxLeaf->_ElementNodes[i]-1][2]== (*it)[2])
                {
                    // std::cout<<"NodeIn xyz : "<< ListNodes[MaxLeaf->_ElementNodes[i]-1][0] << " " <<  ListNodes[MaxLeaf->_ElementNodes[i]-1][1] << " " << ListNodes[MaxLeaf->_ElementNodes[i]-1][2] <<"\n";
                    MasterNodes.push_back(MaxLeaf->_ElementNodes[i]);
                    if (MasterNodes.size()<5) Face[j] = i;
                    j++;
                }

            }
            if (MasterNodes.size()==4)
            {
                MasterNodes.clear();
                if (Face[0] == 0 & Face[1] == 1 & Face[2] == 2 & Face[3] == 3 )
                {
                    MasterNodes.push_back(MaxLeaf->_ElementNodes[1]);
                    MasterNodes.push_back(MaxLeaf->_ElementNodes[3]);
                }
                if (Face[0] == 0 & Face[1] == 3 & Face[2] == 4 & Face[3] == 7 )
                {
                    MasterNodes.push_back(MaxLeaf->_ElementNodes[0]);
                    MasterNodes.push_back(MaxLeaf->_ElementNodes[7]);
                }
                if (Face[0] == 0 & Face[1] == 1 & Face[2] == 4 & Face[3] == 5 )
                {
                    MasterNodes.push_back(MaxLeaf->_ElementNodes[1]);
                    MasterNodes.push_back(MaxLeaf->_ElementNodes[4]);
                }
                if (Face[0] == 4 & Face[1] == 5 & Face[2] == 6 & Face[3] == 7 )
                {
                    MasterNodes.push_back(MaxLeaf->_ElementNodes[5]);
                    MasterNodes.push_back(MaxLeaf->_ElementNodes[7]);
                }
                if (Face[0] == 1 & Face[1] == 2 & Face[2] == 5 & Face[3] == 6 )
                {
                    MasterNodes.push_back(MaxLeaf->_ElementNodes[1]);
                    MasterNodes.push_back(MaxLeaf->_ElementNodes[6]);
                }
                if (Face[0] == 2 & Face[1] == 3 & Face[2] == 6 & Face[3] == 7 )
                {
                    MasterNodes.push_back(MaxLeaf->_ElementNodes[2]);
                    MasterNodes.push_back(MaxLeaf->_ElementNodes[7]);
                }

            }
            if (MasterNodes.size() > 4)
            {
                //std::cout<<"Recompt : \n";
                MasterNodes.clear();
                for (int i = 0 ; i<8;i++)
                {
                    if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][0] == (*it)[0] )
                    {
                        if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][1]== (*it)[1] | ListNodes[MaxLeaf->_ElementNodes[i]-1][2]== (*it)[2])
                        {
                            MasterNodes.push_back(MaxLeaf->_ElementNodes[i]);
                            //std::cout<<"mm x NodeIn xyz : "<< ListNodes[MaxLeaf->_ElementNodes[i]-1][0] << " " <<  ListNodes[MaxLeaf->_ElementNodes[i]-1][1] << " " << ListNodes[MaxLeaf->_ElementNodes[i]-1][2] <<"\n";
                        }
                    }
                    else if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][1] == (*it)[1] )
                    {
                        if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][0]== (*it)[0] | ListNodes[MaxLeaf->_ElementNodes[i]-1][2]== (*it)[2])
                        {
                            MasterNodes.push_back(MaxLeaf->_ElementNodes[i]);
                            //std::cout<<"mm y NodeIn xyz : "<< ListNodes[MaxLeaf->_ElementNodes[i]-1][0] << " " <<  ListNodes[MaxLeaf->_ElementNodes[i]-1][1] << " " << ListNodes[MaxLeaf->_ElementNodes[i]-1][2] <<"\n";
                        }
                    }else if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][2] == (*it)[2] )
                    {
                        if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][0]== (*it)[0] | ListNodes[MaxLeaf->_ElementNodes[i]-1][1]== (*it)[1])
                        {
                            MasterNodes.push_back(MaxLeaf->_ElementNodes[i]);
                            // std::cout<<"mm z NodeIn xyz : "<< ListNodes[MaxLeaf->_ElementNodes[i]-1][0] << " " <<  ListNodes[MaxLeaf->_ElementNodes[i]-1][1] << " " << ListNodes[MaxLeaf->_ElementNodes[i]-1][2] <<"\n";
                        }
                    }
                }
            }
            HangingNodes[k+1] = MasterNodes;
        }
        if (Leafs.size()==3)
        {
            Box *MaxLeaf;
            MaxLeaf = Leafs[0];
            for (int i=1;i<3;i++)
            {
                if (MaxLeaf->BoxSize() < Leafs[i]->BoxSize())
                    MaxLeaf = Leafs[i];
            }
            for (int i = 0 ; i<8;i++)
            {
                if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][0] == (*it)[0] )
                {
                    if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][1]== (*it)[1] | ListNodes[MaxLeaf->_ElementNodes[i]-1][2]== (*it)[2])
                        MasterNodes.push_back(MaxLeaf->_ElementNodes[i]);
                } else if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][1] == (*it)[1] )
                {
                    if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][0]== (*it)[0] | ListNodes[MaxLeaf->_ElementNodes[i]-1][2]== (*it)[2])
                        MasterNodes.push_back(MaxLeaf->_ElementNodes[i]);
                } else if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][2] == (*it)[2] )
                {
                    if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][0]== (*it)[0] | ListNodes[MaxLeaf->_ElementNodes[i]-1][1]== (*it)[1])
                        MasterNodes.push_back(MaxLeaf->_ElementNodes[i]);
                }
            }
            HangingNodes[k+1] = MasterNodes;
        }
        if (Leafs.size()==6)
        {
            Box *MaxLeaf;
            MaxLeaf = Leafs[0];
            for (int i=1;i<6;i++)
            {
                if (MaxLeaf->BoxSize() < Leafs[i]->BoxSize())
                    MaxLeaf = Leafs[i];
            }
            for (int i = 0 ; i<8;i++)
            {
                if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][0] == (*it)[0] )
                {
                    if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][1]== (*it)[1] | ListNodes[MaxLeaf->_ElementNodes[i]-1][2]== (*it)[2])
                        MasterNodes.push_back(MaxLeaf->_ElementNodes[i]);
                } else if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][1] == (*it)[1] )
                {
                    if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][0]== (*it)[0] | ListNodes[MaxLeaf->_ElementNodes[i]-1][2]== (*it)[2])
                        MasterNodes.push_back(MaxLeaf->_ElementNodes[i]);
                } else if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][2] == (*it)[2] )
                {
                    if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][0]== (*it)[0] | ListNodes[MaxLeaf->_ElementNodes[i]-1][1]== (*it)[1])
                        MasterNodes.push_back(MaxLeaf->_ElementNodes[i]);
                }
            }
            HangingNodes[k+1] = MasterNodes;
        }

        if (Leafs.size()==7)
        {
            Box *MaxLeaf;
            MaxLeaf = Leafs[0];
            for (int i=1;i<7;i++)
            {
                if (MaxLeaf->BoxSize() < Leafs[i]->BoxSize())
                    MaxLeaf = Leafs[i];
            }
            for (int i = 0 ; i<8;i++)
            {
                if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][0] == (*it)[0] )
                {
                    if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][1]== (*it)[1] | ListNodes[MaxLeaf->_ElementNodes[i]-1][2]== (*it)[2])
                        MasterNodes.push_back(MaxLeaf->_ElementNodes[i]);
                } else if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][1] == (*it)[1] )
                {
                    if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][0]== (*it)[0] | ListNodes[MaxLeaf->_ElementNodes[i]-1][2]== (*it)[2])
                        MasterNodes.push_back(MaxLeaf->_ElementNodes[i]);
                } else if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][2] == (*it)[2] )
                {
                    if ( ListNodes[MaxLeaf->_ElementNodes[i]-1][0]== (*it)[0] | ListNodes[MaxLeaf->_ElementNodes[i]-1][1]== (*it)[1])
                        MasterNodes.push_back(MaxLeaf->_ElementNodes[i]);
                }
            }
            HangingNodes[k+1] = MasterNodes;
        }
        it++;
        k++;
    }
}

void OctreeLSImage::FillMeshInfo(int & pas){

    if (!_ListNodes.empty()){
        return;
    }

    _root->FillMeshInfo(_ListNodes,_ListElements,_ListLSValue,pas);

}



// fonction par balayage de région


void Box::FillMeshInfo(std::vector< std::vector<int> > &ListNodes, std::vector< std::vector<int> > &ListElements, std::vector<float> &ListLSValue,int &pas){


    int size = _octree->GetRoot()->BoxSize();

    int xpas =pas;  // à modifier si sizeZ n'est pas le plus petit
    int ypas = pas;
    int zpas = pas;

    std::vector<std::vector<int> >::iterator it;

    it = ListNodes.begin();
    int iti=0;

    for (int z = 0;z<=size;z+=zpas)
        for (int y = 0;y<=size;y+=ypas)
            for (int x = 0;x<=size; x+=xpas)
            {
                std::vector<Box*> Leafs;
                Leafs.clear();
                GetLeafsWith(Leafs, x,  y,  z);
                std::map<int,std::vector< int > > ElementsNodes;
                std::vector<int> NodesIn;

                bool added = false;
                for (unsigned int l=0;l<Leafs.size();l++){
                    if (!added){
                        std::vector<int> XYZ;
                        XYZ.push_back(x);
                        XYZ.push_back(y);
                        XYZ.push_back(z);
                        for (int i = 0 ; i<2;i++ )
                            for (int j = 0 ; j<2;j++ )
                                for (int k = 0 ; k<2;k++ ){
                                    if (x == Leafs[l]->GetData()->boundingbox[i] & y == Leafs[l]->GetData()->boundingbox[j+2] & z == Leafs[l]->GetData()->boundingbox[4+k] ){
                                        ListLSValue.push_back(Leafs[l]->GetData()->LevelSetValue[i][j][k]);
                                        ListNodes.push_back(XYZ);
                                        added = true;
                                        iti++;
                                    }
                                }
                    }else break;
                }
                if (added){
                    for (unsigned int l=0;l<Leafs.size();l++){
                        for (int i = 0 ; i<2;i++ )
                            for (int k = 0 ; k<2;k++ )
                                for (int j = 0 ; j<2;j++ ){
                                    int pos ;
                                    pos = i*4+k*2+j*1; // pour l'autre méthode
                                    if (x == Leafs[l]->GetData()->boundingbox[i] & y == Leafs[l]->GetData()->boundingbox[j+2] & z == Leafs[l]->GetData()->boundingbox[k+4]){
                                        Leafs[l]->SetElementNode(pos,iti);  //différence avec l'autre méthode
                                    }
                                }
                    }
                }
            }
    std::cout<<"\nNumber Nodes : "<< ListNodes.size() << "\n";
    _octree->GetRoot()->FillElementsNode(ListElements);

}

void Box::FillElementsNode(std::vector< std::vector<int> > &ListElements){
    // if it s a leaf then fill list node if node dont exist in list
    if (!this->HaveChildren()) {
        std::vector<int> ElementNodes;
        for (int i = 0 ; i < 8 ; i++) ElementNodes.push_back(_ElementNodes[i]);
        int temp;
        temp = ElementNodes[2];
        ElementNodes[2] = ElementNodes[3];
        ElementNodes[3] = temp;
        temp = ElementNodes[6];
        ElementNodes[6] = ElementNodes[7];
        ElementNodes[7] = temp;


        temp = _ElementNodes[2];
        _ElementNodes[2] = _ElementNodes[3];
        _ElementNodes[3] = temp;
        temp = _ElementNodes[6];
        _ElementNodes[6] = _ElementNodes[7];
        _ElementNodes[7] = temp;

//    temp = ElementNodes[1];
//    ElementNodes[1] = ElementNodes[2];
//		ElementNodes[2] = temp;
//		temp = ElementNodes[2];
//    ElementNodes[2] = ElementNodes[3];
//		ElementNodes[3] = temp;
//
//		temp = ElementNodes[5];
//    ElementNodes[5] = ElementNodes[6];
//		ElementNodes[6] = temp;
//		temp = ElementNodes[6];
//    ElementNodes[6] = ElementNodes[7];
//		ElementNodes[7] = temp;

        ListElements.push_back(ElementNodes);
//		std::cout<<"\n Nodes :";
//    for (int i = 0 ; i < 8 ; i++)
//    std::cout<<" " << ElementNodes[i];
        return;
    }

    for (int n = 0 ; n < 8 ; n++){
        this->_children[n]->FillElementsNode(ListElements);
    }
}


/*
void Box::FillInfo(std::vector< std::vector<int> > &ListNodes, std::vector< std::vector<int> > &ListElements, std::vector<float> &ListLSValue){

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
std::vector< std::vector <int> > *OctreeLSImage::GetListElements(){

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
//    	ListNodes = this->_octree->GetListNodes();
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




void OctreeLSImage::SetLeafNumber(){
    _LeafNumber = 0;
    _root->CountLeafNumber(_LeafNumber);
}

void Box::CountLeafNumber(int &LeafNumber){

    if (this->GetChild(0)==NULL) {
        LeafNumber = LeafNumber + 1;
        return;
    }

    for (int n = 0 ; n < 8 ; n++){
        this->_children[n]->CountLeafNumber(LeafNumber);
    }

}

// Divide function

void Box::Divide(){

// box divide in 8 boxes whit limite xl = (xmin + xmax)/2 ; yl = (ymin + ymax)/2 ; zl = (zmin + zmax)/2

    int n;

    // Box 1 :  < xl ; < yl  ; < zl

    n = 0;
    BoxData* data1 = new BoxData;

    data1->boundingbox[0]=this->_data->boundingbox[0];
    data1->boundingbox[1]=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2;
    data1->boundingbox[2]=this->_data->boundingbox[2];
    data1->boundingbox[3]=(this->_data->boundingbox[3]+this->_data->boundingbox[2])/2;
    data1->boundingbox[4]=this->_data->boundingbox[4];
    data1->boundingbox[5]=(this->_data->boundingbox[5]+this->_data->boundingbox[4])/2;

    this->_children[n] = new Box(data1,this,this->_octree);
    this->_children[n]->FillLevelSetValue(_children[n]->_octree->GetImage(),_children[n]->GetData());

    // Box 2 :  > xl ; < yl  ; < zl

    n = 1;
    BoxData* data2 = new BoxData;

    data2->boundingbox[0]=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2;
    data2->boundingbox[1]=this->_data->boundingbox[1];
    data2->boundingbox[2]=this->_data->boundingbox[2];
    data2->boundingbox[3]=(this->_data->boundingbox[3]+this->_data->boundingbox[2])/2;
    data2->boundingbox[4]=this->_data->boundingbox[4];
    data2->boundingbox[5]=(this->_data->boundingbox[5]+this->_data->boundingbox[4])/2;

    this->_children[n] = new Box(data2,this,this->_octree);
    this->_children[n]->FillLevelSetValue(_children[n]->_octree->GetImage(),_children[n]->GetData());

    // Box 3 :  < xl ; > yl  ; < zl

    n = 2;
    BoxData* data3 = new BoxData;

    data3->boundingbox[0]=this->_data->boundingbox[0];
    data3->boundingbox[1]=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2;
    data3->boundingbox[2]=(this->_data->boundingbox[3]+this->_data->boundingbox[2])/2;
    data3->boundingbox[3]=this->_data->boundingbox[3];
    data3->boundingbox[4]=this->_data->boundingbox[4];
    data3->boundingbox[5]=(this->_data->boundingbox[5]+this->_data->boundingbox[4])/2;

    this->_children[n] = new Box(data3,this,this->_octree);
    this->_children[n]->FillLevelSetValue(_children[n]->_octree->GetImage(),_children[n]->GetData());

    // Box 4 :  > xl ; > yl  ; < zl

    n = 3;
    BoxData* data4 = new BoxData;

    data4->boundingbox[0]=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2;
    data4->boundingbox[1]=this->_data->boundingbox[1];
    data4->boundingbox[2]=(this->_data->boundingbox[3]+this->_data->boundingbox[2])/2;
    data4->boundingbox[3]=this->_data->boundingbox[3];
    data4->boundingbox[4]=this->_data->boundingbox[4];
    data4->boundingbox[5]=(this->_data->boundingbox[5]+this->_data->boundingbox[4])/2;

    this->_children[n] = new Box(data4,this,this->_octree);
    this->_children[n]->FillLevelSetValue(_children[n]->_octree->GetImage(),_children[n]->GetData());

    // Box 5 :  < xl ; < yl  ; > zl

    n = 4;
    BoxData* data5 = new BoxData;

    data5->boundingbox[0]=this->_data->boundingbox[0];
    data5->boundingbox[1]=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2;
    data5->boundingbox[2]=this->_data->boundingbox[2];
    data5->boundingbox[3]=(this->_data->boundingbox[3]+this->_data->boundingbox[2])/2;
    data5->boundingbox[4]=(this->_data->boundingbox[5]+this->_data->boundingbox[4])/2;
    data5->boundingbox[5]=this->_data->boundingbox[5];

    this->_children[n] = new Box(data5,this,this->_octree);
    this->_children[n]->FillLevelSetValue(_children[n]->_octree->GetImage(),_children[n]->GetData());

    // Box 6 :  > xl ; < yl  ; > zl

    n = 5;
    BoxData* data6 = new BoxData;

    data6->boundingbox[0]=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2;
    data6->boundingbox[1]=this->_data->boundingbox[1];
    data6->boundingbox[2]=this->_data->boundingbox[2];
    data6->boundingbox[3]=(this->_data->boundingbox[3]+this->_data->boundingbox[2])/2;
    data6->boundingbox[4]=(this->_data->boundingbox[5]+this->_data->boundingbox[4])/2;
    data6->boundingbox[5]=this->_data->boundingbox[5];

    this->_children[n] = new Box(data6,this,this->_octree);
    this->_children[n]->FillLevelSetValue(_children[n]->_octree->GetImage(),_children[n]->GetData());

    // Box 7 :  < xl ; > yl  ; > zl

    n = 6;
    BoxData* data7 = new BoxData;

    data7->boundingbox[0]=this->_data->boundingbox[0];
    data7->boundingbox[1]=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2;
    data7->boundingbox[2]=(this->_data->boundingbox[3]+this->_data->boundingbox[2])/2;
    data7->boundingbox[3]=this->_data->boundingbox[3];
    data7->boundingbox[4]=(this->_data->boundingbox[5]+this->_data->boundingbox[4])/2;
    data7->boundingbox[5]=this->_data->boundingbox[5];

    this->_children[n] = new Box(data7,this,this->_octree);
    this->_children[n]->FillLevelSetValue(_children[n]->_octree->GetImage(),_children[n]->GetData());

    // Box 8 :  > xl ; > yl  ; > zl

    n = 7;
    BoxData* data8 = new BoxData;

    data8->boundingbox[0]=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2;
    data8->boundingbox[1]=this->_data->boundingbox[1];
    data8->boundingbox[2]=(this->_data->boundingbox[3]+this->_data->boundingbox[2])/2;
    data8->boundingbox[3]=this->_data->boundingbox[3];
    data8->boundingbox[4]=(this->_data->boundingbox[5]+this->_data->boundingbox[4])/2;
    data8->boundingbox[5]=this->_data->boundingbox[5];

    this->_children[n] = new Box(data8,this,this->_octree);
    this->_children[n]->FillLevelSetValue(_children[n]->_octree->GetImage(),_children[n]->GetData());
}

bool OctreeLSImage::Smooth(){

    return _root->Smooth();

}


bool Box::Smooth(){


    if (!this->HaveChildren()) {
        bool smoothed = true;
        BoxData*data = this->GetData();
        std::vector<Box*> Leafs;
        for (int i = 0 ; i<2;i++ ){
            for (int j = 0 ; j<2;j++ ){
                for (int k = 0 ; k<2;k++ ){
                    Leafs.clear();
                    _octree->GetRoot()->GetLeafsWith(Leafs,data->boundingbox[i],data->boundingbox[2+j],data->boundingbox[4+k]);
                    if (Leafs.size()!=8){
                        int min = Leafs[0]->BoxSize();
                        for (unsigned int l=0;l<Leafs.size();l++){
                            if (min>Leafs[l]->BoxSize()) min = Leafs[l]->BoxSize();
                        }
                        for (unsigned int l=0;l<Leafs.size();l++){
                            if (min<=(Leafs[l]->BoxSize())/4){
                                Leafs[l]->Divide();
                                smoothed = false;
                            }
                        }
                    }
                }
            }
        }
        return smoothed;
    }

    bool smoothed = true;
    for (int n = 0 ; n < 8 ; n++){
        if (!this->_children[n]->Smooth()) smoothed = false;
    }
    return smoothed;
}

// Octree research, box specialisation from root

void Box::GetLeafsWith(std::vector<Box*> &Leafs, int x, int y, int z){

    if (!this->HaveChildren()){
        Box* parent = this;
        BoxData* data;
        while (parent->GetParent()!=NULL){
            data = parent->GetParent()->GetData();
            parent=parent->GetParent();
        }
        Leafs.push_back(this);
        return;
    }


    if ((x<=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2) & (y <= (this->_data->boundingbox[3]+this->_data->boundingbox[2])/2) & (z <= (this->_data->boundingbox[5]+this->_data->boundingbox[4])/2) ){
        _children[0]->GetLeafsWith(Leafs,x,y,z);
    }

    if ((x>=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2) & (y <= (this->_data->boundingbox[3]+this->_data->boundingbox[2])/2) & (z <= (this->_data->boundingbox[5]+this->_data->boundingbox[4])/2) ){
        _children[1]->GetLeafsWith(Leafs,x,y,z);
    }

    if ((x<=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2) & (y >= (this->_data->boundingbox[3]+this->_data->boundingbox[2])/2) & (z <= (this->_data->boundingbox[5]+this->_data->boundingbox[4])/2) ){
        _children[2]->GetLeafsWith(Leafs,x,y,z);
    }

    if ((x>=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2) & (y >= (this->_data->boundingbox[3]+this->_data->boundingbox[2])/2) & (z <= (this->_data->boundingbox[5]+this->_data->boundingbox[4])/2) ){
        _children[3]->GetLeafsWith(Leafs,x,y,z);
    }

    if ((x<=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2) & (y <= (this->_data->boundingbox[3]+this->_data->boundingbox[2])/2) & (z >= (this->_data->boundingbox[5]+this->_data->boundingbox[4])/2) ){
        _children[4]->GetLeafsWith(Leafs,x,y,z);
    }

    if ((x>=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2) & (y <= (this->_data->boundingbox[3]+this->_data->boundingbox[2])/2) & (z >= (this->_data->boundingbox[5]+this->_data->boundingbox[4])/2) ){
        _children[5]->GetLeafsWith(Leafs,x,y,z);
    }

    if ((x<=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2) & (y >= (this->_data->boundingbox[3]+this->_data->boundingbox[2])/2) & (z >= (this->_data->boundingbox[5]+this->_data->boundingbox[4])/2) ){
        _children[6]->GetLeafsWith(Leafs,x,y,z);
    }

    if ((x>=(this->_data->boundingbox[1]+this->_data->boundingbox[0])/2) & (y >= (this->_data->boundingbox[3]+this->_data->boundingbox[2])/2) & (z >= (this->_data->boundingbox[5]+this->_data->boundingbox[4])/2) ){
        _children[7]->GetLeafsWith(Leafs,x,y,z);
    }

}
