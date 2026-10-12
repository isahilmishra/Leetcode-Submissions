class Solution {
public:
    long long MOD= 1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<int>cnt(32,0);

        for(int x: nums){
            for(int i=0; i<32; i++){
                if(x&(1<<i)) cnt[i]++;
            }
        }
        long long res=0;
        while(k--){
            long long curr=0;
            for(int i=0; i<32; i++){
                
                if(cnt[i]>0){
                   cnt[i]--;

                   curr= (curr | (1<<i));
                }
            }
            res=(res + (curr*curr)%MOD)%MOD;
        }
      return res;
    }
};