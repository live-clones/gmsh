/**************************************************************************/
/*                                                                        */
/* EXPORTED FUNCTIONS:                                                    */
/*                                                                        */
/*    void                                                                */
/*        freecplanestruct (),                                            */
/*        freeiplanestruct (),                                            */
/*        cplane_to_iplane (),                                            */
/*        iplane_to_cplane (),                                            */
/*        portablecut_to_cplane (),                                       */
/*        portablecut_to_handles_and_teeth (),                            */
/*        portablecut_to_iplane (),                                       */
/*        freeteeth (),                                                   */
/*        printchvatalcomb (),                                            */
/*        printcliquetree (),                                             */
/*        dumpchvatalcomb (),                                             */
/*        dumpcliquetree ();                                              */
/*                                                                        */
/*    int                                                                 */
/*        slackclique (),                                                 */
/*        induced_edges_flow ();                                          */
/*                                                                        */
/*    NOT CALLED:  portablecut_to_handles_and_teeth()                     */
/*                                                                        */
/**************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "Xsubtour.h"

#ifdef CC_PROTOTYPE_ANSI
int Xslackclique (Xgraph *G, Xnodeptrptr *handles, Xnodeptrptr *teeth,
                 double *slack)
#else
int Xslackclique (G, handles, teeth, slack)
Xgraph *G;
Xnodeptrptr *handles, *teeth;
double *slack;
#endif
{
    /* ASSUMES x VALUES ON THE EDGES  */
    int hit, H, T, TI, nteeth;
    Xedge *e, *lastedge = (G->edgelist) + G->nedges;
    Xnodeptr *np;
    Xnodeptrptr *ntp, *mtp;
    double sum, rhs;

    for (e = G->edgelist; e != lastedge; e++)
        e->flow = 0.0;

    for (ntp = handles, H = 0; ntp; ntp = ntp->next) {
        H += Xinduced_edges_flow (G, ntp->this);
    }
    for (ntp = teeth, nteeth = 0, T = 0; ntp; ntp = ntp->next) {
        nteeth++;
        T += Xinduced_edges_flow (G, ntp->this);
    }

    for (ntp = teeth, TI = 0; ntp; ntp = ntp->next) {
        G->magicnum++;
        for (np = ntp->this; np; np = np->next)
            np->this->magiclabel = G->magicnum;
        for (hit = 0, mtp = handles; mtp; mtp = mtp->next) {
            for (np = mtp->this; np; np = np->next) {
                if (np->this->magiclabel == G->magicnum) {
                    TI++;
                    hit++;
                    break;
                }
            }
        }
        if (!hit) {
            fprintf (stderr, "Tooth doesn't meet handles\n");
            return 0;
        }
    }

    rhs = H + T - TI - ((nteeth + 1) / 2);

    for (e = G->edgelist, sum = 0.0; e != lastedge; e++)
        if (e->flow >= 1.0)
            sum += (e->flow * e->x);

    *slack = rhs - sum;
    return 1;
}


#ifdef CC_PROTOTYPE_ANSI
int Xinduced_edges_flow (Xgraph *G, Xnodeptr *set)
#else
int Xinduced_edges_flow (G, set)
Xgraph *G;
Xnodeptr *set;
#endif
{
    Xnodeptr *np;
    Xedgeptr *ep;
    int count;

    G->magicnum++;
    for (np = set, count = 0; np; count++, np = np->next)
        np->this->magiclabel = G->magicnum;
    for (np = set; np; np = np->next)
        for (ep = np->this->adj.head; ep; ep = ep->next)
            if (ep->this->ends[0]->magiclabel ==
                ep->this->ends[1]->magiclabel)
                ep->this->flow += 0.5;
    return count;
}

#ifdef CC_PROTOTYPE_ANSI
void Xfreecplanestruct (Xcplane *c)
#else
void Xfreecplanestruct (c)
Xcplane *c;
#endif
{
    if (c->handle != (Xnodeptr *) NULL)
        Xnodeptr_list_free (c->handle);
    if (c->handles != (Xnodeptrptr *) NULL)
        Xfreeteeth (c->handles);
    if (c->teeth != (Xnodeptrptr *) NULL)
        Xfreeteeth (c->teeth);
    Xcplanefree (c);
}

