// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Curvature.h"
#include "MElement.h"

#include<iostream>
#include<fstream>
#include<cmath>

//========================================================================================================

//CONSTRUCTOR
Curvature::Curvature(GModel* model)
{
    _model = model;
}
//========================================================================================================

//DESTRUCTOR
Curvature::~Curvature()
{

}
//========================================================================================================

void Curvature::retrievePhysicalSurfaces(const std::string & face_tag)
{
//    GFaceList ptFaceList;     //Pointer to face
    GEntityList ptTempEntityList;


    std::map<int, GEntityList > physicals[4]; //The right vector is a vector of 4 maps: 1 for 0D, one for 1D, one for 2D, one for 3D
    _model->getPhysicalGroups(physicals);
    std::map<int, GEntityList > surface_physicals = physicals[2];// Here we need only the 2nd maps which represents the faces (triangles)

    for (GEntityIter it = surface_physicals.begin(); it != surface_physicals.end(); it++) //Loop over physical names
    {
      std::string physicalTag = _model->getPhysicalName(2, it->first);
//        std::cout << "The physical tag we have stored is: "<< physicalTag << std::endl;

      if (physicalTag == face_tag) //face_tag is one of the argument of "compute_curvature"
      {
        ptTempEntityList.clear(); // the vector is cleared before the for-loop where is it filled
        ptTempEntityList  = it->second;

        for (unsigned int iEnt = 0; iEnt < ptTempEntityList.size(); iEnt++)
        {
          GEntity* entity = ptTempEntityList[iEnt];
          _ptFinalEntityList.push_back(entity);

        }
      }
   }
//   //To check that all the surfaces with the physical-tag "face_tag", are stored in ptFinalEntityList:
//   std::cout << "Stored physical tags:" << std::endl;
//   for(unsigned int i =0; i < _ptFinalEntityList.size(); ++i)
//   {
//    std::cout << _ptFinalEntityList[i]->tag() << std::endl; //some method that prints the name of the entity
//   }

}

//========================================================================================================

//INITIALIZATION OF THE MAP  AND  RENUMBERING OF THE SELECTED ENTITIES:

void Curvature::initializeMap()
{

  for (int i = 0; i< _ptFinalEntityList.size(); ++i)
  {
    // entity is a pointer to one surface of the group "FinalEntityList"
    GEntity* entity = _ptFinalEntityList[i];

    // Loop over the element all the element of the "myTag"-surface
    for (int iElem = 0; iElem < entity->getNumMeshElements(); iElem++)
    {
      // Pointer to one element
      MElement *e = entity->getMeshElement(iElem);
      // Tag of the corresponding element
      const int E = e->getNum();
      // std::cout << "We are now looking at element Nr: " << E << std::endl;
      _ElementToInt[E] = 1;

      const int A = e->getVertex(0)->getNum();   //Pointer to 1st vertex of the triangle
      const int B = e->getVertex(1)->getNum();
      const int C = e->getVertex(2)->getNum();

      _VertexToInt[A] = 1;
      _VertexToInt[B] = 1;
      _VertexToInt[C] = 1;
    }
  }

  /// Set up a new numbering of chosen vertices and triangles
  int idx = 0;

  // map between the pointer to vertex and the new numbering of the vertex
  std::map<int,int>::iterator vertex_iterator;
  // map between the pointer to element and the new numbering of the element
  std::map<int,int>::iterator element_iterator;

  for (vertex_iterator = _VertexToInt.begin() ; vertex_iterator !=_VertexToInt.end() ; ++ vertex_iterator, ++idx)
  {
    (*vertex_iterator).second = idx;
  }

  idx = 0;

  for (element_iterator = _ElementToInt.begin() ; element_iterator !=_ElementToInt.end() ; ++ element_iterator, ++idx)
  {
    (*element_iterator).second = idx;
  }

}

//========================================================================================================

void Curvature::computeVertexNormals()
{
  SVector3 vector_AB;
  SVector3 vector_AC;

  _TriangleArea.resize(_ElementToInt.size() );
  _VertexArea.resize(_ElementToInt.size() );
  _VertexNormal.resize(_VertexToInt.size());

  for (int i = 0; i< _ptFinalEntityList.size(); ++i)
  {
    // entity is a pointer to one surface of the group "FinalEntityList"
    GEntity* entity = _ptFinalEntityList[i];

    //Loop over the element all the element of the "myTag"-surface
    for (int iElem = 0; iElem < entity->getNumMeshElements(); iElem++)
    {
      // Pointer to one element
      MElement *e = entity->getMeshElement(iElem);
      // The NEW tag of the corresponding element
      const int E = _ElementToInt[e->getNum()];
      // std::cout << "We are now looking at element Nr: " << E << std::endl;

      // Pointers to vertices of triangle
      MVertex* A = e->getVertex(0);
      MVertex* B = e->getVertex(1);
      MVertex* C = e->getVertex(2);

      const int V0 = _VertexToInt[A->getNum()];  //The new number of the vertex
      const int V1 = _VertexToInt[B->getNum()];
      const int V2 = _VertexToInt[C->getNum()];

      vector_AB = SVector3(B->x() - A->x(), B->y() - A->y(), B->z() - A->z() );
      vector_AC = SVector3(C->x() - A->x(), C->y() - A->y(), C->z() - A->z() );

      const SVector3 cross = crossprod(vector_AB, vector_AC);

      // Area of the triangles:
      _TriangleArea[E] = 0.5*cross.norm();
      // std::cout << "The area of the triangle nr: " << e->getNum() << " is: "<< TriangleArea[E] << std::endl;

      _VertexArea[V0] += _TriangleArea[E];
      _VertexArea[V1] += _TriangleArea[E];
      _VertexArea[V2] += _TriangleArea[E];

      _VertexNormal[V0] += cross;  //here we are actually computing the unit normal vector per vertex
      _VertexNormal[V1] += cross;
      _VertexNormal[V2] += cross;


    } // end of loop over elements of one entity

  } //Loop over _ptFinalEntityList


    ///////Normalize the vertex-normals.
    for (unsigned int n = 0; n < _VertexToInt.size(); ++ n)
    {
      _VertexNormal[n].normalize();
    }

}

