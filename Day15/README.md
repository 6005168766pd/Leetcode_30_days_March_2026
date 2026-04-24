# LeetCode 1622 — Fancy Sequence

##  Problem Overview

Design a data structure that supports the following operations on a sequence of integers:

1. **append(val)**
   Append an integer `val` to the end of the sequence.

2. **addAll(inc)**
   Add `inc` to every element of the sequence.

3. **multAll(m)**
   Multiply every element of the sequence by `m`.

4. **getIndex(idx)**
   Return the value at index `idx` (0-indexed).
   If `idx` is out of bounds, return `-1`.

All results must be returned **modulo (10^9 + 7)**.

---

# 💡 Intuition

Applying `addAll` or `multAll` to every element directly would take **O(n)** time per operation, which is too slow.

Instead, we use **lazy mathematical transformations**.

We maintain two global variables:

* `mul` → current multiplication factor
* `add` → current addition factor

Every stored element is kept in a **normalized form** so we can apply global operations efficiently.

Actual value formula:

```
actual_value = stored_value * mul + add
```

This allows us to update the entire sequence in **constant time**.

---

# 🚀 Approach

### Append Operation

When inserting a new value, we normalize it relative to current transformations:

```
stored_value = (val - add) * modular_inverse(mul)
```

This ensures future transformations apply correctly.

---

### Add Operation

Increase the global addition value:

```
add = (add + inc) % MOD
```

---

### Multiply Operation

Update both transformation variables:

```
mul = (mul * m) % MOD
add = (add * m) % MOD
```

---

### Get Index

Retrieve the stored value and apply transformations:

```
value = stored_value * mul + add
```

---

# ⏱ Complexity Analysis

| Operation | Time Complexity |
| --------- | --------------- |
| append    | O(1)            |
| addAll    | O(1)            |
| multAll   | O(1)            |
| getIndex  | O(1)            |

Space Complexity: **O(n)**

---

# 💻 C++ Implementation

```cpp
class Fancy {
public:
    const long long MOD = 1e9 + 7;
    vector<long long> arr;
    long long mul = 1, add = 0;

    long long modInverse(long long x) {
        long long res = 1, p = MOD - 2;
        while (p) {
            if (p & 1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            p >>= 1;
        }
        return res;
    }

    Fancy() {}

    void append(int val) {
        long long inv = modInverse(mul);
        long long normalized = ((val - add + MOD) % MOD * inv) % MOD;
        arr.push_back(normalized);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;
        return (arr[idx] * mul + add) % MOD;
    }
};
```

---

# 📌 Example

```
Fancy fancy = new Fancy();

fancy.append(2);     → [2]
fancy.addAll(3);     → [5]
fancy.append(7);     → [5,7]
fancy.multAll(2);    → [10,14]

fancy.getIndex(0) → 10
```

---

# 🔑 Key Concepts

* Lazy transformation technique
* Modular arithmetic
* Modular inverse using fast exponentiation
* Efficient data structure design

---
* Modular Arithmetic
* Hard
