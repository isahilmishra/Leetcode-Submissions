class Solution {
public:
    int getDigitSum(int x){
        int sum=0;
        while(x>0){
            sum+=x%10;
            x/=10;
        }
        return sum;
    }
    
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>t(nums.begin(),nums.end());

        sort(t.begin(),t.end(), [this](int a, int b){
            int aSum= getDigitSum(a);
            int bSum= getDigitSum(b);

            if(aSum!=bSum)return aSum<bSum;

            return a<b;
        });
       unordered_map<int,int>mp;
       for(int i=0; i<n; i++){
         mp[nums[i]]=i;
       }

       int cnt=0;
       for(int i=0; i<n; i++){
          int expVal=t[i];
          int curVal=nums[i];

          if(expVal==curVal) continue;

          int idx= mp[expVal];
          nums[i]=expVal;
          nums[idx]=curVal;
          
          mp[curVal] = idx;
          mp[expVal] = i;
          cnt++;
       }
       return cnt;
    }
};