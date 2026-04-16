 Equal Sum Grid Partition I : Leetcode 3546
 Problem Statement

Given a 2D integer grid, determine whether it is possible to partition the grid into two parts such that the sum of elements in both parts is equal.

You can partition the grid:

Horizontally (between two rows), or
Vertically (between two columns)

Return true if such a partition exists, otherwise return false.

🧠 Intuition

The key idea is simple:

Compute the total sum of the grid.
If the sum is odd, equal partition is impossible.
Otherwise, check if we can split:
Row-wise → top part = bottom part
Column-wise → left part = right part

Instead of recomputing sums repeatedly, we precompute row and column sums for efficiency.

⚙️ Approach
Step 1: Precompute Sums
rowSum[i] → sum of all elements in row i
colSum[j] → sum of all elements in column j
Also calculate total sum of grid
Step 2: Check Total Sum
If total % 2 != 0 → return false
Step 3: Row-wise Partition
Traverse rows and keep adding rowSum
Stop before last row (m-1) to ensure valid partition

If:

upperSum == total - upperSum

→ return true

Step 4: Column-wise Partition
Same idea using colSum
Stop before last column (n-1)
Step 5: Return Result
If no partition found → return false
💻 Code (C++)
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<long long> rowSum(m, 0);
        vector<long long> colSum(n, 0);

        long long total = 0;

        // Compute total, row sums, and column sums
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                total += grid[i][j];
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }

        // If total sum is odd, partition is impossible
        if(total % 2 != 0) return false;

        // Check horizontal partition
        long long upperSum = 0;
        for(int i = 0; i < m - 1; i++){
            upperSum += rowSum[i];
            if(upperSum == total - upperSum) return true;
        }

        // Check vertical partition
        long long leftSum = 0;
        for(int j = 0; j < n - 1; j++){
            leftSum += colSum[j];
            if(leftSum == total - leftSum) return true;
        }

        return false;
    }
};
⏱️ Complexity Analysis
Time Complexity:
O(m × n)
(single pass to compute sums + linear scans)
Space Complexity:
O(m + n)
(for row and column sum arrays)
🔥 Key Insights
Precomputing row & column sums avoids redundant calculations.
Always check odd total sum early to save time.
Partition must leave at least one row/column on both sides, hence m-1 and n-1.
✅ Example

Input:

grid = [
  [1, 2],
  [3, 0]
]

Total Sum = 6 → Half = 3

Horizontal split after row 0:
Top = 1+2 = 3
Bottom = 3+0 = 3 ✅

Output: true
