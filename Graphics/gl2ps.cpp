/*
 * GL2PS, an OpenGL to Postscript Printing Library
 * Copyright (C) 1999-2001  Christophe Geuzaine 
 *
 * $Id: gl2ps.cpp,v 1.20 2001-06-12 08:49:42 geuzaine Exp $
 *
 * E-mail: Christophe.Geuzaine@AdValvas.be
 * URL: http://www.geuz.org/gl2ps/
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

#include <string.h>
#include <sys/types.h>
#include <malloc.h>
#include <math.h>
#include <stdarg.h>
#include <time.h>

#include "gl2ps.h"

/* The static gl2ps context. gl2ps is not thread safe (we should
   create a local GL2PScontext during gl2psBeginPage). */

static GL2PScontext gl2ps;

/* Some 'system' utility routines */

GLvoid gl2psMsg(GLint level, char *fmt, ...){
  va_list args;

  if(!(gl2ps.options & GL2PS_SILENT)){
    switch(level){
    case GL2PS_INFO : fprintf(stderr, "GL2PS info: "); break;
    case GL2PS_WARNING : fprintf(stderr, "GL2PS warning: "); break;
    case GL2PS_ERROR : fprintf(stderr, "GL2PS error: "); break;
    }
    va_start(args, fmt);
    vfprintf(stderr, fmt, args); 
    va_end (args);
    fprintf(stderr, "\n");
  }
  if(level == GL2PS_ERROR) exit(1);
}

GLvoid *gl2psMalloc(size_t size){
  GLvoid *ptr;

  if(!size) return(NULL);
  ptr = malloc(size);
  if(!ptr) gl2psMsg(GL2PS_ERROR, "Couldn't allocate requested memory");
  return(ptr);
}

GLvoid *gl2psRealloc(GLvoid *ptr, size_t size){
  if(!size) return(NULL);
  ptr = realloc(ptr, size);
  if(!ptr) gl2psMsg(GL2PS_ERROR, "Couldn't reallocate requested memory");
  return(ptr);
}

GLvoid gl2psFree(GLvoid *ptr){
  if(!ptr) return;
  free(ptr);
}

/* The list handling routines */

GLvoid gl2psListRealloc(GL2PSlist *list, GLint n){
  if(n <= 0) return;
  if(!list->array){
    list->nmax = ((n - 1) / list->incr + 1) * list->incr;
    list->array = (char *)gl2psMalloc(list->nmax * list->size);
  }
  else
    if(n > list->nmax){
      list->nmax = ((n - 1) / list->incr + 1) * list->incr;
      list->array = (char *)gl2psRealloc(list->array,
					 list->nmax * list->size);
    }
}

GL2PSlist *gl2psListCreate(GLint n, GLint incr, GLint size){
  GL2PSlist *list;

  if(n < 0) n = 0;
  if(incr <= 0) incr = 1;
  list = (GL2PSlist *)gl2psMalloc(sizeof(GL2PSlist));
  list->nmax = 0;
  list->incr = incr;
  list->size = size;
  list->n = 0;
  list->array = NULL;
  gl2psListRealloc(list, n);
  return(list);
}

GLvoid gl2psListDelete(GL2PSlist *list){
  gl2psFree(list->array);
  gl2psFree(list);
}

GLvoid gl2psListAdd(GL2PSlist *list, GLvoid *data){
  list->n++;
  gl2psListRealloc(list, list->n);
  memcpy(&list->array[(list->n - 1) * list->size], data, list->size);
}

GLint gl2psListNbr(GL2PSlist *list){
  return(list->n);
}

GLvoid *gl2psListPointer(GL2PSlist *list, GLint index){
  if((index < 0) || (index >= list->n))
    gl2psMsg(GL2PS_ERROR, "Wrong list index in gl2psListPointer");
  return(&list->array[index * list->size]);
}

GLvoid gl2psListSort(GL2PSlist *list,
		     GLint (*fcmp)(const GLvoid *a, const GLvoid *b)){
  qsort(list->array, list->n, list->size, fcmp);
}

GLvoid gl2psListAction(GL2PSlist *list, 
		       GLvoid (*action)(GLvoid *data, GLvoid *dummy)){
  GLint i, dummy;

  for(i=0 ; i<gl2psListNbr(list) ; i++)
    (*action)(gl2psListPointer(list, i), &dummy);
}

GLvoid gl2psListActionInverse(GL2PSlist *list, 
			      GLvoid (*action)(GLvoid *data, GLvoid *dummy)){
  GLint i, dummy;

  for(i=gl2psListNbr(list) ; i>0 ; i--)
    (*action)(gl2psListPointer(list, i-1), &dummy);
}

/* The 3D sorting routines */

GLfloat gl2psComparePointPlane(GL2PSxyz point, GL2PSplane plane){
  return(plane[0] * point[0] + 
	 plane[1] * point[1] + 
	 plane[2] * point[2] + 
	 plane[3]);
}

GLfloat gl2psPsca(GLfloat *a, GLfloat *b){
  return(a[0]*b[0] + a[1]*b[1] + a[2]*b[2]);
}

GLvoid gl2psPvec(GLfloat *a, GLfloat *b, GLfloat *c){
  c[0] = a[1]*b[2] - a[2]*b[1];
  c[1] = a[2]*b[0] - a[0]*b[2];
  c[2] = a[0]*b[1] - a[1]*b[0];
}

GLfloat gl2psNorm(GLfloat *a){
  return sqrt(a[0]*a[0] + a[1]*a[1] + a[2]*a[2]);
}

GLvoid gl2psGetNormal(GLfloat *a, GLfloat *b, GLfloat *c){
  GLfloat norm;
  gl2psPvec(a, b, c);
  if((norm = gl2psNorm(c))){
    c[0] = c[0] / norm;
    c[1] = c[1] / norm;
    c[2] = c[2] / norm;
  }
  else
    gl2psMsg(GL2PS_WARNING, "Bad plane in BSP tree");
}

GLvoid gl2psGetPlane(GL2PSprimitive *prim, GL2PSplane plane){
  GL2PSxyz v={0., 0., 0.}, w={0., 0., 0.};

  switch(prim->type){
  case GL2PS_TRIANGLE :
  case GL2PS_QUADRANGLE :
    v[0] = prim->verts[1].xyz[0] - prim->verts[0].xyz[0]; 
    v[1] = prim->verts[1].xyz[1] - prim->verts[0].xyz[1]; 
    v[2] = prim->verts[1].xyz[2] - prim->verts[0].xyz[2]; 
    w[0] = prim->verts[2].xyz[0] - prim->verts[0].xyz[0]; 
    w[1] = prim->verts[2].xyz[1] - prim->verts[0].xyz[1]; 
    w[2] = prim->verts[2].xyz[2] - prim->verts[0].xyz[2]; 
    if((!v[0] && !v[1] && !v[2]) || (!w[0] && !w[1] && !w[2])){
      plane[0] = plane[1] = 0.;
      plane[2] = 1.;
      plane[3] = -prim->verts[0].xyz[2];
    }
    else{
      gl2psGetNormal(v, w, plane);
      plane[3] = 
	- plane[0] * prim->verts[0].xyz[0] 
	- plane[1] * prim->verts[0].xyz[1] 
	- plane[2] * prim->verts[0].xyz[2];
    }
    break;
  case GL2PS_LINE :
    v[0] = prim->verts[1].xyz[0] - prim->verts[0].xyz[0]; 
    v[1] = prim->verts[1].xyz[1] - prim->verts[0].xyz[1]; 
    v[2] = prim->verts[1].xyz[2] - prim->verts[0].xyz[2]; 
    if(!v[0] && !v[1] && !v[2]){
      plane[0] = plane[1] = 0.;
      plane[2] = 1.;
      plane[3] = -prim->verts[0].xyz[2];
    }
    else{
      if(!v[0])      w[0] = 1.;
      else if(!v[1]) w[1] = 1.;
      else           w[2] = 1.;
      gl2psGetNormal(v, w, plane);
      plane[3] = 
	- plane[0] * prim->verts[0].xyz[0] 
	- plane[1] * prim->verts[0].xyz[1] 
	- plane[2] * prim->verts[0].xyz[2];
    }
    break;
  case GL2PS_POINT :
  case GL2PS_TEXT :
    plane[0] = plane[1] = 0.;
    plane[2] = 1.;
    plane[3] = -prim->verts[0].xyz[2];
    break;
  default :
    gl2psMsg(GL2PS_ERROR, "Unknown primitive type in BSP tree");
  }
}

