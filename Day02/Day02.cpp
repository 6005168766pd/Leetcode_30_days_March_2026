class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> endZeroes(n,0); // endzeroes[i] = tells us the no. of zeroes at the end of every row

        for(int i=0;i<n;i++){
            int j=n-1;
            int count=0;
            while(j>=0 && grid[i][j]==0){
                count++;
                j--;
            }
            endZeroes[i]=count;
        }
        // step 2: finding the swaps needed 
        int steps=0;
        for(int i=0;i<n;i++){
            int need = n-i-1;
            int j=i;
            while(j<n && endZeroes[j]<need){
                j++;
            }
            if(j==n){
                return -1;
            }
            steps+=(j-i);      // for two rows, j and i there are (j-i) swaps required
            while(j>i){
                swap(endZeroes[j],endZeroes[j-1]);
                j--;
            }
        }
        return steps;
    }
};
