import matplotlib.pyplot as plt
import time
import random

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            # Plot current state
            plt.clf()
            plt.bar(range(len(arr)), arr)
            plt.title(f"Bubble Sort - Step {i},{j}")
            plt.pause(0.1)

            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

# Generate random array
arr = [random.randint(1, 50) for _ in range(10)]

plt.ion()  # Turn on interactive mode
bubble_sort(arr)

# Final sorted graph
plt.clf()
plt.bar(range(len(arr)), arr)
plt.title("Sorted Array")
plt.show()
