class Solution {
public:
    double binExpo(double x, long long expo) {
        if (expo == 0)
            return 1.0;

        double half = binExpo(x, expo / 2);

        if (expo % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }

    double myPow(double x, int n) {
        long long expo = n;

        if (expo < 0) {
            x = 1 / x;
            expo = -expo;
        }

        return binExpo(x, expo);
    }
};