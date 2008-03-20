#ifndef _OCTREE_INTERNALS_H_
#define _OCTREE_INTERNALS_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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

#include <list>

// file of function prototypes and macro constants 
typedef void (*BBFunction)(void *, double*, double*);
typedef int (*InEleFunction)(void *, double *); 
typedef void (*CentroidFunction)(void *, double *);

// structure for list of elements in an octant 
typedef struct elem {
  void * region;  // the pointer to a mesh Db region 
  double centroid[3]; // centroid of element bounding box inside of the octant 
  double minPt[3]; // corner of element bounding box nearest the origin 
  double maxPt[3]; // corner of elem bound box furthest from the origin  
  struct elem *next; // link to next item in list, NULL if end 
} Elem;
typedef Elem *ELink;

// stucture for octant buckets 
struct bucket {
  double minPt[3];   //  the point with the smallest coordinates 
  double maxPt[3];   //  the point with the biggest coordinates 
  int numElements; // number of elements contained by bucket 
  int precision;   // the level of precision of the bucket 
  ELink lhead; // list of elements in bucket, if NULL -> no elements 
  std::list<void *> listBB; // list of elements in bucket by Bounding Box       
  struct bucket *next; // link to ragged digit extensions to bucket array 
  struct bucket *parent; // link to the parent bucket 
};
typedef struct bucket octantBucket; 

// structure for global information and requirment 
struct global {
  int numBuckets; // number of octant buckets in initial grid array 
  int maxElements; // max. number of elements allowed in an octant 
  int maxPrecision; // current maximum octant precision for model 
  double origin[3];   // smallest x,y, z of model's bounding box  
  double size[3];    // size in x, y, z of model bounding box 
  void * ptrToPrevElement;      
  std::list<void *> listAllElements;
};
typedef struct global globalInfo;

typedef struct
{
  globalInfo *info;
  octantBucket *root;
  BBFunction function_BB;
  InEleFunction function_inElement; 
  CentroidFunction function_centroid; 
}Octree;

void refineOctants(octantBucket *buckets,
                   globalInfo *globalPara);

int addElement2Bucket(octantBucket *bucket, void * element, 
                      double *minBB, double *maxBB,
                      double *ele_centroid, globalInfo *globalPara);
int subdivideOctantBucket(octantBucket *bucket, globalInfo *globalPara);
int initializeOctantBuckets(double *orig, double *size, int maxElem,
                            octantBucket **buckets, globalInfo **globalPara);
int checkElementInBucket(octantBucket *bucket, void * element); 
octantBucket* findElementBucket(octantBucket *buckets, double *pt);
void * searchElement(octantBucket *buckets, double *pt, 
                     globalInfo *globalPara, BBFunction BBElement, 
                     InEleFunction xyzInElement);
int xyzInElementBB(double *xyz, void *region, BBFunction BBElement);
void insertOneBB(void *, double *, double *, octantBucket *);
void * searchAllElements(octantBucket *_buckets_head, double *_pt, globalInfo *_globalPara,
                         BBFunction BBElement, InEleFunction xyzInElement, 
                         std::list<void *> *_elements);

#endif