#ifdef CC_PROTOTYPE_ANSI
void Xfreeiplanestruct (Xiplane *c)
#else
void Xfreeiplanestruct (c)
Xiplane *c;
#endif
{
    Xintptrptr *itp;

    if (c->handle)
        Xintptr_list_free (c->handle);
    if (c->handles) {
        for (itp = c->handles; itp; itp = itp->next)
            Xintptr_list_free (itp->this);
        Xintptrptr_list_free (c->handles);
    }
    if (c->teeth) {
        for (itp = c->teeth; itp; itp = itp->next)
            Xintptr_list_free (itp->this);
        Xintptrptr_list_free (c->teeth);
    }
    Xiplanefree (c);
}

#ifdef CC_PROTOTYPE_ANSI
void Xcplane_to_iplane (Xgraph *G, Xcplane *c, Xiplane **ipl)
#else
void Xcplane_to_iplane (G, c, ipl)
Xgraph *G;
Xcplane *c;
Xiplane **ipl;
#endif
{
    Xintptr *handle, *ip, *tooth, *h;
    Xintptrptr *handles, *teeth;
    Xnodeptr *np;
    Xnodeptrptr *ntp;

    if (c->handle) {
        handle = (Xintptr *) NULL;
        for (np = c->handle; np; np = np->next) {
            ip = Xintptralloc ();
            ip->this = np->this - G->nodelist;
            ip->next = handle;
            handle = ip;
        }
    } else
        handle = (Xintptr *) NULL;

    if (c->handles) {
        handles = (Xintptrptr *) NULL;
        for (ntp = c->handles; ntp; ntp = ntp->next) {
            h = (Xintptr *) NULL;
            for (np = ntp->this; np; np = np->next) {
                ip = Xintptralloc ();
                ip->this = np->this - G->nodelist;
                ip->next = h;
                h = ip;
            }
            Xadd_intptrptr (&handles, h);
        }
    } else
        handles = (Xintptrptr *) NULL;

    if (c->teeth) {
        teeth = (Xintptrptr *) NULL;
        for (ntp = c->teeth; ntp; ntp = ntp->next) {
            tooth = (Xintptr *) NULL;
            for (np = ntp->this; np; np = np->next) {
                ip = Xintptralloc ();
                ip->this = np->this - G->nodelist;
                ip->next = tooth;
                tooth = ip;
            }
            Xadd_intptrptr (&teeth, tooth);
        }
    } else
        teeth = (Xintptrptr *) NULL;

    *ipl = Xiplanealloc ();
    (*ipl)->handle = handle;
    (*ipl)->handles = handles;
    (*ipl)->teeth = teeth;
}

#ifdef CC_PROTOTYPE_ANSI
void Xiplane_to_cplane (Xgraph *G, Xiplane *c, Xcplane **cpl)
#else
void Xiplane_to_cplane (G, c, cpl)
Xgraph *G;
Xiplane *c;
Xcplane **cpl;
#endif
{
    Xnodeptr *handle, *np, *tooth, *h;
    Xnodeptrptr *handles, *teeth;
    Xintptr *ip;
    Xintptrptr *itp;

    if (c->handle) {
        handle = (Xnodeptr *) NULL;
        for (ip = c->handle; ip; ip = ip->next) {
            np = Xnodeptralloc ();
            np->this = ip->this + G->nodelist;
            np->next = handle;
            handle = np;
        }
    } else
        handle = (Xnodeptr *) NULL;

    if (c->handles) {
        handles = (Xnodeptrptr *) NULL;
        for (itp = c->handles; itp; itp = itp->next) {
            h = (Xnodeptr *) NULL;
            for (ip = itp->this; ip; ip = ip->next) {
                np = Xnodeptralloc ();
                np->this = ip->this + G->nodelist;
                np->next = h;
                h = np;
            }
            Xadd_nodeptrptr (&handles, h);
        }
    } else
        handles = (Xnodeptrptr *) NULL;

    if (c->teeth) {
        teeth = (Xnodeptrptr *) NULL;
        for (itp = c->teeth; itp; itp = itp->next) {
            tooth = (Xnodeptr *) NULL;
            for (ip = itp->this; ip; ip = ip->next) {
                np = Xnodeptralloc ();
                np->this = ip->this + G->nodelist;
                np->next = tooth;
                tooth = np;
            }
            Xadd_nodeptrptr (&teeth, tooth);
        }
    } else
        teeth = (Xnodeptrptr *) NULL;

    *cpl = Xcplanealloc ();
    (*cpl)->handle = handle;
    (*cpl)->handles = handles;
    (*cpl)->teeth = teeth;
}

