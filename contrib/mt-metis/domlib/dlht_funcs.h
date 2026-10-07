/**
 * @file dlht_funcs.h
 * @brief Hash table functions
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-04
 */




/* prefixing ugliness */
#define DLHT_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLHT_PRE1(prefix,suffix) DLHT_PRE2(prefix,suffix)
#define DLHT_PUB(name) DLHT_PRE1(DLHT_PREFIX,name)
#define DLHT_PRI(name) DLHT_PRE1(_,DLHT_PRE1(DLHT_PREFIX,name))


#ifndef DLHT_VISIBILITY
  #define DLHT_DEFVIS
  #define DLHT_VISIBILITY
#endif




/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/

static const DLHT_KEY_T DLHT_PUB(ht_null_key) = (DLHT_KEY_T)-1;
static const DLHT_VAL_T DLHT_PUB(ht_null_value) = (DLHT_VAL_T)-1;
static const DLHT_VAL_T DLHT_PUB(ht_fail_value) = (DLHT_VAL_T)-2;




/******************************************************************************
* MEMORY FUNCTIONS ************************************************************
******************************************************************************/


#define DLMEM_PREFIX DLHT_PRI(ht_kv)
#define DLMEM_TYPE_T DLHT_PRI(ht_kv_t)
#define DLMEM_STATIC
#include "dlmem_headers.h"
#undef DLMEM_STATIC
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T


#define DLMEM_PREFIX DLHT_PUB(ht)
#define DLMEM_TYPE_T DLHT_PUB(ht_t)
#define DLMEM_STATIC
#include "dlmem_headers.h"
#undef DLMEM_STATIC
#undef DLMEM_PREFIX
#undef DLMEM_TYPE_T



/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


static int const DLHT_PRI(NULL_NEXT) = -1;




/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


/**
 * @brief Releases the chained element at index cidx
 *
 * @param cidx The chain index to release.
 * @param map The map to release the chain index from.
 */
static void DLHT_PRI(ht_fixchain)(
    int const cidx, 
    DLHT_PUB(ht_t) * const map)
{
  size_t hk;
  DLHT_PRI(ht_kv_t) * oldkv;

  DL_ASSERT(cidx >= 0, "Bad chain index passed to fixchain\n");

  --map->cidx;

  if (cidx != map->cidx) {
    /* move the last element into the place of the released chain index */
    map->chain[cidx] = map->chain[map->cidx];
    hk = ((size_t)map->chain[cidx].key) & map->hashmask;

    /* fix the pointer to the moved element by finding its chain */
    oldkv = map->elements+hk;
    while (oldkv->next != map->cidx) {
      DL_ASSERT(oldkv->key != DLHT_PUB(ht_null_key), \
          "cidx points to empty slot");
      DL_ASSERT(oldkv->next >= 0,"Broken chain encountered when " \
          "performing fix\n");
      DL_ASSERT(oldkv->next < map->csize,"Out of range chain index when " \
          "fixing chains\n");
      oldkv = map->chain+oldkv->next;
    }

    /* update the pointer */
    oldkv->next = cidx;
  }
}




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


DLHT_VISIBILITY DLHT_PUB(ht_t) * DLHT_PUB(ht_create)(
    size_t const size,
    int const csize)
{
  size_t i;

  DLHT_PUB(ht_t) * const map = DLHT_PUB(ht_alloc)(1);

  map->size = 0;
  map->hashsize = size_uppow2(size);
  map->maxsize = map->hashsize;
  map->hashmask = map->hashsize - 1;
  map->elements = DLHT_PRI(ht_kv_alloc)(map->maxsize);
  map->csize = csize;
  map->cidx = 0;
  map->chain = DLHT_PRI(ht_kv_alloc)(map->csize);

  /* empty my hash table */
  for (i=0;i<map->maxsize;++i) {
    map->elements[i].key = DLHT_PUB(ht_null_key);
  }

  return map;
}


DLHT_VISIBILITY DLHT_VAL_T DLHT_PUB(ht_get)(
    DLHT_KEY_T const key,
    DLHT_PUB(ht_t) const * const map)
{
  int cidx;

  size_t hk = ((size_t)key) & map->hashmask;

  DL_ASSERT(map != NULL,"Attempt to search a NULL hashmap\n");
  DL_ASSERT(key != DLHT_PUB(ht_null_key),"Attempt to search a hashmap "
      "with a null key\n");

  if (map->elements[hk].key == key) {
    /* life is good */
    return map->elements[hk].val;
  } else if (map->elements[hk].key == DLHT_PUB(ht_null_key)) {
    /* we don't have the key */
    return DLHT_PUB(ht_null_value);
  } else {
    /* search the stupid chain */
    cidx = map->elements[hk].next;
    while (cidx >= 0) {
      if (map->chain[cidx].key == key) {
        return map->chain[cidx].val;
      }
      cidx = map->chain[cidx].next;
    }
    return DLHT_PUB(ht_null_value);
  }
}


