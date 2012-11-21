from dgpy import *
import random
import math



# Parameters
Nr = 100
p = 2



# Evaluate polynomial
def polyEval(FCT, p, coeff, uvw):
  for n in range(uvw.size1()):
    u = uvw(n,0)
    v = uvw(n,1)
    w = uvw(n,2)
    FCT.set(n,0)
    ind = 0
    for i in range(p+1):
      upi = math.pow(u,i)
      for j in range(p+1-i):
        vpj = math.pow(v,j)
        for k in range(p+1-i-j):
          FCT.set(n,FCT(n)+coeff(ind)*upi*vpj*math.pow(w,k))
          ind += 1



# Evaluate gradient of polynomial
def gradPolyEval(FCT, p, coeff, uvw):
  for n in range(uvw.size1()):
    u = uvw(n,0)
    v = uvw(n,1)
    w = uvw(n,2)
    FCT.set(3*n,0)
    FCT.set(3*n+1,0)
    FCT.set(3*n+2,0)
    ind = 0
    for i in range(p+1):
      upi = math.pow(u,i)
      if (i == 0):
        dupi = 0
      else:
        dupi = i*math.pow(u,i-1)
      for j in range(p+1-i):
        vpj = math.pow(v,j)
        if (j == 0):
          dvpj = 0
        else:
          dvpj = j*math.pow(v,j-1)
        for k in range(p+1-i-j):
          wpk = math.pow(w,k)
          if (k == 0):
            dwpk = 0
          else:
            dwpk = k*math.pow(w,k-1)
          FCT.set(3*n,FCT(3*n)+coeff(ind)*dupi*vpj*wpk)
          FCT.set(3*n+1,FCT(3*n+1)+coeff(ind)*upi*dvpj*wpk)
          FCT.set(3*n+2,FCT(3*n+2)+coeff(ind)*upi*vpj*dwpk)
          ind += 1



# Evaluate approx. on nodal basis
def interp(FCT, basis, coeff, uvw):
  sf = fullMatrixDouble(uvw.size1(),coeff.size())
  basis.f(uvw,sf)
  for i in range(uvw.size1()):
    FCT.set(i,0)
    for j in range(coeff.size()):
      FCT.set(i,FCT(i)+coeff(j)*sf(i,j))



# Evaluate gradient of approx. on nodal basis
def gradInterp(FCT, basis, coeff, uvw):
  gsf = fullMatrixDouble(coeff.size(),3*uvw.size1())
  basis.df(uvw,gsf)
  for i in range(3*uvw.size1()):
    FCT.set(i,0)
    for j in range(coeff.size()):
      FCT.set(i,FCT(i)+coeff(j)*gsf(j,i))



# Test if point is in unit pyramid
def isInPyr(u,v,w):
  if ((w >= 0) and (w < 1)):
    uh = u/(1-w)
    vh = v/(1-w)
    return ((uh >= -1) and (uh <= 1) and (vh >= -1) and (vh <= 1))
  elif (w == 1):
    return ((u == 0) and (v == 0))
  else:
    return False



# Generate polynomial of order p with random coefficients
Np = (p+1)*(p+2)*(p+3)/6
poly = fullVectorDouble(Np)
for i in range(Np):
  poly.set(i,random.random())

# Get appropriate basis
if (p == 1):
  basis = pyramidalBasis(MSH_PYR_5)
elif (p == 2):
  basis = pyramidalBasis(MSH_PYR_14)
elif (p == 3):
  basis = pyramidalBasis(MSH_PYR_30)
elif (p == 4):
  basis = pyramidalBasis(MSH_PYR_55)
elif (p == 5):
  basis = pyramidalBasis(MSH_PYR_91)
elif (p == 6):
  basis = pyramidalBasis(MSH_PYR_140)
elif (p == 7):
  basis = pyramidalBasis(MSH_PYR_204)
elif (p == 8):
  basis = pyramidalBasis(MSH_PYR_285)
elif (p == 9):
  basis = pyramidalBasis(MSH_PYR_385)