GLvoid gl2psCutEdge(GL2PSvertex a, GL2PSvertex b, GL2PSplane plane, 
		    GL2PSvertex *c){
  GL2PSxyz v;
  GLfloat  sect;

  v[0] = b.xyz[0] - a.xyz[0];
  v[1] = b.xyz[1] - a.xyz[1];
  v[2] = b.xyz[2] - a.xyz[2];
  sect = - gl2psComparePointPlane(a.xyz, plane) / gl2psPsca(plane, v);

  c->xyz[0] = a.xyz[0] + v[0] * sect;
  c->xyz[1] = a.xyz[1] + v[1] * sect;
  c->xyz[2] = a.xyz[2] + v[2] * sect;
  
  c->rgba[0] = (1.-sect) * a.rgba[0] + sect * b.rgba[0];
  c->rgba[1] = (1.-sect) * a.rgba[1] + sect * b.rgba[1];
  c->rgba[2] = (1.-sect) * a.rgba[2] + sect * b.rgba[2];
  c->rgba[3] = (1.-sect) * a.rgba[3] + sect * b.rgba[3];
}

GLvoid gl2psFreePrimitive(GLvoid *a, GLvoid *b){
  GL2PSprimitive *q ;
  
  q = *(GL2PSprimitive**)a;
  gl2psFree(q->verts);
  if(q->type == GL2PS_TEXT){
    if(q->text->str) gl2psFree(q->text->str);
    gl2psFree(q->text);
  }
  gl2psFree(q);
}

GLvoid gl2psCreateSplittedPrimitive(GL2PSprimitive *parent, GL2PSplane plane,
				    GL2PSprimitive **child, GLshort numverts,
				    GLshort *index0, GLshort *index1){
  GLshort i;

  if(numverts > 4){
    gl2psMsg(GL2PS_WARNING, "%d vertices in polygon", numverts);
    numverts = 4;
  }

  switch(numverts){
  case 1 : (*child)->type = GL2PS_POINT; break; 
  case 2 : (*child)->type = GL2PS_LINE; break; 
  case 3 : (*child)->type = GL2PS_TRIANGLE; break; 
  case 4 : (*child)->type = GL2PS_QUADRANGLE; break;    
  }
  (*child)->boundary = 0; /* not done! */
  (*child)->dash = parent->dash;
  (*child)->width = parent->width;
  (*child)->numverts = numverts;
  (*child)->verts = (GL2PSvertex *)gl2psMalloc(numverts * sizeof(GL2PSvertex));

  for(i=0 ; i<numverts ; i++){
    if(index1[i] < 0)
      (*child)->verts[i] = parent->verts[index0[i]];
    else
      gl2psCutEdge(parent->verts[index0[i]], parent->verts[index1[i]], 
		   plane, &(*child)->verts[i]);
  }
}

GLvoid gl2psAddIndex(GLshort *index0, GLshort *index1, GLshort *nb, 
		     GLshort i, GLshort j){
  GLint k;

  for(k=0 ; k<*nb ; k++)
    if((index0[k] == i && index1[k] == j) ||
       (index1[k] == i && index0[k] == j)) return;

  index0[*nb] = i;
  index1[*nb] = j;
  (*nb)++;
}

GLshort gl2psGetIndex(GLshort i, GLshort num){
  return(i < num-1) ? i+1 : 0;
}

GLint gl2psTestSplitPrimitive(GL2PSprimitive *prim, GL2PSplane plane){
  GLint     type=GL2PS_COINCIDENT;
  GLshort   i, j;
  GLfloat   d[5]; 

  for(i = 0 ; i < prim->numverts ; i++){  
    d[i] = gl2psComparePointPlane(prim->verts[i].xyz, plane);
  }

  if(prim->type == GL2PS_POINT)
    return 0;
  else{
    for(i = 0 ; i < prim->numverts ; i++){
      j = gl2psGetIndex(i, prim->numverts);
      if(d[j] > GL2PS_EPSILON){
	if(type == GL2PS_COINCIDENT)      type = GL2PS_IN_BACK_OF;
	else if(type != GL2PS_IN_BACK_OF) return 1; 
	if(d[i] < -GL2PS_EPSILON)	  return 1;
      }
      else if(d[j] < -GL2PS_EPSILON){
	if(type == GL2PS_COINCIDENT)       type = GL2PS_IN_FRONT_OF;   
	else if(type != GL2PS_IN_FRONT_OF) return 1;
	if(d[i] > GL2PS_EPSILON)           return 1;
      }
    }
  }
  return 0;
}

GLint gl2psSplitPrimitive(GL2PSprimitive *prim, GL2PSplane plane, 
			  GL2PSprimitive **front, GL2PSprimitive **back){
  GLshort  i, j, in=0, out=0, in0[5], in1[5], out0[5], out1[5];
  GLint    type;
  GLfloat  d[5]; 

  type = GL2PS_COINCIDENT;

  for(i = 0 ; i < prim->numverts ; i++){  
    d[i] = gl2psComparePointPlane(prim->verts[i].xyz, plane);
  }

  switch(prim->type){
  case GL2PS_POINT :
    if(d[0] > GL2PS_EPSILON)       type = GL2PS_IN_BACK_OF;
    else if(d[0] < -GL2PS_EPSILON) type = GL2PS_IN_FRONT_OF;
    else                           type = GL2PS_COINCIDENT;
    break;
  default :
    for(i = 0 ; i < prim->numverts ; i++){
      j = gl2psGetIndex(i, prim->numverts);
      if(d[j] > GL2PS_EPSILON){
	if(type == GL2PS_COINCIDENT)      type = GL2PS_IN_BACK_OF;
	else if(type != GL2PS_IN_BACK_OF) type = GL2PS_SPANNING; 
	if(d[i] < -GL2PS_EPSILON){
	  gl2psAddIndex(in0, in1, &in, i, j);
	  gl2psAddIndex(out0, out1, &out, i, j);
	  type = GL2PS_SPANNING;
	}
	gl2psAddIndex(out0, out1, &out, j, -1);
      }
      else if(d[j] < -GL2PS_EPSILON){
	if(type == GL2PS_COINCIDENT)       type = GL2PS_IN_FRONT_OF;   
	else if(type != GL2PS_IN_FRONT_OF) type = GL2PS_SPANNING;
	if(d[i] > GL2PS_EPSILON){
	  gl2psAddIndex(in0, in1, &in, i, j);
	  gl2psAddIndex(out0, out1, &out, i, j);
	  type = GL2PS_SPANNING;
	}
	gl2psAddIndex(in0, in1, &in, j, -1);
      }
      else{
	gl2psAddIndex(in0, in1, &in, j, -1);
	gl2psAddIndex(out0, out1, &out, j, -1);
      }
    }
    break;
  }

  if(type == GL2PS_SPANNING){
    *back = (GL2PSprimitive*)gl2psMalloc(sizeof(GL2PSprimitive));
    *front = (GL2PSprimitive*)gl2psMalloc(sizeof(GL2PSprimitive));
    gl2psCreateSplittedPrimitive(prim, plane, back, out, out0, out1);
    gl2psCreateSplittedPrimitive(prim, plane, front, in, in0, in1);
  }

  return type;
}

