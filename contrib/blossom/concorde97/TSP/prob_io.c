/**************************************************************************/
/*                                                                        */
/* Date: April 19, 1996  (dave)                                           */
/*       August 28, 1996 (bico)                                           */
/*                                                                        */
/* EXPORTED FUNCTIONS:                                                    */
/*                                                                        */
/* CCtsp_PROB_FILE                                                        */
/*     *CCtsp_prob_read (char *f, int n),                                 */
/*     *CCtsp_prob_read_name (char *f),                                   */
/*     *CCtsp_prob_write (char *f, int n);                                */
/*     *CCtsp_prob_write_name (char *fname, char *pname);                 */
/*                                                                        */
/* int                                                                    */
/*     CCtsp_prob_file_delete (char *f, int n),                           */
/*     CCtsp_prob_getname (CCtsp_PROB_FILE *p, char *name),               */
/*     CCtsp_prob_getid (CCtsp_PROB_FILE *p, int *id),                    */
/*     CCtsp_prob_getparent (CCtsp_PROB_FILE *p, int *parent),            */
/*     CCtsp_prob_getub (CCtsp_PROB_FILE *p, double *ub),                 */
/*     CCtsp_prob_getlb (CCtsp_PROB_FILE *p, double *lb),                 */
/*     CCtsp_prob_getexactlb (CCtsp_PROB_FILE *p, CCbigguy *lb),          */
/*     CCtsp_prob_getnnodes (CCtsp_PROB_FILE *p, int *nnodes),            */
/*     CCtsp_prob_getchildren (CCtsp_PROB_FILE *p, int *child0,           */
/*             int *child1),                                              */
/*     CCtsp_prob_getreal (CCtsp_PROB_FILE *p, int *real),                */
/*     CCtsp_prob_getprocessed (CCtsp_PROB_FILE *p, int *processed),      */
/*     CCtsp_prob_getinfeasible (CCtsp_PROB_FILE *p, int *infeasible),    */
/*     CCtsp_prob_gettour (CCtsp_PROB_FILE *p, int **tour),               */
/*     CCtsp_prob_getedges (CCtsp_PROB_FILE *p, int *nedges, int **elist, */
/*             int **elen),                                               */
/*     CCtsp_prob_getcuts (CCtsp_PROB_FILE *p, CCtsp_lp *lp);             */
/*     CCtsp_prob_getbasis (CCtsp_PROB_FILE *p, int *ccount, int *rcount, */
/*             int **cstat, int **rstat),                                 */
/*     CCtsp_prob_getnorms (CCtsp_PROB_FILE *p, int *rcount,              */
/*             double **dnorm),                                           */
/*     CCtsp_prob_getexactdual (CCtsp_PROB_FILE *p, ncount,               */
/*             CCtsp_bigdual **d)                                         */
/*     CCtsp_prob_gethistory (CCtsp_PROB_FILE *p, int *depth,             */
/*             CCtsp_branchobj **history)                                 */
/*     CCtsp_prob_rclose (CCtsp_PROB_FILE *p),                            */
/*                                                                        */
/*     CCtsp_prob_putname (CCtsp_PROB_FILE *p, char *name),               */
/*     CCtsp_prob_putid (CCtsp_PROB_FILE *p, int id),                     */
/*     CCtsp_prob_putparent (CCtsp_PROB_FILE *p, int parent),             */
/*     CCtsp_prob_putub (CCtsp_PROB_FILE *p, double ub),                  */
/*     CCtsp_prob_putlb (CCtsp_PROB_FILE *p, double lb),                  */
/*     CCtsp_prob_putexactlb (CCtsp_PROB_FILE *p, CCbigguy lb),           */
/*     CCtsp_prob_putnnodes (CCtsp_PROB_FILE *p, int nnodes),             */
/*     CCtsp_prob_putchildren (CCtsp_PROB_FILE *p, int child0,            */
/*             int child1),                                               */
/*     CCtsp_prob_putreal (CCtsp_PROB_FILE *p, int real),                 */
/*     CCtsp_prob_putprocessed (CCtsp_PROB_FILE *p, int processed),       */
/*     CCtsp_prob_putinfeasible (CCtsp_PROB_FILE *p, int infeasible),     */
/*     CCtsp_prob_puttour (CCtsp_PROB_FILE *p, int *tour),                */
/*     CCtsp_prob_putedges (CCtsp_PROB_FILE *p, int ecount, int *elist,   */
/*             int *elen);                                                */
/*     CCtsp_prob_putcuts (CCtsp_PROB_FILE *p, CCtsp_lp *lp);             */
/*     CCtsp_prob_putbasis (CCtsp_PROB_FILE *p, int ccount, int rcount,   */
/*             int *cstat, int *rstat),                                   */
/*     CCtsp_prob_putnorms (CCtsp_PROB_FILE *p, int rcount, double *dnorm)*/
/*     CCtsp_prob_putexact_dual (CCtsp_PROB_FILE *p,                      */
/*             CCtsp_bigdual *exact_dual)                                 */
/*     CCtsp_prob_puthistory (CCtsp_PROB_FILE *p, int depth,              */
/*             CCtsp_branchobj *history)                                  */
/*     CCtsp_prob_wclose (CCtsp_PROB_FILE *p),                            */
/*                                                                        */
/**************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "tsp.h"
#include "bigguy.h"

#ifdef CC_PROTOTYPE_ANSI

static int
    prob_name (char *buf, int buflen, char *f, int n),
    write_header (CCtsp_PROB_FILE *p);

static void
    prob_init (CCtsp_PROB_FILE *p);

#else

static int
    prob_name (),
    write_header ();

static void
    prob_init ();

#endif


#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_file_delete (char *f, int n)
#else
int CCtsp_prob_file_delete (f, n)
char *f;
int n;
#endif
{
    char nambuf[1024];
    int sval;

    if (prob_name (nambuf, sizeof (nambuf), f, n)) return 1;
    printf ("Delete file: %s\n", nambuf);
    fflush (stdout);
    sval = CCutil_sdelete_file (nambuf);
    if (sval) {
        printf ("Prob file %s could not be deleted\n", nambuf);
        fflush (stdout);
    }
    sval = CCutil_sdelete_file_backup (nambuf);
    if (!sval) {
        printf ("Deleted backup to file: %s\n", nambuf);
        fflush (stdout);
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
CCtsp_PROB_FILE *CCtsp_prob_read (char *f, int n)
#else
CCtsp_PROB_FILE *CCtsp_prob_read (f, n)
char *f;
int n;
#endif
{
    char nambuf[1024];

    if (prob_name (nambuf, sizeof (nambuf), f, n))
        return (CCtsp_PROB_FILE *) NULL;

    return CCtsp_prob_read_name (nambuf);
}

#ifdef CC_PROTOTYPE_ANSI
CCtsp_PROB_FILE *CCtsp_prob_read_name (char *f)
#else
CCtsp_PROB_FILE *CCtsp_prob_read_name (f)
char *f;
#endif
{
    CCtsp_PROB_FILE *p = (CCtsp_PROB_FILE *) NULL;
    unsigned char version;
    int i;

    printf ("Read File %s\n", f); fflush (stdout);

    p = CC_SAFE_MALLOC (1, CCtsp_PROB_FILE);
    if (p == (CCtsp_PROB_FILE *) NULL) goto CLEANUP;
    prob_init (p);

    p->f = CCutil_sopen (f, "r");
    if (!p->f) goto CLEANUP;

    if (CCutil_sread_char (p->f, &version)) goto CLEANUP;
    for (i = 0; i < CCtsp_PROB_FILE_NAME_LEN; i++)
        if (CCutil_sread_char (p->f, (unsigned char *) &p->name[i]))
            goto CLEANUP;

    switch (version) {
      case 1:
        if (CCutil_sread_int (p->f, (unsigned int *) &p->parent))
            goto CLEANUP;
        if (CCutil_sread_int (p->f, (unsigned int *) &p->id))
            goto CLEANUP;
        if (CCutil_sread_double (p->f, &p->ub))
            goto CLEANUP;
        if (CCutil_sread_double (p->f, &p->lb))
            goto CLEANUP;
        if (CCbigguy_sread (p->f, &p->exactlb))
            goto CLEANUP;
        if (CCutil_sread_int (p->f, (unsigned int *) &p->nnodes))
            goto CLEANUP;
        if (CCutil_sread_int (p->f, (unsigned int *) &p->child0))
            goto CLEANUP;
        if (CCutil_sread_int (p->f, (unsigned int *) &p->child1))
            goto CLEANUP;
        if (CCutil_sread_int (p->f, (unsigned int *) &p->real))
            goto CLEANUP;
        if (CCutil_sread_int (p->f, (unsigned int *) &p->processed))
            goto CLEANUP;
        if (CCutil_sread_int (p->f, (unsigned int *) &p->infeasible))
            goto CLEANUP;
        if (CCutil_sread_int (p->f, (unsigned int *) &p->offsets.dat))
            goto CLEANUP;
        if (CCutil_sread_int (p->f, (unsigned int *) &p->offsets.edge))
            goto CLEANUP;
        if (CCutil_sread_int (p->f, (unsigned int *) &p->offsets.fulladj))
            goto CLEANUP;
        if (CCutil_sread_int (p->f, (unsigned int *) &p->offsets.cut))
            goto CLEANUP;
        if (CCutil_sread_int (p->f, (unsigned int *) &p->offsets.tour))
            goto CLEANUP;
        if (CCutil_sread_int (p->f, (unsigned int *) &p->offsets.basis))
            goto CLEANUP;
        if (CCutil_sread_int (p->f, (unsigned int *) &p->offsets.norms))
            goto CLEANUP;
        if (CCutil_sread_int (p->f, (unsigned int *) &p->offsets.fix))
            goto CLEANUP;
        if (CCutil_sread_int (p->f, (unsigned int *) &p->offsets.exactdual))
            goto CLEANUP;
        if (CCutil_sread_int (p->f, (unsigned int *) &p->offsets.history))
            goto CLEANUP;
        break;
      default:
        fprintf (stderr, "Unknown problem version %ud\n", version);
        goto CLEANUP;
    }
    return p;

  CLEANUP:
    if (p) {
        if (p->f) {
            CCutil_sclose (p->f);
        }
        CC_FREE (p, CCtsp_PROB_FILE);
    }
    return (CCtsp_PROB_FILE *) NULL;
}


#ifdef CC_PROTOTYPE_ANSI
CCtsp_PROB_FILE *CCtsp_prob_write (char *f, int n)
#else
CCtsp_PROB_FILE *CCtsp_prob_write (f, n)
char *f;
int n;
#endif
{
    char nambuf[1024];

    if (prob_name (nambuf, sizeof (nambuf), f, n))
        return (CCtsp_PROB_FILE *) NULL;

    return CCtsp_prob_write_name (nambuf, f);
}

#ifdef CC_PROTOTYPE_ANSI
CCtsp_PROB_FILE *CCtsp_prob_write_name (char *fname, char *pname)
#else
CCtsp_PROB_FILE *CCtsp_prob_write_name (fname, pname)
char *fname, *pname;
#endif
{
    CCtsp_PROB_FILE *p = (CCtsp_PROB_FILE *) NULL;
    int i;

    printf ("Write File %s\n", fname); fflush (stdout);

    p = CC_SAFE_MALLOC (1, CCtsp_PROB_FILE);
    if (p == (CCtsp_PROB_FILE *) NULL) goto CLEANUP;
    prob_init (p);
    for (i = 0; pname[i] && i < CCtsp_PROB_FILE_NAME_LEN - 1; i++)
        p->name[i] = pname[i];
    p->name[i] = '\0';

    p->f = CCutil_sopen (fname, "w");
    if (!p->f) goto CLEANUP;

    if (write_header (p)) {
        printf ("write_header failed\n");
        goto CLEANUP;
    }

    return p;

CLEANUP:
    if (p) {
        if (p->f) {
            CCutil_sclose (p->f);
        }
        CC_FREE (p, CCtsp_PROB_FILE);
    }
    return (CCtsp_PROB_FILE *) NULL;
}

#ifdef CC_PROTOTYPE_ANSI
static int write_header (CCtsp_PROB_FILE *p)
#else
static int write_header (p)
CCtsp_PROB_FILE *p;
#endif
{
    int  i;

    if (CCutil_srewind (p->f)) return 1;
    if (CCutil_swrite_char (p->f, (unsigned char) CCtsp_PROB_IO_VERSION)) return 1;
    for (i = 0; i < CCtsp_PROB_FILE_NAME_LEN; i++) {
        if (CCutil_swrite_char (p->f, (unsigned char) p->name[i])) return 1;
    }
    if (CCutil_swrite_int (p->f, (unsigned int) p->parent)) return 1;
    if (CCutil_swrite_int (p->f, (unsigned int) p->id)) return 1;
    if (CCutil_swrite_double (p->f, p->ub)) return 1;
    if (CCutil_swrite_double (p->f, p->lb)) return 1;
    if (CCbigguy_swrite (p->f, p->exactlb)) return 1;
    if (CCutil_swrite_int (p->f, (unsigned int) p->nnodes)) return 1;
    if (CCutil_swrite_int (p->f, (unsigned int) p->child0)) return 1;
    if (CCutil_swrite_int (p->f, (unsigned int) p->child1)) return 1;
    if (CCutil_swrite_int (p->f, (unsigned int) p->real)) return 1;
    if (CCutil_swrite_int (p->f, (unsigned int) p->processed)) return 1;
    if (CCutil_swrite_int (p->f, (unsigned int) p->infeasible)) return 1;
    if (CCutil_swrite_int (p->f, (unsigned int) p->offsets.dat)) return 1;
    if (CCutil_swrite_int (p->f, (unsigned int) p->offsets.edge)) return 1;
    if (CCutil_swrite_int (p->f, (unsigned int) p->offsets.fulladj)) return 1;
    if (CCutil_swrite_int (p->f, (unsigned int) p->offsets.cut)) return 1;
    if (CCutil_swrite_int (p->f, (unsigned int) p->offsets.tour)) return 1;
    if (CCutil_swrite_int (p->f, (unsigned int) p->offsets.basis)) return 1;
    if (CCutil_swrite_int (p->f, (unsigned int) p->offsets.norms)) return 1;
    if (CCutil_swrite_int (p->f, (unsigned int) p->offsets.fix)) return 1;
    if (CCutil_swrite_int (p->f, (unsigned int) p->offsets.exactdual)) return 1;
    if (CCutil_swrite_int (p->f, (unsigned int) p->offsets.history)) return 1;

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int prob_name (char *buf, int buflen, char *f, int n)
#else
static int prob_name (buf, buflen, f, n)
char *buf;
int buflen;
char *f;
int n;
#endif
{
    int l = strlen(f);
    int lastslash;
    int i;
    int d;

    if (l + 5 > buflen || n >= 1000 + 26*36*36 || n < 0) {
        fprintf (stderr, "Cannot generate filename for %s node %d\n",
                 f, n);
        return -1;
    }

    for (i = 0, lastslash = -1; i < l; i++) {
        if (f[i] == '/') lastslash = i;
        buf[i] = f[i];
    }
    if (l > lastslash + 9) l = lastslash + 9;
    for (i = lastslash+1; i < l; i++) {
        if (buf[i] == '.') buf[i] = '_';
    }
    buf[l++] = '.';
    if (n < 1000) {
        d = n/100;
        buf[l++] = '0' + ((unsigned char) d);
        n -= d*100;
        d = n/10;
        buf[l++] = '0' + ((unsigned char) d);
        n -= d*10;
        d = n;
        buf[l++] = '0' + ((unsigned char) d);
    } else {
        n -= 1000;
        d = n/1296;
        buf[l++] = 'a' + ((unsigned char) d);
        n -= d*1296;
        d = n/36;
        buf[l++] = (d < 10) ? '0'+((unsigned char) d)
                            : 'a'+((unsigned char) (d-10));
        n -= d*36;
        d = n;
        buf[l++] = (d < 10) ? '0'+((unsigned char) d)
                            : 'a'+((unsigned char) (d-10));
    }
    buf[l] = '\0';
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void prob_init (CCtsp_PROB_FILE *p)
#else
static void prob_init (p)
CCtsp_PROB_FILE *p;
#endif
{
    int i;

    p->f = (CC_SFILE *) NULL;
    for (i = 0; i < CCtsp_PROB_FILE_NAME_LEN; i++)
        p->name[i] = '\0';
    p->id = -1;
    p->parent = -1;
    p->lb = -1.0;
    p->ub = -1.0;
    p->exactlb = CCbigguy_ZERO;
    p->nnodes = -1;
    p->child0 = -1;
    p->child1 = -1;
    p->real = -1;
    p->processed = -1;
    p->infeasible = -1;
    p->offsets.dat = -1;
    p->offsets.edge = -1;
    p->offsets.fulladj = -1;
    p->offsets.cut = -1;
    p->offsets.tour = -1;
    p->offsets.basis = -1;
    p->offsets.norms = -1;
    p->offsets.fix = -1;
    p->offsets.exactdual = -1;
    p->offsets.history = -1;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_rclose (CCtsp_PROB_FILE *p)
#else
int CCtsp_prob_rclose (p)
CCtsp_PROB_FILE *p;
#endif
{
    int rval;

    rval = CCutil_sclose (p->f);

    CC_FREE (p, CCtsp_PROB_FILE);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_wclose (CCtsp_PROB_FILE *p)
#else
int CCtsp_prob_wclose (p)
CCtsp_PROB_FILE *p;
#endif
{
    int rval;

    rval = write_header (p);
    if (rval) return rval;

    rval = CCutil_sclose (p->f);

    CC_FREE (p, CCtsp_PROB_FILE);

    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_getname (CCtsp_PROB_FILE *p, char *name)
#else
int CCtsp_prob_getname (p, name)
CCtsp_PROB_FILE *p;
char *name;
#endif
{
    int i;

    if (!p) return -1;

    for (i = 0; i < CCtsp_PROB_FILE_NAME_LEN; i++)
        name[i] = p->name[i];

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_putname (CCtsp_PROB_FILE *p, char *name)
#else
int CCtsp_prob_putname (p, name)
CCtsp_PROB_FILE *p;
char *name;
#endif
{
    int i;

    if (!p) return 1;

    for (i = 0; name[i] && i < CCtsp_PROB_FILE_NAME_LEN - 1; i++)
        p->name[i] = name[i];
    for (; i < CCtsp_PROB_FILE_NAME_LEN; i++)
        p->name[i] = '\0';

    return 0;
}


#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_getid (CCtsp_PROB_FILE *p, int *id)
#else
int CCtsp_prob_getid (p, id)
CCtsp_PROB_FILE *p;
int *id;
#endif
{
    if (!p) return -1;

    *id = p->id;
    if (*id == -1) {
        printf ("Setting -1 ID to 0\n"); fflush (stdout);
        *id = 0;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_putid (CCtsp_PROB_FILE *p, int id)
#else
int CCtsp_prob_putid (p, id)
CCtsp_PROB_FILE *p;
int id;
#endif
{
    if (!p) return 1;

    p->id = id;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_getparent (CCtsp_PROB_FILE *p, int *parent)
#else
int CCtsp_prob_getparent (p, parent)
CCtsp_PROB_FILE *p;
int *parent;
#endif
{
    if (!p) return -1;

    *parent = p->parent;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_putparent (CCtsp_PROB_FILE *p, int parent)
#else
int CCtsp_prob_putparent (p, parent)
CCtsp_PROB_FILE *p;
int parent;
#endif
{
    if (!p) return 1;

    p->parent = parent;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_getub (CCtsp_PROB_FILE *p, double *ub)
#else
int CCtsp_prob_getub (p, ub)
CCtsp_PROB_FILE *p;
double *ub;
#endif
{
    if (!p) return -1;

    *ub = p->ub;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_putub (CCtsp_PROB_FILE *p, double ub)
#else
int CCtsp_prob_putub (p, ub)
CCtsp_PROB_FILE *p;
double ub;
#endif
{
    if (!p) return 1;

    p->ub = ub;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_getlb (CCtsp_PROB_FILE *p, double *lb)
#else
int CCtsp_prob_getlb (p, lb)
CCtsp_PROB_FILE *p;
double *lb;
#endif
{
    if (!p) return -1;

    *lb = p->lb;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_putlb (CCtsp_PROB_FILE *p, double lb)
#else
int CCtsp_prob_putlb (p, lb)
CCtsp_PROB_FILE *p;
double lb;
#endif
{
    if (!p) return 1;

    p->lb = lb;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_getexactlb (CCtsp_PROB_FILE *p, CCbigguy *lb)
#else
int CCtsp_prob_getexactlb (p, lb)
CCtsp_PROB_FILE *p;
CCbigguy *lb;
#endif
{
    if (!p) return -1;

    *lb = p->exactlb;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_putexactlb (CCtsp_PROB_FILE *p, CCbigguy lb)
#else
int CCtsp_prob_putexactlb (p, lb)
CCtsp_PROB_FILE *p;
CCbigguy lb;
#endif
{
    if (!p) return 1;

    p->exactlb = lb;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_getnnodes (CCtsp_PROB_FILE *p, int *nnodes)
#else
int CCtsp_prob_getnnodes (p, nnodes)
CCtsp_PROB_FILE *p;
int *nnodes;
#endif
{
    if (!p) return -1;

    *nnodes = p->nnodes;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_putnnodes (CCtsp_PROB_FILE *p, int nnodes)
#else
int CCtsp_prob_putnnodes (p, nnodes)
CCtsp_PROB_FILE *p;
int nnodes;
#endif
{
    if (!p) return 1;

    p->nnodes = nnodes;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_getchildren (CCtsp_PROB_FILE *p, int *child0, int *child1)
#else
int CCtsp_prob_getchildren (p, child0, child1)
CCtsp_PROB_FILE *p;
int *child0, *child1;
#endif
{
    if (!p) return -1;

    *child0 = p->child0;
    *child1 = p->child1;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_putchildren (CCtsp_PROB_FILE *p, int child0, int child1)
#else
int CCtsp_prob_putchildren (p, child0, child1)
CCtsp_PROB_FILE *p;
int child0, child1;
#endif
{
    if (!p) return 1;

    p->child0 = child0;
    p->child1 = child1;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_getreal (CCtsp_PROB_FILE *p, int *real)
#else
int CCtsp_prob_getreal (p, real)
CCtsp_PROB_FILE *p;
int *real;
#endif
{
    if (!p) return -1;

    *real = p->real;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_putreal (CCtsp_PROB_FILE *p, int real)
#else
int CCtsp_prob_putreal (p, real)
CCtsp_PROB_FILE *p;
int real;
#endif
{
    if (!p) return 1;

    p->real = real;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_getprocessed (CCtsp_PROB_FILE *p, int *processed)
#else
int CCtsp_prob_getprocessed (p, processed)
CCtsp_PROB_FILE *p;
int *processed;
#endif
{
    if (!p) return -1;

    *processed = p->processed;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_putprocessed (CCtsp_PROB_FILE *p, int processed)
#else
int CCtsp_prob_putprocessed (p, processed)
CCtsp_PROB_FILE *p;
int processed;
#endif
{
    if (!p) return 1;

    p->processed = processed;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_getinfeasible (CCtsp_PROB_FILE *p, int *infeasible)
#else
int CCtsp_prob_getinfeasible (p, infeasible)
CCtsp_PROB_FILE *p;
int *infeasible;
#endif
{
    if (!p) return -1;

    *infeasible = p->infeasible;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_putinfeasible (CCtsp_PROB_FILE *p, int infeasible)
#else
int CCtsp_prob_putinfeasible (p, infeasible)
CCtsp_PROB_FILE *p;
int infeasible;
#endif
{
    if (!p) return 1;

    p->infeasible = infeasible;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_puttour (CCtsp_PROB_FILE *p, int *tour)
#else
int CCtsp_prob_puttour (p, tour)
CCtsp_PROB_FILE *p;
int *tour;
#endif
{
    int i;
    int ncount;

    if (!p) return 1;

    ncount = p->nnodes;
    if (ncount <= 0) {
        printf ("nnodes not set in CCtsp_prob_puttour\n");
        return 1;
    }
    p->offsets.tour = CCutil_stell (p->f);
    for (i = 0; i < ncount; i++) {
        if (CCutil_swrite_int (p->f, (unsigned int) tour[i]))
            return 1;
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_gettour (CCtsp_PROB_FILE *p, int **tour)
#else
int CCtsp_prob_gettour (p, tour)
CCtsp_PROB_FILE *p;
int **tour;
#endif
{
    int i;
    int ncount;

    if (!p) return -1;

    ncount = p->nnodes;
    if (ncount <= 0) {
        printf ("nnodes not set in CCtsp_prob_gettour\n");
        return 1;
    }
    if (p->offsets.tour == -1) {
        printf ("No tour in file.\n");
        return 1;
    }
    if (CCutil_sseek (p->f, p->offsets.tour)) {
        printf ("CCutil_sseek failed in CCtsp_prob_gettour\n");
        return -1;
    }

    *tour = CC_SAFE_MALLOC (ncount, int);
    if (!(*tour)) {
        fprintf (stderr, "out of memory in CCtsp_prob_gettour\n");
        return -1;
    }

    for (i = 0; i < ncount; i++) {
        if (CCutil_sread_int (p->f, (unsigned int *) &((*tour)[i]))) {
            CC_FREE (*tour, int);
            return -1;
        }
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_putedges (CCtsp_PROB_FILE *p, int ecount, int *elist, int *elen)
#else
int CCtsp_prob_putedges (p, ecount, elist, elen)
CCtsp_PROB_FILE *p;
int ecount;
int *elist, *elen;
#endif
{
    int i;

    if (!p) return 1;

    p->offsets.edge = CCutil_stell (p->f);
    if (CCutil_swrite_int (p->f, (unsigned int) ecount))
        return 1;
    for (i = 0; i < 2 * ecount; i++) {
        if (CCutil_swrite_int (p->f, (unsigned int) elist[i]))
            return 1;
    }
    for (i = 0; i < ecount; i++) {
        if (CCutil_swrite_int (p->f, (unsigned int) elen[i]))
            return 1;
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_getedges (CCtsp_PROB_FILE *p, int *ecount, int **elist, int **elen)
#else
int CCtsp_prob_getedges (p, ecount, elist, elen)
CCtsp_PROB_FILE *p;
int *ecount;
int **elist, **elen;
#endif
{
    int i;

    if (!p) return -1;

    if (p->offsets.edge == -1) {
        printf ("No edges in file.\n");
        return 1;
    }
    if (CCutil_sseek (p->f, p->offsets.edge)) {
        printf ("CCutil_sseek failed in CCtsp_prob_getedges\n");
        return -1;
    }
    if (CCutil_sread_int (p->f, (unsigned int *) ecount))
        return -1;

    *elist = CC_SAFE_MALLOC (2 * (*ecount), int);
    *elen = CC_SAFE_MALLOC (*ecount, int);
    if (!(*elist) || !(*elen)) {
        fprintf (stderr, "out of memory in CCtsp_prob_getedges\n");
        CC_IFFREE (*elist, int);
        CC_IFFREE (*elen, int);
        return -1;
    }

    for (i = 0; i < 2 * (*ecount); i++) {
        if (CCutil_sread_int (p->f, (unsigned int *) &((*elist)[i]))) {
            CC_FREE (*elist, int);
            CC_FREE (*elen, int);
            return -1;
        }
    }
    for (i = 0; i < *ecount; i++) {
        if (CCutil_sread_int (p->f, (unsigned int *) &((*elen)[i]))) {
            CC_FREE (*elist, int);
            CC_FREE (*elen, int);
            return -1;
        }
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_putcuts (CCtsp_PROB_FILE *p, CC_SFILE *s, CCtsp_lpcuts *cuts)
#else
int CCtsp_prob_putcuts (p, s, cuts)
CCtsp_PROB_FILE *p;
CC_SFILE *s;
CCtsp_lpcuts *cuts;
#endif
{
    int *marks = (int *) NULL;
    int cend = cuts->cliqueend;
    int i, j, k;
    CC_SFILE *f;

    if (!p && !s) return 1;

    if (p) {
        p->offsets.cut = CCutil_stell (p->f);
        f = p->f;
    } else {
        f = s;
    }

    if (CCutil_swrite_int (f, (unsigned int) CCtsp_PROB_IO_CUTS_VERSION))
        return 1;

    if (cend) {
        marks = CC_SAFE_MALLOC (cend, int);
        if (!marks) {
            fprintf (stderr, "out of memory in CCtsp_prob_putcut\n");
            return 1;
        }
        for (i = 0; i < cend; i++)
            marks[i] = 0;

        for (i = 0; i < cuts->cutcount; i++) {
            for (j = 0; j < cuts->cuts[i].cliquecount; j++) {
                marks[cuts->cuts[i].cliques[j]]++;
            }
        }
        for (i = 0, k = 1; i < cend; i++) {  /* Start a 1 to avoid 0 as an index */
            if (marks[i]) {
                if (marks[i] != cuts->cliques[i].refcount) {
                    fprintf (stderr, "SCREW UP in refcount for clique %d\n", i);
                }
                marks[i] = k++;
            }
        }

        for (i = 0; i < cend; i++) {
            if (marks[i]) {
                if (CCutil_swrite_int (f, (unsigned int) cuts->cliques[i].segcount))
                    return 1;
                for (j = 0; j < cuts->cliques[i].segcount; j++) {
                    if (CCutil_swrite_int (f,
                            (unsigned int) cuts->cliques[i].nodes[j].lo))
                        return 1;
                    if (CCutil_swrite_int (f,
                            (unsigned int) cuts->cliques[i].nodes[j].hi))
                        return 1;
                }
            }
        }
    }

    if (CCutil_swrite_int (f, (unsigned int) -1)) return 1;

    for (i = 0; i < cuts->cutcount; i++) {
        if (CCutil_swrite_int (f, (unsigned int) cuts->cuts[i].cliquecount))
            return 1;
        if (CCutil_swrite_int (f, (unsigned int) cuts->cuts[i].handlecount))
            return 1;
        if (CCutil_swrite_int (f, (unsigned int) cuts->cuts[i].rhs))
            return 1;
        if (CCutil_swrite_char (f, (unsigned char) cuts->cuts[i].sense))
            return 1;

        for (j = 0; j < cuts->cuts[i].cliquecount; j++) {
            if (CCutil_swrite_int (f,
              (unsigned int) marks[cuts->cuts[i].cliques[j]] - 1))
                return 1;
        }
        if (p) {
            if (CCutil_swrite_int (f, (unsigned int) cuts->cuts[i].modcount))
                return 1;
            for (j = 0; j < cuts->cuts[i].modcount; j++) {
                if (CCutil_swrite_int (f,(unsigned int) cuts->cuts[i].mods[j].node))
                    return 1;
                if (CCutil_swrite_int (f,(unsigned int) cuts->cuts[i].mods[j].mult))
                    return 1;
            }
        }
    }
    if (CCutil_swrite_int (f, (unsigned int) -1)) return 1;

    CC_IFFREE (marks, int);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_getcuts (CCtsp_PROB_FILE *p, CC_SFILE *s, CCtsp_lpcuts *cuts)
