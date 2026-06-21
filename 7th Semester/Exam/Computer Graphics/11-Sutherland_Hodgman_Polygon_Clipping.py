import matplotlib.pyplot as plt
# Clipping window
xmin, ymin = 2, 2
xmax, ymax = 8, 8
# Original polygon
polygon = [(1, 1), (6, 1), (9, 5), (6, 9), (1, 6)]
# -------------------------
# Intersection function
# -------------------------
def intersect(s, e, edge, lim):
    x1, y1 = s
    x2, y2 = e
    if edge in ["left", "right"]:
        if x1 == x2:
            return (lim, y1)
        y = y1 + (y2 - y1) * (lim - x1) / (x2 - x1)
        return (lim, y)
    else:
        if y1 == y2:
            return (x1, lim)
        x = x1 + (x2 - x1) * (lim - y1) / (y2 - y1)
        return (x, lim)
# -------------------------
# Sutherland–Hodgman Algorithm
# -------------------------
def sutherland_hodgman(poly, xmin, ymin, xmax, ymax):
    def inside(p, edge, lim):
        x, y = p
        if edge == "left":
            return x >= lim
        if edge == "right":
            return x <= lim
        if edge == "bottom":
            return y >= lim
        if edge == "top":
            return y <= lim
    edges = [
        ("left", xmin),
        ("right", xmax),
        ("bottom", ymin),
        ("top", ymax)
    ]
    for edge, lim in edges:
        if not poly:
            return []
        output = []
        for i in range(len(poly)):
            s = poly[i - 1]
            e = poly[i]
            in_s = inside(s, edge, lim)
            in_e = inside(e, edge, lim)
            if in_e:
                if not in_s:
                    output.append(intersect(s, e, edge, lim))
                output.append(e)
            elif in_s:
                output.append(intersect(s, e, edge, lim))
        poly = output
    return poly
# -------------------------
# Run algorithm
# -------------------------
clipped = sutherland_hodgman(polygon, xmin, ymin, xmax, ymax)
# -------------------------
# Plotting
# -------------------------
plt.figure(figsize=(6, 6))
# Original polygon
px, py = zip(*(polygon + [polygon[0]]))
plt.plot(px, py, "b--", label="Original Polygon")
# Window
plt.plot(
    [xmin, xmax, xmax, xmin, xmin],
    [ymin, ymin, ymax, ymax, ymin],
    "r-",
    label="Clipping Window"
)
# Clipped polygon
if clipped:
    cx, cy = zip(*(clipped + [clipped[0]]))
    plt.fill(cx, cy, color="green", alpha=0.3, label="Clipped Area")
    plt.plot(cx, cy, "g-o", label="Clipped Polygon")
plt.title("Sutherland–Hodgman Polygon Clipping")
plt.legend()
plt.grid(True)
plt.axis("equal")
plt.show()