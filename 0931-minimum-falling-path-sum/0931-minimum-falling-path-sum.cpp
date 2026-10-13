class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j=0; j<m; j++){
             dp[n-1][j]=matrix[n-1][j];
        }
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<m; j++){
                int u=matrix[i][j]+dp[i+1][j];

                int l=INT_MAX; int r=INT_MAX;

                if(j>0) l=matrix[i][j]+dp[i+1][j-1];
                if(j+1<m) r=matrix[i][j]+dp[i+1][j+1];

                dp[i][j]=min({u,l,r});
            }
        }
        int ans=INT_MAX;
        for(int j=0; j<m; j++){
            ans=min(ans,dp[0][j]);
        }
        return ans;
    }
};