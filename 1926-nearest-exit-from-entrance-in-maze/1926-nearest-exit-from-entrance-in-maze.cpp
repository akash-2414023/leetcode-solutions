class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        vector<vector<int>> vis(n, vector<int>(m, false));
        vis[entrance[0]][entrance[1]] = true;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int count = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;
                if ((r == 0 || r == n - 1 || c == 0 || c == m - 1) &&
                    !(entrance[0] == r && entrance[1] == c)) {
                    return count;
                }
                for (int i = 0; i < 4; i++) {
                    int nrow = r + dr[i];
                    int ncol = c + dc[i];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                        !vis[nrow][ncol] && maze[nrow][ncol] == '.') {
                        vis[nrow][ncol] = true;
                        q.push({nrow, ncol});
                    }
                }
            }
            count++;
        }
        return -1;
    }
};