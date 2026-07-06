class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> rowMin(n), colMax(m);
        int maxi = -1;
        for (int i = 0; i < n; i++) {
            int mini = INT_MAX;
            for (int j = 0; j < m; j++) {
                mini = min(mini, matrix[i][j]);
            }
            rowMin[i] = mini;
        }
        for (int j = 0; j < m; j++) {
            int maxi = INT_MIN;
            for (int i = 0; i < n; i++) {
                maxi = max(maxi, matrix[i][j]);
            }
            colMax[j] = maxi;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};