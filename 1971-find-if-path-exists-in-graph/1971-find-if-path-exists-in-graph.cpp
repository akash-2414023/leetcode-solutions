class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        q.push(source);
        vector<int> visited(n, false);
        visited[source] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == destination)
                return true;

            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        return false;
    }
};