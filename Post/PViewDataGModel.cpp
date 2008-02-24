// $Id: PViewDataGModel.cpp,v 1.15 2008-02-24 16:18:19 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
// 

#include "PViewDataGModel.h"
#include "Message.h"

PViewDataGModel::PViewDataGModel(GModel *model) : _model(model)
{
  /* 
     store linear vector of GEntity* (index in that vector used for
     all element access later)

     create a vector (one entry per time step) of 

     class data{
       // nodes       components
       std::vector< std::vector<double > >
     }

     When reading a .msh file:

     * get node number in file
     * get vertex pointer from _model->_vertexCache
     * if MVertex 
         has no dataIndex, increment it (need global value stored in GModel)
         it has one, do nothing
     * fill the dataIndex entry in data{}



     .msh file format:

     $NodeData
     name precision-single-double step time-value
     type node-or-ele-id num-comp val (num-comp times)
     type node-or-ele-id num-comp val (num-comp times)
     ...
     $EndNodeData

     number of time steps stored should be an option. should be able
     to dynamically load/overwrite time step when reading new one
  */
}

PViewDataGModel::~PViewDataGModel()
{

}

double PViewDataGModel::getTime(int step)
{
  return 0;
}

double PViewDataGModel::getMin(int step)
{
  return 0;
}

double PViewDataGModel::getMax(int step)
{
  return 1;
}

int PViewDataGModel::getNumEntities()
{
  return 0;
}

int PViewDataGModel::getNumElements(int ent)
{
  if(ent < 0)
    return _model->getNumMeshElements(); 
  else
    return 0; // TODO
}

int PViewDataGModel::getDimension(int ent, int ele)
{
  return 0; 
}

int PViewDataGModel::getNumNodes(int ent, int ele)
{
  return 0; 
}

void PViewDataGModel::getNode(int ent, int ele, int nod, double &x, double &y, double &z)
{
}

int PViewDataGModel::getNumComponents(int ent, int ele)
{
  return 1; 
}

void PViewDataGModel::getValue(int ent, int ele, int node, int comp, int step, double &val)
{

}

int PViewDataGModel::getNumEdges(int ent, int ele)
{ 
  return 0; 
}

bool PViewDataGModel::skipEntity(int ent)
{
  return false;
}

bool PViewDataGModel::skipElement(int ent, int ele)
{
  return false;
}

bool PViewDataGModel::readMSH(FILE *fp)
{
  Msg(INFO, "Filling PViewDataGModel...");
  
  MVertex *v =  _model->getMeshVertexByTag(10);
  if(v){
    printf("vertex 10 in mesh is %p\n", v);
  }

  return false;
}

bool PViewDataGModel::writePOS(std::string name, bool binary, bool parsed,
			       bool append)
{
  // model->writePOS()
  return false;
}

bool PViewDataGModel::writeSTL(std::string name)
{
  // model->writeSTL()
  return false;
}

bool PViewDataGModel::writeTXT(std::string name)
{
  // model->writeTXT()
  return false;
}

bool PViewDataGModel::writeMSH(std::string name)
{
  // model->writeMSH()
  return false;
}
