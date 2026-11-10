#ifndef HXT_COMBINE_ATOMIC_OPS_H
#define HXT_COMBINE_ATOMIC_OPS_H

// Relaxed atomic operations on plain integers shared by the threads: the
// GCC/Clang builtins, or the Interlocked intrinsics of MSVC (whose 64-bit
// reads go through a compare-exchange, as they could tear on 32-bit targets)

#include <cstddef>
#include <cstring>

#if defined(_MSC_VER) && !defined(__clang__)
#include <intrin.h>
#endif

namespace HXTCombine {

#if defined(_MSC_VER) && !defined(__clang__)

  namespace atomicDetail {
    template <std::size_t N> struct Interlocked;
    template <> struct Interlocked<1> {
      typedef char type;
      static type cas(volatile type *p, type desired, type expected)
      {
        return _InterlockedCompareExchange8(p, desired, expected);
      }
    };
    template <> struct Interlocked<4> {
      typedef long type;
      static type cas(volatile type *p, type desired, type expected)
      {
        return _InterlockedCompareExchange(p, desired, expected);
      }
    };
    template <> struct Interlocked<8> {
      typedef __int64 type;
      static type cas(volatile type *p, type desired, type expected)
      {
        return _InterlockedCompareExchange64(p, desired, expected);
      }
    };
  } // namespace atomicDetail

  template <class T> inline T atomicLoad(const T *p)
  {
    typedef atomicDetail::Interlocked<sizeof(T)> I;
    typedef typename I::type U;
    U old;
    if(sizeof(T) == 8)
      old = I::cas((volatile U *)p, U(0), U(0)); // unchanged unless 0
    else
      old = *(const volatile U *)p;
    T value;
    std::memcpy(&value, &old, sizeof(T));
    return value;
  }

  // the value read goes to expected when the exchange fails
  template <class T, class V>
  inline bool atomicCompareExchange(T *p, T &expected, V desired)
  {
    typedef atomicDetail::Interlocked<sizeof(T)> I;
    typedef typename I::type U;
    const T d = (T)desired;
    U e, u;
    std::memcpy(&e, &expected, sizeof(T));
    std::memcpy(&u, &d, sizeof(T));
    const U old = I::cas((volatile U *)p, u, e);
    if(old == e) return true;
    std::memcpy(&expected, &old, sizeof(T));
    return false;
  }

  template <class T, class V> inline T atomicFetchAdd(T *p, V v)
  {
    T old = atomicLoad(p);
    while(!atomicCompareExchange(p, old, (T)(old + (T)v))) {}
    return old;
  }

#else

  template <class T> inline T atomicLoad(const T *p)
  {
    return __atomic_load_n(p, __ATOMIC_RELAXED);
  }

  // the value read goes to expected when the exchange fails
  template <class T, class V>
  inline bool atomicCompareExchange(T *p, T &expected, V desired)
  {
    return __atomic_compare_exchange_n(p, &expected, (T)desired, false,
                                       __ATOMIC_RELAXED, __ATOMIC_RELAXED);
  }

  template <class T, class V> inline T atomicFetchAdd(T *p, V v)
  {
    return __atomic_fetch_add(p, (T)v, __ATOMIC_RELAXED);
  }

#endif

} // namespace HXTCombine

#endif
