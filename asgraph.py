import matplotlib.pyplot as plt

# Activities: (start, finish)
activities = [(1, 2), (3, 4), (0, 6), (5, 7), (8, 9), (5, 9)]

# Sort by finish time (greedy step)
activities.sort(key=lambda x: x[1])

selected = []
last_finish = -1

# Greedy selection
for s, f in activities:
    if s >= last_finish:
        selected.append((s, f))
        last_finish = f

# Plot
plt.figure(figsize=(10, 5))

for i, (s, f) in enumerate(activities):
    plt.plot([s, f], [i, i], linewidth=6, label="Activity" if i == 0 else "")

    # mark selected ones in red
    if (s, f) in selected:
        plt.plot([s, f], [i, i], linewidth=6, color="red")

plt.yticks(range(len(activities)), [f"A{i+1}" for i in range(len(activities))])
plt.xlabel("Time")
plt.ylabel("Activities")
plt.title("Activity Selection (Greedy) - Timeline Graph")

plt.show()