import matplotlib.pyplot as plt
import math
# Original polygon points
x = [2, 4, 3, 2]
y = [2, 2, 5, 2]
tx = int(input("Enter tx: "))
ty = int(input("Enter ty: "))
angle = float(input("Enter rotation angle: "))
rad = math.radians(angle)
# Centroid (correct general form)
cx = sum(x[:-1]) / (len(x) - 1)
cy = sum(y[:-1]) / (len(y) - 1)
# -------------------------
# 1. Translation
# -------------------------
xt = [i + tx for i in x]
yt = [i + ty for i in y]
# -------------------------
# 2. Rotation (about centroid)
# -------------------------
xr = []
yr = []
for i in range(len(x)):
    # shift to origin
    x_shift = x[i] - cx
    y_shift = y[i] - cy
    # rotation
    x_rot = x_shift * math.cos(rad) - y_shift * math.sin(rad)
    y_rot = x_shift * math.sin(rad) + y_shift * math.cos(rad)
    # shift back
    xr.append(x_rot + cx)
    yr.append(y_rot + cy)
# -------------------------
# Plotting
# -------------------------
plt.figure(figsize=(6, 6))
plt.plot(x, y, 'b-o', label="Original")
plt.plot(xt, yt, 'g-o', label="Translated")
plt.plot(xr, yr, 'r-o', label="Rotated (about centroid)")
plt.title("2D Transformation: Translation & Rotation")
plt.legend()
plt.grid(True)
plt.axis('equal')
plt.show()