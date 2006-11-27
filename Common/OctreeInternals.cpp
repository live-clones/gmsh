// $Id: OctreeInternals.cpp,v 1.2 2006-11-27 22:22:07 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s): 
//   We lost track of the origin of this octree code. If you happen to
//   know the author of the original routines, please send us an email.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <list>

#include "Message.h"
#include "OctreeInternals.h"

using std::list;

int initializeOctantBuckets(double *_orig, double *_size, int _maxElem,
			    octantBucket **buckets_head, globalInfo **globalPara)
// Initialize the buckets                                          
// Given by user: orig and size -- information about the domain    
//                maxElem -- maximum number of elements per bucket 
// Return: buckets -- pointer to the begin of buckets              
//         globalPara -- some info about the buckets               
// At last, 1 will be returned if succeed, otherwise, return 0     
{
  int i, j, k, tmp1; 
  int p = 1;
  int initial_buckets_num;  // which is a number of 8^p form for integer p 
  double tmp[3], error[3];
  octantBucket *buckets;

  for (i = 0; i < 3; i++)
    error[i]= _size[i]*0.01;

  initial_buckets_num = (int)pow(8., p); // it is actually 8 

  (*globalPara) = new globalInfo;
  (*globalPara)->maxPrecision = 1;
  (*globalPara)->maxElements = _maxElem;
  (*globalPara)->ptrToPrevElement = NULL;

  for (i = 0; i < 3; i++) {
    (*globalPara)->origin[i] = _orig[i];
    (*globalPara)->size[i] = _size[i];
  }

  (*globalPara)->numBuckets = initial_buckets_num;
  *buckets_head = new octantBucket;
  if (!(*buckets_head)) {
    Msg(GERROR, "initializeOctantBuckets could not allocate enough space");
    return (0);
  } // if could not allocate buckets 

  buckets = new octantBucket[8];
  if (!buckets) { 
    Msg(GERROR, "initializeOctantBuckets could not allocate enough space");
    return (0);
  }

  (*buckets_head)->next = buckets;
  (*buckets_head)->parent = NULL;
  (*buckets_head)->numElements = 0;
  (*buckets_head)->lhead = NULL;
  (*buckets_head)->precision = 0;
  for (i = 0; i< 3; i++) {
    (*buckets_head)->minPt[i] = _orig[i]-error[i];
    (*buckets_head)->maxPt[i] = _size[i]+_orig[i]+error[i];
  }

  for (i = 0; i < (*globalPara)->numBuckets; i++) {
    buckets[i].numElements = 0;
    buckets[i].lhead = NULL;
    buckets[i].next = NULL;
    buckets[i].parent = *buckets_head;
    buckets[i].precision = 1;
  } 
  
  tmp1 = (int)(pow(2., p));
  for (i = 0; i < 3; i++) {
    tmp[i] = (double)(_size[i]+2*error[i])/tmp1;
  }

  for (k = 0; k < tmp1; k++) {
    for (j = 0; j < tmp1; j++) {
      for (i = 0; i < tmp1; i++) {
	buckets[i+j*tmp1+k*tmp1*tmp1].minPt[0] = (*buckets_head)->minPt[0] + tmp[0]*i;
	buckets[i+j*tmp1+k*tmp1*tmp1].minPt[1] = (*buckets_head)->minPt[1] + tmp[1]*j;
	buckets[i+j*tmp1+k*tmp1*tmp1].minPt[2] = (*buckets_head)->minPt[2] + tmp[2]*k;
	buckets[i+j*tmp1+k*tmp1*tmp1].maxPt[0] = (*buckets_head)->minPt[0] + tmp[0]*(i+1);
	buckets[i+j*tmp1+k*tmp1*tmp1].maxPt[1] = (*buckets_head)->minPt[1] + tmp[1]*(j+1);
	buckets[i+j*tmp1+k*tmp1*tmp1].maxPt[2] = (*buckets_head)->minPt[2] + tmp[2]*(k+1);
      }
    }
  }

#if 0
  for (i = 0; i < 8; i++) {
    printf(" bucket %d : min[0]=%f, min[1]=%f, min[2]=%f, max[0]= %f, max[1]=%f, max[3]=%f\n",
	   i,buckets[i].minPt[0],buckets[i].minPt[1],
	   buckets[i].minPt[2], buckets[i].maxPt[0], buckets[i].maxPt[1],
	   buckets[i].maxPt[2]);                   
    printf("bucket elements link list: bucket->lhead = %d\n", buckets[i].lhead);
  }
#endif

  return (1);
}

