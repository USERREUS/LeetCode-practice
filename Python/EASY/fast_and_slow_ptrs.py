'''
    TASK: Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
    Time complexity: O(n). Our fast pointer does not visit the same spot twice.
    Space complexity: O(1). All operations are made in-place
'''

class Solution:
    def moveZeroes(self, nums: list) -> None:
        slow = 0
        for fast in range(len(nums)):
            if nums[fast] != 0 and nums[slow] == 0:
                nums[slow], nums[fast] = nums[fast], nums[slow]

            if nums[slow] != 0:
                slow += 1