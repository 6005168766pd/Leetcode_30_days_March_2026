class Solution {
public:
set<int> st;
    void addset(int sum){
        st.insert(sum);
        if(st.size()>3){
           st.erase(begin(st));
        }
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                // 0 side rhombus
                addset(grid[r][c]);
                for(int side=1;r-side>=0 && r+side<m && c-side>=0 && c+side<n;side++){
                    int sum=0;
                    for(int k=0;k<=side-1;k++){
                        sum+=grid[r-side+k][c+k];
                        sum+=grid[r+k][c+side-k];
                        sum+=grid[r+side-k][c-k];
                        sum+=grid[r-k][c-side+k];
                    }
                    addset(sum);
                }
            }
        }
        return vector<int> (rbegin(st),rend(st));
    }
};
