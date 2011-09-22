#ifndef __XPQSETS_H
#define __XPQSETS_H

typedef struct PQ_set {
    int size;
    struct PQ_node *left;
    struct PQ_node *right;
} PQ_set;

typedef struct PQ_elem {
    struct PQ_node *ptr1;
    struct PQ_node *ptr2;
} PQ_elem;

/* Summary of the macros:
   PQ_set_INIT(PQ_set s) initializes s to the empty set

   PQ_set_ISEMPTY(PQ_set s) is an expression which tests if s is empty

   PQ_set_SIZE(PQ_set s) is the size of s

   PQ_set_PTR_TO(PQ_elem e, PQ_node *q) is the field of e which points to q

   PQ_set_PTR_REPLACE(PQ_elem e, PQ_node *q, PQ_node *r) replaces q with r
   in e

   PQ_set_PTR_AWAY(PQ_elem e, PQ_node *q) is the field of e which doesn't
   point to q

   PQ_set_ADD_WORK(PQ_node *x, PQ_set s, ELEM_FIELD efield, DIRECTION dir)
   adds x to s at the dir end, using the efield field to link things
   together. It is intended to be an internal macro used by PQ_set_ADD_LEFT
   and PQ_set_ADD_RIGHT.

   PQ_set_ADD_LEFT(PQ_node *x, PQ_set s, ELEM_FIELD efield) adds x to s at
   the left end.

   PQ_set_ADD_RIGHT(PQ_node *x, PQ_set s, ELEM_FIELD efield) adds x to s at
   the right end.

   PQ_set_ADD(PQ_node *x, PQ_set s, ELEM_FIELD efield) adds x to s

   PQ_set_DELETE(PQ_node *x, PQ_set s, ELEM_FIELD efield) deletes x from s

   PQ_set_DELETE2(PQ_node *x, SET_FIELD sfield, ELEM_FIELD efield) deletes
   x from the sfield set of its parent.  If x is an endmost child in this
   set, then DELETE2 uses the parent pointer to find the set field.
   Otherwise, the parent pointer is not used.

   PQ_set_LEFT_ELEM(PQ_set s) is the left element of s, or NULL if s is
   empty

   PQ_set_RIGHT_ELEM(PQ_set s) is the right element of s, or NULL if s is
   empty

   PQ_set_FOREACH(PQ_set s, PQ_node *x, ELEM_FIELD efield, PQ_node *xprev,
                  PQ_node *xnext) iterates x over elements of s using
   temporary variables xprev and xnext.

   PQ_set_FOREACH_FROM(PQ_node *x, ELEM_FIELD efield, PQ_node *xprev,
                       PQ_node *xnext) iterates x over elements of s starting
   at x and going away from xprev.  xnext is a temporary variable used in
   the loop, which also changes xprev and x

   PQ_set_FOREACH_DEL(PQ_set s, PQ_node *x, ELEM_FIELD efield,
                      PQ_node *xprev, PQ_node *xnext) iterates x over
   elements of s using temporary variables xprev and xnext.  x may be deleted
   from the set in the body of the loop (but delete any other element from s
   at your own risk).

   PQ_set_FOREACH_ADJ(PQ_node *x, ELEM_FIELD efield, PQ_node *z, int itemp)
   iterates z over the immediate neighbors of x using itemp as a temporary
   variable. It is just used to save code replication when you want to do
   something for each of the two neighbors.

*/


/* PQ_set_INIT(PQ_set s) initializes s to the empty set */

#define PQ_set_INIT(s) {                                                \
    (s).size = 0;                                                       \
    (s).left = (PQ_node *) NULL;                                        \
    (s).right = (PQ_node *) NULL;                                       \
}

/* In the comments below, something of type ELEM_FIELD is the name of a field
   in a PQ_node of type PQ_elem, and something of type DIRECTION is either
   left or right. */

/* PQ_set_ISEMPTY(PQ_set s) is an expression which tests if s is empty */

#define PQ_set_ISEMPTY(s)       ((s).left == (PQ_node *) NULL)

/* PQ_set_SIZE(PQ_set s) is the size of s */

#define PQ_set_SIZE(s)  ((s).size)

/* PQ_set_PTR_TO(PQ_elem e, PQ_node *q) is the field of e which points to q */