GLvoid gl2psDivideQuad(GL2PSprimitive *quad, 
		       GL2PSprimitive **t1, GL2PSprimitive **t2){
  *t1 = (GL2PSprimitive*)gl2psMalloc(sizeof(GL2PSprimitive));
  *t2 = (GL2PSprimitive*)gl2psMalloc(sizeof(GL2PSprimitive));
  (*t1)->type = (*t2)->type = GL2PS_TRIANGLE;
  (*t1)->numverts = (*t2)->numverts = 3;
  (*t1)->depth = (*t2)->depth = quad->depth;
  (*t1)->dash = (*t2)->dash = quad->dash;
  (*t1)->width = (*t2)->width = quad->width;
  (*t1)->verts = (GL2PSvertex *)gl2psMalloc(3 * sizeof(GL2PSvertex));
  (*t2)->verts = (GL2PSvertex *)gl2psMalloc(3 * sizeof(GL2PSvertex));
  (*t1)->verts[0] = quad->verts[0];
  (*t1)->verts[1] = quad->verts[1];
  (*t1)->verts[2] = quad->verts[2];
  (*t1)->boundary = ((quad->boundary & 1) ? 1 : 0) | ((quad->boundary & 2) ? 2 : 0);
  (*t2)->verts[0] = quad->verts[0];
  (*t2)->verts[1] = quad->verts[2];
  (*t2)->verts[2] = quad->verts[3];
  (*t1)->boundary = ((quad->boundary & 4) ? 2 : 0) | ((quad->boundary & 4) ? 2 : 0);
}

int gl2psCompareDepth(const GLvoid *a, const GLvoid *b){
  GL2PSprimitive *q,*w;
  GLfloat        diff;

  q = *(GL2PSprimitive**)a;
  w = *(GL2PSprimitive**)b;
  diff = q->depth - w->depth;
  if(diff > 0.) 
    return 1;
  else if(diff < 0.)
    return -1;
  else
    return 0;
}

GLint gl2psTrianglesFirst(const GLvoid *a, const GLvoid *b){
  GL2PSprimitive *q,*w;

  q = *(GL2PSprimitive**)a;
  w = *(GL2PSprimitive**)b;
  return(q->type < w->type ? 1 : -1);
}

GLint gl2psFindRoot(GL2PSlist *primitives, GL2PSprimitive **root){
  GLint          i, j, count, best=1000000, index=0;
  GL2PSprimitive *prim1, *prim2;
  GL2PSplane     plane;

  if(gl2ps.options & GL2PS_BEST_ROOT){
    *root = *(GL2PSprimitive**)gl2psListPointer(primitives, 0);
    for(i=0 ; i<gl2psListNbr(primitives) ; i++){
      prim1 = *(GL2PSprimitive**)gl2psListPointer(primitives, i);
      gl2psGetPlane(prim1, plane);
      count=0;
      for(j=0 ; j<gl2psListNbr(primitives) ; j++){
	if(j != i){
	  prim2 = *(GL2PSprimitive**)gl2psListPointer(primitives, j);
	  count += gl2psTestSplitPrimitive(prim2, plane); 
	}
	if(count > best) break;
      }
      if(count < best){
	best = count;
	index = i;
	*root = prim1;
	if(!count) return index;
      }
    }
    if(index) gl2psMsg(GL2PS_INFO, "GL2PS_BEST_ROOT was worth it: %d", index);
    return index;
  }
  else{
    *root = *(GL2PSprimitive**)gl2psListPointer(primitives, 0);
    return 0;
  }
}


GLvoid gl2psAddPrimitiveInList(GL2PSprimitive *prim, GL2PSlist *list){
  GL2PSprimitive *t1, *t2;

  if(prim->type != GL2PS_QUADRANGLE){
    gl2psListAdd(list, &prim);
  }
  else{
    gl2psDivideQuad(prim, &t1, &t2);
    gl2psListAdd(list, &t1);
    gl2psListAdd(list, &t2);
    gl2psFreePrimitive(&prim, NULL);
  }
  
}

GLvoid gl2psFreeBspTree(GL2PSbsptree *tree){
  if(tree->back){
    gl2psFreeBspTree(tree->back);
    gl2psFree(tree->back);
  }
  if(tree->primitives){
    gl2psListAction(tree->primitives, gl2psFreePrimitive);
    gl2psListDelete(tree->primitives);
  }
  if(tree->front){
    gl2psFreeBspTree(tree->front);
    gl2psFree(tree->front);
  }
}

GLboolean gl2psGreater(GLfloat f1, GLfloat f2){
  if(f1 > f2) return 1;
  else return 0;
}

GLboolean gl2psLess(GLfloat f1, GLfloat f2){
  if(f1 < f2) return 1;
  else return 0;
}

GLvoid gl2psBuildBspTree(GL2PSbsptree *tree, GL2PSlist *primitives){
  GL2PSprimitive *prim, *frontprim, *backprim;
  GL2PSlist      *frontlist, *backlist;
  GLint          i, index;

  tree->front = NULL;
  tree->back = NULL;
  tree->primitives = gl2psListCreate(1, 2, sizeof(GL2PSprimitive*));
  index = gl2psFindRoot(primitives, &prim);
  gl2psGetPlane(prim, tree->plane);
  gl2psAddPrimitiveInList(prim, tree->primitives);

  frontlist = gl2psListCreate(1, 2, sizeof(GL2PSprimitive*));
  backlist = gl2psListCreate(1, 2, sizeof(GL2PSprimitive*));

  for(i=0 ; i<gl2psListNbr(primitives) ; i++){
    if(i != index){
      prim = *(GL2PSprimitive**)gl2psListPointer(primitives,i);
      switch(gl2psSplitPrimitive(prim,tree->plane,&frontprim,&backprim)){
      case GL2PS_COINCIDENT:
	gl2psAddPrimitiveInList(prim, tree->primitives);
	break;
      case GL2PS_IN_BACK_OF:
	gl2psAddPrimitiveInList(prim, backlist);
	break;
      case GL2PS_IN_FRONT_OF:
	gl2psAddPrimitiveInList(prim, frontlist);
	break;
      case GL2PS_SPANNING:
	gl2psAddPrimitiveInList(backprim, backlist);
	gl2psAddPrimitiveInList(frontprim, frontlist);
	gl2psFreePrimitive(&prim, NULL);
	break;
      }
    }
  }

  if(gl2psListNbr(tree->primitives))
    gl2psListSort(tree->primitives, gl2psTrianglesFirst);

  if(gl2psListNbr(frontlist)){
    gl2psListSort(frontlist, gl2psTrianglesFirst);
    tree->front = (GL2PSbsptree*)gl2psMalloc(sizeof(GL2PSbsptree));
    gl2psBuildBspTree(tree->front, frontlist);
  }
  else
    gl2psListDelete(frontlist);

  if(gl2psListNbr(backlist)){
    gl2psListSort(backlist, gl2psTrianglesFirst);
    tree->back = (GL2PSbsptree*)gl2psMalloc(sizeof(GL2PSbsptree));
    gl2psBuildBspTree(tree->back, backlist);
  }
  else
    gl2psListDelete(backlist);
  
  gl2psListDelete(primitives);
}

