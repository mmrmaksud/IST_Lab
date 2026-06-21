import matplotlib.pyplot as plt
import math
# Original polygon
x = [2, 4, 3, 2]
y = [2, 2, 5, 2]
tx = int(input("Enter tx: "))
ty = int(input("Enter ty: "))
angle = float(input("Enter angle: "))
rad = math.radians(angle)
# -------------------------
# 1. Translation
# -------------------------
xt = [i + tx for i in x]
yt = [i + ty for i in y]
# -------------------------
# 2. Centroid of translated object
# -------------------------
cx_t = sum(xt[:-1]) / (len(xt) - 1)
cy_t = sum(yt[:-1]) / (len(yt) - 1)
# -------------------------
# 3. Rotation about centroid
# -------------------------
xr = []
yr = []
for i in range(len(xt)):
    x_shift = xt[i] - cx_t
    y_shift = yt[i] - cy_t
    x_rot = x_shift * math.cos(rad) - y_shift * math.sin(rad)
    y_rot = x_shift * math.sin(rad) + y_shift * math.cos(rad)
    xr.append(x_rot + cx_t)
    yr.append(y_rot + cy_t)
# -------------------------
# Plotting
# -------------------------
plt.figure(figsize=(6, 6))
plt.plot(x, y, 'b-o', label="Original")
plt.plot(xt, yt, 'g-o', label="Translated")
plt.plot(xr, yr, 'r-o', label="Composite (T → R)")
plt.title("Composite Transformation (Translation + Rotation)")
plt.legend()
plt.grid(True)
plt.axis('equal')
plt.show()