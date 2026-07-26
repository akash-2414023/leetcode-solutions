class Solution {
public:
    bool check(vector<int>& time, long long ind, int totalTrips) {
        int n = time.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += ind / time[i];
            if (total >= totalTrips)
                return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long low = *min_element(time.begin(), time.end());
        long long high = 1LL * (*min_element(time.begin(), time.end())) * totalTrips;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            bool isTrue = check(time, mid, totalTrips);
            if (isTrue) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};