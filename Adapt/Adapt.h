/* $Id: Adapt.h,v 1.2 2000-11-23 14:11:24 geuzaine Exp $ */
#ifndef _ADAPT_H_
#define _ADAPT_H_

#define ADAPT_P1 1
#define ADAPT_P2 2
#define ADAPT_H1 3
#define ADAPT_H2 4

double optimesh (
		 int N,        /* Nombre d'elements a traiter        */
		 int method,   /* H1 , P1 , H2 ou P2                 */
		 int dim,      /* 2 pour 2D et 3 pour 3D             */
		 double *err,  /* erreurs elementaires               */
		 double *h,    /* tailles de mailles elementaires    */
		 double *p,    /* exposante elementaires             */
		 double e0,    /* erreur prescrite par l'utilisateur */
		 double N0     /* nbre d'elements ds le maillage opt */
		 );

#endif
