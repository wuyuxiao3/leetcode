// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

// Example:

// Input: 

// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0

// Output: 4


// needs to find max which requires some kind of continuity, similar to Longest Common Substring
// uses a variable to be current max, keep updating
// compare to LC Subsequence, which does NOT need to be continuous, whose result lies in dp[m][n]

// O(mn) time
// O(mn) space, need to optimize to O(2n) and then O(n)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res*res;
    }
};
