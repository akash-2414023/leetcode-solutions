class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> a1, a2;
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        for (int k = 2; k < n; k++) {
            if (a1.back() > a2.back()) {
                a1.push_back(nums[k]);
            } else {
                a2.push_back(nums[k]);
            }
        }
        vector<int> ans;
        for (int x : a1) {
            ans.push_back(x);
        }
        for (int x : a2) {
            ans.push_back(x);
        }
        return ans;
    }
};