class Solution {
public:

    #define ll long long

    int maximumLength(vector<int>& nums) {

        map<ll,int> mp;

        int one = 0;

        for(int x : nums) {

            if(x == 1)
                one++;

            else
                mp[x]++;
        }

        if(one % 2 == 0)
            one--;

        int ans = max(1, one);

        for(auto it : mp) {

            ll val = it.first;

            int cnt = 0;

            while(mp.count(val) && mp[val] > 1) {

                cnt += 2;

                if(val > 1e9)
                    break;

                val = val * val;
            }

            if(mp[val] == 1)
                cnt++;

            else
                cnt--;

            ans = max(ans, cnt);
        }

        return ans;
    }
};