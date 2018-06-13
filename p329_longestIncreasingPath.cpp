// Given an integer matrix, find the length of the longest increasing path.

// From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

// Example 1:

// Input: nums = 
// [
  // [9,9,4],
  // [6,6,8],
  // [2,1,1]
// ] 
// Output: 4 
// Explanation: The longest increasing path is [1, 2, 6, 9].
// Example 2:

// Input: nums = 
// [
  // [3,4,5],
  // [3,2,6],
  // [2,2,1]
// ] 
// Output: 4 
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.


// O(mn) time
// O(mn) space
class Solution {
    vector<int> dir;
    vector<vector<int>> dp;
    int m, n;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        m = matrix.size(), n = matrix[0].size();
        dir = {0, 1, 0, -1, 0};
        dp = vector<vector<int>>(m, vector<int>(n, 0));
        int res = 1;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
            res = max(res, dfs(matrix, i, j));
        }
        return res;
    }
    
    int dfs(auto& matrix, int i, int j) {
        if (dp[i][j] > 0) return dp[i][j];
        int res = 1;
        for (int k = 0; k < 4; k++) {
            int ii = i + dir[k], jj = j + dir[k+1];
            if (0 <= ii && ii < m && 0 <= jj && jj < n &&
               matrix[ii][jj] > matrix[i][j])
                res = max(res, 1 + dfs(matrix, ii, jj));
        }
        dp[i][j] = res;
        return res;
    }
};
