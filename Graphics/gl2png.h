#ifndef _GL2PNG_H_
#define _GL2PNG_H_

/*
 * GL2PNG, an OpenGL to PNG Printing Library
 * Copyright (C) 2003 Christophe Geuzaine 
 *
 * $Id: gl2png.h,v 1.2 2003-04-02 06:02:01 geuzaine Exp $
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

#include <stdio.h>

void create_png(FILE *outfile, int width, int height, int quality);

#endif
