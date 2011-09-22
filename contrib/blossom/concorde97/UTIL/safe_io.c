/***************************************************************************/
/*                                                                         */
/*                    INPUT/OUTPUT ROUTINES                                */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/* Written by:  Applegate, Bixby, Chvatal, and Cook                        */
/* Date: February 13, 1995                                                 */
/*                                                                         */
/* EXPORTED FUNCTIONS:                                                     */
/*                                                                         */
/* CC_SFILE                                                                */
/*     *CCutil_sopen (char *f, char *s),                                   */
/*     *CCutil_sdopen (int d, char *s);                                    */
/* int                                                                     */
/*    CCutil_swrite (CC_SFILE *f, unsigned char *buf, int size),           */
/*    CCutil_swrite_bits (CC_SFILE *f, unsigned int x, int xbits),         */
/*    CCutil_swrite_char (CC_SFILE *f, unsigned char x),                   */
/*    CCutil_swrite_string (CC_SFILE *f, unsigned char *s)                 */
/*    CCutil_swrite_short (CC_SFILE *f, unsigned short x),                 */
/*    CCutil_swrite_int (CC_SFILE *f, unsigned int x),                     */
/*    CCutil_swrite_double (CC_SFILE *f, double x),                        */
/*    CCutil_sread (CC_SFILE *f, unsigned char *buf, int size),            */
/*    CCutil_sread_bits (CC_SFILE *f, unsigned int x, int xbits),          */
/*    CCutil_sread_char (CC_SFILE *f, unsigned char *x),                   */
/*    CCutil_sread_string (CC_SFILE *f, unsigned char *x, int maxlen)      */
/*    CCutil_sread_short (CC_SFILE *f, unsigned short *x),                 */
/*    CCutil_sread_short_r (CC_SFILE *f, unsigned short *x),               */
/*    CCutil_sread_int (CC_SFILE *f, unsigned int *x),                     */
/*    CCutil_sread_int_r (CC_SFILE *f, unsigned int *x),                   */
/*    CCutil_sread_double (CC_SFILE *f, double *x),                        */
/*    CCutil_sread_double_r (CC_SFILE *f, double *x),                      */
/*    CCutil_sflush (CC_SFILE *f),                                         */
/*    CCutil_stell (CC_SFILE *f),                                          */
/*    CCutil_sseek (CC_SFILE *f, int offset),                              */
/*    CCutil_srewind (CC_SFILE *f),                                        */
/*    CCutil_sclose (CC_SFILE *f),                                         */
/*    CCutil_sbits (unsigned int x),                                       */
/*    CCutil_sdelete_file (char *f),                                       */
/*    CCutil_sdelete_file_backup (char *f)                                 */
/*                                                                         */
/*  This routines provide buffered binary I/O.  The routines sopen,        */
/*  sdopen, swrite, sread, sflush, stell, sseek, srewind, and sclose       */
/*  resemble the stdio routines fopen, fdopen, fwrite, fread, fflush,      */
/*  ftell, fseek, rewind, and fclose.  swrite_{char,short,int,double}      */
/*  and sread_{char,short,int,double} provide a somewhat machine           */
/*  independent binary I/O mechanism.  sread_{short,int,double}_r read     */
/*  the values in reverse order, and are provided for compatibility        */
/*  reasons.  sread_bits and swrite_bits write variable-length bit         */
/*  strings.  sbits can be used to compute the number of bits necessary    */
/*  to represent a number.  The variable-length bit strings are padded     */
/*  to a byte boundary when one of the other read/write routines, flush,   */
/*  tell, seek, rewind, or close are called.                               */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"

#ifndef SEEK_SET
#ifdef L_SET
#define SEEK_SET L_SET
#else
#define SEEK_SET 0
#endif
#endif

#ifdef CC_PROTOTYPE_ANSI

static CC_SFILE
    *sopen_write (char *f),
    *sdopen_write (int t),
    *sopen_read (char *f),
    *sdopen_read (int t);

static int
    swrite_buffer (CC_SFILE *f),
    sread_buffer (CC_SFILE *f);

static void
    sinit (CC_SFILE *s);

#else

static CC_SFILE
    *sopen_write (),
    *sdopen_write (),
    *sopen_read (),
    *sdopen_read ();

static int
    swrite_buffer (),
    sread_buffer ();

