/**************************************************************************/
/*                                                                        */
/* EXPORTED FUNCTIONS:                                                    */
/*                                                                        */
/*    void                                                                */
/*        cleancomb ();                                                   */
/*                                                                        */
/*    int                                                                 */
/*        checkcomb (),                                                   */
/*        cliquefluff (),                                                 */
/*        temp_combfluff (),                                              */
/*        combfluff (),                                                   */
/*        histok (),                                                      */
/*        checkclique ();                                                 */
/*                                                                        */
/**************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "Xsubtour.h"


#ifdef CC_PROTOTYPE_ANSI

static void
    complement_nodeptrlist (Xgraph *G, Xnodeptr *list, Xnodeptr **new),
    get_smaller_cliquetree (Xgraph *G, Xnodeptrptr **newhandles,
        Xnodeptrptr **newteeth, Xnodeptrptr *handles, Xnodeptrptr *teeth,
        Xnodeptr *specialhandle),
    clean_handle (Xgraph *G, Xnodeptr **handle, Xnodeptrptr **teeth,
                  int *nteeth, int *degree, double *x),
    clean_stretch (Xgraph *G, Xnode *a, Xnode *b, Xnodeptr **toss,
                   Xnodeptr **tooth, int *degree, double *x),
    clean_tooth (Xgraph *G, Xnodeptr *handle, Xnodeptr *tooth,
                 Xnodeptr **newtooth, double *x, int *degree),
    process_clean_tooth_node (Xgraph *G, Xnode *n, double *x, int *degree,
                              Xnodeptr **toss),
    clean_handle_connect_dfs (Xgraph *G, Xnode *n, double *x, int k);

static int
    checkclique_work (Xgraph *G, Xnodeptrptr *handles, Xnodeptrptr *teeth,
                                 int flipped),
    check_for_intersecting_teeth (Xgraph *G, Xnodeptr *handle,
                                  Xnodeptrptr *teeth),
    setmarks (Xgraph *G, int *vec, Xnodeptr *p, int from, int to),
    check_cavity (Xgraph *G, Xnodeptr *p, int *vec),
    verify_13 (Xgraph *G, Xnodeptrptr *handles, Xnodeptrptr *teeth),
    clean_handle_connect (Xgraph *G, Xnodeptr *handle, double *x);

#else

static void
    complement_nodeptrlist (),
    get_smaller_cliquetree (),
    clean_handle (),
    clean_stretch (),
    clean_tooth (),
    process_clean_tooth_node (),
    clean_handle_connect_dfs ();

static int
    checkclique_work (),
    check_for_intersecting_teeth (),
    setmarks (),
    check_cavity (),
    verify_13 (),
    clean_handle_connect ();

#endif


#ifdef CC_PROTOTYPE_ANSI
int Xcheckcomb (Xgraph *G, Xnodeptr *handle, Xnodeptrptr *teeth)
#else
int Xcheckcomb (G, handle, teeth)
Xgraph *G;
Xnodeptr *handle;
Xnodeptrptr *teeth;
#endif
{
    int nteeth, count, in, out;
    Xnodeptr *np;
    Xnodeptrptr *ntp;

    for (nteeth = 0, ntp = teeth; ntp; ntp = ntp->next)
        nteeth++;
    if (nteeth % 2 == 0) {
        return 0;
    }
    G->magicnum++;
    for (count = 0, np = handle; np; np = np->next, count++)
        np->this->magiclabel = G->magicnum;

    if (count < 3) {
        return 0;
    }
    for (count = 0, ntp = teeth; count < nteeth; ntp = ntp->next, count++) {
        in = out = 0;
        for (np = ntp->this; np; np = np->next)
            if (np->this->magiclabel == G->magicnum)
                in = 1;
            else
                out = 1;
        if (!in || !out) {
            return 0;
        }
    }
    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
int Xcliquefluff (Xgraph *G, Xnodeptrptr **handles, Xnodeptrptr **teeth)
#else
int Xcliquefluff (G, handles, teeth)
Xgraph *G;
Xnodeptrptr **handles, **teeth;
#endif
{
    /* Returns 1 if new clique-tree is loaded in handles and teeth */
    /* Returns 0 if clique-tree should be killed, wiping out the cut. */

    int nteeth, nhandles, nonpendant, hit, hit1, hit2, cavity;
    Xnodeptrptr *ntp, *mtp;
    Xnodeptrptr *nonpendant_teeth, *pendant_teeth;
    Xnodeptrptr *handle1_teeth, *handle2_teeth;
    Xnodeptrptr *handle1, *handle2;
    Xnodeptr *np;

    for (nhandles = 0, ntp = *handles; ntp; ntp = ntp->next)
        nhandles++;
    for (nteeth = 0, ntp = *teeth; ntp; ntp = ntp->next)
        nteeth++;

    if (nhandles == 1)
        return Xcombfluff (G, handles, teeth, 0);

    if (nteeth % 2 == 0 || nteeth < 3 || nhandles != 2) {
        Xfreeteeth (*teeth);
        Xfreeteeth (*handles);
        /* printf ("FF Wrong Number of Handles or Teeth\n"); */
        return 0;
    }
    /* COLLECT NONPENDANT TEETH */

    nonpendant_teeth = (Xnodeptrptr *) NULL;
    pendant_teeth = (Xnodeptrptr *) NULL;
    nonpendant = 0;
    for (ntp = *teeth; ntp; ntp = ntp->next) {
        G->magicnum++;
        for (np = ntp->this; np; np = np->next)
            np->this->magiclabel = G->magicnum;
        for (mtp = *handles, hit = 0; mtp && hit < 2; mtp = mtp->next)
            for (np = mtp->this; np; np = np->next)
                if (np->this->magiclabel == G->magicnum) {
                    hit++;
                    break;
                }
        if (hit >= 2) {
            nonpendant++;
            Xadd_nodeptrptr (&nonpendant_teeth, ntp->this);
        } else
            Xadd_nodeptrptr (&pendant_teeth, ntp->this);
    }

    if (nonpendant != 1) {
        Xnodeptrptr_list_free (nonpendant_teeth);
        Xnodeptrptr_list_free (pendant_teeth);
        Xfreeteeth (*teeth);
        Xfreeteeth (*handles);
        return 0;
    }
    /* DO NOT ALLOW NONPENDANT TEETH TO MEET ANY OTHER TEETH */

    G->magicnum++;
    for (ntp = pendant_teeth; ntp; ntp = ntp->next)
        for (np = ntp->this; np; np = np->next)
            np->this->magiclabel = G->magicnum;
    for (ntp = nonpendant_teeth; ntp; ntp = ntp->next)
        for (np = ntp->this; np; np = np->next)
            if (np->this->magiclabel == G->magicnum) {
                Xnodeptrptr_list_free (nonpendant_teeth);
                Xnodeptrptr_list_free (pendant_teeth);
                Xfreeteeth (*teeth);
                Xfreeteeth (*handles);
                /* printf ("FF Nonpendant Teeth Meet\n"); */
                return 0;
            } else
                np->this->magiclabel = G->magicnum;

    /* DIVIDE THE NONPENDANT TEETH AMONGST THE TWO HANDLES */

    G->magicnum++;
    handle1 = (Xnodeptrptr *) NULL;
    Xadd_nodeptrptr (&handle1, (*handles)->this);
    handle1_teeth = (Xnodeptrptr *) NULL;
    for (np = handle1->this; np; np = np->next)
        np->this->magiclabel = G->magicnum;
    for (ntp = pendant_teeth; ntp; ntp = ntp->next)
        for (np = ntp->this; np; np = np->next)
            if (np->this->magiclabel == G->magicnum) {
                Xadd_nodeptrptr (&handle1_teeth, ntp->this);
                break;
            }
    G->magicnum++;
    handle2 = (Xnodeptrptr *) NULL;
    Xadd_nodeptrptr (&handle2, (*handles)->next->this);
    handle2_teeth = (Xnodeptrptr *) NULL;
    for (np = handle2->this; np; np = np->next)
        np->this->magiclabel = G->magicnum;
    for (ntp = pendant_teeth; ntp; ntp = ntp->next)
        for (np = ntp->this; np; np = np->next)
            if (np->this->magiclabel == G->magicnum) {
                Xadd_nodeptrptr (&handle2_teeth, ntp->this);
                break;
            }
    /* WE NO LONGER NEED THE ORIGINAL HANDLE & TEETH LISTS */

    Xnodeptrptr_list_free (*handles);
    Xnodeptrptr_list_free (*teeth);
    Xnodeptrptr_list_free (pendant_teeth);

    /* DON'T ALLOW ANY TOOTH TO MEET A TOOTH HITTING THE OTHER HANDLE */

    G->magicnum++;
    for (ntp = handle1_teeth; ntp; ntp = ntp->next)
        for (np = ntp->this; np; np = np->next)
            np->this->magiclabel = G->magicnum;
    for (ntp = handle2_teeth; ntp; ntp = ntp->next)
        for (np = ntp->this; np; np = np->next)
            if (np->this->magiclabel == G->magicnum) {
                Xfreeteeth (handle1_teeth);
                Xfreeteeth (handle2_teeth);
                Xfreeteeth (handle1);
                Xfreeteeth (handle2);
                Xfreeteeth (nonpendant_teeth);
                /* printf ("FF Cross Teeth Meet\n"); */
                return 0;
            }

    /* USE THE COMB CODE TO CLEAN THE TEETH MEETING EACH HANDLE */

    if (!Xcombfluff (G, &handle1, &handle1_teeth, 1)) {
        Xfreeteeth (handle2);
        Xfreeteeth (handle2_teeth);
        Xfreeteeth (nonpendant_teeth);
        /* printf ("FF Comb Fluff of First Handle Failed\n"); */
        return 0;
    } else if (!Xcombfluff (G, &handle2, &handle2_teeth, 1)) {
        Xfreeteeth (handle1);
        Xfreeteeth (handle1_teeth);
        Xfreeteeth (nonpendant_teeth);
        /* printf ("FF Comb Fluff of Second Handle Failed\n"); */
        return 0;
    }
    if (!handle1 || !handle2 || !handle1_teeth || !handle2_teeth) {
        /* printf ("OH OH IN FLUFF\n"); */
        return 0;
    }

    /* CHECK THAT NEW HANDLES DO NOT MEET */

    G->magicnum++;
    for (np = handle1->this; np; np = np->next)
        np->this->magiclabel = G->magicnum;
    G->magicnum++;
    for (np = handle2->this; np; np = np->next)
        if (np->this->magiclabel == G->magicnum - 1) {
            Xfreeteeth (handle1);
            Xfreeteeth (handle2);
            Xfreeteeth (handle1_teeth);
            Xfreeteeth (handle2_teeth);
            Xfreeteeth (nonpendant_teeth);
            /*  printf ("FF New Handles Meet\n"); */
            return 0;
        } else
            np->this->magiclabel = G->magicnum;

    /* CHECK THAT NONPENDANT TOOTH HAS A CAVITY */

    for (np = nonpendant_teeth->this, hit1 = 0, hit2 = 0, cavity = 0; np;
                                                              np = np->next) {
        if (np->this->magiclabel == G->magicnum - 1)
            hit1++;
        else if (np->this->magiclabel == G->magicnum)
            hit2++;
        else
            cavity++;
    }

    if (!hit1 || !hit2 || !cavity) {
        Xfreeteeth (handle1);
        Xfreeteeth (handle2);
        Xfreeteeth (handle1_teeth);
        Xfreeteeth (handle2_teeth);
        Xfreeteeth (nonpendant_teeth);
        /* printf ("FF Nonpendant Tooth No Longer Has a Cavity\n"); */
        return 0;
    }

    /* PUT THE NEW CLIQUE TREE TOGETHER */

    handle1->next = handle2;
    *handles = handle1;

    ntp = handle1_teeth;
    while (ntp->next)
        ntp = ntp->next;
    if (!ntp) {
        /* printf ("OH OH 2 IN FLUFF\n"); */
        return 0;
    }
    ntp->next = handle2_teeth;
    nonpendant_teeth->next = handle1_teeth;
    *teeth = nonpendant_teeth;

    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
