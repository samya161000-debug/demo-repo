import matplotlib.pyplot as plt

# Example steps (low, mid, high)
steps = [(0, 3, 6), (4, 5, 6), (4, 4, 4)]

# Array
arr = [1, 3, 5, 7, 9, 11, 13]

plt.plot(arr, marker='o')

# Plot each step
for i, (low, mid, high) in enumerate(steps):
    plt.scatter(low, arr[low], s=100, label=f'Low (Step {i+1})')
    plt.scatter(mid, arr[mid], s=100, label=f'Mid (Step {i+1})')
    plt.scatter(high, arr[high], s=100, label=f'High (Step {i+1})')

plt.title("Binary Search Graph")
plt.xlabel("Index")
plt.ylabel("Value")
plt.legend()
plt.grid()

plt.show()