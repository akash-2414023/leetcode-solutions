class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minEleIndex = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxEleIndex = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(minEleIndex, maxEleIndex);
        int right = max(minEleIndex, maxEleIndex);

        return min({left + 1 + n - right, right + 1, n - left});
    }
};