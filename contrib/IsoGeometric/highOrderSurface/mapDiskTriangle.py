import numpy as np
import math
import cmath
import matplotlib.pyplot as plt
import random
import sys


def unSildeDisk(c):
  p = np.empty(4)
  for i in range(4):
    p[i] = cmath.phase(c[i])
    if p[i] < 0:
      p[i] += 2*math.pi

  for i in range(3):
    p[i+1] -= p[0]
    if p[i+1] < 0:
      p[i+1] += 2*math.pi

  c[0] = cmath.rect(1, 0./3*math.pi)
  c[1] = cmath.rect(1, 2./3*math.pi)
  c[2] = cmath.rect(1, 4./3*math.pi)
  c[3] = abs(c[3]) * c[0]
  if (p[1] > p[2]):
    for i in range(3):
      p[i+1] -= 2*math.pi
  '''
  if (p[1] > p[2]):
    tmp = p[1]
    p[1] = p[2]
    p[2] = tmp
    c[1] = cmath.rect(1, 4./3*math.pi)
    c[2] = cmath.rect(1, 2./3*math.pi)
  '''

  if (abs(p[3]) < abs(p[1])):
    padd = p[3]/p[1] * 2./3*math.pi
    c[3] *= cmath.rect(1, padd)
    return c

  padd = 2./3*math.pi
  
  for i in range(2):
    p[i+2] -= p[1]

  if (abs(p[3]) < abs(p[2])):
    padd += p[3]/p[2] * 2./3*math.pi
    c[3] *= cmath.rect(1, padd)
    return c

  padd += 2./3*math.pi
  p[3] -= p[2]

  padd += abs(p[3])/(2*math.pi-abs(p[2])-abs(p[1])) * 2./3*math.pi
  c[3] *= cmath.rect(1, padd)

  return c 


def slideDisk(c):
  p = np.empty(4)
  for i in range(4):
    p[i] = cmath.phase(c[i])
    if p[i] < 0:
      p[i] += 2*math.pi

  c[3] = cmath.rect(abs(c[3]), p[0])

  for i in range(2):
    p[i+1] -= p[0]
    if p[i+1] < 0:
      p[i+1] += 2*math.pi

  if (p[1] > p[2]):
    for i in range(2):
      p[i+1] -= 2*math.pi

  if (p[3] < 2*math.pi/3):
    c[3] *= cmath.rect(1, p[3]/(2*math.pi/3) * p[1])
    return c

  c[3] *= cmath.rect(1, p[1])
  p[2] -= p[1]
  p[3] -= 2*math.pi/3


  if (p[3] < 2*math.pi/3):
    c[3] *= cmath.rect(1, p[3]/(2*math.pi/3) * p[2])
    return c


  c[3] *= cmath.rect(1, p[2])
  p[3] -= 2*math.pi/3

  c[3] *= cmath.rect(1, p[3]/(2*math.pi/3)  * np.sign(p[1]) * (2*math.pi - abs(p[1]+p[2])) )

  return c


def deflateDisk(c):
  p = np.empty(3)
  for i in range(3):
    p[i] = cmath.phase(c[i+1]) - cmath.phase(c[0])
    if p[i] < 0:
      p[i] += 2*math.pi

  switch = False
  if (p[0] > p[1]):
    tmp = p[0]
    p[0] = p[1]
    p[1] = tmp
    tmp = c[1]
    c[1] = c[2]
    c[2] = tmp
    switch = True

  if (p[2] < p[0]):
    alpha = p[0]
    beta = p[2]
    cr = c[0]
  elif (p[2] < p[1]):
    alpha = p[1] - p[0]
    beta = p[2] - p[0]
    cr = c[1]
  else:
    alpha = 2*math.pi - p[1]
    beta = p[2] - p[1]
    cr = c[2]

  dist = math.cos(alpha/2)
  gamma = alpha/2 - math.atan( (1 - (2*beta)/(alpha)) * math.tan(alpha/2) )
  mult = dist / math.cos(alpha/2 - gamma)

  c[3] = cr * cmath.rect(1, gamma) * abs(c[3])
  c[3] = c[3] * mult

  if switch:
    tmp = c[1]
    c[1] = c[2]
    c[2] = tmp

  return c


