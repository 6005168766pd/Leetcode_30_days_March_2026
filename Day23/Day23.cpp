class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int mod = 1e9 + 7;
        const long long LIMIT = 1e18;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> maxDP(m, vector<long long>(n));
        vector<vector<long long>> minDP(m, vector<long long>(n));

        maxDP[0][0] = minDP[0][0] = grid[0][0];

        // First Column
        for(int i = 1; i < m; i++){
            long long val = maxDP[i-1][0] * grid[i][0];
            val = max(-LIMIT, min(LIMIT, val));
            maxDP[i][0] = minDP[i][0] = val;
        }

        // First Row
        for(int j = 1; j < n; j++){
            long long val = maxDP[0][j-1] * grid[0][j];
            val = max(-LIMIT, min(LIMIT, val));
            maxDP[0][j] = minDP[0][j] = val;
        }

        // DP
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                long long val = grid[i][j];

                long long a = maxDP[i-1][j] * val;
                long long b = minDP[i-1][j] * val;
                long long c = maxDP[i][j-1] * val;
                long long d = minDP[i][j-1] * val;

                long long mx = max({a, b, c, d});
                long long mn = min({a, b, c, d});

                // clamp
                maxDP[i][j] = max(-LIMIT, min(LIMIT, mx));
                minDP[i][j] = max(-LIMIT, min(LIMIT, mn));
            }
        }

        long long result = maxDP[m-1][n-1];

        if(result < 0) return -1;
        return result % mod;
    }
};
