//
// group for interface element
//
// Description: Choose a function space. Can be integrated in functionSpace.h
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef FUNCTIONSPACETYPE_H_
#define FUNCTIONSPACETYPE_H_
// Enum that allow to choose a function space
class functionSpaceType{
 public :
  // To chosen the space type
  enum whichSpace{Lagrange, Inter};
  functionSpaceType(){};
  ~functionSpaceType(){}; // rewrite to delete object
};
#endif // FUNCTIONSPACETYPE_H_
