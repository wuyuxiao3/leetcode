# Given a string s, partition s such that every substring of the partition is a palindrome.

# Return all possible palindrome partitioning of s.

# Example:

# Input: "aab"
# Output:
# [
#   ["aa","b"],
#   ["a","a","b"]
# ]



class Solution:
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        def helper(s, path):
            if s == '':
                self.res += path[:],
                # if no [:], path is by reference, will pop later
                return
            for i in range(1, len(s)+1):
                if s[:i] == s[:i][::-1]:
                    path += s[:i],
                    helper(s[i:], path)
                    path.pop() # explicit make it backtracking
                    
        self.res = []
        helper(s, [])
        return self.res
        
        