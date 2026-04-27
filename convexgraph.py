import matplotlib.pyplot as plt

# Orientation function
def orientation(p, q, r):
    return (q[1]-p[1])*(r[0]-q[0]) - (q[0]-p[0])*(r[1]-q[1])

# Convex Hull (Graham Scan)
def convex_hull(points):
    points = sorted(points)

    # Lower hull
    lower = []
    for p in points:
        while len(lower) >= 2 and orientation(lower[-2], lower[-1], p) >= 0:
            lower.pop()
        lower.append(p)

    # Upper hull
    upper = []
    for p in reversed(points):
        while len(upper) >= 2 and orientation(upper[-2], upper[-1], p) >= 0:
            upper.pop()
        upper.append(p)

    return lower[:-1] + upper[:-1]


# Input points
points = [(0,3), (2,2), (1,1), (2,1), (3,0), (0,0), (3,3)]

hull = convex_hull(points)

# Plot points
x = [p[0] for p in points]
y = [p[1] for p in points]
plt.scatter(x, y)

# Plot hull
hx = [p[0] for p in hull] + [hull[0][0]]
hy = [p[1] for p in hull] + [hull[0][1]]
plt.plot(hx, hy)

plt.title("Convex Hull")
plt.xlabel("X")
plt.ylabel("Y")
plt.grid()

plt.show()