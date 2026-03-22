class Solution {
public:
    void rotate(vector<vector<int>>& mat){
        int n = mat.size();

        // Transpose
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }

        // Reverse each row
        for(int i = 0; i < n; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        for(int c = 0; c < 4; c++){
            if(mat == target) return true;
            rotate(mat);
        }

        return false;
    }
};
