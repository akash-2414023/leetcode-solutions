class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int count = 0;
        for (auto it : mp) {
            vector<int>& vec = it.second;
            if (vec.size() >= 3) {
                bool check = true;
                for (int i = 1; i < vec.size() - 1; i++) {
                    if (2 * vec[i] != vec[i - 1] + vec[i + 1]) {
                        check = false;
                        break;
                    }
                }
                if (check == true) {
                    count++;
                }
            }
        }
        return count;
    }
};