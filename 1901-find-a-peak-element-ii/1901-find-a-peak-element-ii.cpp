class Solution {
public:
    int solve(vector<vector<int>>& mat, int n, int m, int col) {
        int maxi = INT_MIN;
        int row = 0;
        for (int i = 0; i < n; i++) {
            if (mat[i][col] > maxi) {
                maxi = mat[i][col];
                row = i;
            }
        }
        return row;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int maxColIndex = solve(mat, n, m, mid);
            int left = mid - 1 >= 0 ? mat[maxColIndex][mid - 1] : -1;
            int right = mid + 1 < m ? mat[maxColIndex][mid + 1] : -1;
            if (mat[maxColIndex][mid] > left && mat[maxColIndex][mid] > right) {
                return {maxColIndex, mid};
            } else if (mat[maxColIndex][mid] < left) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return {-1, -1};
    }
};