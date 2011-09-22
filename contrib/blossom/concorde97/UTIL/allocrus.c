/***************************************************************************/
/*                                                                         */
/*                   MEMORY ALLOCATION MACROS                              */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: February 2, 1995 (cofeb16)                                       */
/*                                                                         */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    void *CCutil_allocrus (unsigned int size)                            */
/*         RETURNS a pointer to an allocated block of "size" memory.       */
/*                                                                         */
/*    void CCutil_freerus (void *ptr)                                      */
/*         FREES ptr.                                                      */
/*                                                                         */
/*    void *CCutil_reallocrus (void *ptr, unsigned int size)               */
/*         REALLOCS ptr to size bytes.                                     */
/*                                                                         */
/*    int CCutil_reallocrus_scale (void **pptr, int *pnnum, int count,     */
/*            double scale, unsigned int size)                             */
/*         void **pptr (a reference to the pointer to the allocated space) */
/*         int *pnnum (a reference to the number of objects in the         */
/*                     allocated space)                                    */
/*         int count (a minimum value for the new nnum)                    */
/*         double scale (a scale factor to apply to nnum)                  */
/*         int size (the size of objects to be realloced)                  */
/*         RETURNS 0 if *pptr was successfully changed to point to at      */
/*                 least max(*pnnum*scale, *pnnum+1000, count) objects.    */
/*                 *pnnum is changed to the new object count.              */
/*                 Otherwise, prints an error message, leaves *pptr and    */
/*                 *pnnum alone, and returns nonzero.                      */
/*                                                                         */
/*    int CCutil_reallocrus_count (void **pptr, int count,                 */
/*            unsigned int size)                                           */
/*         void **pptr (a reference to the pointer to the allocated space) */
/*         int count (number of objects to be realloced)                   */
/*         int size (the size of the objects to be realloced)              */
/*         RETURNS 0 is successful, and 1 if the realloc failed.           */
/*                                                                         */
/*                                                                         */
/*    CCbigchunkptr *CCutil_bigchunkalloc (void)                           */
/*         RETURNS a CCbigchunkptr with the "this" field loaded with a     */
/*                 a pointer to a bigchunk of memory.                      */
/*    CCutil_bigchunkfree (CCbigchunkptr *bp)                              */
/*         ACTION: Gives the CCbigchunkptr back to the global supply.      */
/*    int CCutil_bigchunk_free_world (void)                                */
/*         ACTION: Gives the global supply of CCbigchunkptrs and bigchunks */
/*                 back to the system. It returns a nonzero value if there */
/*                 was an error.                                           */
/*                                                                         */
/*    NOTES:                                                               */
/*       Functions prototyped in allocrus.h.                               */
/*       The idea is to use bigchunks (the size of a bigchunk is defined   */
/*       by BIGCHUNK in allocrus.h) to supply local routines with memory   */
/*       for ptrs, so the memory can be shared with other local routines.  */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"

static CCbigchunkptr *local_bigchunk_list = (CCbigchunkptr *) NULL;
static CCbigchunkptr *bigchunk_list = (CCbigchunkptr *) NULL;
static CCbigchunkptr *bigchunk_freelist = (CCbigchunkptr *) NULL;
static CCbigchunkptr *bigchunkptr_freelist = (CCbigchunkptr *) NULL;

static int bigchunktotal = 0;
static int bigchunkreserve = 0;
static int bigchunkptrtotal = 0;

#ifdef CC_PROTOTYPE_ANSI

static void
    bigchunkptrfree (CCbigchunkptr *bp);

static CCbigchunkptr
    *bigchunkptralloc (void);

#else

static void
    bigchunkptrfree ();

static CCbigchunkptr
    *bigchunkptralloc ();

#endif



#ifdef CC_PROTOTYPE_ANSI
void *CCutil_allocrus (unsigned int size)
#else
void *CCutil_allocrus (size)
unsigned int size;
#endif
{
    void *mem = (void *) NULL;

    if (size == 0) {
        fprintf (stderr, "Warning: 0 bytes allocated\n");
    }

    mem = (void *) malloc (size);
    if (mem == (void *) NULL) {
        fprintf (stderr, "Out of memory. Asked for %d bytes\n", size);
    }
    return mem;
}

