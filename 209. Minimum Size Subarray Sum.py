# Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

# Example: 

# Input: s = 7, nums = [2,3,1,2,4,3]
# Output: 2
# Explanation: the subarray [4,3] has the minimal length under the problem constraint.
# Follow up:
# If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 


# O(n) time, two pointers i, j can each do one pass at most
# O(1) space
class Solution:
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        res = n+1
        cursum = 0
        i = 0
        for j in range(n):
            cursum += nums[j]
            while cursum >= s and i <= j: # i = j also valid, no need i <= j (an array of n positive integers)
                res = min(res, j-i+1)
                cursum -= nums[i]
                i += 1
                
        return res if res != n+1 else 0
        
        """
        0_____i_____j
              cursum = sum of nums[i:j+1]
        """
        
        
        