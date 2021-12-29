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

// Modified for Gmsh (C++ and 64 bit compatibility)

#include "GmshConfig.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif
#include <stdio.h>
#include "avl.h"
#include "MallocUtils.h"

#define ALLOC(type, number)  (type *) Malloc((unsigned) sizeof(type) * number)
#define FREE(item)           (void) Free(item)
#define XRNMAX(a,b)          ((a) > (b) ? (a) : (b))
#define HEIGHT(node)         (node == NIL(avl_node) ? -1 : (node)->height)
#define BALANCE(node)        (HEIGHT((node)->right) - HEIGHT((node)->left))

#define compute_height(node) {                          \
    int x=HEIGHT(node->left), y=HEIGHT(node->right);    \
    (node)->height = XRNMAX(x,y) + 1;                   \
}

#define COMPARE(key, nodekey, compare)                  \
    ((compare == avl_numcmp) ?                          \
        (intptr_t) key - (intptr_t) nodekey :                   \
        (*compare)(key, nodekey))

static void avl_record_gen_forward(avl_node *node, avl_generator *gen);
static void avl_record_gen_backward(avl_node *node, avl_generator *gen);
static avl_node *find_rightmost(avl_node **node_p);
static void do_rebalance(avl_node ***stack_nodep, int stack_n);
static void rotate_left(avl_node **node_p);
static void rotate_right(avl_node **node_p);
static void free_entry(avl_node *node, void (*key_free)(void *key),
                       void (*value_free)(void *value));
static avl_node *new_node(void *key, void *value);
static int do_check_tree(avl_node *node, int (*compar)(const void *key1, const void *key2),
                         int *error);


avl_tree *avl_init_table(int (*compar)(const void *key1, const void *key2))
{
    avl_tree *tree;

    tree = ALLOC(avl_tree, 1);
    tree->root = NIL(avl_node);
    tree->compar = compar;
    tree->num_entries = 0;
    return tree;
}

int avl_lookup(avl_tree *tree, void *key, void **value_p)
{
    avl_node *node;
    int (*compare)(const void*, const void *) = tree->compar, diff;

    node = tree->root;
    while (node != NIL(avl_node)) {
        diff = COMPARE(key, node->key, compare);
        if (diff == 0) {
            /* got a match, give the user a 'value' only if non-null */
            if (value_p != NIL(void *)) *value_p = node->value;
            return 1;
        }
        node = (diff < 0) ? node->left : node->right;
    }
    return 0;
}

int avl_insert(avl_tree *tree, void *key, void *value)
{
    avl_node **node_p, *node;
    int stack_n = 0;
    int (*compare)(const void*, const void *) = tree->compar;
    avl_node **stack_nodep[32];
    int diff, status;

    node_p = &tree->root;

    /* walk down the tree (saving the path); stop at insertion point */
    status = 0;
    while ((node = *node_p) != NIL(avl_node)) {
        stack_nodep[stack_n++] = node_p;
        diff = COMPARE(key, node->key, compare);
        if (diff == 0) status = 1;
        node_p = (diff < 0) ? &node->left : &node->right;
    }

    /* insert the item and re-balance the tree */
    *node_p = new_node(key, value);
    do_rebalance(stack_nodep, stack_n);
    tree->num_entries++;
    tree->modified = 1;
    return status;
}

