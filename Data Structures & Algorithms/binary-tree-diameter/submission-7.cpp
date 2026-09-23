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
    int diameterOfBinaryTree(TreeNode* root) {
        int rootDepth = depth(root);
        return res - 1;
    }

private:
    int depth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        res = max(res, left + right + 1);
        return 1 + max(left, right);
    }

    int res = 0;
};
