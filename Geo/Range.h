#ifndef _RANGE_H_
#define _RANGE_H_

// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

// represents a range of values of the template type
template <class T>
class Range {
 private:
  T Low;
  T High;
 public:
  Range() {}
  Range( const T& low, const T& high) : Low(low), High(high) {}
  T low() const { return Low; }
  void low(const T& low) { Low = low; }
  T high() const { return High; }
  void high(const T& high) { High = high; }
  int contains(const T& value) const;
  int contains(const Range<T> & range) const;
  int operator == (const Range<T> &range) const;
};

template<class T>
int Range<T>::contains(const T& value) const
{ return ( (value >= Low) && (value <= High) ); }

template<class T>
int Range<T>::contains(const Range<T>& range) const
{ return ( (range.low() >= Low) && (range.high() <= High) ); }

template<class T>
int Range<T>::operator == (const Range<T>& range) const
{ return ( (range.low() == Low) && (range.high() == High) ); }

#endif
