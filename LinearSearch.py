from pathlib import Path

import matplotlib.pyplot as plt

script_dir = Path(__file__).resolve().parent
output_dir = script_dir.parent / "graphs"
output_dir.mkdir(exist_ok=True)

x = []
y_actual = []
y_theoretical = []

with open(script_dir.parent / 'LS_output.txt') as f:
    next(f)
    for line in f:
        n, t = line.strip().split(',')
        x.append(int(n))
        y_actual.append(float(t))
        y_theoretical.append(int(n))

plt.plot(x, y_actual, marker='o', label='Actual')
plt.plot(x, y_theoretical, marker='s', label='Theoretical (n)')
plt.title("Input Size vs Time Taken for Linear Search")
plt.xlabel("Input Size (n)")
plt.ylabel("Time (ms)")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig(output_dir / "linear_search_graph.png", dpi=200)
plt.show()
