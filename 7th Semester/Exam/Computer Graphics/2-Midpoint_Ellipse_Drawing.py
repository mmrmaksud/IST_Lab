import matplotlib.pyplot as plt
def midpoint_ellipse(rx, ry):
    x = 0
    y = ry
    points = []
    # Region 1
    p1 = ry**2 - rx**2 * ry + 0.25 * rx**2
    dx = 2 * ry**2 * x
    dy = 2 * rx**2 * y
    while dx < dy:
        points.extend([
            (x, y), (-x, y),
            (x, -y), (-x, -y)
        ])
        if p1 < 0:
            x += 1
            dx = 2 * ry**2 * x
            p1 += dx + ry**2
        else:
            x += 1
            y -= 1
            dx = 2 * ry**2 * x
            dy = 2 * rx**2 * y
            p1 += dx - dy + ry**2
    # Region 2
    p2 = (ry**2) * (x + 0.5)**2 + \
         (rx**2) * (y - 1)**2 - \
         (rx**2 * ry**2)
    while y >= 0:
        points.extend([
            (x, y), (-x, y),
            (x, -y), (-x, -y)
        ])
        if p2 > 0:
            y -= 1
            dy = 2 * rx**2 * y
            p2 += rx**2 - dy
        else:
            x += 1
            y -= 1
            dx = 2 * ry**2 * x
            dy = 2 * rx**2 * y
            p2 += dx - dy + rx**2
    xs, ys = zip(*points)
    plt.figure(figsize=(6, 6))
    plt.scatter(xs, ys, color='purple', s=10)
    plt.title("Midpoint Ellipse Drawing Algorithm")
    plt.axis('equal')
    plt.grid(True)
    plt.show()
# Example
midpoint_ellipse(30, 20)