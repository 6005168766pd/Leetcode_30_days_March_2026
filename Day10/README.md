# 🚀 Find All Possible Stable Binary Arrays II

## 🧩 Problem

Given three integers:

* `zero` → number of **0s**
* `one` → number of **1s**
* `limit` → maximum allowed **consecutive identical elements**

A **stable binary array** is defined as a binary array that:

1. Contains exactly `zero` number of `0`s.
2. Contains exactly `one` number of `1`s.
3. Does **not contain more than `limit` consecutive `0`s or `1`s**.

Return the **number of possible stable binary arrays** that can be formed.

Since the result may be very large, return it **modulo (10^9 + 7)**.

---

# 🧠 Intuition

We need to construct arrays using:

* `zero` zeros
* `one` ones

But with the restriction that **no more than `limit` identical numbers appear consecutively**.

A brute-force approach of generating all permutations is impossible because:

```
(zero + one)! possibilities
```

Instead, we use **Dynamic Programming (DP)** to build arrays step-by-step.

The DP state keeps track of:

* Remaining zeros
* Remaining ones
* Last placed element

---

# ⚙️ Approach — Dynamic Programming + Memoization

Define:

```
dp[z][o][last]
```

Where:

* `z` = zeros remaining
* `o` = ones remaining
* `last` = last placed element (`0` or `1`)

We try to place:

* up to `limit` zeros
* up to `limit` ones

while ensuring we never exceed the consecutive limit.

---
   

# ⏱ Complexity Analysis

| Complexity | Value                   |
| ---------- | ----------------------- |
| Time       | `O(zero × one × limit)` |
| Space      | `O(zero × one × 2)`     |

---

# 📊 Example

### Input

```
zero = 1
one = 1
limit = 2
```

### Possible Stable Arrays

```
01
10
```

### Output

```
2
```



⭐ If you found this helpful, consider giving the repository a **star**!
