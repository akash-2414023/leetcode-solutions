class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> prev;

        for (int i = 0; i < arr.size(); i++) {
            unordered_set<int> curr;

            curr.insert(arr[i]);

            for (int x : prev) {
                curr.insert(x | arr[i]);
            }

            for (int x : curr) {
                ans.insert(x);
            }

            prev = curr;
        }

        return ans.size();
    }
};