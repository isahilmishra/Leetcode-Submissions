class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(); int m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
         
        int child=0,cookie=0;
        while(child<n && cookie<m){
          if(g[child]<=s[cookie])child++;

          cookie++;
        }
        return child;
    }
};