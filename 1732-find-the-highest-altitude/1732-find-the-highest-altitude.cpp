class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>ans;
        ans.push_back(0);
        int cnt=0;
        for(int i=0; i<gain.size(); i++){
             cnt+=gain[i];
             ans.push_back(cnt);
        }
        return *max_element(ans.begin(),ans.end());
    }
};