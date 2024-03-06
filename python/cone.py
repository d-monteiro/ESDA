import matplotlib.pyplot as plt
import numpy as np

from matplotlib import cm

plt.style.use('_mpl-gallery')

# Make data
X = np.linspace(-10, 10, 100)
Y = np.linspace(-10, 10, 100)
#Z = np.linspace(-10, 10, 100)

# Create a meshgrid from y and z
X, Y = np.meshgrid(X, Y)

Z = -(np.sqrt(Y**2 + X**2))

# Plot the surface
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X, Y, Z, cmap='viridis')

ax.set(xticklabels=[],
       yticklabels=[],
       zticklabels=[])

# Add a grid
ax.grid(True)

# Set axis labels
ax.set_xlabel('X Axis')
ax.set_ylabel('Y Axis')
ax.set_zlabel('Z Axis')

plt.show()