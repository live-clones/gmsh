/**************************************************************************/
/*                                                                        */
/* EXPORTED FUNCTIONS:                                                    */
/*                                                                        */
/*  void                                                                  */
/*      XPQ_free_all (),                                                  */
/*      XPQ_save_tree_free ();                                            */
/*                                                                        */
/*  PQ_node                                                               */
/*      *XPQ_process (),                                                  */
/*      *XPQ_init_tree (),                                                */
/*      *XPQ_find_root (),                                                */
/*      *XPQ_save_tree (),                                                */
/*      *XPQ_restore_tree ();                                             */
/*                                                                        */
/**************************************************************************/


#include "machdefs.h"
#include "util.h"
#include "Xsubtour.h"
#include "Xpq.h"


#ifdef CC_PROTOTYPE_ANSI

static void
    PQ_tree_grab (PQ_node *, PQ_set *, PQ_node *),
    PQ_label_full (PQ_node *),
    PQ_label_partial (PQ_node *),
    PQ_collect_full_children (PQ_node *, int),
    PQ_neighbor_replace (PQ_node *, PQ_set *, PQ_node *, PQ_node *),
    PQ_merge_qnode (PQ_node *),
    PQ_replace_node (PQ_node *, PQ_node *),
    PQ_node_free (PQ_node *),
    PQ_tree_free (PQ_node *, int),
#ifndef NDEBUG
    dump_solution (PQ_node *),
    dump_subtree (PQ_node *),
#endif
    print_solution (PQ_node *, PQ_node *);

static int
    PQ_bubble (PQ_node *),
    PQ_left_end_is_full (PQ_node *);

#ifndef NDEBUG
static int
    checkout_before (PQ_node *, int),
    checkout_after (PQ_node *, int),
    check_tree (PQ_node *),
    check_node_pert (PQ_node *),
    check_node_pert_work (PQ_node *),
    check_subtree (PQ_node *),
    check_node (PQ_node *);
#endif

static PQ_node
    *PQ_reduce (PQ_node *),
    *PQ_template_l1 (PQ_node *),
    *PQ_template_p1 (PQ_node *),
    *PQ_template_p3_notroot (PQ_node *),
    *PQ_template_p5_notroot (PQ_node *),
    *PQ_template_q1 (PQ_node *),
    *PQ_template_q2 (PQ_node *),
    *PQ_template_p2_root (PQ_node *),
    *PQ_template_p4_root (PQ_node *),
    *PQ_template_p6_root (PQ_node *),
    *PQ_template_q3_root (PQ_node *),
    *PQ_collect_empty_children (PQ_node *, int),
    *PQ_next_nondir (PQ_node *, PQ_node *),
    *PQ_node_alloc_work (void),
    *PQ_node_alloc (void),
    *PQ_save_work (PQ_node *),
    *PQ_restore_work (PQ_node *, int);

#else

static void
    PQ_tree_grab (),
    PQ_label_full (),
    PQ_label_partial (),
    PQ_collect_full_children (),
    PQ_neighbor_replace (),
    PQ_merge_qnode (),
    PQ_replace_node (),
    PQ_node_free (),
    PQ_tree_free (),
#ifndef NDEBUG
    dump_solution (),
    dump_subtree (),
#endif
    print_solution ();

static int
    PQ_bubble (),
    PQ_left_end_is_full ();

#ifndef NDEBUG
static int
    checkout_before (),
    checkout_after (),
    check_tree (),
    check_node_pert (),
    check_node_pert_work (),
    check_subtree (),
    check_node ();
#endif

static PQ_node
    *PQ_reduce (),
    *PQ_template_l1 (),
    *PQ_template_p1 (),
    *PQ_template_p3_notroot (),
    *PQ_template_p5_notroot (),
    *PQ_template_q1 (),
    *PQ_template_q2 (),
    *PQ_template_p2_root (),
    *PQ_template_p4_root (),
    *PQ_template_p6_root (),
    *PQ_template_q3_root (),
    *PQ_collect_empty_children (),
    *PQ_next_nondir (),
    *PQ_node_alloc_work (),
    *PQ_node_alloc (),
    *PQ_save_work (),
    *PQ_restore_work ();

#endif

/* This is an implementation of the PQ-tree algorithms described in "Testing
 * for the Consecutive Ones Property, Interval Graphs, and Graph Planarity
 * Using PQ-Tree Algorithms" by Kellogg Booth and George Leuker, Journal of
 * Computer and Systems Sciences 13 (1976) pp 335-379.  For details, proofs
 * of correctness, etc. see the paper */

#ifdef CC_PROTOTYPE_ANSI
PQ_node *XPQ_process (PQ_node *S)
#else
PQ_node *XPQ_process (S)
PQ_node *S;
#endif
{
    if (!PQ_bubble (S)) {
        return (PQ_node *) NULL;
    }
    return PQ_reduce (S);
}

#ifdef CC_PROTOTYPE_ANSI
static void PQ_tree_grab (PQ_node *x, PQ_set *leaves, PQ_node *xprev)
#else
static void PQ_tree_grab (x, leaves, xprev)
PQ_node *x;
PQ_set *leaves;
PQ_node *xprev;
#endif
{
    PQ_node *z, *zprev, *znext;

    if (x->type == LEAF_NODE || x->type == DIR_NODE) {
        PQ_set_ADD_RIGHT (x, *leaves, leaves_elem);
        if ((x->leaves_elem.ptr1 == (PQ_node *) NULL &&
             x->children_elem.ptr1 == xprev) ||
            (x->leaves_elem.ptr2 == (PQ_node *) NULL &&
             x->children_elem.ptr2 == xprev)) {
            /* We want the leaves ptr usage to match the children ptr usage,
             * so we can preserve the direction the DIR_NODEs point */
            SWAP (x->leaves_elem.ptr1, x->leaves_elem.ptr2, z);
        }
    } else {
        PQ_set_FOREACH (x->children_set, z, children_elem, zprev, znext) {
            PQ_tree_grab (z, leaves, zprev);
        }
    }
}

int markbase = 0;
PQ_set blocked_set;
PQ_node pseudo_root;
int off_the_top;

#ifdef CC_PROTOTYPE_ANSI
PQ_node *XPQ_init_tree (PQ_node *S)
#else
PQ_node *XPQ_init_tree (S)
PQ_node *S;
#endif
{
    PQ_node *root;
    PQ_node *x;

    if (!S->next) {
        S->type = LEAF_NODE;
        S->parent = (PQ_node *) NULL;
        S->parenttype = P_NODE;
        PQ_set_INIT (S->children_set);
        PQ_set_INIT (S->full_children_set);
        PQ_set_INIT (S->partial_children_set);
        S->label = 0;
        S->mark = 0;
        S->pertinent_child_count = 0;
        S->pertinent_leaf_count = 0;
        return S;
    }
    root = PQ_node_alloc ();

    PQ_set_INIT (root->children_set);
    PQ_set_INIT (root->full_children_set);
    PQ_set_INIT (root->partial_children_set);
    root->type = P_NODE;
    root->parent = (PQ_node *) NULL;
    root->parenttype = P_NODE;

    for (x = S; x; x = x->next) {
        x->parent = root;
        x->parenttype = P_NODE;
        PQ_set_ADD (x, root->children_set, children_elem);
        x->label = 0;
        x->mark = 0;
        x->type = LEAF_NODE;
        PQ_set_INIT (x->children_set);
        PQ_set_INIT (x->full_children_set);
        PQ_set_INIT (x->partial_children_set);
        x->pertinent_child_count = 0;
        x->pertinent_leaf_count = 0;
    }
    return root;
}

