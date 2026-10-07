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
        queue<pair<TreeNode*, int>> q;
        if (root == nullptr)
            return 0;
        int res = 0;
        q.push({root, INT_MIN});
        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            int val = q.front().second;
            q.pop();
            if (cur->val >= val)
                res++;
            val = max(cur->val, val);
            if (cur->left != nullptr)
                q.push({cur->left, val});
            if (cur->right != nullptr)
                q.push({cur->right, val});    
        }
        return res;
    }
};
