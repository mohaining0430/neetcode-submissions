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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preleft,
                        int preright, int inleft, int inright) {
        if (preleft > preright)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[preleft]);
        int index = 0;
        for (index = inleft; index <= inright; ++index)
            if (inorder[index] == root->val)
                break;
        root->left = build(preorder, inorder, preleft + 1, preleft + 1 + index - 1 - inleft, inleft, index - 1);
        root->right = build(preorder, inorder, preleft + 1 + index - 1 - inleft + 1, preright, index + 1, inright);
        return root;
    }
};