//========================================================================================================

void Curvature::curvatureTensor()
{

  STensor3 TempTensor;
  STensor3 TijABTensorProduct;
  SVector3 TijAB;
  SVector3 vector_AB;

  _CurveTensor.resize(_VertexToInt.size());


  for (int i = 0; i< _ptFinalEntityList.size(); ++i)
  {
    GEntity* entity = _ptFinalEntityList[i]; //entity is a pointer to one surface of the group "FinalEntityList"

    for (int iElem = 0; iElem < entity->getNumMeshElements(); iElem++) //Loop over the element all the element of the "myTag"-surface
    {
      MElement *e = entity->getMeshElement(iElem);  //Pointer to one element
      const int E = _ElementToInt[e->getNum()]; //The NEW tag of the corresponding element

      for (unsigned int i = 0; i<3; ++i)  // Loop over the 3 edges of each element
      {

        MVertex* A = e->getVertex(i);                   //Pointer to 1st vertex of the edge A-to-B
        MVertex* B = e->getVertex((i+1)%3);             //Pointer to 2nd vertex of the edge A-to-B

        const int V0 = _VertexToInt[A->getNum()];       //Tag of the 1st vertex of the edge A-to-B
        const int V1 = _VertexToInt[B->getNum()];       //Tag of the 2nd vertex of the edge A-to-B


        //Weight for triangle-i-th's contribution to the shape tensor:
        const double Wij0 = _TriangleArea[E] / (2 * _VertexArea[V0]);
        const double Wij1 = _TriangleArea[E] / (2 * _VertexArea[V1]);

        //Approximate Curvature "kappa" along some tangential vector T:
        vector_AB = SVector3(B->x() - A->x(), B->y() - A->y(), B->z() - A->z() );
        const double k_nominator0 = dot(_VertexNormal[V0], vector_AB); //Dot-product of the 2 vectors
        const double k_nominator1 = -dot(_VertexNormal[V1], vector_AB); //Dot-product of the 2 vectors

        const double coeff = 2.0/vector_AB.normSq(); //normSq is the norm to the power 2
        const double KijAB_0 = coeff*k_nominator0;
        const double KijAB_1 = coeff*k_nominator1;

        //Projection of the edge vector AB on the tangential plane:
        //** For Vertex 0
        tensprod(_VertexNormal[V0], _VertexNormal[V0], TempTensor);
        TempTensor *= -1.0; //-N*Nt
        TempTensor(0,0) += 1.0; //I-N*Nt
        TempTensor(1,1) += 1.0;
        TempTensor(2,2) += 1.0;

        for (int m = 0; m<3; ++m)
        {
          TijAB(m) = 0.0;
          for (int n = 0; n<3; ++n)
          {
            TijAB(m) += TempTensor(m,n) * vector_AB(n);
          }
        }
        TijAB.normalize();
        tensprod(TijAB, TijAB, TijABTensorProduct);
        _CurveTensor[V0] += Wij0*KijAB_0*TijABTensorProduct;


        //** For Vertex 1
        tensprod(_VertexNormal[V1], _VertexNormal[V1], TempTensor);
        TempTensor *= -1.0; //-N*Nt
        TempTensor(0,0) += 1.0; //I-N*Nt
        TempTensor(1,1) += 1.0;
        TempTensor(2,2) += 1.0;

         for (int m = 0; m<3; ++m)
        {
          TijAB(m) = 0.0;
          for (int n = 0; n<3; ++n)
          {
            TijAB(m) += TempTensor(m,n) * vector_AB(n);
          }
        }
        TijAB.normalize();
        tensprod(TijAB, TijAB, TijABTensorProduct);
        _CurveTensor[V1] += Wij1*KijAB_1*TijABTensorProduct;


      }//end of loop over the edges

    }//end of loop over all elements of one GEntity

  }//End of loop over ptFinalEntityList

}//End of method

//========================================================================================================

