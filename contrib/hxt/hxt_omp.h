#ifndef _HXT_OMP_H_
#define _HXT_OMP_H_
#ifdef _OPENMP
#include <omp.h>
#else
#include <time.h>
static inline int omp_get_max_threads(void)  {return 1;}
static inline int omp_get_thread_num(void)  {return 0;}
static inline int omp_get_num_threads(void) {return 1;}
static inline int omp_get_num_procs(void) {return 1;}
static inline int omp_get_thread_limit(void) {return 1;}
static inline void omp_set_num_threads(int n) { ; }
static inline double omp_get_wtime(void) {
  clock_t t = clock();
  return (double)t/CLOCKS_PER_SEC;
}
#endif
#endif //_HXT_OMP_H_
