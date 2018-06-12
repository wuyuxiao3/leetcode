// You are given a binary tree in which each node contains an integer value.

// Find the number of paths that sum to a given value.

// The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

// The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

// Example:

// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      // 10
     // /  \
    // 5   -3
   // / \    \
  // 3   2   11
 // / \   \
// 3  -2   1

// Return 3. The paths that sum to 8 are:

// 1.  5 -> 3
// 2.  5 -> 2 -> 1
// 3. -3 -> 11


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// O(n) time, do a dfs/backtrack in every node
// O(n) space
class Solution {
    unordered_map<int, int> preSum;
    int cnt;
public:
    int pathSum(TreeNode* root, int sum) {
        preSum = {{0, 1}};
        cnt = 0;
        dfs(root, sum, 0);
        return cnt;
    }
    void dfs(TreeNode* root, int target, int cursum) {
        if (!root) return;
        cursum += root->val;
        cnt += preSum[cursum - target];
        preSum[cursum]++;
        dfs(root->left, target, cursum);
        dfs(root->right, target, cursum);
        preSum[cursum]--;
    }
};

// brutal force recursion, O(n^2)
// class Solution {
//     int pathSumFrom(TreeNode* root, int sum) {
//         if (!root) return 0;
//         return (root->val == sum? 1: 0) + 
//             pathSumFrom(root->left, sum-root->val) + 
//             pathSumFrom(root->right, sum-root->val);
//     }
//     public:
//     int pathSum(TreeNode* root, int sum) {
//         if (!root) return 0;
//         return pathSumFrom(root, sum) + 
//                 pathSum(root->left, sum) + 
//                 pathSum(root->right, sum);
//     }
// };