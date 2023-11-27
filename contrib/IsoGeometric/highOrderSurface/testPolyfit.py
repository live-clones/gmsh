from polyfit import polyfitCompute1D, polyfitEval1D, polyfitCompute2D, polyfitEval2D
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
'''
np.random.seed(42)
x = np.sort(5 * np.random.rand(20))
y = 3 * x**2 - 5 * x + 2 + np.random.randn(20)

coefficients = polyfitCompute1D(x, y, 2, [0,len(x)-1])
x_fit = np.linspace(0, 5, 100)
y_fit = polyfitEval1D(coefficients, x_fit)

plt.scatter(x, y, label='Original Data')
plt.plot(x_fit, y_fit, label='Fitted Curve', color='red')
plt.title('Polynomial Fitting Example')
plt.xlabel('X')
plt.ylabel('Y')
plt.legend()
plt.figure()
'''



np.random.seed(42)
x = np.sort(5 * np.random.rand(10))
y = np.sort(5 * np.random.rand(10))
x, y = np.meshgrid(x, y)
z = np.sin(x) + np.cos(y) + 0.2 * x + 0.5 * y + np.random.randn(*x.shape)

coefficients = polyfitCompute2D(np.ravel(x), np.ravel(y), np.ravel(z), 2, [0, len(np.ravel(x))-1])
x_fit = np.linspace(x.min(), x.max(), 100)
y_fit = np.linspace(y.min(), y.max(), 100)
x_fit, y_fit = np.meshgrid(x_fit, y_fit)
z_fit = polyfitEval2D(coefficients, np.ravel(x_fit), np.ravel(y_fit)).reshape(x_fit.shape)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(x, y, z, label='Original Data', color='blue')
ax.plot_surface(x_fit, y_fit, z_fit, color='red', alpha=0.5, label='Fitted Surface')
ax.set_title('Polynomial Surface Fitting Example')
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
#ax.legend()
plt.show()
