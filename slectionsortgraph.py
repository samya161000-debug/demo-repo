import matplotlib.pyplot as plt
import time
import random

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        
        for j in range(i+1, n):
            # Plot current state
            plt.clf()
            plt.bar(range(len(arr)), arr)
            plt.title(f"Selection Sort - i={i}, j={j}")
            plt.pause(0.1)

            if arr[j] < arr[min_idx]:
                min_idx = j
        
        # Swap
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

# Generate random array
arr = [random.randint(1, 50) for _ in range(10)]

plt.ion()  # interactive mode ON
selection_sort(arr)

# Final sorted graph
plt.clf()
plt.bar(range(len(arr)), arr)
plt.title("Sorted Array")
plt.show()