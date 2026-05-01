from pathlib import Path

import matplotlib.pyplot as plt

script_dir = Path(__file__).resolve().parent
output_dir = script_dir.parent / "graphs"
output_dir.mkdir(exist_ok=True)

n_values = []
time_values = []

with open(script_dir / "binary_search.txt", "r") as file:
    next(file)

    for line in file:
        n, t = line.split()
        n_values.append(int(n))
        time_values.append(int(t))

plt.plot(n_values, time_values, marker='o')
plt.xlabel("Number of Elements")
plt.ylabel("Time (ns)")
plt.title("Binary Search Time Complexity")
plt.grid(True)
plt.tight_layout()
plt.savefig(output_dir / "binary_search_graph.png", dpi=200)
plt.show()