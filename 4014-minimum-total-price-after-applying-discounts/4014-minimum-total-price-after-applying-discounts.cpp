class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size();
        int m = discounts.size();
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());

        double ans = 0;
        int i = 0;
        while( i < min(n,m)) {
            ans += (double)(1LL * prices[i] * (100 - discounts[i])) / 100;
            i++;
        }
        while(i < n){
            ans += prices[i];
            i++;
        }

        return ans;
    }
};