#ifdef CC_PROTOTYPE_ANSI
void Xportablecut_to_cplane (Xgraph *G, Xportablecut *p, Xcplane **cpl)
#else
void Xportablecut_to_cplane (G, p, cpl)
Xgraph *G;
Xportablecut *p;
Xcplane **cpl;
#endif
{
    Xnodeptr *np, *tooth, *h;
    Xnodeptrptr *handles, *teeth;
    int i, k;

    handles = (Xnodeptrptr *) NULL;
    for (i = 0, k = 0; i < p->nhandles; i++) {
        h = (Xnodeptr *) NULL;
        while (p->handles[k] != -1) {
            np = Xnodeptralloc ();
            np->this = p->handles[k++] + G->nodelist;
            np->next = h;
            h = np;
        }
        Xadd_nodeptrptr (&handles, h);
        k++;
    }

    teeth = (Xnodeptrptr *) NULL;
    for (i = 0, k = 0; i < p->nteeth; i++) {
        tooth = (Xnodeptr *) NULL;
        while (p->teeth[k] != -1) {
            np = Xnodeptralloc ();
            np->this = p->teeth[k++] + G->nodelist;
            np->next = tooth;
            tooth = np;
        }
        Xadd_nodeptrptr (&teeth, tooth);
        k++;
    }

    *cpl = Xcplanealloc ();
    (*cpl)->handle = (Xnodeptr *) NULL;
    (*cpl)->handles = handles;
    (*cpl)->teeth = teeth;
}

#ifdef CC_PROTOTYPE_ANSI
void Xportablecut_to_handles_and_teeth (Xgraph *G, Xportablecut *p,
                            Xnodeptrptr **handles, Xnodeptrptr **teeth)
#else
void Xportablecut_to_handles_and_teeth (G, p, handles, teeth)
Xgraph *G;
Xportablecut *p;
Xnodeptrptr **handles, **teeth;
#endif
{
    Xnodeptr *np, *tooth, *h;
    int i, k;

    *handles = (Xnodeptrptr *) NULL;
    for (i = 0, k = 0; i < p->nhandles; i++) {
        h = (Xnodeptr *) NULL;
        while (p->handles[k] != -1) {
            np = Xnodeptralloc ();
            np->this = p->handles[k++] + G->nodelist;
            np->next = h;
            h = np;
        }
        Xadd_nodeptrptr (handles, h);
        k++;
    }

    *teeth = (Xnodeptrptr *) NULL;
    for (i = 0, k = 0; i < p->nteeth; i++) {
        tooth = (Xnodeptr *) NULL;
        while (p->teeth[k] != -1) {
            np = Xnodeptralloc ();
            np->this = p->teeth[k++] + G->nodelist;
            np->next = tooth;
            tooth = np;
        }
        Xadd_nodeptrptr (teeth, tooth);
        k++;
    }
}

