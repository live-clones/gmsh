/***************************************************************************/
/*                                                                         */
/*               MISCELLANEOUS UTILITY ROUTINES                            */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: October 12, 1995                                                 */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "macrorus.h"
#include "util.h"

#ifdef CC_PROTOTYPE_ANSI

static int
    isprime (unsigned int x);

#else

static int
    isprime ();

#endif

#ifdef CC_PROTOTYPE_ANSI
unsigned int CCutil_nextprime (unsigned int x)
#else
unsigned int CCutil_nextprime (x)
unsigned int x;
#endif
{
    if (x < 3) return 3;
    x |= 1;
    while (!isprime (x)) x += 2;
    return x;
}

#ifdef CC_PROTOTYPE_ANSI
static int isprime (unsigned int p)
#else
static int isprime (p)
unsigned int p;
#endif
{
    unsigned int i;

    if ((p&1) == 0) return 0;
    for (i=3; i*i<=p; i+=2) {
        if (p%i == 0) return 0;
    }
    return 1;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_our_gcd (int a, int b)
#else
int CCutil_our_gcd (a, b)
int a;
int b;
#endif
{
    int c;

    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a > b) CC_SWAP (a, b, c);

    while (a) {
        c = b % a;
        b = a;
        a = c;
    }
    return b;
}

#ifdef CC_PROTOTYPE_ANSI
char *CCutil_strrchr (char *s, int c)
#else
char *CCutil_strrchr (s, c)
char *s;
int c;
#endif
{
    char *l = (char *) NULL;

    while (*s) {
        if (*s == c) l = s;
        s++;
    }
    return l;
}

