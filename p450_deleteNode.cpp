// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

// Basically, the deletion can be divided into two stages:

// Search for a node to remove.
// If the node is found, delete the node.
// Note: Time complexity should be O(height of tree).

// Example:

// root = [5,3,6,2,4,null,7]
// key = 3

    // 5
   // / \
  // 3   6
 // / \   \
// 2   4   7

// Given key to delete is 3. So we find the node with value 3 and delete it.

// One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    // 5
   // / \
  // 4   6
 // /     \
// 2       7

// Another valid answer is [5,2,6,null,4,null,7].

    // 5
   // / \
  // 2   6
   // \   \
    // 4   7

	


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 
 
// iterative
// O(h) time, height of tree
// O(1) space
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *cur, *dummy = new TreeNode(INT_MAX), *pre;
        cur = root, pre = dummy, pre->left = cur;
        while (cur) {
            if (cur->val == key) break;
            pre = cur;
            if (key < cur->val) cur = cur->left;
            else cur = cur->right;
        }
        if (!cur) return root;
        if (!cur->left) {
            if (cur == pre->left) pre->left = cur->right;
            else pre->right = cur->right;
        }
        else if(!cur->right) {
            if (cur == pre->left) pre->left = cur->left;
            else pre->right = cur->left;
        }
        else {
            auto left = cur->left;
            while (left->right) left = left->right;
            left->right = cur->right;
            if (cur == pre->left) pre->left = cur->left;
            else pre->right = cur->left;
        }
        return dummy->left;  
    }
};


// recursive
// O(h) time
// O(h) space, recursive calls
// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if (!root) return root;
//         if (root->val == key) {
//             if (!root->left) return root->right;
//             else if (!root->right) return root->left;
//             else {
//                 auto cur = root->left;
//                 while (cur->right) cur = cur->right;
//                 cur->right = root->right;
//                 return root->left;
//             }
//         }
//         else if (key < root->val) {
//             root->left = deleteNode(root->left, key);
//             return root;
//         }
//         else {
//             root->right = deleteNode(root->right, key);
//             return root;
//         }
//     }
// };