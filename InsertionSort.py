import math
import matplotlib.pyplot as plt

x = []
y_actual = []
y_theoretical = []

with open('outputIS.txt') as f:
    next(f) 
    for line in f:
        n, t = line.strip().split(',')
        x.append(int(n))
        y_actual.append(float(t))
        y_theoretical.append(int(n) * int(n)) 

plt.plot(x, y_theoretical, marker='s', label='Theoretical (n²)')
plt.title("Input Size vs Time Taken for Insertion Sort")
plt.xlabel("Input Size (n)")
plt.ylabel("Time (ms)")
plt.legend()
plt.grid(True)
plt.show()
