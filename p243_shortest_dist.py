# Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

# Example:
# Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

# Input: word1 = “coding”, word2 = “practice”
# Output: 3
# Input: word1 = "makes", word2 = "coding"
# Output: 1
# Note:
# You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.



class Solution:
    def shortestDistance(self, words, word1, word2):
        """
        :type words: List[str]
        :type word1: str
        :type word2: str
        :rtype: int
        """
        res = len(words)
        i = -1
        for j, word in enumerate(words):
            if word in [word1, word2]:
                if i != -1 and word != words[i]:
                    res = min(res, j-i)
                i = j
        return res
    
    # time    O(n)
    # space   O(1)
        