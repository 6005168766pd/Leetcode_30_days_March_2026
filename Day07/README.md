1784. Check if Binary String Has at Most One Segment of Ones
 Problem Statement

Given a binary string s containing only '0' and '1', return true if the string contains at most one contiguous segment of ones.

Otherwise, return false.

A segment of ones means a continuous group of '1' characters.

 Examples
Example 1
Input: s = "1001"
Output: false

Explanation:
There are two segments of '1' → "1" and "1".

Example 2
Input: s = "110"
Output: true

Explanation:
There is only one segment of '1'.

Example 3
Input: s = "111000"
Output: true

Explanation:
All '1' characters form one continuous segment.

 Key Observation

If the string contains more than one segment of ones, it must contain the pattern:

10...01

In simpler terms:

If "01" appears before all ones finish, another segment will start later.

The simplest check is to verify whether the substring "01" occurs more than once, or directly check whether "01" exists followed by another '1'.

A very clean trick:

If "01" appears in the string → return false

Actually the correct simple check used by most solutions is:

return s.find("01") == -1

But since the string starts with ones (per constraints), detecting a second segment becomes easy.

💡 Approach

Traverse the string.

Count the number of segments of '1'.

If the count exceeds 1, return false.

Otherwise return true.

⚙️ Algorithm
segment = 0

for each character in string:
    if current == '1' and previous == '0'
        segment++

return segment <= 1
 C++ Implementation
class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == '1' && s[i-1] == '0')
                return false;
        }
        return true;
    }
};
⏱ Complexity Analysis
Complexity	Value
Time	O(n)
Space	O(1)

We simply traverse the string once.

 Key Insight

If the string ever transitions from:

1 → 0 → 1

then a second segment of ones exists, which violates the condition.

Single pass traversal	Check transitions
Detect pattern	101 pattern indicates two segments
Efficient	O(n) time
