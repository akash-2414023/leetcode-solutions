class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        for (int i = mini + 1; i < maxi; i++) {
            if (mp.find(i) == mp.end()) {
                ans.push_back(i);
            }
        }
        return ans;
        /*sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) {
                for (int x = nums[i - 1] + 1; x < nums[i]; x++) {
                    ans.push_back(x);
                }
            }
        }
        return ans;*/
    }
};