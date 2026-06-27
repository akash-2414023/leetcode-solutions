class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }
        vector<int> ans;
        for (int num : nums) {
            if (freq[num] == 1 && freq[num - 1] == 0 && freq[num + 1] == 0) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};