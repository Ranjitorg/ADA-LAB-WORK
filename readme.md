# ADA Practical File — UE243116 Trijal Gandotra

---

# Experiment 1 Binary Truth Table

## Aim
To generate all binary combinations using recursion.

## Algorithm

```
BinaryTruth(n):
  IF n == 0:
    PRINT combination
    RETURN
  CALL BinaryTruth(n-1) with bit = 0
  CALL BinaryTruth(n-1) with bit = 1
```

## Time Complexity
- Best: O(2^n)
- Average: O(2^n)
- Worst: O(2^n)

## Use Cases
- Digital logic
- Bit generation


---

# Experiment 2 Bouncing Ball

## Aim
To simulate bouncing ball heights recursively.

## Algorithm

```
BouncingBall(h):
  IF h <= 0:
    RETURN
  PRINT h
  CALL BouncingBall(h/2)
```

## Time Complexity
- Best: O(1)
- Average: O(n)
- Worst: O(n)

## Use Cases
- Physics simulation
- Recursive modeling

## Graph
![Ball Bounce Count - Time Taken vs n](graphs/ball_bounce_graph.png)

---

# Experiment 3 Horner's Rule

## Aim
To evaluate a polynomial efficiently using Horner's Rule.

## Algorithm

```
Horner(poly, n, x):
  IF n == 0: RETURN poly[0]
  RETURN poly[n] + x * Horner(n-1)
```

## Time Complexity
- Best: O(n)
- Average: O(n)
- Worst: O(n)

## Use Cases
- Polynomial evaluation
- Numerical methods

