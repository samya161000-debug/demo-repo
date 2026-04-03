import matplotlib.pyplot as plt
import time

def missing(arr, n, total_sum):
    s = 0
    for i in range(n):
        s += arr[i]
    return total_sum - s

n_values = []
time_values = []

for n in range(10, 100001, 5000):
    arr = list(range(1, n + 2))
    arr.remove(n // 2)   # remove one number
    
    total_sum = (n + 1) * (n + 2) // 2

    start = time.time()
    missing(arr, n, total_sum)
    end = time.time()

    n_values.append(n)
    time_values.append(end - start)

plt.plot(n_values, time_values)
plt.xlabel("Input size (n)")
plt.ylabel("Time taken (seconds)")
plt.title("Time Complexity of Missing Number Algorithm")
plt.show()
