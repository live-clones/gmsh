#include "meshGRegionDelaunayInsertion.h"
#include <set>
#include <algorithm>

int faces[4][3] = {{0,1,2},{0,2,3},{0,1,3},{1,2,3}};

struct faceXtet
{
  MVertex *v[3];
  MTet4 * t1;
  int i1;
  faceXtet ( MTet4 *_t, int iFac)
    : t1(_t),i1(iFac)
  {
    v[0] = t1->tet()->getVertex ( faces [iFac][0] );
    v[1] = t1->tet()->getVertex ( faces [iFac][1] );
    v[2] = t1->tet()->getVertex ( faces [iFac][2] );
    std::sort ( &v[0], &v[2] );
  }
  inline bool operator < ( const faceXtet & other) const
  {
    if (v[0] < other.v[0])return true;
    if (v[0] > other.v[0])return false;
    if (v[1] < other.v[1])return true;
    if (v[1] > other.v[1])return false;
    if (v[2] < other.v[2])return true;
    return false;
  }
};


void connectTets ( std::list<MTet4*> & tets)
{
  std::set<faceXtet> conn;
  {
    std::list<MTet4*>::iterator it = tets.begin ();
    while (it != tets.end())
      {
	for (int i=0;i<4;i++)
	  {
	    faceXtet fxt ( *it ,  i );
	    std::set<faceXtet>::iterator found = conn.find (fxt);
	    if (found == conn.end())
	      conn.insert ( fxt );
	    else
	      {
		found->t1->setNeigh(found->i1,*it);
	        (*it)->setNeigh ( i, found->t1);
	      }
	  }
	++it;
      }
  }
}


void recurFindCavity ( std::list<faceXtet> & shell, 
		       std::list<MTet4*> & cavity, 
		       MVertex *v , 
		       MTet4 *t)
{
  for (int i=0;i<4;i++)
    {
      MTet4 *neigh =  t->getNeigh(i) ;
      if ( neigh && neigh->inCircumSphere ( v ) )
	{
	  neigh->remove ();
	  cavity.push_back(neigh);
	  recurFindCavity ( shell, cavity,v , neigh);
	}
      else if (neigh)
	{
	  shell.push_back ( faceXtet ( neigh, i ) );
	}
    }
}

void insertVertex (std::set<MTet4*> allTets,
		   MVertex *v , 
		   MTet4   *t )
{
  std::list<faceXtet>  shell;
  std::list<MTet4*>  cavity; 
  std::list<MTet4*>  new_cavity; 
  t->remove();
  cavity.push_back(t);
  recurFindCavity ( shell,  cavity, v , t);
  
  std::list<faceXtet>::iterator it =   shell.begin();
  double newVolume = 0;
  double oldVolume = 0;

  std::list<MTet4*>::iterator ittet = cavity.begin();
  std::list<MTet4*>::iterator ittete = cavity.end();
  while ( ittet != ittete )
    {
      oldVolume += (*ittet)->getVolume();
      cavity.push_back ( *ittet );
      ++ittet;
    }

  while (it != shell.end())
    {
      MTetrahedron *t = new MTetrahedron ( it->v[0],
					   it->v[1],
					   it->v[2],
					   v);
      MTet4 *t4 = new MTet4 ( t ); 
      new_cavity.push_back (t4);
      new_cavity.push_back (it->t1);
      newVolume += t4->getVolume();
      ++it;
    }
  if (fabs(oldVolume - newVolume) < 1.e-10 * oldVolume )
    {      
      connectTets ( new_cavity );      
    }
  else
    {      
      connectTets ( cavity );      
    }
}