int avl_delete(avl_tree *tree, void **key_p, void **value_p)
{
    avl_node **node_p, *node, *rightmost;
    int stack_n = 0;
    void *key = *key_p;
    int (*compare)(const void*, const void*) = tree->compar, diff;
    avl_node **stack_nodep[32];

    node_p = &tree->root;

    /* Walk down the tree saving the path; return if not found */
    while ((node = *node_p) != NIL(avl_node)) {
        diff = COMPARE(key, node->key, compare);
        if (diff == 0) goto delete_item;
        stack_nodep[stack_n++] = node_p;
        node_p = (diff < 0) ? &node->left : &node->right;
    }
    return 0;           /* not found */

    /* prepare to delete node and replace it with rightmost of left tree */
  delete_item:
    *key_p = node->key;
    if (value_p != nullptr) *value_p = node->value;
    if (node->left == NIL(avl_node)) {
        *node_p = node->right;
    } else {
        rightmost = find_rightmost(&node->left);
        rightmost->left = node->left;
        rightmost->right = node->right;
        rightmost->height = -2;         /* mark bogus height for do_rebal */
        *node_p = rightmost;
        stack_nodep[stack_n++] = node_p;
    }
    FREE(node);

    /* work our way back up, re-balancing the tree */
    do_rebalance(stack_nodep, stack_n);
    tree->num_entries--;
    tree->modified = 1;
    return 1;
}

static void avl_record_gen_forward(avl_node *node, avl_generator *gen)
{
    if (node != NIL(avl_node)) {
        avl_record_gen_forward(node->left, gen);
        gen->nodelist[gen->count++] = node;
        avl_record_gen_forward(node->right, gen);
    }
}

static void avl_record_gen_backward(avl_node *node, avl_generator *gen)
{
    if (node != NIL(avl_node)) {
        avl_record_gen_backward(node->right, gen);
        gen->nodelist[gen->count++] = node;
        avl_record_gen_backward(node->left, gen);
    }
}

avl_generator *avl_init_gen(avl_tree *tree, int dir)
{
    avl_generator *gen;

    /* what a hack */
    gen = ALLOC(avl_generator, 1);
    gen->tree = tree;
    gen->nodelist = ALLOC(avl_node *, avl_count(tree));
    gen->count = 0;
    if (dir == AVL_FORWARD) {
        avl_record_gen_forward(tree->root, gen);
    } else {
        avl_record_gen_backward(tree->root, gen);
    }
    gen->count = 0;

    /* catch any attempt to modify the tree while we generate */
    tree->modified = 0;
    return gen;
}

int avl_gen(avl_generator *gen, void **key_p, void **value_p)
{
    avl_node *node;

    if (gen->count == gen->tree->num_entries) {
        return 0;
    } else {
        node = gen->nodelist[gen->count++];
        if (key_p != NIL(void *)) *key_p = node->key;
        if (value_p != NIL(void *)) *value_p = node->value;
        return 1;
    }
}

void avl_free_gen(avl_generator *gen)
{
    FREE(gen->nodelist);
    FREE(gen);
}

static avl_node *find_rightmost(avl_node **node_p)
{
    avl_node *node;
    int stack_n = 0;
    avl_node **stack_nodep[32];

    node = *node_p;
    while (node->right != NIL(avl_node)) {
        stack_nodep[stack_n++] = node_p;
        node_p = &node->right;
        node = *node_p;
    }
    *node_p = node->left;

    do_rebalance(stack_nodep, stack_n);
    return node;
}

static void do_rebalance(avl_node ***stack_nodep, int stack_n)
{
    avl_node **node_p, *node;
    int hl, hr;
    int height;

    /* work our way back up, re-balancing the tree */
    while (--stack_n >= 0) {
        node_p = stack_nodep[stack_n];
        node = *node_p;
        hl = HEIGHT(node->left);                /* watch for NIL */
        hr = HEIGHT(node->right);               /* watch for NIL */
        if ((hr - hl) < -1) {
            rotate_right(node_p);
        } else if ((hr - hl) > 1) {
            rotate_left(node_p);
        } else {
            height = XRNMAX(hl, hr) + 1;
            if (height == node->height) break;
            node->height = height;
        }
    }
}

