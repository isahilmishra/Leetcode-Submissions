class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int d= accumulate(nums.begin(),nums.end(),0);

        if(d%2 !=0) return false;

        int target=d/2;
        vector<vector<bool>>dp(n,vector<bool>(target+1, false));

        for(int i=0; i<n; i++) dp[i][0]=true;
        if(nums[0]<=target)dp[0][nums[0]]=true;

        for(int i=1; i<n; i++){
            for(int t=1; t<=target; t++){
                bool notTake= dp[i-1][t];
                bool take = false;
                if(t>=nums[i]) take=dp[i-1][t-nums[i]];
                dp[i][t]= take || notTake;
            }
        }
        return dp[n-1][target];
    }
};