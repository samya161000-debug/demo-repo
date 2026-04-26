import matplotlib.pyplot as plt

# Given list
arr = [1, 2, 3, 5, 6]

# Step 1: Find missing number
n = max(arr)
total_expected = n * (n + 1) // 2
total_actual = sum(arr)

missing = total_expected - total_actual

print("Missing number is:", missing)

# Step 2: Plot graph
expected = list(range(1, n + 1))

plt.plot(expected, expected, marker='o', label='Expected')
plt.scatter(arr, arr, label='Actual')

# Highlight missing number
plt.scatter(missing, missing, marker='x', s=100, label='Missing')

plt.title("Missing Number Visualization")
plt.xlabel("Numbers")
plt.ylabel("Values")
plt.legend()
plt.grid()

plt.show()