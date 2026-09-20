class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = max(intervals[i][0], intervals[j][0]);
                int b = min(intervals[i][1], intervals[j][1]);
                if (a <= b) {
                    count++;
                }
            }
        }
        return count;
    }
};