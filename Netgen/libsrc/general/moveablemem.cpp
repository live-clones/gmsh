#include <iostream>
#include <iomanip>

#include <myadt.hpp>
using namespace std;
namespace netgen
{
  
  NgMutex mem_mutex;
  
  size_t BaseMoveableMem::totalsize = 0; // 500000000;
  size_t BaseMoveableMem::used = 0;
  char * BaseMoveableMem::largeblock = 0;
  
  BaseMoveableMem * BaseMoveableMem::first = 0;
  BaseMoveableMem * BaseMoveableMem::last = 0;
  

  BaseMoveableMem :: BaseMoveableMem (size_t s)
  {
    // cout << "Construct object begin" << endl;
    //   Print ();

  prev = last;
  next = 0;

  if (last) last->next = this;
  last = this;
  if (!first) first = this;

  size = 0;

  if (prev)
    pos = prev->pos + prev->size;
  else
    pos = 0;

  ptr = 0;
  name = 0;

  if (s) Alloc(s);
}
 
BaseMoveableMem :: ~BaseMoveableMem () throw()
{
  Free();

  if (next) next->prev = prev;
  else last = prev;
  if (prev) prev->next = next;
  else first = next;

  delete name;
}

void BaseMoveableMem :: SetName (const char * aname)
{
  delete name;
  if (aname)
    {
      name = new char[strlen(aname)+1];
      strcpy (name, aname);
    }
}


void BaseMoveableMem :: Alloc (size_t s)
{
  if (totalsize == 0)
    {
      size = s;
      ptr = (char*) malloc(s);
      return;
    }


  used += s - size;

  int r = s % 8;
  if (r) s += 8-r;
  if (prev)
    pos = prev->pos + prev->size;
  else
    pos = 0;
  size = s;
  
  if (next)
    {
      NgLock lock(mem_mutex);
      lock.Lock();
      try
	{
	  next->MoveTo (pos+size);
	}
      catch (NgException e)
      {
	lock.UnLock();
	throw NgException ("MoveableMem overflow");
      }
      lock.UnLock();
    }

  if (size)
    {
      if (!largeblock)
	{
	  cout << "moveable memory: allocate large block of "
	       << totalsize / 1048576  << " MB" << endl; 
	  // largeblock = new char[totalsize];
	  largeblock = (char*)malloc (totalsize);
	}
      ptr = largeblock+pos;

      if (pos + size > totalsize)
	throw NgException ("MoveableMem overflow");
    }
  else
    ptr = 0;
}

void BaseMoveableMem :: ReAlloc (size_t s)
{
  if (totalsize == 0)
    {
      if (size == s) return;
      
      char * old = ptr;
      ptr = (char*)malloc(s);
      memmove (ptr, old, (s < size) ? s : size);
      free (old);
      size = s;
      return;
    }

  Alloc (s);
}

void BaseMoveableMem :: MoveTo (size_t newpos)
{
  //  cout << "move block, oldpos = " << pos << "; newpos = " << newpos
  // << ", size = " << size << endl;
  static int move = 0;

  if (newpos + size > totalsize)
    throw NgException ("MoveableMem overflow");
  if (newpos > pos)
    {
      if (next) next->MoveTo (newpos+size);
      memmove (largeblock+newpos, largeblock+pos, size);
      move += size;
    }
  else if (newpos < pos)
    {
      // cout << "move down: " << size << endl;
      memmove (largeblock+newpos, largeblock+pos, size);
      if (next) next->MoveTo (newpos+size);
      move += size;
    }
  pos = newpos;
  ptr = largeblock+pos;
  //  cout << "total move: " << move << endl;
}

void BaseMoveableMem :: Free () throw()
{
  if (totalsize == 0)
    {
      free (ptr);
      ptr = 0;
      return;
    }

  /*
    cout << "free block, pos = " << pos << "size = " << size << endl;
    cout << "before: " << endl;
    Print();
  */
  used -= size;
  if (next) 
    {
      NgLock lock(mem_mutex);
      lock.Lock();
      next->MoveTo (pos);
      lock.UnLock();
    }
  
  size = 0;
  ptr = 0;
  // pos = 0;
}

void BaseMoveableMem :: Swap (BaseMoveableMem & m2) throw()
{
  int hi;
  BaseMoveableMem * hp;
  char * cp;
  hi = size; size  = m2.size; m2.size = hi;
  hi = pos; pos = m2.pos; m2.pos = hi;
  /*
  hp = prev; prev = m2.prev; m2.prev = hp;
  hp = next; next = m2.next; m2.next = hp;
  */
  cp = ptr; ptr = m2.ptr; m2.ptr = cp;
  cp = name; name = m2.name; m2.name = cp;
}


void BaseMoveableMem :: Print ()
{
  cout << "****************** Moveable Mem Report ****************" << endl;
  BaseMoveableMem * p = first;
  int mem = 0;
  int cnt = 0;
  while (p)
    {
      mem += p->size;
      cnt++;

      cout << setw(10) << p->size << " Bytes";
      cout << ", pos = " << p->pos;
      //      cout << ", addr = " << p->ptr;
      if (p->name)
	cout << " in block " << p->name;
      cout << endl;

      p = p->next;
    }

  if (mem > 100000000)
    cout << "memory in moveable arena: " << mem/1048576 << " MB" << endl;
  else if (mem > 100000)
    cout << "memory in moveable arena: " << mem/1024 << " kB" << endl;
  else
    cout << "memory in moveable arena: " << mem << " Bytes" << endl;
  cout << "number of blocks:         " << cnt << endl;
  
  cout << " used  = " << used << endl;
  //  cout << "******************************************************" << endl;
}

}
