/**
 * @file dltree_funcs.h
 * @brief Tree functions
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-03
 */




/* this is ugly but neccessary */
#define DLTREE_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLTREE_PRE1(prefix,suffix) DLTREE_PRE2(prefix,suffix)
#define DLTREE_PUB(name) DLTREE_PRE1(DLTREE_PREFIX,name)
#define DLTREE_PRI(name) \
  DLTREE_PRE1(_,DLTREE_PRE1(DLTREE_PREFIX,name))



#define DLMEM_PREFIX DLTREE_PRI(tree_node)
#define DLMEM_TYPE_T DLTREE_PRI(tree_node_t)
#define DLMEM_STATIC
#include "dlmem_headers.h"
#undef DLMEM_STATIC
#undef DLMEM_TYPE_T
#undef DLMEM_PREFIX


#define DLMEM_PREFIX DLTREE_PUB(tree)
#define DLMEM_TYPE_T DLTREE_PUB(tree_t)
#define DLMEM_STATIC
#include "dlmem_headers.h"
#undef DLMEM_STATIC
#undef DLMEM_TYPE_T
#undef DLMEM_PREFIX




/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/


static void DLTREE_PRI(tree_node_free)(DLTREE_PRI(tree_node_t) * node)
{
  size_t i;
  for (i=0;i<node->nchildren;++i) {
    DLTREE_PRI(tree_node_free)(node->children[i]); 
  }
  dl_free(node);
}


static DLTREE_VAL_T DLTREE_PRI(tree_find)(
    DLTREE_KEY_T const key, 
    DLTREE_PRI(tree_node_t) * const node, 
    int (*compar)(DLTREE_KEY_T const, DLTREE_KEY_T const))
{
  int r;
  size_t i,j,k;

  j=i=0;
  k=node->nelements;
  while (i < k) {
    j = (i+k)/2;
    r = compar(key,node->key[j]);
    if (r < 0) {
      k = j; 
    } else if (r > 0) {
      i = j+1;
    } else {
      /* key collision */
      return node->val[j];
    }
  }
  j = (i+k)/2;

  if (node->nchildren > 0) {
    DL_ASSERT(node->nchildren == node->nelements+1,"Wrong number of "
        "children\n");
    return DLTREE_PRI(tree_find)(key,node->children[j],compar);
  } else {
    return (DLTREE_VAL_T)-1;
  }
}


static void DLTREE_PRI(tree_shift)(
    size_t const idx, 
    DLTREE_PRI(tree_node_t) * const node)
{
  size_t i;

  DL_ASSERT(node->nelements < DLTREE_WIDTH,"Attempting to shift a full "
      "node\n");

  i=node->nelements;
  while (i > idx) {
    node->key[i] = node->key[i-1];
    node->val[i] = node->val[i-1];
    if (node->nchildren > 0) {
      node->children[i+1] = node->children[i];
    }
    --i;
  }
}


static void DLTREE_PRI(tree_split)(
    size_t const idx, 
    DLTREE_PRI(tree_node_t) * const node)
{
  size_t i, n;
  DLTREE_KEY_T key;
  DLTREE_VAL_T val;
  DLTREE_PRI(tree_node_t) * newchild, * oldchild; 

  newchild = DLTREE_PRI(tree_node_alloc)(1);
  oldchild = node->children[idx];
  
  newchild->nelements=0;
  newchild->nchildren=0;

  /* move keys and values to new child */
  n = oldchild->nelements / 2;
  for (i=n+1;i<oldchild->nelements;++i) {
    newchild->key[newchild->nelements] = oldchild->key[i];
    newchild->val[newchild->nelements] = oldchild->val[i];
    ++newchild->nelements;
  }
  oldchild->nelements = n;

  /* save the moving child */
  key = oldchild->key[n];
  val = oldchild->val[n]; 

  /* move children to new child */
  n = oldchild->nchildren / 2;
  for (i=n;i<oldchild->nchildren;++i) {
    newchild->children[newchild->nchildren] = oldchild->children[i];
    ++newchild->nchildren;
  }
  oldchild->nchildren = n;

  /* make room for the upgraded node and the new child */
  DLTREE_PRI(tree_shift)(idx,node);
  ++node->nelements;
  if (node->nchildren > 0) {
    ++node->nchildren;
  }

  /* insert the upgraded node and the new child */
  node->key[idx] = key;
  node->val[idx] = val;
  node->children[idx+1] = newchild;
}