#ifdef CC_PROTOTYPE_ANSI
void Xportablecut_to_iplane (Xportablecut *p, Xiplane **ipl)
#else
void Xportablecut_to_iplane (p, ipl)
Xportablecut *p;
Xiplane **ipl;
#endif
{
    Xintptr *ip, *tooth, *h;
    Xintptrptr *handles, *teeth;
    int i, k;

    handles = (Xintptrptr *) NULL;
    for (i = 0, k = 0; i < p->nhandles; i++) {
        h = (Xintptr *) NULL;
        while (p->handles[k] != -1) {
            ip = Xintptralloc ();
            ip->this = p->handles[k++];
            ip->next = h;
            h = ip;
        }
        Xadd_intptrptr (&handles, h);
        k++;
    }

    teeth = (Xintptrptr *) NULL;
    for (i = 0, k = 0; i < p->nteeth; i++) {
        tooth = (Xintptr *) NULL;
        while (p->teeth[k] != -1) {
            ip = Xintptralloc ();
            ip->this = p->teeth[k++];
            ip->next = tooth;
            tooth = ip;
        }
        Xadd_intptrptr (&teeth, tooth);
        k++;
    }

    *ipl = Xiplanealloc ();
    (*ipl)->handle = (Xintptr *) NULL;
    (*ipl)->handles = handles;
    (*ipl)->teeth = teeth;
}

#ifdef CC_PROTOTYPE_ANSI
void Xiplane_to_portablecut (Xiplane *c, Xportablecut *p)
#else
void Xiplane_to_portablecut (c, p)
Xiplane *c;
Xportablecut *p;
#endif
{
    int hands, handcount;
    int teeth, teethcount;
    int k;
    Xintptr *ip;
    Xintptrptr *ipp;

    if (c->handle) {
        p->nhandles = 1;
        for (ip = c->handle, handcount = 0; ip; ip = ip->next)
            handcount++;
        handcount++;
        p->handles = CC_SAFE_MALLOC (handcount, int);
        if (!p->handles) {
            fprintf (stderr, "out of memory in iplane_to_portablecut\n");
            exit (1);
        }
        for (ip = c->handle, k = 0; ip; ip = ip->next)
            p->handles[k++] = ip->this;
        p->handles[k] = -1;
    } else {
        for (ipp = c->handles, hands = 0; ipp; ipp = ipp->next)
            hands++;
        p->nhandles = hands;
        for (ipp = c->handles, handcount = 0; ipp; ipp = ipp->next) {
            for (ip = ipp->this; ip; ip = ip->next)
                handcount++;
            handcount++;
        }
        p->handles = CC_SAFE_MALLOC (handcount, int);
        if (!p->handles) {
            fprintf (stderr, "out of memory in iplane_to_portablecut\n");
            exit (1);
        }
        for (ipp = c->handles, k = 0; ipp; ipp = ipp->next) {
            for (ip = ipp->this; ip; ip = ip->next)
                p->handles[k++] = ip->this;
            p->handles[k++] = -1;
        }
    }

    for (ipp = c->teeth, teeth = 0; ipp; ipp = ipp->next)
        teeth++;
    p->nteeth = teeth;
    for (ipp = c->teeth, teethcount = 0; ipp; ipp = ipp->next) {
        for (ip = ipp->this; ip; ip = ip->next)
            teethcount++;
        teethcount++;
    }
    p->teeth = CC_SAFE_MALLOC (teethcount, int);
    if (!p->teeth) {
        fprintf (stderr, "out of memory in iplane_to_portablecut\n");
        exit (1);
    }

    for (ipp = c->teeth, k = 0; ipp; ipp = ipp->next) {
        for (ip = ipp->this; ip; ip = ip->next)
            p->teeth[k++] = ip->this;
        p->teeth[k++] = -1;
    }
}

#ifdef CC_PROTOTYPE_ANSI
void Xfreeteeth (Xnodeptrptr *teeth)
#else
void Xfreeteeth (teeth)
Xnodeptrptr *teeth;
#endif
{
    Xnodeptrptr *ntp;

    for (ntp = teeth; ntp; ntp = ntp->next)
        Xnodeptr_list_free (ntp->this);
    Xnodeptrptr_list_free (teeth);
}

