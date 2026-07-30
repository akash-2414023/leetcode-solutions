class Solution {
public:
    int dfs(vector<vector<int>>& adj, int curr, int parent,
            vector<bool>& hasApple) {
        int time = 0;
        for (int& child : adj[curr]) {
            if (child == parent)
                continue;
            int timeForChild = dfs(adj, child, curr, hasApple);

            if (timeForChild > 0 || hasApple[child]) {
                time += timeForChild + 2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n + 1);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(adj, 0, -1, hasApple);
    }
};