class Solution {
public:
    bool bfsCheck(vector<vector<int>>& adj, int node, vector<int>& color) {
        color[node] = 1;
        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& v : adj[u]) {
                if (color[u] == color[v]) {
                    return false;
                } else if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for (auto it : dislikes) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (bfsCheck(adj, i, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};