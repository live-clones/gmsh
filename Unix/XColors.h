/* $Id: XColors.h,v 1.2 2000-11-23 14:11:41 geuzaine Exp $ */
#ifndef _XCOLORS_H_
#define _XCOLORS_H_

void XColorInitialize(void);
unsigned long AllocateColorInt( int r, int g, int b );
unsigned long AllocateColor( float red, float green, float blue );

#endif

