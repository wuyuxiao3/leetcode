// Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

// Note: The length of path between two nodes is represented by the number of edges between them.

// Example 1:

// Input:

//               5
//              / \
//             4   5
//            / \   \
//           1   1   5
// Output:

// 2
// Example 2:

// Input:

//               1
//              / \
//             4   5
//            / \   \
//           4   4   5
// Output:

// 2
// Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.



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
// O(n) space
class Solution {
    int res = 0;
    int helper(TreeNode* root) {
        if (!root) return 0;
        int left = helper(root->left); // must call, otherwise won't recurse if root != left/right
        int right = helper(root->right);
        left = (root->left && root->left->val == root->val)? 1+left: 0;
        right = (root->right && root->right->val == root->val)? 1+right: 0; 
        res = max(res, left + right);
        return max(left, right);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        helper(root);
        return res;
    }
};