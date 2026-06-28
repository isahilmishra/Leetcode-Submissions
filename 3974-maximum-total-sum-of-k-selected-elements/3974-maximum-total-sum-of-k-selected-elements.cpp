class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long totalSum=0;
        for(int i=n-1; i>=0; i--){
            if(k>0 && mul>0){
                 long long d= nums[i];
                 totalSum+=max(d,d*mul);
                 k--; mul--;
            }
            else if(k>0){
                totalSum+=nums[i];
                k--;
            }
            else break;
        }
        return totalSum;
    }
};