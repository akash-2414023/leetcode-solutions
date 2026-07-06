class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int end = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < end) {
                count++;
                end = min(end, intervals[i][1]);
            } else {
                end = intervals[i][1];
            }
        }
        return count;
        /*sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int i = 0;
        int j = 1;
        int count = 0;
        while (j < n) {
            vector<int> curr_interval = intervals[i];
            vector<int> next_interval = intervals[j];

            int cs = curr_interval[0];
            int ce = curr_interval[1];
            int ns = next_interval[0];
            int ne = next_interval[1];
            if (ce <= ns) {
                i = j;
                j++;
            } else if (ce > ns && ce <= ne) {
                count++;
                j++;
            } else if (ce > ne) {
                i = j;
                j++;
                count++;
            }
        }
        return count;*/
        
    }
};