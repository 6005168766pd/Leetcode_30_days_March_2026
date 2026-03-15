# LeetCode 1415 — The k-th Lexicographical Happy String of Length n

## 🧩 Problem

A **happy string** is a string that:

* Contains only characters **'a'**, **'b'**, and **'c'**
* No two adjacent characters are the same

Given two integers:

* `n` → length of the string
* `k` → lexicographical order

Return the **k-th lexicographically smallest happy string of length `n`**.
If there are fewer than `k` happy strings, return an **empty string**.

---

# 💡 Intuition

We must generate strings using the characters:

```
a, b, c
```

with the condition that **no two adjacent characters are the same**.

Instead of generating all possible strings blindly, we use **Backtracking (DFS)** to build valid strings step by step.

When a string reaches length `n`, we:

* increase a counter
* check if it is the **k-th string**
* store it as the result

To optimize, we **stop recursion early** once the k-th string is found.

---

# 🚀 Approach

1. Start with an empty string.
2. Try adding characters `'a'`, `'b'`, `'c'`.
3. Skip a character if it is the same as the previous character.
4. Use recursion to build the string.
5. Maintain a counter of valid strings.
6. When the counter reaches `k`, store the result and stop further recursion.

---

# ⏱ Complexity Analysis

| Complexity       | Value    |
| ---------------- | -------- |
| Time Complexity  | `O(2^n)` |
| Space Complexity | `O(n)`   |

Explanation:

* At each step we have at most **2 valid choices** (excluding the previous character).

---

# 💻 C++ Implementation

```cpp
class Solution {
public:
    void solve(int n, string &curr, int &count, int k, string &result) {
        if (curr.length() == n) {
            count++;
            if (count == k) {
                result = curr;
            }
            return;
        }

        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!curr.empty() && curr.back() == ch)
                continue;

            curr.push_back(ch);

            solve(n, curr, count, k, result);

            if (!result.empty()) return;

            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        string result = "";
        int count = 0;

        solve(n, curr, count, k, result);

        return result;
    }
};
```

---

# 📌 Example

### Input

```
n = 3
k = 9
```

### Output

```
cab
```

### Explanation

Happy strings of length `3` in lexicographical order:

```
aba
abc
aca
acb
bab
bac
bca
bcb
cab
cac
cba
cbc
```

The **9th string** is `"cab"`.

---

# 🔑 Key Concepts

* Backtracking
* Depth First Search (DFS)
* Lexicographical order
* Early stopping optimization

---

# 🏷 Tags

`Backtracking`
`Recursion`
`String`
`Medium`

---

⭐ If you found this solution helpful, consider **starring the repository**.
