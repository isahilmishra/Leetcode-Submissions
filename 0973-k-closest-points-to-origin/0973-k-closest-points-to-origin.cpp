class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pair<int,pair<int,int>>>pq;

        for(int i=0; i<n; i++){
            pq.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], {points[i][0],points[i][1]}});

            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            int a=pq.top().second.first;
            int b=pq.top().second.second;

            ans.push_back({a,b});
            pq.pop();
        }
        return ans;
    }
};