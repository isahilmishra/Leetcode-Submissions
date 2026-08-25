class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size();
        int l=0,r=0; int cntZero=0;
        int len=0;
        while(r<n){
           if(nums[r]==0) cntZero++;
           while(cntZero>k){
              if(nums[l]==0)cntZero--;
              l++;
           }
           len=max(len,r-l+1);
           r++;
        }
        return len;
    }
};