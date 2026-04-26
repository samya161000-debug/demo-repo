import itertools
import matplotlib.pyplot as plt

# Input
arr = [1, 2, 3]

# Generate permutations
perms = list(itertools.permutations(arr))

print("Permutations:")
for p in perms:
    print(p)

# Plot each permutation
for i, p in enumerate(perms):
    plt.plot(range(len(p)), p, marker='o', label=str(p))

plt.title("Permutation Graph")
plt.xlabel("Index")
plt.ylabel("Value")
plt.legend()
plt.grid()

plt.show()