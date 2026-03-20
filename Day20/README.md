# 📊 Minimum Absolute Difference in K×K Subgrid

## 🧩 Problem Statement

Given a 2D integer matrix `grid` of size `m x n` and an integer `k`, compute a result matrix such that:

* Each element `(i, j)` represents the **minimum absolute difference between any two distinct values** inside the `k x k` subgrid starting at `(i, j)`.

---

## ✨ Example

### Input

```
grid = [
  [1, 3, 6],
  [7, 2, 8],
  [9, 4, 5]
]
k = 2
```

### Output

```
[
  [1, 1],
  [2, 1]
]
```

---

## 🚀 Approach

For every possible `k x k` subgrid:

1. Traverse the subgrid and insert elements into a **sorted set (`std::set`)**
2. The set automatically:

   * Removes duplicates
   * Maintains sorted order
3. Iterate through adjacent elements in the set
4. Compute the **minimum absolute difference**

---

## ⚠️ Edge Case

* If a subgrid contains **only one unique element**, then:

  * No valid pair exists
  * Minimum absolute difference = **0**

---

## 💻 Implementation (C++)

```cpp
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m-k+1, vector<int>(n-k+1));

        for(int i=0;i<=m-k;i++){
            for(int j=0;j<=n-k;j++){
                set<int> val;

                for(int r=i;r<i+k;r++){
                    for(int c=j;c<j+k;c++){
                        val.insert(grid[r][c]);
                    }
                }

                // Edge case: only one unique value
                if(val.size() <= 1){
                    result[i][j] = 0;
                    continue;
                }

                int minAbsDiff = INT_MAX;
                auto prev = val.begin();
                auto curr = next(prev);

                while(curr != val.end()){
                    minAbsDiff = min(minAbsDiff, *curr - *prev);
                    prev = curr;
                    curr++;
                }

                result[i][j] = minAbsDiff;
            }
        }
        return result;
    }
};
```

---

## ⏱️ Time Complexity

* Number of subgrids: `(m - k + 1) × (n - k + 1)`
* Each subgrid:

  * Insert `k²` elements → `O(k² log k²)`
  * Traverse set → `O(k²)`

**Overall Complexity:**

```
O((m - k + 1)(n - k + 1) × k² log(k²))
```

---

## 🧠 Space Complexity

* `O(k²)` for storing elements of each subgrid

---

## 🔥 Optimization Ideas

For large constraints, this approach may be slow. Possible improvements:

* Sliding window technique
* Multiset / frequency map
* Avoid rebuilding data structure for each subgrid

---

## 🛠️ Tech Stack

* Language: C++
* Data Structures:

  * `std::set`
  * 2D vectors

---

## 📌 Key Takeaways

* Sorted structures simplify minimum difference problems
* Always handle edge cases (like single unique value)
* Balance between simplicity and performance

---

## 🙌 Contribution

Feel free to fork this repository and improve the solution 🚀