int Xtemp_combfluff (Xgraph *G, Xnodeptr **handle, Xnodeptrptr **teeth)
#else
int Xtemp_combfluff (G, handle, teeth)
Xgraph *G;
Xnodeptr **handle;
Xnodeptrptr **teeth;
#endif
{
    Xnodeptrptr *temphandle;

    temphandle = (Xnodeptrptr *) NULL;
    Xadd_nodeptrptr (&temphandle, *handle);
    if (!Xcliquefluff (G, &temphandle, teeth)) {
        return 0;
    } else {
        *handle = temphandle->this;
        Xnodeptrptrfree (temphandle);
        return 1;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int Xtemp_combcheck (Xgraph *G, Xnodeptr *handle, Xnodeptrptr *teeth)
#else
int Xtemp_combcheck (G, handle, teeth)
Xgraph *G;
Xnodeptr *handle;
Xnodeptrptr *teeth;
#endif
{
    int rval;
    Xnodeptrptr *temphandle;

    temphandle = (Xnodeptrptr *) NULL;
    Xadd_nodeptrptr (&temphandle, handle);

    rval = Xcheckclique (G, temphandle, teeth);
    Xnodeptrptrfree (temphandle);
    return rval;
}

#define SET_NOTEST -2

#ifdef CC_PROTOTYPE_ANSI
int Xcombfluff (Xgraph *G, Xnodeptrptr **handles, Xnodeptrptr **teeth,
                int cliquetest)
#else
int Xcombfluff (G, handles, teeth, cliquetest)
Xgraph *G;
Xnodeptrptr **handles;
Xnodeptrptr **teeth;
int cliquetest;
#endif
{
    int *in_hand;
    int *in_tooth;
    int i, j;
    int nhand;
    int nteeth;
    int newteeth;
    Xnodeptr **teeth_array;
    Xnodeptr *p;
    Xnodeptrptr *np;
    int v;

    for (np = *handles, nhand = 0; np; np = np->next)
        nhand++;
    for (np = *teeth, nteeth = 0; np; np = np->next)
        nteeth++;
    if (nhand != 1) {
        /*
        printf ("FF Fluff Comb called with more (or less) than one handle\n");
        */
        Xfreeteeth (*handles);
        Xfreeteeth (*teeth);
        return 0;
    }
    if (nteeth == 3 && !cliquetest) {
        if (verify_13 (G, *handles, *teeth)) {
            return 1;
        } else {
            for (np = *handles; np; np = np->next) {
                Xnodeptr_list_free (np->this);
            }
            for (np = *teeth; np; np = np->next) {
                Xnodeptr_list_free (np->this);
            }
            Xnodeptrptr_list_free (*handles);
            Xnodeptrptr_list_free (*teeth);
            *handles = (Xnodeptrptr *) NULL;
            *teeth = (Xnodeptrptr *) NULL;
            /* printf ("FF Fluff Comb\n"); */
            return 0;
        }
    }
    in_hand = CC_SAFE_MALLOC (G->nnodes, int);
    in_tooth = CC_SAFE_MALLOC (G->nnodes, int);
    if (!in_hand || !in_tooth) {
        fprintf (stderr, "out of memory in Xcombfluff\n");
        exit (1);
    }

    for (i = 0; i < G->nnodes; i++) {
        in_hand[i] = 0;
        in_tooth[i] = -1;
    }

    if (setmarks (G, in_hand, (*handles)->this, 0, 1) != SET_NOTEST) {
        fprintf (stderr, "A setmarks failed\n");
        exit (1);
    }
    Xnodeptr_list_free ((*handles)->this);

    teeth_array = CC_SAFE_MALLOC (nteeth, Xnodeptr *);
    if (!teeth_array) {
        fprintf (stderr, "out of memory in Xcombfluff\n");
        exit (1);
    }

    for (np = *teeth, i = 0; np; np = np->next, i++) {
        teeth_array[i] = np->this;
    }
    Xnodeptrptr_list_free (*teeth);

    for (i = 0; i < nteeth; i++) {
        v = setmarks (G, in_tooth, teeth_array[i], -1, i);
        if (v != SET_NOTEST) {
            j = in_tooth[v];
            if (setmarks (G, in_tooth, teeth_array[i], i, -1) != v ||
                setmarks (G, in_tooth, teeth_array[j], j, -1) != SET_NOTEST) {
                fprintf (stderr, "B setmarks failed\n");
                exit (1);
            }
            if (in_hand[v]) {
                setmarks (G, in_hand, teeth_array[i], SET_NOTEST, 0);
                setmarks (G, in_hand, teeth_array[j], SET_NOTEST, 0);
            } else {
                setmarks (G, in_hand, teeth_array[i], SET_NOTEST, 1);
                setmarks (G, in_hand, teeth_array[j], SET_NOTEST, 1);
            }
            Xnodeptr_list_free (teeth_array[i]);
            Xnodeptr_list_free (teeth_array[j]);
            teeth_array[i] = (Xnodeptr *) NULL;
            teeth_array[j] = (Xnodeptr *) NULL;
        }
    }
    *teeth = (Xnodeptrptr *) NULL;
    for (i = 0, newteeth = 0; i < nteeth; i++) {
        if (teeth_array[i]) {
            if (check_cavity (G, teeth_array[i], in_hand)) {
                newteeth++;
                Xadd_nodeptrptr (teeth, teeth_array[i]);
            } else {
                Xnodeptr_list_free (teeth_array[i]);
                teeth_array[i] = (Xnodeptr *) NULL;
            }
        }
    }

    if (newteeth > 1 && (((!cliquetest && (newteeth & 1) == 1)) ||
                           (cliquetest && (newteeth & 1) == 0))) {
        p = (Xnodeptr *) NULL;
        for (i = 0; i < G->nnodes; i++) {
            if (in_hand[i]) {
                Xadd_nodeptr (&p, &(G->nodelist[i]));
            }
        }
        *handles = (Xnodeptrptr *) NULL;
        Xadd_nodeptrptr (handles, p);
        CC_FREE (in_hand, int);
        CC_FREE (in_tooth, int);
        CC_FREE (teeth_array, Xnodeptr *);
        return 1;
    } else {
        for (np = *teeth; np; np = np->next) {
            Xnodeptr_list_free (np->this);
        }
        Xnodeptrptr_list_free (*teeth);
        *teeth = (Xnodeptrptr *) NULL;
        *handles = (Xnodeptrptr *) NULL;
        CC_FREE (in_hand, int);
        CC_FREE (in_tooth, int);
        CC_FREE (teeth_array, Xnodeptr *);
        /* printf ("FF Fluff Comb\n"); */
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int setmarks (Xgraph *G, int *vec, Xnodeptr *p, int from, int to)
#else
static int setmarks (G, vec, p, from, to)
Xgraph *G;
int *vec;
Xnodeptr *p;
int from, to;
#endif
{
    if (from == SET_NOTEST) {
        while (p) {
            vec[p->this - G->nodelist] = to;
            p = p->next;
        }
    } else {
        while (p) {
            if (vec[p->this - G->nodelist] != from) {
                return p->this - G->nodelist;
            }
            vec[p->this - G->nodelist] = to;
            p = p->next;
        }
    }
    return SET_NOTEST;
}

#ifdef CC_PROTOTYPE_ANSI
static int check_cavity (Xgraph *G, Xnodeptr *p, int *vec)
#else
static int check_cavity (G, p, vec)
Xgraph *G;
Xnodeptr *p;
int *vec;
#endif
{
    int got_hand = 0;
    int got_cavity = 0;

    while (p) {
        if (vec[p->this - G->nodelist]) {
            if (got_cavity)
                return 1;
            got_hand++;
        } else {
            if (got_hand)
                return 1;
            got_cavity++;
        }
        p = p->next;
    }
    return 0;
}

#define HANDLE 1
#define TOOTH1 2
#define TOOTH2 4
#define TOOTH3 8
#define NREGIONS 16

#ifdef CC_PROTOTYPE_ANSI
static int verify_13 (Xgraph *G, Xnodeptrptr *handles, Xnodeptrptr *teeth)
#else
static int verify_13 (G, handles, teeth)
Xgraph *G;
Xnodeptrptr *handles;
Xnodeptrptr *teeth;
#endif
{
    unsigned int *node_stat;
    unsigned int flip;
    unsigned int hist[NREGIONS];
    unsigned int hist2[NREGIONS];
    int i;
    Xnodeptr *p;
    Xnodeptrptr *pp;
    int nhand;
    int nteeth;

    node_stat = CC_SAFE_MALLOC (G->nnodes, unsigned int);
    if (!node_stat) {
        fprintf (stderr, "out of memory in verify_13\n");
        exit (1);
    }

    for (i = 0; i < G->nnodes; i++) {
        node_stat[i] = 0;
    }
    for (pp = handles, nhand = 0; pp; pp = pp->next, nhand++) {
        for (p = pp->this; p; p = p->next) {
            node_stat[p->this - G->nodelist] |= (1 << nhand);
        }
    }
    for (pp = teeth, nteeth = 0; pp; pp = pp->next, nteeth++) {
        for (p = pp->this; p; p = p->next) {
            node_stat[p->this - G->nodelist] |= 1 << (nhand + nteeth);
        }
    }
    if (nhand != 1 || nteeth != 3) {
        CC_FREE (node_stat, unsigned int);
        return 0;
    }
    for (i = 0; i < NREGIONS; i++) {
        hist[i] = 0;
    }
    for (i = 0; i < G->nnodes; i++) {
        hist[node_stat[i]]++;
    }
    for (flip = 0; flip < NREGIONS; flip++) {
        for (i = 0; i < NREGIONS; i++) {
            hist2[i] = hist[i ^ flip];
        }
        if (Xhistok (hist2)) {
            CC_FREE (node_stat, unsigned int);
            return 1;
        }
    }
    CC_FREE (node_stat, unsigned int);
    /* printf ("CC Verify special failed to find a good flip\n"); */
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int Xhistok (unsigned int *hist)
#else
int Xhistok (hist)
unsigned int *hist;
#endif
{
    if (!hist[TOOTH1])
        return 0;               /* tooth 1 has a cavity */
    if (!hist[TOOTH2])
        return 0;               /* tooth 2 has a cavity */
    if (!hist[TOOTH3])
        return 0;               /* tooth 3 has a cavity */
    if (!hist[TOOTH1 | HANDLE])
        return 0;               /* tooth 1 intersects the handle */
    if (!hist[TOOTH2 | HANDLE])
        return 0;               /* tooth 1 intersects the handle */
    if (!hist[TOOTH3 | HANDLE])
        return 0;               /* tooth 1 intersects the handle */
    if (hist[TOOTH1 | TOOTH2] ||/* Nothing else happens */
        hist[TOOTH1 | TOOTH3] ||
        hist[TOOTH2 | TOOTH3] ||
        hist[TOOTH1 | TOOTH2 | TOOTH3] ||
        hist[TOOTH1 | TOOTH2 | HANDLE] ||
        hist[TOOTH1 | TOOTH3 | HANDLE] ||
        hist[TOOTH2 | TOOTH3 | HANDLE] ||
        hist[TOOTH1 | TOOTH2 | TOOTH3 | HANDLE]) {
        return 0;
    }
    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
int Xcheckclique (Xgraph *G, Xnodeptrptr *handles, Xnodeptrptr *teeth)
#else
int Xcheckclique (G, handles, teeth)
Xgraph *G;
Xnodeptrptr *handles, *teeth;
#endif
{
    return checkclique_work (G, handles, teeth, 0);
}

#ifdef CC_PROTOTYPE_ANSI
static int checkclique_work (Xgraph *G, Xnodeptrptr *handles,
                             Xnodeptrptr *teeth, int flipped)
#else
static int checkclique_work (G, handles, teeth, flipped)
Xgraph *G;
Xnodeptrptr *handles, *teeth;
int flipped;
#endif
{
    int nteeth, nhandles, nonpendant, hit, cavity, inhit;
    Xnodeptr *np, *mp, *newtooth;
    Xnodeptrptr *ntp, *mtp, *nonpendant_teeth, *pendant_teeth;
    Xnodeptrptr *newhandles, *newteeth;
    int special13, rval;

    for (nteeth = 0, ntp = teeth; ntp; ntp = ntp->next)
        nteeth++;
    if (nteeth % 2 == 0) {
        /* printf ("CC Even Number of Teeth: %d\n", nteeth); */
        return 0;
    }
    for (nhandles = 0, ntp = handles; ntp; ntp = ntp->next)
        nhandles++;

    if (nhandles == 0) {
        /* printf ("CC No Handles\n"); */
        return 0;
    }
    if (nhandles == 1 && nteeth == 3)
        special13 = 1;
    else
        special13 = 0;


    /* EASY STUFF - Emtpy cliques, bad node numbers, etc. */

    for (ntp = handles; ntp; ntp = ntp->next) {
        if (!ntp->this) {
            /* printf ("CC Empty Handle\n"); */
            return 0;
        }
        for (hit = 0, np = ntp->this; np; np = np->next) {
            if ((np->this - G->nodelist) < 0 ||
                (np->this - G->nodelist) >= G->nnodes) {
                /* printf ("CC Invalid node number in handle\n"); */
                return 0;
            } else
                hit++;
        }
        if (hit >= G->nnodes) {
            /* printf ("CC Handle is entire graph\n"); */
            return 0;
        }
    }

    for (ntp = teeth; ntp; ntp = ntp->next) {
        if (!ntp->this) {
            /* printf ("CC Empty Tooth\n"); */
            return 0;
        }
        for (hit = 0, np = ntp->this; np; np = np->next) {
            if ((np->this - G->nodelist) < 0 ||
                (np->this - G->nodelist) >= G->nnodes) {
                /* printf ("CC Invalid node number in tooth\n"); */
                return 0;
            } else
                hit++;
        }
        if (hit >= G->nnodes) {
            /* printf ("CC Tooth is entire graph\n"); */
            return 0;
        }
    }

    /* HANDLES SHOULD NEVER INTERSECT */

    G->magicnum++;
    for (ntp = handles; ntp; ntp = ntp->next)
        for (np = ntp->this; np; np = np->next)
            if (np->this->magiclabel == G->magicnum) {
                if (special13)
                    return verify_13 (G, handles, teeth);
                else {
                    /* printf ("CC Handles Meet\n"); */
                    return 0;
                }
            } else
                np->this->magiclabel = G->magicnum;


    /* INSIST THAT EVERY TOOTH HAVE A CAVITY, UNLESS WE HAVE THE 1-3 */
    /* CASE, WHERE WE ALLOW THE INVERTED TOOTH TO HAVE NO CAVITY.    */

    for (ntp = teeth; ntp; ntp = ntp->next) {
        cavity = inhit = 0;
        for (np = ntp->this; np; np = np->next)
            if (np->this->magiclabel != G->magicnum)
                cavity++;
            else
                inhit++;
        if (!cavity || !inhit) {
            if (special13)
                return verify_13 (G, handles, teeth);
            else {
                /* printf ("CC Tooth has no cavity\n"); */
                return 0;
            }
        }
    }

    /* EVERY HANDLE HITS AN ODD NUMBER OF TEETH */

    for (ntp = handles; ntp; ntp = ntp->next) {
        G->magicnum++;
        for (np = ntp->this; np; np = np->next)
            np->this->magiclabel = G->magicnum;
        for (hit = 0, mtp = teeth; mtp; mtp = mtp->next)
            for (mp = mtp->this; mp; mp = mp->next)
                if (mp->this->magiclabel == G->magicnum) {
                    hit++;
                    break;
                }
        if (hit % 2 == 0) {
            if (special13)
                return verify_13 (G, handles, teeth);
            else {
                /* printf ("CC Handle hits even num of teeth\n"); */
                return 0;
            }
        }
    }

    /* TEETH IN COMBS CANNOT INTERSECT UNLESS 1-3 CASE */

    if (nhandles == 1) {
        G->magicnum++;
        for (ntp = teeth; ntp; ntp = ntp->next) {
            for (np = ntp->this; np; np = np->next) {
                if (np->this->magiclabel == G->magicnum) {
                    if (special13)
                        return verify_13 (G, handles, teeth);
                    else {
                        /* printf ("CC Teeth in Comb\n"); */
                        return 0;
                    }
/*
                }
*/

                } else {
                    np->this->magiclabel = G->magicnum;
                }


/******************** BUG *************************************
  SHOULD HAVE:  } else {
                    np->this->magiclabel = G->magicnum;
                }
**************************************************************/

            }
        }
        return 1;
    }
    /* Deal with a multihandled cliquetree by finding a handle to */
    /* delete and check that the remainder is a valid cliquetree. */


    nonpendant_teeth = (Xnodeptrptr *) NULL;
    pendant_teeth = (Xnodeptrptr *) NULL;
    nonpendant = 0;
    for (ntp = teeth; ntp; ntp = ntp->next) {
        G->magicnum++;
        for (np = ntp->this; np; np = np->next)
            np->this->magiclabel = G->magicnum;
        for (mtp = handles, hit = 0; mtp && hit < 2; mtp = mtp->next)
            for (np = mtp->this; np; np = np->next)
                if (np->this->magiclabel == G->magicnum) {
                    hit++;
                    break;
                }
        if (hit >= 2) {
            nonpendant++;
            Xadd_nodeptrptr (&nonpendant_teeth, ntp->this);
        } else
            Xadd_nodeptrptr (&pendant_teeth, ntp->this);
    }

    if (nonpendant > nhandles - 1) {
        /*
        printf ("CC %d handles, but %d nonpendant teeth\n",
                    nhandles, nonpendant);
        */
        Xnodeptrptr_list_free (nonpendant_teeth);
        Xnodeptrptr_list_free (pendant_teeth);
        Xprintcliquetree (G, handles, teeth);
        return 0;
    }
    for (ntp = handles; ntp; ntp = ntp->next) {
        G->magicnum++;
        for (np = ntp->this; np; np = np->next)
            np->this->magiclabel = G->magicnum;
        for (mtp = nonpendant_teeth, hit = 0; mtp && hit < 2; mtp = mtp->next)
            for (np = mtp->this; np; np = np->next)
                if (np->this->magiclabel == G->magicnum) {
                    hit++;
                    break;
                }
        if (!hit) {
            /* printf ("CC Handle meets no nonpendant tooth\n"); */
            Xnodeptrptr_list_free (nonpendant_teeth);
            Xnodeptrptr_list_free (pendant_teeth);
            return 0;
        } else if (hit == 1) {
            if (check_for_intersecting_teeth (G, ntp->this, teeth)) {
                get_smaller_cliquetree (G, &newhandles, &newteeth,
                                        handles, teeth, ntp->this);
                rval = checkclique_work (G, newhandles, newteeth, flipped);
                Xnodeptrptr_list_free (nonpendant_teeth);
                Xnodeptrptr_list_free (pendant_teeth);
                Xnodeptrptr_list_free (newhandles);
                Xnodeptrptr_list_free (newteeth);
                if (!rval) {
                    printf ("CC Bad Recursion\n");
                    Xprintcliquetree (G, handles, teeth);
                    fflush (stdout);
                }
                return rval;
            }
        }
    }

    if (nhandles > 2) {
        /* printf ("CC No good handle (%d) to reduce\n", nhandles); */
    }

    /* TRY FLIPPING THE NONPENDANT TOOTH IN TWO HANDLED CASE */

    if (nhandles == 2 && !flipped) {
        complement_nodeptrlist (G, nonpendant_teeth->this, &newtooth);
        Xadd_nodeptrptr (&pendant_teeth, newtooth);
        rval = checkclique_work (G, handles, pendant_teeth, 1);
        Xnodeptr_list_free (newtooth);
        Xnodeptrptr_list_free (nonpendant_teeth);
        Xnodeptrptr_list_free (pendant_teeth);
        if (rval) {
            /* printf ("CC Needed to Flip the nonpendant tooth.\n"); */
        } else {
            /* printf ("CC FLIP DID NOT HELP\n"); */
        }
        return rval;
    } else {
        Xnodeptrptr_list_free (nonpendant_teeth);
        Xnodeptrptr_list_free (pendant_teeth);
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static void complement_nodeptrlist (Xgraph *G, Xnodeptr *list, Xnodeptr **new)
#else
static void complement_nodeptrlist (G, list, new)
Xgraph *G;
Xnodeptr *list, **new;
#endif
{
    Xnodeptr *np;
    int i;
    Xnode *n;

    *new = (Xnodeptr *) NULL;
    G->magicnum++;
    for (np = list; np; np = np->next)
        np->this->magiclabel = G->magicnum;
    for (i = G->nnodes, n = G->nodelist; i; i--, n++)
        if (n->magiclabel != G->magicnum)
            Xadd_nodeptr (new, n);
}

#ifdef CC_PROTOTYPE_ANSI
static void get_smaller_cliquetree (Xgraph *G, Xnodeptrptr **newhandles,
    Xnodeptrptr **newteeth, Xnodeptrptr *handles, Xnodeptrptr *teeth,
    Xnodeptr *specialhandle)
#else
static void get_smaller_cliquetree (G, newhandles, newteeth, handles,
    teeth, specialhandle)
Xgraph *G;
Xnodeptrptr **newhandles, **newteeth, *handles, *teeth;
Xnodeptr *specialhandle;
#endif
{
    Xnodeptrptr *ntp, *mtp;
    Xnodeptr *np;
    int hit;

    *newhandles = (Xnodeptrptr *) NULL;
    for (ntp = handles; ntp; ntp = ntp->next)
        if (ntp->this != specialhandle)
            Xadd_nodeptrptr (newhandles, ntp->this);
    *newteeth = (Xnodeptrptr *) NULL;
    for (ntp = teeth; ntp; ntp = ntp->next) {
        G->magicnum++;
        for (np = ntp->this; np; np = np->next)
            np->this->magiclabel = G->magicnum;
        for (mtp = *newhandles, hit = 0; mtp && !hit; mtp = mtp->next) {
            for (np = mtp->this; np; np = np->next)
                if (np->this->magiclabel == G->magicnum) {
                    hit++;
                    break;
                }
        }
        if (hit)
            Xadd_nodeptrptr (newteeth, ntp->this);
    }
}

#ifdef CC_PROTOTYPE_ANSI
static int check_for_intersecting_teeth (Xgraph *G, Xnodeptr *handle,
                                         Xnodeptrptr *teeth)
#else
static int check_for_intersecting_teeth (G, handle, teeth)
Xgraph *G;
Xnodeptr *handle;
Xnodeptrptr *teeth;
#endif
{
    Xnodeptrptr *ntp;
    Xnodeptr *np;
    Xnodeptrptr *handle_teeth;

    G->magicnum++;
    for (np = handle; np; np = np->next)
        np->this->magiclabel = G->magicnum;
    handle_teeth = (Xnodeptrptr *) NULL;
    for (ntp = teeth; ntp; ntp = ntp->next)
        for (np = ntp->this; np; np = np->next)
            if (np->this->magiclabel == G->magicnum) {
                Xadd_nodeptrptr (&handle_teeth, ntp->this);
                break;
            }
    G->magicnum++;
    for (ntp = handle_teeth; ntp; ntp = ntp->next)
        for (np = ntp->this; np; np = np->next)
            if (np->this->magiclabel == G->magicnum) {
                Xnodeptrptr_list_free (handle_teeth);
                return 0;
            } else
                np->this->magiclabel = G->magicnum;

    Xnodeptrptr_list_free (handle_teeth);
    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
void Xcleancomb (Xgraph *G, Xnodeptr **handle, Xnodeptrptr **teeth,
                int *nteeth, double *x)
#else
void Xcleancomb (G, handle, teeth, nteeth, x)
Xgraph *G;
Xnodeptr **handle;
Xnodeptrptr **teeth;
int *nteeth;
double *x;
#endif
{
    int *degree;
    Xnodeptrptr *newteeth, *ntp, *newtp;

    /* The cleaned comb goes back into handle and teeth. */

    if (x == (double *) NULL)
        return;

    newteeth = (Xnodeptrptr *) NULL;

    degree = CC_SAFE_MALLOC (G->nnodes, int);
    if (!degree) {
        fprintf (stderr, "out of memory in cleancomb\n");
        exit (1);
    }
    for (ntp = *teeth; ntp; ntp = ntp->next) {
        newtp = Xnodeptrptralloc ();
        newtp->this = (Xnodeptr *) NULL;
        newtp->next = newteeth;
        newteeth = newtp;
        clean_tooth (G, *handle, ntp->this, &(newtp->this), x, degree);
    }

    Xfreeteeth (*teeth);

    *teeth = newteeth;

    clean_handle (G, handle, teeth, nteeth, degree, x);

    CC_FREE (degree, int);
}

#ifdef CC_PROTOTYPE_ANSI
static void clean_handle (Xgraph *G, Xnodeptr **handle, Xnodeptrptr **teeth,
                          int *nteeth, int *degree, double *x)
#else
static void clean_handle (G, handle, teeth, nteeth, degree, x)
Xgraph *G;
Xnodeptr **handle;
Xnodeptrptr **teeth;
int *nteeth, *degree;
double *x;
#endif
{
    Xnodeptr *np, *toss = (Xnodeptr *) NULL;
    Xnodeptrptr *ntp;
    Xnodeptr *tooth1, *tooth2, *newhandle;
    Xnode *n, *n1;
    Xedgeptr *ep;
    Xedge *e;

    if (!clean_handle_connect (G, *handle, x))
        return;

    G->magicnum++;
    for (np = *handle; np; np = np->next) {
        np->this->magiclabel = G->magicnum;
        degree[np->this - G->nodelist] = 0;
    }
    for (np = *handle; np; np = np->next) {
        n = np->this;
        for (ep = n->adj.head; ep; ep = ep->next) {
            e = ep->this;
            if (x[e - G->edgelist] > .9999 &&
                e->ends[0]->magiclabel == G->magicnum &&
                e->ends[1]->magiclabel == G->magicnum)
                (degree[n - G->nodelist])++;
        }
    }
    for (ntp = *teeth; ntp; ntp = ntp->next)
        for (np = ntp->this; np; np = np->next)
            np->this->magiclabel = G->magicnum - 1;

    for (np = *handle; np; np = np->next) {
        n = np->this;
        if (degree[n - G->nodelist] != 2 || n->magiclabel != G->magicnum)
            continue;
        for (ep = n->adj.head; ep; ep = ep->next) {
            e = ep->this;
            n1 = OTHEREND (e, n);
            if (x[e - G->edgelist] > .9999 &&
                n1->magiclabel == G->magicnum &&
                degree[n1 - G->nodelist] == 2) {
                Xadd_nodeptr (&toss, n);
                Xadd_nodeptr (&toss, n1);
                degree[n - G->nodelist] = 0;
                degree[n1 - G->nodelist] = 0;
                clean_stretch (G, n, n1, &toss, &tooth1, degree, x);
                clean_stretch (G, n1, n, &toss, &tooth2, degree, x);
                Xadd_nodeptrptr (teeth, tooth1);
                Xadd_nodeptrptr (teeth, tooth2);
                (*nteeth) += 2;
                break;
            }
        }
    }
    G->magicnum++;
    for (np = toss; np; np = np->next)
        np->this->magiclabel = G->magicnum;

    Xnodeptr_list_free (toss);

    newhandle = (Xnodeptr *) NULL;
    for (np = *handle; np; np = np->next)
        if (np->this->magiclabel != G->magicnum)
            Xadd_nodeptr (&newhandle, np->this);
    Xnodeptr_list_free (*handle);
    *handle = newhandle;
}

#ifdef CC_PROTOTYPE_ANSI
static void clean_stretch (Xgraph *G, Xnode *a, Xnode *b, Xnodeptr **toss,
                           Xnodeptr **tooth, int *degree, double *x)
#else
static void clean_stretch (G, a, b, toss, tooth, degree, x)
Xgraph *G;
Xnode *a, *b;
Xnodeptr **toss, **tooth;
int *degree;
double *x;
#endif
{
    Xnode *c;
    Xedgeptr *ep;
    Xedge *e;

    for (ep = a->adj.head; ep; ep = ep->next) {
        e = ep->this;
        if (x[e - G->edgelist] > .9999 && ((c = OTHEREND (e, a)) != b)) {
            if (degree[c - G->nodelist] == 2 &&
                c->magiclabel == G->magicnum) {
                Xadd_nodeptr (toss, c);
                degree[c - G->nodelist] = 0;
                clean_stretch (G, c, a, toss, tooth, degree, x);
            } else {
                *tooth = (Xnodeptr *) NULL;
                Xadd_nodeptr (tooth, a);
                Xadd_nodeptr (tooth, c);
            }
            return;
        }
    }
    printf ("ERROR IN CLEAN_STRETCH\n");
    fflush (stdout);
}

#ifdef CC_PROTOTYPE_ANSI
static void clean_tooth (Xgraph *G, Xnodeptr *handle, Xnodeptr *tooth,
                         Xnodeptr **newtooth, double *x, int *degree)
#else
static void clean_tooth (G, handle, tooth, newtooth, x, degree)
Xgraph *G;
Xnodeptr *handle, *tooth, **newtooth;
double *x;
int *degree;
#endif
{
    Xnodeptr *np, *np1, *toss;
    Xnode *n;
    Xedgeptr *ep;
    Xedge *e;

    G->magicnum++;
    for (np = tooth; np; np = np->next) {
        degree[np->this - G->nodelist] = 0;
        np->this->magiclabel = G->magicnum;
    }

    for (np = tooth; np; np = np->next) {
        n = np->this;
        for (ep = n->adj.head; ep; ep = ep->next) {
            e = ep->this;
            if (x[e - G->edgelist] > XEPSILON &&
                e->ends[0]->magiclabel == e->ends[1]->magiclabel)
                (degree[n - G->nodelist])++;
        }
    }

    G->magicnum++;
    for (np = handle; np; np = np->next) {
        np->this->magiclabel = G->magicnum;
    }

    toss = (Xnodeptr *) NULL;

    for (np = tooth; np; np = np->next) {
        n = np->this;
        if (n->magiclabel == G->magicnum - 1 && degree[n - G->nodelist] == 1)
            process_clean_tooth_node (G, n, x, degree, &toss);
    }
    G->magicnum++;

    for (np = toss; np; np = np->next)
        np->this->magiclabel = G->magicnum;

    Xnodeptr_list_free (toss);

    *newtooth = (Xnodeptr *) NULL;
    for (np = tooth; np; np = np->next)
        if (np->this->magiclabel != G->magicnum) {
            np1 = Xnodeptralloc ();
            np1->this = np->this;
            np1->next = *newtooth;
            *newtooth = np1;
        }
}

#ifdef CC_PROTOTYPE_ANSI
static void process_clean_tooth_node (Xgraph *G, Xnode *n, double *x,
                                      int *degree, Xnodeptr **toss)
#else
static void process_clean_tooth_node (G, n, x, degree, toss)
Xgraph *G;
Xnode *n;
double *x;
int *degree;
Xnodeptr **toss;
#endif
{
    Xedgeptr *ep;
    Xedge *e;
    Xnodeptr *np;
    Xnode *n1;
    double t;

    for (ep = n->adj.head; ep; ep = ep->next) {
        e = ep->this;
        t = x[e - G->edgelist];
        if (t > XEPSILON &&
            e->ends[0]->magiclabel == e->ends[1]->magiclabel) {
            if (t > 0.9999) {
                np = Xnodeptralloc ();
                np->this = n;
                np->next = *toss;
                *toss = np;
                n->magiclabel = G->magicnum - 2;
                n1 = OTHEREND (e, n);
                if (degree[n1 - G->nodelist] == 2)
                    process_clean_tooth_node (G, n1, x, degree, toss);
            }
            return;
        }
    }
    return;
}

#ifdef CC_PROTOTYPE_ANSI
static int clean_handle_connect (Xgraph *G, Xnodeptr *handle, double *x)
#else
static int clean_handle_connect (G, handle, x)
Xgraph *G;
Xnodeptr *handle;
double *x;
#endif
{
    Xnodeptr *np;

    if (handle == (Xnodeptr *) NULL)
        return 0;

    G->magicnum++;
    for (np = handle; np; np = np->next)
        np->this->magiclabel = G->magicnum;

    clean_handle_connect_dfs (G, handle->this, x, G->magicnum);

    for (np = handle; np; np = np->next)
        if (np->this->magiclabel == G->magicnum)
            return 0;

    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
static void clean_handle_connect_dfs (Xgraph *G, Xnode *start, double *x, int k)
#else
static void clean_handle_connect_dfs (G, start, x, k)
Xgraph *G;
Xnode *start;
double *x;
int k;
#endif
{
    Xedgeptr *ep;
    Xedge *e;
    Xnode *n, *n1;
    Xnodeptr *next, *queue = (Xnodeptr *) NULL;

    start->magiclabel = k - 1;
    Xadd_nodeptr (&queue, start);

    while (queue) {
        n = queue->this;
        next = queue->next;
        Xnodeptrfree (queue);
        queue = next;

        for (ep = n->adj.head; ep; ep = ep->next) {
            e = ep->this;
            if (x[e - G->edgelist] > 0.005) {
                n1 = OTHEREND (e, n);
                if (n1->magiclabel == k) {
                    n1->magiclabel = k - 1;
                    Xadd_nodeptr (&queue, n1);
                }
            }
        }
    }
}

