import matplotlib.pyplot as plt
import numpy as np

from mpl_toolkits.mplot3d import Axes3D

# Make data
x = np.linspace(-10, 10, 100)
y = np.linspace(-10, 10, 100)
z = np.linspace(-10, 10, 100)

# Create a meshgrid from x, y, and z
x, y, z = np.meshgrid(x, y, z)

# Define the condition for the surface
condition = z**2 + y**2 <= x**2

# Set z values to NaN where the condition is not met
z[~condition] = np.nan

# Plot the surface
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(x, y, z[:,:,0], cmap='viridis')

# Set labels for axes
ax.set_xlabel('X Axis')
ax.set_ylabel('Y Axis')
ax.set_zlabel('Z Axis')

plt.show()
