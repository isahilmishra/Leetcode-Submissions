class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int d= accumulate(nums.begin(),nums.end(),0);

        if(d%2 !=0) return false;

        int target=d/2;
        vector<int>prev(target+1), curr(target+1);

        prev[0]=curr[0]=true;
        if(nums[0]<=target)prev[nums[0]]=true;

        for(int i=1; i<n; i++){
            for(int t=1; t<=target; t++){
                bool notTake= prev[t];
                bool take = false;
                if(t>=nums[i]) take=prev[t-nums[i]];
                curr[t]= take || notTake;
            }
            prev=curr;
        }
        return prev[target];
    }
};