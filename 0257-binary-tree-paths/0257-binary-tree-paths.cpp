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
  vector<string> res;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
      helper(root, "");
      return res;
    }
    void helper(TreeNode* root, string curr) {
      if (root == nullptr) return;
      curr += to_string(root->val);
      if (root->left == nullptr && root->right == nullptr) res.push_back(curr);
      helper(root->left, curr + "->");
      helper(root->right, curr + "->");
    }
};