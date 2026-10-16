/**
 * @file dlthread_funcs.h
 * @brief Thread reduction functions.
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2014-2015, Dominique LaSalle
 * @version 1
 * @date 2014-12-02
 */




/* prefixing ugliness */
#define DLTHREAD_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLTHREAD_PRE1(prefix,suffix) DLTHREAD_PRE2(prefix,suffix)
#define DLTHREAD_PUB(name) DLTHREAD_PRE1(DLTHREAD_PREFIX,name)
#define DLTHREAD_PRI(name) DLTHREAD_PRE1(_,DLTHREAD_PRE1(DLTHREAD_PREFIX,name))


#ifndef DLTHREAD_VISIBILITY
  #define DLTHREAD_VISIBILITY
  #define DLTHREAD_DEFVIS
#endif




/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


static void DLTHREAD_PRI(dlthread_sumdreduce)(
    DLTHREAD_TYPE_T * const val,
    size_t const n,
    dlthread_comm_t const comm)
{
  size_t i, nbr;
  ssize_t d;
  DLTHREAD_TYPE_T * nbrval, ** buf;

  size_t const myid = dlthread_get_id(comm);
  size_t const nthreads = dlthread_get_nthreads(comm);
  size_t const up = size_uppow2(nthreads);
  size_t const start = ((myid & 1U) == 0 ? 0 : n/2);
  size_t const end = ((myid & 1U) == 0 ? n/2 : n);
  int const sign = ((myid & 1U) == 0 ? 1 : -1);

  /* set my value */
  buf = dlthread_get_buffer(sizeof(DLTHREAD_TYPE_T*)*up,comm);
  buf[myid] = val;

  /* allocate values for missing neighbors */
  if (myid + nthreads < up) {
    buf[myid+nthreads] = calloc(n,sizeof(DLTHREAD_TYPE_T));
  }

  dlthread_barrier(comm);
  /* do a hyper cube reduction */
  nbr = myid;
  for (d=1;d<(ssize_t)nthreads;d<<=1) {
    nbr = (size_t)((nbr+(sign*d))%up);
    nbrval = buf[nbr];
    if (nbr < nthreads) {
      for (i=start;i<end;++i) {
        val[i] += nbrval[i];
      }
      memcpy(nbrval+start,val+start,(end-start)*sizeof(DLTHREAD_TYPE_T));
    } else {
      for (i=0;i<n;++i) {
        val[i] += nbrval[i];
      }
      memcpy(nbrval,val,n*sizeof(DLTHREAD_TYPE_T));
    }
    dlthread_barrier(comm);
  }

  /* free blank space */
  if (myid + nthreads < up) {
    dl_free(buf[myid+nthreads]);
  }
  dlthread_barrier(comm);
}




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


DLTHREAD_VISIBILITY DLTHREAD_TYPE_T DLTHREAD_PUB(dlthread_sumreduce)(
    DLTHREAD_TYPE_T const val,
    dlthread_comm_t const comm)
{
  size_t i;
  DLTHREAD_TYPE_T sum;
  DLTHREAD_TYPE_T * buf;

  size_t const myid = dlthread_get_id(comm);
  size_t const nthreads = dlthread_get_nthreads(comm);

  buf = (DLTHREAD_TYPE_T*)dlthread_get_buffer( \
      sizeof(DLTHREAD_TYPE_T)*nthreads,comm);

  buf[myid] = val;
  
  dlthread_barrier(comm);

  /* works for small numbers of threads */
  if (myid == 0) {
    sum = val;
    for (i=1;i<nthreads;++i) {
      sum += buf[i];
    }
    buf[0] = sum;
  }
  dlthread_barrier(comm);

  sum = buf[0];

  dlthread_barrier(comm);

  return sum;
}


DLTHREAD_VISIBILITY DLTHREAD_TYPE_T DLTHREAD_PUB(dlthread_sumreduce_s)(
    DLTHREAD_TYPE_T const val,
    size_t const group,
    size_t const ngroup,
    dlthread_comm_t const comm)
{
  size_t i, g, nbytes;
  DLTHREAD_TYPE_T sum;
  DLTHREAD_TYPE_T * buf, * seg;
  size_t * gid;

  size_t const myid = dlthread_get_id(comm);
  size_t const nthreads = dlthread_get_nthreads(comm);

  nbytes = (sizeof(DLTHREAD_TYPE_T)*nthreads) + \
      (sizeof(DLTHREAD_TYPE_T)*ngroup) + (sizeof(size_t)*nthreads);

  buf = dlthread_get_buffer(nbytes,comm);
  seg = (DLTHREAD_TYPE_T*)(buf + nthreads); 
  gid = (size_t*)(seg + ngroup);

  buf[myid] = val;
  gid[myid] = group;

  dlthread_barrier(comm);

  /* works for small numbers of threads and groups */
  if (myid == 0) {
    for (g=0;g<ngroup;++g) {
      seg[g] = 0;
    }
    for (i=0;i<nthreads;++i) {
      g = gid[i];
      seg[g] += buf[i];
    }
  }
  dlthread_barrier(comm);

  sum = seg[group];

  dlthread_barrier(comm);

  return sum;
}