int addElement2Bucket(octantBucket *_bucket, void * _element, 
		      double *_minBB, double *_maxBB,
		      double *_ele_centroid, globalInfo *_globalPara)
// Add another element to the octant bucket's list.                    
// If the bucket contains too many elements after adding this element, 
// refine this bucket and reallocate the elements of this bucket       
// Given:- the octant bucket, - the element                            
//       - the element's minimum and maximum x,y,z                     
//       - the element's centroid,  - global information               
// Check if element has already been added - if not, return 1          
// for successfully adding, otherwise return -1                        
{
  int i, flag = 1;
  ELink ptr1, ptr2;
  octantBucket *ptrBucket;
  
  // check for duplicates 
  if ( checkElementInBucket(_bucket, _element) == 1) return -1; 

  // printf("\n addToBucket...\n"); 
  // ptr1 = (ELink) malloc(sizeof(Elem));
  ptr1 = new Elem;
  (_globalPara->listAllElements).push_back(_element);
 
  ptr1-> next = _bucket->lhead;
  ptr1-> region = _element; 

  for (i = 0; i < 3; i++) {  
    ptr1->minPt[i] = _minBB[i];
    ptr1->maxPt[i] = _maxBB[i];
    ptr1->centroid[i] = _ele_centroid[i]; 
    // printf(" %7.2f->%-7.2f",ptr1->minPt[i], ptr1->maxPt[i]); 
  } 
  
  _bucket->lhead = ptr1;
  (_bucket->numElements)++;

#if 0
  printf("bucket element list: bucket->lhead = %d", _bucket->lhead);
  printf(" numElements = %d\n",_bucket->numElements); 
  printf("the element is add to this bucket: (%f, %f, %f) to (%f, %f, %f)\n",
	 _bucket->minPt[0],_bucket->minPt[1], _bucket->minPt[2], _bucket->maxPt[0],
	 _bucket->maxPt[1], _bucket->maxPt[2]);
#endif

  // check whether the number of elements in the bucket > maxElements 
  // if true, refine the bucket and reallocate the elements           
  while ( flag == 1) {
    flag = 0;
    if (_bucket->numElements > _globalPara->maxElements) {	

      // printf(" going to subdivide\n");

      subdivideOctantBucket(_bucket, _globalPara);

      // printf("finish subdivede \n");

      ptr1 = _bucket->lhead;
      while (ptr1 != NULL) {
	ptrBucket = findElementBucket(_bucket, ptr1->centroid);
	ptr2 = ptr1;
	ptr1 = ptr1->next;
	if (ptrBucket == NULL)
	  Msg(GERROR, "Wrong , ptrBucket = NULL. A bug here!");
	ptr2->next = ptrBucket->lhead;
	ptrBucket->lhead = ptr2;
	(ptrBucket->numElements)++;
	if (ptrBucket->numElements > _globalPara->maxElements) {
	  flag = 1;
	  _bucket->lhead = NULL;	
	  _bucket = ptrBucket;
	}	
      }       	
      if (flag == 0) _bucket->lhead = NULL;
    }
  }
  return 1;
}

int checkElementInBucket(octantBucket *_bucket, void* _element)
// Given an elememt and an octant bucket, check if the element     
// exists in the bucket's element list. return 1 if already exits, 
// otherwise, return 0                                             
{
  ELink ptr;
  for (ptr = _bucket->lhead; ptr != NULL; ptr = ptr->next) {
    // changed ****, compare the objected pointed by the void *. 
    if (ptr->region == _element)    return 1; 
  }
  return 0;
}


