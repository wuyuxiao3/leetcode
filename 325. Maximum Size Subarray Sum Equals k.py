# Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

# Note:
# The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

# Example 1:

# Input: nums = [1, -1, 5, -2, 3], k = 3
# Output: 4 
# Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
# Example 2:

# Input: nums = [-2, -1, 2, 1], k = 1
# Output: 2 
# Explanation: The subarray [-1, 2] sums to 1 and is the longest.
# Follow Up:
# Can you do it in O(n) time?


# O(n) time
# O(n) space, worst case
class Solution:
    def maxSubArrayLen(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        dic = {0: 0} # key: sum of nums[:idx) (excluding idx), value: idx
        res = cursum = 0
        for i, num in enumerate(nums):
            cursum += num
            if cursum - k in dic:
                res = max(res, i - dic[cursum-k] + 1)
            if cursum not in dic: # keep the smallest
                dic[cursum] = i + 1
        return res
        
        """
        suppose running sum 0:j = cursum
        then sum of i:j = k if some running sum 0:i-1 = cursum - k exists for (multiple) i
        0_____i_____j_____
        
        """
        
        
        
        