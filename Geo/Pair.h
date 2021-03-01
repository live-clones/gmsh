// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PAIR_H
#define PAIR_H

// A pair of values, the types of which can be different
template <class L, class R> class Pair {
private:
  L Left;
  R Right;

public:
  Pair() {}
  Pair(const L &left, const R &right) : Left(left), Right(right) {}
  L left() const { return Left; }
  void left(const L &left) { Left = left; }
  R right() const { return Right; }
  void right(const R &right) { Right = right; }
  L first() const { return Left; }
  R second() const { return Right; }
};

#endif
