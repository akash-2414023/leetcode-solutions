class Solution {
public:
    bool isPossible(vector<int>& candies, int mid, long long k) {
        int n = candies.size();
        long long children = 0;
        for (int x : candies) {
            children += x / mid;
        }
        if (children >= k) {
            return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool isValid = isPossible(candies, mid, k);
            if (isValid) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return high;
    }
};