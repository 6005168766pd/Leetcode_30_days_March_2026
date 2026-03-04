# Special Positions in a Binary Matrix

## 📌 Problem Statement

Given an `m x n` binary matrix `mat`, return the number of **special positions** in the matrix.

A position `(i, j)` is called **special** if:

* `mat[i][j] == 1`
* All other elements in **row i** are `0`
* All other elements in **column j** are `0`

In other words, the `1` at `(i, j)` must be the **only 1 in its row and its column**.

---

## 📊 Example

### Example 1

Input:

```
mat = [[1,0,0],
       [0,0,1],
       [1,0,0]]
```

Output:

```
1
```

Explanation:

* Position `(1,2)` is special because it is the only `1` in its row and column.

---

### Example 2

Input:

```
mat = [[1,0,0],
       [0,1,0],
       [0,0,1]]
```

Output:

```
3
```

Explanation:

Each row and column contains exactly one `1`, so all three are special positions.

---

## 🔍 Approach

To determine if a position `(i, j)` is special:

1. Count the number of `1`s in each **row**.
2. Count the number of `1`s in each **column**.
3. Traverse the matrix:

   * If `mat[i][j] == 1`
   * And `rowCount[i] == 1`
   * And `colCount[j] == 1`
   * Then increment the result.

This avoids repeatedly scanning rows and columns.

---

## ⚙️ Algorithm

1. Initialize two arrays:

   * `rowCount[m]`
   * `colCount[n]`
2. Traverse the matrix and count `1`s in rows and columns.
3. Traverse the matrix again:

   * If `mat[i][j] == 1` and `rowCount[i] == 1` and `colCount[j] == 1`
   * Increment the answer.
4. Return the count.

---

## 🧑‍💻 C++ Implementation

```cpp
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> row(m,0);
        vector<int> col(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int count = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1 && row[i]==1 && col[j]==1){
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

**Time Complexity**

```
O(m × n)
```

We traverse the matrix twice.

**Space Complexity**

```
O(m + n)
```

For storing row and column counts.

---

## 🧠 Key Concepts

* Matrix traversal
* Counting frequency
* Efficient row/column checks
* Space optimization

---

