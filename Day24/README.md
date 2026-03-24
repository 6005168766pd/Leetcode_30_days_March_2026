# 🔢 Product Matrix

## 🧩 Problem Statement

Given a 2D matrix `grid` of size `n x m`, construct a new matrix `p` such that:

```
p[i][j] = product of all elements in grid except grid[i][j] (mod 12345)
```

---

## 📌 Example

```
Input:
grid = [[1,2],
        [3,4]]

Output:
[[24,12],
 [8,6]]
```

---

## 💡 Approach

We cannot directly compute the product for each cell by iterating over the entire matrix every time (that would be **O(n² * m²)** ❌).

Instead, we optimize using **Prefix Product + Suffix Product**.

---

### 🔥 Key Idea

- Traverse the matrix in **reverse order** → store suffix product  
- Traverse the matrix in **forward order** → combine with prefix product  

👉 This avoids division and works efficiently with modulo.

---

## ⚙️ Algorithm

### Step 1: Initialize
- Create result matrix `p`
- Set:
  ```
  suffix = 1
  ```

---

### Step 2: Compute Suffix Products (Reverse Traversal)

- Traverse from bottom-right to top-left:
```
p[i][j] = suffix
suffix = (suffix * grid[i][j]) % MOD
```

---

### Step 3: Compute Prefix Products (Forward Traversal)

- Traverse from top-left to bottom-right:
```
p[i][j] = (prefix * p[i][j]) % MOD
prefix = (prefix * grid[i][j]) % MOD
```

---

### Step 4: Return Result

---

## 🧠 Complexity Analysis

| Type | Complexity |
|------|----------|
| Time | O(n × m) |
| Space | O(n × m) |

---

## 🧾 Code (C++)

```cpp
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const int MOD = 12345;

        vector<vector<int>> p(n, vector<int>(m));

        long long suffix = 1;

        // Step 1: Suffix Product
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                p[i][j] = suffix;
                suffix = (suffix * grid[i][j]) % MOD;
            }
        }

        long long prefix = 1;

        // Step 2: Prefix Product
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                p[i][j] = (prefix * p[i][j]) % MOD;
                prefix = (prefix * grid[i][j]) % MOD;
            }
        }

        return p;
    }
};
```

---

## 🔥 Key Insights

- Avoid division → use prefix & suffix products  
- Flatten matrix traversal logically without extra space  
- Works efficiently under modulo  

---

## 🏷️ Tags

`Matrix` `Prefix Sum` `Simulation` `Math`

---

## 🚀 Takeaway

> Prefix + Suffix technique is a powerful pattern for “product except self” problems in both arrays and matrices.
