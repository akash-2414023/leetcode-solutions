class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        n = len(s)
        ans = 0
        for i in range (n - 2):
            a = s[i]
            b = s[i + 1]
            c = s[i + 2]
            if a != b and b !=c and c != a:
                ans+=1

        return ans