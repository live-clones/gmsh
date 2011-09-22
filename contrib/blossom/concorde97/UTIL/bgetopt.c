/***************************************************************************/
/*                                                                         */
/*                        PORTABLE GETOPT                                  */
/*                                                                         */
/*                           TSP CODE                                      */
/*                                                                         */
/*                                                                         */
/*  Written by:  Applegate, Bixby, Chvatal, and Cook                       */
/*  Date: 1993 (?) (fmfeb02)                                               */
/*  Modified: 15 February 1995 (bico)  - added warning                     */
/*                                                                         */
/*  EXPORTED FUNCTIONS:  Parses command-line strings                       */
/*    int CCutil_bix_getopt (int ac, char **av, char *def)                 */
/*                                                                         */
/***************************************************************************/

#include "machdefs.h"
#include "util.h"

int CCutil_bix_optind = 1;
char *CCutil_bix_optarg = (char *) NULL;

#ifdef CC_PROTOTYPE_ANSI
int CCutil_bix_getopt (int ac, char **av, char *def)
#else
int CCutil_bix_getopt (ac, av, def)
int ac;
char **av;
char *def;
#endif
{
    int c;
    char *sp = av[CCutil_bix_optind];
    char bwarn[2];

    if (CCutil_bix_optind < 1 || CCutil_bix_optind >= ac) {
        CCutil_bix_optind = ac;
        return (EOF);
    }
    if ((int) *sp != (int) '-')
        return (EOF);
    if ((int) *(sp + 1) == (int) '-') {
        CCutil_bix_optind++;
        return (EOF);
    }
    (av[CCutil_bix_optind])++;
    sp++;
    while ((int) *sp != (int) *def && (int) *def != (int) '\0')
            def++;
    if ((int) *def == (int) '\0') {
        CCutil_bix_optind = ac;
        bwarn[0] = *sp;                          /* Bico: February 8, 1995 */
        bwarn[1] = '\0';
        printf ("Illegal option: -%s\n", bwarn);
        return CC_BIX_GETOPT_UNKNOWN;
    }
    if ((int) *(def + 1) != (int) ':') {
        c = *sp;
        if ((int) *(sp + 1) != (int) '\0')
            *sp = '-';
        else
            CCutil_bix_optind++;
        return (c);
    } else {
        if ((int) *(sp + 1) != (int) '\0') {
            CCutil_bix_optarg = sp + 1;
            c = *sp;
            CCutil_bix_optind++;
            return (c);
        } else if (CCutil_bix_optind >= ac - 1) {
            CCutil_bix_optind = ac;
            return (EOF);
        } else {
            CCutil_bix_optarg = av[CCutil_bix_optind + 1];
            c = *sp;
            CCutil_bix_optind += 2;
            return (c);
        }
    }
}
