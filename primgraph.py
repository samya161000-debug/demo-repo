import networkx as nx
import matplotlib.pyplot as plt

# Weighted graph edges (u, v, weight)
edges = [
    ("A", "B", 2),
    ("A", "C", 3),
    ("A", "D", 6),
    ("B", "C", 8),
    ("B", "E", 5),
    ("C", "E", 7),
    ("C", "D", 1),
    ("D", "E", 9)
]

# Create graph
G = nx.Graph()

for u, v, w in edges:
    G.add_edge(u, v, weight=w)

# Prim’s MST
mst = nx.minimum_spanning_tree(G, algorithm="prim")

# Layout
pos = nx.spring_layout(G, seed=42)

plt.figure(figsize=(8,6))

# Full graph (light)
nx.draw(G, pos,
        with_labels=True,
        node_color="lightgray",
        edge_color="gray",
        node_size=2000)

# MST (highlighted)
nx.draw(mst, pos,
        with_labels=True,
        node_color="lightblue",
        edge_color="red",
        width=3,
        node_size=2000)

# Edge labels
edge_labels = nx.get_edge_attributes(G, "weight")
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)

plt.title("Prim's Algorithm - Minimum Spanning Tree")
plt.show()