#ifndef _GL2YUV_H_
#define _GL2YUV_H_

/*
 * GL2YUV, an OpenGL to YUV Printing Library
 * Copyright (C) 1999-2002  Christophe Geuzaine 
 *
 * $Id: gl2yuv.h,v 1.2 2002-05-18 07:18:02 geuzaine Exp $
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

void create_yuv(FILE *outfile, int width, int height);

#endif
