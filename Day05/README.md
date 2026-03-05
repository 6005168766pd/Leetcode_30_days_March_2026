# LeetCode 1758 — Minimum Changes to Make Alternating Binary String

## Problem

Given a binary string `s` consisting only of `0`s and `1`s, return the **minimum number of operations** needed to make the string **alternating**.

In one operation, you can change any character:

* `0 → 1`
* `1 → 0`

An **alternating string** is a string where no two adjacent characters are the same.

### Valid Alternating Examples

```
010101
101010
```

### Invalid Examples

```
001
110
1001
```

---

# Example

### Input

```
s = "0100"
```

### Output

```
1
```

### Explanation

Changing the last character gives:

```
0101
```

which is an alternating string.

---

# Approach

A binary alternating string can only have **two possible patterns**:

1. **Start with `0`**

```
010101...
```

2. **Start with `1`**

```
101010...
```

Instead of modifying the string, we **compare the input string with both patterns** and count mismatches.

### Steps

1. Traverse the string.
2. For each index:

   * Check expected character for pattern starting with `0`
   * Check expected character for pattern starting with `1`
3. Count mismatches for both patterns.
4. Return the **minimum of the two mismatch counts**.

---

# Algorithm

```
1. Initialize two counters:
   start0 = mismatches if pattern starts with '0'
   start1 = mismatches if pattern starts with '1'

2. Traverse the string:
      if s[i] != expected char for pattern starting with '0'
            start0++

      if s[i] != expected char for pattern starting with '1'
            start1++

3. Return min(start0, start1)
```

---

# Complexity Analysis

| Complexity       | Value |
| ---------------- | ----- |
| Time Complexity  | O(n)  |
| Space Complexity | O(1)  |

* We traverse the string only once.
* Only two counters are used.

---

# C++ Implementation

```cpp
class Solution {
public:
    int minOperations(string s) {
        int start0 = 0;
        int start1 = 0;

        for(int i = 0; i < s.size(); i++) {

            char expected0 = (i % 2 == 0) ? '0' : '1';
            char expected1 = (i % 2 == 0) ? '1' : '0';

            if(s[i] != expected0) start0++;
            if(s[i] != expected1) start1++;
        }

        return min(start0, start1);
    }
};
```

---

# Dry Run

### Input

```
s = "1111"
```

### Pattern 1 → `0101`

```
s:        1 1 1 1
pattern:  0 1 0 1
```

Mismatches = **2**

### Pattern 2 → `1010`

```
s:        1 1 1 1
pattern:  1 0 1 0
```

Mismatches = **2**

### Result

```
min(2,2) = 2
```

---
Time Complexity: O(n)
Space Complexity: O(1)
