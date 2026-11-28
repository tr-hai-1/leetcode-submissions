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
    int total = 0;
    int findTilt(TreeNode* root) {
      helper(root);
      return total;
    }
    int helper(TreeNode* node) {
      if (node == nullptr) return 0;
      int totalLeft = helper(node->left);
      int totalRight = helper(node->right);
      total += abs(totalLeft - totalRight);
      return node->val + totalLeft + totalRight;
    }
};