class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int mid, int m, int k) {
        int n = bloomDay.size();
        int cnt = 0;
        int noOfBouquets = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= mid) {
                cnt++;
            } else {
                noOfBouquets += (cnt / k);
                cnt = 0;
            }
        }
        noOfBouquets += (cnt / k);
        if (noOfBouquets >= m)
            return true;

        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (1LL * m * k > n)
            return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            bool valid = isPossible(bloomDay, mid, m, k);
            if (valid) {
                //ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};