print("Basis:\n -> type = %i\n -> parentType = %i\n -> order = %i\n -> points = %i\n -> dimension = %i\n -> numFaces = %i\n -> serendip = %s" %
      (basis.type, basis.parentType, basis.order, basis.points.size1(), basis.dimension, basis.numFaces, basis.serendip))

#print("%i points:" % basis.points.size1())
#for i in range(basis.points.size1()) :
#  print(" -> (%g, %g, %g)" % (basis.points(i,0), basis.points(i,1), basis.points(i,2)))

#sf = fullMatrixDouble(basis.points.size1(),5)
#basis.f(basis.points,sf)
#print("SF:")
#for i in range(5) :
#  print(" -> %g %g %g %g %g" % (sf(i,0), sf(i,1), sf(i,2), sf(i,3), sf(i,4)))

# nodal coefficients of function to be evaluated
nodalCoeff = fullVectorDouble(basis.points.size1())
polyEval(nodalCoeff,p,poly,basis.points)
#print("%i nodalCoeffs:" % nodalCoeff.size())
#for i in range(nodalCoeff.size()) :
#  print(" -> %g" % nodalCoeff(i))

# Generate Nr random points in pyramid (well, Nr-5 random plus vertices to test indeterminate form)
uvwr = fullMatrixDouble(Nr,3)
uvwr.set(0,0,-1); uvwr.set(0,1,-1); uvwr.set(0,2,0)
uvwr.set(1,0,-1); uvwr.set(1,1,1); uvwr.set(1,2,0)
uvwr.set(2,0,1); uvwr.set(2,1,1); uvwr.set(2,2,0)
uvwr.set(3,0,1); uvwr.set(3,1,-1); uvwr.set(3,2,0)
uvwr.set(4,0,0); uvwr.set(4,1,0); uvwr.set(4,2,1)
for i in range(5,Nr):
  uvwr.set(i,0,1000)
  uvwr.set(i,1,1000)
  uvwr.set(i,2,1000)
  while (not isInPyr(uvwr(i,0),uvwr(i,1),uvwr(i,2))):
    uvwr.set(i,0,random.random())
    uvwr.set(i,1,random.random())
    uvwr.set(i,2,random.random())

# Exact value and gradient of function at random points
valExact = fullVectorDouble(Nr)
polyEval(valExact,p,poly,uvwr)
gradExact = fullVectorDouble(3*Nr)
gradPolyEval(gradExact,p,poly,uvwr)

# Approx. value and gradient of function at random points
valApp = fullVectorDouble(Nr)
interp(valApp,basis,nodalCoeff,uvwr)
gradApp = fullVectorDouble(3*Nr)
gradInterp(gradApp,basis,nodalCoeff,uvwr)

# Compute error
avgErrVal = 0
avgErrGradX = 0
avgErrGradY = 0
avgErrGradZ = 0
for i in range(Nr):
  avgErrVal += (valApp(i)-valExact(i))*(valApp(i)-valExact(i))
  avgErrGradX += (gradApp(3*i)-gradExact(3*i))*(gradApp(3*i)-gradExact(3*i))
  avgErrGradY += (gradApp(3*i+1)-gradExact(3*i+1))*(gradApp(3*i+1)-gradExact(3*i+1))
  avgErrGradZ += (gradApp(3*i+2)-gradExact(3*i+2))*(gradApp(3*i+2)-gradExact(3*i+2))
avgErrVal = math.sqrt(avgErrVal)/Nr
avgErrGradX = math.sqrt(avgErrGradX)/Nr
avgErrGradY = math.sqrt(avgErrGradY)/Nr
avgErrGradZ = math.sqrt(avgErrGradZ)/Nr

# Print error
print("Check on %i random points:" % Nr)
print(" -> average error value = %g" % avgErrVal)
print(" -> average error X gradient = %g" % avgErrGradX)
print(" -> average error Y gradient = %g" % avgErrGradY)
print(" -> average error Z gradient = %g" % avgErrGradZ)

