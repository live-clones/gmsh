#ifndef __XCUTPOOL_H
#define __XCUTPOOL_H

typedef struct Xportablecut {
    int nhandles;
    int *handles;  /* each handle terminated with a -1 */
    int nteeth;
    int *teeth;    /* each tooth  terminated with a -1 */
} Xportablecut;

typedef struct Xportableclique {
    int size;
    int *nodes;
    double cutval;
} Xportableclique;

#endif /* __XCUTPOOL_H */
