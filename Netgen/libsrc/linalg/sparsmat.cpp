#include <mystdlib.h>
 
#include <linalg.hpp>


namespace netgen
{
MatrixGraph :: MatrixGraph (int size, int aincrement)
{
  int i;
  increment = aincrement;
  
  lines.SetSize (size);
  for (i = 1;i <= size; i++)
    {
      lines.Elem(i).allocsize = increment;
      lines.Elem(i).size = 1;
      lines.Elem(i).diag = 1;
      lines.Elem(i).col = new INDEX[increment];
      lines.Elem(i).col[0] = i;
    }
}

MatrixGraph :: MatrixGraph (const ARRAY<int> & linesize)
{
  INDEX i;
  INDEX n = linesize.Size();
  INDEX sum = 0;
  INDEX * cola;

  lines.SetSize (n);
  increment = 0;

  for (i = 1; i <= n; i++)
    sum += linesize.Get(i);
  
  cola = new INDEX[sum];

  sum = 0;
  for (i = 1; i <= n; i++)
    {
      lines.Elem(i).allocsize=linesize.Get(i);
      lines.Elem(i).size = 1;
      lines.Elem(i).diag = 1;
      lines.Elem(i).col = &cola[sum];
      cola[sum] = i;
      sum += linesize.Get(i);
    }
}

int MatrixGraph :: GetPosition (INDEX i, INDEX j) const
{
  int k;
  
  INDEX * ip = lines.Get(i).col;
  INDEX n = lines.Get(i).size;
  for (k = 1; k <= n; k++, ip++)
    {
      if (j == *ip) return k;
    }

  return 0;
  
  /*  
  //  quick search:

  const INDEX * ip = lines.Get(i).col;
  int max = lines.Get(i).size;

  int l = 0, k = 1, newind;
  
  while (k < max)
    k <<= 1;

  while (k > 0)
    {
      k >>= 1;
      newind = k+l;
      if (newind >= max) continue;
      if (ip[newind] <= j)
	l += k;
    }

  if (l < max && ip[l] == j) 
    return l+1;

  return 0;
  */
}



int MatrixGraph :: CreatePosition (INDEX i, INDEX j)    
  {
  int k;
  MatrixGraph::linestruct * lin = &lines.Elem(i);

 

  for (k = 1; k <= lin->size; k++)
    {
      if (lin->col[k-1] == j) 
	return 0;
      if (lin->col[k-1] > j) 
	break;
    }

  // k ... position to enter new element

  if (lin->size == lin->allocsize)
    {
      INDEX * tmpcol = new INDEX[lin->size + increment];
      memcpy (tmpcol, lin->col, sizeof(INDEX) * lin->size);
      delete lin->col;
      lin->col = tmpcol;
      lin->allocsize+=increment;
    }

  if (k <= lin->size)
    memmove (&lin->col[k], &lin->col[k-1], 
	     sizeof(INDEX) * (lin->size + 1 - k));
  
  lin->col[k-1] = j;
  lin->size++;
  if (j < i) lin->diag++;

  return 1;
  }



double & SparseMatrix :: operator() (INDEX i, INDEX j)
{
  if (i >= 1 && i <= height && j >= 1 && j <= width)
    return Elem(i, j);
  else
    {
    (*myerr) << "SparseMatirx::operator(): out of range" << endl;
    return shit;
    }
}
 
double SparseMatrix :: operator() (INDEX i, INDEX j) const
{
  if (i >= 1 && i <= height && j >= 1 && j <= width)
    return Get(i, j);
  else
    {
    (*myerr) << "SparseMatirx::operator(): out of range" << endl;
    return shit;
    }
}
   





SparseMatrix :: SparseMatrix (INDEX h, INDEX w)
  : BaseMatrix (h, w)
{
  ;
}




void SparseMatrix :: Mult (const BaseVector & bv, BaseVector & bprod) const
  {
  double sum, vi;
  INDEX i, j, n;

  const INDEX * col;
  const double * valp;

  const Vector & v = bv.CastToVector();
  Vector & prod = bprod.CastToVector();

  prod.SetLength (Height());

  /*
  if (prod.Length() != Height() || v.Length() != Width())
    {
    (*myerr) << "SparseMatrix::Mult: Dimensions don't fit" << endl;
    return;
    }
    */

  if (!Symmetric())
    {
      n = Height();
      INDEX w = Width();

      /*
      const MatrixGraph::linestruct * linep = &graph->lines.Get(1);   

      for (i = 1; i <= n; i++) 
	{
	  sum = 0; 
	  col = linep->col;
	  valp = data.Get(i);
	  
	  for (j = 0; j < linep->size; j++, valp++, col++)
	    sum += *valp * v.Get(*col); 

	  linep++;
	  prod.Set (i, sum);
	}
	*/

      const MatrixGraph::linestruct * linep = &graph->lines.Get(1);   
      const double * vp = &v.Get(1);
      vp--;

      for (i = 1; i <= n; i++) 
	{
	  sum = 0; 
	  col = linep->col;
	  valp = data.Get(i);
	  const int ls = linep->size;
	  
	  if (i <= w)
	    for (j = 0; j < ls; j++)
	      sum += valp[j] * vp[col[j]];
	  else
	    // decrement one, because of diagonal element outside
	    for (j = 0; j < ls-1; j++)
	      sum += valp[j] * vp[col[j]];

	  
	  linep++;
	  prod.Set (i, sum);
	}

    }
  else
    {
      prod = 0;
      n = Height();
      
      const MatrixGraph::linestruct * linep = &graph->lines.Get(1);   

      for (i = 1; i <= n; i++)
	{
	  sum = 0; 
	  //	  col = graph->lines.Get(i).col;
	  col = linep->col;
	  valp = data.Get(i);
	  vi = v.Get(i);
	  
	  for (j = linep->diag-1; j > 0; j--, col++, valp++)
	    {
	      sum += (*valp) * v.Get(*col);
	      prod.Elem(*col) += (*valp) * vi;
	    }
	  
	  linep++;
	  sum += (*valp) * v.Get(*col);
	  prod.Elem(i) += sum;
	}
    }
  }

void SparseMatrix :: MultTrans (const BaseVector & bv, BaseVector & bprod) const
  {
  INDEX i, j, n, coln;
  const Vector & v = bv.CastToVector();
  Vector & prod = bprod.CastToVector();
  const INDEX * col;
  const double * valp;
  double val;

  prod.SetLength (Width());

  if (prod.Length() != Width() || v.Length() != Height())
    {
    (*myerr) << "SparseMatrix::Mult: Dimensions don't fit" << endl;
    return;
    }

  if (!Symmetric())
    {
    n = Height();
    prod = 0;

    for (i = 1; i <= n; i++)
      {
	col = graph->lines.Get(i).col;
	valp = data.Get(i);
	coln = graph->lines.Get(i).size;
	val = v.Get(i);

	//      lin = &lins.Get(i);
	//      col = lin->col;
	//      val = v.Get(i);
      
      for (j = 1; j <= coln; j++, col++, valp++)
        prod.Elem(*col) += (*valp) * val;
      }
    }
  else
    {
    Mult (v, prod);
    }
  }




void SparseMatrix :: Residuum (const BaseVector & bx, const BaseVector & bb,
      BaseVector & bres) const
  {
    BaseMatrix :: Residuum (bx, bb, bres);
    /*
  double sum, xi;
  INDEX i, j, n;
  colstruct * col;
  const linestruct * lin;
  const Vector & x = bx.CastToVector();
  const Vector & b = bb.CastToVector();
  Vector & res = bres.CastToVector();

  res.SetLength (b.Length());

  if (res.Length() != b.Length() || b.Length() != Height() ||
      x.Length() != Width())
    {
    (*myerr) << "SparseMatrix::Residuum: Dimensions don't fit" << endl;
    return;
    }

  n = Height();
  if (!Symmetric())
    {
    for (i = 1; i <= Height(); i++)
      {
      lin = &lins.Get(i);
      sum = b.Get(i);
      col = lin->col;

      for (j = lin->size; j > 0; j--, col++)
        sum -= col->data * x.Get(col->colnr);

      res.Set (i, sum);
      }
    }
  else
    {
    res = b;
    for (i = 1; i <= n; i++)
      {
      lin = &lins.Get(i);
      sum = 0;
      col = lin->col;
      xi = x.Get(i);

      for (j = lin->size; j > 0; j--, col++)
        {
        sum -= col->data * x.Get(col->colnr);
        if (col->colnr != i)
          res.Elem(col->colnr) -= col->data * xi;
        }

      res.Elem(i) += sum;
      }
    }
    */
  }


void SparseMatrix :: ResiduumTrans (const BaseVector & /* bx */, 
				    const BaseVector & /* bb */,
				    BaseVector & /* bres */) const
  {
    cerr << "SparseMastrix :: Residuumtrans called, but not implemented" << endl;

    /*
  INDEX i, j, n;
  colstruct * col;
  const linestruct * lin;
  const Vector & x = bx.CastToVector();
  const Vector & b = bb.CastToVector();
  Vector & res = bres.CastToVector();


  res.SetLength (Width());

  if (res.Length() != b.Length() || b.Length() != Width() ||
      x.Length() != Height())
    {
    (*myerr) << "SparseMatrix::ResiduumTrans: Dimensions don't fit" << endl;
    return;
    }
  
  if (!Symmetric())
    {
    n = Height();

    res = b;

    for (i = 1; i <= n; i++)
      {
      lin = &lins.Get(i);
      col = lin->col;

      for (j = lin->size; j > 0; j--, col++)
        res.Elem(col->colnr) -= col->data * x.Get(i);
      }
    }
  else
    {
    Residuum (bx, bb, bres);
    }
    */
  }



ostream & SparseMatrix :: Print (ostream & s) const
  {
  INDEX i, j;

  if (Symmetric()) s << "Lower half of matrix:" << endl;

  for (i = 1; i <= Height(); i++)
    {
    s << "Line " << i << " ";

    if (Symmetric())
      {
	for (j = 1 ; j <= GetDiagPos (i); j++)
	  s << "(" << GetColIndex (i, j) << ": " << GetData (i, j) << ") ";
      }
    else
      {
	for (j = 1 ; j <= ElementsInLine (i); j++)
	  s << "(" << GetColIndex (i, j) << ": " << GetData (i, j) << ") ";
      }

    s << endl;
    }
  return s;
  }






void SparseMatrix :: AddElementMatrix (const ARRAY<INDEX> & pnum,
      const BaseMatrix & elemmat)
{
  int i, j, i1, i2, n;

  n = pnum.Size();
  static ARRAY<int> spnum, map;
  spnum.SetSize (n);
  map.SetSize (n);

  for (i = 1; i <= n; i++)
    spnum.Elem(i) = pnum.Get(i);

  for (i = 1; i <= n; i++)
    for (j = 1; j <= n-1; j++)
      if (spnum.Elem(j) > spnum.Elem(j+1))
	swap (spnum.Elem(j), spnum.Elem(j+1));

  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      if (pnum.Get(i) == spnum.Get(j))
	map.Elem(j) = i;


  const DenseMatrix & delemmat = (const DenseMatrix&)elemmat;
  if (Symmetric())
    {
      for (i1 = 1; i1 <= n; i1++)
	{
	  INDEX ii1 = spnum.Get(i1);
	  const INDEX * coli = graph->lines.Get(ii1).col;
	  double * val = data.Get(ii1);
	  int ncol = graph->lines.Get(ii1).size;

	  int hi = 0;
	  for (i2 = 1; i2 <= i1; i2++)
	    {
	      while (coli[hi] < spnum.Get(i2))
		hi++;
	      val[hi] += delemmat.Get(map.Get(i1), map.Get(i2));
	    }
	}

      /*
      for (i1 = 1; i1 <= pnum.Size(); i1++)
	for (i2 = 1; i2 <= i1; i2++)
	  Elem(pnum.Get(i1), pnum.Get(i2)) += delemmat.Get(i1, i2);
	  */
    }
  else
    {
      for (i1 = 1; i1 <= n; i1++)
	{
	  INDEX ii1 = spnum.Get(i1);
	  const INDEX * coli = graph->lines.Get(ii1).col;
	  double * val = data.Get(ii1);
	  int ncol = graph->lines.Get(ii1).size;

	  int hi = 0;
	  for (i2 = 1; i2 <= n; i2++)
	    {
	      while (coli[hi] < spnum.Get(i2))
		hi++;
	      val[hi] += delemmat.Get(map.Get(i1), map.Get(i2));
	    }
	}

      /*
      for (i1 = 1; i1 <= pnum.Size(); i1++)
	for (i2 = 1; i2 <= pnum.Size(); i2++)
	  Elem(pnum.Get(i1), pnum.Get(i2)) += delemmat.Get(i1, i2);
	  */
    }
}




double SparseMatrix :: RowTimesVector (INDEX i, const Vector & v) const
  {
  const double * valp;
  const INDEX * col;
  int coln;
  double sum;
  int j;

  /*
  if (Width() > v.Length())
    {
    cerr << "SparseMatrix::RowTimesVector: Size doesn't fit" << endl;
    return 0;
    }
    */

  col = graph->lines.Get(i).col;
  valp = data.Get(i);
  sum = 0;
  coln = Symmetric() ? graph->lines.Get(i).diag : graph->lines.Get(i).size;

  for (j = 1; j <= coln; ++j, ++col, ++valp)
    sum += (*valp) * v.Get(*col);

  return sum;

  /*
	col = graph->lines.Get(i).col;
	valp = data.Get(i);
	coln = graph->lines.Get(i).size;
	val = v.Get(i);

	//      lin = &lins.Get(i);
	//      col = lin->col;
	//      val = v.Get(i);
      
      for (j = 1; j <= coln; j++, col++, valp++)
        prod.Elem(*col) += (*valp) * val;
	*/


  }
  


void SparseMatrix :: AddRowToVector (INDEX i, double s, Vector & v) const
{
  const double * valp;
  const INDEX * col;
  double * vp;
  int coln, j;
  
#ifdef debug  
  if (Width() > v.Length())
    {
      cerr << "SparseMatrix::AddRowToVector: Size doesn't fit" 
	   << "w = " << Width() << " len = " << v.Length() << endl;
      return;
    }
#endif    

  vp = &v.Elem(1) - 1;
  valp = data.Get(i);
  col = graph->lines.Get(i).col;
  coln =  Symmetric() ? graph->lines.Get(i).diag : graph->lines.Get(i).size;

  //  for (j = 0; j < coln; j++)
  //    vp[col[j]] += s * valp[j];

  for (j = coln-1; j >= 0; --j, ++valp, ++col)
    vp[*col] += s * (*valp);
}






char SparseMatrix :: Used (INDEX i, INDEX j) const
  {
  return (graph->GetPosition(i, j) != 0);
  }



double SparseMatrix :: Get(INDEX i, INDEX j) const
  {
  if (Symmetric() && (j > i)) swap (i, j);
    
  int pos = graph->GetPosition(i, j);
  if (pos)
    return data.Get(i)[pos-1];
  else 
    return 0;
  }
  

/*
  quick search:

  const colstruct * col = lins.Get(i).col;
  INDEX max = lins.Get(i).size;

  int l = 0, k = 1, newind;

  while (k < max)
    k <<= 1;


  while (k > 0)
    {
    k >>= 1;
    newind = k+l;
    if (newind >= max) continue;
    if (col[newind].colnr <= j)
      l += k;
    }

  if (l < max && col[l].colnr == j) return col[l].data;

  return 0;
  */
  


void SparseMatrix :: Set(INDEX i, INDEX j, double v)
  {
  Elem (i, j) = v;
  }



double & SparseMatrix :: Elem(INDEX i, INDEX j)
  {
  if (Symmetric() && j > i) swap (i, j);
  
  int pos = graph->GetPosition (i, j);
  if (!pos)
    {
      CreatePosition (i, j);
      pos = graph->GetPosition (i, j);
    }

  return data.Elem(i)[pos-1];
  }








SparseMatrixFlex :: SparseMatrixFlex (INDEX h, INDEX w)
  : SparseMatrix (h, w)
{
  INDEX i;
  graph = 
    mygraph = new MatrixGraph (h);

  data.SetSize (h);
  for (i = 1; i <= graph->Size(); i++)
    {
      data.Elem(i) = new double[graph->lines.Get(i).allocsize];
      data.Elem(i)[0] = 0;
    }
}

SparseMatrixFlex :: ~SparseMatrixFlex ()
{
  ;
}


void SparseMatrixFlex :: SetSize (INDEX /* h */, INDEX /* w */)
{
  cerr << "SparseMatrixFlex :: SetSize() not implemented" << endl;
}

void SparseMatrixFlex :: SetSymmetric (int sym)
{
  BaseMatrix::SetSymmetric (sym);
}

void SparseMatrixFlex :: ChangeSize (INDEX /* h */, INDEX /* w */)
{
  cerr << "SparseMatrixFlex :: ChangeSize() not implemented" << endl;
}


void SparseMatrixFlex :: DeleteElements ()
{
  ;
} 

BaseMatrix * SparseMatrixFlex :: Copy () const
{
  return (SparseMatrixFlex*)this;
}


int SparseMatrixFlex :: CreatePosition (INDEX i, INDEX j)
{
  int oldlinesize = graph->lines.Get(i).allocsize;
  if (mygraph->CreatePosition(i, j))
    {
      int newlinesize = graph->lines.Get(i).allocsize;
      if (oldlinesize != newlinesize)
	{
	  double * hdp = new double[newlinesize];
	  memcpy (hdp, data.Elem(i), sizeof(double) * oldlinesize);
	  delete data.Elem(i);
	  data.Elem(i) = hdp;
	}

      int pos = graph->GetPosition (i, j);
      int size = graph->lines.Get(i).size;

      memmove (&data.Elem(i)[pos], &data.Elem(i)[pos-1], 
	       sizeof(double) * (size-pos));
      data.Elem(i)[pos-1] = 0;
    }

  return 0;
}




SparseMatrixFix :: SparseMatrixFix (const MatrixGraph & agraph,
				     int asymmetric)
  : SparseMatrix (agraph.Size())
{
  graph = &agraph;
  SetSymmetric (asymmetric);

  data.SetSize (graph->Size());

  int i, nne;
  double * block;
  
  nne = 0;
  for (i = 1; i <= graph->Size(); i++)
    {
    if (Symmetric())
      nne += graph->lines.Get(i).diag;
    else
      nne += graph->lines.Get(i).size;
    }
    
  block = new double[nne];
  
  for (i = 0; i < nne; i++)
    block[i] = 0;

  nne = 0;
  for (i = 1; i <= graph->Size(); i++)
    {
    data.Elem(i) = &block[nne];
    if (Symmetric())
      nne += graph->lines.Get(i).diag;
    else
      nne += graph->lines.Get(i).size;
    }

}


SparseMatrixFix :: ~SparseMatrixFix ()
{
  ;
}

int SparseMatrixFix :: CreatePosition (INDEX i, INDEX j)
{
  (*myerr) << "SparseMatrixFix cannot change graph, requested: " 
       << i << "-" << j << endl;
  return 0;
}

#ifdef nothing


SparseMatrix :: SparseMatrix () : BaseMatrix (), lins()
  {
  };

SparseMatrix :: SparseMatrix (INDEX h, INDEX w) : BaseMatrix (h, w), lins (h)
  {
  if (!w) w = h;

  for (INDEX i = 1; i <= h; i++)
    {
    lins[i].size = 0;
    lins[i].maxsize = 0;
    lins[i].col = NULL;
    }
  }

SparseMatrix :: SparseMatrix (const SparseMatrix & m2) : BaseMatrix(), lins()
  {
  (*this) = m2;
  }


SparseMatrix :: ~SparseMatrix ()
  {
  DeleteElements ();
  }



void SparseMatrix :: SetSize (INDEX h, INDEX w)
  {
  if (!w) w = h;
  DeleteElements ();

  if (height == h && width == w) return;

  height = h;
  width = w;
  lins.SetSize (height);

  if (lins.Size () == height)
    {
    for (INDEX i = 1; i <= h; i++)
      {
      lins[i].size = 0;
      lins[i].maxsize = 0;
      lins[i].col = NULL;
      }
    }
  else
    {
    height = width = 0;
    (*myerr) << "SparseMatrix::SetSize: Out of memory" << endl;
    }
  }


void SparseMatrix :: ChangeSize (INDEX h, INDEX w)
  {
  INDEX i;

  if (!w) w = h;
  if (height == h && width == w) return;

  lins.SetSize (h);

  if (lins.Size () == h)
    {
    for (i = height+1; i <= h; i++)
      {
      lins[i].size = 0;
      lins[i].maxsize = 0;
      lins[i].col = NULL;
      }
    for (i = h+1; i <= height; i++)
      {
      if (lins[i].col)
        {
        DeleteColStruct (lins[i].col, lins[i].maxsize);

        lins[i].col = NULL;
        lins[i].size = 0;
        lins[i].maxsize = 0;
        }
      }

    height = h;
    width = w;
    }
  else
    {
    height = width = 0;
    (*myerr) << "SparseMatrix::SetSize: Out of memory" << endl;
    }
  }


void SparseMatrix :: SetSymmetric (int sym)
  {
  INDEX i, j;
  int nr;

  if (sym != Symmetric())
    {
    BaseMatrix :: SetSymmetric (sym);

    if (!sym)
      {
      for (i = 1; i <= Height(); i++)
        for (nr = 1; nr <= ElementsInLine (i); nr++)
          {
          j = GetIndex (i, nr);
          if (j < i)
            Elem (j, i) = GetData (i, nr);
          }
      }
    else
      {
      DeleteElements();
      }
    }
  }


void SparseMatrix :: DeleteElements ()
  {
  for (INDEX i = 1; i <= lins.Size(); i++)
    {
    if (lins[i].col)
      {
      DeleteColStruct (lins[i].col, lins[i].maxsize);

      lins[i].col = NULL;
      lins[i].size = 0;
      lins[i].maxsize = 0;
      }
    }
  }



double & SparseMatrix::operator() (INDEX i, INDEX j)
{
  if (i >= 1 && j >= 1 && i <= height && j <= width)
    {
      return Elem(i, j);
    }
  else (*myerr) << "\nindex (" << i << "," << j << ") out of range (1.."
	     << height << ",1.." << width << ")\n";
  return shit;
}

double SparseMatrix::operator() (INDEX i, INDEX j) const
{
  if (i >= 1 && j >= 1 && i <= height && j <= width)
    {
    return Get(i, j);
    }
  else (*myerr) << "\nindex (" << i << "," << j << ") out of range (1.."
	     << height << ",1.." << width << ")\n";
  return 0;
}

SparseMatrix & SparseMatrix :: operator= (const SparseMatrix & m2)
  {
  INDEX i, j;

  SetSize (m2.Height(), m2.Width());
  SetSymmetric (m2.Symmetric());

  for (i = 1; i <= m2.Height(); i++)
    for (j = 1; j <= m2.ElementsInLine(i); j++)
      (*this).Elem(i, m2.GetIndex(i, j)) = m2.GetData(i, j);
  return *this;
  }


SparseMatrix & SparseMatrix :: operator*= (double v)
  {
  INDEX i, j;

  for (i = 1; i <= Height(); i++)
    for (j = 1; j <= ElementsInLine(i); j++)
      GetDataRef(i, j) *= v;
  return *this;
  }



char SparseMatrix :: Used (INDEX i, INDEX j) const
  {
  if (Symmetric() && j > i) swap (i, j);

  if (i < 1 || i > height) return 0;

  const colstruct * col = lins.Get(i).col;
  INDEX max = lins.Get(i).size;

  for (int k = 0; k < max; k++, col++)
    if (col->colnr == j) return 1;

  return 0;
  }



double SparseMatrix :: Get(INDEX i, INDEX j) const
  {
  if (Symmetric() && j > i) swap (i, j);

  const colstruct * col = lins.Get(i).col;
  INDEX max = lins.Get(i).size;

  int l = 0, k = 1, newind;

  while (k < max)
    k <<= 1;


  while (k > 0)
    {
    k >>= 1;
    newind = k+l;
    if (newind >= max) continue;
    if (col[newind].colnr <= j)
      l += k;
    }

  if (l < max && col[l].colnr == j) return col[l].data;

  return 0;

  /*
  for (INDEX k = 0; k < max; k++, col++)
    if (col->colnr == j) 
      {
	if (l != k) cerr << "Set: ind not ok" << endl;
        else cerr << "is ok" << endl;
      return col->data;
      }

  return 0;
  */
  }


void SparseMatrix :: Set(INDEX i, INDEX j, double v)
  {
  Elem (i, j) = v;
  }



double & SparseMatrix :: Elem(INDEX i, INDEX j)
  {
  if (Symmetric() && j > i) swap (i, j);

  linestruct * lin = &lins.Elem(i);
  colstruct * col, *ncol;

  int size = lin->size;
  int pos;

  if (size)
    {

    // bereits Elemente in der Liste

    if (j > lin->col[size-1].colnr)
      {

      // neues Element an letzter Position einfuegen

      if (lin->maxsize > size)
        {
        lin->size++;
        lin->col[size].colnr = j;
        return lin->col[size].data = 0;
        }

      if ( (ncol = NewColStruct(lin->maxsize+4)/* new colstruct[lin->maxsize+4] */) != NULL)
        {
        memcpy (ncol, lin->col, sizeof(colstruct) * size);

        DeleteColStruct (lin->col, lin->maxsize);

        lin->maxsize += 4;
        lin->col = ncol;
        lin->size++;
        ncol[size].colnr = j;
        return ncol[size].data = 0;
        }
      else
        {
        (*myerr) << "SparseMatrix::Elem: Out of memory 1" << endl;
        return shit;
        }

      }
    else
      {

      for (col = lin->col; col->colnr < j; col++);
                                        // Zeilenliste durchsuchen

      if (col->colnr == j) return col->data;
                                        // Element exisitiert bereits

      if (lin->maxsize > size)
        {
        memmove (col+1, col, size_t((char*)&lin->col[size] - (char*)col));

        lin->size++;
        col->colnr = j;
        return col->data = 0;
        }

      pos = size_t (col - lin->col);

      if ( (ncol = NewColStruct(lin->maxsize+4) ) != NULL)
        {

        if (pos) memcpy (ncol, lin->col, sizeof(colstruct) * pos);
        memcpy (ncol+(pos+1), col, sizeof(colstruct) * (size-pos));

        DeleteColStruct (lin->col, lin->maxsize);
//        delete lin->col;

        lin->maxsize += 4;
        lin->col = ncol;
        lin->size++;
        ncol[pos].colnr = j;
        return ncol[pos].data = 0;
        }
      else
        {
        (*myerr) << "SparseMatrix::Elem: Out of memory 2" << endl;
        return shit;
        }
      }
    }
  else
    {
    // kein Element in der Liste

    if (lin->maxsize)
      {
      // Liste bereits angelegt

      lin->size = 1;
      lin->col->colnr = j;
      return lin->col->data = 0;
      }
    else
      {
      if ( (lin->col = NewColStruct(6) ) != NULL )
        {
        lin->maxsize = 6;
        lin->size = 1;
        lin->col->colnr = j;
        return lin->col->data = 0;
        }
      else
        {
        (*myerr) << "SparseMatrix::Elem: Out of memory 3" << endl;
        return shit;
        }
      }
    }
  }



void SparseMatrix :: Delete (INDEX i, int nr)
  {
  colstruct * col = lins[i].col;

  nr--;
  while (nr < lins[i].size-1)
    {
    col[nr].data = col[nr+1].data;
    col[nr].colnr = col[nr+1].colnr;
    nr++;
    }
  lins[i].size--;
  }

void SparseMatrix :: DeleteElem (INDEX i, INDEX j)
  {
  int nr;
  int dec = 0;

  if (Symmetric() && j > i) swap (i, j);

  colstruct * col = lins[i].col;

  for (nr = 0; nr < lins[i].size; nr++)
    {
    if (dec)
      {
      col[nr-1].data = col[nr].data;
      col[nr-1].colnr = col[nr].colnr;
      }
    if (col[nr].colnr == j) dec = 1;
    }
  if (dec)
    lins[i].size--;
  }


void SparseMatrix :: SetLineAllocSize (INDEX i, int j)
  {
  colstruct * ncol;


  if (lins[i].maxsize < j)
    {
    if ( (ncol = NewColStruct(j)) != NULL)
      {
      memcpy (ncol, lins[i].col, sizeof(colstruct) * lins[i].size);

      if (lins[i].maxsize)
        DeleteColStruct (lins[i].col, lins[i].maxsize);

      lins[i].maxsize = j;
      lins[i].col = ncol;
      }
    else
      (*myerr) << "SPARSE_MATIRX :: SetLineAllocSize: Out of Memory" << endl;
    }
  }









  
  



SparseMatrix operator* (const SparseMatrix & m1,
                         const SparseMatrix & m2)
  {
  SparseMatrix m(m1.Height(), m2.Width());
  INDEX i, j, k, nr;

  if (!m1.Symmetric() && !m2.Symmetric())
    {
    for (i = 1; i <= m1.Height(); i++)
      {
      for (j = 1; j <= m1.ElementsInLine(i); j++)
        {
        nr = m1.GetIndex (i, j);
        for (k = 1; k <= m2.ElementsInLine(nr); k++)
          {
          m(i, m2.GetIndex(nr, k)) += m1.GetData(i, j) * m2.GetData(nr, k);
          }
        }
      }
    }
  else
    {
    (*myerr) << "SparseMatrix :: operator* not implemented for symmetric case" << endl;
    }
  return m;
  }


SparseMatrix & SparseMatrix :: operator+= (const SparseMatrix & m2)
  {
  INDEX i, k;
  int j;

  if (Symmetric() == m2.Symmetric())
    {
    for (i = 1; i <= Height(); i++)
      for (j = 1; j <= m2.ElementsInLine (i); j++)
        {
        k = m2.GetIndex (i, j);
        Elem(i, k) += m2.GetData (i, j);
        }
    }
  else
    {
    (*myerr) << "SparseMatrix :: operator+= not implemented for different cases" << endl;
    }
  return *this;
  }



SparseMatrix & SparseMatrix :: operator*= (const SparseMatrix & m2)
  {
  INDEX i, k;
  int j, l;
  colstruct * cs;
  int ms, s;

  if (!Symmetric() && !m2.Symmetric())
    {
    for (i = 1; i <= Height(); i++)
      {
      cs = lins[i].col;
      s = lins[i].size;
      ms = lins[i].maxsize;

      lins[i].col = NULL;
      lins[i].size = 0;
      lins[i].maxsize = 0;


      for (j = 0; j < s; j++)
        {
        k = cs[j].colnr;

        for (l = 1; l <= m2.ElementsInLine (k); l++)
          Elem(i, m2.GetIndex(k, l)) += cs[j].data * m2.GetData(k, l);
        }

      DeleteColStruct (cs, ms);
      }
    }
  else
    {
    (*myerr) << "SparseMatrix :: operator*= not implemented for Symmetric matrices" << endl;
    }

  return *this;
  }


void SparseMatrix :: Solve (const Vector & v, Vector & sol) const
  {
  SparseMatrix temp = *this;
  INDEX i, j, nr, k;
  double q;

  sol = v;


  if (!Symmetric())
    {
    for (i = 1; i <= Height(); i++)
      {
      if (temp.ElementsInLine(i) < 1 || temp.GetIndex(i, 1) != i)
        {
        (*myerr) << "i = " << i << endl;
        (*myerr) << "Solve: Matrix singular" << endl;
        char ch;
        cin >> ch;
        }
      for (j = 2; j <= temp.ElementsInLine(i); j++)
        {
        nr = temp.GetIndex(i, j);
        if (temp.GetIndex(nr, 1) != i)
          {
          (*myerr) << temp << endl;
          (*myerr) << "i = " << i << "j = " << j << "nr = " << nr << endl;
          (*myerr) << "Solve: Graph not symmetrix" << endl;
          char ch;
          cin >> ch;
          }

        q = temp.GetData (nr, 1) / temp.GetData(i, 1);
        temp.Delete (nr, 1);

        for (k = 2; k <= temp.ElementsInLine (i); k++)
          temp.Elem(nr, temp.GetIndex(i, k)) -= q * temp.GetData(i, k);

        sol(nr) -= q * sol(i);
        }
      }

    for (i = temp.Height(); i >= 1; i--)
      {
      for (j = 2; j <= temp.ElementsInLine(i); j++)
        {
        sol(i) -= temp.GetData(i, j) * sol(temp.GetIndex(i, j));
        }
      sol(i) /= temp.GetData(i, 1);
      }
    }
  else
    (*myerr) << "SparseMatrix :: Solve not implemented for symmetic case" << endl;
  }





void Transpose (const SparseMatrix & m1, SparseMatrix & m2)
  {
  INDEX i, j;

  m2.SetSize(m1.Width(), m1.Height());
  m2.SetSymmetric(m1.Symmetric());

  if (!m1.Symmetric())
    {
    for (i = 1; i <= m1.Height(); i++)
      for (j = 1; j <= m1.ElementsInLine(i); j++)
        m2(m1.GetIndex(i, j), i) = m1.GetData(i, j);
    }
  else
    m2 = m1;
  }



BaseMatrix * SparseMatrix :: Copy () const
  {
  return new SparseMatrix (*this);
  }







void SparseMatrix :: AddRowMatrix (INDEX row, const SparseMatrix & m2)
  {
  int i1, i2, i;
  colstruct * cs1, * cs2, * ncs;
  int s1, s2, s;

  s1 = lins[row].size;
  s2 = m2.lins[1].size;
  cs1 = lins[row].col;
  cs2 = m2.lins[1].col;

  i1 = 0;
  i2 = 0;
  i = 0;


  if (Symmetric())
    {
    while (s2 && cs2[s2-1].colnr > row) s2--;
    }


  while (i1 < s1 && i2 < s2)
    {
    if (cs1[i1].colnr < cs2[i2].colnr) i1++;
    else if (cs1[i1].colnr > cs2[i2].colnr) i2++;
    else { i1++; i2++; }
    i++;
    }

  i += (s1 - i1);
  i += (s2 - i2);

  s = i;

  if (s > s1)
    {
    ncs = NewColStruct (s);

    i1 = 0;
    i2 = 0;
    i = 0;

    while (i1 < s1 && i2 < s2)
      {
      if (cs1[i1].colnr < cs2[i2].colnr)
        {
        ncs[i].colnr = cs1[i1].colnr;
        ncs[i].data = cs1[i1].data;
        i1++;
        }
      else if (cs1[i1].colnr > cs2[i2].colnr)
        {
        ncs[i].colnr = cs2[i2].colnr;
        ncs[i].data = cs2[i2].data;
        i2++;
        }
      else
        {
        ncs[i].colnr = cs1[i1].colnr;
        ncs[i].data = cs1[i1].data + cs2[i2].data;
        i1++;
        i2++;
        }
      i++;
      }

    while (i1 < s1)
      {
      ncs[i].colnr = cs1[i1].colnr;
      ncs[i].data = cs1[i1].data;
      i1++;
      i++;
      }

    while (i2 < s2)
      {
      ncs[i].colnr = cs2[i2].colnr;
      ncs[i].data = cs2[i2].data;
      i2++;
      i++;
      }

    if (lins[row].maxsize)
      DeleteColStruct (cs1, lins[row].maxsize);

    lins[row].col = ncs;
    lins[row].size = s;
    lins[row].maxsize = s;
    }


  else
    {
    i1 = 0;
    i2 = 0;

    while (i2 < s2)
      {
      if (cs1[i1].colnr == cs2[i2].colnr)
        {
        cs1[i1].data += cs2[i2].data;
        i2++;
        }
      i1++;
      }
    }
  }


double SparseMatrix :: RowTimesVector (INDEX i, const Vector & v) const
  {
  const linestruct * lin;
  const colstruct * col;
  double sum;
  int j;

  if (Width() > v.Length())
    {
    cerr << "SparseMatrix::RowTimesVector: Size doesn't fit" << endl;
    return 0;
    }

  lin = &lins.Get(i);
  sum = 0;
  col = lin->col;

  for (j = lin->size; j > 0; j--, col++)
    sum += col->data * v.Get(col->colnr);

  return sum;
  }
  
void SparseMatrix :: AddRowToVector (INDEX i, double s, Vector & v) const
  {
  const linestruct * lin;
  const colstruct * col;
  int j;

  if (Width() > v.Length())
    {
    cerr << "SparseMatrix::AddRowToVector: Size doesn't fit" 
    	 << "w = " << Width() << " len = " << v.Length() << endl;
    return;
    }

  lin = &lins.Get(i);
  col = lin->col;

  for (j = lin->size; j > 0; j--, col++)
    v.Elem(col->colnr) += s * col->data;
  }


static ARRAY<void*> poolarray;
static ARRAY<int> poolsizes;


SparseMatrix::colstruct * SparseMatrix :: NewColStruct (int s)
  {
//  return new colstruct[s];


  int i, j;
  void * p;
  colstruct * cs;

  if (s > 20) return new colstruct[s];

  for (i = 1; i <= poolsizes.Size(); i++)
    if (poolsizes.Get(i) == s) break;

  if (i > poolsizes.Size())
    {
    poolsizes.Append(s);
    poolarray.Append((void*)NULL);
    i = poolsizes.Size();
    }

  p = poolarray.Get(i);
  if (!p)
    {
    poolarray.Elem(i) = p = cs = new colstruct[10 * s];
    for (j = 0; j < 9; j++)
      *(void**)(void*)(&cs[s * j]) = &cs[s * (j+1)];
    *(void**)(void*)(&cs[s * 9]) = NULL;
    }

  poolarray.Elem(i) = *(void**)p;
  return (colstruct*)p;
  }

void SparseMatrix :: DeleteColStruct (colstruct * cs, int s)
  {
//  delete cs;
//  return;

  int i;

  if (s > 20)
    {
    delete cs;
    return;
    }

  for (i = 1; i <= poolsizes.Size(); i++)
    if (poolsizes.Get(i) == s) break;


  if (i > poolsizes.Size())
    {
    (*myerr) << "SparseMatrix :: DeleteColStruct: Size not found" << endl;
    return;
    }


  *(void**)(void*)cs = poolarray.Get(i);
  poolarray.Elem(i) = cs;
  }

void SparseMatrix :: SetGraph (const class TABLE<INDEX> & graph)
  { 
  int i, j, es, ad, nne;
  colstruct * block;
  
  nne = 0;
  for (i = 1; i <= graph.Size(); i++)
    {
    if (Symmetric())
      {
      es = 0;
      for (j = 1; j <= graph.EntrySize(i); j++)
        if (graph.Get(i, j) <= i)
          es++;
      }
    else
      es = graph.EntrySize(i);
    nne += es;
    }
    
  oneblock = 1;
  block = new colstruct[nne];
  
  ad = 0;
  for (i = 1; i <= graph.Size(); i++)
    {
    if (Symmetric())
      {
      es = 0;
      for (j = 1; j <= graph.EntrySize(i); j++)
        if (graph.Get(i, j) <= i)
          es++;
      }
    else
      es = graph.EntrySize(i);
      
    lins.Elem(i).size = 0;
    lins.Elem(i).maxsize = es;
    lins.Elem(i).col = &block[ad];
    ad += es;
    }
  }




#endif
}
