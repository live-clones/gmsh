/***************************************************************************/
/*                                                                         */
/*            ROUTINES TO MAP NODE PAIRS TO EDGES                          */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: September 27, 1995                                               */
/*                                                                         */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "tsp.h"
#include "macrorus.h"

CC_PTR_ALLOC_ROUTINE (CCtsp_edgeinf, edgeinf_alloc, edgeinf_bigchunklist,
        edgeinf_freelist)
CC_PTR_FREE_ROUTINE (CCtsp_edgeinf, edgeinf_free, edgeinf_freelist)
CC_PTR_FREE_LIST_ROUTINE(CCtsp_edgeinf, edgeinf_list_free, edgeinf_free)
CC_PTR_FREE_WORLD_ROUTINE (CCtsp_edgeinf, edgeinf_free_world,
        edgeinf_bigchunklist, edgeinf_freelist)

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_edgehash_init (CCtsp_edgehash *h, int size)
#else
int CCtsp_edgehash_init (h, size)
CCtsp_edgehash *h;
int size;
#endif
{
    unsigned int i;

    h->size = CCutil_nextprime ((unsigned int) size);
    h->mult = (int) sqrt ((double) h->size);
    h->table = CC_SAFE_MALLOC ((int) h->size, CCtsp_edgeinf *);
    if (!h->table) {
        h->size = 0;
        return 1;
    }
    for (i=0; i<h->size; i++) {
        h->table[i] = (CCtsp_edgeinf *) NULL;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_edgehash_add (CCtsp_edgehash *h, int end1, int end2, int val)
#else
int CCtsp_edgehash_add (h, end1, end2, val)
CCtsp_edgehash *h;
int end1;
int end2;
int val;
#endif
{
    int t;
    unsigned int loc;
    CCtsp_edgeinf *e;

    if (h->size == 0) return 1;
    e = edgeinf_alloc();
    if (!e) return 1;

    if (end1 > end2) CC_SWAP (end1, end2, t);
    loc = (end1 * h->mult + end2) % h->size;
    e->ends[0] = end1;
    e->ends[1] = end2;
    e->val = val;
    e->next = h->table[loc];
    h->table[loc] = e;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_edgehash_del (CCtsp_edgehash *h, int end1, int end2)
#else
int CCtsp_edgehash_del (h, end1, end2)
CCtsp_edgehash *h;
int end1;
int end2;
#endif
{
    int t;
    CCtsp_edgeinf **prev;
    CCtsp_edgeinf *p;

    if (end1 > end2) CC_SWAP (end1, end2, t);
    if (h->size == 0) return 1;

    prev  = &h->table[(end1 * h->mult + end2) % h->size];
    p = *prev;
    while (p) {
        if (p->ends[0] == end1 && p->ends[1] == end2) {
            *prev = p->next;
            edgeinf_free (p);
            return 0;
        }
        prev = &p->next;
        p = *prev;
    }
    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_edgehash_delall (CCtsp_edgehash *h)
#else
void CCtsp_edgehash_delall (h)
CCtsp_edgehash *h;
#endif
{
    unsigned int i;

    for (i=0; i<h->size; i++) {
        if (h->table[i]) {
            edgeinf_list_free (h->table[i]);
            h->table[i] = (CCtsp_edgeinf *) NULL;
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_edgehash_find (CCtsp_edgehash *h, int end1, int end2)
#else
int CCtsp_edgehash_find (h, end1, end2)
CCtsp_edgehash *h;
int end1;
int end2;
#endif
{
    int t;
    CCtsp_edgeinf *p;

    if (end1 > end2) CC_SWAP (end1, end2, t);
    if (h->size == 0) return -1;

    for (p = h->table[(end1 * h->mult + end2) % h->size]; p; p = p->next) {
        if (p->ends[0] == end1 && p->ends[1] == end2) {
            return p->val;
        }
    }
    return -1;
}

#ifdef CC_PROTOTYPE_ANSI
void CCtsp_edgehash_free (CCtsp_edgehash *h)
#else
void CCtsp_edgehash_free (h)
CCtsp_edgehash *h;
#endif
{
    CCtsp_edgehash_delall (h);
    CC_FREE (h->table, CCtsp_edgeinf *);
    edgeinf_free_world ();
    h->size = 0;
}
