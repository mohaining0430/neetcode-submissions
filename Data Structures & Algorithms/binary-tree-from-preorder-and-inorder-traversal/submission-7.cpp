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
        if (preleft > preright || inleft > inright)
            return nullptr;
        int index = -1;
        for (index = inleft; index <= inright; ++index)
            if (inorder[index] == preorder[preleft])
                break;
        TreeNode* left = build(preorder, inorder, preleft + 1, preleft + index - inleft,
                                inleft, index - 1);
        TreeNode* right = build(preorder, inorder, preleft + index - inleft + 1, preright,
                                index + 1, inright);
        TreeNode* root = new TreeNode(preorder[preleft]);
        root->left = left;
        root->right = right;
        return root;
    }
};
