#ifndef _CONSTS_H_
#define _CONSTS_H_

//#define RAND_LONG    LC * ((rand()%1000)/1.E08)
//#define RAND_LONG    LC * ((rand()%1000)/1.E08)/10.

//RAND_LONG in [0, LC/1.e6]
#define RAND_LONG    (LC/1.e6*rand()/RAND_MAX)

//EPSILON_LONG in [0, LC/1.e12]
#define EPSILON_LC   (LC/1.e12*rand()/RAND_MAX)

#define RADTODEG      57.29578

#define TEXT_BUFFER_SIZE       1024
#define SELECTION_BUFFER_SIZE  1024
#define LABEL_STR_L            16
#define NAME_STR_L             256
#define MAX_OPEN_FILES         20

#define RacineDeDeux  1.41421356237
#define RacineDeTrois 1.73205080757
#define Pi            3.14159265359
#define Deux_Pi       6.28318530718
#define UnTiers       0.33333333333

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)<(b))?(b):(a))
#define SQR(a)   (((a)==0.0)?0.0:((a)*(a)))

#define IMIN MIN
#define LMIN MIN
#define FMIN MIN
#define DMIN MIN

#define IMAX MAX
#define LMAX MAX
#define FMAX MAX
#define DMAX MAX

#define DSQR SQR
#define FSQR SQU

#define THRESHOLD(a,b,c) (((a)>(c))?(c):((a)<(b)?(b):(a)))

#define myhypot(a,b) (sqrt((a)*(a)+(b)*(b)))

#define sign(x)   (((x)>=0)?1:-1)
#define Pred(x)   ((x)->prev)
#define Succ(x)   ((x)->next)
#define square(x) ((x)*(x))

#endif
