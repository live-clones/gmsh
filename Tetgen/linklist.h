///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// linklist.h    Defines some commonly usefed data types, such as link, list //
//               queue and stack, etc.                                       //
//                                                                           //
// Si hang                                                                   //
// Email: sihang@weboo.com                                                   //
// http://www.weboo.com/sh/tetgen.htm                                        //
//                                                                           //
// You are free to use, copy and modify the sources under certain            //
// circumstances, provided this copyright notice remains intact.             //
// See the file LICENSE for details.                                         //
//                                                                           //
//   A given programming language will have a number of data types available //
// along with some operations on them. C/C++ include int, float/double, char,//
// etc. We don't normally worry about how these datatypes and operations are //
// implemented, but just know what we can do with them.  However, most real  //
// programming tasks require more complex and sophisticated data types. If   //
// the programming language we used doesn't provide them, we'll have to      //
// define them ourself. Once we've defined such data types, we again don't   //
// want to worry about how they're implemented, just know what operations    //
// are allowed on that data type. There is huge range of reasonable courses, //
// textbooks and online sources on data structures and algorithms[1][2][3]   //
// [4][5].                                                                   //
//                                                                           //
//   In this file, we defined some basic and most useful data types in our   //
// common programming task. They are list, (double) link, queue, stack and   //
// memorypool. where memorypool is a special data type for deal with large   //
// memory blocks and was frequently used in the Tetgen Mesh program. All the //
// data types defined here can be used with arbitrary data types, include    //
// built-in and user defined datatypes.                                      //
//                                                                           //
//   I didn't use the Standard Template Library (STL)[2] of C++ language     //
// provided to implement these data types. Although the STL is powerful and  //
// elegant. But it need all the data types be known at compilation time, so  //
// it can not compile each data types to seperate object files (*.o) until   //
// the real date types are constructed. And it duplicate code which will     //
// increase the code length and compilation time.                            //
//                                                                           //
//   The basic idea for implementing arbitrary datatypes is to use the       //
// generic pointer type of C++ 'void*'. LEDA[4]'s solution is to consider    //
// a data structure whose containers have a slot for storing objects of a    //
// type T, which T are not stored directly in the containers of the data     //
// structure but on the heap. The data slots of the containers have type     //
// 'void*', and contain pointers to the objects on the heap. Type casting is //
// used to bridge the gap between the untyped world of the data slots (all   //
// data is void*) and the typed world of the heap. So to implement a single  //
// data types, there need 2 seperate classes in LEDA, one represents the     //
// abstract data type (data slots) and the other represents the real data    //
// type (data on the heap), these two classes can be compiled seperately     //
// into object files (*.o) then link them together when in use.              //
//                                                                           //
//   My implementation was diffrent with LEDA's. As a fact, I implemented    //
// the data slots directly on the heap (dynamic memory). Any data type is    //
// internally represented by a set of bytes, the size of data type is        //
// determined at running time. Use a pointer (type of void*) to access each  //
// data slot. No type casing is needed, it is up to user to determinte which //
// type is. This scheme simplified the implementation but less convient in   //
// use than LEDA's. Users have to provide the size of data types to the      //
// constructor and there still can not deal with some kinds of data types    //
// (like a structure/class contains pointers as its member variables).       //
// Anyway, I don't mean to provide more general data types at here, anybody  //
// is welcome to make any improvement on it. Thank you.                      //
//                                                                           //
// References:                                                               //
//                                                                           //
// [1] A.V. Aho, J.E. Hopcroft, and J.D. Ullman. Data Structures and         //
//     Algorithms. Addison-Wesley, 1983.                                     //
// [2] Joseph Bergin, Joe Bergin, F. B. Schneider, Data Structure Programm-  //
//     ing : With the Standard Template Library in C++ (Undergraduate Texts  //
//     in Computer Science). Springer Verlag, June 1998.                     //
// [3] Bruno R. Preiss, Data Structures and Algorithms with Object-Oriented  //
//     Design Patterns in C++. John Wiley & Sons; August 31, 1998.           //
// [4] K. Mehlhorn and S. Naher, The LEDA Platform of Combinatorial and      //
//     Geometric Computing. Cambridge University Press, 1999.                //
// [5] Data Structures and Algorithms, Online source,                        //
//     http://www.cee.hw.ac.uk/~alison/ds.html.                              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef linklistH
#define linklistH