#else
int CCtsp_prob_getcuts (p, s, cuts)
CCtsp_PROB_FILE *p;
CC_SFILE *s;
CCtsp_lpcuts *cuts;
#endif
{
    int i, j, k, nseg, ncliq, nhand, rhs, cliq, nmod, hi, lo, n, mult;
    char sense;
    int cliqcount = 0, cutcount = 0;
    CCtsp_lpclique c;
    CCtsp_lpcut u;
    int *hits = (int *) NULL;
    int version = 0;
    CC_SFILE *f;


    if (!p && !s) return -1;

    if (p) {
        if (p->offsets.cut == -1) {
            printf ("No cuts in file.\n");
            return 1;
        }
        if (CCutil_sseek (p->f, p->offsets.cut)) {
            printf ("CCutil_sseek failed in CCtsp_prob_getedges\n");
            return -1;
        }
        f = p->f;
    } else {
        f = s;
    }

    if (CCutil_sread_int (f, (unsigned int *) &version))
        goto CLEANUP;

    if (version > CCtsp_PROB_IO_CUTS_VERSION_BASE) {
        /* an initial version of the cut system did not have a version # */
        printf ("Pre-sense version of files cuts\n"); fflush (stdout);
        nseg = version;
        version = 0;
    } else {
        if (CCutil_sread_int (f, (unsigned int *) &nseg)) goto CLEANUP;
    }

    while (nseg != -1) {
        c.segcount = nseg;
        if (nseg == 0) {
            fprintf (stderr, "ERROR: Clique with no segs in read_da_cuts\n");
            goto CLEANUP;
        }
        c.nodes = CC_SAFE_MALLOC (nseg, CCtsp_segment);
        if (!c.nodes) {
            fprintf (stderr, "out of memory in read_da_cuts\n");
            goto CLEANUP;
        }
        for (j = 0; j < nseg; j++) {
            if (CCutil_sread_int (f, (unsigned int *) &lo)) goto CLEANUP;
            if (CCutil_sread_int (f, (unsigned int *) &hi)) goto CLEANUP;
            c.nodes[j].lo = lo;
            c.nodes[j].hi = hi;
        }
        k = CCtsp_register_clique (cuts, &c);
        CC_FREE (c.nodes, CCtsp_segment);
        if (k == -1) {
            fprintf (stderr, "CCtsp_register_clique failed\n");
            goto CLEANUP;
        }
        if (k != cliqcount) {
            fprintf (stderr, "clique registration number is out of seq\n");
            cliqcount++;
            goto CLEANUP;
        }
        cliqcount++;
        if (CCutil_sread_int (f, (unsigned int *) &nseg)) goto CLEANUP;
    }


    if (cliqcount) {
        hits = CC_SAFE_MALLOC (cliqcount, int);
        if (!hits) {
            fprintf (stderr, "out of memory in read_da_cuts\n");
            goto CLEANUP;
        }
        for (i = 0; i < cliqcount; i++)
            hits[i] = 0;
    }

    if (CCutil_sread_int (f, (unsigned int *) &ncliq)) goto CLEANUP;
    while (ncliq != -1) {
        if (CCutil_sread_int (f, (unsigned int *) &nhand)) goto CLEANUP;
        if (CCutil_sread_int (f, (unsigned int *) &rhs)) goto CLEANUP;
        if (version <= CCtsp_PROB_IO_CUTS_VERSION_BASE) {
            if (CCutil_sread_char (f, (unsigned char *) &sense)) goto CLEANUP;
        } else {
            sense = 'G';
        }
        u.cliquecount = ncliq;
        u.handlecount = nhand;
        u.rhs = rhs;
        u.sense = sense;
        u.branch = 0;
        u.age = 0;
        u.cliques = CC_SAFE_MALLOC (ncliq, int);
        if (!u.cliques) {
            fprintf (stderr, "out of memory in read_da_cuts\n");
            goto CLEANUP;
        }
        for (j = 0; j < ncliq; j++) {
            if (CCutil_sread_int (f, (unsigned int *) &cliq)) goto CLEANUP;
            u.cliques[j] = cliq;
            if (hits[cliq])
                cuts->cliques[cliq].refcount++;
            else
                hits[cliq] = 1;
        }
        if (p) {
            if (CCutil_sread_int (f, (unsigned int *) &nmod)) goto CLEANUP;
            u.modcount = nmod;
            if (nmod) {
                u.mods = CC_SAFE_MALLOC (nmod, CCtsp_sparser);
                if (!u.mods) {
                    fprintf (stderr, "out of memory in read_da_cuts\n");
                    CC_FREE (u.cliques, int);
                    goto CLEANUP;
                }
            } else {
                u.mods = (CCtsp_sparser *) NULL;
            }
            for (j = 0; j < nmod; j++) {
                if (CCutil_sread_int (f, (unsigned int *) &n)) goto CLEANUP;
                if (CCutil_sread_int (f, (unsigned int *) &mult)) goto CLEANUP;
                u.mods[j].node = (unsigned int) n;
                u.mods[j].mult = (unsigned int) mult;
            }
        } else {
            u.mods = (CCtsp_sparser *) NULL;
            u.modcount = 0;
        }

        k = CCtsp_add_cut_to_cutlist (cuts, &u);
        if (k == -1) {
            fprintf (stderr, "CCtsp_add_cut_to_cutlist failed\n");
            cutcount++;
            goto CLEANUP;
        }
        if (k != cutcount) {
            fprintf (stderr, "cut location is out of seq\n");
            goto CLEANUP;
        }
        cutcount++;
        if (CCutil_sread_int (f, (unsigned int *) &ncliq)) goto CLEANUP;
    }

    CC_IFFREE (hits, int);
    return 0;


CLEANUP:

    if (cutcount) {
        for (i = 0; i < cutcount; i++)
            CCtsp_delete_cut_from_cutlist (cuts, i);
    } else {
        for (i = 0; i < cliqcount; i++)
            CCtsp_unregister_clique (cuts, i);
    }
    return -1;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_putbasis (CCtsp_PROB_FILE *p, int ccount, int rcount, int *cstat,
                   int *rstat)
#else
int CCtsp_prob_putbasis (p, ccount, rcount, cstat, rstat)
CCtsp_PROB_FILE *p;
int ccount, rcount;
int *cstat, *rstat;
#endif
{
    int i;

    if (!p) return 1;

    p->offsets.basis = CCutil_stell (p->f);

    if (CCutil_swrite_int (p->f, (unsigned int) ccount)) return 1;
    if (CCutil_swrite_int (p->f, (unsigned int) rcount)) return 1;

    for (i = 0; i < ccount; i++) {
        if (CCutil_swrite_bits (p->f, (unsigned int) cstat[i], 2)) return 1;
    }

    for (i = 0; i < rcount; i++) {
        if (CCutil_swrite_bits (p->f, (unsigned int) rstat[i], 1)) return 1;
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_getbasis (CCtsp_PROB_FILE *p, int *ccount, int *rcount, int **cstat,
                   int **rstat)
#else
int CCtsp_prob_getbasis (p, ccount, rcount, cstat, rstat)
CCtsp_PROB_FILE *p;
int *ccount, *rcount;
int **cstat, **rstat;
#endif
{
    int i;

    *ccount = 0;
    *rcount = 0;
    *cstat = (int *) NULL;
    *rstat = (int *) NULL;

    if (!p) return -1;

    if (p->offsets.basis == -1) {
        printf ("No basis in file.\n");
        return 1;
    }
    if (CCutil_sseek (p->f, p->offsets.basis)) {
        printf ("CCutil_sseek failed in CCtsp_prob_getbasis\n");
        return -1;
    }

    if (CCutil_sread_int (p->f, (unsigned int *) ccount)) goto CLEANUP;
    if (CCutil_sread_int (p->f, (unsigned int *) rcount)) goto CLEANUP;

    *cstat = CC_SAFE_MALLOC (*ccount, int);
    *rstat = CC_SAFE_MALLOC (*rcount, int);
    if (!(*rstat) || !(*cstat)) {
        fprintf (stderr, "out of memory in CCtsp_prob_getbasis\n");
        goto CLEANUP;
    }
    for (i = 0; i < *ccount; i++) {
        if (CCutil_sread_bits (p->f, (unsigned int *) &((*cstat)[i]), 2)) goto CLEANUP;
    }
    for (i = 0; i < *rcount; i++) {
        if (CCutil_sread_bits (p->f, (unsigned int *) &((*rstat)[i]), 1)) goto CLEANUP;
    }

    return 0;

CLEANUP:

    CC_IFFREE (*cstat, int);
    CC_IFFREE (*rstat, int);
    *ccount = 0;
    *rcount = 0;

    return -1;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_putnorms (CCtsp_PROB_FILE *p, int rcount, double *dnorm)
#else
int CCtsp_prob_putnorms (p, rcount, dnorm)
CCtsp_PROB_FILE *p;
int rcount;
double *dnorm;
#endif
{
    int i;

    if (!p) return 1;

    p->offsets.norms = CCutil_stell (p->f);

    if (CCutil_swrite_int (p->f, (unsigned int) rcount)) return 1;

    for (i = 0; i < rcount; i++) {
        if (CCutil_swrite_double (p->f, dnorm[i])) return 1;
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_getnorms (CCtsp_PROB_FILE *p, int *rcount, double **dnorm)
#else
int CCtsp_prob_getnorms (p, rcount, dnorm)
CCtsp_PROB_FILE *p;
int *rcount;
double **dnorm;
#endif
{
    int i;

    *rcount = 0;
    *dnorm  = (double *) NULL;

    if (!p) return -1;

    if (p->offsets.norms == -1) {
        printf ("No norms in file.\n");
        return 1;
    }
    if (CCutil_sseek (p->f, p->offsets.norms)) {
        printf ("CCutil_sseek failed in CCtsp_prob_getnorms\n");
        return -1;
    }

    if (CCutil_sread_int (p->f, (unsigned int *) rcount)) goto CLEANUP;

    *dnorm = CC_SAFE_MALLOC (*rcount, double);
    if (!(*dnorm)) {
        fprintf (stderr, "out of memory in CCtsp_prob_getnorms\n");
        goto CLEANUP;
    }
    for (i = 0; i < *rcount; i++) {
        if (CCutil_sread_double (p->f, &((*dnorm)[i]))) goto CLEANUP;
    }

    return 0;

CLEANUP:

    CC_IFFREE (*dnorm, double);
    *rcount = 0;

    return -1;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_putfulladj (CCtsp_PROB_FILE *p, int ncount, int fullcount,
        CCtsp_genadj *adj)
#else
int CCtsp_prob_putfulladj (p, ncount, fullcount, adj)
CCtsp_PROB_FILE *p;
int ncount, fullcount;
CCtsp_genadj *adj;
#endif
{
    int i, j;

    if (!p) return 1;

    p->offsets.fulladj = CCutil_stell (p->f);

    if (CCutil_swrite_int (p->f, (unsigned int) fullcount)) return 1;
    for (i = 0; i < ncount; i++) {
        if (CCutil_swrite_int (p->f, (unsigned int) adj[i].deg)) return 1;
        for (j = 0; j < adj[i].deg; j++) {
            if (CCutil_swrite_int (p->f, (unsigned int) adj[i].list[j].end))
                return 1;
            if (CCutil_swrite_int (p->f, (unsigned int) adj[i].list[j].len))
                return 1;
        }
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_getfulladj (CCtsp_PROB_FILE *p, int ncount, int *fullcount,
        CCtsp_genadj **adj, CCtsp_genadjobj **adjspace)
#else
int CCtsp_prob_getfulladj (p, ncount, fullcount, adj, adjspace)
CCtsp_PROB_FILE *p;
int ncount, *fullcount;
CCtsp_genadj **adj;
CCtsp_genadjobj **adjspace;
#endif
{
    int i, j;
    CCtsp_genadj *a;
    CCtsp_genadjobj *s;

    *fullcount = 0;
    *adj = (CCtsp_genadj *) NULL;
    *adjspace = (CCtsp_genadjobj *) NULL;

    if (!p || ncount <= 0) return -1;

    if (p->offsets.fulladj == -1) {
        printf ("No fulladj in file.\n");
        return 1;
    }
    if (CCutil_sseek (p->f, p->offsets.fulladj)) {
        printf ("CCutil_sseek failed in CCtsp_prob_getfulladj\n");
        return -1;
    }

    if (CCutil_sread_int (p->f, (unsigned int *) fullcount)) goto CLEANUP;

    *adjspace = CC_SAFE_MALLOC (*fullcount, CCtsp_genadjobj);
    *adj = CC_SAFE_MALLOC (ncount, CCtsp_genadj);
    if (!adjspace || !adj) {
        fprintf (stderr, "out of memory in CCtsp_prob_getfulladj\n");
        goto CLEANUP;
    }

    s = *adjspace;
    a = *adj;
    for (i = 0; i < ncount; i++) {
        a[i].list = s;
        if (CCutil_sread_int (p->f, (unsigned int *) &(a[i].deg))) goto CLEANUP;
        for (j = 0; j < a[i].deg; j++) {
            if (CCutil_sread_int (p->f, (unsigned int *) &(a[i].list[j].end)))
                goto CLEANUP;
            if (CCutil_sread_int (p->f, (unsigned int *) &(a[i].list[j].len)))
                goto CLEANUP;
        }
        s += a[i].deg;
    }

    return 0;

CLEANUP:

    CC_IFFREE (*adjspace, CCtsp_genadjobj);
    CC_IFFREE (*adj, CCtsp_genadj);
    *fullcount = 0;

    return -1;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_putfixed (CCtsp_PROB_FILE *p, int ecount, int *elist)
#else
int CCtsp_prob_putfixed (p, ecount, elist)
CCtsp_PROB_FILE *p;
int ecount;
int *elist;
#endif
{
    int i;

    if (!p) return 1;

    p->offsets.fix = CCutil_stell (p->f);

    if (CCutil_swrite_int (p->f, (unsigned int) ecount)) return 1;

    for (i = 0; i < 2*ecount; i++) {
        if (CCutil_swrite_int (p->f, (unsigned int) elist[i])) return 1;
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_getfixed (CCtsp_PROB_FILE *p, int *ecount, int **elist)
#else
int CCtsp_prob_getfixed (p, ecount, elist)
CCtsp_PROB_FILE *p;
int *ecount;
int **elist;
#endif
{
    int i;

    *ecount = 0;
    *elist = (int *) NULL;
    if (!p) return -1;

    if (p->offsets.fix == -1) {
        printf ("No fix in file\n");
        return 1;
    }
    if (CCutil_sseek (p->f, p->offsets.fix)) {
        printf ("CCutil_sseek failed in CCtsp_prob_getfix\n");
        return -1;
    }
    if (CCutil_sread_int (p->f, (unsigned int *) ecount)) goto CLEANUP;

    if (*ecount) {
        *elist = CC_SAFE_MALLOC (2*(*ecount), int);
        if (!(*elist)) {
            fprintf (stderr, "out of memory in CCtsp_prob_getfixed\n");
            goto CLEANUP;
        }
        for (i = 0; i < 2*(*ecount); i++) {
            if (CCutil_sread_int (p->f, (unsigned int *) (&((*elist)[i]))))
                goto CLEANUP;
        }
    }

    return 0;

CLEANUP:

    CC_IFFREE (*elist, int);
    *ecount = 0;

    return -1;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_putexactdual (CCtsp_PROB_FILE *p, CCtsp_bigdual *d, int ncount)
#else
int CCtsp_prob_putexactdual (p, d, ncount)
CCtsp_PROB_FILE *p;
CCtsp_bigdual *d;
int ncount;
#endif
{
    int i;

    if (!p) return 1;

    p->offsets.exactdual = CCutil_stell (p->f);

    if (CCutil_swrite_int (p->f, (unsigned int) d->cutcount)) return 1;

    for (i = 0; i < ncount; i++) {
        if (CCbigguy_swrite (p->f, d->node_pi[i])) return 1;
    }
    for (i = 0; i < d->cutcount; i++) {
        if (CCbigguy_swrite (p->f, d->cut_pi[i])) return 1;
    }

    return 0;
}


#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_getexactdual (CCtsp_PROB_FILE *p, int ncount, CCtsp_bigdual **d)
#else
int CCtsp_prob_getexactdual (p, ncount, d)
CCtsp_PROB_FILE *p;
int ncount;
CCtsp_bigdual **d;
#endif
{
    CCtsp_bigdual *rd;
    int i;

    *d = (CCtsp_bigdual *) NULL;

    if (!p) return -1;

    if (p->offsets.exactdual == -1) {
        printf ("No exactdual in file\n");
        fflush (stdout);
        return 1;
    }

    *d = CC_SAFE_MALLOC (1, CCtsp_bigdual);
    if (!(*d)) {
        fprintf (stderr, "out of memory in CCtsp_prob_getexactdual\n");
        goto CLEANUP;
    }
    rd = *d;
    rd->cutcount = 0;
    rd->node_pi = (CCbigguy *) NULL;
    rd->cut_pi = (CCbigguy *) NULL;

    if (CCutil_sseek (p->f, p->offsets.exactdual)) {
        fprintf (stderr, "CCutil_sseek failed in CCtsp_prob_getexactdual\n");
        return -1;
    }
    if (CCutil_sread_int (p->f, (unsigned int *) &(rd->cutcount))) goto CLEANUP;

    rd->node_pi = CC_SAFE_MALLOC (ncount, CCbigguy);
    if (!rd->node_pi) {
        fprintf (stderr, "out of memory in CCtsp_prob_getexactdual\n");
        goto CLEANUP;
    }
    for (i = 0; i < ncount; i++) {
        if (CCbigguy_sread (p->f, &(rd->node_pi[i]))) goto CLEANUP;
    }
    if (rd->cutcount) {
        rd->cut_pi = CC_SAFE_MALLOC (rd->cutcount, CCbigguy);
        if (!rd->cut_pi) {
            fprintf (stderr, "out of memory in CCtsp_prob_getexactdual\n");
            goto CLEANUP;
        }
        for (i = 0; i < rd->cutcount; i++) {
            if (CCbigguy_sread (p->f, &(rd->cut_pi[i]))) goto CLEANUP;
        }
    }

    return 0;

CLEANUP:

    if (*d) {
        CC_IFFREE ((*d)->node_pi, CCbigguy);
        CC_IFFREE ((*d)->cut_pi, CCbigguy);
        CC_FREE (*d, CCtsp_bigdual);
    }
    return -1;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_puthistory (CCtsp_PROB_FILE *p, int depth,
        CCtsp_branchobj *history)
#else
int CCtsp_prob_puthistory (p, depth, history)
CCtsp_PROB_FILE *p;
int depth;
CCtsp_branchobj *history;
#endif
{
    int i, j;
    CCtsp_lpclique *c;

    if (!p) return 1;

    p->offsets.history = CCutil_stell (p->f);

    if (CCutil_swrite_int (p->f, (unsigned int) depth)) return 1;

    for (i = 0; i < depth; i++) {
        if (CCutil_swrite_int (p->f, (unsigned int) history[i].depth))
            return 1;
        if (CCutil_swrite_int (p->f, (unsigned int) history[i].rhs))
            return 1;
        if (CCutil_swrite_int (p->f, (unsigned int) history[i].ends[0]))
            return 1;
        if (CCutil_swrite_int (p->f, (unsigned int) history[i].ends[1]))
            return 1;
        if (history[i].clique) {
            c = history[i].clique;
            if (CCutil_swrite_int (p->f, (unsigned int) c->segcount))
                return 1;
            for (j = 0; j < c->segcount; j++) {
                if (CCutil_swrite_int (p->f, (unsigned int) c->nodes[j].lo))
                    return 1;
                if (CCutil_swrite_int (p->f, (unsigned int) c->nodes[j].hi))
                    return 1;
            }
        } else {
            if (CCutil_swrite_int (p->f, (unsigned int) 0)) return 1;
        }
        if (CCutil_swrite_char (p->f, (unsigned char) history[i].sense))
            return 1;
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCtsp_prob_gethistory (CCtsp_PROB_FILE *p, int *depth,
        CCtsp_branchobj **history)
#else
int CCtsp_prob_gethistory (p, depth, history)
CCtsp_PROB_FILE *p;
int *depth;
CCtsp_branchobj **history;
#endif
{
    int i, j, nseg, rval;
    CCtsp_lpclique *c = (CCtsp_lpclique *) NULL;
    int *slist  = (int *) NULL;

    *depth = 0;
    *history = (CCtsp_branchobj *) NULL;
    if (!p) return -1;

    if (p->offsets.history == -1) {
        printf ("No branch history in file\n");
        return 1;
    }
    if (CCutil_sseek (p->f, p->offsets.history)) {
        printf ("CCutil_sseek failed in CCtsp_prob_gethistory\n");
        return -1;
    }
    if (CCutil_sread_int (p->f, (unsigned int *) depth)) goto CLEANUP;

    if (*depth) {
        *history = CC_SAFE_MALLOC (*depth, CCtsp_branchobj);
        if (!(*history)) {
            fprintf (stderr, "out of memory in CCtsp_prob_gethistory\n");
            goto CLEANUP;
        }
        for (i = 0; i < (*depth); i++) {
            if (CCutil_sread_int (p->f,
                   (unsigned int *) &((*history)[i].depth)))
                goto CLEANUP;
            if (CCutil_sread_int (p->f,
                   (unsigned int *) &((*history)[i].rhs)))
                goto CLEANUP;
            if (CCutil_sread_int (p->f,
                   (unsigned int *) &((*history)[i].ends[0])))
                goto CLEANUP;
            if (CCutil_sread_int (p->f,
                   (unsigned int *) &((*history)[i].ends[1])))
                goto CLEANUP;
            if (CCutil_sread_int (p->f, (unsigned int *) &nseg))
                goto CLEANUP;
            if (nseg) {
                slist = CC_SAFE_MALLOC (2*nseg, int);
                if (!slist) goto CLEANUP;
                for (j = 0; j < nseg; j++) {
                    if (CCutil_sread_int (p->f, (unsigned int *) &slist[2*j]))
                        goto CLEANUP;
                    if (CCutil_sread_int (p->f, (unsigned int *) &slist[2*j+1]))
                        goto CLEANUP;
                }
                c = CC_SAFE_MALLOC (1, CCtsp_lpclique);
                if (!c) goto CLEANUP;
                rval = CCtsp_seglist_to_lpclique (nseg, slist, c);
                if (rval) {
                    fprintf (stderr, "CCtsp_seglist_to_lpclique failed\n");
                    CC_FREE (c, CCtsp_lpclique);
                    goto CLEANUP;
                }
                (*history)[i].clique = c;
            } else {
                (*history)[i].clique = (CCtsp_lpclique *) NULL;
            }
            if (CCutil_sread_char (p->f,
                   (unsigned char *) &((*history)[i].sense)))
                return 1;
        }
    }

    return 0;

CLEANUP:

    CC_IFFREE (slist, int);
    CC_IFFREE (*history, CCtsp_branchobj);
    *depth = 0;

    return -1;
}
