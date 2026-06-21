import matplotlib.pyplot as plt
def midpoint_circle(r):
    x = 0
    y = r
    p = 1 - r
    points = []
    while x <= y:
        points.extend([
            (x, y), (-x, y), (x, -y), (-x, -y),
            (y, x), (-y, x), (y, -x), (-y, -x)
        ])
        if p < 0:
            p = p + 2*x + 3
        else:
            p = p + 2*(x - y) + 5
            y -= 1
        x += 1
    xs, ys = zip(*points)
    plt.scatter(xs, ys)
    plt.axis('equal')
    plt.grid(True)
    plt.show()
midpoint_circle(20)