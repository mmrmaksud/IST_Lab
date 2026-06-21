import matplotlib.pyplot as plt
def bresenham(x1, y1, x2, y2):
    dx = abs(x2 - x1)
    dy = abs(y2 - y1)
    sx = 1 if x1 < x2 else -1
    sy = 1 if y1 < y2 else -1
    x, y = x1, y1
    points = []
    # Same point case
    if dx == 0 and dy == 0:
        points.append((x, y))
    # Slope |m| <= 1
    elif dx > dy:
        p = 2 * dy - dx
        while x != x2:
            points.append((x, y))
            if p >= 0:
                y += sy
                p -= 2 * dx
            x += sx
            p += 2 * dy
    # Slope |m| > 1
    else:
        p = 2 * dx - dy
        while y != y2:
            points.append((x, y))
            if p >= 0:
                x += sx
                p -= 2 * dy
            y += sy
            p += 2 * dx
    points.append((x, y))
    xs, ys = zip(*points)
    plt.figure(figsize=(6, 6))
    plt.scatter(xs, ys, color='blue', s=40)
    plt.plot(xs, ys, 'r--', linewidth=1)
    plt.title("Bresenham's Line Drawing Algorithm")
    plt.axis('equal')
    plt.grid(True)
    plt.show()
# Example
bresenham(2, 3, 15, 10)