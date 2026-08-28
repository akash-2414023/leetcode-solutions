class Solution {
public:
    int solve(int i, int j, string& s, string& t, int n, int m,
              vector<vector<int>>& dp) {
        if (i == n && j != m)
            return 0;

        if (j == m) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == t[j]) {
            int take = solve(i + 1, j + 1, s, t, n, m, dp);
            int notTake = solve(i + 1, j, s, t, n, m, dp);
            return dp[i][j] = take + notTake;
        }
        return dp[i][j] = solve(i + 1, j, s, t, n, m, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, s, t, n, m, dp);
    }
};