#ifndef memorypoolCXX
#define memorypoolCXX

#include "tetgen.h"

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// restart()    Deallocate all objects in this pool.                         //
//                                                                           //
// The pool returns to a fresh state, like after it was initialized, except  //
// that no memory is freed to the operating system.  Rather, the previously  //
// allocated blocks are ready to be used.                                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::arraypool::restart()
{
  objects = 0l;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// poolinit()    Initialize an arraypool for allocation of objects.          //
//                                                                           //
// Before the pool may be used, it must be initialized by this procedure.    //
// After initialization, memory can be allocated and freed in this pool.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::arraypool::poolinit(int sizeofobject, int log2objperblk)
{
  // Each object must be at least one byte long.
  objectbytes = sizeofobject > 1 ? sizeofobject : 1;

  log2objectsperblock = log2objperblk;
  // Compute the number of objects in each block.
  objectsperblock = ((int) 1) << log2objectsperblock;

  // No memory has been allocated.
  totalmemory = 0l;
  // The top array has not been allocated yet.
  toparray = (char **) NULL;
  toparraylen = 0;

  // Ready all indices to be allocated.
  restart();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// arraypool()    The constructor and destructor.                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenmesh::arraypool::arraypool(int sizeofobject, int log2objperblk)
{
  poolinit(sizeofobject, log2objperblk);
}

tetgenmesh::arraypool::~arraypool()
{
  int i;

  // Has anything been allocated at all?
  if (toparray != (char **) NULL) {
    // Walk through the top array.
    for (i = 0; i < toparraylen; i++) {
      // Check every pointer; NULLs may be scattered randomly.
      if (toparray[i] != (char *) NULL) {
        // Free an allocated block.
        free((void *) toparray[i]);
      }
    }
    // Free the top array.
    free((void *) toparray);
  }

  // The top array is no longer allocated.
  toparray = (char **) NULL;
  toparraylen = 0;
  objects = 0;
  totalmemory = 0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// getblock()    Return (and perhaps create) the block containing the object //
//               with a given index.                                         //
//                                                                           //
// This function takes care of allocating or resizing the top array if nece- //
// ssary, and of allocating the block if it hasn't yet been allocated.       //
//                                                                           //
// Return a pointer to the beginning of the block (NOT the object).          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

char* tetgenmesh::arraypool::getblock(int objectindex)
{
  char **newarray;
  char *block;
  int newsize;
  int topindex;
  int i;

  // Compute the index in the top array (upper bits).
  topindex = objectindex >> log2objectsperblock;
  // Does the top array need to be allocated or resized?
  if (toparray == (char **) NULL) {
    // Allocate the top array big enough to hold 'topindex', and NULL out
    //   its contents.
    newsize = topindex + 128;
    toparray = (char **) malloc((size_t) (newsize * sizeof(char *)));
    toparraylen = newsize;
    for (i = 0; i < newsize; i++) {
      toparray[i] = (char *) NULL;
    }
    // Account for the memory.
    totalmemory = newsize * (unsigned long) sizeof(char *);
  } else if (topindex >= toparraylen) {
    // Resize the top array, making sure it holds 'topindex'.
    newsize = 3 * toparraylen;
    if (topindex >= newsize) {
      newsize = topindex + 128;
    }
    // Allocate the new array, copy the contents, NULL out the rest, and
    //   free the old array.
    newarray = (char **) malloc((size_t) (newsize * sizeof(char *)));
    for (i = 0; i < toparraylen; i++) {
      newarray[i] = toparray[i];
    }
    for (i = toparraylen; i < newsize; i++) {
      newarray[i] = (char *) NULL;
    }
    free(toparray);
    // Account for the memory.
    totalmemory += (newsize - toparraylen) * sizeof(char *);
    toparray = newarray;
    toparraylen = newsize;
  }

  // Find the block, or learn that it hasn't been allocated yet.
  block = toparray[topindex];
  if (block == (char *) NULL) {
    // Allocate a block at this index.
    block = (char *) malloc((size_t) (objectsperblock * objectbytes));
    toparray[topindex] = block;
    // Account for the memory.
    totalmemory += objectsperblock * objectbytes;
  }

  // Return a pointer to the block.
  return block;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// lookup()    Return the pointer to the object with a given index, or NULL  //
//             if the object's block doesn't exist yet.                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void* tetgenmesh::arraypool::lookup(int objectindex)
{
  char *block;
  int topindex;

  // Has the top array been allocated yet?
  if (toparray == (char **) NULL) {
    return (void *) NULL;
  }

  // Compute the index in the top array (upper bits).
  topindex = objectindex >> log2objectsperblock;
  // Does the top index fit in the top array?
  if (topindex >= toparraylen) {
    return (void *) NULL;
  }

  // Find the block, or learn that it hasn't been allocated yet.
  block = toparray[topindex];
  if (block == (char *) NULL) {
    return (void *) NULL;
  }

  // Compute a pointer to the object with the given index.  Note that
  //   'objectsperblock' is a power of two, so the & operation is a bit mask
  //   that preserves the lower bits.
  return (void *)(block + (objectindex & (objectsperblock - 1)) * objectbytes);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// newindex()    Allocate space for a fresh object from the pool.            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int tetgenmesh::arraypool::newindex(void **newptr)
{
  void *newobject;
  int newindex;

  // Allocate an object at index 'firstvirgin'.
  newindex = objects;
  newobject = (void *) (getblock(objects) +
    (objects & (objectsperblock - 1)) * objectbytes);
  objects++;

  // If 'newptr' is not NULL, use it to return a pointer to the object.
  if (newptr != (void **) NULL) {
    *newptr = newobject;
  }
  return newindex;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// restart()   Deallocate all items in this pool.                            //
//                                                                           //
// The pool is returned to its starting state, except that no memory is      //
// freed to the operating system.  Rather, the previously allocated blocks   //
// are ready to be reused.                                                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::memorypool::restart()
{
  unsigned long alignptr;

  items = 0;
  maxitems = 0;

  // Set the currently active block.
  nowblock = firstblock;
  // Find the first item in the pool.  Increment by the size of (void *).
  alignptr = (unsigned long) (nowblock + 1);
  // Align the item on an `alignbytes'-byte boundary.
  nextitem = (void *)
    (alignptr + (unsigned long) alignbytes -
     (alignptr % (unsigned long) alignbytes));
  // There are lots of unallocated items left in this block.
  unallocateditems = itemsperblock;
  // The stack of deallocated items is empty.
  deaditemstack = (void *) NULL;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// alloc()   Allocate space for an item.                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void* tetgenmesh::memorypool::alloc()
{
  void *newitem;
  void **newblock;
  unsigned long alignptr;

  // First check the linked list of dead items.  If the list is not 
  //   empty, allocate an item from the list rather than a fresh one.
  if (deaditemstack != (void *) NULL) {
    newitem = deaditemstack;                     // Take first item in list.
    deaditemstack = * (void **) deaditemstack;
  } else {
    // Check if there are any free items left in the current block.
    if (unallocateditems == 0) {
      // Check if another block must be allocated.
      if (*nowblock == (void *) NULL) {
        // Allocate a new block of items, pointed to by the previous block.
        newblock = (void **) malloc(itemsperblock * itembytes + sizeof(void *) 
                                    + alignbytes);
        if (newblock == (void **) NULL) {
          printf("Error:  Out of memory.\n");
          terminatetetgen(1);
        }
        *nowblock = (void *) newblock;
        // The next block pointer is NULL.
        *newblock = (void *) NULL;
      }
      // Move to the new block.
      nowblock = (void **) *nowblock;
      // Find the first item in the block.
      //   Increment by the size of (void *).
      alignptr = (unsigned long) (nowblock + 1);
      // Align the item on an `alignbytes'-byte boundary.
      nextitem = (void *)
        (alignptr + (unsigned long) alignbytes -
         (alignptr % (unsigned long) alignbytes));
      // There are lots of unallocated items left in this block.
      unallocateditems = itemsperblock;
    }
    // Allocate a new item.
    newitem = nextitem;
    // Advance `nextitem' pointer to next free item in block.
    if (itemwordtype == POINTER) {
      nextitem = (void *) ((void **) nextitem + itemwords);
    } else {
      nextitem = (void *) ((REAL *) nextitem + itemwords);
    }
    unallocateditems--;
    maxitems++;
  }
  items++;
  return newitem;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// dealloc()   Deallocate space for an item.                                 //
//                                                                           //
// The deallocated space is stored in a queue for later reuse.               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::memorypool::dealloc(void *dyingitem)
{
  // Push freshly killed item onto stack.
  *((void **) dyingitem) = deaditemstack;
  deaditemstack = dyingitem;
  items--;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// traversalinit()   Prepare to traverse the entire list of items.           //
//                                                                           //
// This routine is used in conjunction with traverse().                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::memorypool::traversalinit()
{
  unsigned long alignptr;

  // Begin the traversal in the first block.
  pathblock = firstblock;
  // Find the first item in the block.  Increment by the size of (void *).
  alignptr = (unsigned long) (pathblock + 1);
  // Align with item on an `alignbytes'-byte boundary.
  pathitem = (void *)
    (alignptr + (unsigned long) alignbytes -
     (alignptr % (unsigned long) alignbytes));
  // Set the number of items left in the current block.
  pathitemsleft = itemsperblock;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// traverse()   Find the next item in the list.                              //
//                                                                           //
// This routine is used in conjunction with traversalinit().  Be forewarned  //
// that this routine successively returns all items in the list, including   //
// deallocated ones on the deaditemqueue. It's up to you to figure out which //
// ones are actually dead.  It can usually be done more space-efficiently by //
// a routine that knows something about the structure of the item.           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void* tetgenmesh::memorypool::traverse()
{
  void *newitem;
  unsigned long alignptr;

  // Stop upon exhausting the list of items.
  if (pathitem == nextitem) {
    return (void *) NULL;
  }
  // Check whether any untraversed items remain in the current block.
  if (pathitemsleft == 0) {
    // Find the next block.
    pathblock = (void **) *pathblock;
    // Find the first item in the block.  Increment by the size of (void *).
    alignptr = (unsigned long) (pathblock + 1);
    // Align with item on an `alignbytes'-byte boundary.
    pathitem = (void *)
      (alignptr + (unsigned long) alignbytes -
       (alignptr % (unsigned long) alignbytes));
    // Set the number of items left in the current block.
    pathitemsleft = itemsperblock;
  }
  newitem = pathitem;
  // Find the next item in the block.
  if (itemwordtype == POINTER) {
    pathitem = (void *) ((void **) pathitem + itemwords);
  } else {
    pathitem = (void *) ((REAL *) pathitem + itemwords);
  }
  pathitemsleft--;
  return newitem;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// poolinit()    Initialize a pool of memory for allocation of items.        //
//                                                                           //
// A 'pool' is created whose records have size at least 'bytecount'.  Items  //
// will be allocated in `itemcount'-item blocks.  Each item is assumed to be //
// a collection of words, and either pointers or floating-point values are   //
// assumed to be the "primary" word type.  (The "primary" word type is used  //
// to determine alignment of items.)  If 'alignment' isn't zero, all items   //
// will be `alignment'-byte aligned in memory.  'alignment' must be either a //
// multiple or a factor of the primary word size;  powers of two are safe.   //
// 'alignment' is normally used to create a few unused bits at the bottom of //
// each item's pointer, in which information may be stored.                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::memorypool::poolinit(int bytecount, int itemcount,
  enum wordtype wtype, int alignment)
{
  int wordsize;

  // Initialize values in the pool.
  itemwordtype = wtype;
  wordsize = (itemwordtype == POINTER) ? sizeof(void *) : sizeof(REAL);
  // Find the proper alignment, which must be at least as large as:
  //   - The parameter `alignment'.
  //   - The primary word type, to avoid unaligned accesses.
  //   - sizeof(void *), so the stack of dead items can be maintained
  //       without unaligned accesses.
  if (alignment > wordsize) {
    alignbytes = alignment;
  } else {
    alignbytes = wordsize;
  }
  if ((int) sizeof(void *) > alignbytes) {
    alignbytes = (int) sizeof(void *);
  }
  itemwords = ((bytecount + alignbytes - 1) /  alignbytes)
            * (alignbytes / wordsize);
  itembytes = itemwords * wordsize;
  itemsperblock = itemcount;

  // Allocate a block of items.  Space for `itemsperblock' items and one
  //   pointer (to point to the next block) are allocated, as well as space
  //   to ensure alignment of the items. 
  firstblock = (void **) malloc(itemsperblock * itembytes + sizeof(void *)
                                + alignbytes); 
  if (firstblock == (void **) NULL) {
    printf("Error:  Out of memory.\n");
    terminatetetgen(1);
  }
  // Set the next block pointer to NULL.
  *(firstblock) = (void *) NULL;
  restart();
}

tetgenmesh::memorypool::memorypool(int bytecount, int itemcount,
  enum wordtype wtype, int alignment)
{
  poolinit(bytecount, itemcount, wtype, alignment);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// ~memorypool()   Free to the operating system all memory taken by a pool.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenmesh::memorypool::~memorypool()
{
  while (firstblock != (void **) NULL) {
    nowblock = (void **) *(firstblock);
    free(firstblock);
    firstblock = nowblock;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// initializepools()    Initialize pools of mesh elements.                   //
//                                                                           //
// The sizes of the tetrahedron, shellface, and point will be calculated.    //
// Some class variables, such as 'pointmarkindex', 'elemmarkindex', 'volume- //
// boundindex', 'dummypoint', etc, are initialized. The pools of tetrahedra, //
// points, subfaces, and segments are allocated.                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::initializepools()
{
  enum wordtype wtype;
  int ptsize, elesize, shsize;

  // A point contains 3 coordinates, 1 weight, plus 'n' attributes in REALs,
  //   and other fields, such as pointers, boundary markers, etc. The total
  //   size (in byte) of a point is calcualted below.
  ptsize = (4 + in->numberofpointattributes) * sizeof(REAL);
  // The index within each point at which an element pointer is found, where
  //   the index is measured in pointers. Ensure the index is aligned to a
  //   sizeof(tetrahedron)-byte address.
  point2tetindex = (ptsize + sizeof(tetrahedron) - 1) / sizeof(tetrahedron);
  // Increase the point size by two pointers, which are
  //   - a pointer to a tet, read by point2tet(), or
  //   - a pointer to a parent point, read by point2ppt().
  ptsize = (point2tetindex + 2) * sizeof(tetrahedron);
  // The index within each point at which the boundary marker is found,
  //   Ensure the marker is aligned to a sizeof(int)-byte address.
  pointmarkindex = (ptsize + sizeof(int) - 1) / sizeof(int);
  // Increase the point size by two integers, which are:
  //   - an integer for boundary marker, read by pointmark();
  //   - an integer for vertex type, read by pointtype();
  ptsize = (pointmarkindex + 2) * sizeof(int);
  // Decide the wordtype used in point pool.
  wtype = (sizeof(REAL) >= sizeof(tetrahedron)) ? FLOATINGPOINT : POINTER;
  // Initialize the pool of vertices.
  pointpool = new memorypool(ptsize, VERPERBLOCK, wtype, 0);
  
  // Initialize spaces for 'dummypoint'.
  dummypoint = new REAL[(ptsize + sizeof(REAL) - 1) / sizeof(REAL)];
  dummypoint[0] = dummypoint[1] = dummypoint[2] = dummypoint[3] = 0.0;
  pointmark(dummypoint) = -1;

  // The number of bytes occupied by a tetrahedron.  There are 4 pointers
  //   to other tetrahedra, 4 pointers to corners, and possibly 1 pointers
  //   to an array of subfaces/subsegments.
  elesize = (8 + (b->useshelles ? 2 : 0)) * sizeof(tetrahedron);
  // The index within each element at which its attributes are found, where
  //   the index is measured in REALs. 
  elemattribindex = (elesize + sizeof(REAL) - 1) / sizeof(REAL);
  // The index within each element at which the maximum voulme bound is
  //   found, where the index is measured in REALs.  Note that if the
  //   `b->regionattrib' flag is set, an additional attribute will be added.
  volumeboundindex = elemattribindex + in->numberoftetrahedronattributes
                   + (b->regionattrib > 0);
  // If element attributes or an constraint are needed, increase the number
  //   of bytes occupied by an element.
  elesize = (volumeboundindex + (b->varvolume > 0)) * sizeof(REAL);
  // The index within each element at which its marker is found, where the
  //   index is measured in ints.
  elemmarkerindex = (elesize + sizeof(int) - 1) / sizeof(int);
  // Increase the size by one interger.
  elesize = (elemmarkerindex + 1) * sizeof(int);
  // If -o2 switch is used, an additional pointer pointed to the list of
  //   higher order nodes is allocated for each element.
  highorderindex = (elesize + sizeof(tetrahedron) - 1) / sizeof(tetrahedron);
  if (b->order == 2) {
    elesize = (highorderindex + 1) * sizeof(tetrahedron);
  }
  // Having determined the memory size of an element, initialize the pools.
  tetrahedronpool = new memorypool(elesize, ELEPERBLOCK, POINTER, 16);

  if (b->useshelles) {
    // The number of bytes occupied by a subface.  The list of pointers
    //   stored in a subface are: three to other subfaces, three to corners,
    //   three to subsegments, one to an adjacent tetrahedron.
    shsize = 10 * sizeof(shellface);
    // The index within each subface at which the maximum area bound is
    //   found, where the index is measured in REALs.
    areaboundindex = (shsize + sizeof(REAL) - 1) / sizeof(REAL);
    // If -q switch is in use, increase the number of bytes occupied by
    //   a subface for saving maximum area bound.
    if (b->quality && checkconstraints) {
      shsize = (areaboundindex + 1) * sizeof(REAL);
    } else {
      shsize = areaboundindex * sizeof(REAL);
    }
    // The index within subface at which the facet marker is found. Ensure
    //   the marker is aligned to a sizeof(int)-byte address.
    shmarkindex = (shsize + sizeof(int) - 1) / sizeof(int);
    // Increase the number of bytes by two or three integers, one for facet
    //   marker, one for shellface type, and optionally one for pbc group.
    shsize = (shmarkindex + 2 + checkpbcs) * sizeof(int);
    // Initialize the pool of subfaces. Each subface record is eight-byte
    //   aligned so it has room to store an edge version (from 0 to 5) in
    //   the least three bits.
    subfacepool = new memorypool(shsize, SUBPERBLOCK, POINTER, 8);
    // Initialize the pool of subsegments.
    subsegpool = new memorypool(shsize, SUBPERBLOCK, POINTER, 8);

    // Initialize the pool for tet-subseg connections.
    tet2segpool = new memorypool(6*sizeof(shellface), SUBPERBLOCK, POINTER, 0);
    // Initialize the pool for tet-subface connections.
    tet2subpool = new memorypool(4*sizeof(shellface), SUBPERBLOCK, POINTER, 0);

    // Initialize arraypools for segment & facet recovery.
    subsegstack = new arraypool(sizeof(face), 10);
    subfacstack = new arraypool(sizeof(face), 10);

    // Initialize arraypools for surface Bowyer-Watson algorithm.
    caveshlist = new arraypool(sizeof(face), 8);
    caveshbdlist = new arraypool(sizeof(face), 8);
  }

  // Initialize the pool for flips.
  flippool = new memorypool(sizeof(badface), 1024, POINTER, 0);

  // Initialize the arraypools for Bowyer-Watson algorithm.
  cavetetlist = new arraypool(sizeof(triface), 10);
  cavebdrylist = new arraypool(sizeof(triface), 10);
  caveoldtetlist = new arraypool(sizeof(triface), 10);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetrahedrondealloc()    Deallocate space for a tet, marking it dead.      //
//                                                                           //
// Set the first vertex of 'dyingtet' to NULL. So we can detect dead tets    //
// when when traversing the list of all tetrahedra.                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::tetrahedrondealloc(tetrahedron *dyingtet)
{
  // Mark it as a dead tet.
  dyingtet[4] = (tetrahedron) NULL;

  if (b->useshelles) {
    // Dealloc the space to subfaces/subsegments.
    if (dyingtet[8] != NULL) {
      tet2segpool->dealloc((shellface *) dyingtet[8]);
    }
    if (dyingtet[9] != NULL) {
      tet2subpool->dealloc((shellface *) dyingtet[9]);
    }
  }

  // Actually pool->dealloc();
  *((void **) (dyingtet)) = tetrahedronpool->deaditemstack;
  tetrahedronpool->deaditemstack = (void *) (dyingtet);
  tetrahedronpool->items--;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetrahedrontraverse()    Traverse the tetrahedra, skipping dead ones.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenmesh::tetrahedron* tetgenmesh::tetrahedrontraverse()
{
  tetrahedron *newtetrahedron;

  // Skip dead and hull tetrahedra.
  do {
    newtetrahedron = (tetrahedron *) tetrahedronpool->traverse();
    if (newtetrahedron == (tetrahedron *) NULL) {
      return (tetrahedron *) NULL;
    }
  } while ((newtetrahedron[4] == (tetrahedron) NULL) ||
    ((point) newtetrahedron[7] == dummypoint)); 
  return newtetrahedron;
}

tetgenmesh::tetrahedron* tetgenmesh::alltetrahedrontraverse()
{
  tetrahedron *newtetrahedron;

  do {
    newtetrahedron = (tetrahedron *) tetrahedronpool->traverse();
    if (newtetrahedron == (tetrahedron *) NULL) {
      return (tetrahedron *) NULL;
    }
  } while (newtetrahedron[4] == (tetrahedron) NULL); // Skip dead ones.
  return newtetrahedron;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// shellfacedealloc()    Deallocate space for a shellface, marking it dead.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::shellfacedealloc(memorypool *pool, shellface *dyingsh)
{
  dyingsh[3] = (shellface) NULL;
  pool->dealloc((void *) dyingsh);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// shellfacetraverse()    Traverse the subfaces, skipping dead ones.         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenmesh::shellface* tetgenmesh::shellfacetraverse(memorypool *pool)
{
  shellface *newshellface;

  do {
    newshellface = (shellface *) pool->traverse();
    if (newshellface == (shellface *) NULL) {
      return (shellface *) NULL;
    }
  } while (newshellface[3] == (shellface) NULL); // Skip dead ones.
  return newshellface;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// badfacedealloc()    Deallocate space for a badface, marking it dead.      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::badfacedealloc(memorypool *pool, badface *dying)
{
  dying->forg = (point) NULL;
  pool->dealloc((void *) dying);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// badfacetraverse()    Traverse the pools, skipping dead ones.              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenmesh::badface* tetgenmesh::badfacetraverse(memorypool *pool)
{
  badface *newsh;

  do {
    newsh = (badface *) pool->traverse();
    if (newsh == (badface *) NULL) {
      return (badface *) NULL;
    }
  } while (newsh->forg == (point) NULL); // Skip dead ones.
  return newsh;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// pointdealloc()    Deallocate space for a point, marking it dead.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::pointdealloc(point dyingpoint)
{
  setpointtype(dyingpoint, DEADVERTEX);
  pointpool->dealloc((void *) dyingpoint);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// pointtraverse()    Traverse the points, skipping dead ones.               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenmesh::point tetgenmesh::pointtraverse()
{
  point newpoint;

  do {
    newpoint = (point) pointpool->traverse();
    if (newpoint == (point) NULL) {
      return (point) NULL;
    }
  } while (getpointtype(newpoint) == DEADVERTEX); // Skip dead ones.
  return newpoint;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// maketetrahedron()    Create a new tetrahedron.                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::maketetrahedron(triface *newtet)
{
  int i;

  newtet->tet = (tetrahedron *) tetrahedronpool->alloc();
  for (i = 0; i < 8; i++) {
    newtet->tet[i] = (tetrahedron) NULL;
  }
  if (b->useshelles) {
    newtet->tet[8] = (tetrahedron) NULL;
    newtet->tet[9] = (tetrahedron) NULL;
  }
  for (i = 0; i < in->numberoftetrahedronattributes; i++) {
    setelemattribute(newtet->tet, i, 0);
  }
  if (b->varvolume) {
    setvolumebound(newtet->tet, -1.0);
  }
  elemmarker(newtet->tet) = 0;
  newtet->loc = 0;
  newtet->ver = 0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// makeshellface()    Create a new shellface and initialize its data fields. //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::makeshellface(memorypool* pool, face* newsh)
{
  int i;

  newsh->sh = (shellface *) pool->alloc();
  for (i = 0; i < 10; i++) {
    newsh->sh[i] = (shellface) NULL;
  }
  if (checkconstraints) {
    areabound(*newsh) = 0.0;
  }
  // setshelltype(*newsh, NSHARP);
  // if (checkpbcs) {
    // setshellpbcgroup(*newsh, -1);
  // }
  ((int *) (newsh->sh))[shmarkindex] = 0;
  // Initialize the version to be Zero.
  newsh->shver = 0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// makepoint()    Create a new point.                                        //
//                                                                           //
// The new point is indexed (starting from 'in->firstnumber'). It's type is  //
// initialized as UNUSEDVERTEX.                                              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::makepoint(point* pnewpt)
{
  int i;

  *pnewpt = (point) pointpool->alloc();
  // Initialize the list of coordinates and user-defined attributes.
  for (i = 0; i < 4 + in->numberofpointattributes; i++) {
    (*pnewpt)[i] = 0.0;
  }
  // Initialize the point marker (starting from in->firstnumber).
  pointmark(*pnewpt) = (int) pointpool->items - (in->firstnumber ? 0 : 1);
  point2tet(*pnewpt) = NULL;
  setpointtype(*pnewpt, UNUSEDVERTEX);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// makeindex2pointmap()    Make a map from indices to points.                //
//                                                                           //
// The first index of the point is 'in->firstnumber' (0 or 1). '*pidx2ptmap' //
// return this map. NOTE: it is allocated but not deleted in this function.  //
// The caller has to deleted it.                                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::makeindex2pointmap(point*& idx2ptmap)
{
  point pt;
  int idx;

  if (b->verbose> 1) {
    printf("  Making a map from indices to points.\n");
  }

  idx2ptmap = new point[pointpool->items + 1];
  pointpool->traversalinit();
  idx = in->firstnumber;
  pt = pointtraverse();
  while (pt != NULL) {
    idx2ptmap[idx++] = pt;
    pt = pointtraverse();
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// makesubfacemap()    Create a map from vertex to subfaces incident at it.  //
//                                                                           //
// The map is returned in two arrays 'idx2faclist' and 'facperverlist'.  All //
// subfaces incident at i-th vertex (i is counted from 0) are found in the   //
// array facperverlist[j], where idx2faclist[i] <= j < idx2faclist[i + 1].   //
// Each entry in facperverlist[j] is a subface whose origin is the vertex.   //
//                                                                           //
// NOTE: These two arrays will be created inside this routine, don't forget  //
// to free them after using.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::makepoint2submap(memorypool* pool, int*& idx2faclist,
  face*& facperverlist)
{
  face shloop;
  int i, j, k;

  if (b->verbose > 1) {
    printf("  Making a map from points to subfaces.\n");
  }

  // Initialize 'idx2faclist'.
  idx2faclist = new int[pointpool->items + 1];
  for (i = 0; i < pointpool->items + 1; i++) idx2faclist[i] = 0;

  // Loop all subfaces, counter the number of subfaces incident at a vertex.
  pool->traversalinit();
  shloop.sh = shellfacetraverse(pool);
  while (shloop.sh != (shellface *) NULL) {
    // Increment the number of incident subfaces for each vertex.
    j = pointmark((point) shloop.sh[3]) - in->firstnumber;
    idx2faclist[j]++;
    j = pointmark((point) shloop.sh[4]) - in->firstnumber;
    idx2faclist[j]++;
    // Skip the third corner if it is a segment.
    if (shloop.sh[5] != NULL) {
      j = pointmark((point) shloop.sh[5]) - in->firstnumber;
      idx2faclist[j]++;
    }
    shloop.sh = shellfacetraverse(pool);
  }

  // Calculate the total length of array 'facperverlist'.
  j = idx2faclist[0];
  idx2faclist[0] = 0;  // Array starts from 0 element.
  for (i = 0; i < pointpool->items; i++) {
    k = idx2faclist[i + 1];
    idx2faclist[i + 1] = idx2faclist[i] + j;
    j = k;
  }

  // The total length is in the last unit of idx2faclist.
  facperverlist = new face[idx2faclist[i]];

  // Loop all subfaces again, remember the subfaces at each vertex.
  pool->traversalinit();
  shloop.sh = shellfacetraverse(pool);
  while (shloop.sh != (shellface *) NULL) {
    j = pointmark((point) shloop.sh[3]) - in->firstnumber;
    shloop.shver = 0; // save the origin.
    facperverlist[idx2faclist[j]] = shloop;
    idx2faclist[j]++;
    // Is it a subface or a subsegment?
    if (shloop.sh[5] != NULL) {
      j = pointmark((point) shloop.sh[4]) - in->firstnumber;
      shloop.shver = 2; // save the origin.
      facperverlist[idx2faclist[j]] = shloop;
      idx2faclist[j]++;
      j = pointmark((point) shloop.sh[5]) - in->firstnumber;
      shloop.shver = 4; // save the origin.
      facperverlist[idx2faclist[j]] = shloop;
      idx2faclist[j]++;
    } else {
      j = pointmark((point) shloop.sh[4]) - in->firstnumber;
      shloop.shver = 1; // save the origin.
      facperverlist[idx2faclist[j]] = shloop;
      idx2faclist[j]++;
    }
    shloop.sh = shellfacetraverse(pool);
  }

  // Contents in 'idx2faclist' are shifted, now shift them back.
  for (i = pointpool->items - 1; i >= 0; i--) {
    idx2faclist[i + 1] = idx2faclist[i];
  }
  idx2faclist[0] = 0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// makepoint2tetmap()    Make a map from points to tetrahedra.               //
//                                                                           //
// Traverses all the tetrahedra,  provides each corner of each tetrahedron   //
// with a pointer to that tetrahedera.  Some pointers will be overwritten by //
// other pointers because each point may be a corner of several tetrahedra,  //
// but in the end every point will point to a tetrahedron that contains it.  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenmesh::makepoint2tetmap()
{
  tetrahedron *tptr;
  point *pt;

  if (b->verbose > 1) {
    printf("  Making a map from points to tetrahedra.\n");
  }

  tetrahedronpool->traversalinit();
  tptr = tetrahedrontraverse();
  while (tptr != (tetrahedron *) NULL) {
    pt  = (point *) tptr;
    point2tet(pt[4]) = (tetrahedron) tptr;
    point2tet(pt[5]) = (tetrahedron) tptr;
    point2tet(pt[6]) = (tetrahedron) tptr;
    point2tet(pt[7]) = (tetrahedron) tptr;
    tptr = tetrahedrontraverse();
  }
}

#endif // #ifndef memorypoolCXX
