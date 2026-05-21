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
        return balanced;
    }

    int depth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int left = depth(root->left), right = depth(root->right);
        if (abs(left - right) > 1)
            balanced = false;
        return left >= right ? left + 1 : right + 1;
    }

    bool balanced = true;
};

/*
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        int left = height(root->left);
        int right = height(root->right);
        if (abs(left - right) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(height(root->left), height(root->right));
    }
};
*/
