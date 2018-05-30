/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int res = INT_MAX, n = words.size(), i = -1, j = -1;
        for (int k = 0; k < n; k++) {
            if (words[k] == word1) i = k;
            else if (words[k] == word2) j = k;
            if (i >= 0 && j >= 0) res = min(res, abs(j-i));
        }
        return res;
    }
};
    
    // time    O(n)
    // space   O(1)
        