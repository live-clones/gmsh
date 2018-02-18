#ifndef _HXT_OMP_H_
#define _HXT_OMP_H_
#ifdef _OPENMP
#include <omp.h>
#else
#include <time.h>
static inline int omp_get_max_threads()  {return 1;}
static inline int omp_get_thread_num()  {return 0;}
static inline int omp_get_num_threads() {return 1;}
static inline int omp_get_num_procs() {return 1;}
static inline int omp_get_thread_limit() {return 1;}
static inline double omp_get_wtime() {
  clock_t t = clock();
  return (double)t/CLOCKS_PER_SEC;
}
#endif
#endif //_HXT_OMP_H_
