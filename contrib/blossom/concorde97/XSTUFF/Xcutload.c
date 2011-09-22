/**************************************************************************/
/*                                                                        */
/* EXPORTED FUNCTIONS:                                                    */
/*                                                                        */
/*    void                                                                */
/*        cliquetree_slack_rhs_flow (),                                   */
/*        destroycutlinks (),                                             */
/*        freecplanelist ();                                              */
/*    int                                                                 */
/*        cutchecksout (),                                                */
/*        temp_doblossom (),                                              */
/*        violated_clique_flow (),                                        */
/*        loadcplane (),                                                  */
/*        loadcplane_cut (),                                              */
/*                                                                        */
/**************************************************************************/

#include "machdefs.h"
#include "Xsubtour.h"

#ifdef CC_PROTOTYPE_ANSI
int Xcutchecksout (Xgraph *G, int x)
#else
int Xcutchecksout (G, x)
Xgraph *G;
int x;
#endif
{
    double weight = 0.0;
    int i;
    Xedge *e;

    for (i = G->nedges, e = G->edgelist; i; i--, e++)
        if ((e->ends[0]->magiclabel == x) !=
            (e->ends[1]->magiclabel == x))
            weight += e->x;

    return (weight <= 2.0 - XEPSILON);
}

#ifdef CC_PROTOTYPE_ANSI
int Xtemp_doblossom (Xgraph *G, Xcplane **cplanelist, Xnodeptr *handle,
                     Xedgeptr *teeth)
