/**************************************************************************/
/*                                                                        */
/*                CONVERT AN EDGE LIST TO A CYCLE ARRAY                   */
/*                                                                        */
/*                              TSP CODE                                  */
/*                                                                        */
/*  Written by: Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: February 8, 1995                                                */
/*                                                                        */
/*  EXPORTED FUNCTION:                                                    */
/*      int CCutil_edge_to_cycle (int ncount, int *elist, int *cyc)       */
/*        elist - edgelist in end1 end2 format                            */
/*        cyc - returns the cycle in node node node format                */
/*              (the calling routine should allocate cyc)                 */
/*        Returns a nonzero value if there was and error.                 */
/*                                                                        */
/**************************************************************************/

#include "machdefs.h"
#include "util.h"

#ifdef CC_PROTOTYPE_ANSI
int CCutil_edge_to_cycle (int ncount, int *elist, int *cyc)
#else
int CCutil_edge_to_cycle (ncount, elist, cyc)
int ncount;
int *elist, *cyc;
#endif
{
    int *Lside, *Rside;
    int i, k, end1, end2, prev, this, next, start, okfirst, first = 0;

    Lside = CC_SAFE_MALLOC (ncount, int);
    if (!Lside)
        return 1;
    Rside = CC_SAFE_MALLOC (ncount, int);
    if (!Rside) {
        CC_FREE (Lside, int);
        return 1;
    }
    for (i = 0; i < ncount; i++) {
        Lside[i] = Rside[i] = -1;
    }

    for (i = 0, k = 0; i < ncount; i++) {
        end1 = elist[k++];
        end2 = elist[k++];
        if (Lside[end1] == -1)
            Lside[end1] = end2;
        else
            Rside[end1] = end2;
        if (Lside[end2] == -1)
            Lside[end2] = end1;
        else
            Rside[end2] = end1;
    }

    for (i = 0, k = 0; i < ncount; i++) {
        end1 = elist[k++];
        end2 = elist[k++];
        if (Lside[end1] == -1 || Rside[end1] == -1 ||
            Lside[end2] == -1 || Rside[end2] == -1) {
            fprintf (stderr, "Error in circuit\n");
            CC_FREE (Lside, int);
            CC_FREE (Rside, int);
            return  1;
        }
    }
    start = elist[0];
    prev = -2;
    this = start;
    k = 0;
    okfirst = 0;
    do {
        if (this == first)
           okfirst = 1;
        if (Lside[this] != prev)
            next = Lside[this];
        else
            next = Rside[this];
        prev = this;
        this = next;
        k++;
    } while (next != start && k < ncount);

    if (k != ncount || !okfirst) {
        fprintf (stderr, "Error in circuit\n");
        CC_FREE (Lside, int);
        CC_FREE (Rside, int);
        return 1;
    }

    start = first;
    prev = -2;
    this = start;
    k = 0;
    do {
        cyc[k++] = this;
        if (Lside[this] != prev)
            next = Lside[this];
        else
            next = Rside[this];
        prev = this;
        this = next;
    } while (next != start && k < ncount);

    CC_FREE (Lside, int);
    CC_FREE (Rside, int);
    return 0;
}
