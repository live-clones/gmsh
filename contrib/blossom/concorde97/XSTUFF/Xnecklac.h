#ifndef __XNECKLAC_H
#define __XNECKLAC_H
typedef struct Xneckedge {
    struct PQ_node *ends[2];
    struct PQ_node *cends[2];
    double x;
    int magiclabel;
    int insystem;
    int inspanning;
    int necklabel;
    struct Xneckedge *next;
} Xneckedge;

typedef struct Xneckedgeptr {
    struct Xneckedge *this;
    struct Xneckedgeptr *next;
} Xneckedgeptr;

typedef struct Xeqn {
    struct Xintptr *lhs;
    int rhs;
    struct Xeqn *next;
    int pivot;
    int hitdense;
} Xeqn;

typedef struct bin_var {
#define VALUE_UNKNOWN (-1)
    int value;
    int fixed;
    struct Xeqn *elim;
} bin_var;

typedef struct bin_system {
    int nvars;
    int nfreevars;
    struct bin_var *vars;
    struct Xeqn *sparselist;
    struct Xeqn *denseeqn;
} bin_system;

#ifdef CC_PROTOTYPE_ANSI

/* ouralloc.c */

Xeqn *Xeqnalloc (void);
Xneckedgeptr *Xneckedgeptralloc (void);
void Xadd_neckedgeptr (Xneckedgeptr **, Xneckedge *);
void Xeqnfree (Xeqn *);
void Xneckedgeptrfree (Xneckedgeptr *);
void Xneckedgeptr_list_free (Xneckedgeptr *);

#else

/* ouralloc.c */

Xeqn *Xeqnalloc ();
Xneckedgeptr *Xneckedgeptralloc ();
void Xadd_neckedgeptr ();
void Xeqnfree ();
void Xneckedgeptrfree ();
void Xneckedgeptr_list_free ();

#endif
#endif /*  __XNECKLAC_H */
