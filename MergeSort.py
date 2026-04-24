import math
import matplotlib.pyplot as plt

x = list(range(1000, 20001, 1000))
y_theoretical = [n * math.log(n) for n in x]

plt.plot(x, y_theoretical, marker='s', label='Theoretical (n log n)')
plt.title("Input Size vs Time Taken for Merge Sort")
plt.xlabel("Input Size (n)")
plt.ylabel("Time (ms)")
plt.legend()
plt.grid(True)
plt.show()
