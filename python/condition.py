import matplotlib.pyplot as plt
import numpy as np

from mpl_toolkits.mplot3d import Axes3D

# Make data
x = np.linspace(0, 10, 100)
y = np.linspace(0, 10, 100)

# Create a meshgrid from x, y, and z
x, y = np.meshgrid(x, y)

# Define the condition for the surface
z = y**2 + x**2


# Plot the surface
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(x, y, z, cmap='viridis')

# Set labels for axes
ax.set_xlabel('X Axis')
ax.set_ylabel('Y Axis')
ax.set_zlabel('Z Axis')

plt.show()