DLTHREAD_VISIBILITY DLTHREAD_TYPE_T DLTHREAD_PUB(dlthread_maxreduce_value)(
    DLTHREAD_TYPE_T const val,
    dlthread_comm_t const comm)
{
  size_t i;
  DLTHREAD_TYPE_T max;
  DLTHREAD_TYPE_T * buf;

  size_t const myid = dlthread_get_id(comm);
  size_t const nthreads = dlthread_get_nthreads(comm);

  buf = dlthread_get_buffer(sizeof(DLTHREAD_TYPE_T)*nthreads,comm);

  buf[myid] = val;

  dlthread_barrier(comm);
  /* works for small numbers of threads */
  if (myid == 0) {
    max = val;
    for (i=1;i<nthreads;++i) {
      if (max < buf[i]) {
        max = buf[i];
      }
    }
    buf[0] = max;
  }
  dlthread_barrier(comm);

  max = buf[0];

  dlthread_barrier(comm);

  return max;
}


DLTHREAD_VISIBILITY DLTHREAD_TYPE_T DLTHREAD_PUB(dlthread_minreduce_value)(
    DLTHREAD_TYPE_T const val,
    dlthread_comm_t const comm)
{
  size_t i;
  DLTHREAD_TYPE_T min;
  DLTHREAD_TYPE_T * buf;

  size_t const myid = dlthread_get_id(comm);
  size_t const nthreads = dlthread_get_nthreads(comm);

  buf = dlthread_get_buffer(sizeof(DLTHREAD_TYPE_T)*nthreads,comm);

  buf[myid] = val;

  dlthread_barrier(comm);
  /* works for small numbers of threads */
  if (myid == 0) {
    min = val;
    for (i=1;i<nthreads;++i) {
      if (min < buf[i]) {
        min = buf[i];
      }
    }
    buf[0] = min;
  }
  dlthread_barrier(comm);

  min = buf[0];

  dlthread_barrier(comm);

  return min;
}


DLTHREAD_VISIBILITY size_t DLTHREAD_PUB(dlthread_maxreduce_index)(
    DLTHREAD_TYPE_T const val,
    dlthread_comm_t const comm)
{
  size_t i, j;
  size_t * maxidx;
  DLTHREAD_TYPE_T max;
  DLTHREAD_TYPE_T * buf;

  size_t const myid = dlthread_get_id(comm);
  size_t const nthreads = dlthread_get_nthreads(comm);

  buf = dlthread_get_buffer(sizeof(DLTHREAD_TYPE_T)*nthreads+sizeof(size_t), \
      comm);
  maxidx = (size_t*)(buf + nthreads);

  buf[myid] = val;

  dlthread_barrier(comm);
  /* works for small numbers of threads */
  if (myid == 0) {
    j = 0;
    max = val;
    for (i=1;i<nthreads;++i) {
      if (max < buf[i]) {
        j = i;
        max = buf[i];
      }
    }
    maxidx[0] = j;
  }
  dlthread_barrier(comm);

  j = maxidx[0];

  dlthread_barrier(comm);

  return j;
}



DLTHREAD_VISIBILITY size_t DLTHREAD_PUB(dlthread_minreduce_index)(
    DLTHREAD_TYPE_T const val,
    dlthread_comm_t const comm)
{
  size_t i, j;
  size_t * minidx;
  DLTHREAD_TYPE_T min;
  DLTHREAD_TYPE_T * buf;

  size_t const myid = dlthread_get_id(comm);
  size_t const nthreads = dlthread_get_nthreads(comm);

  buf = dlthread_get_buffer(sizeof(DLTHREAD_TYPE_T)*nthreads+sizeof(size_t), \
      comm);
  minidx = (size_t*)(buf + nthreads);

  buf[myid] = val;

  dlthread_barrier(comm);
  /* works for small numbers of threads */
  if (myid == 0) {
    j = 0;
    min = val;
    for (i=1;i<nthreads;++i) {
      if (min > buf[i]) {
        j = i;
        min = buf[i];
      }
    }
    minidx[0] = j;
  }
  dlthread_barrier(comm);

  j = minidx[0];

  dlthread_barrier(comm);

  return j;
}


