class Solution {
public:
    void dfs(vector<vector<int>>& stones, int ind, vector<int>& vis) {
        vis[ind] = true;
        for (int i = 0; i < stones.size(); i++) {
            int r = stones[ind][0];
            int c = stones[ind][1];

            if (!vis[i] && (stones[i][0] == r || stones[i][1] == c)) {
                dfs(stones, i, vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> vis(n, false);
        int group = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == true)
                continue;

            dfs(stones, i, vis);
            group++;
        }
        return n - group;
    }
};