/**************************************************************************/
/*                                                                        */
/*  BIGGUY OPERATIONS:                                                    */
/*                                                                        */
/*  x += y                  CCbigguy_add (CCbigguy *x, CCbigguy y)        */
/*  x -= y                  CCbigguy_sub (CCbigguy *x, CCbigguy y)        */
/*  x += y*m                CCbigguy_addmult (CCbigguy *x, CCbigguy y,    */
/*                                            short m)                    */
/*  x<y -1, x==y 0, x>y 1   CCbigguy_cmp (CCbigguy x, CCbigguy y)         */
/*  ceil(x)                 CCbigguy_ceil (CCbigguy x)                    */
/*                                                                        */
/*  (double) x              CCbigguy_bigguytod (CCbigguy x)               */
/*  (bigguy) i              CCbigguy_itobigguy (int i)                    */
/*  (bigguy) d              CCbigguy_dtobigguy (double d)                 */
/*                                                                        */
/*  read(x)                 CCbigguy_sread (CC_SFILE *f, CCbigguy *x)     */
/*  write(x)                CCbigguy_swrite (CC_SFILE *f, CCbigguy x)     */
/*                                                                        */
/*  biggest possible x      const CCbigguy CCbigguy_MAXBIGGUY             */
/*  smallest possible x     const CCbigguy CCbigguy_MINBIGGUY             */
/*  0                       const CCbigguy CCbigguy_ZERO                  */
/*  1                       const CCbigguy CCbigguy_ONE                   */
/*                                                                        */
/*                                                                        */
/*  EXPORTED FUNCTIONS:                                                   */
/*                                                                        */
/*      int                                                               */
/*          CCbigguy_swrite (CC_SFILE *f, CCbigguy x)                     */
/*          CCbigguy_sread (CC_SFILE *f, CCbigguy *x)                     */
/*                                                                        */
/*  If  CC_BIGGUY_LONGLONG is not defined                                 */
/*                                                                        */
/*      void                                                              */
/*          CCbigguy_addmult (CCbigguy *x, CCbigguy y, short m)           */
/*                                                                        */
/*      int                                                               */
/*          CCbigguy_cmp (CCbigguy x, CCbigguy y)                         */
/*                                                                        */
/*      double                                                            */
/*          CCbigguytod (CCbigguy x)                                      */
/*                                                                        */
/*      CCbigguy                                                          */
/*          CCbigguy_itobigguy (int d)                                    */
/*          CCbigguy_dtobigguy (double d)                                 */
/*          CCbigguy_ceil (CCbigguy x)                                    */
/*                                                                        */
/*  If an overflow occurs (in CCbigguy_dtobigguy, CCbigguy_ceil, or       */
/*  CCbigguy_addmult), an error message is output and the routines        */
/*  abort.                                                                */
/*                                                                        */
/*  If  CC_BIGGUY_LONGLONG is defined, these are implemented by macros,   */
/*  and have no overflow checking.                                        */
/*                                                                        */
/**************************************************************************/

#include "machdefs.h"
#include "util.h"
#include "bigguy.h"

#ifdef  CC_BIGGUY_LONGLONG

