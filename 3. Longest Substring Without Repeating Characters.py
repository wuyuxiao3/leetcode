# Given a string, find the length of the longest substring without repeating characters.

# Examples:

# Given "abcabcbb", the answer is "abc", which the length is 3.

# Given "bbbbb", the answer is "b", with the length of 1.

# Given "pwwkew", the answer is "wke", with the length of 3. 
# Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


# O(n) time
# O(n) space
class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        seen = {}
        res = 0
        j = 0
        for i, c in enumerate(s):
            if c in seen and seen[c] >= j :
                j = seen[c] + 1
            seen[c] = i
            res = max(res, i-j+1)
            
        return res