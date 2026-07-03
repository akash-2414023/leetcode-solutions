class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            temp.push_back(nums[i]);
        }
        sort(nums.begin(), nums.end());
        int start = 0, end = n - 1;
        while (start < end) {
            if ((nums[start] + nums[end]) == target) {
                break;
            } else if ((nums[start] + nums[end]) < target) {
                start++;
            } else
                end--;
        }
        for (int i = 0; i < n; i++) {
            if (nums[start] == temp[i]) {
                ans.push_back(i);
            } else if (nums[end] == temp[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};