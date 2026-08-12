class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ans = 0;
        for (int unique = 1; unique <= 26; unique++) {
            int l = 0;
            int r = 0;
            vector<int> freq(26, 0);
            int count = 0;
            int distinct = 0;
            while (r < n) {
                freq[s[r] - 'a']++;
                if (freq[s[r] - 'a'] == 1) {
                    distinct++;
                }
                if (freq[s[r] - 'a'] == k) {
                    count++;
                }
                while (distinct > unique) {
                    if (freq[s[l] - 'a'] == k) {
                        count--;
                    }
                    freq[s[l] - 'a']--;

                    if (freq[s[l] - 'a'] == 0) {
                        distinct--;
                    }
                    l++;
                }
                if (distinct == unique && unique == count) {
                    ans = max(ans, r - l + 1);
                }
                r++;
            }
        }
        return ans;
    }
};