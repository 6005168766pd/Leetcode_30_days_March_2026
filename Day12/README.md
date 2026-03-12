# Maximum Stability of a Spanning Tree

## 📖 Problem Summary

You are given:

* `n` nodes in a graph
* A list of edges `edges[i] = [u, v, s, m]`

Where:

* `u`, `v` → endpoints of the edge
* `s` → stability value of the edge
* `m` → mandatory flag

  * `m = 1` → edge **must be included**
  * `m = 0` → edge is **optional**

You are also given an integer `k` representing the **maximum number of upgrades** allowed.

### Upgrade Rule

For optional edges:

* If `s ≥ mid` → edge can be used normally
* If `2 × s ≥ mid` → edge can be **upgraded** (counts as one upgrade)

### Objective

Find the **maximum possible stability value `mid`** such that:

* A **valid spanning tree** can be formed
* All **mandatory edges are included**
* At most **`k` upgrades** are used

If it is impossible to construct such a tree, return **`-1`**.

---

# 💡 Approach

The problem asks us to **maximize a value**, which suggests using **Binary Search on the answer**.

For each candidate stability value `mid`, we check whether it is possible to construct a valid spanning tree.

To efficiently manage connected components while building the tree, we use the **Disjoint Set Union (DSU)** data structure.

---

# ⚙️ Algorithm

## 1️⃣ Validate Mandatory Edges

Mandatory edges must be included in the spanning tree.

If mandatory edges themselves create a **cycle**, then building a spanning tree is impossible.

```
for each mandatory edge:
    if find(u) == find(v):
        return -1
    union(u, v)
```

---

## 2️⃣ Binary Search on Stability

We perform binary search on the possible stability value:

```
left = 1
right = maximum possible stability
```

For each `mid`, we check whether it is feasible.

---

## 3️⃣ Feasibility Check

During the check:

### Mandatory Edges

* Must satisfy `s ≥ mid`
* Otherwise the configuration is invalid

### Optional Edges

There are three cases:

1. **Strong Edge**

```
s ≥ mid
```

Add it directly.

2. **Upgradeable Edge**

```
2*s ≥ mid
```

Store it as an upgrade candidate.

3. **Weak Edge**

Ignore it.

---

## 4️⃣ Use Upgrades

Process upgrade candidates and connect components if possible.

```
if components are different and k > 0:
    union(u, v)
    k--
```

---

## 5️⃣ Connectivity Check

Finally verify that **all nodes belong to the same component**.

If yes → the candidate stability `mid` is valid.

---

# 🧠 Data Structure Used

## Disjoint Set Union (Union-Find)

The DSU structure supports:

### `find(x)`

Finds the representative of the component containing `x`.

Uses **Path Compression** for optimization.

### `union(x, y)`

Merges two components.

Uses **Union by Rank**.

Both optimizations make operations nearly constant time.

---

# ⏱️ Complexity Analysis

Let:

* `N` = number of nodes
* `E` = number of edges

### Binary Search

```
O(log W)
```

Where `W` is the maximum stability value.

### DSU Operations

```
O(E α(N))
```

`α(N)` is the **inverse Ackermann function**, which grows extremely slowly.

### Total Complexity

```
O(E log W)
```

---

# 🚀 Key Takeaways

* Binary Search can be applied to **maximize or minimize answers**
* DSU efficiently manages **dynamic graph connectivity**
* Mandatory constraints must be checked carefully to avoid invalid trees
* Greedy upgrades allow maximizing the achievable stability

---

# 🏁 Conclusion

This problem combines multiple algorithmic techniques:

* Binary Search on Answer
* Graph Connectivity
* Greedy Decisions
* Disjoint Set Union

Together they allow us to efficiently determine the **maximum achievable stability of the spanning tree** under the given constraints.
