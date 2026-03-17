# 🧠 Largest Submatrix With Rearrangements

## 📌 Problem Statement

Given a binary matrix `matrix`, you are allowed to rearrange the columns of each row independently.

Return the **largest area of a submatrix consisting only of 1s** after performing any number of column rearrangements.

---

## 🧩 Example

**Input**

```
matrix = [
  [0,0,1],
  [1,1,1],
  [1,0,1]
]
```

**Output**

```
4
```

---

## 💡 Intuition

Instead of directly finding rectangles:

* Convert the matrix into **heights of consecutive 1s**
* Treat each row as a **histogram**
* Since column rearrangement is allowed:

  * Sort each row in descending order
  * Try forming the largest rectangle

👉 Sorting helps because we can rearrange columns freely to maximize width.

---

## 🪜 Algorithm

1. Traverse the matrix and build heights:

   * If `matrix[i][j] == 1`, add value from above
   * Else keep it `0`

2. For each row:

   * Copy the row
   * Sort in descending order
   * For each index `j`:

     * Width = `j + 1`
     * Height = `row[j]`
     * Area = `height × width`

3. Track the maximum area

---

## 📊 Dry Run

**Heights Matrix**

```
[
  [0,0,1],
  [1,1,2],
  [2,0,3]
]
```

**After Sorting Rows**

```
[1,0,0]
[2,1,1]
[3,2,0]
```

**Maximum Area = 4**

---

## 💻 C++ Implementation

```cpp
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Build heights
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }

        int maxArea = 0;

        // Process each row
        for (int i = 0; i < m; i++) {
            vector<int> row = matrix[i];

            sort(row.begin(), row.end(), greater<int>());

            for (int j = 0; j < n; j++) {
                int height = row[j];
                int width = j + 1;
                maxArea = max(maxArea, height * width);
            }
        }

        return maxArea;
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(m × n log n)`
* **Space Complexity:** `O(1)` (in-place modification)

---

## 🧠 Key Takeaways

* Convert matrix → histogram problem
* Sorting simulates column rearrangement
* Greedy width expansion gives optimal result

---