GLvoid  gl2psTraverseBspTree(GL2PSbsptree *tree, GL2PSxyz eye, GLfloat epsilon,
			     GLboolean (*compare)(GLfloat f1, GLfloat f2),
			     GLvoid (*action)(GLvoid *data, GLvoid *dummy)){
  GLfloat result;

  if(!tree) return;

  result = gl2psComparePointPlane(eye, tree->plane);

  if(compare(result, epsilon)){
    gl2psTraverseBspTree(tree->back, eye, epsilon, compare, action);
    gl2psListAction(tree->primitives, action);
    gl2psTraverseBspTree(tree->front, eye, epsilon, compare, action);
  }
  else if(compare(-epsilon, result)){ 
    gl2psTraverseBspTree(tree->front, eye, epsilon, compare, action);
    gl2psListAction(tree->primitives, action);
    gl2psTraverseBspTree(tree->back, eye, epsilon, compare, action) ;
  }
  else{
    gl2psTraverseBspTree(tree->front, eye, epsilon, compare, action);
    gl2psTraverseBspTree(tree->back, eye, epsilon, compare, action) ;
  }
}

/* The 2D sorting routines (for occlusion culling). These routines do
   _not_ work as expected at the moment... */

GLint gl2psSplit2d(GL2PSxyz a, GL2PSxyz b, GL2PSxy tc, GL2PSxy td){
  GLfloat  line[3], n, d[2]; 

  /*
    in back of == >0 == outside polygon
   */

  line[0] = td[1] - tc[1] ;
  line[1] = tc[0] - td[0] ;
  n = sqrt(line[0]*line[0]+line[1]*line[1]);
  line[0] /= n ; 
  line[1] /= n ;
  line[2] = - line[0] * tc[0] - line[1] * tc[1] ;

  d[0] = line[0]*a[0] + line[1]*a[1] + line[2] ;

  if(b == NULL){
    if(d[0] > GL2PS_EPSILON)       return GL2PS_IN_BACK_OF;
    else if(d[0] < -GL2PS_EPSILON) return GL2PS_IN_FRONT_OF;
    else                           return GL2PS_COINCIDENT;
  }
  else{
    d[1] = line[0]*b[0] + line[1]*b[1] + line[2] ;
    
    if(d[0] > GL2PS_EPSILON){
      if(d[1] < -GL2PS_EPSILON) return GL2PS_SPANNING;
      else return GL2PS_IN_BACK_OF;
    }
    if(d[0] < -GL2PS_EPSILON){
      if(d[1] > GL2PS_EPSILON) return GL2PS_SPANNING;
      else return GL2PS_IN_FRONT_OF;
    }
    else{
      if(d[1] > GL2PS_EPSILON) return GL2PS_IN_BACK_OF;
      else if(d[1] < -GL2PS_EPSILON) return GL2PS_IN_FRONT_OF;
      /* else return GL2PS_COINCIDENT; */
      else return GL2PS_IN_FRONT_OF;
    }
  }
}


GLvoid  gl2psSimplify2d(GL2PSbsptree2d *tree){
  if(!tree) return;
  if(tree->back){
    if(tree->flag==0)
      gl2psSimplify2d(tree->back);
  }
  if(tree->front){
    gl2psSimplify2d(tree->front);
  }
}

GLvoid  gl2psReset(GL2PSbsptree2d *tree){
  if(!tree) return;
  tree->flag=0;
  if(tree->back){
    gl2psReset(tree->back);
  }
  if(tree->front){
    gl2psReset(tree->front);
  }
}


static GL2PSbsptree2d *image=NULL;

GLvoid gl2psAddInImageTree(GL2PSprimitive *prim, 
			   GL2PSxyz a, GL2PSxyz b, GL2PSbsptree2d **tree){
  GLint res;

  if(*tree == NULL){
    /* insert the edge, except for lines & points */
    if(prim->numverts > 2){ 
      prim->depth = -1.; 
      (*tree) = (GL2PSbsptree2d*)gl2psMalloc(sizeof(GL2PSbsptree2d));
      (*tree)->a[0] = a[0];
      (*tree)->a[1] = a[1];
      (*tree)->b[0] = b[0];
      (*tree)->b[1] = b[1];
      (*tree)->front = NULL;
      (*tree)->back = NULL;
      (*tree)->flag = 1;
    }
  }
  else{
    res = gl2psSplit2d(a, b, (*tree)->a, (*tree)->b);

    switch(res){
    case GL2PS_IN_BACK_OF:
       gl2psAddInImageTree(prim, a, b, &(*tree)->back);
      break;
    case GL2PS_IN_FRONT_OF:
      if((*tree)->flag) gl2psAddInImageTree(prim, a, b, &(*tree)->front);
      break;
    case GL2PS_SPANNING:
      gl2psAddInImageTree(prim, a, b, &(*tree)->back);
      if((*tree)->flag) gl2psAddInImageTree(prim, a, b, &(*tree)->front);
      break;
    case GL2PS_COINCIDENT:
      (*tree)->flag = 1;
      break;
    }
  }
}

static int count=0;

GLvoid gl2psAddInImage(void *a, void *b){
  GL2PSprimitive *prim;
  GLint          i;

  prim = *(GL2PSprimitive **)a;

  /*  if(prim->numverts == 1)
      gl2psAddInImageTree(prim, prim->verts[i].xyz, NULL, &image); */
  if(prim->numverts < 3)
    return;
  else{
    for(i=0 ; i<prim->numverts ; i++){
      count++;
      gl2psAddInImageTree(prim, prim->verts[i].xyz, 
			  prim->verts[gl2psGetIndex(i,prim->numverts)].xyz, &image);
    }
  }

  /* simplify old/new */

  gl2psReset(image);

}


#define GL2PS_BOUNDARY_OFFSET 0

