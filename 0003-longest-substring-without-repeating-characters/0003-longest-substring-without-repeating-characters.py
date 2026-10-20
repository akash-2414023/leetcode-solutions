class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        dict1 = {}
        l = 0
        r = 0
        maxLen = 0
        while(r < n):
            if s[r] in dict1 and dict1[s[r]] >= l :
                l = dict1[s[r]] + 1
            maxLen = max(maxLen , r - l + 1)
            dict1[s[r]] = r
            r += 1
        
        return maxLen
        