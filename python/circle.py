import matplotlib.pyplot as plt

plt.ion()

def draw_circle(radius):
    # Create a figure and axis object
    fig, ax = plt.subplots()

    # Create a circle object with the specified radius
    circle = plt.Circle((0, 0), radius, fill=False)

    # Add the circle to the axis
    ax.add_artist(circle)

    # Set the aspect of the plot to be equal
    ax.set_aspect('equal', adjustable='box')

    # Set the limits of the plot
    ax.set_xlim(-radius * 1.1, radius * 1.1)
    ax.set_ylim(-radius * 1.1, radius * 1.1)

    # Show the plot
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.title('Circle with radius {}'.format(radius))
    plt.grid(True)
    plt.show()

# Test the function with a radius of 5
draw_circle(5)