static void rotate_left(avl_node **node_p)
{
    avl_node *old_root = *node_p, *new_root, *new_right;

    if (BALANCE(old_root->right) >= 0) {
        *node_p = new_root = old_root->right;
        old_root->right = new_root->left;
        new_root->left = old_root;
    } else {
        new_right = old_root->right;
        *node_p = new_root = new_right->left;
        old_root->right = new_root->left;
        new_right->left = new_root->right;
        new_root->right = new_right;
        new_root->left = old_root;
        compute_height(new_right);
    }
    compute_height(old_root);
    compute_height(new_root);
}

static void rotate_right(avl_node **node_p)
{
    avl_node *old_root = *node_p, *new_root, *new_left;

    if (BALANCE(old_root->left) <= 0) {
        *node_p = new_root = old_root->left;
        old_root->left = new_root->right;
        new_root->right = old_root;
    } else {
        new_left = old_root->left;
        *node_p = new_root = new_left->right;
        old_root->left = new_root->right;
        new_left->right = new_root->left;
        new_root->left = new_left;
        new_root->right = old_root;
        compute_height(new_left);
    }
    compute_height(old_root);
    compute_height(new_root);
}


int avl_extremum(avl_tree *tree, int side, void **value_p)
{
    avl_node *node;

    node = tree->root;
    if (node == NIL(avl_node)) return 0;

    if (side == AVL_MOST_LEFT)
      while (node->left != NIL(avl_node)) node = node->left;
    else
      while (node->right != NIL(avl_node)) node = node->right;

    if (value_p != NIL(void *)) {
      *value_p = node->value;
      return 1;
    }
    return 0;
}

static void free_entry(avl_node *node, void (*key_free)(void *key), void (*value_free)(void *value))
{
    if (node != NIL(avl_node)) {
        free_entry(node->left, key_free, value_free);
        free_entry(node->right, key_free, value_free);
        if (key_free != nullptr) (*key_free)(node->key);
        if (value_free != nullptr) (*value_free)(node->value);
        FREE(node);
    }
}

void avl_free_table(avl_tree *tree, void (*key_free)(void *key), void (*value_free)(void *value))
{
    free_entry(tree->root, key_free, value_free);
    FREE(tree);
}

int avl_count(avl_tree *tree)
{
    return tree->num_entries;
}

static avl_node *new_node(void *key, void *value)
{
    avl_node *newn;

    newn = ALLOC(avl_node, 1);
    newn->key = key;
    newn->value = value;
    newn->height = 0;
    newn->left = newn->right = NIL(avl_node);
    return newn;
}

int avl_numcmp(const void *x, const void*y)
{
    return (intptr_t) x - (intptr_t) y;
}

int avl_check_tree(avl_tree *tree)
{
    int error = 0;
    (void) do_check_tree(tree->root, tree->compar, &error);
    return error;
}

static int do_check_tree(avl_node *node,
                         int (*compar)(const void *key1, const void *key2), int *error)
{
    int l_height, r_height, comp_height, bal;

    if (node == NIL(avl_node)) {
        return -1;
    }

    r_height = do_check_tree(node->right, compar, error);
    l_height = do_check_tree(node->left, compar, error);

    comp_height = XRNMAX(l_height, r_height) + 1;
    bal = r_height - l_height;

    if (comp_height != node->height) {
        (void) printf("Bad height for %p: computed=%d stored=%d\n",
                      (void*)node, comp_height, node->height);
        ++*error;
    }

    if (bal > 1 || bal < -1) {
        (void) printf("Out of balance at node %p, balance = %d\n",
                      (void*)node, bal);
        ++*error;
    }

    if (node->left != NIL(avl_node) &&
                    (*compar)(node->left->key, node->key) > 0) {
        (void) printf("Bad ordering between %p and %p",
                      (void*)node, (void*)node->left);
        ++*error;
    }

    if (node->right != NIL(avl_node) &&
                    (*compar)(node->key, node->right->key) > 0) {
        (void) printf("Bad ordering between %p and %p",
                      (void*)node, (void*)node->right);
        ++*error;
    }

    return comp_height;
}
