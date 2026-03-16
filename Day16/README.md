# LeetCode 1878 — Get Biggest Three Rhombus Sums in a Grid

## 🧩 Problem Overview

You are given an `m x n` integer matrix `grid`.
A **rhombus sum** is defined as the sum of the numbers that lie on the **border of a rhombus shape** in the grid.

Your task is to return the **three largest distinct rhombus sums** in **descending order**.

If fewer than three distinct sums exist, return all of them.

---

# 💡 Intuition

A rhombus in the grid is defined by:

* A **center cell `(r, c)`**
* A **side length `side`**

For a rhombus:

```
        top
       /   \
 left       right
       \   /
       bottom
```

The border consists of four edges:

1. Top → Right
2. Right → Bottom
3. Bottom → Left
4. Left → Top

For each cell `(r, c)`:

* Consider it as the **center**
* Expand the rhombus by increasing `side`
* Calculate the **border sum**

We maintain the **top three distinct sums** using a `set`.

---

# 🚀 Approach

### Step 1

Iterate through every cell in the grid and treat it as the center of a rhombus.

### Step 2

Insert the value of the single cell (side = 0 rhombus).

### Step 3

Expand rhombus borders while remaining inside grid bounds.

### Step 4

Compute border sums for each rhombus.

### Step 5

Store sums in a `set` to keep them **unique and sorted**.

### Step 6

Keep only the **largest three values**.

---

# ⏱ Complexity Analysis

| Complexity       | Value                 |
| ---------------- | --------------------- |
| Time Complexity  | `O(m * n * min(m,n))` |
| Space Complexity | `O(1)`                |

Explanation:

* Each cell can generate rhombuses of increasing sizes.
* The set maintains only **three values**.

---

# 💻 C++ Implementation

```cpp id="r6p2o7"
class Solution {
public:
    set<int> st;

    void addset(int sum){
        st.insert(sum);
        if(st.size() > 3){
            st.erase(begin(st));
        }
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){

                // side = 0 rhombus
                addset(grid[r][c]);

                for(int side = 1;
                    r - side >= 0 && r + side < m &&
                    c - side >= 0 && c + side < n;
                    side++) {

                    int sum = 0;

                    for(int k = 0; k <= side - 1; k++){
                        sum += grid[r - side + k][c + k];
                        sum += grid[r + k][c + side - k];
                        sum += grid[r + side - k][c - k];
                        sum += grid[r - k][c - side + k];
                    }

                    addset(sum);
                }
            }
        }

        return vector<int>(rbegin(st), rend(st));
    }
};
```

---

# 📌 Example

### Input

```
grid =
[[3,4,5,1,3],
 [3,3,4,2,3],
 [20,30,200,40,10],
 [1,5,5,4,1],
 [4,3,2,2,5]]
```

### Output

```
[228, 216, 211]
```

Explanation:

The algorithm finds all possible rhombus border sums and returns the **top three distinct values**.

---

# 🔑 Key Concepts

* Matrix traversal
* Geometry in grid problems
* Set data structure
* Maintaining top-k elements

---

# 🏷 Tags

* Matrix
* Enumeration
* Geometry
* Set
* Medium

---

