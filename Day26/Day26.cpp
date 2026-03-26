class Solution {
public:
    typedef long long ll;
    ll total=0;
    bool checkHorcuts(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        unordered_set<ll> set;
        ll top = 0;
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n;j++){
                set.insert(grid[i][j]);
                top += grid[i][j];
            }
            ll bottom = (total-top);
            ll diff = (top - bottom);

            if(diff==0)  return true;
            if(diff== (ll)grid[0][0])  return true;
            if(diff == (ll)grid[0][n-1])  return true;
            if(diff == (ll)grid[i][0])  return true;
            if(i>0 && n>1 && set.count(diff)){
                return true;
            }

        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
     int m = grid.size();
     int n = grid[0].size();
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            total += grid[i][j];
        }
     }
     // Horizontal Cuts
     if(checkHorcuts(grid)){
        return true;
     }
     reverse(grid.begin(),grid.end());
     if(checkHorcuts(grid)){
        return true;
     }
     reverse(grid.begin(),grid.end());   // converting again to original main
     vector<vector<int>> transposeGrid(n,vector<int>(m));
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            transposeGrid[j][i] = grid[i][j];
        }
     }
     if(checkHorcuts(transposeGrid)){
        return true;
     }
     reverse(transposeGrid.begin(),transposeGrid.end());
     if(checkHorcuts(transposeGrid)){
        return true;
     }   
      return false;
    }
};
