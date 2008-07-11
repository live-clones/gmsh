// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _RANGE_H_
#define _RANGE_H_

// represents a range of values of the template type
template <class T>
class Range {
 private:
  T Low;
  T High;
 public:
  Range() {}
  Range(const T& low, const T& high) : Low(low), High(high) {}
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
