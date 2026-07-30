class Solution {
public:
    bool check(vector<vector<int>>& distNearestThief, int safeFactor) {
        int n = distNearestThief.size();
        if (distNearestThief[0][0] < safeFactor)
            return false;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if (row == n - 1 && col == n - 1)
                return true;

            for (int i = 0; i < 4; i++) {
                int nRow = row + dr[i];
                int nCol = col + dc[i];

                if (nRow < n && nRow >= 0 && nCol < n && nCol >= 0 &&
                    !visited[nRow][nCol]) {
                    if (distNearestThief[nRow][nCol] < safeFactor) {
                        continue;
                    }
                    q.push({nRow, nCol});
                    visited[nRow][nCol] = true;
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> distNearestThief(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    distNearestThief[i][j] = 0;
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                distNearestThief[row][col] = level;

                for (int i = 0; i < 4; i++) {
                    int nRow = row + dr[i];
                    int nCol = col + dc[i];

                    if (nRow >= n || nRow < 0 || nCol >= n || nCol < 0 ||
                        visited[nRow][nCol])
                        continue;

                    q.push({nRow, nCol});
                    visited[nRow][nCol] = true;
                }
            }
            level++;
        }
        int low = 1, high = 400;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(distNearestThief, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};