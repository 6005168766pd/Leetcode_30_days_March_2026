#  LeetCode 3070: Count Submatrices with Top-Left Element and Sum Less Than k


---

## 🧠 Problem Statement

You are given a **0-indexed 2D integer matrix `grid`** and an integer `k`.

A submatrix is defined by its **top-left corner at (0,0)** and some bottom-right corner `(i, j)`.

👉 Your task is to **count the number of submatrices** such that the **sum of elements in the submatrix is less than or equal to `k`**.

---

## 💡 Approach: Prefix Sum (2D)

To efficiently compute submatrix sums, we use a **2D prefix sum technique**.

### 🔹 Key Idea

* Convert the matrix into a prefix sum matrix where:

  ```
  grid[i][j] = sum of all elements from (0,0) to (i,j)
  ```
* Then simply check:

  ```
  if grid[i][j] <= k → count++
  ```

---

## ⚙️ Algorithm

1. Traverse the matrix row by row.
2. Update each cell as:

   ```
   grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1]
   ```
3. For each cell `(i, j)`, check:

   ```
   if grid[i][j] <= k → increment count
   ```

---

## 💻 Code (C++)

```cpp
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(i > 0) grid[i][j] += grid[i-1][j];
                if(j > 0) grid[i][j] += grid[i][j-1];
                if(i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];

                if(grid[i][j] <= k) count++;
            }
        }

        return count;
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(m × n)`
* **Space Complexity:** `O(1)` (in-place prefix sum)

---

## 🔍 Example

### Input:

```
grid = [[7,6,3],
        [6,6,1]]
k = 18
```

### Output:

```
4
```

---

## 🚀 Key Takeaways

* Use **2D prefix sum** to optimize submatrix sum queries.
* Since all submatrices start at `(0,0)`, we only need prefix sums.
* Efficient and optimal solution for this problem.

---

## 🏷️ Tags

`Array` `Matrix` `Prefix Sum` `Greedy`

---

⭐ If you found this helpful, consider giving a star!