#ifndef NULL
  #define NULL 0
#endif

#ifndef BYTE
  #define BYTE char
#endif

#ifdef SINGLE
  #define REALTYPE float
#else
  #define REALTYPE double
#endif

// Uncomment the following line to disable assertions.

// #define NDEBUG

#include <assert.h>

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Define a line-order function type, used in list, link.                    //
//                                                                           //
// A function: int cmp(const T &, const T &),  is said to realize a linear   //
// order on the type T if there is a linear order <= on T such that for all  //
// x and y in T satisfy the following relation:                              //
//                                                                           //
//                  -1  if x < y.                                            //
//    comp(x, y) =   0  if x is equivalent to y.                             //
//                  +1  if x > y.                                            //
//                                                                           //
// For many primitive data types (like int, unsigned long, ...) a function   //
// compare is predefined and defines the so-called default ordering of the   //
// type. The default ordering is the usual "less than or equal" for the      //
// numerical types, the lexicographic ordering for strings, and the          //
// lexicographic ordering of the Cartesian coordinates for points. For all   //
// other types T there is no default ordering, and the user has to define    //
// the function compare if a linear order on T is required.                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

typedef int (*compfunc) (const void *, const void *);

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Class list                                                                //
//                                                                           //
// Any data type list with dynamic re-allocation.                            //
//                                                                           //
// base-->  __________     list, which stores an array of pointers(void*),   //
//         |_        _|    is ofen used to maintain lists of objects. list   //
//         |_ data 0 _|    introduces properties and methods to:             //
//         |__________|      > Add or delete the objects in the list.        //
//         |_        _|      > Rearrange the objects in the list.            //
//         |_ data 1 _|      > Locate and access objects in the list.        //
//         |__________|      > Sort the objects in the list.                 //
//         |_        _|                                                      //
//         |_ data 2 _|    Note: The index of list is zero-based. Where 0 is //
//         |__________|          the index of the first object, 1 is the     //
//         |_        _|          index of second object, and so on.          //
//         |_        _|                                                      //
//         |__________|                                                      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class list {

    void **base;
    int  itembytes, itemints;
    long items, maxitems;
    long expandsize;
    compfunc comp;

  public:

    list(char*, int _maxitems = 256, int _expandsize = 128);
    list(int _itembytes, int _maxitems = 256, int _expandsize = 128);
    list(list&);
    ~list();

    list& operator=(list&);
    int  getitembytes() { return itembytes; }
    int  getitemints() { return itemints; }
    long getmaxitems() { return maxitems; }
    long getexpandsize() { return expandsize; }
    void setexpandsize(int size) { assert(size); expandsize = size; }
    void setcomp(compfunc compf) { assert(compf); comp = compf; }

    void *operator[](int index);
    void *getitem(int index);
    void clear() { items = 0; }
    int  len() { return items; }
    void *alloc();
    void append(void*);
    void insert(int, void*);
    void del(int);
    int  remove(void*);
    int  hasitem(void*);
    int  indexof(void*);
    void sort();
    void simplify();

    friend void mergelist(list*, list*, list&, compfunc compf = NULL);
    friend void splitlist(list*, int, list&, list&, compfunc compf = NULL);
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Class link                                                                //
//                                                                           //
// Any data type double link list build on a memory pool.                    //
//                                                                           //
// This class's storage scheme is same with class memorypool. It implement a //
// double link list on the pool. Item traverse is through pointers stored in //
// each item's 'next' and 'prev' field.  So do not need traverseinit() and   //
// traverse().                                                               //
//                                                                           //
//   head-> _________      _________      _________      _________<-tail     //
//         |__next___|--> |__next___|--> |__next___|--> |__NULL___|          //
//         |__NULL___|<-- |__prev___|<-- |__prev___|<-- |__prev___|          //
//         |         |    |_       _|    |_       _|    |         |          //
//         |         |    |_ Data1 _|    |_ Data2 _|    |         |          //
//         |_________|    |_________|    |_________|    |_________|          //
//                                                                           //
//                                                                           //
// Note: The index of link is one-based. Where 1 is the index of the first   //
//       object, 2 is the index of second object, and so on. 0 is used to    //
//       indicate a void link.                                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class link {

  protected:

    void **firstblock, **nowblock;
    void *nextitem;
    void *deaditemstack;
    int  itemsperblock;
    int  unallocateditems;
    long maxitems;

    void **head, **tail;
    void *nextlinkitem;
    int  itembytes, itemints;
    long items;
    int  curpos;
    compfunc comp;

  protected:

    void *alloc();
    void dealloc(void*);
    void poolinit(int, int);
    void poolrestart();

  public:

    link(char*, int itemcount = 256);
    link(int _itembytes, int itemcount = 256);
    ~link();

    int getitembytes() { return itembytes; }
    int getitemints() { return itemints; }
    void setcomp(compfunc compf) { assert(compf); comp = compf; }

    void init();
    void clear() { poolrestart(); init(); }
    int  len() { return items; }
    int  move(int);
    int  locate(int);
    void add(void*);
    void insert(int, void*);
    void del(int);
    void rewind() { nextlinkitem = *head; curpos= 1; }
    void goend() { nextlinkitem = *(tail+1); curpos = items; }
    void *getitem();
    void *getnitem(int);
    void setnitem(int, void*);
    int  hasitem(void*);
    void sort();
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Class queue                                                               //
//                                                                           //
// Unbounded any data type queue with dynamic re-allocation.                 //
//                                                                           //
//                ___________     ___________     ___________                //
//     Get() <-- |_         _|<--|_         _|<--|_         _| <-- Push()    //
//               |_  Data0  _|   |_  Data1  _|   |_  Data2  _|               //
//               |___________|   |___________|   |___________|               //
//                                                                           //
//                queue head                       queue tail                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Class queue Member Functions                                              //
//                                                                           //
// > Empty()                                                                 //
//   Tests if queue is empty.                                                //
// > Push()                                                                  //
//   Adds a new top element (Stack and queue operation!).                    //
// > Bot()                                                                   //
//   Returns the bottom element (queue operation!) but does not remove it.   //
// > Get()                                                                   //
//   Returns the bottom element (queue operation!) and removes it.           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class queue : public link {

  public:

    queue(char* str, int itemcount = 256) : link(str, itemcount) {};
    queue(int _itembytes, int itemcount = 256) : link(_itembytes, itemcount) {};

    int  empty() { return items == 0; }
    void push(void* newitem) { link::add(newitem); };
    void *bot() { return link::getnitem(1); };
    int  get(void*);
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Class stack                                                               //
//                                                                           //
// Unbounded any data type stack with dynamic re-allocation.                 //
//                                                                           //
//           firstblock                         nowblock                     //
//           __________       __________       __________                    //
//          |__next____|---> |__next____|---> |__NULL____|                   //
//          |__NULL____|<--- |__prev____|<--- |__prev____|                   //
// Base---> |_        _|     |_        _|     |_        _|                   //
//          |_ data 0 _|     |_ data 3 _|     |_ data 6 _|                   //
//          |__________|     |__________|     |__________|                   //
//          |_        _|     |_        _|     |_        _| <--- top          //
//          |_ data 1 _|     |_ data 4 _|     |_        _|                   //
//          |__________|     |__________|     |__________|                   //
//          |_        _|     |_        _|     |_        _|                   //
//          |_ data 2 _|     |_ data 5 _|     |_        _|                   //
//          |__________|     |__________|     |__________|                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Class stack Member Functions                                              //
//                                                                           //
// > Clear()                                                                 //
//   Clears the contents of stack.                                           //
// > Empty()                                                                 //
//   Tests if stack is empty.                                                //
// > Top()                                                                   //
//   Returns the top element (stack operation!) but does not pop it.         //
// > Pop()                                                                   //
//   Returns the top element (stack operation!) and pops it.                 //
// > Push()                                                                  //
//   Adds a new top element (stack and queue operation!).                    //
// > Len()                                                                   //
//   Returns the number of elements in stack.                                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class stack {

    void **firstblock, **nowblock;
    void *top;
    int  itembytes, itemints;
    int  itemsperblock;
    int  unuseditems;
    long items, maxitems;
    compfunc comp;

  public:

    stack(char*, int _itemsperblock = 256);
    stack(int _itembytes, int _itemsperblock = 256);
    ~stack();

    void setcomp(compfunc compf) { assert(compf); comp = compf; }

    void init(int, int);
    void restart();
    int  len() { return items; }
    int  empty() { return items == 0; }
    void push(void*);
    void *topitem();
    int  pop(void*);
    int  hasitem(void*);
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Labels that signify whether a record consists primarily of pointers or of //
//   floating-point words.  Used to make decisions about data alignment.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

