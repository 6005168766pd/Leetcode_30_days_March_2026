# 🧩 Partition Grid with One Removal (LeetCode)

## 📌 Problem Overview

Given a 2D grid of integers, the task is to determine whether it is possible to partition the grid into two parts (using a horizontal or vertical cut) such that:

* The sum of both parts is equal
  **OR**
* The sums can be made equal by removing **at most one element** from either part

---

## 🎯 Approach

### 🔹 Key Idea

* Compute the **total sum** of the grid
* Try all possible:

  * Horizontal cuts
  * Vertical cuts (by transposing the grid)

At each cut:

* Divide grid into **top** and **bottom**
* Compute:

  * `topSum`
  * `bottomSum`

---

### 🔹 Conditions Checked

At every cut:

1. ✅ If `topSum == bottomSum` → return `true`
2. ✅ Else compute:

   ```cpp
   diff = abs(topSum - bottomSum)
   ```
3. Check if `diff` exists in the **top partition**

   * If yes → removing that element balances both parts

---

### 🔹 Why Reverse?

* To simulate cuts from both directions (top-down & bottom-up)

---

### 🔹 Why Transpose?

* To convert **vertical cuts → horizontal cuts**

---

## 💻 Implementation

```cpp
class Solution {
public:
    typedef long long ll;
    ll total = 0;

    bool checkHorcuts(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        unordered_set<ll> set;
        ll top = 0;

        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < n; j++){
                set.insert(grid[i][j]);
                top += grid[i][j];
            }

            ll bottom = (total - top);
            ll diff = abs(top - bottom);

            if(diff == 0) return true;

            if(set.count(diff)) return true;
        }
        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        total = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                total += grid[i][j];
            }
        }

        // Horizontal cuts
        if(checkHorcuts(grid)) return true;

        reverse(grid.begin(), grid.end());
        if(checkHorcuts(grid)) return true;
        reverse(grid.begin(), grid.end());

        // Transpose for vertical cuts
        vector<vector<int>> transposeGrid(n, vector<int>(m));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                transposeGrid[j][i] = grid[i][j];
            }
        }

        if(checkHorcuts(transposeGrid)) return true;

        reverse(transposeGrid.begin(), transposeGrid.end());
        if(checkHorcuts(transposeGrid)) return true;

        return false;
    }
};
```

---

## ⏱️ Complexity Analysis

| Type  | Complexity                 |
| ----- | -------------------------- |
| Time  | **O(m × n)**               |
| Space | **O(n)** (for set storage) |

---

## 🧠 Key Insights

* Prefix sum (top accumulation) helps avoid recomputation
* Using `set` enables quick lookup for required element removal
* Reversing + transposing avoids writing duplicate logic

---
## ✅ Conclusion

This approach efficiently checks whether a grid can be partitioned into two equal-sum parts with at most one removal. It leverages prefix sums, set-based lookup, and matrix transformations for optimal performance.

---

⭐ *If you found this helpful, consider giving a star to the repo!*
