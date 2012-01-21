// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "Octree.h"

Octree* Octree_Create(int maxElements, double origin[3], double size[3],   
                      void  (*BB)(void *, double*, double*),
                      void  (*Centroid)(void *, double *),
                      int   (*InEle)(void *, double *))
{
  Octree *myOctree = new Octree;
  initializeOctantBuckets(origin, size, maxElements,
                          &(myOctree->root), &(myOctree->info));       
  myOctree->function_BB = BB;
  myOctree->function_centroid = Centroid;
  myOctree->function_inElement = InEle;
  return myOctree;
}

void free_buckets(octantBucket * bucket)
{
  int i, numBuck = 8;
  ELink ptr1, ptr2;

  if(bucket->next == NULL) {
    ptr1 = bucket->lhead;
    while(ptr1 != NULL) {
      ptr2 = ptr1;
      ptr1 = ptr1->next;
      delete ptr2;
    }
    bucket->listBB.clear(); 
    return;
  }

  for(i = numBuck-1; i >= 0; i--) 
    free_buckets((bucket->next)+i);         
  delete []bucket->next;
  return;
}

void Octree_Delete(Octree *myOctree)
{
  if(!myOctree) return;
  delete myOctree->info;
  free_buckets(myOctree->root);
  delete myOctree->root;
  delete myOctree;
}

void Octree_Insert(void *element, Octree *myOctree)
{
  if(!myOctree) return;
  double minBB[3], maxBB[3], centroid[3];
  octantBucket *bucket;
  (*(myOctree->function_BB))(element, minBB, maxBB);
  (*(myOctree->function_centroid))(element, centroid);
  bucket = findElementBucket(myOctree->root, centroid);
  if(bucket)
    addElement2Bucket(bucket, element, minBB, maxBB,
                      centroid, myOctree->info);  
}

void Octree_Arrange(Octree *myOctree)
{
  if(!myOctree) return;
  //std::list<void *>::iterator iter;
  std::vector<void *>::iterator iter;
  double minPt[3], maxPt[3];
  for(iter = myOctree->info->listAllElements.begin(); iter!= 
      myOctree->info->listAllElements.end(); iter++) {
    (*(myOctree->function_BB))(*iter, minPt, maxPt);
    insertOneBB(*iter, minPt, maxPt, myOctree->root);
  }
  myOctree->info->listAllElements.clear();
}   

void *Octree_Search(double *pt, Octree *myOctree)
{
  if(!myOctree) return 0;
  return searchElement(myOctree->root, pt, myOctree->info, 
                       myOctree->function_BB, myOctree->function_inElement);
}

void Octree_SearchAll(double *pt, Octree *myOctree, std::vector<void*> *output)
{
  if(!myOctree) return;
  searchAllElements(myOctree->root, pt, myOctree->info, myOctree->function_BB,
                    myOctree->function_inElement, output);      
}