static void
    sinit ();

#endif


/* VERSION A3 */

/* sopen interprets filenames "stdin" as descriptor 0, "stdout" as
 * descriptor 1, and "stderr" as descriptor 2.  "-" is interpreted as
 * 0 or 1, depending on whether the file is opened for reading or writing.
 *
 * sclose doesn't close descriptors 0, 1, and 2.
 */

/* When writing, written data extends from buffer[0] bit 7 through
 * buffer[chars_in_buffer-1] bit bits_in_last_char.  Empty space extends
 * from buffer[chars_in_buffer-1] bit bits_in_last_char-1 through
 * buffer[CC_SBUFFER_SIZE-1] bit 0.
 *
 * When reading, read data extends from buffer[0] bit 7 through
 * buffer[current_buffer_char] bit bits_in_last_char.  unread data
 * extends from buffer[current_buffer_char] bit bits_in_last_char-1
 * through buffer[chars_in_buffer-1] bit 0.  Empty space extends from
 * buffer[chars_in_buffer] bit 7 through buffer[CC_SBUFFER_SIZE-1] bit 0.
 */

/* If the routines detect an error, they return -1.
 */

#define SREAD 1
#define SWRITE 2

#define NBITMASK(n) ((1<<(n))-1)
#define BITRANGE(x,start,length) (((x) >> (start)) & NBITMASK(length))
#define BITS_PER_CHAR (8)

#ifndef O_BINARY
#define O_BINARY 0
#endif
#ifndef O_EXCL
#define O_EXCL 0
#endif

#ifdef CC_PROTOTYPE_ANSI
CC_SFILE *CCutil_sopen (char *f, char *s)
#else
CC_SFILE *CCutil_sopen (f, s)
char *f;
char *s;
#endif
{
    if (s[0] == 'r' || s[0] == 'R') {
        return sopen_read (f);
    } else if (s[0] == 'w' || s[0] == 'W') {
        return sopen_write (f);
    } else {
        fprintf (stderr, "Need to specify read/write in sopen\n");
        return (CC_SFILE *) NULL;
    }
}

#ifdef CC_PROTOTYPE_ANSI
CC_SFILE *CCutil_sdopen (int d, char *s)
#else
CC_SFILE *CCutil_sdopen (d, s)
int d;
char *s;
#endif
{
    if (s[0] == 'r' || s[0] == 'R') {
        return sdopen_read (d);
    } else if (s[0] == 'w' || s[0] == 'W') {
        return sdopen_write (d);
    } else {
        fprintf (stderr, "Need to specify read/write in sopen\n");
        return (CC_SFILE *) NULL;
    }
}

#ifdef CC_PROTOTYPE_ANSI
static CC_SFILE *sopen_write (char *f)
#else
static CC_SFILE *sopen_write (f)
char *f;
#endif
{
    CC_SFILE *s = (CC_SFILE *) NULL;
    int t;
    char fbuf[CC_SFNAME_SIZE];
    char fbuf_N[CC_SFNAME_SIZE + 32];
    char fbuf_Nx[CC_SFNAME_SIZE + 64];

    strncpy (fbuf, f, sizeof (fbuf) - 12);
    fbuf[sizeof (fbuf) - 12] = '\0';
    sprintf (fbuf_N, "N%s", fbuf);
    sprintf (fbuf_Nx, "N%s~", fbuf);


    if (!strcmp (f, "stdout") || !strcmp (f, "-")) {
        s = sdopen_write (1);
    } else if (!strcmp (f, "stderr")) {
        s = sdopen_write (2);
    } else {
        t = open (fbuf_N, O_WRONLY | O_CREAT | O_BINARY | O_EXCL, 0644);
        if (t == -1 && errno == EEXIST) {
            fprintf (stderr, "%s already exists, renaming to %s\n",
                          fbuf_N, fbuf_Nx);
            if (rename (fbuf_N, fbuf_Nx)) {
                perror (fbuf_Nx);
                fprintf (stderr, "Couldn't rename %s to %s\n", fbuf_N,
                         fbuf_Nx);
                return (CC_SFILE *) NULL;
            }
            t = open (fbuf_N, O_WRONLY | O_CREAT | O_BINARY | O_EXCL, 0644);
        }
        if (t == -1) {
            perror (fbuf_N);
            fprintf (stderr, "Couldn't open %s for output\n", fbuf_N);
            return (CC_SFILE *) NULL;
        }
        s = sdopen_write (t);
        if (!s) {
            close (t);
        }
    }
    if (s) {
        strncpy (s->fname, fbuf, sizeof (s->fname));
        s->fname[sizeof (s->fname)-1] = '\0';
    }
    return s;
}