DLTHREAD_VISIBILITY size_t DLTHREAD_PUB(dlthread_broadcast)(
    DLTHREAD_TYPE_T const val,
    size_t const root,
    dlthread_comm_t const comm)
{
  size_t i;
  DLTHREAD_TYPE_T out;
  DLTHREAD_TYPE_T * buf;

  size_t const myid = dlthread_get_id(comm);
  size_t const nthreads = dlthread_get_nthreads(comm);

  buf = dlthread_get_buffer(sizeof(DLTHREAD_TYPE_T)*nthreads,comm);

  /* small number of threads */
  if (myid == root) {
    for (i=0;i<nthreads;++i) {
      buf[i] = val;
    }
  }

  dlthread_barrier(comm);

  out = buf[myid];

  dlthread_barrier(comm);

  return out;
}


DLTHREAD_VISIBILITY void DLTHREAD_PUB(dlthread_sumareduce)(
    DLTHREAD_TYPE_T * const val,
    size_t const n,
    dlthread_comm_t const comm)
{
  size_t i, j, t, ei;
  DLTHREAD_TYPE_T ** buf;

  static size_t const chunk = 64 / sizeof(DLTHREAD_TYPE_T);
  DLTHREAD_TYPE_T sum[chunk];

  size_t const myid = dlthread_get_id(comm);
  size_t const nthreads = dlthread_get_nthreads(comm);
  size_t const start = size_chunkstart(myid,nthreads,n); \
  size_t const end = start + size_chunksize(myid,nthreads,n); \

  if (0) {
  if (nthreads > 128 && n / nthreads < chunk) {
    DLTHREAD_PRI(dlthread_sumdreduce)(val,n,comm);
  } else {
    buf = dlthread_get_buffer(sizeof(DLTHREAD_TYPE_T*)*nthreads,comm);
    buf[myid] = val;

    dlthread_barrier(comm);
    for (j=start;j<end;j+=chunk) {
      ei = dl_min(chunk,end-j);
      memcpy(sum,val+j,ei*sizeof(DLTHREAD_TYPE_T));
      for (t=(myid+1)%nthreads;t!=myid;t=((t+1)%nthreads)) {
        for (i=0;i<ei;++i) {
          sum[i] += buf[t][j+1];
        }
      }
      memcpy(val+j,sum,ei*sizeof(DLTHREAD_TYPE_T));
      for (t=(myid+1)%nthreads;t!=myid;t=((t+1)%nthreads)) {
        memcpy(buf[t]+j,sum,ei*sizeof(DLTHREAD_TYPE_T));
      }
    }
    dlthread_barrier(comm);
  } 
  }else {
    buf = dlthread_get_buffer(sizeof(DLTHREAD_TYPE_T*)*nthreads,comm);
    buf[myid] = val;
    dlthread_barrier(comm);
    if (myid == 0) {
      for (t=1;t<nthreads;++t) {
        for (i=0;i<n;++i) {
          buf[0][i] += buf[t][i];
        }
      }
      for (t=1;t<nthreads;++t) {
        memcpy(buf[t],buf[0],n*sizeof(DLTHREAD_TYPE_T));
      }
    }
    dlthread_barrier(comm);
  }
}


DLTHREAD_VISIBILITY void DLTHREAD_PUB(dlthread_maxareduce)(
    DLTHREAD_TYPE_T * const val,
    size_t const n,
    dlthread_comm_t const comm)
{
  size_t i, t;
  DLTHREAD_TYPE_T ** buf;

  size_t const myid = dlthread_get_id(comm);
  size_t const nthreads = dlthread_get_nthreads(comm);

  buf = dlthread_get_buffer(sizeof(DLTHREAD_TYPE_T*)*nthreads,comm);
  buf[myid] = val;
  dlthread_barrier(comm);
  if (myid == 0) {
    for (t=1;t<nthreads;++t) {
      for (i=0;i<n;++i) {
        if (buf[0][i] < buf[t][i]) {
          buf[0][i] = buf[t][i];
        }
      }
    }
    for (t=1;t<nthreads;++t) {
      memcpy(buf[t],buf[0],n*sizeof(DLTHREAD_TYPE_T));
    }
  }
  dlthread_barrier(comm);
}


