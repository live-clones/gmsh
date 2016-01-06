// Gmsh - Copyright (C) 1997-2016 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _FILTER_OVERLAPPING_ELEMENTS_
#define _FILTER_OVERLAPPING_ELEMENTS_

#include <map>
#include <vector>

class MElement;
class MPrism;
class MHexahedron;
class MTriangle;
class MQuadrangle;

void filterOverlappingElements(std::vector<MElement*> &,
                               std::map<MElement*,std::vector<MElement*> > &_elemColumns,
                               std::map<MElement*,MElement*> &_toFirst);
void filterOverlappingElements(std::vector<MPrism*> &blPrisms,
                               std::vector<MHexahedron*>&blHexes,
                               std::map<MElement*,std::vector<MElement*> > &_elemColumns,
                               std::map<MElement*,MElement*> &_toFirst);
void filterOverlappingElements(std::vector<MTriangle*> &blTris,
                               std::vector<MQuadrangle*>&blQuads,
                               std::map<MElement*,std::vector<MElement*> > &_elemColumns,
                               std::map<MElement*,MElement*> &_toFirst);
void filterColumns(std::vector<MElement*> &elem,
		   std::map<MElement*,std::vector<MElement*> > &_elemColumns);

#endif
