//C++ Solution


class Solution {
public:
    int helper(int i, int j, int n, int m, vector<vector<int>> &dp, vector<vector<int>>& matrix) {
        if(i<0 || j<0 || i>=n || j>=m) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 1;

        if(i+1 < n && matrix[i+1][j] > matrix[i][j]) {
            ans = max(ans, 1 + helper(i+1, j, n, m, dp, matrix));
        } 
        if(j+1 < m && matrix[i][j+1] > matrix[i][j]) {
            ans = max(ans, 1 + helper(i, j+1, n, m, dp, matrix));
        } 
        if(i-1 >= 0 && matrix[i-1][j] > matrix[i][j]) {
            ans = max(ans, 1 + helper(i-1, j, n, m, dp, matrix));
        } 
        if(j-1 >=0 && matrix[i][j-1] > matrix[i][j]) {
            ans = max(ans, 1 + helper(i, j-1, n, m, dp, matrix));
        } 

        dp[i][j] = ans;
        return ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));

        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans = max(ans, helper(i, j, n, m, dp, matrix));
            }
        }

        return ans;
    }
};
