class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt1=0,cnt2=0;
        for(char c:s){
            if(c=='(')cnt1++;
            else if(cnt1>0) cnt1--;
            else cnt2++;
        }
        return cnt1+cnt2;
    }
};