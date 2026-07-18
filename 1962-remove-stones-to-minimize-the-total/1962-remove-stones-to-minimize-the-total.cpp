class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> pq(piles.begin(), piles.end());
        while (k--) {
            int maxi = pq.top();
            pq.pop();
            maxi = (maxi + 2 - 1) / 2; // ceil value
            pq.push(maxi);
        }
        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};