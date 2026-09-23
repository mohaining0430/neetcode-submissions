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
    bool isBalanced(TreeNode* root) {
        depth(root);
        return res;
    }

private:
    int depth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = depth(root->left), right = depth(root->right);
        if (abs(left - right) > 1)
            res = false;
        return 1 + max(left, right);
    }

    bool res = true;
};