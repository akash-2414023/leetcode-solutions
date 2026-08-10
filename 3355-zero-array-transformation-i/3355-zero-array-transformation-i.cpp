class Solution {
public:
    bool check(vector<int>& nums, vector<vector<int>>& queries, int ind) {
        int n = nums.size();
        int m = queries.size();
        vector<int> diff(n, 0);
        for (int i = 0; i <= ind; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int x = 1;

            diff[l] += x;
            if (r + 1 < n) {
                diff[r + 1] -= x;
            }
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
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        bool zero = true;
        for(int x : nums){
            if(x != 0){
                zero = false;
                break;
            }
        }
        if(zero)
            return 0;

        int l = 0;
        int r = m - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2 ;
            if (check(nums, queries, mid)) {
                return true;
            }
            else {
                l = mid + 1;
            }
        }
        return false;
    }
};