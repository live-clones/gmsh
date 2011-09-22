#include "machdefs.h"
#include "util.h"
#include "bigguy.h"

#define EPSILON ((1.0/(1<<15))*(1.0/(1<<15)))

#ifdef CC_PROTOTYPE_ANSI

static CCbigguy
    bgrand (double *delta, int maxx);

static int
    bgcheck (CC_SFILE *sfin, CC_SFILE *sfout, CCbigguy x, char *name),
    dotest (int maxx, int maxy, int maxs, int ntrial, double *delta,
        CCbigguy *sum, CC_SFILE *sfin, CC_SFILE *sfout);

static void
    sum_chk (CCbigguy *sum, CCbigguy x);

static short
    shortrand (short maxs);

#else

static CCbigguy
    bgrand();

static int
    bgcheck (),
    dotest ();

static void
    sum_chk ();

static short
    shortrand ();

#endif

#ifdef CC_PROTOTYPE_ANSI
int main (int ac, char **av)
#else
int main (ac, av)
int ac;
char **av;
#endif
{
    int i;
    int x, y, d;
    int nerrs = 0;
    CC_SFILE *sfin = CCutil_sdopen (0, "r");
    CC_SFILE *sfout = CCutil_sdopen (1, "w");
    double delta;
    CCbigguy sum;

    CCutil_sprand (47);

    if (ac > 1) {
        fprintf (stderr, "Usage: %s < std_file > new_file\n", av[0]);
        return 1;
    }

    nerrs += bgcheck (sfin, sfout, CCbigguy_MINBIGGUY, "CCbigguy_MINBIGGUY");
    nerrs += bgcheck (sfin, sfout, CCbigguy_MAXBIGGUY, "CCbigguy_MAXBIGGUY");
    nerrs += bgcheck (sfin, sfout, CCbigguy_ZERO, "CCbigguy_ZERO");
    nerrs += bgcheck (sfin, sfout, CCbigguy_ONE, "CCbigguy_ONE");

    delta = 0.0;

    sum = CCbigguy_ZERO;
    nerrs += bgcheck (sfin, sfout, sum, "sum_init");
    
    for (i=6; i<=30; i+=8) {
        for (x=(1<<i), y=(1<<i); y >= 1; y /= 16, x += 15*y) {
            for (d=(y < 32767 ? y : 32767); d>0; d /= 6) {
                nerrs += dotest (x, y/d, d, 100, &delta, &sum, sfin, sfout);
            }
            for (d=(y < 32767 ? y : 32767); d>0; d /= 6) {
                nerrs += dotest (y, x/d, d, 100, &delta, &sum, sfin, sfout);
            }
        }
    }

    CCutil_sclose (sfin);
    CCutil_sclose (sfout);

    fprintf (stderr, "%d total errors\n", nerrs);
    fprintf (stderr, "Total delta: %.20f\n", delta);

    return nerrs;
}

#ifdef CC_PROTOTYPE_ANSI
static int dotest (int maxx, int maxy, int maxs, int ntrial, double *delta,
                   CCbigguy *sum, CC_SFILE *sfin, CC_SFILE *sfout)
#else
static int dotest (maxx, maxy, maxs, ntrial, delta, sum, sfin, sfout)
int maxx;
int maxy;
int maxs;
int ntrial;
double *delta;
CCbigguy *sum;
CC_SFILE *sfin;
CC_SFILE *sfout;
#endif
{
    int i;
    int j;
    CCbigguy x;
    CCbigguy y;
    CCbigguy a, b, c, d, e, f, g;
    short s;
    int nerrs = 0;

    if (maxs > 32767) maxs = 32767;
    
    for (i=0; i<ntrial; i++) {
        x = bgrand (delta, maxx);
        y = bgrand (delta, maxy);
        s = shortrand (maxs);

        a = x;
        CCbigguy_add (&a, y);

        b = x;
        CCbigguy_sub (&b, y);

        c = x;
        CCbigguy_addmult (&c, y, CCbigguy_cmp (x, y));

        d = x;
        CCbigguy_addmult (&d, y, s);

        e = CCbigguy_ceil (x);

        j = CCutil_lprand();

        f = CCbigguy_itobigguy (j);

        g = CCbigguy_itobigguy (-j);

        sum_chk (sum, x);
        sum_chk (sum, y);
        sum_chk (sum, a);
        sum_chk (sum, b);
        sum_chk (sum, c);
        sum_chk (sum, d);
        sum_chk (sum, e);
        sum_chk (sum, f);
        sum_chk (sum, g);

        if (i < 3) {
            char nambuf[5];
            sprintf (nambuf, "x%d", i);
            nerrs += bgcheck (sfin, sfout, x, nambuf);
            nambuf[0] = 'y';
            nerrs += bgcheck (sfin, sfout, y, nambuf);
            nambuf[0] = 'a';
            nerrs += bgcheck (sfin, sfout, a, nambuf);
            nambuf[0] = 'b';
            nerrs += bgcheck (sfin, sfout, b, nambuf);
            nambuf[0] = 'c';
            nerrs += bgcheck (sfin, sfout, c, nambuf);
            nambuf[0] = 'd';
            nerrs += bgcheck (sfin, sfout, d, nambuf);
            nambuf[0] = 'e';
            nerrs += bgcheck (sfin, sfout, e, nambuf);
            nambuf[0] = 'f';
            nerrs += bgcheck (sfin, sfout, f, nambuf);
            nambuf[0] = 'g';
            nerrs += bgcheck (sfin, sfout, g, nambuf);
        }
    }
    nerrs += bgcheck (sfin, sfout, *sum, "end sum");

    return nerrs;
}

