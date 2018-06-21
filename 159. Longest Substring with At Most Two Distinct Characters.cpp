// Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

// Example 1:

// Input: "eceba"
// Output: 3
// Explanation: t is "ece" which its length is 3.
// Example 2:

// Input: "ccaabbb"
// Output: 5
// Explanation: t is "aabbb" which its length is 5.


// O(n) time
// O(1) space, hash table stores at most 2 items
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> seen;
        int res = 0, j = 0, tmp;
        char k1;
        for (int i = 0; i < s.size(); i++) {
            if (seen.size() == 2 && seen.find(s[i]) == seen.end()) {
                tmp = INT_MAX;
                for (auto x:seen)
                    if (x.second < tmp) tmp = x.second, k1 = x.first;
                j = seen[k1] + 1;
                seen.erase(k1);
            }
            seen[s[i]] = i;
            res = max(res, i-j+1);
        }
        return res;
    }
};