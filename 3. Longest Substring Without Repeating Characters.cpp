// Given a string, find the length of the longest substring without repeating characters.

// Examples:

// Given "abcabcbb", the answer is "abc", which the length is 3.

// Given "bbbbb", the answer is "b", with the length of 1.

// Given "pwwkew", the answer is "wke", with the length of 3. 
// Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


// O(n) time
// O(n) space
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        int res = 0, j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (seen.find(s[i]) != seen.end() && seen[s[i]] >= j)
                j = seen[s[i]] + 1;
            seen[s[i]] = i;
            res = max(res, i-j+1);
        }
        return res;
    }
};