# 🚀 Complement of Base 10 Integer

## 🧩 Problem

Given a **non-negative integer `n`**, return its **bitwise complement**.

The complement of a binary number is obtained by **flipping every bit**:

* `0 → 1`
* `1 → 0`

The result should be returned as a **base-10 integer**.

---

# 📘 Example

### Example 1

Input

```
n = 5
```

Binary representation

```
101
```

Complement

```
010
```

Output

```
2
```

---

# 🧠 Approach 1 — Bit by Bit Construction

### Idea

1. Extract each bit of the number.
2. Flip the bit using `!`.
3. Rebuild the number using powers of `2`.

Example for `5`:

```
5 = 101
Complement = 010
```

### Implementation

```cpp
class Solution {
public:
    int result = 0;
    int counter = 0;

    int bitwiseComplement(int n) {

        if(n == 0) return 1;

        while(n){
            int r = n % 2;
            result += pow(2, counter++) * (!r);
            n /= 2;
        }

        return result;
    }
};
```

### Complexity

| Type  | Complexity |
| ----- | ---------- |
| Time  | O(log n)   |
| Space | O(1)       |

---

# ⚡ Approach 2 — Bit Masking (Optimal)

### Idea

Instead of flipping bits one by one, we create a **mask of all 1s** having the same number of bits as `n`.

Example:

```
n = 5 → 101
mask = 111
```

Then compute:

```
mask ^ n
```

Because XOR flips bits when XORed with `1`.

### Implementation

```cpp
class Solution {
public:
    int bitwiseComplement(int n) {

        if(n == 0) return 1;

        int bits = floor(log2(n)) + 1;
        int mask = (1 << bits) - 1;

        return mask ^ n;
    }
};
```

---

# ⏱ Complexity Analysis

| Complexity       | Value |
| ---------------- | ----- |
| Time Complexity  | O(1)  |
| Space Complexity | O(1)  |

---


⭐ If you found this explanation useful, consider **starring the repository**.
