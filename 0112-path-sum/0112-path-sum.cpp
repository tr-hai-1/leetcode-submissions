/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
      if (root == nullptr) return 0;
      int remaining = targetSum - root->val;
      if (root->left == nullptr && root->right == nullptr) return remaining == 0;
      return (hasPathSum(root->left, remaining) || hasPathSum(root->right, remaining));
    }
};