#define PQ_set_PTR_TO(e,q)      (((e).ptr1 == (q)) ? ((e).ptr1) : ((e).ptr2))

/* PQ_set_PTR_REPLACE(PQ_elem e, PQ_node *q, PQ_node *r) replaces q with r
   in e */

#define PQ_set_PTR_REPLACE(e,q,r) {                                     \
        if ((e).ptr1 == (q)) {                                          \
                (e).ptr1 = (r);                                         \
        } else {                                                        \
                (e).ptr2 = (r);                                         \
        }                                                               \
}

/* PQ_set_PTR_AWAY(pq_elem e, PQ_node *q) is the field of e which doesn't
   point to q */

#define PQ_set_PTR_AWAY(e,q)    (((e).ptr1 == (q)) ? ((e).ptr2) : ((e).ptr1))

/* PQ_set_ADD_WORK(PQ_node *x, PQ_set s, ELEM_FIELD efield, DIRECTION dir)
   adds x to s at the dir end, using the efield field to link things
   together. It is intended to be an internal macro used by PQ_set_ADD_LEFT
   and PQ_set_ADD_RIGHT. */

#define PQ_set_ADD_WORK(x,s,efield,dir) {                               \
    (x)->efield.ptr1 = (s).dir;                                         \
    (x)->efield.ptr2 = (PQ_node *) NULL;                                \
    if ((s).dir) {                                                      \
        PQ_set_PTR_REPLACE((s).dir->efield,(PQ_node *) NULL, (x));              \
        (s).dir = (x);                                                  \
    } else {                                                            \
        (s).left = (s).right = (x);                                     \
    }                                                                   \
    (s).size++;                                                         \
}

/* PQ_set_ADD_LEFT(PQ_node *x, PQ_set s, ELEM_FIELD efield) adds x to s at
   the left end. */

#define PQ_set_ADD_LEFT(x,s,efield) PQ_set_ADD_WORK(x,s,efield,left)

/* PQ_set_ADD_RIGHT(PQ_node *x, PQ_set s, ELEM_FIELD efield) adds x to s at
   the right end. */

#define PQ_set_ADD_RIGHT(x,s,efield) PQ_set_ADD_WORK(x,s,efield,right)

/* PQ_set_ADD(PQ_node *x, PQ_set s, ELEM_FIELD efield) adds x to s */

#define PQ_set_ADD(x,s,efield) PQ_set_ADD_LEFT(x,s,efield)

/* PQ_set_DELETE(PQ_node *x, PQ_set s, ELEM_FIELD efield) deletes x from s */

#define PQ_set_DELETE(x,s,efield) {                                     \
    if (PQ_set_ISEMPTY(s)) {                                            \
        fprintf (stderr, "Error - attempt to delete from empty set\n"); \
    }                                                                   \
    if ((x)->efield.ptr1) {                                             \
        PQ_set_PTR_REPLACE((x)->efield.ptr1->efield,(x),(x)->efield.ptr2); \
    } else {                                                            \
        if ((s).left == (x)) {                                          \
                (s).left = (x)->efield.ptr2;                            \
        } else {                                                        \
                (s).right = (x)->efield.ptr2;                           \
        }                                                               \
    }                                                                   \
    if ((x)->efield.ptr2) {                                             \
        PQ_set_PTR_REPLACE((x)->efield.ptr2->efield,(x),(x)->efield.ptr1);\
    } else {                                                            \
        if ((s).right == (x)) {                                         \
                (s).right = (x)->efield.ptr1;                           \
        } else {                                                        \
                (s).left = (x)->efield.ptr1;                            \
        }                                                               \
    }                                                                   \
    (s).size--;                                                         \
}

/* PQ_set_DELETE2(PQ_node *x, SET_FIELD sfield, ELEM_FIELD efield) deletes
   x from the sfield set of its parent.  If x is an endmost child in this
   set, then DELETE2 uses the parent pointer to find the set field.
   Otherwise, the parent pointer is not used.  If the parent pointer is
   NULL, then the parent update is ignored. */