static int DLTREE_PRI(tree_insert)(
    DLTREE_KEY_T const key, 
    DLTREE_VAL_T const val, 
    DLTREE_PRI(tree_node_t) * const node,
    int (*compar)(DLTREE_KEY_T const, DLTREE_KEY_T const))
{
  int r;
  size_t i,j,k;

  DL_ASSERT(node->nelements < DLTREE_WIDTH,"Encountered full node\n");

  /* do a binary search to find where the key goes */
  r = -1; /* default for an empty tree */
  j = i =0;
  k=node->nelements;
  while (i < k) {
    j = (i+k)/2;
    r = compar(key,node->key[j]);
    if (r < 0) {
      k = j; 
    } else if (r > 0) {
      i = j+1;
    } else {
      /* key collision */
      return 0;
    }
  }
  j = (i+k)/2;
  DL_ASSERT(r != 0,"Didn't exit on found key\n");

  if (node->nchildren > 0) {
    /* traverse down j */
    DL_ASSERT(node->nchildren == node->nelements+1,"Incorrect number of "
        "children\n");
    if (node->children[j]->nelements == DLTREE_WIDTH) {
      /* split the full node */
      DLTREE_PRI(tree_split)(j,node);

      /* see which resulting child we want */
      if (compar(key,node->key[j]) > 0) {
        ++j;
      }
    }
    return DLTREE_PRI(tree_insert)(key,val,node->children[j],compar);
  } else {
    /* insert in this node */
    if (j < node->nelements) {
      DLTREE_PRI(tree_shift)(j,node);
    }
    node->key[j] = (DLTREE_KEY_T)key;
    node->val[j] = (DLTREE_VAL_T)val;
    ++node->nelements;

    return 1;
  }
}




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


#ifndef DLTREE_VISIBILITY
  #define DLTREE_VISIBILITY
  #define DLTREE_DEFVIS
#endif


DLTREE_VISIBILITY DLTREE_PUB(tree_t) * DLTREE_PUB(tree_create)(
    int (*compar)(DLTREE_KEY_T const, DLTREE_KEY_T const))
{
  DLTREE_PUB(tree_t) * tree;

  tree = DLTREE_PUB(tree_alloc)(1);
  tree->root = DLTREE_PRI(tree_node_alloc(1));
  tree->root->nelements = 0;
  tree->root->nchildren = 0;
  tree->size = 0;
  tree->compar = compar;

  return tree;
}


DLTREE_VISIBILITY void DLTREE_PUB(tree_free)(
    DLTREE_PUB(tree_t) * tree)
{
  DLTREE_PRI(tree_node_free)(tree->root); 
  dl_free(tree);
}


DLTREE_VISIBILITY int DLTREE_PUB(tree_add)(
    DLTREE_KEY_T const key, 
    DLTREE_VAL_T const val, 
    DLTREE_PUB(tree_t) * const tree)
{
  int r;
  DLTREE_PRI(tree_node_t) * root;

  if (tree->root->nelements == DLTREE_WIDTH) {
    root = tree->root;
    tree->root = DLTREE_PRI(tree_node_alloc)(1);
    tree->root->nelements = 0;
    tree->root->nchildren = 1;
    tree->root->children[0] = root;
    DLTREE_PRI(tree_split)(0,tree->root);
  } 
  r = DLTREE_PRI(tree_insert)(key,val,tree->root,tree->compar);
  if (r) {
    ++tree->size;
  }
  return r;
}


DLTREE_VISIBILITY DLTREE_VAL_T DLTREE_PUB(tree_remove)(
    DLTREE_KEY_T const key, 
    DLTREE_PUB(tree_t) * const tree)
{
  /* implement me */
  return (DLTREE_VAL_T)0; 
}


DLTREE_VISIBILITY DLTREE_VAL_T DLTREE_PUB(tree_get)(
    DLTREE_KEY_T const key, 
    DLTREE_PUB(tree_t) * const tree)
{
  return DLTREE_PRI(tree_find)(key,tree->root,tree->compar);  
}


#ifdef DLMEM_DEFVIS
  #undef DLMEM_VISIBILITY
  #undef DLMEM_DEFVIS
#endif

#undef DLTREE_PUB
#undef DLTREE_PRI
#undef DLTREE_PRE1
#undef DLTREE_PRE2


