class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n=start.size();
        vector<pair<int,int>>v;
        for(int i=0; i<n; i++){
            v.push_back({start[i],finish[i]});
        }
        sort(v.begin(),v.end(), [](pair<int,int> &a, pair<int,int> &b){
             return a.second<b.second;
        });
        int cnt=0; int freeTime=-1;
        for(auto it:v){
            int start=it.first;
            int end= it.second;
            if(start>freeTime){
                cnt++;
                freeTime=end;
            }
        }
        return cnt;
    }
};