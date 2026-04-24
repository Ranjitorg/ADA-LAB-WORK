import matplotlib.pyplot as plt

n_values = []
time_values = []

with open("binary_search.txt", "r") as file:
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
plt.show()