DLTHREAD_VISIBILITY void DLTHREAD_PUB(dlthread_minareduce)(
    DLTHREAD_TYPE_T * const val,
    size_t const n,
    dlthread_comm_t const comm)
{
  size_t i, t;
  DLTHREAD_TYPE_T ** buf;

  size_t const myid = dlthread_get_id(comm);
  size_t const nthreads = dlthread_get_nthreads(comm);

  buf = dlthread_get_buffer(sizeof(DLTHREAD_TYPE_T*)*nthreads,comm);
  buf[myid] = val;
  dlthread_barrier(comm);
  if (myid == 0) {
    for (t=1;t<nthreads;++t) {
      for (i=0;i<n;++i) {
        if (buf[0][i] > buf[t][i]) {
          buf[0][i] = buf[t][i];
        }
      }
    }
    for (t=1;t<nthreads;++t) {
      memcpy(buf[t],buf[0],n*sizeof(DLTHREAD_TYPE_T));
    }
  }
  dlthread_barrier(comm);
}


DLTHREAD_VISIBILITY void DLTHREAD_PUB(dlthread_prefixsum)(
    DLTHREAD_TYPE_T * const val,
    size_t const n,
    DLTHREAD_TYPE_T * const gval,
    dlthread_comm_t const comm)
{
  size_t i, j, t;
  DLTHREAD_TYPE_T ** buf;

  size_t const myid = dlthread_get_id(comm);
  size_t const nthreads = dlthread_get_nthreads(comm);
  size_t const step = CACHE_LINE_SIZE/sizeof(DLTHREAD_TYPE_T);

  buf = dlthread_get_buffer(sizeof(DLTHREAD_TYPE_T*)*(nthreads+1),comm);
  buf[myid] = val;
  if (myid == 0) {
    if (gval) {
      buf[nthreads] = gval;
    } else {
      buf[nthreads] = malloc(sizeof(DLTHREAD_TYPE_T)*n);
    }
  }
  dlthread_barrier(comm);
  /* column wise prefix sums */
  for (i=myid*step;i<n;i+=step*nthreads) {
    for (t=1;t<nthreads;++t) {
      for (j=i;j<dl_min(i+step,n);++j) {
        buf[t][j] += buf[t-1][j];
      }
    }
  }
  dlthread_barrier(comm);
  /* global prefix sum */
  if (myid == 0) {
    buf[nthreads][0] = 0;
    for (i=1;i<n;++i) {
      buf[nthreads][i] = buf[nthreads][i-1] + buf[nthreads-1][i-1]; 
    }
  }
  dlthread_barrier(comm);
  /* offset of column wise sums and shift */ 
  for (i=myid*step;i<n;i+=step*nthreads) {
    for (t=nthreads;t>1;) {
      --t;
      for (j=i;j<dl_min(i+step,n);++j) {
        buf[t][j] = buf[t-1][j] + buf[nthreads][j];
      }
    }
    for (j=i;j<dl_min(i+step,n);++j) {
      buf[0][j] = buf[nthreads][j];
    }
  }
  dlthread_barrier(comm);
  if (myid == 0) {
    if (!gval) {
      dl_free(buf[nthreads]);
    }
  }
}




#if 0

#define dlthread_prefixsum_reduce(myid,values,nvalues,partial,buffer,nthreads, \
    type) \
  do { \
    DL_ASSERT(nthreads>0,"Must have positive number of threads\n"); \
    _Pragma("omp barrier") \
    size_t _i; \
    size_t _mystart = ((nvalues/nthreads)*myid) + \
      dl_min((size_t)myid,(size_t)(nvalues%nthreads)); \
    size_t _mysize = (nvalues/nthreads) + \
      (((size_t)myid < (size_t)(nvalues%nthreads)) ? 1U : 0U); \
    for (_i=_mystart+1U;_i<_mystart+_mysize;++_i) { \
      values[_i] += values[_i-1U]; \
    } \
    partial[myid] = values[_i-1U]; \
    _Pragma("omp barrier") \
    for (_i=1U;_i<(size_t)nthreads;_i<<=1U) { \
      if (((size_t)myid)>=_i) { \
        buffer[myid] = partial[myid] + partial[myid-_i]; \
      } \
      _Pragma("omp barrier") \
      _Pragma("omp single") \
      { \
        memcpy(partial+1,buffer+1,sizeof(type)*(nthreads-1)); \
      } \
    } \
    for (_i=_mystart;_i<_mystart+_mysize;++_i) { \
      values[_i] += partial[myid] - values[_mystart+_mysize-1]; \
    } \
    _Pragma ("omp barrier") \
  } while(0)

#endif


#undef DLTHREAD_PRE2
#undef DLTHREAD_PRE1
#undef DLTHREAD_PUB
#undef DLTHREAD_PRI


#ifdef DLTHREAD_DEFVIS
  #undef DLTHREAD_DEFVIS
  #undef DLTHREAD_VISIBILITY
#endif


