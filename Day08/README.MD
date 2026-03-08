1980. Find Unique Binary String
🧩 Problem Statement

Given an array of n unique binary strings nums, where each string has length n, return a binary string of length n that does not appear in nums. If multiple answers exist, return any of them.

Example
Input: nums = ["01","10"]
Output: "00"
Input: nums = ["00","01"]
Output: "11"
Constraints

n == nums.length

1 ≤ n ≤ 16

nums[i].length == n

nums[i] contains only '0' or '1'

All strings in nums are unique

💡 Approach (Cantor’s Diagonalization)

The most optimal way to solve this problem is using Cantor’s Diagonal Trick.

Key Idea

Construct a new binary string result such that:

result[i] ≠ nums[i][i]

This ensures the new string differs from every string in the array at least at one position.

Steps

Iterate from 0 → n-1.

If nums[i][i] == '0', append '1'.

Otherwise append '0'.

Return the constructed string.

This guarantees the resulting string cannot exist in the given list.

⚙️ Algorithm
for i from 0 to n-1
    if nums[i][i] == '0'
        result += '1'
    else
        result += '0'
return result
💻 C++ Implementation
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result = "";

        for(int i = 0; i < n; i++) {
            if(nums[i][i] == '0')
                result += '1';
            else
                result += '0';
        }

        return result;
    }
};
⏱ Complexity Analysis
Complexity	Value
Time	O(n)
Space	O(n)

We iterate through the list only once.

The constructed string has length n.

🧠 Key Insight

Since the constructed string differs from:

nums[0] at index 0

nums[1] at index 1

nums[2] at index 2

...

it cannot match any string in the array.

🚀 Alternative Approach

Another approach is:

Generate all binary numbers from 0 → 2ⁿ - 1

Store given strings in a hash set

Return the first binary string not in the set

However this approach has complexity:

Time: O(2^n * n)
