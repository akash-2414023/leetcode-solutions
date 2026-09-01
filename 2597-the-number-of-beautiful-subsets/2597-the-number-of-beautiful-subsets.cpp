class Solution {
public:
    void solve(int ind, vector<int>& nums, int k,
               unordered_map<int, int>& mp, int& res) {

        if (ind >= nums.size()) {
            res++;
            return;
        }

        solve(ind + 1, nums, k, mp, res);

        if (!mp[nums[ind] - k] && !mp[nums[ind] + k]) {
            mp[nums[ind]]++;

            solve(ind + 1, nums, k, mp, res);

            mp[nums[ind]]--;
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> mp;

        solve(0, nums, k, mp, result);

        return result - 1;
    }
};