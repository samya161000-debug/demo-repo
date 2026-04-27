import networkx as nx
import matplotlib.pyplot as plt

# Directed multistage graph edges (u, v, weight)
edges = [
    (0, 1, 2),
    (0, 2, 1),
    (0, 3, 3),
    (1, 4, 2),
    (2, 4, 3),
    (3, 5, 6),
    (4, 5, 1)
]

G = nx.DiGraph()

for u, v, w in edges:
    G.add_edge(u, v, weight=w)

# Define stages (for layout)
stages = {
    0: (0, 0),
    1: (1, 2),
    2: (1, 0),
    3: (1, -2),
    4: (2, 0),
    5: (3, 0)
}

pos = stages

plt.figure(figsize=(8,6))

# Draw graph
nx.draw(G, pos,
        with_labels=True,
        node_color="lightblue",
        node_size=2000,
        arrows=True)

# Draw edge weights
edge_labels = nx.get_edge_attributes(G, "weight")
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)

# Highlight a sample shortest path (0 → 2 → 4 → 5)
path_edges = [(0, 2), (2, 4), (4, 5)]
nx.draw_networkx_edges(G, pos,
                       edgelist=path_edges,
                       width=3,
                       edge_color="red")

plt.title("Multistage Graph (Layered Structure + Path)")
plt.show()