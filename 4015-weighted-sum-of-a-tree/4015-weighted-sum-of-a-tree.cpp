class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        queue<pair<int, int>> q;
        q.push({0, 1});
        int height = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int node = q.front().first;
                int depth = q.front().second;
                q.pop();
                height = max(height, depth);
                for (auto it : adj[node]) {
                    q.push({it, depth + 1});
                }
            }
        }
        long long ans = 0;
        q.push({0, 1});
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int node = q.front().first;
                int depth = q.front().second;
                q.pop();
                ans += 1LL * nums[node] * (height - depth + 1);
                for (auto it : adj[node]) {
                    q.push({it, depth + 1});
                }
            }
        }
        return ans;
    }
};