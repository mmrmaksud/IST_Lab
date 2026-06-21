import matplotlib.pyplot as plt
def bresenham_circle(r):
    if r <= 0:
        print("Radius must be positive.")
        return
    x = 0
    y = r
    d = 3 - 2 * r
    points = []
    while x <= y:
        points.extend([
            (x, y), (-x, y), (x, -y), (-x, -y),
            (y, x), (-y, x), (y, -x), (-y, -x)
        ])
        if d < 0:
            d = d + 4 * x + 6
        else:
            d = d + 4 * (x - y) + 10
            y -= 1
        x += 1
    xs, ys = zip(*points)
    plt.figure(figsize=(6, 6))
    plt.scatter(xs, ys, color='blue', s=20)
    plt.title("Bresenham's Circle Drawing Algorithm")
    plt.axis('equal')
    plt.grid(True)
    plt.show()
# Example
bresenham_circle(20)