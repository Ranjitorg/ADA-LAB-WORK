import matplotlib.pyplot as plt

n_values = []
time_values = []

with open("d:\\Downloads\\Algorithim\\LABS\\MAIN\\horner_rule.txt", "r") as file:
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
plt.show()