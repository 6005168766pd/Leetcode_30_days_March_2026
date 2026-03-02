**Problem Statement**
You are given an n x n binary grid.
In one step, you can swap two adjacent rows.
Return the minimum number of swaps required so that:
For every row i, all cells above the main diagonal are 0.
If it is impossible, return -1.

**Key Insight**
For a valid grid:
Row 0 needs at least n - 1 trailing zeros
Row 1 needs at least n - 2 trailing zeros
Row 2 needs at least n - 3 trailing zeros
...
Row n - 1 needs at least 0 trailing zeros

**So the idea is:**
Count trailing zeros for each row.
For each position i, find a row below it that has enough trailing zeros.
Bring that row up using adjacent swaps.
Count swaps.
If no such row exists → return -1.

📊 Example
Input
grid = [
 [0,0,1],
 [1,1,0],
 [1,0,0]
]
Step 1: Count Trailing Zeros
Row 0 → 0
Row 1 → 1
Row 2 → 2
So:
trailingZeros = [0, 1, 2]
Step 2: Required Trailing Zeros
For n = 3
Trailed Zeroes	Required in (i, No. of trailing zeroes)
0	2
1	1
2	0
Step 3: Arrange Rows
We need row 0 to have ≥ 2 trailing zeros.
Row 0 → 0 ❌
Row 1 → 1 ❌
Row 2 → 2 ✅
Bring row 2 to position 0.
Swaps needed:
Row2 → Row1 (1 swap)
Row1 → Row0 (1 swap)
Total swaps so far = 2
New order:
[2, 0, 1]
Continue checking remaining rows…
Final Answer = 3

**Approach**
1.Count trailing zeros for each row.
2.For each row i:
3.Required = n - i - 1
4.Find row j ≥ i such that trailingZeros[j] ≥ required
5.If not found → return -1
6.Move row j to i using swaps
7.Add (j - i) to answer
8.Return total swaps
