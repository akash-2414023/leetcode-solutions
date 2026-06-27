class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Moore's voting algo
        int n = nums.size();
        int cnt = 0 ;
        int el;
        for(int i = 0 ; i < n ; i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }else if(nums[i] == el){
                cnt++;
            }else cnt--;
        }
        return el;


        // unordered_map<int, int> mp;
        // int n= nums.size();
        // for (int i = 0; i < n; i++) {
        //     mp[nums[i]]++;

        //     if (mp[nums[i]] > n / 2) {
        //         return nums[i];
        //     }
        // }
        // return -1;
        /*sort(nums.begin(), nums.end());
        int ans = nums[nums.size() / 2];
        return ans;*/
    }
};