/***************************************************************************/
/*                                                                         */
/*                  GENERIC HASH TABLE ROUTINES                            */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: November 12, 1996                                                */
/*                                                                         */
/*  These routines use a hash table to implement a generic associative     */
/*  array.                                                                 */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    int CCutil_genhash_init (CCgenhash *h, int size,                     */
/*            int (*hcmp) (void *key1, void *key2, void *u_data),          */
/*            unsigned int (*hfunc) (void *key, void *u_data),             */
/*            void *u_data, double maxdensity, double lowdensity)          */
/*      -CCgenhash *h (a pointer to a CCgenhash structure to be            */
/*       initialized)                                                      */
/*      -int size (the initial size of the hash table)                     */
/*      -int (*hcmp) (void *key1, void *key2, void *u_data) (a pointer to  */
/*       a function which returns 0 if key1 == key2, nonzero otherwise.    */
/*       u_data will be the u_data passed to CCgenhash_init)               */
/*      -unsigned int (*hfunc) (void *key, void *u_data) (a pointer to a   */
/*       function which computes a hash function of key.                   */
/*       u_data will be the u_data passed to CCgenhash_init)               */
/*      -void *u_data (a pointer which will be passed into hcmp and hfunc) */
/*      -double maxdensity (the maximum density (# elems / size) for the   */
/*       hash table.  When this density is reached the hash table is       */
/*       expanded.  0.0 means never expand the hash table)                 */
/*      -double lowdensity (the density of a hash table immediately after  */
/*       expansion)                                                        */
/*     RETURNS 0 for success, -1 if out of memory.                         */
/*                                                                         */
/*    void CCutil_genhash_free (CCgenhash *h, void (*freefunc)(void *k,    */
/*            void *d, void *u_data)                                       */
/*      -CCgenhash *h (a pointer to the hash table)                        */
/*      -void (*freefunc)(void *key, void *data, void *u_data) (a pointer  */
/*       to a function to be called for each (key, data) pair in the       */
/*       hashtable, or NULL)                                               */
/*     ACTION: deletes all entries in h, and frees the space for h.        */
/*                                                                         */
/*    void CCutil_genhash_u_data (CCgenhash *h, void *u_data),             */
/*      -CCgenhash *h (a pointer to the hash table)                        */
/*      -void *u_data (a new value for u_data)                             */
/*     ACTION: changes the u_data stored with the hash table, and          */
/*      passed to hcomp and hfunc)                                         */
/*                                                                         */
/*    int CCutil_genhash_insert (CCgenhash *h, void *key, void *data)      */
/*      -CCgenhash *h (a pointer to the hash table)                        */
/*      -void *key (a pointer to the key data for this entry)              */
/*      -void *data (the data to be stored)                                */
/*     ACTION: h[key] = data                                               */
/*     COMMENT: if h[key] already has a value, this acts like a stack      */
/*      CCutil_genhash_delete (key) will reveal the old value.             */
/*     RETURNS 0 for success, -1 if out of memory.                         */
/*                                                                         */
/*    int CCutil_genhash_replace (CCgenhash *h, void *key, void *data)     */
/*      -CCgenhash *h (a pointer to the hash table)                        */
/*      -void *key (a pointer to the key data for this entry)              */
/*      -void *data (the data to be stored)                                */
/*     ACTION: h[key] = data                                               */
/*     COMMENT: if h[key] already has a value, this replaces that          */
/*      value.                                                             */
/*     RETURNS 0 for success, -1 if out of memory.                         */
/*                                                                         */
/*    int CCutil_genhash_delete (CCgenhash *h, void *key)                  */
/*      -CCgenhash *h (a pointer to the hash table)                        */
/*      -void *key (a pointer to the key data for this entry)              */
/*     ACTION: h[key] = NULL                                               */
/*     RETURNS 0 for success, -1 if h[key] was already NULL                */
/*                                                                         */
/*    void *CCutil_genhash_lookup (CCgenhash *h, void *key)                */
/*      -CCgenhash *h (a pointer to the hash table)                        */
/*      -void *key (a pointer to the key data for this entry)              */
/*     RETURNS h[key], or NULL if h[key] not defined                       */
/*                                                                         */
/*    unsigned int CCutil_genhash_hash (CCgenhash *h, void *key)           */
/*      -CCgenhash *h (a pointer to the hash table)                        */
/*      -void *key (a pointer to key data)                                 */
/*     RETURNS the hash function of key (ie, h->hfunc(key))                */
/*                                                                         */
/*    int CCutil_genhash_insert_h (CCgenhash *h, unsigned int hashval,     */
/*            void *key, void *data)                                       */
/*    int CCutil_genhash_replace_h (CCgenhash *h, unsigned int hashval,    */
/*            void *key, void *data)                                       */
/*    int CCutil_genhash_delete_h (CCgenhash *h, unsigned int hashval,     */
/*            void *key)                                                   */
/*    int CCutil_genhash_lookup_h (CCgenhash *h, unsigned int hashval,     */
/*            void *key)                                                   */
/*     NOTE: These are alternate versions of the same functions without    */
/*      the _h suffix, and take an additional argument, hashval, which     */
/*      should be equal to CCutil_genhash_hash (key).  They provide a      */
/*      method to avoid recomputing CCgenhash_hash over multiple calls     */
/*      with the same key.                                                 */
/*                                                                         */
/*    void CCutil_genhash_start (CCgenhash *h, CCgenhash_iter *iter)       */
/*     -CCgenhash *h (a pointer to the hash table)                         */
/*     -CCgenhash_iter *iter (a pointer to the iterator to be              */
/*       initialized)                                                      */
/*      ACTION: initializes iter for iterating over elements of h using    */
/*       CCutil_genhash_next ().                                           */
/*                                                                         */
/*    void *CCutil_genhash_next (CCgenhash *h, CCgenhash_iter *iter,       */
/*            void **key, int *keysize)                                    */
/*     -CCgenhash *h (a pointer to the hash table)                         */
/*     -CCgenhash_iter *iter (a pointer to an iterator)                    */
/*     -void **key (a pointer to a location for the key value)             */
/*     -int *keysize (a pointer to a location for the key size)            */
/*     RETURNS: a next data value from the hash table (corresponding       */
/*      to the returned key and keysize), or NULL if there                 */
/*      are no more elements.                                              */
/*     NOTE: CCgenhash_next can tolerate the deletion of the current       */
/*      (last returned) element and arbitrary lookups and replaces         */
/*      between calls to CCgenhash_next.  However, deletion of             */
/*      elements other than the current one are not permitted, and         */
/*      insertion a table which could be expanded can result in            */
/*      elements being skipped.                                            */
/*                                                                         */
/*    NOTES:                                                               */
/*       Functions prototyped in genhash.h.                                */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"

typedef struct CCgenhash_elem {
    void *key;
    void *data;
    struct CCgenhash_elem *next;
} CCgenhash_elem;

CC_PTR_ALLOC_ROUTINE (CCgenhash_elem, CCgenhash_elemalloc,
                      CCgenhash_elemchunklist, CCgenhash_elemfreelist)
CC_PTR_FREE_ROUTINE (CCgenhash_elem, CCgenhash_elemfree,
                     CCgenhash_elemfreelist)
CC_PTR_FREE_WORLD_ROUTINE (CCgenhash_elem, CCgenhash_elemfree_world,
                           CCgenhash_elemchunklist, CCgenhash_elemfreelist)
CC_PTR_LEAKS_ROUTINE (CCgenhash_elem, CCgenhash_elem_check_leaks,
                      CCgenhash_elemchunklist, CCgenhash_elemfreelist,
                      data, void *)
CC_PTR_STATUS_ROUTINE (CCgenhash_elem, CCgenhash_elem_status,
                       CCgenhash_elemchunklist, CCgenhash_elemfreelist)

#ifdef CC_PROTOTYPE_ANSI

static int
    genhash_resize (CCgenhash *h);

#else

static int
    genhash_resize ();

#endif

#ifdef CC_PROTOTYPE_ANSI
int CCutil_genhash_init (CCgenhash *h, int size,
                  int (*hcmp) (void *key1, void *key2, void *u_data),
                  unsigned int (*hfunc) (void *key, void *u_data),
                  void *u_data, double maxdensity, double lowdensity)
#else
int CCutil_genhash_init (h, size, hcmp, hfunc, u_data, maxdensity, lowdensity)
CCgenhash *h;
int size;
int (*hcmp)();
unsigned int (*hfunc)();
void *u_data;
double maxdensity;
double lowdensity;
#endif
{
    int i;

    h->nelem = 0;
    h->size = CCutil_nextprime ((unsigned int) size);
    h->hcmp = hcmp;
    h->hfunc = hfunc;
    h->u_data = u_data;
    h->maxdensity = maxdensity;
    h->lowdensity = lowdensity;

    if (maxdensity <= 0.0) {
        h->maxelem = 0;
    } else {
        h->maxelem = (int) (h->maxdensity * h->size);
    }

    h->table = CC_SAFE_MALLOC (h->size, CCgenhash_elem *);
    if (!h->table) {
        return -1;
    }
    for (i=0; i<h->size; i++) {
        h->table[i] = (CCgenhash_elem *) NULL;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_genhash_insert (CCgenhash *h, void *key, void *data)
#else
int CCutil_genhash_insert (h, key, data)
CCgenhash *h;
void *key;
void *data;
#endif
{
    return CCutil_genhash_insert_h (h, h->hfunc(key, h->u_data), key, data);
}

#ifdef CC_PROTOTYPE_ANSI
void CCutil_genhash_u_data (CCgenhash *h, void *u_data)
#else
void CCutil_genhash_u_data (h, u_data)
CCgenhash *h;
void *u_data;
#endif
{
    h->u_data = u_data;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_genhash_insert_h (CCgenhash *h, unsigned int hashval, void *key,
            void *data)
#else
int CCutil_genhash_insert_h (h, hashval, key, data)
CCgenhash *h;
unsigned int hashval;
void *key;
void *data;
#endif
{
    int loc;
    CCgenhash_elem *e;

    if (h->maxelem && h->nelem >= h->maxelem) {
        if (genhash_resize (h)) {
            return -1;
        }
    }

    loc = hashval % h->size;
    e = CCgenhash_elemalloc();
    if (!e) return -1;

    e->key = key;
    e->data = data;
    e->next = h->table[loc];
    h->table[loc] = e;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_genhash_replace (CCgenhash *h, void *key, void *data)
#else
int CCutil_genhash_replace (h, key, data)
CCgenhash *h;
void *key;
void *data;
#endif
{
    return CCutil_genhash_replace_h (h, h->hfunc (key, h->u_data), key, data);
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_genhash_replace_h (CCgenhash *h, unsigned int hashval, void *key,
            void *data)
#else
int CCutil_genhash_replace_h (h, hashval, key, data)
CCgenhash *h;
unsigned int hashval;
void *key;
void *data;
#endif
{
    CCgenhash_elem *e;

    for (e = h->table[hashval % h->size]; e; e = e->next) {
        if (h->hcmp(e->key, key, h->u_data) == 0) {
            e->data = data;
            return 0;
        }
    }
    return CCutil_genhash_insert_h (h, hashval, key, data);
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_genhash_delete (CCgenhash *h, void *key)
#else
int CCutil_genhash_delete (h, key)
CCgenhash *h;
void *key;
#endif
{
    return CCutil_genhash_delete_h (h, h->hfunc(key, h->u_data), key);
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_genhash_delete_h (CCgenhash *h, unsigned int hashval, void *key)
#else
int CCutil_genhash_delete_h (h, hashval, key)
CCgenhash *h;
unsigned int hashval;
void *key;
#endif
{
    int loc = hashval % h->size;
    CCgenhash_elem *e, **eprev;

    for (e = h->table[loc], eprev = &h->table[loc]; e;
         eprev = &e->next, e = e->next) {
        if (h->hcmp(e->key, key, h->u_data) == 0) {
            *eprev = e->next;
            CCgenhash_elemfree (e);
            return 0;
        }
    }
    return -1;
}

#ifdef CC_PROTOTYPE_ANSI
unsigned int CCutil_genhash_hash (CCgenhash *h, void *key)
#else
unsigned int CCutil_genhash_hash (h, key)
CCgenhash *h;
void *key;
#endif
{
    return h->hfunc (key, h->u_data);
}

#ifdef CC_PROTOTYPE_ANSI
void *CCutil_genhash_lookup (CCgenhash *h, void *key)
#else
void *CCutil_genhash_lookup (h, key)
CCgenhash *h;
void *key;
#endif
{
    return CCutil_genhash_lookup_h (h, h->hfunc(key, h->u_data), key);
}

#ifdef CC_PROTOTYPE_ANSI
void *CCutil_genhash_lookup_h (CCgenhash *h, unsigned int hashval, void *key)
#else
void *CCutil_genhash_lookup_h (h, hashval, key)
CCgenhash *h;
unsigned int hashval;
void *key;
#endif
{
    CCgenhash_elem *e;

    for (e = h->table[hashval % h->size]; e; e = e->next) {
        if (h->hcmp(e->key, key, h->u_data) == 0) {
            return e->data;
        }
    }
    return (void *) NULL;
}

#ifdef CC_PROTOTYPE_ANSI
void CCutil_genhash_free (CCgenhash *h, void (*freefunc)(void *key, void *data,
             void *u_data))
#else
void CCutil_genhash_free (h, freefunc)
CCgenhash *h;
void (*freefunc)();
#endif
{
    int i;
    CCgenhash_elem *e, *enext;
    int total, onlist;

    for (i=0; i<h->size; i++) {
        for (e = h->table[i]; e; e = enext) {
            enext = e->next;
            if (freefunc) {
                (*freefunc)(e->key, e->data, h->u_data);
            }
            CCgenhash_elemfree (e);
        }
    }
    if (!CCgenhash_elem_status (&total, &onlist)) {
        CCgenhash_elemfree_world();
    }
    CC_FREE (h->table, CCgenhash_elem *);
}

#ifdef CC_PROTOTYPE_ANSI
static int genhash_resize (CCgenhash *h)
#else
static int genhash_resize (h)
CCgenhash *h;
#endif
{
    int newsize = CCutil_nextprime ((unsigned int) (h->nelem / h->lowdensity));
    CCgenhash_elem **newtable;
    CCgenhash_elem *e, *enext;
    int loc;
    int i;

    if (newsize <= h->nelem)
        newsize = CCutil_nextprime ((unsigned int) h->nelem + 1);

    newtable = CC_SAFE_MALLOC (newsize, CCgenhash_elem *);
    if (!newtable) {
        return -1;
    }

    for (i=0; i<newsize; i++) {
        newtable[i] = (CCgenhash_elem *) NULL;
    }

    for (i=0; i<h->size; i++) {
        for (e = h->table[i]; e; e = enext) {
            enext = e;
            loc = h->hfunc(e->key, h->u_data) % newsize;
            e->next = newtable[loc];
            newtable[loc] = e;
        }
    }

    CC_FREE (h->table, CCgenhash_elem *);

    h->table = newtable;
    h->size = newsize;
    h->maxelem = (int) (h->maxdensity * h->size);

    return 0;
}
