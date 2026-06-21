import matplotlib.pyplot as plt
# Original polygon
x = [2, 4, 3, 2]
y = [2, 2, 5, 2]
sx = float(input("Enter sx: "))
sy = float(input("Enter sy: "))
tx = int(input("Enter tx: "))
ty = int(input("Enter ty: "))
# -------------------------
# Centroid (better reference point)
# -------------------------
cx = sum(x[:-1]) / (len(x) - 1)
cy = sum(y[:-1]) / (len(y) - 1)
# -------------------------
# 1. Scaling about centroid
# -------------------------
xs = [(i - cx) * sx + cx for i in x]
ys = [(i - cy) * sy + cy for i in y]
# -------------------------
# 2. Translation
# -------------------------
xt = [i + tx for i in xs]
yt = [i + ty for i in ys]
# -------------------------
# Plotting
# -------------------------
plt.figure(figsize=(6, 6))
plt.plot(x, y, 'b-o', label="Original")
plt.plot(xs, ys, 'g-o', label="Scaled")
plt.plot(xt, yt, 'r-o', label="Scaled + Translated")
plt.title("2D Transformation: Scaling + Translation")
plt.legend()
plt.grid(True)
plt.axis('equal')
plt.show()