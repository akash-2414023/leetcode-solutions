class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int threshold){
        int n = nums.size();
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            int num = (nums[i] + mid -1)/mid;
            sum += num;
        }
        if(sum <= threshold) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(low <= high){
            int mid = low + (high - low)/2 ;
            bool isValid = isPossible(nums , mid , threshold);
            if(isValid) {
                high = mid - 1;
            }else{
                low = mid + 1;
            }

        }
        return low;
    }
};