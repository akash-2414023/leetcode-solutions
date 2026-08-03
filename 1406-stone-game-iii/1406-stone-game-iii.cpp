class Solution {
public:
    int solve(vector<int>& arr, int i,vector<int>& dp) {
        int n = arr.size();
        if (i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int res = INT_MIN;

        res = max(res, arr[i] - solve(arr, i + 1,dp));
        if (i + 1 < n)
            res =max(res, arr[i] + arr[i+1] - solve(arr, i + 2,dp));
        if (i + 2 < n)
            res = max(res, arr[i] + arr[i + 1] + arr[i + 2] - solve(arr, i + 3,dp));

        return dp[i] = res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>dp(n,-1);
        int diff = solve(stoneValue, 0,dp);
        if (diff > 0)
            return "Alice";

        if (diff < 0)
            return "Bob";
        else
            return "Tie";

        return "";
    }
};
