/*
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

Example 1:

Input:

   1
    \
     3
    / \
   2   4
        \
         5

Output: 3

Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
Example 2:

Input:

   2
    \
     3
    / 
   2    
  / 
 1

Output: 2 

Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.

*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// O(n) time
// O(1)? space
class Solution {
    int res = 0;
    void dfs(TreeNode* root, int pre, int path) {
        if (!root) return;
        if (root->val == pre + 1) path++;
        else path = 1;
        res = max(res, path);
        dfs(root->left,  root->val, path);
        dfs(root->right, root->val, path);
    }
public:
    int longestConsecutive(TreeNode* root) {
        if (root) dfs(root, root->val, 0);
        return res;
    }
};