DLHT_VISIBILITY DLHT_VAL_T DLHT_PUB(ht_put)(
    DLHT_KEY_T const key, 
    DLHT_VAL_T const val, 
    DLHT_PUB(ht_t) * const map)
{
  int cidx;
  DLHT_PRI(ht_kv_t) * oldkv;
  DLHT_VAL_T oldval;
  size_t hk;

  DL_ASSERT(map != NULL,"Attempt to search a NULL hashmap\n");
  DL_ASSERT(key != DLHT_PUB(ht_null_key),"Attempt to set a null key "
      "in the hasmap\n");
  DL_ASSERT(val != DLHT_PUB(ht_null_value),"Attempt to set a null "
      "value in the hashmap\n");

  hk = ((size_t)key) & map->hashmask;

  if (map->elements[hk].key == DLHT_PUB(ht_null_key)) {
    /* new kv in empty slot */
    map->elements[hk].key = key;
    map->elements[hk].val = val;
    map->elements[hk].next = DLHT_PRI(NULL_NEXT);
    ++map->size;
    return DLHT_PUB(ht_null_value);
  } else if (map->elements[hk].key == key) {
    /* replace old kv */
    oldval = map->elements[hk].val;
    map->elements[hk].val = val;
    return oldval;
  } else {
    /* search the stupid chain */
    oldkv = map->elements+hk;
    cidx = oldkv->next;

    while (cidx >= 0) {
      if (map->chain[cidx].key == key) {
        /* replace old kv */
        oldval = map->chain[cidx].val;
        map->chain[cidx].val = val;
        return oldval;
      }
      oldkv = map->chain+cidx;
      cidx = map->chain[cidx].next;
    }

    if (map->cidx < map->csize) {
      /* add new kv to chain */
      cidx = (oldkv->next = map->cidx++);
      map->chain[cidx].key = key;
      map->chain[cidx].val = val;
      map->chain[cidx].next = DLHT_PRI(NULL_NEXT);
      ++map->size;
      return DLHT_PUB(ht_null_value);
    } else {
      /* our chain is full return an error */
      return DLHT_PUB(ht_fail_value);
    }
  }
}


DLHT_VISIBILITY DLHT_VAL_T DLHT_PUB(ht_min)(
    DLHT_KEY_T const key, 
    DLHT_VAL_T const av, 
    DLHT_PUB(ht_t) * const map)
{
  int cidx;

  size_t hk = ((size_t)key) & map->hashmask;

  DL_ASSERT(map != NULL,"Attempt to search a NULL hashmap\n");
  DL_ASSERT(key != DLHT_PUB(ht_null_key),"Attempt to search a hashmap "
      "with a null key\n");

  if (map->elements[hk].key == key) {
    /* life is good */
    if (map->chain[hk].val > av) {
      map->chain[hk].val = av;
    }
    return map->chain[hk].val;
  } else if (map->elements[hk].key == DLHT_PUB(ht_null_key)) {
    /* we don't have the key */
    DLHT_PUB(ht_put)(key,av,map);
    return av;
  } else {
    /* search the stupid chain */
    cidx = map->elements[hk].next;
    while (cidx >= 0) {
      if (map->chain[cidx].key == key) {
        if (map->chain[cidx].val > av) {
          map->chain[cidx].val = av;
        }
        return map->chain[cidx].val;
      }
      cidx = map->chain[cidx].next;
    }
    return DLHT_PUB(ht_null_value);
  }
}


DLHT_VISIBILITY DLHT_VAL_T DLHT_PUB(ht_max)(
    DLHT_KEY_T const key, 
    DLHT_VAL_T const av, 
    DLHT_PUB(ht_t) * const map)
{
  int cidx;

  size_t hk = ((size_t)key) & map->hashmask;

  DL_ASSERT(map != NULL,"Attempt to search a NULL hashmap\n");
  DL_ASSERT(key != DLHT_PUB(ht_null_key),"Attempt to search a hashmap "
      "with a null key\n");

  if (map->elements[hk].key == key) {
    /* life is good */
    if (map->chain[hk].val < av) {
      map->chain[hk].val = av;
    }
    return map->chain[hk].val;
  } else if (map->elements[hk].key == DLHT_PUB(ht_null_key)) {
    /* we don't have the key */
    DLHT_PUB(ht_put)(key,av,map);
    return av;
  } else {
    /* search the stupid chain */
    cidx = map->elements[hk].next;
    while (cidx >= 0) {
      if (map->chain[cidx].key == key) {
        if (map->chain[cidx].val < av) {
          map->chain[cidx].val = av;
        }
        return map->chain[cidx].val;
      }
      cidx = map->chain[cidx].next;
    }
    return DLHT_PUB(ht_null_value);
  }
}


