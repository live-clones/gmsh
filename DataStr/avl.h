#ifndef _AVL_H_
#define _AVL_H_

/*
 * avl package
 *
 * Copyright (c) 1988-1993, The Regents of the University of California.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose and without fee is hereby granted, provided
 * that the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of the University of California not
 * be used in advertising or publicity pertaining to distribution of 
 * the software without specific, written prior permission.  The University
 * of California makes no representations about the suitability of this
 * software for any purpose.  It is provided "as is" without express or
 * implied warranty.
 *
 * THE UNIVERSITY OF CALIFORNIA DISCLAIMS ALL WARRANTIES WITH REGARD TO 
 * THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND 
 * FITNESS, IN NO EVENT SHALL THE UNIVERSITY OF CALIFORNIA BE LIABLE FOR
 * ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF
 * CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN 
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

typedef struct avl_node_struct avl_node;
struct avl_node_struct {
  avl_node *left, *right;
  void *key;
  void *value;
  int height;
};


typedef struct avl_tree_struct avl_tree;
struct avl_tree_struct {
  avl_node *root;
  int (*compar)(const void *key1, const void *key2);
  int num_entries;
  int modified;
};


typedef struct avl_generator_struct avl_generator;
struct avl_generator_struct {
  avl_tree *tree;
  avl_node **nodelist;
  int count;
};


#define AVL_FORWARD     0
#define AVL_BACKWARD    1

#define AVL_MOST_LEFT   0
#define AVL_MOST_RIGHT  1

#define avl_is_member(tree, key)   avl_lookup(tree, key, (void **) 0)
#define NIL(type)            (type *) 0

#define avl_foreach_item(table, gen, dir, key_p, value_p)               \
    for(gen = avl_init_gen(table, dir);                                 \
            avl_gen(gen, key_p, value_p) || (avl_free_gen(gen),0);)


inline void avl_walk_forward(avl_node *node, void (*func)(void *key, void *value))
{
  if (node != NIL(avl_node)) {
    avl_walk_forward(node->left, func);
    (*func)(node->key, node->value);
    avl_walk_forward(node->right, func);
  }
}

inline void avl_walk_backward(avl_node *node, void (*func)(void *key, void *value))
{
  if (node != NIL(avl_node)) {
    avl_walk_backward(node->right, func);
    (*func)(node->key, node->value);
    avl_walk_backward(node->left, func);
  }
}

inline void avl_foreach(avl_tree *tree, void (*func)(void *key, void *value), int direction)
{
  if (direction == AVL_FORWARD) {
    avl_walk_forward(tree->root, func);
  } else {
    avl_walk_backward(tree->root, func);
  }
}

avl_tree *avl_init_table(int (*compar)(const void *key1, const void *key2));
int avl_lookup(avl_tree *tree, void *key, void **value_p);
int avl_insert(avl_tree *tree, void *key, void *value);
int avl_delete(avl_tree *tree, void **key_p, void **value_p);
void avl_free_table(avl_tree *tree, void (*key_free)(void *key), void (*value_free)(void *value));
int avl_count(avl_tree *tree);
int avl_check_tree(avl_tree *tree);
int avl_extremum(avl_tree *tree, int side, void **value_p);

avl_generator *avl_init_gen(avl_tree *tree, int dir);
int avl_gen(avl_generator *gen, void **key_p, void **value_p);
void avl_free_gen(avl_generator *gen);

int avl_numcmp(const void *x, const void*y);

#endif