#else
int Xtemp_doblossom (G, cplanelist, handle, teeth)
Xgraph *G;
Xcplane **cplanelist;
Xnodeptr *handle;
Xedgeptr *teeth;
#endif
{
    Xnodeptrptr *temp_teeth, *ntp;
    Xedgeptr *ep;
    int nteeth, i, returnval;
    int countcheck = 1;

    for (nteeth = 0, ep = teeth; ep; ep = ep->next)
        nteeth++;

    if (nteeth % 2 == 0) {
        fprintf (stderr, "EVEN NUMBER OF TEETH on a blossom\n");
        Xnodeptr_list_free (handle);
        return 0;
    }
    temp_teeth = (Xnodeptrptr *) NULL;
    for (i = 0, ep = teeth; i < nteeth; i++, ep = ep->next) {
        ntp = Xnodeptrptralloc ();
        ntp->this = (Xnodeptr *) NULL;
        ntp->next = temp_teeth;
        temp_teeth = ntp;

        Xadd_nodeptr (&(ntp->this), ep->this->ends[0]);
        Xadd_nodeptr (&(ntp->this), ep->this->ends[1]);
    }

    if (!Xtemp_combfluff (G, &handle, &temp_teeth)) {
        return 0;
    }

    returnval = Xloadcplane (cplanelist, handle, (Xnodeptrptr *) NULL,
                             temp_teeth, countcheck);
    if (!returnval) {
        Xfreeteeth (temp_teeth);
        Xnodeptr_list_free (handle);
        return 0;
    }

    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
void Xcliquetree_slack_rhs_flow (Xgraph *G, Xnodeptrptr *handles,
             Xnodeptrptr *teeth, double *x, double *slack, double *rhs)
#else
void Xcliquetree_slack_rhs_flow (G, handles, teeth, x, slack, rhs)
Xgraph *G;
Xnodeptrptr *handles, *teeth;
double *x;
double *slack, *rhs;
#endif
{
    int i;
    Xedge *e;
    Xnodeptrptr *ntp, *mtp;
    Xnodeptr *np;
    int nteeth;
    int H, T, TI;
    double sum;

    /* Puts cliquetree coef on the flow variables, computes rhs of */
    /* the cliquetree, and computes slack if x is given.           */

    for (i = G->nedges, e = G->edgelist; i; i--, e++)
        e->flow = 0.0;

    for (ntp = handles, H = 0; ntp; ntp = ntp->next) {
        H += Xinduced_edges_flow (G, ntp->this);
    }
    for (ntp = teeth, nteeth = 0, T = 0; ntp; ntp = ntp->next) {
        nteeth++;
        T += Xinduced_edges_flow (G, ntp->this);
    }

    /* TI will be the sum over all teeth of the number of handles */
    /* a given tooth meets.                                           */

    for (ntp = teeth, TI = 0; ntp; ntp = ntp->next) {
        G->magicnum++;
        for (np = ntp->this; np; np = np->next)
            np->this->magiclabel = G->magicnum;
        for (mtp = handles; mtp; mtp = mtp->next) {
            for (np = mtp->this; np; np = np->next) {
                if (np->this->magiclabel == G->magicnum) {
                    TI++;
                    break;
                }
            }
        }
    }

    *rhs = H + T - TI - ((nteeth + 1) / 2);

    if (x) {
        for (i = G->nedges, e = G->edgelist, sum = 0.0; i; i--, e++)
            if (e->flow >= 1.0)
                sum += (e->flow * x[e - G->edgelist]);
        *slack = *rhs - sum;
    } else {
        *slack = 0.0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int Xviolated_clique_flow (Xgraph *G, Xnodeptrptr *handles, Xnodeptrptr *teeth,
                           double *x)
#else
int Xviolated_clique_flow (G, handles, teeth, x)
Xgraph *G;
Xnodeptrptr *handles;
Xnodeptrptr *teeth;
double *x;
#endif
{
    double slack, rhs;

    if (!Xcheckclique (G, handles, teeth))
        return 0;

    Xcliquetree_slack_rhs_flow (G, handles, teeth, x, &slack, &rhs);

    if (slack > -XEPSILON) {
        return 0;
    } else {
        return 1;
    }
}

#define MAXCOMBSIZE 150

#ifdef CC_PROTOTYPE_ANSI
int Xloadcplane (Xcplane **list, Xnodeptr *h, Xnodeptrptr *H,
                 Xnodeptrptr *t, int countcheck)
#else
int Xloadcplane (list, h, H, t, countcheck)
Xcplane **list;
Xnodeptr *h;
Xnodeptrptr *H;
Xnodeptrptr *t;
int countcheck;
#endif
{
    unsigned long val;
    Xcplane *c;
    Xnodeptr *np;
    Xnodeptrptr *ntp;
    int count;

    if (t == (Xnodeptrptr *) NULL)
        val = Xcut_hash_value (h);
    else if (H == (Xnodeptrptr *) NULL)
        val = Xcomb_hash_value (h, t);
    else
        val = Xclique_hash_value (H, t);

    for (c = *list; c; c = c->next)
        if (c->val == val)
            break;
    if (c == (Xcplane *) NULL) {
        if (t != (Xnodeptrptr *) NULL && h != (Xnodeptr *) NULL && countcheck) {
            count = 0;
            for (np = h; np; np = np->next)
                count++;
            for (ntp = t; ntp; ntp = ntp->next)
                for (np = ntp->this; np; np = np->next)
                    count++;
            if (count > MAXCOMBSIZE)
                return 0;
        }
        c = Xcplanealloc ();
        c->val = val;
        c->handle = h;
        c->handles = H;
        c->teeth = t;
        c->next = *list;
        *list = c;
        return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int Xloadcplane_cut (Xgraph *G, Xcplane **list, int num)
#else
int Xloadcplane_cut (G, list, num)
Xgraph *G;
Xcplane **list;
int num;
#endif
{
    Xnodeptr *handle, *np;
    Xnode *n;
    int i, cnt = 0, test, countcheck = 1;

    for (i = 0; i < G->nnodes; i++)
        if (G->nodelist[i].magiclabel == num)
            cnt++;

    if (cnt < 3 || cnt > G->nnodes - 2)
        return 0;

    if (cnt <= G->nnodes / 2) {
        for (handle = (Xnodeptr *) NULL, i = G->nnodes, n = G->nodelist; i;
             n++, i--) {
            if (n->magiclabel == num) {
                np = Xnodeptralloc ();
                np->this = n;
                np->next = handle;
                handle = np;
            }
        }
    } else {
        for (handle = (Xnodeptr *) NULL, i = G->nnodes, n = G->nodelist; i;
             n++, i--) {
            if (n->magiclabel != num) {
                np = Xnodeptralloc ();
                np->this = n;
                np->next = handle;
                handle = np;
            }
        }
    }
    test = Xloadcplane (list, handle, (Xnodeptrptr *) NULL,
                       (Xnodeptrptr *) NULL, countcheck);
    if (!test) {
        Xnodeptr_list_free (handle);
    }
    return test;
}

#ifdef CC_PROTOTYPE_ANSI
void Xfreecplanelist (Xcplane **list)
#else
void Xfreecplanelist (list)
Xcplane **list;
#endif
{
    Xcplane *c, *cnext;

    for (c = *list; c; c = cnext) {
        cnext = c->next;
        Xfreecplanestruct (c);
    }
    *list = (Xcplane *) NULL;
}
