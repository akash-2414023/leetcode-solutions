class Solution {
public:
    int n;
    void solve(vector<int>& nums, int ind,
               vector<vector<int>>& res,
               vector<int>& curr) {

        if (curr.size() >= 2) {
            res.push_back(curr);
        }

        unordered_set<int> st;

        for (int i = ind; i < n; i++) {

            if (st.find(nums[i]) != st.end())
                continue;

            if (!curr.empty() && nums[i] < curr.back())
                continue;

            st.insert(nums[i]);

            curr.push_back(nums[i]);

            solve(nums, i + 1, res, curr);

            curr.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {

        n = nums.size();

        vector<vector<int>> res;
        vector<int> curr;

        solve(nums, 0, res, curr);

        return res;
    }
};