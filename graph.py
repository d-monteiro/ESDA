import matplotlib
matplotlib.use('TkAgg')

import matplotlib.pyplot as plt

# Define data
x = [1, 2, 3, 4, 5]
y = [2, 3, 5, 7, 6]

# Create a line plot
plt.plot(x, y, marker='o', linestyle='-')

# Add labels and title
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('Simple Line Plot')

# Show the plot
plt.show()