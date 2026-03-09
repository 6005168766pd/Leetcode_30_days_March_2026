# Find All Stable Binary Arrays I

**LeetCode Problem:** 3129
**Difficulty:** Medium
**Topic Tags:** Dynamic Programming, Combinatorics

---

## 🧩 Problem Description

You are given three integers:

* `zero` → number of `0`s available
* `one` → number of `1`s available
* `limit` → maximum number of **consecutive identical elements** allowed

A **stable binary array** is defined as a binary array that:

* Uses exactly `zero` number of `0`s
* Uses exactly `one` number of `1`s
* Does **not contain more than `limit` consecutive `0`s**
* Does **not contain more than `limit` consecutive `1`s**

Your task is to **count the total number of such stable binary arrays**.

Return the answer **modulo (10^9 + 7)**.

---

## 🧠 Approach

To solve this problem efficiently, we use **Dynamic Programming**.

### Key Idea

Instead of tracking the exact length of consecutive elements, we treat the array as **blocks of 0s or 1s**.

For example:

```
0001110
```

Can be seen as:

```
[000] → [111] → [0]
```

Each block length must be **between 1 and `limit`**.

---

### DP State

We define:

```
dp[z][o][last]
```

Where:

* `z` = number of zeros used
* `o` = number of ones used
* `last` = last placed element

  * `0` → last block ended with `0`
  * `1` → last block ended with `1`

The value represents **the number of stable arrays that can be formed** with these parameters.

---

### Transition

If the last placed element was `1`, we can place a block of `0`s:

```
dp[z][o][0] += dp[z-k][o][1]
```

Where:

```
1 ≤ k ≤ limit
```

Similarly, if the last element was `0`, we place a block of `1`s:

```
dp[z][o][1] += dp[z][o-k][0]
```

---

## ⏱ Complexity Analysis

### Time Complexity

```
O(zero × one × limit)
```

Worst case:

```
200 × 200 × 200 ≈ 8 × 10⁶ operations
```

Which is efficient.

---

### Space Complexity

```
O(zero × one × 2)
```

Approximately **80k states**, which is very memory efficient.

---

## 💻 C++ Implementation

```cpp
class Solution {
public:
    const int MOD = 1e9+7;

    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<long long>>> dp(
            zero+1, vector<vector<long long>>(one+1, vector<long long>(2,0))
        );

        for(int i=1;i<=min(limit,zero);i++)
            dp[i][0][0] = 1;

        for(int i=1;i<=min(limit,one);i++)
            dp[0][i][1] = 1;

        for(int z=0; z<=zero; z++){
            for(int o=0; o<=one; o++){

                if(z>0){
                    for(int k=1;k<=limit && k<=z;k++){
                        dp[z][o][0] = (dp[z][o][0] + dp[z-k][o][1]) % MOD;
                    }
                }

                if(o>0){
                    for(int k=1;k<=limit && k<=o;k++){
                        dp[z][o][1] = (dp[z][o][1] + dp[z][o-k][0]) % MOD;
                    }
                }
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
```

---

## 📊 Example

### Input

```
zero = 2
one = 1
limit = 1
```

### Valid Stable Arrays

```
010
101
```

### Output

```
2
```

---

## ⭐ Key Learning

This problem demonstrates an important **Dynamic Programming pattern**:

> **Counting sequences with constraints on consecutive elements**

Similar patterns appear in problems like:

* Binary strings without consecutive `1`s
* Run-length constrained sequences
* Combinatorics with adjacency restrictions

---

## 📌 Summary

* Use **Dynamic Programming**
* Track **zeros used, ones used, and last element**
* Add **blocks of size `1..limit`**
* Apply **modulo (10^9+7)** to avoid overflow

