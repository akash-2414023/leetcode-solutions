class Solution {
public:
    /*void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }*/
    void rotate(vector<int>& nums, int k) {
        if (nums.empty())
            return;

        k %= nums.size();
        // left rotation
        //  reverse(nums.begin(), nums.begin() + k);
        //  reverse(nums.begin() + k, nums.end());
        //  reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};