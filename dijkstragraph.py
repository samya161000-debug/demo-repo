import networkx as nx
import matplotlib.pyplot as plt

# Create weighted graph
G = nx.Graph()

edges = [
    ("A", "B", 4),
    ("A", "C", 2),
    ("B", "C", 5),
    ("B", "D", 10),
    ("C", "E", 3),
    ("E", "D", 4),
    ("D", "F", 11)
]

# Add edges
for u, v, w in edges:
    G.add_edge(u, v, weight=w)

# Run Dijkstra from source
source = "A"
dist = nx.single_source_dijkstra_path_length(G, source)

# Positions for graph layout
pos = nx.spring_layout(G, seed=42)

plt.figure(figsize=(8,6))

# Draw graph
nx.draw(G, pos, with_labels=True, node_color="lightblue",
        node_size=2000, font_size=12)

# Draw edge labels (weights)
edge_labels = nx.get_edge_attributes(G, "weight")
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)

# Highlight shortest distances from source
for node, d in dist.items():
    plt.text(pos[node][0], pos[node][1]+0.1,
             f"dist={d}", ha='center', color="red")

plt.title(f"Dijkstra Shortest Path from {source}")
plt.show()