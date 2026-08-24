class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int cnt=0;
        int maxCnt=0;
        int i=0; int j=0;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                cnt++;
                i=i+1;
            }
            else{
                j=j+1;
                cnt--;
            }
            maxCnt=max(cnt,maxCnt);
        }
        
        return maxCnt;
    }
};
