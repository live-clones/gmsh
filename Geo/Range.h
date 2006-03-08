#ifndef H_Range
#define H_Range

/** represents a range of values of the template type */
template <class T>
class Range{
private:
  T	Low;
  T	High;
public:
  Range() {}
  Range( const T& low, const T& high) : Low(low), High(high) {}
  T	low() const { return Low; }
  void low(const T& low) { Low = low; }
  T	high() const { return High; }
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
