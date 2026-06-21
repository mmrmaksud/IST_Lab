import matplotlib.pyplot as plt
import math
# Triangle vertices
triangle = [(2, 2), (6, 2), (4, 6)]
# Pivot point
xp = float(input("Enter pivot x: "))
yp = float(input("Enter pivot y: "))
# Rotation angle
angle = float(input("Enter angle: "))
rad = math.radians(angle)
rotated = []
# -------------------------
# Rotation about arbitrary point
# -------------------------
for x, y in triangle:
    # Step 1: translate to origin (pivot as origin)
    x_shift = x - xp
    y_shift = y - yp
    # Step 2: rotate
    x_rot = x_shift * math.cos(rad) - y_shift * math.sin(rad)
    y_rot = x_shift * math.sin(rad) + y_shift * math.cos(rad)
    # Step 3: translate back
    x_final = x_rot + xp
    y_final = y_rot + yp
    rotated.append((x_final, y_final))
# -------------------------
# Close polygons
# -------------------------
orig_x = [p[0] for p in triangle] + [triangle[0][0]]
orig_y = [p[1] for p in triangle] + [triangle[0][1]]
rot_x = [p[0] for p in rotated] + [rotated[0][0]]
rot_y = [p[1] for p in rotated] + [rotated[0][1]]
# -------------------------
# Plotting
# -------------------------
plt.figure(figsize=(6, 6))
plt.plot(orig_x, orig_y, 'b-o', label="Original Triangle")
plt.plot(rot_x, rot_y, 'r-o', label="Rotated Triangle")
plt.scatter(xp, yp, color='black', s=100, label="Pivot Point")
plt.title("Rotation of Triangle About Arbitrary Point")
plt.legend()
plt.grid(True)
plt.axis('equal')
plt.show()