#define PQ_set_DELETE2(x,sfield,efield) {                               \
    if ((x)->efield.ptr1) {                                             \
        PQ_set_PTR_REPLACE((x)->efield.ptr1->efield,(x),(x)->efield.ptr2); \
    } else if ((x)->parent) {                                           \
        if ((x)->parent->sfield.left == (x)) {                          \
                (x)->parent->sfield.left = (x)->efield.ptr2;            \
        } else {                                                        \
                (x)->parent->sfield.right = (x)->efield.ptr2;           \
        }                                                               \
    }                                                                   \
    if ((x)->efield.ptr2) {                                             \
        PQ_set_PTR_REPLACE((x)->efield.ptr2->efield,(x),(x)->efield.ptr1);\
    } else if ((x)->parent) {                                           \
        if ((x)->parent->sfield.right == (x)) {                         \
                (x)->parent->sfield.right = (x)->efield.ptr1;           \
        } else {                                                        \
                (x)->parent->sfield.left = (x)->efield.ptr1;            \
        }                                                               \
    }                                                                   \
    if ((x)->parent) {                                                  \
        (x)->parent->sfield.size--;                                     \
    }                                                                   \
}

/* PQ_set_LEFT_ELEM(PQ_set s) is the left element of s, or NULL if s is
   empty */

#define PQ_set_LEFT_ELEM(s) ((s).left)

/* PQ_set_RIGHT_ELEM(PQ_set s) is the right element of s, or NULL if s is
   empty */

#define PQ_set_RIGHT_ELEM(s) ((s).right)

/* PQ_set_FOREACH(PQ_set s, PQ_node *x, ELEM_FIELD efield, PQ_node *xprev,
                  PQ_node *xnext) iterates x over elements of s using
   temporary variables xprev and xnext. */

#define PQ_set_FOREACH(s,x,efield,xprev,xnext)                          \
        for ((xprev) = (PQ_node *) NULL,                                \
             (x) = (s).left;                                            \
            (x);                                                        \
             (xnext) = PQ_set_PTR_AWAY((x)->efield,xprev),              \
             (xprev) = (x),                                             \
             (x) = (xnext)                                              \
)

/* PQ_set_FOREACH_FROM(PQ_node *x, ELEM_FIELD efield, PQ_node *xprev,
                       PQ_node *xnext) iterates x over elements of s starting
   at x and going away from xprev.  xnext is a temporary variable used in
   the loop, which also changes xprev and x */

#define PQ_set_FOREACH_FROM(x,efield,xprev,xnext)                       \
        for (;                                                          \
            (x);                                                        \
             (xnext) = PQ_set_PTR_AWAY((x)->efield,xprev),              \
             (xprev) = (x),                                             \
             (x) = (xnext)                                              \
)

/* PQ_set_FOREACH_DEL(PQ_set s, PQ_node *x, ELEM_FIELD efield,
                      PQ_node *xprev, PQ_node *xnext) iterates x over
   elements of s using temporary variables xprev and xnext.  x may be deleted
   from the set in the body of the loop (but delete any other element from s
   at your own risk). */

#define PQ_set_FOREACH_DEL(s,x,efield,xprev,xnext)                      \
        for ((xprev) = (PQ_node *) NULL,                                \
             (x) = (s).left,                                            \
             (xnext) = ((x) ? PQ_set_PTR_AWAY((x)->efield,(PQ_node *) NULL) \
                            : (PQ_node *) NULL);                        \
            (x);                                                        \
             (xprev) = (((xprev) ? (((xprev)->efield.ptr1 == (x))       \
                                 || ((xprev)->efield.ptr2 == (x)))      \
                                 : ((s).left == (x)))                   \
                        ? (x) : (xprev)),                               \
             (x) = (xnext),                                             \
             (xnext) = ((x) ? PQ_set_PTR_AWAY((x)->efield, xprev)       \
                            : (PQ_node *) NULL) \
)

/* PQ_set_FOREACH_ADJ(PQ_node *x, ELEM_FIELD efield, PQ_node *z, int itemp)
   iterates z over the immediate neighbors of x using itemp as a temporary
   variable. It is just used to save code replication when you want to do
   something for each of the two neighbors. */

#define PQ_set_FOREACH_ADJ(x,efield,z,itemp)                            \
        for (z = x->efield.ptr1, itemp = 0;                             \
             itemp < 2;                                                 \
             z = x->efield.ptr2, itemp++)

#ifndef SWAP
#define SWAP(x, y, t) (((t) = (x)),((x) = (y)),((y) = (t)))
#endif

#endif  /* __XPQSETS_H */