GLvoid gl2psAddBoundaryInList(GL2PSprimitive *prim, GL2PSlist *list){
  GL2PSprimitive *b;
  GLshort         i;
  GL2PSxyz        c;

  c[0] = c[1] = c[2] = 0.;
  for(i=0 ; i<prim->numverts ; i++){
    c[0] += prim->verts[i].xyz[0];
    c[1] += prim->verts[i].xyz[1];
  }
  c[0] /= prim->numverts;
  c[1] /= prim->numverts;

  for(i=0 ; i<prim->numverts ; i++){
    if(prim->boundary & (GLint)pow(2., i)){
      b = (GL2PSprimitive*)gl2psMalloc(sizeof(GL2PSprimitive));
      b->type = GL2PS_LINE;
      b->dash = prim->dash;
      b->width = prim->width;
      b->boundary = 0;
      b->numverts = 2;
      b->verts = (GL2PSvertex *)gl2psMalloc(2 * sizeof(GL2PSvertex));

#if GL2PS_BOUNDARY_OFFSET
      v[0] = c[0] - prim->verts[i].xyz[0];
      v[1] = c[1] - prim->verts[i].xyz[1];
      v[2] = 0.;
      norm = gl2psNorm(v);
      v[0] /= norm;
      v[1] /= norm;
      b->verts[0].xyz[0] = prim->verts[i].xyz[0] +0.1*v[0];
      b->verts[0].xyz[1] = prim->verts[i].xyz[1] +0.1*v[1];
      b->verts[0].xyz[2] = prim->verts[i].xyz[2];
      v[0] = c[0] - prim->verts[gl2psGetIndex(i, prim->numverts)].xyz[0];
      v[1] = c[1] - prim->verts[gl2psGetIndex(i, prim->numverts)].xyz[1];
      norm = gl2psNorm(v);
      v[0] /= norm;
      v[1] /= norm;
      b->verts[1].xyz[0] = prim->verts[gl2psGetIndex(i, prim->numverts)].xyz[0] +0.1*v[0];
      b->verts[1].xyz[1] = prim->verts[gl2psGetIndex(i, prim->numverts)].xyz[1] +0.1*v[1];
      b->verts[1].xyz[2] = prim->verts[gl2psGetIndex(i, prim->numverts)].xyz[2];
#else
      b->verts[0].xyz[0] = prim->verts[i].xyz[0];
      b->verts[0].xyz[1] = prim->verts[i].xyz[1];
      b->verts[0].xyz[2] = prim->verts[i].xyz[2];
      b->verts[1].xyz[0] = prim->verts[gl2psGetIndex(i, prim->numverts)].xyz[0];
      b->verts[1].xyz[1] = prim->verts[gl2psGetIndex(i, prim->numverts)].xyz[1];
      b->verts[1].xyz[2] = prim->verts[gl2psGetIndex(i, prim->numverts)].xyz[2];
#endif

      b->verts[0].rgba[0] = 0.;
      b->verts[0].rgba[1] = 0.;
      b->verts[0].rgba[2] = 0.;
      b->verts[0].rgba[3] = 0.;
      b->verts[1].rgba[0] = 0.;
      b->verts[1].rgba[1] = 0.;
      b->verts[1].rgba[2] = 0.;
      b->verts[1].rgba[3] = 0.;
      gl2psListAdd(list, &b);
    }
  }

}

GLvoid  gl2psBuildPolygonBoundary(GL2PSbsptree *tree){
  GLint          i, n;
  GL2PSprimitive *prim;

  if(!tree) return;
  gl2psBuildPolygonBoundary(tree->back);
  n = gl2psListNbr(tree->primitives);
  for(i=0 ; i<n ; i++){
    prim = *(GL2PSprimitive**)gl2psListPointer(tree->primitives, i);
    if(prim->boundary) gl2psAddBoundaryInList(prim, tree->primitives);
  }
  gl2psBuildPolygonBoundary(tree->front);
}

/* The feedback buffer parser */

GLvoid gl2psAddPolyPrimitive(GLshort type, GLshort numverts, 
			     GL2PSvertex *verts, GLint offset, 
			     GLshort dash, GLshort width,
			     GLshort boundary){
  GLshort         i;
  GLfloat         factor, units, area, dZ, dZdX, dZdY, maxdZ;
  GL2PSprimitive *prim;

  prim = (GL2PSprimitive *)gl2psMalloc(sizeof(GL2PSprimitive));
  prim->type = type;
  prim->numverts = numverts;
  prim->verts = (GL2PSvertex *)gl2psMalloc(numverts * sizeof(GL2PSvertex));
  memcpy(prim->verts, verts, numverts * sizeof(GL2PSvertex));
  prim->boundary = boundary;

  if(gl2ps.options & GL2PS_SIMPLE_LINE_OFFSET){
    if(type == GL2PS_LINE){
      if(gl2ps.sort == GL2PS_SIMPLE_SORT){
	prim->verts[0].xyz[2] -= 1.;
	prim->verts[1].xyz[2] -= 1.;
      }
      else{
	prim->verts[0].xyz[2] -= 0.1;
	prim->verts[1].xyz[2] -= 0.1;
      }
    }
  }
  else if(offset && type == GL2PS_TRIANGLE){

    if(gl2ps.sort == GL2PS_SIMPLE_SORT){    
      factor = gl2ps.offset[0];
      units = gl2ps.offset[1];
    }
    else{
      factor = gl2ps.offset[0] / 800.;
      units = gl2ps.offset[1] / 800.;
    }

    area = 
      (prim->verts[1].xyz[0] - prim->verts[0].xyz[0]) * 
      (prim->verts[2].xyz[1] - prim->verts[1].xyz[1]) - 
      (prim->verts[2].xyz[0] - prim->verts[1].xyz[0]) * 
      (prim->verts[1].xyz[1] - prim->verts[0].xyz[1]);
    dZdX = 
      (prim->verts[2].xyz[1] - prim->verts[1].xyz[1]) *
      (prim->verts[1].xyz[2] - prim->verts[0].xyz[2]) -
      (prim->verts[1].xyz[1] - prim->verts[0].xyz[1]) *
      (prim->verts[2].xyz[2] - prim->verts[1].xyz[2]) / area;
    dZdY = 
      (prim->verts[1].xyz[0] - prim->verts[0].xyz[0]) *
      (prim->verts[2].xyz[2] - prim->verts[1].xyz[2]) -
      (prim->verts[2].xyz[0] - prim->verts[1].xyz[0]) *
      (prim->verts[1].xyz[2] - prim->verts[0].xyz[2]) / area;
    
    maxdZ = sqrt(dZdX*dZdX + dZdY*dZdY);

    dZ = factor * maxdZ + units;

    /* printf("dZ = %g  (fact=%g  units=%g)\n", dZ, factor, units); */

    prim->verts[0].xyz[2] += dZ;
    prim->verts[1].xyz[2] += dZ;
    prim->verts[2].xyz[2] += dZ;
  }

  prim->depth = 0.;
  prim->dash = dash;
  prim->width = width;  /* we should maybe use floats */

  if(gl2ps.sort == GL2PS_SIMPLE_SORT){
    for(i = 0; i < numverts; i++) 
      prim->depth += prim->verts[i].xyz[2]; 
    prim->depth /= (GLfloat)numverts;
  }
  
  gl2psListAdd(gl2ps.primitives, &prim);
}

GLint gl2psGetVertex(GL2PSvertex *v, GLfloat *p){
  GLint i;

  v->xyz[0] = p[0];
  v->xyz[1] = p[1];
  v->xyz[2] = 1000. * p[2];

  if(gl2ps.colormode == GL_COLOR_INDEX && gl2ps.colorsize > 0){
    i = (GLint)(p[3] + 0.5);
    v->rgba[0] = gl2ps.colormap[i][0];
    v->rgba[1] = gl2ps.colormap[i][1];
    v->rgba[2] = gl2ps.colormap[i][2];
    v->rgba[3] = gl2ps.colormap[i][3];
    return 4;
  }
  else{
    v->rgba[0] = p[3];
    v->rgba[1] = p[4];
    v->rgba[2] = p[5];
    v->rgba[3] = p[6];
    return 7;
  }
}

