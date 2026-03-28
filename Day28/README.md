# 🧩 Construct String from LCP Matrix

## 📌 Problem Overview

You are given an `n x n` matrix `lcp`, where:

* `lcp[i][j]` represents the **length of the longest common prefix** between:

  * suffix starting at index `i`
  * suffix starting at index `j`

Your task is to **reconstruct the original string** using only lowercase English letters (`'a'` to `'z'`).

👉 If it is impossible to construct such a string, return an empty string `""`.

---

## 🧠 Key Observations

### 1. Meaning of LCP

* `lcp[i][j] > 0`
  ⇒ `word[i] == word[j]`

* `lcp[i][j] == 0`
  ⇒ `word[i] != word[j]`

---

### 2. Recursive Property

If characters match:

```
lcp[i][j] = 1 + lcp[i+1][j+1]
```

Else:

```
lcp[i][j] = 0
```

---

## ⚙️ Approach

### Step 1: Initialize Result String

* Create a string `word` of size `n` filled with placeholder (`'$'`)

---

### Step 2: Construct String Greedily

For each index `i`:

#### ✅ Case 1: Match with previous index

* If there exists `j < i` such that:

  ```
  lcp[i][j] > 0
  ```
* Then:

  ```
  word[i] = word[j]
  ```

---

#### 🚫 Case 2: Assign new character

If no such `j` exists:

1. Track forbidden characters:

   * For all `j < i` where:

     ```
     lcp[j][i] == 0
     ```
   * Mark:

     ```
     word[j] as forbidden
     ```

2. Assign the smallest valid character (`'a' → 'z'`) not forbidden

3. If no character is available:

   * Return `""`

---

### Step 3: Validate the Result

* Recompute LCP matrix from constructed string
* Compare with input `lcp`
* Return:

  * valid string ✅
  * else `""` ❌

---

## 🧮 Complexity Analysis

| Operation        | Complexity |
| ---------------- | ---------- |
| Construct string | O(n²)      |
| Recompute LCP    | O(n²)      |
| **Total**        | **O(n²)**  |

---

## 💡 Example

### Input:

```
lcp = [
  [3,0,1],
  [0,2,0],
  [1,0,1]
]
```

### Output:

```
"aba"
```

---

## 🚨 Edge Cases

* All zeros except diagonal → all characters must be different
* Conflicting constraints → return `""`
* Large repeated patterns → reuse characters efficiently

---

## 🧑‍💻 Implementation (C++)

```cpp
class Solution {
public:
    vector<vector<int>> checkLCP(string word){
        int n = word.length();
        vector<vector<int>> lcp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            lcp[i][n-1] = (word[i]==word[n-1])?1:0;
        }
        for(int j=0;j<n;j++){
            lcp[n-1][j] = (word[j]==word[n-1])?1:0;
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(word[i]==word[j]){
                    lcp[i][j] = 1 + lcp[i+1][j+1];
                } else {
                    lcp[i][j] = 0;
                }
            }
        }
        return lcp;
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n,'$');

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(lcp[i][j]!=0){
                    word[i]=word[j];
                    break;
                }
            }

            if(word[i]=='$'){
                vector<bool> forbidden(26,false);

                for(int j=0;j<i;j++){
                    if(lcp[j][i]==0){
                        forbidden[word[j]-'a']=true;
                    }
                }

                for(int idx=0;idx<26;idx++){
                    if(!forbidden[idx]){
                        word[i]=idx+'a';
                        break;
                    }
                }

                if(word[i]=='$') return "";
            }
        }

        return checkLCP(word)==lcp ? word : "";
    }
};
```

---

## 🚀 Key Takeaways

* Convert LCP constraints into:

  * **Equality constraints**
  * **Inequality constraints**
* Use **greedy + validation**
* Always verify constructed string

---

## 📚 Tags

* Greedy
* Strings
* Matrix
* Dynamic Programming
* Constructive Algorithms

---

## ⭐ If you found this helpful, give it a star!
