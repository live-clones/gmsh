#include <iostream>
#include <iomanip>

#include <myadt.hpp>
using namespace std;

namespace netgen
{

BaseDynamicMem * BaseDynamicMem::first = 0;
BaseDynamicMem * BaseDynamicMem::last = 0;


BaseDynamicMem :: BaseDynamicMem ()
{
  prev = last;
  next = 0;

  if (last) last->next = this;
  last = this;
  if (!first) first = this;

  size = 0;
  ptr = 0;
  name = 0;
}
 
BaseDynamicMem :: ~BaseDynamicMem ()
{
  Free();

  if (next) next->prev = prev;
  else last = prev;
  if (prev) prev->next = next;
  else first = next;

  delete name;
}

void BaseDynamicMem :: SetName (const char * aname)
{
  delete name;
  if (aname)
    {
      name = new char[strlen(aname)+1];
      strcpy (name, aname);
    }
}


void BaseDynamicMem :: Alloc (size_t s)
{
  size = s;
  // ptr = new char[s];
  ptr = (char*)malloc (s);
}

void BaseDynamicMem :: ReAlloc (size_t s)
{
  if (size == s) return;

  char * old = ptr;
  // ptr = new char[s];
  ptr = (char*)malloc(s);
  memmove (ptr, old, (s < size) ? s : size);
  // delete old;
  free (old);
  size = s;
}

void BaseDynamicMem :: Free ()
{
  // delete ptr;
  free (ptr);
  ptr = 0;
}

void BaseDynamicMem :: Swap (BaseDynamicMem & m2)
{
  int hi;
  char * cp;
  hi = size; size  = m2.size; m2.size = hi;
  cp = ptr; ptr = m2.ptr; m2.ptr = cp;
  cp = name; name = m2.name; m2.name = cp;
}


void BaseDynamicMem :: Print ()
{
  cout << "****************** Dynamic Mem Report ****************" << endl;
  BaseDynamicMem * p = first;
  int mem = 0;
  int cnt = 0;
  while (p)
    {
      mem += p->size;
      cnt++;

      cout << setw(10) << p->size << " Bytes";
      if (p->name)
	cout << " in block " << p->name;
      cout << endl;

      p = p->next;
    }

  if (mem > 100000000)
    cout << "memory in dynamic memory: " << mem/1048576 << " MB" << endl;
  else if (mem > 100000)
    cout << "memory in dynamic memory: " << mem/1024 << " kB" << endl;
  else
    cout << "memory in dynamic memory: " << mem << " Bytes" << endl;
    cout << "number of blocks:         " << cnt << endl;
  //  cout << "******************************************************" << endl;
}

}
