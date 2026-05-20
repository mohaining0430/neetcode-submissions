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
    // Longest path will be a path that passes through either the root or an internal node.
    int diameterOfBinaryTree(TreeNode* root) {
        int rootDepth = depth(root);
        return res - 1;
    }

private:
    int depth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int left = depth(root->left), right = depth(root->right);
        // max_length_of_a_path_that_passes_through_a_node
        res = std::max(res, left + right + 1);
        // return depth of root
        return left >= right ? left + 1 : right + 1;
    }    

    int res = 0;
};
