class Solution {
  public:
    vector<int>convertToBinary(int n){
        vector<int>res;
        while(n>0){
            if(n%2==1) res.push_back(1);
            else res.push_back(0);
            n/=2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    int maxConsecutiveOnes(int n) {
        // code here
        vector<int>arr= convertToBinary(n);
        int t=arr.size();
        int l=0; int r=0;
        int maxLen=0;
        while(r<t){
            if(arr[r]==0){
                l=r+1;
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};