#ifdef CC_PROTOTYPE_ANSI
static void sum_chk (CCbigguy *sum, CCbigguy x)
#else
static void sum_chk (sum, x)
CCbigguy *sum;
CCbigguy x;
#endif
{
    CCbigguy y;
    
    if (CCbigguy_cmp (x, CCbigguy_ZERO) > 0 &&
        CCbigguy_cmp (*sum, CCbigguy_ZERO) > 0) {
        y = CCbigguy_MAXBIGGUY;
        CCbigguy_sub (&y, x);
        if (CCbigguy_cmp (*sum, y) >= 0) {
            CCbigguy_sub (sum, CCbigguy_MAXBIGGUY);
        }
    } else if (CCbigguy_cmp (x, CCbigguy_ZERO) < 0 &&
        CCbigguy_cmp (*sum, CCbigguy_ZERO) < 0) {
        y = CCbigguy_MINBIGGUY;
        CCbigguy_sub (&y, x);
        if (CCbigguy_cmp (*sum, y) <= 0) {
            CCbigguy_sub (sum, CCbigguy_MINBIGGUY);
        }
    }
    CCbigguy_add (sum, x);
}

#ifdef CC_PROTOTYPE_ANSI
static int bgcheck (CC_SFILE *sfin, CC_SFILE *sfout, CCbigguy x, char *name)
#else
static int bgcheck (sfin, sfout, x, name)
CC_SFILE *sfin;
CC_SFILE *sfout;
CCbigguy x;
char *name;
#endif
{
    CCbigguy v;

    CCbigguy_sread (sfin, &v);
    CCbigguy_swrite (sfout, x);
    if (CCbigguy_cmp(v,x)) {
        fprintf (stderr, "%s misread (%.15f != %.15f)\n", name,
                 CCbigguy_bigguytod(v), CCbigguy_bigguytod(x));
        return 1;
    } else {
        return 0;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static CCbigguy bgrand (double *delta, int maxv)
#else
static CCbigguy bgrand (delta, maxv)
double *delta;
int maxv;
#endif
{
    CCbigguy x, y;
    double d16 = 1.0 / (1 << 16);
    double d32 = d16 * d16;
    double dx;

    dx = d32 * (CCutil_lprand() & 0xffff);
    x = CCbigguy_dtobigguy (dx);
    *delta += fabs(dx - CCbigguy_bigguytod(x));

    dx = d16 * (CCutil_lprand() & 0xffff);
    y = CCbigguy_dtobigguy(dx);
    *delta += fabs(dx - CCbigguy_bigguytod(y));
    CCbigguy_add (&x, y);

    dx = 1.0 * (CCutil_lprand() % maxv);
    y = CCbigguy_dtobigguy(dx);
    *delta += fabs(dx - CCbigguy_bigguytod(y));
    CCbigguy_add (&x, y);

    if (CCutil_lprand() & 1) {
        return x;
    } else {
        dx = CCbigguy_bigguytod(x);
        y = CCbigguy_ZERO;
        CCbigguy_sub (&y, x);
        *delta += fabs(dx + CCbigguy_bigguytod(y));
        return y;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static short shortrand (short maxs)
#else
static short shortrand (maxs)
short maxs;
#endif
{
    int s = CCutil_lprand() % maxs;

    if (CCutil_lprand() % 1) s = -s;

    return (short) s;
}
