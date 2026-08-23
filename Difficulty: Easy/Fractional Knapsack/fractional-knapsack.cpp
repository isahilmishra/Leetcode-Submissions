class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
       vector<pair<double,pair<int,int>>>p;
       int n=val.size();
       for(int i=0; i<n; i++){
           double c= (double)val[i]/(double)wt[i];
           p.push_back({c,{val[i],wt[i]}});
       }
       sort(p.begin(),p.end(),greater<>());
       double ans=0;
       
       for(auto it : p){
          double ratio= it.first;
          int value= it.second.first;
          int weight= it.second.second;
          
          if(capacity>weight){
              ans+=value; capacity-=weight;
          }
          else {
              ans+= ratio*capacity;
              break;
          }
       }
       return ans;
    }
};
