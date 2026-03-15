# LeetCode 3296 — Minimum Number of Seconds to Make Mountain Height Zero

## 🧩 Problem Overview

You are given:

* An integer `mountainHeight`
* An array `workerTimes` where `workerTimes[i]` represents the time taken by the `i-th` worker to reduce the mountain height.

Each worker can reduce the height multiple times, but the time taken increases in an arithmetic pattern.

Your task is to determine the **minimum number of seconds required to reduce the mountain height to zero** using the available workers.

---

## 💡 Intuition

Each worker reduces the mountain height multiple times with increasing time cost:

```
time = workerTime * (1 + 2 + 3 + ... + k)
```

Which becomes:

```
time = workerTime * (k * (k + 1) / 2)
```

Where:

* `k` = number of units of height reduced by that worker.

The problem asks us to determine the **minimum time required** such that the combined work of all workers reduces the mountain height to `0`.

To solve this efficiently, we use **Binary Search on Time**.

---

## 🚀 Approach

### Step 1: Binary Search on Time

Search for the minimum time `T` such that workers together can reduce the mountain height completely.

### Step 2: Check Feasibility

For each worker:

```
workerTime * (k * (k + 1) / 2) ≤ T
```

We compute the maximum `k` each worker can reduce within time `T`.

### Step 3: Sum Contributions

Add reductions from all workers.

If the total reduction ≥ `mountainHeight`, then time `T` is feasible.

---

## ⏱ Complexity Analysis

| Complexity       | Value        |
| ---------------- | ------------ |
| Time Complexity  | `O(n log T)` |
| Space Complexity | `O(1)`       |

Where:

* `n` = number of workers
* `T` = search space of time

---

## 💻 C++ Implementation

```cpp
class Solution {
public:
    long long maxHeight(long long t, int w) {
        long long left = 0, right = 1e6;
        
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long timeNeeded = (long long)w * (mid * (mid + 1) / 2);
            
            if (timeNeeded <= t) left = mid + 1;
            else right = mid - 1;
        }
        
        return right;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 1, right = 1e18;
        long long ans = right;

        while (left <= right) {
            long long mid = (left + right) / 2;
            
            long long reduced = 0;
            for (int w : workerTimes) {
                reduced += maxHeight(mid, w);
                if (reduced >= mountainHeight) break;
            }

            if (reduced >= mountainHeight) {
                ans = mid;
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
```

---

## 🔑 Key Concepts

* Binary Search on Answer
* Mathematical series (`k*(k+1)/2`)
* Greedy accumulation
* Optimization for large constraints

---

## 📌 Example

**Input**

```
mountainHeight = 4
workerTimes = [2,1,1]
```

**Output**

```
3
```

Explanation:
Workers collaboratively reduce the mountain height in the minimum time possible.

---


⭐ If you found this solution helpful, consider **starring the repository**!
