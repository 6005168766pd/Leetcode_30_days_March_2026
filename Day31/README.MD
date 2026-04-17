# Leetcode 3474: Lexicographically Smallest Generated String

##  Problem Statement

You are given two strings:

- `str1` consisting of characters `'T'` and `'F'`
- `str2` consisting of lowercase English letters

Your task is to construct a string `word` such that:

- For every index `i` where `str1[i] == 'T'`, the substring of `word` starting at `i` must **match `str2` exactly**
- For every index `i` where `str1[i] == 'F'`, the substring of `word` starting at `i` must **NOT match `str2`**

If it is possible to construct such a string, return it. Otherwise, return an empty string `""`.

---

##  Intuition

We build the result string step by step:

1. **Initialize** a result string `word` of size `n + m - 1` filled with `'$',` representing unassigned positions.

2. **Handle `'T'` positions**:
   - For every index `i` where `str1[i] == 'T'`, enforce that `str2` must start at index `i` in `word`
   - If a conflict occurs (different characters at same position), return `""`

3. **Fill remaining positions**:
   - Replace all `'$',` with `'a'` (default character)
   - Mark these positions as changeable

4. **Handle `'F'` positions**:
   - If substring at index `i` matches `str2`, we must break it
   - Change one of the characters (preferably from rightmost changeable position)

---

## ⚙️ Approach

- Use a helper function `isSame()` to check substring equality
- Maintain a `canChange[]` array to track flexible positions
- Carefully handle overlaps and conflicts

---

## 💻 Code

```cpp
class Solution {
public:
    bool isSame(string &word, string &str2, int i , int m){
        if(i + m > word.size()) return false;

        for(int j=0;j<m;j++){
            if(word[i] != str2[j]){
                return false;
            }
            i++;
        }
        return true;
    }

    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        int N = n + m - 1;
        string word(N,'$');
        vector<bool> canChange(N, false);

        // Process 'T'
        for(int i=0;i<n;i++){
            if(str1[i]=='T'){
                int k = i;
                for(int j=0;j<m;j++){
                    if(word[k] != '$' && word[k] != str2[j]){
                        return "";
                    }
                    word[k] = str2[j];
                    k++;
                }
            }
        }

        // Fill remaining with 'a'
        for(int i=0;i<N;i++){
            if(word[i]=='$'){
                word[i]='a';
                canChange[i]=true;
            }
        }

        // Process 'F'
        for(int i=0;i<n;i++){
            if(str1[i]=='F'){
                if(isSame(word,str2,i,m)){
                    bool changed = false;
                    for(int k=i+m-1; k>=i;k--){
                        if(canChange[k]){
                            word[k]='b';
                            changed=true;
                            break;
                        }
                    }
                    if(!changed){
                        return "";
                    }
                }
            }
        }
        return word;
    }
};
Complexity Analysis
Time Complexity: O(n * m)
Each position may require checking a substring of length m
Space Complexity: O(n + m)
For result string and auxiliary array
