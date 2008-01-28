// $Id: PViewDataGModel.cpp,v 1.7 2008-01-28 09:59:52 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

/*
add new optional field in .msh file to store

- node or element post-pro data
- one field per-time step, per view

$Data
name precision-single-double step time-value
type node-or-ele-id num-comp val (num-comp times)
type node-or-ele-id num-comp val (num-comp times)
...
$EndData

Then?

1) in MVertex and MElement, add

std::vector<std::vector<double> > _scalar, _vector, _tensor;

and access using e.g. _scalar[viewIndex][comp & time step]. In GModel
we would store a map with the correspondance between the index and the
unique view id created in PView().

2) Or, we store directly a map indexed with the unique view id

1) and 2) are pretty expensive, due to the overhead and the "micro"
allocations (in each element/node)

3) It might be better to store the data *per entity*?

4) Or just store the big vectors in the GModel?

My preference at the moment is to store per entity (i.e., (3)): not
too much overhead; can do local indexing and checks with
nodes/elements--which are stored per entity too; avoids storing entity
ptr in each value (I think we should have that info in the post-pro:
it's one of the annoying shortcomings of the old format)

if we choose 3, unfortunately, we need to keep track of some local
indices to access the data with a single, continuous index. This is
exactly the same problem as with PViewDataList. Maybe it's worth it?

if we choose 4, we could have e.g. vectors of map<MVertex*, data> and
map<MElement*, data>. The overhead is not negligeable... but it would
be *very* simple to implement and maintain (very easy to load/discard
time steps on the fly, do I/O; and the storage is completely separate
from the model; it's good for handling errors too: when we loop over
nodes/elements to generate vertex arrays, we just query the maps: if
no answer, that's it).


5) store 2 hash_maps in PViewDataGModel: one for vertices, one for
elements. Each entry in the hash_map is an array of size

[num_time_steps_stored * max_num_values]

where

* num_time_steps_stored is either num_time_steps (by default) or some
user-set default (so that we do not have to load all the time steps at
once)

* max_num_values??


*/

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