DLHT_VISIBILITY DLHT_VAL_T DLHT_PUB(ht_add)(
    DLHT_KEY_T const key, 
    DLHT_VAL_T const av, 
    DLHT_PUB(ht_t) * const map)
{
  int cidx;

  size_t hk = ((size_t)key) & map->hashmask;

  DL_ASSERT(map != NULL,"Attempt to search a NULL hashmap\n");
  DL_ASSERT(key != DLHT_PUB(ht_null_key),"Attempt to search a hashmap "
      "with a null key\n");

  if (map->elements[hk].key == key) {
    /* life is good */
    return (map->elements[hk].val += av);
  } else if (map->elements[hk].key == DLHT_PUB(ht_null_key)) {
    /* we don't have the key */
    DLHT_PUB(ht_put)(key,av,map);
    return av;
  } else {
    /* search the stupid chain */
    cidx = map->elements[hk].next;
    while (cidx >= 0) {
      if (map->chain[cidx].key == key) {
        return (map->chain[cidx].val += av);
      }
      cidx = map->chain[cidx].next;
    }
    return DLHT_PUB(ht_null_value);
  }
}


DLHT_VISIBILITY DLHT_VAL_T DLHT_PUB(ht_multiply)(
    DLHT_KEY_T const key, 
    DLHT_VAL_T const av, 
    DLHT_PUB(ht_t) * const map)
{
  int cidx;

  size_t hk = ((size_t)key) & map->hashmask;

  DL_ASSERT(map != NULL,"Attempt to search a NULL hashmap\n");
  DL_ASSERT(key != DLHT_PUB(ht_null_key),"Attempt to search a hashmap "
      "with a null key\n");

  if (map->elements[hk].key == key) {
    /* life is good */
    return (map->elements[hk].val *= av);
  } else if (map->elements[hk].key == DLHT_PUB(ht_null_key)) {
    /* we don't have the key */
    DLHT_PUB(ht_put)(key,av,map);
    return av;
  } else {
    /* search the stupid chain */
    cidx = map->elements[hk].next;
    while (cidx >= 0) {
      if (map->chain[cidx].key == key) {
        return (map->chain[cidx].val *= av);
      }
      cidx = map->chain[cidx].next;
    }
    return DLHT_PUB(ht_null_value);
  }
}


DLHT_VISIBILITY DLHT_VAL_T DLHT_PUB(ht_and)(
    DLHT_KEY_T const key, 
    DLHT_VAL_T const av, 
    DLHT_PUB(ht_t) * const map)
{
  int cidx;

  size_t hk = ((size_t)key) & map->hashmask;

  DL_ASSERT(map != NULL,"Attempt to search a NULL hashmap\n");
  DL_ASSERT(key != DLHT_PUB(ht_null_key),"Attempt to search a hashmap "
      "with a null key\n");

  if (map->elements[hk].key == key) {
    /* life is good */
    return (map->elements[hk].val = 
        (((int)map->elements[hk].val) && ((int)av)));
  } else if (map->elements[hk].key == DLHT_PUB(ht_null_key)) {
    /* we don't have the key */
    DLHT_PUB(ht_put)(key,av,map);
    return av;
  } else {
    /* search the stupid chain */
    cidx = map->elements[hk].next;
    while (cidx >= 0) {
      if (map->chain[cidx].key == key) {
        return (map->chain[cidx].val =
            (((int)map->chain[cidx].val) && ((int)av)));
      }
      cidx = map->chain[cidx].next;
    }
    return DLHT_PUB(ht_null_value);
  }
}


DLHT_VISIBILITY DLHT_VAL_T DLHT_PUB(ht_or)(
    DLHT_KEY_T const key, 
    DLHT_VAL_T const av, 
    DLHT_PUB(ht_t) * const map)
{
  int cidx;

  size_t hk = ((size_t)key) & map->hashmask;

  DL_ASSERT(map != NULL,"Attempt to search a NULL hashmap\n");
  DL_ASSERT(key != DLHT_PUB(ht_null_key),"Attempt to search a hashmap "
      "with a null key\n");

  if (map->elements[hk].key == key) {
    /* life is good */
    return (map->elements[hk].val = 
        ((int)map->elements[hk].val) || ((int)map->elements[hk].val));
  } else if (map->elements[hk].key == DLHT_PUB(ht_null_key)) {
    /* we don't have the key */
    DLHT_PUB(ht_put)(key,av,map);
    return av;
  } else {
    /* search the stupid chain */
    cidx = map->elements[hk].next;
    while (cidx >= 0) {
      if (map->chain[cidx].key == key) {
        return (map->chain[cidx].val =
            (((int)map->chain[cidx].val) || ((int)av)));
      }
      cidx = map->chain[cidx].next;
    }
    return DLHT_PUB(ht_null_value);
  }
}


