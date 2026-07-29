class Solution {
public:
    int help(vector<int>& prefSum, int L, int M) {
        int n = prefSum.size();
        int res = 0;
        for (int mEnd = L + M - 1; mEnd < n; mEnd++) {
            int lEnd = mEnd - M;
            int lStartPrev = lEnd - L;

            int mBlockSum = prefSum[mEnd] - prefSum[lEnd];

            int lBlockSum =
                prefSum[lEnd] - (lStartPrev < 0 ? 0 : prefSum[lStartPrev]);

            int maxLeftSum = max(maxLeftSum, lBlockSum);
            res = max(res, maxLeftSum + mBlockSum);
        }
        return res;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int L, int M) {
        int n = nums.size();
        vector<int> prefSum(n, 0);
        prefSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefSum[i] = nums[i] + prefSum[i - 1];
        }
        return max(help(prefSum, L, M), help(prefSum, M, L));
    }
};