enum wordtype {POINTER, FLOATINGPOINT};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// class memorypool                                                          //
//                                                                           //
// A type used to allocate memory.  firstblock is the first block of items.  //
//   nowblock is the block from which items are currently being allocated.   //
//   nextitem points to the next slab of free memory for an item.            //
//   deaditemstack is the head of a linked list (stack) of deallocated items //
//   that can be recycled.  unallocateditems is the number of items that     //
//   remain to be allocated from nowblock.                                   //
//                                                                           //
// Traversal is the process of walking through the entire list of items, and //
//   is separate from allocation.  Note that a traversal will visit items on //
//   the "deaditemstack" stack as well as live items.  pathblock points to   //
//   the block currently being traversed.  pathitem points to the next item  //
//   to be traversed.  pathitemsleft is the number of items that remain to   //
//   be traversed in pathblock.                                              //
//                                                                           //
// itemwordtype is set to POINTER or FLOATINGPOINT, and is used to suggest   //
//   what sort of word the record is primarily made up of.  alignbytes       //
//   determines how new records should be aligned in memory.  itembytes and  //
//   itemwords are the length of a record in bytes (after rounding up) and   //
//   words.  itemsperblock is the number of items allocated at once in a     //
//   single block.  items is the number of currently allocated items.        //
//   maxitems is the maximum number of items that have been allocated at     //
//   once; it is the current number of items plus the number of records kept //
//   on deaditemstack.                                                       //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// memorypool member functions:                                              //
//                                                                           //
// > init()                                                                  //
//   Initialize a pool of memory for allocation of items.                    //
// > restart()                                                               //
//   Deallocate all items in a pool.                                         //
// > alloc()                                                                 //
//   Allocate space for an item.                                             //
// > dealloc()                                                               //
//   Deallocate space for an item.                                           //
// > traversalinit()                                                         //
//   Prepare to traverse the entire list of items.                           //
// > traverse()                                                              //
//   Find the next item in the list.                                         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

class memorypool {

  public:

    void **firstblock, **nowblock;
    void *nextitem;
    void *deaditemstack;
    void **pathblock;
    void *pathitem;
    wordtype itemwordtype;
    int  alignbytes;
    int  itembytes, itemwords;
    int  itemsperblock;
    long items, maxitems;
    int  unallocateditems;
    int  pathitemsleft;

  public:

    memorypool();
    memorypool(int, int, enum wordtype, int);
    ~memorypool();

    void init(int, int, enum wordtype, int);
    void restart();
    void deinit();
    void *alloc();
    void dealloc(void*);
    void traversalinit();
    void *traverse();
};

#endif // #ifndef linklistH
