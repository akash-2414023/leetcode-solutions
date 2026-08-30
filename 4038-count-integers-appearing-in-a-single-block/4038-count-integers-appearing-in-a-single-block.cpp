class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = 0;
        for (auto it : mp) {
            vector<int> vec = it.second;
            bool flag = true;
            for (int i = 0; i < vec.size() - 1; i++) {
                if (vec[i] + 1 != vec[i + 1]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans++;
        }
        return ans;
    }
};