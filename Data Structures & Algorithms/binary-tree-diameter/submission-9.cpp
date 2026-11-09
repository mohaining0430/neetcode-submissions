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
        int d = depth(root);
        return res - 1;
    }

    int depth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = depth(root->left), right = depth(root->right);
        res = max(res, left + right + 1);
        return 1 + max(left, right);
    }

private:
    int res = 0;
};