GLint gl2psParseFeedbackBuffer(GLvoid){
  GLint        i, used, count, v, vtot, offset=0;
  GLshort      boundary, flag, dash=0, psize=1, lwidth=1;
  GLfloat     *current;
  GL2PSvertex  vertices[3];

  used = glRenderMode(GL_RENDER);

  if(used < 0){
    gl2psMsg(GL2PS_INFO, "OpenGL feedback buffer reallocation");
    return GL2PS_OVERFLOW;
  }

  if(used == 0){
    gl2psMsg(GL2PS_WARNING, "Empty feedback buffer");
    return GL2PS_NO_FEEDBACK;
  }

  current = gl2ps.feedback;
  boundary = gl2ps.boundary = 0;

  while(used > 0){

    if(boundary) gl2ps.boundary = 1;
    
    switch((GLint)*current){
    case GL_POINT_TOKEN :
      current ++;
      used --;
      i = gl2psGetVertex(&vertices[0], current);
      current += i;
      used    -= i;
      gl2psAddPolyPrimitive(GL2PS_POINT, 1, vertices, 0, dash, psize, 0);
      break;
    case GL_LINE_TOKEN :
    case GL_LINE_RESET_TOKEN :
      current ++;
      used --;
      i = gl2psGetVertex(&vertices[0], current);
      current += i;
      used    -= i;
      i = gl2psGetVertex(&vertices[1], current);
      current += i;
      used    -= i;
      gl2psAddPolyPrimitive(GL2PS_LINE, 2, vertices, 0, dash, lwidth, 0);
      break;
    case GL_POLYGON_TOKEN :
      count = (GLint)current[1];
      current += 2;
      used -= 2;
      v = vtot = 0;
      while(count > 0 && used > 0){
	i = gl2psGetVertex(&vertices[v], current);
	current += i;
	used    -= i;
	count --;
	vtot++;
	if(v == 2){
	  if(boundary){
	    if(!count && vtot==2) flag = 1|2|4;
	    else if(!count) flag = 2|4;
	    else if(vtot==2) flag = 1|2;
	    else flag = 2;
	  }
	  else
	    flag = 0;
	  gl2psAddPolyPrimitive(GL2PS_TRIANGLE, 3, vertices, 
				offset, dash, 1, flag);
	  vertices[1] = vertices[2];
	}
	else
	  v ++;
      }
      break;      
    case GL_BITMAP_TOKEN :
    case GL_DRAW_PIXEL_TOKEN :
    case GL_COPY_PIXEL_TOKEN :
      current ++;
      used --;
      i = gl2psGetVertex(&vertices[0], current);
      current += i;
      used    -= i;
      break;      
    case GL_PASS_THROUGH_TOKEN :
      switch((GLint)current[1]){
      case GL2PS_BEGIN_POLYGON_OFFSET_FILL : offset=1; break;
      case GL2PS_END_POLYGON_OFFSET_FILL : offset=0; break;
      case GL2PS_BEGIN_POLYGON_BOUNDARY : boundary=1; break;
      case GL2PS_END_POLYGON_BOUNDARY : boundary=0; break;
      case GL2PS_BEGIN_LINE_STIPPLE : dash=4; break;
      case GL2PS_END_LINE_STIPPLE : dash=0; break;
      case GL2PS_SET_POINT_SIZE : 
	current+=2; 
	used-=2; 
	psize=(GLint)current[1];
	break;
      case GL2PS_SET_LINE_WIDTH : 
	current+=2; 
	used-=2; 
	lwidth=(GLint)current[1];
	break;
      }
      current += 2; 
      used -= 2; 
      break;      
    default :
      gl2psMsg(GL2PS_WARNING, "Unknown token in buffer");
      current ++;
      used --;
      break;
    }
  }
  
  return GL2PS_SUCCESS;
}

/* The postscript routines. Other (vector) image formats should be
   easy to generate by creating the three corresponding routines for
   the new format. */

GLvoid gl2psPrintPostscriptHeader(GLvoid){
  GLint   viewport[4], index;
  GLfloat rgba[4];
  time_t  now;

  time(&now);

  glGetIntegerv(GL_VIEWPORT, viewport);

  /* 
     Greyscale: r g b G (replace C by G in output to change from rgb to gray)
     RGB color: r g b C
     Font choose: size fontname FC
     String primitive: (string) x y r g b size fontname S
     Point primitive: x y size r g b P
     Flat-shaded line: x2 y2 x1 y1 r g b width L
     Flat-shaded triangle: x3 y3 x2 y2 x1 y1 r g b T
     Smooth-shaded line: x2 y2 r2 g2 b2 x1 y1 r1 g1 b1 width SL
     Smooth-shaded triangle: x3 y3 r3 g3 b3 x2 y2 r2 g2 b2 x1 y1 r1 g1 b1 ST
  */

  fprintf(gl2ps.stream, 
	  "%%!PS-Adobe-3.0\n"
	  "%%%%Title: %s\n"
	  "%%%%Creator: GL2PS, an OpenGL to Postscript Printing Library, v. %g\n"
	  "%%%%For: %s\n"
	  "%%%%CreationDate: %s"
	  "%%%%LanguageLevel: 2\n"
	  "%%%%Pages: 1\n"
	  "%%%%DocumentData: Clean7Bit\n"
	  "%%%%PageOrder: Ascend\n"
	  "%%%%Orientation: Portrait\n"
	  "%%%%DocumentMedia: Default %d %d 0 () ()\n"
	  "%%%%BoundingBox: %d %d %d %d\n"
	  "%%%%Copyright: GNU LGPL (C) 1999-2001 Christophe.Geuzaine@AdValvas.be\n"
	  "%%%%EndComments\n"
	  "%%%%BeginProlog\n"
	  "/gl2psdict 64 dict def gl2psdict begin\n"
	  "1 setlinecap 1 setlinejoin /bd {bind def} bind def\n"
	  "/G { 0.082 mul exch 0.6094 mul add exch 0.3086 mul add neg 1.0 add\n"
	  "setgray } bd /C { setrgbcolor } bd /FC { findfont exch scalefont\n"
	  "setfont } bd /S { FC C moveto show } bd /P { C newpath 0.0 360.0\n"
	  "arc closepath fill } bd /L { setlinewidth C newpath moveto lineto\n"
	  "stroke } bd /T { C newpath moveto lineto lineto closepath fill } bd\n"
	  "/SL { /lw exch def /b1 exch def /g1 exch def /r1 exch def /y1 exch def\n"
	  "/x1 exch def /b2 exch def /g2 exch def /r2 exch def /y2 exch def\n"
	  "/x2 exch def b2 b1 sub abs 0.01 gt g2 g1 sub abs 0.005 gt r2 r1 sub\n"
	  "abs 0.008 gt or or { /bm b1 b2 add 0.5 mul def /gm g1 g2 add 0.5 mul def\n"
	  "/rm r1 r2 add 0.5 mul def /ym y1 y2 add 0.5 mul def /xm x1 x2 add\n"
	  "0.5 mul def x1 y1 r1 g1 b1 xm ym rm gm bm lw SL xm ym rm gm bm x2 y2 r2\n"
	  "g2 b2 lw SL } { x1 y1 x2 y2 r1 g1 b1 lw L } ifelse } bd /ST {/b1 exch\n"
	  "def /g1 exch def /r1 exch def /y1 exch def /x1 exch def\n"
	  "/b2 exch def /g2 exch def /r2 exch def /y2 exch def /x2 exch def\n"
	  "/b3 exch def /g3 exch def /r3 exch def /y3 exch def /x3 exch def\n"
	  "b2 b1 sub abs 0.05 gt g2 g1 sub abs 0.017 gt r2 r1 sub abs 0.032 gt\n"
	  "b3 b1 sub abs 0.05 gt g3 g1 sub abs 0.017 gt r3 r1 sub abs 0.032 gt\n"
	  "b2 b3 sub abs 0.05 gt g2 g3 sub abs 0.017 gt r2 r3 sub abs 0.032 gt\n"
	  "or or or or or or or or { /b12 b1 b2 add 0.5 mul def /g12 g1 g2 add\n"
	  "0.5 mul def /r12 r1 r2 add 0.5 mul def /y12 y1 y2 add 0.5 mul def\n"
	  "/x12 x1 x2 add 0.5 mul def /b13 b1 b3 add 0.5 mul def /g13 g1 g3\n"
	  "add 0.5 mul def /r13 r1 r3 add 0.5 mul def /y13 y1 y3 add 0.5 mul\n"
	  "def /x13 x1 x3 add 0.5 mul def /b32 b3 b2 add 0.5 mul def\n"
	  "/g32 g3 g2 add 0.5 mul def /r32 r3 r2 add 0.5 mul def /y32 y3 y2\n"
	  "add 0.5 mul def /x32 x3 x2 add 0.5 mul def x1 y1 r1 g1 b1 x12 y12\n"
	  "r12 g12 b12 x13 y13 r13 g13 b13 x2 y2 r2 g2 b2 x12 y12 r12 g12 b12\n"
	  "x32 y32 r32 g32 b32 x3 y3 r3 g3 b3 x32 y32 r32 g32 b32 x13 y13 r13\n"
	  "g13 b13 x32 y32 r32 g32 b32 x12 y12 r12 g12 b12 x13 y13 r13 g13 b13\n"
	  "ST ST ST ST } { x1 y1 x2 y2 x3 y3 r1 g1 b1 T } ifelse } bd\n"
	  "end\n"
	  "%%%%EndProlog\n"
	  "%%%%BeginSetup\n"
	  "/DeviceRGB setcolorspace\n"
	  "gl2psdict begin\n"
	  "%%%%EndSetup\n"
	  "%%%%Page: 1 1\n"
	  "%%%%BeginPageSetup\n"
	  "%%%%EndPageSetup\n"
	  "mark\n"
	  "gsave\n"
	  "1.0 1.0 scale\n",
	  gl2ps.title, GL2PS_VERSION, gl2ps.producer, ctime(&now), 
	  viewport[2], viewport[3], viewport[0], viewport[1], viewport[2], viewport[3]);
	  
  if(gl2ps.options & GL2PS_DRAW_BACKGROUND){
    if(gl2ps.colormode == GL_RGBA || gl2ps.colorsize == 0)
      glGetFloatv(GL_COLOR_CLEAR_VALUE, rgba);
    else{
      glGetIntegerv(GL_INDEX_CLEAR_VALUE, &index);
      rgba[0] = gl2ps.colormap[index][0];
      rgba[1] = gl2ps.colormap[index][1];
      rgba[2] = gl2ps.colormap[index][2];
      rgba[3] = 0.;
    }
    fprintf(gl2ps.stream,
	    "%g %g %g C\n"
	    "newpath %d %d moveto %d %d lineto %d %d lineto %d %d lineto\n"
	    "closepath fill\n",
	    rgba[0], rgba[1], rgba[2], 
	    viewport[0], viewport[1], viewport[2], viewport[1], 
	    viewport[2], viewport[3], viewport[0], viewport[3]);
  }
}

