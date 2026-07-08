class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        /*vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            long long sum = 0;
            long long x = 0;
            for (int j = l; j <= r; j++) {
                int d = s[j] - '0';
                sum += d;
                if (d > 0) {
                    x = (x * 10 + d) % mod;
                }
            }
            ans.push_back((x * sum) % mod);
        }
        return ans;*/
        int MOD = 1e9 + 7;
        int n = s.size();
        vector<int> nonZeroCount(n, 0);
        vector<long long> numberUpTo(n, 0);
        vector<long long> digitSumUpTo(n, 0);
        vector<long long> pow10(n + 1, 0);

        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        nonZeroCount[0] = (s[0] != '0') ? 1 : 0;
        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            nonZeroCount[i] = nonZeroCount[i - 1] + ((digit != 0) ? 1 : 0);
        }

        numberUpTo[0] = s[0] - '0';
        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            if (digit != 0) {
                numberUpTo[i] = ((numberUpTo[i - 1] * 10) + digit) % MOD;
            } else {
                numberUpTo[i] = numberUpTo[i - 1];
            }
        }

        digitSumUpTo[0] = s[0] - '0';
        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            digitSumUpTo[i] = digitSumUpTo[i - 1] + digit;
        }

        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            long long sum =
                digitSumUpTo[r] - ((l == 0) ? 0 : digitSumUpTo[l - 1]);

            int numBefore = (l == 0) ? 0 : numberUpTo[l - 1];

            int k = nonZeroCount[r] - ((l == 0) ? 0 : nonZeroCount[l - 1]);

            long long x =
                (numberUpTo[r] - (numBefore * pow10[k] % MOD) + MOD) % MOD;

            ans[i] = (int)((x * sum) % MOD);
        }
        return ans;
    }
};
/*vector<int> ans;
for (int i = 0; i < queries.size(); i++) {
    int l = queries[i][0];
    int r = queries[i][1];
    long long sum = 0;
    long long x = 0;
    for (int j = l; j <= r; j++) {
        int d = s[j] - '0';
        sum += d;
        if (d > 0) {
            x = (x * 10 + d) % mod;
        }
    }
    ans.push_back((x * sum) % mod);
}
return ans;*/
