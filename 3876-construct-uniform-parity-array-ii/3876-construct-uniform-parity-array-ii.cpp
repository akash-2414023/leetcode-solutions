class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int mini = INT_MAX;
        for (int x : nums1) {
            if (x % 2 == 1) {
                mini = min(mini, x);
            }
        }
        for (int x : nums1) {
            if (x % 2 == 0 && mini != INT_MAX && mini > x) {
                return false;
            }
        }
        return true;
    }
};