GLvoid gl2psPrintPostscriptPrimitive(GLvoid *a, GLvoid *b){
  GL2PSprimitive *prim;

  prim = *(GL2PSprimitive**) a;

  if(gl2ps.options & GL2PS_OCCLUSION_CULL && prim->depth >= 0.) return;

  switch(prim->type){
  case GL2PS_TEXT :
    fprintf(gl2ps.stream, "(%s) %g %g %g %g %g %d /%s S\n",
	    prim->text->str, prim->verts[0].xyz[0], prim->verts[0].xyz[1],
	    prim->verts[0].rgba[0], prim->verts[0].rgba[1], 
	    prim->verts[0].rgba[2], prim->text->fontsize, 
	    prim->text->fontname);
    break;
  case GL2PS_POINT :
    fprintf(gl2ps.stream, "%g %g %g %g %g %g P\n", 
	    prim->verts[0].xyz[0], prim->verts[0].xyz[1], 0.5*prim->width, 
	    prim->verts[0].rgba[0], prim->verts[0].rgba[1], prim->verts[0].rgba[2]);
    break;
  case GL2PS_LINE :
    if(prim->dash)
      fprintf(gl2ps.stream, "[%d] 0 setdash\n", prim->dash);
    if(gl2ps.shade){
      fprintf(gl2ps.stream, "%g %g %g %g %g %g %g %g %g %g %g SL\n",
	      prim->verts[1].xyz[0], prim->verts[1].xyz[1],
	      prim->verts[1].rgba[0], prim->verts[1].rgba[1],
	      prim->verts[1].rgba[2], prim->verts[0].xyz[0],
	      prim->verts[0].xyz[1], prim->verts[0].rgba[0],
	      prim->verts[0].rgba[1], prim->verts[0].rgba[2],
	      0.5*prim->width);
    }
    else{
      fprintf(gl2ps.stream, "%g %g %g %g %g %g %g %g L\n",
	      prim->verts[1].xyz[0], prim->verts[1].xyz[1],
	      prim->verts[0].xyz[0], prim->verts[0].xyz[1],
	      prim->verts[0].rgba[0], prim->verts[0].rgba[1], 
	      prim->verts[0].rgba[2], 0.5*prim->width);
    }
    if(prim->dash)
      fprintf(gl2ps.stream, "[] 0 setdash\n");
    break;
  case GL2PS_TRIANGLE :
    if(gl2ps.shade){
      fprintf(gl2ps.stream, "%g %g %g %g %g %g %g %g %g %g %g %g %g %g %g ST\n",
	      prim->verts[2].xyz[0], prim->verts[2].xyz[1],
	      prim->verts[2].rgba[0], prim->verts[2].rgba[1],
	      prim->verts[2].rgba[2], prim->verts[1].xyz[0],
	      prim->verts[1].xyz[1], prim->verts[1].rgba[0],
	      prim->verts[1].rgba[1], prim->verts[1].rgba[2],
	      prim->verts[0].xyz[0], prim->verts[0].xyz[1],
	      prim->verts[0].rgba[0], prim->verts[0].rgba[1],
	      prim->verts[0].rgba[2]);
    }
    else{
      fprintf(gl2ps.stream, "%g %g %g %g %g %g %g %g %g T\n",
	      prim->verts[2].xyz[0], prim->verts[2].xyz[1],
	      prim->verts[1].xyz[0], prim->verts[1].xyz[1],
	      prim->verts[0].xyz[0], prim->verts[0].xyz[1],
	      prim->verts[0].rgba[0], prim->verts[0].rgba[1],
	      prim->verts[0].rgba[2]);
    }
    break;
  case GL2PS_QUADRANGLE :
    gl2psMsg(GL2PS_WARNING, "There should not be any quad left to print");
    break;
  default :
    gl2psMsg(GL2PS_ERROR, "Unknown type of primitive to print");
    break;
  }
}

void gl2psPrintPostscriptFooter(GLvoid){
  fprintf(gl2ps.stream,
	  "grestore\n"
	  "showpage\n"
	  "cleartomark\n"
	  "%%%%PageTrailer\n"
	  "%%%%Trailer\n"
	  "end\n"
	  "%%%%EOF\n");
}


/* The public routines */

