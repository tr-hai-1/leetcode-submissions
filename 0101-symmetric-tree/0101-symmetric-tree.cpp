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
    bool isSymmetric(TreeNode* root) {
      return isMirror(root->left, root->right);
    }
private:
  bool isMirror(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return 1;
    if (p == nullptr || q == nullptr || p->val != q->val) return 0;
    return isMirror(p->left, q->right) && isMirror(p->right, q->left);
  }
};