def inflateDisk(c):
  gamma = cmath.phase(c)
  module = abs(c)
  sqrt32 = math.sqrt(3)/2
  twoPi3 = 2*math.pi/3

  c = cmath.rect(1, 0)
  if (gamma > twoPi3):
    gamma -= twoPi3
    c *= cmath.rect(1, twoPi3)
  if (gamma < -twoPi3):
    gamma += twoPi3
    c /= cmath.rect(1, twoPi3)
  if (gamma < 0):
    gamma += twoPi3
    c /= cmath.rect(1, twoPi3)

  module *= math.cos(twoPi3/2 - gamma) * 2
  c *= module

  beta = twoPi3/2 * (1 - math.tan(twoPi3/2 - gamma) / math.tan(twoPi3/2))
  c *= cmath.rect(1, beta)

  return c



def isoTriangle(p):
  d0 = p[1] - p[0]
  d1 = p[2] - p[0]
  d2 = p[3] - p[0]
  coeff_matrix = np.vstack((d0, d1)).T
  p = np.linalg.solve(coeff_matrix, d2)
  return [[0,0], [1,0], [0,1], p]


def unIsoTriangle(p):
  d0 = np.array([-1.5, math.sqrt(3)/2])
  d1 = np.array([-1.5, -math.sqrt(3)/2])
  p = [1, 0] + p[0]*d0 + p[1]*d1
  return p


def disk2Triangle(p):
  c = np.empty(4, dtype=complex)
  for i in range(4):
    c[i] = complex(p[i][0],p[i][1])
  c = unSildeDisk(c)

  c = deflateDisk(c)

  for i in range(4):
    p[i] = np.array([c[i].real, c[i].imag])
  p = isoTriangle(p)

  return p


def triangle2Disk(p):
  
  p[3] = unIsoTriangle(p[3])

  c = np.empty(4, dtype=complex)
  for i in range(4):
    c[i] = complex(p[i][0],p[i][1])
  c[3] = inflateDisk(c[3])

  c = slideDisk(c)

  return [c[3].real, c[3].imag]






