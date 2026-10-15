class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int totalSum=0;
        for(int x: stones)totalSum+=x;
        int k=totalSum;
        vector<vector<bool>>dp(n,vector<bool>(k+1));

        for(int i=0; i<n; i++)dp[i][0]=true;
        if(stones[0]<=k) dp[0][stones[0]]=true;

        for(int i=1; i<n; i++){
            for(int target=1; target<=k; target++){
                bool notTake= dp[i-1][target];
                bool take=false;
                if(stones[i]<=target) take=dp[i-1][target-stones[i]];

                dp[i][target]= take| notTake;
            }
        }
        // dp[n-1][i--->k] if it exists;
        int mini=1e9;
        for(int i=0; i<=k/2; i++){
            if(dp[n-1][i]){
                int s1=i;
                int s2=k-i;
                mini=min(mini,abs(s1-s2));
            }
        }
        return mini;
    }
};