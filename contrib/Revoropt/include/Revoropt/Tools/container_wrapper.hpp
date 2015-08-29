// @licstart revoropt
// This file is part of Revoropt, a library for the computation and 
// optimization of restricted Voronoi diagrams.
//
// Copyright (C) 2013 Vincent Nivoliers <vincent.nivoliers@univ-lyon1.fr>
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
// @licend revoropt
#ifndef _REVOROPT_TOOLS_CONTAINER_WRAPPER_HPP_
#define _REVOROPT_TOOLS_CONTAINER_WRAPPER_HPP_

#include "meta.hpp"

#include <iterator>
#include <cassert>
#include <list>
#include <type_traits>

namespace Revoropt {

/* This is nasty stuff to be used with caution */

/* Base class to be able to merge various similar iterators */

/* The idea of this class is that it does not fulfill the requirements of
 * iterators, but that real iterators can be built from it. First, we wrap the
 * comparison between iterators using the address of the thing pointed to. This
 * will allow us to compare different iterator types. By convention, this
 * address will be NULL for past-the-end iterators Beware however that two
 * iterators pointing to the same object will be equal once wrapped. The return
 * type of incr is void, which allows it to be easily virtual, whereas classical
 * operator++ for iterators return instances of the class itself which makes it
 * difficult for virtual functions. The copy_to method will be used to be able
 * to implement operator= on iterators built upon this class. */

template<typename T>
class SimiliIterator ;

//case of iterators pointing to const values
template<typename T>
class SimiliIterator<const T> {

  public :

    /* Construction */
    SimiliIterator() : address_(NULL) {} ;
    SimiliIterator( const T* address ) : address_(address) {} ;

    /* Destruction */
    virtual ~SimiliIterator() {} ;
    
    /* Incrementation */
    /* has to be implemented and update the protected fields */

    virtual void incr() = 0 ;

    /* Deep copy */
    
    virtual void copy_to( SimiliIterator<const T>** target ) const = 0 ;

    /* Comparison */ 
    /* only compares addresses, therefore any two iterators pointing to the same
     * element are identical. */

    bool operator==(const SimiliIterator& rhs) const {
      return address_ == rhs.address_ ;
    }; 
    bool operator==(const SimiliIterator<T>& rhs) const {
      return address_ == rhs.address_ ;
    }; 
    bool operator!=(const SimiliIterator& rhs) const {
      return address_ != rhs.address_ ;
    };
    bool operator!=(const SimiliIterator<T>& rhs) const {
      return address_ != rhs.address_ ;
    };

    /* Dereferencement */
    /* Beware not to dereference past_the_end iterators */
    const T& operator*() const {
      return *address_ ;
    };

  protected :

    /* address to the element pointed to. NULL if past_the_end */
    const T* address_ ;
    
} ;

/* inheritance allows conversion from values to const values */
template<typename T>
class SimiliIterator : public SimiliIterator<const T> {

  public :

    /* Construction */
    SimiliIterator() : SimiliIterator<const T>() {} ;
    SimiliIterator( T* address ) : SimiliIterator<const T>(address) {} ;

    /* Destruction */
    virtual ~SimiliIterator() {} ;

    /* Deep copy */
    
    virtual void copy_to( SimiliIterator<T>** target ) const = 0 ;
    virtual void copy_to( SimiliIterator<const T>** target ) const = 0 ;

    /* Dereferencement */
    /* Beware not to dereference past_the_end iterators */
    T& operator*() {
      return *const_cast<T*>(SimiliIterator<const T>::address_) ;
    };
} ;

/* End iterator, use to check the past_the_end status */

/* Since SimiliIterators store a pointer to the value pointed to, and that this
 * pointer is NULL for past-the-end iterators, all wrapped past the end iterators 
 * will compare equal to that one. */
template<typename T>
class EndIterator : public SimiliIterator<T> {

  public :

    /* Construction */
    EndIterator() : SimiliIterator<T>() {} ;

    /* Incrementation */
    void incr() {} ;

