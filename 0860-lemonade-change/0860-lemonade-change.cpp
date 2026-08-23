class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        //sort(bills.begin(),bills.end());
        unordered_map<int,int>mp;
        for(int x: bills){
            if(x==5) mp[x]++;
            else if(x==10){
                if(mp[5]==0) return false;
                else{
                    mp[5]--;
                    mp[10]++;
                }
            }
            else if(x==20){
                if(mp[10]>0 && mp[5]>0){
                    mp[10]--;
                    mp[5]--;
                }
                else if(mp[5]>=3) mp[5]-=3;
                else return false;
            }
        }
       return true;
    }
};