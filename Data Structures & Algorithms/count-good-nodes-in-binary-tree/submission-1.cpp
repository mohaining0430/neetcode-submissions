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
    int goodNodes(TreeNode* root) {
        int res = 0;
        queue<std::pair<TreeNode*, int>> q;
        if (root != nullptr)
            q.push({root, root->val});
        while (!q.empty()) {
            TreeNode *cur = q.front().first;
            int curMax = q.front().second;
            q.pop();
            if (curMax <= cur->val)
                res++;
            if (cur->left != nullptr)
                q.push({cur->left, max(cur->val, curMax)});
            if (cur->right != nullptr) 
                q.push({cur->right, max(cur->val, curMax)});
        }
        return res;
    }
};
