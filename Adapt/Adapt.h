/* $Id: Adapt.h,v 1.3 2000-11-23 23:20:34 geuzaine Exp $ */
#ifndef _ADAPT_H_
#define _ADAPT_H_

#define ADAPT_P1 1
#define ADAPT_P2 2
#define ADAPT_H1 3
#define ADAPT_H2 4

double AdaptMesh (int N,        /* Number of elements */
		  int method,   /* ADAPT_H1, ADAPT_H2, ADAPT_P1 or ADAPT_P2 */
		  int dim,      /* 2 or 3 */
		  double *err,  /* elementary errors */
		  double *h,    /* elementary mesh sizes */
		  double *p,    /* elementary exponents */
		  double e0     /* prescribed error or number of elements */);

#endif
