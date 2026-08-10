class Solution {
public:
    bool check(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        int m = queries.size();

        vector<int> diff(n, 0);

        for (int i = 0; i <= k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];

            diff[l] += x;

            if (r + 1 < n)
                diff[r + 1] -= x;
        }

        int currSum = 0;

        for (int i = 0; i < n; i++) {
            currSum += diff[i];

            diff[i] = currSum;

            if (nums[i] - diff[i] > 0) {
                return false;
            }
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        int l = 0;
        int r = m - 1;
        int ans = -1;

        //edge case zero check
        bool zero = true;
        for(int x : nums){
            if(x != 0){
                zero = false;
                break;
            }
        }
        if(zero)
            return 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(nums, queries, mid)) {
                ans = mid + 1;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};