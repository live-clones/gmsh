/***************************************************************************/
/*                                                                         */
/*       FUNCTIONS FOR COMPUTING EDGE LENGTHS FOR GEOMETRIC PROBLEMS       */
/*                                                                         */
/*                             TSP CODE                                    */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: Summer 1994                                                      */
/*        Modified - March 2, 1995                                         */
/*                 - October 5, 1995 (Bico)                                */
/*                                                                         */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    int                                                                  */
/*        CCutil_init_dat_edgelen (CCdatagroup *dat)                       */
/*    int                                                                  */
/*      (*CCutil_dat_edgelen) (int i, int j, CCdatagroup *dat)             */
/*    void                                                                 */
/*        CCutil_dsjrand_init (int maxdist, int seed)                      */
/*    void                                                                 */
/*        CCutil_freedata (int ncount, CCdatagroup *dat)                   */
/*                                                                         */
/*    NOTES:                                                               */
/*        Supported norms (with defs in edgelen.h) are:                    */
/*            MAXNORM  -  the L-infinity norm                              */
/*            EUCLIDEAN_CEIL - the norm for the plaXXXX problems           */
/*            EUCLIDEAN - rounded L-2 norm                                 */
/*            EUCLIDEAN_3d - rounded L-2 norm in 3 space                   */
/*            IBM - a norm for drilling problems in Bonn                   */
/*            GEOGRAPHIC - distances on a sphere (Groetshel and Holland)   */
/*            ATT - pseudo-Euclidean norm for att532                       */
/*            MATRIXNORM - complete graph (lower + diagonal matrix)        */
/*            DSJRAND - random edgelengths                                 */
/*            CRYSTAL - Bland-Shallcross xray norm                         */
/*                    - The coordinates generated for CRYSTAL problems     */
/*               (in getdata.c) have been diveded by the motor speeds      */
/*               (this makes the edgelen function faster) and scaled by    */
/*               CRYSTAL_SCALE (currently 10000) and rounded to the        */
/*               nearest integer (this lets the edgelen function produce   */
/*               integer lengths without further rounding). The result is  */
/*               a closer approximation to the Bland - Shallcrosss         */
/*               floating point length function than that given in         */
/*               TSPLIB_1.2.                                               */
/*                                                                         */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"

#ifdef CC_PROTOTYPE_ANSI

static double
    dtrunc (double);

#else

static double
    dtrunc ();

#endif

#ifndef M_PI
#define M_PI 3.14159265358979323846264
#endif

#ifdef CC_PROTOTYPE_ANSI
int (*CCutil_dat_edgelen) (int, int, CCdatagroup *);
#else
int (*CCutil_dat_edgelen) ();
#endif

#ifdef CC_PROTOTYPE_ANSI
int CCutil_init_dat_edgelen (CCdatagroup *dat)
#else
int CCutil_init_dat_edgelen (dat)
CCdatagroup *dat;
#endif
{
    switch (dat->norm) {
    case CC_EUCLIDEAN_CEIL:
        CCutil_dat_edgelen = CCutil_euclid_ceiling_edgelen;
        break;
    case CC_EUCLIDEAN:
        CCutil_dat_edgelen = CCutil_euclid_edgelen;
        break;
    case CC_MAXNORM:
        CCutil_dat_edgelen = CCutil_max_edgelen;
        break;
    case CC_EUCLIDEAN_3D:
        CCutil_dat_edgelen = CCutil_euclid3d_edgelen;
        break;
    case CC_IBM:
        CCutil_dat_edgelen = CCutil_ibm_edgelen;
        break;
    case CC_GEOGRAPHIC:
        CCutil_dat_edgelen = CCutil_geographic_edgelen;
        break;
    case CC_ATT:
        CCutil_dat_edgelen = CCutil_att_edgelen;
        break;
    case CC_MATRIXNORM:
        CCutil_dat_edgelen = CCutil_matrix_edgelen;
        break;
    case CC_DSJRANDNORM:
        CCutil_dat_edgelen = CCutil_dsjrand_edgelen;
        break;
    case CC_CRYSTAL:
        CCutil_dat_edgelen = CCutil_crystal_edgelen;
        break;
    default:
        fprintf (stderr, "ERROR:  Unknown NORM %d.\n", dat->norm);
        return 1;
    }
    return 0;
}

/* Several variables that would normally be called y1 and y2 are called
   yy1 and yyy2 to avoid conflict with the bessel functions */