octantBucket *findElementBucket(octantBucket *_buckets_head, double *_pt)
// Find the leaf bucket which contains the point _pt	  
// given parameter: _buckets --- the point to buckets head 
//                  _pt --- the point to find             
// Return the pointer to the bucket contains the point    
// if fail, return NULL                                   	 
{
  int i, j;
  int num = 8;
  octantBucket *prevbucket = NULL;
  octantBucket *tmpbucket = _buckets_head->next;

  while (tmpbucket != NULL) {
    for (i = 0; i < num; i ++) {
      for (j = 0; j < 3; j++) {	
	if (tmpbucket[i].minPt[j] > _pt[j] || 
	    tmpbucket[i].maxPt[j] < _pt[j])
	  break;
      }
      if (j == 3) {
	prevbucket = tmpbucket+i;
	tmpbucket = tmpbucket[i].next;
	break;
      }		
    } // for loop i 
    if (i == num) {
      //	printf("Error, no bucket contains the given point! ");
      return NULL;
    }		
  } // for while loop 
  return prevbucket;
}


int subdivideOctantBucket(octantBucket *_bucket, globalInfo *_globalPara)
// To many elements are in this octant bucket, so try to refine      
// Returns 1 for success, 0 for failure (no memory left).       
{
  int i, j, k, tmp1;
  int numBuck = 8;
  double tmp[3];

  _bucket->next = new octantBucket[8];   
  // _bucket->next  = (octantBucket *) calloc(numBuck,sizeof(octantBucket));

  if (!_bucket->next) {
    fprintf(stderr,"Error, subdivideOctantBucket could not allocate enough space\n");
    return 0;
  }

  _globalPara->numBuckets +=8;
  if (_bucket->precision == _globalPara->maxPrecision)
    _globalPara->maxPrecision++;
  for (i = 0; i < numBuck; i++) {
    (_bucket->next[i]).numElements = 0;
    (_bucket->next[i]).lhead = NULL;
    (_bucket->next[i]).next = NULL;
    (_bucket->next[i]).parent = _bucket;
    (_bucket->next[i]).precision = _bucket->precision+1;
  } 
  
  tmp1 = 2;
  for (i = 0; i < 3; i++) {
    tmp[i] = ((double)(_bucket->maxPt[i]-_bucket->minPt[i]))/tmp1;
  }

  for (k = 0; k < tmp1; k++) {
    for (j = 0; j < tmp1; j++) {
      for (i = 0; i < tmp1; i++) {
        _bucket->next[i+j*tmp1+k*tmp1*tmp1].minPt[0] = _bucket->minPt[0] + tmp[0]*i;
        _bucket->next[i+j*tmp1+k*tmp1*tmp1].minPt[1] = _bucket->minPt[1] + tmp[1]*j;
        _bucket->next[i+j*tmp1+k*tmp1*tmp1].minPt[2] = _bucket->minPt[2] + tmp[2]*k;
        _bucket->next[i+j*tmp1+k*tmp1*tmp1].maxPt[0] = _bucket->minPt[0] + tmp[0]*(i+1);
        _bucket->next[i+j*tmp1+k*tmp1*tmp1].maxPt[1] = _bucket->minPt[1] + tmp[1]*(j+1);
        _bucket->next[i+j*tmp1+k*tmp1*tmp1].maxPt[2] = _bucket->minPt[2] + tmp[2]*(k+1);
      }
    }
  }

  return 1;
}

