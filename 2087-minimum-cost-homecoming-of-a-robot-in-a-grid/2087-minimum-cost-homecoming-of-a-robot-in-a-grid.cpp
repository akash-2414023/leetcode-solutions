class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {
        int r1 = startPos[0];
        int c1 = startPos[1];
        int r2 = homePos[0];
        int c2 = homePos[1];
        int result = 0;
        if (r1 <= r2) {
            // moving down
            for (int r = r1 + 1; r <= r2; r++) {
                result += rowCosts[r];
            }
        } else {
            // moving up
            for (int r = r1 - 1; r >= r2; r--) {
                result += rowCosts[r];
            }
        }

        // col
        if (c1 <= c2) {
            // moving down
            for (int c = c1 + 1; c <= c2; c++) {
                result += colCosts[c];
            }
        } else {
            // moving up
            for (int c = c1 - 1; c >= c2; c--) {
                result += colCosts[c];
            }
        }
        return result;
    }
};