    /* Deep copy */
    void copy_to(SimiliIterator<T>** target) const {
      *target = new EndIterator() ;
    }
    void copy_to(SimiliIterator<const T>** target) const {
      *target = new EndIterator<const T>() ;
    }
} ;

template<typename T>
class EndIterator<const T> : public SimiliIterator<const T> {

  public :

    /* Construction */
    EndIterator() : SimiliIterator<const T>() {} ;

    /* Incrementation */
    void incr() {} ;

    /* Deep copy */
    void copy_to(SimiliIterator<const T>** target) const {
      *target = new EndIterator() ;
    }
} ;

/* Wrapping container iterators */

/* We now describe how to generate SimiliIterators from usual InputIterators. */

template<typename InputIterator, typename Enable = void>
class IteratorWrapper ;

/* This enable_if ensures that this class only gets instantiated whenever the
 * provided iterator is not on a const type. Without doing this trick, the
 * problem is that we have to instantiate the two versions of the copy_to
 * function, one to copy to a SimiliIterator<const T>, and one to copy to a
 * SimiliIterator<T>. However, since const const T is const T, the two function
 * prototypes end up identical, which fails as an invalid overload. */
template<typename InputIterator>
class IteratorWrapper<
  InputIterator,
  typename std::enable_if<
    !std::is_const<typename one_deref_type<InputIterator>::type>::value
  >::type
> : 
  public SimiliIterator<
    typename one_deref_type<InputIterator>::type
  > 
{

    /* Backend iterator type */
    typedef InputIterator iterator ;
    /* Iterator dereference type */
    typedef typename one_deref_type<iterator>::type T ;
 
  protected :
 
    /* Iterator references */
    iterator it_ ;
    iterator end_ ;

  public :

    /* Construction */

    IteratorWrapper( const iterator& it, const iterator& end ) : 
      it_(it), end_(end) {
      if(it_ != end_) {
        SimiliIterator<T>::address_ = &(*it_) ;
      }
    }
    IteratorWrapper( 
      const IteratorWrapper<iterator>& rhs 
    ) : it_(rhs.it_), end_(rhs.end_) {
      if(it_ != end_) {
        SimiliIterator<T>::address_ = &(*it_) ;
      }
    }

    /* Incrementation */

    void incr() {
      if(it_ != end_) {
        if(++it_ != end_) {
          SimiliIterator<T>::address_ = &(*it_) ;
        } else {
          SimiliIterator<T>::address_ = NULL ;
        }
      }
    }

    /* Copy */

    void copy_to( SimiliIterator<T>** target ) const {
      *target = new IteratorWrapper<iterator>(*this) ;
    }

    void copy_to( SimiliIterator<const T>** target ) const {
      *target = new IteratorWrapper<iterator>(*this) ;
    }

} ;

/* This one only gets instantiated if InputIterator is on a const type. */
template<typename InputIterator>
class IteratorWrapper<
  InputIterator,
  typename std::enable_if<
    std::is_const<typename one_deref_type<InputIterator>::type>::value
  >::type
> : 
  public SimiliIterator<
    typename one_deref_type<InputIterator>::type
  > 
{

    /* Backend iterator type */
    typedef InputIterator iterator ;
    /* Iterator dereference type */
    typedef typename one_deref_type<iterator>::type T ;
 
  protected :
 
    /* Iterator references */
    iterator it_ ;
    iterator end_ ;

  public :

    /* Construction */

    IteratorWrapper( const iterator& it, const iterator& end ) : 
      it_(it), end_(end) {
      if(it_ != end_) {
        SimiliIterator<T>::address_ = &(*it_) ;
      }
    }
    IteratorWrapper( 
      const IteratorWrapper<iterator>& rhs 
    ) : it_(rhs.it_), end_(rhs.end_) {
      if(it_ != end_) {
        SimiliIterator<T>::address_ = &(*it_) ;
      }
    }

    /* Incrementation */

    void incr() {
      if(it_ != end_) {
        if(++it_ != end_) {
          SimiliIterator<T>::address_ = &(*it_) ;
        } else {
          SimiliIterator<T>::address_ = NULL ;
        }
      }
    }

    /* Copy */

    void copy_to( SimiliIterator<T>** target ) const {
      *target = new IteratorWrapper<iterator>(*this) ;
    }
} ;

/* Flattening container iterators : returning the fully dereferenced value */

/* This wrapper aims at transforming a container on pointers to iterators to ...
 * on a type T into a container on T, applying as many dereferencements
 * necessary on the elements of the container to reach the non dereferenceable
 * type. */
template<typename InputIterator, typename Enable = void>
class IteratorFlattener ;

/* The same enable_if is used as previously, except that the type of the fully
 * dereferenced iterator is used instead. This case is on non const final type. 
 * */
template<typename InputIterator>
class IteratorFlattener<
  InputIterator,
  typename std::enable_if<
    !std::is_const<typename full_deref_type<InputIterator>::type>::value
  >::type
>: 
  public SimiliIterator<
    typename full_deref_type<InputIterator>::type
  >
{

    /* Backend iterator type */
    typedef InputIterator iterator ;
    /* Iterator dereference type */
    typedef typename full_deref_type<iterator>::type T ;
 
  protected :
 
    /* Iterator references */
    iterator it_ ;
    iterator end_ ;

  public :

    /* Construction */

    IteratorFlattener( const iterator& it, const iterator& end ) : 
      it_(it), end_(end) {
      if(it_ != end_) {
        SimiliIterator<T>::address_ = &(full_deref(it_)) ;
      }
    }
    IteratorFlattener( 
      const IteratorFlattener<iterator>& rhs 
    ) : it_(rhs.it_), end_(rhs.end_) {
      if(it_ != end_) {
        SimiliIterator<T>::address_ = &(full_deref(it_)) ;
      }
    }

    /* Incrementation */

    void incr() {
      if(it_ != end_) {
        if(++it_ != end_) {
          SimiliIterator<T>::address_ = &(full_deref(it_)) ;
        } else {
          SimiliIterator<T>::address_ = NULL ;
        }
      }
    }

    /* Copy */

    void copy_to( SimiliIterator<T>** target ) const {
      *target = new IteratorFlattener<iterator>(*this) ;
    }

    void copy_to( SimiliIterator<const T>** target ) const {
      *target = new IteratorFlattener<iterator>(*this) ;
    }

} ;

/* Case for const final type */
template<typename InputIterator>
class IteratorFlattener<
  InputIterator,
  typename std::enable_if<
    std::is_const<typename full_deref_type<InputIterator>::type>::value
  >::type
>: 
  public SimiliIterator<
    typename full_deref_type<InputIterator>::type
  >
{

    /* Backend iterator type */
    typedef InputIterator iterator ;
    /* Iterator dereference type */
    typedef typename full_deref_type<iterator>::type T ;
 
  protected :
 
    /* Iterator references */
    iterator it_ ;
    iterator end_ ;

  public :

    /* Construction */

    IteratorFlattener( const iterator& it, const iterator& end ) : 
      it_(it), end_(end) {
      if(it_ != end_) {
        SimiliIterator<T>::address_ = &(full_deref(it_)) ;
      }
    }
    IteratorFlattener( 
      const IteratorFlattener<iterator>& rhs 
    ) : it_(rhs.it_), end_(rhs.end_) {
      if(it_ != end_) {
        SimiliIterator<T>::address_ = &(full_deref(it_)) ;
      }
    }

    /* Incrementation */

    void incr() {
      if(it_ != end_) {
        if(++it_ != end_) {
          SimiliIterator<T>::address_ = &(full_deref(it_)) ;
        } else {
          SimiliIterator<T>::address_ = NULL ;
        }
      }
    }

    /* Copy */

    void copy_to( SimiliIterator<T>** target ) const {
      *target = new IteratorFlattener<iterator>(*this) ;
    }

} ;

/* Generic iterator, based on a SimiliIterator */

/* We now build true iterators, fulfilling the stl requirements on iterators. To
 * do so, and to use virtual functions on SimiliIterators, we need to use
 * pointers on these. A Generic Iterator is therefore responsible of the memory
 * allocated to the SimiliIterator it is built upon, even though the allocation
 * is not done by the class itself. */

/* Iterator on non const types */
template<typename T>
class GenericIterator : 
  public std::iterator<std::input_iterator_tag,T> 
{

    friend class GenericIterator<const T> ;
  
    //The generic iterator is responsible for the memory allocated for its
    //iterator, and will free this memory upon destruction.
    SimiliIterator<T>* it_ ;

  public :

    /* Construction */

    GenericIterator() : it_(NULL) {
    }
    GenericIterator( SimiliIterator<T>* it ) : it_(it) {
    }
    GenericIterator( const GenericIterator& rhs ) {
      rhs.it_->copy_to(&it_) ;
    }

    /* Assignment */
    GenericIterator& operator=( const GenericIterator& rhs ) {
      delete it_ ;
      rhs.it_->copy_to(&it_) ;
      return *this ;
    }

    /* Destruction */
    virtual ~GenericIterator() { 
      delete it_ ; 
    }

    /* Incrementation */
    GenericIterator& operator++() { 
      it_->incr(); 
      return *this ; 
    }
    GenericIterator operator++(int) { 
      GenericIterator tmp(*this) ; 
      it_->incr(); 
      return tmp ; 
    }

    /* Comparison */
    bool operator==( const GenericIterator& rhs ) const {
      return *it_ == *(rhs.it_) ;
    }
    bool operator==( const GenericIterator<const T>& rhs ) const {
      return rhs == *this ;
    }

    bool operator!=( const GenericIterator& rhs ) const {
      return *it_ != *(rhs.it_) ;
    }
    bool operator!=( const GenericIterator<const T>& rhs ) const {
      return rhs != *this ;
    }

    /* Dereferencement */
    T& operator*() {
      return **it_ ;
    }
    const T& operator*() const {
      return **it_ ;
    }
    T* operator->() {
      return &(**it_) ;
    }
    const T* operator->() const {
      return &(**it_) ;
    }

} ;

/* Iterator on const types */
template<typename T>
class GenericIterator<const T> : 
  public std::iterator<std::input_iterator_tag,const T> 
{

  friend class GenericIterator<T> ;
  
    //The generic iterator is responsible for the memory allocated for its
    //iterator, and will free this memory upon destruction.
    SimiliIterator<const T>* it_ ;

  public :

    /* Construction */

    GenericIterator() : it_(NULL) {
    }
    GenericIterator( SimiliIterator<const T>* it ) : it_(it) {
    }
    GenericIterator( SimiliIterator<T>* it ) : it_(it) {
    }
    GenericIterator( const GenericIterator& rhs ) {
      rhs.it_->copy_to(&it_) ;
    }
    GenericIterator( const GenericIterator<T>& rhs ) {
      rhs.it_->copy_to(&it_) ;
    }

    /* Assignment */
    GenericIterator& operator=( const GenericIterator& rhs ) {
      delete it_ ;
      rhs.it_->copy_to(&it_) ;
      return *this ;
    }
    GenericIterator& operator=( const GenericIterator<T>& rhs ) {
      delete it_ ;
      rhs.it_->copy_to(&it_) ;
      return *this ;
    }

    /* Destruction */
    virtual ~GenericIterator() { 
      delete it_ ; 
    }

    /* Incrementation */
    GenericIterator& operator++() { 
      it_->incr(); 
      return *this ; 
    }
    GenericIterator operator++(int) { 
      GenericIterator tmp(*this) ; 
      it_->incr(); 
      return tmp ; 
    }

    /* Comparison */
    bool operator==( const GenericIterator& rhs ) const {
      return *it_ == *(rhs.it_) ;
    }
    bool operator==( const GenericIterator<T>& rhs ) const {
      return *it_ == *(rhs.it_) ;
    }

    bool operator!=( const GenericIterator& rhs ) const {
      return *it_ != *(rhs.it_) ;
    }
    bool operator!=( const GenericIterator<T>& rhs ) const {
      return *it_ != *(rhs.it_) ;
    }

    /* Dereferencement */
    const T& operator*() const {
      return **it_ ;
    }
    const T* operator->() const {
      return &(**it_) ;
    }

} ;


/* Generic container, to wrap many existing containers */

/* Now that we can wrap container iterators with a common parent class and build
 * generic iterators from this class, we can focus on wrapping containers as
 * well with a common parent class. The following class is this parent class.
 * Its idea is to only care about providing an input iterator on the content. */

template<typename T>
class GenericContainer ;

/* Container on const values */
template<typename T>
class GenericContainer<const T> {
  
