class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        n = len(nums)
        j = 0
        for i in range (n):
            if j < 2 or nums[i] != nums[j - 2]:
                nums[j] = nums[i]
                j += 1

        return j
            