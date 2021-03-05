// All libOL code is Copyright 2012-2018 - by Loïc Maréchal / INRIA.
// This program is a free software.
// You can redistribute it and/or modify it under the terms of the MIT License
// as published by the Open Source Initiative.
//  
// This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the MIT License for more details.
//  
// You should have received a copy of the MIT License along with this program
// as the file LICENSE.txt; if not, please see:
// https://opensource.org/licenses/MIT
//
//
// MIT License
// 
// Copyright (c) 2012-2018 Loïc Maréchal / INRIA
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                      LIB OCTREE LOCALISATION V1.70                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Description:         Octree for mesh localization                       */
/*    Author:              Loic MARECHAL                                      */
/*    Creation date:       mar 16 2012                                        */
/*    Last modification:   feb 03 2021                                        */
/*                                                                            */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Public defines : type of elements and 32/64 bits int and floating points   */
/*----------------------------------------------------------------------------*/

enum TypTag {  LolTypVer=1, LolTypEdg, LolTypTri, LolTypQad,
               LolTypTet,   LolTypPyr, LolTypPri, LolTypHex, LolNmbTyp };


/*----------------------------------------------------------------------------*/
/* Set integer and floating point sizes:                                      */
/* default values are 32-bit integers and 64-bit floating points              */
/* define INT64 or REAL32 to override default settings                        */
/*----------------------------------------------------------------------------*/

#ifdef INT64
#define itg int64_t
#define utg uint64_t
#else
#define itg int32_t
#define utg uint32_t
#endif

#ifdef REAL32
#define fpn float
#else
#define fpn double
#endif


/*----------------------------------------------------------------------------*/
/* Public procedures                                                          */
/*----------------------------------------------------------------------------*/

int64_t LolNewOctree       (itg, fpn *, fpn *, itg, itg *, itg *,
                            itg, itg *, itg *, itg, itg *, itg *,
                            itg, itg *, itg *, itg, itg *, itg *,
                            itg, itg *, itg *, itg, itg *, itg *, itg, itg);
size_t  LolFreeOctree      (int64_t);
itg     LolGetBoundingBox  (int64_t , itg , itg, itg *, fpn [3], fpn [3], itg);
itg     LolGetNearest      (int64_t, itg, fpn *, fpn *, fpn, itg (void *, itg),
                            void * , itg);
itg     LolIntersectSurface(int64_t, fpn *, fpn *, fpn *,
                            fpn, itg (void *, itg), void *, itg );
itg     LolProjectVertex   (int64_t, fpn *, itg, itg, fpn *, itg);


/*----------------------------------------------------------------------------*/
/* Fortran 77 API                                                             */
/*----------------------------------------------------------------------------*/

#if defined(F77_NO_UNDER_SCORE)
#define call(x) x
#else
#define call(x) x ## _
#endif
