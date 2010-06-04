//
// Description : Filters for function space dof selection
//
//
// Author:  <Eric Bechet>::<Boris Sedji>,  02/2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "filters.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MLine.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MElementCut.h"
#include "MElement.h"

void FilterLevelSetForLagMultSpace::SortNodes (void)
{
		
		std::set< EdgeType > Se; // edges
		std::set< NodeType > Sn; // level set nodes kept
		std::map < NodeType, int > NodesScore;
		std::map < NodeType , EdgeType > NodeToEdgeMap;
		std::set< NodeType >::iterator itn;
		
		// initialization
		fillNodeToEdgeMap (NodeToEdgeMap,Se,Sn);
		
		//-- decimation algorithm --
		
		
		while (!Sn.empty())
		{
		// compute score of Sn
		ComputeScore(NodeToEdgeMap,Se,Sn,NodesScore);
		// take the lowest score
		NodeType v = getNodeWithLowestScore(NodesScore);
		// if NOT marked as looser then it s a winner
		if (_looser_nodes.find(v) != _looser_nodes.end()) _winner_nodes.insert(v);
		// kill all connected edges and nodes (then mark them as loosers)
		killConnectedEdges (NodeToEdgeMap,Se,Sn,v);
		}
		
		
}

void FilterLevelSetForLagMultSpace::fillNodeToEdgeMap(std::map < NodeType , EdgeType > & NodeToEdgeMap, std::set< EdgeType > & Se , std::set< NodeType > & Sn)
{
	std::set<MElement*>::const_iterator it = _LevelSetElements->begin();
	for (; it != _LevelSetElements->end(); it++)
		{
			MElement *e = *it;
			for (int i = 0 ; i < e->getNumVertices() ; i ++)  // warning getnumvertices polygon : vertices + inner ?
			{
				NodeType v = e->getVertex(i);
				EdgeType edge = findEdge(v,e);
				Sn.insert(v);
				Se.insert(edge);
				NodeToEdgeMap[v] = edge; 
			}
		}
}

std::pair <MVertex * , MVertex * > FilterLevelSetForLagMultSpace::findEdge(NodeType v, MElement * e)
{
	MElement *ep;
	if (e->getParent()) ep = e->getParent();
	switch (ep->getType())
	{
		case TYPE_TRI :
		{
			EdgeType edge;
			for (int i = 0 ; i < 3 ; i ++)  // for all edges
			{
				int n1,n2;
				n1 = i;
				n2 = (i+1)%3;
				// if it s an element vertex
				if (v->getNum() == ep->getVertex(n1)->getNum())
				{ 
					edge = EdgeType (ep->getVertex(n1),ep->getVertex(n1));
					return edge;
				}
				if (v->getNum() == ep->getVertex(n2)->getNum())
				{
					edge = EdgeType (ep->getVertex(n2),ep->getVertex(n2));
					return edge;
				}
				// else if it s not an element vertex
				edge = EdgeType(ep->getVertex(n1),ep->getVertex(n2));  
			  if (NodeBelongToEdge(v,edge)) return edge;
			}
		}
		case TYPE_QUA :
		{
			EdgeType edge;
			for (int i = 0 ; i < 4 ; i ++)  // for all edges
			{
				int n1,n2;
				n1 = i;
				n2 = (i+1)%4;
				// if it s an element vertex
				if (v->getNum() == ep->getVertex(n1)->getNum())
				{ 
					edge = EdgeType (ep->getVertex(n1),ep->getVertex(n1));
					return edge;
				}
				if (v->getNum() == ep->getVertex(n2)->getNum())
				{
					edge = EdgeType (ep->getVertex(n2),ep->getVertex(n2));
					return edge;
				}
				// else if it s not an element vertex
				edge = EdgeType(ep->getVertex(n1),ep->getVertex(n2));  
			  if (NodeBelongToEdge(v,edge)) return edge;
			}
		}
		case TYPE_TET :
		{
			int tab[6][2] = {{0, 1}, {0, 3}, {0, 2}, {1, 2}, {2, 3}, {3, 1}};  // edges
			EdgeType edge;
			for (int i = 0 ; i < 6 ; i ++)  // for all edges
			{
				int n1,n2;
				n1 = tab[i][0];
				n2 = tab[i][1];
				// if it s an element vertex
				if (v->getNum() == ep->getVertex(n1)->getNum())
				{ 
					edge = EdgeType (ep->getVertex(n1),ep->getVertex(n1));
					return edge;
				}
				if (v->getNum() == ep->getVertex(n2)->getNum())
				{
					edge = EdgeType (ep->getVertex(n2),ep->getVertex(n2));
					return edge;
				}
				// else if it s not an element vertex
				edge = EdgeType(ep->getVertex(n1),ep->getVertex(n2));  
			  if (NodeBelongToEdge(v,edge)) return edge;
			}
		}
		case TYPE_HEX :
		{
			int tab[12][2] = {{0, 1}, {0, 4}, {0, 3}, {1, 2}, {1, 5},
			                  {2, 3},{2,6},{3, 7}, {4, 7}, {4, 5},{5, 6},{6, 7}};// edges
			EdgeType edge;
			for (int i = 0 ; i < 12 ; i ++)  // for all edges
			{
				int n1,n2;
				n1 = tab[i][0];
				n2 = tab[i][1];
				// if it s an element vertex
				if (v->getNum() == ep->getVertex(n1)->getNum())
				{ 
					edge = EdgeType (ep->getVertex(n1),ep->getVertex(n1));
					return edge;
				}
				if (v->getNum() == ep->getVertex(n2)->getNum())
				{
					edge = EdgeType (ep->getVertex(n2),ep->getVertex(n2));
					return edge;
				}
				// else if it s not an element vertex
				edge = EdgeType(ep->getVertex(n1),ep->getVertex(n2));  
			  if (NodeBelongToEdge(v,edge)) return edge;
			}
		}
		default : std::cout << "findEdge warning..." << std::endl;
	}
}


