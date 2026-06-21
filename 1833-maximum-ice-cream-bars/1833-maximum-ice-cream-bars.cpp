class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        sort(costs.begin(), costs.end());
        int cnt=0;
        for(int x: costs){
            if(x<=coins){
                cnt++;
                coins-=x;
            }
        }
        return cnt;
    }
};