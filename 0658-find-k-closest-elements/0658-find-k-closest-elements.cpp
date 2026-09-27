class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(int i : arr){
            pq.push({abs(x-i),i});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            int b=pq.top().second;
            ans.push_back(b);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};