#ifdef CC_PROTOTYPE_ANSI
static CC_SFILE *sdopen_write (int t)
#else
static CC_SFILE *sdopen_write (t)
int t;
#endif
{
    CC_SFILE *s = (CC_SFILE *) NULL;

    if (t < 0) {
        fprintf (stderr, "Invalid descriptor %d\n", t);
        return (CC_SFILE *) NULL;
    }

    s = CC_SAFE_MALLOC (1, CC_SFILE);
    if (s == (CC_SFILE *) NULL) {
        return s;
    }
    sinit (s);

    s->status = SWRITE;
    s->desc = t;
    sprintf (s->fname, "descriptor %d", t);
    return s;
}

#ifdef CC_PROTOTYPE_ANSI
static CC_SFILE *sopen_read (char *f)
#else
static CC_SFILE *sopen_read (f)
char *f;
#endif
{
    CC_SFILE *s = (CC_SFILE *) NULL;
    int t;

    if (!strcmp (f, "stdin") || !strcmp (f, "-")) {
        s = sdopen_read (0);
    } else {
        t = open (f, O_RDONLY | O_BINARY, 0644);
        if (t == -1) {
            perror (f);
            fprintf (stderr, "Couldn't open for input\n");
            s = (CC_SFILE *) NULL;
        }
        s = sdopen_read (t);
        if (!s) {
            close (t);
        }
    }
    if (s) {
        strncpy (s->fname, f, sizeof (s->fname));
        s->fname[sizeof (s->fname)-1] = '\0';
    }
    return s;
}

