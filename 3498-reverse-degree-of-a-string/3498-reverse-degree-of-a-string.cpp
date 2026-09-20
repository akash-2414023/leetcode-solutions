class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int ch = 26 - s[i - 1] + 'a';
            ans += (ch * i);
        }

        return ans;
    }
};