class Solution {
public:
    int maximumProduct(vector<int>& nums) {
         int n=nums.size();
        sort (nums.begin(),nums.end());
        int ans=0;
            int option1=nums[0]*nums[1]*nums[n-1];
        int option2=nums[n-1]*nums[n-2]*nums[n-3];
      ans=max(option1, option2);
        return ans;
    }
};