#ifdef CC_PROTOTYPE_ANSI
static CC_SFILE *sdopen_read (int t)
#else
static CC_SFILE *sdopen_read (t)
int t;
#endif
{
    CC_SFILE *s = (CC_SFILE *) NULL;

    if (t < 0) {
        fprintf (stderr, "Invalid descriptor %d\n", t);
        return (CC_SFILE *) NULL;
    }

    s = CC_SAFE_MALLOC (1, CC_SFILE);
    if (s == (CC_SFILE *) NULL) {
        return s;
    }
    sinit (s);

    s->status = SREAD;
    s->desc = t;
    sprintf (s->fname, "descriptor %d", t);
    return s;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_swrite (CC_SFILE *f, unsigned char *buf, int size)
#else
int CCutil_swrite (f, buf, size)
CC_SFILE *f;
unsigned char *buf;
int size;
#endif
{
    int i;

    for (i=0; i<size; i++) {
        if (CCutil_swrite_char (f, buf[i])) return -1;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_swrite_bits (CC_SFILE *f, unsigned int x, int xbits)
#else
int CCutil_swrite_bits (f, x, xbits)
CC_SFILE *f;
unsigned int x;
int xbits;
#endif
{
    int getbits;
    unsigned int v;

    if (!f) return -1;
    if (f->status != SWRITE) {
        fprintf (stderr, "%s not open for output\n", f->fname);
        return -1;
    }
    while (xbits) {
        if (f->bits_in_last_char == 0) {
            if (f->chars_in_buffer == CC_SBUFFER_SIZE) {
                if (swrite_buffer (f)) return -1;
            }
            f->buffer[f->chars_in_buffer++] = 0;
            f->bits_in_last_char = BITS_PER_CHAR;
        }
        getbits = f->bits_in_last_char;
        if (getbits > xbits)
            getbits = xbits;
        xbits -= getbits;
        f->bits_in_last_char -= getbits;
        v = BITRANGE (x, xbits, getbits);
        f->buffer[f->chars_in_buffer - 1] |=
            v << f->bits_in_last_char;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_swrite_char (CC_SFILE *f, unsigned char x)
#else
int CCutil_swrite_char (f, x)
CC_SFILE *f;
unsigned char x;
#endif
{
    if (!f) return -1;
    if (f->status != SWRITE) {
        fprintf (stderr, "%s not open for output\n", f->fname);
        return -1;
    }

    f->bits_in_last_char = 0;
    if (f->chars_in_buffer + 1 > CC_SBUFFER_SIZE) {
        if (swrite_buffer (f)) return -1;
    }
    f->buffer[f->chars_in_buffer++] = ((unsigned int) x) & 0xff;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_swrite_string (CC_SFILE *f, unsigned char *s)
#else
int CCutil_swrite_string (f, s)
CC_SFILE *f;
unsigned char *s;
#endif
{
    int rval;

    while (*s) {
        rval = CCutil_swrite_char (f, *s);
        if (rval)
            return rval;
        s++;
    }
    CCutil_swrite_char (f, (unsigned char) 0);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_swrite_short (CC_SFILE *f, unsigned short x)
#else
int CCutil_swrite_short (f, x)
CC_SFILE *f;
unsigned short x;
#endif
{
    if (!f) return -1;
    if (f->status != SWRITE) {
        fprintf (stderr, "%s not open for output\n", f->fname);
        return -1;
    }

    f->bits_in_last_char = 0;
    if (f->chars_in_buffer + 2 > CC_SBUFFER_SIZE) {
        if (swrite_buffer (f)) return -1;
    }

    f->buffer[f->chars_in_buffer++] = (((unsigned int) x) >> 8) & 0xff;
    f->buffer[f->chars_in_buffer++] = ((unsigned int) x) & 0xff;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_swrite_int (CC_SFILE *f, unsigned int x)
#else
int CCutil_swrite_int (f, x)
CC_SFILE *f;
unsigned int x;
#endif
{
    if (!f) return -1;
    if (f->status != SWRITE) {
        fprintf (stderr, "%s not open for output\n", f->fname);
        return -1;
    }

    f->bits_in_last_char = 0;
    if (f->chars_in_buffer + 4 > CC_SBUFFER_SIZE) {
        if (swrite_buffer (f)) return -1;
    }

    f->buffer[f->chars_in_buffer++] = (((unsigned int) x) >> 24) & 0xff;
    f->buffer[f->chars_in_buffer++] = (((unsigned int) x) >> 16) & 0xff;
    f->buffer[f->chars_in_buffer++] = (((unsigned int) x) >> 8) & 0xff;
    f->buffer[f->chars_in_buffer++] = ((unsigned int) x) & 0xff;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_swrite_double (CC_SFILE *f, double x)
#else
int CCutil_swrite_double (f, x)
CC_SFILE *f;
double x;
#endif
{
    unsigned short e;
    unsigned int m1;
    unsigned int m2;

    e = 128;

    if (x < 0) {
        e += 256;
        x = -x;
    }

    if (x >= 1.0) {
#define MUNCH_HI_EXP(x,e,v,lv) if (x >= v) {e += lv; x *= 1/v;}
        MUNCH_HI_EXP(x,e,18446744073709551616.0,64);
        MUNCH_HI_EXP(x,e,4294967296.0,32);
        MUNCH_HI_EXP(x,e,65536.0, 16);
        MUNCH_HI_EXP(x,e,256.0, 8);
        MUNCH_HI_EXP(x,e,16.0, 4);
        MUNCH_HI_EXP(x,e,4.0, 2);
        MUNCH_HI_EXP(x,e,2.0, 1);
        x /= 2; e++;
    } else if (x < 0.5) {
#define MUNCH_LO_EXP(x,e,v,lv) if (x < 1/v) {e -= lv; x *= v;}
        MUNCH_LO_EXP(x,e,18446744073709551616.0,64);
        MUNCH_LO_EXP(x,e,4294967296.0,32);
        MUNCH_LO_EXP(x,e,65536.0, 16);
        MUNCH_LO_EXP(x,e,256.0, 8);
        MUNCH_LO_EXP(x,e,16.0, 4);
        MUNCH_LO_EXP(x,e,4.0, 2);
        MUNCH_LO_EXP(x,e,2.0, 1);
    }
    x *= 4294967296.0;
    m1 = (unsigned int) x;
    m2 = (unsigned int) ((x - m1) * 4294967296.0);
    if (CCutil_swrite_short (f, e)) return -1;
    if (CCutil_swrite_int (f, m1)) return -1;
    if (CCutil_swrite_int (f, m2)) return -1;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_sread (CC_SFILE *f, unsigned char *buf, int size)
#else
int CCutil_sread (f, buf, size)
CC_SFILE *f;
unsigned char *buf;
int size;
#endif
{
    int i;

    for (i=0; i<size; i++) {
        if (CCutil_sread_char (f, &buf[i])) return -1;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_sread_bits (CC_SFILE *f, unsigned int *x, int xbits)
#else
int CCutil_sread_bits (f, x, xbits)
CC_SFILE *f;
unsigned int *x;
int xbits;
#endif
{
    int getbits;
    unsigned int v;

    if (!f) return -1;
    if (f->status != SREAD) {
        fprintf (stderr, "%s not open for input\n", f->fname);
        return -1;
    }
    *x = 0;
    while (xbits) {
        if (f->bits_in_last_char == 0) {
            if (f->current_buffer_char + 1 == f->chars_in_buffer) {
                if (sread_buffer (f)) return -1;
            }
            f->current_buffer_char++;
            f->bits_in_last_char = BITS_PER_CHAR;
        }
        getbits = f->bits_in_last_char;
        if (getbits > xbits)
            getbits = xbits;
        f->bits_in_last_char -= getbits;
        xbits -= getbits;
        v = BITRANGE ((unsigned int) f->buffer[f->current_buffer_char],
                      f->bits_in_last_char, getbits);
        *x |= v << xbits;
    }
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_sread_char (CC_SFILE *f, unsigned char *x)
#else
int CCutil_sread_char (f, x)
CC_SFILE *f;
unsigned char *x;
#endif
{
    if (!f) return -1;
    if (f->status != SREAD) {
        fprintf (stderr, "%s not open for input\n", f->fname);
        return -1;
    }
    f->bits_in_last_char = 0;
    if (f->current_buffer_char + 1 == f->chars_in_buffer) {
        if (sread_buffer (f)) return -1;
    }
    *x = ((unsigned char) f->buffer[++f->current_buffer_char]);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_sread_string (CC_SFILE *f, unsigned char *x, int maxlen)
#else
int CCutil_sread_string (f, x, maxlen)
CC_SFILE *f;
unsigned char *x;
int maxlen;
#endif
{
    int i, rval;

    maxlen--;
    for (i = 0; i < maxlen;  i++, x++) {
        rval = CCutil_sread_char (f, x);
        if (rval)
            return rval;
        if (*x == 0)
            return 0;
    }
    *x = 0;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_sread_short (CC_SFILE *f, unsigned short *x)
#else
int CCutil_sread_short (f, x)
CC_SFILE *f;
unsigned short *x;
#endif
{
    if (!f) return -1;
    if (f->status != SREAD) {
        fprintf (stderr, "%s not open for input\n", f->fname);
        return -1;
    }
    f->bits_in_last_char = 0;
    if (f->current_buffer_char + 1 == f->chars_in_buffer) {
        if (sread_buffer (f)) return -1;
    }
    *x = ((unsigned short) f->buffer[++f->current_buffer_char]) << 8;
    if (f->current_buffer_char + 1 == f->chars_in_buffer) {
        if (sread_buffer (f)) return -1;
    }
    *x |= ((unsigned short) f->buffer[++f->current_buffer_char]);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_sread_short_r (CC_SFILE *f, unsigned short *x)
#else
int CCutil_sread_short_r (f, x)
CC_SFILE *f;
unsigned short *x;
#endif
{
    if (!f) return -1;
    if (f->status != SREAD) {
        fprintf (stderr, "%s not open for input\n", f->fname);
        return -1;
    }
    f->bits_in_last_char = 0;
    if (f->current_buffer_char + 1 == f->chars_in_buffer) {
        if (sread_buffer (f)) return -1;
    }
    *x = ((unsigned short) f->buffer[++f->current_buffer_char]);
    if (f->current_buffer_char + 1 == f->chars_in_buffer) {
        if (sread_buffer (f)) return -1;
    }
    *x |= ((unsigned short) f->buffer[++f->current_buffer_char]) << 8;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_sread_int (CC_SFILE *f, unsigned int *x)
#else
int CCutil_sread_int (f, x)
CC_SFILE *f;
unsigned int *x;
#endif
{
    if (!f) return -1;
    if (f->status != SREAD) {
        fprintf (stderr, "%s not open for input\n", f->fname);
        return -1;
    }
    f->bits_in_last_char = 0;
    if (f->current_buffer_char + 1 == f->chars_in_buffer) {
        if (sread_buffer (f)) return -1;
    }
    *x = ((unsigned short) f->buffer[++f->current_buffer_char]) << 24;
    if (f->current_buffer_char + 1 == f->chars_in_buffer) {
        if (sread_buffer (f)) return -1;
    }
    *x |= ((unsigned short) f->buffer[++f->current_buffer_char]) << 16;
    if (f->current_buffer_char + 1 == f->chars_in_buffer) {
        if (sread_buffer (f)) return -1;
    }
    *x |= ((unsigned short) f->buffer[++f->current_buffer_char]) << 8;
    if (f->current_buffer_char + 1 == f->chars_in_buffer) {
        if (sread_buffer (f)) return -1;
    }
    *x |= ((unsigned short) f->buffer[++f->current_buffer_char]);
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_sread_int_r (CC_SFILE *f, unsigned int *x)
#else
int CCutil_sread_int_r (f, x)
CC_SFILE *f;
unsigned int *x;
#endif
{
    if (!f) return -1;
    if (f->status != SREAD) {
        fprintf (stderr, "%s not open for input\n", f->fname);
        return -1;
    }
    f->bits_in_last_char = 0;
    if (f->current_buffer_char + 1 == f->chars_in_buffer) {
        if (sread_buffer (f)) return -1;
    }
    *x = ((unsigned short) f->buffer[++f->current_buffer_char]);
    if (f->current_buffer_char + 1 == f->chars_in_buffer) {
        if (sread_buffer (f)) return -1;
    }
    *x |= ((unsigned short) f->buffer[++f->current_buffer_char]) << 8;
    if (f->current_buffer_char + 1 == f->chars_in_buffer) {
        if (sread_buffer (f)) return -1;
    }
    *x |= ((unsigned short) f->buffer[++f->current_buffer_char]) << 16;
    if (f->current_buffer_char + 1 == f->chars_in_buffer) {
        if (sread_buffer (f)) return -1;
    }
    *x |= ((unsigned short) f->buffer[++f->current_buffer_char]) << 24;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_sread_double (CC_SFILE *f, double *x)
#else
int CCutil_sread_double (f, x)
CC_SFILE *f;
double *x;
#endif
{
    unsigned short e;
    unsigned int m1;
    unsigned int m2;

    if (CCutil_sread_short (f, &e)) return -1;
    if (CCutil_sread_int (f, &m1)) return -1;
    if (CCutil_sread_int (f, &m2)) return -1;

    *x = ((m2 / 4294967296.0) + m1) / 4294967296.0;

    if (e >= 256) {
        *x = -*x;
        e -= 256;
    }

    if (e > 128) {
#define UNMUNCH_HI_EXP(x,e,v,lv) if (e >= (unsigned short) (128 + lv)) \
                                      {e -= lv; x *= v;}
        UNMUNCH_HI_EXP(*x,e,18446744073709551616.0,64);
        UNMUNCH_HI_EXP(*x,e,4294967296.0,32);
        UNMUNCH_HI_EXP(*x,e,65536.0, 16);
        UNMUNCH_HI_EXP(*x,e,256.0, 8);
        UNMUNCH_HI_EXP(*x,e,16.0, 4);
        UNMUNCH_HI_EXP(*x,e,4.0, 2);
        UNMUNCH_HI_EXP(*x,e,2.0, 1);
    } else if (e < 128) {
#define UNMUNCH_LO_EXP(x,e,v,lv) if (e <= (unsigned short) (128 - lv)) \
                                     {e += lv; x *= 1/v;}
        UNMUNCH_LO_EXP(*x,e,18446744073709551616.0,64);
        UNMUNCH_LO_EXP(*x,e,4294967296.0,32);
        UNMUNCH_LO_EXP(*x,e,65536.0, 16);
        UNMUNCH_LO_EXP(*x,e,256.0, 8);
        UNMUNCH_LO_EXP(*x,e,16.0, 4);
        UNMUNCH_LO_EXP(*x,e,4.0, 2);
        UNMUNCH_LO_EXP(*x,e,2.0, 1);
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_sread_double_r (CC_SFILE *f, double *x)
#else
int CCutil_sread_double_r (f, x)
CC_SFILE *f;
double *x;
#endif
{
    unsigned short e;
    unsigned int m1;
    unsigned int m2;

    if (CCutil_sread_short_r (f, &e)) return -1;
    if (CCutil_sread_int_r (f, &m1)) return -1;
    if (CCutil_sread_int_r (f, &m2)) return -1;

    *x = ((m2 / 4294967296.0) + m1) / 4294967296.0;

    if (e >= 256) {
        *x = -*x;
        e -= 256;
    }

    if (e > 128) {
#define UNMUNCH_HI_EXP(x,e,v,lv) if (e >= (unsigned short) (128 + lv)) \
                                     {e -= lv; x *= v;}
        UNMUNCH_HI_EXP(*x,e,18446744073709551616.0,64);
        UNMUNCH_HI_EXP(*x,e,4294967296.0,32);
        UNMUNCH_HI_EXP(*x,e,65536.0, 16);
        UNMUNCH_HI_EXP(*x,e,256.0, 8);
        UNMUNCH_HI_EXP(*x,e,16.0, 4);
        UNMUNCH_HI_EXP(*x,e,4.0, 2);
        UNMUNCH_HI_EXP(*x,e,2.0, 1);
    } else if (e < 128) {
#define UNMUNCH_LO_EXP(x,e,v,lv) if (e <= (unsigned short) (128 - lv)) \
                                      {e += lv; x *= 1/v;}
        UNMUNCH_LO_EXP(*x,e,18446744073709551616.0,64);
        UNMUNCH_LO_EXP(*x,e,4294967296.0,32);
        UNMUNCH_LO_EXP(*x,e,65536.0, 16);
        UNMUNCH_LO_EXP(*x,e,256.0, 8);
        UNMUNCH_LO_EXP(*x,e,16.0, 4);
        UNMUNCH_LO_EXP(*x,e,4.0, 2);
        UNMUNCH_LO_EXP(*x,e,2.0, 1);
    }

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_sflush (CC_SFILE *f)
#else
int CCutil_sflush (f)
CC_SFILE *f;
#endif
{
    if (!f) return -1;
    if (f->status == SREAD) {
        f->bits_in_last_char = 0;
        return 0;
    } else if (f->status == SWRITE) {
        return swrite_buffer (f);
    } else {
        fprintf (stderr, "Buffer %s has invalid status %d\n", f->fname,
                 f->status);
        return -1;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_stell (CC_SFILE *f)
#else
int CCutil_stell (f)
CC_SFILE *f;
#endif
{
    if (!f) return -1;
    f->bits_in_last_char = 0;
    if (f->status == SREAD) {
        return f->pos - f->chars_in_buffer + f->current_buffer_char + 1;
    } else if (f->status == SWRITE) {
        return f->pos + f->chars_in_buffer;
    } else {
        fprintf (stderr, "Buffer %s has invalid status %d\n", f->fname,
                 f->status);
        return -1;
    }
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_sseek (CC_SFILE *f, int offset)
#else
int CCutil_sseek (f, offset)
CC_SFILE *f;
int offset;
#endif
{
    int curloc;

    if (!f) return -1;
    if (CCutil_sflush (f)) return -1;
    curloc = CCutil_stell (f);
    if (curloc < 0) return curloc;
    if (curloc == offset) return 0;
    if (lseek (f->desc, offset, SEEK_SET) < 0) {
        perror (f->fname);
        fprintf (stderr, "Unable to lseek on %s\n", f->fname);
        return -1;
    }
    f->chars_in_buffer = 0;
    f->current_buffer_char = -1;
    f->pos = offset;

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_srewind (CC_SFILE *f)
#else
int CCutil_srewind (f)
CC_SFILE *f;
#endif
{
    return CCutil_sseek (f, 0);
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_sclose (CC_SFILE *f)
#else
int CCutil_sclose (f)
CC_SFILE *f;
#endif
{
    int retval = 0;
    char fbuf_O[CC_SFNAME_SIZE + 32];
    char fbuf_N[CC_SFNAME_SIZE + 32];

    if (!f) return -1;

    if (f->status == SWRITE && f->chars_in_buffer) {
        if (swrite_buffer (f)) retval = -1;
    }

    if (f->desc >= 3) {
        if (close (f->desc)) {
            perror ("close");
            fprintf (stderr, "Unable to close swrite file %s\n", f->fname);
            retval = -1;
        }
        if (f->status == SWRITE) {
            sprintf (fbuf_N, "N%s", f->fname);
            sprintf (fbuf_O, "O%s", f->fname);
            rename (f->fname, fbuf_O);
            if (rename (fbuf_N, f->fname)) {
                perror (f->fname);
                fprintf (stderr, "Couldn't rename %s to %s\n",
                                               fbuf_N, f->fname);
                retval = -1;
            }
        }
    }

    CC_FREE (f, CC_SFILE);

    return retval;
}

#ifdef CC_PROTOTYPE_ANSI
static int swrite_buffer (CC_SFILE *f)
#else
static int swrite_buffer (f)
CC_SFILE *f;
#endif
{
    char *p;
    int nleft;
    int n;

    if (!f) return -1;
    if (f->status != SWRITE) {
        fprintf (stderr, "%s not open for output\n", f->fname);
        return -1;
    }
    p = (char *) f->buffer;
    nleft = f->chars_in_buffer;
    while (nleft) {
        n = write (f->desc, p, nleft);
        if (n == -1) {
            if (errno == EINTR) {
                fprintf (stderr, "swrite interrupted, retrying\n");
                continue;
            }
            perror ("write");
            fprintf (stderr, "swrite of %d chars to %s failed\n", nleft,
                     f->fname);
            return -1;
        }
        nleft -= n;
        p += n;
        f->pos += n;
    }
    f->bits_in_last_char = 0;
    f->chars_in_buffer = 0;
    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static int sread_buffer (CC_SFILE *f)
#else
static int sread_buffer (f)
CC_SFILE *f;
#endif
{
    int n;

    if (!f) return -1;
    if (f->status != SREAD) {
        fprintf (stderr, "%s not open for input\n", f->fname);
        return -1;
    }
    if (f->current_buffer_char + 1 == f->chars_in_buffer) {
        f->chars_in_buffer = 0;
        f->current_buffer_char = -1;
    }
    if (f->chars_in_buffer == CC_SBUFFER_SIZE) {
        fprintf (stderr, "sread_buffer for %s when buffer full\n", f->fname);
        return 0;
    }

retry:
    n = read (f->desc, (char *) f->buffer + f->chars_in_buffer,
              CC_SBUFFER_SIZE - f->chars_in_buffer);

    if (n == -1) {
        if (errno == EINTR) {
            fprintf (stderr, "sread interrupted, retrying\n");
            goto retry;
        }
        perror ("read");
        fprintf (stderr, "sread failed\n");
        return -1;
    }
    if (n == 0) {
        fprintf (stderr, "sread encountered EOF\n");
        return -1;
    }
    f->pos += n;
    f->chars_in_buffer += n;

    return 0;
}

#ifdef CC_PROTOTYPE_ANSI
static void sinit (CC_SFILE *s)
#else
static void sinit (s)
CC_SFILE *s;
#endif
{
    s->status = 0;
    s->desc = -1;
    s->chars_in_buffer = 0;
    s->current_buffer_char = -1;
    s->bits_in_last_char = 0;
    s->pos = 0;
    s->fname[0] = '\0';
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_sbits (unsigned int x)
#else
int CCutil_sbits (x)
unsigned int x;
#endif
{
    int i;
    int ux = x;
    unsigned int b;

    i = 32;
    b = ((unsigned int) 1) << 31;
    while ((ux & b) == 0 && i > 1) {
        b >>= 1;
        i--;
    }
    return i;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_sdelete_file (char *fname)
#else
int CCutil_sdelete_file (fname)
char *fname;
#endif
{
    int rval;

    rval = unlink (fname);
    if (rval) {
        perror (fname);
        fprintf (stderr, "unlink: could not delete %s\n", fname);
    }
    return rval;
}

#ifdef CC_PROTOTYPE_ANSI
int CCutil_sdelete_file_backup (char *fname)
#else
int CCutil_sdelete_file_backup (fname)
char *fname;
#endif
{
    int rval;
    char fbuf_O[CC_SFNAME_SIZE + 32];

    sprintf (fbuf_O, "O%s", fname);
    rval = unlink (fbuf_O);

    return rval;
}
