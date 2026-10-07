/**
 * @file dlutil.c
 * @brief Utility functions
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-09-11
 */




#ifndef DL_UTIL_C
#define DL_UTIL_C




#include "dlutil.h"




/******************************************************************************
* MACROS **********************************************************************
******************************************************************************/


#define BYTEMASK 0xff
#define BYTED(a,s) \
  ((unsigned char)(((a) >> ((s)*8)) & BYTEMASK))
#define BYTEN(t,a,s) \
  (((t)(a)) << ((s)*8))


#define __UNINITIALIZED_SEED ((unsigned int)-1)


/******************************************************************************
* GLOBAL VARIABLES ************************************************************
******************************************************************************/


static __thread unsigned int __domlib_random_seed = __UNINITIALIZED_SEED;




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


void dl_to_bytes(
    void * dst, 
    const void * const src, 
    size_t width)
{
  #ifdef DL_HTONXX_AVAILABLE
  switch (width) {
    case 1 : *((unsigned char *)dst) = *((unsigned char*)src);
             break;
    case 2 : *((uint16_t*)dst) = hton16(*((uint16_t*)src));
             break;
    case 4 : *((uint32_t*)dst) = hton32(*((uint32_t*)src));
             break;
    case 8 : *((uint64_t*)dst) = hton64(*((uint64_t*)src));
             break;
    default : dl_error("Unsupported byte width %zu\n",width);
  }
  #else 
  int64_t x;
  unsigned char * bdst = (unsigned char*)dst;
  switch (width) {
    case 1: *bdst = *((unsigned char*)src);
            break;
    case 2: x = *((int16_t*)src);
            bdst[0] = BYTED(x,1); 
            bdst[1] = BYTED(x,0);
            break;
    case 4: x = *((int32_t*)src);
            bdst[0] = BYTED(x,3); 
            bdst[1] = BYTED(x,2);
            bdst[2] = BYTED(x,1);
            bdst[3] = BYTED(x,0);
            break;
    case 8: x = *((int64_t*)src);
            bdst[0] = BYTED(x,7); 
            bdst[1] = BYTED(x,6);
            bdst[2] = BYTED(x,5);
            bdst[3] = BYTED(x,4);
            bdst[4] = BYTED(x,3); 
            bdst[5] = BYTED(x,2);
            bdst[6] = BYTED(x,1);
            bdst[7] = BYTED(x,0);
            break;
    default: dl_error("Uncovertable width %zu",width);
  }
  #endif
}


void dl_from_bytes(
    void * dst, 
    const void * const src, 
    size_t width) 
{
  #ifdef DL_HTONXX_AVAILABLE
  switch (width) {
    case 1 : *((unsigned char *)dst) = *((unsigned char*)src);
             break;
    case 2 : *((uint16_t*)dst) = n16toh(*((uint16_t*)src));
             break;
    case 4 : *((uint32_t*)dst) = n32toh(*((uint32_t*)src));
             break;
    case 8 : *((uint64_t*)dst) = n64toh(*((uint64_t*)src));
             break;
    default : dl_error("Unsupported byte width %zu\n",width);
  }
  #else 
  int64_t x;
  unsigned char * bsrc = (unsigned char*)src;

  switch (width) {
    case 1: *((unsigned char*)dst) = *bsrc;
            break;
    case 2: x = BYTEN(int16_t,bsrc[0],1);
            x += BYTEN(int16_t,bsrc[1],0);
            *((int16_t*)(dst)) = (int16_t)x;
            break;
    case 4: x = BYTEN(int32_t,bsrc[0],3);
            x += BYTEN(int32_t,bsrc[1],2);
            x += BYTEN(int32_t,bsrc[2],1);
            x += BYTEN(int32_t,bsrc[3],0);
            *((int32_t*)(dst)) = (int32_t)x;
            break;
    case 8: x = BYTEN(int64_t,bsrc[0],7);
            x += BYTEN(int64_t,bsrc[1],6);
            x += BYTEN(int64_t,bsrc[2],5);
            x += BYTEN(int64_t,bsrc[3],4);
            x += BYTEN(int64_t,bsrc[4],3);
            x += BYTEN(int64_t,bsrc[5],2);
            x += BYTEN(int64_t,bsrc[6],1);
            x += BYTEN(int64_t,bsrc[7],0);
            *((int64_t*)(src)) = x;
            break;
    default: dl_error("Uncovertable width %zu",width);
  }
  #endif
}


/* Time Wrappers */
double dl_wctime(void)
{
  struct timeval ctime; 
  gettimeofday(&ctime,NULL); 
  return (double)(ctime.tv_sec + (.000001*ctime.tv_usec)); 
}


/* Timer Functions */
void dl_init_timer(
    dl_timer_t * const timer)
{
  timer->duration = 0.0;
  timer->start = -1.0;
  timer->state = DL_TIMER_STOPPED;
}


double dl_start_timer(
    dl_timer_t * const timer) 
{ 
  timer->state = DL_TIMER_RUNNING;
  return (timer->start = dl_wctime());
} 


double dl_stop_timer(
    dl_timer_t * const timer)
{
  timer->duration += dl_wctime() - timer->start;
  timer->start = -1.0;
  timer->state = DL_TIMER_STOPPED;
  return timer->duration;
}


double dl_reset_timer(
    dl_timer_t * const timer)
{
  double dur;
  switch (timer->state) {
    case DL_TIMER_STOPPED: 
      dur = timer->duration;
      break;
    case DL_TIMER_RUNNING:
      dur = dl_stop_timer(timer);
      break;
    default:
      dur = 0;
      break;
  }
  dl_init_timer(timer);
  return dur;
}


double dl_poll_timer(
    const dl_timer_t * const timer) 
{
  double res;
  switch(timer->state) {
    case DL_TIMER_RUNNING:
      res = timer->duration + (dl_wctime() - timer->start);
      break;
    case DL_TIMER_STOPPED:
      res = timer->duration;
      break;
    default:
      dl_error("Unknown timer state %d\n",timer->state);
      break;
  }
  return res;
}


void dl_combine_timer(
    dl_timer_t * const timer1,
    dl_timer_t const * const timer2)
{
  timer1->duration += timer2->duration;
}


double dl_diff_timer(
    const dl_timer_t * const timer1, 
    const dl_timer_t * const timer2)
{
  return dl_poll_timer(timer1) - dl_poll_timer(timer2);
}


void dl_init_rand(void)
{
  __domlib_random_seed = (unsigned int)time(NULL);
}


void dl_set_rand(
    const unsigned int seed)
{
  __domlib_random_seed = seed;
}


unsigned int * dl_get_rand(void)
{
  if (__domlib_random_seed == __UNINITIALIZED_SEED) {
    dl_init_rand();
  }
  return &__domlib_random_seed;
}




#undef BYTEMASK
#undef BYTED
#undef BYTEN
#undef __UINITIALIZED_SEED




#endif
