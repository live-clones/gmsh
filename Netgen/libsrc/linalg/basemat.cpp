#include <mystdlib.h>
#include <linalg.hpp>


// ofstream (*myerr) ("error.out");
// ofstream (*myerr) ("NUL");


namespace netgen
{

double BaseMatrix :: shit = 0;


BaseMatrix :: BaseMatrix ()
  {
  height = width = 0;
  symmetric = 0;
  }

BaseMatrix :: BaseMatrix (INDEX h, INDEX w)
  {
  if (!w) w = h;
  height = h;
  width = w;
  symmetric = 0;
  }

void BaseMatrix :: SetSize (INDEX h, INDEX w)
  {
  if (!w) w = h;
  height = h;
  width = w;
  }

void BaseMatrix :: SetSymmetric (int sym)
  {
  symmetric = sym;
  }

double & BaseMatrix :: operator() (INDEX, INDEX)
  {
  (*myerr) << "BaseMatrix: operator() called" << endl;
  return shit;
  }

double BaseMatrix :: operator() (INDEX, INDEX) const
  {
  (*myerr) << "BaseMatrix: operator() called" << endl;
  return 0;
  }



ostream & operator<<(ostream & s, const BaseMatrix & m)
  {
  return m.Print (s);
  }

ostream & BaseMatrix :: Print (ostream & s) const
  {
  if (Symmetric()) s << "Symmetric" << endl;
  for (INDEX i = 1; i <= Height(); i++)
    {
    for (INDEX j = 1; j < Width(); j++)
      s << (*this)(i, j) << "  ";
    s << (*this)(i, Width()) << endl;
    }

  return s;
  }



TempVector BaseMatrix :: operator* (const BaseVector & v) const
  {
  Vector * prod = new Vector(Height());

  if (Width() != v.Length())
    {
    (*myerr) << "\nMatrix and Vector don't fit 1" << endl;
    }
  else if (Height() != prod->Length())
    {
    (*myerr) << "Base_Matrix::operator*(Vector): prod vector not ok" << endl;
    }
  else
    {
    Mult (v, *prod);
    }

  return *prod;
  }



DenseMatrix operator* (const BaseMatrix & m1, const BaseMatrix & m2)
  {
  DenseMatrix temp (m1.Height(), m2.Width());
  double sum;

  if (m1.Width() != m2.Height())
         {
         (*myerr) << "BaseMatrix :: operator*: Matrix Size does not fit" << endl;
         }
  else if (temp.Height() != m1.Height())
         {
         (*myerr) << "BaseMatrix :: operator*: temp not allocated" << endl;
    }
  else
    {
    for (INDEX i = 1; i <= m1.Height(); i++)
      for (INDEX j = 1; j <= m2.Width(); j++)
        {
        sum = 0;
        for (INDEX k = 1; k <= m1.Width(); k++)
          sum += m1(i, k) * m2(k, j);
        temp(i, j) = sum;
        }
    }
  return temp;
  }


DenseMatrix operator+ (const BaseMatrix & m1, const BaseMatrix & m2)
  {
  DenseMatrix temp (m1.Height(), m1.Width());
  INDEX i, j;

  if (m1.Width() != m2.Width() || m1.Height() != m2.Height())
    {
    (*myerr) << "BaseMatrix :: operator+: Matrix Size does not fit" << endl;
    }
  else if (temp.Height() != m1.Height())
    {
    (*myerr) << "BaseMatrix :: operator+: temp not allocated" << endl;
    }
  else
    {
    for (i = 1; i <= m1.Height(); i++)
      for (j = 1; j <= m1.Width(); j++)
        {
        temp(i, j) = m1(i, j) + m2(i, j);
        }
    }
  return temp;
  }


void BaseMatrix :: Mult (const BaseVector & /* v */,
      BaseVector & /* prod */) const
  {
  (*myerr) << "BaseMatrix :: Mult called" << endl;
  }

void BaseMatrix :: MultTrans (const BaseVector &  v,
      BaseVector & prod) const
  {
  if (Symmetric())
    Mult (v, prod);
  else
    (*myerr) << "BaseMatrix :: MultTrans called for non symmetric matrix" << endl;
  }

void BaseMatrix :: Residuum (const BaseVector &  x,
      const BaseVector & b, BaseVector & res) const
  {
  Mult (x, res);
  res *= -1;
  res.Add (1, b);
  }

void BaseMatrix :: ResiduumTrans (const BaseVector & x,
      const BaseVector & b, BaseVector & res) const
  {
  MultTrans (x, res);
  res *= -1;
  res.Add (1, b);
  }

BaseMatrix * BaseMatrix :: Copy () const
  {
  (*myerr) << "BaseMatrix :: Copy called" << endl;
  return NULL;
  }


BaseVector * BaseMatrix :: CreateVector () const
  {
  return new Vector (Height());
  }



/*
void BaseMatrix :: Mult (const Vector & v, Vector & prod) const
  {
  double sum;

  prod.SetLength (Height());

  if (Width() != v.Length())
    {
    (*myerr) << "\nMatrix and Vector don't fit 2" << endl;
    }
  else if (Height() != prod.Length())
    {
    (*myerr) << "Base_Matrix::operator*(Vector): prod vector not ok" << endl;
    }
  else
    {
    for (INDEX i = 1; i <= Height(); i++)
      {
      sum = 0;

      for (INDEX j = 1; j <= Width(); j++)
        sum += (*this)(i,j) * v.Get(j);

      prod.Set (i, sum);
      }
    }
  }


void BaseMatrix :: MultTrans (const Vector & v, Vector & prod) const
  {
  double sum;

  prod.SetLength (Width());

  if (Height() != v.Length())
    {
    (*myerr) << "\nMatrix and Vector don't fit 3" << endl;
    }
  else if (Width() != prod.Length())
    {
    (*myerr) << "Base_Matrix::operator*(Vector): prod vector not ok" << endl;
    }
  else
    {
    for (INDEX i = 1; i <= Width(); i++)
      {
      sum = 0;

      for (INDEX j = 1; j <= Height(); j++)
        sum += (*this)(j, i) * v.Get(j);

      prod.Set (i, sum);
      }
    }
  }


void BaseMatrix :: Residuum (const Vector & x, const Vector & b, Vector & res) const
  {
  double sum;

  res.SetLength (Height());

  if (Width() != x.Length() || Height() != b.Length())
    {
    (*myerr) << "\nMatrix and Vector don't fit 4" << endl;
    }
  else if (Height() != res.Length())
    {
    (*myerr) << "Base_Matrix::operator*(Vector): prod vector not ok" << endl;
    }
  else
    {
    for (INDEX i = 1; i <= Height(); i++)
      {
      sum = b.Get(i);

      for (INDEX j = 1; j <= Width(); j++)
        sum -= (*this)(i,j) * x.Get(j);

      res.Set (i, sum);
      }
    }
  }
*/







void BaseMatrix :: SolveDestroy (const Vector & v, Vector & sol)
  {
  INDEX i, j, k;
  double q;

  if (Width() != Height())
    {
    (*myerr) << "SolveDestroy: Matrix not square";
    return;
    }
  if (Width() != v.Length())
    {
    (*myerr) << "SolveDestroy: Matrix and Vector don't fit";
    return;
    }

  sol = v;
  if (Height() != sol.Length())
    {
    (*myerr) << "SolveDestroy: Solution Vector not ok";
    return;
    }

  for (i = 1; i <= Height(); i++)
    {
    for (j = i+1; j <= Height(); j++)
      {
      q=(*this)(j,i) / (*this)(i,i);
      for (k = i+1; k <= Height(); k++)
        {
        (*this)(j, k) -= q * (*this)(i,k);
        }
      sol.Elem(j) -= q * sol.Get(i);
      }
    }

  for (i = Height(); i >= 1; i--)
    {
    q = sol(i);
    for (j = i+1; j <= Height(); j++)
      {
      q -= (*this)(i,j) * sol.Get(j);
      }
    sol.Set(i, q / (*this)(i,i));
    }
  }

void BaseMatrix :: Solve (const Vector & v, Vector & sol) const
  {
  BaseMatrix * temp = Copy();

  if (temp->Height() != Height())
    {
    (*myerr) << "Solve: Matrix temp not allocated" << endl;
    return;
    }

  temp->SolveDestroy (v, sol);

  delete temp;
  }


Vector BaseMatrix :: SolveDestroyFunc (const Vector & /* b */) const
{
  return Vector(0);
}



Vector BaseMatrix :: Solve (const Vector & v) const
  {
  Vector sol (v.Length());

  if (Width() != Height())
    {
    (*myerr) << "Solve: Matrix not square";
    return v;
    }
  if (Width() != v.Length())
    {
    (*myerr) << "Solve: Matrix and Vector don't fit";
    return v;
    }
  if (Width() != sol.Length())
    {
    (*myerr) << "Solve: Vector sol not allocated" << endl;
    }

  Solve (v, sol);

  return sol;
  }







void BaseMatrix :: LU_Decomposition (DenseMatrix & l, DenseMatrix & u) const
  {
  INDEX i, j ,k;
  double sum;
  l.SetSize (Width());
  u.SetSize (Width());

  for (i = 1; i <= Width(); i++)
    for (j = 1; j <= Width(); j++)
      l(i, j) = u(i, j) = 0;

  for (i = 1; i <= Width(); i++)
    {
    for (k = 1; k < i; k++)
      {
      sum = (*this)(i, k);
      for (j = 1; j < k; j++)
        sum -= l(i, j) * u(j, k);
      l(i, k) = sum / u(k, k);
      }
    l(i, i) = 1;

    for (k = i; k <= Width(); k++)
      {
      sum = (*this)(i, k);
      for (j = 1; j < i; j++)
        sum -= l(i, j) * u(j, k);
      u(i, k) = sum;
      }
    }
  }



void Transpose (const BaseMatrix & m1, DenseMatrix & m2)
  {
  m2.SetSize (m1.Width(), m1.Height());
  INDEX i, j;

  for (i = 1; i <= m1.Height(); i++)
    for (j = 1; j <= m1.Width(); j++)
      m2(j, i) = m1(i, j);
  }



DenseMatrix * BaseMatrix :: MakeDenseMatrix () const
{
  DenseMatrix * dmat = new DenseMatrix (Height(), Width());
  dmat -> SetSymmetric(Symmetric());

  Vector x(Width()), y(Height());
  INDEX i, j;

  for (i = 1; i <= Width(); i++)
    {
      x = 0;
      x.Elem(i) = 1;
      Mult (x, y);
      
      for (j = 1; j <= Height(); j++)
	dmat->Elem(j, i) = y.Get(j);
    }

  return dmat;
}
 

BaseMatrix * BaseMatrix :: InverseMatrix (const BitArray * /* inner */) const
{
  (*mycout) << "called basematrix::inversemarix" << endl;
  return NULL;
}



}
