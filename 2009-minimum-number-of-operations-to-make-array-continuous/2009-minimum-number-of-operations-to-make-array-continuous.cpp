class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = INT_MAX;
        set<int>st;
        for(int i = 0 ; i < n ; i++){
            st.insert(nums[i]);
        }
        vector<int>temp(begin(st),end(st));
        for(int i = 0 ; i < temp.size() ; i++){
            int l = temp[i] ; 
            int r = l + n - 1;
            int j = upper_bound(begin(temp),end(temp),r) - begin(temp);

            int within_range = j - i;
            int out_of_range = n - within_range;
            ops = min(ops,out_of_range);
            
        }
        return ops;
    }
};