#ifdef CC_PROTOTYPE_ANSI
void CCutil_freerus (void *p)
#else
void CCutil_freerus (p)
void *p;
#endif
{
    if (!p) {
        fprintf (stderr, "Warning: null pointer freed\n");
        return;
    }

    free (p);
}

#ifdef CC_PROTOTYPE_ANSI
void *CCutil_reallocrus (void *ptr, unsigned int size)
#else
void *CCutil_reallocrus (ptr, size)
void *ptr;
unsigned int size;
#endif
{
    void *newptr;

    if (!ptr) {
        return CCutil_allocrus (size);
    } else {
        newptr = (void *) realloc (ptr, size);
        if (!newptr) {
            fprintf (stderr, "Out of memory.  Tried to grow %d bytes\n", size);
        }
        return newptr;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_reallocrus_scale (void **pptr, int *pnnum, int count, double scale,
        unsigned int size)
#else
int CCutil_reallocrus_scale (pptr, pnnum, count, scale, size)
void **pptr;
int *pnnum;
int count;
double scale;
unsigned int size;
#endif
{
    int newsize = (int) (((double) *pnnum) * scale);
    void *p;

    if (newsize < *pnnum+1000) newsize = *pnnum+1000;
    if (newsize < count) newsize = count;
    p = CCutil_reallocrus (*pptr, newsize * size);
    if (!p) {
        return 1;
    } else {
        *pptr = p;
        *pnnum = newsize;
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_reallocrus_count (void **pptr, int count, unsigned int size)
#else
int CCutil_reallocrus_count (pptr, count, size)
void **pptr;
int count;
unsigned int size;
#endif
{
    void *p = CCutil_reallocrus (*pptr, count * size);

    if (!p) {
        return 1;
    } else {
        *pptr = p;
        return 0;
    }
}


#ifdef CC_PROTOTYPE_ANSI
CCbigchunkptr *CCutil_bigchunkalloc (void)
#else
CCbigchunkptr *CCutil_bigchunkalloc ()
#endif
{
    void *p;
    CCbigchunkptr *bp, *cp;

    if (!bigchunk_freelist) {
        p = (void *) CCutil_allocrus (CC_BIGCHUNK);
        if (!p)
            return (CCbigchunkptr *) NULL;
        bp = bigchunkptralloc ();
        if (!bp) {
            CC_FREE (p, void);
            return (CCbigchunkptr *) NULL;
        }
        cp = bigchunkptralloc ();
        if (!cp) {
            CC_FREE (p, void);
            bigchunkptrfree (bp);
            return (CCbigchunkptr *) NULL;
        }
        bp->this = p;
        cp->this = p;
        cp->next = bigchunk_list;
        bigchunk_list = cp;
        bigchunktotal++;
        return bp;
    } else {
        bp = bigchunk_freelist;
        bigchunk_freelist = bp->next;
        bigchunkreserve--;
        return bp;
    }
}

#ifdef CC_PROTOTYPE_ANSI
void CCutil_bigchunkfree (CCbigchunkptr *bp)
#else
void CCutil_bigchunkfree (bp)
CCbigchunkptr *bp;
#endif
{
    bp->next = bigchunk_freelist;
    bigchunk_freelist = bp;
    bigchunkreserve++;
}

#ifdef CC_PROTOTYPE_ANSI
void CCutil_bigchunkquery (int *total, int *reserve)
#else
void CCutil_bigchunkquery (total, reserve)
int *total, *reserve;
#endif
{
    *total = bigchunktotal;
    *reserve = bigchunkreserve;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_bigchunk_free_world (void)
#else
int CCutil_bigchunk_free_world ()
#endif
{
    int duplicates = 0, localcount, bpcount, i;
    void **tosslist;
    CCbigchunkptr *bp, *bpnext;

    /* First some checking, to see that the routines were used properly */

    if (bigchunkreserve != bigchunktotal) {
        fprintf (stderr, "WARNING: %d outstanding bigchunks\n",
                 bigchunktotal - bigchunkreserve);
    }
    for (bp = bigchunk_freelist; bp; bp = bp->next)
        bp->this = (void *) NULL;
    for (bp = bigchunk_freelist; bp; bp = bp->next) {
        if (bp->this == (void *) 1)
            duplicates++;
        else
            bp->this = (void *) 1;
    }
    if (duplicates) {
        fprintf (stderr, "WARNING: %d duplicate bigchunks returned",
                 duplicates);
    }

    /* Now free the global bigchunks */

    for (bp = bigchunk_list; bp; bp = bpnext) {
        bpnext = bp->next;
        CC_FREE (bp->this, void);
        bigchunkptrfree (bp);
    }
    for (bp = bigchunk_freelist; bp; bp = bpnext) {
        bpnext = bp->next;
        bigchunkptrfree (bp);
    }

    /* Record the local bigchunks used by the bigchunkptrs */

    localcount = 0;
    for (bp = local_bigchunk_list; bp; bp = bp->next)
        localcount++;
    if (!localcount)
        return 0;  /* We haven't allocated anything */

    tosslist = CC_SAFE_MALLOC(localcount, void *);
    if (!tosslist)
        return 1;
    localcount = 0;
    for (bp = local_bigchunk_list; bp; bp = bpnext) {
        bpnext = bp->next;
        tosslist[localcount++] = bp->this;
        bigchunkptrfree (bp);
    }

    /* Check that the bigchunkptrs were used correctly */

    bpcount = 0;
    for (bp = bigchunkptr_freelist; bp; bp = bp->next) {
        bp->this = (void *) NULL;
        bpcount++;
    }
    if (bpcount != bigchunkptrtotal) {
        fprintf (stderr, "WARNING: %d outstanding bigchunkptrs\n",
                 bigchunkptrtotal - bpcount);
    }
    duplicates = 0;
    for (bp = bigchunkptr_freelist; bp; bp = bp->next) {
        if (bp->this == (void *) 1)
            duplicates++;
        else
            bp->this = (void *) 1;
    }
    if (duplicates) {
        fprintf (stderr, "WARNING: %d duplicate bigchunksptrs returned",
                 duplicates);
    }

    /* And free the space used by the bigchunkptrs */

    for (i = 0; i < localcount; i++) {
        CC_FREE (tosslist[i], void);
    }
    CC_FREE (tosslist, void *);

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static CCbigchunkptr *bigchunkptralloc (void)
#else
static CCbigchunkptr *bigchunkptralloc ()
#endif
{
    CCbigchunkptr *bp;

    if (!bigchunkptr_freelist) {
        int count = CC_BIGCHUNK / sizeof(CCbigchunkptr);
        void *p;

        /* Grab a new bigchunk of memory */

        p = (void *) CCutil_allocrus (CC_BIGCHUNK);
        if (!p)
            return (CCbigchunkptr *) NULL;

        /* Split it up into linked bigchunkptrs */

        bigchunkptr_freelist = (CCbigchunkptr *) p;
        for (bp = bigchunkptr_freelist + count -2;
             bp >= bigchunkptr_freelist; bp--) {
            bp->next = bp+1;
        }
        bigchunkptr_freelist[count - 1].next = (CCbigchunkptr *) NULL;
        bigchunkptrtotal += count;

        /* And attach the bigchunk to the local bigchunklist */

        bp = bigchunkptr_freelist;
        bigchunkptr_freelist = bp->next;
        bp->this = p;
        bp->next = local_bigchunk_list;
        local_bigchunk_list = bp;
    }
    bp = bigchunkptr_freelist;
    bigchunkptr_freelist = bp->next;
    return bp;
}

#ifdef CC_PROTOTYPE_ANSI
static void bigchunkptrfree (CCbigchunkptr *bp)
#else
static void bigchunkptrfree (bp)
CCbigchunkptr *bp;
#endif
{
    bp->next = bigchunkptr_freelist;
    bigchunkptr_freelist = bp;
}
