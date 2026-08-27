class Solution {
public:
    bool f(string& s, int ind, int count, vector<vector<int>>& dp) {
        int n = s.size();
        if (count < 0)
            return false;

        if (ind == n)
            return count == 0;

        if (dp[ind][count] != -1)
            return dp[ind][count];

        bool ans;

        if (s[ind] == '(') {
            ans = f(s, ind + 1, count + 1, dp);
        }
        else if (s[ind] == ')') {
            ans = f(s, ind + 1, count - 1, dp);
        }
        else {
            ans = f(s, ind + 1, count + 1, dp) ||
                  f(s, ind + 1, count - 1, dp) ||
                  f(s, ind + 1, count, dp);
        }

        return dp[ind][count] = ans;
    }

    bool checkValidString(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(s, 0, 0, dp);
    }
};