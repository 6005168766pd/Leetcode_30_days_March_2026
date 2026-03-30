🧩 LeetCode 2840 - Check if Strings Can be Made Equal With Operations II
📌 Problem Statement

You are given two strings s1 and s2 of equal length.

You can perform the following operation any number of times:

Choose any two indices i and j such that:
i < j
(j - i) % 2 == 0
Swap the characters at positions i and j.

👉 Return true if you can make s1 equal to s2 after any number of operations, otherwise return false.

💡 Key Insight

The operation allows swapping characters only between indices having the same parity:

Even indices can swap among themselves.
Odd indices can swap among themselves.

👉 So, characters at:

Even positions form one independent group.
Odd positions form another independent group.
🧠 Approach
Separate characters of both strings into:
Even-indexed characters
Odd-indexed characters
Sort both groups independently for both strings.
Compare:
Sorted even characters of s1 with s2
Sorted odd characters of s1 with s2
If both match → return true, else false.
⚙️ Algorithm
1. Initialize 4 strings:
   - s1_even, s1_odd
   - s2_even, s2_odd

2. Traverse both strings:
   - If index is even → add to even string
   - Else → add to odd string

3. Sort all four strings

4. Compare:
   - s1_even == s2_even AND s1_odd == s2_odd

5. Return result
💻 C++ Implementation
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string s1_even = "", s1_odd = "";
        string s2_even = "", s2_odd = "";
        
        for(int i = 0; i < s1.size(); i++) {
            if(i % 2 == 0) {
                s1_even += s1[i];
                s2_even += s2[i];
            } else {
                s1_odd += s1[i];
                s2_odd += s2[i];
            }
        }
        
        sort(s1_even.begin(), s1_even.end());
        sort(s1_odd.begin(), s1_odd.end());
        sort(s2_even.begin(), s2_even.end());
        sort(s2_odd.begin(), s2_odd.end());
        
        return s1_even == s2_even && s1_odd == s2_odd;
    }
};
⏱️ Complexity Analysis
Type	Complexity
Time Complexity	O(n log n)
Space Complexity	O(n)
🔍 Example
Input
s1 = "abcdba"
s2 = "cabdab"
Process
Even indices:
s1 → a, c, b
s2 → c, b, b
Odd indices:
s1 → b, d, a
s2 → a, d, a

After sorting:

Even: match ❌
Odd: match ❌
Output
false
