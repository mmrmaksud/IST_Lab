import matplotlib.pyplot as plt
def dda(x1, y1, x2, y2):
    dx = x2 - x1
    dy = y2 - y1
    steps = max(abs(dx), abs(dy))
    if steps == 0:
        plt.scatter(x1, y1, color='blue')
        plt.show()
        return
    xinc = dx / steps
    yinc = dy / steps
    x = x1
    y = y1
    points = []
    for i in range(steps + 1):
        points.append((round(x), round(y)))
        x += xinc
        y += yinc
    xs, ys = zip(*points)
    plt.scatter(xs, ys, color='blue', s=30)
    plt.title("DDA Line Drawing Algorithm")
    plt.axis('equal')
    plt.grid(True)
    plt.show()
# Example
dda(2, 3, 15, 10)