  public :

    /* Destruction */
    virtual ~GenericContainer() {} ;

    /* Typedefs */
    typedef GenericIterator<T> iterator ;
    typedef GenericIterator<const T> const_iterator ;

    /* Iteration */
    virtual const_iterator begin() const = 0 ;

    virtual const_iterator end() const = 0 ;
} ;

/* Container on non const values. The inheritance ensures the conversion to a
 * container on const values. */
template<typename T>
class GenericContainer : public GenericContainer<const T> {
  
  public :

    /* Destruction */
    virtual ~GenericContainer() {} ;

    /* Typedefs */
    typedef GenericIterator<T> iterator ;
    typedef GenericIterator<const T> const_iterator ;

    /* Iteration */
    virtual iterator begin() = 0 ;
    virtual const_iterator begin() const = 0 ;

    virtual iterator end() = 0 ;
    virtual const_iterator end() const = 0 ;
} ;

/* We now wrap usual containers as GenericContainers */

/* Case for stl containers */
template<typename Container>
class ContainerWrapper : 
  public GenericContainer<typename Container::value_type> 
{

    Container &c ;

    /* Typedefs */
    typedef IteratorWrapper<
      typename Container::iterator
    > internal_iterator ;
    typedef IteratorWrapper<
      typename Container::const_iterator
    > internal_const_iterator ;
  
  public :

    /* Typedefs */
    typedef typename Container::value_type value_type ;
    typedef GenericIterator<value_type> iterator ;
    typedef GenericIterator<const value_type> const_iterator ;

    /* Construction, destruction */
    ContainerWrapper(Container& _c) : c(_c) {}
    virtual ~ContainerWrapper() {} ;

    /* Iteration */
    iterator begin() {
      return iterator(new internal_iterator(c.begin(), c.end())) ;
    }
    const_iterator begin() const {
      return const_iterator(new internal_const_iterator(c.begin(), c.end())) ;
    };

    iterator end() {
      return iterator(new internal_iterator(c.end(),c.end())) ;
    };
    const_iterator end() const {
      return const_iterator(new internal_const_iterator(c.end(),c.end())) ;
    };
} ;

/* Case for usual arrays */
template<typename T>
class ContainerWrapper<T*> : 
  public GenericContainer<T> 
{

    T* begin_ ; 
    T* end_ ;

    /* Typedefs */
    typedef IteratorWrapper<
      T *
    > internal_iterator ;
    typedef IteratorWrapper<
      T const *
    > internal_const_iterator ;
  
  public :

    /* Typedefs */
    typedef T value_type ;
    typedef GenericIterator<value_type> iterator ;
    typedef GenericIterator<const value_type> const_iterator ;

    /* Construction, destruction */
    ContainerWrapper(T* begin, T* end) : begin_(begin), end_(end) {}
    virtual ~ContainerWrapper() {} ;

    /* Iteration */
    iterator begin() {
      return iterator(new internal_iterator(begin_, end_)) ;
    }
    const_iterator begin() const {
      return const_iterator(new internal_const_iterator(begin_, end_)) ;
    };

    iterator end() {
      return iterator(new internal_iterator(end_, end_)) ;
    };
    const_iterator end() const {
      return const_iterator(new internal_const_iterator(end_, end_)) ;
    };
} ;

/* Container Flattener for stl like containers */
/* Virtually transforms a vector of pointers chains to a container 
 * containing the fully dereferenced elements. */

/* Case for stl containers */
template<typename Container>
class ContainerFlattener : 
  public GenericContainer<
    typename full_deref_type<typename Container::value_type>::type
  >
{

    Container &c ;

    /* Typedefs */
    typedef IteratorFlattener<
      typename Container::iterator
    > internal_iterator ;
    typedef IteratorFlattener<
      typename Container::const_iterator
    > internal_const_iterator ;
  
  public :

    /* Typedefs */
    typedef typename full_deref_type<
      typename Container::value_type
    >::type value_type ;
    typedef GenericIterator<value_type> iterator ;
    typedef GenericIterator<const value_type> const_iterator ;

    /* Construction, destruction */
    ContainerFlattener(Container& _c) : c(_c) {}
    virtual ~ContainerFlattener() {}

    /* Iteration */
    iterator begin() {
      return iterator(new internal_iterator(c.begin(), c.end())) ;
    }
    const_iterator begin() const {
      return const_iterator(new internal_const_iterator(c.begin(), c.end())) ;
    };

    iterator end() {
      return iterator(new internal_iterator(c.end(),c.end())) ;
    };
    const_iterator end() const {
      return const_iterator(new internal_const_iterator(c.end(),c.end())) ;
    };
} ;

/* Case for usual arrays */
template<typename T>
class ContainerFlattener<T*> : 
  public GenericContainer<
    typename full_deref_type<T>::type
  >
{

    T* begin_ ;
    T* end_ ;

    /* Typedefs */
    typedef IteratorFlattener<
      T *
    > internal_iterator ;
    typedef IteratorFlattener<
      T const *
    > internal_const_iterator ;
  
  public :

    /* Typedefs */
    typedef typename full_deref_type<T>::type value_type ;
    typedef GenericIterator<value_type> iterator ;
    typedef GenericIterator<const value_type> const_iterator ;

    /* Construction, destruction */
    ContainerFlattener(T* begin, T* end) : begin_(begin), end_(end) {}
    virtual ~ContainerFlattener() {}

    /* Iteration */
    iterator begin() {
      return iterator(new internal_iterator(begin_, end_)) ;
    }
    const_iterator begin() const {
      return const_iterator(new internal_const_iterator(begin_, end_)) ;
    };

    iterator end() {
      return iterator(new internal_iterator(end_, end_)) ;
    };
    const_iterator end() const {
      return const_iterator(new internal_const_iterator(end_, end_)) ;
    };
} ;

/* Container merging */

/* Using the GenericContainer class, several containers of various types can now
 * be merged together. We first create the iterator type that we be able to
 * iterate on the elements of a sequence of containers. */

/* Composite iterator */

/* The composite iterator takes a sequence of GenericContainers, and passes from
 * one container to the other when the end of the first container is reached.*/

/* Case for non const values */
template<typename T>
class CompositeIterator : 
  public std::iterator<std::input_iterator_tag,T> 
{

  friend class CompositeIterator<const T> ;

  public :
   
    /* Typedefs */
    typedef GenericIterator<T> iterator ;
    typedef typename std::list<
      GenericContainer<T>*
    >::iterator sub_iterator ;
    typedef typename std::list<
      GenericContainer<T>*
    >::const_iterator const_sub_iterator ;

    /* Construction */

    CompositeIterator() : end_(new EndIterator<T>), 
                          inner_it_(end_), 
                          outer_it_(containers_.end()) {
    }
    CompositeIterator( const CompositeIterator& rhs ) : 
      end_(new EndIterator<T>) 
    {
      *this = rhs ;
    }

    sub_iterator push_back( GenericContainer<T>* c ) {
      //we need to ensure that we point to the first value
      //even when empty containers are provided
      if(inner_it_ == end_) {
        containers_.push_back(c) ;
        outer_it_ = --containers_.end() ;
        inner_it_ = c->begin() ;
      } else {
        containers_.push_back(c) ;
      }
      return --containers_.end() ;
    }


    /* Assignment */
    CompositeIterator& operator=( const CompositeIterator& rhs ) {
      //copy the inner iterator
      inner_it_ = rhs.inner_it_ ;
      //copy the container sequence
      containers_.clear() ;
      typedef typename CompositeIterator<T>::const_sub_iterator rhs_iterator ;
      for( rhs_iterator it = rhs.containers_.begin(); 
           it != rhs.containers_.end(); 
           ++it 
         ) {
        push_back(*it) ;
        if(it == rhs.outer_it_) {
          //replace the outer iterator to the right position in the sequence
          outer_it_ = --containers_.end() ;
        }
      }
      if(rhs.outer_it_ == rhs.containers_.end()) {
        //handle the case when rhs is past-the-end
        outer_it_ = containers_.end() ;
      }
      return *this ;
    }

    /* Incrementation */
    CompositeIterator& operator++() { 
      ++inner_it_ ; 
      while(inner_it_ == end_) {
        //we pass over the empty arrays here
        ++outer_it_ ;
        if(outer_it_ != containers_.end()) {
          inner_it_ = (*outer_it_)->begin() ;
        } else {
          break ;
        }
      }
      return *this ; 
    }
    CompositeIterator operator++(int) { 
      CompositeIterator tmp(*this) ; 
      this->operator++() ; 
      return tmp ; 
    }

    /* Comparison */
    bool operator==( const CompositeIterator& rhs ) const {
      return inner_it_ == rhs.inner_it_ ;
    }
    bool operator==( const CompositeIterator<const T>& rhs ) const {
      return inner_it_ == rhs.inner_it_ ;
    }

    bool operator!=( const CompositeIterator& rhs ) const {
      return inner_it_ != rhs.inner_it_ ;
    }
    bool operator!=( const CompositeIterator<const T>& rhs ) const {
      return inner_it_ != rhs.inner_it_ ;
    }

    /* Dereferencement */
    T& operator*() {
      return *inner_it_ ;
    }
    const T& operator*() const {
      return *inner_it_ ;
    }
    T* operator->() {
      return &(*inner_it_) ;
    }
    const T* operator->() const {
      return &(*inner_it_) ;
    }

  private :

    /* global end iterator */
    iterator end_ ;

    /* current inner iterator */
    iterator inner_it_ ;

    /* store a list of generic iterators to concatenate */
    std::list<GenericContainer<T>*> containers_ ;

    /* current outer_iterator_ */
    sub_iterator outer_it_ ;

} ;

/* Case for const values */
template<typename T>
class CompositeIterator<const T> :
  public std::iterator<std::input_iterator_tag,const T> 
{
 
  friend class CompositeIterator<T> ;

  public :
   
    /* Typedefs */
    typedef GenericIterator<const T> iterator ;
    typedef typename std::list<
      const GenericContainer<const T>*
    >::const_iterator sub_iterator ;

    /* Construction */

    CompositeIterator() : end_(new EndIterator<const T>), 
                          inner_it_(end_), 
                          outer_it_(containers_.end()) {
    }
    CompositeIterator( const CompositeIterator& rhs ) : 
      end_(new EndIterator<const T>) 
    {
      *this = rhs ;
    }
    CompositeIterator( const CompositeIterator<T>& rhs ) : 
      end_(new EndIterator<T>) 
    {
      *this = rhs ;
    }

    sub_iterator push_back( const GenericContainer<const T>* c ) {
      //we need to ensure that we point to the first value
      //even when empty containers are provided
      if(inner_it_ == end_) {
        containers_.push_back(c) ;
        outer_it_ = --containers_.end() ;
        inner_it_ = c->begin() ;
      } else {
        containers_.push_back(c) ;
      }
      return --containers_.end() ;
    }


    /* Assignment */
    CompositeIterator& operator=( const CompositeIterator& rhs ) {
      //copy the inner iterator
      inner_it_ = rhs.inner_it_ ;
      //copy the container sequence
      containers_.clear() ;
      for( sub_iterator it = rhs.containers_.begin(); 
           it != rhs.containers_.end(); 
           ++it 
         ) {
        push_back(*it) ;
        if(it == rhs.outer_it_) {
          //ensure that the outer iterator is correctly set
          outer_it_ = --containers_.end() ;
        }
      }
      if(rhs.outer_it_ == rhs.containers_.end()) {
        //handle the case when rhs is past-the-end
        outer_it_ = containers_.end() ;
      }
      return *this ;
    }
    CompositeIterator& operator=( const CompositeIterator<T>& rhs ) {
      //copy the inner iterator
      inner_it_ = rhs.inner_it_ ;
      //copy the container sequence
      containers_.clear() ;
      typedef typename CompositeIterator<T>::const_sub_iterator rhs_iterator ;
      for( rhs_iterator it = rhs.containers_.begin(); 
           it != rhs.containers_.end(); 
           ++it 
         ) {
        push_back(*it) ;
        if(it == rhs.outer_it_) {
          //ensure that the outer iterator is correctly set
          outer_it_ = --containers_.end() ;
        }
      }
      if(rhs.outer_it_ == rhs.containers_.end()) {
        //handle the case when rhs is past-the-end
        outer_it_ = containers_.end() ;
      }
      return *this ;
    }

    /* Incrementation */
    CompositeIterator& operator++() { 
      ++inner_it_ ; 
      while(inner_it_ == end_) {
        //we pass over the empty arrays here
        ++outer_it_ ;
        if(outer_it_ != containers_.end()) {
          inner_it_ = (*outer_it_)->begin() ;
        } else {
          break ;
        }
      }
      return *this ; 
    }
    CompositeIterator operator++(int) { 
      CompositeIterator tmp(*this) ; 
      this->operator++() ; 
      return tmp ; 
    }

    /* Comparison */
    bool operator==( const CompositeIterator& rhs ) const {
      return inner_it_ == rhs.inner_it_ ;
    }
    bool operator==( const CompositeIterator<T>& rhs ) const {
      return inner_it_ == rhs.inner_it_ ;
    }

    bool operator!=( const CompositeIterator& rhs ) const {
      return inner_it_ != rhs.inner_it_ ;
    }
    bool operator!=( const CompositeIterator<T>& rhs ) const {
      return inner_it_ != rhs.inner_it_ ;
    }

    /* Dereferencement */
    const T& operator*() const {
      return *inner_it_ ;
    }
    const T* operator->() const {
      return &(*inner_it_) ;
    }

  private :

    /* global end iterator */
    iterator end_ ;

    /* current inner iterator */
    iterator inner_it_ ;

    /* store a list of generic iterators to concatenate */
    std::list<const GenericContainer<const T>*> containers_ ;

    /* current outer_iterator_ */
    sub_iterator outer_it_ ;

} ;

/* An stl like container to merge multiple containers */

template<typename T>
class composite {

