/**
 * @file dlthread_pool.c
 * @brief A custom thread pool.
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2014-2015, Dominique LaSalle
 * @version 1
 * @date 2015-01-17
 */




#ifndef DLTHREAD_POOL_C
#define DLTHREAD_POOL_C




#include "dlthread_pool.h"
#include "dlenv.h"
#include <pthread.h>
#include <omp.h>




/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/


typedef enum task_state_t {
  TASK_STATE_WAITING,
  TASK_STATE_RUNNING,
  TASK_STATE_FINISHED
} task_state_t;


typedef struct task_t {
  void (* func)(void * ptr); 
  void * var;
  int state;
} task_t;


typedef struct taskq_t {
  size_t maxtasks;
  size_t offset;
  size_t first;
  size_t last;
  task_t * tasks;
  pthread_mutex_t lock; 
} taskq_t;


typedef struct dlthread_pool_t {
  size_t nthreads;
  size_t nwaiting;
  int schedule;
  taskq_t * queues;
  pthread_mutex_t lock;
  pthread_cond_t cond;
} dlthread_pool_t;


typedef enum task_bit_t {
  LOCAL_FIRST = DLTHREAD_POOL_TS_LFRF & DLTHREAD_POOL_TS_LFRL,
  REMOTE_FIRST = DLTHREAD_POOL_TS_LLRF & DLTHREAD_POOL_TS_LFRF
} task_bit_t;




/******************************************************************************
* STRINGS *********************************************************************
******************************************************************************/


#define DLTHREAD_POOL_STR_TS_LFRF "lfrf"
#define DLTHREAD_POOL_STR_TS_LFRL "lfrl"
#define DLTHREAD_POOL_STR_TS_LLRF "llrf"
#define DLTHREAD_POOL_STR_TS_LLRL "llrl"
#define DLTHREAD_POOL_STR_SCHEDULE "DLTHREAD_POOL_SCHEDULE"



/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


static char const * trans_table_schedule[] = {
  [DLTHREAD_POOL_TS_LFRF] = DLTHREAD_POOL_STR_TS_LFRF, 
  [DLTHREAD_POOL_TS_LFRL] = DLTHREAD_POOL_STR_TS_LFRL,
  [DLTHREAD_POOL_TS_LLRF] = DLTHREAD_POOL_STR_TS_LLRF,
  [DLTHREAD_POOL_TS_LLRL] = DLTHREAD_POOL_STR_TS_LLRL
};




/******************************************************************************
* GLOBAL VARIABLES ************************************************************
******************************************************************************/


volatile int pool_alive = 0;
dlthread_pool_t pool;




/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


static size_t const DEFAULT_MAXTASKS = 4096;
static size_t const NULL_TASK = (size_t)-1;




/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


static void __expand_pool(void)
{
  size_t i, nactive;
  taskq_t * q;
  task_t * tasks;

  size_t const myid = omp_get_thread_num();

  q = pool.queues+myid;

  /* calculate the new offset */
  for (i=0;i<q->last;++i) {
    if (q->tasks[i].state != TASK_STATE_FINISHED) {
      break;
    }
  }
  q->offset += i;
  q->first = 0;
  q->maxtasks *= 2;

  tasks = malloc(q->maxtasks*sizeof(task_t));
  nactive = q->last - i;
  memcpy(tasks,q->tasks+i,sizeof(task_t)*nactive);
  q->last = nactive;

  dl_free(q->tasks);

  q->tasks = tasks;
}


static size_t __get_task_back(
    taskq_t * const q)
{
  size_t tid;
  task_t * task;

  if (q->last > q->first) {
    /* perform a local task */
    --q->last;

    task = q->tasks+q->last;

    DL_ASSERT_EQUALS(task->state,TASK_STATE_WAITING,"%d");

    task->state = TASK_STATE_RUNNING;

    /* calculate the task id */
    tid = q->last + q->offset;
  } else {
    tid = NULL_TASK;
  }

  return tid;
}


static size_t __get_task_front(
    taskq_t * const q)
{
  size_t tid;
  task_t * task;

  if (q->last > q->first) {
    task = q->tasks+q->first;

    /* calculate the task id */
    tid = q->first + q->offset;

    ++q->first;

    DL_ASSERT_EQUALS(task->state,TASK_STATE_WAITING,"%d");

    task->state = TASK_STATE_RUNNING;
  } else {
    tid = NULL_TASK;
  }

  return tid;
}


