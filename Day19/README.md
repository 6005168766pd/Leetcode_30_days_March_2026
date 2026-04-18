# 📌 LeetCode 3212 – Count Submatrices With Equal Frequency of X and Y

##  Problem Statement

Given a 2D grid consisting of characters `'X'` and `'Y'`, your task is to count the number of submatrices where the number of `'X'` and `'Y'` are equal.

---

##  Intuition

To solve this problem efficiently, we use the concept of **2D Prefix Sum**.

* Instead of recalculating counts for every submatrix, we precompute cumulative counts of:

  * `'X'` → `cumSumX`
  * `'Y'` → `cumSumY`
* For each cell `(i, j)`, we store:

  * Total number of `'X'` from `(0,0)` to `(i,j)`
  * Total number of `'Y'` from `(0,0)` to `(i,j)`

👉 If at any point:

```
cumSumX[i][j] == cumSumY[i][j]
```

Then the submatrix from `(0,0)` to `(i,j)` is valid.

---

## ⚙️ Approach

1. Initialize two 2D arrays:

   * `cumSumX[m][n]`
   * `cumSumY[m][n]`

2. Traverse the grid:

   * Add current cell contribution (`X` or `Y`)
   * Add values from:

     * Top cell
     * Left cell
   * Subtract diagonal (to avoid double counting)

3. Check:

   * If counts of `X` and `Y` are equal → increment answer

---

## 🧮 Prefix Sum Formula

For each cell `(i, j)`:

```
sum[i][j] = current 
          + sum[i-1][j] 
          + sum[i][j-1] 
          - sum[i-1][j-1]
```

---

## ✅ C++ Implementation

```cpp
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<vector<int>> cumSumX(m, vector<int>(n, 0));
        vector<vector<int>> cumSumY(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                cumSumX[i][j] = (grid[i][j] == 'X');
                cumSumY[i][j] = (grid[i][j] == 'Y');

                if(i > 0){
                    cumSumX[i][j] += cumSumX[i-1][j];
                    cumSumY[i][j] += cumSumY[i-1][j];
                }

                if(j > 0){
                    cumSumX[i][j] += cumSumX[i][j-1];
                    cumSumY[i][j] += cumSumY[i][j-1];
                }

                if(i > 0 && j > 0){
                    cumSumX[i][j] -= cumSumX[i-1][j-1];
                    cumSumY[i][j] -= cumSumY[i-1][j-1];
                }

                if(cumSumX[i][j] == cumSumY[i][j]){
                    count++;
                }
            }
        }

        return count;
    }
};
```

---

## ⏱️ Complexity Analysis

| Type  | Complexity |
| ----- | ---------- |
| Time  | `O(m × n)` |
| Space | `O(m × n)` |

---

## ⚠️ Important Note

This solution counts only **submatrices starting from (0,0)**.

👉 If the problem requires counting **all possible submatrices**, then a more advanced approach is needed:

* Fix rows
* Convert to 1D array
* Use hashmap with prefix sum

---

## 🚀 Key Takeaways

* 2D Prefix Sum is powerful for submatrix problems
* Always remember:

  * Add top + left
  * Subtract diagonal
* Be careful with edge conditions

---

## 🏁 Conclusion

This approach efficiently reduces redundant computation and allows us to count valid submatrices in linear time relative to grid size.

---