/* PQ_bubble forms the first half of the PQ-tree implementation.
 *
 * It takes as input a list of PQ_node(s) linked by (next).
 *
 * It fills in the parent field of all the nodes in the PQ-tree, notices certain
 * unsatisfiable requests, fills in the pertinent_child_counts, ...
 *
 * It returns either BUBBLE_NO_SOL or BUBBLE_SUCCESS. */

#ifdef CC_PROTOTYPE_ANSI
static int PQ_bubble (PQ_node *S)
#else
static int PQ_bubble (S)
PQ_node *S;
#endif
{
    PQ_set q;
    int block_count;
    PQ_node *x;
    PQ_node *zprev, *z, *znext;
    PQ_node *leftsib, *rightsib;
    int i;
    int nbs;

    assert (check_tree (S));

    markbase += 4;
    PQ_set_INIT (q);
    block_count = 0;
    PQ_set_INIT (blocked_set);
    off_the_top = 0;

    for (x = S; x; x = x->next) {
        PQ_set_ADD_LEFT (x, q, queue_elem);
    }

    while (PQ_set_SIZE (q) + block_count + off_the_top > 1) {
        if (PQ_set_ISEMPTY (q)) {
            return 0;
        }
        x = PQ_set_RIGHT_ELEM (q);
        PQ_set_DELETE (x, q, queue_elem);
        x->mark = BLOCKED;

        x->pertinent_leaf_count = 0;
        PQ_set_INIT (x->full_children_set);
        PQ_set_INIT (x->partial_children_set);

        nbs = 0;

        leftsib = PQ_next_nondir (x->children_elem.ptr1, x);
        rightsib = PQ_next_nondir (x->children_elem.ptr2, x);

        if (leftsib && leftsib->mark == BLOCKED) {
            nbs++;
        }
        if (rightsib && rightsib->mark == BLOCKED) {
            nbs++;
        }
        if (x->parenttype == P_NODE || leftsib == (PQ_node *) NULL
            || rightsib == (PQ_node *) NULL) {
            x->mark = UNBLOCKED;
        } else if (leftsib->mark == UNBLOCKED) {
            z = x;
            zprev = x->children_elem.ptr2;
            PQ_set_FOREACH_FROM (z, children_elem, zprev, znext) {
                if (z == leftsib) {
                    break;
                }
                z->parent = leftsib->parent;
                z->mark = UNBLOCKED;
            }
            assert (z == leftsib);
        } else if (rightsib->mark == UNBLOCKED) {
            z = x;
            zprev = x->children_elem.ptr1;
            PQ_set_FOREACH_FROM (z, children_elem, zprev, znext) {
                if (z == rightsib) {
                    break;
                }
                z->parent = rightsib->parent;
                z->mark = UNBLOCKED;
            }
            assert (z == rightsib);
        }
        if (x->mark == UNBLOCKED) {
            if (x->parent && IS_UNINITIALIZED (x->parent)) {
                x->parent->mark = UNMARKED;
                x->parent->pertinent_child_count = 0;
            }
            PQ_set_FOREACH_ADJ (x, children_elem, z, i) {
                zprev = x;
                PQ_set_FOREACH_FROM (z, children_elem, zprev, znext) {
                    if (z->type == DIR_NODE) {
                        z->parent = x->parent;
                    } else if (z->mark == BLOCKED) {
                        z->parent = x->parent;
                        z->mark = UNBLOCKED;
                        if (x->parent) {
                            x->parent->pertinent_child_count++;
                        }
                        PQ_set_DELETE (z, blocked_set, blocked_elem);
                    } else {
                        break;
                    }
                }
            }

            if (x->parent) {
                x->parent->pertinent_child_count++;
                if (x->parent->mark == UNMARKED) {
                    PQ_set_ADD_LEFT (x->parent, q, queue_elem);
                    x->parent->mark = QUEUED;
                }
            } else {
                off_the_top = 1;
            }
            block_count -= nbs;
        } else {
            block_count = block_count + 1 - nbs;
            PQ_set_ADD (x, blocked_set, blocked_elem);
        }
    }
    if (!PQ_set_ISEMPTY (q)) {
        x = PQ_set_LEFT_ELEM (q);
        x->pertinent_leaf_count = 0;
        if (x->pertinent_child_count == 1) {
            x->pertinent_child_count = 0;
        }
        PQ_set_INIT (x->full_children_set);
        PQ_set_INIT (x->partial_children_set);
    }
    if (block_count) {
        pseudo_root.type = Q_NODE;
        pseudo_root.parent = (PQ_node *) NULL;
        pseudo_root.pertinent_child_count = 0;
        PQ_set_FOREACH (blocked_set, x, blocked_elem, zprev, znext) {
            x->parent = &pseudo_root;
            pseudo_root.pertinent_child_count++;
        }
        pseudo_root.pertinent_leaf_count = 0;
        PQ_set_INIT (pseudo_root.full_children_set);
        PQ_set_INIT (pseudo_root.partial_children_set);
        pseudo_root.label = 0;
    }
    assert (check_tree (S));
    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *PQ_reduce (PQ_node *S)
#else
static PQ_node *PQ_reduce (S)
PQ_node *S;
#endif
{
    PQ_set q;
    PQ_node *x;
    int ssize;
    PQ_node *y;

    assert (check_tree (S));

    PQ_set_INIT (q);

    for (x = S, ssize = 0; x; x = x->next, ssize++) {
        PQ_set_ADD_LEFT (x, q, queue_elem);
        x->pertinent_leaf_count = 1;
    }
    while (!PQ_set_ISEMPTY (q)) {
        x = PQ_set_RIGHT_ELEM (q);
        PQ_set_DELETE (x, q, queue_elem);

        assert (check_node_pert (x));

        if (x->pertinent_leaf_count < ssize) {
            /* x is not the root of the pertinent subtree */
            assert (checkout_before (x, 0));
            y = x->parent;
            y->pertinent_leaf_count += x->pertinent_leaf_count;
            y->pertinent_child_count--;
            if (y->pertinent_child_count == 0) {
                PQ_set_ADD_LEFT (y, q, queue_elem);
            }
            /* now, the templates */
            if (!PQ_template_l1 (x) &&
                !PQ_template_p1 (x) &&
                !PQ_template_p3_notroot (x) &&
                !PQ_template_p5_notroot (x) &&
                !PQ_template_q1 (x) &&
                !PQ_template_q2 (x)) {
                return (PQ_node *) NULL;
            }
            assert (checkout_after (x, 0));
        } else {
            /* x is the root of the pertinent subtree */
            assert (checkout_before (x, 1));
            assert (PQ_set_ISEMPTY (q));
            if ((y = PQ_template_l1 (x)) ||
                (y = PQ_template_p1 (x)) ||
                (y = PQ_template_p2_root (x)) ||
                (y = PQ_template_p4_root (x)) ||
                (y = PQ_template_p6_root (x)) ||
                (y = PQ_template_q1 (x)) ||
                (y = PQ_template_q2 (x)) ||
                (y = PQ_template_q3_root (x))) {
                assert (check_tree (S));
                return y;
            } else {
                return (PQ_node *) NULL;
            }
        }
    }
    return (PQ_node *) NULL;
}

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *PQ_template_l1 (PQ_node *x)
#else
static PQ_node *PQ_template_l1 (x)
PQ_node *x;
#endif
{
    if (x->type != LEAF_NODE) {
        return (PQ_node *) NULL;
    }
    PQ_label_full (x);
    return x;
}

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *PQ_template_p1 (PQ_node *x)
#else
static PQ_node *PQ_template_p1 (x)
PQ_node *x;
#endif
{
    if (x->type != P_NODE) {
        return (PQ_node *) NULL;
    }
    if (PQ_set_SIZE (x->full_children_set) != PQ_set_SIZE (x->children_set)) {
        return (PQ_node *) NULL;
    }
    PQ_label_full (x);
    return x;
}

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *PQ_template_p3_notroot (PQ_node *x)
#else
static PQ_node *PQ_template_p3_notroot (x)
PQ_node *x;
#endif
{
    if (x->type != P_NODE) {
        return (PQ_node *) NULL;
    }
    if (!PQ_set_ISEMPTY (x->partial_children_set)) {
        return (PQ_node *) NULL;
    }
    assert (!PQ_set_ISEMPTY (x->full_children_set));
    assert (PQ_set_SIZE (x->full_children_set) != PQ_set_SIZE (x->children_set));

    PQ_collect_full_children (x, Q_NODE);
    x = PQ_collect_empty_children (x, Q_NODE);

    PQ_label_partial (x);

    return x;
}

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *PQ_template_p5_notroot (PQ_node *x)
#else
static PQ_node *PQ_template_p5_notroot (x)
PQ_node *x;
#endif
{
    PQ_node *partial_child;
    PQ_node *full_child;
    PQ_node *z;

    if (x->type != P_NODE) {
        return (PQ_node *) NULL;
    }
    if (PQ_set_SIZE (x->partial_children_set) != 1) {
        return (PQ_node *) NULL;
    }
    partial_child = PQ_set_LEFT_ELEM (x->partial_children_set);
    PQ_set_DELETE (partial_child, x->children_set, children_elem);
    PQ_set_DELETE (partial_child, x->partial_children_set, partial_children_elem);

    PQ_collect_full_children (x, Q_NODE);
    if (!PQ_set_ISEMPTY (x->full_children_set)) {
        full_child = PQ_set_LEFT_ELEM (x->full_children_set);
        PQ_set_DELETE (full_child, x->children_set, children_elem);
        PQ_set_DELETE (full_child, x->full_children_set, full_children_elem);
        full_child->parent = partial_child;
        full_child->parenttype = Q_NODE;
        if (PQ_left_end_is_full (partial_child)) {
            PQ_set_ADD_LEFT (full_child, partial_child->children_set, children_elem);
            PQ_set_ADD_LEFT (full_child, partial_child->full_children_set, full_children_elem);
        } else {
            PQ_set_ADD_RIGHT (full_child, partial_child->children_set, children_elem);
            PQ_set_ADD_RIGHT (full_child, partial_child->full_children_set, full_children_elem);
        }
    }
    PQ_replace_node (x, partial_child);

    if (PQ_set_ISEMPTY (x->children_set)) {
        PQ_node_free (x);
    } else {
        if (PQ_set_SIZE (x->children_set) == 1) {
            z = PQ_set_LEFT_ELEM (x->children_set);
            PQ_node_free (x);
            x = z;
        }
        x->parent = partial_child;
        x->parenttype = Q_NODE;
        if (PQ_left_end_is_full (partial_child)) {
            PQ_set_ADD_RIGHT (x, partial_child->children_set, children_elem);
        } else {
            PQ_set_ADD_LEFT (x, partial_child->children_set, children_elem);
        }
    }
    PQ_label_partial (partial_child);
    return partial_child;
}

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *PQ_template_q1 (PQ_node *x)
#else
static PQ_node *PQ_template_q1 (x)
PQ_node *x;
#endif
{
    PQ_node *z, *zprev, *znext;

    if (x->type != Q_NODE) {
        return (PQ_node *) NULL;
    }
    if (x == &pseudo_root) {
        return (PQ_node *) NULL;
    }
    PQ_set_FOREACH (x->children_set, z, children_elem, zprev, znext) {
        if (z->label != FULL && z->type != DIR_NODE) {
            return (PQ_node *) NULL;
        }
    }
    PQ_label_full (x);
    return x;
}

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *PQ_template_q2 (PQ_node *x)
#else
static PQ_node *PQ_template_q2 (x)
PQ_node *x;
#endif
{
    PQ_node *partial_child;
    int full_count;
    PQ_node *z, *zprev, *znext;
    PQ_node *full_end, *empty_end;

    if (x->type != Q_NODE) {
        return (PQ_node *) NULL;
    }
    if (x == &pseudo_root) {
        return (PQ_node *) NULL;
    }
    if (PQ_set_SIZE (x->partial_children_set) > 1) {
        return (PQ_node *) NULL;
    }
    if (PQ_left_end_is_full (x)) {
        full_end = PQ_set_LEFT_ELEM (x->children_set);
        empty_end = PQ_set_RIGHT_ELEM (x->children_set);
    } else {
        full_end = PQ_set_RIGHT_ELEM (x->children_set);
        empty_end = PQ_set_LEFT_ELEM (x->children_set);
    }

    full_count = 0;
    z = full_end;
    zprev = (PQ_node *) NULL;

    PQ_set_FOREACH_FROM (z, children_elem, zprev, znext) {
        if (z->label == FULL) {
            full_count++;
        } else if (z->type != DIR_NODE) {
            break;
        }
    }

    if (full_count != PQ_set_SIZE (x->full_children_set)) {
        return (PQ_node *) NULL;
    }
    if (!PQ_set_ISEMPTY (x->partial_children_set) &&
        z != PQ_set_LEFT_ELEM (x->partial_children_set)) {
        return (PQ_node *) NULL;
    }
    assert (!PQ_set_ISEMPTY (x->full_children_set) || !PQ_set_ISEMPTY (x->partial_children_set));

    if (!PQ_set_ISEMPTY (x->partial_children_set)) {
        partial_child = PQ_set_LEFT_ELEM (x->partial_children_set);
        PQ_set_DELETE (partial_child, x->partial_children_set, partial_children_elem);
        PQ_merge_qnode (partial_child);
    }
    PQ_label_partial (x);
    return x;
}

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *PQ_template_p2_root (PQ_node *x)
#else
static PQ_node *PQ_template_p2_root (x)
PQ_node *x;
#endif
{
    if (x->type != P_NODE) {
        return (PQ_node *) NULL;
    }
    if (!PQ_set_ISEMPTY (x->partial_children_set)) {
        return (PQ_node *) NULL;
    }
    assert (!PQ_set_ISEMPTY (x->full_children_set));
    assert (PQ_set_SIZE (x->full_children_set) != PQ_set_SIZE (x->children_set));

    PQ_collect_full_children (x, P_NODE);

    return PQ_set_LEFT_ELEM (x->full_children_set);
}

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *PQ_template_p4_root (PQ_node *x)
#else
static PQ_node *PQ_template_p4_root (x)
PQ_node *x;
#endif
{
    PQ_node *partial_child;
    PQ_node *full_child;

    if (x->type != P_NODE) {
        return (PQ_node *) NULL;
    }
    if (PQ_set_SIZE (x->partial_children_set) != 1) {
        return (PQ_node *) NULL;
    }
    partial_child = PQ_set_LEFT_ELEM (x->partial_children_set);

    PQ_collect_full_children (x, Q_NODE);

    if (!PQ_set_ISEMPTY (x->full_children_set)) {
        full_child = PQ_set_LEFT_ELEM (x->full_children_set);
        PQ_set_DELETE (full_child, x->children_set, children_elem);
        PQ_set_DELETE (full_child, x->full_children_set, full_children_elem);
        full_child->parent = partial_child;
        full_child->parenttype = Q_NODE;
        if (PQ_left_end_is_full (partial_child)) {
            PQ_set_ADD_LEFT (full_child, partial_child->children_set, children_elem);
            PQ_set_ADD_LEFT (full_child, partial_child->full_children_set, full_children_elem);
        } else {
            PQ_set_ADD_RIGHT (full_child, partial_child->children_set, children_elem);
            PQ_set_ADD_RIGHT (full_child, partial_child->full_children_set, full_children_elem);
        }
    }
    if (PQ_set_SIZE (x->children_set) == 1) {
        full_child = PQ_set_LEFT_ELEM (x->children_set);
        PQ_replace_node (x, full_child);
        PQ_node_free (x);
    }
    return partial_child;
}

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *PQ_template_p6_root (PQ_node *x)
#else
static PQ_node *PQ_template_p6_root (x)
PQ_node *x;
#endif
{
    PQ_node *partial_child1, *partial_child2;
    PQ_node *full_end1, *empty_end1, *full_end2, *empty_end2;
    PQ_node *z, *zprev, *znext;
    PQ_node *full_child;

    if (x->type != P_NODE) {
        return (PQ_node *) NULL;
    }
    if (PQ_set_SIZE (x->partial_children_set) > 2) {
        return (PQ_node *) NULL;
    }
    assert (PQ_set_SIZE (x->partial_children_set) == 2);

    partial_child1 = PQ_set_LEFT_ELEM (x->partial_children_set);
    partial_child2 = PQ_set_RIGHT_ELEM (x->partial_children_set);

    PQ_collect_full_children (x, Q_NODE);

    if (!PQ_set_ISEMPTY (x->full_children_set)) {
        full_child = PQ_set_LEFT_ELEM (x->full_children_set);
        PQ_set_DELETE (full_child, x->children_set, children_elem);
        PQ_set_DELETE (full_child, x->full_children_set, full_children_elem);

        full_child->parent = partial_child1;
        full_child->parenttype = Q_NODE;
        if (PQ_left_end_is_full (partial_child1)) {
            PQ_set_ADD_LEFT (full_child, partial_child1->children_set, children_elem);
            PQ_set_ADD_LEFT (full_child, partial_child1->full_children_set, full_children_elem);
        } else {
            PQ_set_ADD_RIGHT (full_child, partial_child1->children_set, children_elem);
            PQ_set_ADD_RIGHT (full_child, partial_child1->full_children_set, full_children_elem);
        }
    }
    if (PQ_left_end_is_full (partial_child1)) {
        full_end1 = PQ_set_LEFT_ELEM (partial_child1->children_set);
        empty_end1 = PQ_set_RIGHT_ELEM (partial_child1->children_set);
    } else {
        full_end1 = PQ_set_RIGHT_ELEM (partial_child1->children_set);
        empty_end1 = PQ_set_LEFT_ELEM (partial_child1->children_set);
    }
    if (PQ_left_end_is_full (partial_child2)) {
        full_end2 = PQ_set_LEFT_ELEM (partial_child2->children_set);
        empty_end2 = PQ_set_RIGHT_ELEM (partial_child2->children_set);
    } else {
        full_end2 = PQ_set_RIGHT_ELEM (partial_child2->children_set);
        empty_end2 = PQ_set_LEFT_ELEM (partial_child2->children_set);
    }

    PQ_set_PTR_REPLACE (full_end1->children_elem, 0, full_end2);
    PQ_set_PTR_REPLACE (full_end2->children_elem, 0, full_end1);

    if (partial_child1->children_set.left == full_end1) {
        partial_child1->children_set.left = empty_end2;
    } else {
        partial_child1->children_set.right = empty_end2;
    }
    partial_child1->children_set.size += partial_child2->children_set.size;
    empty_end2->parent = partial_child1;

    PQ_set_FOREACH_DEL (partial_child2->full_children_set, z, full_children_elem, zprev, znext) {
        PQ_set_DELETE (z, partial_child2->full_children_set, full_children_elem);
        PQ_set_ADD (z, partial_child1->full_children_set, full_children_elem);
        z->parent = partial_child1;
    }

    PQ_set_DELETE (partial_child2, x->children_set, children_elem);
    PQ_set_DELETE (partial_child2, x->partial_children_set, partial_children_elem);

    PQ_node_free (partial_child2);

    if (PQ_set_SIZE (x->children_set) == 1) {
        full_child = PQ_set_LEFT_ELEM (x->children_set);
        PQ_replace_node (x, full_child);
        PQ_node_free (x);
    }
    return partial_child1;
}

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *PQ_template_q3_root (PQ_node *x)
#else
static PQ_node *PQ_template_q3_root (x)
PQ_node *x;
#endif
{
    int full_count;
    PQ_node *z, *zprev, *znext, *zstart;

    /* note that we cannot talk about x->children_set, since x might be the
     * pseudo_root */

    if (x->type != Q_NODE) {
        return (PQ_node *) NULL;
    }
    if (PQ_set_ISEMPTY (x->partial_children_set)) {
        zstart = PQ_set_LEFT_ELEM (x->full_children_set);
        assert (zstart->label == FULL);
        full_count = 1;
        zprev = zstart;
        z = zstart->children_elem.ptr1;

        PQ_set_FOREACH_FROM (z, children_elem, zprev, znext) {
            if (z->label == FULL) {
                full_count++;
            } else if (z->type != DIR_NODE) {
                break;
            }
        }

        zprev = zstart;
        z = zstart->children_elem.ptr2;

        PQ_set_FOREACH_FROM (z, children_elem, zprev, znext) {
            if (z->label == FULL) {
                full_count++;
            } else if (z->type != DIR_NODE) {
                break;
            }
        }
        if (full_count != PQ_set_SIZE (x->full_children_set)) {
            return (PQ_node *) NULL;
        }
    } else {
        zstart = PQ_set_LEFT_ELEM (x->partial_children_set);
        z = PQ_next_nondir (zstart->children_elem.ptr1, zstart);

        if (z && !IS_EMPTY (z)) {
            z = zstart->children_elem.ptr1;
        } else {
            z = zstart->children_elem.ptr2;
        }

        zprev = zstart;
        full_count = 0;
        PQ_set_FOREACH_FROM (z, children_elem, zprev, znext) {
            if (z->label == FULL) {
                full_count++;
            } else if (z->type != DIR_NODE) {
                break;
            }
        }
        if (full_count != PQ_set_SIZE (x->full_children_set)) {
            return (PQ_node *) NULL;
        }
        if (z && z->label == PARTIAL && PQ_set_SIZE (x->partial_children_set) != 2) {
            return (PQ_node *) NULL;
        }
        if (z && z->label != PARTIAL && PQ_set_SIZE (x->partial_children_set) != 1) {
            return (PQ_node *) NULL;
        }
    }

    PQ_set_FOREACH_DEL (x->partial_children_set, z, partial_children_elem, zprev, znext) {
        PQ_set_DELETE (z, x->partial_children_set, partial_children_elem);
        PQ_merge_qnode (z);
    }

    return x;
}

/* PQ_label_full marks a node as full, and if it has a parent, adds it to the
 * parents list of full children */

#ifdef CC_PROTOTYPE_ANSI
static void PQ_label_full (PQ_node *x)
#else
static void PQ_label_full (x)
PQ_node *x;
#endif
{
    x->label = FULL;
    if (x->parent) {
        PQ_set_ADD (x, x->parent->full_children_set, full_children_elem);
    }
} /* PQ_LABEL_FULL */

/* PQ_label_partial marks a node as partial, and if it has a parent, adds it
 * to the parents list of partial children */

#ifdef CC_PROTOTYPE_ANSI
static void PQ_label_partial (PQ_node *x)
#else
static void PQ_label_partial (x)
PQ_node *x;
#endif
{
    x->label = PARTIAL;
    if (x->parent) {
        PQ_set_ADD (x, x->parent->partial_children_set, partial_children_elem);
    }
}

/* PQ_collect_full_children collects all the full children of x, and places
 * them under a new P-node below x.  It sets the parenttype of the new node
 * to t */

#ifdef CC_PROTOTYPE_ANSI
static void PQ_collect_full_children (PQ_node *x, int t)
#else
static void PQ_collect_full_children (x, t)
PQ_node *x;
int t;
#endif
{
    PQ_node *new_node;
    PQ_node *z, *zprev, *znext;

    assert (x->type == P_NODE);
    if (PQ_set_SIZE (x->full_children_set) > 1) {
        new_node = PQ_node_alloc ();
        PQ_set_INIT (new_node->children_set);
        PQ_set_INIT (new_node->full_children_set);
        PQ_set_INIT (new_node->partial_children_set);
        new_node->label = FULL;
        new_node->type = P_NODE;
        PQ_set_FOREACH_DEL (x->full_children_set, z, full_children_elem, zprev, znext) {
            PQ_set_DELETE (z, x->children_set, children_elem);
            PQ_set_DELETE (z, x->full_children_set, full_children_elem);
            z->parent = new_node;
            z->parenttype = P_NODE;
            PQ_set_ADD (z, new_node->children_set, children_elem);
            PQ_set_ADD (z, new_node->full_children_set, full_children_elem);
        }
        assert (PQ_set_ISEMPTY (x->full_children_set));
        new_node->parent = x;
        new_node->parenttype = t;
        PQ_set_ADD (new_node, x->children_set, children_elem);
        PQ_set_ADD (new_node, x->full_children_set, full_children_elem);
    } else if (PQ_set_SIZE (x->full_children_set) == 1) {
        z = PQ_set_LEFT_ELEM (x->full_children_set);
        z->parenttype = t;
    }
} /* PQ_COLLECT_FULL_CHILDREN */

/* PQ_collect_empty_children collects all the emtpy children of x, and places
 * them under a new P-node below x.  It sets the parenttype of the new node
 * to t.  If there is more than 1 empty child, it actually does this by
 * creating a new node to replace x, and moves all the full children of x to
 * the new node, and moves x down.  It returns a pointer to the node that is
 * where x used to be. */

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *PQ_collect_empty_children (PQ_node *x, int t)
#else
static PQ_node *PQ_collect_empty_children (x, t)
PQ_node *x;
int t;
#endif
{
    PQ_node *y;
    PQ_node *z, *zprev, *znext;
    PQ_node *new_node;

    assert (x->type == P_NODE);
    assert (PQ_set_ISEMPTY (x->partial_children_set));
    assert (PQ_set_SIZE (x->children_set) > PQ_set_SIZE (x->full_children_set));

    if (PQ_set_SIZE (x->children_set) - PQ_set_SIZE (x->full_children_set) > 1) {
        new_node = PQ_node_alloc ();
        PQ_set_INIT (new_node->children_set);
        PQ_set_INIT (new_node->full_children_set);
        PQ_set_INIT (new_node->partial_children_set);
        new_node->label = x->label;
        new_node->type = t;

        PQ_set_FOREACH_DEL (x->full_children_set, z, full_children_elem, zprev, znext) {
            PQ_set_DELETE (z, x->children_set, children_elem);
            PQ_set_DELETE (z, x->full_children_set, full_children_elem);
            z->parent = new_node;
            z->parenttype = t;
            PQ_set_ADD (z, new_node->children_set, children_elem);
            PQ_set_ADD (z, new_node->full_children_set, full_children_elem);
        }

        y = x->parent;
        new_node->parent = y;
        new_node->parenttype = x->parenttype;
        new_node->children_elem.ptr1 = x->children_elem.ptr1;
        new_node->children_elem.ptr2 = x->children_elem.ptr2;
        if (y) {
            PQ_neighbor_replace (new_node->children_elem.ptr1, &y->children_set, x, new_node);
            PQ_neighbor_replace (new_node->children_elem.ptr2, &y->children_set, x, new_node);
        }
        x->parent = new_node;
        x->parenttype = t;

        x->label = EMPTY;
        PQ_set_ADD (x, new_node->children_set, children_elem);

        x = new_node;
    } else if (PQ_set_SIZE (x->children_set) - PQ_set_SIZE (x->full_children_set) == 1) {
        PQ_set_FOREACH (x->children_set, z, children_elem, zprev, znext) {
            if (IS_EMPTY (z)) {
                z->parenttype = t;
                break;
            }
        }
        x->type = t;
    }
    return x;
}

/* PQ_neighbor_replace replaces the pointer to q in the children list with a
 * pointer to r */

#ifdef CC_PROTOTYPE_ANSI
static void PQ_neighbor_replace (PQ_node *x, PQ_set *s, PQ_node *q,
                                 PQ_node *r)
#else
static void PQ_neighbor_replace (x, s, q, r)
PQ_node *x;
PQ_set *s;
PQ_node *q;
PQ_node *r;
#endif
{
    if (x) {
        PQ_set_PTR_REPLACE (x->children_elem, q, r);
    } else {
        if (s->left == q) {
            s->left = r;
        } else {
            assert (s->right == q);
            s->right = r;
        }
    }
}

/* PQ_merge_qnode merges x into its parent */

#ifdef CC_PROTOTYPE_ANSI
static void PQ_merge_qnode (PQ_node *x)
#else
static void PQ_merge_qnode (x)
PQ_node *x;
#endif
{
    PQ_node *parent = x->parent;
    PQ_node *full_end, *empty_end;
    PQ_node *z, *zprev, *znext;
    PQ_node *empty_neighbor, *full_neighbor;
    PQ_node *empty_neighbor2, *full_neighbor2;

    assert (x->type == Q_NODE);
    if (PQ_left_end_is_full (x)) {
        full_end = PQ_set_LEFT_ELEM (x->children_set);
        empty_end = PQ_set_RIGHT_ELEM (x->children_set);
    } else {
        full_end = PQ_set_RIGHT_ELEM (x->children_set);
        empty_end = PQ_set_LEFT_ELEM (x->children_set);
    }

    PQ_set_FOREACH_DEL (x->full_children_set, z, full_children_elem, zprev, znext) {
        PQ_set_DELETE (z, x->full_children_set, full_children_elem);
        PQ_set_ADD (z, parent->full_children_set, full_children_elem);
        z->parent = parent;
    }

    full_end->parent = parent;
    empty_end->parent = parent;
    empty_neighbor = x->children_elem.ptr1;
    full_neighbor = x->children_elem.ptr2;
    empty_neighbor2 = PQ_next_nondir (empty_neighbor, x);
    full_neighbor2 = PQ_next_nondir (full_neighbor, x);
    if ((empty_neighbor2 && !IS_EMPTY (empty_neighbor2)) ||
        (full_neighbor2 && IS_EMPTY (full_neighbor2))) {
        SWAP (empty_neighbor, full_neighbor, z);
        SWAP (empty_neighbor2, full_neighbor2, z);
    }
    assert (full_end != empty_end);
    assert (empty_neighbor2 == 0 || IS_EMPTY (empty_neighbor2));
    assert (full_neighbor2 == 0 || full_neighbor2->label == FULL || full_neighbor2->label == PARTIAL);
    assert (empty_neighbor2 || full_neighbor2);

    PQ_set_PTR_REPLACE (full_end->children_elem, 0, full_neighbor);
    PQ_set_PTR_REPLACE (empty_end->children_elem, 0, empty_neighbor);
    PQ_neighbor_replace (full_neighbor, &parent->children_set, x, full_end);
    PQ_neighbor_replace (empty_neighbor, &parent->children_set, x, empty_end);

    parent->children_set.size += x->children_set.size - 1;

    PQ_node_free (x);
}

/* PQ_replace_node replaces old with new */

#ifdef CC_PROTOTYPE_ANSI
static void PQ_replace_node (PQ_node *old, PQ_node *new)
#else
static void PQ_replace_node (old, new)
PQ_node *old;
PQ_node *new;
#endif
{
    new->parent = old->parent;
    new->parenttype = old->parenttype;

    new->children_elem.ptr1 = old->children_elem.ptr1;
    new->children_elem.ptr2 = old->children_elem.ptr2;

    if (new->parent) {
        PQ_neighbor_replace (new->children_elem.ptr1, &new->parent->children_set, old, new);
        PQ_neighbor_replace (new->children_elem.ptr2, &new->parent->children_set, old, new);
    } else {
        if (new->children_elem.ptr1) {
            PQ_set_PTR_REPLACE (new->children_elem.ptr1->children_elem, old, new);
        }
        if (new->children_elem.ptr2) {
            PQ_set_PTR_REPLACE (new->children_elem.ptr2->children_elem, old, new);
        }
    }
}

/* PQ_left_end_is_full is a boolean which indicates whether the left end of a
 * partial Q_NODE is full or not */

#ifdef CC_PROTOTYPE_ANSI
static int PQ_left_end_is_full (PQ_node *x)
#else
static int PQ_left_end_is_full (x)
PQ_node *x;
#endif
{
    PQ_node *left_end;
    PQ_node *right_end;

    assert (x->type == Q_NODE);

    left_end = PQ_next_nondir (PQ_set_LEFT_ELEM (x->children_set), (PQ_node *) NULL);
    right_end = PQ_next_nondir (PQ_set_RIGHT_ELEM (x->children_set), (PQ_node *) NULL);
    return IS_EMPTY (right_end) || left_end->label == FULL;
}

/* PQ_next_nondir finds the next neighbor which is not of type DIR_NODE,
 * heading from z away from zprev */

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *PQ_next_nondir (PQ_node *z, PQ_node *zprev)
#else
static PQ_node *PQ_next_nondir (z, zprev)
PQ_node *z;
PQ_node *zprev;
#endif
{
    PQ_node *znext;

    PQ_set_FOREACH_FROM (z, children_elem, zprev, znext) {
        if (z->type != DIR_NODE)
            return z;
    }
    return (PQ_node *) NULL;
}

static int node_counter = -1;
static PQ_node *PQ_node_freelist = (PQ_node *) NULL;

#define PQ_alloc_chunk (((1<<17)-16)/sizeof (PQ_node))

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *PQ_node_alloc_work (void)
#else
static PQ_node *PQ_node_alloc_work ()
#endif
{
    PQ_node *x;
    int i;

    if (!PQ_node_freelist) {
        PQ_node_freelist = CC_SAFE_MALLOC (PQ_alloc_chunk, PQ_node);
        if (!PQ_node_freelist) {
            fprintf (stderr, "out of memory in PQ_node_alloc_work\n");
            exit (1);
        }
        printf ("MALLOC %d PQ NODES\n", (int) PQ_alloc_chunk);
        fflush (stdout);
        if (!PQ_node_freelist) {
            fprintf (stderr, "Out of memory\n");
            exit (1);
        }
        for (i = 0; i < (int) PQ_alloc_chunk - 1; i++) {
            PQ_node_freelist[i].next = &PQ_node_freelist[i + 1];
        }
        PQ_node_freelist[PQ_alloc_chunk - 1].next = (PQ_node *) NULL;
    }
    x = PQ_node_freelist;
    PQ_node_freelist = PQ_node_freelist->next;

    return x;
}

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *PQ_node_alloc (void)
#else
static PQ_node *PQ_node_alloc ()
#endif
{
    PQ_node *x;

    x = PQ_node_alloc_work ();
    x->next = (PQ_node *) NULL;
    x->number = node_counter;
    node_counter--;
    x->base_edge = (struct Xedge *) NULL;
    x->queue_elem.ptr1 = (PQ_node *) NULL;
    x->queue_elem.ptr2 = (PQ_node *) NULL;
    PQ_set_INIT (x->children_set);
    PQ_set_INIT (x->partial_children_set);
    PQ_set_INIT (x->full_children_set);
    x->children_elem.ptr1 = (PQ_node *) NULL;
    x->children_elem.ptr2 = (PQ_node *) NULL;
    x->partial_children_elem.ptr1 = (PQ_node *) NULL;
    x->partial_children_elem.ptr2 = (PQ_node *) NULL;
    x->full_children_elem.ptr1 = (PQ_node *) NULL;
    x->full_children_elem.ptr2 = (PQ_node *) NULL;
    x->blocked_elem.ptr1 = (PQ_node *) NULL;
    x->blocked_elem.ptr2 = (PQ_node *) NULL;
    x->leaves_elem.ptr1 = (PQ_node *) NULL;
    x->leaves_elem.ptr2 = (PQ_node *) NULL;
    x->parent = (PQ_node *) NULL;
    x->pertinent_child_count = 0;
    x->pertinent_leaf_count = 0;
    x->mark = 0;
    x->type = 0;
    x->parenttype = 0;
    x->label = 0;
    x->magiclabel = 0;

    return x;
}

#ifdef CC_PROTOTYPE_ANSI
static void PQ_node_free (PQ_node *x)
#else
static void PQ_node_free (x)
PQ_node *x;
#endif
{
    x->next = PQ_node_freelist;
    PQ_node_freelist = x;
}

/* PQ_tree_free recursively frees the tree rooted at x */

#ifdef CC_PROTOTYPE_ANSI
static void PQ_tree_free (PQ_node *x, int saveleaves)
#else
static void PQ_tree_free (x, saveleaves)
PQ_node *x;
int saveleaves;
#endif
{
    PQ_node *z, *zprev, *znext;

    PQ_set_FOREACH_DEL (x->children_set, z, children_elem, zprev, znext) {
        PQ_set_DELETE (z, x->children_set, children_elem);
        PQ_tree_free (z, saveleaves);
    }
    if (!(saveleaves && (x->type == DIR_NODE || x->type == LEAF_NODE))) {
        PQ_node_free (x);
    }
}

/* PQ_free_all frees storage for a tree */

#ifdef CC_PROTOTYPE_ANSI
void XPQ_free_all (PQ_node *x, int saveleaves)
#else
void XPQ_free_all (x, saveleaves)
PQ_node *x;
int saveleaves;
#endif
{
    PQ_tree_free (XPQ_find_root (x), saveleaves);
}

/* PQ_find_root is only used by the dump and check routines, and PQ_free_all */

#ifdef CC_PROTOTYPE_ANSI
PQ_node *XPQ_find_root (PQ_node *x)
#else
PQ_node *XPQ_find_root (x)
PQ_node *x;
#endif
{
    PQ_node *zprev, *znext;

    for (;;) {
        if (x->parenttype == P_NODE) {
            if (x->parent)
                x = x->parent;
            else
                return x;
        } else {
            zprev = x->children_elem.ptr1;
            PQ_set_FOREACH_FROM (x, children_elem, zprev, znext);
            if (zprev->parent)
                x = zprev->parent;
            else
                return zprev;
        }
    }
}

#ifndef NDEBUG

#ifdef CC_PROTOTYPE_ANSI
static void dump_solution (PQ_node *x)
#else
static void dump_solution (x)
PQ_node *x;
#endif
{
    dump_subtree (XPQ_find_root (x));
}

#ifdef CC_PROTOTYPE_ANSI
static void dump_subtree (PQ_node *x)
#else
static void dump_subtree (x)
PQ_node *x;
#endif
{
    print_solution (x, (PQ_node *) NULL);
    printf ("\n");
}

#endif

#ifdef CC_PROTOTYPE_ANSI
static void print_solution (PQ_node *x, PQ_node *xprev)
#else
static void print_solution (x, xprev)
PQ_node *x;
PQ_node *xprev;
#endif
{
    PQ_node *z, *zprev, *znext;

    if (x->type == LEAF_NODE) {
        printf ("%d ", x->number);
    } else if (x->type == DIR_NODE) {
        if (x->children_elem.ptr1 == xprev) {
            printf ("<<%d<< ", x->number);
        } else {
            printf (">>%d>> ", x->number);
        }
    } else if (x->type == P_NODE) {
        printf ("(");
        PQ_set_FOREACH (x->children_set, z, children_elem, zprev, znext) {
            print_solution (z, zprev);
        }
        printf (")<%d> ", x->number);
    } else {
        printf ("[");
        PQ_set_FOREACH (x->children_set, z, children_elem, zprev, znext) {
            print_solution (z, zprev);
        }
        printf ("]<%d> ", x->number);
    }
}

/* the various check routines are for debugging use only, to verify that the
 * state of the PQ_tree is valid. */

#ifndef NDEBUG

#ifdef CC_PROTOTYPE_ANSI
static int checkout_before (PQ_node *x, int isroot)
#else
static int checkout_before (x, isroot)
PQ_node *x;
int isroot;
#endif
{
    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
static int checkout_after (PQ_node *x, int isroot)
#else
static int checkout_after (x, isroot)
PQ_node *x;
int isroot;
#endif
{
    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
static int check_tree (PQ_node *x)
#else
static int check_tree (x)
PQ_node *x;
#endif
{
    if (!check_subtree (XPQ_find_root (x))) {
        dump_solution (x);
        return 0;
    } else {
        return 1;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int check_subtree (PQ_node *x)
#else
static int check_subtree (x)
PQ_node *x;
#endif
{
    PQ_node *z, *zprev, *znext;

    if (!check_node (x)) {
        return 0;
    }
    PQ_set_FOREACH (x->children_set, z, children_elem, zprev, znext) {
        if (!check_subtree (z)) {
            return 0;
        }
    }
    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
static int check_node (PQ_node *x)
#else
static int check_node (x)
PQ_node *x;
#endif
{
    PQ_node *z, *zprev, *znext;
    int cnt;

    cnt = 0;

    if (x == &pseudo_root) {
        return 1;
    }
    PQ_set_FOREACH (x->children_set, z, children_elem, zprev, znext) {
        cnt++;
        if (z->parenttype != x->type) {
            printf ("Node %x has parenttype %d, parent %x has type %d\n",
                    (unsigned int) z, z->parenttype, (unsigned int) x,
                    x->type);
            return 0;
        }
        if (x->type == P_NODE && z->parent != x) {
            printf ("Node %x has parent %x, should be P-node %x\n",
                    (unsigned int) z, (unsigned int) z->parent,
                    (unsigned int) x);
            return 0;
        }
        if (!((z->children_elem.ptr1 == zprev && z->children_elem.ptr2 != zprev) ||
              (z->children_elem.ptr2 == zprev && z->children_elem.ptr1 != zprev))) {
            printf ("Node %x has children ptr1 %x ptr2 %x, should be =, != %x\n",
                    (unsigned int) z, (unsigned int) z->children_elem.ptr1,
                    (unsigned int) z->children_elem.ptr2,
                    (unsigned int) zprev);
            return 0;
        }
    }
    if (x->type == P_NODE && cnt != PQ_set_SIZE (x->children_set)) {
        printf ("P-node %x has %d children, set size %d\n", (unsigned int) x,
                cnt, PQ_set_SIZE (x->children_set));
        return 0;
    }
    if (x->type == Q_NODE && PQ_set_LEFT_ELEM (x->children_set)->parent != x) {
        printf ("Q_node %x left child %x has parent %x\n", (unsigned int) x,
                (unsigned int) PQ_set_LEFT_ELEM (x->children_set),
                (unsigned int) PQ_set_LEFT_ELEM (x->children_set)->parent);
        return 0;
    }
    if (x->type == Q_NODE && PQ_set_RIGHT_ELEM (x->children_set)->parent != x) {
        printf ("Q_node %x right child %x has parent %x\n", (unsigned int) x,
                (unsigned int) PQ_set_RIGHT_ELEM (x->children_set),
                (unsigned int) PQ_set_RIGHT_ELEM (x->children_set)->parent);
        return 0;
    }
    if (x->type != LEAF_NODE && x->type != DIR_NODE && PQ_set_ISEMPTY (x->children_set)) {
        printf ("node %x is type %d, but has no children\n", (unsigned int) x,
                x->type);
        return 0;
    }
    if (x->type == LEAF_NODE && !PQ_set_ISEMPTY (x->children_set)) {
        printf ("leaf node %x has children\n", (unsigned int) x);
        return 0;
    }
    if (x->type == DIR_NODE && !PQ_set_ISEMPTY (x->children_set)) {
        printf ("dir node %x has children\n", (unsigned int) x);
        return 0;
    }
    if (x->type == DIR_NODE && (x->children_elem.ptr1 == (PQ_node *) NULL ||
                                x->children_elem.ptr2 == (PQ_node *) NULL)) {
        printf ("dir node doesn't have 2 neighbors\n");
        return 0;
    }
    if (x->type == P_NODE && cnt < 2) {
        printf ("P-node %d only has %d children\n", x->number, cnt);
        return 0;
    }
    if (x->type == Q_NODE && cnt < ((x->label == PARTIAL) ? 2 : 3)) {
        printf ("Q-node %d only has %d children\n", x->number, cnt);
        return 0;
    }
    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
static int check_node_pert (PQ_node *x)
#else
static int check_node_pert (x)
PQ_node *x;
#endif
{
    if (!check_node_pert_work (x)) {
        dump_solution (x);
        return 0;
    } else {
        return 1;
    }
}


#ifdef CC_PROTOTYPE_ANSI
static int check_node_pert_work (PQ_node *x)
#else
static int check_node_pert_work (x)
PQ_node *x;
#endif
{
    PQ_node *z, *zprev, *znext;
    int cnt, full_cnt, partial_cnt, empty_cnt;

    if (!check_node (x)) {
        return 0;
    }
    if (x != &pseudo_root) {
        empty_cnt = 0;
        full_cnt = 0;
        partial_cnt = 0;
        PQ_set_FOREACH (x->children_set, z, children_elem, zprev, znext) {
            if (IS_EMPTY (z))
                empty_cnt++;
            else if (z->label == PARTIAL)
                partial_cnt++;
            else if (z->label == FULL)
                full_cnt++;
            else {
                printf ("Node %x has label %d\n", (unsigned int) z, z->label);
                return 0;
            }
            if (!IS_EMPTY (z) && x != &pseudo_root && z->parent != x) {
                printf ("Node %x has parent %x, should be %x\n",
                        (unsigned int) z, (unsigned int) z->parent,
                        (unsigned int) x);
                return 0;
            }
        }

        if (full_cnt != PQ_set_SIZE (x->full_children_set)) {
            printf ("node %x has full children size %d, but has %d children full\n",
                    (unsigned int) x, PQ_set_SIZE (x->full_children_set),
                    full_cnt);
            return 0;
        }
        if (partial_cnt != PQ_set_SIZE (x->partial_children_set)) {
            printf ("node %x has partial children size %d, but has %d children partial\n",
                    (unsigned int) x, PQ_set_SIZE (x->partial_children_set),
                    partial_cnt);
            return 0;
        }
    }
    cnt = 0;
    PQ_set_FOREACH (x->full_children_set, z, full_children_elem, zprev, znext) {
        cnt++;
        if (!((z->full_children_elem.ptr1 == zprev && z->full_children_elem.ptr2 != zprev) ||
              (z->full_children_elem.ptr2 == zprev && z->full_children_elem.ptr1 != zprev) ||
              (z->full_children_elem.ptr1 == zprev &&
        z->full_children_elem.ptr2 == zprev && zprev == (PQ_node *) NULL))) {
            printf ("Node %x has full_children ptr1 %x ptr2 %x, should be =, != %x\n",
                    (unsigned int) z,
                    (unsigned int) z->full_children_elem.ptr1,
                    (unsigned int) z->full_children_elem.ptr2,
                    (unsigned int) zprev);
            return 0;
        }
        if (z->label != FULL) {
            printf ("Node %x has label %d, but is in full set\n",
                    (unsigned int) z, z->label);
            return 0;
        }
    }
    if (cnt != PQ_set_SIZE (x->full_children_set)) {
        printf ("node %x has %d full children, set size %d\n",
                (unsigned int) x, cnt, PQ_set_SIZE (x->full_children_set));
        return 0;
    }
    cnt = 0;
    PQ_set_FOREACH (x->partial_children_set, z, partial_children_elem, zprev, znext) {
        cnt++;
        if (!((z->partial_children_elem.ptr1 == zprev && z->partial_children_elem.ptr2 != zprev) ||
              (z->partial_children_elem.ptr2 == zprev && z->partial_children_elem.ptr1 != zprev) ||
              (z->partial_children_elem.ptr1 == zprev &&
               z->partial_children_elem.ptr2 == zprev && zprev == (PQ_node *) NULL))) {
            printf ("Node %x has partial_children ptr1 %x ptr2 %x, should be =, != %x\n",
                    (unsigned int) z,
                    (unsigned int) z->partial_children_elem.ptr1,
                    (unsigned int) z->partial_children_elem.ptr2,
                    (unsigned int) zprev);
            return 0;
        }
        if (z->label != PARTIAL) {
            printf ("Node %x has label %d, but is in partial set\n",
                    (unsigned int) z, (unsigned int) z->label);
            return 0;
        }
    }
    if (cnt != PQ_set_SIZE (x->partial_children_set)) {
        printf ("node %x has %d partial children, set size %d\n",
                (unsigned int) x, cnt, PQ_set_SIZE (x->partial_children_set));
        return 0;
    }
    return 1;
}

#endif /* NDEBUG */

#ifdef CC_PROTOTYPE_ANSI
PQ_node *XPQ_save_tree (PQ_node *x)
#else
PQ_node *XPQ_save_tree (x)
PQ_node *x;
#endif
{
    PQ_node *rootcopy = PQ_save_work (XPQ_find_root (x));

    rootcopy->parent = (PQ_node *) NULL;
    rootcopy->parenttype = P_NODE;

    return rootcopy;
}

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *PQ_save_work (PQ_node *x)
#else
static PQ_node *PQ_save_work (x)
PQ_node *x;
#endif
{
    PQ_node *xcopy = PQ_node_alloc_work ();
    PQ_node *y, *yprev, *ynext;
    PQ_node *ycopy;

    xcopy->type = x->type;
    xcopy->number = x->number;
    xcopy->next = x;
    PQ_set_INIT (xcopy->children_set);

    PQ_set_FOREACH (x->children_set, y, children_elem, yprev, ynext) {
        ycopy = PQ_save_work (y);
        ycopy->parent = xcopy;
        ycopy->parenttype = xcopy->type;
        PQ_set_ADD_LEFT (ycopy, xcopy->children_set, children_elem);
    }
    return xcopy;
}

#ifdef CC_PROTOTYPE_ANSI
PQ_node *XPQ_restore_tree (PQ_node *x, int saveleaves)
#else
PQ_node *XPQ_restore_tree (x, saveleaves)
PQ_node *x;
int saveleaves;
#endif
{
    PQ_node *rootcopy = PQ_restore_work (x, saveleaves);

    rootcopy->parent = (PQ_node *) NULL;
    rootcopy->parenttype = P_NODE;

    return rootcopy;
}

#ifdef CC_PROTOTYPE_ANSI
static PQ_node *PQ_restore_work (PQ_node *x, int saveleaves)
#else
static PQ_node *PQ_restore_work (x, saveleaves)
PQ_node *x;
int saveleaves;
#endif
{
    PQ_node *xcopy;
    PQ_node *y, *yprev, *ynext;
    PQ_node *ycopy;

    if (saveleaves && (x->type == DIR_NODE || x->type == LEAF_NODE)) {
        xcopy = x->next;
    } else {
        xcopy = PQ_node_alloc_work ();
    }

    xcopy->type = x->type;
    xcopy->number = x->number;
    PQ_set_INIT (xcopy->full_children_set);
    PQ_set_INIT (xcopy->partial_children_set);
    xcopy->label = 0;
    xcopy->mark = 0;
    xcopy->pertinent_child_count = 0;
    xcopy->pertinent_leaf_count = 0;

    PQ_set_INIT (xcopy->children_set);

    PQ_set_FOREACH (x->children_set, y, children_elem, yprev, ynext) {
        ycopy = PQ_restore_work (y, saveleaves);
        ycopy->parent = xcopy;
        ycopy->parenttype = xcopy->type;
        PQ_set_ADD_LEFT (ycopy, xcopy->children_set, children_elem);
    }
    return xcopy;
}

#ifdef CC_PROTOTYPE_ANSI
void XPQ_save_tree_free (PQ_node *x)
#else
void XPQ_save_tree_free (x)
PQ_node *x;
#endif
{
    PQ_tree_free (x, 0);
}

