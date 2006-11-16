#include "GEdgeLoop.h"
#include "Message.h"

void GEdgeSigned::print() const
{
  Msg(INFO,"GEdgeSigned : Edge %d sign %d Ordered Vertices %d,%d",ge->tag(),_sign,getBeginVertex()->tag(),getEndVertex()->tag());
}

int countInList ( std::list<GEdge*> &wire , GEdge *ge)
{
  std::list<GEdge*>::iterator it = wire.begin();
  std::list<GEdge*>::iterator ite = wire.end();
  int count = 0;
  while (it != ite)
    {
      if (*it == ge) count++; 
      ++it;
    }
  return count;
}

GEdgeSigned nextOne ( GEdgeSigned *thisOne, std::list<GEdge*> &wire)
{

  if (!thisOne)
    {
      GEdge *ge = *(wire.begin());
      wire.erase(wire.begin());
      return GEdgeSigned ( 1 , ge );   
    }

  GVertex *gv = thisOne->getEndVertex();

  std::list<GEdge*> possibleChoices;

  std::list<GEdge*>::iterator it = wire.begin();
  std::list<GEdge*>::iterator ite = wire.end();
  while (it != ite)
    {
      GEdge *ge = *it;
      GVertex *v1 = ge->getBeginVertex();
      GVertex *v2 = ge->getEndVertex();
      if (v1 == gv || v2 == gv)possibleChoices.push_back(ge);
      ++it;
    }
  it = possibleChoices.begin();
  ite = possibleChoices.end();
  while (it != ite)
    {
      GEdge *ge = *it;
      if (countInList (possibleChoices , ge) == 2)
	{
	  wire.erase(std::remove_if(wire.begin(),wire.end() , std::bind2nd(std::equal_to<GEdge*>(), ge)) , 
		 wire.end());
	  wire.push_back(ge);
	  GVertex *v1 = ge->getBeginVertex();
	  GVertex *v2 = ge->getEndVertex();
	  if (v1 == gv)return GEdgeSigned ( 1  , ge );   
	  if (v2 == gv)return GEdgeSigned ( -1 , ge );   
	  throw;
	}
      ++it;
    }
  it = possibleChoices.begin();
  ite = possibleChoices.end();
  while (it != ite)
    {
      GEdge *ge = *it;
      if (ge != thisOne->ge)
	{
	  wire.erase(std::remove_if(wire.begin(),wire.end() , std::bind2nd(std::equal_to<GEdge*>(), ge)) , 
		     wire.end());
	  GVertex *v1 = ge->getBeginVertex();
	  GVertex *v2 = ge->getEndVertex();
	  if (v1 == gv)return GEdgeSigned ( 1  , ge );   
	  if (v2 == gv)return GEdgeSigned ( -1 , ge );
	  throw;
	}   
      ++it;
    }
}

int  GEdgeLoop::count (GEdge* ge) const
{
  GEdgeLoop::citer it = begin();
  GEdgeLoop::citer ite = end();
  int count = 0;
  while (it != ite)
    {
      if (it->ge == ge) count++; 
      ++it;
    }
  return count;
}

GEdgeLoop::GEdgeLoop ( const std::list<GEdge*> & cwire )
{

  std::list<GEdge*> wire (cwire);

  GEdgeSigned *prevOne = 0;

  Msg(INFO,"Building a wire");
  GEdgeSigned ges(0,0);
  while (wire.size())
    {
      ges = nextOne ( prevOne , wire );
      prevOne = &ges;
      ges.print();
      loop.push_back(ges);
    }

}
