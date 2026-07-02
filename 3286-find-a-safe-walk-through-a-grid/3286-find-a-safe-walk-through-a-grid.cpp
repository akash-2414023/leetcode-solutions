class Solution {
public:
    typedef pair<int, pair<int, int>> P;

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> best(n, vector<int>(m, -1));

        priority_queue<P> pq;  

        int start = health - grid[0][0];
        if (start <= 0) return false;

        best[0][0] = start;
        pq.push({start, {0, 0}});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int rem = cur.first;
            int r = cur.second.first;
            int c = cur.second.second;

            if (r == n - 1 && c == m - 1)
                return true;

            if (rem < best[r][c])
                continue;

            for (int i = 0; i < 4; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int newHealth = rem - grid[nr][nc];

                    if (newHealth > 0 && newHealth > best[nr][nc]) {
                        best[nr][nc] = newHealth;
                        pq.push({newHealth, {nr, nc}});
                    }
                }
            }
        }

        return false;
    }
};