void * searchElement(octantBucket *_buckets_head, double *_pt, globalInfo *_globalPara,
		     BBFunction BBElement, InEleFunction xyzInElement) 
{
  int flag;
  octantBucket *ptrBucket;
  ELink ptr1;  
  list<void *>::iterator iter;
  void * ptrToEle = _globalPara->ptrToPrevElement;

  if (ptrToEle) {
    flag = xyzInElementBB(_pt, ptrToEle, BBElement);
    if (flag == 1)
      flag = xyzInElement(ptrToEle, _pt);
    if (flag == 1) return ptrToEle;
  }
    	
  ptrBucket = findElementBucket(_buckets_head, _pt);
  if (ptrBucket == NULL) {
    // printf("Error! the point is not in the domain.\n");
    return NULL;
  }	

  ptr1 = ptrBucket->lhead;

#if 0
  printf("point %lf %lf %lf has been found in bucket %lf %lf %fl -> %lf %lf %lf  %p\n",
	 _pt[0],_pt[1],_pt[2], ptrBucket->minPt[0],ptrBucket->minPt[1],ptrBucket->minPt[2],
	 ptrBucket->maxPt[0],ptrBucket->maxPt[1],ptrBucket->maxPt[2], ptr1);
  if (ptr1 == NULL) {
    printf("empty element list for centroid list!?\n, possible!");
  }
#endif

  while (ptr1 != NULL){
    flag = xyzInElementBB(_pt, ptr1->region, BBElement);
    if (flag == 1) 
      flag = xyzInElement(ptr1->region, _pt);
    if (flag == 1) {
      _globalPara->ptrToPrevElement = ptr1->region;
      return ptr1->region;
    }	
    ptr1 = ptr1->next;
  }
 
  for (iter = (ptrBucket->listBB).begin(); 
       iter != (ptrBucket->listBB).end(); iter++){
    flag = xyzInElementBB(_pt, *iter, BBElement);
    if (flag == 1)
      flag = xyzInElement(*iter, _pt);
    if (flag == 1) {
      _globalPara->ptrToPrevElement = *iter;
      return *iter;
    }
  }

  // printf("This point is not found in all elements! It is not in the domain \n"); 
  return NULL;
}

int xyzInElementBB(double *_xyz, void * _region, BBFunction _BBElement)
// Check if xyz is in the region's bounding box, return 1 if true, 0 otherwise 
// BBElement is the function given by user to find the bounding box            
{		   
  int i;
  double minPt[3]; // corner with smallest x,y,z coords 
  double maxPt[3]; // corner with largest x,y,z coords 

  (*_BBElement)(_region, minPt, maxPt);

  for (i = 0; i < 3; i++) {
    if (_xyz[i] > maxPt[i] || _xyz[i] < minPt[i]) return 0;
  } // for ith direction

  return 1;
}

void insertOneBB(void* _region, double *_minPt, double *_maxPt, octantBucket *_bucket)
{
  int i;
  ELink ptr;
  for (i = 0; i < 3; i++) {
    if (_bucket->minPt[i] > _maxPt[i] || _bucket->maxPt[i] < _minPt[i])
      return;
  }
  if (_bucket->next == NULL) {
    ptr = _bucket->lhead;
    while (ptr != NULL) {
      if (ptr->region == _region) return;
      ptr = ptr->next;
    }

    _bucket->listBB.insert(_bucket->listBB.end(),_region);	
    return;
  }
    	
  for (i = 0; i < 8; i++)
    insertOneBB(_region, _minPt, _maxPt, _bucket->next+i);
  return;
}

void * searchAllElements(octantBucket *_buckets_head, double *_pt, globalInfo *_globalPara,
			 BBFunction BBElement, InEleFunction xyzInElement, list<void *> *_elements)
{
  int flag, flag1;
  octantBucket *ptrBucket;
  list<void *>::iterator iter;

  ptrBucket = findElementBucket(_buckets_head, _pt);
  if (ptrBucket == NULL) {
    Msg(GERROR, "The point is not in the domain");
    return NULL;
  }

#if 0
  printf("point %lf %lf %lf has been found in bucket %lf %lf %fl -> %lf %lf %lf  %p\n",
	 _pt[0],_pt[1],_pt[2], ptrBucket->minPt[0],ptrBucket->minPt[1],ptrBucket->minPt[2],
	 ptrBucket->maxPt[0],ptrBucket->maxPt[1],ptrBucket->maxPt[2], ptr1);
  
  if (ptr1 == NULL) {
    printf("empty element list for centroid list!?\n, possible!");
  }
#endif

  flag1 = 0;
  for (iter = (ptrBucket->listBB).begin(); 
       iter != (ptrBucket->listBB).end(); iter++){
    // printf("Enter 1 \n");	
    flag = xyzInElementBB(_pt, *iter, BBElement);
    if (flag == 1)
      flag = xyzInElement(*iter, _pt);
    if (flag == 1) { 
      _elements->push_back(*iter);        
      flag1 = 1;
    }	
  }

  if (flag1)
    return (void *)(_elements);
  
  Msg(WARNING, "This point is not found in any element! It is not in the domain");
  return NULL;
}
