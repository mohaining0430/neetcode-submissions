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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 0;
        if (root != nullptr)
            q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left != nullptr)
                    q.push(cur->left);
                if (cur->right != nullptr)
                    q.push(cur->right);
            }
            level++;
        }
        return level;
    }
};

/*
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return depth(root);
    }

    int depth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int left = depth(root->left), right = depth(root->right);
        return left >= right ? left + 1 : right + 1;
    }
};
*/
