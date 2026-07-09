class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,vector<vector<int>>& queries) {
        vector<int> comp(n);
        comp[0] = 0;
        int id = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                comp[i] = id;
            } else {
                id++;
                comp[i] = id;
            }
        }
        vector<bool> ans(queries.size(), false);

        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            if (comp[u] == comp[v]) {
                ans[i] = true;
            }
        }

        return ans;
    }
};