#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#


# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        sumMap = {}
        for i, n in enumerate(nums):
            diff = target - nums[i]
            if diff in sumMap:
                return [sumMap[diff], i]
            sumMap[n] = i
        return


# @lc code=end
