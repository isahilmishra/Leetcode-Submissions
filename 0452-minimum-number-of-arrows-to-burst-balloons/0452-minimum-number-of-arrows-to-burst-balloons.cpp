class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        
        sort(points.begin(),points.end(), [](vector<int>&a, vector<int>&b){
            return a[0]<b[0];
        });
        int cnt=1;
        int prevEnd=points[0][1];
        for(int i=1; i<n; i++){
            int s=points[i][0];
            int e=points[i][1];
            if(s>prevEnd){
                cnt++;
                prevEnd=e;
            }
            else{
                prevEnd=min(prevEnd,e);
            }
        }
        return cnt;
    }
};