class Solution {
public:
    string ans = "";

    void solve(string &s, string &target, vector<bool>& used, string &curr) {

        int n = s.size();

        // Already greater than target
        if (curr > target.substr(0, curr.size())) {
            string temp = curr;

            for (int i = 0; i < n; i++) {
                if (!used[i])
                    temp += s[i];
            }

            sort(temp.begin() + curr.size(), temp.end());

            if (ans == "" || temp < ans)
                ans = temp;

            return;
        }

        if (curr.size() == n) {
            if (curr > target && (ans == "" || curr < ans))
                ans = curr;

            return;
        }

        for (int i = 0; i < n; i++) {

            if (used[i])
                continue;

            // Skip duplicates
            if (i > 0 && s[i] == s[i - 1] && !used[i - 1])
                continue;

            // If smaller than target at this position,
            // this branch can NEVER become greater.
            if (s[i] < target[curr.size()])
                continue;

            used[i] = true;
            curr += s[i];

            solve(s, target, used, curr);

            curr.pop_back();
            used[i] = false;
        }
    }

    string lexGreaterPermutation(string s, string target) {

        sort(s.begin(), s.end());

        vector<bool> used(s.size(), false);
        string curr = "";

        solve(s, target, used, curr);

        return ans;
    }
};