#ifdef CC_PROTOTYPE_ANSI
void Xprintchvatalcomb (Xgraph *G, Xnodeptr *h, Xnodeptrptr *t)
#else
void Xprintchvatalcomb (G, h, t)
Xgraph *G;
Xnodeptr *h;
Xnodeptrptr *t;
#endif
{
    Xnodeptr *np;
    Xnodeptrptr *ntp;
    int i;

    printf ("HANDLE: ");
    fflush (stdout);
    for (np = h; np; np = np->next) {
        printf ("%d ", (int) (np->this - G->nodelist));
        fflush (stdout);
    }
    printf ("\n");
    for (i = 0, ntp = t; ntp; ntp = ntp->next, i++) {
        printf ("TOOTH[%d]: ", i);
        fflush (stdout);
        for (np = ntp->this; np; np = np->next) {
            printf ("%d ", (int) (np->this - G->nodelist));
            fflush (stdout);
        }
        printf ("\n");
    }
    printf ("\n");
}

#ifdef CC_PROTOTYPE_ANSI
void Xprintcliquetree (Xgraph *G, Xnodeptrptr *h, Xnodeptrptr *t)
#else
void Xprintcliquetree (G, h, t)
Xgraph *G;
Xnodeptrptr *h, *t;
#endif
{
    Xnodeptr *np;
    Xnodeptrptr *ntp;
    int i;

    for (i = 0, ntp = h; ntp; ntp = ntp->next, i++) {
        printf ("HANDLE[%d]: ", i);
        fflush (stdout);
        for (np = ntp->this; np; np = np->next) {
            printf ("%d ", (int) (np->this - G->nodelist));
            fflush (stdout);
        }
        printf ("\n");
    }
    for (i = 0, ntp = t; ntp; ntp = ntp->next, i++) {
        printf ("TOOTH[%d]: ", i);
        fflush (stdout);
        for (np = ntp->this; np; np = np->next) {
            printf ("%d ", (int) (np->this - G->nodelist));
            fflush (stdout);
        }
        printf ("\n");
    }
    printf ("\n");
}

/* Format  #handles  #teeth  (handle) -1  (handle) -1 ... (tooth) -1 ... */

#ifdef CC_PROTOTYPE_ANSI
void Xdumpchvatalcomb (FILE *out, Xintptr *h, Xintptrptr *t)
#else
void Xdumpchvatalcomb (out, h, t)
FILE *out;
Xintptr *h;
Xintptrptr *t;
#endif
{
    Xintptr *ip;
    Xintptrptr *itp;
    int nteeth;

    for (nteeth = 0, itp = t; itp; itp = itp->next)
        nteeth++;

    fprintf (out, "1 %d  ", nteeth);
    for (ip = h; ip; ip = ip->next)
        fprintf (out, "%d ", ip->this);
    fprintf (out, "%d ", -1);
    for (itp = t; itp; itp = itp->next) {
        for (ip = itp->this; ip; ip = ip->next)
            fprintf (out, "%d ", ip->this);
        fprintf (out, "%d ", -1);
    }
    fprintf (out, "\n");
}

#ifdef CC_PROTOTYPE_ANSI
void Xdumpcliquetree (FILE *out, Xintptrptr *h, Xintptrptr *t)
#else
void Xdumpcliquetree (out, h, t)
FILE *out;
Xintptrptr *h;
Xintptrptr *t;
#endif
{
    Xintptr *ip;
    Xintptrptr *itp;
    int nteeth, nhandles;

    for (nhandles = 0, itp = h; itp; itp = itp->next)
        nhandles++;
    for (nteeth = 0, itp = t; itp; itp = itp->next)
        nteeth++;

    fprintf (out, "%d  ", nhandles);
    fprintf (out, "%d  ", nteeth);
    for (itp = h; itp; itp = itp->next) {
        for (ip = itp->this; ip; ip = ip->next)
            fprintf (out, "%d ", ip->this);
        fprintf (out, "%d ", -1);
    }
    for (itp = t; itp; itp = itp->next) {
        for (ip = itp->this; ip; ip = ip->next)
            fprintf (out, "%d ", ip->this);
        fprintf (out, "%d ", -1);
    }
    fprintf (out, "\n");
}

