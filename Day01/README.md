**LeetCode 1689: Partitioning Into Minimum Number Of Deci-Binary Numbers**
**Problem Statement:**
A deci-binary number is a number that contains only digits 0 and 1.

You are given a decimal number n as a string.
Return the minimum number of positive deci-binary numbers needed so that their sum equals n.

Key Insight
Each deci-binary number can contribute:
At most 1 at any digit position.
So if a digit in n is d,
we need at least d deci-binary numbers contributing 1 at that position.
**Therefore:**
The answer is simply the maximum digit in the string.

📊 Example
Input:
n = "32"
Maximum digit = 3
So the answer is:3

🔎 Step-by-Step Conversion of 32 to 0
Let’s actually construct the deci-binary numbers.
We need 3 deci-binary numbers (because max digit = 3).
Step 1:
Take 1 from each non-zero digit.
  32
- 11
------
  21
First deci-binary number: 11
Step 2:
Again subtract 1 from each non-zero digit.
  21
- 11
------
  10
Second deci-binary number: 11
Step 3:
Subtract again.
  10
- 10
------
  00
Third deci-binary number: 10
Final Decomposition:
32 = 11 + 11 + 10
Total deci-binary numbers used = 3

 **Approach**
1.Initialize maxDigit = 0
2.Traverse the string
3.For each character:
4.Convert to integer
5.Update maximum
6.Return maximum digit


