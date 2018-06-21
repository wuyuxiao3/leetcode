# Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

# Example 1:

# Input: "eceba"
# Output: 3
# Explanation: t is "ece" which its length is 3.
# Example 2:

# Input: "ccaabbb"
# Output: 5
# Explanation: t is "aabbb" which its length is 5.


# O(n) time
# O(1) space, hash table stores at most 2 items
class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s):
        """
        :type s: str
        :rtype: int
        """
        seen = {}
        res = 0
        j = 0
        for i, c in enumerate(s):
            if len(seen) == 2 and c not in seen:
                k1, k2 = seen.keys()
                if seen[k2] < seen[k1]:
                    k1, k2 = k2, k1
                j = seen[k1] + 1
                del seen[k1]

            seen[c] = i
            res = max(res, i-j+1)
            
        return res
        