import matplotlib.pyplot as plt
import numpy as np
def boundary_fill_4(x, y, fill_color, boundary_color, screen):
    stack = [(x, y)]
    while stack:
        cx, cy = stack.pop()
        # boundary check
        if cx < 0 or cx >= screen.shape[1] or cy < 0 or cy >= screen.shape[0]:
            continue
        current_color = screen[cy, cx]
        # fill condition
        if not np.array_equal(current_color, boundary_color) and not np.array_equal(current_color, fill_color):
            screen[cy, cx] = fill_color
            # 4-connected neighbors
            stack.append((cx + 1, cy))
            stack.append((cx - 1, cy))
            stack.append((cx, cy + 1))
            stack.append((cx, cy - 1))
# Create white canvas
screen = np.ones((400, 400, 3))
# Rectangle boundary (black)
screen[100:300, 100] = [0, 0, 0]
screen[100:300, 300] = [0, 0, 0]
screen[100, 100:301] = [0, 0, 0]
screen[300, 100:301] = [0, 0, 0]

# Fill inside rectangle (red)
boundary_fill_4(
    150, 150,
    [1, 0, 0],   # fill color (red)
    [0, 0, 0],   # boundary color (black)
    screen
)
plt.imshow(screen)
plt.title("Boundary Fill Algorithm (4-connected)")
plt.axis("off")
plt.show()