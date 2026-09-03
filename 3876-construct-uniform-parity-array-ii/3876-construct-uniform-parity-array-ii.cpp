class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int cnt=0; int mini=INT_MAX;
        for(int x: nums1){
            if(x&1){
                cnt++;
                mini=min(x,mini);
            }
        }
        if(cnt==0) return true;
        else{
            for(int i=0; i<nums1.size(); i++){
                if((nums1[i]-mini)<0) return false;
            }
        }
       return true;
    }
};