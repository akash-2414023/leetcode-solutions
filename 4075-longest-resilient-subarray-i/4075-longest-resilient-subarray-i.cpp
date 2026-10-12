class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 1;
        for(int i = 0 ; i < n ; i++){
            int sum = 0;
            int rem = nums[i] % k;
            for(int j = i ; j < n ; j++){
                if(nums[j] % k != rem){
                    break;
                }
                sum += nums[j];

                if(sum % k == rem){
                    maxLen = max(maxLen , j - i + 1);
                }
            }
        }
        return maxLen;
    }
};