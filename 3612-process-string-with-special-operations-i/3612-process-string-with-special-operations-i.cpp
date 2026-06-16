class Solution {
public:
    string processStr(string s) {
        string ans="";
        for(char c: s){
            if(c!='*' && c!='#' && c!='%')ans.push_back(c);
            else if( c=='*'){
                if(!ans.empty()) ans.pop_back();
            }
            else if(c=='#'){
                string temp=ans;
                ans+=temp;
            }
            else{
                reverse(ans.begin(),ans.end());
            }
        }
        return ans;
    }
};