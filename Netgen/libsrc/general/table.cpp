/**************************************************************************/
/* File:   table.cpp                                                      */
/* Author: Joachim Schoeberl                                              */
/* Date:   01. Jun. 95                                                    */
/**************************************************************************/

/* 
   Abstract data type TABLE
*/

#include <mystdlib.h>
#include <myadt.hpp>

namespace netgen
{
  using namespace netgen;

  BASE_TABLE :: BASE_TABLE (int size)
    : data(size)
  {
    for (int i = 0; i < size; i++)
      {
	data[i].maxsize = 0;
	data[i].size = 0;
	data[i].col = NULL;
      }
    oneblock = NULL;
  }

  BASE_TABLE :: BASE_TABLE (const FlatArray<int> & entrysizes, int elemsize)
    : data(entrysizes.Size())
  {
    int i, cnt = 0;
    int n = entrysizes.Size();

    for (i = 0; i < n; i++)
      cnt += entrysizes[i];
    oneblock = new char[elemsize * cnt];
    // mem_total_alloc_table += elemsize * cnt;

    cnt = 0;
    for (i = 0; i < n; i++)
      {
	data[i].maxsize = entrysizes[i];
	data[i].size = 0;

	data[i].col = &oneblock[elemsize * cnt];
	cnt += entrysizes[i];
      }
  }

  BASE_TABLE :: ~BASE_TABLE ()
  {
    if (oneblock)
      delete [] oneblock;
    else
      {
	for (int i = 0; i < data.Size(); i++)
	  delete [] (char*)data[i].col;
      }
  }
  
  void BASE_TABLE :: SetSize (int size)
  {
    int i;
    for (i = 0; i < data.Size(); i++)
      delete [] (char*)data[i].col;
    
    data.SetSize(size);
    for (i = 0; i < size; i++)
      {
	data[i].maxsize = 0;
	data[i].size = 0;
	data[i].col = NULL;
      }    
  }

  void BASE_TABLE :: IncSize2 (int i, int elsize)
  {
    if (i < 1 || i > data.Size())
      {
	MyError ("BASE_TABLE::Inc: Out of range");
	return;
      }
  
    linestruct & line = data.Elem (i);
  
    if (line.size == line.maxsize)
      {
	/*
	  static int totalloc = 0, cnt = 0;
	  totalloc += (line.maxsize+5) * elsize;
	  cnt ++;

	  if (cnt % 100000 == 0)
	  cout << "base_table: total alloc = " << totalloc << endl;
	*/

	void * p = new char [(line.maxsize+5) * elsize];
	// mem_total_alloc_table += (line.maxsize+5) * elsize;


	if (!p)
	  {
	    MyError ("BASE_TABLE::Inc: Out of memory");
	    return;
	  }
      
	memcpy (p, line.col, line.maxsize * elsize);
	delete [] (char*)line.col;
	line.col = p;
	line.maxsize += 5;
      }
  
    line.size++;
  }

  void BASE_TABLE :: DecSize (int i)
  {
    if (i < 1 || i > data.Size())
      {
	MyError ("BASE_TABLE::Dec: Out of range");
	return;
      }
  
    linestruct & line = data.Elem (i);
  
    if (line.size == 0)
      {
	MyError ("BASE_TABLE::Dec: EntrySize < 0");
	return;      
      }
  
    line.size--;
  }


  /*
  void BASE_TABLE :: IncSizePrepare (int i)
  {
    data.Elem(i).maxsize++;
  }
  */


  void BASE_TABLE :: AllocateElementsOneBlock (int elemsize)
  {
    int i, cnt = 0;
    int n = data.Size();

    for (i = 1; i <= n; i++)
      cnt += data.Get(i).maxsize;
    oneblock = new char[elemsize * cnt];
    // mem_total_alloc_table += elemsize * cnt;

    //  cout << "Allocate oneblock, mem = " << (elemsize * cnt) << endl;

    cnt = 0;
    for (i = 1; i <= n; i++)
      {
	data.Elem(i).size = 0;

	data.Elem(i).col = &oneblock[elemsize * cnt];
	cnt += data.Elem(i).maxsize;
      }
  
  }








  int BASE_TABLE :: AllocatedElements () const
  {
    int els = 0;
    for (int i = 0; i < data.Size(); i++)
      els += data[i].maxsize;
    return els;
  }

  int BASE_TABLE :: UsedElements () const
  {
    int els = 0;
    for (int i = 0; i < data.Size(); i++)
      els += data[i].size;
    return els;
  }

}
