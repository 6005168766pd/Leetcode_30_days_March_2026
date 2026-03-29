# 🔍 LeetCode 2839 - Check if Strings Can be Made Equal With Operations I

## 🧩 Problem Statement

Given two strings `s1` and `s2`, both of length 4, determine if they can be made equal using the following operation any number of times:

### 🔁 Allowed Operation:

* Swap characters at indices `i` and `j` such that:

  * `i < j`
  * `(j - i) % 2 == 0`

👉 This means:

* Even indices (`0, 2`) can swap among themselves
* Odd indices (`1, 3`) can swap among themselves

---

## 💡 Core Insight

Since swapping is only allowed within:

* Even positions
* Odd positions

👉 We can treat **even and odd indices independently**

---

# 🚀 Approaches

---

## 🧠 Approach 1: Direct Comparison (Tricky O(1))

### Idea:

Manually check all possible valid swaps between:

* Even indices
* Odd indices

### Code:

```cpp
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool condition1 = (s1[0]==s2[0] && s1[2]==s2[2]) ||
                          (s1[0]==s2[2] && s1[2]==s2[0]);

        bool condition2 = (s1[1]==s2[1] && s1[3]==s2[3]) ||
                          (s1[1]==s2[3] && s1[3]==s2[1]);

        return condition1 && condition2;
    }
};
```

### ✅ Complexity

* Time: `O(1)`
* Space: `O(1)`

### ⚠️ Note

* Works only because string length is fixed (4)
* Not scalable

---

## 🔄 Approach 2: Sorting Even & Odd Positions

### Idea:

* Extract characters at:

  * Even indices → sort
  * Odd indices → sort
* Compare both groups

### Code:

```cpp
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string evens1 = "", odds1 = "";
        string evens2 = "", odds2 = "";

        evens1 += s1[0];
        evens1 += s1[2];

        evens2 += s2[0];
        evens2 += s2[2];

        odds1 += s1[1];
        odds1 += s1[3];

        odds2 += s2[1];
        odds2 += s2[3];

        sort(evens1.begin(), evens1.end());
        sort(evens2.begin(), evens2.end());
        sort(odds1.begin(), odds1.end());
        sort(odds2.begin(), odds2.end());

        return evens1 == evens2 && odds1 == odds2;
    }
};
```

### ✅ Complexity

* Time: `O(1)` (since length = 4)
* Space: `O(1)`

### 👍 Pros

* Cleaner and more intuitive
* Easily extendable

---

## ⚡ Approach 3: Frequency Count (Optimal & Scalable)

### Idea:

* Count frequency difference for:

  * Even indices
  * Odd indices
* If both frequency arrays match → valid

### Code:

```cpp
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<int> even(26, 0);
        vector<int> odd(26, 0);

        for (int i = 0; i < 4; i++) {
            if (i % 2 == 0) {
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            } else {
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (even[i] != 0 || odd[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
```

### ✅ Complexity

* Time: `O(n)` → generalizable
* Space: `O(1)` (26 letters)

### 🚀 Best Choice

* Most scalable
* Preferred in interviews

---

## 🧪 Example

### Input:

```
s1 = "tibm"
s2 = "itmb"
```

### Analysis:

* Even indices:

  * s1 → {t, b}
  * s2 → {i, m} ❌
* Odd indices:

  * s1 → {i, m}
  * s2 → {t, b} ❌

### Output:

```
false
```

---

## 🎯 Summary

| Approach          | Time | Space | Notes                   |
| ----------------- | ---- | ----- | ----------------------- |
| Direct Comparison | O(1) | O(1)  | Hardcoded, not scalable |
| Sorting           | O(1) | O(1)  | Clean and intuitive     |
| Frequency Count   | O(n) | O(1)  | Best for interviews     |

---

## 🏷️ Tags

* Strings
* Greedy
* Counting
* Sorting

---

💬 *Pro Tip: Whenever swaps are restricted within groups, think in terms of independent buckets (like even/odd indices).*