## Graph
![Horner's Rule](graphs/image.png)

---

# Experiment 4 Linear Search

## Aim
To find an element recursively.

## Algorithm

```
LinearSearch(arr, n, key, i):
  IF i >= n: RETURN -1
  IF arr[i] == key: RETURN i
  RETURN LinearSearch(i+1)
```

## Time Complexity
- Best: O(1)
- Average: O(n)
- Worst: O(n)

## Use Cases
- Searching
- Small datasets

## Graph
![Linear Search](graphs/image-1.png)

---

# Experiment 5 Max Min

## Aim
To find the maximum and minimum element in an array recursively.

## Algorithm

```
MaxMin(low, high):
  IF low == high: RETURN arr[low]
  mid = (low + high) / 2
  left  = MaxMin(low, mid)
  right = MaxMin(mid+1, high)
  RETURN combine
```

## Time Complexity
- Best: O(n)
- Average: O(n)
- Worst: O(n)

## Use Cases
- Optimization
- Large arrays

![Min-Max](graphs/min_max_graph.png)

---

# Experiment 6 Permutations

## Aim
To generate all permutations of a string.

## Algorithm

```
Permute(str, l, r):
  IF l == r: PRINT str
  FOR i = l TO r:
    SWAP str[l] and str[i]
    CALL Permute(l+1)
    SWAP back
```

## Time Complexity
- Best: O(n!)
- Average: O(n!)
- Worst: O(n!)

## Use Cases
- Combinatorics
- Backtracking

## Graph
![Permutation Generation of String](graphs/image-4.png)

---

# Experiment 7 Power xⁿ

## Aim
To compute power recursively.

## Algorithm

```
Power(x, n):
  IF n == 0: RETURN 1
  RETURN x * Power(x, n-1)
```

## Time Complexity
- Best: O(1)
- Average: O(n)
- Worst: O(n)

## Use Cases
- Mathematics
- Exponentiation

## Graph
![Power Recursive](graphs/image-6.png)

---

# Experiment 8 Recursive Sum

## Aim
To find the sum of n numbers recursively.

## Algorithm

```
Sum(n):
  IF n == 0: RETURN 0
  RETURN n + Sum(n-1)
```

## Time Complexity
- Best: O(1)
- Average: O(n)
- Worst: O(n)

## Use Cases
- Summation
- Basics of recursion

## Graph
![Sum of Array](graphs/image-8.png)

---

# Experiment 9 Tower of Hanoi

## Aim
To solve the Tower of Hanoi problem recursively.

## Algorithm

```
TOH(n, s, a, d):
  IF n == 1:
    MOVE s → d
    RETURN
  CALL TOH(n-1, s, d, a)
  MOVE disk n from s to d
  CALL TOH(n-1, a, s, d)
```

## Time Complexity
- Best: O(2^n)
- Average: O(2^n)
- Worst: O(2^n)

## Use Cases
- Assessment of cognitive function in psychology and neuroscience
- Evaluating frontal lobe function and cognitive planning

## Graph
![Tower of Hanoi - Time Taken vs n](graphs/toh_graph.png)

---

# Experiment 11 Finding Missing Value in Consecutive Sequence

## Aim
To find a missing value in a consecutive sequence.

## Algorithm

```
FIND_MISSING(arr, n):
  low  ← 0
  high ← n - 1
  WHILE low ≤ high:
    mid ← (low + high) // 2
    IF arr[mid] == mid:
      low ← mid + 1
    ELSE:
      high ← mid - 1
  RETURN low
```

## Time Complexity
- Best: O(n)
- Average: O(n)
- Worst: O(n)

## Use Cases
- Detection of missing data in ordered sequences
- Tracking gaps in IDs, logs, or indexed records

## Graph
![Missing Number](graphs/image-2.png)

---

# Experiment 16 Insertion Sort

## Aim
To implement the Insertion Sort algorithm.

## Algorithm

```
InsertionSort(arr, n):
  FOR i = 1 TO n-1:
    key = arr[i]
    j   = i - 1
    WHILE j >= 0 AND arr[j] > key:
      arr[j+1] = arr[j]
      j = j - 1
    arr[j+1] = key
```

## Time Complexity
- Best: O(n)
- Average: O(n²)
- Worst: O(n²)

## Use Cases
- Used when data is nearly sorted, such as arranging student marks where only a few values are out of place

## Graph
![Insertion Sort](graphs/image-10.png)

---

# Experiment 17 Merge Sort

## Aim
To implement the Merge Sort algorithm.

## Algorithm

```
MergeSort(arr, l, r):
  IF l < r:
    mid = (l + r) / 2
    CALL MergeSort(arr, l, mid)
    CALL MergeSort(arr, mid+1, r)
    MERGE(arr, l, mid, r)
```

## Time Complexity
- Best: O(n log n)
- Average: O(n log n)
- Worst: O(n log n)

## Use Cases
- Used in external sorting where data is too large to fit into memory, such as sorting large database files

## Graph
![Merge Sort](graphs/image-11.png)

---

# Experiment 18 Quick Sort

## Aim
To implement the Quick Sort algorithm.

## Algorithm

```
QuickSort(arr, l, r):
  IF l < r:
    p = Partition(arr, l, r)
    CALL QuickSort(arr, l, p-1)
    CALL QuickSort(arr, p+1, r)
```

## Time Complexity
- Best: O(n log n)
- Average: O(n log n)
- Worst: O(n²)

## Use Cases
- Widely used in system libraries for fast sorting of large datasets due to good average-case performance

## Graph
![Quick Sort](graphs/image-12.png)

---

# Experiment 19 Convex Hull Triangle

## Aim
To implement the Convex Hull Triangle algorithm.

## Algorithm

```
ConvexHull(points):
  FOR all triplets (i, j, k):
    FORM triangle
    FOR each point p:
      IF p lies inside triangle:
        MARK p as inside
  PRINT points not marked
```

## Time Complexity
- Best: O(n³)
- Average: O(n³)
- Worst: O(n³)

## Use Cases
- Used in computer graphics to find the boundary of shapes or objects

## Graph
![Convex Hull Time Complexity](graphs/image-13.png)

---

# Experiment 20 Binary Search

## Aim
To implement the Binary Search algorithm.

## Algorithm

```
BinarySearch(arr, l, r, key):
  IF l > r: RETURN -1
  mid = (l + r) / 2
  IF arr[mid] == key: RETURN mid
  ELSE IF key < arr[mid]:
    RETURN BinarySearch(arr, l, mid-1, key)
  ELSE:
    RETURN BinarySearch(arr, mid+1, r, key)
```

## Time Complexity
- Best: O(1)
- Average: O(log n)
- Worst: O(log n)

## Use Cases
- Used in searching elements in sorted databases, like finding a record in a sorted employee list

## Graph
![Binary Search](graphs/image-9.png)

---

# Experiment 21 Dijkstra Algorithm

## Aim
To implement the Dijkstra shortest path algorithm.

## Algorithm

```
Dijkstra(graph, source):
  INITIALIZE dist[]
  dist[source] = 0
  WHILE nodes remain:
    PICK node with minimum distance
    UPDATE distances of neighbors
```

## Time Complexity
- Best: O(V log V)
- Average: O((V+E) log V)
- Worst: O((V+E) log V)

## Use Cases
- Used in GPS navigation systems to find shortest routes between locations

## Graph
![Dijkstra's Algorithm Time Complexity](graphs/image-16.png)

---

# Experiment 22 Prim's Algorithm

## Aim
To implement Prim's Minimum Spanning Tree algorithm.

## Algorithm

```
Prims(graph):
  INITIALIZE visited set
  PICK minimum edge
  ADD edge to MST
  REPEAT until all vertices included
```

## Time Complexity
- Best: O(E log V)
- Average: O(E log V)
- Worst: O(E log V)

## Use Cases
- Used in designing minimum-cost networks like electrical wiring or roads

## Graph
![Prim's Algorithm Time Complexity](graphs/image-18.png)

---

# Experiment 23 Kruskal's Algorithm

## Aim
To implement Kruskal's Minimum Spanning Tree algorithm.

## Algorithm

```
Kruskal(edges):
  SORT edges by weight
  FOR each edge:
    IF no cycle formed:
      ADD edge to MST
```

## Time Complexity
- Best: O(E log E)
- Average: O(E log E)
- Worst: O(E log E)

## Use Cases
- Used in network design to connect all nodes with minimum cost

## Graph
![Kruskal's Algorithm Time Complexity](graphs/image-17.png)

---

# Experiment 24 Forward Multistage Graph (MSG)

## Aim
To implement the Forward Multistage Graph algorithm.

## Algorithm

```
MinSum(graph):
  SET dist[sink] = 0
  FOR nodes from sink to source:
    UPDATE minimum cost
  RETURN dist[source]
```

## Time Complexity
- Best: O(V+E)
- Average: O(V+E)
- Worst: O(V+E)

## Use Cases
- Used in multistage decision problems like shortest path in layered graphs

## Graph
![Minimum Cost Path in Multistage Graph](graphs/image-20.png)

---

# Experiment 25 Backward Multistage Graph (MSG)

## Aim
To implement the Backward Multistage Graph algorithm.

## Algorithm

```
MSGBackward(graph):
  SET dist[source] = 0
  FOR nodes from source forward:
    UPDATE cost of neighbors
  RETURN dist[sink]
```

## Time Complexity
- Best: O(V+E)
- Average: O(V+E)
- Worst: O(V+E)

## Use Cases
- Used in forward dynamic programming problems such as staged optimization

## Graph
![Min Cost Path in Multistage Graph](graphs/image-22.png)

---

# Experiment 26 Stages in MSG

## Aim
To count the number of stages in a Multistage Graph.

## Algorithm

```
Stages(graph):
  INITIALIZE stack with source
  WHILE stack not empty:
    POP node
    PUSH neighbors
    COUNT stages
```

## Time Complexity
- Best: O(V+E)
- Average: O(V+E)
- Worst: O(V+E)

## Use Cases
- Used to determine levels or stages in decision-making graphs

## Graph
![Count Stages in multistage graph](graphs/image-29.png)

---

# Experiment 27 All Pairs Shortest Path (Floyd-Warshall)

## Aim
To implement the All Pairs Shortest Path algorithm (Warshall Algorithm).

## Algorithm

```
FloydWarshall(graph):
  FOR k = 1 TO n:
    FOR i = 1 TO n:
      FOR j = 1 TO n:
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
```

## Time Complexity
- Best: O(n³)
- Average: O(n³)
- Worst: O(n³)

## Use Cases
- Used in network routing to compute shortest paths between all pairs of nodes

## Graph
![All Pairs Shortest Paths](graphs/image-23.png)

---

# Experiment 28 Travelling Salesman Problem

## Aim
To implement the Travelling Salesman Problem algorithm.

## Algorithm

```
TSP(i, S):
  IF S empty:
    RETURN cost to source
  FOR each node j in S:
    CALCULATE cost
    TAKE minimum
```

## Time Complexity
- Best: O(n² × 2ⁿ)
- Average: O(n² × 2ⁿ)
- Worst: O(n² × 2ⁿ)

## Use Cases
- Used in logistics and delivery systems to find the minimum cost route

## Graph
![Traveling Salesman Problem](graphs/image-24.png)

---

# Experiment 29 Matrix Chain Multiplication

## Aim
To implement the Matrix Chain Multiplication algorithm.

## Algorithm

```
MatrixChain(p):
  FOR length = 2 TO n:
    FOR i:
      j = i + length - 1
      FOR k = i TO j-1:
        CALCULATE cost
        TAKE minimum
```

## Time Complexity
- Best: O(n³)
- Average: O(n³)
- Worst: O(n³)

## Use Cases
- Used in optimizing matrix multiplication order in compilers and scientific computing

## Graph
![Matrix Chain Multiplication](graphs/image-21.png)


# Experiment 30 Graph Coloring

## Aim
To implement the Graph Coloring algorithm.

## Algorithm

```
GraphColoring(graph, m):
  INITIALIZE color array
  FOR each vertex:
    ASSIGN color
    IF no valid color found:
      RETURN false
  RETURN true
```

## Time Complexity
- Best: O(m^n)
- Average: O(m^n)
- Worst: O(m^n)

## Use Cases
- Used in scheduling and register allocation problems

## Graph
![Graph Coloring](graphs/image-25.png)


# Experiment 31 Hamiltonian Cycle

## Aim
To implement the Hamiltonian Cycle algorithm.

## Algorithm

```
HamiltonianCycle(graph, n):
  INITIALIZE path array
  path[0] = 0
  IF hamiltonianUtil(graph, path, 1, n):
    RETURN true
  RETURN false
```

## Time Complexity
- Best: O(m^n)
- Average: O(m^n)
- Worst: O(m^n)

## Use Cases
- Used in scheduling and register allocation problems

## Graph

![Hamiltonian Cycle](graphs/image-26.png)


# Experiment 32 N-Queens Problem

## Aim
To implement the N-Queens Problem algorithm.

## Algorithm

```
NQueens(board, col, n):
  IF col >= n:
    PRINT board
    RETURN true
  FOR i = 0 TO n-1:
    IF isSafe(board, i, col):
      board[i][col] = 1
      CALL NQueens(col + 1)
      board[i][col] = 0
```

## Time Complexity
- Best: O(n!)
- Average: O(n!)
- Worst: O(n!)

## Use Cases
- Chess puzzle solving and analysis

## Graph

![N-Queens Problem](graphs/image-27.png)
