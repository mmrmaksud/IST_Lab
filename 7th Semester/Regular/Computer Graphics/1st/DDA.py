import matplotlib.pyplot as plt

def dda(x1, y1, x2, y2):
    points = []

    dx = x2 - x1
    dy = y2 - y1

    steps = max(abs(dx), abs(dy))

    x_increment = dx / steps
    y_increment = dy / steps

    x = x1
    y = y1

    for i in range(steps + 1):
        points.append((round(x), round(y)))

        x += x_increment
        y += y_increment

    return points


# Input
x1 = int(input("Enter x1: "))
y1 = int(input("Enter y1: "))
x2 = int(input("Enter x2: "))
y2 = int(input("Enter y2: "))

# Run DDA
line_points = dda(x1, y1, x2, y2)

# Print points
print("Points on the line:")
for point in line_points:
    print(point)

# Graph plotting
x_vals = [p[0] for p in line_points]
y_vals = [p[1] for p in line_points]

plt.plot(x_vals, y_vals, marker='o')
plt.title("DDA Line Drawing Algorithm")
plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.grid(True)

plt.show()