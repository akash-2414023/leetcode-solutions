class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int maxSum = 0;
        int lSum = 0;
        int rSum = 0;
        for(int i = 0 ; i < k ; i++){
            lSum += nums[i];
            maxSum = lSum;
        }
        int rIndex = n - 1;
        for(int i = k - 1 ; i >= 0 ; i--){
            lSum -= nums[i];
            rSum += nums[rIndex];
            rIndex--;
            maxSum = max(maxSum , lSum + rSum);
        }
        return maxSum;
    }
};