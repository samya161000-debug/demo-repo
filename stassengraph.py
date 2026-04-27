import networkx as nx
import matplotlib.pyplot as plt

# Create graph
G = nx.DiGraph()

# Root
G.add_edge("A × B", "M1")
G.add_edge("A × B", "M2")
G.add_edge("A × B", "M3")
G.add_edge("A × B", "M4")
G.add_edge("A × B", "M5")
G.add_edge("A × B", "M6")
G.add_edge("A × B", "M7")

# Add meaning of each multiplication
labels = {
    "M1": "(A11+A22)(B11+B22)",
    "M2": "(A21+A22)B11",
    "M3": "A11(B12−B22)",
    "M4": "A22(B21−B11)",
    "M5": "(A11+A12)B22",
    "M6": "(A21−A11)(B11+B12)",
    "M7": "(A12−A22)(B21+B22)"
}

# Draw graph
plt.figure(figsize=(10,6))
pos = nx.spring_layout(G, seed=42)

nx.draw(G, pos, with_labels=True, node_color="lightblue",
        node_size=2500, font_size=10, arrows=True)

# Add labels for M1–M7
nx.draw_networkx_labels(G, pos, labels, font_size=8, font_color="red")

plt.title("Strassen Matrix Multiplication Flow (Graph View)")
plt.show()