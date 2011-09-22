/***************************************************************************/
/*                                                                         */
/*              MACHINE INDEPENDENT RANDOM NUMBER GENERATOR                */
/*                                                                         */
/*                             TSP CODE                                    */
/*                                                                         */
/*                                                                         */
/*  Written by:  DIMACS  (modified for TSP)                                */
/*  Date: February 7, 1995  (cofeb16)                                      */
/*                                                                         */
/*                                                                         */
/*  EXPORTED FUNCTIONS:                                                    */
/*    void CCutil_sprand (int seed)                                        */
/*      - Call once to initialize the generator.                           */
/*    int CCutil_lprand (void)                                             */
/*      - Returns an integer in the range 0 to PRANDMAX - 1.               */
/*                                                                         */
/*    NOTES (from DIMACS):                                                 */
/*        This file contains a set of c-language functions for generating  */
/*    uniform integers.   This is a COMPLETELY PORTABLE generator. It will */
/*    give IDENTICAL sequences of random numbers for any architecture with */
/*    at least 30-bit integers, regardless of the integer representation,  */
/*    MAXINT value, or roundoff/truncation method, etc.                    */
/*        This Truly Remarkable RNG is described more fully in             */
/*    J. Bentley's column, ``The Software Exploratorium ''. It is based on */
/*    one in Knuth, Vol 2, Section 3.2.2 (Algorithm A).                    */
/*                                                                         */
/***************************************************************************/


#include "machdefs.h"
#include "util.h"

#define PRANDMAX 1000000000
static int a;
static int b;
static int arr[55];


#ifdef CC_PROTOTYPE_ANSI
void CCutil_sprand (int seed)
#else
void CCutil_sprand (seed)
int seed;
#endif
{
    int i, ii;
    int last, next;

    seed %= PRANDMAX;
    if (seed < 0) seed += PRANDMAX;

    arr[0] = last = seed;
    next = 1;
    for (i = 1; i < 55; i++) {
        ii = (21 * i) % 55;
        arr[ii] = next;
        next = last - next;
        if (next < 0)
            next += PRANDMAX;
        last = arr[ii];
    }
    a = 0;
    b = 24;
    for (i = 0; i < 165; i++)
        last = CCutil_lprand ();
}


#ifdef CC_PROTOTYPE_ANSI
int CCutil_lprand (void)
#else
int CCutil_lprand ()
#endif
{
    int t;

    if (a-- == 0)
        a = 54;
    if (b-- == 0)
        b = 54;

    t = arr[a] - arr[b];

    if (t < 0)
        t += PRANDMAX;

    arr[a] = t;

    return t;
}


#ifdef      TRY_CODE

/*-----------------------------------------------*/
/* This is a little driver program so you can    */
/* test the code.                                */
/* Typing: a.out 0 3 1                           */
/* should produce                                */
/*     921674862                                 */
/*     250065336                                 */
/*     377506581                                 */
/*  Typing: a.out 1000000 1 2                    */
/*  should produce                               */
/*     57265995                                  */
/*-----------------------------------------------*/

#ifdef CC_PROTOTYPE_ANSI
int main (int ac, char **av)
#else
int main (ac, av)
int ac;
char **av;
#endif
{
    int i;
    int j;
    int n;
    int m;
    int seed;

    if (ac < 4) {
        fprintf (stderr, "Usage: #discard #print #seed\n");
        return 0;
    }
    m = atoi (av[1]);           /* Number to discard initially */
    n = atoi (av[2]);           /* Number to print */
    seed = atoi (av[3]);        /* Seed */

    CCutil_sprand (seed);

    for (i = 0; i < m; i++)
        j = CCutil_lprand ();
    for (i = 0; i < n; i++)
        printf ("%ld\n", CCutil_lprand ());
    return 0;
}

#endif  /* TRY_CODE */
