class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        bool allZero = true;
        int resultxor = 0;
        for (int x : nums) {
            resultxor = (resultxor ^ x);

            if (x != 0) {
                allZero = false;
            }
        }
        if (allZero) {
            return 0;
        }

        return resultxor == 0 ? n - 1 : n;
    }
};