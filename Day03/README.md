**Leetcode 1545: Find Kth Bit in Nth Binary String**

**📌 Problem Statement**
Given two integers **n** and **k**, return the **kᵗʰ bit** in the **nᵗʰ binary string** (Sₙ).
The sequence of strings is defined recursively:
* **S₁ = "0"**
* For **i > 1**
  **Sᵢ = Sᵢ₋₁ + "1" + reverse(invert(Sᵢ₋₁))**
Where:
* **reverse(x)** → reverses the string `x`
* **invert(x)** → changes `0 → 1` and `1 → 0`
---
  ### Example 1
Input:
```
n = 3, k = 1
```
Output:
```
0
```
Explanation:
```
S1 = "0"
S2 = "011"
S3 = "0111001"
```
The **1st bit** of `S3` is **0**.
---
### Example 2
Input:
```
n = 4, k = 11
Output:
```
1
```
Explanation:
```
S4 = "011100110110001"
```
The **11th bit** of `S4` is **1**.
---
## 🔍 Observations
Length of the string:
```
|Sₙ| = 2ⁿ - 1
```
The **middle element** of every string is always:
```
middle = 2^(n-1)
value = '1'
```
Structure:
```
Sₙ = left + "1" + right
```
Where:
* `left = Sₙ₋₁`
* `right = reverse(invert(Sₙ₋₁))`
---
## 💡 Key Idea
If:
```
k == middle
return:
```
1
```
If:
```
k < middle
```
the answer lies in **Sₙ₋₁**.
If:
```
k > middle
```
it lies in the **mirrored position** of `Sₙ₋₁` and must be **inverted**.
Mirror position formula:
```
mirror = length - k + 1

****## ⚙️ Algorithm****
1. Calculate `length = 2^n - 1`
2. Find the middle index `mid = length / 2 + 1`
3. If `k == mid` → return `'1'`
4. If `k < mid` → recursively find in `(n-1, k)`
5. If `k > mid`:

   * Find mirrored index
   * Recursively solve
   * Invert the result

## ⏱️ Complexity Analysis

**Time Complexity**
O(n)
Each recursive call reduces `n` by 1.
**Space Complexity**
O(n)

Due to recursion stack.
## 🧠 Key Concepts

* Recursion
* Binary string construction
* Divide and conquer
* Bit manipulation

