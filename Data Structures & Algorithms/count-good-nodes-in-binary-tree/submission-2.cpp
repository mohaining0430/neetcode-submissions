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
        if (root != nullptr)
            q.push({root, INT_MIN});
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* cur = q.front().first;
                int maxVal = q.front().second;
                q.pop();
                if (cur->val >= maxVal)
                    res++;
                if (cur->left != nullptr)
                    q.push({cur->left, max(maxVal, cur->val)});
                if (cur->right != nullptr)
                    q.push({cur->right, max(maxVal, cur->val)});
            }
        }
        return res;
    }
};
