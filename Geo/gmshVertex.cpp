#include "GFace.h"
#include "gmshVertex.h"
#include "Geo.h"
#include "GeoInterpolation.h"
#include "Context.h"

SPoint2 gmshVertex::reparamOnFace ( GFace *face , int dir) const
{
  Surface *s = (Surface*) face->getNativePtr();


  if (s->Typ ==  MSH_SURF_REGL)
    {
      const double corners[4][2] = {{0,0},{0,1},{1,1},{1,0}};

      double U,V;
      Curve *C[4];
      int iPos;
      for(int i = 0; i < 4; i++) {
	List_Read(s->Generatrices, i, &C[i]);
      }


      if ((C[0]->beg == v && C[3]->beg == v) ||
	  (C[0]->end == v && C[3]->beg == v) ||
	  (C[0]->beg == v && C[3]->end == v) ||
	  (C[0]->end == v && C[3]->end == v))
	{
	  U = V = 0;
	}
      else if ((C[0]->beg == v && C[1]->beg == v) ||
	       (C[0]->end == v && C[1]->beg == v) ||
	       (C[0]->beg == v && C[1]->end == v) ||
	       (C[0]->end == v && C[1]->end == v))
	{
	  U = 1;
	  V = 0;
	}
      else if ((C[2]->beg == v && C[1]->beg == v) ||
	       (C[2]->end == v && C[1]->beg == v) ||
	       (C[2]->beg == v && C[1]->end == v) ||
	       (C[2]->end == v && C[1]->end == v))
	{
	  U = 1;
	  V = 1;
	}
      else if ((C[2]->beg == v && C[3]->beg == v) ||
	       (C[2]->end == v && C[3]->beg == v) ||
	       (C[2]->beg == v && C[3]->end == v) ||
	       (C[2]->end == v && C[3]->end == v))
	{
	  U = 0;
	  V = 1;
	}
      else
	throw;
//       GPoint p1 = point();
//       GPoint p2 = face->point(U,V);
      
//       printf("face %2d (%8.3f %8.3f) point %2d %8.3f %8.3f %8.3f vs %8.3f %8.3f %8.3f D = %8.3f\n",
// 	     face->tag(),U,V,
// 	     tag(),
// 	     p1.x(),p1.y(),p1.z(),p2.x(),p2.y(),p2.z(),
// 	     sqrt((p1.x()-p2.x())*(p1.x()-p2.x())+(p1.y()-p2.y())*(p1.y()-p2.y())+(p1.z()-p2.z())*(p1.z()-p2.z())));      



      return SPoint2(U,V);
    }
  else
    {
      return GVertex::reparamOnFace(face,dir);
    }
}
