import matplotlib.pyplot as plt

x = []
y_actual = []
y_theoretical = []

with open('d:\\Downloads\\Algorithim\\LABS\\MAIN\\LS_output.txt') as f:
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
plt.show()
