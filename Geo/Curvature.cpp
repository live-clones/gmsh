// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Curvature.h"
#include "MElement.h"

#include<iostream>
#include<fstream>
#include<cmath>

#define NEXT(i) ((i)<2 ? (i)+1 : (i)-2)
#define PREV(i) ((i)>0 ? (i)-1 : (i)+2)

//std::cout << "NEXT(1) = " << NEXT(1) << std::endl;
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

//COMPUTE THE NORMAL AT THE VERTEX AND THE AREA AROUND

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

// Compute per-vertex point areas
void Curvature::computePointareas()
{

//    if (_pointareas.size() == _VertexToInt.size())
//        return;
//        need_faces();

    std::cout << "Computing point areas... " << std::endl;
//    std::cout << "The mesh has " << _VertexToInt.size() << " nodes" << std::endl;

    SVector3 e[3];
    SVector3 l2;
    SVector3 ew;

    _pointareas.resize(_VertexToInt.size());
    _cornerareas.resize(_ElementToInt.size());


    for (int i = 0; i< _ptFinalEntityList.size(); ++i)
    {
      GEntity* entity = _ptFinalEntityList[i]; //entity is a pointer to one surface of the group "FinalEntityList"

      for (int iElem = 0; iElem < entity->getNumMeshElements(); iElem++) //Loop over the element all the element of the "myTag"-surface
      {
          MElement *E = entity->getMeshElement(iElem);  //Pointer to one element
          // The NEW tag of the corresponding element
          const int EIdx = _ElementToInt[E->getNum()];

          MVertex* A = E->getVertex(0);  //Pointers to vertices of triangle
          MVertex* B = E->getVertex(1);
          MVertex* C = E->getVertex(2);

          //Edges
          e[0] = SVector3(C->x() - B->x(), C->y() - B->y(), C->z() - B->z()); //vector side of a triangilar element
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

          const int V0 = _VertexToInt[A->getNum()];
          const int V1 = _VertexToInt[B->getNum()];
          const int V2 = _VertexToInt[C->getNum()];

          _pointareas[V0] += _cornerareas[EIdx][0];
          //_pointareas[faces[i][0]] += _cornerareas[i][0];

          _pointareas[V1] += _cornerareas[EIdx][1];

          _pointareas[V2] += _cornerareas[EIdx][2];

      }//End of loop over iElem

      std::cout << "Done computing pointareas" << std::endl;
//      std::cout << "_pointareas.size = " << _pointareas.size() << std::endl;
//      std::cout << "_cornerareas.size = " << _cornerareas.size() << std::endl;

    }//End of loop over _ptFinalEntityList

}//End of the method "computePointareas"


//========================================================================================================

//Rotate a coordinate system to be perpendicular to the given normal

void Curvature::rot_coord_sys(const SVector3 &old_u, const SVector3 &old_v, const SVector3 &new_norm, SVector3 &new_u, SVector3 &new_v)
{
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
  }//end of if-condtion

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
                          double &new_ku, double &new_kuv, double &new_kv)
{
  SVector3 r_new_u;
  SVector3 r_new_v;
  rot_coord_sys(new_u, new_v, crossprod(old_u,old_v), r_new_u, r_new_v);

  double u1 = dot(r_new_u, old_u);
  double v1 = dot(r_new_u, old_v);
  double u2 = dot(r_new_v, old_u);
  double v2 = dot(r_new_v, old_v);

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
                      SVector3 &pdir1, SVector3 &pdir2, double &k1, double &k2)
{
  SVector3 r_old_u;
  SVector3 r_old_v;

  double c = 1.0;
  double s = 0.0;
  double tt = 0.0;

  rot_coord_sys(old_u, old_v, new_norm, r_old_u, r_old_v);

//  if(unlikely(kuv !=0.0f))
  if(kuv !=0.0)
  {
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

  if(std::abs(k1) >= std::abs(k2))
  {
    pdir1 = c*r_old_u - s*r_old_v;
  }
  else
  {
    std::swap(k1,k2);
    pdir1 = s*r_old_u + c*r_old_v;
  }
  pdir2 = crossprod(new_norm, pdir1);
}

//========================================================================================================

void Curvature::computeCurvature_Rusinkiewicz()
{
  initializeMap();
  computeVertexNormals();
  computePointareas();

  SVector3 e[3];
  STensor3 w;
  SVector3 t;
  SVector3 n;
  SVector3 b;
  SVector3 m;
  SVector3 dn;

  int vj;

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



  std::cout << "Computing Curvature.." << std::endl;

  for (int i = 0; i< _ptFinalEntityList.size(); ++i)
  {
    GEntity* entity = _ptFinalEntityList[i]; //entity is a pointer to one surface of the group "FinalEntityList"

    for (int iElem = 0; iElem < entity->getNumMeshElements(); iElem++) //Loop over the element all the element of the "myTag"-surface
    {
      MElement *E = entity->getMeshElement(iElem);  //Pointer to one element

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

    for (int ivertex = 0; ivertex < _VertexToInt.size(); ++ivertex)
    {
      _pdir1[ivertex] = crossprod(_pdir1[ivertex], _VertexNormal[ivertex]);
      _pdir1[ivertex].normalize();
      _pdir2[ivertex] = crossprod(_VertexNormal[ivertex], _pdir1[ivertex]);
    }

    // Compute curvature per face:
    for (int i = 0; i< _ptFinalEntityList.size(); ++i)
    {
      GEntity* entity = _ptFinalEntityList[i]; //entity is a pointer to one surface of the group "FinalEntityList"
      for (int iElem = 0; iElem < entity->getNumMeshElements(); iElem++) //Loop over the element all the element of the "myTag"-surface
      {
        MElement *E = entity->getMeshElement(iElem);  //Pointer to one element
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

        //Least Square Solution
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

          _curv1[vj] += wt*c1;
          _curv12[vj] += wt*c12;
          _curv2[vj] += wt*c2;

        }

    } //End of loop over the element (iElem)

  } //End of loop over "_ptFinalEntityList"


    //Compute principal directions and curvatures at each vertex
    for (int ivertex = 0; ivertex < _VertexToInt.size(); ++ivertex)
    {
        diagonalize_curv(_pdir1[ivertex], _pdir2[ivertex], _curv1[ivertex], _curv12[ivertex], _curv2[ivertex],
                         _VertexNormal[ivertex], _pdir1[ivertex], _pdir2[ivertex], _curv1[ivertex], _curv2[ivertex]);
    }

    std::cout << "Done" << std::endl;

    _VertexCurve.resize( _VertexToInt.size() );

    for (int ivertex = 0; ivertex < _VertexToInt.size(); ++ivertex)
    {
        _VertexCurve[ivertex] = (_curv1[ivertex]+_curv2[ivertex])*0.5;

    }

} //End of the "computeCurvature_Rusinkiewicz" method


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