#ifdef CC_PROTOTYPE_ANSI
int CCbigguy_swrite (CC_SFILE *f, CCbigguy x)
#else
int CCbigguy_swrite(f, x)
CC_SFILE *f;
CCbigguy x;
#endif
{
    if (CCutil_swrite_short (f, (x>>48)&0xffff)) return -1;
    if (CCutil_swrite_short (f, (x>>32)&0xffff)) return -1;
    if (CCutil_swrite_short (f, (x>>16)&0xffff)) return -1;
    if (CCutil_swrite_short (f, x&0xffff)) return -1;

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCbigguy_sread (CC_SFILE *f, CCbigguy *x)
#else
int CCbigguy_sread (f, x)
CC_SFILE *f;
CCbigguy *x;
#endif
{
    unsigned short y;

    if (CCutil_sread_short (f, &y)) return -1;
    *x = ((CCbigguy) y) << 48;
    if (CCutil_sread_short (f, &y)) return -1;
    *x |= ((CCbigguy) y) << 32;
    if (CCutil_sread_short (f, &y)) return -1;
    *x |= ((CCbigguy) y) << 16;
    if (CCutil_sread_short (f, &y)) return -1;
    *x |= ((CCbigguy) y);
    return 0;
}

#else  /* CC_BIGGUY_LONGLONG */

const CCbigguy CCbigguy_MINBIGGUY = {0x8000,0x0000,0x0000,0x0001};
const CCbigguy CCbigguy_MAXBIGGUY = {0x7fff,0xffff,0xffff,0xffff};
const CCbigguy CCbigguy_ZERO = {0,0,0,0};
const CCbigguy CCbigguy_ONE  = {0,1,0,0};

#ifdef CC_PROTOTYPE_ANSI

static void
    bigguy_neg (CCbigguy *x);

#else

static void
    bigguy_neg ();

#endif

#ifdef CC_PROTOTYPE_ANSI
static void bigguy_neg (CCbigguy *x)
#else
static void bigguy_neg (x)
CCbigguy *x;
#endif
{
    x->ihi = ((unsigned short) 65535) - x->ihi;
    x->ilo = ((unsigned short) 65535) - x->ilo;
    x->fhi = ((unsigned short) 65535) - x->fhi;
    x->flo = ((unsigned short) 65535) - x->flo;

    if (x->flo < 65535) {
        x->flo++;
    } else {
        x->flo = 0;
        if (x->fhi < 65535) {
            x->fhi++;
        } else {
            x->fhi = 0;
            if (x->ilo < 65535) {
                x->ilo++;
            } else {
                x->ilo = 0;
                x->ihi++;
            }
        }
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCbigguy_swrite (CC_SFILE *f, CCbigguy x)
#else
int CCbigguy_swrite (f, x)
CC_SFILE *f;
CCbigguy x;
#endif
{
    if (CCutil_swrite_short (f, x.ihi)) return -1;
    if (CCutil_swrite_short (f, x.ilo)) return -1;
    if (CCutil_swrite_short (f, x.fhi)) return -1;
    if (CCutil_swrite_short (f, x.flo)) return -1;

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCbigguy_sread (CC_SFILE *f, CCbigguy *x)
#else
int CCbigguy_sread (f, x)
CC_SFILE *f;
CCbigguy *x;
#endif
{
    if (CCutil_sread_short (f, &(x->ihi))) return -1;
    if (CCutil_sread_short (f, &(x->ilo))) return -1;
    if (CCutil_sread_short (f, &(x->fhi))) return -1;
    if (CCutil_sread_short (f, &(x->flo))) return -1;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
double CCbigguy_bigguytod (CCbigguy x)
#else
double CCbigguy_bigguytod (x)
CCbigguy x;
#endif
{
    int sgn = 1;

    if (x.ihi >= 32768) {
        bigguy_neg (&x);
        sgn = -1;
    }
    
    return sgn * (((double) x.ihi) * 65536.0 +
                  ((double) x.ilo) +
                  ((double) x.fhi) / 65536.0 +
                  ((double) x.flo) / (65536.0*65536.0));
}

#ifdef CC_PROTOTYPE_ANSI
CCbigguy CCbigguy_itobigguy (int d)
#else
CCbigguy CCbigguy_itobigguy (d)
int d;
#endif
{
    CCbigguy x;
    int sgn;

    if (d < 0) {
        d = -d;
        sgn = -1;
    } else {
        sgn = 1;
    }

    x.ihi = ((unsigned short) (d >> 16));
    x.ilo = ((unsigned short) (d & 0xffff));
    x.fhi = 0;
    x.flo = 0;

    if (x.ihi >= 32768) {
/*      fprintf (stderr, "OVERFLOW in CCbigguy_itobigguy\n");
        fprintf (stderr, "BIGGUY errors are fatal\n");
        abort ();
*/    }
    
    if (sgn == -1) {
        bigguy_neg (&x);
    }
    return x;
}

#ifdef CC_PROTOTYPE_ANSI
CCbigguy CCbigguy_dtobigguy (double d)
#else
CCbigguy CCbigguy_dtobigguy (d)
double d;
#endif
{
    CCbigguy x;
    int sgn;

    if (d < 0.0) {
        d = -d;
        sgn = -1;
    } else {
        sgn = 1;
    }

    if (d / 65536.0 >= 32768.0) {
/*      fprintf (stderr, "OVERFLOW in CCbigguy_dtobigguy (%.6f)\n", d * sgn);
        fprintf (stderr, "BIGGUY errors are fatal\n");
        abort ();
*/    }
    
    x.ihi = ((unsigned short) (d / 65536.0));
    d -= ((double) x.ihi) * 65536.0;
    x.ilo = ((unsigned short) d);
    d -= ((double) x.ilo);
    x.fhi = ((unsigned short) (d * 65536.0));
    d -= ((double) x.fhi) / 65536.0;
    x.flo = ((unsigned short) (d * 65536.0 * 65536.0));

    if (sgn == -1) {
        bigguy_neg (&x);
    }

    return x;
}

#ifdef CC_PROTOTYPE_ANSI
CCbigguy CCbigguy_ceil (CCbigguy x)
#else
CCbigguy CCbigguy_ceil (x)
CCbigguy x;
#endif
{
    if (x.fhi || x.flo) {
        x.fhi = 0;
        x.flo = 0;
        x.ilo++;
        if (x.ilo == 0) {
            if (x.ihi == 32767) {
/*              fprintf (stderr, "OVERFLOW in CCbigguy_ceil\n");
                fprintf (stderr, "BIGGUY errors are fatal\n");
                abort ();
*/          }
            x.ihi++;
        }
    }

    return x;
}

#ifdef CC_PROTOTYPE_ANSI
int CCbigguy_cmp (CCbigguy x, CCbigguy y)
#else
int CCbigguy_cmp (x, y)
CCbigguy x;
CCbigguy y;
#endif
{
    if (x.ihi >= 32768 && y.ihi < 32768) return -1;
    else if (x.ihi < 32768 && y.ihi >= 32768) return 1;
    else if (x.ihi < y.ihi) return -1;
    else if (x.ihi > y.ihi) return 1;
    else if (x.ilo < y.ilo) return -1;
    else if (x.ilo > y.ilo) return 1;
    else if (x.fhi < y.fhi) return -1;
    else if (x.fhi > y.fhi) return 1;
    else if (x.flo < y.flo) return -1;
    else if (x.flo > y.flo) return 1;
    else return 0;
}

#ifdef CC_PROTOTYPE_ANSI
void CCbigguy_addmult (CCbigguy *x, CCbigguy y, short m)
#else
void CCbigguy_addmult (x, y, m)
CCbigguy *x;
CCbigguy y;
short m;
#endif
{
    int carry = 0;
    int sgn = 1;

    if (m == -32768) {
/*      fprintf (stderr, "OVERFLOW in CCbigguy_addmult\n");
        fprintf (stderr, "BIGGUY errors are fatal\n");
        abort ();
*/    }
    
    if (y.ihi >= 32768) {
        bigguy_neg (&y);
        m = -m;
    }

    if (x->ihi >= 32768) {
        bigguy_neg (x);
        m = -m;
        sgn = -1;
    }

    carry = x->flo + m * y.flo;
    x->flo = carry & ((unsigned short) 0xffff);
    carry -= x->flo;
    carry /= 65536;
    carry = carry + x->fhi + m * y.fhi;
    x->fhi = carry & ((unsigned short) 0xffff);
    carry -= x->fhi;
    carry /= 65536;
    carry = carry + x->ilo + m * y.ilo;
    x->ilo = carry & ((unsigned short) 0xffff);
    carry -= x->ilo;
    carry /= 65536;
    carry = carry + x->ihi + m * y.ihi;
    x->ihi = carry & ((unsigned short) 0xffff);
    carry -= x->ihi;
    carry /= 65536;

    if (carry < -1 || carry > 0 ||
        (carry == -1 && x->ihi < 32768) ||
        (carry == 0 && x->ihi >= 32768)) {
/*      fprintf (stderr, "OVERFLOW in CCbigguy_addmult\n");
        fprintf (stderr, "BIGGUY errors are fatal\n");
        abort ();
*/    }

    if (sgn == -1) {
        bigguy_neg (x);
    }
}

#endif /* CC_BIGGUY_LONGLONG */
