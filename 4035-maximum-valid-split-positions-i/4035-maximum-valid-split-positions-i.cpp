class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];

        for(int i = 1; i < n; i++) {
            prefixSum[i] = gcd(nums[i], prefixSum[i - 1]);
        }

        vector<int> suffixSum(n, 0);
        suffixSum[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            suffixSum[i] = gcd(nums[i], suffixSum[i + 1]);
        }

        int score = 0;

        // No removal
        for(int i = 0; i < n - 1; i++) {
            if(prefixSum[i] == suffixSum[i + 1]) {
                score++;
            }
        }
        // At most one removal
        for(int remove = 0; remove < n; remove++) {

            vector<int> arr;

            for(int i = 0; i < n; i++) {
                if(remove != i) {
                    arr.push_back(nums[i]);
                }
            }

            int m = arr.size();

            vector<int> pre(m);
            vector<int> suf(m);

            pre[0] = arr[0];

            for(int i = 1; i < m; i++) {
                pre[i] = gcd(arr[i], pre[i - 1]);
            }

            suf[m - 1] = arr[m - 1];
            for(int i = m - 2; i >= 0; i--) {
                suf[i] = gcd(suf[i + 1], arr[i]);
            }

            int curr = 0;

            for(int i = 0; i < m - 1; i++) {
                if(pre[i] == suf[i + 1]) {
                    curr++;
                }
            }

            score = max(score, curr);
        }

        return score;
    }
};