DLHT_VISIBILITY DLHT_VAL_T DLHT_PUB(ht_remove)(
    DLHT_KEY_T const key,
    DLHT_PUB(ht_t) * const map)
{
  DLHT_VAL_T oldval;
  DLHT_PRI(ht_kv_t) * oldkv;
  int cidx, nidx;

  size_t hk = ((size_t)key) & map->hashmask;

  DL_ASSERT(map != NULL,"Attempt to remove from a NULL hashmap\n");
  DL_ASSERT(key != DLHT_PUB(ht_null_key),"Attempt to remove a null "
      "key in the hasmap\n");

  if (map->elements[hk].key == key) {
    /* key in the table -- remove it */
    oldval = map->elements[hk].val;
    if ((cidx = map->elements[hk].next) >= 0) { 
      map->elements[hk] = map->chain[cidx];
      DLHT_PRI(ht_fixchain)(cidx,map);
    } else {
      map->elements[hk].key = DLHT_PUB(ht_null_key);
    }
    --map->size;
    return oldval;
  } else if (map->elements[hk].key == DLHT_PUB(ht_null_key)) {
    /* key not in the table */
    return DLHT_PUB(ht_null_value);
  } else {
    /* search the stupid chain */
    oldkv = map->elements+hk;
    cidx = oldkv->next;
    while (cidx >= 0) {
      if (map->chain[cidx].key == key) {
        /* delete the kv */
        oldval = map->chain[cidx].val;
        nidx = map->chain[cidx].next;
        if (nidx >= 0) {
          map->chain[cidx] = map->chain[nidx];
          DLHT_PRI(ht_fixchain)(nidx,map);
        } else {
          oldkv->next = DLHT_PRI(NULL_NEXT);
          DLHT_PRI(ht_fixchain)(cidx,map);
        }
        --map->size;
        return oldval;
      }
      oldkv = map->chain+cidx;
      cidx = map->chain[cidx].next;
    }
    return DLHT_PUB(ht_null_value);
  }
}


DLHT_VISIBILITY int DLHT_PUB(ht_contains)(
    DLHT_KEY_T const key,
    DLHT_PUB(ht_t) const * const map)
{
  DL_ASSERT(map != NULL,"Attempt to remove from a NULL hashmap\n");
  DL_ASSERT(key != DLHT_PUB(ht_null_key),"Attempt to remove a null "
      "key in the hasmap\n");

  int cidx;

  size_t hk = ((size_t)key) & map->hashmask;

  if (map->elements[hk].key == key) {
    /* life is good */
    return 1;
  } else if (map->elements[hk].key == DLHT_PUB(ht_null_key)) {
    /* we don't have the key */
    return 0;
  } else {
    /* search the stupid chain */
    cidx = map->elements[hk].next;
    while (cidx >= 0) {
      if (map->chain[cidx].key == key) {
        return 1;
      }
      cidx = map->chain[cidx].next;
    }
    return 0;
  }
}


DLHT_VISIBILITY size_t DLHT_PUB(ht_clear)(
    DLHT_PUB(ht_t) * const map)
{
  size_t i, oldsize;

  oldsize = map->size;
  for (i=0;i<map->hashsize;++i) {
    map->elements[i].key = DLHT_PUB(ht_null_key);
  }
  map->size = 0;
  map->cidx = 0;

  return oldsize;
}


DLHT_VISIBILITY void DLHT_PUB(ht_clear_chains)(
    DLHT_PUB(ht_t) * const map)
{
  map->cidx = 0;
}


DLHT_VISIBILITY void DLHT_PUB(ht_clear_slot)(
    DLHT_KEY_T const key, 
    DLHT_PUB(ht_t) * const map)
{
  size_t hk = ((size_t)key) & map->hashmask;
  map->elements[hk].key = DLHT_PUB(ht_null_key);
  map->elements[hk].next = DLHT_PRI(NULL_NEXT);
}


DLHT_VISIBILITY int DLHT_PUB(ht_adjust_size)(
    size_t const newsize,
    DLHT_PUB(ht_t) * const map)
{
  if (map->size != 0 || map->maxsize < newsize) {
    return 0;
  } else {
    map->hashsize = size_uppow2(newsize);
    map->hashmask = map->hashsize - 1;
    return 1;
  }
}


DLHT_VISIBILITY void DLHT_PUB(ht_free)(
    DLHT_PUB(ht_t) * map)
{
  dl_free(map->elements);
  dl_free(map->chain);
  dl_free(map);
}



#ifdef DLHT_DEFVIS
  #undef DLHT_DEFVIS
  #undef DLHT_VISIBILITY
#endif



#undef DLHT_PRE1
#undef DLHT_PRE2
#undef DLHT_PUB
#undef DLHT_PRI


