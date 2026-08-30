class Solution {
public:
    const long long mod = 1e9 + 7;
    long long binExpo(long long base, int expo) {
        if (expo == 0) {
            return 1;
        }

        long long half = binExpo(base, expo / 2);
        
        if (expo % 2 == 0) {
            return (half * half) % mod;
        }

        return ((half * half) % mod * base) % mod;
    }

    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long num = nums[i];
            int width = num % 10;
            long long d = num / 10;
            string s = to_string(d);    
            string x = "";

            for (int j = 0; j < width; j++) {
                x += s[j];
            }

            string y = "";

            for (int j = width; j < s.size(); j++) {
                y += s[j];
            }
            long long x1 = stoll(x);
            long long y1 = stoll(y);

            sum = (sum + binExpo(x1, y1)) % mod;

        }

        return sum;
    }
};