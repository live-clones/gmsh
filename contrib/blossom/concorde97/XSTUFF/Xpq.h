#ifndef __XPQ_H
#define __XPQ_H

#include "Xpqsets.h"

#define MAGICNODE 0

typedef struct PQ_node {
    int number;
    struct PQ_node *next;
    struct Xedge *base_edge;
    int dir_nodenum;
    int labeled_children_count;
    int magiclabel;
    struct  Xintptr *toroot;
    struct Xneckedgeptr *adj;
    struct Xneckedge *entered;
    struct {
        struct PQ_node *parent;
        int rank;
    } setinfo;

    PQ_elem queue_elem;

/* the size of the children_set will not necessarily be correct for Q nodes */
    PQ_set children_set;
    PQ_elem children_elem;

    PQ_set full_children_set;
    PQ_elem full_children_elem;

    PQ_set partial_children_set;
    PQ_elem partial_children_elem;

    PQ_elem blocked_elem;

    PQ_elem leaves_elem;

    struct PQ_node *parent;

    int pertinent_child_count;
    int pertinent_leaf_count;

    int mark;
#define IS_UNINITIALIZED(x) ((x)->mark < markbase)
#define UNMARKED (markbase+0)
#define QUEUED (markbase+1)
#define BLOCKED (markbase+2)
#define UNBLOCKED (markbase+3)

    int type;
    int parenttype;
#define LEAF_NODE 0
#define P_NODE 1
#define Q_NODE 2
#define DIR_NODE 3

    int label;
#define IS_EMPTY(x) ((x)->label <= markbase)
#define EMPTY (markbase + 0)
#define PARTIAL (markbase + 1)
#define FULL (markbase + 2)

} PQ_node;


#define BUBBLE_SUCCESS 0
#define REDUCE_SUCCESS 0
#define BUBBLE_NO_SOL 1
#define REDUCE_NO_SOL 2

#ifdef CC_PROTOTYPE_ANSI

/* pq.c */

void
    XPQ_free_all (PQ_node *, int),
    XPQ_save_tree_free (PQ_node *);

PQ_node
    *XPQ_process (PQ_node *),
    *XPQ_init_tree (PQ_node *),
    *XPQ_find_root (PQ_node *),
    *XPQ_save_tree (PQ_node *),
    *XPQ_restore_tree (PQ_node *, int);

#else

/* pq.c */

void
    XPQ_free_all (),
    XPQ_save_tree_free ();

PQ_node
    *XPQ_process (),
    *XPQ_init_tree (),
    *XPQ_find_root (),
    *XPQ_save_tree (),
    *XPQ_restore_tree ();

#endif

#endif  /* __XPQ_H */
