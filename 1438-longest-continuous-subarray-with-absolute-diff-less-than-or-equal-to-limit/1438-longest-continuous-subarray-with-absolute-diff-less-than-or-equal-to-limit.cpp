class Solution {
public:
    typedef pair<int, int> P;

    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int maxi = 0;

        priority_queue<P, vector<P>> maxHeap;
        priority_queue<P, vector<P>, greater<P>> minHeap;

        while (r < n) {
            maxHeap.push({nums[r], r});
            minHeap.push({nums[r], r});

            while (maxHeap.top().first - minHeap.top().first > limit) {

                l = min(maxHeap.top().second, minHeap.top().second) + 1;

                while (!minHeap.empty() && minHeap.top().second < l) {
                    minHeap.pop();
                }

                while (!maxHeap.empty() && maxHeap.top().second < l) {
                    maxHeap.pop();
                }
            }

            maxi = max(maxi, r - l + 1);

            r++;
        }

        return maxi;
    }
};