#
# E X A M P L E S
#
if '-disk2Triangle' in sys.argv:

  theta0 = 1./3 * math.pi
  theta1 = 5./3 * math.pi
  theta2 = 5./4 * math.pi
  pc0 = np.array([math.cos(theta0), math.sin(theta0)])
  pc1 = np.array([math.cos(theta1), math.sin(theta1)])
  pc2 = np.array([math.cos(theta2), math.sin(theta2)])

  c0 = complex(pc0[0],pc0[1])
  c1 = complex(pc1[0],pc1[1])
  c2 = c0 * (c1/c0)**(1./3) * 0.
  pc = np.array([c2.real, c2.imag])


  # FIG 1: uniform distribution on a disk

  OPT = True
  if OPT:
    num_points = 2500
  else:
    num_points = 2
  r = np.sqrt(np.random.uniform(0, 1, num_points))
  theta = np.random.uniform(0, 2 * np.pi, num_points)
  x = r * np.cos(theta)
  y = r * np.sin(theta)
  colors = theta  # Use the angle as the color

  if OPT:
    plt.scatter(x, y, c=colors, cmap='twilight', marker='o', s=25)
  else:
    plt.scatter(x[0], y[0], c=colors[0], cmap='twilight', marker='o', s=25, label='1')
    plt.scatter(x[1], y[1], c=colors[1], cmap='twilight', marker='o', s=25, label='1')
  plt.colorbar()
  plt.xlim(-1.1, 1.1)
  plt.ylim(-1.1, 1.1)
  plt.xlabel('u')
  plt.ylabel('v')
  plt.scatter(pc0[0], pc0[1], c='black', marker='o', s=100)
  plt.scatter(pc1[0], pc1[1], c='black', marker='o', s=100)
  plt.scatter(pc2[0], pc2[1], c='black', marker='o', s=100)
  plt.title('Origin')
  plt.figure()



  # FIG 2: silde vertices on disk

  cs =  np.empty(len(x), dtype=object)
  for j in range(len(x)):
    c = np.empty(4, dtype=complex)
    c[0] = complex(pc0[0],pc0[1])
    c[1] = complex(pc1[0],pc1[1])
    c[2] = complex(pc2[0],pc2[1])
    c[3] = complex(x[j],y[j])
    c = unSildeDisk(c)
    x[j] = c[3].real
    y[j] = c[3].imag
    cs[j] = c

  if OPT:
    plt.scatter(x, y, c=colors, cmap='twilight', marker='o', s=25)
  else:
    plt.scatter(x[0], y[0], c=colors[0], cmap='twilight', marker='o', s=25, label='1')
    plt.scatter(x[1], y[1], c=colors[1], cmap='twilight', marker='o', s=25, label='1')
  plt.colorbar()
  plt.xlim(-1.1, 1.1)
  plt.ylim(-1.1, 1.1)
  plt.xlabel('u')
  plt.ylabel('v')
  plt.scatter(c[0].real, c[0].imag, c='black', marker='o', s=100)
  plt.scatter(c[1].real, c[1].imag, c='black', marker='o', s=100)
  plt.scatter(c[2].real, c[2].imag, c='black', marker='o', s=100)
  plt.title('Slided')
  plt.figure()



  # FIG 3: deflate disk into a triangle

  for j in range(len(x)):
    c = cs[j]
    c = deflateDisk(c)
    x[j] = c[3].real
    y[j] = c[3].imag

  if OPT:
    plt.scatter(x, y, c=colors, cmap='twilight', marker='o', s=25)
  else:
    plt.scatter(x[0], y[0], c=colors[0], cmap='twilight', marker='o', s=25, label='1')
    plt.scatter(x[1], y[1], c=colors[1], cmap='twilight', marker='o', s=25, label='1')
  plt.colorbar()
  plt.xlim(-1.1, 1.1)
  plt.ylim(-1.1, 1.1)
  plt.xlabel('u')
  plt.ylabel('v')
  plt.scatter(c[0].real, c[0].imag, c='black', marker='o', s=100)
  plt.scatter(c[1].real, c[1].imag, c='black', marker='o', s=100)
  plt.scatter(c[2].real, c[2].imag, c='black', marker='o', s=100)
  plt.title('Deflated')
  plt.figure()



  # FIG 4: get isoparametric triangle

  p0 = np.array([c[0].real, c[0].imag])
  p1 = np.array([c[1].real, c[1].imag])
  p2 = np.array([c[2].real, c[2].imag])

  for j in range(len(x)):
    c = cs[j]
    p = np.array([c[3].real, c[3].imag])
    p = isoTriangle([p0, p1, p2, p])
    x[j], y[j] = p[3]

  if OPT:
    plt.scatter(x, y, c=colors, cmap='twilight', marker='o', s=25)
  else:
    plt.scatter(x[0], y[0], c=colors[0], cmap='twilight', marker='o', s=25, label='1')
    plt.scatter(x[1], y[1], c=colors[1], cmap='twilight', marker='o', s=25, label='1')
  plt.colorbar()
  plt.xlim(-0.1, 1.1)
  plt.ylim(-0.1, 1.1)
  plt.xlabel('u')
  plt.ylabel('v')
  plt.scatter(p[0][0], p[0][1], c='black', marker='o', s=100)
  plt.scatter(p[1][0], p[1][1], c='black', marker='o', s=100)
  plt.scatter(p[2][0], p[2][1], c='black', marker='o', s=100)
  plt.title('Isoparametric')
  plt.show()



