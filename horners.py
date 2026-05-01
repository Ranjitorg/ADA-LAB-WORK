from pathlib import Path

import matplotlib.pyplot as plt

script_dir = Path(__file__).resolve().parent
output_dir = script_dir.parent / "graphs"
output_dir.mkdir(exist_ok=True)

n_values = []
time_values = []

with open(script_dir.parent / "horner_rule.txt", "r") as file:
    next(file)

    for line in file:
        n, t = line.split()
        n_values.append(int(n))
        time_values.append(float(t))

plt.plot(n_values, time_values, marker='o')
plt.xlabel("Number of Elements")
plt.ylabel("Time (ns)")
plt.title("Horner Rule Time Complexity")
plt.grid(True)
plt.tight_layout()
plt.savefig(output_dir / "horner_rule_graph.png", dpi=200)
plt.show()