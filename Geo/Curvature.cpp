// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Curvature.h"
#include "MElement.h"
#include "MTriangle.h"
#include "GEntity.h"
#include "GFaceCompound.h"
#include "MLine.h"
#include "GRbf.h"
#include "OS.h"
#include "SBoundingBox3d.h"
#include "discreteEdge.h"

#include<iostream>
#include<fstream>
#include<cmath>

#define NEXT(i) ((i)<2 ? (i)+1 : (i)-2)
#define PREV(i) ((i)>0 ? (i)-1 : (i)+2)
//========================================================================================================

//Initialization of the static variables:
Curvature* Curvature::_instance = 0;
bool Curvature::_destroyed = false;
bool Curvature::_alreadyComputedCurvature = false;

//========================================================================================================

//CONSTRUCTOR
Curvature::Curvature() : _isMapInitialized(false)
{
}

// Curvature::Curvature(std::list<GFace*> &myFaces){

//   std::list<GFace*>::const_iterator it = myFaces.begin();
//   for( ; it != myFaces.end() ; ++it){
//          _ptFinalEntityList.push_back(*it);
//   }

// }

//========================================================================================================

Curvature::~Curvature()
{
   _instance = 0;
  _destroyed = true;

}
//========================================================================================================
void Curvature::onDeadReference()
{
  std::cout << "Dead reference of Curvature detected" << std::endl;
}
//========================================================================================================

Curvature& Curvature::getInstance()
{
  if (!_instance)  {
    if(_destroyed){
      onDeadReference();
    }
    else{
      create();
    }
  }
  return *_instance;
}
//========================================================================================================
  bool Curvature::valueAlreadyComputed()
  {
    return _alreadyComputedCurvature;
  }

//========================================================================================================

 void Curvature::create()
 {
   static Curvature instance;
   _instance = & instance;
 }

 //========================================================================================================
 void Curvature::retrieveCompounds()  {
#if defined(HAVE_SOLVER)

   /// -------------------------------------------------------------------------------------------
   // Loop over all faces. Check if the face is a compound. If it is, store all of its discrete
   // faces in _EntityArray

   std::list<GFace*> global_face_list;

   for(GModel::fiter face_iter = _model->firstFace(); face_iter != _model->lastFace(); ++face_iter)
   {
     if ( (*face_iter)->geomType() == GEntity::CompoundSurface )
     {
       GFaceCompound* compound = dynamic_cast<GFaceCompound*>(*face_iter);
       std::list<GFace*> tempcompounds = compound->getCompounds();
       std::list<GFace*>::iterator surfIterator;

       for(surfIterator = tempcompounds.begin(); surfIterator != tempcompounds.end(); ++surfIterator)
       {
         if ((*surfIterator)->geomType() == GEntity::DiscreteSurface)
         {
           global_face_list.push_back(*surfIterator);
         }
       }
     }

   } // Loop over faces of the model

   global_face_list.sort();
   global_face_list.unique();
   _EntityArray.resize(global_face_list.size());
   std::copy(global_face_list.begin(),global_face_list.end(),_EntityArray.begin());

//   std::cout << "Retrieve compounds: some preliminary info:" << std::endl;
//   std::cout << "The size of _ptFinalEntityList = " << _EntityArray.size() << std::endl;
//   std::cout << "Number of elements in all faces: " << std::endl;
//   for(int i = 0; i < _EntityArray.size(); ++i)
//   {
//     std::cout << "\t" << _EntityArray[i]->getNumMeshElements() << " elements" << std::endl;
//   }

#endif
 }

 //========================================================================================================

 // Method to detect boundary edges of the mesh. We want to find which edges are on the boundary in order
 // to correct the curvature field close to boundaries

 void Curvature::correctOnEdges()
 {
#if defined(HAVE_SOLVER)

   if (! _alreadyComputedCurvature )
   {
     Msg::Error("Cannot correct the curvature values at the edges because the curvatures weren't computed yet");
     return;
   }
   // Remark: this can only be used after the call to initializeMap() !

  buildEdgeList();

  std::list<MeshEdgeInfo>::iterator VertToEdgeListIter;

   _isOnBoundary.resize(_VertexToInt.size());
   for (unsigned int i = 0; i < _VertexToInt.size(); ++i)
   {
     _isOnBoundary[i] = 0;
   }

   // To detect the nodes on the egdes of a geometry, we create a list of all edges on the mesh. The
   // edges which are shared by only one mesh element are boundary edges. Their nodes are tagged by 1
   for (unsigned int i = 0; i < _VertexToInt.size(); ++i)
   {
     for (VertToEdgeListIter = _VertexToEdgeList[i].begin(); VertToEdgeListIter != _VertexToEdgeList[i].end();
                                                                                    ++VertToEdgeListIter)
     {
       if ((*VertToEdgeListIter).NbElemNeighbour == 1)
       {
         _isOnBoundary[(*VertToEdgeListIter).StartV] = 1;
         _isOnBoundary[(*VertToEdgeListIter).EndV] = 1;
       }
     }

   }

   // We want to find the nodes that are the immediate neighbours of the boundary nodes. Those nodes are
   // considered nodes with 'level 2'. The neighbours of neighbours have 'level 3' etc.
   // We want to construct levels 1,2,3. Nodes with level 0 are internal nodes of the mesh
   //Loop over the vector of edgelist
   for (int level = 1; level < 3; ++level)
   {
     for (unsigned int i = 0; i < _VertexToEdgeList.size(); ++i)
     {
       for (VertToEdgeListIter = _VertexToEdgeList[i].begin(); VertToEdgeListIter != _VertexToEdgeList[i].end();
                                                                                ++VertToEdgeListIter)
       {
         if (_isOnBoundary[(*VertToEdgeListIter).StartV] == level && _isOnBoundary[(*VertToEdgeListIter).EndV] == 0)
         {
          _isOnBoundary[(*VertToEdgeListIter).EndV] = level+1;
         }
         if (_isOnBoundary[(*VertToEdgeListIter).EndV] == level && _isOnBoundary[(*VertToEdgeListIter).StartV] == 0)
         {
           _isOnBoundary[(*VertToEdgeListIter).StartV] = level+1;
         }
       }
     }
   }//Loop over the level of the ring


   // Check test to see the tag of the nodes on the boundary:
//   for (int i = 0; i< _EntityArray.size(); ++i)
//   {
//     GFace* face = _EntityArray[i]; //List of all the discrete face on which we compute the curvature

//     for (int iElem = 0; iElem < face->getNumMeshElements(); iElem++)
//     {
//       MElement *e = face->getMeshElement(iElem);

//       // The NEW tag of the corresponding element
//       const int E = _ElementToInt[e->getNum()];

//       // Pointers to vertices of triangle
//       MVertex* A = e->getVertex(0);
//       MVertex* B = e->getVertex(1);
//       MVertex* C = e->getVertex(2);

//       V[0] = _VertexToInt[A->getNum()];  //The new number of the vertex
//       V[1] = _VertexToInt[B->getNum()];
//       V[2] = _VertexToInt[C->getNum()];

//       if (_isOnBoundary[V[0]] == 3)
//       {
//         std::cout << "Vertex: " << A->getNum() << " -- " << A->x() << "; " << A->y() << "; " << A->z() << std::endl;
//       }
//       if (_isOnBoundary[V[1]] == 3)
//       {
//         std::cout << "Vertex: " << B->getNum() << " -- " << B->x() << "; " << B->y() << "; " << B->z() << std::endl;
//       }
//       if (_isOnBoundary[V[2]] == 3)
//       {
//         std::cout << "Vertex: " << C->getNum() << " -- " << C->x() << "; " << C->y() << "; " << C->z() << std::endl;
//       }
//     }
//   }


   // Now we'll propagate the cuvature values from inside nodes with level = 3 close to the boundary - first
   // to nodes with level 2, then from nodes with level 2 to nodes with level 1 (on the boundary)
   _NbNeighbour.resize(_VertexToInt.size());
   for(unsigned int i = 0; i < _NbNeighbour.size(); ++i)
   {
     _NbNeighbour[i] = 0;
   }

   for (int level = 2; level > 0 ; --level)
   {

     for (unsigned int i = 0; i< _NbNeighbour.size(); ++i)
     {
       _NbNeighbour[i] = 0;
       if (_isOnBoundary[i] == level)
       {
        _VertexCurve[i] = 0.0;
       }
     }


     for (unsigned int i = 0; i < _VertexToEdgeList.size(); ++i)
     {
       for (VertToEdgeListIter = _VertexToEdgeList[i].begin(); VertToEdgeListIter != _VertexToEdgeList[i].end();
                                                                                ++VertToEdgeListIter)
       {

         if (_isOnBoundary[(*VertToEdgeListIter).StartV] == level && _isOnBoundary[(*VertToEdgeListIter).EndV] == level+1)
         {
            _VertexCurve[(*VertToEdgeListIter).StartV] += _VertexCurve[(*VertToEdgeListIter).EndV];
            _NbNeighbour[(*VertToEdgeListIter).StartV] ++;

         }
         if (_isOnBoundary[(*VertToEdgeListIter).EndV] == level && _isOnBoundary[(*VertToEdgeListIter).StartV] == level+1)
         {
            _VertexCurve[(*VertToEdgeListIter).EndV] += _VertexCurve[(*VertToEdgeListIter).StartV];
            _NbNeighbour[(*VertToEdgeListIter).EndV] ++;
         }

       }
     }

     // Correction for a degenerate case when a node has neighbours with the same or lower level, but zero
     // neighbours with level+1

     for (unsigned int i = 0; i < _VertexToEdgeList.size(); ++i)
     {
       for (VertToEdgeListIter = _VertexToEdgeList[i].begin(); VertToEdgeListIter != _VertexToEdgeList[i].end();
                                                                                ++VertToEdgeListIter)
       {

         if (_isOnBoundary[(*VertToEdgeListIter).StartV] == level
             && _isOnBoundary[(*VertToEdgeListIter).EndV] == level
             && _NbNeighbour[(*VertToEdgeListIter).StartV] == 0)
         {
           _VertexCurve[(*VertToEdgeListIter).StartV] += _VertexCurve[(*VertToEdgeListIter).EndV];
           _NbNeighbour[(*VertToEdgeListIter).StartV] = _NbNeighbour[(*VertToEdgeListIter).EndV];
         }
         if (_isOnBoundary[(*VertToEdgeListIter).EndV] == level
             && _isOnBoundary[(*VertToEdgeListIter).StartV] == level
             && _NbNeighbour[(*VertToEdgeListIter).EndV] == 0)
         {
           _VertexCurve[(*VertToEdgeListIter).EndV] += _VertexCurve[(*VertToEdgeListIter).StartV];
           _NbNeighbour[(*VertToEdgeListIter).EndV] = _NbNeighbour[(*VertToEdgeListIter).StartV];
         }
       }
     }

     for (unsigned int i = 0; i < _isOnBoundary.size(); ++i)
     {
       if (_isOnBoundary[i] == level)
       {
         if (_NbNeighbour[i] == 0)
         {
           std::cout << "ERROR: VERTEX " << i << " WITH LEVEL " << level << " HAS 0 NEIGHBOURS" << std::endl;
         }
         _VertexCurve[i] = _VertexCurve[i]/_NbNeighbour[i];
       }
     }

   }//Loop over the levels of the ring

//   for (int i = 0; i < _isOnBoundary.size(); ++i)
//   {
//     _VertexCurve[i] = _isOnBoundary[i];
//   }

#endif
 }

