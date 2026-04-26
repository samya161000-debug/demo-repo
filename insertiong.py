import matplotlib.pyplot as plt

steps = []

def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        steps.append(arr.copy())  # store step after partition

        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)


def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


# Input array
arr = [8, 3, 5, 2, 9, 1]
quick_sort(arr, 0, len(arr) - 1)

# Plot each step
for i, step in enumerate(steps):
    plt.figure()
    plt.bar(range(len(step)), step)
    plt.title(f"Step {i+1}")
    plt.xlabel("Index")
    plt.ylabel("Value")
    plt.grid()
    plt.show()