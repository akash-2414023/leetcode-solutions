class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });

        int lastIndex = intervals[0][1];
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (lastIndex >= intervals[i][1])
                continue;
            lastIndex = intervals[i][1];
            count++;
        }
        return count;
        /*vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {
            if (result.back()[0] <= intervals[i][0] &&
                result.back()[1] >= intervals[i][1]) {
                continue;
            }
            result.push_back(intervals[i]);
        }
        return result.size();*/
    }
};