  public :

    /* Typedefs */
    typedef T value_type ;
    typedef CompositeIterator<T> iterator ;
    typedef CompositeIterator<const T> const_iterator ;
    typedef typename std::list<GenericContainer<T>*>::iterator sub_iterator ;
    typedef typename std::list<GenericContainer<T>*>::const_iterator const_sub_iterator ;

    /* Construction */
    composite() {}

    template<typename Container>
    sub_iterator push_back( Container& container ) {
      containers_.push_back(new ContainerFlattener<Container>(container)) ;
      return --containers_.end() ;
    }

    template<typename Tp>
    sub_iterator push_back( Tp begin, Tp end ) {
      containers_.push_back( 
        new ContainerFlattener<Tp>(begin, end)
      ) ;
      return --containers_.end() ;
    }

    /* Destruction */
    ~composite() {
      for( sub_iterator it = containers_.begin(); 
           it != containers_.end(); 
           ++it
         ) {
        delete *it ;
      }
    }

    void erase( sub_iterator it ) {
      delete *it ;
      containers_.erase(it) ;
    }

    /* Iteration */
    iterator begin() {
      iterator composite_it ;
      for( sub_iterator it = containers_.begin(); 
           it != containers_.end(); 
           ++it
         ) {
        composite_it.push_back(*it) ;
      }
      return composite_it ;
    }
    const_iterator begin() const {
      const_iterator composite_it ;
      for( const_sub_iterator it = containers_.begin(); 
           it != containers_.end(); 
           ++it
         ) {
        composite_it.push_back(*it) ;
      }
      return composite_it ;
    };

    iterator end() {
      return end_ ;
    };
    const_iterator end() const {
      return end_ ;
    };

  private :

    /* Wrapped containers */
    std::list<GenericContainer<T>*> containers_ ;

    /* global end iterator */
    iterator end_ ;

} ;

} //end of namespace Revoropt

#endif
