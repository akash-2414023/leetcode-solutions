class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        int maxi = -1;
        unordered_map<int, int> freq;
        for (int x : arr) {
            freq[x]++;
        }
        for (auto it : freq) {
            if (it.second == it.first) {
                maxi = max(maxi, it.first);
            }
        }
        return maxi;
    }
};