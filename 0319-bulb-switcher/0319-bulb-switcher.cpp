class Solution {
public:
    int bulbSwitch(int n) {
        int low = 1;
        int high = n/2;
        if(n == 1)
            return 1;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(mid * mid > n){
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        return high;
    }
};