//========================================================================================================

//INITIALIZATION OF THE MAP  AND  RENUMBERING OF THE SELECTED ENTITIES:

void Curvature::initializeMap()
{
  if (! _isMapInitialized)
  {
    for (unsigned int i = 0; i< _EntityArray.size(); ++i)
    {
      GFace* face = _EntityArray[i];

      for (unsigned int iElem = 0; iElem < face->getNumMeshElements(); iElem++)
      {
        MElement *e = face->getMeshElement(iElem);
        const int E = e->getNum();
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
      (*vertex_iterator).second = idx;

    idx = 0;

    for (element_iterator = _ElementToInt.begin() ; element_iterator !=_ElementToInt.end() ; ++ element_iterator, ++idx)
      (*element_iterator).second = idx;

   _isMapInitialized = true;

  }

}

//========================================================================================================

//COMPUTE THE NORMAL AT THE VERTEX AND THE AREA AROUND

void Curvature::computeVertexNormals()
{
  SVector3 vector_AB;
  SVector3 vector_AC;

  _TriangleArea.resize(_ElementToInt.size() );
  _VertexArea.resize(_ElementToInt.size() );
  _VertexNormal.resize(_VertexToInt.size());

  for (unsigned int i = 0; i< _EntityArray.size(); ++i)
  {
    // face is a pointer to one surface of the group "FinalEntityList"
    GFace* face = _EntityArray[i];

    //Loop over the element all the element of the "myTag"-surface
    for (unsigned int iElem = 0; iElem < face->getNumMeshElements(); iElem++)
    {
      // Pointer to one element
      MElement *e = face->getMeshElement(iElem);
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

    } // end of loop over elements of one face

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

  for (unsigned int i = 0; i< _EntityArray.size(); ++i)
  {
    GFace* face = _EntityArray[i]; //face is a pointer to one surface of the group "FinalEntityList"

    for (unsigned int iElem = 0; iElem < face->getNumMeshElements(); iElem++) //Loop over the element all the element of the "myTag"-surface
    {
      MElement *e = face->getMeshElement(iElem);  //Pointer to one element
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
        const double k_nominator0 =  dot(_VertexNormal[V0], vector_AB); //Dot-product of the 2 vectors
        const double k_nominator1 = -dot(_VertexNormal[V1], vector_AB);

        const double coeff   = 2.0/vector_AB.normSq(); //normSq is the norm to the power 2
        const double KijAB_0 = coeff*k_nominator0;
        const double KijAB_1 = coeff*k_nominator1;

        //Projection of the edge vector AB on the tangential plane:
        //** For Vertex 0
        tensprod(_VertexNormal[V0], _VertexNormal[V0], TempTensor);
        TempTensor      *= -1.0; //-N*Nt
        TempTensor(0,0) +=  1.0; //I-N*Nt
        TempTensor(1,1) +=  1.0;
        TempTensor(2,2) +=  1.0;

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
        TempTensor      *= -1.0; //-N*Nt
        TempTensor(0,0) +=  1.0; //I-N*Nt
        TempTensor(1,1) +=  1.0;
        TempTensor(2,2) +=  1.0;

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

    }//end of loop over all elements of one GFace

  }//End of loop over ptFinalEntityList

}//End of method

//========================================================================================================

void Curvature::computeCurvature_Simple()
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
    Qvi      *= -2.0;                      //-2*Wvi*Wvi^t
    Qvi(0,0) +=  1.0;                      //I - 2*Wvi*Wvi^t  ==> Householder transformation
    Qvi(1,1) +=  1.0;
    Qvi(2,2) +=  1.0;

    //Transpose the matrix:
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

//COMPUTE THE NORMAL AT THE VERTEX AND THE AREA AROUND

void Curvature::computeRusinkiewiczNormals()
{
  SVector3 vector_AB;
  SVector3 vector_AC;
  SVector3 vector_BC;

  _TriangleArea.resize(_ElementToInt.size() );
  _VertexNormal.resize(_VertexToInt.size());

  for (unsigned int i = 0; i< _EntityArray.size(); ++i)
  {
    // face is a pointer to one surface of the group "FinalEntityList"
    GFace* face = _EntityArray[i];

    //Loop over the element all the element of the "myTag"-surface
    for (unsigned int iElem = 0; iElem < face->getNumMeshElements(); iElem++)
    {
      // Pointer to one element
      MElement *e = face->getMeshElement(iElem);
      const int E = _ElementToInt[e->getNum()];
    
      // Pointers to vertices of triangle
      MVertex* A = e->getVertex(0);
      MVertex* B = e->getVertex(1);
      MVertex* C = e->getVertex(2);

      const int V0 = _VertexToInt[A->getNum()];  //The new number of the vertex
      const int V1 = _VertexToInt[B->getNum()];
      const int V2 = _VertexToInt[C->getNum()];

      vector_AB = SVector3(B->x() - A->x(), B->y() - A->y(), B->z() - A->z() );
      vector_AC = SVector3(C->x() - A->x(), C->y() - A->y(), C->z() - A->z() );
      vector_BC = SVector3(C->x() - B->x(), C->y() - B->y(), C->z() - B->z() );

      const SVector3 cross = crossprod(vector_AB, vector_AC);

      // Area of the triangles:
      _TriangleArea[E] = 0.5*cross.norm();

      const double l_AB = vector_AB.normSq();
      const double l_AC = vector_AC.normSq();
      const double l_BC = vector_BC.normSq();

      _VertexNormal[V0] += cross * (1.0/ (l_AB*l_AC));
      _VertexNormal[V1] += cross * (1.0/ (l_AB*l_BC));
      _VertexNormal[V2] += cross * (1.0/ (l_AC*l_BC));

    } // end of loop over elements of one face

  } //Loop over _ptFinalEntityList

    ///////Normalize the vertex-normals.
    for (unsigned int n = 0; n < _VertexToInt.size(); ++ n)
    {
      _VertexNormal[n].normalize();
    }
}

//========================================================================================================
// Compute per-vertex point areas
void Curvature::computePointareas(){

  SVector3 e[3];
  SVector3 l2;
  SVector3 ew;
  double factor[3];

  _pointareas.resize(_VertexToInt.size());
  _cornerareas.resize(_ElementToInt.size());

  for (unsigned int i = 0; i< _EntityArray.size(); ++i)
  {
    GFace* face = _EntityArray[i]; //face is a pointer to one surface of the group "FinalEntityList"

    for (unsigned int iElem = 0; iElem < face->getNumMeshElements(); iElem++) //Loop over the element all the element of the "myTag"-surface
    {
      MElement *E = face->getMeshElement(iElem);  //Pointer to one element
      // The NEW tag of the corresponding element
      const int EIdx = _ElementToInt[E->getNum()];

      MVertex* A = E->getVertex(0);  //Pointers to vertices of triangle
      MVertex* B = E->getVertex(1);
      MVertex* C = E->getVertex(2);

      const int V0 = _VertexToInt[A->getNum()];
      const int V1 = _VertexToInt[B->getNum()];
      const int V2 = _VertexToInt[C->getNum()];

      if (_isOnBoundary[V0])
      {
          factor[0] = 1.0;
      }
      else {factor[0] = 1.0;}

      if (_isOnBoundary[V1])
      {
          factor[1] = 1.0;
      }
      else {factor[1] = 1.0;}

      if (_isOnBoundary[V2])
      {
          factor[2] = 1.0;
      }
      else {factor[2] = 1.0;}

      //Edges
      e[0] = SVector3(C->x() - B->x(), C->y() - B->y(), C->z() - B->z()); //vector side of a triangular element
      e[1] = SVector3(A->x() - C->x(), A->y() - C->y(), A->z() - C->z());
      e[2] = SVector3(B->x() - A->x(), B->y() - A->y(), B->z() - A->z());

      // Compute corner weights
      //SVector3 len = crossprod(e[0], e[1]);
      //len = norm
      //len2 = normSq
      double area = 0.5 * norm(crossprod(e[0], e[1])); //area of a triangle
      l2 = SVector3( normSq(e[0]), normSq(e[1]), normSq(e[2]) );
      ew = SVector3( l2[0] * (l2[1] + l2[2] - l2[0]),
                     l2[1] * (l2[2] + l2[0] - l2[1]),
                     l2[2] * (l2[0] + l2[1] - l2[2]) );

      if (ew[0] <= 0.0)
      {
        _cornerareas[EIdx][1] = -0.25 * l2[2] * area / dot(e[0], e[2]);
        _cornerareas[EIdx][2] = -0.25 * l2[1] * area / dot(e[0], e[1]);
        _cornerareas[EIdx][0] = area - _cornerareas[EIdx][1] - _cornerareas[EIdx][2];
      }
      else if (ew[1] <= 0.0)
      {
        _cornerareas[EIdx][2] = -0.25 * l2[0] * area / dot(e[1], e[0]);
        _cornerareas[EIdx][0] = -0.25 * l2[2] * area / dot(e[1], e[2]);
        _cornerareas[EIdx][1] = area - _cornerareas[EIdx][2] - _cornerareas[EIdx][0];
      }
      else if (ew[2] <= 0.0)
      {
        _cornerareas[EIdx][0] = -0.25 * l2[1] * area / dot(e[2], e[1]);
        _cornerareas[EIdx][1] = -0.25 * l2[0] * area / dot(e[2], e[0]);
        _cornerareas[EIdx][2] = area - _cornerareas[EIdx][0] - _cornerareas[EIdx][1];
      }
      else
      {
        float ewscale = 0.5 * area / (ew[0] + ew[1] + ew[2]);
        for (int j = 0; j < 3; j++)
          _cornerareas[EIdx][j] = ewscale * (ew[(j+1)%3] + ew[(j+2)%3]);
      }

      _pointareas[V0] += _cornerareas[EIdx][0];

      _pointareas[V1] += _cornerareas[EIdx][1];

      _pointareas[V2] += _cornerareas[EIdx][2];

      for (int j = 0; j < 3; j++)
      {
          _cornerareas[EIdx][j] = factor[j]*_cornerareas[EIdx][j];
      }


    } //End of loop over iElem

//      std::cout << "_pointareas.size = " << _pointareas.size() << std::endl;
//      std::cout << "_cornerareas.size = " << _cornerareas.size() << std::endl;

  } //End of loop over _ptFinalEntityList

} //End of the method "computePointareas"


//========================================================================================================
//Rotate a coordinate system to be perpendicular to the given normal
void Curvature::rot_coord_sys(const SVector3 &old_u, const SVector3 &old_v, const SVector3 &new_norm, SVector3 &new_u, SVector3 &new_v){

  new_u = old_u;
  new_v = old_v;
  SVector3 old_norm = crossprod(old_u, old_v);
  double ndot = dot(old_norm, new_norm);
//  if (unlikely(ndot <= -1.0f))
  if (ndot <= -1.0f)
  {
    new_u = -1.0*new_u;
    new_v = -1.0*new_v;
    return;
  }

  SVector3 perp_old = new_norm - ndot*old_norm;
  SVector3 dperp = 1.0f/(1 + ndot) * (old_norm + new_norm);
  new_u -= dperp*dot(new_u, perp_old);
  new_v -= dperp*dot(new_v, perp_old);
}

//========================================================================================================

//Project a curvature tensor from the basis spanned by old_u and old_v
//(which are assumed to be unit-length and perpendicular) to the new_u
//and new_v basis

void Curvature::proj_curv( const SVector3 &old_u, const SVector3 &old_v,
                          double old_ku, double old_kuv, double old_kv,
                          const SVector3  &new_u, const SVector3 &new_v,
                          double &new_ku, double &new_kuv, double &new_kv){
  SVector3 r_new_u;
  SVector3 r_new_v;
  rot_coord_sys(new_u, new_v, crossprod(old_u,old_v), r_new_u, r_new_v);

  const double u1 = dot(r_new_u, old_u);
  const double v1 = dot(r_new_u, old_v);
  const double u2 = dot(r_new_v, old_u);
  const double v2 = dot(r_new_v, old_v);

  new_ku  =   old_ku*u1*u1 + old_kuv*(2.0f * u1*v1)   + old_kv*v1*v1;
  new_kuv  =  old_ku*u1*u2 + old_kuv*(u1*v2 * u2*v1)  + old_kv*v1*v2;
  new_kv  =   old_ku*u2*u2 + old_kuv*(2.0f * u2*v2)   + old_kv*v2*v2;
}


//========================================================================================================

//Given a curvature tensor, find principal directions and curvatures
//Makes sure that pdir1 and pdir2 are perpendicular to normal

void Curvature::diagonalize_curv(const SVector3 &old_u, const SVector3 &old_v,
                      double ku, double kuv, double kv,
                      const SVector3 &new_norm,
                      SVector3 &pdir1, SVector3 &pdir2, double &k1, double &k2){
  SVector3 r_old_u;
  SVector3 r_old_v;

  double c = 1.0;
  double s = 0.0;
  double tt = 0.0;

  rot_coord_sys(old_u, old_v, new_norm, r_old_u, r_old_v);

//  if(unlikely(kuv !=0.0f))
  if(kuv !=0.0)  {
    //Jacobi rotation to diagonalize
    double h= 0.5*(kv -ku)/ kuv;
    tt = (h<0.0) ?
          1.0 / (h - std::sqrt(1.0 + h*h)):
          1.0 / (h + std::sqrt(1.0 + h*h));
    c = 1.0 / std::sqrt(1.0 + tt*tt);
    s = tt*c;
  }

  k1 = ku - tt *kuv;
  k2 = kv + tt *kuv;

  if(std::abs(k1) >= std::abs(k2))  {
    pdir1 = c*r_old_u - s*r_old_v;
  }
  else  {
    std::swap(k1,k2);
    pdir1 = s*r_old_u + c*r_old_v;
  }
  pdir2 = crossprod(new_norm, pdir1);
}

//========================================================================================================
void Curvature::computeCurvature(GModel* model, typeOfCurvature typ)
{

  _model = model;

  double t0 = Cpu();
  Msg::StatusBar(2, true, "(C) Computing Curvature");
  if (typ == RUSIN)
    computeCurvature_Rusinkiewicz(0);
  else if (typ == RBF)
    computeCurvature_RBF();
  else if (typ == SIMPLE)
    computeCurvature_Simple();

  double t1 = Cpu();
  Msg::StatusBar(2, true, "(C) Done Computing Curvature (%g s)", t1-t0);

  //writeToMshFile("curvature.msh");
  writeToPosFile("curvature.pos");
  //writeToVtkFile("curvature.vtk");

}

//========================================================================================================

void Curvature::buildEdgeList()
{

  int V[3];
  bool edgefound;

  _VertexToEdgeList.clear();

  std::list<MeshEdgeInfo>::iterator VertToEdgeListIter;
  MeshEdgeInfo TempEdge;

  _VertexToEdgeList.resize(_VertexToInt.size());

  for (unsigned int i = 0; i< _EntityArray.size(); ++i)
  {
    GFace* face = _EntityArray[i]; //List of all the discrete face on which we compute the curvature

    for (unsigned int iElem = 0; iElem < face->getNumMeshElements(); iElem++)
    {
      MElement *e = face->getMeshElement(iElem);

      // Pointers to vertices of triangle
      MVertex* A = e->getVertex(0);
      MVertex* B = e->getVertex(1);
      MVertex* C = e->getVertex(2);

      V[0] = _VertexToInt[A->getNum()];  //The new number of the vertex
      V[1] = _VertexToInt[B->getNum()];
      V[2] = _VertexToInt[C->getNum()];

      // Try to add edge [V0,V1] to the global list
      for (int j = 0; j < 3; ++j)
      {
          const int StartV = std::min(V[j], V[(j+1)%3]);
          const int EndV = std::max(V[j], V[(j+1)%3]);

          edgefound = false;
          for (VertToEdgeListIter = _VertexToEdgeList[StartV].begin(); VertToEdgeListIter != _VertexToEdgeList[StartV].end();
                                                                                   ++VertToEdgeListIter)
          {
            if(StartV == (*VertToEdgeListIter).StartV && EndV == (*VertToEdgeListIter).EndV)
            {
              (*VertToEdgeListIter).NbElemNeighbour ++;
              edgefound = true;
            }

          }
          if (false == edgefound)
          {
            TempEdge.StartV = StartV;
            TempEdge.EndV = EndV;
            TempEdge.NbElemNeighbour = 1;
            _VertexToEdgeList[StartV].push_back(TempEdge);
          }


      } // Loop over j


    } // Loop over the elements (triangles) of the face
  }

  int NbEdges = 0;
  for(unsigned int i = 0; i < _VertexToEdgeList.size(); ++i)
  {
    NbEdges += _VertexToEdgeList[i].size();
  }

  //std::cout << "Euler formula:" << std::endl;
  //std::cout << "Edges + 2 =        " << NbEdges + 2 << std::endl;
  //std::cout << "Elements + Nodes = " << _VertexToInt.size() + _ElementToInt.size() << std::endl;

}

//========================================================================================================


void Curvature::smoothCurvatureField(const int NbIter)
{
  if ( _VertexToEdgeList.size() == 0 ) { buildEdgeList(); }

  std::vector<double> smoothedCurvature;
  smoothedCurvature.resize( _VertexToInt.size() );


  // Smoothed curvature directions
  std::vector<SVector3> smoothedDir1;
  std::vector<SVector3> smoothedDir2;
  smoothedDir1.resize(_VertexToInt.size());
  smoothedDir2.resize(_VertexToInt.size());

  _NbNeighbour.resize(_VertexToInt.size());
  for(unsigned int i = 0; i < _VertexToInt.size(); ++i)
  {
    _NbNeighbour[i] = 0;
  }


  // Smoothing iterations
  for(int iter = 0; iter < NbIter; ++iter)
  {

    for(unsigned int i = 0; i < smoothedCurvature.size(); ++i)
    {
      smoothedCurvature[i] = 0.0;
      smoothedDir1[i] = SVector3();
      smoothedDir2[i] = SVector3();
    }

    std::list<MeshEdgeInfo>::const_iterator edgeIterator;


    for(unsigned int i = 0; i < _VertexToEdgeList.size(); ++i)
    {
      for(edgeIterator = _VertexToEdgeList[i].begin(); edgeIterator != _VertexToEdgeList[i].end(); ++edgeIterator)
      {

        const int V0 = (*edgeIterator).StartV;
        const int V1 = (*edgeIterator).EndV;

        smoothedCurvature[V0] += _VertexCurve[V1];
        smoothedCurvature[V1] += _VertexCurve[V0];

        smoothedDir1[V0] += _pdir1[V1];
        smoothedDir1[V1] += _pdir1[V0];

        smoothedDir2[V0] += _pdir2[V1];
        smoothedDir2[V1] += _pdir2[V0];

        _NbNeighbour[V0]++;
        _NbNeighbour[V1]++;
      }
    }



    const double Lambda = 0.3;
    for(unsigned int i = 0; i < _VertexCurve.size(); ++i)
    {
      _VertexCurve[i] = Lambda*_VertexCurve[i] + (1-Lambda)*smoothedCurvature[i] / _NbNeighbour[i];
      _pdir1[i] = Lambda * _pdir1[i] + (1.-Lambda)/_NbNeighbour[i] * smoothedDir1[i];
      _pdir2[i] = Lambda * _pdir2[i] + (1.-Lambda)/_NbNeighbour[i] * smoothedDir2[i];
    }
  }

}


//========================================================================================================



void Curvature::computeCurvature_Rusinkiewicz(int isMax)
{
  retrieveCompounds();
  initializeMap();

  computeRusinkiewiczNormals();
  computePointareas();

  SVector3 e[3];
  STensor3 w;
  SVector3 t;
  SVector3 n;
  SVector3 b;
  SVector3 m;
  SVector3 dn;

  double u;
  double v;
  double dnu;
  double dnv;
  double c1;
  double c2;
  double c12;
  double wt;

  _pdir1.resize(_VertexToInt.size());
  _pdir2.resize(_VertexToInt.size());

  _curv1.resize(_VertexToInt.size());
  _curv2.resize(_VertexToInt.size());
  _curv12.resize(_VertexToInt.size());

  for (unsigned int i = 0; i< _EntityArray.size(); ++i)
  {
    GFace* face = _EntityArray[i]; //face is a pointer to one surface of the group "FinalEntityList"

    for (unsigned int iElem = 0; iElem < face->getNumMeshElements(); iElem++) //Loop over the element all the element of the "myTag"-surface
    {
      MElement *E = face->getMeshElement(iElem);  //Pointer to one element

      MVertex* A = E->getVertex(0);  //Pointers to vertices of triangle
      MVertex* B = E->getVertex(1);
      MVertex* C = E->getVertex(2);

      const int V0 = _VertexToInt[A->getNum()];  //Tag of the 1st vertex of the triangle
      const int V1 = _VertexToInt[B->getNum()];
      const int V2 = _VertexToInt[C->getNum()];

      ///Set up an initial coordinate system per vertex:

      _pdir1[V0] = SVector3(B->x() - A->x(), B->y() - A->y(), B->z() - A->z());
      _pdir1[V1] = SVector3(C->x() - B->x(), C->y() - B->y(), C->z() - B->z());
      _pdir1[V2] = SVector3(A->x() - C->x(), A->y() - C->y(), A->z() - C->z());
    }
  }

  for (unsigned int ivertex = 0; ivertex < _VertexToInt.size(); ++ivertex)
  {
    _pdir1[ivertex] = crossprod(_pdir1[ivertex], _VertexNormal[ivertex]);
    _pdir1[ivertex].normalize();
    _pdir2[ivertex] = crossprod(_VertexNormal[ivertex], _pdir1[ivertex]);
  }

  // Compute curvature per face:
  for (unsigned int i = 0; i< _EntityArray.size(); ++i)
  {
    //face is a pointer to one surface of the group "FinalEntityList"
    GFace* face = _EntityArray[i];

    //Loop over all elements of this face:
    for (unsigned int iElem = 0; iElem < face->getNumMeshElements(); iElem++)
    {
      MElement *E = face->getMeshElement(iElem);  //Pointer to one element
      // The NEW tag of the corresponding element
      const int EIdx = _ElementToInt[E->getNum()];

      MVertex* A = E->getVertex(0);  //Pointers to vertices of triangle
      MVertex* B = E->getVertex(1);
      MVertex* C = E->getVertex(2);

      e[0] = SVector3(C->x() - B->x(), C->y() - B->y(), C->z() - B->z());
      e[1] = SVector3(A->x() - C->x(), A->y() - C->y(), A->z() - C->z());
      e[2] = SVector3(B->x() - A->x(), B->y() - A->y(), B->z() - A->z());

      //SVector3 e[3] = {SVector3(C->x() - B->x(), C->y() - B->y(), C->z() - B->z()), SVector3(A->x() - C->x(), A->y() - C->y(), A->z() - C->z()), SVector3(B->x() - A->x(), B->y() - A->y(), B->z() - A->z()) };

      //N-T-B coordinate system per face
      t = e[0];
      t.normalize();
      n = crossprod( e[0], e[1]);
      b = crossprod(n, t);
      b.normalize();

      //Estimate curvature based on variations of normals along edges:
      //intialization:
      m = SVector3(0.0, 0.0, 0.0);
      //maybe double m[3] = { 0.0, 0.0, 0.0 };
      // w *= 0.0; //Reset w to zero
      for (int i  = 0; i< 3; ++i)
      {
        for (int j = 0; j<3; ++j)
        {
          w(i,j) = 0.0;
        }
      }

      //filling:
      for (int j = 0; j< 3; ++j)
      {
        u = dot(e[j], t);
        v = dot(e[j], b);

        w(0,0) += u*u;
        w(0,1) += u*v;
        w(2,2) += v*v;

        MVertex* U = E->getVertex(PREV(j));
        MVertex* V = E->getVertex(NEXT(j));

        const int UIdx = _VertexToInt[U->getNum()];
        const int VIdx = _VertexToInt[V->getNum()];

        dn = _VertexNormal[UIdx] - _VertexNormal[VIdx];

        dnu = dot(dn, t);
        dnv = dot(dn, b);

        m[0] += dnu*u;
        m[1] += dnu*v + dnv*u;
        m[2] += dnv*v;
      }

      w(1,1) = w(0,0) + w(2,2);
      w(1,2) = w(0,1);

      //Least Squares Solution
      double diag[3];
      if (!ldltdc(w, diag))
      {
        std::cout << "ldltdc failed" << std::endl;
        continue;
      }
      ldltsl(w, diag, m, m);

      //Push it back out to the vertices
      for (int j = 0; j< 3; ++j)
      {
        const int old_vj = E->getVertex(j)->getNum();
        const int vj = _VertexToInt[old_vj];
        proj_curv(t, b, m[0], m[1], m[2], _pdir1[vj], _pdir2[vj], c1, c12, c2);
        wt = _cornerareas[EIdx][j]/_pointareas[vj];
//          wt = 1.0;
//        if (_isOnBoundary[vj])
//        {
//            wt = 2.0*wt;
//        }

        _curv1[vj]  += wt*c1;
        _curv12[vj] += wt*c12;
        _curv2[vj]  += wt*c2;
      }

    } //End of loop over the element (iElem)

  } //End of loop over "_EntityArray"


  //Compute principal directions and curvatures at each vertex
  for (unsigned int ivertex = 0; ivertex < _VertexToInt.size(); ++ivertex)  {
    diagonalize_curv(_pdir1[ivertex], _pdir2[ivertex], _curv1[ivertex], _curv12[ivertex], _curv2[ivertex],
                     _VertexNormal[ivertex], _pdir1[ivertex], _pdir2[ivertex], _curv1[ivertex], _curv2[ivertex]);
  }

  _VertexCurve.resize( _VertexToInt.size() );

  for (unsigned int ivertex = 0; ivertex < _VertexToInt.size(); ++ivertex){

    if (isMax){
      _VertexCurve[ivertex] = std::max(fabs(_curv1[ivertex]), fabs(_curv2[ivertex]));
    }
    else{
    //_VertexCurve[ivertex] = (_curv1[ivertex]+_curv2[ivertex])*0.5; //Mean curvature
    //_VertexCurve[ivertex] = _curv1[ivertex]*_curv2[ivertex]; //Gaussian
    _VertexCurve[ivertex] = _curv1[ivertex]; //Maximal Curvature
    }

  }

//   smoothCurvatureField(1);
  _alreadyComputedCurvature = true;

// Propagate the value of curvature from nodes close the edges of the geometry onto the edges
  correctOnEdges();

} //End of the "computeCurvature_Rusinkiewicz" method

 //========================================================================================================

void Curvature::computeCurvature_RBF()
{
  retrieveCompounds();
  initializeMap();
  
  //fill set of MVertex
  std::set<MVertex*> allNodes;
  for (unsigned int i = 0; i< _EntityArray.size(); ++i)  {
    GFaceCompound* face = (GFaceCompound*)_EntityArray[i];
    for (unsigned iElem = 0; iElem < face->getNumMeshElements(); iElem++) {
      MElement *e = face->getMeshElement(iElem);
      for(int j = 0; j < e->getNumVertices(); j++){
        allNodes.insert(e->getVertex(j));
      }
    }
  }

  //bounding box
  SBoundingBox3d bb;
  std::vector<SPoint3> vertices;
  for(std::set<MVertex *>::iterator itv = allNodes.begin(); itv !=allNodes.end() ; ++itv){
    SPoint3 pt((*itv)->x(),(*itv)->y(), (*itv)->z());
    vertices.push_back(pt);
    bb +=pt;
  }
  double sizeBox = norm(SVector3(bb.max(), bb.min()));

  //compure curvature RBF
  std::map<MVertex*, SVector3> _normals;
  std::vector<MVertex*> _ordered;
  std::map<MVertex*, double> curvRBF;
  //GLOBAL
  GRbf *_rbf = new GRbf(sizeBox, 0, 1, _normals, allNodes, _ordered); 
  _rbf->computeCurvature(_rbf->getXYZ(),curvRBF);
  //LOCAL FD
  //GRbf *_rbf = new GRbf(sizeBox, 0, 1, _normals, allNodes, _ordered, true); 
  //_rbf->computeLocalCurvature(_rbf->getXYZ(),curvRBF);

  //fill vertex curve
  _VertexCurve.resize( _VertexToInt.size() );
  for(std::set<MVertex *>::iterator itv = allNodes.begin(); itv !=allNodes.end() ; ++itv){
    MVertex *v = *itv;
    std::map<int,int>::iterator vertexIterator;
    int V0;
    vertexIterator = _VertexToInt.find( v->getNum() );
    if ( vertexIterator != _VertexToInt.end() )  V0 = (*vertexIterator).second;
    _VertexCurve[V0] = curvRBF[v];
   }

 _alreadyComputedCurvature = true;

} //End of the "computeCurvature_RBF" method


 //========================================================================================================

void Curvature::triangleNodalValues(MTriangle* triangle, double& c0, double& c1, double& c2, int isAbs)
  {
    MVertex* A = triangle->getVertex(0);
    MVertex* B = triangle->getVertex(1);
    MVertex* C = triangle->getVertex(2);

    int V0 = 0;
    int V1 = 0;
    int V2 = 0;

    std::map<int,int>::iterator vertexIterator;
    vertexIterator = _VertexToInt.find( A->getNum() );
    if ( vertexIterator != _VertexToInt.end() )  V0 = (*vertexIterator).second;
    else
      std::cout << "Didn't find vertex with number " << A->getNum() << " in _VertextToInt !" << std::endl;
    
    vertexIterator = _VertexToInt.find( B->getNum() );
    if ( vertexIterator != _VertexToInt.end() )   V1 = (*vertexIterator).second;
    else
      std::cout << "Didn't find vertex with number " << B->getNum() << " in _VertextToInt !" << std::endl;
    
    vertexIterator = _VertexToInt.find( C->getNum() );
    if ( vertexIterator != _VertexToInt.end() )  V2 = (*vertexIterator).second;
    else
      std::cout << "Didn't find vertex with number " << C->getNum() << " in _VertextToInt !" << std::endl;
    
    if (isAbs){
      c0 = std::abs(_VertexCurve[V0]); //Mean curvature in vertex 0
      c1 = std::abs(_VertexCurve[V1]); //Mean curvature in vertex 1
      c2 = std::abs(_VertexCurve[V2]); //Mean curvature in vertex 2
    }
    else{
      c0 = _VertexCurve[V0]; //Mean curvature in vertex 0
      c1 = _VertexCurve[V1]; //Mean curvature in vertex 1
      c2 = _VertexCurve[V2]; //Mean curvature in vertex 2
    }

  }

//========================================================================================================

void Curvature::triangleNodalValuesAndDirections(MTriangle* triangle, SVector3* dMax, SVector3* dMin, double* cMax, double* cMin, int isAbs)
{
  MVertex* A = triangle->getVertex(0);
  MVertex* B = triangle->getVertex(1);
  MVertex* C = triangle->getVertex(2);

  int V0 = 0;
  int V1 = 0;
  int V2 = 0;

  std::map<int,int>::iterator vertexIterator;
  vertexIterator = _VertexToInt.find( A->getNum() );
  if ( vertexIterator != _VertexToInt.end() )  V0 = (*vertexIterator).second;
  else
    std::cout << "Didn't find vertex with number " << A->getNum() << " in _VertextToInt !" << std::endl;

  vertexIterator = _VertexToInt.find( B->getNum() );
  if ( vertexIterator != _VertexToInt.end() )  V1 = (*vertexIterator).second;
  else
    std::cout << "Didn't find vertex with number " << B->getNum() << " in _VertextToInt !" << std::endl;

  vertexIterator = _VertexToInt.find( C->getNum() );
  if ( vertexIterator != _VertexToInt.end() )  V2 = (*vertexIterator).second;
  else
    std::cout << "Didn't find vertex with number " << C->getNum() << " in _VertextToInt !" << std::endl;

  if (isAbs){
    dMax[0] = _pdir1[V0];
    dMax[1] = _pdir1[V1];
    dMax[2] = _pdir1[V2];

    dMin[0] = _pdir2[V0];
    dMin[1] = _pdir2[V1];
    dMin[2] = _pdir2[V2];

    cMax[0]  = std::abs(_curv1[V0]);
    cMax[1]  = std::abs(_curv1[V1]);
    cMax[2]  = std::abs(_curv1[V2]);

    cMin[0]  = std::abs(_curv2[V0]);
    cMin[1]  = std::abs(_curv2[V1]);
    cMin[2]  = std::abs(_curv2[V2]);

  }
  else{

    dMax[0] = _pdir1[V0];
    dMax[1] = _pdir1[V1];
    dMax[2] = _pdir1[V2];

    dMin[0] = _pdir2[V0];
    dMin[1] = _pdir2[V1];
    dMin[2] = _pdir2[V2];

    cMax[0]  = _curv1[V0];
    cMax[1]  = _curv1[V1];
    cMax[2]  = _curv1[V2];

    cMin[0]  = _curv2[V0];
    cMin[1]  = _curv2[V1];
    cMin[2]  = _curv2[V2];
  }
}



  //========================================================================================================

void Curvature::edgeNodalValues(MLine* edge, double& c0, double& c1, int isAbs)
   {
     MVertex* A = edge->getVertex(0);
     MVertex* B = edge->getVertex(1);

     int V0 = 0;
     int V1 = 0;

     std::map<int,int>::iterator vertexIterator;

     vertexIterator = _VertexToInt.find( A->getNum() );
     if ( vertexIterator != _VertexToInt.end() )  V0 = (*vertexIterator).second;
     else  std::cout << "Didn't find vertex with number " << A->getNum() << " in _VertextToInt !" << std::endl;
     
     vertexIterator = _VertexToInt.find( B->getNum() );
     if ( vertexIterator != _VertexToInt.end() ) V1 = (*vertexIterator).second;
     else std::cout << "Didn't find vertex with number " << B->getNum() << " in _VertextToInt !" << std::endl;
     
     if (isAbs){
       c0 = std::abs(_VertexCurve[V0]); //Mean curvature in vertex 0
       c1 = std::abs(_VertexCurve[V1]); //Mean curvature in vertex 1
     }
     else{
       c0 = _VertexCurve[V0]; //Mean curvature in vertex 0
       c1 = _VertexCurve[V1]; //Mean curvature in vertex 1
     }

   }

//========================================================================================================

void Curvature::edgeNodalValuesAndDirections(MLine* edge, SVector3* dMax, SVector3* dMin, double* cMax, double* cMin, int isAbs)
{
    std::vector<MVertex*> LineVertices;
    //LineVertices.resize(2);
    edge->getEdgeVertices(0,LineVertices);//triangle->getVertex(0);

    int V0 = 0;
    int V1 = 0;

    //LineVertices[0] is a pointer the first vertex of the edge
    //LineVertices[1] is a pointer the second vertex of the edge


    std::map<int,int>::iterator vertexIterator;
    vertexIterator = _VertexToInt.find( LineVertices[0]->getNum() );
    if ( vertexIterator != _VertexToInt.end() )  V0 = (*vertexIterator).second;
    else
      std::cout << "Didn't find vertex with number " << LineVertices[0]->getNum() << " in _VertextToInt !" << std::endl;

    vertexIterator = _VertexToInt.find( LineVertices[1]->getNum() );
    if ( vertexIterator != _VertexToInt.end() )  V1 = (*vertexIterator).second;
    else
      std::cout << "Didn't find vertex with number " << LineVertices[1]->getNum() << " in _VertextToInt !" << std::endl;


    if (isAbs){
      dMax[0] = _pdir1[V0];
      dMax[1] = _pdir1[V1];

      dMin[0] = _pdir2[V0];
      dMin[1] = _pdir2[V1];

      cMax[0]  = std::abs(_curv1[V0]);
      cMax[1]  = std::abs(_curv1[V1]);

      cMin[0]  = std::abs(_curv2[V0]);
      cMin[1]  = std::abs(_curv2[V1]);

    }
    else{

      dMax[0] = _pdir1[V0];
      dMax[1] = _pdir1[V1];

      dMin[0] = _pdir2[V0];
      dMin[1] = _pdir2[V1];

      cMax[0]  = _curv1[V0];
      cMax[1]  = _curv1[V1];

      cMin[0]  = _curv2[V0];
      cMin[1]  = _curv2[V1];
    }
}


//========================================================================================================

double Curvature::getAtVertex(const MVertex *v) const {
  std::map<int,int>::const_iterator it = _VertexToInt.find(v->getNum());
  if (it == _VertexToInt.end()) {
    Msg::Error("curvature has not been computed for vertex %i (%i)", v->getNum(), _VertexToInt.size());
    return 1;
  }
  return _VertexCurve[it->second];
}

//========================================================================================================

void Curvature::writeToMshFile(const std::string &filename)
{
  std::ofstream outfile;
  outfile.precision(18);
  outfile.open(filename.c_str());

  /// Write the values of curvature 1 (max)
  outfile << "$MeshFormat"    << std::endl;
  outfile << "2.1 0 8"        << std::endl;
  outfile << "$EndMeshFormat" << std::endl;
  outfile << "$NodeData" << std::endl;
  outfile << "1" << std::endl;                 // One string tag
  outfile << "\"Curvature 1 (max)\"" << std::endl;     // The name of the view
  outfile << "1"             << std::endl;     // One real tag
  outfile << "0.0"           << std::endl;     // The time value
  outfile << "3"             << std::endl;     // Three integer tags
  outfile << "0"             << std::endl;     // The time step (time steps always start at 0)
  outfile << "1"             << std::endl;     // 1-component (scalar) field
  outfile << _VertexToInt.size() << std::endl; // How many associated nodal values

  std::map<int,int>::const_iterator vertex_iterator;
  for(vertex_iterator = _VertexToInt.begin(); vertex_iterator != _VertexToInt.end(); ++vertex_iterator)
  {
    outfile << vertex_iterator->first << " " << _curv1[vertex_iterator->second] << std::endl;
  }

  outfile << "$EndNodeData" << std::endl;


  /// Write the values of curvature 2 (min)
  outfile << "$MeshFormat"    << std::endl;
  outfile << "2.1 0 8"        << std::endl;
  outfile << "$EndMeshFormat" << std::endl;
  outfile << "$NodeData" << std::endl;
  outfile << "1" << std::endl;                 // One string tag
  outfile << "\"Curvature 2 (min)\"" << std::endl;     // The name of the view
  outfile << "1"             << std::endl;     // One real tag
  outfile << "0.0"           << std::endl;     // The time value
  outfile << "3"             << std::endl;     // Three integer tags
  outfile << "0"             << std::endl;     // The time step (time steps always start at 0)
  outfile << "1"             << std::endl;     // 1-component (scalar) field
  outfile << _VertexToInt.size() << std::endl; // How many associated nodal values


  for(vertex_iterator = _VertexToInt.begin(); vertex_iterator != _VertexToInt.end(); ++vertex_iterator)
  {
    outfile << vertex_iterator->first << " " << _curv2[vertex_iterator->second] << std::endl;
  }

  outfile << "$EndNodeData" << std::endl;


  /// Write the values of characteristic length

  double lc;

  outfile << "$MeshFormat"    << std::endl;
  outfile << "2.1 0 8"        << std::endl;
  outfile << "$EndMeshFormat" << std::endl;
  outfile << "$NodeData" << std::endl;
  outfile << "1" << std::endl;                 // One string tag
  outfile << "\"Characteristic mesh length\"" << std::endl;     // The name of the view
  outfile << "1"             << std::endl;     // One real tag
  outfile << "0.0"           << std::endl;     // The time value
  outfile << "3"             << std::endl;     // Three integer tags
  outfile << "0"             << std::endl;     // The time step (time steps always start at 0)
  outfile << "1"             << std::endl;     // 1-component (scalar) field
  outfile << _VertexToInt.size() << std::endl; // How many associated nodal values

  for(vertex_iterator = _VertexToInt.begin(); vertex_iterator != _VertexToInt.end(); ++vertex_iterator)
  {
    lc = 2.0*M_PI/( fabs(_VertexCurve[vertex_iterator->second]) * CTX::instance()->mesh.minCircPoints );
    lc = std::max(lc, CTX::instance()->mesh.lcMin);
    lc = std::min(lc, CTX::instance()->mesh.lcMax);
    //outfile << vertex_iterator->first << " " << 1.0/(lc*lc) << std::endl;
    outfile << vertex_iterator->first << " " << lc << std::endl;
  }

  outfile << "$EndNodeData" << std::endl;

  /// Write the values of curvature direction - principal direction 1
  outfile << "$NodeData" << std::endl;
  outfile << "1" << std::endl;                 // One string tag
  outfile << "\"Principal curvature direction 1\"" << std::endl;     // The name of the view
  outfile << "1"             << std::endl;     // One real tag
  outfile << "0.0"           << std::endl;     // The time value
  outfile << "3"             << std::endl;     // Three integer tags
  outfile << "0"             << std::endl;     // The time step (time steps always start at 0)
  outfile << "3"             << std::endl;     // 3-component (vector) field
  outfile << _VertexToInt.size() << std::endl; // How many associated nodal values

  for(vertex_iterator = _VertexToInt.begin(); vertex_iterator != _VertexToInt.end(); ++vertex_iterator)
  {
    outfile << vertex_iterator->first << " " << _pdir1[vertex_iterator->second].x() << " "
                                             << _pdir1[vertex_iterator->second].y() << " "
                                             << _pdir1[vertex_iterator->second].z() << std::endl;
  }

  outfile << "$EndNodeData" << std::endl;


  /// Write the values of curvature direction - principal direction 2
  outfile << "$NodeData" << std::endl;
  outfile << "1" << std::endl;                 // One string tag
  outfile << "\"Principal curvature direction 2\"" << std::endl;     // The name of the view
  outfile << "1"             << std::endl;     // One real tag
  outfile << "0.0"           << std::endl;     // The time value
  outfile << "3"             << std::endl;     // Three integer tags
  outfile << "0"             << std::endl;     // The time step (time steps always start at 0)
  outfile << "3"             << std::endl;     // 3-component (vector) field
  outfile << _VertexToInt.size() << std::endl; // How many associated nodal values

  for(vertex_iterator = _VertexToInt.begin(); vertex_iterator != _VertexToInt.end(); ++vertex_iterator)
  {
    outfile << vertex_iterator->first << " " << _pdir2[vertex_iterator->second].x() << " "
                                             << _pdir2[vertex_iterator->second].y() << " "
                                             << _pdir2[vertex_iterator->second].z() << std::endl;
  }

  outfile << "$EndNodeData" << std::endl;

  outfile.close();


}

//========================================================================================================

void Curvature::writeToPosFile( const std::string & filename)
{
  std::ofstream outfile;
  outfile.precision(18);
  outfile.open(filename.c_str());
  outfile << "View \"Curvature \"{" << std::endl;

  int idxelem = 0;

  for (unsigned int i = 0; i< _EntityArray.size(); ++i) {
    GFace* face = _EntityArray[i];

    for (unsigned iElem = 0; iElem < face->getNumMeshElements(); iElem++){
      MElement *e = face->getMeshElement(iElem);  
      //const int E = _ElementToInt[e->getNum()]; 
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

//      outfile << _VertexNormal[V1].x() << ","<< _VertexNormal[V1].y() << ","<< _VertexNormal[V1].z() << ",";
//      outfile << _VertexNormal[V2].x() << ","<< _VertexNormal[V2].y() << ","<< _VertexNormal[V2].z() << ",";
//      outfile << _VertexNormal[V3].x() << ","<< _VertexNormal[V3].y() << ","<< _VertexNormal[V3].z();

      outfile << _VertexCurve[V1] << "," << _VertexCurve[V2] << "," << _VertexCurve[V3];

      outfile << "};" << std::endl;

      idxelem++;

  } //Loop over elements
 
} // Loop over ptFinalEntityList

outfile << "};" << std::endl;

outfile.close();
}

//========================================================================================================

void Curvature::writeToVtkFile( const std::string & filename)
{

  std::ofstream outfile;
  outfile.precision(18);
  outfile.open(filename.c_str());
  outfile << "# vtk DataFile Version 2.0" << std::endl;
  outfile << "Surface curvature computed by Gmsh" << std::endl;
  outfile << "ASCII" << std::endl;
  outfile << "DATASET UNSTRUCTURED_GRID" << std::endl;

  const int npoints = _VertexToInt.size();

  outfile << "POINTS " << npoints << " double" << std::endl;

  /// Build a table of coordinates
  /// Loop over all elements and look at the 'old' (not necessarily continuous) numbers of vertices
  /// Get the 'new' index of each vertex through _VertexToInt and the [x,y,z] coordinates of this vertex
  /// Store them in coordx,coordy and coordz


  std::vector<VtkPoint> coord;

  coord.resize(npoints);

  for (unsigned int i = 0; i< _EntityArray.size(); ++i)
  {
    GFace* face = _EntityArray[i];

    for (unsigned int iElem = 0; iElem < face->getNumMeshElements(); iElem++)
    {
      MElement *e = face->getMeshElement(iElem);

      MVertex* A = e->getVertex(0);  //Pointers to vertices of triangle
      MVertex* B = e->getVertex(1);
      MVertex* C = e->getVertex(2);

      const int oldIdxA = A->getNum();
      const int oldIdxB = B->getNum();
      const int oldIdxC = C->getNum();

      const int newIdxA = _VertexToInt[oldIdxA];
      const int newIdxB = _VertexToInt[oldIdxB];
      const int newIdxC = _VertexToInt[oldIdxC];

      coord[newIdxA].x = A->x();
      coord[newIdxA].y = A->y();
      coord[newIdxA].z = A->z();

      coord[newIdxB].x = B->x();
      coord[newIdxB].y = B->y();
      coord[newIdxB].z = B->z();

      coord[newIdxC].x = C->x();
      coord[newIdxC].y = C->y();
      coord[newIdxC].z = C->z();
    }
  }

  for (int v = 0; v < npoints; ++v)
  {
    outfile << coord[v].x << " " << coord[v].y << " " << coord[v].z << std::endl;
  }

  /// Empty the array 'coord' to free the memory
  /// Point coordinates will not be needed anymore
  coord.clear();

  /// Write the cell connectivity

  outfile << std::endl << "CELLS " << _ElementToInt.size() << " " << 4*_ElementToInt.size() << std::endl;

  for (unsigned int i = 0; i< _EntityArray.size(); ++i)
  {
    GFace* face = _EntityArray[i];

    for (unsigned int iElem = 0; iElem < face->getNumMeshElements(); iElem++)
    {
      MElement *e = face->getMeshElement(iElem);

      MVertex* A = e->getVertex(0);  //Pointers to vertices of triangle
      MVertex* B = e->getVertex(1);
      MVertex* C = e->getVertex(2);

      const int oldIdxA = A->getNum();
      const int oldIdxB = B->getNum();
      const int oldIdxC = C->getNum();

      const int newIdxA = _VertexToInt[oldIdxA];
      const int newIdxB = _VertexToInt[oldIdxB];
      const int newIdxC = _VertexToInt[oldIdxC];

      outfile << "3 " << newIdxA << " " << newIdxB << " " << newIdxC << std::endl;
    }
  }

  outfile << std::endl << "CELL_TYPES " << _ElementToInt.size() << std::endl;
  for(unsigned int ie = 0; ie < _ElementToInt.size(); ++ie)
  {
    outfile << "5" << std::endl; //Triangle is element type 5 in vtk

  }

  /// Write the curvature values as vtk 'point data'

  outfile << std::endl << "POINT_DATA " << npoints << std::endl;
  outfile << "SCALARS Curvature float 1" << std::endl;
  outfile << "LOOKUP_TABLE default" << std::endl;

  for (int iv = 0; iv < npoints; ++iv)
  {
    outfile << _VertexCurve[iv] << std::endl;
  }

  outfile << "SCALARS CharacteristicMeshLength float 1" << std::endl;
  outfile << "LOOKUP_TABLE default" << std::endl;

  double lc;

  for (int iv = 0; iv < npoints; ++iv)
  {
    lc = 2.0*M_PI / ( fabs(_VertexCurve[iv]) * CTX::instance()->mesh.minCircPoints );
    lc = std::max(lc, CTX::instance()->mesh.lcMin);
    lc = std::min(lc, CTX::instance()->mesh.lcMax);
    //outfile << 1.0/(lc*lc) << std::endl;
    outfile << lc << std::endl;
  }

  outfile << "VECTORS CurvatureDir1 float" << std::endl;
  for (int iv = 0; iv < npoints; ++iv)
  {
    outfile << _pdir1[iv].x() << " " << _pdir1[iv].y() << " " << _pdir1[iv].z() << std::endl;
  }

  outfile << "VECTORS CurvatureDir2 float" << std::endl;
  for (int iv = 0; iv < npoints; ++iv)
  {
    outfile << _pdir2[iv].x() << " " << _pdir2[iv].y() << " " << _pdir2[iv].z() << std::endl;
  }

  outfile.close();

}

//========================================================================================================

void Curvature::writeDirectionsToPosFile( const std::string & filename)
{
  std::ofstream outfile;
  outfile.precision(18);
  outfile.open(filename.c_str());
  outfile << "View \"Curvature_DirMax \"{" << std::endl;

  for (unsigned int i = 0; i< _EntityArray.size(); ++i)
  {
    GFace* face = _EntityArray[i]; //face is a pointer to one surface of the group "FinalEntityList"

    for (unsigned int iElem = 0; iElem < face->getNumMeshElements(); iElem++) //Loop over the element all the element of the "myTag"-surface
    {
      MElement *e = face->getMeshElement(iElem);  //Pointer to one element

      //const int E = _ElementToInt[e->getNum()]; //The NEW tag of the corresponding element
      //std::cout << "We are now looking at element Nr: " << E << std::endl;

      MVertex* A = e->getVertex(0);  //Pointers to vertices of triangle
      MVertex* B = e->getVertex(1);
      MVertex* C = e->getVertex(2);

      const int V1 = _VertexToInt[A->getNum()];                //Tag of the 1st vertex of the triangle
      const int V2 = _VertexToInt[B->getNum()];                //Tag of the 2nd vertex of the triangle
      const int V3 = _VertexToInt[C->getNum()];                //Tag of the 3rd vertex of the triangle

      //Here is printing the triplet X-Y-Z of each vertex:
      //*************************************************

      outfile << "VT("; //VT = vector triangles   //ST = scalar triangle
      outfile << A->x() << ","<< A->y() << "," << A->z()<< ",";
      outfile << B->x() << ","<< B->y() << "," << B->z()<< ",";
      outfile << C->x() << ","<< C->y() << "," << C->z();

      outfile << ")";
      outfile <<"{";

      //Here is printing the 3 components of the curvature max direction for each vertex:
      //*********************************************************************************

         outfile << _pdir1[V1].x() << ","<< _pdir1[V1].y() << ","<< _pdir1[V1].z() << ",";
         outfile << _pdir1[V2].x() << ","<< _pdir1[V2].y() << ","<< _pdir1[V2].z() << ",";
         outfile << _pdir1[V3].x() << ","<< _pdir1[V3].y() << ","<< _pdir1[V3].z();


      outfile << "};" << std::endl;

  } //Loop over elements

} // Loop over ptFinalEntityList

outfile << "};" << std::endl;


//----------------------------------------------------------------------------------------------

outfile << "View \"Curvature_DirMin \"{" << std::endl;

for (unsigned int i = 0; i< _EntityArray.size(); ++i)
{
  GFace* face = _EntityArray[i]; //face is a pointer to one surface of the group "FinalEntityList"

  for (unsigned int iElem = 0; iElem < face->getNumMeshElements(); iElem++) //Loop over the element all the element of the "myTag"-surface
  {
    MElement *e = face->getMeshElement(iElem);  //Pointer to one element

    //const int E = _ElementToInt[e->getNum()]; //The NEW tag of the corresponding element
    //std::cout << "We are now looking at element Nr: " << E << std::endl;

    MVertex* A = e->getVertex(0);  //Pointers to vertices of triangle
    MVertex* B = e->getVertex(1);
    MVertex* C = e->getVertex(2);

    const int V1 = _VertexToInt[A->getNum()];                //Tag of the 1st vertex of the triangle
    const int V2 = _VertexToInt[B->getNum()];                //Tag of the 2nd vertex of the triangle
    const int V3 = _VertexToInt[C->getNum()];                //Tag of the 3rd vertex of the triangle

    //Here is printing the triplet X-Y-Z of each vertex:
    //*************************************************

    outfile << "VT("; //VT = vector triangles   //ST = scalar triangle
    outfile << A->x() << ","<< A->y() << "," << A->z()<< ",";
    outfile << B->x() << ","<< B->y() << "," << B->z()<< ",";
    outfile << C->x() << ","<< C->y() << "," << C->z();

    outfile << ")";
    outfile <<"{";

    //Here is printing the 3 components of the curvature min direction for each vertex:
    //*********************************************************************************

       outfile << _pdir2[V1].x() << ","<< _pdir2[V1].y() << ","<< _pdir2[V1].z() << ",";
       outfile << _pdir2[V2].x() << ","<< _pdir2[V2].y() << ","<< _pdir2[V2].z() << ",";
       outfile << _pdir2[V3].x() << ","<< _pdir2[V3].y() << ","<< _pdir2[V3].z();


    outfile << "};" << std::endl;

} //Loop over elements

} // Loop over ptFinalEntityList

outfile << "};" << std::endl;

outfile.close();
}
//========================================================================================================