if '-triangle2Disk' in sys.argv:

  theta0 = 1./3 * math.pi
  theta1 = 5./3 * math.pi
  theta2 = 5./4 * math.pi
  pc0 = np.array([math.cos(theta0), math.sin(theta0)])
  pc1 = np.array([math.cos(theta1), math.sin(theta1)])
  pc2 = np.array([math.cos(theta2), math.sin(theta2)])

  c0 = complex(pc0[0],pc0[1])
  c1 = complex(pc1[0],pc1[1])
  c2 = c0 * (c1/c0)**(1./3) * 0.
  pc = np.array([c2.real, c2.imag])



  # FIG 1: uniform distribution on a triangle

  OPT = True
  if OPT:
    num_points = 2500
  else:
    num_points = 2

  def generate_random_point_in_triangle():
    while True:
      x = random.uniform(0, 1)
      y = random.uniform(0, 1)
      if x + y <= 1:
        return [x, y]

  def calculate_angle(point, center):
      dx = point[0] - center[0]
      dy = point[1] - center[1]
      return math.atan2(dy, dx)

  def assign_color_based_on_angle(angle):
      if angle < 0:
          angle += 2 * math.pi
      hue = angle / (2 * math.pi)
      return hue

  center = (1/3, 1/3)
  points = [generate_random_point_in_triangle() for _ in range(num_points)]
  angles = [calculate_angle(point, center) for point in points]
  colors = [assign_color_based_on_angle(angle) for angle in angles]

  x = [p[0] for p in points]
  y = [p[1] for p in points]

  if OPT:
    plt.scatter(x, y, c=colors, cmap='twilight', marker='o', s=25)
  else:
    plt.scatter(x[0], y[0], c=colors[0], cmap='twilight', marker='o', s=25, label='1')
    plt.scatter(x[1], y[1], c=colors[1], cmap='twilight', marker='o', s=25, label='1')
  plt.colorbar()
  plt.xlim(-0.1, 1.1)
  plt.ylim(-0.1, 1.1)
  plt.xlabel('u')
  plt.ylabel('v')
  plt.scatter(0, 0, c='black', marker='o', s=100)
  plt.scatter(1, 0, c='black', marker='o', s=100)
  plt.scatter(0, 1, c='black', marker='o', s=100)
  plt.title('Origin')
  plt.figure()



  # FIG 2: put vertices on circle

  for j,p in enumerate(points):
    points[j] = unIsoTriangle(p)
    x[j] = points[j][0]
    y[j] = points[j][1]


  if OPT:
    plt.scatter(x, y, c=colors, cmap='twilight', marker='o', s=25)
  else:
    plt.scatter(x[0], y[0], c=colors[0], cmap='twilight', marker='o', s=25, label='1')
    plt.scatter(x[1], y[1], c=colors[1], cmap='twilight', marker='o', s=25, label='1')
  plt.colorbar()
  plt.xlim(-1.1, 1.1)
  plt.ylim(-1.1, 1.1)
  plt.xlabel('u')
  plt.ylabel('v')
  plt.scatter(1, 0, c='black', marker='o', s=100)
  plt.scatter(-.5, math.sqrt(3)/2, c='black', marker='o', s=100)
  plt.scatter(-.5, -math.sqrt(3)/2, c='black', marker='o', s=100)
  plt.title('On circle')
  plt.figure()


  # FIG 3: inflate triangle into a disk

  cs =  np.empty(len(x), dtype=complex)
  for j,p in enumerate(points):
    cs[j] = complex(p[0],p[1])
    cs[j] = inflateDisk(cs[j])

    x[j] = cs[j].real
    y[j] = cs[j].imag

  if OPT:
    plt.scatter(x, y, c=colors, cmap='twilight', marker='o', s=25)
  else:
    plt.scatter(x[0], y[0], c=colors[0], cmap='twilight', marker='o', s=25, label='1')
    plt.scatter(x[1], y[1], c=colors[1], cmap='twilight', marker='o', s=25, label='1')
  plt.colorbar()
  plt.xlim(-1.1, 1.1)
  plt.ylim(-1.1, 1.1)
  plt.xlabel('u')
  plt.ylabel('v')
  plt.scatter(1, 0, c='black', marker='o', s=100)
  plt.scatter(-.5, math.sqrt(3)/2, c='black', marker='o', s=100)
  plt.scatter(-.5, -math.sqrt(3)/2, c='black', marker='o', s=100)
  plt.title('Inflated')
  plt.figure()


  # FIG 4: get isoparametric triangle

  for j,p in enumerate(points):
    c = np.empty(4, dtype=complex)
    c[0] = complex(pc0[0],pc0[1])
    c[1] = complex(pc1[0],pc1[1])
    c[2] = complex(pc2[0],pc2[1])
    c[3] = cs[j]
    c = slideDisk(c)
    cs[j] = c[3]
    
    x[j] = cs[j].real
    y[j] = cs[j].imag

  if OPT:
    plt.scatter(x, y, c=colors, cmap='twilight', marker='o', s=25)
  else:
    plt.scatter(x[0], y[0], c=colors[0], cmap='twilight', marker='o', s=25, label='1')
    plt.scatter(x[1], y[1], c=colors[1], cmap='twilight', marker='o', s=25, label='1')
  plt.colorbar()
  plt.xlim(-1.1, 1.1)
  plt.ylim(-1.1, 1.1)
  plt.xlabel('u')
  plt.ylabel('v')
  plt.scatter(pc0[0], pc0[1], c='black', marker='o', s=100)
  plt.scatter(pc1[0], pc1[1], c='black', marker='o', s=100)
  plt.scatter(pc2[0], pc2[1], c='black', marker='o', s=100)
  plt.title('Slided vertices')

  plt.show()

