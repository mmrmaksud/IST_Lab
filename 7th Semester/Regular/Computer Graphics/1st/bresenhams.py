import matplotlib.pyplot as plt

def bresenham(x1, y1, x2, y2):
    points = []

    dx = abs(x2 - x1)
    dy = abs(y2 - y1)

    sx = 1 if x2 > x1 else -1
    sy = 1 if y2 > y1 else -1

    err = dx - dy

    while True:
        points.append((x1, y1))

        if x1 == x2 and y1 == y2:
            break

        e2 = 2 * err

        if e2 > -dy:
            err -= dy
            x1 += sx

        if e2 < dx:
            err += dx
            y1 += sy

    return points


# Input
x1 = int(input("Enter x1: "))
y1 = int(input("Enter y1: "))
x2 = int(input("Enter x2: "))
y2 = int(input("Enter y2: "))

# Get points
line_points = bresenham(x1, y1, x2, y2)

# Print points
print("Points on the line:")
for point in line_points:
    print(point)

# Separate x and y values
x_vals = [p[0] for p in line_points]
y_vals = [p[1] for p in line_points]

# Plot graph
plt.plot(x_vals, y_vals, marker='o')
plt.title("Bresenham Line Drawing")
plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.grid(True)

# Show graph
plt.show()