GLvoid gl2psBeginPage(char *title, char *producer, GLint sort, GLint options, 
		      GLint colormode, GLint colorsize, GL2PSrgba *colormap,
		      GLint buffersize, FILE *stream){

  gl2ps.format = GL2PS_EPS; /* a new arg should be introduced to select the format */
  gl2ps.title = title;
  gl2ps.producer = producer;
  gl2ps.sort = sort;
  gl2ps.options = options;
  gl2ps.colormode = colormode;
  gl2ps.buffersize = buffersize > 0 ? buffersize : 2048 * 2048;
  gl2ps.feedback = (GLfloat*)gl2psMalloc(gl2ps.buffersize * sizeof(GLfloat));
  gl2ps.primitives = gl2psListCreate(500, 500, sizeof(GL2PSprimitive*));

  if(gl2ps.colormode == GL_RGBA){
    gl2ps.colorsize = 0;
    gl2ps.colormap = NULL;
  }
  else if(gl2ps.colormode == GL_COLOR_INDEX){
    if(!colorsize || !colormap)
      gl2psMsg(GL2PS_ERROR, "Missing colormap for GL_COLOR_INDEX rendering");
    if(gl2ps.colormap) 
      gl2psFree(gl2ps.colormap);
    gl2ps.colorsize = colorsize;
    gl2ps.colormap = (GL2PSrgba*)gl2psMalloc(gl2ps.colorsize * sizeof(GL2PSrgba));
    memcpy(gl2ps.colormap, colormap, gl2ps.colorsize * sizeof(GL2PSrgba));
  }
  else
    gl2psMsg(GL2PS_ERROR, "Unknown color mode in gl2psBeginPage");

  if(stream)
    gl2ps.stream = stream;
  else
    gl2psMsg(GL2PS_ERROR, "Bad file pointer");

  glFeedbackBuffer(gl2ps.buffersize, GL_3D_COLOR, gl2ps.feedback);
  glRenderMode(GL_FEEDBACK);  
}

GLint gl2psEndPage(GLvoid){
  GL2PSbsptree   *root;
  GL2PSxyz        eye={0., 0., 100000.};
  GLint           shademodel, res;
  void          (*phead)(GLvoid);
  void          (*pprim)(GLvoid *a, GLvoid *b);
  void          (*pfoot)(GLvoid);

  glGetIntegerv(GL_SHADE_MODEL, &shademodel);
  gl2ps.shade = (shademodel == GL_SMOOTH);

  res = gl2psParseFeedbackBuffer();

  if(gl2ps.feedback) gl2psFree(gl2ps.feedback);

  if(res == GL2PS_SUCCESS){

    switch(gl2ps.format){
      /* other vector formats should go here */
    case GL2PS_EPS :
    default :
      phead = gl2psPrintPostscriptHeader;
      pprim = gl2psPrintPostscriptPrimitive;
      pfoot = gl2psPrintPostscriptFooter;
      break;
    }

    phead();
    switch(gl2ps.sort){
    case GL2PS_NO_SORT :
      gl2psListAction(gl2ps.primitives, pprim);
      gl2psListAction(gl2ps.primitives, gl2psFreePrimitive);
      gl2psListDelete(gl2ps.primitives);
      res = GL2PS_SUCCESS;
      break;
    case GL2PS_SIMPLE_SORT :
      gl2psListSort(gl2ps.primitives, gl2psCompareDepth);
      gl2psListActionInverse(gl2ps.primitives, pprim);
      gl2psListAction(gl2ps.primitives, gl2psFreePrimitive);
      gl2psListDelete(gl2ps.primitives);
      res = GL2PS_SUCCESS;
      break;
    case GL2PS_BSP_SORT :
      root = (GL2PSbsptree*)gl2psMalloc(sizeof(GL2PSbsptree));
      gl2psBuildBspTree(root, gl2ps.primitives);
      if(gl2ps.boundary) gl2psBuildPolygonBoundary(root);
      if(gl2ps.options & GL2PS_OCCLUSION_CULL){
	gl2psTraverseBspTree(root, eye, -GL2PS_EPSILON, gl2psLess,
			     gl2psAddInImage);
      }
      gl2psTraverseBspTree(root, eye, GL2PS_EPSILON, gl2psGreater, 
			   pprim);
      gl2psFreeBspTree(root);
      res = GL2PS_SUCCESS;
      break;
    default :
      gl2psMsg(GL2PS_ERROR, "Unknown sorting algorithm");
    }
    pfoot();
    fflush(gl2ps.stream);

  }

  if(gl2ps.colormap) gl2psFree(gl2ps.colormap);

  return res;
}

GLvoid gl2psText(char *str, char *fontname, GLint fontsize){
  GLfloat         pos[4];
  GL2PSprimitive  *prim;
  GLint           len;

  prim = (GL2PSprimitive *)gl2psMalloc(sizeof(GL2PSprimitive));
  prim->type = GL2PS_TEXT;
  prim->boundary = 0;
  prim->numverts = 1;
  prim->verts = (GL2PSvertex *)gl2psMalloc(sizeof(GL2PSvertex));
  glGetFloatv(GL_CURRENT_RASTER_POSITION, pos);
  prim->verts[0].xyz[0] = pos[0];
  prim->verts[0].xyz[1] = pos[1];
  prim->verts[0].xyz[2] = pos[2];
  prim->depth = pos[2];
  prim->dash = 0;
  prim->width = 1;
  glGetFloatv(GL_CURRENT_RASTER_COLOR, prim->verts[0].rgba);
  prim->text = (GL2PSstring*)gl2psMalloc(sizeof(GL2PSstring));
  if((len = strlen(str))){
    prim->text->str = (char*)gl2psMalloc(len*sizeof(char));
    strcpy(prim->text->str, str);
  }
  else
    prim->text->str = "";
  prim->text->fontname = fontname;
  prim->text->fontsize = fontsize;
  gl2psListAdd(gl2ps.primitives, &prim);
}

GLvoid gl2psEnable(GLint mode){
  switch(mode){
  case GL2PS_POLYGON_OFFSET_FILL :
    glPassThrough(GL2PS_BEGIN_POLYGON_OFFSET_FILL);
    glGetFloatv(GL_POLYGON_OFFSET_FACTOR, &gl2ps.offset[0]);
    glGetFloatv(GL_POLYGON_OFFSET_UNITS, &gl2ps.offset[1]);
    break;
  case GL2PS_POLYGON_BOUNDARY :
    glPassThrough(GL2PS_BEGIN_POLYGON_BOUNDARY);
    break;
  case GL2PS_LINE_STIPPLE :
    glPassThrough(GL2PS_BEGIN_LINE_STIPPLE);
    break;
  default :
    gl2psMsg(GL2PS_WARNING, "Unknown mode in gl2psEnable");
    break;
  }
}

GLvoid gl2psDisable(GLint mode){
  switch(mode){
  case GL2PS_POLYGON_OFFSET_FILL :
    glPassThrough(GL2PS_END_POLYGON_OFFSET_FILL);
    break;
  case GL2PS_POLYGON_BOUNDARY :
    glPassThrough(GL2PS_END_POLYGON_BOUNDARY);
    break;
  case GL2PS_LINE_STIPPLE :
    glPassThrough(GL2PS_END_LINE_STIPPLE);
    break;
  default :
    gl2psMsg(GL2PS_WARNING, "Unknown mode in gl2psDisable");
    break;
  }
}

GLvoid gl2psPointSize(GLfloat value){
  glPassThrough(GL2PS_SET_POINT_SIZE);
  glPassThrough(value);
}

GLvoid gl2psLineWidth(GLfloat value){
  glPassThrough(GL2PS_SET_LINE_WIDTH);
  glPassThrough(value);
}
