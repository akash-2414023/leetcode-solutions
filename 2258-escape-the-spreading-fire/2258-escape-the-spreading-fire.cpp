class Solution {
public:
    bool isPossible(vector<vector<int>>& fireTime, int time) {
        int n = fireTime.size();
        int m = fireTime[0].size();

        if (time >= fireTime[0][0]) {
            return false;
        }
        int currTime = time;
        vector<vector<int>> vis(n, vector<int>(m, false));
        queue<pair<int, int>> q;

        q.push({0, 0});
        vis[0][0] = true;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int sz = q.size();
            currTime++;

            while (sz--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = row + dr[i];
                    int nc = col + dc[i];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= m ||
                        vis[nr][nc] || fireTime[nr][nc] == -1) {
                        continue;
                    }
                    if (nr == n - 1 && nc == m - 1) {
                        if (currTime <= fireTime[nr][nc]) {
                            return true;
                        }
                        continue;
                    }
                    if (fireTime[nr][nc] > currTime) {
                        q.push({nr, nc});
                        vis[nr][nc] = true;
                    }
                }
            }
        }

        return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        const int inf = 1e9;

        vector<vector<int>> vis(n, vector<int>(m, false));
        vector<vector<int>> fireTime(n, vector<int>(m, inf));

        queue<pair<int, int>> q;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    fireTime[i][j] = 0;
                    vis[i][j] = true;
                } else if (grid[i][j] == 2) {
                    fireTime[i][j] = -1;
                }
            }
        }

        int level = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                fireTime[row][col] = level;

                for (int i = 0; i < 4; i++) {
                    int nr = row + dr[i];
                    int nc = col + dc[i];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= m ||
                        vis[nr][nc] || fireTime[nr][nc] == -1) {
                        continue;
                    }

                    q.push({nr, nc});
                    vis[nr][nc] = true;
                }
            }

            level++;
        }

        int low = 0;
        int high = n * m;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(fireTime, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (high == n * m)
            return 1000000000;

        return high;
    }
};