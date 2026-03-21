# 🚀 Reverse Submatrix (LeetCode 3643)

## 📌 Problem Summary

Given a 2D matrix `grid`, and three integers `x`, `y`, and `k`, reverse a **k × k submatrix** starting from position `(x, y)`.

- Rows range from `x` to `x + k - 1`
- Columns range from `y` to `y + k - 1`

The reversal is performed **vertically**, meaning:
- The top row of the submatrix is swapped with the bottom row
- The process continues inward until the middle is reached

---

## 🧠 Approach

### 💡 Key Idea

Instead of creating a new matrix, we perform the operation **in-place**.

We use a **two-pointer technique on rows**:
- One pointer starts at the top of the submatrix
- The other starts at the bottom
- Swap entire rows column by column within the submatrix

---

## ⚙️ Algorithm

1. Initialize:
   - `startRow = x`
   - `endRow = x + k - 1`
   - `startCol = y`
   - `endCol = y + k - 1`

2. Iterate while `startRow <= endRow`:
   - For each column in `[startCol, endCol]`:
     - Swap `grid[startRow][col]` with `grid[endRow][col]`

3. Move pointers:
   - `startRow++`
   - `endRow--`

4. Return the modified grid

---

## 🧾 Implementation (C++)

```cpp
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int startRow = x;
        int endRow = x + k - 1;
        int startCol = y;
        int endCol = y + k - 1;

        while (startRow <= endRow) {
            for (int col = startCol; col <= endCol; col++) {
                swap(grid[startRow][col], grid[endRow][col]);
            }
            startRow++;
            endRow--;
        }

        return grid;
    }
};
