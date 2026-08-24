class Solution {
public:
    vector<int> getFactors(int x) {
        vector<int> factors;
        for(int m = 2 ; m*m <= x ; m++){
            if (x % m == 0) {
                factors.push_back(m);

                while (x % m == 0) {
                    x /= m;
                }
            }
            
        }
        if(x > 1){
            factors.push_back(x);
        }
        return factors;
    }
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int distinct = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        while (r < n) {
            vector<int> right = getFactors(nums[r]);
            for (int x : right) {
                if (mp[x] == 0) {
                    distinct++;
                }
                mp[x]++;
            }
            while (distinct > k) {
                vector<int> left = getFactors(nums[l]);
                for (int x : left) {
                    mp[x]--;
                    if (mp[x] == 0) {
                        distinct--;
                    }
                }
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};