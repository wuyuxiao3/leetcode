# We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

# Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

# Example 1:
# Input: [1,3,2,2,5,2,3,7]
# Output: 5
# Explanation: The longest harmonious subsequence is [3,2,2,2,3].
# Note: The length of the input array will not exceed 20,000.



class Solution:
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = dict()
        res = 0
        for x in nums:
            count[x] = count.get(x, 0) + 1
        for x in count:
            if x+1 in count:
                res = max(res, count[x] + count[x+1])
        return res

        # time    O(n)
        # space   O(n)
        