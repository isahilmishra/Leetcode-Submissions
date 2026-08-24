class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        int n=bt.size();
        sort(bt.begin(),bt.end());
        
        int waitingTime=0;
        int currTime=0;
        for(int i=0; i<n; i++){
             waitingTime+=currTime;
            currTime+=bt[i];
           
        }
      
       
       return waitingTime/n;
    }
};