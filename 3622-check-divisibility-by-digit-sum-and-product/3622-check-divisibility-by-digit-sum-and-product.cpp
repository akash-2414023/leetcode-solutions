class Solution {
public:
    bool checkDivisibility(int n) {
        int ori = n;
        int digit_sum = 0;
        int digit_multiply = 1;
        while (n > 0) {
            digit_sum += n % 10;
            digit_multiply *= n % 10;
            n /= 10;
        }
        if (ori % (digit_sum + digit_multiply) == 0) {
            return true;
        } else
            return false;
    }
};