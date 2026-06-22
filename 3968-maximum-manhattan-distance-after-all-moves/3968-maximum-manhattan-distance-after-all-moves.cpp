class Solution {
public:
    int maxDistance(string moves) {
        int x=0,y=0;
        int unds=0;
        for(char c:moves){
            if(c=='U') y++;
            else if(c=='D') y--;
            else if(c=='L') x--;
            else if(c=='R') x++;
            else unds++;
        }

        return abs(x)+abs(y)+unds;
    }
};