void Curvature::computeCurvature()
{
    SVector3 vector_E;
    SVector3 vector_A;
    SVector3 vector_B;
    SVector3 vector_Wvi;
    STensor3 Qvi;
    STensor3 QviT;
    STensor3 Holder;

    initializeMap();
    computeVertexNormals();
    curvatureTensor();

    _VertexCurve.resize(_VertexToInt.size());


    for (unsigned int n = 0; n < _VertexToInt.size(); ++ n) //Loop over the vertex
    {
       vector_E = SVector3(1,0,0);
       vector_A = vector_E + _VertexNormal[n];
       vector_B = vector_E - _VertexNormal[n];

       const double MagA = vector_A.norm();
       const double MagB = vector_B.norm();

       if (MagB > MagA)
       {
          vector_Wvi = vector_B;
       }
       else
       {
          vector_Wvi = vector_A;
       }

       vector_Wvi.normalize();
       //to obtain the Qvi = Id -2*Wvi*Wvi^t
       tensprod(vector_Wvi, vector_Wvi, Qvi); //Qvi = Wvi*Wvi^t
       Qvi *= -2.0;                           //-2*Wvi*Wvi^t
       Qvi(0,0) += 1.0;                       //I - 2*Wvi*Wvi^t  ==> Householder transformation
       Qvi(1,1) += 1.0;
       Qvi(2,2) += 1.0;

       //To create the transpose matrix:
       for (int i = 0; i<3; ++i)
       {
         for (int j = 0; j<3; ++j)
         {
           QviT(i,j) = Qvi(j,i);
         }
       }

       QviT *= _CurveTensor[n];
       QviT *=Qvi;
       Holder = QviT;

       //Eigenvalues of the 2*2 minor from the Householder matrix
       const double A = 1.0;
       const double B = -(Holder(1,1) + Holder(2,2));
       const double C = Holder(1,1)*Holder(2,2) - Holder(1,2)*Holder(2,1);
       const double Delta = std::sqrt(B*B-4*A*C);

       if((B*B-4.*A*C) < 0.0)
       {
         std::cout << "WARNING: negative discriminant: " << B*B-4.*A*C << std::endl;
       }


       const double m11 = (-B + Delta)/(2*A);  //Eigenvalue of Householder submatrix
       const double m22 = (-B - Delta)/(2*A);

       //_VertexCurve[n] = (3*m11-m22)*(3*m22-m11);  //Gaussian Curvature
       _VertexCurve[n] = ((3*m11-m22) + (3*m22-m11))*0.5; //Mean Curvature

    }
}

//========================================================================================================

void Curvature::writeToFile( const std::string & filename)
{
  std::ofstream outfile;
  outfile.precision(18);
  outfile.open(filename.c_str());
  outfile << "View \"Curvature \"{" << std::endl;

  for (int i = 0; i< _ptFinalEntityList.size(); ++i)
  {
    GEntity* entity = _ptFinalEntityList[i]; //entity is a pointer to one surface of the group "FinalEntityList"

    for (int iElem = 0; iElem < entity->getNumMeshElements(); iElem++) //Loop over the element all the element of the "myTag"-surface
    {
      MElement *e = entity->getMeshElement(iElem);  //Pointer to one element
      const int E = _ElementToInt[e->getNum()]; //The NEW tag of the corresponding element

      //std::cout << "We are now looking at element Nr: " << E << std::endl;

      MVertex* A = e->getVertex(0);  //Pointers to vertices of triangle
      MVertex* B = e->getVertex(1);
      MVertex* C = e->getVertex(2);

      const int V1 = _VertexToInt[A->getNum()];                //Tag of the 1st vertex of the triangle
      const int V2 = _VertexToInt[B->getNum()];                //Tag of the 2nd vertex of the triangle
      const int V3 = _VertexToInt[C->getNum()];                //Tag of the 3rd vertex of the triangle

      //Here is printing the triplet X-Y-Z of each vertex:
      //*************************************************

      outfile << "ST("; //VT = vector triangles   //ST = scalar triangle
      outfile << A->x() << ","<< A->y() << "," << A->z()<< ",";
      outfile << B->x() << ","<< B->y() << "," << B->z()<< ",";
      outfile << C->x() << ","<< C->y() << "," << C->z();

      outfile << ")";
      outfile <<"{";

      //Here is printing the 3 components of the normal vector for each vertex:
      //**********************************************************************

//         outfile << VertexNormal[V1].x() << ","<< VertexNormal[V1].y() << ","<< VertexNormal[V1].z() << ",";
//         outfile << VertexNormal[V2].x() << ","<< VertexNormal[V2].y() << ","<< VertexNormal[V2].z() << ",";
//         outfile << VertexNormal[V3].x() << ","<< VertexNormal[V3].y() << ","<< VertexNormal[V3].z();

      outfile << _VertexCurve[V1] << "," << _VertexCurve[V2] << "," << _VertexCurve[V3];

      outfile << "};" << std::endl;

  } //Loop over elements

} // Loop over ptFinalEntityList

outfile << "};" << std::endl;

outfile.close();
}

//========================================================================================================


