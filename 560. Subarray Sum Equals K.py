# Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

# Example 1:
# Input:nums = [1,1,1], k = 2
# Output: 2
# Note:
# The length of the array is in range [1, 20,000].
# The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].


# O(n) time
# O(n) space, worst case
class Solution:
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        dic = {0:1}
        res = cursum = 0
        for num in nums:
            cursum += num
            if cursum - k in dic:
                res += dic[cursum - k]
            dic[cursum] = dic.get(cursum, 0) + 1
        return res
    
        """
        suppose running sum 0:j = cursum
        then sum of i:j = k if some running sum 0:i-1 = cursum - k exists for (multiple) i
        0_____i_____j_____
        
        """
        