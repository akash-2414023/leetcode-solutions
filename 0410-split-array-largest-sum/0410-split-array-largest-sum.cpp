class Solution {
public:
    int func(vector<int>& nums, long long mid) {
        int cnt = 1;
        int splitCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (splitCount + nums[i] <= mid) {
                splitCount += nums[i];
            } else {
                cnt++;
                splitCount = nums[i];
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            int split = func(nums, mid);
            if (split <= k) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};