///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// linklist.cpp    Implement link, list, queue, stack, memorypool data types //
//                 which declared in linklist.h.                             //
//                                                                           //
// Si hang                                                                   //
// Email: sihang@weboo.com                                                   //
// http://www.weboo.com/sh/tetgen.htm                                        //
//                                                                           //
// Please see linklist.h for a detail description.                           //
//                                                                           //
// You are free to use, copy and modify the sources under certain            //
// circumstances, provided this copyright notice remains intact.             //
// See the file LICENSE for details.                                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>                             // Defined function printf().
#include <stdlib.h>                             // Defined function qsort().
#include <string.h>                 // Defined function strncmp(), strcmp().
#include "linklist.h"

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Predefined linar order functions for most primitive data types.           //                                                               //
//                                                                           //
// Return -1 if x < y; Return +1 if x > y; Return Zero if x == y.            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

int compare2ints(const void* pi1, const void* pi2)
{
  if(*(int*)pi1 < *(int*)pi2) {
    return -1;
  } else if(*(int*)pi1 > *(int*)pi2) {
    return 1;
  } else {
    return 0;
  }
}

int compare2unsignedlongs(const void* pl1, const void* pl2)
{
  if(*(unsigned long*)pl1 < *(unsigned long*)pl2) {
    return -1;
  } else if(*(unsigned long*)pl1 > *(unsigned long*)pl2) {
    return 1;
  } else {
    return 0;
  }
}

int compare2chars(const void* pc1, const void* pc2)
{
  if(*(char*)pc1 < *(char*)pc2) {
    return -1;
  } else if(*(char*)pc1 > *(char*)pc2) {
    return 1;
  } else {
    return 0;
  }
}

