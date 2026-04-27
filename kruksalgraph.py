import networkx as nx
import matplotlib.pyplot as plt

# Graph edges (u, v, weight)
edges = [
    ("A", "B", 4),
    ("A", "C", 2),
    ("B", "C", 1),
    ("B", "D", 5),
    ("C", "D", 8),
    ("C", "E", 10),
    ("D", "E", 2)
]

# Create graph
G = nx.Graph()
for u, v, w in edges:
    G.add_edge(u, v, weight=w)

# Kruskal MST
mst = nx.minimum_spanning_tree(G, algorithm="kruskal")

# Layout
pos = nx.spring_layout(G, seed=42)

plt.figure(figsize=(8,6))

# Draw full graph (light gray)
nx.draw(G, pos,
        with_labels=True,
        node_color="lightgray",
        edge_color="gray",
        node_size=2000)

# Draw MST edges (highlight red)
nx.draw(mst, pos,
        with_labels=True,
        node_color="lightblue",
        edge_color="red",
        width=3,
        node_size=2000)

# Edge labels (weights)
edge_labels = nx.get_edge_attributes(G, "weight")
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)

plt.title("Kruskal's Algorithm - Minimum Spanning Tree")
plt.show()