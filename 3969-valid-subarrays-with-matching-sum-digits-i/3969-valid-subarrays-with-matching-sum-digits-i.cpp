class Solution {
public:
    bool checkSum(long long sum, int x){
        sum = abs(sum);

        int last = sum % 10;

        while(sum >= 10)
            sum /= 10;

        int first = sum;

        return (first == x && last == x);
    }
    int countValidSubarrays(vector<int>& nums, int x) {
         int n = nums.size();

        long long ans = 0;

        for(int i = 0; i < n; i++){

            long long sum = 0;

            for(int j = i; j < n; j++){

                sum += nums[j];

                if(checkSum(sum, x))
                    ans++;
            }
        }

        return ans;
    }
};