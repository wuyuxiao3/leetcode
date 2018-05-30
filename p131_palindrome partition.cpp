/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/



class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        helper(s, {}, 0);
        return res;
    }
    
    void helper(string& s, vector<string> path, int idx) {
        if (idx == s.size()) {
            res.push_back(path);
            return; 
        }
        for (int i = idx; i < s.size(); i++) {
            if (isPa(s, idx, i)) {
                path.push_back(s.substr(idx, i-idx+1));
                helper(s, path, i+1);
                path.pop_back();
            }
        }
    }
    
    bool isPa(string& s, int i, int j) {
        while (i < j && s[i] == s[j]) i++, j--;
        return i >= j;
    }
};
        
        