int compare2strings(const void* pstr1, const void* pstr2)
{
  return strcmp(*(char**)pstr1, *(char**)pstr2);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// setpredefineddatatype()                                                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void setpredefineddatatype(char* strdatatype, int *itembytes, compfunc *comp)
{
  if (strncmp(strdatatype, "int", 3) == 0) {
    *itembytes = sizeof(int);
    *comp = compare2ints;
  } else if (strncmp(strdatatype, "unsigned long", 13) == 0) {
    *itembytes = sizeof(unsigned long);
    *comp = compare2unsignedlongs;
  } else if (strncmp(strdatatype, "char", 4) == 0) {
    *itembytes = sizeof(char);
    *comp = compare2chars;
  } else if (strncmp(strdatatype, "string", 6) == 0) {
    *itembytes = sizeof(char*);
    *comp = compare2strings;
  } else if (strncmp(strdatatype, "point", 5) == 0) {
    // This type is for my tetrahedra program used, actually type is REAL*.
    *itembytes = sizeof(unsigned long);
    *comp = compare2unsignedlongs;
  } else {
    printf("Sorry, this data type %s is unknown by list now.\n", strdatatype);
    assert(0);
  }
}

///////////////////////////////////////////////////////////////////////////////
// class list implementation                                                 //
// BEGIN                                                                     //
///////////////////////////////////////////////////////////////////////////////

list::list(char* strdatatype, int _maxitems, int _expandsize)
{
  int bytesofint = sizeof(int);

  assert(strdatatype && (_maxitems > 0) && (_expandsize > 0));

  comp = (compfunc) NULL;
  setpredefineddatatype(strdatatype, &itembytes, &comp);
  assert(comp && (itembytes > 0));

  if(itembytes % bytesofint) {
    itemints  = itembytes / bytesofint + 1;
  } else {
    itemints  = itembytes / bytesofint;
  }

  maxitems = _maxitems;
  expandsize = _expandsize;
  base = new void*[maxitems * itemints];
  items = 0;
}

list::list(int _itembytes, int _maxitems, int _expandsize)
{
  assert((_itembytes > 0) && (_maxitems > 0) && (_expandsize > 0));

  int bytesofint = sizeof(int);
  itembytes = _itembytes;
  if(itembytes % bytesofint) {
    itemints  = itembytes / bytesofint + 1;
  } else {
    itemints  = itembytes / bytesofint;
  }
  comp = NULL;

  maxitems = _maxitems;
  expandsize = _expandsize;
  base = new void*[maxitems * itemints];
  items = 0;
}

list::~list()
{
  delete [] base;
}

list::list(list& src)
{
  assert(src.items > 0);
  itembytes = src.itembytes;
  itemints = src.itemints;
  maxitems = src.maxitems;
  expandsize = src.expandsize;
  items = src.items;
  base = new void*[maxitems * itemints];
  memcpy(base, src.base, items * itemints * sizeof(int));
}

void* list::operator[](int index)
{
  assert(index >= 0 && index < items);
  return (void*) (base + index * itemints);
}

void* list::getitem(int index)
{
  assert(index >= 0 && index < items);
  return (void*) (base + index * itemints);
}

void* list::alloc()
{
  if (items == maxitems) {
    // No space available, need re-allocate.
    void **newbase = new void*[(maxitems + expandsize) * itemints];
    memcpy(newbase, base, maxitems * itemints * sizeof(int));
    delete [] base;
    base = newbase;
    maxitems += expandsize;
  }
  items++;
  return (base + (items - 1) * itemints);
}

void list::append(void* newitem)
{
  if (items == maxitems) {
    // No space available, need re-allocate.
    void **newbase = new void*[(maxitems + expandsize) * itemints];
    memcpy(newbase, base, maxitems * itemints * sizeof(int));
    delete [] base;
    base = newbase;
    maxitems += expandsize;
  }
  memcpy((void*) (base + items * itemints), newitem, itembytes);
  items++;
}

// Insert an item before index 'befireindex'. 'beforeindex' should be a
//   value from 1 to listlength. If 'beforeindex' == listlength, insert
//   operation is equal to append operation.

void list::insert(int beforeindex, void* insertitem)
{
  assert(beforeindex > 0 && beforeindex <= items);
  if (beforeindex == items) {
    append(insertitem);
    return;
  }
  if (items == maxitems) {
    // No space available, need re-allocate.
    void **newbase = new void*[(maxitems + expandsize) * itemints];
    memcpy(newbase, base, maxitems * itemints * sizeof(int));
    delete [] base;
    base = newbase;
    maxitems += expandsize;
  }
  // Do block move.
  memmove((void*) (base + (beforeindex + 1) * itemints),   // dest
          (void*) (base + beforeindex * itemints),         // src
          (items - beforeindex) * itemints * sizeof(int)); // size in bytes
  // Insert the insertitem.
  memcpy((void*) (base + beforeindex * itemints), insertitem, itembytes);
  items++;
}

// Delete an item from the list. 'deleteindex' should be a value from
//   0 to listlength-1.

void list::del(int deleteindex)
{
  assert(deleteindex >= 0 && deleteindex < items);
  if (deleteindex != (items - 1)) {
    // Do block move.
    memmove((void*) (base + deleteindex * itemints),       // dest
            (void*) (base + (deleteindex + 1) * itemints), // src
            (items - deleteindex - 1) * itemints * sizeof(int));
  }
  items--;
}

// To remove a specific item from the list when its index is unknown. The
//   value returned is the index of the item in the Items array before it
//   was removed. After an item is removed, all the items that follow it
//   are moved up in index position and the Count(items) is reduced by one.
// If the Items array contains more than one copy of the pointer, only the
//   first copy is deleted.

int list::remove(void *removeitem)
{
  int index = hasitem(removeitem);
  if (index != -1) {
    del(index);
  }
  return index;
}

// Return 0 to listlength - 1 if 'checkitem' existed in list,
// Return -1 if 'checkitem' not exist.

int list::hasitem(void* checkitem)
{
  int i;

  for (i = 0; i < items; i ++) {
    if (comp) {
      if ((*comp)((void*)(base + i * itemints), checkitem) == 0) return i;
    } else {
      if (compare2ints((void*)(base + i * itemints), checkitem) == 0) return i;
    }
  }
  return -1;
}

// Return 0 to listlength - 1 if 'finditem' existed in list,
// Return -1 if 'finditem' not exist.

int list::indexof(void* finditem)
{
  return hasitem(finditem);
}

// Performs a QuickSort on the list based on the comparison function.

void list::sort()
{
  qsort((void*)base, (size_t)items, (size_t)(itemints * sizeof(int)), comp);
}

void list::simplify()
{
  compfunc compare;
  void *pathitem, *checkitem;
  int i, j;

  if(comp) {
    compare = (compfunc) comp;
  } else {
    compare = (compfunc) compare2ints;  // Use default compare function.
  }

  for (i = 0; i < items; i++) {
    pathitem = (*this)[i];
    for (j = i + 1; j < items; j++) {
      checkitem = (*this)[j];
      if ((*compare)(pathitem, checkitem) == 0) {
        del(j);
        j--;
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
// END                                                                       //
// class list implementation                                                 //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// class link implementation                                                 //
// BEGIN                                                                     //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                     Constructor, Destructor                               //
///////////////////////////////////////////////////////////////////////////////

link::link(char* strdatatype, int itemcount)
{
  int _itembytes;

  assert(strdatatype && (itemcount > 0));

  _itembytes = 0;
  comp = (compfunc) NULL;
  setpredefineddatatype(strdatatype, &_itembytes, &comp);
  assert(comp && (_itembytes > 0));

  poolinit(_itembytes, itemcount);
  init();
}

link::link(int _itembytes, int itemcount)
{
  assert((_itembytes > 0) && (itemcount > 0));

  poolinit(_itembytes, itemcount);
  init();
  comp = NULL;
}

link::~link()
{
  while (firstblock != (void**)NULL) {
    nowblock = (void **) *firstblock;
    delete [] firstblock;
    firstblock = nowblock;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                        Member Functions                                   //
///////////////////////////////////////////////////////////////////////////////

void link::poolinit(int bytes, int itemcount)
{
  itembytes = bytes;
  itemsperblock = itemcount;

  int bytesofint = sizeof(int);
  if(itembytes % bytesofint)
    itemints  = itembytes / bytesofint + 1;
  else
    itemints  = itembytes / bytesofint;
  // In double link, each items need 2 pointer spaces. So actually one
  //   item's total space is: itemints + 2 (ints).
  firstblock = new void*[1 + (itemints + 2) * itemsperblock];
  *firstblock = (void*) NULL;
  maxitems = itemsperblock;
  poolrestart();
}

void link::poolrestart()
{
  // Set the currently active block.
  nowblock = firstblock;
  // Find the first item in the pool.  Increment by the size of (void *).
  nextitem = (void*) (nowblock + 1);
  // There are lots of unallocated items left in this block.
  unallocateditems = itemsperblock;
  // The stack of deallocated items is empty.
  deaditemstack = (void*) NULL;
}

void* link::alloc()
{
  void *newitem;
  void **newblock;

  // First check the linked list of dead items.  If the list is not
  //   empty, allocate an item from the list rather than a fresh one.
  if (deaditemstack != (void *) NULL) {
    newitem = deaditemstack;               // Take first item in list.
    deaditemstack = * (void **) deaditemstack;
  } else {
    // Check if there are any free items left in the current block.
    if (unallocateditems == 0) {
      // Check if another block must be allocated.
      if (*nowblock == (void *) NULL) {
        // Allocate a new block of items, pointed to by the previous block.
        newblock = new void*[1 + (itemints + 2) * itemsperblock];
        *nowblock = (void *) newblock;
        // The next block pointer is NULL.
        *newblock = (void *) NULL;
        maxitems += itemsperblock;
      }
      // Move to the new block.
      nowblock = (void **) *nowblock;
      // Find the first item in the block.
      //   Increment by the size of (VOID *).
      nextitem = (void *)(nowblock + 1);
      // There are lots of unallocated items left in this block.
      unallocateditems = itemsperblock;
    }
    // Allocate a new item.
    newitem = nextitem;
    // Advance `nextitem' pointer to next free item in block.
    nextitem = (void *) ((void **) nextitem + itemints + 2);
    unallocateditems--;
  }

  return newitem;
}

void link::dealloc(void* dyingitem)
{
  // Push freshly killed item onto stack.
  *((void **) dyingitem) = deaditemstack;
  deaditemstack = dyingitem;
}

///////////////////////////////////////////////////////////////////////////////
//                          Member Functions                                 //
///////////////////////////////////////////////////////////////////////////////

void link::init()
{
  head = (void**) alloc();
  tail = (void**) alloc();
  *head = (void*) tail;
  *(head + 1) = NULL;
  *tail = NULL;
  *(tail + 1) = (void*) head;
  nextlinkitem = *head;
  curpos = 1;
  items = 0;
}

int link::move(int i)
{ // i > 0 move forward, i < 0 move backward.
  void** nownode = (void**)nextlinkitem;
  if(i > 0) {
    int j = 0;
    while((j < i) && *nownode) {
      nownode = (void**)*nownode;
      j++;
    }
    if((j > i) || !(*nownode)) return 0;
    nextlinkitem = (void*)nownode;
    curpos += i;
  } else if(i < 0) {
    int j = 0;
    i = -i;
    while((j < i) && *(nownode+1)) {
      nownode = (void**)*(nownode+1);
      j++;
    }
    if((j > i) || !(*(nownode+1))) return 0;
    nextlinkitem = (void*)nownode;
    curpos -= i;
  }
  return 1;
}

int link::locate(int i)
{
  if((i == 0) || (i > items)) return 0;

  int headdist = i - 1, taildist = items - i, curdist = i - curpos;
  int abscurdist = curdist >= 0 ? curdist : -curdist;

  int mindist;
  if(headdist > taildist) { // 1000
    if(taildist > abscurdist) {
      mindist = curdist;
    } else {
      // taildist <= abs(curdist)
      mindist = -taildist;
      goend();
    }
  } else { // 1000 else
    // headdist <= taildist
    if(headdist > abscurdist) {
      mindist = curdist;
    } else {
      // headdist <= abs(curdist)
      mindist = headdist;
      rewind();
    }
  } // 1000

  return move(mindist);
}

void link::add(void* elem)
{
  void **newnode = tail;
  memcpy((void*)(newnode + 2), elem, itembytes);
  tail = (void**) alloc();
  // To do init jobs after 'new' operater
  for(int i = 0; i < itemints + 2; i ++) {
    *((int *) (tail + i))  = 0;
  }
  *tail = NULL;
  *newnode = (void*) tail;
  *(tail + 1) = (void*) newnode;
  items++;
}

void link::insert(int index, void* elem)
{
  if(!locate(index)) assert(0);
  void **nownode = (void**) nextlinkitem;

  // Insert a node before 'nownode'.
  void **newnode = (void**) alloc();
  // To do init jobs after 'new' operater
  for(int i = 0; i < itemints + 2; i ++) {
    *((int *) (newnode + i))  = 0;
  }
  memcpy((void*)(newnode + 2), elem, itembytes);

  *(void**)(*(nownode + 1)) = (void*)newnode;
  *newnode = (void*) nownode;
  *(newnode + 1) = *(nownode+1);
  *(nownode + 1) = (void*)newnode;
  items++;

  nextlinkitem = (void*) newnode;
}

void link::del(int index)
{
  if(!locate(index)) assert(0);
  void **deadnode = (void**)nextlinkitem;

  // now delete the nownode
  void **nextnode = (void**)*deadnode;
  void **prevnode = (void**)*(deadnode + 1);
  *prevnode = (void*)nextnode;
  *(nextnode + 1) = (void*)prevnode;

  dealloc((void*) deadnode);
  items--;

  nextlinkitem = (void*) nextnode;
}

void* link::getitem()
{
  if (nextlinkitem == (void*)tail) return NULL;
  void **nownode = (void**)nextlinkitem;
  nextlinkitem = *nownode;
  curpos += 1;
  return (void*)(nownode + 2);
}

void* link::getnitem(int n)
{
  if(!locate(n)) return NULL;
  return (void*)((void**)nextlinkitem + 2);
}

void link::setnitem(int n, void* elem)
{
  assert(locate(n));
  void **nownode = (void**) nextlinkitem;
  // now set the nownode's data field with the new data
  memcpy((void*)(nownode + 2), elem, itembytes);
}

int link::hasitem(void* testitem)
{
  void *pathitem;
  int count;

  rewind();
  pathitem = getitem();
  count = 0;
  while (pathitem) {
    count ++;
    if (comp) {
      if ((*comp)(pathitem, testitem) == 0) return count;
    } else {
      if (compare2ints(pathitem, testitem) == 0) return count;
    }
    pathitem = getitem();
  }
  return -1;
}

void link::sort()
{
  compfunc compare;
  if(comp) {
    compare = (compfunc) comp;
  } else {
    compare = (compfunc) compare2ints;  // Use default compare function.
  }

  unsigned char *table;
  table = new unsigned char[items * itembytes];
  rewind();
  void *pathitem = getitem();
  int count = 0;
  while(pathitem) {
    memcpy(&table[count * itembytes], pathitem, itembytes);
    pathitem = getitem();
    count ++;
  }
  if(count != items) assert(0);

  qsort (table, (size_t) items, (size_t) itembytes, compare);

  clear();
  for(int i = 0; i < count; i ++) {
    add(&table[i * itembytes]);
  }
  delete [] table;
}

///////////////////////////////////////////////////////////////////////////////
// END                                                                       //
// class link implementation                                                 //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// class queue implementation                                                //
// BEGIN                                                                     //
///////////////////////////////////////////////////////////////////////////////

int queue::get(void* retitem)
{
  void* tmpitem = link::getnitem(1);
  if(tmpitem == NULL) return 0;
  memcpy(retitem, tmpitem, itembytes);
  link::del(1);
  return 1;
}

///////////////////////////////////////////////////////////////////////////////
// END                                                                       //
// class queue implementation                                                //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// class stack implementation                                                //
// BEGIN                                                                     //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                     Constructor, Destructor                               //
///////////////////////////////////////////////////////////////////////////////

stack::stack(char* strdatatype, int _itemsperblock)
{
  int _itembytes;

  assert(strdatatype && _itemsperblock > 0);

  _itembytes = 0;
  comp = (compfunc) NULL;
  setpredefineddatatype(strdatatype, &_itembytes, &comp);
  assert(comp && (_itembytes > 0));

  init(_itembytes, _itemsperblock);
}

stack::stack(int _itembytes, int _itemsperblock)
{
  assert(_itembytes > 0 && _itemsperblock > 0);
  init(_itembytes, _itemsperblock);
  comp = NULL;
}

stack::~stack()
{
  while (firstblock != (void**)NULL) {
    nowblock = (void **) *firstblock;
    delete [] firstblock;
    firstblock = nowblock;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                        Member Functions                                   //
///////////////////////////////////////////////////////////////////////////////

void stack::init(int bytes, int _itemsperblock)
{
  int bytesofint = sizeof(int);
  itembytes = bytes;
  if(itembytes % bytesofint)
    itemints  = itembytes / bytesofint + 1;
  else
    itemints  = itembytes / bytesofint;
  itemsperblock = _itemsperblock;
  firstblock = new void*[2 + itemints*itemsperblock];
  *firstblock = (void*) NULL;
  *(firstblock + 1) = (void*) NULL;
  restart();
}

void stack::restart()
{
  // clear items count
  items = 0;
  // find the maxitem's count we can save now.
  maxitems = itemsperblock;
  nowblock = firstblock;
  while(*nowblock != (void*) NULL) {
    maxitems += itemsperblock;
    nowblock = (void**) *nowblock;
  }
  // Set the currently active block.
  nowblock = firstblock;
  // Find the first item in the pool.  Increment by the size of (void *).
  top = (void*)(nowblock + 2);
  // There are lots of unused items left in this block.
  unuseditems = itemsperblock;
}

void stack::push(void* newitem)
{
  if( unuseditems == 0 ) {
    // nowblock is out of space
    if( items < maxitems ) {
      // next block is available, just move to it
      nowblock = (void**)*nowblock;
    } else {
      // we need allocte an new block for extend allocating space
      void **newblock = new void*[2 + itemints*itemsperblock];
      // set pointer to newblock and point back
      *nowblock = (void*) newblock;
      *newblock = (void*) NULL;
      *(newblock + 1) = (void*) nowblock;
      // move to newblock
      nowblock = newblock;
      // don't forget to extend maxitems
      maxitems += itemsperblock;
    }
    top = (void*)(nowblock + 2);
    // There are lots of unused items left in this block.
    unuseditems = itemsperblock;
  }
  // save newitem
  memcpy(top, newitem, itembytes);
  items ++;
  unuseditems --;
  // move top to next available item
  if(unuseditems) top = (void *) ((void **) top + itemints);
}

void* stack::topitem()
{
  if(items == 0) return NULL;
  void* retitem;
  if (unuseditems == 0) {
    // this time need attention, because last Push() operator didn't move
    // top to next block, so top is still point to the last pushed item
    retitem = top;
  } else if (unuseditems == itemsperblock) {
    // this time need move back a block
    void** prevblock = (void**)*(nowblock + 1);
    // top is point to the last item of the block
    retitem = (void*)(prevblock + 2 + itemints * (itemsperblock - 1));
  } else {
    // normal case in a block
    retitem = (void*) ((void**) top - itemints);
  }
  return retitem;
}

int stack::pop(void* retitem)
{
  if(items == 0) return 0;
  if(unuseditems == 0) {
    // this time need attention, because last Push() operator didn't move
    // top to next block, so top is still point to the last pushed item
  } else if(unuseditems == itemsperblock){
    // this time need move back a block
    nowblock = (void**)*(nowblock + 1);
    // top is point to the last item of the block
    top = (void*)(nowblock + 2 + itemints * (itemsperblock - 1));
    unuseditems = 0;
  } else {
    // normal case in a block
    top = (void*) ((void**) top - itemints);
  }
  // get wanted item
  memcpy(retitem, top, itembytes);
  items --;
  unuseditems ++;
  return 1;
}

int stack::hasitem(void* testitem)
{
  void** pathblock = firstblock;
  void* pathitem = (void*) (pathblock + 2);
  int pathitemsleft = itemsperblock;

  while(pathitem != top) {
    // Check whether any untraversed items remain in the current block.
    if (pathitemsleft == 0) {
      // Find the next block.
      pathblock = (void **) *pathblock;
      // Find the first item in the block.  Increment by the size of (VOID *).
      pathitem = (void *) (pathblock + 2);
      // Set the number of items left in the current block.
      pathitemsleft = itemsperblock;
    }
    if (comp) {
      if ((*comp)(pathitem, testitem) == 0) return 1;
    } else {
      if (compare2ints(pathitem, testitem) == 0) return 1;
    }
    // Find the next item in the block.
    pathitem = (void*) ((void**) pathitem + itemints);
    pathitemsleft--;
  }
  return -1;
}

///////////////////////////////////////////////////////////////////////////////
// END                                                                       //
// class stack implementation                                                //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// class memorypool implementation                                           //
// BEGIN                                                                     //
///////////////////////////////////////////////////////////////////////////////

memorypool::memorypool()
{
  firstblock = nowblock = (void**) NULL;
  nextitem = (void*) NULL;
  deaditemstack = (void*) NULL;
  pathblock = (void**) NULL;
  pathitem = (void*) NULL;
  itemwordtype = POINTER;
  alignbytes = 0;
  itembytes = itemwords = 0;
  itemsperblock = 0;
  items = maxitems = 0;
  unallocateditems = 0;
  pathitemsleft = 0;
}

memorypool::memorypool(int bytecount, int itemcount, enum wordtype wtype,
  int alignment)
{
  assert(bytecount > 0 && itemcount > 0);
  init(bytecount, itemcount, wtype, alignment);
}

memorypool::~memorypool()
{
  while (firstblock != (void **) NULL) {
    nowblock = (void **) *(firstblock);
    delete [] firstblock;
    firstblock = nowblock;
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// init()   Initialize a pool of memory for allocation of items.             //
//                                                                           //
// This routine initializes the machinery for allocating items.  A `pool' is //
// created whose records have size at least `bytecount'. Items will be allo- //
// cated in `itemcount'-item blocks. Each item is assumed to be a collection //
// of words, and either pointers or floating-point values are assumed to be  //
// the "primary" word type.  (The "primary" word type is used to determine   //
// alignment of items.)  If `alignment' isn't zero, all items will be `alig- //
// nment'-byte aligned in memory.  `alignment' must be either a multiple or  //
// a factor of the primary word size; powers of two are safe. `alignment' is //
// normally used to create a few unused bits at the bottom  of each item's   //
// pointer, in which information may be stored.                              //
//                                                                           //
//  Don't change this routine unless you understand it.                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void memorypool::init(int bytecount, int itemcount, enum wordtype wtype,
  int alignment)
{
  int wordsize;

  // Initialize values in the pool.
  itemwordtype = wtype;
  wordsize = (itemwordtype == POINTER) ? sizeof(void *) : sizeof(REALTYPE);
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
  if (sizeof(void *) > alignbytes) {
    alignbytes = sizeof(void *);
  }
  itemwords = ((bytecount + alignbytes - 1) / alignbytes)
              * (alignbytes / wordsize);
  itembytes = itemwords * wordsize;
  itemsperblock = itemcount;

  // Allocate a block of items.  Space for `itemsperblock' items and one
  //   pointer (to point to the next block) are allocated, as well as space
  //   to ensure alignment of the items.
  firstblock = (void**)
    (new BYTE[itemsperblock * itembytes + sizeof(void *) + alignbytes]);
  // Set the next block pointer to NULL.
  *firstblock = (void *) NULL;
  restart();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// restart()   Deallocate all items in a pool.                               //
//                                                                           //
// The pool is returned to its starting state, except that no memory is      //
// freed to the operating system.  Rather, the previously allocated blocks   //
// are ready to be reused.                                                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void memorypool::restart()
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
    (alignptr + (unsigned long) alignbytes
     - (alignptr % (unsigned long) alignbytes));
  // There are lots of unallocated items left in this block.
  unallocateditems = itemsperblock;
  // The stack of deallocated items is empty.
  deaditemstack = (void *) NULL;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// deinit()   Free to the operating system all memory taken by a pool.       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void memorypool::deinit()
{
  while (firstblock != (void **) NULL) {
    nowblock = (void **) *(firstblock);
    delete [] firstblock;
    firstblock = nowblock;
  }

  firstblock = nowblock = (void**) NULL;
  nextitem = (void*) NULL;
  deaditemstack = (void*) NULL;
  pathblock = (void**) NULL;
  pathitem = (void*) NULL;
  itemwordtype = POINTER;
  alignbytes = 0;
  itembytes = itemwords = 0;
  itemsperblock = 0;
  items = maxitems = 0;
  unallocateditems = 0;
  pathitemsleft = 0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// alloc()   Allocate space for an item.                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void* memorypool::alloc()
{
  void *newitem;
  void **newblock;
  unsigned long alignptr;

  // First check the linked list of dead items.  If the list is not
  //   empty, allocate an item from the list rather than a fresh one.
  if (deaditemstack != (void *) NULL) {
    newitem = deaditemstack;               // Take first item in list.
    deaditemstack = * (void **) deaditemstack;
  } else {
    // Check if there are any free items left in the current block.
    if (unallocateditems == 0) {
      // Check if another block must be allocated.
      if (*(nowblock) == (void *) NULL) {
        // Allocate a new block of items, pointed to by the previous block.
        newblock = (void**)
          (new BYTE[itemsperblock * itembytes + sizeof(void *) + alignbytes]);
        *(nowblock) = (void *) newblock;
        // The next block pointer is NULL.
        *newblock = (void *) NULL;
      }
      // Move to the new block.
      nowblock = (void **) *(nowblock);
      // Find the first item in the block.
      //   Increment by the size of (void *).
      alignptr = (unsigned long) (nowblock + 1);
      // Align the item on an `alignbytes'-byte boundary.
      nextitem = (void *)
        (alignptr + (unsigned long) alignbytes
         - (alignptr % (unsigned long) alignbytes));
      // There are lots of unallocated items left in this block.
      unallocateditems = itemsperblock;
    }
    // Allocate a new item.
    newitem = nextitem;
    // Advance `nextitem' pointer to next free item in block.
    if (itemwordtype == POINTER) {
      nextitem = (void *) ((void **) nextitem + itemwords);
    } else {
      nextitem = (void *) ((REALTYPE *) nextitem + itemwords);
    }
    unallocateditems--;
    maxitems++;
  }
  items++;
  return newitem;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// dealloc()     Deallocate space for an item.                               //
//                                                                           //
// The deallocated space is stored in a queue for later reuse.               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void memorypool::dealloc(void* dyingitem)
{
  // Push freshly killed item onto stack.
  *((void **) dyingitem) = deaditemstack;
  deaditemstack = dyingitem;
  items--;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// traversalinit()    Prepare to traverse the entire list of items.          //
//                                                                           //
// This routine is used in conjunction with traverse().                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void memorypool::traversalinit()
{
  unsigned long alignptr;

  // Begin the traversal in the first block.
  pathblock = firstblock;
  // Find the first item in the block.  Increment by the size of (void *).
  alignptr = (unsigned long) (pathblock + 1);
  // Align with item on an `alignbytes'-byte boundary.
  pathitem = (void *)
    (alignptr + (unsigned long) alignbytes
     - (alignptr % (unsigned long) alignbytes));
  // Set the number of items left in the current block.
  pathitemsleft = itemsperblock;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// traverse()     Find the next item in the list.                            //
//                                                                           //
// This routine is used in conjunction with traversalinit().  Be forewarned  //
// that this routine successively returns all items in the list, including   //
// deallocated ones on the deaditemqueue. It's up to you to figure out which //
// ones are actually dead.  Why?  I don't want to allocate extra space just  //
// to demarcate dead items. It can usually be done more space-efficiently by //
// a routine that knows something about the structure of the item.           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void* memorypool::traverse()
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
    pathblock = (void **) *(pathblock);
    // Find the first item in the block.  Increment by the size of (void *).
    alignptr = (unsigned long) (pathblock + 1);
    // Align with item on an `alignbytes'-byte boundary.
    pathitem = (void *)
      (alignptr + (unsigned long) alignbytes
       - (alignptr % (unsigned long) alignbytes));
    // Set the number of items left in the current block.
    pathitemsleft = itemsperblock;
  }
  newitem = pathitem;
  // Find the next item in the block.
  if (itemwordtype == POINTER) {
    pathitem = (void *) ((void **) pathitem + itemwords);
  } else {
    pathitem = (void *) ((REALTYPE *) pathitem + itemwords);
  }
  pathitemsleft--;
  return newitem;
}

///////////////////////////////////////////////////////////////////////////////
// END                                                                       //
// class memorypool implementation                                           //
///////////////////////////////////////////////////////////////////////////////
