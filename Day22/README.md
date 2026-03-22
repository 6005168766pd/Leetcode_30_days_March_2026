# 🔄 Find Rotation

## 🧩 Problem Statement

Given two **n × n** binary matrices `mat` and `target`, return `true` if `mat` can be rotated in 90-degree clockwise steps to match `target`. Otherwise, return `false`.

You can rotate the matrix **0°, 90°, 180°, or 270°**.

---

## 📌 Example

```
Input:
mat = [[0,1],
       [1,0]]

target = [[1,0],
          [0,1]]

Output:
true
```

---

## 💡 Approach

To rotate a matrix by **90° clockwise**, follow two steps:

1. **Transpose the matrix**
   - Convert rows into columns  
2. **Reverse each row**
   - This completes the rotation  

---

## 🔁 Strategy

- Perform up to **4 rotations**
- After each rotation:
  - Check if `mat == target`
- If a match is found → return `true`
- If no match after all rotations → return `false`

---

## ⚙️ Algorithm

```
Repeat 4 times:
    If mat == target → return true
    Rotate mat by 90°
Return false
```

---

## 🧠 Complexity Analysis

- **Time Complexity:** O(n²)  
- **Space Complexity:** O(1)

---

## 🧾 Implementation (C++)

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& mat){
        int n = mat.size();

        // Step 1: Transpose
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }

        // Step 2: Reverse each row
        for(int i = 0; i < n; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        for(int i = 0; i < 4; i++){
            if(mat == target) return true;
            rotate(mat);
        }

        return false;
    }
};
```

---

## 🚀 Key Takeaways

- Matrix rotation can be done **in-place**
- Transpose + Reverse = **90° rotation**
- Only **4 rotations** are needed
- Direct comparison simplifies implementation

---

## 🏷️ Tags

`Matrix` `Array` `Simulation` `Rotation`
