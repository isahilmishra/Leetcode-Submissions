class Solution {
public:
    int f(int i, int j, vector<vector<int>>&m, vector<vector<int>>&dp){
        int d=m[0].size();
        if(j<0 || j>=d) return 1e9;
        if(i==0) return m[0][j];

        if(dp[i][j]!=INT_MAX) return dp[i][j];

        int s=m[i][j] + f(i-1,j,m,dp);
        int ld=m[i][j]+ f(i-1,j-1,m,dp);
        int rd=m[i][j]+ f(i-1,j+1,m,dp);

        return dp[i][j]= min(s,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m= matrix[0].size();

        vector<vector<int>>dp(n, vector<int>(m, INT_MAX));
        int ans = INT_MAX;

        for (int j = 0; j < m; j++) {
            ans = min(ans, f(n - 1, j, matrix, dp));
        }

        return ans;
    }
};