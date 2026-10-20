class Solution:
    def merge(self, nums, low, mid, high):
        temp = []
        left = low
        right = mid + 1
        while left <= mid and right <= high:
            if nums[left] <= nums[right]:
                temp.append(nums[left])
                left += 1
            else:
                temp.append(nums[right])
                right += 1

        while left <= mid:
            temp.append(nums[left])
            left += 1

        while right <= high:
            temp.append(nums[right])
            right += 1

        for i in range(low, high + 1):
            nums[i] = temp[i - low]

    def mergeSort(self, nums, low, high):
        if low >= high:
            return
        mid = low + (high - low) // 2
        self.mergeSort(nums, low, mid)
        self.mergeSort(nums, mid + 1, high)
        self.merge(nums, low, mid, high)

    def sortArray(self, nums: list[int]) -> list[int]:
        n = len(nums)
        self.mergeSort(nums, 0, n - 1)
        return nums
