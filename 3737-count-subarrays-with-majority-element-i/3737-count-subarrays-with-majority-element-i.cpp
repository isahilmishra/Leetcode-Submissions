class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            unordered_map<int,int>mp;
            for(int j=i; j<n; j++){
                mp[nums[j]]++;
                int size=j-i+1;
                int freq=mp[target];
                if(freq>size/2) cnt++;
            }
        }
        return cnt;
    }
};