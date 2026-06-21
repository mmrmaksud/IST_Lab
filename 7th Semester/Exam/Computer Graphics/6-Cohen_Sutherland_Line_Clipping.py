import matplotlib.pyplot as plt
# Clipping window boundaries
xmin, ymin = 100, 100
xmax, ymax = 300, 300
# Region codes
LEFT = 1
RIGHT = 2
BOTTOM = 4
TOP = 8
def get_code(x, y):
    code = 0
    if x < xmin:
        code |= LEFT
    elif x > xmax:
        code |= RIGHT
    if y < ymin:
        code |= BOTTOM
    elif y > ymax:
        code |= TOP
    return code
def cohen_sutherland(x1, y1, x2, y2):
    # Save original line
    ox1, oy1, ox2, oy2 = x1, y1, x2, y2
    c1 = get_code(x1, y1)
    c2 = get_code(x2, y2)
    accept = False
    while True:
        # Case 1: fully inside
        if c1 == 0 and c2 == 0:
            accept = True
            break
        # Case 2: fully outside
        elif (c1 & c2) != 0:
            break
        # Case 3: partial clipping
        else:
            outcode = c1 if c1 != 0 else c2
            dx = x2 - x1
            dy = y2 - y1
            # TOP boundary
            if outcode & TOP:
                if dy != 0:
                    x = x1 + dx * (ymax - y1) / dy
                else:
                    x = x1
                y = ymax
            # BOTTOM boundary
            elif outcode & BOTTOM:
                if dy != 0:
                    x = x1 + dx * (ymin - y1) / dy
                else:
                    x = x1
                y = ymin
            # RIGHT boundary
            elif outcode & RIGHT:
                if dx != 0:
                    y = y1 + dy * (xmax - x1) / dx
                else:
                    y = y1
                x = xmax
            # LEFT boundary
            elif outcode & LEFT:
                if dx != 0:
                    y = y1 + dy * (xmin - x1) / dx
                else:
                    y = y1
                x = xmin
            # Update point
            if outcode == c1:
                x1, y1 = x, y
                c1 = get_code(x1, y1)
            else:
                x2, y2 = x, y
                c2 = get_code(x2, y2)
    # Output
    if accept:
        print(f"Clipped Line: ({x1:.2f}, {y1:.2f}) to ({x2:.2f}, {y2:.2f})")
        # Window
        plt.plot(
            [xmin, xmax, xmax, xmin, xmin],
            [ymin, ymin, ymax, ymax, ymin],
            'r-',
            label="Clipping Window"
        )
        # Original line
        plt.plot(
            [ox1, ox2],
            [oy1, oy2],
            'b--',
            label="Original Line"
        )
        # Clipped line
        plt.plot(
            [x1, x2],
            [y1, y2],
            'g-',
            linewidth=3,
            label="Clipped Line"
        )
        plt.title("Cohen-Sutherland Line Clipping Algorithm")
        plt.axis('equal')
        plt.grid(True)
        plt.legend()
        plt.show()
    else:
        print("Line completely outside")
# Example
cohen_sutherland(50, 50, 350, 350)