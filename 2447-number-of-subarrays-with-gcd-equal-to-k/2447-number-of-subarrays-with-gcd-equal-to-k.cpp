class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n; i++){
            int res=0;
            for(int j=i; j<n ; j++){
               res= gcd(res,nums[j]);
               
               if(res==k) cnt++;

               if(res<k || res%k!=0) break;
            }
        }
        return cnt;
    }
};