#ifdef CC_PROTOTYPE_ANSI
int CCutil_max_edgelen (int i, int j, CCdatagroup *dat)
#else
int CCutil_max_edgelen (i, j, dat)
int i, j;
CCdatagroup *dat;
#endif
{
    double t1 = dat->x[i] - dat->x[j], t2 = dat->y[i] - dat->y[j];

    if (t1 < 0)
        t1 *= -1;
    if (t2 < 0)
        t2 *= -1;

    return (int) (t1 < t2 ? t2 : t1);
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_euclid_edgelen (int i, int j, CCdatagroup *dat)
#else
int CCutil_euclid_edgelen (i, j, dat)
int i, j;
CCdatagroup *dat;
#endif
{
    double t1 = dat->x[i] - dat->x[j], t2 = dat->y[i] - dat->y[j];
    int temp;

    temp = (int) (sqrt (t1 * t1 + t2 * t2) + 0.5);
    return temp;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_euclid3d_edgelen (int i, int j, CCdatagroup *dat)
#else
int CCutil_euclid3d_edgelen (i, j, dat)
int i, j;
CCdatagroup *dat;
#endif
{
    double t1 = dat->x[i] - dat->x[j], t2 = dat->y[i] - dat->y[j];
    double t3 = dat->z[i] - dat->z[j];
    int temp;

    temp = (int) (sqrt (t1 * t1 + t2 * t2 + t3 * t3) + 0.5);
    return temp;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_ibm_edgelen (int i, int j, CCdatagroup *dat)
#else
int CCutil_ibm_edgelen (i, j, dat)
int i, j;
CCdatagroup *dat;
#endif
{
    double dw = dat->x[i] - dat->x[j], dw1 = dat->y[i] - dat->y[j];
    static double ibm_xmult[7] = {1062.5,
        300.0,
        300.0,
        250.0,
        300.0,
        1000.0,
        154.6};
    static double ibm_xadd[7] = {155.0 - 0.01 * 1062.5,
        197.5 - 0.05 * 300.0,
        212.5 - 0.10 * 300.0,
        227.5 - 0.15 * 250.0,
        240.5 - 0.20 * 300.0,
        255.0 - 0.25 * 1000.0,
        305.0 - 0.30 * 154.6};
    static double ibm_ymult[7] = {1062.5,
        450.0,
        350.0,
        250.0,
        300.0,
        900.0,
        157.7};
    static double ibm_yadd[7] = {150.0 - 0.01 * 1062.5,
        192.5 - 0.05 * 450.0,
        215.0 - 0.10 * 350.0,
        232.5 - 0.15 * 250.0,
        245.5 - 0.20 * 300.0,
        250.0 - 0.25 * 900.0,
        295.0 - 0.30 * 157.7};

    if (dw < 0.0)
        dw = -dw;
    dw /= 25400.0;
    if (dw <= 0.01) {
        dw *= 15500.0;
    } else if (dw >= 0.30) {
        dw = dw * 154.6 + (305.0 - 0.3 * 154.6);
    } else {
        dw = dw * ibm_xmult[(int) (dw / 0.05)] +
            ibm_xadd[(int) (dw / 0.05)];
    }
    if (dw1 < 0.0)
        dw1 = -dw1;
    dw1 /= 25400.0;
    if (dw1 <= 0.01) {
        dw1 *= 15000.0;
    } else if (dw1 >= 0.30) {
        dw1 = dw1 * 157.7 + (295.0 - 0.3 * 157.7);
    } else {
        dw1 = dw1 * ibm_ymult[(int) (dw1 / 0.05)] +
            ibm_yadd[(int) (dw1 / 0.05)];
    }
    if (dw < dw1)
        dw = dw1;
    return (int) dw;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_euclid_ceiling_edgelen (int i, int j, CCdatagroup *dat)
#else
int CCutil_euclid_ceiling_edgelen (i, j, dat)
int i, j;
CCdatagroup *dat;
#endif
{
    double t1 = dat->x[i] - dat->x[j], t2 = dat->y[i] - dat->y[j];
/*
    int rd;
    double max;

    max = sqrt (t1 * t1 + t2 * t2);
    rd = (int) max;
    return (((max - rd) > .000000001) ? rd + 1 : rd);
*/
    return (int) (ceil (sqrt (t1 * t1 + t2 * t2)));
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_geographic_edgelen (int i, int j, CCdatagroup *dat)
#else
int CCutil_geographic_edgelen (i, j, dat)
int i, j;
CCdatagroup *dat;
#endif
{
    double deg, min;
    double lati, latj, longi, longj;
    double q1, q2, q3;
    int dd;
    double x1 = dat->x[i], x2 = dat->x[j], yy1 = dat->y[i], yy2 = dat->y[j];

    deg = dtrunc (x1);
    min = x1 - deg;
    lati = M_PI * (deg + 5.0 * min / 3.0) / 180.0;
    deg = dtrunc (x2);
    min = x2 - deg;
    latj = M_PI * (deg + 5.0 * min / 3.0) / 180.0;

    deg = dtrunc (yy1);
    min = yy1 - deg;
    longi = M_PI * (deg + 5.0 * min / 3.0) / 180.0;
    deg = dtrunc (yy2);
    min = yy2 - deg;
    longj = M_PI * (deg + 5.0 * min / 3.0) / 180.0;

    q1 = cos (longi - longj);
    q2 = cos (lati - latj);
    q3 = cos (lati + latj);
    dd = (int) (6378.388 * acos (0.5 * ((1.0 + q1) * q2 - (1.0 - q1) * q3))
                + 1.0);
    return dd;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_att_edgelen (int i, int j, CCdatagroup *dat)
#else
int CCutil_att_edgelen (i, j, dat)
int i, j;
CCdatagroup *dat;
#endif
{
    double xd = dat->x[i] - dat->x[j];
    double yd = dat->y[i] - dat->y[j];
    double rij = sqrt ((xd * xd + yd * yd) / 10.0);
    double tij = dtrunc (rij);
    int dij;

    if (tij < rij)
        dij = (int) tij + 1;
    else
        dij = (int) tij;
    return dij;
}

#ifdef CC_PROTOTYPE_ANSI
static double dtrunc (double x)
#else
static double dtrunc (x)
double x;
#endif
{
    int k;

    k = (int) x;
    x = (double) k;
    return x;
}

static int dsjrand_param = 1;
static double dsjrand_factor = 1.0;

#ifdef CC_PROTOTYPE_ANSI
void CCutil_dsjrand_init (int maxdist, int seed)
#else
void CCutil_dsjrand_init (maxdist, seed)
int maxdist, seed;
#endif
{
    dsjrand_factor = maxdist/2147483648.0;
    dsjrand_param = 104*seed+1;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_dsjrand_edgelen (int i, int j, CCdatagroup *dat)
#else
int CCutil_dsjrand_edgelen (i, j, dat)
int i, j;
CCdatagroup *dat;
#endif
{
    int di = (int) dat->x[i];
    int dj = (int) dat->x[j];
    int x, y, z;

    x = di&dj;
    y = di|dj;
    z = dsjrand_param;

    x *= z;
    y *= x;
    z *= y;

    z ^= dsjrand_param;

    x *= z;
    y *= x;
    z *= y;

    x = ((di+dj)^z)&0x7fffffff;
    return (int)(x*dsjrand_factor);
}

#define CRYSTAL_SCALE 10000

#define CRYSTAL_FLIP_TOL ((180 * CRYSTAL_SCALE * 4) / 5)
#define CRYSTAL_NEEDS_FLIP(x) ((x) > (CRYSTAL_FLIP_TOL))
#define CRYSTAL_FLIP(x) ((2 * (CRYSTAL_FLIP_TOL)) - (x))

#ifdef CC_PROTOTYPE_ANSI
int CCutil_crystal_edgelen (int i, int j, CCdatagroup *dat)
#else
int CCutil_crystal_edgelen (i, j, dat)
int i, j;
CCdatagroup *dat;
#endif
{
    double w, w1;

    w = dat->x[i] - dat->x[j];
    if (w < 0)
        w = -w;
    w1 = dat->y[i] - dat->y[j];
    if (w1 < 0)
        w1 = -w1;
    if (CRYSTAL_NEEDS_FLIP (w1))
        w1 = CRYSTAL_FLIP (w1);
    if (w < w1)
        w = w1;
    w1 = dat->z[i] - dat->z[j];
    if (w1 < 0)
        w1 = -w1;
    if (w < w1)
        w = w1;

    return (int) w;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_matrix_edgelen (int i, int j, CCdatagroup *dat)
#else
int CCutil_matrix_edgelen (i, j, dat)
int i, j;
CCdatagroup *dat;
#endif
{
    if (i > j)
        return (dat->adj[i])[j];
    else
        return (dat->adj[j])[i];
}

#ifdef CC_PROTOTYPE_ANSI
void CCutil_freedatagroup (int ncount, CCdatagroup *dat)
#else
void CCutil_freedatagroup (ncount, dat)
int ncount;
CCdatagroup *dat;
#endif
{
    int i;

    CC_IFFREE (dat->x, double);
    CC_IFFREE (dat->y, double);
    CC_IFFREE (dat->z, double);
    if (dat->adj) {
        for (i = 0; i < ncount; i++) {
            CC_IFFREE (dat->adj[i], int);
        }
        CC_FREE (dat->adj, int *);
    }
}