bool FilterLevelSetForLagMultSpace::NodeBelongToEdge(NodeType v, EdgeType edge)
{
	
	double eps = 1e-10;
	
	double distn, edgelength;
	
	edgelength = edge.first->distance(edge.second);
	distn = v->distance(edge.first) + v->distance(edge.second);
	
	if (std::abs(edgelength - distn) < eps) return true;
	else return false;
	
}


void FilterLevelSetForLagMultSpace::ComputeScore(
std::map < NodeType , EdgeType > & NodeToEdgeMap, std::set< EdgeType > & Se, std::set< NodeType > & Sn, std::map < NodeType , int > & NodesScore)
{
	NodesScore.clear();
	std::set < NodeType >::iterator it = Sn.begin();
  for (;it!=Sn.end();it++)
	{
		int score;
		EdgeType edge;
		edge = NodeToEdgeMap[(*it)];
		if (edge.first->getNum() == edge.second->getNum()) score = 0;  // regular mesh nodes score
		else score = ComputeIncidentEdges(Se,edge.first) + ComputeIncidentEdges(Se,edge.second);
		NodesScore[(*it)] = score;
	}
}


int FilterLevelSetForLagMultSpace::ComputeIncidentEdges(std::set< EdgeType > & Se, NodeType & v)
{
	int n = 0;
	std::set < EdgeType >::iterator it = Se.begin();
  for (;it!=Se.end();it++)
	{
		if ((*it).first == v | (*it).second == v) n++;
	}
	return n;
}


MVertex * FilterLevelSetForLagMultSpace::getNodeWithLowestScore(std::map < NodeType , int > & NodesScore)
{
	NodeType v;
	std::map < NodeType , int >::iterator it = NodesScore.begin();
	v = (*it).first;
	for (;it!=NodesScore.end() ; it ++)
	{
		if ((*it).second < NodesScore[v]) v = (*it).first ;
	}
	return v;
}

void FilterLevelSetForLagMultSpace::killConnectedEdges (std::map < NodeType , EdgeType > & NodeToEdgeMap, std::set< EdgeType > & Se , std::set< NodeType > & Sn, NodeType v)
{
	
	std::vector < EdgeType > EdgesToErase;
	std::vector < NodeType > NodesToErase;
	
	NodeType v1 = NodeToEdgeMap[v].first;
	NodeType v2 = NodeToEdgeMap[v].second;
	
	std::set < EdgeType >::iterator ite = Se.begin();
  for (;ite!=Se.end();ite++)
	{
		if ((*ite).first == v1 | (*ite).second == v1) EdgesToErase.push_back(*ite);
		if ((*ite).first == v2 | (*ite).second == v2) EdgesToErase.push_back(*ite);
	}
	for (int i = 0 ; i < EdgesToErase.size() ; i ++)
	{
		Se.erase(EdgesToErase[i]);
	}
	
	
	std::set < NodeType >::iterator itn = Sn.begin();
	for (; itn != Sn.end() ; itn ++)
	{
	  if (Se.find(NodeToEdgeMap[(*itn)]) == Se.end()) NodesToErase.push_back(*itn);
	}
	for (int i = 0 ; i < NodesToErase.size() ; i ++)
	{
		if (NodesToErase[i]->getNum() != v->getNum()) _looser_nodes.insert(NodesToErase[i]);
		Sn.erase(NodesToErase[i]);
	}
	
}

