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
private:
  int dfs(TreeNode* node, bool isLeft) {
    if (node == nullptr) return 0;
    if (node->left == nullptr && node->right == nullptr) return isLeft ? node->val : 0;
    int leftSum = dfs(node->left, 1);
    int rightSum = dfs(node->right, 0);
    return leftSum + rightSum;
  }
public:
    int sumOfLeftLeaves(TreeNode* root) {
      return dfs(root, 0);
    }
};