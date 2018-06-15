// Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

// Example 1:
// Input:

// "bbbab"
// Output:
// 4
// One possible longest palindromic subsequence is "bbbb".
// Example 2:
// Input:

// "cbbd"
// Output:
// 2
// One possible longest palindromic subsequence is "bb".
	

	
// O(n^2) time
// O(n) space, can further optimize
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<int> cur(n, 0), pre(n, 0);
        for (int i = n-1; i >= 0; i--) {
            cur[i] = 1;
            for (int j = i+1; j < n; j++)
                cur[j] = (s[i] == s[j])?  pre[j-1]+2: max(pre[j], cur[j-1]);
            pre = cur;
        }
        return cur[n-1];
    }
};



// O(n^2) time
// O(n^2) space
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof dp);
        for (int i = n-1; i >= 0; i--) for (int j = i; j < n; j++) {
            if (i == j) dp[i][j] = 1;
            else if (s[i] == s[j])
                dp[i][j] = dp[i+1][j-1] + 2;
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);                
        }
        return dp[0][n-1];
    }
};