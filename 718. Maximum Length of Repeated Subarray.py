# Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

# Example 1:
# Input:
# A: [1,2,3,2,1]
# B: [3,2,1,4,7]
# Output: 3
# Explanation: 
# The repeated subarray with maximum length is [3, 2, 1].
# Note:
# 1 <= len(A), len(B) <= 1000
# 0 <= A[i], B[i] < 100


# the problem is same as Longest Common Substring

# O(mn) time
# O(mn) space, need to optimize to O(2n) and then O(n)
class Solution:
    def findLength(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        m, n = len(A), len(B) 
        res = 0
        dp = [[0] * (n+1) for _ in range(m+1)]
        for i in range(1, m+1):
            for j in range(1, n+1):
                if A[i-1] == B[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                    res = max(res, dp[i][j])
        return res