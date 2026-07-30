class Solution {
public:
    void dfs(int src, int target, vector<vector<int>>& ans,
             vector < int >& path, vector<vector<int>>& graph) {
        path.push_back(src);
        if (src == target) {
            ans.push_back(path);
        } else {
            for (auto it : graph[src]) {
                dfs(it, target, ans, path, graph);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, n - 1, ans, path, graph);
        return ans;
    }
};