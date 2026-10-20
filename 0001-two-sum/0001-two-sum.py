class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        n = len(nums)
        mp = {}

        for i in range (n) : 
            need = target - nums[i]

            if need in mp:
                return [mp[need],i]

            mp[nums[i]] = i
        return []