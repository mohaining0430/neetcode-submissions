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

// DFS -- iterative
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }

    TreeNode* invert(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        TreeNode* left = invert(root->left);
        TreeNode* right = invert(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};


/*
// DFS -- recursive
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }

    TreeNode* invert(TreeNode *root) {
        if (root == nullptr)
            return nullptr;
        TreeNode *left = invert(root->left);
        TreeNode *right = invert(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};
*/


/*
// BFS
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> queue;
        if (root != nullptr)
            queue.push(root);
        while (!queue.empty()) {
            TreeNode *cur = queue.front();
            queue.pop();
            TreeNode *left = cur->left, *right = cur->right;
            cur->left = right;
            cur->right = left;
            if (cur->left != nullptr)
                queue.push(cur->left);
            if (cur->right != nullptr)
                queue.push(cur->right);            
        }
        return root;
    }
};
*/