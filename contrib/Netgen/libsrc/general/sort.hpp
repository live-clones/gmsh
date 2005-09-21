#ifndef FILE_SORT
#define FILE_SORT

/**************************************************************************/
/* File:   sort.hh                                                        */
/* Author: Joachim Schoeberl                                              */
/* Date:   07. Jan. 00                                                    */
/**************************************************************************/


// order(i) is sorted index of element i
extern void Sort (const ARRAY<double> & values,
		  ARRAY<int> & order);

extern void QickSort (const ARRAY<double> & values,
		      ARRAY<int> & order);

		  
#endif
