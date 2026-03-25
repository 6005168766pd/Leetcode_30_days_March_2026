class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<long long> rowSum(m,0);
        vector<long long> colSum(n,0);
        long long total=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                total += grid[i][j];
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }
        if(total%2!=0){     // bcz if the total sum is odd then the sum can neither be divided into two parts
            return false;
        }
        long long upperSum=0;
        for(int i=0;i<m-1;i++){
            upperSum += rowSum[i];
            if(upperSum == (total-upperSum))  return true;
        }
        long long leftSum=0;
        for(int j=0;j<n-1;j++){
            leftSum += colSum[j];
            if(leftSum == (total-leftSum)) return true;
        }
        return false;
    }
};
