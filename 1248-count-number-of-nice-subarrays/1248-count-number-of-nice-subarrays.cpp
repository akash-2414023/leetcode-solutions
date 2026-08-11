class Solution {
public:
    long long atMost(vector<int>& nums, int k) {

        if (k < 0)
            return 0;

        int n = nums.size();
        int left = 0;
        int r = 0;
        long long sum = 0;
        long long ans = 0;

        while (r < n) {
            sum += (nums[r] % 2);
            while (sum > k) {
                sum -= (nums[left] % 2);
                left++;
            }
            ans += (r - left + 1);
            r++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {

        return atMost(nums, k) - atMost(nums, k - 1);
    }
};