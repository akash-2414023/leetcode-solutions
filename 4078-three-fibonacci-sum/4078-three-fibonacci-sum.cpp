
class Solution {
public:
    bool threeFibonacciSum(int n) {
        long long a = 0;
        long long b = 1;

        for (int i = 0; i < 50; i++) {
            long long c = a + b;
            long long sum = a + b + c;
            if (sum == n) {
                return true;
            }
            if(sum > n){
                return false;
            }

            a = b;
            b = c;
        }

        return false;
    }
};
