class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle= (hour!=12? 30*hour : 0) + minutes/2.0;
        double minAngle= (6*minutes);

        double diff=abs(hourAngle-minAngle);

        return min(diff, 360-diff);
    }
};