static int __perform_task(void)
{
  size_t t, tid;
  taskq_t * q;
  task_t * task;
  task_t ltask;

  size_t const myid = omp_get_thread_num();
  size_t const nthreads = pool.nthreads;

  q = pool.queues+myid;

  /* check my pool for tasks */
  pthread_mutex_lock(&q->lock);

  if (pool.schedule & LOCAL_FIRST) {
    tid = __get_task_front(q);
  } else {
    tid = __get_task_back(q);
  }

  if (tid != NULL_TASK) {
    /* for debugging */
    t = myid;
  } else {
    /* perform a remote task */

    /* unlock my queue */
    pthread_mutex_unlock(&q->lock);

    /* this currently searches for a task in rr order, but it would be best to
     * do it in hypercube order */
    for (t=(myid+1)%nthreads;t!=myid;t=(t+1)%nthreads) {
      q = pool.queues+t;

      pthread_mutex_lock(&q->lock);

      if (pool.schedule & REMOTE_FIRST) {
        tid = __get_task_front(q);
      } else {
        tid = __get_task_back(q);
      }

      if (tid != NULL_TASK) {
        /* the lock will be released below the loop */
        break;
      }

      /* release the current lock */
      pthread_mutex_unlock(&q->lock);
    }
    if (t == myid) {
      /* there is no work to be done */
      return 0;
    }
  }

  /* the location of the task may change, so make a copy */
  ltask = q->tasks[tid-q->offset];

  pthread_mutex_unlock(&q->lock);
  
  /* the location of the task may change */

  /* perform task */
  ltask.func(ltask.var);

  pthread_mutex_lock(&q->lock);

  /* change the state of the task */
  task = q->tasks+(tid-q->offset);
  task->state = TASK_STATE_FINISHED;

  pthread_mutex_unlock(&q->lock);

  return 1;
}




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


void dlthread_pool_init(
    size_t const nthreads)
{
  int i;
  size_t t;
  taskq_t * q;
  const char * str;

  #pragma omp single
  {
    pool.nthreads = nthreads;
    pool.nwaiting = 0;
    pthread_mutex_init(&pool.lock,NULL);
    pthread_cond_init(&pool.cond,NULL);
    pool.queues = malloc(nthreads*sizeof(taskq_t));

    /* figure out the schedule to use */
    str = dl_get_env_string(DLTHREAD_POOL_STR_SCHEDULE, \
        DLTHREAD_POOL_STR_TS_LLRF);
    for (i=0;i<__DLTHREAD_POOL_TS_TERM;++i) {
      if (strcmp(trans_table_schedule[i],str) == 0) {
        break;
      }
    }
    if (i == __DLTHREAD_POOL_TS_TERM) {
      wprintf("Invalid schedule '%s', using default\n",str);
      i = DLTHREAD_POOL_TS_LLRF;
    }
    pool.schedule = i; 

    for (t=0;t<nthreads;++t) {
      q = pool.queues+t;
      q->first = 0;
      q->last = 0;
      q->offset = 0;
      q->maxtasks = DEFAULT_MAXTASKS;
      q->tasks = malloc(q->maxtasks*sizeof(task_t));

      pthread_mutex_init(&q->lock,NULL);
    }

    pool_alive = 1;
  }
  while (pool_alive == 0) {
    /* do nothing */
  }
}


void dlthread_pool_finalize(void)
{
  int work;
  size_t t;
  taskq_t * q;

  size_t const nthreads = pool.nthreads;

  do {
    work = __perform_task();

    pthread_mutex_lock(&pool.lock);

    if (!work) {
      ++pool.nwaiting;
      if (pool.nwaiting < pool.nthreads) {
        pthread_cond_wait(&pool.cond,&pool.lock);
      } else {
        pthread_cond_broadcast(&pool.cond);
      }

      if (pool.nwaiting < pool.nthreads) {
        --pool.nwaiting;
      }
    }

    pthread_mutex_unlock(&pool.lock);
  } while(pool.nwaiting < pool.nthreads);

  #pragma omp barrier
  #pragma omp master
  {
    for (t=0;t<nthreads;++t) {
      q = pool.queues+t;
      dl_free(q->tasks);
      pthread_mutex_destroy(&q->lock);
    }

    dl_free(pool.queues);

    pthread_mutex_destroy(&pool.lock);
    pthread_cond_destroy(&pool.cond);

    pool_alive = 0;
  }
  #pragma omp barrier
}


void dlthread_pool_set_schedule(
    int schedule)
{
  pool.schedule = schedule;
}


size_t dlthread_pool_add(
    void (* func)(void*ptr),
    void * var)
{
  size_t id;
  task_t task;
  taskq_t * q;

  size_t const myid = omp_get_thread_num();

  DL_ASSERT(myid < pool.nthreads,"Invalid thread id of %zu/%zu\n",myid, \
      pool.nthreads);

  q = pool.queues+myid;

  pthread_mutex_lock(&q->lock);

  if (q->last == q->maxtasks) {
    __expand_pool();
  }

  id = q->last + q->offset;

  task.func = func;
  task.var = var;
  task.state = TASK_STATE_WAITING;

  q->tasks[q->last++] = task;

  pthread_mutex_unlock(&q->lock);

  pthread_cond_signal(&pool.cond);

  return id;
}


void dlthread_pool_wait(
    size_t tid)
{
  int finished;
  taskq_t * q;

  size_t const myid = omp_get_thread_num();

  finished = 0;

  q = pool.queues+myid;

  do {
    if (tid < q->offset) {
      /* the task has been pushed out the end as finished */
      break;
    }

    pthread_mutex_lock(&q->lock);

    if (q->tasks[tid-q->offset].state == TASK_STATE_FINISHED) {
      finished = 1;
    }
    pthread_mutex_unlock(&q->lock);

    if (finished) {
      break;
    }  

    /* tackle a task while we wait for ours */
    __perform_task();
  } while(1);
}




#endif
