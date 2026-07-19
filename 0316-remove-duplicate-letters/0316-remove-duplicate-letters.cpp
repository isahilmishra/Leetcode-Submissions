class Solution {
public:
    string removeDuplicateLetters(string s) {
         unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        stack<char>st;
        vector<bool> vis(26,false);
        for(char c : s){
            mp[c]--;

            if(vis[c-'a']) continue;

            while(!st.empty() && st.top()> c && mp[st.top()]>0){
                vis[st.top()-'a']=false;
                st.pop();
            }
            st.push(c);
            vis[c-'a']=true;
        }
        string t;
        while(!st.empty()){
            t+=st.top();
            st.pop();
        }
        reverse(t.begin(),t.end());
        return t;
    }
};