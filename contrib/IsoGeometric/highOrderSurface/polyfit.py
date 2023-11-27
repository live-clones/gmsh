import numpy as np

EPS = 1e-6


def polyfitMatrix1D(t, nRows):
  X = np.empty([len(t), nRows])
  for i in range(len(t)):
    for j in range(nRows):
      X[i][j] = t[i] ** j
  return X

def polyfitMatrix2D(u, v, nRows):
  X = np.empty([len(u), nRows])    # int((degree)*(degree+1)/2)
  for j in range(len(u)):
    d = 0
    c = 0
    while (c < nRows):
      for i in range(d + 1):
        X[j][c] = u[j] ** (d - i) * v[j] ** i
        c += 1
        if (c >= nRows):
          break
      d += 1
  return X

def polyfitEval1D(coefficients, t):
  if isinstance(t, (int, float)):
    x = polyfitMatrix1D([t], len(coefficients))
    return np.dot(x, coefficients)[0]
  else:
    x = polyfitMatrix1D(t, len(coefficients))
    return np.dot(x, coefficients)

def polyfitEval2D(coefficients, u, v):
  #degree = int((-1 + ((8 * len(coefficients)) ** (1./2))) / 2)
  if isinstance(u, (int, float)):
    x = polyfitMatrix2D([u], [v], len(coefficients))
    return np.dot(x, coefficients)[0]
  else:
    x = polyfitMatrix2D(u, v, len(coefficients))
    return np.dot(x, coefficients)

def polyfitComputeImplementation(X, x, forcedIndices):
  for j,forcedIndex in enumerate(forcedIndices):
    if (abs(X[forcedIndex][j]) < EPS):
      for k in range(len(x)):
        if k in forcedIndices[:j]:
          continue
        if (abs(X[k][j]) > EPS):
          X[forcedIndex] = X[forcedIndex] + X[k]
          x[forcedIndex] = x[forcedIndex] + x[k]
          break

    for i in range(len(x)):
      if (i != forcedIndex):
        tmp = X[i][j]/X[forcedIndex][j]
        X[i] = X[i] - tmp * X[forcedIndex]
        x[i] = x[i] - tmp * x[forcedIndex]

  A = np.delete(X, forcedIndices, 0)
  A = np.delete(A, range(len(forcedIndices)), 1)
  b = np.delete(x, forcedIndices, 0)

  if (A.shape[1] > 0):
    if (A.shape[0] == A.shape[1]):
      coefficients = np.linalg.solve(A, b)
    else:
      coefficients, residuals, _, _ = np.linalg.lstsq(A, b, rcond=None)
  else:
    coefficients = []
  
  if (len(forcedIndices) > 0):
    A = X[forcedIndices, :]
    A = np.delete(A, range(len(forcedIndices)), 1)
    b = x[forcedIndices]
    b = b - np.dot(A, coefficients)
    
    A = X[forcedIndices, :]
    A = A[:, range(len(forcedIndices))]
    coefficients = np.append(np.linalg.solve(A, b), coefficients)
  return coefficients


def polyfitCompute1D(t, x, degree, forcedIndices=[]):
  if (degree < 1):
    raise ValueError("Degree of the fitting polynomial must be larger than zero")
  d = degree+1
  if (len(t) < d):
    d = len(t)-1
  X = polyfitMatrix1D(t, d)
  return polyfitComputeImplementation(X, x.copy(), forcedIndices)


def polyfitCompute2D(u, v, x, degree, forcedIndices=[]):
  if (degree < 1):
    raise ValueError("Degree of the fitting polynomial must be larger than zero")
  d = int((degree+1)*(degree+2)/2)
  if (len(u) <= d):
    d = len(u)-1
  X = polyfitMatrix2D(u, v, d)
  return polyfitComputeImplementation(X, x.copy(), forcedIndices)



