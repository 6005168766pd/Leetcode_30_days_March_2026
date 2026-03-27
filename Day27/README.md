# 🚀 LeetCode 2946 - Matrix Similarity After Cyclic Shifts

## 🧩 Problem Statement

Given a 2D integer matrix `mat` of size `m x n` and an integer `k`, determine whether the matrix remains the same after performing the following operation:

* For every row:

  * If the row index is **even**, shift the row **left** by `k` positions.
  * If the row index is **odd**, shift the row **right** by `k` positions.

Return `true` if the matrix remains unchanged after the operation, otherwise return `false`.

---

## 💡 Intuition

Instead of actually modifying the matrix, we can **simulate the shifts mathematically** and compare positions.

Key idea:

* After shifting:

  * Even row (`i % 2 == 0`): element moves from `j → (j + k) % n`
  * Odd row (`i % 2 == 1`): element moves from `j → (j - k + n) % n`

If **every element maps back to its original position**, the matrix is unchanged.

---

## ⚙️ Approach

1. Traverse each row `i` and column `j`.
2. Compute the new index after shifting:

   * If row is even → `newCol = (j + k) % n`
   * If row is odd → `newCol = (j - k + n) % n`
3. Compare:

   * `mat[i][j]` with `mat[i][newCol]`
4. If any mismatch occurs → return `false`
5. If all elements match → return `true`

---

## 🧠 Algorithm

```
for each row i:
    for each column j:
        if i is even:
            newCol = (j + k) % n
        else:
            newCol = (j - k + n) % n
        
        if mat[i][j] != mat[i][newCol]:
            return false

return true
```

---

## 🧾 Code (C++)

```cpp
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        k = k % n;  // optimize unnecessary rotations
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int newCol;
                
                if(i % 2 == 0){
                    // left shift
                    newCol = (j + k) % n;
                } else {
                    // right shift
                    newCol = (j - k + n) % n;
                }
                
                if(mat[i][j] != mat[i][newCol]){
                    return false;
                }
            }
        }
        
        return true;
    }
};
```

---

## ⏱️ Complexity Analysis

| Type             | Complexity |
| ---------------- | ---------- |
| Time Complexity  | `O(m × n)` |
| Space Complexity | `O(1)`     |

* We only traverse the matrix once.
* No extra space is used.

---

## 📝 Key Observations

* Rotating by `k` is equivalent to rotating by `k % n`
* No need to physically rotate rows → saves time and space
* Direct index mapping is the most efficient approach

---

## 🧪 Example

### Input

```
mat = [[1,2,3],
       [4,5,6]]
k = 1
```

### After Shifts

```
Row 0 (even): left shift → [2,3,1]
Row 1 (odd):  right shift → [6,4,5]
```

### Output

```
false
```

---

## 🎯 Summary

* Use modular arithmetic to simulate cyclic shifts
* Compare positions directly instead of modifying the matrix
* Efficient and clean solution with O(m × n) time

---

⭐ If you found this helpful, consider starring your repo!
